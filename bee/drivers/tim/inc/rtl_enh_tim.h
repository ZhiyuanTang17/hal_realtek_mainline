/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_enh_tim.h
* \brief    The header file of the peripheral Enhance ENHTIMER driver.
* \details  This file provides all Enhance ENHTIMER firmware functions.
* \author   Grace_yan
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
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
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "tim/src/rtl87x2g/rtl_enhtim_def.h"
#include "pinmux/src/rtl87x2g/pin_def.h"
#endif

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
    ENHTIM_CLOCK_DIVIDER_1   = 0x0,
    ENHTIM_CLOCK_DIVIDER_2   = 0x1,
    ENHTIM_CLOCK_DIVIDER_4   = 0x2,
    ENHTIM_CLOCK_DIVIDER_8   = 0x3,
    ENHTIM_CLOCK_DIVIDER_16  = 0x4,
    ENHTIM_CLOCK_DIVIDER_32  = 0x5,
    ENHTIM_CLOCK_DIVIDER_40  = 0x6,
    ENHTIM_CLOCK_DIVIDER_64  = 0x7,
} ENHTIMClkDiv_TypeDef;

#define IS_ENHTIM_CLK_DIVIDER(div) (((div) == ENHTIM_CLOCK_DIVIDER_1) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_2) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_4) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_8) || \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_16)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_32)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_40)|| \
                                    ((div) == ENHTIM_CLOCK_DIVIDER_64))

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
    LATCH_CNT_0 = 0x0,
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    LATCH_CNT_1 = 0x1,
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    LATCH_CNT_2 = 0x2,
#endif
} ENHTIMLatchCnt_TypeDef;

#if (ENHTIM_SUPPORT_LATCH_CNT_0 && !ENHTIM_SUPPORT_LATCH_CNT_1 && !ENHTIM_SUPPORT_LATCH_CNT_2)
#define IS_ENHTIM_LATCH_CNT(cnt) ((cnt) == LATCH_CNT_0)
#endif
#if (ENHTIM_SUPPORT_LATCH_CNT_0 && ENHTIM_SUPPORT_LATCH_CNT_1 && ENHTIM_SUPPORT_LATCH_CNT_2)
#define IS_ENHTIM_LATCH_CNT(cnt) ((cnt) == LATCH_CNT_0 || (cnt) == LATCH_CNT_1 || (cnt) == LATCH_CNT_2)
#endif

/** End of ENHTIM_Latch_Channel_Count
  * \}
  */

/**
 * \defgroup    ENHTIM_DMA_Control_Mode ENHTIM DMA Control Mode
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_DMAC_FLOW_CONTROL = 0x00,
    ENHTIM_FLOW_CONTROL = 0x01,
} ENHTIMDmaCtrlMode_TypeDef;

#define IS_ENHTIM_DMA_CTRL_MODE (mode) (((mode) == ENHTIM_DMAC_FLOW_CONTROL) || \
                                        ((mode) == ENHTIM_FLOW_CONTROL))

/** End of ENHTIM_DMA_Control_Mode
  * \}
  */

/**
 * \defgroup    ENHTIM_DMA_Target ENHTIM DMA Target
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_DMA_CCR_FIFO = 0x00,
    ENHTIM_DMA_LC_FIFO = 0x01,
} ENHTIMDmaTarget_TypeDef;

#define IS_ENHTIM_DMA_TARGET(mode) (((mode) == ENHTIM_DMA_CCR_FIFO) || \
                                    ((mode) == ENHTIM_DMA_LC_FIFO))

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
    ENHTIM_LATCH_TRIGGER_RISING_EDGE = 0x00,
    ENHTIM_LATCH_TRIGGER_FALLING_EDGE = 0x01,
    ENHTIM_LATCH_TRIGGER_BOTH_EDGE = 0x02,
} ENHTIMLatchTriggleMode_TypeDef;

#define IS_ENHTIM_LATCH_TRIG_Mode(mode) (((mode) == ENHTIM_LATCH_TRIGGER_BOTH_EDGE) || \
                                         ((mode) == ENHTIM_LATCH_TRIGGER_FALLING_EDGE) || \
                                         ((mode) == ENHTIM_LATCH_TRIGGER_RISING_EDGE))

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
    ENHTIM_MODE_FreeRun = 0x00,   /*!< User define freerun mode. */
    ENHTIM_MODE_PWM_AUTO = 0x01,  /*!< User define pwm auto mode. */
    ENHTIM_MODE_PWM_MANUAL = 0x02,/*!< User define pwm manual mode. */
} ENHTIMMode_TypeDef;

#define IS_ENHTIM_MODE(mode) (((mode) == ENHTIM_MODE_PWM_MANUAL) || \
                              ((mode) == ENHTIM_MODE_PWM_AUTO) || \
                              ((mode) == ENHTIM_MODE_UserDefine))

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
    ENHTIM_PWM_START_WITH_LOW = 0x00,
    ENHTIM_PWM_START_WITH_HIGH = 0x01,
} ENHTIMPWMPolarity_TypeDef;

#define IS_ENHTIM_PWM_POLARITY(Pol) (((Pol) == ENHTIM_PWM_START_WITH_HIGH) || \
                                     ((Pol) == ENHTIM_PWM_START_WITH_LOW))

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
    ENHTIM_PWM_DZCLKSRCE_ENHTIM = 0x0,
    ENHTIM_PWM_DZCLKSRCE_32K = 0x1,
} ENHTIMPWMDZClkSrc_TypeDef;

#define IS_ENHTIM_PWM_DeadZone_Clock_Source(src) (((src) == ENHTIM_PWM_DZCLKSRCE_ENHTIM) || \
                                                  ((src) == ENHTIM_PWM_DZCLKSRCE_32K))

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
    ENHTIM_PWM_STOP_AT_LOW = 0x0,
    ENHTIM_PWM_STOP_AT_HIGH = 0x1,
} ENHTIMPWMDZStopState_TypeDef;

/** End of ENHPWM_DeadZone_Stop_State
  * \}
  */

#if ENHTIM_SUPPORT_PWM_SRC_SELECT
/**
 * \defgroup    ENHPWM_Reference_Selection ENHPWM Reference Selection
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
typedef enum
{
    ENHTIM_DZ_REF_PWMPN = 0x0,
    ENHTIM_DZ_REF_PWMNN = 0x1,
    ENHTIM_DZ_REF_PWMPP = 0x2,
    ENHTIM_DZ_REF_PWMNP = 0x3,
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
#define ENHTIM_INT_TIM                            (0x00)
#define ENHTIM_INT_LATCH_CNT_FIFO_FULL            (0x40)
#define ENHTIM_INT_LATCH_CNT_FIFO_THD             (0x42)
#define ENHTIM_INT_LATCH_CNT_FIFO_EMPTY           (0x01) /*!< Empty interrupt flag bit but no interrupt. */

#define IS_ENHTIM_INT(INT) (((INT) == ENHTIM_INT_TIM) || \
                            ((INT) == ENHTIM_INT_LATCH_CNT_FIFO_FULL) || \
                            ((INT) == ENHTIM_INT_LATCH_CNT_FIFO_THD))

/** End of ENHTIM_Interrupts
  * \}
  */

/**
 * \defgroup    ENHTIM_Flag ENHTIM Flag
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_FLAG_CCR_FIFO_EMPTY        3
#define ENHTIM_FLAG_CCR_FIFO_FULL         2
#define ENHTIM_FLAG_LC_FIFO_EMPTY         1
#define ENHTIM_FLAG_LC_FIFO_FULL          0

#define IS_ENHTIM_FLAG(flag) (((flag) == ENHTIM_FLAG_CCR_FIFO_FULL) || \
                              ((flag) == ENHTIM_FLAG_CCR_FIFO_EMPTY)|| \
                              ((flag) == ENHTIM_FLAG_LC_FIFO_FULL)  || \
                              ((flag) == ENHTIM_FLAG_LC_FIFO_EMPTY) ))

/** End of ENHTIM_Flag
  * \}
  */

/**
 * \defgroup    ENHTIM_FIFO_Clear_Flag ENHTIM FIFO Clear Flag
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_FIFO_CLR_CCR                 (0)
#define ENHTIM_FIFO_CLR_CNT0                (8)

/** End of ENHTIM_FIFO_Clear_Flag
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
    ENHTIMClkSrc_TypdDef ENHTIM_ClockSource;   /*!< Specifies the ENHTIM clock source.*/
    FunctionalState ENHTIM_ClockDiv_En;        /*!< Specifies enable ENHTIM clock source divider.
                                                    This parameter can be a value of DISABLE or ENABLE.*/
    ENHTIMClkDiv_TypeDef ENHTIM_ClockDiv;      /*!< Specifies the ENHTIM clock source div.*/
    ENHTIMMode_TypeDef ENHTIM_Mode;            /*!< Specifies the counter mode.*/
    FunctionalState ENHTIM_PWMOutputEn;        /*!< Specifies enable Enhtimer PWM oupput.
                                                    This parameter can be a value of DISABLE or ENABLE. */
    ENHTIMPWMPolarity_TypeDef ENHTIM_PWMStartPolarity; /*!< Specifies enhtim toggle output polarity
                                                    for user-define PWM mode.*/
    FunctionalState ENHTIM_LatchCountEn[3];    /*!< Specifies enbale EnhtimerN Latch_cnt.
                                                    This parameter can be a value of DISABLE or ENABLE. */
    ENHTIMLatchTriggleMode_TypeDef ENHTIM_LatchCountTrigger[3]; /*!< Specifies EnhtimerN
                                                    counter latch trigger mode. */
    uint16_t ENHTIM_LatchCountThd;             /*!< Specifies EnhtimerN latched counter fifo threshold.
                                                    This parameter can be value of  0~0x1F. */
    uint16_t ENHTIM_LatchTriggerPad;           /*!< Specifies the PWM mode.
                                                    This parameter can be a value of P0_0 to P19_0. */
    uint32_t ENHTIM_MaxCount;                  /*!< Specifies the Enhtimer max counter value for user-define PWM mode.
                                                    This parameter leagel value range is from 0 ~ 2^32-2. */
    uint32_t ENHTIM_CCValue;                   /*!< Specifies the Enhtimer capture/compare value for user-define PWM mode.
                                                    This parameter leagel value range is from 0 ~ 2^32-2.*/
    FunctionalState ENHTIM_PWMDeadZoneEn;      /*!< Specifies the Enhtimer PWM Deadzone enable.
                                                    This parameter can be a value of ENABLE or DISABLE. */
    uint16_t ENHTIM_PWMDeadZoneClockSource;    /*!< Specifies ENHTIM PWM Deadzone Clock Source.
                                                    This parameter can be a value of ENHTIM_PWM_DeadZone_Clock_Source. */
    FunctionalState ENHTIM_PWMDeadZone_ClockDivEn; /*!< Specifies enbale ENHTIM PWM DZ CLK SRC DIV. */
    ENHTIMClkDiv_TypeDef ENHTIM_PWMDeadZone_ClockDiv; /*!< Specifies ENHTIM PWM DZ CLK SRC DIV. */
    ENHTIMPWMDZStopState_TypeDef ENHTIM_PWMStopStateP; /*!< Specifies the ENHTIM PWM P stop state. */
    ENHTIMPWMDZStopState_TypeDef ENHTIM_PWMStopStateN; /*!< Specifies the PWM N stop state. */
    uint32_t ENHTIM_DeadZoneSize;              /*!< Specifies size of deadzone time, DeadzoneTime=deadzonesize/32000 or 32768.
                                                    This parameter must range from 1 to 0xff. */
    FunctionalState ENHTIM_DmaEn;              /*!< Specifies enable Enhtimer DMA.
                                                    This parameter can be a value of DISABLE or ENABLE. */
    ENHTIMDmaTarget_TypeDef ENHTIM_DmaTragget; /*!< Specifies Enhtimer DMA target. */
#if ENHTIM_SUPPORT_ONESHOT_CMD
    FunctionalState ENHTIM_OneShotEn;          /*!< Specifies the one shot mode. */
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
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] ENHTIM_InitStruct: pointer to a ENHTIM_InitTypeDef structure
 *            that contains the configuration information for the specified ENHTIM peripheral.
 *
 * \return  None.
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
 * \brief       Fills each ENHTIM_InitStruct member with its default value.
 *
 * \param[in]   ENHTIM_TimeBaseInitStruct: Pointer to a ENHTIM_TimeBaseInitTypeDef structure which will be initialized.
 *
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_enhance_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);
 *
 *     ENHTIM_TimeBaseInitTypeDef ENHTIM_InitStruct;
 *     ENHTIM_StructInit(&ENHTIM_InitStruct);
 *
 *     ENHTIM_InitStruct.ENHTIM_PWM_En = PWM_DISABLE;
 *     ENHTIM_InitStruct.ENHTIM_Period = 1000000 - 1;
 *     ENHTIM_InitStruct.ENHTIM_Mode = ENHTIM_Mode_UserDefine;
 *     ENHTIM_TimeBaseInit(ENH_TIM0, &ENHTIM_InitStruct);
 * }
 * \endcode
 */
void ENHTIM_StructInit(ENHTIM_InitTypeDef *ENHTIM_InitStruct);
/**
 * \brief     Enable or disable the specified ENHTIM peripheral.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] NewState: New state of the ENHTIMx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
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
 * \brief     Enable or disable ENHTIMx interrupt.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT2_FIFO_FULL: Enhance Timer latch count2 fifo full interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT2_FIFO_THD: Enhance Timer latch count2 fifo threshold interrupt source.
 * \param[in] NewState: New state of the ENHTIMx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
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
 */
void ENHTIM_INTConfig(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT, FunctionalState NewState);

/**
 * \brief     Read ENHTIMx latch counter fifo data.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] length: Latch count0 fifo length, max 32.
 * \pBuf[out] pBuf: FIFO data out buffer.
 *
 * \return    None.
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
 * \brief     Check whether the ENHTIM interrupt has occurred or not.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT_FIFO_EMPTY: Enhance Timer latch count0 fifo empty interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
 *
 * \return    The new state of the ENHTIM_INT(SET or RESET).
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
 * \brief     Clear ENHTIMx interrupt.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
 *            \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
 *
 * \return    None.
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
 * \brief     Get ENHTIMx toggle state.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 *
 * \return    None.
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
 * \brief  Change Enhtimer pwm_phase_shift count
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] PhaseShiftCnt:This parameter can be 0 to ccr.
 *
 * \return None
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
 * \brief  Get Enhtimer current count
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 *
 * \return None
 *
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
 * \brief     Set Max Count value.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] count: Max counter value for user-define PWM mode (leagel value: 0 ~ 2^32-2).
 *
 * \return    None.
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
 * \brief     Set ENHTIMx capture/compare value for user-define PWM manual mode.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] value: User-defined EnhtimerN capture/compare value for PWM manual mode,
 *            ranging from 0 to 2^31.
 *
 * \return    None.
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
 * \brief     Set ENHTIMx capture/compare value for user-define PWM auto mode.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] value:  User-defined EnhtimerN capture/compare value for PWM manual mode,
 *            ranging from 0 to 2^31.
 * \return    None.
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
 * \brief     Check whether the specified ENHTIM flag is set.
 *
 * \param[in] ENHTIMx: Where x can be 0 to 7 to select the ENHTIMx peripheral.
 * \param[in] ENHTIM_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg ENHTIM_FLAG_LC_FIFO_EMPTY: FIFO empty or not. If SET, LC FIFO is empty.
 *            \arg ENHTIM_FLAG_LC_FIFO_FULL: FIFO full or not. If SET, LC FIFO is full.
 *            \arg ENHTIM_FLAG_CCR_FIFO_EMPTY: FIFO empty or not. If SET, CCR FIFO is empty.
 *            \arg ENHTIM_FLAG_CCR_FIFO_FULL: FIFO full or not. If SET, CCR FIFO is full.
 *
 * \return    The new state of ENHTIM_FLAG (SET or RESET).
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
 * \brief     Enable ENHTIMx latch counter.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
 *            This parameter can be one of follow.
 *            \arg LATCH_COUNT_0: Enhance timer latch count 0.
 *            \arg LATCH_COUNT_1: Enhance timer latch count 1.
 *            \arg LATCH_COUNT_2: Enhance timer latch count 2.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint32_t cur_value = ENHTIM_LatchCountEnable(ENH_TIM0, LATCH_COUNT_0);
 * }
 * \endcode
 */
void ENHTIM_LatchCountEnable(ENHTIM_TypeDef *ENHTIMx,
                             ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Disable ENHTIMx latch counter.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
 *            This parameter can be one of follow.
 *            \arg LATCH_COUNT_0: Enhance timer latch count 0.
 *            \arg LATCH_COUNT_1: Enhance timer latch count 1.
 *            \arg LATCH_COUNT_2: Enhance timer latch count 2.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint32_t cur_value = ENHTIM_LatchCountDisable(ENH_TIM0, LATCH_COUNT_0);
 * }
 * \endcode
 */
void ENHTIM_LatchCountDisable(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Get ENHTIMx latch count value.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
 *            This parameter can be one of follow.
 *            \arg LATCH_COUNT_0: Enhance timer latch count 0.
 *            \arg LATCH_COUNT_1: Enhance timer latch count 1.
 *            \arg LATCH_COUNT_2: Enhance timer latch count 2.
 *
 * \return    The latch counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint32_t count_value = ENHTIM_GetLatchCountValue(ENH_TIM0, LATCH_COUNT_0);
 * }
 * \endcode
 */
uint32_t ENHTIM_GetLatchCount(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx);

/**
 * \brief     Get ENHTIMx latch counter2 fifo length.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 *
 * \return    FIFO data length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void enhance_timer_demo(void)
 * {
 *     uint8_t length = ENHTIM_GetLatchCount2FIFOLength(ENH_TIM0);
 * }
 * \endcode
 */
uint8_t ENHTIM_GetLatchCountFIFOLength(ENHTIM_TypeDef *ENHTIMx);

/**
 * \brief     Clear capture/compare or latch count2 fifo.
 *
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] FIFO_CLR: Specifies the FIFO type which to be clear.
 *            This parameter can be one of the following values:
 *            \arg ENHTIM_FIFO_CLR_CCR: Enhance Timer CCR FIFO clear flag.
 *            \arg ENHTIM_FIFO_CLR_CNT2: Enhance Timer latch count2 FIFO clear flag.
 *
 * \return    None.
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
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 *
 * \return  None.
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
 * \param[in] ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in] NewState: New state of the ENHTIMx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
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
 * \param[in] None.
 *
 * \return    All the state of the ENHTIM_INT.
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
 * \brief  Enable or disable the specified ENHTIM peripheral.
 *
 * \param[in]  ENHTIMx: Where x can be 0 to 3 to select the ENHTIMx peripheral.
 * \param[in]  NewState: New state of the ENHTIMx peripheral.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \brief  Check whether the ENHTIM latch count0 fifo has data or not.
 *
 * \param  ENHTIMx: Where x can be 0 to 7 to select the ENHTIMx peripheral.
 *
 * \return The new state of the specified ENHTIMx peripheral
 *         latch count0 fifo (SET or RESET).
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
 * \brief  Change ENHTIME PWM freq and duty according high_cnt
 *
 * \param  ENHTIMx: where x can be 0 to 3 to select the ENHTIMx peripheral.
 * \param  enhtim_mode: This parameter can be ENHTIM_MODE_PWM_MANUAL or ENHTIM_MODE_PWM_AUTO.
 * \param  max_count: Timer max counter value for user-define mode
 *         This parameter can be 1 ~ 2^32-2
 * \param  high_count: Timer capture/compare value for user-define manual mode or timer capture/compare fifo entry for user-define auto mode.
 *         This parameter can be 0 ~ 2^32-2
 *
 * \return None
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
void ENHTIM_PWMChangeFreqAndDuty(ENHTIM_TypeDef *ENHTIMx, uint16_t enhtim_mode, uint32_t max_count,
                                 uint32_t high_count);

#if ENHTIM_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * \brief  ENHTIM clock config.
 *
 * \param[in]  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[in]  ClockSrc: specifies the PLL clock source.  \ref ENHTIM_Clock_Source
 * \param[in]  ClockDiv: specifies the APB peripheral to gates its clock.  \ref ENHTIM_Clock_Divider
 *
 * \return None
 */
void ENHTIM_ClkConfig(ENHTIM_TypeDef *ENHTIMx, ENHTIMClkSrc_TypdDef ClockSrc,
                      ENHTIMClkDiv_TypeDef ClockDiv);

/**
 * \brief  Get ENHTIM clock config.
 *
 * \param[in]  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
 * \param[out]  ClockSrc: specifies the PLL clock source. \ref ENHTIM_Clock_Source
 * \param[out]  ClockDiv: specifies the APB peripheral to gates its clock. \ref ENHTIM_Clock_Divider
 *
 * \return None
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


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/