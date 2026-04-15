/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GPIO_DEF_H
#define RTL_GPIO_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

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
#define GPIO_SUPPORT_SET_CONTROL_MODE                  (0) //!< The function is not supported.
#define GPIO_SUPPORT_SWAP_DEB_PINBIT                   (1) //!< The function must be enabled when using GPIO debounce.
#define GPIO_SUPPORT_LS_SYNC                           (1) //!< The function must be enabled when level-triggered interrupts occur.
#define GPIO_SUPPORT_INT_BOTHEDGE                      (0) //!< The function is not supported.

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
 *                         GPIO Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t GPIO_DR;              /*!< 0x00 */
    __IO uint32_t GPIO_DDR;             /*!< 0x04 */
    __IO uint32_t RSVD[10];
    __IO uint32_t GPIO_INT_EN;          /*!< 0x30 */
    __IO uint32_t GPIO_INT_MASK;        /*!< 0x34 */
    __IO uint32_t GPIO_INT_LV;          /*!< 0x38 */
    __IO uint32_t RSVD1;
    __I  uint32_t GPIO_INT_STS;         /*!< 0x40 */
    __I  uint32_t GPIO_INT_RAW_STS;     /*!< 0x44 */
    __IO uint32_t RSVD2;
    __O  uint32_t GPIO_INT_CLR;         /*!< 0x4C */
    __IO uint32_t RSVD3[4];
    __IO uint32_t GPIO_LS_SYNC;         /*!< 0x60 */
    __IO uint32_t RSVD4[39];
    __IO uint32_t GPIO_OUT_MODE;        /*!< 0x100 */
    __I  uint32_t GPIO_PAD_STATE;       /*!< 0x104 */
    __IO uint32_t GPIO_EXT_DEB_POL_CTL; /*!< 0x108 */
} GPIO_TypeDef;

typedef struct
{
    __IO uint32_t GPIO_DEB_CLK_CTL[4];  /*!< 0x00 ~ 0x0C */
    __IO uint32_t GPIO_DEB_FUN_CTL;     /*!< 0x10 */
} GPIO_Debounce_TypeDef;

/*============================================================================*
 *                         GPIO Declaration
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
 * \defgroup GPIO_Declaration GPIO Declaration
 * \{
 * \ingroup  GPIO_Exported_Constants
 */

#define GPIO               ((GPIO_TypeDef          *) GPIOA_REG_BASE)     //!< GPIO base address.
#define GPIOA              ((GPIO_TypeDef          *) GPIOA_REG_BASE)     //!< GPIOA base address.
#define GPIOB              ((GPIO_TypeDef          *) GPIOB_REG_BASE)     //!< GPIOB base address.
#define GPIOA_DEB          ((GPIO_Debounce_TypeDef *) GPIOA_DEB_REG_BASE) //!< GPIOA_DEB base address.
#define GPIOB_DEB          ((GPIO_Debounce_TypeDef *) GPIOB_DEB_REG_BASE) //!< GPIOB_DEB base address.

/** End of GPIO_Declaration
  * \}
  */

/** End of GPIO_Exported_Constants
  * \}
  */

/** End of GPIO
  * \}
  */

/*============================================================================*
 *                         GPIO Private Types
 *============================================================================*/
typedef struct
{
    uint32_t gpio_reg[15];
} GPIOStoreReg_Typedef;

/*============================================================================*
 *                         GPIO Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    gpio_swporta_dr         32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_swporta_dr: 32;
    } b;
} GPIO_DR_TypeDef;



/* 0x04
   31:0    R/W    gpio_swporta_ddr        32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_swporta_ddr: 32;
    } b;
} GPIO_DDR_TypeDef;


/* 0x30
   31:0    R/W    gpio_inten              32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_inten: 32;
    } b;
} GPIO_INT_EN_TypeDef;



/* 0x34
   31:0    R/W    gpio_intmask            32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_intmask: 32;
    } b;
} GPIO_INT_MASK_TypeDef;



/* 0x38
   31:0    R/W    gpio_inttype_level      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_inttype_level: 32;
    } b;
} GPIO_INT_LV_TypeDef;



/* 0x40
   31:0    R      gpio_intstatus          32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t gpio_intstatus: 32;
    } b;
} GPIO_INT_STS_TypeDef;


/* 0x44
   31:0    R      gpio_raw_intstatus      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t gpio_raw_intstatus: 32;
    } b;
} GPIO_INT_RAW_STS_TypeDef;


/* 0x4C
   31:0    W      gpio_porta_eoi          32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_porta_eoi: 32;
    } b;
} GPIO_INT_CLR_TypeDef;



/* 0x60
   0       R/W    gpio_ls_sync            1'h0
   31:1    R/W    reserved                31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_ls_sync: 1;
        uint32_t reserved: 31;
    } b;
} GPIO_LS_SYNC_TypeDef;



/* 0x100
   31:0    R/W    gpio_output_mode        32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_output_mode: 32;
    } b;
} GPIO_OUT_MODE_TypeDef;


/* 0x104
   31:0    R      gpio_pad_state          32'h0
   31:0    R/W    gpio_external_porta     32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t gpio_pad_state: 32;
    } b;
} GPIO_PAD_STATE_TypeDef;


/* 0x108
   31:0    R/W    gpio_polarity           32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t gpio_polarity: 32;
    } b;
} GPIO_EXT_DEB_POL_CTL_TypeDef;

/* 0x00 ~ 0x0C
   7:0     R/W    GPIO_G_L_CNT_LIMIT      8'h1
   8       R/W    GPIO_G_L_DEB_CLK_SEL    1'h0
   11:9    R/W    GPIO_G_L_DEB_CLK_DIV    3'h0
   12      R/W    GPIO_G_L_DEB_CNT_EN     1'b0
   15:13   R/W    DUMMY                  3'h0
   23:16   R/W    GPIO_G_H_CNT_LIMIT      8'h1
   24      R/W    GPIO_G_H_DEB_CLK_SEL    1'h0
   27:25   R/W    GPIO_G_H_DEB_CLK_DIV    3'h0
   28      R/W    GPIO_G_H_DEB_CNT_EN     1'b0
   31:29   R/W    DUMMY                  2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t GPIO_G_L_CNT_LIMIT: 8;
        uint32_t GPIO_G_L_DEB_CLK_SEL: 1;
        uint32_t GPIO_G_L_DEB_CLK_DIV: 3;
        uint32_t GPIO_G_L_DEB_CNT_EN: 1;
        uint32_t reserved_1: 3;
        uint32_t GPIO_G_H_CNT_LIMIT: 8;
        uint32_t GPIO_G_H_DEB_CLK_SEL: 1;
        uint32_t GPIO_G_H_DEB_CLK_DIV: 3;
        uint32_t GPIO_G_H_DEB_CNT_EN: 1;
        uint32_t reserved_0: 3;
    } b;
} GPIO_DEB_CLK_CTL_TypeDef;



/* 0x10
   31:0    R/W    GPIO_x_DEB_FUNC_EN     32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t GPIO_x_DEB_FUNC_EN: 32;
    } b;
} GPIO_DEB_FUN_CTL_TypeDef;


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
 * \defgroup    GPIO_Debounce_Clock_Source GPIO Debounce Clock Source
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DEBOUNCE_32K = 0x0, //!< GPIO debounce clock source is 32KHz.
    GPIO_DEBOUNCE_S11 = 0x1, //!< GPIO debounce clock source is S11_clk.
} GPIODebounceSrc_TypeDef;

#define IS_GPIO_DEBOUNCE_SRC_TYPE(TYPE) (((TYPE) == GPIO_DEBOUNCE_32K) || \
                                         ((TYPE) == GPIO_DEBOUNCE_S11)) //!< Check if the input parameter is valid.

/** End of GPIO_Debounce_Clock_Source
  * \}
  */

/**
 * \defgroup    GPIO_Debounce_Divider GPIO Debounce Divider
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DEBOUNCE_DIVIDER_1  = 0x0, //!< The debounce divider is 1.
    GPIO_DEBOUNCE_DIVIDER_2  = 0x1, //!< The debounce divider is 2.
    GPIO_DEBOUNCE_DIVIDER_4  = 0x2, //!< The debounce divider is 4.
    GPIO_DEBOUNCE_DIVIDER_8  = 0x3, //!< The debounce divider is 8.
    GPIO_DEBOUNCE_DIVIDER_16 = 0x4, //!< The debounce divider is 16.
    GPIO_DEBOUNCE_DIVIDER_32 = 0x5, //!< The debounce divider is 32.
    GPIO_DEBOUNCE_DIVIDER_40 = 0x6, //!< The debounce divider is 40.
    GPIO_DEBOUNCE_DIVIDER_64 = 0x7, //!< The debounce divider is 64.
} GPIODebounceDiv_TypeDef;

#define IS_GPIO_DEBOUNCE_DIV_TYPE(TYPE) (((TYPE) == GPIO_DEBOUNCE_DIVIDER_1) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_2) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_4) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_8) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_16) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_32) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_40) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_64)) //!< Check if the input parameter is valid.

/** End of GPIO_Debounce_Divider
  * \}
  */

/**
 * \defgroup GPIO_Constant_Wrapper GPIO Constant Wrapper
 * \{
 * \ingroup  GPIO_Exported_Constants
 */
#define GPIO_Mode               GPIO_Dir               //!< The macro is a wrapper for GPIO_Dir.
#define GPIO_Mode_IN            GPIO_DIR_IN            //!< The macro is a wrapper for GPIO_DIR_IN.
#define GPIO_Mode_OUT           GPIO_DIR_OUT           //!< The macro is a wrapper for GPIO_DIR_OUT.
#define GPIO_MODE_IN            GPIO_DIR_IN            //!< The macro is a wrapper for GPIO_DIR_IN.
#define GPIO_MODE_OUT           GPIO_DIR_OUT           //!< The macro is a wrapper for GPIO_DIR_OUT.
#define GPIO_INT_Trigger_LEVEL  GPIO_INT_TRIGGER_LEVEL //!< The macro is a wrapper for GPIO_INT_TRIGGER_LEVEL.
#define GPIO_INT_Trigger_EDGE   GPIO_INT_TRIGGER_EDGE  //!< The macro is a wrapper for GPIO_INT_TRIGGER_EDGE.

/** End of GPIO_Constant_Wrapper
  * \}
  */

/**
 * \defgroup GPIO_API_Wrapper GPIO API Wrapper
 * \{
 * \ingroup  GPIO_Exported_Constants
 */
#define GPIO_GetPin             GPIO_GetPinBit         //!< The macro is a wrapper for GPIO_GetPinBit.
#define GPIO_DBClkCmd           GPIO_ExtDebCmd         //!< The macro is a wrapper for GPIO_ExtDebCmd.
#define GPIO_SetDebounceTime    GPIO_ExtDebUpdate      //!< The macro is a wrapper for GPIO_ExtDebUpdate.
#define GPIO_SetITPolarity      GPIO_SetPolarity       //!< The macro is a wrapper for GPIO_SetPolarity.

/** End of GPIO_API_Wrapper
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
