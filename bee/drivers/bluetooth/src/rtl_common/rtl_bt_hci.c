/*
 * Copyright(c) 2020, Realtek Semiconductor Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <string.h>
#include "rtl_bt_hci.h"
#include "mem_types.h"
#include "os_mem.h"
#include "os_sync.h"
#include "trace.h"

#define F_RTK_BT_HCI_H2C_POOL_DEBUG_LOG 0
#define F_RTK_BT_HCI_DRIVER_DEBUG_LOG   0

#define HCI_TX_ACL_BUF_OFFSET           11
#define HCI_CMD_BUF_OFFSET              7
#define HCI_TX_ACL_RSVD_SIZE            8
#define HCI_RX_ACL_BUF_OFFSET           19
#define HCI_RX_ISO_BUF_OFFSET           19
#define HCI_TX_ISO_BUF_OFFSET           11
#define HCI_TX_ISO_RSVD_SIZE            8

typedef enum
{
    HCI_IF_EVT_OPENED = 0,     /* hci I/F open completed */
    HCI_IF_EVT_DATA_IND = 2,   /* hci I/F rx data indicated */
    HCI_IF_EVT_DATA_XMIT = 3,  /* hci I/F tx data transmitted */
    HCI_IF_EVT_ERROR = 4,      /* hci I/F error occurred */
} T_HCI_IF_EVT;

typedef bool (*P_HCI_IF_CALLBACK)(T_HCI_IF_EVT evt, bool status, uint8_t *p_buf, uint32_t len);


extern bool (*vhci_open)(P_HCI_IF_CALLBACK p_callback);
extern bool (*vhci_send)(void *p_buf, uint32_t len);
extern bool (*vhci_ack)(void *p_buf);

P_RTL_BT_HCI_CALLBACK p_rtl_bt_hci_cb = NULL;

typedef struct t_bt_hci_buffer
{
    struct t_bt_hci_buffer   *p_next;     /* next free pool buffer */
    uint32_t                  size  : 16; /* buffer size */
    uint32_t                  flags : 3;  /* buffer flags */
} T_BT_HCI_BUFFER;

typedef struct t_bt_hci_pool
{
    T_BT_HCI_BUFFER   pool_start;
    T_BT_HCI_BUFFER  *p_pool_end;
    void             *p_start_boundary;
    void             *p_end_boundary;

    uint32_t          heap_size_unused;
    uint16_t          buf_num_used;
} T_BT_HCI_POOL;

/* BT HCI Pool Bit Mask */
#define BT_HCI_FLAG_BUFFER_ALLOCATED   0x01
#define BT_HCI_POOL_HDR_SIZE           sizeof(T_BT_HCI_BUFFER)
#define BT_HCI_POOL_BUFFER_ADDR_MASK   (sizeof(void *) - 1)
#define BT_HCI_POOL_BUFFER_ALIGN_SIZE  (1 << 4)
#define BT_HCI_POOL_BUFFER_ALIGN_MASK  (BT_HCI_POOL_BUFFER_ALIGN_SIZE - 1)
#define BT_HCI_POOL_BUFFER_MINI_SIZE   (BT_HCI_POOL_BUFFER_ALIGN_SIZE << 1)

T_BT_HCI_POOL hci_if_pool;

bool rtl_bt_hci_h2c_pool_init(uint32_t pool_size)
{
    if (hci_if_pool.p_start_boundary == NULL)
    {
        uint8_t      *p_heap;
        uint8_t      *p_heap_start;
        uint8_t      *p_heap_end;
        uint32_t      heap_size;
        T_BT_HCI_BUFFER *p_buf;

        hci_if_pool.buf_num_used = 0;

        heap_size = pool_size;

        p_heap = os_mem_zalloc(RAM_TYPE_BUFFER_ON, heap_size);
        if (p_heap == NULL)
        {
            DBG_DIRECT("[POOL] init: alloc failed, size %d", heap_size);
            return false;
        }

        p_heap_start = p_heap;

        /* make pool heap start address alignment */

        if ((size_t)p_heap_start & BT_HCI_POOL_BUFFER_ALIGN_MASK)
        {
            p_heap_start += BT_HCI_POOL_BUFFER_ALIGN_SIZE - 1;
            p_heap_start  = (uint8_t *)((size_t)p_heap_start &
                                        ~BT_HCI_POOL_BUFFER_ALIGN_MASK);
            heap_size    -= (size_t)p_heap_start - (size_t)p_heap;
        }

        hci_if_pool.pool_start.p_next = (void *)p_heap_start;
        hci_if_pool.pool_start.size   = 0;

        /* make pool heap end address alignment */

        p_heap_end  = p_heap_start + heap_size - BT_HCI_POOL_HDR_SIZE;
        p_heap_end  = (uint8_t *)((size_t)p_heap_end &
                                  ~BT_HCI_POOL_BUFFER_ALIGN_MASK);

        hci_if_pool.p_pool_end          = (T_BT_HCI_BUFFER *)p_heap_end;
        hci_if_pool.p_pool_end->p_next  = NULL;
        hci_if_pool.p_pool_end->size    = 0;

        p_buf           = (T_BT_HCI_BUFFER *)p_heap_start;
        p_buf->p_next   = (T_BT_HCI_BUFFER *)p_heap_end;
        p_buf->size     = (size_t)p_heap_end - (size_t)p_heap_start;

        hci_if_pool.heap_size_unused = p_buf->size;

        hci_if_pool.p_start_boundary = hci_if_pool.pool_start.p_next;
        hci_if_pool.p_end_boundary   = hci_if_pool.p_pool_end;
#if F_RTK_BT_HCI_H2C_POOL_DEBUG_LOG
        DBG_DIRECT("[POOL] init: pool_size %d, p_heap %p, heap_size_unused %d, boundary(%p - %p)",
                   pool_size, p_heap,
                   hci_if_pool.heap_size_unused, hci_if_pool.p_start_boundary,
                   hci_if_pool.p_end_boundary);
#endif
        return true;
    }
    DBG_DIRECT("[POOL] init: failed");
    return false;
}

#if F_RTK_BT_HCI_H2C_POOL_DEBUG_LOG
void rtl_bt_hci_dump(void)
{
    T_BT_HCI_BUFFER  *p_hdr;
    uint32_t       s;

    s = os_lock();

    DBG_DIRECT("[POOL] dump: heap_size_unused %d, buf_num_used %d",
               hci_if_pool.heap_size_unused,  hci_if_pool.buf_num_used);

    p_hdr = hci_if_pool.pool_start.p_next;

    while (p_hdr != NULL)
    {
        DBG_DIRECT("[POOL] dump: free list hdr %p, next %p, size %d, flags 0x%01x",
                   p_hdr, p_hdr->p_next, p_hdr->size, p_hdr->flags);

        p_hdr = p_hdr->p_next;
    }

    os_unlock(s);
}
#endif

bool rtl_bt_hci_h2c_buf_alloc(T_RTL_BT_HCI_BUF *p_hci_buf, uint8_t h4_type, uint16_t data_size)
{
    uint8_t         *p_buf = NULL;
    T_BT_HCI_BUFFER *p_prev_hdr;
    T_BT_HCI_BUFFER *p_curr_hdr;
    uint16_t         buf_size;
    uint8_t          pkt_offset;
    uint8_t          err_idx = 0;
    uint32_t         s;

    s = os_lock();

    if (p_hci_buf == NULL || data_size == 0)
    {
        err_idx = 1;
        goto FAILED;
    }

    if (h4_type == H4_ACL)
    {
        pkt_offset = HCI_TX_ACL_BUF_OFFSET;
        buf_size = data_size + pkt_offset + 1 + HCI_TX_ACL_RSVD_SIZE;
    }
    else if (h4_type == H4_ISO)
    {
        pkt_offset = HCI_TX_ISO_BUF_OFFSET;
        buf_size = data_size + pkt_offset + 1 + HCI_TX_ISO_RSVD_SIZE;
    }
    else if (h4_type == H4_CMD)
    {
        pkt_offset = HCI_CMD_BUF_OFFSET;
        buf_size = data_size + pkt_offset + 1 ;
    }
    else
    {
        err_idx = 2;
        goto FAILED;
    }

    buf_size += BT_HCI_POOL_HDR_SIZE;

    if (buf_size & BT_HCI_POOL_BUFFER_ALIGN_MASK)
    {
        buf_size = (buf_size + BT_HCI_POOL_BUFFER_ALIGN_SIZE - 1) &
                   ~BT_HCI_POOL_BUFFER_ALIGN_MASK;
    }

    if (buf_size > hci_if_pool.heap_size_unused)
    {
        err_idx = 3;
        goto FAILED;
    }

    p_prev_hdr = &hci_if_pool.pool_start;
    p_curr_hdr = hci_if_pool.pool_start.p_next;

    while (p_curr_hdr->size < buf_size && p_curr_hdr->p_next != NULL)
    {
        p_prev_hdr = p_curr_hdr;
        p_curr_hdr = p_curr_hdr->p_next;
    }

    if (p_curr_hdr == hci_if_pool.p_pool_end)
    {
        err_idx = 4;
        goto FAILED;
    }

    p_buf = (uint8_t *)p_prev_hdr->p_next + BT_HCI_POOL_HDR_SIZE;

    if (p_curr_hdr->size - buf_size >= BT_HCI_POOL_BUFFER_MINI_SIZE)
    {
        T_BT_HCI_BUFFER *p_tmp_hdr;

        p_tmp_hdr = (T_BT_HCI_BUFFER *)((uint8_t *)p_prev_hdr->p_next +
                                        buf_size);
        p_tmp_hdr->p_next = p_curr_hdr->p_next;
        p_tmp_hdr->size   = p_curr_hdr->size - buf_size;
        p_tmp_hdr->flags  = 0;

        p_prev_hdr->p_next = p_tmp_hdr;
        p_curr_hdr->size   = buf_size;

        hci_if_pool.heap_size_unused -= buf_size;
    }
    else
    {
        p_prev_hdr->p_next = p_curr_hdr->p_next;

        hci_if_pool.heap_size_unused -= p_curr_hdr->size;
    }

    p_curr_hdr->p_next     = NULL;
    p_curr_hdr->flags      = BT_HCI_FLAG_BUFFER_ALLOCATED;

    p_hci_buf->p_h2c_buf      = p_buf + pkt_offset;
    p_hci_buf->h2c_buf_size   = 1;
    p_hci_buf->h2c_buf_size_max = data_size + 1;

    memcpy(p_buf + pkt_offset, &h4_type, 1);
    if (h4_type == H4_ACL)
    {
        p_hci_buf->h2c_buf_size   += HCI_TX_ACL_RSVD_SIZE;
        p_hci_buf->h2c_buf_size_max += HCI_TX_ACL_RSVD_SIZE;
        memcpy(p_buf + pkt_offset + HCI_TX_ACL_RSVD_SIZE, &h4_type, 1);
    }
    else if (h4_type == H4_ISO)
    {
        p_hci_buf->h2c_buf_size   += HCI_TX_ISO_RSVD_SIZE;
        p_hci_buf->h2c_buf_size_max += HCI_TX_ISO_RSVD_SIZE;
        memcpy(p_buf + pkt_offset + HCI_TX_ISO_RSVD_SIZE, &h4_type, 1);
    }


    uint32_t buffer_addr = (uint32_t)p_buf;
    memcpy(p_buf + pkt_offset - 4, &buffer_addr, 4);

    hci_if_pool.buf_num_used++;

    os_unlock(s);

#if F_RTK_BT_HCI_H2C_POOL_DEBUG_LOG
    DBG_DIRECT("[POOL] alloc: buf_size %d, p_buf %p",
               buf_size, p_buf);
#endif

    return true;
FAILED:
    os_unlock(s);
    DBG_DIRECT("[POOL] alloc: failed, err_idx %d", err_idx);
    return false;
}

bool rtl_bt_hci_h2c_buf_add(T_RTL_BT_HCI_BUF *p_hci_buf, uint8_t *p_data, uint16_t data_size)
{
    uint32_t      s;

    s = os_lock();
    if (p_hci_buf != NULL && p_data != NULL && data_size != 0)
    {
        if (p_hci_buf->p_h2c_buf &&
            (p_hci_buf->h2c_buf_size + data_size) <= p_hci_buf->h2c_buf_size_max)
        {
            memcpy(p_hci_buf->p_h2c_buf + p_hci_buf->h2c_buf_size, p_data, data_size);
            p_hci_buf->h2c_buf_size   += data_size;
            os_unlock(s);
            return true;
        }
    }
    os_unlock(s);
    DBG_DIRECT("[POOL] add: failed, data_size %d", data_size);
    return false;
}

bool rtl_bt_hci_h2c_buf_release(uint8_t *p_h2c_buf)
{
    T_BT_HCI_BUFFER          *p_hdr;
    T_BT_HCI_BUFFER          *p_curr_hdr;
    void                     *p_buf = NULL;
    uint32_t                  buffer_addr;
    uint32_t                  s;
    uint8_t                   err_idx = 0;

    s = os_lock();

    if (p_h2c_buf == NULL)
    {
        err_idx = 1;
        goto FAILED;
    }

    memcpy(&buffer_addr, p_h2c_buf - 4, 4);
    p_buf = (uint32_t *)buffer_addr;

    if ((p_buf == NULL) || ((size_t)p_buf & BT_HCI_POOL_BUFFER_ADDR_MASK))
    {
        err_idx = 2;
        goto FAILED;
    }

    if (hci_if_pool.p_start_boundary > p_buf ||
        hci_if_pool.p_end_boundary < p_buf)
    {
        err_idx = 3;
        goto FAILED;
    }

    p_hdr = (void *)((uint8_t *)p_buf - BT_HCI_POOL_HDR_SIZE);

    if (!(p_hdr->flags & BT_HCI_FLAG_BUFFER_ALLOCATED))
    {
        err_idx = 4;
        goto FAILED;
    }

    p_hdr->flags = 0;

    hci_if_pool.heap_size_unused += p_hdr->size;

    hci_if_pool.buf_num_used--;

    p_curr_hdr = &hci_if_pool.pool_start;
    while (p_curr_hdr->p_next < p_hdr)
    {
        p_curr_hdr = p_curr_hdr->p_next;
    }

    /* merge left contiguous buffers */

    if ((uint8_t *)p_curr_hdr + p_curr_hdr->size == (uint8_t *)p_hdr)
    {
        p_curr_hdr->size += p_hdr->size;
        p_hdr = p_curr_hdr;
    }

    /* merge right contiguous buffers */

    if ((uint8_t *)p_hdr + p_hdr->size == (uint8_t *)p_curr_hdr->p_next)
    {
        if (p_curr_hdr->p_next != hci_if_pool.p_pool_end)
        {
            p_hdr->size   += p_curr_hdr->p_next->size;
            p_hdr->p_next  = p_curr_hdr->p_next->p_next;
        }
        else
        {
            p_hdr->p_next = hci_if_pool.p_pool_end;
        }
    }
    else
    {
        p_hdr->p_next = p_curr_hdr->p_next;
    }

    /* no left merge */

    if (p_curr_hdr != p_hdr)
    {
        p_curr_hdr->p_next = p_hdr;
    }

    os_unlock(s);

#if F_RTK_BT_HCI_H2C_POOL_DEBUG_LOG
    DBG_DIRECT("[POOL] release: p_buf %p", p_buf);
    rtl_bt_hci_dump();
#endif

    return true;
FAILED:
    os_unlock(s);
    DBG_DIRECT("[POOL] release: failed, p_buf %p", p_buf);
    return false;
}

bool rtl_bt_hci_h2c_buf_rel(T_RTL_BT_HCI_BUF hci_buf)
{
    return rtl_bt_hci_h2c_buf_release(hci_buf.p_h2c_buf);
}


bool rtl_bt_hci_cb(T_HCI_IF_EVT evt, bool status, uint8_t *p_buf, uint32_t len)
{
    bool result = true;

#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
    DBG_DIRECT("[BT] c2h cb: evt %d, status %d, p_buf %p, len %d", evt, status, (void *)p_buf, len);
#endif

    switch (evt)
    {
    case HCI_IF_EVT_OPENED:
        {
            if (p_rtl_bt_hci_cb)
            {
                result = (*p_rtl_bt_hci_cb)(BT_HCI_EVT_OPENED, status, NULL, 0);
            }
        }
        break;

    case HCI_IF_EVT_DATA_IND:
        {
            if (p_buf[0] == H4_EVT)
            {
                if (p_rtl_bt_hci_cb)
                {
                    BT_SNOOP_UP_TRACE(len, p_buf);

                    result = (*p_rtl_bt_hci_cb)(BT_HCI_EVT_DATA_IND, status, p_buf, len);
                    break;
                }
            }
            else if (p_buf[0] == H4_ACL)
            {
                if (p_rtl_bt_hci_cb)
                {
                    if (len > HCI_RX_ACL_BUF_OFFSET)
                    {
                        p_buf[HCI_RX_ACL_BUF_OFFSET] = H4_ACL;
                        BT_SNOOP_UP_TRACE(len - HCI_RX_ACL_BUF_OFFSET, p_buf + HCI_RX_ACL_BUF_OFFSET);

                        result = (*p_rtl_bt_hci_cb)(BT_HCI_EVT_DATA_IND, status, p_buf + HCI_RX_ACL_BUF_OFFSET,
                                                    len - HCI_RX_ACL_BUF_OFFSET);
                        break;
                    }

                }
            }
            else if (p_buf[0] == H4_ISO)
            {
                if (p_rtl_bt_hci_cb)
                {
                    if (len > HCI_RX_ISO_BUF_OFFSET)
                    {
                        p_buf[HCI_RX_ISO_BUF_OFFSET] = H4_ISO;
                        BT_SNOOP_UP_TRACE(len - HCI_RX_ISO_BUF_OFFSET, p_buf + HCI_RX_ISO_BUF_OFFSET);

                        result = (*p_rtl_bt_hci_cb)(BT_HCI_EVT_DATA_IND, status, p_buf + HCI_RX_ISO_BUF_OFFSET,
                                                    len - HCI_RX_ISO_BUF_OFFSET);
                        break;
                    }

                }
            }
            else
            {
                DBG_DIRECT("[BT] c2h cb: unknown pkt type %d", p_buf[0]);
                result = false;
            }
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
            DBG_DIRECT("[BT] c2h: type %d, vhci_ack %p", p_buf[0], p_buf);
#endif
            vhci_ack(p_buf);
        }
        break;

    case HCI_IF_EVT_DATA_XMIT:
        {
            rtl_bt_hci_h2c_buf_release(p_buf);
        }
        break;

    default:
        result = false;
        break;
    }
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
    //DBG_DIRECT("[BT] c2h cb: end, p_buf %p", p_buf);
#endif
    return result;
}

bool rtl_bt_hci_open(P_RTL_BT_HCI_CALLBACK p_callback)
{
    p_rtl_bt_hci_cb = p_callback;
    return vhci_open(rtl_bt_hci_cb);
}

bool rtl_bt_hci_send(T_RTL_BT_HCI_BUF hci_buf)
{
    if (hci_buf.p_h2c_buf)
    {
        if (hci_buf.p_h2c_buf[0] == H4_CMD)
        {
            BT_SNOOP_DOWN_TRACE(hci_buf.h2c_buf_size, hci_buf.p_h2c_buf);
        }
        else if (hci_buf.p_h2c_buf[0] == H4_ACL)
        {
            BT_SNOOP_DOWN_TRACE(hci_buf.h2c_buf_size - HCI_TX_ACL_RSVD_SIZE,
                                hci_buf.p_h2c_buf + HCI_TX_ACL_RSVD_SIZE);
        }
        else if (hci_buf.p_h2c_buf[0] == H4_ISO)
        {
            BT_SNOOP_DOWN_TRACE(hci_buf.h2c_buf_size - HCI_TX_ISO_RSVD_SIZE,
                                hci_buf.p_h2c_buf + HCI_TX_ISO_RSVD_SIZE);
        }
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
        DBG_DIRECT("[BT] h2c data: p_buf %p, len %d, type %d", hci_buf.p_h2c_buf,
                   hci_buf.h2c_buf_size, hci_buf.p_h2c_buf[0]);
#endif
        if (vhci_send(hci_buf.p_h2c_buf, hci_buf.h2c_buf_size))
        {
            return true;
        }
    }
    return false;
}

void rtl_bt_hci_ack(uint8_t *p_buf)
{
    if (p_buf)
    {
        if (p_buf[0] == H4_EVT)
        {
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
            DBG_DIRECT("[BT] event vhci_ack %p", p_buf);
#endif
            vhci_ack(p_buf);
        }
        else if (p_buf[0] == H4_ACL)
        {
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
            DBG_DIRECT("[BT] acl vhci_ack %p", p_buf - HCI_RX_ACL_BUF_OFFSET);
#endif
            vhci_ack(p_buf - HCI_RX_ACL_BUF_OFFSET);
        }
        else if (p_buf[0] == H4_ISO)
        {
#if F_RTK_BT_HCI_DRIVER_DEBUG_LOG
            DBG_DIRECT("[BT] iso vhci_ack %p", p_buf - HCI_RX_ISO_BUF_OFFSET);
#endif
            vhci_ack(p_buf - HCI_RX_ISO_BUF_OFFSET);
        }
    }
}