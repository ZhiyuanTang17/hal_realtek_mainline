/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef SYSTEM_RTL876X_NS_H
#define SYSTEM_RTL876X_NS_H


/*============================================================================*
 *                      Headers
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>

/** @defgroup SYSTEM_RTL876X_API  System RTL876X
  * @brief CMSIS API sets for RTL876x Device Series
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                      Types
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_types System RTL876X Exported types
  * @{
  */


typedef enum
{
    SYSTEM_CALL_SET_XTAL_POWER_IN_DLPS   = 0x01,
    SYSTEM_CALL_BYPASS_PMU_CHECK_FOR_WFI = 0x02,
    SYSTEM_CALL_DISABLE_XIP_ACCESS       = 0x03
} T_SYSTEM_CALL_OPCODE;

typedef bool (*APP_MAIN_FUNC)();
typedef void (*USER_CALL_BACK)();

/** End of SYSTEM_RTL876X_Exported_types
  * @}
  */

/*============================================================================*
 *                      Variables
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Variables System RTL876X Exported Variables
  * @{
  */
extern uint32_t SystemCoreClock;

extern APP_MAIN_FUNC app_pre_main;
extern APP_MAIN_FUNC app_main;

extern USER_CALL_BACK app_pre_main_cb;
extern USER_CALL_BACK os_patch_init;

/** End of SYSTEM_RTL876X_Exported_Variables
  * @}
  */



/*============================================================================*
 *                      Functions
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Functions System RTL876X Sets Exported Functions
  * @brief
  * @{
  */

extern void SystemCall(uint32_t opcode, uint32_t parm);

/** End of SYSTEM_RTL876X_Exported_Functions
  * @}
  */

/** End of SYSTEM_RTL876X_API
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_RTL876X_H */

