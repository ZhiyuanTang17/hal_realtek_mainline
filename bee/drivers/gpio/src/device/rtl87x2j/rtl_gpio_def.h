/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GPIO_DEF_H
#define RTL_GPIO_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "vector_table.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          GPIO Defines
 *============================================================================*/
/** \defgroup GPIO        GPIO
  * \brief
  * \{
  */

/** \defgroup GPIO_Exported_Constants GPIO Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup GPIO_Defines GPIO Defines
 * \{
 * \ingroup  GPIO_Exported_Constants
 */
#define GPIO_SUPPORT_SET_CONTROL_MODE                  (0)
#define GPIO_SUPPORT_LS_SYNC                           (0)
#define GPIO_SUPPORT_BOTHEDGE                          (1)
#define GPIO_SUPPORT_RAP_FUNCTION                      (1)
#define GPIO_SUPPORT_AUTO_CLOCK                        (1)
#define GPIO_SUPPORT_OUTPUT_MODE_SELECT                (1)

/** End of GPIO_Defines
  * \}
  */

/** End of GPIO_Exported_Constants
  * \}
  */

/** End of GPIO
  * \}
  */

/*============================================================================*
 *                          GPIO Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t GPIO_DR;                          /*!< 0x00 */
    __IO uint32_t GPIO_DDR;                         /*!< 0x04 */
    __IO uint32_t GPIO_SRC;                         /*!< 0x08 */
    __IO uint32_t RSVD[9];
    __IO uint32_t GPIO_INT_EN;                      /*!< 0x30 */
    __IO uint32_t GPIO_INT_MASK;                    /*!< 0x34 */
    __IO uint32_t GPIO_INT_LV;                      /*!< 0x38 */
    __IO uint32_t RSVD1;
    __I  uint32_t GPIO_INT_STS;                     /*!< 0x40 */
    __I  uint32_t GPIO_INT_RAW_STS;                 /*!< 0x44 */
    __IO uint32_t RSVD2;
    __O  uint32_t GPIO_INT_CLR;                     /*!< 0x4C */
    __IO uint32_t RSVD3[6];
    __IO uint32_t GPIO_INT_BOTHEDGE;                /*!< 0x68 */
    __IO uint32_t RSVD4[37];
    __IO uint32_t GPIO_OUT_MODE;                    /*!< 0x100 */
    __I  uint32_t GPIO_PAD_STATE;                   /*!< 0x104 */
    __IO uint32_t GPIO_EXT_DEB_CLK_CTL[4];          /*!< 0x108 - 0x114*/
    __IO uint32_t RSVD5[12];                        /*!< 0x118 - 0x144*/
    __IO uint32_t GPIO_EXT_DEB_FUNC_CTL;            /*!< 0x148 */
    __IO uint32_t GPIO_EXT_DEB_POL_CTL;             /*!< 0x14C */
    __I  uint32_t GPIO_VERSION;                     /*!< 0x150 */
    __IO uint32_t GPIO_RAP_CTL;                     /*!< 0x154 */
    __O  uint32_t GPIO_RAP_TASK_DRSET;              /*!< 0x158 */
    __O  uint32_t GPIO_RAP_TASK_DRCLR;              /*!< 0x15C */
    __O  uint32_t GPIO_RAP_TASK_DRTOGGLE;           /*!< 0x160 */
    __O  uint32_t RSVD6[5];                         /*!< 0x164 - 0x174*/
    __IO uint32_t GPIO_QACTIVE_MANUAL_CTRL;         /*!< 0x178 */
} GPIO_TypeDef;

/*============================================================================*
 *                          GPIO Declaration
 *============================================================================*/
/** \defgroup GPIO        GPIO
  * \brief
  * \{
  */

/** \defgroup GPIO_Exported_Constants GPIO Exported Constants
  * \brief
  * \{
  */

/** \defgroup GPIO_Declaration GPIO Declaration
  * \brief
  * \{
  */
#define GPIOA_REG_BASE     (GPIO0_BASE)
#define GPIOB_REG_BASE     (GPIO0_BASE + 0x800)

#define GPIO               ((GPIO_TypeDef *) GPIOA_REG_BASE)
#define GPIOA              ((GPIO_TypeDef *) GPIOA_REG_BASE)
#define GPIOB              ((GPIO_TypeDef *) GPIOB_REG_BASE)

/** End of GPIO_Declaration
  * \}
  */

/** \defgroup GPIO_IRQn GPIO IRQn
  * \brief
  * \{
  */
#ifdef GPIOA
#define GPIOA0_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 0)
#define GPIOA1_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 1)
#define GPIOA2_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 2)
#define GPIOA3_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 3)
#define GPIOA4_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 4)
#define GPIOA5_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 5)
#define GPIOA6_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 6)
#define GPIOA7_IRQn         SUB_IRQ_DEF(GPIOA0_7_IRQn, 7)
#define GPIOA8_IRQn         SUB_IRQ_DEF(GPIOA8_15_IRQn, 8)
#define GPIOA9_IRQn         SUB_IRQ_DEF(GPIOA8_15_IRQn, 9)
#define GPIOA10_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 10)
#define GPIOA11_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 11)
#define GPIOA12_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 12)
#define GPIOA13_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 13)
#define GPIOA14_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 14)
#define GPIOA15_IRQn        SUB_IRQ_DEF(GPIOA8_15_IRQn, 15)
#define GPIOA16_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 16)
#define GPIOA17_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 17)
#define GPIOA18_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 18)
#define GPIOA19_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 19)
#define GPIOA20_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 20)
#define GPIOA21_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 21)
#define GPIOA22_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 22)
#define GPIOA23_IRQn        SUB_IRQ_DEF(GPIOA16_23_IRQn, 23)
#define GPIOA24_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 24)
#define GPIOA25_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 25)
#define GPIOA26_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 26)
#define GPIOA27_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 27)
#define GPIOA28_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 28)
#define GPIOA29_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 29)
#define GPIOA30_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 30)
#define GPIOA31_IRQn        SUB_IRQ_DEF(GPIOA24_31_IRQn, 31)
#endif
#ifdef GPIOB
#define GPIOB0_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 32)
#define GPIOB1_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 33)
#define GPIOB2_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 34)
#define GPIOB3_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 35)
#define GPIOB4_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 36)
#define GPIOB5_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 37)
#define GPIOB6_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 38)
#define GPIOB7_IRQn         SUB_IRQ_DEF(GPIOA32_39_IRQn, 39)
#define GPIOB8_IRQn         SUB_IRQ_DEF(GPIOA40_47_IRQn, 40)
#define GPIOB9_IRQn         SUB_IRQ_DEF(GPIOA40_47_IRQn, 41)
#define GPIOB10_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 42)
#define GPIOB11_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 43)
#define GPIOB12_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 44)
#define GPIOB13_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 45)
#define GPIOB14_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 46)
#define GPIOB15_IRQn        SUB_IRQ_DEF(GPIOA40_47_IRQn, 47)
#define GPIOB16_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 48)
#define GPIOB17_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 49)
#define GPIOB18_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 50)
#define GPIOB19_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 51)
#define GPIOB20_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 52)
#define GPIOB21_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 53)
#define GPIOB22_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 54)
#define GPIOB23_IRQn        SUB_IRQ_DEF(GPIOA48_55_IRQn, 55)
#endif

/** End of GPIO_IRQn
  * \}
  */

/** End of GPIO_Exported_Constants
  * \}
  */

/** End of GPIO
  * \}
  */

/*============================================================================*
 *                          GPIO Private Types
 *============================================================================*/
typedef struct
{
    uint32_t gpio_reg[15];
} GPIOStoreReg_Typedef;

/*============================================================================*
 *                          GPIO Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    gpio_swporta_dr             32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_swporta_dr: 32;
    } b;
} GPIO_DR_TypeDef;


/* 0x04
   31:0    R/W    gpio_swporta_ddr            32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_swporta_ddr: 32;
    } b;
} GPIO_DDR_TypeDef;


/* 0x08
   31:0    R/W    gpio_swporta_ctl            32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_swporta_ctl: 32;
    } b;
} GPIO_SRC_TypeDef;


/* 0x30
   31:0    R/W    gpio_inten                  32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_inten: 32;
    } b;
} GPIO_INT_EN_TypeDef;


/* 0x34
   31:0    R/W    gpio_intmask                32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_intmask: 32;
    } b;
} GPIO_INT_MASK_TypeDef;


/* 0x38
   31:0    R/W    gpio_inttype_level          32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_inttype_level: 32;
    } b;
} GPIO_INT_LV_TypeDef;


/* 0x40
   31:0    R      gpio_intstatus              32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t gpio_intstatus: 32;
    } b;
} GPIO_INT_STS_TypeDef;


/* 0x44
   31:0    R      gpio_raw_intstatus          32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t gpio_raw_intstatus: 32;
    } b;
} GPIO_INT_RAW_STS_TypeDef;


/* 0x4C
   31:0    W      gpio_porta_eoi              32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_porta_eoi: 32;
    } b;
} GPIO_INT_CLR_TypeDef;


/* 0x68
   31:0    R/W    gpio_int_bothedge           32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_int_bothedge: 32;
    } b;
} GPIO_INT_BOTHEDGE_TypeDef;


/* 0x100
   31:0    R/W    gpio_output_mode            32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_output_mode: 32;
    } b;
} GPIO_OUT_MODE_TypeDef;


/* 0x104
   31:0    R      gpio_pad_state              32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t gpio_pad_state: 32;
    } b;
} GPIO_PAD_STATE_TypeDef;


/* 0x108 - 0x114
   7:0     R/W    gpio_l_cnt_limit   8'h1
   8       R      reserved8          1'h0
   11:9    R/W    gpio_l_deb_clk_div 3'h0
   15:12   R      reserved15_12      4'h0
   23:16   R/W    gpio_h_cnt_limit   8'h1
   24      R      reserved24         1'h0
   27:25   R/W    gpio_h_deb_clk_div 3'h0
   31:28   R      reserved31_28      4'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_l_cnt_limit: 8;
        const uint32_t reserved_3: 1;
        uint32_t gpio_l_deb_clk_div: 3;
        const uint32_t reserved_2: 4;
        uint32_t gpio_h_cnt_limit: 8;
        const uint32_t reserved_1: 1;
        uint32_t gpio_h_deb_clk_div: 3;
        const uint32_t reserved_0: 4;
    } b;
} GPIO_EXT_DEB_CLK_CTL_TypeDef;


/* 0x148
   31:0    R/W    gpio_x_deb_func_en          32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_x_deb_func_en: 32;
    } b;
} GPIO_EXT_DEB_FUNC_CTL_TypeDef;


/* 0x14C
   31:0    R/W    gpio_polarity               32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_polarity: 32;
    } b;
} GPIO_EXT_DEB_POL_CTL_TypeDef;


/* 0x150
   31:0    R      gpio_version                32'h2402210A
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t gpio_version: 32;
    } b;
} GPIO_VERSION_TypeDef;


/* 0x154
   31:0    R/W    gpio_rap_mode               32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_rap_mode: 32;
    } b;
} GPIO_RAP_CTL_TypeDef;


/* 0x158
   31:0    WAC    gpio_task_drset             32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_task_drset: 32;
    } b;
} GPIO_RAP_TASK_DRSET_TypeDef;


/* 0x15C
   31:0    WAC    gpio_task_drclr             32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_task_drclr: 32;
    } b;
} GPIO_RAP_TASK_DRCLR_TypeDef;


/* 0x160
   31:0    WAC    gpio_task_drtoggle          32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_task_drtoggle: 32;
    } b;
} GPIO_RAP_TASK_DRTOGGLE_TypeDef;


/* 0x178
   0       R/W    pclk_qactive_man_data       1'h0
   1       R/W    pclk_qactive_man_enable     1'h0
   2       R/W    gclkintr_qactive_man_data   1'h0
   3       R/W    gclkintr_qactive_man_enable 1'h0
   4       R/W    clk32k_qactive_man_data     1'h0
   5       R/W    clk32k_qactive_man_enable   1'h0
   6       R/W    gclk_qactive_man_data       1'h0
   7       R/W    gclk_qactive_man_enable     1'h0
   31:8    R      reserved178_31_8            24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t pclk_qactive_man_data: 1;
        uint32_t pclk_qactive_man_enable: 1;
        uint32_t gclkintr_qactive_man_data: 1;
        uint32_t gclkintr_qactive_man_enable: 1;
        uint32_t clk32k_qactive_man_data: 1;
        uint32_t clk32k_qactive_man_enable: 1;
        uint32_t gclk_qactive_man_data: 1;
        uint32_t gclk_qactive_man_enable: 1;
        const uint32_t reserved_0: 24;
    } b;
} GPIO_QACTIVE_MANUAL_CTRL_TypeDef;



/*============================================================================*
 *                          GPIO Constants
 *============================================================================*/
/** \defgroup GPIO        GPIO
  * \brief
  * \{
  */

/** \defgroup GPIO_Exported_Constants GPIO Exported Constants
  * \brief
  * \{
  */


/**
 * \defgroup    GPIO_Debounce_Source GPIO Debounce Dource
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DEB_CLOCK_SRC_32K = 0x0, /**< debounce clock source 32KHz. */
} GPIODebClockSrc_TypeDef;

#define IS_GPIO_DEBOUNCE_CLOCK_SRC(SRC) (((SRC) == GPIO_DEB_CLOCK_SRC_32K))

/** End of GPIO_Debounce_Source
  * \}
  */

/**
 * \defgroup    GPIO_Debounce_Divide GPIO Debounce Divide
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DEB_CLOCK_DIV_1   = 0x0, /**< debounce clock divider 1. */
    GPIO_DEB_CLOCK_DIV_2   = 0x1, /**< debounce clock divider 2. */
    GPIO_DEB_CLOCK_DIV_4   = 0x2, /**< debounce clock divider 4. */
    GPIO_DEB_CLOCK_DIV_8   = 0x3, /**< debounce clock divider 8. */
    GPIO_DEB_CLOCK_DIV_16  = 0x4, /**< debounce clock divider 16. */
    GPIO_DEB_CLOCK_DIV_32  = 0x5, /**< debounce clock divider 32. */
    GPIO_DEB_CLOCK_DIV_64  = 0x6, /**< debounce clock divider 64. */
} GPIODebClockDiv_TypeDef;

#define IS_GPIO_DEBOUNCE_CLOCK_DIV(DIV) (((DIV) == GPIO_DEB_CLOCK_DIV_1) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_2) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_4) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_8) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_16) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_32) || \
                                         ((DIV) == GPIO_DEB_CLOCK_DIV_64))

/** End of GPIO_Debounce_Divide
  * \}
  */

/**
 * \defgroup GPIO_Constant_Private GPIO Constant Private
 * \{
 * \ingroup  GPIO_Exported_Constants
 */

#define GPIO_DEFAULT_DEB_CLOCK_SRC      GPIO_DEB_CLOCK_SRC_32K
/**
 * \brief    GPIO API Wrapper
 *
 * \ingroup  GPIO_Exported_Constants
 */
#define GPIO_DBClkCmd           GPIO_ExtDebCmd
#define GPIO_SetDebounceTime    GPIO_ExtDebUpdate
#define GPIO_SetITPolarity      GPIO_SetPolarity

#define GPIOIT_LevelType            GPIOTrigger_TypeDef
#define GPIOIT_PolarityType         GPIOPolarity_TypeDef
#define GPIOIT_DebounceType         GPIODebounce_TypeDef
#define GPIO_PinBit                 GPIO_Pin
#define GPIO_Mode                   GPIO_Dir
#define GPIO_Mode_IN                GPIO_DIR_IN
#define GPIO_Mode_OUT               GPIO_DIR_OUT
#define GPIOMode_TypeDef            GPIODir_TypeDef
#define GPIO_INT_Trigger_LEVEL      GPIO_TRIGGER_LEVEL
#define GPIO_INT_Trigger_EDGE       GPIO_TRIGGER_EDGE

#define GPIOx_DeInit                GPIO_DeInit
#define GPIOx_Init                  GPIO_Init
#define GPIOx_INTConfig             GPIO_INTConfig
#define GPIOx_ClearINTPendingBit    GPIO_ClearINTPendingBit
#define GPIOx_MaskINTConfig         GPIO_MaskINTConfig
#define GPIOx_ReadInputDataBit      GPIO_ReadInputDataBit
#define GPIOx_ReadInputData         GPIO_ReadInputData
#define GPIOx_ReadOutputDataBit     GPIO_ReadOutputDataBit
#define GPIOx_ReadOutputData        GPIO_ReadOutputData
#define GPIOx_SetBits               GPIO_SetBits
#define GPIOx_ResetBits             GPIO_ResetBits
#define GPIOx_WriteBit              GPIO_WriteBit
#define GPIOx_Write                 GPIO_Write
#define GPIOx_GetINTStatus          GPIO_GetINTStatus
#define GPIOx_ModeSet               GPIO_SetDirection
#define GPIOx_ChangePolarity        GPIO_SetPolarity
#define GPIOx_IntPolaritySet        GPIO_SetPolarity
#define GPIO_GetPin                 GPIO_GetPinBit
#define GPIO_ModeSet                GPIO_SetDirection
/** End of GPIO_Constant_Private
  * \}
  */

/** End of GPIO_Exported_Constants
  * \}
  */

/** End of GPIO
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_GPIO_DEF_H */
