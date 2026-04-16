/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_WDT_H
#define RTL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "wdt/src/rtl87x2g/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "wdt/src/rtl87x3e/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "wdt/src/rtl87x3d/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "wdt/src/rtl87x2j/rtl_wdt_def.h"
#endif

/** \defgroup WDT         WDT
  * \brief
  * \{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup WDT_Exported_Types WDT Exported Types
  * \brief
  * \{
  */

/**
  * \brief       WDT Mode structure definition.
  *
  * \ingroup     WDT_Exported_Types
  */
typedef enum
{
    RESET_ALL = 0,                //!< Reset all.
    RESET_ALL_EXCEPT_AON = 1,     //!< Reset all except RTC and some AON register.
    INTERRUPT_CPU = 2,            //!< Interrupt CPU.
    WDT_MODE_NUM = 3,             //!< The maximum selectable value for WDT mode.
} WDTMode_TypeDef;

#define IS_WDT_Mode(MODE) (((MODE) == RESET_ALL) || \
                           ((MODE) == RESET_ALL_EXCEPT_AON) || \
                           ((MODE) == INTERRUPT_CPU)) //!< Check if the input parameter is valid.

/** End of group WDT_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup WDT_Exported_Functions WDT Exported Functions
  * \{
  */

/**
 * \brief  Start WDT. This function will enable WDT clock, set and start WDT.
 *
 * \param[in]  TimeMs  WDT Timeout Time. Unit: ms.
 * \param[in]  Mode    Refer to \ref WDTMode_TypeDef. If the Reset WDT operation is not performed within the Timeout period,
 *                     the configured mode operation will be executed.
 *
 * \return  true or false.
 *          - true: WDT mode set successfully, enabling the function..
 *          - false: WDT setting failed.
 */
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
 * \brief  Enable WDT.
 */
void WDT_Enable(void);

/**
 * \brief  Disable WDT.
 */
void WDT_Disable(void);

/**
 * \brief  Kick WDT to restart WDT.
 */
void WDT_Kick(void);

/**
 * \brief  Is WDT enable.
 *
 * \return Is WDT enable or not
 */
bool WDT_IsEnable(void);

/**
 * \brief  Get WDT timeout.
 *
 * \return WDT timeout
 */
uint32_t WDT_GetTimeoutMs(void);

/**
 * \brief  Get WDT mode.
 *
 * \return WDT mode
 */
WDTMode_TypeDef WDT_GetMode(void);

/** End of WDT_Exported_Functions
  * \}
  */

/** End of WDT
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_WDT_H */
