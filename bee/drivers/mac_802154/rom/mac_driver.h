/**************************************************************************//**
 * @file     mac_driver.h
 * @brief    IEEE802.15.4 MAC/PHY driver header file.
 *
 * @version  V1.00
 * @date     2021-09-24
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2021 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/


#ifndef _MAC_DRIVER_H_
#define _MAC_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "string.h"
#include "zb_section.h"
#include "mac_reg_mask.h"
#include "mac_data_type.h"

/**
  \brief  Define TX/RX FIFO and Key buffer base address
*/
#define MAC_TXN_BASE_ADDR             ((uint32_t)mac_FIFO_BaseAddr(TXN_FIFO_ID))
#define MAC_TXB_BASE_ADDR             ((uint32_t)mac_FIFO_BaseAddr(TXB_FIFO_ID))
#define MAC_TXG1_BASE_ADDR            ((uint32_t)mac_FIFO_BaseAddr(TXG1_FIFO_ID))
#define MAC_TXG2_BASE_ADDR            ((uint32_t)mac_FIFO_BaseAddr(TXG2_FIFO_ID))
#define MAC_KEY_FIFO_BASE_ADDR        ((uint32_t)mac_FIFO_BaseAddr(KEY_FIFO_ID))
#define MAC_RX_BASE_ADDR              ((uint32_t)mac_FIFO_BaseAddr(RX_FIFO_ID))

// Base address of extend addr
uint8_t *MAC_EADR_BASE_ADDR(void);

/**
  \brief  Defines type for MAC 8-bits register retention list
*/
typedef struct retention_8b_reg_s
{
    __IOM uint8_t *const reg_addr;
    uint8_t mask;
} retention_8b_reg_t, *pretention_8b_reg_t;

/**
  \brief  Defines MAC callback function
*/
typedef void (*mac_intr_callback_t)(uint32_t int_sts);
typedef int32_t (*mac_edscan_lv2dbm_callback_t)(int32_t level);
typedef void (*mac_gnt_entry_callback_t)(uint16_t prio, uint16_t prio_min);
typedef void (*modem_cca_comb_callback_t)(uint8_t comb);

/**
  \brief  Defines MAC Driver ROM code patch functions entry table
*/
typedef struct mac_driver_rom_patch_s
{
    // util
    void *(*memcpy)(void *dest, const void *src, uint32_t len);
    void (*porting_init)(void);

    //ISR
    void (*edscan_handler)(void);
    void (*swtimer_handler)(void);

    // Interrupt
    void (*enter_critical)(void);
    void (*exit_critical)(void);

    // Reset
    void (*reset)(void);

    // BT Clk Timer
    uint32_t (*btclk2us)(mac_bt_clk_t bt_clk);
    uint32_t (*curr_btus)(void);
    void (*set_btus_int)(uint32_t tid, uint32_t time_us);

    // radio
    void (*reset_rf)(void);
    void (*set_radio_state)(mac_radio_state_t new_state);
    mac_radio_state_t (*get_radio_state)(void);

    // cca and edscan
    void (*enable_txn_csmacca)(void);
    void (*disable_txn_csmacca)(void);

    // software timer
    void (*swtimer_init)(mac_timer_handle_t *ptmr_entities, uint8_t tmr_num);
    void (*swtimer_stop)(pmac_timer_handle_t pstop_tmr);
    void (*swtimer_free)(pmac_timer_handle_t pmac_tmr);

    // rx
    uint8_t (*rx)(uint8_t *RxFIFO);
} mac_driver_rom_patch_t, *pmac_driver_rom_patch_t;

/**
  \brief MAC driver state flags.
*/
typedef union
{
    uint8_t w;

    struct
    {
        uint8_t rf_rst_pending    : 1;          /*!< is RF reset pending  */
        uint8_t hci_rst_backup_buf_alloc : 1;   /*!< is MAC reg backup buffer is allocated */
        uint8_t   : 6;
    } b;                                        /*!< bit fields for MAC driver state flags */
} mac_state_flag_t, *pmac_state_flag_t;

typedef union
{
    uint32_t w;
    struct
    {
        uint32_t txnif      : 1;
        uint32_t txg1if     : 1;
        uint32_t txg2if     : 1;
        uint32_t txnterrif  : 1;
        uint32_t rxelyif    : 1;
        uint32_t secif      : 1;
        uint32_t rxif       : 1;
        uint32_t mactmrif   : 1;
        uint32_t btcmp0if   : 1;
        uint32_t btcmp1if   : 1;
        uint32_t gntif      : 1;
        uint32_t edscanif   : 1;
        uint32_t sfstartif  : 1;
        uint32_t sfendif    : 1;
        uint32_t btcmp2if   : 1;
        uint32_t btcmp3if   : 1;
        uint32_t            : 16;
    } b; /*!< bit fields for isrsts */
} isrsts_t, *pisrsts_t;

typedef union
{
    uint32_t w; /*!< Interrupt Mask Control Register */
    struct
    {
        uint32_t txnmsk     : 1;
        uint32_t txg1msk    : 1;
        uint32_t txg2msk    : 1;
        uint32_t txnterrmsk : 1;
        uint32_t rxelymsk   : 1;
        uint32_t secmsk     : 1;
        uint32_t rxmsk      : 1;
        uint32_t mactmrmsk  : 1;
        uint32_t btcmp0msk  : 1;
        uint32_t btcmp1msk  : 1;
        uint32_t gntmsk     : 1;
        uint32_t edscanmsk  : 1;
        uint32_t sfstartmsk : 1;
        uint32_t sfendmsk   : 1;
        uint32_t btcmp2msk  : 1;
        uint32_t btcmp3msk  : 1;
        uint32_t            : 16;
    } b; /*!< bit fields for mac_intmsk */
} intmsk_t, *pintmsk_t;

typedef union
{
    uint8_t w; /*!< Normal TX FIFO Trigger Control Register */

    struct
    {
        uint8_t txntrig     : 1;
        uint8_t txnsecen    : 1;
        uint8_t txnackreq   : 1;
        uint8_t ack_type    : 1;
        uint8_t             : 1;
        uint8_t txnfrmtry   : 3;
    } b; /*!< bit fields for mac_txn_trig */
} txn_trig_t, *ptxn_trig_t;

typedef union
{
    uint32_t w; /*!< BT Time Comparator for TX Trigger Time Control Register */

    struct
    {
        uint32_t txn_nclk   : 18;
        uint32_t txn_ckc    : 10;
        uint32_t schtxnocca : 1;
        uint32_t            : 2;
        uint32_t txntmren   : 1;
    } b; /*!< bit fields for mac_tx_given_time_set */
} tx_given_time_set_t, *ptx_given_time_set_t;

typedef union
{
    uint32_t w;  /*!< MAC/PHY RX backup register 2 */

    struct
    {
        uint32_t rx_bkprg2_pg_addr : 8;
        uint32_t channel           : 7;
        uint32_t opt_cca_ed_or     : 1;
        uint32_t bkrpt0_reg_addr   : 8;
        uint32_t bkrpt0_en         : 1;
        uint32_t                   : 7;
    } b; /*!< bit fields for mac_rx_prg_reg_2w */
} rx_prg_reg_2w_t, *prx_prg_reg_2w_t;

typedef union
{
    uint32_t w; /*!< PHY RX backup register 0 */

    struct
    {
        uint32_t bkrpt2_reg_addr : 8;
        uint32_t bkrpt2_en       : 1;
        uint32_t                 : 7;
        uint32_t bkrpt1_reg_addr : 8;
        uint32_t bkrpt1_en       : 1;
        uint32_t                 : 7;
    } b; /*!< bit fields for mac_rx_bkrpt0w */
} rx_bkrpt0w_t, *prx_bkrpt0w_t;

typedef union
{
    uint32_t w; /*!< PHY RX backup register 1 */

    struct
    {
        uint32_t bkrpt4_reg_addr : 8;
        uint32_t bkrpt4_en       : 1;
        uint32_t                 : 7;
        uint32_t bkrpt3_reg_addr : 8;
        uint32_t bkrpt3_en       : 1;
        uint32_t                 : 7;
    } b; /*!< bit fields for mac_rx_bkrpt1w */
} rx_bkrpt1w_t, *prx_bkrpt1w_t;

typedef struct mac_driver_s
{
    volatile isrsts_t IntIn;
    volatile isrsts_t IntProc;
    volatile intmsk_t IntMask;

    mac_radio_state_t mac_radio_state;
    union
    {
        tx_pending_sts_t tx_trig_pend;
        uint8_t tx_trig_pend_w;
    };
    tx_pending_sts_t tx_pend_secen;
    volatile txn_trig_t txntrig_saved;
    uint8_t gnt_failed_retry;

    uint8_t tx_at_time_pending;

    uint8_t DualRxFlag;

    uint8_t TransceiverState;   /*!< RF Transceiver state */
    uint8_t cca_mode;           /*!< selected CCA mode of CSMA-CA */
    mac_state_flag_t state_flg;
    uint16_t CurrentFrequency;
    uint16_t tagt_no_cca_trig_tim;   /*!< the period from MAC TX trigger to
                                          the PHY start TX for TX at given time without CCA */
    uint16_t tagt_trig_tim;     /*!< the period from MAC TX trigger to
                                     the PHY start TX for TX at given time with CCA */

    tx_given_time_set_t tx_given_time_set_saved;
    pmac_timer_handle_t mac_timer_free_list;
    union
    {
        pmac_timer_handle_t mac_timer_running_list;
        pmac_timer_handle_t mac_timer_running_head;
    };

    mac_ed_scan_states_t ed_scan_state;
    /* for back up the latest value write to these registers,
       R/W to these registers map to different register internaly */
    volatile rx_prg_reg_2w_t rx_prg_reg_2w;
    volatile rx_bkrpt0w_t rx_bkrpt0w;
    volatile rx_bkrpt1w_t rx_bkrpt1w;

    /* call back functions */
    mac_intr_callback_t mac_intr_cb;
    mac_edscan_lv2dbm_callback_t mac_edscan_lv2dbm_cb;
    mac_gnt_entry_callback_t mac_gnt_entry_cb;
    modem_cca_comb_callback_t modem_cca_comb_cb;

    /* MAC driver attributes */
    mac_attribute_t mac_attribute;

    /* Reg list for MAC register retention by SW */
    const uint32_t **preten_reg32b_list;
    const uint16_t **preten_reg16b_list;
    const retention_8b_reg_t *preten_reg8b_list;

    /* ROM code patch function pointers */
    pmac_driver_rom_patch_t rcp;

    // MAC register backup buffer
    /* the buffer for backup the MAC registers. when entering DLPS or doing MAC reset the MAC
       registers may need to be backup and re-store */
    void *preg_backup_buf;

    uint32_t reserved[3];
} mac_driver_t, *pmac_driver_t;

/**
  \brief  Defines MAC stubs function
*/
typedef struct
{
    // from phy
    int8_t (*get_rssi_from_raw)(uint16_t rssi_raw, uint8_t channel);
    // util
    void *(*memcpy)(void *dest, const void *src, uint32_t len);
    void (*hal_delay_us)(uint32_t delay_us);
    uint8_t (*hal_is_timeout)(uint32_t timeout);
    // isr
    void (*swtimer_handler)(void);
    void (*edscan_handler)(void);
    // interrupt
    void (*enter_critical)(void);
    void (*exit_critical)(void);
    void (*disable_interrupt)(void);
    void (*resume_interrupt)(void);
    // reset
    void (*reset)(void);
    void (*enable)(void);
    void (*disable)(void);
    // bt native clock
    void (*curr_btclk)(mac_bt_clk_t *pbt_clk);
    uint32_t (*btclk2us)(mac_bt_clk_t bt_clk);
    uint32_t (*curr_btus)(void);
    uint64_t (*curr_mactime)(void);
    void (*set_btclk_int)(uint32_t tid, mac_bt_clk_t *pbt_clk);
    void (*set_btus_int)(uint32_t tid, uint32_t time_us);
    // radio
    void (*reset_rf)(void);
    void (*radio_on)(void);
    void (*radio_off)(void);
    void (*set_radio_state)(mac_radio_state_t new_state);
    mac_radio_state_t (*get_radio_state)(void);
    uint8_t (*set_trx_state)(uint8_t state);
    uint8_t (*get_trx_state)(void);
    uint8_t (*set_channel)(uint8_t ch);
    uint8_t (*get_channel)(void);
    uint8_t (*set_tx_power)(int8_t tx_dbm);
    // PIB
    // rx filter
    // cca and edscan
    void (*enable_txn_csmacca)(void);
    void (*disable_txn_csmacca)(void);
    void (*set_ccamode)(mac_cca_mode_t cca_mode);
    uint8_t (*edscan_ext)(uint32_t scan_duration, int8_t *ed_peak_lev, int8_t *ed_avrg_lev);
    uint8_t (*edscan_schedule)(uint32_t scan_duration, mac_ed_scan_callback_t callback);
    void (*edscan_cancel)(void);
    // software timer
    void (*swtimer_init)(mac_timer_handle_t *ptmr_entities, uint8_t tmr_num);
    pmac_timer_handle_t (*swtimer_alloc)(void);
    void (*swtimer_free)(pmac_timer_handle_t pmac_tmr);
    void (*swtimer_start)(pmac_timer_handle_t pstart_tmr, uint32_t timeout, void *pcallback, void *arg);
    void (*swtimer_stop)(pmac_timer_handle_t pstop_tmr);
    // tx
    uint8_t (*trig_txn)(uint8_t ackreq, uint8_t secreq);
    void (*update_pretrig_time)(void);
    uint8_t (*trig_txn_at)(uint8_t aclreq, uint8_t secreq, uint8_t docca, mac_bt_clk_t txtime);
    uint8_t (*trig_txenhack)(uint8_t early, uint8_t secreq);
    void (*trig_upperenc)(void);
    void (*trig_upperdec)(void);
    // rx
    uint8_t (*rx)(uint8_t *RxFIFO);
    uint8_t (*rxfifo)(uint8_t *RxFIFO, uint8_t *MorePkt);
    // addr match filter
    void (*set_addr_matchmode)(uint8_t mode);
    uint8_t (*add_short_match)(uint16_t short_addr, uint16_t panid);
    uint8_t (*del_short_match)(uint16_t short_addr, uint16_t panid);
    void (*del_short_match_all)(void);
    uint8_t (*add_ext_match)(uint8_t *pext_addr);
    uint8_t (*del_ext_match)(uint8_t *pext_addr);
    void (*del_ext_match_all)(void);
    // security
    uint8_t (*upper_cipher)(uint8_t sec_mode, uint8_t *sec_key, uint8_t *sec_nonce);
    uint8_t (*upper_decipher)(uint8_t sec_mode, uint8_t *sec_key, uint8_t *sec_nonce);
    // Callback function hook
    void (*interrupt_callback_hook)(mac_intr_callback_t intr_cb);
    void (*lv2dbm_callback_hook)(mac_edscan_lv2dbm_callback_t lv2dbm_cb);
    void (*phy_gnt_entry_callback_hook)(mac_gnt_entry_callback_t gnt_entry_cb);
    void (*modem_cca_comb_callback_hook)(modem_cca_comb_callback_t cca_comb_cb);

    // Register SW retention functions
    uint32_t (*get_retention_reg_size)(void);
    void *(*backup_reten_reg)(uint8_t *preten_buf);
    void *(*restore_reten_reg)(uint8_t *preten_buf);

    // PTA control
    void (*pta_duty_set_ratio)(uint32_t high_ticks, uint32_t low_ticks);

    // Initialization
    void (*mac_init_attribute)(mac_attribute_t *attribute);
    void (*mac_init)(mac_driver_t *ptr_drv, mac_attribute_t *attribute);

    // ROM Table
    const uint8_t *secmode_06to03;
    const uint8_t *secmode_mic_len;

    //callback for BT
    void (*bt_hci_reset_start)(void);
    void (*bt_hci_reset_end)(void);

    // added after RTL87X2G B-Cut
    void (*grant_phy_req)(uint8_t slot_offset);
    uint32_t (*fifo_base_addr)(mac_fifo_id_t fifo_id);
    uint8_t (*LoadTxNPayload)(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO);
    void (*SetPANId)(uint16_t pid);
    uint16_t (*GetPANId)(void);
    void (*SetShortAddress)(uint16_t sadr);
    void (*SetLongAddress)(uint8_t  *ladr);
    void (*SetCoordinatorShortAddress)(uint16_t sadr);
    void (*SetCoordinatorLongAddress)(uint8_t  *ladr);
    void (*SetGroupAddress)(uint8_t *gpadr);
    uint8_t (*SetTxNMaxRetry)(uint8_t max_retry);
    void (*SetTXGain)(uint8_t tx_gain);
    uint8_t (*GetTXGain)(void);
    void (*SetMaxCSMABackoffs)(uint8_t MaxCSMABackoffs);
    uint32_t (*GetTxNStatus)(void);
    uint32_t (*GetTxTermedStatus)(void);
    uint8_t (*GetTxNRetryTimes)(void);
    void (*SetPromiscuous)(uint8_t en);
    uint8_t (*GetPromiscuous)(void);
    void (*SetScanMode)(uint8_t en);
    uint8_t (*GetScanMode)(void);
    uint8_t (*GetRxFrmSeq)(void);
    uint8_t (*GetRxFrmAckReq)(void);
    uint8_t (*GetRxFrmType)(void);
    uint8_t (*GetRxFrmVersion)(void);
    uint8_t (*GetRxFrmPanidCompress)(void);
    uint8_t (*GetRxFrmSecEn)(void);
    uint8_t (*GetRxFrmSecLevel)(void);
    uint8_t (*GetRxFrmSecKeyIdMode)(void);
    uint8_t (*GetRxFrmSecKeyId)(void);
    uint8_t (*GetRxFrmSrcAddrMode)(void);
    uint16_t (*GetRxFrmShortAddr)(void);
    uint64_t (*GetRxFrmLongAddr)(void);
    int8_t (*GetCcaEDThreshold)(void);
    void (*SetTxEnhAckPending)(uint8_t len);
    uint8_t (*GetTxEnhAckPending)(void);
    void (*RxFlush)(void);
    uint8_t (*GetSrcMatchStatus)(void);
    void (*ClrSrcMatchStatus)(void);
    void (*SetNonce)(uint8_t *nonce);
    void (*SetKey)(uint8_t *key_buf, uint8_t *key);
    void (*LoadNonce)(uint8_t *nonce);
    void (*LoadTxNKey)(uint8_t *key);
    void (*SetTxNChiper)(uint8_t level);
    void (*LoadTxEnhAckKey)(uint8_t *key);
    void (*SetTxEnhAckChiper)(uint8_t level);
    uint8_t (*GetSecHLEN)(void);
    void (*SetSecHLEN)(uint8_t val);
    void (*SetRxChiper)(uint8_t level);
    void (*TrigRxDecryption)(void);
    void (*IgnoreRxDec)(void);
    void (*PTA_Enable)(uint8_t enable);
    void (*PTA_PrityDutyEnable)(uint8_t enable);
    void (*PTA_LoRXReq_Enable)(uint8_t enable);
    void (*PTA_ShareLNA)(uint8_t is_share_lan);
    void (*PTA_CCAReq_Enable)(uint8_t enable);
    void (*PTA_TXReq_Pri)(uint8_t hi_priority);
    void (*PTA_DutySetTick)(uint32_t tick_us);
    void (*DisBTClkTmr)(uint32_t tid);
} mac_adapter_t;

/*
  rom exported symbol
*/
extern uint32_t (*mac_GetZBArbitrationWindow)(int16_t *prio, int16_t *prio_min);
extern const mac_adapter_t mac_adapter;

static __inline uint32_t mac_FIFO_BaseAddr(mac_fifo_id_t fifo_id)
{
    return mac_adapter.fifo_base_addr(fifo_id);
}

/*
  Init
*/
/**
*
* @fn void mac_InitAttribute(mac_attribute_t* attr)
*
* @brief Initialize mac_attribute_t structure with default value.
*
* @param attr the mac_attribute_t pointer to be initialized
*
* @return None
*
*/
static __inline void mac_InitAttribute(mac_attribute_t *attribute)
{
    mac_adapter.mac_init_attribute(attribute);
}

/**
*
* @fn void mac_RegisterCallback(mac_intr_callback_t intr_cb, mac_edscan_lv2dbm_callback_t lv2dbm_cb,
*                               mac_gnt_entry_callback_t gnt_entry_cb)
*
* @brief Register mac callback function
*
* @param intr_cb interrupt handler callback function
*
* @param lv2dbm_cb translate EDScan level to dbm callback function
*
* @param gnt_entry_cb set gnt entry priority callback function
*
* @return None
*
*/
static __inline void mac_RegisterCallback(mac_intr_callback_t intr_cb,
                                          mac_edscan_lv2dbm_callback_t lv2dbm_cb,
                                          mac_gnt_entry_callback_t gnt_entry_cb,
                                          modem_cca_comb_callback_t cca_comb_cb)
{
    mac_adapter.interrupt_callback_hook(intr_cb);
    mac_adapter.lv2dbm_callback_hook(lv2dbm_cb);
    mac_adapter.phy_gnt_entry_callback_hook(gnt_entry_cb);
    mac_adapter.modem_cca_comb_callback_hook(cca_comb_cb);
}

/**
*
* @fn void mac_Initialize(mac_driver_t *ptr_drv, mac_attribute_t *attribute)
*
* @brief Initialize mac layer with attributes
*
* @param ptr_drv the mac_driver_t pointer to be initialized, mac_driver_t should be defined in data section
*
* @param attribute the mac_attribute_t pointer point to structure with default value
*
* @return None
*
*/
static __inline void mac_Initialize(mac_driver_t *ptr_drv, mac_attribute_t *attribute)
{
    mac_adapter.mac_init(ptr_drv, attribute);
}

/**
*
* @fn mac_Initialize_Additional()
*
* @brief Additional initialize step
*
* @param None
*
*/
void mac_Initialize_Additional(void);

/**
*
* @fn void mac_EnterDLPS(void *reg_retention_buf)
*
* @brief Let MAC enter the deep sleep power saving mode
*
* @param reg_retention_buf the buffer for MAC register backup before it entring sleep mode,
*                          if this buffer is NULL then no register will be backup. The buffer
*                          size must be big enough to backup registers in the backup list.
*
* @return None
*
*/
void mac_EnterDLPS(void *reg_retention_buf);

/**
*
* @fn void mac_ExitDLSP(void *reg_retention_buf)
*
* @brief Resume the MAC from deep sleep power saving mode
*
* @param reg_retention_buf the buffer for MAC register backup, which is used to restore MAC register.
*                          if this buffer is NULL then no register will be restored.
*
* @return None
*
*/
void mac_ExitDLPS(void *reg_retention_buf);

/*
  Interrupt
*/
/**
*
* @fn void mac_EnterCritical (void)
*
* @brief Enter MAC layer driver critical section (no MAC interrupt)
*
* @param None
*
* @return None
*
*/
static __inline void mac_EnterCritical(void)
{
    mac_adapter.enter_critical();
}

/**
*
* @fn void mac_EnterCritical (void)
*
* @brief Leave MAC layer driver critical section (MAC interrupt resume)
*
* @param None
*
* @return None
*
*/
static __inline void mac_ExitCritical(void)
{
    mac_adapter.exit_critical();
}

/**
*
* @fn void mac_DisableInterrupt(void)
*
* @brief disable MAC interrupt (store current interrupt mask
*        and then mask all interrupt)
*
* @param Mode
*
* @return None
*
*/
static __inline void mac_DisableInterrupt(void)
{
    mac_adapter.disable_interrupt();
}

/**
*
* @fn void mac_ResumeInterrupt(void)
*
* @brief resume MAC interrupt (restore interrupt mask)
*
* @param Mode
*
* @return None
*
*/
static __inline void mac_ResumeInterrupt(void)
{
    mac_adapter.resume_interrupt();
}

/*
  Reset
*/
/**
*
* @fn mac_Reset()
*
* @brief Software reset MAC
*
* @param None
*
*/
static __inline void mac_Reset(void)
{
    mac_adapter.reset();
}

/**
*
* @fn mac_Enable()
*
* @brief Enable MAC clock
*
* @param None
*
*/
static __inline void mac_Enable(void)
{
    mac_adapter.enable();
}

/**
*
* @fn mac_Disable()
*
* @brief Disable MAC clock
*
* @param None
*
*/
static __inline void mac_Disable(void)
{
    mac_adapter.disable();
}

/*
  BT native clock
*/
/**
*
* @fn void mac_GetCurrentBTClk(mac_bt_clk_t *pbt_clk)
*
* @brief Get current BT native clock and clock counter vaule
*
*
* @param pbt_clk the pointer of return BT clock data structure
*
* @return None
*
*/
static __inline void mac_GetCurrentBTClk(mac_bt_clk_t *pbt_clk)
{
    mac_adapter.curr_btclk(pbt_clk);
}

/**
*
* @fn uint32_t mac_BTClkToUs(mac_bt_clk_t bt_clk)
*
* @brief Convert a BT clock value to a time value with unit of 1us.
*
* @param bt_clk the BT clock value to be converted
*
* @return the converted time value with unit of 1us
*
*/
static __inline uint32_t mac_BTClkToUS(mac_bt_clk_t bt_clk)
{
    return mac_adapter.btclk2us(bt_clk);
}

/**
*
* @fn uint32_t mac_GetCurrentBTUS(void)
*
* @brief Get current BT native clock and clock counter vaule and convert
*        it as micro-second
*
* @return current BT clock counter in micro-second format
*
*/
static __inline uint32_t mac_GetCurrentBTUS(void)
{
    return mac_adapter.curr_btus();
}

/**
*
* @fn void mac_USToBTClk(uint32_t time_us, mac_bt_clk_t *pbt_clk)
*
* @brief Convert a time value of 1us to a BT clock value
*
* @param time_us the time value with 1us unit to be converted
*
* @param pbt_clk the pointer of the converted BT clock
*
* @return None
*
*/
static __inline void mac_USToBTClk(uint32_t time_us, mac_bt_clk_t *pbt_clk)
{
    uint32_t native_clk;
    uint32_t clk_cntr;

    if (time_us >= MAX_BT_CLOCK_COUNTER)
    {
        time_us -= MAX_BT_CLOCK_COUNTER;
    }

    native_clk = time_us / 625;
    clk_cntr = time_us - (native_clk * 625);
    pbt_clk->bt_native_clk = native_clk & 0x3FFFFF;
    if (clk_cntr > 0)
    {
        pbt_clk->bt_clk_counter = 625 - clk_cntr;
    }
    else
    {
        pbt_clk->bt_clk_counter = 0;
    }
}

/**
*
* @fn uint64_t mac_GetCurrentMACTime(void)
*
* @brief Get current MAC time in us, based on BT clock counter
*
* @return current MAC time
*
*/
static __inline uint64_t mac_GetCurrentMACTime(void)
{
    return mac_adapter.curr_mactime();
}

/**
*
* @fn void mac_SetBTClkInt(uint32_t tid, mac_bt_long_clk_t *pbt_clk)
*
* @brief Setup a BT clock interrupt
*
* @param tid the ID of BT clock timer to be set
*
* @param pbt_clk the given BT clock value to trigger the interrupt
*
* @return None
*
*/
static __inline void mac_SetBTClkInt(uint32_t tid, mac_bt_clk_t *pbt_clk)
{
    mac_adapter.set_btclk_int(tid, pbt_clk);
}

/**
*
* @fn void mac_SetBTClkUSInt(uint32_t tid, uint32_t time_us)
*
* @brief Setup a BT clock interrupt by a time format in micro-second
*
* @param tid the ID of BT clock timer to be set
*
* @param time_us the given BT clock value in us format to trigger the interrupt
*
* @return None
*
*/
static __inline void mac_SetBTClkUSInt(uint32_t tid, uint32_t time_us)
{
    mac_adapter.set_btus_int(tid, time_us);
}

/**
*
* @fn uint64_t mac_ConvertT0AndDtTo64BitTime(uint32_t aT0, uint32_t aDt, const uint64_t *aNow)
*
* @brief Convert 32bit T0 and Dt to 64bit time
*
* @return 64bit time
*
*/
static __inline uint64_t mac_ConvertT0AndDtTo64BitTime(uint32_t aT0, uint32_t aDt,
                                                       const uint64_t *aNow)
{
    uint64_t now;
    now = *aNow;

    if (((uint32_t)now < aT0) && ((aT0 - (uint32_t)now) > (UINT32_MAX / 2)))
    {
        now -= EPOCH_32BIT_US;
    }
    else if (((uint32_t)now > aT0) && (((uint32_t)now) - aT0 > (UINT32_MAX / 2)))
    {
        now += EPOCH_32BIT_US;
    }

    return (EPOCH_FROM_TIME(now)) + aT0 + aDt;
}

/*
  Util
*/
/**
*
* @fn void hal_delay_us(uint32_t delay_us)
*
* @brief Busy wait delay by pooling BT clock timer
*
* @param delay_us the delay time period, in micro-sec
*
* @return None
*
*/
static __inline void hal_delay_us(uint32_t delay_us)
{
    mac_adapter.hal_delay_us(delay_us);
}

/**
*
* @fn uint8_t HAL_Is_Timeout(uint32_t timeout)
*
* @brief check whether current MAC time (BT clock based) is later than the specified timeout time
*
* @param timeout the timeout for checking, in micro-secand
*
* @return None
*
*/
static __inline uint8_t hal_is_timeout(uint32_t timeout)
{
    return mac_adapter.hal_is_timeout(timeout);
}

/**
*
* @fn void *mac_memcpy(void *dest, const void *src, uint32_t len)
*
* @brief internal memcpy
*
* @param None
*
* @return None
*
*/
static __inline void *mac_memcpy(void *dest, const void *src, uint32_t len)
{
    return mac_memcpy_rom(dest, src, len);
}

/*
  Radio
*/
/**
*
* @fn mac_RstRF(Level)
*
* @brief Software reset RF part only then turns RF to RX mode
*
* @param None
*
* @return None
*
*/
static __inline void mac_RstRF(void)
{
    mac_adapter.reset_rf();
}

/**
*
* @fn void mac_RadioOn(void)
*
* @brief To request for PHY grant for MAC TX/RX
*
* @return None
*
*/
static __inline void mac_RadioOn(void)
{
    mac_adapter.radio_on();
}

/**
*
* @fn void mac_RadioOff(void)
*
* @brief To release PHY grant, no TX/RX is allowed after release PHY grant
*
* @return None
*
*/
static __inline void mac_RadioOff(void)
{
    mac_adapter.radio_off();
}

/**
*
* @fn void mac_SetRadioState(mac_radio_state_t new_state)
*
* @brief To set the Radio(PHY arbitration) state
*
* @param new_state the new radio state to be set
*
* @return None
*
*/
static __inline void mac_SetRadioState(mac_radio_state_t new_state)
{
    mac_adapter.set_radio_state(new_state);
}

/**
*
* @fn mac_radio_state_t mac_GetRadioState(void)
*
* @brief To get current Radio(PHY arbitration) state
*
* @return Current radio state
*
*/
static __inline mac_radio_state_t mac_GetRadioState(void)
{
    return mac_adapter.get_radio_state();
}

/**
*
* @fn uint8_t  mac_SetMACTRXState(uint8_t  state)
*
* @brief User can use this function to control the RF state of the RF (analog) part only.
*        The state includes TX, RX, TRX auto switch and TRX off.
*
* @param state The RF state.
*        TRANSCEIVER_TRX_AUTO   TRX auto switch
*        TRANSCEIVER_RX_ON      RX only
*        TRANSCEIVER_TX_ON      TX only
*        TRANSCEIVER_TRX_OFF    TRX off
*
* @return The function result.
* @retval MAC_STS_SUCCESS change RF state successfully.
* @retval MAC_STS_INVALID_PARAMETER RF state is unkonwn.
*
*/
static __inline uint8_t mac_SetMACTRXState(uint8_t state)
{
    return mac_adapter.set_trx_state(state);
}

/**
*
* @fn uint8_t  mac_GetMACTRXState(void)
*
* @brief User can use this function to get current the RF state.
*        The state includes TX, RX, TRX auto switch and TRX off.
*
* @param None
*
* @return The current RF state.
* @retval TRANSCEIVER_TRX_AUTO TRX auto switch
* @retval TRANSCEIVER_RX_ON RX only
* @retval TRANSCEIVER_TX_ON TX only
* @retval TRANSCEIVER_TRX_OFF TRX off
*
*/
static __inline uint8_t mac_GetMACTRXState(void)
{
    return mac_adapter.get_trx_state();
}

/**
*
* @fn uint8_t  mac_SetChannel(uint8_t  channel)
*
* @brief This function is used to change RF channel between 11 ~ 26.
*
* @param channel Channel number. Value range is 11~26.
*
* @return The result of changing channel.
* @retval MAC_STS_SUCCESS Set channel successfully.
* @retval MAC_STS_INVALID_PARAMETER The channel number is out of range.
*
*/
static __inline uint8_t mac_SetChannel(uint8_t ch)
{
    return mac_adapter.set_channel(ch);
}

/**
*
* @fn uint8_t mac_SetTXPower(int8_t tx_dbm)
*
* @brief This function is used to set the RF TX power.
*
* @param tx_dbm the TX power in 0.5dBm unit
*
* @return The TX gain index for this TX power setting.
*
*/
static __inline uint8_t mac_SetTXPower(int8_t tx_dbm)
{
#ifdef ROM_PATCH_SETTXPOWER
    extern uint8_t mac_SetTXPower_patch(int8_t tx_dbm);
    return mac_SetTXPower_patch(tx_dbm);
#else
    return mac_adapter.set_tx_power(tx_dbm);
#endif
}

/**
*
* @fn uint8_t  mac_GetChannel(void)
*
* @brief Read current RF channel
*
* @param None
*
* @return RF channel, range 11-26
*
*/
static __inline uint8_t mac_GetChannel(void)
{
    return mac_adapter.get_channel();
}

/**
*
* @fn int8_t mac_GetRSSIFromRaw(uint16_t rssi_raw, uint8_t channel)
*
* @brief Get RSSI value from current raw data
*
* @param rssi_raw RSSI raw data from phy layer
*
* @param channel Channel number. Value range is 11~26.
*
* @return RSSI value (dbm)
*
*/
static __inline int8_t mac_GetRSSIFromRaw(uint16_t rssi_raw, uint8_t channel)
{
    return mac_adapter.get_rssi_from_raw(rssi_raw, channel);
}

/*
  PIB
*/
/**
*
* @fn void mac_SetPANId(uint16_t  pid)
*
* @brief Set IEEE 802.15.4 destination PAN id
*
* @param pid 16 bits length PAN identifier
*
* @return None
*
*/
static __inline void mac_SetPANId(uint16_t pid)
{
    mac_adapter.SetPANId(pid);
}

/**
*
* @fn void mac_GetPANId(uint16_t  pid)
*
* @brief Get IEEE 802.15.4 destination PAN id
*
* @return 16 bits length PAN identifier
*
*/
static __inline uint16_t mac_GetPANId(void)
{
    return mac_adapter.GetPANId();
}

/**
*
* @fn void mac_SetShortAddress(uint16_t  sadr)
*
* @brief Set IEEE 802.15.4 destination network(short) address
*
* @param sadr 16 bits length network(short) address
*
* @return None
*
*/
static __inline void mac_SetShortAddress(uint16_t sadr)
{
    mac_adapter.SetShortAddress(sadr);
}

/**
*
* @fn void mac_SetLongAddress(uint8_t  *ladr)
*
* @brief Set IEEE 802.15.4 destination extend(long) address
*
* @param *ladr 64 bits extend(long) address pointer
*
* @return None
*

*/
static __inline void mac_SetLongAddress(uint8_t  *ladr)
{
    mac_adapter.SetLongAddress(ladr);
}

/**
*
* @fn void mac_SetCoordinatorShortAddress(uint16_t  sadr)
*
* @brief Set associated coordinator short address for slotted network synchronization.
*
* @param sadr Associated coordinator short address.
*
* @return None
*
*/
static __inline void mac_SetCoordinatorShortAddress(uint16_t sadr)
{
    mac_adapter.SetCoordinatorShortAddress(sadr);
}

/**
*
* @fn void mac_SetCoordinatorLongAddress(uint8_t  *ladr)
*
* @brief Set associated coordinator long address for slotted network synchronization.
*
* @param *ladr 64 bits extend(long) address pointer
*
* @return None
*
*/
static __inline void mac_SetCoordinatorLongAddress(uint8_t  *ladr)
{
    mac_adapter.SetCoordinatorLongAddress(ladr);
}

/**
*
* @fn void mac_SetGroupAddress(uint8_t  *gpadr)
*
* @brief Set EUI-64 group address of this device is belong to.
*
* @param *gpadr 64 bits EUI-64 group address pointer
*
* @return None
*
*/
static __inline void mac_SetGroupAddress(uint8_t *gpadr)
{
    mac_adapter.SetGroupAddress(gpadr);
}

/**
*
* @fn uint8_t mac_SetTXNMaxRetry(uint8_t max_retry)
*
* @brief Set the maximum retry count of the Normal FIFO transmission.
*
* @param max_retry the maximum retry count
*
* @return Status
* @retval MAC_STS_SUCCESS Maximum retry set OK
*
*/
static __inline uint8_t mac_SetTxNMaxRetry(uint8_t max_retry)
{
    return mac_adapter.SetTxNMaxRetry(max_retry);
}

/**
*
* @fn void  mac_SetTXGain(uint8_t tx_gain)
*
* @brief Set RF TX power index
*
* @param tx_gain the TX gain to set
*
* @return None
*
*/
static __inline void mac_SetTXGain(uint8_t tx_gain)
{
    mac_adapter.SetTXGain(tx_gain);
}

/**
*
* @fn uint8_t  mac_GetTXGain(void)
*
* @brief Get current TX gain index setting value
*
* @return current TX gain control register value
*
*/
static __inline uint8_t mac_GetTXGain(void)
{
    return mac_adapter.GetTXGain();
}

/**
*
* @fn void mac_SetMaxCSMABackoffs(uint8_t MaxCSMABackoffs)
*
* @brief This function sets the maximum value of BACKOFF parameter of the TX CSMACA algorithm.
*        The paramater effects only TX normal FIFO.
*
* @param MaxCSMABackoffs the max BACKOFF numbers. The value range is 0 ~ 7.
*
* @return None
*
*/
static __inline void mac_SetMaxCSMABackoffs(uint8_t MaxCSMABackoffs)
{
    mac_adapter.SetMaxCSMABackoffs(MaxCSMABackoffs);
}

/**
*
* @fn uint32_t mac_GetTxNStatus(void)
*
* @brief Get latese TX error status
*
* @return the latest TX error status:
*         bit0: Normal FIFO TX status
*         bit1: GTS1 FIFO TX status
*         bit2: GTS2 FIFO TX status
*         bit3: GTS1 TX slot time not enough
*         bit4: GTS2 TX slot time not enough
*         bit5: CCA status
*
*/
static __inline uint32_t mac_GetTxNStatus(void)
{
    return mac_adapter.GetTxNStatus();
}

/**
*
* @fn uint32_t mac_GetTxTermedStatus(void)
*
* @brief Get latese TX termed status
*
* @return the latest TX error status:
*         bit0: GTS2 FIFO TX termed
*         bit1: GTS1 FIFO TX termed
*         bit2: Normal FIFO TX termed
*         bit3: Beacon FIFO Tx termed
*
*/
static __inline uint32_t mac_GetTxTermedStatus(void)
{
    return mac_adapter.GetTxTermedStatus();
}

/**
*
* @fn uint8_t  mac_GetTxNRetryTimes(void)
*
* @brief Get last TxN retry times
*
* @param None
*
* @return Last TxN retry times 0-3
*
*/
static __inline uint8_t mac_GetTxNRetryTimes(void)
{
    return mac_adapter.GetTxNRetryTimes();
}

/*
  RX filter
*/
/**
*
* @fn void mac_SetPromiscuous(uint8_t en)
*
* @brief Set promiscuous mode stauts
*
* @param en Disable 0/Enable 1
*
* @return None
*
*/
static __inline void mac_SetPromiscuous(uint8_t en)
{
    mac_adapter.SetPromiscuous(en);
}

/**
*
* @fn uint8_t  mac_GetPromiscuous(void)
*
* @brief Get promiscuous mode status
*
* @param None
*
* @return Disable 0/Enable 1
*
*/
static __inline uint8_t mac_GetPromiscuous(void)
{
    return mac_adapter.GetPromiscuous();
}

/**
*
* @fn void mac_SetScanMode(uint8_t en)
*
* @brief Set scan mode stauts
*
* @param en Disable 0/Enable 1
*
* @return None
*
*/
static __inline void mac_SetScanMode(uint8_t en)
{
    mac_adapter.SetScanMode(en);
}

/**
*
* @fn uint8_t  mac_GetScanMode(void)
*
* @brief Get scan mode status
*
* @param None
*
* @return Disable 0/Enable 1
*
*/
static __inline uint8_t mac_GetScanMode(void)
{
    return mac_adapter.GetScanMode();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSeq(void)
*
* @brief Get Rx frame sequence number
*
* @param None
*
* @return rx frame sequence number
*
*/
static __inline uint8_t mac_GetRxFrmSeq(void)
{
    return mac_adapter.GetRxFrmSeq();
}

/**
*
* @fn uint8_t  mac_GetRxFrmAckReq(void)
*
* @brief Check Rx frame with ack request
*
* @param None
*
* @return Disable 0/Enable 1
*
*/
static __inline uint8_t mac_GetRxFrmAckReq(void)
{
    return mac_adapter.GetRxFrmAckReq();
}

/**
*
* @fn uint8_t  mac_GetRxFrmType(void)
*
* @brief Get Rx frame type
*
* @param None
*
* @retval 0x0 Beacon
*         0x1 Data
*         0x2 Ack
*         0x3 MAC command
*         0x4 Reserved
*         0x5 Multiple
*         0x6 Fragment
*         0x7 Extended
*
*/
static __inline uint8_t mac_GetRxFrmType(void)
{
    return mac_adapter.GetRxFrmType();
}

/**
*
* @fn uint8_t  mac_GetRxFrmVersion(void)
*
* @brief Get Rx frame version
*
* @param None
*
* @retval 0x0 IEEE 802.15.4 2003
*         0x1 IEEE 802.15.4 2006
*         0x2 IEEE 802.15.4 2015
*         0x3 Resrved
*
*/
static __inline uint8_t mac_GetRxFrmVersion(void)
{
    return mac_adapter.GetRxFrmVersion();
}

/**
*
* @fn uint8_t  mac_GetRxFrmPanidCompress(void)
*
* @brief Check Rx frame with panid compress
*
* @param None
*
* @return Disable 0/Enable 1
*
*/
static __inline uint8_t mac_GetRxFrmPanidCompress(void)
{
    return mac_adapter.GetRxFrmPanidCompress();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSecEn(void)
*
* @brief Check Rx frame with security
*
* @param None
*
* @return Disable 0/Enable 1
*
*/
static __inline uint8_t mac_GetRxFrmSecEn(void)
{
    return mac_adapter.GetRxFrmSecEn();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSecLevel(void)
*
* @brief Get Rx frame security level
*
* @param None
*
* @retval 0x0 None
*         0x1 MIC-32
*         0x2 MIC-64
*         0x3 MIC-128
*         0x4 ENC
*         0x5 ENC-MIC-32
*         0x6 ENC-MIC-64
*         0x7 ENC-MIC-128
*
*/
static __inline uint8_t mac_GetRxFrmSecLevel(void)
{
    return mac_adapter.GetRxFrmSecLevel();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSecKeyIdMode(void)
*
* @brief Get Rx frame security key id mode
*
* @param None
*
* @retval 0x0~0x03
*
*/
static __inline uint8_t mac_GetRxFrmSecKeyIdMode(void)
{
    return mac_adapter.GetRxFrmSecKeyIdMode();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSecKeyId(void)
*
* @brief Get Rx frame security key id
*
* @param None
*
* @return security key id
*
*/
static __inline uint8_t mac_GetRxFrmSecKeyId(void)
{
    return mac_adapter.GetRxFrmSecKeyId();
}

/**
*
* @fn uint8_t  mac_GetRxFrmSrcAddrMode(void)
*
* @brief Get Rx frame source address mode
*
* @param None
*
* @retval 0x0 Not present
*         0x1 Reserved
*         0x2 short
*         0x3 extended
*
*/
static __inline uint8_t mac_GetRxFrmSrcAddrMode(void)
{
    return mac_adapter.GetRxFrmSrcAddrMode();
}

/**
*
* @fn uint16_t  mac_GetRxFrmShortAddr(void)
*
* @brief Get Rx frame short address
*
* @param None
*
* @return short address
*
*/
static __inline uint16_t mac_GetRxFrmShortAddr(void)
{
    return mac_adapter.GetRxFrmShortAddr();
}

/**
*
* @fn uint8_t  mac_GetRxFrmLongAddr(void)
*
* @brief Get Rx frame extended address
*
* @param None
*
* @return extended address
*
*/
static __inline uint64_t mac_GetRxFrmLongAddr(void)
{
    return mac_adapter.GetRxFrmLongAddr();
}

/*
  CCA and EDScan
*/
/**
*
* @fn void mac_EnTxNCsmacaCca(void)
*
* @brief Enable CSMA/CA function for TxN FIFO.
*
* @param None
*
* @return None
*
*/
static __inline void mac_EnTxNCsmacaCca(void)
{
    mac_adapter.enable_txn_csmacca();
}

/**
*
* @fn void mac_DisTxNCsmacaCca(void)
*
* @brief Disable CSMA/CA function for TxN FIFO.
*
* @param None
*
* @return None
*
*/
static __inline void mac_DisTxNCsmacaCca(void)
{
    mac_adapter.disable_txn_csmacca();
}

/**
*
* @fn void mac_SetCcaMode(mac_cca_mode_t cca_mode)
*
* @brief Select the CCA mode of CSMA-CA for frame TX.
*
* @param cca_mode the selected CCA mode
*               MAC_CCA_NONE(0)   disable CCA
*               MAC_CCA_ED(1)     Energy Detection mode
*               MAC_CCA_CS(2)     Carrier Sense mode
*               MAC_CCA_CS_ED(3)  CS or ED combination mode
*               MAC_CCA_CS_ED_AND(4)  CS and ED combination mode
*
* @return None
*
*/
static __inline void mac_SetCcaMode(mac_cca_mode_t cca_mode)
{
    mac_adapter.set_ccamode(cca_mode);
}

/**
*
* @fn int8_t mac_GetCcaEDThreshold(void)
*
* @brief Get CCA ED mode threshold.
*
* @return CCA ED mode threshold
*
*/
static inline int8_t mac_GetCcaEDThreshold(void)
{
    return mac_adapter.GetCcaEDThreshold();
}

/**
*
* @fn uint8_t mac_EDScanExt(uint32_t scan_duration, int8_t *ed_peak_lev, int8_t *ed_avrg_lev)
*
* @brief To do a energy detection scan for a given duration on current channel and
*        report the maximum energy level detected during this scan.
*
* @param scan_duration the duration of this ED scan, in unit of us.
*
* @param ed_peak_lev to return the peak energy level of this ED scan.
*
* @param ed_avrg_lev to return the average energy level of this ED scan.
*
* @return The function result.
* @retval MAC_STS_SUCCESS ED scan successfully.
* @retval MAC_STS_INVALID_PARAMETER ED level return buffer is NULL.
* @retval MAC_STS_CANCELED ED scan is canceled by FW or FW trigger TXN
* @retval MAC_STS_PHY_GRANT_FAILED ED scan is failed due to PHY grant failed
* @retval MAC_STS_TIMEOUT ED scan is failed due to wait PHY report timeout
*
*/
static __inline uint8_t mac_EDScanExt(uint32_t scan_duration, int8_t *ed_peak_lev,
                                      int8_t *ed_avrg_lev)
{
    return mac_adapter.edscan_ext(scan_duration, ed_peak_lev, ed_avrg_lev);
}

/**
*
* @fn uint8_t mac_EDScanSchedule(uint32_t scan_duration, mac_ed_scan_callback_t callback)
*
* @brief To start a scheduled ED scan (non-blocking ED scan) procedure.
*
* @param scan_duration the duration of this ED scan, in unit of us.
*
* @param callback the callback function for ED scan done event.
*
* @return The function result.
* @retval MAC_STS_SUCCESS Scheduled ED scan start successfully.
* @retval MAC_STS_INVALID_PARAMETER call this function with invalid arguments.
* @retval MAC_STS_TEMPORARY_UNAVAILABLE previous scheduled ED scan process is not finished yet.
*
*/
static __inline uint8_t mac_EDScanSchedule(uint32_t scan_duration, mac_ed_scan_callback_t callback)
{
    return mac_adapter.edscan_schedule(scan_duration, callback);
}

/**
*
* @fn void mac_EDScanScheduleCancel(void)
*
* @brief To cancel a started scheduled ED scan process.
*
* @return None
*
*/
static __inline void mac_EDScanScheduleCancel(void)
{
    mac_adapter.edscan_cancel();
}

/*
  Software Timer
*/
/**
*
* @fn void mac_SoftwareTimer_Init(mac_timer_handle_t *ptmr_entities, uint8_t tmr_num)
*
* @brief Initial MAC driver software timer handler.
*
* @param ptmr_entities the software timer handler entities list
*
* @param tmr_num number of software timer handler in the entities list
*
* @return None
*
*/
static __inline void mac_SoftwareTimer_Init(mac_timer_handle_t *ptmr_entities, uint8_t tmr_num)
{
    mac_adapter.swtimer_init(ptmr_entities, tmr_num);
}

/**
*
* @fn uint8_t mac_SoftwareTimer_Alloc(void *pcallback, void *parg)
*
* @brief Allocate a MAC software handler from free timer handler pool.
*
* @return the allocated timer handler
*
*/
static __inline pmac_timer_handle_t mac_SoftwareTimer_Alloc(void)
{
    return mac_adapter.swtimer_alloc();
}

/**
*
* @fn void mac_SoftwareTimer_Free(pmac_timer_handle_t pmac_tmr)
*
* @brief Free a MAC timer handler
*
* @param pmac_tmr the MAC timer handler to be free
*
* @return None
*
*/
static __inline void mac_SoftwareTimer_Free(pmac_timer_handle_t pmac_tmr)
{
    mac_adapter.swtimer_free(pmac_tmr);
}

/**
*
* @fn void mac_SoftwareTimer_Start(pmac_timer_handle_t pmac_tmr, mac_bt_clk_t bt_clk)
*
* @brief Start a MAC timer with a given time stamp (BT clock) of timeout event be triggered.
*
* @param pmac_tmr the MAC timer handler to be started
*
* @param timeout the time stamp (base on BT clock) to trigger timeout
*
* @param pcallback the callback function for timeout event which will be called in timer
*                  interrupt handler
*
* @param arg the argument of the timeout callback function
*
* @return None
*
*/
static __inline void mac_SoftwareTimer_Start(pmac_timer_handle_t pstart_tmr, uint32_t timeout,
                                             void *pcallback, void *arg)
{
    mac_adapter.swtimer_start(pstart_tmr, timeout, pcallback, arg);
}

/**
*
* @fn void mac_SoftwareTimer_Stop(pmac_timer_handle_t pstop_tmr)
*
* @brief To stop a running MAC timer.
*
* @param pstop_tmr the MAC timer to be stopped
*
* @return None
*
*/
static __inline void mac_SoftwareTimer_Stop(pmac_timer_handle_t pstop_tmr)
{
    mac_adapter.swtimer_stop(pstop_tmr);
}

/*
  TX
*/
/**
*
* @fn uint8_t  mac_LoadTxNPayload(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO)
*
* @brief Load frame into Tx normal fifo
*
* @param *TxFIFO The tx fifo structure which user wants to transmit.
*
*        +---------+---------+-----------+
*        | 1 byte  | 1 byte  | 125 bytes |
*        +---------+---------+-----------+
*        | HDR LEN | FRM LEN | USER DATA |
*        +---------+---------+-----------+
*
* @return The process status.
* @retval MAC_STS_SUCCESS The TX transmission is successful
* @retval MAC_STS_DATA_LEN_ERROR the frame length is larger than 125 bytes
*
*/
static __inline uint8_t  mac_LoadTxNPayload(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO)
{
    return mac_adapter.LoadTxNPayload(HdrL, FrmL, TxFIFO);
}

/**
*
* @fn uint8_t  mac_TrigTxN(bool_t AckReq, bool_t SecReq)
*
* @brief Set if require ack, security process, then trigger Tx normal FIFO.
*
* @param AckReq Require Tx waitting an ack frame.
* @param SecReq Trigger Tx outgoing security process.
*
* @return Status
* @retval MAC_STS_SUCCESS TxN is triggered.
*
*/
static __inline uint8_t mac_TrigTxN(uint8_t ackreq, uint8_t secreq)
{
    return mac_adapter.trig_txn(ackreq, secreq);
}

/**
*
* @fn void mac_UpdatePreTrigTime(void)
*
* @brief To update the pre-trigger time for TX at given time. Once
*        any PHY delay time setting is modified, this function should
*        be called to recalculate the pre-trigger time.
*
* @param AckReq Require Tx waitting an ack frame.
* @param SecReq Trigger Tx outgoing security process.
*
* @return Status
* @retval MAC_STS_SUCCESS TxN is triggered.
*
*/
static __inline void mac_UpdatePreTrigTime(void)
{
    mac_adapter.update_pretrig_time();
}

/**
* @fn uint8_t  mac_TrigTxNAtTime(bool_t AckReq, mac_bt_clk_t tx_time)
*
* @brief Set if require ack, then enable normal FIFO TX with a specified
*        trigger time.
*
* @param AckReq Require Tx waitting an ack frame.
* @param DoCCA Require to do CCA before TX.
* @param TxTime The time to trigger Tx.
*
* @return Status
* @retval MAC_STS_SUCCESS TxN is triggered.
* @retval MAC_STS_TRANSMISSION_TIME_NOT_ENOUGH the specified TXN trigger time is past.
*
*/
static __inline uint8_t mac_TrigTxNAtTime(uint8_t ackreq, uint8_t secreq, uint8_t docca,
                                          mac_bt_clk_t txtime)
{
    return mac_adapter.trig_txn_at(ackreq, secreq, docca, txtime);
}

/**
*
* @fn void mac_SetTxEnhAckPending (uint8_t len)
*
* @brief Set the pending enhanced ack frame length
*
* @param len
*
* @return None
*
*/
static __inline void mac_SetTxEnhAckPending(uint8_t len)
{
    mac_adapter.SetTxEnhAckPending(len);
}

/**
*
* @fn uint8_t mac_GetTxEnhAckPending (void)
*
* @brief Set the pending enhanced ack frame length
*
* @param None
*
* @return pending enhanced ack frame length
*
*/
static __inline uint8_t mac_GetTxEnhAckPending(void)
{
    return mac_adapter.GetTxEnhAckPending();
}

/**
*
* @fn uint8_t  mac_LoadTxEnhAckPayload(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO)
*
* @brief Load frame into Tx G1 fifo
*
* @param *TxFIFO The tx fifo structure which user wants to transmit.
*
*        +---------+---------+-----------+
*        | 1 byte  | 1 byte  | 125 bytes |
*        +---------+---------+-----------+
*        | HDR LEN | FRM LEN | USER DATA |
*        +---------+---------+-----------+
*
* @return The process status.
* @retval MAC_STS_SUCCESS The TX transmission is successful
* @retval MAC_STS_DATA_LEN_ERROR the frame length is larger than 125 bytes
*
*/
static __inline uint8_t mac_LoadTxEnhAckPayload(uint8_t HdrL, uint8_t FrmL, uint8_t *TxFIFO)
{
    pmac_txfifo_t pTxG1FIFO = (pmac_txfifo_t)MAC_TXG1_BASE_ADDR;

    // max data length is 125
    if ((FrmL > MAC_MAX_TX_FRM_LEN) || (FrmL < MAC_MIN_TX_FRM_LEN))
    {
        return MAC_STS_DATA_LEN_ERROR;
    }

    pTxG1FIFO->hdr_len = HdrL; //write header length into tx normal fifo
    pTxG1FIFO->frm_len = FrmL; //write frame length into tx normal fifo
    mac_memcpy_rom((void *)pTxG1FIFO->payload, TxFIFO, FrmL); //write data into tx normal fifo

    return MAC_STS_SUCCESS;
}

/**
*
* @fn uint8_t  mac_TrigTxEnhAck(uint8_t early, uint8_t secreq)
*
* @brief Set if require ack, security process, then trigger Tx normal FIFO.
*
* @param early Trigger Tx enhack in rx early interrupt
* @param secreq Trigger Tx enhack outgoing security process.
*
* @return Status
* @retval MAC_STS_SUCCESS Tx enhack is triggered.
*
*/
static __inline uint8_t mac_TrigTxEnhAck(uint8_t early, uint8_t secreq)
{
    return mac_adapter.trig_txenhack(early, secreq);
}

/**
*
* @fn void mac_TrigUpperEnc(void)
*
* @brief Trigger upper layer encrypt process
*
* @param None
*
* @return None
*
*/
static __inline void mac_TrigUpperEnc(void)
{
    mac_adapter.trig_upperenc();
}

/**
*
* @fn void mac_TrigUpperDec(void)
*
* @brief Trigger upper layer decrypt process
*
* @param None
*
* @return None
*
*/
static __inline void mac_TrigUpperDec(void)
{
    mac_adapter.trig_upperdec();
}

/*
  RX
*/
/**
*
* @fn uint8_t  mac_Rx(uint8_t  *RxFIFO)
*
* @brief Read received packet from RX FIFO.
*
* @param *RxFIFO User data buffer pointer. The packet length will be put in the start address of buffer
*
*        +---------+-----------+------------------+--------------+------------+
*        | 1 byte  | 125 bytes | 1 byte | 2 bytes |  4/2 bytes   |  3 bytes   |
*        +---------+-----------+------------------+--------------+------------+
*        | FRM LEN | USER DATA |   LQI  |  RSSI   |  TimeStamp   | SF Count   |
*        +---------+-----------+------------------+--------------+------------+
*
* @return Rx status
* @retval MAC_STS_FAILURE There is no received packet.
* @retval MAC_STS_SUCCESS Retrived one packet
*
*/
static __inline uint8_t mac_Rx(uint8_t *RxFIFO)
{
    return mac_adapter.rx(RxFIFO);
}

/**
*
* @fn void mac_RxFlush(void)
*
* @brief Flush rx fifo
*
* @return None
*
*/
static __inline void mac_RxFlush(void)
{
    mac_adapter.RxFlush();
}

/**
*
* @fn uint8_t mac_RxFIFO(uint8_t *RxFIFO, uint8_t *MorePkt)
*
* @brief Check RX FIFO Full status and read received packet from RX FIFO.
*
* @param *RxFIFO User data buffer pointer.
*
* @param *MorePkt to report if more packet is ready in RX FIFO.
*                 *MorePkt = false: no more new RX packet in FIFO
*                 *MorePkt = true: there is more new RX packet in FIFO
*
* @return Rx status
* @retval MAC_STS_FAILURE There is no received packet.
* @retval MAC_STS_SUCCESS Retrived one packet
*
*/
static __inline uint8_t mac_RxFIFO(uint8_t *RxFIFO, uint8_t *MorePkt)
{
    return mac_adapter.rxfifo(RxFIFO, MorePkt);
}

/*
  Addr Match Filter
*/
/**
*
* @fn void mac_GetSrcMatchStatus(void)
*
* @brief Get source match filter status
*
* @return source match filter status
*
*/
static __inline uint8_t mac_GetSrcMatchStatus(void)
{
    return mac_adapter.GetSrcMatchStatus();
}

/**
*
* @fn void mac_ClrSrcMatchStatus(void)
*
* @brief Clear source match filter status
*
* @return None
*
*/
static __inline void mac_ClrSrcMatchStatus(void)
{
    mac_adapter.ClrSrcMatchStatus();
}

/**
*
* @fn void mac_SetAddrMatchMode(uint8_t mode)
*
* @brief config the mode of auto set frame pending bit for Ack frame
*
* @param mode AUTO_ACK_PENDING_MODE_ZIGBEE: set the pending bit as IEEE802.15.4 Spec;
*             AUTO_ACK_PENDING_MODE_THREAD: set the pending bit as Thread Spec;
*
* @return None
*
*/
static __inline void mac_SetAddrMatchMode(uint8_t mode)
{
    mac_adapter.set_addr_matchmode(mode);
}

/**
*
* @fn uint8_t mac_AddSrcShortAddrMatch(uint16_t short_addr, uint16_t panid)
*
* @brief To add a short address and panid pair to a entry of Source Address Match Filter.
*
* @param short_addr the short address to be added into the Source Address Match Filter.
*
* @param panid the panid to be added into the Source Address Match Filter.
*
* @return The function result.
* @retval MAC_STS_SUCCESS add a new short address entry successfully.
* @retval MAC_STS_HW_LIMIT no free address match entry.
*
*/
static __inline uint8_t mac_AddSrcShortAddrMatch(uint16_t short_addr, uint16_t panid)
{
    return mac_adapter.add_short_match(short_addr, panid);
}

/**
*
* @fn uint8_t mac_DelSrcShortAddrMatch(uint16_t short_addr, uint16_t panid)
*
* @brief To disable a short address match entry by a given short address and panid pair.
*
* @param short_addr the short address of the short address match entry to be disabled
*
* @param panid the panidof the short address match entry to be disabled
*
* @return The function result.
* @retval MAC_STS_SUCCESS disable a short address entry successfully.
* @retval MAC_STS_FAILURE the short address match entry is not found.
*
*/
static __inline uint8_t mac_DelSrcShortAddrMatch(uint16_t short_addr, uint16_t panid)
{
    return mac_adapter.del_short_match(short_addr, panid);
}

/**
*
* @fn void mac_DelAllSrcShortAddrMatch(void)
*
* @brief To disable all short address match entries.
*
* @return None
*
*/
static __inline void mac_DelAllSrcShortAddrMatch(void)
{
    mac_adapter.del_short_match_all();
}

/**
*
* @fn uint8_t mac_AddSrcExtAddrMatch(uint8_t *pext_addr)
*
* @brief To add an extended address match entry of Source Address Match Filter.
*
* @param pext_addr the extended address to be added into the Source Address Match Filter.
*
* @return The function result.
* @retval MAC_STS_SUCCESS add a new short address entry successfully.
* @retval MAC_STS_HW_LIMIT no free address match entry.
*
*/
static __inline uint8_t mac_AddSrcExtAddrMatch(uint8_t *pext_addr)
{
    return mac_adapter.add_ext_match(pext_addr);
}

/**
*
* @fn uint8_t mac_DelSrcExtAddrMatch(uint8_t *pext_addr)
*
* @brief To disable an extended address match entry by a given extended address.
*
* @param pext_addr the extended address of the extended address match entry to be disabled
*
* @return The function result.
* @retval MAC_STS_SUCCESS disable a short address entry successfully.
* @retval MAC_STS_FAILURE the short address match entry is not found.
*
*/
static __inline uint8_t mac_DelSrcExtAddrMatch(uint8_t *pext_addr)
{
    return mac_adapter.del_ext_match(pext_addr);
}

/**
*
* @fn void mac_DelAllSrcExtAddrMatch(void)
*
* @brief To disable all extended address match entries.
*
* @return None
*
*/
static __inline void mac_DelAllSrcExtAddrMatch(void)
{
    mac_adapter.del_ext_match_all();
}

/*
  Security
*/

/**
*
* @fn void mac_SetNonce(uint8_t *nonce)
*
* @brief Set nonce into MAC.
*
* @param nonce the nonce structure to be loaded.
*
* @return None
*
*/
static __inline void mac_SetNonce(uint8_t *nonce)
{
    mac_adapter.SetNonce(nonce);
}

/**
*
* @fn void mac_SetKey(uint8_t *key)
*
* @brief Load key into TxN key fifo.
*
* @param key_buf the key_buf to be loaded.
*
* @param key the key to be loaded.
*
* @return None
*
*/
static __inline void mac_SetKey(uint8_t *key_buf, uint8_t *key)
{
    mac_adapter.SetKey(key_buf, key);
}

/**
*
* @fn void mac_LoadNonce(uint8_t *nonce)
*
* @brief Load nonce into MAC.
*
* @param nonce the nonce structure to be loaded.
*
* @return None
*
*/
static __inline void mac_LoadNonce(uint8_t *nonce)
{
    mac_adapter.LoadNonce(nonce);
}

/**
*
* @fn void mac_LoadTxNKey(uint8_t *key)
*
* @brief Load key into TxN key fifo.
*
* @param key the TxN key to be loaded.
*
* @return None
*
*/
static __inline void mac_LoadTxNKey(uint8_t *key)
{
    mac_adapter.LoadTxNKey(key);
}

/**
*
* @fn void mac_SetTxNChiper(uint8_t level)
*
* @brief config the security level of Normal FIFO cipher
*
* @param level the security level(as the defination in IEEE802.15.4 MAC Spec.)
*
* @return None
*
*/
static __inline void mac_SetTxNChiper(uint8_t level)
{
    mac_adapter.SetTxNChiper(level);
}

/**
*
* @fn void mac_LoadTxEnhAckKey(uint8_t *key)
*
* @brief Load key into TxG1 key fifo.
*
* @param key the TxG1 key to be loaded.
*
* @return None
*
*/
static __inline void mac_LoadTxEnhAckKey(uint8_t *key)
{
    mac_adapter.LoadTxEnhAckKey(key);
}

/**
*
* @fn void mac_SetTxEnhAckChiper(uint8_t level)
*
* @brief config the security level of GTS1 FIFO cipher
*
* @param level the security level(as the defination in IEEE802.15.4 MAC Spec.)
*
* @return None
*
*/
static __inline void mac_SetTxEnhAckChiper(uint8_t level)
{
    mac_adapter.SetTxEnhAckChiper(level);
}

/**
*
* @fn uint8_t mac_GetSecMICLEN(uint8_t level)
*
* @brief Get the length of current security level.
*
* @param level the security level(as the defination in IEEE802.15.4 MAC Spec.)
*
* @return the MIC length of current security level.
*
*/
static __inline uint8_t mac_GetSecMICLEN(uint8_t level)
{
    return mac_adapter.secmode_mic_len[level];
}

/**
*
* @fn uint8_t mac_GetSecHLEN(void)
*
* @brief Get the length of current receiving frame header
*
* @param None
*
* @return the frame header length of current receiving frame
*
*/
static __inline uint8_t mac_GetSecHLEN(void)
{
    return mac_adapter.GetSecHLEN();
}

/**
*
* @fn void mac_SetSecHLEN(uint8_t val)
*
* @brief Set the frame header length for frame decryption in RX FIFO
*
* @param val the secure frame header length
*
*/
static __inline void mac_SetSecHLEN(uint8_t val)
{
    mac_adapter.SetSecHLEN(val);
}

/**
*
* @fn void mac_SetRxChiper(uint8_t level)
*
* @brief config the security level of RX FIFO cipher
*
* @param level the security level(as the defination in IEEE802.15.4 MAC Spec.)
*
* @return None
*
*/
static __inline void mac_SetRxChiper(uint8_t level)
{
    mac_adapter.SetRxChiper(level);
}

/**
*
* @fn void mac_TrigRxDecryption(void)
*
* @brief Trigger the received secure frame decryption process,
*        MAC HW will issue RX done interrupt when decryption is finished.
*        RX FIFO decryption finish status is indicated by rxnif
*        (RX done interrupt).
*        The MIC error status is indicated by MAC->rxm_sts_b.secdecerr once
*        the decryption is done.
*
* @param None
*
* @return None
*
*/
static __inline void mac_TrigRxDecryption(void)
{
    mac_adapter.TrigRxDecryption();
}

/**
*
* @fn void mac_IgnoreRxDec(void)
*
* @brief Ignore the received secure frame decryption process.
*
* @param None
*
* @return None
*
*/
static __inline void mac_IgnoreRxDec(void)
{
    mac_adapter.IgnoreRxDec();
}

/**
*
* @fn uint8_t  mac_UpperCipher(uint8_t  SecMode, uint8_t  *SecKey, uint8_t  *SecNonce)
*
* @brief Using TX normal FIFO to do upper cipher encryption. The data to be encrypted
*        should be filled into the TX Normal FIFO before calling this function. It should follow
*        the structure of the TX FIFO format.
*        The encrypted data will be stored to the TX Normal FIFO and replace the origional data.
*
* @param SecMode Security mode.
* @param *SecKey Security key pointer, security key is 16 bytes.
* @param SecNonce Security nonce, nonce is 13 bytes
*
* @return Process status.
* @retval MAC_STS_SUCCESS Encryption success.
* @retval MAC_STS_UNSUPPORT_SECURITY_MODE
* @retval MAC_STS_DATA_LEN_ERROR
* @retval MAC_STS_SECURITY_FAILED
*
*/
static __inline uint8_t mac_UpperCipher(uint8_t SecMode, uint8_t *SecKey, uint8_t *SecNonce)
{
    return mac_adapter.upper_cipher(SecMode, SecKey, SecNonce);
}

/**
*
* @fn uint8_t  mac_UpperDecipher(uint8_t  *TxFIFO, uint8_t  SecMode, uint8_t  *SecKey, uint8_t  *SecNonce)
*
* @brief Using TX normal FIFO to do upper cipher decryption. The data to be decrypted
*        should be filled into the TX Normal FIFO before calling this function. It should follow
*        the structure of the TX FIFO format.
*        The decrypted data will be stored to the TX Normal FIFO and replace the origional data.
*
* @param SecMode Security mode.
* @param *SecKey Security key pointer, security key is 16 bytes.
* @param SecNonce Security nonce, nonce is 13 bytes
*
* @return Process status.
* @retval MAC_STS_SUCCESS Encryption success.
* @retval MAC_STS_UNSUPPORT_SECURITY_MODE
* @retval MAC_STS_DATA_LEN_ERROR
* @retval MAC_STS_SECURITY_FAILED
*
*/
static __inline uint8_t mac_UpperDecipher(uint8_t SecMode, uint8_t *SecKey, uint8_t *SecNonce)
{
    return mac_adapter.upper_decipher(SecMode, SecKey, SecNonce);
}

/**
*
* @fn uint32_t mac_GetRetentionRegSize(void)
*
* @brief To get the required buffer size for default registers backup list.
*
* @param None
*
* @return the required buffer size, in byte, for registers backup
*
*/
static __inline uint32_t mac_GetRetentionRegSize(void)
{
    return mac_adapter.get_retention_reg_size();
}

/**
*
* @fn *mac_BackupRetenReg(uint8_t *preten_buf)
*
* @brief To backup MAC registers before entring sleep mode.
*        the registers to backup are listed in preten_reg32b_list,
*        preten_reg16b_list, preten_reg8b_list
*
* @param preten_buf the buffer for registers backup. It can be NULL if
*                   no register backup is required.
*
* @return point to the end of register stored memory
*
*/
static __inline void *mac_BackupRetenReg(uint8_t *preten_buf)
{
    return mac_adapter.backup_reten_reg(preten_buf);
}

/**
*
* @fn void *mac_RestoreRetenReg(uint8_t *preten_buf)
*
* @brief To restore MAC registers after resume from sleep mode.
*
* @param preten_buf the buffer for registers backup. this function
*                   will get register backup value from this buffer
*                   for restoring.
*
* @return point to the end of register stored memory
*
*/
static __inline void *mac_RestoreRetenReg(uint8_t *preten_buf)
{
    return mac_adapter.restore_reten_reg(preten_buf);
}

/**
*
* @fn void mac_PTA_Enable(uint8_t enable)
*
* @brief Enable or disable MAC PTA control function.
*        if PTA is enabled, MAC will send PTA request to grant
*        antenna when packets TX/RX.
*
* @param enable PTA enable: 1: enable; 0: disable
*
* @return None
*
*/
static __inline void mac_PTA_Enable(uint8_t enable)
{
    mac_adapter.PTA_Enable(enable);
}

/**
*
* @fn void mac_PTA_PrityDutyEnable(uint8_t enable)
*
* @brief Enable or disable PTA priority duty control function.
*        If PTA priority duty control is enabled, MAC will send PTA request
*        to grant antenna for idle RX periodically.
*
* @param enable 1: enable; 0: disable
*
* @return None
*
*/
static __inline void mac_PTA_PrityDutyEnable(uint8_t enable)
{
    mac_adapter.PTA_PrityDutyEnable(enable);
}

/**
*
* @fn void mac_PTA_LoRXReq_Enable(uint8_t enable)
*
* @brief Enable or disable issue PTA request for low priority RX.
*        Control of whether to issue a low priority RX PTA request for
*        802.15.4 idle RX. Default is enabled.
*
* @param enable enable to issue low priority RX PTA request
*
* @return None
*
*/
static __inline void mac_PTA_LoRXReq_Enable(uint8_t enable)
{
    mac_adapter.PTA_LoRXReq_Enable(enable);
}

/**
*
* @fn void mac_PTA_ShareLNA(uint8_t is_share_lan)
*
* @brief To setup whether the 802.15.4 PHY share the same LNA with WLan.
*        802.15.4 PHY PTA should be configured accorrding to whether the RF
*        share the same LNA with WLan. If it's sharing the LNA, the 802.15.4
*        PTA should not issue high priority RX PTA request for RX hit.
*
* @param is_share_lna indicate to PTA hardware for whether RF is sharing
*                     LNA with WLan, default is 'true'
*
* @return None
*
*/
static __inline void mac_PTA_ShareLNA(uint8_t is_share_lna)
{
    mac_adapter.PTA_ShareLNA(is_share_lna);
}

/**
*
* @fn void mac_PTA_CCAReq_Enable(uint8_t enable)
*
* @brief To configure whether issue a RX PTA request for the CCA
*        of a packet TX.
*
* @param enable 0: no dedicated RX PTA Req for CCA, only a TX PTA Req
*                  for CCA and packet TX. (default)
*               1: a separate RX PTA Req for CCA, another TX PTA Req
*                  for packet TX.
*
* @return None
*
*/
static __inline void mac_PTA_CCAReq_Enable(uint8_t enable)
{
    mac_adapter.PTA_CCAReq_Enable(enable);
}

/**
*
* @fn void mac_PTA_TXReq_Pri(uint8_t priority)
*
* @brief To configure the priority of TX PTA request for a packet TX.
*
* @param hi_priority 0: low priority (default)
*                 1: high priority
*
* @return None
*
*/
static __inline void mac_PTA_TXReq_Pri(uint8_t hi_priority)
{
    mac_adapter.PTA_TXReq_Pri(hi_priority);
}

/**
*
* @fn void mac_PTA_DutySetTick(uint32_t tick_us)
*
* @brief Set the tick time of PTA duty interval control, in us unit.
*        the PTA high/low priority period setting is based on this tick time.
*
* @param tick_us time for a tick, in micro-second.
*
* @return None
*
*/
static __inline void mac_PTA_DutySetTick(uint32_t tick_us)
{
    mac_adapter.PTA_DutySetTick(tick_us);
}

/**
*
* @fn void mac_PTA_DutySetRatio(uint32_t high_ticks, uint32_t low_ticks)
*
* @brief Set the time period of PTA high/low priority duty, in unit of PTA ticks.
*        the MAC will issue a high priority PTA request at start of every high priority
*        duty interval.
*
* @param high_ticks the time period of PTA high priority duty, in unit of PTA ticks
*
* @param low_ticks the time period of PTA low priority duty, in unit of PTA ticks
*
* @return None
*
*/
static __inline void mac_PTA_DutySetRatio(uint32_t high_ticks, uint32_t low_ticks)
{
    mac_adapter.pta_duty_set_ratio(high_ticks, low_ticks);
}

/**
*
* @fn void mac_DisBTClkTmr(uint32_t tid)
*
* @brief Disable a BT clock timer if it is running (enabled)
*
* @param tid the ID of BT clock timer to be disable
*
* @return None
*
*/
static __inline void mac_DisBTClkTmr(uint32_t tid)
{
    mac_adapter.DisBTClkTmr(tid);
}

static __inline void BT_HCIRstStart_Callback(void)
{
    mac_adapter.bt_hci_reset_start();
}

static __inline void BT_HCIRstEnd_Callback(void)
{
    mac_adapter.bt_hci_reset_end();
}

/**
*
* @fn void mac_GrantPHYReq(uint8_t slot_num)
*
* @brief Request to grant the PHY
*
* @param slot_offset the number of slot offset from current BT slot number to grant the PHY
*
* @return None
*
*/

static __inline void mac_GrantPHYReq(uint8_t slot_offset)
{
    mac_adapter.grant_phy_req(slot_offset);
}

#ifdef __cplusplus
}
#endif

#endif    // end of #ifndef _MAC_DRIVER_H_
