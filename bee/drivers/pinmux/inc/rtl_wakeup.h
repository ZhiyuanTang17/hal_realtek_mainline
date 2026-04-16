/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_WAKEUP_H
#define RTL_WAKEUP_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pinmux/src/device/rtl87x2j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "pinmux/src/device/rtl87x3d/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "pinmux/src/device/rtl87x2g/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "pinmux/src/device/rtl87x3j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#endif

/** \defgroup WAKEUP      WAKEUP
  * \brief
  * \{
  */

/*============================================================================*
 *                         Macros
 *============================================================================*/

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup WAKEUP_Exported_Constants WAKEUP Exported Constants
  * \brief
  * \{
  */
/**
 * \brief       PAD WakeUp Polarity
 *
 * \ingroup     WAKEUP_Exported_Constants
 */

typedef enum
{
    SYSTEM_WAKEUP_POLARITY_HIGH,
    SYSTEM_WAKEUP_POLARITY_LOW,
} SystemWakeUpPolarity_TypeDef;

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1 | PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * \brief       WAKEUP_ENABLE_MODE PAD WAKE UP ENABLE SET
 *
 * \ingroup     WAKEUP_Exported_Constants
 */
typedef enum
{
    ADP_MODE,
    BAT_MODE,
    MFB_MODE,
#if (PAD_SUPPORT_USB_WAKEUP == 1)
    USB_MODE,
#endif
} SystemWakeUpMode_TypeDef;
#endif

typedef void (*P_PAD_CBACK)(uint32_t context);

/** End of WAKEUP_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * \brief     Enable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] Polarity: Polarity of wake-up system.
 *            This parameter can be the following:
 *            \arg SYSTEM_WAKEUP_POLARITY_HIGH: Use high level wakeup.
 *            \arg SYSTEM_WAKEUP_POLARITY_LOW: Use low level wakeup.
 *
 * \param[in] DebounceNewState: Enable delay function.
 *            \arg DISABLE: Disable delay function.
 *            \arg ENABLE: Enable delay function.
 *            This parameter is only meaningful if PAD_SUPPORT_CFG_WAKEUP_ENABLE_WITH_DEBOUNCE is defined.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //PM enter IO call back function.
 * void io_uart_pm_enter(void)
 * {
 *     // Switch pad to software mode
 *     Pad_SetControlMode(P2_0, PAD_SW_MODE);//tx pin
 *     Pad_SetControlMode(P2_1, PAD_SW_MODE);//rx pin
 *
 * #ifdef PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE
 *     System_WakeUpPinEnable(P2_1, PAD_WAKEUP_POLARITY_LOW, DISABLE);
 * #else
 *     System_WakeUpPinEnable(P2_1, PAD_WAKEUP_POLARITY_LOW);
 * #endif
 * }
 * \endcode
 */
#if (PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE == 1)
void System_WakeUpPinEnable(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef Polarity,
                            FunctionalState DebounceNewState);
#else
void System_WakeUpPinEnable(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef Polarity);
#endif

/**
 * \brief     Disable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define UART_RX_PIN                P4_1
 *
 * //System interrupt handler function, for wakeup pin.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         Pad_ClearWakeUpINTPendingBit(UART_RX_PIN);
 *         System_WakeUpPinDisable(UART_RX_PIN);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
void System_WakeUpPinDisable(uint8_t Pin_Num);

/**
 * \brief   Get pin interrupt status.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return Interrupt status.
 *         \arg 1: Pin wake up system.
 *         \arg 0: The pin does not wake up the system.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define UART_RX_PIN                P4_1
 *
 * //System interrupt handler function, for wakeup pin.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         System_WakeUpClearINTPendingBit(UART_RX_PIN);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num);

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE == 1)
/**
 * \brief  Enable or disable wake-up debounce function.
 *
 * \param[in]  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *                so that any pin can be filled in.
 *
 * \param  PADWakeUpCmd_TypeDef: wake-up system enable or disable
 *         \arg PAD_WAKEUP_DISABLE: Disable wakeup.
 *         \arg PAD_WAKEUP_DISABLE: Enable wakeup.
 *
 * \return The result of the setting.
 * \retval true: Config wake up debounce success
 * \retval false:Set Config wake up debounce failed due to due to invalid pin num or this pin does not have debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *void System_WakeUpPinEnable(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState)
 *{
 *    if(Pin_Num >= MAX_PIN_NUM)
 *    {
 *        return;
 *    }
 *
 *    Pad_SetWakeUpPolarity(Pin_Num, Polarity);
 *    Pad_WakeUpDebounce_Cmd(Pin_Num, NewState);
 *    if (ENABLE == NewState)
 *    {
 *        System_WakeUpDebounceCmd(Pin_Num, ENABLE);
 *    }
 *    Pad_WakeUp_Cmd(Pin_Num, ENABLE);
 *}
 * \endcode
 */
bool System_WakeUpDebounceCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
 * \brief   Config wak-up system debounce time.
 *
 * \param[in]  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *        so that any pin can be filled in.
 *
 * \param[in] TimeMs: Debounce time.
 *
 * \return The result of the setting.
 * \retval true: Set debounce time success
 * \retval false:Set debounce time failed due to due to invalid pin num or this pin does not have debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceTime(10);
 * }
 * \endcode
 */
bool System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t TimeMs);

/**
 * \brief   Config wak-up system debounce time.
 *
 * \param[in]  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *        so that any pin can be filled in.
 *
 * \param[in] TimeUs: Debounce time.
 *
 * \return The result of the setting.
 * \retval true: Set debounce time success
 * \retval false:Set debounce time failed due to due to invalid pin num or this pin does not have debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceTimeUs(1000);
 * }
 * \endcode
 */
bool System_WakeUpDebounceTimeUs(uint8_t Pin_Num, uint32_t TimeUs);

/**
 * \brief  Get debounce wake up status.
 *
 * \param[in]  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *                    so that any pin can be filled in.
 *
 * \return Debounce wakeup status
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     uint8_t WakeUpDebounceStatus = System_WakeUpDebounceStatus;
 * }
 * \endcode
 */

uint8_t System_WakeUpDebounceStatus(uint8_t Pin_Num);

/**
 * \brief  Clear debounce wake up status. Call this API will clear the debunce wakeup status bit.
 *
 * \param[in]  Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *        so that any pin can be filled in.
 *
 * \return None
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void pm_store(void)
 * {
 *     System_WakeUpDebounceClear(P0_0);
 * }
 * \endcode
 */
void System_WakeUpDebounceClear(uint8_t Pin_Num);

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE_INTERRUPT == 1)
/**
 * \brief   Enable or disable wake-up system debounce interrupt.
 *
 * \param[in]  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \note  Pin_Num is invalid parameter for rtl87x2g series
 *        so that any pin can be filled in.
 *
 * \param[in] NewState: Enable or disable interrupt.
 *
 * \return The result of the setting.
 * \retval true: Config interrupt success
 * \retval false: Config interrupt failed due to invalid pin num or this pin does not have debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceINTConfig(P0_0, ENABLE);
 * }
 * \endcode
 */
bool System_WakeUpDebounceINTConfig(uint8_t Pin_Num, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE_MULTI_GROUP == 1)
bool System_WakeUpDebounceMultiGroupEnable(uint8_t Pin_Num);
bool System_WakeUpDebounceMultiGroupDisable(uint8_t Pin_Num);
#endif
#endif

/**
 * \brief     Clear the interrupt pendign bit of the specified pin
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ClearWakeUpINTPendingBit(P2_0);
 * }
 * \endcode
 */
void System_WakeUpClearINTPendingBit(uint8_t Pin_Num);

/**
 * \brief     Clear all wake up pin interrupt pending bit.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ClearAllWakeUpINT();
 * }
 * \endcode
 */
void System_WakeUpClearAllINT(void);

#if (PAD_SUPPORT_WAKEUP_SHORT_PULSE == 1)
/**
 * \brief  Short pulse wakeup function.
 *
 * \param[in] NewState: Enable or disable short pulse wake up.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable short pulse wake up.
 *            \arg DISABLE: Disable short pulse wake up.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ShortPulseWakeUpCmd(ENABLE);
 * }
 * \endcode
 */
void System_WakeUpShortPulseCmd(FunctionalState NewState);
#endif

/**
  * \brief  Configure wakeup PPU function for the specified pin.
  *
  * \param[in]  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param[in]  Polarity: Select pin wakeup polarity (high level or low level).
  *             This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param[in]  NewState: Enable or disable the wakeup PPU function.
  *             This parameter can be ENABLE or DISABLE.
  *
  * \return None
  */
void System_WakeUpPPUCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);

/**
  * \brief  Configure wakeup RAP function for the specified pin.
  *
  * \param[in]  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param[in]  Polarity: Select pin wakeup polarity (high level or low level).
  *             This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param[in]  NewState: Enable or disable wakeup RAP function.
  *             This parameter can be ENABLE or DISABLE.
  *
  * \return None
  */
void System_WakeUpRAPCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);

/**
  * \brief  Enable or disable the function of the wake-up system of the specified pin.
  *
  * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
  *
  * \param[in] NewState: Enable or disable PAD wake up.
  *            This parameter can be one of the following values:
  *            \arg ENABLE: Enable PAD wake up system.
  *            \arg DISABLE: Disable PAD wake up system.
  *
  * \return None.
  */
void System_WakeUpCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
  * \brief Set the polarity for the function of the wake-up system of the specified pin.
  *
  * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
  *
  * \param[in] Polarity: Polarity of wake-up system.
  *            This parameter can be the following:
  *            \arg SYSTEM_WAKEUP_POLARITY_HIGH: Use high level wakeup.
  *            \arg SYSTEM_WAKEUP_POLARITY_LOW: Use low level wakeup.
  *
  * \return None.
  */
void System_SetWakeUpPinPolarity(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef WakeUpPolarity);

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1 | PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * \brief   Config the system wakeup mode.
 *
 * \param[in] mode: mode of set, this parameter can reference WAKEUP_EN_MODE.
 *            This parameter can be one of the following values:
 *            \arg ADP_MODE: Wake up by adapter.
 *            \arg BAT_MODE: Wake up by battery.
 *            \arg MFB_MODE: Wake up by MFB.
 *            \arg USB_MODE: Wake up by USB.
 * \param[in] pol: polarity to wake up.
 *            This parameter can be the following:
 *            \arg POL_HIGH: Use high level wakeup.
 *            \arg POL_LOW: Use low level wakeup.
 * \param[in] NewState: Enable or disable wake up.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the system wake up at specified polarity.
 *            \arg DISABLE: Disable the system wake up at specified polarity.
 *
 * \return    Config the system wakeup mode fail or success.
 *            \arg 0   Config success.
 *            \arg 1   Config fail due to wrong mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is WAKE_UP_GENERAL
 *     Pad_WakeUpCmd(ADP_MODE, POL_HIGH, ENABLE);
 * }
 * \endcode
 */
uint8_t System_WakeUpModeCmd(SystemWakeUpMode_TypeDef WakeUp_Mode,
                             SystemWakeUpPolarity_TypeDef WakeUpPolarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1)
/**
 * \brief   Configure the adpater wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState: Enable or disable adpater wake up.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable adpater wake up system at specified polarity.
 *            \arg DISABLE: Disable adpater wake up system.
 * \param[in] pol: Polarity to wake up.
 *            This parameter can be the following:
 *            \arg POL_HIGH: Use high level wakeup.
 *            \arg POL_LOW: Use low level wakeup.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is wake_up_power_off
 *     System_SetAdpWakeUpFunction(ENABLE, PAD_WAKEUP_POLARITY_HIGH);
 * }
 * \endcode
 */
void System_WakeUpAdapterCmd(SystemWakeUpPolarity_TypeDef WakeUpPolarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * \brief   Configure the MFB wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState: Enable or disable MFB wake up.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable MFB wake up system.
 *            \arg DISABLE: Disable MFB wake up system.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //io_test_set_mfb_mode is POWER_OFF_WAKEUP_TEST
 * void mfb_wake_up_enable(void)
 * {
 *     System_SetMFBWakeUpFunction(ENABLE);
 * }
 * \endcode
 */
void System_WakeUpMFBCmd(FunctionalState NewState);
#endif

#if (PAD_SUPPORT_DETECT_MODE == 1)
/**
  * \brief  Selected the DETECT mode of PAD interrupt.
  *
  * \param[in]  is_ldetect: Enable or disable the LDETECT.
  *             This parameter can be true or off.
  *
  * \return None
  */
void System_SelectLDETECT(bool is_ldetect);
#endif

#if (PAD_SUPPORT_WKIE_DIFF_BIT == 1)
/**
  * \brief  Configure wakeup off mode(power down) function for the specified pin.
  * \param  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param  Polarity: Select pin wakeup polarity (high level or low level).
  *         This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param  NewState: Enable or disable wakeup RAP function.
  *         This parameter can be ENABLE or DISABLE.
  * \return None
  */
void System_WakeUpPDCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_WAKE_SUB_IRQ == 1)
/**
  * \brief  Register the callback function of the wake-up system of the specified pin.
  *
  * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
  *
  * \param[in] Callback: Callback function.
  *
  * \param[in] Context: Context of the callback
  *
  * \return None.
  */
void System_RegisterPadWakeupCallback(uint8_t Pin_Num, P_PAD_CBACK Callback, uint32_t Context);
#endif

/** End of WAKEUP_Exported_Functions
  * \}
  */

/** End of WAKEUP
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_WAKEUP_H */



