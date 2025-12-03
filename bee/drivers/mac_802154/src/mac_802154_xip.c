/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
   * @file      main.c
   * @brief     Source file for BLE peripheral project, mainly used for initialize modules
   * @author    jane
   * @date      2017-06-12
   * @version   v1.0
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   **************************************************************************************
  */

/*============================================================================*
 *                              Header Files
 *============================================================================*/
#include <string.h>
#include <stdlib.h>
#include "rtl876x.h"
#include "mac_driver.h"
#include "mac_reg.h"
#include "mac_reg_type.h"
#include "trace.h"

/*============================================================================*
 *                              mac driver patch begin
 *============================================================================*/

extern pmac_driver_t pmac_driver;
extern volatile uint64_t bt_clk_offset;
extern void mac_EDScanProcess_rom(void);

typedef void (*bt_hci_reset_handler_t)(void);
static bt_hci_reset_handler_t bt_rci_reset_handler = NULL;

static uint16_t saved_shortaddr = 0;
static uint8_t saved_extaddr[8];

void mac_RegisterBtHciResetHandler(bt_hci_reset_handler_t handler)
{
    bt_rci_reset_handler = handler;
}

bool_t mac_GrantPHYStatus(void)
{
    if (pmac_driver->mac_attribute.phy_arbitration_en)
    {
        return MAC->phy_arb_ctrl_b.zbrf_gnt_sts;
    }
    else
    {
        return true;
    }
}

bool mac_GetTxNTermedStatus(void)
{
    return MAC->tx_term_sts_b.zbrf_normal_tx_termed ? true : false;
}

bool mac_GetTxEnhAckTermedStatus(void)
{
    return MAC->tx_term_sts_b.zbrf_gts1_tx_termed ? true : false;
}

static void mac_PHYGrantIntHandler_Patch(mac_isrsts_t isrsts)
{
    uint32_t gnt;
    if (MAC->phy_arb_ctrl_b.zbrf_gnt_sts == 0)
    {
        //pmac_driver->mac_radio_state = MAC_RADIO_STATE_W4PHYGNT;
    }
    else
    {
        //pmac_driver->mac_radio_state = MAC_RADIO_STATE_RX;
#if 1
        MAC->rfctl_b.rfrst = 1;
        while (MAC->mac_rf_state_b.radio_cst);
        MAC->rfctl_b.rfrst = 0;
        if (pmac_driver->txntrig_saved.w > 0)
        {
            MAC->txn_trig = pmac_driver->txntrig_saved.w;
        }
#endif
    }
}

void Zigbee_Handler_Patch(void)
{
    mac_isrsts_t isrsts;

    isrsts.w = MAC->isrsts;
    pmac_driver->IntIn.w ^= isrsts.w;
    MAC->isrsts = isrsts.w; // write 1 to clear interrupt

    if (isrsts.w & MAC_intmsk_btcmp3msk_Msk)
    {
        mac_bt_clk_t bt_clk;

        *((uint32_t *)&bt_clk) = 0;
        mac_SetBTClkInt(BT_CLK_OVFLW_WATCH_TIMER, &bt_clk);
        bt_clk_offset += MAX_BT_CLOCK_COUNTER;
    }

    if (isrsts.b.gntif)
    {
        // PHY grant interrupt
        mac_PHYGrantIntHandler_Patch(isrsts);
    }

    {
        if (isrsts.b.txnterrif)
        {
            if (pmac_driver->txntrig_saved.w > 0)
            {
                // txn
                pmac_driver->txntrig_saved.w = 0;
            }
        }

        if (isrsts.b.txnif)
        {
            if (pmac_driver->txntrig_saved.w > 0)
            {
                pmac_driver->txntrig_saved.w = 0;
            }
            else
            {
                // upper layer encryption
                isrsts.b.txnif = 0;
            }
        }

        if (isrsts.b.txg1if)
        {
            // toggle nocsmag bit to reset GTS1/GTS2 TX switching
            MAC->gts_ctrl_b.nocsmag = 0;
            MAC->gts_ctrl_b.nocsmag = 1;
        }

        if (isrsts.b.txg2if)
        {
        }
    }

    if (isrsts.b.edscanif)
    {
        // ED scan done interrupt
        //mac_EDScanProcess_rom();
    }

    if (pmac_driver->mac_intr_cb)
    {
        pmac_driver->mac_intr_cb(isrsts.w);
    }
}

uint8_t mac_LoadTxNPayload_patch(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO)
{
    pmac_txfifo_t pTxNFIFO = (pmac_txfifo_t)((uint32_t)(MAC->txn_fifo));

    // max data length is 125
    if ((FrmL > MAC_MAX_TX_FRM_LEN) || (FrmL < MAC_MIN_TX_FRM_LEN))
    {
        return MAC_STS_DATA_LEN_ERROR;
    }

    pTxNFIFO->hdr_len = HdrL; //write header length into tx normal fifo
    pTxNFIFO->frm_len = FrmL; //write frame length into tx normal fifo
    mac_memcpy((void *)pTxNFIFO->payload, TxFIFO, FrmL); //write data into tx normal fifo

    return MAC_STS_SUCCESS;
}

void mac_TrigUpperEnc_patch(void)
{
    mac_txn_trig_t txntrig;
    txntrig.w = 0;
    txntrig.b.txnsecen = 1;
    txntrig.b.txntrig = 1;
    MAC->sec_upper_ctrl_b.upenc = 1; //enable upper cipher mode
    MAC->sec_proc_sts_b.sec_enc_done = 1; // clear encryption done status
    MAC->txn_trig = txntrig.w; // trigger secure process, txnsecen & txntrig must write simultaneously
    while (0 == MAC->sec_proc_sts_b.sec_enc_done); //wait encryption is done
    MAC->sec_upper_ctrl_b.upenc = 0;
    txntrig.b.txnsecen = 0;
    txntrig.b.txntrig = 0;
}

uint8_t  mac_TrigTxN_patch(bool_t AckReq, bool_t SecReq, bool_t Is2015)
{
    mac_txn_trig_t txntrig;

    txntrig.w = 0;

    if (SecReq)
    {
        txntrig.b.txnsecen = 1;
    }

    if (AckReq)
    {
        txntrig.b.txnackreq = 1;
        txntrig.b.ack_type = Is2015;
    }

    txntrig.b.txntrig = 1;
    //mac_EnterCritical_rom();
    pmac_driver->IntProc.b.txnif = pmac_driver->IntIn.b.txnif;  // update TX processing toggle bit
    pmac_driver->txntrig_saved.w = txntrig.w;
    if (mac_GrantPHYStatus())
    {
        MAC->txn_trig = pmac_driver->txntrig_saved.w;
    }
    //mac_ExitCritical_rom();
    return (uint8_t)MAC_STS_SUCCESS;
}

uint8_t mac_TrigTxNAtTime_patch(bool_t AckReq, bool_t SecReq, bool_t Is2015, uint32_t time_us)
{
    mac_bt_clk_t TxTime;
    mac_USToBTClk(time_us, &TxTime);

    mac_txn_trig_t txntrig;
    mac_tx_given_time_set_t tx_given_time_set;
    int32_t bt_clk_cntr;

    txntrig.w = 0;

    if (SecReq)
    {
        txntrig.b.txnsecen = 1;
    }

    if (AckReq)
    {
        txntrig.b.txnackreq = 1;
        txntrig.b.ack_type = Is2015;
    }

    // to compansate PHY TX Settling time, TX trigger earlier
    bt_clk_cntr = BT_SLOT_TIME_US - TxTime.bt_clk_counter;
    bt_clk_cntr -= (int32_t)(pmac_driver->tagt_no_cca_trig_tim);

    while (bt_clk_cntr < 0)
    {
        TxTime.bt_native_clk--;
        bt_clk_cntr += BT_SLOT_TIME_US;
    }
    TxTime.bt_clk_counter = BT_SLOT_TIME_US - bt_clk_cntr;

    tx_given_time_set.w = 0;
    tx_given_time_set.b.txn_nclk = TxTime.bt_native_clk;
    tx_given_time_set.b.txn_ckc = TxTime.bt_clk_counter;
    tx_given_time_set.b.schtxnocca = 1;
    tx_given_time_set.b.txntmren = 1;
    //mac_EnterCritical_rom();
    pmac_driver->IntProc.b.txnif = pmac_driver->IntIn.b.txnif;  // update TX processing toggle bit
    pmac_driver->txntrig_saved.w = txntrig.w;
    pmac_driver->tx_given_time_set_saved.w = tx_given_time_set.w;
    MAC->txn_trig = pmac_driver->txntrig_saved.w;
    MAC->tx_given_time_set = pmac_driver->tx_given_time_set_saved.w;
    //mac_ExitCritical_rom();

    return (uint8_t)MAC_STS_SUCCESS;
}

uint8_t  mac_TrigTxEnhAck_patch(bool_t early, bool_t SecReq)
{
    while (MAC->txm_state_b.gts_state > 0)
    {
        __NOP();
    }

    mac_gts_ctrl_t enh_ack_trig;

    enh_ack_trig.w = MAC->gts_ctrl & ~(MAC_gts_ctrl_enh_ack_trig_Msk | MAC_gts_ctrl_sec_enh_ack_Msk);

    if (SecReq)
    {
        enh_ack_trig.b.sec_enh_ack = 1;
    }
    enh_ack_trig.b.enh_ack_trig = 1;

    if (early)
    {
        MAC->gts_ctrl = enh_ack_trig.w;
        return MAC_STS_SUCCESS;
    }
    else
    {
        if (MAC->tx_enh_ack_ctrl_b.gts_enh_ack_trig_en)
        {
            if (mac_GrantPHYStatus())
            {
                MAC->gts_ctrl = enh_ack_trig.w;
                return MAC_STS_SUCCESS;
            }
            else
            {
                return MAC_STS_PENDING;
            }
        }
        else
        {
            return MAC_STS_TIMEOUT;
        }
    }
}

void mac_TrigMacTmr(void)
{
    MAC->mac_timer_b.mactmr_h = 0x00;
    MAC->mac_timer_b.mactmr_l = 0x01;
}

void mac_RxInfo(uint8_t *p_len, mac_rxfifo_tail_t *p_rxfifo_tail)
{
    uint8_t len;
    MAC->rx_fifo_ctrl_b.rxffwr = 1;  // enable FW RX FIFO access
    len = MAC->rx_fifo[0];
    *p_len = len;
    mac_memcpy(p_rxfifo_tail, &MAC->rx_fifo[len], 7);
    MAC->rx_fifo_ctrl_b.rxffwr = 0;  // disable FW RX FIFO access
}

void mac_RxPayload(uint8_t len, uint8_t *payload)
{
    MAC->rx_fifo_ctrl_b.rxffwr = 1;  // enable FW RX FIFO access
    mac_memcpy(payload, &MAC->rx_fifo[1], len);
    MAC->rx_fifo_ctrl_b.rxffwr = 0;  // disable FW RX FIFO access
}

bool mac_GetPendingBit(void)
{
    return MAC->tx_ctrl_b.pend;
}

void mac_SetPendingBit(bool pending)
{
    MAC->tx_ctrl_b.pend = pending;
}

void mac_SetAddrMatchMode_patch(uint8_t mode)
{
    mac_src_addr_filter_ctrl_t mac_src_addr_filter_ctrl;

    mac_src_addr_filter_ctrl.w = MAC->src_addr_filter_ctrl;
    if (mode == AUTO_ACK_PENDING_MODE_THREAD)
    {
        mac_src_addr_filter_ctrl.b.enh_frmpend_en = 1;
        mac_src_addr_filter_ctrl.b.pending_ack = 0;
        mac_src_addr_filter_ctrl.b.datreq_cmd_pending_ack = 0;
    }
    else
    {
        mac_src_addr_filter_ctrl.b.enh_frmpend_en = 0;
        mac_src_addr_filter_ctrl.b.pending_ack = 0;
        mac_src_addr_filter_ctrl.b.datreq_cmd_pending_ack = 0;
    }
    MAC->src_addr_filter_ctrl = mac_src_addr_filter_ctrl.w;
}

void __wrap_mac_EnterCritical_rom(void)
{
    __NOP();
}

void __wrap_mac_ExitCritical_rom(void)
{
    __NOP();
}

void __wrap_mac_RstRF_rom(void)
{
    if (mac_GrantPHYStatus())
    {
        MAC->rfctl_b.rfrst = 1;
        while (MAC->mac_rf_state_b.radio_cst);
        MAC->rfctl_b.rfrst = 0;
    }
    else
    {
        while (!mac_GrantPHYStatus());
    }
}

/*============================================================================*
 *                              mac driver patch end
 *============================================================================*/

uint32_t get_zigbee_window_slot_imp(int16_t *prio, int16_t *prio_min)
{
    return (pmac_driver->mac_attribute.mac_cfg.anch_jump_val - 1);
}

#define SYSCALL_STACK_NONE 0
#define SYSCALL_STACK_HCI_RESET_ENTER 1
#define SYSCALL_STACK_HCI_RESET_EXIT 2

extern bool (*patch_SystemCall_Zigbee_Stack)(uint32_t opcode);

bool patch_SystemCall_Zigbee_Stack_imp(uint32_t opcode)
{
    switch (opcode)
    {
        case SYSCALL_STACK_HCI_RESET_ENTER:
        mac_memcpy(saved_extaddr, &MAC->eadr_l, 8);
        saved_shortaddr = MAC->sadr;
        break;

        case SYSCALL_STACK_HCI_RESET_EXIT:
        bt_rci_reset_handler();
        mac_SetLongAddress(saved_extaddr);
        mac_SetShortAddress(saved_shortaddr);
        break;

        default:
        break;
    }
}

void mac_Initialize_Patch(void)
{
    patch_SystemCall_Zigbee_Stack = patch_SystemCall_Zigbee_Stack_imp;
}

//++++++++++++++++++++++++++++++++++++++++++++++++
// mac driver
//++++++++++++++++++++++++++++++++++++++++++++++++

void mac_Initialize_Additional(void)
{
    MAC->clk_ctrl_b.engts = 1;          // patch: enable GTS TXM clock
    MAC->seccr0_b.disdec = 1;
    MAC->rxfrmtype_b.rxftype = 0x0f;
    MAC->tx_enh_ack_ctrl_b.gts_enh_ack_timer = 0xc0;
    mac_SetTXPower(8);                  // set TX power = 4 dBm (max)
    mac_Initialize_Patch();
}

void mac_SetTxNCsma(bool enable)
{
    MAC->csma_ctrl_b.nocsman = enable ? 0 : 1;
}

uint32_t mac_BackoffDelay(void)
{
    uint32_t backoff = MAC->dbg_reg0_b.sh_back & 0xf;
    if (backoff < 8)
    {
        backoff = 8;
    }
    return (320 * backoff);
}

uint32_t mac_GetTxMStatus(void)
{
    return MAC->txm_status;
}

uint32_t mac_GetTxAtStatus(void)
{
    return MAC->tx_given_time_status;
}

//------------------------------------------------
