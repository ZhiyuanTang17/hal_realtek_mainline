/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_GPIO_H
#define RTL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "gpio/src/device/rtl87x2g/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "gpio/src/device/rtl87x3e/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3e/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "gpio/src/device/rtl87x3d/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "gpio/src/device/rtl87x2j/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "gpio/src/device/rtl87x3j/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#endif

/** \defgroup GPIO        GPIO
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup GPIO_Exported_Constants GPIO Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    GPIO_Number GPIO Number
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
#ifdef GPIOA
#define GPIOA0   0
#define GPIOA1   1
#define GPIOA2   2
#define GPIOA3   3
#define GPIOA4   4
#define GPIOA5   5
#define GPIOA6   6
#define GPIOA7   7
#define GPIOA8   8
#define GPIOA9   9
#define GPIOA10  10
#define GPIOA11  11
#define GPIOA12  12
#define GPIOA13  13
#define GPIOA14  14
#define GPIOA15  15
#define GPIOA16  16
#define GPIOA17  17
#define GPIOA18  18
#define GPIOA19  19
#define GPIOA20  20
#define GPIOA21  21
#define GPIOA22  22
#define GPIOA23  23
#define GPIOA24  24
#define GPIOA25  25
#define GPIOA26  26
#define GPIOA27  27
#define GPIOA28  28
#define GPIOA29  29
#define GPIOA30  30
#define GPIOA31  31
#endif
#ifdef GPIOB
#define GPIOB0   32
#define GPIOB1   33
#define GPIOB2   34
#define GPIOB3   35
#define GPIOB4   36
#define GPIOB5   37
#define GPIOB6   38
#define GPIOB7   39
#define GPIOB8   40
#define GPIOB9   41
#define GPIOB10  42
#define GPIOB11  43
#define GPIOB12  44
#define GPIOB13  45
#define GPIOB14  46
#define GPIOB15  47
#define GPIOB16  48
#define GPIOB17  49
#define GPIOB18  50
#define GPIOB19  51
#define GPIOB20  52
#define GPIOB21  53
#define GPIOB22  54
#define GPIOB23  55
#define GPIOB24  56
#define GPIOB25  57
#define GPIOB26  58
#define GPIOB27  59
#define GPIOB28  60
#define GPIOB29  61
#define GPIOB30  62
#define GPIOB31  63
#endif
#ifdef GPIOC
#define GPIOC0   64
#define GPIOC1   65
#define GPIOC2   66
#define GPIOC3   67
#define GPIOC4   68
#define GPIOC5   69
#define GPIOC6   70
#define GPIOC7   71
#define GPIOC8   72
#define GPIOC9   73
#define GPIOC10  74
#define GPIOC11  75
#define GPIOC12  76
#define GPIOC13  77
#define GPIOC14  78
#define GPIOC15  79
#define GPIOC16  80
#define GPIOC17  81
#define GPIOC18  82
#define GPIOC19  83
#define GPIOC20  84
#define GPIOC21  85
#define GPIOC22  86
#define GPIOC23  87
#define GPIOC24  88
#define GPIOC25  89
#define GPIOC26  90
#define GPIOC27  91
#define GPIOC28  92
#define GPIOC29  93
#define GPIOC30  94
#define GPIOC31  95
#endif
#ifdef GPIOD
#define GPIOD0   96
#define GPIOD1   97
#define GPIOD2   98
#define GPIOD3   99
#define GPIOD4   100
#define GPIOD5   101
#define GPIOD6   102
#define GPIOD7   103
#define GPIOD8   104
#define GPIOD9   105
#define GPIOD10  106
#define GPIOD11  107
#define GPIOD12  108
#define GPIOD13  109
#define GPIOD14  110
#define GPIOD15  111
#define GPIOD16  112
#define GPIOD17  113
#define GPIOD18  114
#define GPIOD19  115
#define GPIOD20  116
#define GPIOD21  117
#define GPIOD22  118
#define GPIOD23  119
#define GPIOD24  120
#define GPIOD25  121
#define GPIOD26  122
#define GPIOD27  123
#define GPIOD28  124
#define GPIOD29  125
#define GPIOD30  126
#define GPIOD31  127
#endif

/** End of GPIO_Number
  * \}
  */

/**
 * \defgroup    GPIO_Pins_Define GPIO Pins Define
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
#define GPIO_Pin_0                 (BIT0)   /*!< Pin 0 selected   */
#define GPIO_Pin_1                 (BIT1)   /*!< Pin 1 selected   */
#define GPIO_Pin_2                 (BIT2)   /*!< Pin 2 selected   */
#define GPIO_Pin_3                 (BIT3)   /*!< Pin 3 selected   */
#define GPIO_Pin_4                 (BIT4)   /*!< Pin 4 selected   */
#define GPIO_Pin_5                 (BIT5)   /*!< Pin 5 selected   */
#define GPIO_Pin_6                 (BIT6)   /*!< Pin 6 selected   */
#define GPIO_Pin_7                 (BIT7)   /*!< Pin 7 selected   */
#define GPIO_Pin_8                 (BIT8)   /*!< Pin 8 selected   */
#define GPIO_Pin_9                 (BIT9)   /*!< Pin 9 selected   */
#define GPIO_Pin_10                (BIT10)  /*!< Pin 10 selected  */
#define GPIO_Pin_11                (BIT11)  /*!< Pin 11 selected  */
#define GPIO_Pin_12                (BIT12)  /*!< Pin 12 selected  */
#define GPIO_Pin_13                (BIT13)  /*!< Pin 13 selected  */
#define GPIO_Pin_14                (BIT14)  /*!< Pin 14 selected  */
#define GPIO_Pin_15                (BIT15)  /*!< Pin 15 selected  */
#define GPIO_Pin_16                (BIT16)  /*!< Pin 16 selected  */
#define GPIO_Pin_17                (BIT17)  /*!< Pin 17 selected  */
#define GPIO_Pin_18                (BIT18)  /*!< Pin 18 selected  */
#define GPIO_Pin_19                (BIT19)  /*!< Pin 19 selected  */
#define GPIO_Pin_20                (BIT20)  /*!< Pin 20 selected  */
#define GPIO_Pin_21                (BIT21)  /*!< Pin 21 selected  */
#define GPIO_Pin_22                (BIT22)  /*!< Pin 22 selected  */
#define GPIO_Pin_23                (BIT23)  /*!< Pin 23 selected  */
#define GPIO_Pin_24                (BIT24)  /*!< Pin 24 selected  */
#define GPIO_Pin_25                (BIT25)  /*!< Pin 25 selected  */
#define GPIO_Pin_26                (BIT26)  /*!< Pin 26 selected  */
#define GPIO_Pin_27                (BIT27)  /*!< Pin 27 selected  */
#define GPIO_Pin_28                (BIT28)  /*!< Pin 28 selected  */
#define GPIO_Pin_29                (BIT29)  /*!< Pin 29 selected  */
#define GPIO_Pin_30                (BIT30)  /*!< Pin 30 selected  */
#define GPIO_Pin_31                (BIT31)  /*!< Pin 31 selected  */
#define GPIO_Pin_All               ((uint32_t)0xFFFFFFFF)  /*!< All pins selected */

#define IS_GET_GPIO_PIN(PIN)       (((PIN) == GPIO_Pin_0) || \
                                    ((PIN) == GPIO_Pin_1) || \
                                    ((PIN) == GPIO_Pin_2) || \
                                    ((PIN) == GPIO_Pin_3) || \
                                    ((PIN) == GPIO_Pin_4) || \
                                    ((PIN) == GPIO_Pin_5) || \
                                    ((PIN) == GPIO_Pin_6) || \
                                    ((PIN) == GPIO_Pin_7) || \
                                    ((PIN) == GPIO_Pin_8) || \
                                    ((PIN) == GPIO_Pin_9) || \
                                    ((PIN) == GPIO_Pin_10) || \
                                    ((PIN) == GPIO_Pin_11) || \
                                    ((PIN) == GPIO_Pin_12) || \
                                    ((PIN) == GPIO_Pin_13) || \
                                    ((PIN) == GPIO_Pin_14) || \
                                    ((PIN) == GPIO_Pin_15) || \
                                    ((PIN) == GPIO_Pin_16) || \
                                    ((PIN) == GPIO_Pin_17) || \
                                    ((PIN) == GPIO_Pin_18) || \
                                    ((PIN) == GPIO_Pin_19) || \
                                    ((PIN) == GPIO_Pin_20) || \
                                    ((PIN) == GPIO_Pin_21) || \
                                    ((PIN) == GPIO_Pin_22) || \
                                    ((PIN) == GPIO_Pin_23) || \
                                    ((PIN) == GPIO_Pin_24) || \
                                    ((PIN) == GPIO_Pin_25) || \
                                    ((PIN) == GPIO_Pin_26) || \
                                    ((PIN) == GPIO_Pin_27) || \
                                    ((PIN) == GPIO_Pin_28) || \
                                    ((PIN) == GPIO_Pin_29) || \
                                    ((PIN) == GPIO_Pin_30) || \
                                    ((PIN) == GPIO_Pin_31) || \
                                    ((PIN) == GPIO_Pin_All))

#define IS_GPIO_PIN(PIN)          ((PIN) != (uint32_t)0x00)

/** End of GPIO_Pins_Define
  * \}
  */

/**
 * \defgroup    GPIO_Bit_Action GPIO Bit Action
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    Bit_RESET = 0,
    Bit_SET
} BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

/** End of GPIO_Bit_Action
  * \}
  */

/**
 * \defgroup    GPIO_direction GPIO direction
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DIR_IN   = 0x0, /**< GPIO Input direction */
    GPIO_DIR_OUT  = 0x1, /**< GPIO Output direction */
} GPIODir_TypeDef;

#define IS_GPIO_DIR(DIR) (((DIR) == GPIO_DIR_IN) || ((DIR) == GPIO_DIR_OUT))

/** End of GPIO_direction
  * \}
  */

/**
 * \defgroup    GPIO_output_mode GPIO output mode
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_OUTPUT_PUSHPULL  = 0x0, /**< GPIO Output push-pull Mode */
    GPIO_OUTPUT_OPENDRAIN = 0x1, /**< GPIO Output opendrain Mode */
} GPIOOutputMode_TypeDef;

#define IS_GPIO_OUTPUT_MODE(MODE) (((MODE) == GPIO_OUTPUT_PUSHPULL)|| ((MODE) == GPIO_OUTPUT_OPENDRAIN))

/** End of GPIO_output_mode
  * \}
  */

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
/**
 * \brief       GPIO control mode enumeration.
 *
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_SOFTWARE_MODE = 0x0, /**< Gpio Software mode(default) */
    GPIO_HARDWARE_MODE  = 0x1, /**< Gpio Hardware control mode  */
} GPIOControlMode_Typedef;

#define IS_GPIO_CONTROL_MODDE(MODE) (((MODE) == GPIO_SOFTWARE_MODE) || \
                                     ((MODE) == GPIO_HARDWARE_MODE))
#endif

/**
 * \defgroup    GPIO_interrupt_trigger GPIO interrupt trigger
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_TRIGGER_LEVEL = 0x0,     /**< This interrupt is level trigger. */
    GPIO_TRIGGER_EDGE  = 0x1,     /**< This interrupt is edge trigger. */
#if GPIO_SUPPORT_BOTHEDGE
    GPIO_TRIGGER_BOTH_EDGE = 0x2, /**< This interrupt is both edge trigger. */
#endif
} GPIOTrigger_TypeDef;

#define IS_GPIO_TRIGGER_TYPE(TYPE) (((TYPE) == GPIO_TRIGGER_LEVEL) || \
                                    ((TYPE) == GPIO_TRIGGER_EDGE))

/** End of GPIO_interrupt_trigger
  * \}
  */

/**
 * \defgroup    GPIO_interrupt_polarity GPIO interrupt polarity
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_POLARITY_ACTIVE_LOW  = 0x0, /**< Setting interrupt to low active. */
    GPIO_POLARITY_ACTIVE_HIGH = 0x1, /**< Setting interrupt to high active. */
} GPIOPolarity_TypeDef;

#define IS_GPIO_POLARITY_TYPE(TYPE) (((TYPE) == GPIO_POLARITY_ACTIVE_LOW) || \
                                     ((TYPE) == GPIO_POLARITY_ACTIVE_HIGH))

/** End of GPIO_interrupt_polarity
  * \}
  */

#if (GPIO_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    GPIO_Action GPIO Action
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_ACTION_DRSET = 0,
    GPIO_ACTION_DRCLR = 1,
    GPIO_ACTION_DRTOGGLE = 2,
} GPIOAction_TypeDef;

/** End of GPIO_Action
  * \}
  */

#endif

/** End of GPIO_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup GPIO_Exported_Types GPIO Exported Types
  * \brief
  * \{
  */

/**
 * \brief       GPIO init structure definition.
 *
 * \ingroup     GPIO_Exported_Types
 */
typedef struct
{

    uint32_t                GPIO_Pin;           /**< Specifies the GPIO pins to be configured.
                                                     This parameter can be any value of \ref GPIO_Pins_Define. */

    GPIODir_TypeDef         GPIO_Dir;           /**< Specifies the GPIO direction. */

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    GPIOOutputMode_TypeDef  GPIO_OutPutMode;    /**< Specifies the GPIO output mode. */
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIOControlMode_Typedef GPIO_ControlMode;   /**< Specifies the gpio mode. */
#endif

    FunctionalState         GPIO_INTEventEn;    /**< Enable or disable GPIO interrupt. */

    GPIOTrigger_TypeDef     GPIO_Trigger;       /**< Specifies the GPIO interrupt trigger. */

    GPIOPolarity_TypeDef    GPIO_Polarity;      /**< Specifies the GPIO interrupt polarity. */

    FunctionalState         GPIO_DebounceEn;    /**< Enable or disable debounce for interrupt. */

    GPIODebClockSrc_TypeDef GPIO_DebClockSrc;   /**< Select debounce count clk source. */

    GPIODebClockDiv_TypeDef GPIO_DebClockDiv;   /**< Specifies the debounce divide. */

    uint8_t                 GPIO_DebCountLimit; /**< Specifies the debounce Limit.
                                                        Debounce_time = (CntLimit + 1) * DEB_CLK. */
} GPIO_InitTypeDef;

/** End of GPIO_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup GPIO_Exported_Functions GPIO Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitializes the GPIO peripheral registers to their default reset values.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     GPIO_DeInit(GPIOA);
 * }
 * \endcode
 */
void GPIO_DeInit(GPIO_TypeDef *GPIOx);

/**
 * \brief  Initializes the GPIO peripheral according to the specified
 *         parameters in the GPIO_InitStruct.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_InitStruct: Pointer to a GPIO_InitTypeDef structure that
 *            contains the configuration information for the specified GPIO peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_ClockCmd(GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_INTEventEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_Trigger     = GPIO_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_Polarity    = GPIO_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_DebounceEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_DebClockSrc = GPIO_DEB_CLOCK_SRC_32K;
 *     GPIO_InitStruct.GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
 *     GPIO_InitStruct.GPIO_DebCountLimit = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = GPIOA0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);

 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * \brief    Fills each GPIO_InitStruct member with its default value.
 *
 * \param[in]  GPIO_InitStruct: Pointer to a GPIO_InitTypeDef structure which will be initialized.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_ClockCmd(GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin        = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir        = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_INTEventEn = ENABLE;
 *     GPIO_InitStruct.GPIO_Trigger    = GPIO_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_Polarity   = GPIO_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_DebounceEn = ENABLE;
 *     GPIO_InitStruct.GPIO_DebClockSrc = GPIO_DEB_CLOCK_SRC_32K;
 *     GPIO_InitStruct.GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
 *     GPIO_InitStruct.GPIO_DebCountLimit = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 * }
 * \endcode
 */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * \brief   Enable the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 or 31.
 * \param[in] NewState: Enable or disable interrupt
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_ClockCmd(GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_INTEventEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_Trigger     = GPIO_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_Polarity    = GPIO_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_DebounceEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_DebClockSrc = GPIO_DEB_CLOCK_SRC_32K;
 *     GPIO_InitStruct.GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
 *     GPIO_InitStruct.GPIO_DebCountLimit = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = GPIOA0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);

 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_INTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);


/**
 * \brief   Clear the specified GPIO pin interrupt pending bit.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     driver_gpio_init();
 * }
 *
 * void GPIOA0_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     //Add user code here.
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
}
 * \endcode
 */
void GPIO_ClearINTPendingBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);


/**
 * \brief   Mask the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in] NewState: Mask or unmask interrupt.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     driver_gpio_init();
 * }
 *
 * void GPIOA0_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *
 *     //Add user code here.
 *
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_MaskINTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief   Get GPIO GROUP through the given pad.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * \return  GPIOx: GPIO peripheral. \ref GPIO_Declaration
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *      GPIO_TypeDef gpio_port = GPIO_GetPort(P0_0);
 *      //result: gpio_port is GPIOA
 * }
 *
 * \endcode
 */
GPIO_TypeDef *GPIO_GetPort(uint8_t Pin_num);

/**
 * \brief   Get the GPIO_Pin (GPIO0 ~ GPIO31) through the given PAD num.
 *
 * \param[in]  Pin_num: Pin number to be configured. \ref Pin_Number
 *
 * \return  GPIOx(x is 0~31) value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t gpio_pin = GPIO_GetPinBit(P0_0);
 *     //result: gpio_pin is GPIO_Pin_0
 * }
 * \endcode
 */
uint32_t GPIO_GetPinBit(uint8_t Pin_num);

/**
 * \brief   Get GPIO value ( \ref GPIO_Declaration ) through the given pad.
 *
 * \param[in] Pin_num: Pin number to be configured. \ref Pin_Number
 *
 * \return  GPIO value ( \ref GPIO_Declaration ).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t gpio_num = GPIO_GetNum(P0_0);
 *     //result: gpio_num = 0, i.e. GPIOA0.
 * }
 * \endcode
 */
uint8_t GPIO_GetNum(uint8_t Pin_num);

/**
 * \brief   Enable GPIO debounce clock.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in] NewState: Disable or enable debounce clock.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebCmd(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_ExtDebCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief  Set GPIO debounce parameters.
 *
 * \param[in]  GPIOx: where x can be A to D to select the GPIO peripheral.
 * \param[in]  GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in]  GPIO_DebClockSrc: GPIO debounce clock source selection.
 * \param[in]  GPIO_DebClockDiv: GPIO debounce clock divider selection.
 * \param[in]  GPIO_DebCountLimit: debounce time can be calculated by count limit.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebUpdate(GPIOA, GPIO_GetPinBit(P0_0), GPIO_DEB_CLOCK_SRC_32K, GPIO_DEB_CLOCK_DIV_1, 20);
 * }
 * \endcode
 */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebClockSrc_TypeDef GPIO_DebClockSrc,
                       GPIODebClockDiv_TypeDef GPIO_DebClockDiv,
                       uint8_t                 GPIO_DebCountLimit);

/**
 * \brief   Read the specified input port pin.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to read.
 *            This parameter can be GPIO_Pin where can be 0~31.
 *
 * \return  The input port pin value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t input_bit = GPIO_ReadInputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Read value of all GPIO input data port.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * \return GPIO input data port value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t input_data = GPIO_ReadInputData(GPIOA);
 * }
 * \endcode
 */
uint32_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx);

/**
 * \brief   Read the specified output port pin.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to read.
 *            This parameter can be GPIO_Pin where can be 0~31.
 *
 * \return The output port pin value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t output_bit = GPIO_ReadOutputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Read value of all GPIO output data port.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * \return  GPIO output data port value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t output_data = GPIO_ReadOutputData(GPIOA);
 * }
 * \endcode
 */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx);

/**
 * \brief   Sets the selected data port bit.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be GPIO_Pin_x where x can be 0~31 or GPIO_Pin_All.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Reset the selected data port bit.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bits to be written.
 *            This parameter can be GPIO_Pin_0 to GPIO_Pin_31 or GPIO_Pin_All.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ResetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Set or clear the selected data port bit.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin where can be 0~31.
 * \param[in] BitVal: specifies the value to be written to the selected bit.
 *            This parameter can be one of the BitAction enum values:
 *            \arg Bit_RESET: To clear the port pin.
 *            \arg Bit_SET: To set the port pin.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_WriteBit(GPIOA, GPIO_GetPinBit(P0_0), Bit_SET);
 * }
 * \endcode
 */
void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, BitAction BitVal);

/**
 * \brief   Set or clear data port.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] PortVal: Specifies the value to be written to the selected bit.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_Write(GPIOA, 0xFFFFFFFF);
 * }
 * \endcode
 */
void GPIO_Write(GPIO_TypeDef *GPIOx, uint32_t PortVal);


/**
 * \brief  Get GPIO interrupt status.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin where can be 0~31.
 *
 * \return The new state of GPIO_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     ITStatus int_status = GPIO_GetINTStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
ITStatus GPIO_GetINTStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * rtl876x_gpio.h
 *
 * \brief  Specifies the direction for the selected pins.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_PinBit: Specifies the GPIO pins to be configured, please refer to "GPIO_pins_define" part.
 *            This parameter can be one of the following values:
 *            \arg GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] GPIO_Dir: Set the GPIO direction.
 *            This parameter can be one of the following values:
 *            \arg GPIO_DIR_IN: The direction is input.
 *            \arg GPIO_DIR_OUT: The direction is output.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetDirection(GPIOA, GPIO_GetPinBit(P3_0), GPIO_DIR_IN);
 * }
 * \endcode
 */
void GPIO_SetDirection(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinBit,
                       GPIODir_TypeDef GPIO_Dir);

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
/**
 * \brief  Set GPIO Output mode.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin_x where x can be 0~31.
 * \param[in] GPIO_OutputMode: Specifies the output mode to be set.
 *            This parameter can be one of the GPIOOutputMode_TypeDef enum values:
 *            \arg GPIO_OUTPUT_OPENDRAIN: Setting Output push-pull Mode.
 *            \arg GPIO_OUTPUT_PUSHPULL: Setting Output open-drain Mode.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetOutputMode(GPIOA, GPIO_GetPinBit(P0_0), GPIO_OUTPUT_OPENDRAIN);
 * }
 * \endcode
 */
void GPIO_SetOutputMode(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                        GPIOOutputMode_TypeDef GPIO_OutputMode);
#endif

/**
 * \brief  Get GPIO pad status.
 *
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin_x where x can be 0~31.
 *
 * \return The new state of GPIO_Pad (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus int_status = GPIO_GetPadStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Set GPIO Int Polarity.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin_x where x can be 0~31.
 * \param[in] int_type: Specifies the polarity type to be set.
 *            This parameter can be one of the GPIOPolarity_TypeDef enum values:
 *            \arg GPIO_POLARITY_ACTIVE_LOW: Setting interrupt to low active.
 *            \arg GPIO_POLARITY_ACTIVE_HIGH: Setting interrupt to high active.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void GPIO_Init(void)
 * {
 *     GPIO_SetPolarity(GPIOx, GPIO_Pin, GPIO_POLARITY_ACTIVE_LOW);
 * }
 * \endcode
 */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity);

#if (GPIO_SUPPORT_RAP_FUNCTION == 1)

void GPIO_RAPModeCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

void GPIO_ActionTrigger(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint32_t Action);

#if (GPIO_SUPPORT_RAP_EVENT_CONTROL == 1)
/**
 * \brief  Enable or disable RAP event.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: Specifies the port bit to be written.
 *            This parameter can be one of GPIO_Pin_x where x can be 0~31.
 * \param[in] NewState: Enable or disable RAP event.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void GPIO_Init(void)
 * {
 *     GPIO_RAPEventCmd(GPIOx, GPIO_Pin, ENABLE);
 * }
 * \endcode
 */
void GPIO_RAPEventCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);
#endif
#endif

#if (GPIO_SUPPORT_AUTO_CLOCK == 1)

void GPIO_ClockAutoModeCmd(GPIO_TypeDef *GPIOx, FunctionalState Newstate);

#endif

#if (GPIO_SUPPORT_WAKE_UP_FUNCTION == 1)
/**
 * \brief   Enable the GPIO wake up function.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in] NewState: Enable or disable the wake up function.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_WakeUpConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 *
 * \endcode
 */
void GPIO_WakeUpConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief   Check whether the specified input GPIO pin is in debounce.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus flag = GPIO_GetDebStatusBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 *
 * \endcode
 */
FlagStatus GPIO_GetDebStatusBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Check whether any pin under the GPIO is in debounce.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus flag = GPIO_GetDebStatus(GPIOA);
 * }
 *
 * \endcode
 */
FlagStatus GPIO_GetDebStatus(GPIO_TypeDef *GPIOx);
#endif

#if (GPIO_SUPPORT_SELF_TRIGGER_FUNCTION == 1)
/**
 * \brief   Enable the GPIO self-trigger function.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in] NewState: Enable or disable the self-trigger function.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SelfTriggerConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 *
 * \endcode
 */
void GPIO_SelfTriggerConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);
#endif

#if (GPIO_SUPPORT_INPUT_GATE_FUNCTION == 1)
/**
 * \brief   Enable the GPIO input gate function.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 * \param[in] NewState: Enable or disable the input gate function.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_InputGateConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 * }
 *
 * \endcode
 */
void GPIO_InputGateConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief   Check whether input is gate.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 * \param[in] GPIO_Pin: GPIO_Pin can be 0 to 31.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     bool ret = GPIO_IsInputGate(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 *
 * \endcode
 */
FlagStatus GPIO_IsInputGate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
/**
 * \brief   Get the GPIO hardware port address.
 *
 * \param[in] GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
 *
 * \return The GPIO hardware port address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     uint32_t address = GPIO_GetHWPortAddress(GPIOA);
 * }
 *
 * \endcode
 */
uint32_t GPIO_GetHWPortAddress(GPIO_TypeDef *GPIOx);
#endif
/** End of GPIO_Exported_Functions
  * \}
  */

/** End of GPIO
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GPIO_H */



