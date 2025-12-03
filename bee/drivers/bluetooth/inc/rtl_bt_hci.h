/*
 * Copyright(c) 2020, Realtek Semiconductor Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef _RTK_BT_HCI_H_
#define _RTK_BT_HCI_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>

/** @addtogroup RTK_BT_HCI REALTEK BT HCI Transport
  * @brief REALTEK BT HCI Transport
  * @details

    REALTEK BT HCI Transport exposes interfaces to external BT host.

    External BT Host shall initialize BT HCI pool and register callback using @ref rtl_bt_hci_open function.

    External BT Host shall handle the callback message registered by @ref rtl_bt_hci_open. When REALTEK controller needs send HCI packet to BT Host,
    REALTEK controller will call the callback to send message BT_HCI_EVT_DATA_IND.

    External BT Host allocates buffers for HCI commands and ACL data from BT HCI pool using @ref rtl_bt_hci_h2c_buf_alloc. BT Host copies the HCI packet to the buffer using @ref rtl_bt_hci_h2c_buf_add.
    Then External BT Host sends HCI packet to controller using @ref rtl_bt_hci_send.



  * @{
  */
/*============================================================================*
 *                         Macros
 *============================================================================*/
/** @defgroup RTK_BT_HCI_Exported_Macros REALTEK BT HCI Transport Exported Macros
  * @{
  */

/** @defgroup RTK_BT_HCI_TYPE HCI packet types
 * @{
 */
#define H4_CMD  0x01 /**< HCI Command packet. */
#define H4_ACL  0x02 /**< HCI ACL Data packet. */
#define H4_SCO  0x03 /**< HCI Synchronous Data packet. */
#define H4_EVT  0x04 /**< HCI Event packet. */
#define H4_ISO  0x05 /**< HCI ISO Data packet. */
/**
  * @}
  */

/** End of RTK_BT_HCI_Exported_Macros
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup RTK_BT_HCI_Exported_Types REALTEK BT HCI Transport Exported Types
  * @brief
  * @{
  */
typedef enum
{
    BT_HCI_EVT_OPENED,     /**< BT HCI open completed. */
    BT_HCI_EVT_DATA_IND,   /**< BT HCI packet from Controller to Host. */
} T_RTL_BT_HCI_EVT;

/** @brief  BT HCI buffer.*/
typedef struct
{
    uint8_t                  *p_h2c_buf;
    uint16_t                  h2c_buf_size;
    uint16_t                  h2c_buf_size_max;
} T_RTL_BT_HCI_BUF;

/**
  * @brief Callback for controller to host
  * @param[in] evt       Event type @ref T_RTL_BT_HCI_EVT.
  * @param[in] status    The status of the event.
  * @param[in] p_c2h_buf Point to callback data.
  * @param[in] len       The length of callback data.
  * @retval true         If the packet can be sent to host.
  * @retval false        If the packet needs to be dropped.
  */
typedef bool (*P_RTL_BT_HCI_CALLBACK)(T_RTL_BT_HCI_EVT evt, bool status, uint8_t *p_c2h_buf,
                                      uint32_t len);

/** End of RTK_BT_HCI_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * @defgroup RTK_BT_HCI_Exported_Functions REALTEK BT HCI Transport Exported Functions
 *
 * @{
 */

/**
 * @brief Initialize host to controller data pool.
 *
 *   NOTE: This function shall be called before @ref rtl_bt_hci_open is invoked.
 *
 * @param[in] pool_size Initialize pool size.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool test(void)
    {
        if (rtl_bt_hci_h2c_pool_init(F_RTK_BT_HCI_H2C_POOL_SIZE))
        {
            if (rtl_bt_hci_open(bt_recv_cb))
            {
                return true;
            }
        }
        return false;
    }
 * \endcode
 */
bool rtl_bt_hci_h2c_pool_init(uint32_t pool_size);

/**
 * @brief  Allocate BT HCI buffer from data pool.
 * @param[in,out] p_hci_buf The BT HCI buffer that used to save HCI packet.
 * @param[in] h4_type       The packet type @RTK_BT_HCI_TYPE.
 * @param[in] data_size     The data length without packet type.
 * @retval true Success.
 * @retval false Failed.
 */
bool rtl_bt_hci_h2c_buf_alloc(T_RTL_BT_HCI_BUF *p_hci_buf, uint8_t h4_type, uint16_t data_size);

/**
 * @brief  Copies the given number of bytes to the end of the BT HCI buffer.
 * @param[in] p_hci_buf The BT HCI buffer that used to copy HCI packet.
 * @param[in] p_data    Point to the data to be added.
 * @param[in] data_size Length of data to be added.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool test(uint8_t h4_type, uint8_t *p_hci_data_buf, uint16_t hci_data_size)
    {
        T_RTL_BT_HCI_BUF hci_buf = {0};

        if (rtl_bt_hci_h2c_buf_alloc(&hci_buf, h4_type, hci_data_size) == false)
        {
            return false;
        }

        if (rtl_bt_hci_h2c_buf_add(&hci_buf, p_hci_data_buf, hci_data_size) == false)
        {
            rtl_bt_hci_h2c_buf_rel(hci_buf);
            return false;
        }

        if (rtl_bt_hci_send(hci_buf) == false)
        {
            rtl_bt_hci_h2c_buf_rel(hci_buf);
            return false;
        }

        return true;
    }
 * \endcode
 */
bool rtl_bt_hci_h2c_buf_add(T_RTL_BT_HCI_BUF *p_hci_buf, uint8_t *p_data, uint16_t data_size);

/**
 * @brief  Release BT HCI buffer.
 * @param[in] hci_buf The BT HCI buffer that need to release.
 * @retval true Success.
 * @retval false Failed.
 */
bool rtl_bt_hci_h2c_buf_rel(T_RTL_BT_HCI_BUF hci_buf);

/**
 * @brief  Open controller BT HCI interface.
 *
 *   NOTE: This function shall be called after @ref rtl_bt_hci_h2c_pool_init is invoked.
 *
 * @param[in] p_cb Callback function: @ref P_RTL_BT_HCI_CALLBACK.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool bt_recv_cb(T_RTL_BT_HCI_EVT evt, bool status, uint8_t *p_buf, uint32_t len)
    {
        int ret = 0;

        switch (evt)
        {
        case BT_HCI_EVT_OPENED:
            {
                if (status == false)
                {
                    //Failed to open BT HCI.
                }
            }
            break;

        case BT_HCI_EVT_DATA_IND:
            {
                switch (p_buf[0])   // First byte is packet type
                {
                case H4_EVT:
                    {
                        uint8_t event = p_buf[1]; //Event Code
                        uint8_t length = p_buf[2];//Parameter Total Length
                        //Send HCI event packet to BT Host
                    }
                    break;

                case H4_ACL:
                    {
                        uint16_t handle;  //Connection_Handle
                        uint16_t length;  //Data Total Length
                        memcpy(&handle, &p_buf[1], 2);
                        memcpy(&length, &p_buf[3], 2);
                        //Send HCI ACL Data packet to BT Host
                    }
                    break;

                default:
                    break;
                }
                rtl_bt_hci_ack(p_buf);
            }
            break;

        default:
            break;
        }

        return true;
    }

    bool test(void)
    {
        if (rtl_bt_hci_h2c_pool_init(F_RTK_BT_HCI_H2C_POOL_SIZE))
        {
            if (rtl_bt_hci_open(bt_recv_cb))
            {
                return true;
            }
        }
        return false;
    }
 * \endcode
 */
bool rtl_bt_hci_open(P_RTL_BT_HCI_CALLBACK p_cb);

/**
 * @brief  Send packet from host to controller.
 *
 * BT HCI driver should use this function to send packet to controller.
 *
 * @param[in] hci_buf The BT HCI buffer that used to send packet to controller.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool test(uint8_t h4_type, uint8_t *p_hci_data_buf, uint16_t hci_data_size)
    {
        T_RTL_BT_HCI_BUF hci_buf = {0};

        if (rtl_bt_hci_h2c_buf_alloc(&hci_buf, h4_type, hci_data_size) == false)
        {
            return false;
        }

        if (rtl_bt_hci_h2c_buf_add(&hci_buf, p_hci_data_buf, hci_data_size) == false)
        {
            rtl_bt_hci_h2c_buf_rel(hci_buf);
            return false;
        }

        if (rtl_bt_hci_send(hci_buf) == false)
        {
            rtl_bt_hci_h2c_buf_rel(hci_buf);
            return false;
        }

        return true;
    }
 * \endcode
 */
bool rtl_bt_hci_send(T_RTL_BT_HCI_BUF hci_buf);

/**
 * @brief  Send packet acknowledgment response from BT Host to Controller.
 *
 * When BT Host has handled the message BT_HCI_EVT_DATA_IND,
 * BT Host should use this function to ACK packet successfully received from Controller.
 *
 * @param[in] p_buf Point to the buffer that need to ack.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool bt_recv_cb(T_RTL_BT_HCI_EVT evt, bool status, uint8_t *p_buf, uint32_t len)
    {
        int ret = 0;

        switch (evt)
        {
        case BT_HCI_EVT_DATA_IND:
            {
                switch (p_buf[0])   // First byte is packet type
                {
                case H4_EVT:
                    {
                        uint8_t event = p_buf[1]; //Event Code
                        uint8_t length = p_buf[2];//Parameter Total Length
                        //Send HCI event packet to BT Host
                    }
                    break;

                case H4_ACL:
                    {
                        uint16_t handle;  //Connection_Handle
                        uint16_t length;  //Data Total Length
                        memcpy(&handle, &p_buf[1], 2);
                        memcpy(&length, &p_buf[3], 2);
                        //Send HCI ACL Data packet to BT Host
                    }
                    break;

                default:
                    break;
                }
                rtl_bt_hci_ack(p_buf);
            }
            break;

        default:
            break;
        }

        return true;
    }
 * \endcode
 */
void rtl_bt_hci_ack(uint8_t *p_buf);
/** @} */ /* End of group RTK_BT_HCI_Exported_Functions */
/** @} */ /* End of group RTK_BT_HCI */

#ifdef __cplusplus
}
#endif

#endif /* _RTK_BT_HCI_H_ */
