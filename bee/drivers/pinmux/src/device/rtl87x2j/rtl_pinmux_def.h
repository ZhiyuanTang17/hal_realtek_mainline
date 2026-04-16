/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_PINMUX_DEF_H
#define RTL_PINMUX_DEF_H

#include <string.h>
#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"
#include "pcc_reg.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"

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
#define PAD_SUPPORT_CONFIG_PON_DOMAIN                  (1)
#define PAD_SUPPORT_FUNCTION_CONFIG                    (1)
#define PAD_SUPPORT_HIGH_SPEED_CONFIG                  (1)
#define PAD_SUPPORT_CONFIG_EXT                         (0)
#define PAD_SUPPORT_ANALOG_MODE                        (0)
#define PAD_SUPPORT_GET_PIN_NAME                       (1)
#define PAD_SUPPORT_GET_POWER_GROUP                    (0)
#define PAD_SUPPORT_GET_OUTPUT_CTRL                    (0)

#define PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE        (1)
#define PAD_SUPPORT_WAKEUP_DEBOUNCE                    (1)
#define PAD_SUPPORT_WAKEUP_DEBOUNCE_MULTI_GROUP        (1)
#define PAD_SUPPORT_WAKEUP_SHORT_PULSE                 (0)
#define PAD_SUPPORT_ADPATER_WAKEUP                     (0)
#define PAD_SUPPORT_MFB_WAKEUP                         (0)
#define PAD_SUPPORT_USB_WAKEUP                         (0)
#define PAD_SUPPORT_LOWER_POWER_CONFIG                 (1)
#define PAD_SUPPORT_WAKE_SUB_IRQ                       (1)
#define PAD_SUPPORT_WKIE_DIFF_BIT                      (1)

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
    __IO uint32_t CFG[(PCC_REG_PMUX_GPIO_SPIC_2 - PCC_r_PMUX_GPIO_P0_0to3 + 4) >> 2];
} PINMUX_TypeDef;

/**
 * \brief Pad Debounce Register
 */

typedef struct
{
    __IO uint32_t MUX_SEL;         /*!< 0x00 */
    __IO uint32_t CNT[3];          /*!< 0x04 ~ 0x0C */
    __IO uint32_t STS;             /*!< 0x10 */
} PADDEB_TypeDef;

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

#define PAD_REG_BASE            (SYSON_BASE)
#define PAD_DEBOUNCE_BASE       (SYSON_BASE + AON_REG_DEB_MUX_SEL)
#define PAD_FUNCTION_BASE       (SYSON_BASE + AON_REG_PAD_VPON_REG0X)
#define PAD_AONMUX_AS_BASE      (SYSON_BASE + AON_REG_PAD_AUTO_SW_AON_REG8X)
#define PAD_PULL_AON_AS_BASE    (SYSON_BASE + AON_REG_PAD_AUTO_SW_AON_REG0X)
#define PAD_PULL_CORE_AS_BASE   (SYSON_BASE + AON_REG_PAD_AUTO_SW_PON_REG0X)
#define PINMUX_REG_BASE         (SYSON_BASE + PCC_r_PMUX_GPIO_P0_0to3)

#define PAD_DEBOUNCE           ((PADDEB_TypeDef *) PAD_DEBOUNCE_BASE)
#define PAD_FUNCTION           (*((volatile uint32_t *) PAD_FUNCTION_BASE))
#define PINMUX                 ((PINMUX_TypeDef *) PINMUX_REG_BASE)

/** End of PINMUX_Exported_Constants
  * \}
  */

/** End of PINMUX_Declaration
  * \}
  */

/** End of PINMUX
  * \}
  */

/*============================================================================*
 *                         PINMUX Private Types
 *============================================================================*/

/* 0x00
   5:0     R/W    deb_mux_sel0        6'h3f
   7:6     R      reserved10          2'b0
   13:8    R/W    deb_mux_sel1        6'h3f
   15:14   R      reserved8           2'b0
   21:16   R/W    deb_mux_sel2        6'h3f
   23:22   R      reserved6           2'b0
   29:24   R/W    deb_mux_sel3        6'h3f
   31:30   R      reserved4           2'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t deb_mux_sel0: 6;
        const uint32_t reserved_3: 2;
        uint32_t deb_mux_sel1: 6;
        const uint32_t reserved_2: 2;
        uint32_t deb_mux_sel2: 6;
        const uint32_t reserved_1: 2;
        uint32_t deb_mux_sel3: 6;
        const uint32_t reserved_0: 2;
    } b;
} PAD_DEB_MUX_SEL_TypeDef;

/* 0x04 ~ 0x0C
   3:0     R      reserved20          4'h0
   11:4    R/W    deb_cnt_l_cnt_limit 8'h0
   14:12   R/W    deb_cnt_l_clk_div   3'h0
   15      R/W    deb_cnt_l_en        1'b0
   19:16   R      reserved16          4'h0
   27:20   R/W    deb_cnt_h_cnt_limit 8'h0
   30:28   R/W    deb_cnt_h_clk_div   3'h0
   31      R/W    deb_cnt_h_en        1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_1: 4;
        uint32_t deb_cnt_l_cnt_limit: 8;
        uint32_t deb_cnt_l_clk_div: 3;
        uint32_t deb_cnt_l_en: 1;
        const uint32_t reserved_0: 4;
        uint32_t deb_cnt_h_cnt_limit: 8;
        uint32_t deb_cnt_h_clk_div: 3;
        uint32_t deb_cnt_h_en: 1;
    } b;
} PAD_DEB_CNT_TypeDef;

/* 0x10
   0       R/W1C  deb_cnt_0_sts       1'b1
   1       R/W1C  deb_cnt_1_sts       1'b1
   2       R/W1C  deb_cnt_2_sts       1'b1
   3       R/W1C  deb_cnt_3_sts       1'b1
   4       R/W1C  deb_cnt_4_sts       1'b1
   31:5    R      reserved37          27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t deb_cnt_0_sts: 1;
        uint32_t deb_cnt_1_sts: 1;
        uint32_t deb_cnt_2_sts: 1;
        uint32_t deb_cnt_3_sts: 1;
        uint32_t deb_cnt_4_sts: 1;
        const uint32_t reserved_0: 27;
    } b;
} DEB_STS_TypeDef;

typedef union
{
    uint32_t d32;
    struct
    {
        uint8_t reserved: 1;
        uint8_t pd: 1;
        uint8_t pu_en: 1;
        uint8_t reserved1: 4;
        uint8_t as_en: 1;
    } b[4];
} PADMUXAS_TypeDef;

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
/******************* Reference: Bee5_pin_mux_20241231A-bitfile0103.xlsx *******************/
#define IDLE_MODE                  0
#define UART0_TX                   1
#define UART0_RX                   2
#define UART0_CTS                  3
#define UART0_RTS                  4
#define UART1_TX                   5
#define UART1_RX                   6
#define UART1_CTS                  7
#define UART1_RTS                  8
#define UART2_TX                   9
#define UART2_RX                   10
#define UART2_CTS                  11
#define UART2_RTS                  12
#define UART3_TX                   13
#define UART3_RX                   14
#define UART3_CTS                  15
#define UART3_RTS                  16
#define I2C0_CLK                   17
#define I2C0_DAT                   18
#define I2C1_CLK                   19
#define I2C1_DAT                   20
#define SPI0_SS_N_0_SLAVE          21
#define SPI0_CLK_SLAVE             22
#define SPI0_SO_SLAVE              23
#define SPI0_SI_SLAVE              24
#define SPI0_SS_N_0_MASTER         25
#define SPI0_SS_N_1_MASTER         26
#define SPI0_SS_N_2_MASTER         27
#define SPI0_CLK_MASTER            28
#define SPI0_MO_MASTER             29
#define SPI0_MI_MASTER             30
#define SPI1_SS_N_0_MASTER         31
#define SPI1_SS_N_1_MASTER         32
#define SPI1_SS_N_2_MASTER         33
#define SPI1_CLK_MASTER            34
#define SPI1_MO_MASTER             35
#define SPI1_MI_MASTER             36
#define SPI3W_DATA_MASTER          37
#define SPI3W_CLK_MASTER           38
#define SPI3W_CS_MASTER            39
#define SPI3W_QB_MASTER            40
#define PWM0                       41
#define PWM1                       42
#define PWM2                       43
#define PWM3                       44
#define PWM4                       45
#define PWM5                       46
#define PWM6_P                     47
#define PWM6_N                     48
#define PWM7_P                     49
#define PWM7_N                     50
#define PWM8_P                     51
#define PWM8_N                     52
#define PWM9_P                     53
#define PWM9_N                     54
#define IRDA_TX                    55
#define IRDA_RX                    56
#define CAN_TX                     57
#define CAN_RX                     58
#define SWD_CLK                    59
#define SWD_DIO                    60
#define DWGPIO                     90
#define SPI2_SS_N_0_MASTER         91
#define SPI2_CLK_MASTER            92
#define SPI2_MO_MASTER             93
#define SPI2_MI_MASTER             94
#define DIG_DEBUG                  95
#define DMIC1_CLK                  96
#define DMIC1_DAT                  97
#define LRC_I_CODEC_SLAVE          98
#define BCLK_I_CODEC_SLAVE         99
#define SDI_CODEC_SLAVE            100
#define SDO_CODEC_SLAVE            101
#define BT_COEX_I_0                106
#define BT_COEX_I_1                107
#define BT_COEX_I_2                108
#define BT_COEX_I_3                109
#define BT_COEX_O_0                110
#define BT_COEX_O_1                111
#define BT_COEX_O_2                112
#define BT_COEX_O_3                113
#define PTA_I2C_CLK_SLAVE          114
#define PTA_I2C_DAT_SLAVE          115
#define PTA_I2C_INT_OUT            116
#define EN_EXPA                    117
#define EN_EXLNA                   118
#define TRACECLKIN                 119
#define TRACESWO                   120
#define LRC_SPORT0                 123
#define BCLK_SPORT0                124
#define ADCDAT_SPORT0              125
#define DACDAT_SPORT0              126
#define MCLK                       127
#define KEY_COL_0                  128
#define KEY_COL_1                  129
#define KEY_COL_2                  130
#define KEY_COL_3                  131
#define KEY_COL_4                  132
#define KEY_COL_5                  133
#define KEY_COL_6                  134
#define KEY_COL_7                  135
#define KEY_COL_8                  136
#define KEY_COL_9                  137
#define KEY_COL_10                 138
#define KEY_COL_11                 139
#define KEY_COL_12                 140
#define KEY_COL_13                 141
#define KEY_COL_14                 142
#define KEY_COL_15                 143
#define KEY_COL_16                 144
#define KEY_COL_17                 145
#define KEY_COL_18                 146
#define KEY_COL_19                 147
#define KEY_ROW_0                  148
#define KEY_ROW_1                  149
#define KEY_ROW_2                  150
#define KEY_ROW_3                  151
#define KEY_ROW_4                  152
#define KEY_ROW_5                  153
#define KEY_ROW_6                  154
#define KEY_ROW_7                  155
#define KEY_ROW_8                  156
#define KEY_ROW_9                  157
#define KEY_ROW_10                 158
#define KEY_ROW_11                 159
#define KEY_ROW_12                 160
#define KEY_ROW_13                 161
#define KEY_ROW_14                 162
#define KEY_ROW_15                 163
#define KEY_ROW_16                 164
#define KEY_ROW_17                 165

/** End of PIN_Function
  * \}
  */

/**
 * \defgroup    PAD_Function_Config PAD Function Config
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    LPPWM_CH0_SEL  = 0,
    LPQDEC_LED_SEL = 1,
    LPQDEC_PHB_SEL = 2,
    LPQDEC_PHA_SEL = 3,
} PADFuncConfig_TypeDef;

/** End of PAD_Function_Config
  * \}
  */

/**
 * \defgroup    PAD_High_Speed_Config PAD High Speed Config
 * \{
 * \ingroup     PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_HIGH_SPEED_SPI0 = 0,
    PAD_HIGH_SPEED_SPI1 = 1,
    PAD_HIGH_SPEED_SPI2 = 2,
} PADHSConfig_Typedef;

/** End of PAD_High_Speed_Config
  * \}
  */

/**
 * \defgroup    PAD_Driving_Current PAD Driving Current
 * \{
 * \ingroup     PINMUX_Exported_Constants
 *
 * \note        Others support 4/8mA Only
 *              P2_0 ~ P2_7 support 4/8/12/16mA
 *              P0_5 P5_1 P6_1 support 8/16/28mA
 */
typedef enum
{
    PAD_DRIVING_CURRENT_4mA,
    PAD_DRIVING_CURRENT_8mA,
    PAD_DRIVING_CURRENT_18mA,
    PAD_DRIVING_CURRENT_28mA,
} PADDrivingCurrent_TypeDef;


typedef enum _PIN_POWER_GROUP
{
    PAD_POWER_GROUP_INVALID            = 0,
    PAD_POWER_GROUP_RIGHT              = 1,
    PAD_POWER_GROUP_LEFT               = 2,
    PAD_POWER_GROUP_BOTTOM             = 3,
} PADPowerGroup_TypeDef;

/** End of PAD_Driving_Current
  * \}
  */

/** End of PINMUX_Exported_Constants
  * \}
  */

/** End of PINMUX
  * \}
  */

/*============================================================================*
 *                         PINMUX Private
 *============================================================================*/
#define BITOFFSET(n)                     (__builtin_ffs(n) - 1)
#define PAD_REG_READ(addr)               (*((volatile uint32_t *)(addr)))
#define PAD_REG_WRITE(addr, value)       (*((volatile uint32_t *)(addr)) = (value))
#define Pad_TableConfig(Mode, Pin_Num, Value) do                                  \
    {                                                                             \
        uint32_t reg_addr_offset = PAD_REG_BASE + pad_addr_table.reg[Pin_Num];    \
        uint32_t reg_high_offset = (reg_addr_offset & BIT1) ? 16 : 0;             \
        reg_addr_offset &= ~BIT1;                                                 \
        uint32_t reg_value = PAD_REG_READ(reg_addr_offset);                       \
        reg_value &= ~(Mode << reg_high_offset);                                  \
        if (Value) {                                                              \
            reg_value |= (Value << BITOFFSET(Mode) << reg_high_offset);           \
        }                                                                         \
        PAD_REG_WRITE(reg_addr_offset, reg_value);                                \
    } while(0)

/* PAD Registers Field -------------------------------------- */
#define OUTPUT_VAL                  (BIT0)
#define OUTPUT_EN                   (BIT1)
#define PULL_EN                     (BIT2)
#define PULL_DIR                    (BIT3)
#define PULL_RES                    (BIT4)
#define WAKEUP_EN                   (BIT5)
#define WAKEUP_POL                  (BIT6)
#define POWER_SHDN                  (BIT7)
#define PAD_DEB                     (BIT8)
#define WAKEUP_RAP                  (BIT9)
#define WAKEUP_PPU                  (BIT10)
#define PAD_RSVD0                   (BIT11)
#define CUR_DRIVING                 (BIT12)
#define PAD_RSVD1                   (BIT13)
#define AON_MUX                     (BIT14 | BIT15)
#define PAD_CONFIG_MASK             (OUTPUT_VAL | OUTPUT_EN | PULL_EN | PULL_DIR | POWER_SHDN | AON_MUX)

typedef struct
{
    uint16_t reg[TOTAL_PIN_NUM];
} PADAddrTable_TypeDef;

typedef struct
{
    uint8_t reg[TOTAL_PIN_NUM];
} PINMUXIndexTable_TypeDef;

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_PINMUX_DEF_H */
