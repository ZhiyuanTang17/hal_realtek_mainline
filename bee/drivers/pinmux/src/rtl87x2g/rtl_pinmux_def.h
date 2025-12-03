/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_pinmux_def.h
* \brief    Pinmux related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_PINMUX_DEF_H
#define RTL_PINMUX_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          PINMUX Defines
 *============================================================================*/
/** \defgroup PINMUX      PINMUX
  * \brief
  * \{
  */

/** \defgroup PINMUX_Exported_Constants PINMUX Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup PINMUX_Defines PINMUX Defines
 * \{
 * \ingroup  PINMUX_Exported_Constants
 */
#define PINMUX_SUPPORT_AON_CONFIG                      (1)
#define PINMUX_SUPPORT_HS_CONFIG                       (1)
#define PAD_DRIVING_CURRENT_LEVEL                      (4)
#define PAD_SUPPORT_DEDICATE_CONFIG                    (1)
#define PAD_SUPPORT_MULTI_CORE                         (0)
#define PAD_SUPPORT_AON_WAKEUP                         (0)
#define PAD_SUPPORT_CONFIG_EXT                         (0)
#define PAD_SUPPORT_CONFIG_DEFAULT                     (0)
#define PAD_SUPPORT_SLEEP_LED                          (0)
#define PAD_SUPPORT_FUNCTION_CONFIG                    (0)
#define PAD_SUPPORT_GET_POWER_GROUP                    (0)
#define PAD_SUPPORT_GET_PIN_NAME                       (0)
#define PAD_SUPPORT_GET_OUTPUT_CTRL                    (0)
#define PAD_SUPPORT_ANALOG_MODE                        (0)
#define PAD_SUPPORT_ADPATER_WAKEUP                     (0)
#define PAD_SUPPORT_MFB_WAKEUP                         (0)

/** End of PINMUX_Defines
  * \}
  */

/** End of PINMUX_Exported_Constants
  * \}
  */

/** End of PINMUX
  * \}
  */

/*============================================================================*
 *                         PINMUX Registers Memory Map
 *============================================================================*/
/**
 * \brief Pinmux Register
 */

typedef struct                      /*!< Pinmux Structure */
{
    __IO uint32_t CFG[21];          /*!<  */
} PINMUX_TypeDef;

/*============================================================================*
 *                         PINMUX Declaration
 *============================================================================*/
/** \defgroup PINMUX      PINMUX
  * \brief
  * \{
  */

/** \defgroup PINMUX_Exported_Constants PINMUX Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup PINMUX_Declaration PINMUX Declaration
 * \{
 * \ingroup  PINMUX_Exported_Constants
 */
#define PINMUX                  ((PINMUX_TypeDef *) PINMUX_REG_BASE)

/** End of PINMUX_Declaration
  * \}
  */

/** End of PINMUX_Exported_Constants
  * \}
  */

/** End of PINMUX
  * \}
  */

/*============================================================================*
 *                         PINMUX Private Types
 *============================================================================*/
typedef struct
{
    uint32_t pinmux_reg[21];
} PINMUXStoreReg_Typedef;

/*============================================================================*
 *                         PINMUX Constants
 *============================================================================*/
/** \defgroup PINMUX      PINMUX
  * \brief
  * \{
  */

/** \defgroup PINMUX_Exported_Constants PINMUX Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    PIN_Function PIN Function
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */

#define IDLE_MODE                   0

#define UART0_TX                    1
#define UART0_RX                    2
#define UART0_CTS                   3
#define UART0_RTS                   4
#define UART1_TX                    5
#define UART1_RX                    6
#define UART1_CTS                   7
#define UART1_RTS                   8
#define UART2_TX                    9
#define UART2_RX                    10
#define UART2_CTS                   11
#define UART2_RTS                   12
#define UART3_TX                    13
#define UART3_RX                    14
#define UART3_CTS                   15
#define UART3_RTS                   16
#define UART4_TX                    17
#define UART4_RX                    18
#define UART4_CTS                   19
#define UART4_RTS                   20
#define UART5_TX                    21
#define UART5_RX                    22
#define UART5_CTS                   23
#define UART5_RTS                   24

#define I2C0_CLK                    29
#define I2C0_DAT                    30
#define I2C1_CLK                    31
#define I2C1_DAT                    32
#define I2C2_CLK                    33
#define I2C2_DAT                    34
#define I2C3_CLK                    35
#define I2C3_DAT                    36
#define SPI0_CLK_MASTER             37
#define SPI0_MO_MASTER              38
#define SPI0_MI_MASTER              39
#define SPI0_CSN_0_MASTER           40
#define SPI0_CSN_1_MASTER           41
#define SPI0_CSN_2_MASTER           42
#define SPI0_CSN_0_SLAVE            43
#define SPI0_CLK_SLAVE              44
#define SPI0_SO_SLAVE               45
#define SPI0_SI_SLAVE               46
#define SPI1_CLK_MASTER             47
#define SPI1_MO_MASTER              48
#define SPI1_MI_MASTER              49
#define SPI1_CSN_0_MASTER           50
#define SPI1_CSN_1_MASTER           51
#define SPI1_CSN_2_MASTER           52
#define SPI2W_DATA                  53
#define SPI2W_CLK                   54
#define SPI2W_CS                    55

#define ENPWM0_P                    65
#define ENPWM0_N                    66
#define ENPWM1_P                    67
#define ENPWM1_N                    68
#define ENPWM2_P                    69
#define ENPWM2_N                    70
#define ENPWM3_P                    71
#define ENPWM3_N                    72

#define TIMER_PWM2                  83
#define TIMER_PWM3                  84

#define ISO7816_RST                 85
#define ISO7816_CLK                 86
#define ISO7816_IO                  87
#define ISO7816_VCC_EN              88
#define DWGPIO                      89
#define IRDA_TX                     90
#define IRDA_RX                     91
#define TIMER_PWM4                  92
#define TIMER_PWM5                  93
#define TIMER_PWM6                  94
#define TIMER_PWM7                  95
#define TIMER_PWM2_P                96
#define TIMER_PWM2_N                97
#define TIMER_PWM3_P                98
#define TIMER_PWM3_N                99
#define KEY_COL_0                   100
#define KEY_COL_1                   101
#define KEY_COL_2                   102
#define KEY_COL_3                   103
#define KEY_COL_4                   104
#define KEY_COL_5                   105
#define KEY_COL_6                   106
#define KEY_COL_7                   107
#define KEY_COL_8                   108
#define KEY_COL_9                   109
#define KEY_COL_10                  110
#define KEY_COL_11                  111
#define KEY_COL_12                  112
#define KEY_COL_13                  113
#define KEY_COL_14                  114
#define KEY_COL_15                  115
#define KEY_COL_16                  116
#define KEY_COL_17                  117
#define KEY_COL_18                  118
#define KEY_COL_19                  119
#define KEY_ROW_0                   120
#define KEY_ROW_1                   121
#define KEY_ROW_2                   122
#define KEY_ROW_3                   123
#define KEY_ROW_4                   124
#define KEY_ROW_5                   125
#define KEY_ROW_6                   126
#define KEY_ROW_7                   127
#define KEY_ROW_8                   128
#define KEY_ROW_9                   129
#define KEY_ROW_10                  130
#define KEY_ROW_11                  131

#define km4_clk_div_4               138
//#define DSP_GPIO_OUT                139
//#define DSP_JTCK                    140
//#define DSP_JTDI                    141
//#define DSP_JTDO                    142
//#define DSP_JTMS                    143
//#define DSP_JTRST                   144
//#define dsp_clk_div_4               145

#define card_detect_n_0             147
#define biu_volt_reg_0              148
#define back_end_power_0            149
#define card_int_n_sdhc_0           150

#define CAN_TX                      155
#define CAN_RX                      156

#define LRC_SPORT1                  157
#define BCLK_SPORT1                 158
#define ADCDAT_SPORT1               159
#define DACDAT_SPORT1               160

#define DMIC1_CLK                   162
#define DMIC1_DAT                   163
#define LRC_I_CODEC_SLAVE           164
#define BCLK_I_CODEC_SLAVE          165
#define SDI_CODEC_SLAVE             166
#define SDO_CODEC_SLAVE             167

#define LRC_SPORT0                  172
#define BCLK_SPORT0                 173
#define ADCDAT_SPORT0               174
#define DACDAT_SPORT0               175
#define MCLK_OUT                    176

#define MCLK_IN                     189
#define LRC_RX_CODEC_SLAVE          190
#define LRC_RX_SPORT0               191
#define LRC_RX_SPORT1               192

#define PDM_DATA                    196
#define PDM_CLK                     197

#define I2S1_LRC_TX_SLAVE           198
#define I2S1_BCLK_SLAVE             199
#define I2S1_SDI_SLAVE              200
#define I2S1_SDO_SLAVE              201
#define I2S1_LRC_RX_SLAVE           202

#define BT_COEX_I_0                 216
#define BT_COEX_I_1                 217
#define BT_COEX_I_2                 218
#define BT_COEX_I_3                 219
#define BT_COEX_O_0                 220
#define BT_COEX_O_1                 221
#define BT_COEX_O_2                 222
#define BT_COEX_O_3                 223
#define PTA_I2C_CLK_SLAVE           224
#define PTA_I2C_DAT_SLAVE           225
#define PTA_I2C_INT_OUT             226
#define EN_EXPA                     227
#define EN_EXLNA                    228
#define SEL_TPM_SW                  229
#define SEL_TPM_N_SW                230
#define ANT_SW0                     231
#define ANT_SW1                     232
#define ANT_SW2                     233
#define ANT_SW3                     234
#define ANT_SW4                     235
#define ANT_SW5                     236
#define phy_gpio_1                  237
#define phy_gpio_2                  238
#define slow_debug_mux_1            239
#define slow_debug_mux_2            240

#define test_mode                   246

#define SWD_CLK                     253
#define SWD_DIO                     254
#define dig_debug                   255

/** End of PIN_Function
  * \}
  */

/**
 * \defgroup    PAD_Aon_Mux PAD Aon Mux
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
#define RTC_IN_NONE         0x0800
#define RTC_IN_PAD_32K_XI   0x0801
#define RTC_IN_PAD_P2_4     0x0802

#define QDPH0_IN_NONE       0x0F00
#define QDPH0_IN_P1_3_P1_4  0x0F01
#define QDPH0_IN_P5_6_P5_7  0x0F02
#define QDPH0_IN_P9_0_P9_1  0x0F03

/** End of PAD_Aon_Mux
  * \}
  */

/**
 * \defgroup    PAD_HS_Mux PAD HSMux
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
#define DISPLAY_CONTROLLER_HS_MUX     0x00000
#define SPI0_HS_MUX                   0x0000F
#define SDHC_HS_MUX                   0x10000
#define SPIC2_HS_MUX                  0x15550
#define ETHERNET_HS_MUX               0x1AAA0

/** End of PAD_HS_Mux
  * \}
  */

/*============================================================================*
 *                          PINMUX TYPE/API WRAPPERS
 *============================================================================*/
/**
 * \defgroup PAD_Constant_Wrapper PAD_Constant_Wrapper
 * \{
 * \ingroup  PINMUX_Exported_Constants
 */
#define PAD_DRIVING_CURRENT_4mA         LEVEL0
#define PAD_DRIVING_CURRENT_8mA         LEVEL1
#define PAD_DRIVING_CURRENT_12mA        LEVEL2
#define PAD_DRIVING_CURRENT_16mA        LEVEL3

/** End of PAD_Constant_Wrapper
  * \}
  */

/**
 * \defgroup PAD_API_Wrapper PAD API Wrapper
 * \{
 * \ingroup  PINMUX_Exported_Constants
 */
#define Pad_ControlSelectValue          Pad_SetControlMode
#define Pad_OutputEnableValue           Pad_Output_Cmd
#define Pad_OutputControlValue          Pad_SetOutputValue
#define Pad_PullEnableValue             Pad_Pull_Cmd
#define Pad_PullUpOrDownValue           Pad_SetPullMode
#define Pad_PullConfigValue             Pad_SetPullStrengthMode
#define Pad_PowerOrShutDownValue        Pad_Power_Cmd
#define Pad_DrivingCurrentControl       Pad_SetDrivingCurrent
#define Pad_WakeupEnableValue           Pad_Wakeup_Cmd
#define Pad_WakeupPolarityValue         Pad_SetWakeupPolarity
#define Pad_WKDebounceConfig            Pad_WakeupDebounce_Cmd
#define Pad_WakeupInterruptValue        Pad_GetWakeupINTStatus

#define System_DebounceWakeupStatus     System_WakeupDebounceStatus
#define System_Pad_WakeUp_Cmd           System_WakeUpDebounceCmd

#define Pad_Output_Cmd                  Pad_OutputCmd
#define Pad_SetOutputValue              Pad_SetOutputLevel
#define Pad_Pull_Cmd                    Pad_PullCmd
#define Pad_SetPullStrengthMode         Pad_SetPullStrength
#define Pad_Power_Cmd                   Pad_PowerCmd
#define Pad_Wakeup_Cmd                  Pad_WakeupConfig
#define Pad_WakeupDebounce_Cmd          Pad_WakeupDebounceCmd

/** End of PAD_API_Wrapper
  * \}
  */

/** End of PINMUX_Exported_Constants
  * \}
  */

/** End of PINMUX
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_PINMUX_DEF_H */
