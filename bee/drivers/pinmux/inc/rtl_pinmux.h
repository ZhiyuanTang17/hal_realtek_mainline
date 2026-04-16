/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_PINMUX_H
#define RTL_PINMUX_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "pinmux/inc/rtl_wakeup.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "pinmux/src/device/rtl87x2g/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "pinmux/src/device/rtl87x3e/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3e/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "pinmux/src/device/rtl87x3d/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pinmux/src/device/rtl87x2j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3EU)
#include "pinmux/src/device/rtl87x3eu/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3eu/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "pinmux/src/device/rtl87x3j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#endif

/** \defgroup PINMUX      PINMUX
  * \brief
  * \{
  */

/*============================================================================*
 *                         Macros
 *============================================================================*/

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup PINMUX_Exported_Constants PINMUX Exported Constants
  * \brief
  * \{
  */

/**
 * \brief       PAD Power Mode
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_NOT_PWRON,
    PAD_IS_PWRON = 1
} PADPowerMode_TypeDef;

/**
 * \brief       PAD Output Config
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_OUT_DISABLE,
    PAD_OUT_ENABLE
} PADOutputMode_TypeDef;

/**
 * \brief       PAD Output Value
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_OUT_LOW,
    PAD_OUT_HIGH
} PADOutputValue_TypeDef;


/**
 * \brief       PAD Pull Mode
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_PULL_DOWN,
    PAD_PULL_UP,
    PAD_PULL_NONE,
} PADPullMode_TypeDef;

/**
 * \brief       PAD Pull Strength Mode
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_PULL_WEAK,
    PAD_PULL_STRONG,
} PADPullStrengthMode_TypeDef;

/**
 * \brief       PAD Mode
 *
 * \ingroup     PINMUX_Exported_Constants
 */

typedef enum
{
    PAD_SW_MODE,
#if (PAD_SUPPORT_CONFIG_PON_DOMAIN == 1)
    PAD_PON_MODE,
#endif
    PAD_PINMUX_MODE,
} PADMode_TypeDef;

#if (PAD_SUPPORT_ANALOG_MODE == 1)
/**
 * \brief       PADAnalog_TypeDef Pad analog/digital mode for CODEC hybrid IO
 *
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_ANALOG_MODE,
    PAD_DIGITAL_MODE,
} PADAnalog_TypeDef;
#endif

#if (PAD_SUPPORT_GET_OUTPUT_CTRL == 1)
typedef enum _PAD_AON_Status
{
    PAD_AON_OUTPUT_LOW,
    PAD_AON_OUTPUT_HIGH,
    PAD_AON_OUTPUT_DISABLE,
    PAD_AON_PINMUX_ON,
    PAD_AON_PIN_ERR
} PAD_AON_Status;
#endif

/** End of PINMUX_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/**
 * \defgroup    PINMUX_Exported_Functions PINMUX Exported Functions
 * \{
 * \ingroup     PINMUX
 */

/**
 * \brief   Configure or reset all pins to idle mode.
 *
 * \param[in] None.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)//XXX represents the name of the peripheral to be configured.
 * {
 *     Pinmux_Reset();
 * }
 * \endcode
 */
void Pinmux_Reset(void);

/**
 * \brief     Configure the specified pin to idle mode.
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
 *     Pinmux_Deinit(P2_2);
 * }
 * \endcode
 */
void Pinmux_Deinit(uint8_t Pin_Num);

/**
 * \brief     Configure the specified pin to its corresponding peripheral function.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] Pin_Func: Peripheral function
 *            This parameter This parameter refers to \ref Pin_Function_Number
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     Pad_Config(P2_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE,
               PAD_OUT_HIGH);
 *     Pad_Config(P2_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE,
               PAD_OUT_HIGH);

 *     Pinmux_Config(P2_0, UART0_TX);
 *     Pinmux_Config(P2_1, UART0_RX);
 * }
 * \endcode
 */
void Pinmux_Config(uint8_t Pin_Num, uint32_t Pin_Func);

/**
 * \brief     Configure the relevant operation mode,
 *            peripheral circuit and output level value in software mode of the specified pin
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] AON_PAD_Mode: Use software mode or pinmux mode.
 *            This parameter can be one of the following values:
 *            \arg PAD_SW_MODE: Use software mode.
 *            \arg PAD_PINMUX_MODE: Use pinmux mode.
 *
 * \param[in] AON_PAD_PwrOn: Config power of pad.
 *            This parameter can be one of the following values:
 *            \arg PAD_NOT_PWRON: Shutdown power of pad.
 *            \arg PAD_IS_PWRON: Enable power of pad.
 *
 * \param[in] AON_PAD_Pull: config pad pull mode.
 *            This parameter can be one of the following values:
 *            \arg PAD_PULL_NONE: No pull.
 *            \arg PAD_PULL_UP: Pull this pin up.
 *            \arg PAD_PULL_DOWN: Pull this pin down.
 *
 * \param[in] AON_PAD_E: Config pad out put function.
 *            This parameter can be one of the following values:
 *            \arg PAD_OUT_DISABLE: Disable pin output.
 *            \arg PAD_OUT_ENABLE: Enable pad output.
 *
 * \param[in] AON_PAD_O: Config pin output level.
 *            This parameter can be one of the following values:
 *            \arg PAD_OUT_LOW: Pad output low.
 *            \arg PAD_OUT_HIGH: Pad output high.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
 * }
 * \endcode
 */
void Pad_Config(uint8_t                 Pin_Num,
                PADMode_TypeDef         AON_PAD_Mode,
                PADPowerMode_TypeDef    AON_PAD_PwrOn,
                PADPullMode_TypeDef     AON_PAD_Pull,
                PADOutputMode_TypeDef   AON_PAD_E,
                PADOutputValue_TypeDef  AON_PAD_O);

#if (PAD_SUPPORT_CONFIG_EXT == 1)
/**
 * \brief     Configure the relevant operation mode, peripheral circuit, pull resistor value and
 *            output level value in software mode of the specified pin.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] AON_PAD_Mode: Use software mode or pinmux mode.
 *            This parameter can be one of the following values:
 *            \arg PAD_SW_MODE: Use software mode.
 *            \arg PAD_PINMUX_MODE: Use pinmux mode.
 *
 * \param[in] AON_PAD_PwrOn: Config power of pad.
 *            This parameter can be one of the following values:
 *            \arg PAD_SHUTDOWN: Shutdown power of pad.
 *            \arg PAD_IS_PWRON: Enable power of pad.
 *
 * \param[in] AON_PAD_Pull: config pad pull mode.
 *            This parameter can be one of the following values:
 *            \arg PAD_PULL_NONE: No pull.
 *            \arg PAD_PULL_UP: Pull this pin up.
 *            \arg PAD_PULL_DOWN: Pull this pin down.
 *
 * \param[in] AON_PAD_E: Config pad output function, which only valid when PAD_SW_MODE.
 *            This parameter can be one of the following values:
 *            \arg PAD_OUT_DISABLE: Disable pin output.
 *            \arg PAD_OUT_ENABLE: Enable pad output.
 *
 * \param[in] AON_PAD_O: Config pin output level, which only valid when PAD_SW_MODE and output mode.
 *            This parameter can be one of the following values:
 *            \arg PAD_OUT_LOW: Pad output low.
 *            \arg PAD_OUT_HIGH: Pad output high.
 *
 * \param[in] AON_PAD_P: Config resistor value.
 *            This parameter can be one of the following values:
 *            \arg PAD_150K_PULL: pad pull 150k resistance.
 *            \arg PAD_15K_PULL: pad pull 15k resistance.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_adc_init(void)
 * {
 *     Pad_ConfigExt(P2_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_150K_PULL);
 *     Pad_ConfigExt(P2_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_150K_PULL);
 * }
 * \endcode
 */
extern void Pad_ConfigExt(uint8_t Pin_Num,
                          PADMode_TypeDef AON_PAD_Mode,
                          PADPowerMode_TypeDef AON_PAD_PwrOn,
                          PADPullMode_TypeDef AON_PAD_Pull,
                          PADOutputMode_TypeDef AON_PAD_E,
                          PADOutputValue_TypeDef AON_PAD_O,
                          PADPullStrengthMode_TypeDef AON_PAD_P);
#endif

#if (PAD_SUPPORT_LOWER_POWER_CONFIG == 1)
void Pad_LPConfig(uint8_t Pin_Num, PADPullMode_TypeDef AON_PAD_Pull, FunctionalState NewState);

void Pad_ModeAutoSwitchCmd(uint8_t Pin_Num, FunctionalState NewState);

#endif

/**
 * \brief   Set all pins to the default state.
 *
 * \param[in] None.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_AllConfigDefault();
 * }
 * \endcode
 */
void Pad_AllConfigDefault(void);

#if (PAD_SUPPORT_FUNCTION_CONFIG == 1)
/**
  * \brief  Config Pad Function.
  *
  * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
  *
  * \param[in] Pad_Func: Pad function \ref PAD_Function_Config.
  *
  * \return Config the pad function fail or success.
  *         \arg true   Config success.
  *         \arg false  Config fail due to wrong config value.
  */
bool Pad_FunctionConfig(uint8_t Pin_Num, PADFuncConfig_TypeDef Pad_Func);
#endif

#if (PAD_SUPPORT_HIGH_SPEED_CONFIG == 1)
/**
  * \brief  PAD high speed mode function select.
  *
  * \param[in]  Pin_Num: pin number.
  *    This parameter is from ADC_0 to Max pin number, please refer to rtl876x.h "Pin_Number" part.
  * \param[in]  PAD_HS_FUNC_SEL_TYPE: Pad_HS_Func_Sel.
  *             \arg true: Set high speed function select success
  *             \arg false: Set high speed function select failed due to invalid pinmux
  *
  * \return None.
  */
bool Pad_HighSpeedConfig(uint8_t *Pin_Group, uint8_t Pin_GroupLen,
                         PADHSConfig_Typedef Pad_HighSpeed, FunctionalState NewState);
#endif

/**
 * \brief     Configure the driving current.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] PAD_Driving_Current: This parameter sets the driving current.
 *            This parameter can be the following:
 *            \arg PAD_DRIVING_CURRENT_4mA.
 *            \arg PAD_DRIVING_CURRENT_8mA.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_SetDrivingCurrent(P2_0, PAD_DRIVING_CURRENT_4mA);
 * }
 * \endcode
 */
void Pad_SetDrivingCurrent(uint8_t Pin_Num, PADDrivingCurrent_TypeDef PAD_DrivingCurrent);

/**
 * \brief     Set pin control mode.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] value: This parameter sets the pin mode.
 *            This parameter can be the following:
 *            \arg PAD_SW_MODE: Software mode.
 *            \arg PAD_PINMUX_MODE: Default pinmux mode.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_SetControlMode(P2_0, PAD_SW_MODE);
 * }
 * \endcode
 */
void Pad_SetControlMode(uint8_t Pin_Num, PADMode_TypeDef PAD_Mode);

/**
 * \brief     Enable or disable pad output mode.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] value: This parameter sets whether the pin outputs the level in software mode.
 *            This parameter can be enumerated PAD_OUTPUT_ENABLE_Mod of the values:
 *            \arg PAD_OUT_DISABLE: Disable output.
 *            \arg PAD_OUT_ENABLE: Enable output.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_OutputCmd(P2_0, PAD_OUT_ENABLE);
 * }
 * \endcode
 */
void Pad_OutputCmd(uint8_t Pin_Num, PADOutputMode_TypeDef PAD_OutEn);

/**
 * \brief     Configure pad output level.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] value: Config pin output level.
 *            This parameter can be one of the following values:
 *            \arg PAD_OUT_LOW: Pad output low.
 *            \arg PAD_OUT_HIGH: Pad output high.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_SetOutputLevel(P2_0, PAD_OUT_HIGH);
 * }
 * \endcode
 */
void Pad_SetOutputLevel(uint8_t Pin_Num, PADOutputValue_TypeDef PAD_OutValue);

/**
 * \brief     Enable or disable pad pull-up / pull-down resistance function.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] NewState: This parameter enable or disable the the pad pin pull-up/pull-down function.
 *            This parameter can be the following:
 *            \arg DISABLE: Disable pad pull-up / pull-down function.
 *            \arg ENABLE: Enable  pad pull-up / pull-down function.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PullCmd(P2_0, ENABLE);
 * }
 * \endcode
 */
void Pad_PullCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
 * \brief     Pad pull-up/pull-down resistance function selection.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] PAD_PullMode: This parameter sets whether the pin pull-up or pull-down.
 *            This parameter can be the following:
 *            \arg 0: Config pad pull-up function.
 *            \arg 1: Config  pad pull-down function.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_SetPullMode(P2_0, 1);
 * }
 * \endcode
 */
void Pad_SetPullMode(uint8_t Pin_Num, PADPullMode_TypeDef PAD_PullMode);

/**
 * \brief     Configure the strength of pull-up/pull-down resistance.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] PAD_PullStrengthMode: This parameter sets the strength of pull-up/pull-down resistance.
 *            This parameter can be the following:
 *            \arg PAD_WEAK_PULL: Resistance weak pull.
 *            \arg PAD_STRONG_PULL: Resistance strong pull.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_SetPullStrength(P2_0, PAD_STRONG_PULL);
 * }
 * \endcode
 */
void Pad_SetPullStrength(uint8_t Pin_Num, PADPullStrengthMode_TypeDef PAD_PullStrengthMode);

/**
 * \brief     Set pin power mode.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] value: This parameter sets the power supply mode of the pin,
 *            and the value is enumeration PADPowerMode_TypeDef One of the values.
 *            \arg PAD_NOT_PWRON: Power off.
 *            \arg PAD_IS_PWRON: Power on.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PowerCmd(P2_0, PAD_NOT_PWRON);
 * }
 * \endcode
 */
void Pad_PowerCmd(uint8_t Pin_Num, PADPowerMode_TypeDef PAD_PowerMode);

#if (PAD_SUPPORT_ANALOG_MODE == 1)
/**
 * \brief   Config Hybrid pad analog/digital functions.
 *
 * \param[in] pin: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] mode: Please refer to PADAnalog_TypeDef.
 *            \arg This parameter can be: PAD_ANALOG_MODE/PAD_DIGITAL_MODE.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_AnalogMode(P2_1, PAD_ANALOG_MODE);
 * }
 * \endcode
 */
void Pad_AnalogMode(uint8_t pin, PADAnalog_TypeDef PAD_AnalogMode);
#endif

#if (PAD_SUPPORT_GET_OUTPUT_CTRL == 1)
/**
 * \brief   Get pad current output/input setting.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return   reference PAD_AON_Status.
 *           \arg PAD_AON_OUTPUT_LOW: Pad AON output low level.
 *           \arg PAD_AON_OUTPUT_HIGH: Pad AON output high level.
 *           \arg PAD_AON_OUTPUT_DISABLE: Pad AON output disable.
 *           \arg PAD_AON_PINMUX_ON: Pad AON pinmux on.
 *           \arg PAD_AON_PIN_ERR: Pad AON pin error.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     if (Pad_GetOutputCtrl(P2_1) == PAD_AON_OUTPUT_LOW)
 *     {
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
uint8_t Pad_GetOutputCtrl(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_GET_POWER_GROUP == 1)
/**
 * \brief   Get the pad power group.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return   Get the power group of the pin. Please refer to PADPowerGroup_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     PADPowerGroup_TypeDef power_group = Pad_GetPowerGroup(P2_1);
 * }
 * \endcode
 */
PADPowerGroup_TypeDef  Pad_GetPowerGroup(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_GET_PIN_NAME == 1)
/**
 * \brief   Get the pin name in string.
 *
 * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
 *
 * \return   pin name or null.
 *           \arg pin name
 *           \arg null due to invalid pin index.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_GetPinName(P2_1);
 * }
 * \endcode
 */
const char *Pad_GetPinName(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_SELECT_CONTROL_CORE == 1)
/**
 * \brief   Select the PAD pinmux VCORE domain.
 *
 * \param[in] pin: Pin number to be configured. \ref Pin_Number.
 *
 * \param[in] mode: Please refer to PADCoreSelect_TypeDef.
 *            \arg This parameter can be \ref PAD_VCORE_Select.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_SelectCore(P2_1, PAD_CORE_SEL_APP);
 * }
 * \endcode
 */
void Pad_SelectCore(uint8_t pin, PADCoreSelect_TypeDef pad_core_domain);
#endif

#if (PAD_SUPPORT_GET_SELECT_CONTROL_CORE == 1)
/**
 * \brief   Get the Selected VCORE domain.
 *
 * \param[in] pin: Pin number to be configured. \ref Pin_Number.
 *
 * \param[out] mode: Please refer to PADCoreSelect_TypeDef.
 *            \arg This parameter can be \ref PAD_VCORE_Select.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *    PADCoreSelect_TypeDef pad_core =  Pad_GetSelectCore(P2_1);
 * }
 * \endcode
 */
PADCoreSelect_TypeDef Pad_GetSelectCore(uint8_t pin);
#endif

/** End of PINMUX_Exported_Functions
  * \}
  */

/** End of PINMUX
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_PINMUX_H */



