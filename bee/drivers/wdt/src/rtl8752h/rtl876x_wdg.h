/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RTL876X_WDG_H_
#define _RTL876X_WDG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtl876x.h"
#include "rtl876x_bitfields.h"

/** @addtogroup WATCH_DOG WATCH_DOG
  * @brief Watch Dog driver module
  * @{
  */

/** @defgroup WATCH_DOG_Exported_Types Watch Dog Exported Types
  * @{
  */
typedef enum _WDG_MODE
{
    INTERRUPT_CPU = 0,
    RESET_ALL_EXCEPT_AON = 1,
    RESET_CORE_DOMAIN = 2,
    RESET_ALL = 3
} T_WDG_MODE;
/**
  * @}
  */

typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t div_factor  : 16; //[15:0]  R/W Dividing factor. (at least set 1)
        uint32_t en_byte     : 8; //[23:16] R/WSet 0xA5 to enable watch dog timer
        uint32_t clear       : 1; //[24]    W     Write 1 to clear timer
        uint32_t cnt_limit   : 4; //[28:25] R/W   0: 0x001 1: 0x003 .... 10: 0x7FF 11~15: 0xFFF
        uint32_t wdg_mode    : 2; //[29:30] R/W
        uint32_t timeout     : 1; //[31]    R/W1C Watch dog timer timeout. 1 cycle pulse
    } b;
} T_WATCH_DOG_TIMER_REG;

typedef bool (*BOOL_PATCH_FUNC)();

extern BOOL_PATCH_FUNC patch_WDG_Config;

/**
  * @}
  */

/** @defgroup WATCH_DOG_Exported_Functions Watch Dog Exported Functions
  * @{
  */

/**
   * @brief  Watch Dog Clock Enable.
   */
extern void WDG_ClockEnable(void);

/**
   * @brief  Watch Dog Timer Config.
   * @param  div_factor: 16Bit: 32.768k/(1+divfactor).
   * @param  cnt_limit: 2^(cnt_limit+1) - 1 ; max 11~15 = 0xFFF.
   * @param  wdg_mode: 0: interrupt CPU
   *                   1: reset all except aon
   *                   2: reset core domain
   *                   3: reset all
   * @retval none.
   */
extern void WDG_Config(uint16_t div_factor, uint8_t cnt_limit, T_WDG_MODE wdg_mode);

/**
   * @brief  Watch Dog Timer Enable.
   */
extern void WDG_Enable(void);

/**
   * @brief  Watch Dog Timer Disable.
   */
extern void WDG_Disable(void);

/**
   * @brief  Watch Dog Timer Restart.
   */
extern void WDG_Restart(void);

/**
 * @brief  Start Watchdog Timer with specified timeout and mode.
 * @param  time_ms: Timeout value in milliseconds.
 * @param  wdt_mode: Watchdog Timer mode (0: Interrupt, 1: Reset except AON, 2: Reset Core, 3: Reset All)
 * @retval true if started successfully, false otherwise.
 */
bool WDT_Start(uint32_t time_ms, T_WDG_MODE wdt_mode);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif //_RTL876X_WDG_H_
