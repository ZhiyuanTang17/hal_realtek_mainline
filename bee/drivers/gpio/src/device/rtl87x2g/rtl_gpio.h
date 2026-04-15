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
#include "rtl_gpio_def.h"
#include "pin_def.h"

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
#define GPIOA0   0     //!< GPIOA0 corresponding number is 0.
#define GPIOA1   1     //!< GPIOA1 corresponding number is 1.
#define GPIOA2   2     //!< GPIOA2 corresponding number is 2.
#define GPIOA3   3     //!< GPIOA3 corresponding number is 3.
#define GPIOA4   4     //!< GPIOA4 corresponding number is 4.
#define GPIOA5   5     //!< GPIOA5 corresponding number is 5.
#define GPIOA6   6     //!< GPIOA6 corresponding number is 6.
#define GPIOA7   7     //!< GPIOA7 corresponding number is 7.
#define GPIOA8   8     //!< GPIOA8 corresponding number is 8.
#define GPIOA9   9     //!< GPIOA9 corresponding number is 9.
#define GPIOA10  10    //!< GPIOA10 corresponding number is 10.
#define GPIOA11  11    //!< GPIOA11 corresponding number is 11.
#define GPIOA12  12    //!< GPIOA12 corresponding number is 12.
#define GPIOA13  13    //!< GPIOA13 corresponding number is 13.
#define GPIOA14  14    //!< GPIOA14 corresponding number is 14.
#define GPIOA15  15    //!< GPIOA15 corresponding number is 15.
#define GPIOA16  16    //!< GPIOA16 corresponding number is 16.
#define GPIOA17  17    //!< GPIOA17 corresponding number is 17.
#define GPIOA18  18    //!< GPIOA18 corresponding number is 18.
#define GPIOA19  19    //!< GPIOA19 corresponding number is 19.
#define GPIOA20  20    //!< GPIOA20 corresponding number is 20.
#define GPIOA21  21    //!< GPIOA21 corresponding number is 21.
#define GPIOA22  22    //!< GPIOA22 corresponding number is 22.
#define GPIOA23  23    //!< GPIOA23 corresponding number is 23.
#define GPIOA24  24    //!< GPIOA24 corresponding number is 24.
#define GPIOA25  25    //!< GPIOA25 corresponding number is 25.
#define GPIOA26  26    //!< GPIOA26 corresponding number is 26.
#define GPIOA27  27    //!< GPIOA27 corresponding number is 27.
#define GPIOA28  28    //!< GPIOA28 corresponding number is 28.
#define GPIOA29  29    //!< GPIOA29 corresponding number is 29.
#define GPIOA30  30    //!< GPIOA30 corresponding number is 30.
#define GPIOA31  31    //!< GPIOA31 corresponding number is 31.
#endif
#ifdef GPIOB
#define GPIOB0   32    //!< GPIOA32 corresponding number is 32.
#define GPIOB1   33    //!< GPIOA33 corresponding number is 33.
#define GPIOB2   34    //!< GPIOA34 corresponding number is 34.
#define GPIOB3   35    //!< GPIOA35 corresponding number is 35.
#define GPIOB4   36    //!< GPIOA36 corresponding number is 36.
#define GPIOB5   37    //!< GPIOA37 corresponding number is 37.
#define GPIOB6   38    //!< GPIOA38 corresponding number is 38.
#define GPIOB7   39    //!< GPIOA39 corresponding number is 39.
#define GPIOB8   40    //!< GPIOA40 corresponding number is 40.
#define GPIOB9   41    //!< GPIOA41 corresponding number is 41.
#define GPIOB10  42    //!< GPIOA42 corresponding number is 42.
#define GPIOB11  43    //!< GPIOA43 corresponding number is 43.
#define GPIOB12  44    //!< GPIOA44 corresponding number is 44.
#define GPIOB13  45    //!< GPIOA45 corresponding number is 45.
#define GPIOB14  46    //!< GPIOA46 corresponding number is 46.
#define GPIOB15  47    //!< GPIOA47 corresponding number is 47.
#define GPIOB16  48    //!< GPIOA48 corresponding number is 48.
#define GPIOB17  49    //!< GPIOA49 corresponding number is 49.
#define GPIOB18  50    //!< GPIOA50 corresponding number is 50.
#define GPIOB19  51    //!< GPIOA51 corresponding number is 51.
#define GPIOB20  52    //!< GPIOA52 corresponding number is 52.
#define GPIOB21  53    //!< GPIOA53 corresponding number is 53.
#define GPIOB22  54    //!< GPIOA54 corresponding number is 54.
#define GPIOB23  55    //!< GPIOA55 corresponding number is 55.
#define GPIOB24  56    //!< GPIOA56 corresponding number is 56.
#define GPIOB25  57    //!< GPIOA57 corresponding number is 57.
#define GPIOB26  58    //!< GPIOA58 corresponding number is 58.
#define GPIOB27  59    //!< GPIOA59 corresponding number is 59.
#define GPIOB28  60    //!< GPIOA60 corresponding number is 60.
#define GPIOB29  61    //!< GPIOA61 corresponding number is 61.
#define GPIOB30  62    //!< GPIOA62 corresponding number is 62.
#define GPIOB31  63    //!< GPIOA63 corresponding number is 63.
#endif
#ifdef GPIOC
#define GPIOC0   64    //!< GPIOA64 corresponding number is 64.
#define GPIOC1   65    //!< GPIOA65 corresponding number is 65.
#define GPIOC2   66    //!< GPIOA66 corresponding number is 66.
#define GPIOC3   67    //!< GPIOA67 corresponding number is 67.
#define GPIOC4   68    //!< GPIOA68 corresponding number is 68.
#define GPIOC5   69    //!< GPIOA69 corresponding number is 69.
#define GPIOC6   70    //!< GPIOA70 corresponding number is 70.
#define GPIOC7   71    //!< GPIOA71 corresponding number is 71.
#define GPIOC8   72    //!< GPIOA72 corresponding number is 72.
#define GPIOC9   73    //!< GPIOA73 corresponding number is 73.
#define GPIOC10  74    //!< GPIOA74 corresponding number is 74.
#define GPIOC11  75    //!< GPIOA75 corresponding number is 75.
#define GPIOC12  76    //!< GPIOA76 corresponding number is 76.
#define GPIOC13  77    //!< GPIOA77 corresponding number is 77.
#define GPIOC14  78    //!< GPIOA78 corresponding number is 78.
#define GPIOC15  79    //!< GPIOA79 corresponding number is 79.
#define GPIOC16  80    //!< GPIOA80 corresponding number is 80.
#define GPIOC17  81    //!< GPIOA81 corresponding number is 81.
#define GPIOC18  82    //!< GPIOA82 corresponding number is 82.
#define GPIOC19  83    //!< GPIOA83 corresponding number is 83.
#define GPIOC20  84    //!< GPIOA84 corresponding number is 84.
#define GPIOC21  85    //!< GPIOA85 corresponding number is 85.
#define GPIOC22  86    //!< GPIOA86 corresponding number is 86.
#define GPIOC23  87    //!< GPIOA87 corresponding number is 87.
#define GPIOC24  88    //!< GPIOA88 corresponding number is 88.
#define GPIOC25  89    //!< GPIOA89 corresponding number is 89.
#define GPIOC26  90    //!< GPIOA90 corresponding number is 90.
#define GPIOC27  91    //!< GPIOA91 corresponding number is 91.
#define GPIOC28  92    //!< GPIOA92 corresponding number is 92.
#define GPIOC29  93    //!< GPIOA93 corresponding number is 93.
#define GPIOC30  94    //!< GPIOA94 corresponding number is 94.
#define GPIOC31  95    //!< GPIOA95 corresponding number is 95.
#endif
#ifdef GPIOD
#define GPIOD0   96    //!< GPIOA96 corresponding number is 96.
#define GPIOD1   97    //!< GPIOA97 corresponding number is 97.
#define GPIOD2   98    //!< GPIOA98 corresponding number is 98.
#define GPIOD3   99    //!< GPIOA99 corresponding number is 99.
#define GPIOD4   100   //!< GPIOA100 corresponding number is 100.
#define GPIOD5   101   //!< GPIOA101 corresponding number is 101.
#define GPIOD6   102   //!< GPIOA102 corresponding number is 102.
#define GPIOD7   103   //!< GPIOA103 corresponding number is 103.
#define GPIOD8   104   //!< GPIOA104 corresponding number is 104.
#define GPIOD9   105   //!< GPIOA105 corresponding number is 105.
#define GPIOD10  106   //!< GPIOA106 corresponding number is 106.
#define GPIOD11  107   //!< GPIOA107 corresponding number is 107.
#define GPIOD12  108   //!< GPIOA108 corresponding number is 108.
#define GPIOD13  109   //!< GPIOA109 corresponding number is 109.
#define GPIOD14  110   //!< GPIOA110 corresponding number is 110.
#define GPIOD15  111   //!< GPIOA111 corresponding number is 111.
#define GPIOD16  112   //!< GPIOA112 corresponding number is 112.
#define GPIOD17  113   //!< GPIOA113 corresponding number is 113.
#define GPIOD18  114   //!< GPIOA114 corresponding number is 114.
#define GPIOD19  115   //!< GPIOA115 corresponding number is 115.
#define GPIOD20  116   //!< GPIOA116 corresponding number is 116.
#define GPIOD21  117   //!< GPIOA117 corresponding number is 117.
#define GPIOD22  118   //!< GPIOA118 corresponding number is 118.
#define GPIOD23  119   //!< GPIOA119 corresponding number is 119.
#define GPIOD24  120   //!< GPIOA120 corresponding number is 120.
#define GPIOD25  121   //!< GPIOA121 corresponding number is 121.
#define GPIOD26  122   //!< GPIOA122 corresponding number is 122.
#define GPIOD27  123   //!< GPIOA123 corresponding number is 123.
#define GPIOD28  124   //!< GPIOA124 corresponding number is 124.
#define GPIOD29  125   //!< GPIOA125 corresponding number is 125.
#define GPIOD30  126   //!< GPIOA126 corresponding number is 126.
#define GPIOD31  127   //!< GPIOA127 corresponding number is 127.
#endif

/** End of GPIO_Number
  * \}
  */

/**
 * \defgroup    GPIO_Pins_Define GPIO Pins Define
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
#define GPIO_Pin_0                 (BIT0)   //!< GPIO Pin 0 selected.
#define GPIO_Pin_1                 (BIT1)   //!< GPIO Pin 1 selected.
#define GPIO_Pin_2                 (BIT2)   //!< GPIO Pin 2 selected.
#define GPIO_Pin_3                 (BIT3)   //!< GPIO Pin 3 selected.
#define GPIO_Pin_4                 (BIT4)   //!< GPIO Pin 4 selected.
#define GPIO_Pin_5                 (BIT5)   //!< GPIO Pin 5 selected.
#define GPIO_Pin_6                 (BIT6)   //!< GPIO Pin 6 selected.
#define GPIO_Pin_7                 (BIT7)   //!< GPIO Pin 7 selected.
#define GPIO_Pin_8                 (BIT8)   //!< GPIO Pin 8 selected.
#define GPIO_Pin_9                 (BIT9)   //!< GPIO Pin 9 selected.
#define GPIO_Pin_10                (BIT10)  //!< GPIO Pin 10 selected.
#define GPIO_Pin_11                (BIT11)  //!< GPIO Pin 11 selected.
#define GPIO_Pin_12                (BIT12)  //!< GPIO Pin 12 selected.
#define GPIO_Pin_13                (BIT13)  //!< GPIO Pin 13 selected.
#define GPIO_Pin_14                (BIT14)  //!< GPIO Pin 14 selected.
#define GPIO_Pin_15                (BIT15)  //!< GPIO Pin 15 selected.
#define GPIO_Pin_16                (BIT16)  //!< GPIO Pin 16 selected.
#define GPIO_Pin_17                (BIT17)  //!< GPIO Pin 17 selected.
#define GPIO_Pin_18                (BIT18)  //!< GPIO Pin 18 selected.
#define GPIO_Pin_19                (BIT19)  //!< GPIO Pin 19 selected.
#define GPIO_Pin_20                (BIT20)  //!< GPIO Pin 20 selected.
#define GPIO_Pin_21                (BIT21)  //!< GPIO Pin 21 selected.
#define GPIO_Pin_22                (BIT22)  //!< GPIO Pin 22 selected.
#define GPIO_Pin_23                (BIT23)  //!< GPIO Pin 23 selected.
#define GPIO_Pin_24                (BIT24)  //!< GPIO Pin 24 selected.
#define GPIO_Pin_25                (BIT25)  //!< GPIO Pin 25 selected.
#define GPIO_Pin_26                (BIT26)  //!< GPIO Pin 26 selected.
#define GPIO_Pin_27                (BIT27)  //!< GPIO Pin 27 selected.
#define GPIO_Pin_28                (BIT28)  //!< GPIO Pin 28 selected.
#define GPIO_Pin_29                (BIT29)  //!< GPIO Pin 29 selected.
#define GPIO_Pin_30                (BIT30)  //!< GPIO Pin 30 selected.
#define GPIO_Pin_31                (BIT31)  //!< GPIO Pin 31 selected.
#define GPIO_Pin_All               ((uint32_t)0xFFFFFFFF)  //!< All pins selected.

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
                                    ((PIN) == GPIO_Pin_All)) //!< Check if the input parameter is valid.

#define IS_GPIO_PIN(PIN)          ((PIN) != (uint32_t)0x00) //!< Check if the input parameter is valid.

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
    Bit_RESET = 0, //!< Reset the GPIO bit.
    Bit_SET        //!< Set the GPIO bit.
} BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET)) //!< Check if the input parameter is valid.

/** End of GPIO_Bit_Action
  * \}
  */

/**
 * \defgroup    GPIO_Direction GPIO Direction
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DIR_IN   = 0x0, //!< GPIO input direction.
    GPIO_DIR_OUT  = 0x1, //!< GPIO output direction.
} GPIODir_TypeDef;

#define IS_GPIO_DIR(DIR) (((DIR) == GPIO_DIR_IN) || ((DIR) == GPIO_DIR_OUT)) //!< Check if the input parameter is valid.

/** End of GPIO_Direction
  * \}
  */

/**
 * \defgroup    GPIO_Output_Mode GPIO Output Mode
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_OUTPUT_PUSHPULL  = 0x0, //!< GPIO output push-pull mode.
    GPIO_OUTPUT_OPENDRAIN = 0x1, //!< GPIO output open-drain mode.
} GPIOOutputMode_TypeDef;

#define IS_GPIO_OUTPUT_MODE(MODE) (((MODE) == GPIO_OUTPUT_PUSHPULL)|| ((MODE) == GPIO_OUTPUT_OPENDRAIN)) //!< Check if the input parameter is valid.

/** End of GPIO_Output_Mode
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
    GPIO_SOFTWARE_MODE = 0x0,  //!< GPIO software control mode(default).
    GPIO_HARDWARE_MODE  = 0x1, //!< GPIO hardware control mode.
} GPIOControlMode_Typedef;

#define IS_GPIOIT_MODDE(TYPE) (((TYPE) == GPIO_SOFTWARE_MODE)\
                               || ((TYPE) == GPIO_HARDWARE_MODE)) //!< Check if the input parameter is valid.
#endif

/**
 * \defgroup    GPIO_Interrupt_Trigger GPIO Interrupt Trigger
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_INT_TRIGGER_LEVEL = 0x0,     //!< GPIO interrupt trigger mode is level trigger.
    GPIO_INT_TRIGGER_EDGE  = 0x1,     //!< GPIO interrupt trigger mode is edge trigger.
#if GPIO_SUPPORT_INT_BOTHEDGE
    GPIO_INT_TRIGGER_BOTH_EDGE = 0x2, //!< GPIO interrupt trigger mode is both edge trigger.
#endif
} GPIOITTrigger_TypeDef;

#define IS_GPIOIT_TRIGGER_TYPE(TYPE) (((TYPE) == GPIO_INT_TRIGGER_LEVEL) || \
                                      ((TYPE) == GPIO_INT_TRIGGER_EDGE)) //!< Check if the input parameter is valid.

/** End of GPIO_Interrupt_Trigger
  * \}
  */

/**
 * \defgroup    GPIO_Interrupt_Polarity GPIO Interrupt Polarity
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_INT_POLARITY_ACTIVE_LOW  = 0x0, //!< GPIO interrupt interrupt Polarity is low active.
    GPIO_INT_POLARITY_ACTIVE_HIGH = 0x1, //!< GPIO interrupt interrupt Polarity is high active.
} GPIOITPolarity_TypeDef;

#define IS_GPIOIT_POLARITY_TYPE(TYPE) (((TYPE) == GPIO_INT_POLARITY_ACTIVE_LOW) || \
                                       ((TYPE) == GPIO_INT_POLARITY_ACTIVE_HIGH)) //!< Check if the input parameter is valid.

/** End of GPIO_Interrupt_Polarity
  * \}
  */

/**
 * \defgroup    GPIO_Interrupt_Debounce GPIO Interrupt Debounce
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_INT_DEBOUNCE_DISABLE = 0x0, //!< Disable interrupt debounce.
    GPIO_INT_DEBOUNCE_ENABLE  = 0x1, //!< Enable interrupt debounce.
} GPIODebounce_TypeDef;

#define IS_GPIOIT_DEBOUNCE_TYPE(TYPE) (((TYPE) == GPIO_INT_DEBOUNCE_DISABLE) || \
                                       ((TYPE) == GPIO_INT_DEBOUNCE_ENABLE)) //!< Check if the input parameter is valid.

/** End of GPIO_Interrupt_Debounce
  * \}
  */

#if (GPIO_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    GPIO_Qactive_Force GPIO Qactive Force
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_QACTIVE_PCLK_FORCE     = 0x0,
    GPIO_QACTIVE_PCLKINTR_FORCE = 0x1,
    GPIO_QACTIVE_CLK32K_FORCE   = 0x2,
} GPIOQactiveForce_TypeDef;

/** End of GPIO_Qactive_Force
  * \}
  */

/**
 * \defgroup    GPIO_Task GPIO Task
 * \{
 * \ingroup     GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_TASK_DRSET = 0,
    GPIO_TASK_DRCLR = 1,
    GPIO_TASK_DRTOGGLE = 2,
    GPIO_TASK_POLSET = 3,
    GPIO_TASK_POLCLR = 4,
    GPIO_TASK_POLTOGGLE = 5,
    GPIO_TASK_DDRSET = 6,
    GPIO_TASK_DDRCLR = 7,
} GPIOTask_TypeDef;

/** End of GPIO_Task
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

    uint32_t                GPIO_Pin;           /**< Specify the GPIO pins to be configured.
                                                     This parameter can be a value of \ref GPIO_Pins_Define. */

    GPIODir_TypeDef         GPIO_Dir;           /**< Specify the GPIO direction.
                                                     This parameter can be a value of \ref GPIO_Direction */

    GPIOOutputMode_TypeDef  GPIO_OutPutMode;    /**< Specify the GPIO output mode.
                                                     This parameter can be a value of \ref GPIO_Output_Mode */

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIOControlMode_Typedef GPIO_ControlMode;   /**< Specify the GPIO mode. */
#endif

    FunctionalState         GPIO_ITCmd;         /**< Enable or disable GPIO interrupt.
                                                     This parameter can be a value of ENABLE or DISABLE. */

    GPIOITTrigger_TypeDef   GPIO_ITTrigger;     /**< Specify the GPIO interrupt trigger.
                                                     This parameter can be a value of \ref GPIO_Interrupt_Trigger */

    GPIOITPolarity_TypeDef  GPIO_ITPolarity;    /**< Specify the GPIO interrupt polarity.
                                                     This parameter can be a value of \ref GPIO_Interrupt_Polarity */

    GPIODebounce_TypeDef    GPIO_ITDebounce;    /**< Enable or disable debounce for interrupt.
                                                     This parameter can be a value of \ref GPIO_Interrupt_Debounce */

    GPIODebounceSrc_TypeDef GPIO_DebounceClkSource; /**< Select debounce count clock source.
                                                         This parameter can be a value of \ref GPIO_Debounce_Clock_Source */

    GPIODebounceDiv_TypeDef GPIO_DebounceClkDiv;    /**< Specify the debounce clock divider.
                                                         This parameter can be a value of \ref GPIO_Debounce_Divider */

    uint8_t
    GPIO_DebounceCntLimit;  /**< Specify the debounce Limit. Debounce_time = (CntLimit + 1) * GPIO_DebounceClkSource/GPIO_DebounceClkDiv.
                                                         This parameter leagel value range is from 0 ~ 255. */
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
 * \brief   Deinitialize the GPIO peripheral registers to their default reset values.
 *
 * \param[in] GPIOx  Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
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
 * \brief  Initialize the GPIO peripheral according to the specified
 *         parameters in the GPIO_InitStruct.
 *
 * \param[in] GPIOx            Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd       = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger   = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity  = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
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
 * \brief    Fill each GPIO_InitStruct member with its default value.
 *
 * \note The default settings for the GPIO_InitStruct member are shown in the following table:
 *       | GPIO_InitStruct member          | Default value                         |
 *       |:-------------------------------:|:-------------------------------------:|
 *       | GPIO_Pin                        | \ref GPIO_Pin_All                     |
 *       | GPIO_Dir                        | \ref GPIO_DIR_IN                      |
 *       | GPIO_OutPutMode                 | \ref GPIO_OUTPUT_PUSHPULL             |
 *       | GPIO_ITCmd                      | DISABLE                               |
 *       | GPIO_ITTrigger                  | \ref GPIO_INT_TRIGGER_LEVEL           |
 *       | GPIO_ITPolarity                 | \ref GPIO_INT_POLARITY_ACTIVE_LOW     |
 *       | GPIO_ITDebounce                 | \ref GPIO_INT_DEBOUNCE_DISABLE        |
 *       | GPIO_DebounceClkSource          | \ref GPIO_DEBOUNCE_32K                |
 *       | GPIO_DebounceClkDiv             | \ref GPIO_DEBOUNCE_DIVIDER_1          |
 *       | GPIO_DebounceCntLimit           | 32                                    |
 *
 * \param[in] GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin        = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir        = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd      = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger  = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 * }
 * \endcode
 */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * \brief   Enable or disable the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.
 *                      This parameter can be one of GPIO_Pin where can be 0~31.
 * \param[in] NewState  New state of the GPIOx interrupt.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the interrupt of the specified GPIO pin.
 *                      - DISABLE: Disable the interrupt of the specified GPIO pin.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd       = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger   = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity  = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
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
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.
 *                      This parameter can be one of GPIO_Pin where can be 0~31.
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
 * \brief   Mask or unmask the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.
 *                      This parameter can be one of GPIO_Pin where can be 0~31.
 * \param[in] NewState  Mask or unmask interrupt.
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
 * \brief   Get GPIO group through the given pad.
 *
 * \param[in] Pin_num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return  GPIOx(x is 0~31) value. Refer to \ref GPIO_Declaration.
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
 * \param[in] Pin_num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return  GPIOx(x is 0~31) value. Refer to \ref GPIO_Declaration.
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
 * \param[in] Pin_num  Pin number to be configured. Refer to \ref Pin_Number.
 *
 * \return  GPIOx(x is 0~31) value.
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
 * \brief   Enable or disable the debounce counter function and clock.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.
 *                      This parameter can be one of GPIO_Pin where can be 0~31..
 * \param[in] NewState  NewState of GPIO debounce counter function and clock.
 *                      - ENABLE: Enable debounce counter function and clock of the specified pin.
 *                      - DISABLE: Reset the counter and output of external debounce.
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
 * \param[in]  GPIOx                  where x can be A to D to select the GPIO peripheral.
 * \param[in]  GPIO_Pin               Specify the GPIO pins to be configured.
 *                                    This parameter can be one of GPIO_Pin where can be 0~31.
 * \param[in]  GPIO_DebounceClkDiv    Debounce clock divider selection.
 * \param[in]  GPIO_DebounceCntLimit  Debounce time can be calculated by count limit.
 *                                    Debounce_time = (CntLimit + 1) * GPIO_DebounceClkSource/GPIO_DebounceClkDiv.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebUpdate(GPIOA, GPIO_GetPinBit(P0_0), GPIO_DEBOUNCE_32K, GPIO_DEBOUNCE_DIVIDER_1, 20);
 * }
 * \endcode
 */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebounceSrc_TypeDef GPIO_DebounceClkSource,
                       GPIODebounceDiv_TypeDef GPIO_DebounceClkDiv, uint8_t GPIO_DebounceCntLimit);

/**
 * \brief   Read the specified input pin.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the port bit to read.
 *                      This parameter can be \ref GPIO_Pin where can be 0~31.
 *
 * \return  GPIO input port pin value.
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
 * \brief  Read value of all GPIO input data.
 *
 * \param[in] GPIOx  Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
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
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the port bit to read.
 *                      This parameter can be GPIO_Pin where can be 0~31.
 *
 * \return GPIO output port pin value.
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
 * \param[in] GPIOx  Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
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
 * \brief   Set the selected data port bit.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the port bit to be written.
 *                      This parameter can be GPIO_Pin_x where x can be 0~31 or GPIO_Pin_All.
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
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the port bits to be written.
 *                      This parameter can be GPIO_Pin_0 to GPIO_Pin_31 or GPIO_Pin_All.
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
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the port bit to be written.
 *                      This parameter can be one of GPIO_Pin where can be 0~31.
 * \param[in] BitVal    Specify the value to be written to the selected bit.
 *                      This parameter can be one of the BitAction enum values:
 *                      - Bit_RESET: To clear the port pin.
 *                      - Bit_SET: To set the port pin.
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
 * \param[in] GPIOx    Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] PortVal  Specify the value to be written to the selected bit.
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
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.
 *                      This parameter can be one of GPIO_Pin where can be 0~31.
 *
 * \return The new state of interrupt status (SET or RESET).
 *         - SET: The interrupt status is set.
 *         - RESET: The interrupt status has not been set.
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
 * \brief  Specify the direction for the selected pins.
 *
 * \param[in] GPIOx        Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_PinBit  Specify the GPIO pins to be configured, Refer to \ref GPIO_Pins_Define.
 * \param[in] GPIO_Dir     Set the GPIO direction.
 *                         This parameter can be one of the following values:
 *                         - GPIO_DIR_IN: The direction is input.
 *                         - GPIO_DIR_OUT: The direction is output.
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

/**
 * \brief  Set GPIO output mode.
 *
 * \param[in] GPIOx            Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin         Specify the GPIO pins to be configured.Refer to \ref GPIO_Pins_Define.
 * \param[in] GPIO_OutputMode  Specify the output mode to be set.
 *                             This parameter can be one of the \ref GPIO_Output_Mode enum values:
 *                             - GPIO_OUTPUT_OPENDRAIN: Setting Output push-pull Mode.
 *                             - GPIO_OUTPUT_PUSHPULL: Setting Output open-drain Mode.
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

/**
 * \brief  Get GPIO pad status.
 *
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.Refer to \ref GPIO_Pins_Define.
 *
 * \return  The new state of GPIO_Pad.
 *          - SET: The GPIO pad has been set.
 *          - RESET: Failed to set the GPIO pad.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus status = GPIO_GetPadStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Set GPIO Interript Polarity.
 *
 * \param[in] GPIOx     Select the GPIO peripheral. Refer to \ref GPIO_Declaration.
 * \param[in] GPIO_Pin  Specify the GPIO pins to be configured.Refer to \ref GPIO_Pins_Define.
 * \param[in] int_type  Specify the polarity type to be set.
 *                      This parameter can be one of the \ref GPIO_Interrupt_Polarity enum values:
 *                      - GPIO_INT_POLARITY_ACTIVE_LOW: Setting interrupt to low active.
 *                      - GPIO_INT_POLARITY_ACTIVE_HIGH: Setting interrupt to high active.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void GPIO_Init(void)
 * {
 *     GPIO_SetPolarity(GPIOx, GPIO_Pin, GPIO_INT_POLARITY_ACTIVE_LOW);
 * }
 * \endcode
 */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                      GPIOITPolarity_TypeDef int_type);

#if (GPIO_SUPPORT_RAP_FUNCTION == 1)

void GPIO_RAPQactiveCtrl(GPIO_TypeDef *GPIOx, uint32_t Qactive, FunctionalState NewState);

void GPIO_RAPModeCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

void GPIO_TaskTrigger(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint32_t Task);

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

