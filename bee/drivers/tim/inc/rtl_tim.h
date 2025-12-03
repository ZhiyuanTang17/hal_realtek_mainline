/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_tim.h
* \brief    The header file of the peripheral TIMER driver.
* \details  This file provides all TIMER firmware functions.
* \author   Grace_yan
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_TIM_H
#define RTL_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "tim/src/rtl87x2g/rtl_tim_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "tim/src/rtl87x3e/rtl_tim_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "tim/src/rtl87x3d/rtl_tim_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "tim/src/rtl87x2j/rtl_tim_def.h"
#endif

/** \defgroup TIM         TIM
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup TIM_Exported_Constants TIM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    PWM_DeadZone_Clock_Source PWM DeadZone Clock Source
 * \{
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    PWM_CK_5M_TIMER = 0x0,     //!< PWM DeadZone Clock Source is 5MHz.
    PWM_CK_32K_TIMER = 0x1,    //!< PWM DeadZone Clock Source is 32KHz.
} PWMDZClockSrc_TypeDef;

#define IS_TIM_PWM_DZ_SOURCE(PERIPH)     (((PERIPH) == PWM_CK_5M_TIMER) || \
                                          ((PERIPH) == PWM_CK_32K_TIMER))

/** End of PWM_DeadZone_Clock_Source
  * \}
  */

/**
 * \defgroup    TIM_Mode TIM Mode
 * \{
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    TIM_Mode_FreeRun = 0x0,      //!< Select the TIM mode as Free-running mode.
    TIM_Mode_UserDefine = 0x1,   //!< Select the TIM mode as User-defined mode.
} TIMMode_TypeDef;

#define IS_TIM_MODE(mode) (((mode) == TIM_Mode_FreeRun) || \
                           ((mode) == TIM_Mode_UserDefine))

/** End of TIM_Mode
  * \}
  */

/**
 * \defgroup    PWM_DeadZone_Stop_State PWM DeadZone Stop State
 * \{
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    PWM_STOP_AT_LOW = 0x0,   //!< PWM DeadZone stop at low level.
    PWM_STOP_AT_HIGH = 0x1,  //!< PWM DeadZone stop at high level.
} PWMDZStopState_TypeDef;

#define IS_PWM_STOP_STATE(STATE) (((STATE) == PWM_STOP_AT_LOW) || \
                                  ((STATE) == PWM_STOP_AT_HIGH))

/** End of PWM_DeadZone_Stop_State
  * \}
  */

#if TIM_SUPPORT_EVENT_DURATION
/**
 * \brief       TIM_Event_Duration TIM Event Duration
 *
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    TIM_EventDuration_32us  = 0x00,   //!< The TIM event duration is 32us.
    TIM_EventDuration_64us  = 0x01,   //!< The TIM event duration is 64us.
    TIM_EventDuration_128us = 0x02,   //!< The TIM event duration is 128us.
    TIM_EventDuration_256us = 0x03,   //!< The TIM event duration is 256us.
} TIMEventDuration_TypeDef;

#define IS_TIM_Event_DURATION(duration) (((duration) == TIM_EventDuration_32us) || \
                                         ((duration) == TIM_EventDuration_64us) || \
                                         ((duration) == TIM_EventDuration_128us) || \
                                         ((duration) == TIM_EventDuration_256us))
#endif

/** End of TIM_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup TIM_Exported_Types TIM Exported Types
  * \brief
  * \{
  */

/**
 * \brief       TIM init structure definition.
 *
 * \ingroup     TIM_Exported_Types
 */
typedef struct
{
    TIMClockSrc_TypeDef TIM_ClockSrc;          /*!< Specify the clock source.
                                                    This parameter can be a value of \ref TIM_Clock_Source. */

    TIMClockDiv_TypeDef TIM_SOURCE_DIV;        /*!< Specify the clock source div.
                                                    This parameter can be a value of \ref TIM_Clock_Divider. */

    FunctionalState TIM_SOURCE_DIV_En;         /*!< Enable or disable timer source clock div.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    TIMMode_TypeDef TIM_Mode;                  /*!< Specify the counter mode.
                                                    This parameter can be a value of \ref TIM_Mode. */

    FunctionalState TIM_PWM_En;                /*!< Enable or disable the PWM mode.
                                                    This parameter can be a value of DISABLE or ENABLE. */

    uint32_t TIM_Period;                       /*!< Specify the period value to be loaded into the active
                                                    Auto-Reload Register at the next update event.
                                                    This parameter must range from 0x0 to 0xFFFFFFFF. */

    uint32_t TIM_PWM_High_Count;               /*!< Specify the PWM High Count.
                                                    This parameter must range from 0x0 to 0xFFFFFFFF. */

    uint32_t TIM_PWM_Low_Count;                /*!< Specify the PWM Low Count.
                                                    This parameter must range from 0x0 to 0xFFFFFFFF. */

#if TIM_SUPPORT_EVENT_DURATION
    uint32_t TIM_EventMode;                    /*!< Specify the TIM event mode. */

    uint32_t TIM_EventIndex;                   /*!< Specify the TIM event index. */

    uint32_t TIM_EventDuration;                /*!< Specify the TIM event duration. */
#endif

#if TIM_SUPPORT_CLOCK_DEPEND
    uint8_t  ClockDepend;                      /*!< Specify TIM Source depend.
                                                    timer3 depend timer2, timer5 depend timer4, timer7 depend timer6.
                                                    This parameter can be a value of ENABLE or DISABLE. */
#endif

    PWMDZClockSrc_TypeDef PWM_Deazone_ClockSrc;/*!< Specify the pwm deadzone clock source.
                                                    This parameter can be a value of \ref PWM_DeadZone_Clock_Source. */

    TIMClockDiv_TypeDef PWM_Deadzone_DIV;      /*!< Specify the pwm deadzone clock divider.
                                                    This parameter can be a value of \ref TIM_Clock_Divider. */

    uint32_t PWM_Deazone_Size;                 /*!< Specify the pwm deadzone size.
                                                    This parameter must range from 0x1 to 0xff.
                                                    If you want to determine the deadzone time, you can refer to the formula:
                                                    deadzone time = (deadzone size) / deadzone clock */

    FunctionalState
    PWMDeadZone_En;            /*!< Enable or disable the PWM complementary output and dead zone,.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    PWMDZStopState_TypeDef PWM_Stop_State_P;   /*!< Specify the PWM P stop state.
                                                    This parameter can be a value of \ref PWM_DeadZone_Stop_State. */

    PWMDZStopState_TypeDef PWM_Stop_State_N;   /*!< Specify the PWM N stop state.
                                                    This parameter can be a value of \ref PWM_DeadZone_Stop_State. */

} TIM_TimeBaseInitTypeDef;

/** End of TIM_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup TIM_Exported_Functions TIM Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitialize the specified TIMx registers to their default reset values.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIM_DeInit(TIM6);
 * }
 * \endcode
 */
void TIM_DeInit(TIM_TypeDef *TIMx);

/**
 * \brief   Initialize the specified TIMx according to the specified parameters
 *          in TIM_TimeBaseInitStruct.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_PWM_En = DISABLE;
 *     TIM_InitStruct.TIM_Period = 1000000 - 1 ;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_TimeBaseInit(TIM_TypeDef *TIMx, TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * \brief   Fill each TIM_InitStruct member with its default value.
 *
 * \note The default settings for the TIM_InitStruct member are shown in the following table:
 *       | TIM_InitStruct member        | Default value                        |
 *       |:----------------------------:|:------------------------------------:|
 *       | TIM_ClockSrc                 | \ref TIM_CLOCK_SRC_40M               |
 *       | TIM_Mode                     | \ref TIM_Mode_UserDefine             |
 *       | TIM_Period                   | 0xfff                                |
 *       | TIM_SOURCE_DIV               | \ref TIM_CLOCK_DIVIDER_1             |
 *       | TIM_SOURCE_DIV_En            | DISABLE                              |
 *       | TIM_PWM_En                   | DISABLE                              |
 *       | PWM_Stop_State_P             | \ref PWM_STOP_AT_LOW                 |
 *       | PWM_Stop_State_N             | \ref PWM_STOP_AT_HIGH                |
 *       | PWMDeadZone_En               | DISABLE                              |
 *       | PWM_Deadzone_DIV             | \ref TIM_CLOCK_DIVIDER_1             |
 *       | PWM_Deazone_ClockSrc         | \ref PWM_CK_32K_TIMER                |
 *       | PWM_Deazone_Size             | 10                                   |
 *
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_PWM_En = DISABLE;
 *     TIM_InitStruct.TIM_Period = 1000000 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_StructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * \brief   Enable or disable the specified TIMx peripheral.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[in] NewState: New state of the TIMx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_PWM_En = DISABLE;
 *     TIM_InitStruct.TIM_Period = 1000000 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 *     TIM_Cmd(TIM6, ENABLE);
 * }
 * \endcode
 */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
 * \brief       Enable or disable the specified TIMx interrupt.
 *
 * \param[in]   TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[in]   NewState: New state of the TIMx peripheral.
 *              This parameter can be: ENABLE or DISABLE.
 *
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_PWM_En = DISABLE;
 *     TIM_InitStruct.TIM_Period = 1000000 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 *     TIM_ClearINT(TIM6);
 *     TIM_INTConfig(TIM6, ENABLE);
 * }
 * \endcode
 */
void TIM_INTConfig(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
 * \brief       Change the specified TIMx period value.
 *
 * \param[in]   TIMx: Select the TIM peripheral. \ref TIM_Declaration
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
 *     TIM_Cmd(TIM6, DISABLE);
 *     TIM_ChangePeriod(TIM6, new_period);
 * }
 * \endcode
 */
void TIM_ChangePeriod(TIM_TypeDef *TIMx, uint32_t period);

/**
 * \brief   Change the PWM frequency and duty cycle of the specified TIMx according to high_count and low_count.
 *
 * \param[in]   TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[in]   high_count: This parameter can be 0x00~0xFFFFFFFF.
 * \param[in]  low_count: This parameter can be 0x00~0xFFFFFFFF.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define TIM_DEMO TIMB_6
 *
 * void timer_demo(void)
 * {
 *     uint32_t high_count = 1000000 - 1;
 *     uint32_t low_count = 1000000 - 1;
 *     TIM_Cmd(TIM_DEMO, DISABLE);
 *     TIM_ChangePeriod(TIM_DEMO, high_count, low_count);
 * }
 * \endcode
 */
void TIM_PWMChangeFreqAndDuty(TIM_TypeDef *TIMx, uint32_t high_count, uint32_t low_count);

/**
 * \brief   Get the specified TIMx current value when timer is running.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return  The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t cur_value = TIM_GetCurrentValue(TIM6);
 * }
 * \endcode
 */
uint32_t TIM_GetCurrentValue(TIM_TypeDef *TIMx);

/**
 * \brief   Get the specified TIMx interrupt status.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return  The NewState of the timer interrupt status.
 *          \arg SET: The TIM interrupt has occurred.
 *          \arg RESET: The TIM interrupt has not occurred.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus int_status = TIM_GetINTStatus(TIM6);
 * }
 * \endcode
 */
ITStatus TIM_GetINTStatus(TIM_TypeDef *TIMx);

/**
 * \brief   Get the specified TIMx operation status.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return  The NewState of the timer operation status.
 *          \arg SET: The timer is running.
 *          \arg RESET: The timer is not running.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus intstatus = TIM_GetOperationStatus(TIM6);
 * }
 * \endcode
 */
ITStatus TIM_GetOperationStatus(TIM_TypeDef *TIMx);

/**
 * \brief Get the specified TIMx elapsed value when timer is running.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return The elapsed counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t value = TIM_GetElapsedValue(TIM6);
 * }
 * \endcode
 */
uint32_t TIM_GetElapsedValue(TIM_TypeDef *TIMx);

/**
 * \brief   Clear the specified TIMx interrupts.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIM_ClearINT(TIM6);
 * }
 * \endcode
 */
void TIM_ClearINT(TIM_TypeDef *TIMx);

/**
 * \brief   Enable or disable the emergency stop for PWM complementary output function.
 *
 * \param[in] PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param[in] NewState: NewState of complementary output.
 *            \arg ENABLE: Enable the emergency stop output function.
 *            \arg DISABLE: Disable the emergency stop output function.
 *
 * \return  None.
 * \note    When using PWM functions, it is crucial to pay attention to the corresponding relationships:
 *          PWM2 corresponds to TIM2, and PWM3 corresponds to TIM3.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void pwm_demo(void)
 * {
 *    board_pwm_init();
 *    driver_pwm_init();
 *    //Add delay.
 *    TIM_PWMComplOutputEMCmd(PWM2,ENABLE);
 * }
 * \endcode
 */
void TIM_PWMComplOutputEMCmd(PWM_TypeDef *PWMx, FunctionalState NewState);

/**
 * \brief   Enable or disable deadzone bypass for the PWM complementary output function.
 *          Once enabled, PWM_P will become the inverse of PWM_N.
 *
 * \param[in] PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param[in] NewState: NewState of the PWMx peripheral.
 *            \arg ENABLE: Enable bypass deadzone function.
 *            \arg DISABLE: Disable bypass deadzone function.
 *
 * \return  None.
 * \note    When using PWM functions, it is crucial to pay attention to the corresponding relationships:
 *          PWM2 corresponds to TIM2, and PWM3 corresponds to TIM3.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_pwm_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode             = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_PWM_En           = ENABLE;
 *     TIM_InitStruct.TIM_PWM_High_Count   = PWM_HIGH_COUNT;
 *     TIM_InitStruct.TIM_PWM_Low_Count    = PWM_LOW_COUNT;
 *     TIM_InitStruct.PWM_Stop_State_P     = PWM_STOP_AT_HIGH;
 *     TIM_InitStruct.PWM_Stop_State_N     = PWM_STOP_AT_LOW;
 *     TIM_InitStruct.PWMDeadZone_En       = ENABLE;  //enable to use pwn p/n output
 *     TIM_InitStruct.PWM_Deazone_Size     = 255;
 *     TIM_TimeBaseInit(PWM2, &TIM_InitStruct);
 *
 *     TIM_Cmd(PWM2, ENABLE);
 *     TIM_PWMDZBypassCmd(PWM2, ENABLE);
 * }
 * \endcode
 */
void TIM_PWMDZBypassCmd(PWM_TypeDef *PWMx, FunctionalState NewState);

/**
 * \brief   Change the clock source for the PWM deadzone time.
 *
 * \param[in] PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param[in] PWM_Deazone_ClockSrc: Specify the PWM deadzone clock source. \ref PWM_DeadZone_Clock_Source
 *
 * \return  None.
 * \note    When using PWM functions, it is crucial to pay attention to the corresponding relationships:
 *          PWM2 corresponds to TIM2, and PWM3 corresponds to TIM3.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_pwm_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
 *     //Open 32k clock source.
 *     RCC_ClockSrc5MCmd();
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode             = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_PWM_En           = ENABLE;
 *     TIM_InitStruct.TIM_PWM_High_Count   = PWM_HIGH_COUNT;
 *     TIM_InitStruct.TIM_PWM_Low_Count    = PWM_LOW_COUNT;
 *     TIM_InitStruct.PWM_Stop_State_P     = PWM_STOP_AT_HIGH;
 *     TIM_InitStruct.PWM_Stop_State_N     = PWM_STOP_AT_LOW;
 *     TIM_InitStruct.PWMDeadZone_En       = ENABLE;  //enable to use pwn p/n output
 *     TIM_InitStruct.PWM_Deazone_Size     = PWM_DEAD_ZONE_SIZE;
 *     TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
 *
 *     //Use 32k clock source.
 *     TIM_PWMChangeDZClockSrc(TIM2, PWM_CK_32K_TIMER);
 *
 *     TIM_Cmd(TIM2, ENABLE);
 * }
 * \endcode
 */
void TIM_PWMChangeDZClockSrc(PWM_TypeDef *PWMx, PWMDZClockSrc_TypeDef PWM_Deazone_ClockSrc);

/**
 * \brief  Configure the specified TIMx clock.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[in] ClockSrc: Specify the TIM clock source. \ref TIM_Clock_Source.
 * \param[in] ClockDiv: Specify the TIM clock divider. \ref TIM_Clock_Divider.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIM_ClkConfig(TIM6, TIM_CLOCK_SRC_40M, TIM_CLOCK_DIVIDER_1)
 * }
 * \endcode
 */
void TIM_ClkConfig(TIM_TypeDef *TIMx, TIMClockSrc_TypeDef ClockSrc,
                   TIMClockDiv_TypeDef ClockDiv);

/**
 * \brief  Get the specified TIMx clock config.
 *
 * \param[in] TIMx: Select the TIM peripheral. \ref TIM_Declaration
 * \param[out] ClockSrc: Specify the TIM clock source. \ref TIM_Clock_Source.
 * \param[out] ClockDiv: Specify the TIM clock divider. \ref TIM_Clock_Divider.
 *
 * \return The status of get clock
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIM_ClkGet(TIM6, TIM_CLOCK_SRC_40M, TIM_CLOCK_DIVIDER_1)
 * }
 * \endcode
 */
bool TIM_ClkGet(TIM_TypeDef *TIMx, TIMClockSrc_TypeDef *ClockSrc, TIMClockDiv_TypeDef *ClockDiv);

#if RCC_SUPPORT_TIMSOURCECONFIG_API
/**
 * rtl876x_rcc.h
 *
 * \brief     Select the specified divider and source for the timer clock.
 *
 * \param[in] clocklevel: Timer clock divider.
 *            This parameter can be one of the following values:
 *            \arg TIM2TO7_CLOCK_DIV_x: TIM2TO7 clock divider, where x can be 1 ~ 4, 6, 8, 16.
 * \param[in] clocksource: Timer clock Source.
 *            This parameter can be one of the following values:
 *            \arg TIM_CLOCK_SOURCE_SYSTEM_CLOCK: Select timer clock source of system clock.
 *            \arg TIM_CLOCK_SOURCE_40MHZ: Select timer clock source of 40MHz.
 *            \arg TIM_CLOCK_SOURCE_PLL: Select timer clock source of PLL.
 * \param[in] NewState: New state of the specified RCC Clock Source.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified RCC Clock Source.
 *            \arg DISABLE: Disable the specified RCC Clock Source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_xx_init(void)
 * {
 *     TIM_SourceConfig(TIM2TO7_CLOCK_DIV_1, TIM_CLOCK_SOURCE_40MHZ, ENABLE);
 * }
 * \endcode
 */
void TIM_SourceConfig(uint16_t clocklevel, uint16_t clocksource, FunctionalState NewState);
#endif

/** End of TIM_Exported_Functions
  * \}
  */

/** End of TIM
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /*_RTL_TIM_H_*/


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
