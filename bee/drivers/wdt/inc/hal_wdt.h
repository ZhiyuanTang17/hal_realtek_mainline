/**
*****************************************************************************************
*     Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    hal_wdt.h
  * @brief   This file provides watch dog timer HAL layer api
  * @author  renee
  * @date    2023-11-16
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2023 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
 * @endcode
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _HAL_WDT_H
#define _HAL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "reset_reason.h"

/** @addtogroup HAL_WDT HAL WDT
  * @brief HAL WDT function module
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup HAL_WDT_Exported_Types HAL WDT Exported Types
  * @{
  */

/**
 * \brief       WDT supported modes.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef enum _WDT_MODE
{
    WDT_MODE_RESET_ALL = 0,               /**< Reset all. */
    WDT_MODE_RESET_ALL_EXCEPT_AON = 1,    /**< Reset all except RTC and some AON register. */
    WDT_MODE_INTERRUPT_CPU = 2,           /**< Interrupt CPU. */
    WDT_MODE_UNKNOWN = 3                  /**< Mode unknown */
} T_WDT_MODE;

#define IS_WDT_MODE(MODE) ((MODE) < WDT_MODE_UNKNOWN)

/**
 * \brief       This enum define the API return type.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef enum
{
    HAL_WDT_STATUS_INVALID_PARAMETER = -1,       /**<  A wrong parameter is given. */
    HAL_WDT_STATUS_OK = 0                        /**<  No error occurred during the function call. */
} T_WDT_STATUS;

/**
 * \brief       This enum define WDT RESET TYPE for debug
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef enum
{
    HW_RESET                         =  0x00,   /* HW reset */
    CORE_WDT_RESET_ALL               =  0x01,   /* CORE WDT RESET_ALL */
    CORE_WDT_RESET_ALL_EXCEPT_AON    =  0x02,   /* CORE WDT RESET_ALL_EXCEPT_AON  */
    LP_WDT_RESET_ALL                 =  0x03,   /* LP WDT RESET_ALL */
    LP_WDT_RESET_ALL_EXCEPT_AON      =  0x04,   /* LP WDT RESET_ALL_EXCEPT_AON  */
    SYSTEM_RESET_REASON              =  0x05,   /* System reset*/
    WDT_RESET_TYPE_END               =  0xff,
} T_WDT_RESET_TYPE;

/**
 * \brief       Define the type of wdt reset callback.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef void (*P_WDT_RESET_CB)(T_WDT_MODE wdg_mode, uint8_t reset_reason);

/** End of group HAL_WDT_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup HAL_WDT_API_Exported_Functions WDT Api
  * @{
  */

/**
 * hal_wdt.h
 *
 * \brief  Start wdt.
 *
 * \param[in] mode: wdt reset mode \ref T_WDT_MODE.
 * \param[in] timeout_ms: wdt timeout.
 *
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_start(RESET_ALL, 4000);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_start(T_WDT_MODE mode, uint32_t timeout_ms);

/**
 * hal_wdt.h
 *
 * \brief  Disable wdt.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_stop();
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_stop(void);

/**
 * hal_wdt.h
 *
 * \brief  Check whether wdt is enable.
 * \return The result of wdt.
 * \retval true: wdt is enable.
 * \retval false: wdt is disable.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     if (hal_wdt_is_enable() == true)
 *     {
 *
 *     }
 * }
 * \endcode
 */
bool hal_wdt_is_enable(void);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt reset mode.
 * \return T_WDT_MODE: wdt reset mode \ref T_WDT_MODE.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     T_WDT_MODE mode = hal_wdt_get_mode();
 * }
 * \endcode
 */
T_WDT_MODE hal_wdt_get_mode(void);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt current timeout value.
 * \return current timeout value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     uint32_t timeout = hal_wdt_get_timeout_ms();
 * }
 * \endcode
 */
uint32_t hal_wdt_get_timeout_ms(void);

/**
 * hal_wdt.h
 *
 * \brief  Change wdt timeout value.
 * \param[in] timeout_ms: wdt new timeout value.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_change_timeout_period(4000);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_change_timeout_period(uint32_t timeout_ms);

/**
 * hal_wdt.h
 *
 * \brief  Change wdt mode.
 * \param[in] mode: wdt new reset mode \ref T_WDT_MODE.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_change_mode(RESET_ALL);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_change_mode(T_WDT_MODE mode);

/**
 * hal_wdt.h
 *
 * \brief  Kick wdt.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_kick();
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_kick(void);

/**
 * hal_wdt.h
 *
 * \brief  Reset the mcu at specified mode.
 * \param[in] mode: wdt reset mode \ref T_WDT_MODE.
 * \param[in] function: The function that triggers reset.
 * \param[in] line: The line of function that triggers reset.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     chip_reset(RESET_ALL);
 * }
 * \endcode
 */
void hal_wdt_reset(T_WDT_MODE wdt_mode, const char *function, uint32_t line);
#define chip_reset(mode)    hal_wdt_reset(mode,  __FUNCTION__, __LINE__)

/**
 * hal_wdt.h
 *
 * \brief  Register wdt reset callback.
 * \param[in] reset_callback: callback to be registered.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_user_callback(T_WDT_MODE wdg_mode, uint8_t reset_reason)
 * {
 * }
 * void wdt_demo(void)
 * {
 *     hal_wdt_regiser_reset_callback(wdt_user_callback);
 * }
 * \endcode
 */
void hal_wdt_regiser_reset_callback(P_WDT_RESET_CB reset_callback);

/**
 * hal_wdt.h
 *
 * \brief  Reset the mcu at specified mode with reason.
 * \param[in] mode: wdt reset mode \ref T_WDT_MODE.
 * \param[in] reset_reason: reset reason.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_reset_with_reason(RESET_ALL, 2);
 * }
 * \endcode
 */
void hal_wdt_reset_with_reason(T_WDT_MODE wdt_mode, T_SW_RESET_REASON reset_reason);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt reset type.
 * \return Reset type.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     uint8_t type = hal_wdt_get_reset_type();
 * }
 * \endcode
 */
T_WDT_RESET_TYPE hal_wdt_get_reset_type(void);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt reset reason.
 * \return Reset reason.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     uint8_t reason = hal_wdt_get_reset_reason();
 * }
 * \endcode
 */
T_SW_RESET_REASON hal_wdt_get_reset_reason(void);

#ifdef __cplusplus
}
#endif
/** @} */ /* End of group HAL_WDT_API_Exported_Functions */
/** @} */ /* End of group HAL_WDT */
#endif
