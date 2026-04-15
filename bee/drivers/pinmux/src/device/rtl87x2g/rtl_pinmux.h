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
#include "rtl_pinmux_def.h"
#include "pin_def.h"

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
 * \defgroup    PAD_Power_Mode PAD Power Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_NOT_PWRON,     //!< Disable pad power mode.
    PAD_IS_PWRON = 1   //!< Enable pad power mode.
} PADPowerMode_TypeDef;

/** End of PAD_Power_Mode
  * \}
  */

/**
 * \defgroup    PAD_Output_Config PAD Output Config
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_OUT_DISABLE,   //!< Disable pad output.
    PAD_OUT_ENABLE     //!< Enable pad output.
} PADOutputMode_TypeDef;

/** End of PAD_Output_Config
  * \}
  */

/**
 * \defgroup    PAD_Output_Value PAD Output Value
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_OUT_LOW,     //!< The pad outputs a low level.
    PAD_OUT_HIGH     //!< The pad outputs a high level.
} PADOutputValue_TypeDef;

/** End of PAD_Output_Value
  * \}
  */

/**
 * \defgroup    PAD_Pull_Mode PAD Pull Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_PULL_DOWN,     //!< Enable the pull-down resistor function for the pad.
    PAD_PULL_UP,       //!< Enable the pull-up resistor function for the pad.
    PAD_PULL_NONE,     //!< Pad is in a floating state.
} PADPullMode_TypeDef;

/** End of PAD_Pull_Mode
  * \}
  */

/**
 * \defgroup    PAD_Pull_Strength_Mode PAD Pull Strength Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_PULL_WEAK,       //!< PAD pull mode is weak pull mode.
    PAD_PULL_STRONG,     //!< PAD pull mode is srtong pull mode.
} PADPullStrengthMode_TypeDef;

/** End of PAD_Pull_Strength_Mode
  * \}
  */

/**
 * \defgroup    PAD_Driving_Current_Value PAD Driving Current Value
 * \{
 * \ingroup     PINMUX_Exported_Constants
 * \brief       Detailed  level and current relationship refers to \ref PAD_Constant_Wrapper.
 */
typedef enum
{
    LEVEL0,   //!< The PAD driving current is set to level 0.
    LEVEL2,   //!< The PAD driving current is set to level 2.
#if (PAD_DRIVING_CURRENT_LEVEL == 4)
    LEVEL1,   //!< The PAD driving current is set to level 1.
    LEVEL3,   //!< The PAD driving current is set to level 3.
#endif
} PADDrivingCurrent_TypeDef;

/** End of PAD_Driving_Current_Value
  * \}
  */

/**
 * \defgroup    PAD_WakeUp_Debounce PAD WakeUp Debounce
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_WAKEUP_DEB_DISABLE,   //!< Disable pad wakeup debounce function.
    PAD_WAKEUP_DEB_ENABLE     //!< Enable pad wakeup debounce function.
} PADWakeupDebCmd_TypeDef;

/** End of PAD_WakeUp_Debounce
  * \}
  */

/**
 * \defgroup    PAD_WakeUp PAD WakeUp
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_WAKEUP_DISABLE,    //!< Disable PAD wakeup function.
    PAD_WAKEUP_ENABLE      //!< Enable PAD wakeup function.
} PADWakeupCmd_TypeDef;

/** End of PAD_WakeUp
  * \}
  */

/**
 * \defgroup    PAD_Short_Pulse_WakeUp PAD Short Pulse WakeUp
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_SHORT_PULSE_WAKEUP_DISABLE,    //!< Disable PAD short pulse wakeup function.
    PAD_SHORT_PULSE_WAKEUP_ENABLE      //!< Enable PAD short pulse wakeup function.
} PADSPWakeupCmd_TypeDef;

/** End of PAD_Short_Pulse_WakeUp
  * \}
  */

/**
 * \defgroup    PAD_WakeUp_Polarity PAD WakeUp Polarity
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_WAKEUP_POL_HIGH,    //!< PAD wakeup polarity is high.
    PAD_WAKEUP_POL_LOW,     //!< PAD wakeup polarity is low.
    PAD_WAKEUP_NONE         //!< PAD wakeup polarity is none.
} PADWakeupPolarity_TypeDef;

/** End of PAD_WakeUp_Polarity
  * \}
  */

/**
 * \defgroup    PAD_Debounce_Frequency PAD Debounce Frequency
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_DEB_FREQ_32KHz,         //!< The frequency of PAD debounce is 32kHz.
    PAD_DEB_FREQ_16KHz,         //!< The frequency of PAD debounce is 16kHz.
    PAD_DEB_FREQ_8KHz = 3,      //!< The frequency of PAD debounce is 8kHz.
    PAD_DEB_FREQ_4KHz = 7,      //!< The frequency of PAD debounce is 4kHz.
    PAD_DEB_FREQ_2KHz = 15,     //!< The frequency of PAD debounce is 2kHz.
    PAD_DEB_FREQ_1KHz = 31,     //!< The frequency of PAD debounce is 1kHz.
    PAD_DEB_FREQ_500Hz = 63,    //!< The frequency of PAD debounce is 500Hz.
} PADWakeupDebFreq_TypeDef;

/** End of PAD_Debounce_Frequency
  * \}
  */

/**
 * \defgroup    PAD_Mode PAD_Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_SW_MODE,            //!< PAD pin is configured in software mode.
#if PAD_SUPPORT_MULTI_CORE
    PAD_V1_PINMUX_MODE,     //!< PAD pin is configured in vcore1 pinmux mode.
    PAD_V2_V4_PINMUX_MODE,  //!< PAD pin is configured in Vcore2&4 pinmux mode.
    PAD_V3_PINMUX_MODE,     //!< PAD pin is configured in Vcore3 pinmux mode.
    PAD_PINMUX_MODE = PAD_V2_V4_PINMUX_MODE, //!< PAD pins are configured in pinmux mode.
#elif PAD_SUPPORT_PON_DOMAIN
    PAD_PON_MODE,          //!< PAD pin is configured in pon domain mode.
    PAD_PINMUX_MODE,       //!< PAD pin is configured in pinmux mode.
#else
    PAD_PINMUX_MODE,       //!< PAD pin is configured in pinmux mode.
#endif
} PADMode_TypeDef;

/** End of PAD_Mode
  * \}
  */

#if PAD_SUPPORT_SLEEP_LED
/**
 * \defgroup    Sleep_LED_Pin Sleep LED Pin
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _SLEEP_LED_PIN
{
    SLEEP_LED_ADC_0,
    SLEEP_LED_ADC_1,
    SLEEP_LED_ADC_6,
    SLEEP_LED_ADC_7,
    SLEEP_LED_P1_0,
    SLEEP_LED_P1_1,
    SLEEP_LED_P1_4,
    SLEEP_LED_P2_0,
    SLEEP_LED_P2_1,
    SLEEP_LED_P2_2,
} SLEEP_LED_PIN;

/** End of Sleep_LED_Pin
  * \}
  */
#endif

#if PAD_SUPPORT_FUNCTION_CONFIG
/**
 * \defgroup    PAD_Function_Config PAD Function Config
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _PAD_FUNCTION_CONFIG_VALUE
{
    AON_GPIO,
    LED0,
    LED1,
    LED2,
    CLK_REQ,
    EXTRN_SWR_POW_SWR,
    EXTRN_LDO1_POW_LDO,
    EXTRN_LDO2_POW_LDO,
    PAD_FUNC_MAX,
} PAD_FUNCTION_CONFIG_VAL;

/** End of PAD_Function_Config
  * \}
  */
#endif

#if PAD_SUPPORT_GET_POWER_GROUP
/**
 * \defgroup    PAD_Power_Group PAD Power Group
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _PIN_POWER_GROUP
{
    INVALID_PIN_GROUP  = 0,      //!< Invalid pad power group.
    VDDIO1             = 1,      //!< Pad power group of VDDIO1 pin.
    VDDIO2             = 2,      //!< Pad power group of VDDIO2 pin.
    VDDIO3             = 3,      //!< Pad power group of VDDIO3 pin.
    VDDIO4             = 4,      //!< Pad power group of VDDIO4 pin.
    VDDIO5             = 5,      //!< Pad power group of VDDIO5 pin.
    VCODEC             = 6,      //!< Pad power group of VCODEC pin.
    GROUP_ADC          = 7,      //!< Pad power group of ADC pin.
} T_PIN_POWER_GROUP;

/** End of PAD_Power_Group
  * \}
  */
#endif

#if PAD_SUPPORT_ANALOG_MODE
/**
 * \defgroup    Pad_ANA_Mode Pad ANA Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _ANA_MODE
{
    PAD_ANALOG_MODE,      //!< Config Hybrid pad analog function.
    PAD_DIGITAL_MODE,     //!< Config Hybrid pad digital function.
} ANA_MODE;

/** End of Pad_ANA_Mode
  * \}
  */
#endif

#if (PAD_SUPPORT_ADPATER_WAKEUP | PAD_SUPPORT_MFB_WAKEUP)

/**
 * \defgroup    WakeUp_EN_Mode WakeUp EN Mode
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _WAKEUP_EN_MODE
{
    ADP_MODE,    //!< Wake up by adapter.
    BAT_MODE,    //!< Wake up by battery.
    MFB_MODE     //!< Wake up by MFB.
} WAKEUP_EN_MODE;

/** End of WakeUp_EN_Mode
  * \}
  */

/**
 * \defgroup    WakeUp_Polarity WakeUp Polarity
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _WAKEUP_POL
{
    POL_HIGH,    //!< PAD high-level trigger wakeup.
    POL_LOW,     //!< PAD low-level trigger wakeup.
} WAKEUP_POL;

/** End of WakeUp_Polarity
  * \}
  */
#endif

#if PAD_SUPPORT_GET_OUTPUT_CTRL
/**
 * \defgroup    PAD_AON_Status PAD AON Status
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum _PAD_AON_Status
{
    PAD_AON_OUTPUT_LOW,        //!< Pad AON output low level.
    PAD_AON_OUTPUT_HIGH,       //!< Pad AON output high level.
    PAD_AON_OUTPUT_DISABLE,    //!< Pad AON output disable.
    PAD_AON_PINMUX_ON,         //!< Pad AON pinmux on.
    PAD_AON_PIN_ERR            //!< Pad AON pin error.
} PAD_AON_Status;

/** End of PAD_AON_Status
  * \}
  */
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
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
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

#if PAD_SUPPORT_MULTI_CORE
/**
 * \brief  Deinit the VCORE1 IO function of one pin.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pinmux_V1_Deinit(P2_2);
 * }
  * \endcode
  */
void Pinmux_V1_Deinit(uint8_t Pin_Num);

/**
 * \brief  Deinit the VCORE3 IO function of one pin.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pinmux_CODEC_Deinit(P2_2);
 * }
  * \endcode
  */
void Pinmux_CODEC_Deinit(uint8_t Pin_Num);
#endif

/**
 * \brief     Configure the specified pin to its corresponding IO function.
 *
 * \param[in] Pin_Num   Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] Pin_Func  IO function of pin. Refer to \ref PIN_Function.
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
void Pinmux_Config(uint8_t Pin_Num, uint8_t Pin_Func);

#if PAD_SUPPORT_MULTI_CORE
/**
 * \brief     Config the usage function of the selected pin.
 *
 * \param[in] Pin_Num   Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] Pin_Func  IO function of pin. Refer to \ref PIN_Function.
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

 *     Pinmux_CODEC_Config(P2_0, UART0_TX);
 *     Pinmux_CODEC_Config(P2_1, UART0_RX);
 * }
 * \endcode
 */
void Pinmux_CODEC_Config(uint8_t Pin_Num, uint8_t Pin_Func);

/**
 * \brief  Config pin to VCORE1 domain dedicated mux.
 *
 * \param[in] Pin_Num   Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] Pin_Func  IO function of pin. Refer to \ref PIN_Function.
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

 *     Pinmux_CODEC_Config(P2_0, DMIC1_CLK);
 *     Pinmux_CODEC_Config(P2_1, DMIC1_DAT);
 * }
 * \endcode
 */

void Pinmux_V1_Config(uint8_t Pin_Num, uint8_t Pin_Func);
#endif

#if PINMUX_SUPPORT_AON_CONFIG
/**
 * \brief  Configure the specified pin to its corresponding pin AON function
 *
 * \param[in] Pin_Func  AON function of pin. Refer to \ref PINMUX_AON_Function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     Pad_Config(XI32K, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_HIGH);
 *     Pinmux_AON_Config(RTC_IN_PAD_32K_XI);
 * }
 * \endcode
 */
void Pinmux_AON_Config(uint16_t Pin_Func);
#endif

#if PINMUX_SUPPORT_HS_CONFIG
/**
 * \brief  Configure the specified pin to its corresponding pin high speed function.
 *
 * \param[in] Pin_Func  High Speed function. Refer to \ref PINMUX_HS_Function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *      Pinmux_HS_Config(SPI0_HS);
 * }
 * \endcode
 */
void Pinmux_HS_Config(uint32_t Pin_Func);
#endif

/**
 * \brief     Configure the relevant operation mode,
 *            peripheral circuit and output level value in software mode of the specified pin
 *
 * \param[in] Pin_Num        Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] AON_PAD_Mode   Use software mode or pinmux mode.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_SW_MODE: pad pin is configured software mode.
 *                           \arg PAD_PINMUX_MODE: pad pin is configured pinmux mode.
 * \param[in] AON_PAD_PwrOn  Config power of pad.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_NOT_PWRON: pad is not power.
 *                           \arg PAD_IS_PWRON: pad is power on.
 * \param[in] AON_PAD_Pull   Config pad pull mode.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_PULL_NONE: Pull None.
 *                           \arg PAD_PULL_UP: Pull up.
 *                           \arg PAD_PULL_DOWN: Pull down.
 * \param[in] AON_PAD_E      Config pad out put function.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_OUT_DISABLE: Disable pin output.
 *                           \arg PAD_OUT_ENABLE: Enable pad output.
 * \param[in] AON_PAD_O      Config pin output level.
 *                           This parameter can be one of the following values:
 *                           - PAD_OUT_LOW: Pad output low level.
 *                           - PAD_OUT_HIGH: Pad output high level.
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

#if PAD_SUPPORT_CONFIG_EXT
/**
 * \brief     Configure the relevant operation mode, peripheral circuit, pull resistor value and
 *            output level value in software mode of the specified pin.
 *
 * \param[in] Pin_Num        Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] AON_PAD_Mode   Use software mode or pinmux mode.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_SW_MODE: Use software mode.
 *                           \arg PAD_PINMUX_MODE: Use pinmux mode.
 * \param[in] AON_PAD_PwrOn  Config power of pad.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_SHUTDOWN: Shutdown power of pad.
 *                           \arg PAD_IS_PWRON: Enable power of pad.
 * \param[in] AON_PAD_Pull   Config pad pull mode.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_PULL_NONE: No pull.
 *                           \arg PAD_PULL_UP: Pull this pin up.
 *                           \arg PAD_PULL_DOWN: Pull this pin down.
 * \param[in] AON_PAD_E      Config pad output function, which only valid when PAD_SW_MODE.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_OUT_DISABLE: Disable pin output.
 *                           \arg PAD_OUT_ENABLE: Enable pad output.
 * \param[in] AON_PAD_O      Config pin output level, which only valid when PAD_SW_MODE and output mode.
 *                           This parameter can be one of the following values:
 *                           \arg PAD_OUT_LOW: Pad output low.
 *                           \arg PAD_OUT_HIGH: Pad output high.
 * \param[in] AON_PAD_P      Config resistor value.
 *                           This parameter can be one of the following values:
 *                           - PAD_150K_PULL: pad pull 150k resistance.
 *                           - PAD_15K_PULL: pad pull 15k resistance.
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

#if PAD_SUPPORT_DEDICATE_CONFIG
/**
 * \brief     Config the corresponding pad dedicated function.
 *
 * \param[in] Pin_Num  Pin number to be configured.
 *                     This parameter is specific to certain Pins that support dedicated IO.
 * \param[in] Status   Enable or disable the pad dedicate dedicated function.
 *                     - ENABLE: Enable the pad dedicated function.
 *                     - DISABLE: Disable the pad dedicated function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     Pad_Dedicated_Config(P2_2, Enable);
 * }
 * \endcode
 */
void Pad_Dedicated_Config(uint8_t Pin_Num, FunctionalState Status);
#endif

#if PAD_SUPPORT_CONFIG_DEFAULT
/**
 * \brief   Set all pins to the default state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_AllConfigDefault();
 * }
 * \endcode
 */
extern void Pad_AllConfigDefault(void);
#endif

#if PAD_SUPPORT_WAKEUP_MULTI_GROUP
bool System_WakeUpDebounceMultiGroupEnable(uint8_t Pin_Num);
bool System_WakeUpDebounceMultiGroupDisable(uint8_t Pin_Num);
#endif

/**
 * \brief     Enable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_Num     Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] Polarity    Polarity of wake-up system.
 *                        This parameter can be the following:
 *                        \arg PAD_WAKEUP_POL_HIGH: Use high level wake-up polarity.
 *                        \arg PAD_WAKEUP_POL_LOW: Use low level wake-up polarity.
 * \param[in] DebounceEn  Enable delay function.
 *                        - PAD_WK_DEBOUNCE_DISABLE: Disable wake-up debounce function.
 *                        - PAD_WK_DEBOUNCE_ENABLE: Enable wake-up debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * //IO enter dlps call back function.
 * void io_uart_dlps_enter(void)
 * {
 *     // Switch pad to software mode
 *     Pad_ControlSelectValue(P2_0, PAD_SW_MODE);//tx pin
 *     Pad_ControlSelectValue(P2_1, PAD_SW_MODE);//rx pin
 *
 *     System_WakeUpPinEnable(P2_1, PAD_WAKEUP_POL_LOW, PAD_WK_DEBOUNCE_DISABLE);
 * }
 * \endcode
 */
void System_WakeUpPinEnable(uint8_t Pin_Num, uint8_t Polarity, uint8_t DebounceEn);

/**
 * \brief     Disable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define UART_RX_PIN                P4_1
 *
 * //System interrupt handler function, for wake-up pin.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(UART_RX_PIN);
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
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return Interrupt status.
 *         - 1: Pin wake up interrupt status is true.
 *         - 0: Pin wake up interrupt status is false.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define UART_RX_PIN                P4_1
 *
 * //System interrupt handler function, for wakeup pin.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(UART_RX_PIN);
 *         System_WakeUpPinDisable(UART_RX_PIN);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num);

/**
 * \brief  Enable or disable wake-up debounce function.
 *
 * \param[in] Pin_Num               Pin number to be configured. Refer to \ref Pin_Number.
 * \note                            Pin_Num is invalid parameter for rtl87x2g series so that any pin can be filled in.
 * \param[in] PADWakeupCmd_TypeDef  Wake-up system enable or disable
 *                                  - PAD_WAKEUP_DISABLE: Disable wake-up function.
 *                                  - PAD_WAKEUP_DISABLE: Enable wake-up function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *void System_WakeUpPinEnable(uint8_t Pin_Num, uint8_t Polarity, uint8_t DebounceEn)
 *{
 *    if(Pin_Num >= MAX_PIN_NUM)
 *    {
 *        return;
 *    }
 *
 *    Pad_SetWakeupPolarity(Pin_Num, Polarity);
 *    Pad_WakeupDebounce_Cmd(Pin_Num, DebounceEn);
 *    if (PAD_WAKEUP_DEB_ENABLE == DebounceEn)
 *    {
 *        System_WakeUpDebounceCmd(Pin_Num, PAD_WAKEUP_ENABLE);
 *    }
 *    Pad_Wakeup_Cmd(Pin_Num, ENABLE);
 *}
 * \endcode
 */
void System_WakeUpDebounceCmd(uint8_t Pin_Num, PADWakeupCmd_TypeDef Status);

/**
 * \brief   Config wake up system debounce time.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \note               Pin_Num is invalid parameter for rtl87x2g series so that any pin can be filled in.
 * \param[in] time_ms  Debounce time. Unit: ms.
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
void System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t time_ms);

/**
 * \brief   Config wake up system debounce time.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \note               Pin_Num is invalid parameter for rtl87x2g series so that any pin can be filled in.
 * \param[in] time_us  Debounce time. Unit: us.
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
void System_WakeUpDebounceTimeUs(uint8_t Pin_Num, uint8_t time_us);

/**
 * \brief  Get debounce wake up status.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \note               Pin_Num is invalid parameter for rtl87x2g series so that any pin can be filled in.
 *
 * \return Debounce wakeup status.
 *         - 1: Pin debounce wakeup status is true.
 *         - 0: Pin debounce wakeup status is false.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     uint8_t WakeupDebounceStatus = System_WakeupDebounceStatus;
 * }
 * \endcode
 */

uint8_t System_WakeupDebounceStatus(uint8_t Pin_Num);

/**
 * \brief  Clear debounce wake up status. Call this API will clear the debunce wakeup status bit.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \note               Pin_Num is invalid parameter for rtl87x2g series so that any pin can be filled in.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dlps_store(void)
 * {
 *     System_WakeupDebounceClear(P0_0);
 * }
 * \endcode
 */
void System_WakeupDebounceClear(uint8_t Pin_Num);

/**
 * \brief     Configure the driving current.
 *
 * \param[in] Pin_Num              Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] PAD_Driving_Current  This parameter sets the driving current.
 *                                 Refer to \ref PADDrivingCurrent_TypeDef.
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
void Pad_SetDrivingCurrent(uint8_t Pin_Num, PADDrivingCurrent_TypeDef PAD_Driving_Current);

/**
 * \brief     Set pin control mode.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] value    This parameter sets the pin mode.
 *                     This parameter can be the following:
 *                     - PAD_SW_MODE: Software mode.
 *                     - PAD_PINMUX_MODE: Pinmux mode.
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
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] value    This parameter sets whether the pin outputs the level in software mode.
 *                     This parameter can be enumerated \ref PAD_Output_Config of the values:
 *                     - PAD_OUT_DISABLE: Disable output.
 *                     - PAD_OUT_ENABLE: Enable output.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_OutputEnableValue(P2_0, PAD_OUT_ENABLE);
 * }
 * \endcode
 */
void Pad_OutputCmd(uint8_t Pin_Num, PADOutputMode_TypeDef Status);

/**
 * \brief     Configure pad output level.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] value    Config pin output level.
 *                     This parameter can be one of the following values:
 *                     - PAD_OUT_LOW: Pad output low.
 *                     - PAD_OUT_HIGH: Pad output high.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_OutputControlValue(P2_0, PAD_OUT_HIGH);
 * }
 * \endcode
 */
void Pad_SetOutputLevel(uint8_t Pin_Num, uint8_t value);

/**
 * \brief     Enable or disable pad pull resistance.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] value    This parameter enable or disable the the pad pin pull resistance.
 *                     This parameter can be the following value:
 *                     - DISABLE: Disable pad pull function.
 *                     - ENABLE: Enable  pad pull function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PullEnableValue(P2_0, ENABLE);
 * }
 * \endcode
 */
void Pad_PullCmd(uint8_t Pin_Num, FunctionalState Status);

/**
 * \brief     Pad pull-up/pull-down resistance function selection.
 *
 * \param[in] Pin_Num        Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] PAD_Pull_Mode  Config pad pull mode.
 *                           This parameter can be the following values, refer to \ref PAD_Pull_Mode.
 *                           - PAD_PULL_NONE: No pull.
 *                           - PAD_PULL_UP: Pull this pin up
 *                           - PAD_PULL_DOWN: Pull this pin down.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PullUpOrDownValue(P2_0, 1);
 * }
 * \endcode
 */
void Pad_SetPullMode(uint8_t Pin_Num, PADPullMode_TypeDef PAD_Pull_Mode);

/**
 * \brief     Configure the strength of pull-up/pull-down resistance.
 *
 * \param[in] Pin_Num                 Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] PAD_Pull_Strength_Mode  This parameter sets the strength of pull-up/pull-down resistance.
 *                                    This parameter can be the following values, refer to \ref PAD_Pull_Strength_Mode.
 *                                    - PAD_PULL_WEAK: Resistance weak pull.
 *                                    - PAD_PULL_STRONG: Resistance strong pull.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PullConfigValue(P2_0, PAD_PULL_STRONG);
 * }
 * \endcode
 */
void Pad_SetPullStrength(uint8_t Pin_Num, PADPullStrengthMode_TypeDef PAD_Pull_Strength_Mode);

/**
 * \brief     Set pin power mode.
 *
 * \param[in] Pin_Num   Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] PWR_Mode  Config power of pad.
 *                      This parameter can be the following values, refer to \ref PAD_Power_Mode.
 *                      - PAD_NOT_PWRON: Power off.
 *                      - PAD_IS_PWRON: Power on.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PowerOrShutDownValue(P2_0, PAD_NOT_PWRON);
 * }
 * \endcode
 */
void Pad_PowerCmd(uint8_t Pin_Num, PADPowerMode_TypeDef PWR_Mode);

/**
 * \brief     Clear the interrupt pending bit of the specified pin.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ClearWakeupINTPendingBit(P2_0);
 * }
 * \endcode
 */
void Pad_ClearWakeupINTPendingBit(uint8_t Pin_Num);

/**
 * \brief     Clear all wake up pin interrupt pending bit.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ClearAllWakeupINT();
 * }
 * \endcode
 */
void Pad_ClearAllWakeupINT(void);

/**
 * \brief  Short pulse wakeup function.
 *
 * \param[in] Status  PAD_SHORT_PULSE_WAKEUP_DISABLE or PAD_SHORT_PULSE_WAKEUP_ENABLE.
 *                    This parameter refer to \ref PAD_SHORT_PULSE_WAKEUP_EN.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_ShortPulseWakeUpCmd(PAD_SHORT_PULSE_WAKEUP_ENABLE);
 * }
 * \endcode
 */

void Pad_ShortPulseWakeUpCmd(PADSPWakeupCmd_TypeDef Status);

#if PAD_SUPPORT_AON_WAKEUP
/**
 * \brief  Get aon wake up int.
 *
 * \return  Wakeup intterupt.
 *          - bit0: aon pad wake up int
 *          - bit1: aon lpc0 wake up int
 *          - bit2: aon lpc1 wake up int
 *          - bit3: aon qdec wake up int
 *          - bit4: aon vadbuf wake up int
 *          - bit5: aon vad wake up int
 *          - bit6: aon usb wake up int
 *          - bit7: aon rtc wake up int
 *          - bit8: aon pf rtc wake up int
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     get_aon_wakeup_int();
 * }
 * \endcode
 */

uint32_t get_aon_wakeup_int(void);

/**
 * \brief  Clear aon wake up int.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     clear_aon_wakeup_int();
 * }
 * \endcode
 */
void clear_aon_wakeup_int(void);
#endif

#if PAD_SUPPORT_GET_OUTPUT_CTRL
/**
 * \brief   Get pad current output/input setting.
 *
 * \param[in] Pin_Num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return   Refer to \ref PAD_AON_Status.
 *           - PAD_AON_OUTPUT_LOW: Pad AON output low level.
 *           - PAD_AON_OUTPUT_HIGH: Pad AON output high level.
 *           - PAD_AON_OUTPUT_DISABLE: Pad AON output disable.
 *           - PAD_AON_PINMUX_ON: Pad AON pinmux on.
 *           - PAD_AON_PIN_ERR: Pad AON pin error.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
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

#if PAD_SUPPORT_GET_POWER_GROUP
/**
 * \brief   Get the pin power group.
 *
 * \param[in] pin  pin of set only VDDIO pin.
 *
 * \return   get the power group of the pin. Please refer to \ref PAD_Power_Group.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_GetPowerGroup(P2_1);
 * }
 * \endcode
 */
T_PIN_POWER_GROUP  Pad_GetPowerGroup(uint8_t pin);
#endif

#if PAD_SUPPORT_GET_PIN_NAME
/**
 * \brief   Get the pin name in string.
 *
 * \param[in] pin_num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return   pin name or null.
 *           - pin name
 *           - null due to invalid pin index.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_GetPinName(P2_1);
 * }
 * \endcode
 */
const char *Pad_GetPinName(uint8_t pin_num);
#endif

#if PAD_SUPPORT_ANALOG_MODE
/**
 * \brief   Config Hybrid pad analog/digital functions.
 *
 * \param[in] pin   Pin number to be configured. Refer to \ref Pin_Number.
 * \param[in] mode  Please refer to \ref Pad_ANA_Mode.
 *                  This parameter can be: PAD_ANALOG_MODE/PAD_DIGITAL_MODE.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_AnalogMode(P2_1, PAD_ANALOG_MODE);
 * }
 * \endcode
 */
void Pad_AnalogMode(uint8_t pin, ANA_MODE mode);
#endif

#if (PAD_SUPPORT_ADPATER_WAKEUP | PAD_SUPPORT_MFB_WAKEUP)
/**
 * \brief   Config the system wakeup mode.
 *
 * \param[in] mode      Mode of set, this parameter can refer to \ref WakeUp_EN_Mode.
 *                      This parameter can be one of the following values:
 *                      \arg ADP_MODE: Wake up by adapter.
 *                      \arg BAT_MODE: Wake up by battery.
 *                      \arg MFB_MODE: Wake up by MFB.
 *                      \arg USB_MODE: Wake up by USB.
 * \param[in] pol       Polarity to wake up.
 *                      This parameter can be one of the following values:
 *                      \arg POL_HIGH: Use high level wakeup.
 *                      \arg POL_LOW: Use low level wakeup.
 * \param[in] NewState  Enable or disable wake up.
 *                      This parameter can be one of the following values:
 *                      \arg ENABLE: Enable the system wake up at specified polarity.
 *                      \arg DISABLE: Disable the system wake up at specified polarity.
 *
 * \return     Config the system wakeup mode fail or success.
 *             - 0: Config success.
 *             - 1: Config fail due to wrong mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is WAKE_UP_GENERAL
 *     Pad_WakeUpConfig(ADP_MODE, POL_HIGH, ENABLE);
 * }
 * \endcode
 */
uint8_t  Pad_WakeUpCmd(WAKEUP_EN_MODE mode, WAKEUP_POL pol, FunctionalState NewState);
#endif

#if PAD_SUPPORT_ADPATER_WAKEUP
/**
 * \brief   Configure the adpater wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState  Enable or disable adpater wake up.
 *                      This parameter can be one of the following values:
 *                      \arg ENABLE: Enable adpater wake up system at specified polarity.
 *                      \arg DISABLE: Disable adpater wake up system.
 * \param[in] pol       Polarity to wake up.
 *                      This parameter can be one of the following values:
 *                      - POL_HIGH: Use high level wakeup.
 *                      - POL_LOW: Use low level wakeup.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is wake_up_power_off
 *     System_SetAdpWakeUpFunction(ENABLE, POL_HIGH);
 * }
 * \endcode
 */
void System_SetAdpWakeUpFunction(FunctionalState NewState, WAKEUP_POL pol);
#endif

#if PAD_SUPPORT_MFB_WAKEUP
/**
 * \brief   Configure the MFB wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState  Enable or disable MFB wake up.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable MFB wake up system.
 *                      - DISABLE: Disable MFB wake up system.
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
void System_SetMFBWakeUpFunction(FunctionalState NewState);
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


