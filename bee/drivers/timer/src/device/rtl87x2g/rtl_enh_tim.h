/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_ENH_TIM_H
#define RTL_ENH_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "rtl_enhtim_def.h"
#include "pin_def.h"

/** \defgroup ENHTIM      ENHTIM
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    ENHTIM_Clock_Divider ENHTIM Clock Divider
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_CLOCK_DIVIDER_1   = 0x0,     //!< Clock divider is 1.
    ENHTIM_CLOCK_DIVIDER_2   = 0x1,     //!< Clock divider is 2.
    ENHTIM_CLOCK_DIVIDER_4   = 0x2,     //!< Clock divider is 4.
    ENHTIM_CLOCK_DIVIDER_8   = 0x3,     //!< Clock divider is 8.
    ENHTIM_CLOCK_DIVIDER_16  = 0x4,     //!< Clock divider is 16.
    ENHTIM_CLOCK_DIVIDER_32  = 0x5,     //!< Clock divider is 32.
    ENHTIM_CLOCK_DIVIDER_40  = 0x6,     //!< Clock divider is 40.
    ENHTIM_CLOCK_DIVIDER_64  = 0x7,     //!< Clock divider is 64.
} ENHTIMClkDiv_TypeDef;

#define IS_ENHTIM_CLK_DIVIDER(div) (((div) == ENHTIM_CLOCK_DIVIDER_1) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_2) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_4) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_8) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_16)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_32)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_40)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_64)) //!< Check if the input parameter is valid.

/** End of ENHTIM_Clock_Divider
  * \}
  */

/**
 * \defgroup    ENHTIM_Latch_Channel_Count ENHTIM Latch Channel Count
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
#if ENHTIM_SUPPORT_LATCH_CNT_0
    LATCH_CNT_0 = 0x0,     //!< GPIO trigger function.
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    LATCH_CNT_1 = 0x1,     //!< Tx on trigger function.
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    LATCH_CNT_2 = 0x2,     //!< Acc hit trigger function.
#endif
} ENHTIMLatchCnt_TypeDef;

#if (ENHTIM_SUPPORT_LATCH_CNT_0 && !ENHTIM_SUPPORT_LATCH_CNT_1 && !ENHTIM_SUPPORT_LATCH_CNT_2)
#define IS_ENHTIM_LATCH_CNT(cnt) ((cnt) == LATCH_CNT_0) //!< Check if the input parameter is valid.
#endif
#if (ENHTIM_SUPPORT_LATCH_CNT_0 && ENHTIM_SUPPORT_LATCH_CNT_1 && ENHTIM_SUPPORT_LATCH_CNT_2)
#define IS_ENHTIM_LATCH_CNT(cnt) ((cnt) == LATCH_CNT_0 || (cnt) == LATCH_CNT_1 || (cnt) == LATCH_CNT_2) //!< Check if the input parameter is valid.
#endif

/** End of ENHTIM_Latch_Channel_Count
  * \}
  */


/**
 * \defgroup    ENHTIM_DMA_Target ENHTIM DMA Target
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_DMA_CCR_FIFO = 0x00,     //!< DMA target is CCR FIFO.
    ENHTIM_DMA_LC_FIFO = 0x01,      //!< DMA target is latch count FIFO.
} ENHTIMDmaTarget_TypeDef;

#define IS_ENHTIM_DMA_TARGET(mode) (((mode) == ENHTIM_DMA_CCR_FIFO) || \
                                    ((mode) == ENHTIM_DMA_LC_FIFO)) //!< Check if the input parameter is valid.

/** End of ENHTIM_DMA_Target
  * \}
  */

/**
 * \defgroup    ENHTIM_Latch_Trigger_Mode ENHTIM Latch Trigger Mode
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_LATCH_TRIGGER_RISING_EDGE = 0x00,     //!< Latch trigger mode is rising edge.
    ENHTIM_LATCH_TRIGGER_FALLING_EDGE = 0x01,    //!< Latch trigger mode is falling edge.
    ENHTIM_LATCH_TRIGGER_BOTH_EDGE = 0x02,       //!< Latch trigger mode is both rising and falling edge.
} ENHTIMLatchTriggleMode_TypeDef;

#define IS_ENHTIM_LATCH_TRIG_Mode(mode) (((mode) == ENHTIM_LATCH_TRIGGER_BOTH_EDGE) || \
                                         ((mode) == ENHTIM_LATCH_TRIGGER_FALLING_EDGE) || \
                                         ((mode) == ENHTIM_LATCH_TRIGGER_RISING_EDGE)) //!< Check if the input parameter is valid.

/** End of ENHTIM_Latch_Trigger_Mode
  * \}
  */

/**
 * \defgroup    ENHTIM_Mode ENHTIM Mode
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_MODE_FreeRun = 0x00,        //!< Freerun mode.
    ENHTIM_MODE_PWM_AUTO = 0x01,       //!< User define pwm auto mode.
    ENHTIM_MODE_PWM_MANUAL = 0x02,     //!< User define pwm manual mode.
} ENHTIMMode_TypeDef;

#define IS_ENHTIM_MODE(mode) (((mode) == ENHTIM_MODE_PWM_MANUAL) || \
                              ((mode) == ENHTIM_MODE_PWM_AUTO) || \
                              ((mode) == ENHTIM_MODE_UserDefine)) //!< Check if the input parameter is valid.

/** End of ENHTIM_Mode
  * \}
  */

/**
 * \defgroup    ENHTIM_PWM_Polarity ENHTIM PWM Polarity
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_PWM_START_WITH_LOW = 0x00,      //!< PWM start with output low.
    ENHTIM_PWM_START_WITH_HIGH = 0x01,     //!< PWM start with output high.
} ENHTIMPWMPolarity_TypeDef;

#define IS_ENHTIM_PWM_POLARITY(Pol) (((Pol) == ENHTIM_PWM_START_WITH_HIGH) || \
                                     ((Pol) == ENHTIM_PWM_START_WITH_LOW)) //!< Check if the input parameter is valid.

/** End of ENHTIM_PWM_Polarity
  * \}
  */

/**
 * \defgroup    ENHTIM_PWM_DeadZone_Clock_Source ENHTIM PWM DeadZone Clock Source
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_PWM_DZCLKSRCE_ENHTIM = 0x0,     //!< PWM deadzone clock source is the same as ENHTIM clock source.
    ENHTIM_PWM_DZCLKSRCE_32K = 0x1,        //!< PWM deadzone clock source is 32KHz.
} ENHTIMPWMDZClkSrc_TypeDef;

#define IS_ENHTIM_PWM_DeadZone_Clock_Source(src) (((src) == ENHTIM_PWM_DZCLKSRCE_ENHTIM) || \
                                                  ((src) == ENHTIM_PWM_DZCLKSRCE_32K)) //!< Check if the input parameter is valid.

/** End of ENHTIM_PWM_DeadZone_Clock_Source
  * \}
  */

/**
 * \defgroup    ENHPWM_DeadZone_Stop_State ENHPWM DeadZone Stop State
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_PWM_STOP_AT_LOW = 0x0,     //!< PWM deadzone mergence stop state at low.
    ENHTIM_PWM_STOP_AT_HIGH = 0x1,    //!< PWM deadzone mergence stop state at high.
} ENHTIMPWMDZStopState_TypeDef;

/** End of ENHPWM_DeadZone_Stop_State
  * \}
  */

#if ENHTIM_SUPPORT_PWM_SRC_SELECT
/**
 * \defgroup    ENHPWM_DeadZone_Reference_Selection ENHPWM DeadZone Reference Selection
 * \brief   The actual output waveforms of the P and N in complementary PWM mode.
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_DZ_REF_PWMPN = 0x0,     //!< PWM P waveform is PWM_P, PWM N waveform is PWM_N,
    ENHTIM_DZ_REF_PWMNN = 0x1,     //!< PWM P waveform is PWM_N, PWM N waveform is PWM_N,
    ENHTIM_DZ_REF_PWMPP = 0x2,     //!< PWM P waveform is PWM_P, PWM N waveform is PWM_P,
    ENHTIM_DZ_REF_PWMNP = 0x3,     //!< PWM P waveform is PWM_N, PWM N waveform is PWM_P,
} ENHTIMPWMDZRef_TypeDef;

/** End of ENHPWM_Reference_Selection
  * \}
  */
#endif

/**
 * \defgroup    ENHTIM_Interrupts ENHTIM Interrupts
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_INT_TIM                            (0x00)     //!< ENHTIM timeout interrupt.
#define ENHTIM_INT_LATCH_CNT_FIFO_FULL            (0x40)     //!< ENHTIM latch count FIFO full interrupt.
#define ENHTIM_INT_LATCH_CNT_FIFO_THD             (0x42)     //!< ENHTIM latch count FIFO threshold interrupt.
#define ENHTIM_INT_LATCH_CNT_FIFO_EMPTY           (0x01)     //!< ENHTIM latch count FIFO empty interrupt.

#define IS_ENHTIM_INT(INT) (((INT) == ENHTIM_INT_TIM) || \
                            ((INT) == ENHTIM_INT_LATCH_CNT_FIFO_FULL) || \
                            ((INT) == ENHTIM_INT_LATCH_CNT_FIFO_THD)) //!< Check if the input parameter is valid.

/** End of ENHTIM_Interrupts
  * \}
  */

/**
 * \defgroup    ENHTIM_Flag ENHTIM Flag
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_FLAG_CCR_FIFO_EMPTY        3     //!< ENHTIM CCR FIFO empty flag.
#define ENHTIM_FLAG_CCR_FIFO_FULL         2     //!< ENHTIM CCR FIFO full flag.
#define ENHTIM_FLAG_LC_FIFO_EMPTY         1     //!< ENHTIM latch count FIFO empty flag.
#define ENHTIM_FLAG_LC_FIFO_FULL          0     //!< ENHTIM latch count FIFO full flag.

#define IS_ENHTIM_FLAG(flag) (((flag) == ENHTIM_FLAG_CCR_FIFO_FULL) || \
                              ((flag) == ENHTIM_FLAG_CCR_FIFO_EMPTY)|| \
                              ((flag) == ENHTIM_FLAG_LC_FIFO_FULL)  || \
                              ((flag) == ENHTIM_FLAG_LC_FIFO_EMPTY) )) //!< Check if the input parameter is valid.

/** End of ENHTIM_Flag
  * \}
  */

/**
 * \defgroup    ENHTIM_FIFO_Clear ENHTIM FIFO Clear
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_FIFO_CLR_CCR                 (0)     //!< ENHTIM CCR FIFO clear.
#define ENHTIM_FIFO_CLR_CNT0                (8)     //!< ENHTIM latch count FIFO clear.

/** End of ENHTIM_FIFO_Clear
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup ENHTIM_Exported_Types ENHTIM Exported Types
  * \brief
  * \{
  */

/**
 * \brief       ENHTIM init structure definition.
 *
 * \ingroup     ENHTIM_Exported_Types
 */
typedef struct
{
    ENHTIMClkSrc_TypdDef ENHTIM_ClockSource;   /*!< Specify the ENHTIM clock source.
                                                    This parameter can be a value of \ref ENHTIM_Clock_Source . */

    FunctionalState ENHTIM_ClockDiv_En;        /*!< Enable or disable the ENHTIM clock source divider.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    ENHTIMClkDiv_TypeDef ENHTIM_ClockDiv;      /*!< Specify the divider for the ENHTIM clock source.
                                                    This parameter can be a value of \ref ENHTIM_Clock_Divider */

    ENHTIMMode_TypeDef ENHTIM_Mode;            /*!< Specify the counter mode.
                                                    This parameter can be a value of \ref ENHTIM_Mode */

    FunctionalState ENHTIM_PWMOutputEn;        /*!< Enable or disable the ENHTIM PWM output.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    ENHTIMPWMPolarity_TypeDef
    ENHTIM_PWMStartPolarity; /*!< Specify ENHTIM toggle output polarity for user-define mode.
                                                            This parameter can be a value of \ref ENHTIM_PWM_Polarity */

    FunctionalState ENHTIM_LatchCountEn[3];    /*!< Enable or disable the ENHTIM Latch count.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    ENHTIMLatchTriggleMode_TypeDef ENHTIM_LatchCountTrigger[3]; /*!< Specify ENHTIM latch trigger mode.
                                                                     This parameter can be a value of \ref ENHTIM_Latch_Trigger_Mode */

    uint16_t ENHTIM_LatchCountThd;             /*!< Specify the latch counter FIFO threshold.
                                                    This parameter can be value of 0 ~ 0x1F. */

    uint16_t ENHTIM_LatchTriggerPad;           /*!< Specify the latch trigger pin.
                                                    This parameter can be a value of P0_0 to P19_0. */

    uint32_t ENHTIM_MaxCount;                  /*!< Specify the ENHTIM maximum counter value for user-define mode.
                                                    This parameter leagel value range is from 1 ~ 2^32-2. */

    uint32_t ENHTIM_CCValue;                   /*!< Specify the ENHTIM capture/compare value for user-define mode.
                                                    This parameter leagel value range is from 0 ~ 2^32-2.*/

    FunctionalState ENHTIM_PWMDeadZoneEn;      /*!< Enable or disable the ENHTIM PWM deadzone function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint16_t ENHTIM_PWMDeadZoneClockSource;    /*!< Specify the PWM deadzone Clock Source.
                                                    This parameter can be a value of \ref ENHTIM_PWM_DeadZone_Clock_Source. */

    FunctionalState
    ENHTIM_PWMDeadZone_ClockDivEn; /*!< Enable or disable the PWM deadzone clock source divider.
                                                        This parameter can be a value of ENABLE or DISABLE. */

    ENHTIMClkDiv_TypeDef
    ENHTIM_PWMDeadZone_ClockDiv; /*!< Specify the divider for the PWM deadzone clock source.
                                                           This parameter can be a value of \ref ENHTIM_Clock_Divider */

    ENHTIMPWMDZStopState_TypeDef ENHTIM_PWMStopStateP; /*!< Specify the PWM_P stop state.
                                                            This parameter can be a value of \ref ENHPWM_DeadZone_Stop_State */

    ENHTIMPWMDZStopState_TypeDef ENHTIM_PWMStopStateN; /*!< Specify the PWM_N stop state.
                                                            This parameter can be a value of \ref ENHPWM_DeadZone_Stop_State */

    uint32_t ENHTIM_DeadZoneSize;              /*!< Specify size of deadzone time. Deadzone Time = (deadzone size)*(deadzone clock period).
                                                    This parameter must range from 1 to 0xff. */

    FunctionalState ENHTIM_DmaEn;              /*!< Enable or disable the ENHTIM DMA function.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    ENHTIMDmaTarget_TypeDef ENHTIM_DmaTragget; /*!< Specify ENHTIM DMA target.
                                                    This parameter can be a value of \ref ENHTIM_DMA_Target */

#if ENHTIM_SUPPORT_ONESHOT_CMD
    FunctionalState ENHTIM_OneShotEn;          /*!< Enable or disable the one shot mode. */
#endif
} ENHTIM_InitTypeDef;

/** End of ENHTIM_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup ENHTIM_Exported_Functions ENHTIM Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Initialize the ENHTIMx unit peripheral according to
 *            the specified parameters in ENHTIM_InitStruct.
 *
 * \param[in] ENHTIMx                    Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] ENHTIM_TimeBaseInitStruct  Pointer to a ENHTIM_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_enhance_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     ENHTIM_InitTypeDef ENHTIM_InitStruct;
 *     ENHTIM_StructInit(&ENHTIM_InitStruct);
 *
 *     ENHTIM_InitStruct.ENHTIM_PWM_En = PWM_DISABLE;
 *     ENHTIM_InitStruct.ENHTIM_Period = 1000000 - 1 ;
 *     ENHTIM_InitStruct.ENHTIM_Mode = ENHTIM_Mode_UserDefine;
 *     ENHTIM_Init(ENHTIMER_NUM, &ENHTIM_InitStruct);
 * }
 * \endcode
 */
void ENHTIM_Init(ENHTIM_TypeDef *ENHTIMx, ENHTIM_InitTypeDef *ENHTIM_TimeBaseInitStruct);
/**
 * \brief Fill each ENHTIM_InitStruct member with its default value.
 *
 * \note The default settings for the ENHTIM_InitStruct member are shown in the following table:
 *       | ENHTIM_InitStruct member        | Default value                         |
 *       |:-------------------------------:|:-------------------------------------:|
 *       | ENHTIM_ClockSource              | \ref ENHTIM_CLOCK_SOURCE_40M          |
 *       | ENHTIM_ClockDiv_En              | DISABLE                               |
 *       | ENHTIM_ClockDiv                 | \ref ENHTIM_CLOCK_DIVIDER_1           |
 *       | ENHTIM_Mode                     | \ref ENHTIM_MODE_FreeRun              |
 *       | ENHTIM_PWMOutputEn              | DISABLE                               |
 *       | ENHTIM_PWMStartPolarity         | \ref ENHTIM_PWM_START_WITH_LOW        |
 *       | ENHTIM_OneShotEn                | DISABLE                               |
 *       | ENHTIM_LatchCountEn[0]          | DISABLE                               |
 *       | ENHTIM_LatchCountTrigger[0]     | \ref ENHTIM_LATCH_TRIGGER_RISING_EDGE |
 *       | ENHTIM_LatchCountEn[1]          | DISABLE                               |
 *       | ENHTIM_LatchCountTrigger[1]     | \ref ENHTIM_LATCH_TRIGGER_RISING_EDGE |
 *       | ENHTIM_LatchCountEn[2]          | DISABLE                               |
 *       | ENHTIM_LatchCountTrigger[2]     | \ref ENHTIM_LATCH_TRIGGER_RISING_EDGE |
 *       | ENHTIM_LatchCountThd            | 3                                     |
 *       | ENHTIM_LatchTriggerPad          | P0_0                                  |
 *       | ENHTIM_MaxCount                 | 0xFFFFFFFE                            |
 *       | ENHTIM_CCValue                  | 0x0                                   |
 *       | ENHTIM_PWMDeadZoneClockSource   | \ref ENHTIM_PWM_DZCLKSRCE_32K         |
 *       | ENHTIM_PWMDeadZone_ClockDivEn   | DISABLE                               |
 *       | ENHTIM_PWMDeadZone_ClockDiv     | \ref ENHTIM_CLOCK_DIVIDER_1           |
 *       | ENHTIM_PWMDeadZoneEn            | DISABLE                               |
 *       | ENHTIM_PWMStopStateP            | \ref ENHTIM_PWM_STOP_AT_HIGH          |
 *       | ENHTIM_PWMStopStateN            | \ref ENHTIM_PWM_STOP_AT_LOW           |
 *       | ENHTIM_DeadZoneSize             | 0xFF                                  |
 *       | ENHTIM_DmaEn                    | DISABLE                               |
 *       | ENHTIM_DmaTragget               | \ref ENHTIM_DMA_CCR_FIFO              |
 *
 * \param[in]   ENHTIM_InitStruct  Pointer to a ENHTIM_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_enhance_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);
 *
 *     ENHTIM_InitTypeDef ENHTIM_InitStruct;
 *     ENHTIM_StructInit(&ENHTIM_InitStruct);
 *
 *     ENHTIM_InitStruct.ENHTIM_PWM_En = PWM_DISABLE;
 *     ENHTIM_InitStruct.ENHTIM_Period = 1000000 - 1;
 *     ENHTIM_InitStruct.ENHTIM_Mode = ENHTIM_Mode_UserDefine;
 *     ENHTIM_Init(ENH_TIM0, &ENHTIM_InitStruct);
 * }
 * \endcode
 */
void ENHTIM_StructInit(ENHTIM_InitTypeDef *ENHTIM_InitStruct);
/**
 * \brief     Enable or disable the specified ENHTIMx peripheral.
 *
 * \param[in] ENHTIMx   Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] NewState  New state of the ENHTIMx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Count start.
 *                      - DISABLE: Count stop and clear count value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_enhance_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);
 *
 *     ENHTIM_InitTypeDef ENHTIM_InitStruct;
 *     ENHTIM_StructInit(&ENHTIM_InitStruct);
 *
 *     ENHTIM_InitStruct.ENHTIM_PWM_En = PWM_DISABLE;
 *     ENHTIM_InitStruct.ENHTIM_Period = 1000000 - 1;
 *     ENHTIM_InitStruct.ENHTIM_Mode = ENHTIM_Mode_UserDefine;
 *     ENHTIM_Init(ENH_TIM0, &ENHTIM_InitStruct);
 *     ENHTIM_Cmd(ENH_TIM0, ENABLE);
 * }
 * \endcode
 */
void ENHTIM_Cmd(ENHTIM_TypeDef *ENHTIMx, FunctionalState NewState);

/**
 * \brief     Enable or disable the specified ENHTIMx interrupt.
 *
 * \param[in] ENHTIMx     Select the specified ENHTIMx peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] ENHTIM_INT  Specify the ENHTIMx interrupt source which to be enabled or disabled. Refer to \ref ENHTIM_Interrupts.
 * \param[in] NewState    New state of the ENHTIMx peripheral.
 *                        This parameter can be one of the following values:
 *                        - ENABLE: Enable the specified interrupt.
 *                        - DISABLE: Disable the specified interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_enhance_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     ENHTIM_InitTypeDef ENHTIM_InitStruct;
 *     ENHTIM_StructInit(&ENHTIM_InitStruct);
 *
 *     ENHTIM_InitStruct.ENHTIM_PWM_En = PWM_DISABLE;
 *     ENHTIM_InitStruct.ENHTIM_Period = 1000000 - 1;
 *     ENHTIM_InitStruct.ENHTIM_Mode = ENHTIM_Mode_UserDefine;
 *     ENHTIM_Init(ENH_TIM0, &ENHTIM_InitStruct);
 *     ENHTIM_ClearINT(ENH_TIM0);
 *     ENHTIM_INTConfig(ENH_TIM0, ENABLE);
 * }
 * \endcode
 */
void ENHTIM_INTConfig(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT, FunctionalState NewState);

/**
 * \brief     Read ENHTIM latch count fifo data.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] length   Latch count0 fifo length, max 32.
 * \pBuf[out] pBuf     FIFO data out buffer.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint8_t length = ENHTIM_GetLatchCountFIFOLength(ENH_TIM0);
 * }
 * \endcode
 */
void ENHTIM_ReadLatchCountFIFO(ENHTIM_TypeDef *ENHTIMx, uint32_t *pBuf, uint8_t length);

/**
 * \brief     Get the specified ENHTIMx interrupt status.
 *
 * \param[in] ENHTIMx     Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] ENHTIM_INT  Specify the ENHTIMx interrupt source which to be enabled or disabled.
 *                        This parameter can be one of the following values, Refer to \ref ENHTIM_Interrupts.
 *                        \arg ENHTIM_INT_TIM: ENHTIM timeout interrupt.
 *                        \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
 *                        \arg ENHTIM_INT_LATCH_CNT_FIFO_EMPTY: Enhance Timer latch count0 fifo empty interrupt source.
 *                        \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
 *
 * \return    The status of the \ref ENHTIM_Interrupts.
 *            - SET: The specified ENHTIMx interrupt status is set.
 *            - RESET: The specified ENHTIMx interrupt status is reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_GetINTStatus(ENH_TIM0, ENHTIM_INT_TIM);
 * }
 * \endcode
 */
ITStatus ENHTIM_GetINTStatus(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT);

/**
 * \brief     Clear the specified ENHTIMx interrupt.
 *
 * \param[in] ENHTIMx     Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] ENHTIM_INT  Specify the ENHTIMx interrupt source which to be configured.
 *                        This parameter can be one of the following values, Refer to \ref ENHTIM_Interrupts.
 *                        - ENHTIM_INT_TIM: ENHTIM timeout interrupt.
 *                        - ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
 *                        - ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_ClearINTPendingBit(ENH_TIM0, ENHTIM_INT_TIM);
 * }
 * \endcode
 */
void ENHTIM_ClearINTPendingBit(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT);

/**
 * \brief     Get the specified ENHTIMx toggle state.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 *
 * \return    The status of the ENHTIM Toggle.
 *            - SET: The specified ENHTIMx Toggle status is set.
 *            - RESET: The specified ENHTIMx Toggle status is reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     bool State=ENHTIM_GetToggleState(ENHTIM0);
 * }
 * \endcode
 */
bool ENHTIM_GetToggleState(ENHTIM_TypeDef *ENHTIMx);

#if ENHTIM_SUPPORT_PWM_PHASE_SHIFT
/**
 * \brief  Change ENHTIM pwm_phase_shift count
 *
 * \param[in] ENHTIMx        Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] PhaseShiftCnt  This parameter specify the phase shift count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_PhaseShiftCnt(ENH_TIM0, 0);
 * }
 * \endcode
 */
void ENHTIM_PhaseShiftCnt(ENHTIM_TypeDef *ENHTIMx, uint32_t PhaseShiftCnt);
#endif

/**
 * \brief  Get the specified ENHTIMx current count.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 *
 * \return   The current count value.

 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_GetCurrentCount(ENH_TIM0);
 * }
 * \endcode
 */
uint32_t ENHTIM_GetCurrentCount(ENHTIM_TypeDef *ENHTIMx);

/**
 * \brief     Set the maximum count value.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] count    Maximum counter value for user-defined PWM mode (legal value: 0 to (2^{32} - 2)).
 *
 * \note      If it needs a dynamic change of MAX_CNT value, MAX_CNT has a minimum value limit.
 *            Ex. cpu_clk = 40MHz, ETIMER_CLK = 40MHz, then MAX_CNT should larger than 10.
 *            Ex. cpu_clk = 40MHz, ETIMER_CLK = 32kHz, then MAX_CNT should larger than 4.
 *            If in the state where ENHTIM is disabled, there is no such limitation.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_SetMaxCount(ENH_TIM0, 0x10000);
 * }
 * \endcode
 */
void ENHTIM_SetMaxCount(ENHTIM_TypeDef *ENHTIMx, uint32_t count);

/**
 * \brief     Set the capture/compare value for the user-define manual mode.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] value    User-defined ENHTIM capture/compare value for PWM manual mode,
 *                     ranging from 0 to 2^31.
 *
 * \note      If it needs a dynamic change of CCR value, CCR value has a minimum value limit.
 *            Ex. cpu_clk = 40MHz, ETIMER_CLK = 40MHz, then CCR value should larger than 10.
 *            Ex. cpu_clk = 40MHz, ETIMER_CLK = 32kHz, then CCR value should larger than 4.
 *            If in the state where ENHTIM is disabled, there is no such limitation.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_SetCCValue(ENH_TIM0, 0x1000);
 * }
 * \endcode
 */
void ENHTIM_SetCCValue(ENHTIM_TypeDef *ENHTIMx, uint32_t value);

/**
 * \brief     Set the capture/compare value for the user-define auto mode.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] value    User-defined ENHTIM capture/compare value for PWM manual mode,
 *                     ranging from 0 to 2^31.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_WriteCCFIFO(ENH_TIM0,0x10000);
 * }
 * \endcode
 */
void ENHTIM_WriteCCFIFO(ENHTIM_TypeDef *ENHTIMx, uint32_t value);

/**
 * \brief     Get the specified ENHTIM FIFO flag status.
 *
 * \param[in] ENHTIMx      Where x can be 0 to 7 to select the ENHTIMx peripheral.
 * \param[in] ENHTIM_FLAG  Specify the flag to check.
 *                         This parameter can be one of the following values, Refer to \ref ENHTIM_Flag.
 *                         \arg ENHTIM_FLAG_LC_FIFO_EMPTY: FIFO empty or not. If SET, LC FIFO is empty.
 *                         \arg ENHTIM_FLAG_LC_FIFO_FULL: FIFO full or not. If SET, LC FIFO is full.
 *                         \arg ENHTIM_FLAG_CCR_FIFO_EMPTY: FIFO empty or not. If SET, CCR FIFO is empty.
 *                         \arg ENHTIM_FLAG_CCR_FIFO_FULL: FIFO full or not. If SET, CCR FIFO is full.
 *
 * \return  The status of \ref ENHTIM_Flag.
 *          - SET: The specified ENHTIM flag is set.
 *          - RESET: The specified ENHTIM flag is reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     FlagStatus flag_status = ENHTIM_GetFIFOFlagStatus(ENH_TIM0, ENHTIM_FLAG_LC_FIFO_EMPTY);
 * }
 * \endcode
 */
FlagStatus ENHTIM_GetFIFOFlagStatus(ENHTIM_TypeDef *ENHTIMx, uint32_t ENHTIM_FLAG);

/**
 * \brief     Enable the specified ENHTIMx latch counter.
 *
 * \param[in] ENHTIMx      Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] LatchCntIdx  E_ENHTIM_LATCHCNT enum value.
 *                         This parameter can be one of the following values, Refer to \ref ENHTIM_Latch_Channel_Count.
 *                         - LATCH_CNT_0: Enhance timer latch count 0.
 *                         - LATCH_CNT_1: Enhance timer latch count 1.
 *                         - LATCH_CNT_2: Enhance timer latch count 2.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_LatchCountEnable(ENH_TIM0, LATCH_CNT_0);
 * }
 * \endcode
 */
void ENHTIM_LatchCountEnable(ENHTIM_TypeDef *ENHTIMx,
                             ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Disable the specified ENHTIMx latch counter.
 *
 * \param[in] ENHTIMx      Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] LatchCntIdx  E_ENHTIM_LATCHCNT enum value.
 *                         This parameter can be one of the following values, Refer to \ref ENHTIM_Latch_Channel_Count.
 *                         - LATCH_CNT_0: Enhance timer latch count 0.
 *                         - LATCH_CNT_1: Enhance timer latch count 1.
 *                         - LATCH_CNT_2: Enhance timer latch count 2.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_LatchCountDisable(ENH_TIM0, LATCH_CNT_0);
 * }
 * \endcode
 */
void ENHTIM_LatchCountDisable(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Get the specified ENHTIMx latch count value.
 *
 * \param[in] ENHTIMx      Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] LatchCntIdx  E_ENHTIM_LATCHCNT enum value.
 *                         This parameter can be one of the following values, Refer to \ref ENHTIM_Latch_Channel_Count.
 *                         - LATCH_CNT_0: Enhance timer latch count 0.
 *                         - LATCH_CNT_1: Enhance timer latch count 1.
 *                         - LATCH_CNT_2: Enhance timer latch count 2.
 *
 * \return    The latch counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint32_t count_value = ENHTIM_GetLatchCountValue(ENH_TIM0, LATCH_CNT_0);
 * }
 * \endcode
 */
uint32_t ENHTIM_GetLatchCount(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Get the specified ENHTIMx latch count fifo length.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 *
 * \return    FIFO data length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint8_t length = ENHTIM_GetLatchCountFIFOLength(ENH_TIM0);
 * }
 * \endcode
 */
uint8_t ENHTIM_GetLatchCountFIFOLength(ENHTIM_TypeDef *ENHTIMx);

/**
 * \brief     Clear the capture/compare or latch count FIFO.
 *
 * \param[in] ENHTIMx   Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] FIFO_CLR  Specify the FIFO type which to be clear.
 *                      This parameter can be one of the following values, Refer to \ref ENHTIM_FIFO_Clear.
 *                      - ENHTIM_FIFO_CLR_CCR: Enhance Timer CCR FIFO clear flag.
 *                      - ENHTIM_FIFO_CLR_CNT0: Enhance Timer latch count2 FIFO clear flag.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_ClearFIFO(ENH_TIM0, ENHTIM_FIFO_CLR_CCR);
 * }
 * \endcode
 */
void ENHTIM_ClearFIFO(ENHTIM_TypeDef *ENHTIMx, uint8_t FIFO_CLR);

/**
 * \brief   ENHTIM PWM complementary output emergency stop.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_PWMDeadZoneEMStop(ENH_TIM0);
 * }
 * \endcode
 */
void ENHTIM_PWMDeadZoneEMStop(ENHTIM_TypeDef *ENHTIMx);

#if ENHTIM_SUPPORT_PWM_SRC_SELECT
/**
 * \brief   ENHTIM PWMP/N Source Select.
 *
 * \param[in] ENHTIMx    Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] PWMSrcSel  PWMP/N reference selection. The actual output waveforms of the P and N in complementary PWM mode.
 *                       This parameter can be one of the following values, Refer to \ref ENHPWM_Reference_Selection.
 *                       - ENHTIM_DZ_REF_PWMPN: PWM P waveform is PWM_P, PWM N waveform is PWM_N,
 *                       - ENHTIM_DZ_REF_PWMNN: PWM P waveform is PWM_N, PWM N waveform is PWM_N,
 *                       - ENHTIM_DZ_REF_PWMPP: PWM P waveform is PWM_P, PWM N waveform is PWM_P,
 *                       - ENHTIM_DZ_REF_PWMNP: PWM P waveform is PWM_N, PWM N waveform is PWM_P,
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_PWMSrcSelect(ENH_TIM0, ENHTIM_DZ_REF_PWMPN)
 * }
 * \endcode
 */
void ENHTIM_PWMSrcSelect(ENHTIM_TypeDef *ENHTIMx, ENHTIMPWMDZRef_TypeDef PWMSrcSel);
#endif

/**
 * \brief     Get all the ENHTIM interrupt status.
 *
 * \return    All Status of the ENHTIM interrupts.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ITStatus int_status = ENHTIM_GetAllINTStatus();
 * }
 * \endcode
 */
uint32_t ENHTIM_GetAllINTStatus(void);

#if ENHTIM_SUPPORT_ONESHOT_CMD
/**
 * \brief  Enable or disable the specified ENHTIMx oneshot mode.
 *
 * \param[in] ENHTIMx   Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in] NewState  New state of the ENHTIMx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: The timer only triggers the timing function once.
 *                      - DISABLE: Disable the oneshot mode function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_OneShotCmd(ENH_TIM0, ENABLE);
 * }
 * \endcode
 */
void ENHTIM_OneShotCmd(ENHTIM_TypeDef *ENHTIMx, FunctionalState NewState);
#endif

/**
 * \brief  Get the ENHTIM latch count0 FIFO status.
 *
 * \param[in] ENHTIMx  Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 *
 * \return   The status of the specified ENHTIMx latch count0 FIFO.
 *           - SET: ENHTIM latch count0 FIFO has data.
 *           - RESET: ENHTIM latch count0 FIFO has no data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_GetLCFIFOStatus(ENH_TIM0);
 * }
 * \endcode
 */
ITStatus ENHTIM_GetLCFIFOStatus(ENHTIM_TypeDef *ENHTIMx);

/**
 * \brief  Change the specified ENHTIMx PWM frequency and duty cycle.
 *
 * \param[in]  ENHTIMx      Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in]  ENHTIM_mode  This parameter can be ENHTIM_MODE_PWM_MANUAL or ENHTIM_MODE_PWM_AUTO.
 * \param[in]  max_count    Timer max counter value for user-define mode.
 *                          This parameter can be 1 ~ 2^32-2
 * \param[in]  high_count   Timer capture/compare value for user-define manual mode.
 *                          Timer capture/compare fifo entry for user-define auto mode.
 *                          This parameter can be 0 ~ 2^32-2
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     ENHTIM_PWMChangeFreqAndDuty(ENH_TIM0, ENHTIM_MODE_PWM_MANUAL, 1000, 100);
 * }
 * \endcode
 */
void ENHTIM_PWMChangeFreqAndDuty(ENHTIM_TypeDef *ENHTIMx, uint16_t ENHTIM_mode, uint32_t max_count,
                                 uint32_t high_count);

#if ENHTIM_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * \brief  ENHTIM clock config.
 *
 * \param[in]  ENHTIMx   Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[in]  ClockSrc  Specify the ENHTIM clock source.  Refer to \ref ENHTIM_Clock_Source.
 * \param[in]  ClockDiv  Specify the ENHTIM clock source divider. Refer to \ref ENHTIM_Clock_Divider.
 *
 */
void ENHTIM_ClkConfig(ENHTIM_TypeDef *ENHTIMx, ENHTIMClkSrc_TypdDef ClockSrc,
                      ENHTIMClkDiv_TypeDef ClockDiv);

/**
 * \brief  Get ENHTIM clock config.
 *
 * \param[in]  ENHTIMx    Select the ENHTIM peripheral. Refer to \ref ENHTIM_Declaration.
 * \param[out]  ClockSrc  Specify the ENHTIM clock source. Refer to \ref ENHTIM_Clock_Source.
 * \param[out]  ClockDiv  Specify the ENHTIM clock source divider. Refer to \ref ENHTIM_Clock_Divider.
 *
 * \return   The status of the ENHTIM clock configuration .
 *           - TRUE: get clock configuration successful.
 *           - FALSE: get clock configuration false.
 */
bool ENHTIM_ClkGet(ENHTIM_TypeDef *ENHTIMx, ENHTIMClkSrc_TypdDef *ClockSrc,
                   ENHTIMClkDiv_TypeDef *ClockDiv);
#endif

/** End of ENHTIM_Exported_Functions
  * \}
  */

/** End of ENHTIM
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_ENH_TIM_H */
