/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    wdt.h
  * @brief   This file provides apis for watch dog timer.
  * @author  Grace
  * @date    2022-04-27
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __WDT_H_
#define __WDT_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "wdt/inc/rtl_wdt.h"

/*============================================================================*
 *                               Private Function
*============================================================================*/
extern void WDG_SystemReset(WDTMode_TypeDef wdt_mode, int reset_reason);

/** @defgroup HAL_WDT       HAL WDT
  * @brief
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup HAL_WDT_Exported_Types HAL WDT Exported Types
  * @brief
  * @{
  */

typedef enum
{
    HW_RESET              =  0x00,
    CORE_WDT_RESET_LV0    =  0x01,
    CORE_WDT_RESET_LV1    =  0x02,
    AON_WDT_RESET_LV0     =  0x03,
    AON_WDT_RESET_LV1     =  0x04,
    AON_WDT_RESET_DLPS    =  0x05,
    SYSTEM_RESET_REASON   =  0x06,
    WDT_RESET_TYPE_END    =  0xff,
} T_WDT_RESET_TYPE;

/**
  * @brief       Watch Dog Mode structure definition.
  * @note        Watch Dog Eeset reason introduction:
  *              1.If you want to get reset reason from aon 0x15, deviding three types:
  *              a) HW reset: aon reg 0x15 is cleared to 0, magic pattern on ram will change
  *              b) SW RESET_ALL: aon reg 0x15 is cleared to 0,but magic pattern on ram not change
  *              c) SW RESET_ALL_EXCEPT_AON: obtain reset reason by reading aon reg 0x15 .
  *              2. Attention: don't use 0x1 as your reset reason when using RESET_ALL_EXCEPT_AON type! Because 0x1 is default value.
  * @ingroup     HAL_WDT_Exported_Types
  */
typedef enum
{
    RESET_REASON_HW                         = 0x0,  /* HW reset */
    RESET_REASON_WDT_TIMEOUT                = 0x1,
    RESET_REASON_BOOT_EFUSE_INVALID         = 0x2,
    RESET_REASON_BOOT_FLASH_INVALID         = 0x3,
    RESET_REASON_BOOT_RETRY_COUNT_LIMIT     = 0x4,
    RESET_REASON_HARD_FAULT                 = 0x5,
    RESET_REASON_FLASH_IOCTL                = 0x6,
    RESET_REASON_LOWER_STACK                = 0x7,
    RESET_REASON_PASSWORD_DEBUG             = 0x8,
    RESET_REASON_ENTER_FT_MODE              = 0x9,
    RESET_REASON_SWITCH_TO_HCI_MODE         = 0xA,
    RESET_REASON_SWITCH_TO_OTA_MODE         = 0xB,
    RESET_REASON_DFU_FW_RESET               = 0xC,
    RESET_REASON_DFU_UPDATE_IMG             = 0xD,
    RESET_REASON_DFU_UPDATE_IMG_FAIL        = 0xE,
    RESET_REASON_DFU_DISCONN_RSP            = 0xF,
    RESET_REASON_DFU_DISCONN_IND            = 0x10,
    RESET_REASON_ROM_DFU_OPCODE_SYSTEM_RESET = 0x11,
    RESET_REASON_DATATRANS_PATCH_ACTIVE     = 0x12,
    RESET_REASON_DATATRANS_SYSTEM_RESET     = 0x13,
    RESET_REASON_MP_RESET                   = 0x14,
    RESET_REASON_FEATURE_CHECK_FAIL         = 0x15,
    RESET_REASON_FLASH_LAYOUT_OVERFLOW      = 0x16,
    RESET_REASON_DFU_UPDATE_COMPRESSED_IMG  = 0x17,
    RESET_REASON_BRANCH_TO_NS_FAIL          = 0x18,
    RESET_REASON_BRANCH_TO_S_FAIL           = 0x19,
    RESET_REASON_DLPS                       = 0x1A,
    RESET_REASON_POWER_DOWN                 = 0x1B,

    //Compatible for RTL8762C B-cut
    SW_RESET_APP_START              = 0xD0,
    SWITCH_HCI_MODE                 = 0xD1,
    SWITCH_TEST_MODE                = 0xD2,
    DFU_SWITCH_TO_OTA_MODE          = 0xD3,
    DFU_ACTIVE_RESET                = 0xD4,
    DFU_FAIL_RESET                  = 0xD5,
    DFU_TIMEOUT_RESET               = 0xD6,
    DFU_LINK_LOST_RESET             = 0xD7,
    HAL_WRAPPER_RESET               = 0xD8,
    LOW_POWER_RESET                 = 0xD9,
    SWITCH_TO_USB_MODE              = 0xDA,
    SWITCH_TO_TEST_MODE             = 0xDB,
    RESET_REASON_FACTORY_RESET      = 0xDC,
    TRANS_MODE_SWITCH               = 0xDD,
    CLEAR_BOND_INFO                 = 0xDE,
    SWITCH_TO_BLE_FAST_PAIR_TEST_MODE   = 0XDF,
    SWITCH_TO_PPT_FAST_PAIR_TEST_MODE   = 0xE0,
    SWITCH_TO_TEST_MODE_BY_UART     = 0xE1,
    SW_RESET_APP_END                = 0xFF,
} T_SW_RESET_REASON;

/**
 * @brief       Watch Dog Callback
 *
 * @ingroup     HAL_WDT_Exported_Types
 */
typedef bool (*BOOL_WDT_CB)(WDTMode_TypeDef wdt_mode, T_SW_RESET_REASON reset_reason);

/** End of group HAL_WDT_Exported_Types
  * @}
  */

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup HAL_WDT_Exported_Functions HAL WDT Exported Functions
  * @{
  */

/**
  * @brief  Watch Dog System Reset.
  * @param  wdt_mode @ref WDTMode_TypeDef
  * @param  reset_reason @ref T_SW_RESET_REASON
  * @return None.
  */
static inline void WDT_SystemReset(WDTMode_TypeDef wdt_mode, T_SW_RESET_REASON reset_reason)
{
    WDG_SystemReset(wdt_mode, (int) reset_reason);
}

/**
  * @brief  reset reason get
  * @param  none
  * @return reset reason.
  */
static inline T_SW_RESET_REASON reset_reason_get()
{
    extern T_SW_RESET_REASON sw_reset_reason;
    return sw_reset_reason;
}

/**
   * @brief  Watch Dog Reset System
   * @param  type @ref T_WDT_TYPE
   */
void chip_reset(WDTMode_TypeDef wdt_mode);

/** End of group HAL_WDT_Exported_Functions
  * @}
  */

/** End of HAL_WDT
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __WDT_H_ */
