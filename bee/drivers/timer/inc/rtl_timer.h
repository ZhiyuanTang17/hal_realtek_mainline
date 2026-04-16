/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_TIMER_H
#define RTL_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "timer/src/device/rtl87x2g/rtl_timer_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "timer/src/device/rtl87x3e/rtl_timer_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "timer/src/device/rtl87x3d/rtl_tim_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "timer/src/device/rtl87x2j/rtl_timer_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "timer/src/device/rtl87x3j/rtl_timer_def.h"
#include "timer/src/device/rtl87x3j/rtl_timer_cc.h"
#endif

/** \defgroup TIMER         TIMER
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup TIMER_Exported_Constants TIMER Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    TIMER_Mode TIMER Mode
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
#if (TIMER_SUPPORT_FREERUN_MODE == 1)
    TIMER_MODE_FREERUN,
#endif
    TIMER_MODE_USERDEFINE = 0x2,
#if (TIMER_SUPPORT_USERDEFINE_AUTO_MODE == 1)
    TIMER_MODE_USERDEFINE_AUTO = 0x1,
#endif
} TIMERMode_TypeDef;

#define IS_TIMER_MODE(MODE) (((MODE) == TIMER_MODE_FREERUN) || \
                             ((MODE) == TIMER_MODE_USERDEFINE) || \
                             ((MODE) == TIMER_MODE_USERDEFINE_AUTO))

/** End of TIMER_Mode
  * \}
  */

#if (TIMER_SUPPORT_DIRECTION == 1)
/**
 * \defgroup    TIMER_Direction TIMER Direction
 * \{
 * \ingroup     TIMER_Exported_Constants
 */

typedef enum
{
    TIMER_DIRECTION_UP_COUNTING = 0x0,
    TIMER_DIRECTION_DOWN_COUNTING = 0x1,
} TIMERDirection_TypeDef;

#define IS_TIMER_Direction(DIRECTION) (((DIRECTION) == TIMER_DIRECTION_UP_COUNTING) || \
                                       ((DIRECTION) == TIMER_DIRECTION_DOWN_COUNTING))

/** End of TIMER_Direction
  * \}
  */
#endif

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
/**
 * \defgroup    PWM_Polarity PWM Polarity
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_POLARITY_LOW = 0x00,
    PWM_POLARITY_HIGH = 0x01,
} PWMPolarity_TypeDef;

#define IS_PWM_POLARITY(POL) (((POL) == PWM_POLARITY_LOW) || \
                              ((POL) == PWM_POLARITY_HIGH))

/** End of PWM_Polarity
  * \}
  */

/**
 * \defgroup    PWM_Output_Mode PWM Output Mode
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_PUSH_PULL = 0x0,
    PWM_OPEN_DRAIN = 0x1,
}
PWMOutputMode_TypeDef;

#define IS_PWM_OUTPUT_MODE(MODE) (((MODE) == PWM_PUSH_PULL) || \
                                  ((MODE) == PWM_OPEN_DRAIN))

/** End of PWM_Output_Mode
  * \}
  */

#if (TIMER_SUPPORT_PWM_MODE == 1)
/**
 * \defgroup    PWM_Mode PWM Mode
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_MODE_OUTPUT_HIGH_CNT_BELOW_CMP = 0x0,
    PWM_MODE_OUTPUT_LOW_CNT_BELOW_CMP = 0x1,
    PWM_MODE_FIX_LOW = 0x2,
    PWM_MODE_FIX_HIGH = 0x3,
} PWMMode_TypeDef;

#define IS_PWM_MODE(MODE)    (((MODE) == PWM_MODE_OUTPUT_HIGH_CNT_BELOW_CMP) || \
                              ((MODE) == PWM_MODE_OUTPUT_LOW_CNT_BELOW_CMP) || \
                              ((MODE) == PWM_MODE_FIX_LOW) || \
                              ((MODE) == PWM_MODE_FIX_HIGH))

/** End of PWM_Mode
  * \}
  */
#endif

#if (TIMER_SUPPORT_PWM_STOP_STATE_CONTROL == 1)
/**
 * \defgroup    PWM_Stop_State PWM Stop State
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_STOP_STATE_POLARITY_CONTROLLED = 0x0,
    PWM_STOP_STATE_KEEP_LAST = 0x1,
} PWMStopState_TypeDef;

#define IS_PWM_STOP_STATE(STATE) (((STATE) == PWM_STOP_STATE_POLARITY_CONTROLLED) || \
                                  ((STATE) == PWM_STOP_STATE_KEEP_LAST))

/** End of PWM_Stop_State
  * \}
  */
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
/**
 * \defgroup    PWM_DeadZone_Stop_State PWM DeadZone Stop State
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_DZ_STOP_AT_LOW = 0x0,
    PWM_DZ_STOP_AT_HIGH = 0x1,
} PWMDZStopState_TypeDef;

#define IS_PWM_DEADZONE_STOP_STATE(STATE) (((STATE) == PWM_DZ_STOP_AT_LOW) || \
                                           ((STATE) == PWM_DZ_STOP_AT_HIGH))

/** End of PWM_DeadZone_Stop_State
  * \}
  */

#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
/**
 * \defgroup    PWM_DeadZone_Reference PWM DeadZone Reference
 * \{*
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    PWM_DZ_REF_PWMPN = 0x0,
    PWM_DZ_REF_PWMNN = 0x1,
    PWM_DZ_REF_PWMPP = 0x2,
    PWM_DZ_REF_PWMNP = 0x3,
} PWMDZRef_TypeDef;

#define IS_PWM_DEADZONE_REFERENCE(STATE) (((STATE) == PWM_DZ_REF_PWMPN) || \
                                          ((STATE) == PWM_DZ_REF_PWMNN) || \
                                          ((STATE) == PWM_DZ_REF_PWMPP) || \
                                          ((STATE) == PWM_DZ_REF_PWMNP))

/** End of PWM_DeadZone_Reference
  * \}
  */
#endif
#endif
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * \defgroup    TIMER_Latch_Trigger_Mode TIMER Latch Trigger Mode
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_LATCH_TRIGGER_RISING_EDGE = 0x00,
    TIMER_LATCH_TRIGGER_FALLING_EDGE = 0x01,
    TIMER_LATCH_TRIGGER_BOTH_EDGE = 0x02,
} TIMERLatchTriggerMode_TypeDef;

#define IS_TIMER_LATCH_TRIGGER_MODE(MODE) (((MODE) == TIMER_LATCH_TRIGGER_RISING_EDGE) || \
                                           ((MODE) == TIMER_LATCH_TRIGGER_FALLING_EDGE) || \
                                           ((MODE) == TIMER_LATCH_TRIGGER_BOTH_EDGE))

/** End of TIMER_Latch_Trigger_Mode
  * \}
  */
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
/**
 * \defgroup    TIMER_DMA_TARGET TIMER DMA TARGET
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_DMA_CCR_FIFO = 0x00,
    TIMER_DMA_LATCH_FIFO = 0x01,
} TIMERDMATarget_TypeDef;

#define IS_TIMER_DMA_TARGET(MODE) (((MODE) == TIMER_DMA_CCR_FIFO) || \
                                   ((MODE) == TIMER_DMA_LATCH_FIFO))

/** End of TIMER_DMA_TARGET
  * \}
  */
#endif

/**
 * \defgroup    TIMER_Interrupts TIMER Interrupts
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
#define TIMER_INT_TIMEOUT                        (1 << 0)
#define TIMER_INT_PAUSE                          (1 << 1)
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
#define TIMER_INT_LATCH_FIFO_FULL                (1 << 2)
#define TIMER_INT_LATCH_FIFO_THRESHOLD           (1 << 3)
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
#define IS_TIMER_INT(INT) (((INT) == TIMER_INT_TIMEOUT) || \
                           ((INT) == TIMER_INT_PAUSE)  || \
                           ((INT) == TIMER_INT_LATCH_FIFO_FULL)   || \
                           ((INT) == TIMER_INT_LATCH_FIFO_THRESHOLD))
#else
#define IS_TIMER_INT(INT) (((INT) == TIMER_INT_TIMEOUT) || \
                           ((INT) == TIMER_INT_PAUSE))
#endif

/** End of TIMER_Interrupts
  * \}
  */

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * \defgroup    TIMER_Flag TIMER Flag
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
#define TIMER_FLAG_CCR_FIFO_EMPTY                (0)
#define TIMER_FLAG_CCR_FIFO_FULL                 (1)
#define TIMER_FLAG_LATCH_FIFO_EMPTY              (2)
#define TIMER_FLAG_LATCH_FIFO_FULL               (3)
#define TIMER_FLAG_LATCH_FIFO_THRESHOLD          (4)

#define IS_TIMER_FLAG(flag) (((flag) == TIMER_FLAG_CCR_FIFO_FULL) || \
                             ((flag) == TIMER_FLAG_CCR_FIFO_EMPTY) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_EMPTY) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_FULL) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_THRESHOLD))

/** End of TIMER_Flag
  * \}
  */

/**
 * \defgroup    TIMER_Clear_FIFO TIMER Clear FIFO
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
#define TIMER_CLEAR_CCR_FIFO                     (0)
#define TIMER_CLEAR_LATCH_FIFO                   (1)

/** End of TIMER_Clear_FIFO
  * \}
  */
#endif

#if (TIMER_SUPPORT_RAP_FUNCTION == 1)

/**
 * \defgroup    TIMER_Action TIMER Action
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_ACTION_START            = 0,
    TIMER_ACTION_PAUSE            = 1,
    TIMER_ACTION_STOP             = 2,
} TIMERAction_TypeDef;

/** End of TIMER_Action
 * \}
 */

/**
 * \defgroup    TIMER_Shortcut_Action TIMER Shortcut Action
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_SHORTCUT_ACTION_PAUSE = 1,
    TIMER_SHORTCUT_ACTION_STOP  = 2,
} TIMERShortcutAction_TypeDef;

/** End of TIMER_Shortcut_Action
 * \}
 */

/**
 * \defgroup    TIMER_Shortcut_Event TIMER Shortcut Event
 * \{
 * \ingroup     TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_SHORTCUT_EVENT_TIMEOUT = 0,
} TIMERShortcutEvent_TypeDef;

/** End of TIMER_Shortcut_Event
 * \}
 */
#endif

/** End of TIMER_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup TIMER_Exported_Types TIMER Exported Types
  * \brief
  * \{
  */

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
/**
 * \brief       TIMER init structure definition.
 *
 * \ingroup     TIMER_Exported_Types
 */
typedef struct
{
    PWMDZClockSrc_TypeDef PWM_DZClockSrc;     /*!< Specifies the pwm deazone clock source. */

    PWMDZClockDiv_TypeDef PWM_DZClockDiv;     /*!< Specifies the pwm deazone clock divide. */

    uint32_t PWM_DZSize;                      /*!< Specifies the pwm deazone Size.
                                                   DeadzoneTime = deadzonesize / (32000 or 32768).
                                                   This parameter must range from 1 to 0xff. */

    FunctionalState PWM_DZEn;                 /*!< Specifies the pwm deazone enable.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    PWMDZStopState_TypeDef PWM_DZStopStateP;  /*!< Specifies the PWM deazone P stop state. */

    PWMDZStopState_TypeDef PWM_DZStopStateN;  /*!< Specifies the PWM deazone N stop state. */

#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
    FunctionalState PWM_DZInvertP;            /*!< Specifies ENHTIMER invertion of pwm_p.
                                                   This parameter can be a value of PWM Reference */

    FunctionalState PWM_DZInvertN;            /*!< Specifies ENHTIMER invertion of pwm_n.
                                                   This parameter can be a value of PWM Reference */
#endif
} PWMDeadZone_TypeDef;
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
typedef struct
{
    FunctionalState TIMER_LatchEn[3];         /*!< Enable or disable TIMER latch function.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    uint16_t        TIMER_LatchThreshold;     /*!< Specifies TIMER latched count fifo threshold.
                                                   This parameter can be value of 0~8. */

    TIMERLatchTriggerMode_TypeDef TIMER_LatchTriggerMode[3]; /*!< Specifies TIMER latch
                                                   trigger mode. This parameter can be a
                                                   value of /ref TIMERLatchTriggerMode_TypeDef. */


    uint16_t        TIMER_LatchTriggerPad;    /*!< Specifies the TIMER latch trigger pad.
                                                   This parameter can be a value of P0_0 to P19_0. */

    FunctionalState TIMER_LatchDebEn;         /*!< Enable or disable TIMER latch debounce function.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    TIMERClockDiv_TypeDef TIMER_LatchDebClockDiv; /*!< Specifies the TIMER latch debounce
                                                   clock div.This parameter can be a value
                                                   of /ref TIMERClockDiv_TypeDef. */

    uint16_t       TIMER_LatchDebCountLimit;  /*!< Specifies the TIMER latch debounce count limit.
                                                   This parameter must range from 0 to 65535. */
} TIMERLatch_TypeDef;
#endif

typedef struct
{
    TIMERClockSrc_TypeDef TIMER_ClockSrc;   /*!< Specifies the clock source. */

    TIMERClockDiv_TypeDef TIMER_ClockDiv;   /*!< Specifies the clock source div.
                                                 This parameter can be a value of TIMER_Clock_Divider. */

    TIMERMode_TypeDef TIMER_Mode;           /*!< Specifies the operating mode. */

#if (TIMER_SUPPORT_DIRECTION == 1)
    TIMERDirection_TypeDef TIMER_Direction; /*!< Specifies the timer direction. */
#endif

    uint32_t TIMER_Period;                  /*!< Specifies the period value to be loaded into the active
                                                 Auto-Reload Register at the next update event.
                                                 This parameter must range from 0x0 to 0xFFFFFFFF.
                                                 period = PWM_HighCount + PWM_LowCount */

    FunctionalState TIMER_OneShotEn;        /*!< Specifies the one shot mode. */

#if (TIMER_SUPPORT_PERIOD_IMMEDIATELY_UPDATE == 1)
    FunctionalState
    TIMER_PeriodImmediatelyUpdateEn;    /*!< Enable or disable immediately update period.
                                                             This parameter can be a value of ENABLE or DISABLE. */
#endif

#if (TIMER_SUPPORT_TOGGLE_OUTPUT == 1)
    FunctionalState TIMER_ToggleOutputEn;   /*!< Enable or disable timer toggle output.
                                                 This parameter can be a value of ENABLE or DISABLE. */
#endif

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
    FunctionalState PWM_En;                 /*!< Specifies the PWM mode.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    uint32_t PWM_HighCount;                 /*!< Specifies the PWM High Count.
                                                This parameter must range from 0x0 to 0xFFFFFFFF. */

    PWMPolarity_TypeDef PWM_Polarity;       /*!< Specifies enhtimer toggle output polarity
                                                 for user-define PWM mode.*/

    PWMOutputMode_TypeDef PWM_OutputMode;   /*!< Specifies enable PWM open drain. */

#if (TIMER_SUPPORT_PWM_MODE == 1)
    PWMMode_TypeDef PWM_Mode;       /*!< Specifies PWM mode.
                                         This parameter can be a value of /ref PWM_Mode. */
#endif

#if (TIMER_SUPPORT_PWM_STOP_STATE_CONTROL == 1)
    PWMStopState_TypeDef PWM_StopState;     /*!< Specifies enable PWM stop state.
                                                 This parameter can be a value of /ref PWM_Stop_State. */
#endif
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
    PWMDeadZone_TypeDef PWM_DZ;             /*!< Specifies PWM Dead Zone. */
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
    TIMERLatch_TypeDef TIMER_Latch;        /*!< Specifies TIMER Latch Count. */
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
    FunctionalState TIMER_DMAEn;            /*!< Specifies enable TIMER DMA.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    TIMERDMATarget_TypeDef TIMER_DMATarget; /*!< Specifies TIMER DMA target. */
#endif

#if (TIMER_COMPARE_CHANNEL_NUM > 0)
    TIMERCompare_TypeDef TIMER_Compare;     /*!< Specifies timer compare. */
#endif

#if (TIMER_CAPTURE_CHANNEL_NUM > 0)
    TIMERCapture_TypeDef TIMER_Capture;        /*!< Specifies TIMER Latch Count. */
#endif

#if (TIMER_SUPPORT_CC_FIFO == 1)
    TIMERCCFIFO_TypeDef TIMER_CCFIFO;       /*!< Specifies timer CC FIFO. */
#endif

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)
    FunctionalState TIMER_DynConfigEn;      /*!< Specifies the functon to dynamic adjustment of
                                                    CCR & MAX_CNT.  When this feature is enabled,
                                                    dynamic adjustment is supported. When this feature
                                                    is disabled, dynamic adjustment is not supported,
                                                    resulting in lower power consumption.*/
#endif
} TIMER_TimeBaseInitTypeDef;

/** End of TIMER_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup TIMER_Exported_Functions TIMER Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitialize the TIMERx peripheral registers to their default reset values.
 *
 * \return  None.
 */
void TIMER_DeInit(TIMER_TypeDef *TIMERx);

/**
 * \brief   Initialize the TIMERx time base unit peripheral according to
 *          the specified parameters in TIMER_InitStruct.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in] TIMER_InitStruct: Pointer to a TIMER_TimeBaseInitTypeDef
 *            structure that contains the configuration information for the selected TIMER peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1 ;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_Mode_UserDefine;
 *     TIMER_TimeBaseInit(TIMER6, &TIMER_InitStruct);
 * }
 * \endcode
 */
void TIMER_TimeBaseInit(TIMER_TypeDef *TIMERx, TIMER_TimeBaseInitTypeDef *TIMER_InitStruct);

/**
 * \brief   Fills each TIMER_InitStruct member with its default value.
 *
 * \param[in] TIMER_InitStruct: Pointer to a TIMER_TimeBaseInitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_Mode_UserDefine;
 *     TIMER_TimeBaseInit(TIMER6, &TIMER_InitStruct);
 * }
 * \endcode
 */
void TIMER_StructInit(TIMER_TimeBaseInitTypeDef *TIMER_InitStruct);

/**
 * \brief   Enables or disables the specified TIMER peripheral.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in] NewState: New state of the TIMERx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_Mode_UserDefine;
 *     TIMER_TimeBaseInit(TIMER6, &TIMER_InitStruct);
 *     TIMER_Cmd(TIMER6, ENABLE);
 * }
 * \endcode
 */
void TIMER_Cmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

#if (TIMER_SUPPORT_CLEAR_COUNTER == 1)
/**
 * \brief   Clear counter of the specified TIMER peripheral.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  None.
 *
 */
void TIMER_ClearCounter(TIMER_TypeDef *TIMERx);
#endif

/**
 * \brief       Enables or disables the specified TIMERx interrupt.
 *
 * \param[in]   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in]   NewState: New state of the TIMERx peripheral.
 *              This parameter can be: ENABLE or DISABLE.
 *
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_Mode_UserDefine;
 *     TIMER_TimeBaseInit(TIMER6, &TIMER_InitStruct);
 *     TIMER_ClearINT(TIMER6);
 *     TIMER_INTConfig(TIMER6, ENABLE);
 */
void TIMER_INTConfig(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT, FunctionalState NewState);


/**
 * \brief   Check whether the TIMER interrupt has occurred or not.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  The new state of the TIMER_IT(SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus int_status = TIMER_GetINTStatus(TIMER6);
 * }
 * \endcode
 */
ITStatus TIMER_GetINTStatus(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT);

/**
 * \brief   Clear TIMER interrupt.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIMER_ClearINT(TIMER6);
 * }
 * \endcode
 */
void TIMER_ClearINT(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT);

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1) || (TIMER_SUPPORT_CC_FIFO == 1)
/**
  * \brief  Check whether the specified TIMER flag is set.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  TIMER_FLAG: Specifies the flag to check.
  * \return The new state of TIMER_FLAG (SET or RESET).
  */
FlagStatus TIMER_GetFIFOFlagStatus(TIMER_TypeDef *TIMERx, uint32_t TIMER_FLAG);
#endif

/**
 * \brief       Change TIMER period value.
 *
 * \param[in]   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in]   period: Period value to be changed.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t new_period = 1000000 - 1;
 *     TIMER_Cmd(TIMER6, DISABLE);
 *     TIMER_ChangePeriod(TIMER6, new_period);
 *
 * }
 * \endcode
 */
void TIMER_ChangePeriod(TIMER_TypeDef *TIMERx, uint32_t period);

/**
 * \brief   Get TIMERx period value.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  TIMER period value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t period = TIMER_GetPeriod(TIMER6);
 * }
 * \endcode
 */
uint32_t TIMER_GetPeriod(TIMER_TypeDef *TIMERx);

/**
 * \brief   Get TIMERx current value when timer is running.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t cur_value = TIMER_GetCurrentValue(TIMER6);
 * }
 * \endcode
 */
uint32_t TIMER_GetCurrentValue(TIMER_TypeDef *TIMERx);

/**
 * \brief Get TIMERx elapsed value when timer is running.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return The elapsed counter value.
 */
uint32_t TIMER_GetElapsedValue(TIMER_TypeDef *TIMERx);

/**
 * \brief   Check whether the TIMER is in operation or not.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 *
 * \return  The new state of the timer operation status (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus intstatus = TIMER_GetOperationStatus(TIMER6);
 * }
 * \endcode
 */
FlagStatus TIMER_GetOperationStatus(TIMER_TypeDef *TIMERx);

/**
  * \brief  Enable/disable to pause timer counter.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  NewState: New state of the TIMERx peripheral.
  * \return None.
  */
void TIMER_PauseCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

#if (TIMER_SUPPORT_CCR_FIFO == 1) || (TIMER_SUPPORT_CC_FIFO == 1)
/**
  * \brief  Write TIMERx compare FIFO.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  value: Value to be written to compare FIFO.
  * \return None
  */
void TIMER_SetCompareFIFO(TIMER_TypeDef *TIMERx, uint32_t value);
#endif

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Clear capture/compare or latch count0 fifo.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  FIFO_CLR: Specifies the FIFO type which to be clear.
  * \return FIFO data length.
  */
void TIMER_ClearFIFO(TIMER_TypeDef *TIMERx, uint8_t FIFO_CLR);
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Read TIMERx latch counter0 fifo data.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  length: Latch count0 fifo length, max 8.
  * \pBuf   pBuf: FIFO data out buffer.
  * \return None.
  */
void TIMER_GetLatchFIFO(TIMER_TypeDef *TIMERx, uint32_t *pBuf, uint8_t length);

/**
  * \brief  Get TIMER latch counter0 fifo length.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return FIFO data length.
  */
uint8_t TIMER_GetLatchFIFOLength(TIMER_TypeDef *TIMERx);
#endif

/**
  * \brief  Get TIMER toggle state
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return The new state of toggle state(SET or RESET).
  */
bool TIMER_GetToggleState(TIMER_TypeDef *TIMERx);

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
/**
 * \brief   Change PWM freq and duty according high_cnt and low_cnt
 *
 * \param[in]   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in]   high_count: This parameter can be 0x00~0xFFFFFFFF.
 * \param[in]  low_count: This parameter can be 0x00~0xFFFFFFFF.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define TIMER_DEMO TIMERB_6
 *
 * void timer_demo(void)
 * {
 *     uint32_t high_count = 1000000 - 1;
 *     uint32_t low_count = 1000000 - 1;
 *     TIMER_Cmd(TIMER_DEMO, DISABLE);
 *     TIMER_ChangePeriod(TIMER_DEMO, high_count, low_count);
 * }
 * \endcode
 */
void TIMER_PWMChangeFreqAndDuty(TIMER_TypeDef *TIMERx, uint32_t period, uint32_t high_count);

#if (TIMER_SUPPORT_PWM_PHASE_SHIFT == 1)
/**
 * \brief  Change TIMER pwm_phase_shift count
 * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param  ShiftCount:This parameter can be 0 to ccr;
 * \return None
 */
void TIMER_SetShiftCount(TIMER_TypeDef *TIMERx, uint32_t ShiftCount);
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
/**
 * \brief  TIMER PWMP/N Source Select.
 * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param  PWMDZRefcSel: State of the TIMERx PWMP/N.
 * \return None.
 */
void TIMER_SetPWMDZRef(TIMER_TypeDef *TIMERx, PWMDZRef_TypeDef PWMDZRef);
#endif

/**
 * \brief   PWM complementary output emergency stop and resume.
 *          PWM_P emergency stop level state is configured by PWM_Stop_State_P,
 *          PWM_N emergency stop level state is configured by PWM_Stop_State_N.
 *
 * \param[in] PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param[in] NewState: New state of complementary output.
 *            \ref DISABLE: Resume PWM complementary output.
 *            \ref ENABLE: PWM complementary output emergency stop.
 *
 * \return  None.
 * \note    To use this function, need to configure the corresponding timer.
 *          PWM2 ->> TIMER2, PWM3 ->> TIMER3.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_pwm_init(void)
 * {
 *     Pad_Config(P0_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE, PAD_OUT_HIGH);
 *     Pad_Config(P0_2, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE,
 *                PAD_OUT_HIGH);
 *     Pad_Config(P2_2, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE,
 *                PAD_OUT_HIGH);
 *
 *     Pinmux_Config(P0_1, PWM_OUT_PIN_PINMUX);
 *     Pinmux_Config(P0_2, PWM_OUT_P_PIN_PINMUX);
 *     Pinmux_Config(P2_2, PWM_OUT_N_PIN_PINMUX);
 * }
 *
 * void driver_pwm_init(void)
 * {
 *     RCC_ClockCmd(TIMER_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_Mode             = TIMER_Mode_UserDefine;
 *     TIMER_InitStruct.TIMER_PWM_En           = ENABLE;
 *     TIMER_InitStruct.TIMER_PWM_High_Count   = PWM_HIGH_COUNT;
 *     TIMER_InitStruct.TIMER_PWM_Low_Count    = PWM_LOW_COUNT;
 *     TIMER_InitStruct.PWM_Stop_State_P     = PWM_STOP_AT_HIGH;
 *     TIMER_InitStruct.PWM_Stop_State_N     = PWM_STOP_AT_LOW;
 *     TIMER_InitStruct.PWMDeadZone_En       = ENABLE;  //enable to use pwn p/n output
 *     TIMER_InitStruct.PWM_Deazone_Size     = 255;
 *     TIMER_TimeBaseInit(PWM2, &TIMER_InitStruct);
 *
 *     TIMER_Cmd(PWM2, ENABLE);
 * }
 *
 * void pwm_demo(void)
 * {
 *    board_pwm_init();
 *    driver_pwm_init();
 *    //Add delay.
 *    TIMER_PWMComplOutputEMCmd(PWM2,ENABLE);
 * }
 * \endcode
 */
void TIMER_PWMComplOutputEMCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);
#endif
#endif

/**
 * \brief  TIMER clock config.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in] ClockSrc: specifies the PLL clock source.
 * \param[in] ClockDiv: specifies the APB peripheral to gates its clock.
 *
 * \return None
 */
void TIMER_SetClock(TIMER_TypeDef *TIMERx, uint32_t ClockSrc, uint16_t ClockDiv);

/**
 * \brief  Get TIMER clock.
 *
 * \param[in] TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param[in] ClockSrc: specifies the clock source.
 * \param[in] ClockDiv: specifies the clock divide.
 *
 * \return None
 */
bool TIMER_GetClock(TIMER_TypeDef *TIMERx, uint32_t *ClockSrc, uint16_t *ClockDiv);

#if (TIMER_SUPPORT_RAP_FUNCTION == 1)

void TIMER_RAPModeCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

void TIMER_ActionTrigger(TIMER_TypeDef *TIMERx, uint32_t Action);

void TIMER_ShortcutCmd(TIMER_TypeDef *TIMERx, uint32_t Action, uint32_t Event,
                       FunctionalState NewState);

#endif

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)

void TIMER_SetClockAutoMode(TIMER_TypeDef *TIMERx, uint32_t AutoMode);

#endif

/** End of TIMER_Exported_Functions
  * \}
  */

/** End of TIMER
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /*_RTL_TIMER_H_*/



