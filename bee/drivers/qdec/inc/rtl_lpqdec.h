/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_LPQDEC_H
#define RTL_LPQDEC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "qdec/src/device/rtl87x2j/rtl_lpqdec_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "qdec/src/device/rtl87x3j/rtl_lpqdec_def.h"
#endif

/** \defgroup LPQDEC    LPQDEC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup LPQDEC_Exported_Constants LPQDEC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    LPQDEC_Counter_Scale LPQDEC Counter Scale
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_COUNTER_SCALE_1_PHASE = 0x00,
    LPQDEC_COUNTER_SCALE_2_PHASE = 0x01,
} LPQDECCounterScale_TypeDef;

#define IS_LPQDEC_COUNTER_SCALE_PHASE(PHASE) ((PHASE) <= 0x01)

/** End of LPQDEC_Counter_Scale
  * \}
  */

/**
 * \defgroup    LPQDEC_Phase LPQDEC Phase
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_PHASE_MODE0 = 0x00, //phase 00
    LPQDEC_PHASE_MODE1 = 0x01, //phase 01
    LPQDEC_PHASE_MODE2 = 0x02, //phase 10
    LPQDEC_PHASE_MODE3 = 0x03, //phase 11
} LPQDECPhase_TypeDef;

#define IS_LPQDEC_PHSAE(PHSAE) ((PHSAE) <= 0x03)

/** End of LPQDEC_Phase
  * \}
  */

/**
 * \defgroup    LPQDEC_Axis_Direction LPQDEC Axis Direction
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_AXIS_DIR_DOWN = 0x00,
    LPQDEC_AXIS_DIR_UP = 0x01,
} LPQDECAxisDir_TypeDef;

#define IS_LPQDEC_AXIS_DIRECTION(DIRECTION) ((DIRECTION) <= 0x01)

/** End of LPQDEC_Axis_Direction
  * \}
  */

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
/**
 * \defgroup    LPQDEC_LED_Polarity LPQDEC LED Polarity
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_LED_POLARITY_LOW = 0x0,
    LPQDEC_LED_POLARITY_HIGH = 0x1,
} LPQDECLedPolarity_TypeDef;

#define IS_LPQDEC_LED_POLARITY(POLARITY) ((POLARITY) <= 0x01)

/** End of LPQDEC_LED_Polarity
  * \}
  */

/**
 * \defgroup    LPQDEC_LED_Period LPQDEC LED Period
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_LED_PERIOD_0US      = 0x0,
    LPQDEC_LED_PERIOD_31P25US  = 0x1,
    LPQDEC_LED_PERIOD_62P5US   = 0x2,
    LPQDEC_LED_PERIOD_93P75US  = 0x3,
    LPQDEC_LED_PERIOD_125US    = 0x4,
    LPQDEC_LED_PERIOD_156P25US = 0x5,
    LPQDEC_LED_PERIOD_187P5US  = 0x6,
    LPQDEC_LED_PERIOD_218P75US = 0x7,
} LPQDECLedPeriod_TypeDef;

#define IS_LPQDEC_LED_PERIOD(PERIOD) ((PERIOD) <= 0x7)

/** End of LPQDEC_LED_Period
  * \}
  */
#endif

/**
 * \defgroup    LPQDEC_Interrupts LPQDEC Interrupts
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_NEW_DATA               BIT6
#define LPQDEC_X_INT_ILLEGAL                BIT5

#define IS_LPQDEC_INT_CONFIG(CONFIG)        (((CONFIG) == LPQDEC_X_INT_NEW_DATA) || \
                                             ((CONFIG) == LPQDEC_X_INT_ILLEGAL))

/** End of LPQDEC_Interrupts
  * \}
  */

/**
 * \defgroup    LPQDEC_Interrupts_Mask LPQDEC Interrupts Mask
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */

#define LPQDEC_X_INT_MASK_NEW_DATA          BIT8
#define LPQDEC_X_INT_MASK_ILLEGAL           BIT7

#define IS_LPQDEC_INT_MASK_CONFIG(CONFIG)   (((CONFIG) == LPQDEC_X_INT_MASK_NEW_DATA) || \
                                             ((CONFIG) == LPQDEC_X_INT_MASK_ILLEGAL))

/** End of LPQDEC_Interrupts_Mask
  * \}
  */

/**
 * \defgroup    LPQDEC_Interrupts_Clear LPQDEC Interrupts Clear
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_CLEAR_ILLEGAL          BIT4
#define LPQDEC_X_INT_CLEAR_UNDERFLOW        BIT3
#define LPQDEC_X_INT_CLEAR_OVERFLOW         BIT2
#define LPQDEC_X_INT_CLEAR_NEW_DATA         BIT1

#define IS_LPQDEC_INT_CLEAR_CONFIG(CONFIG)  (((CONFIG) == LPQDEC_X_INT_CLEAR_ILLEGAL) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_UNDERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_OVERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_NEW_DATA))

/** End of LPQDEC_Interrupts_Clear
  * \}
  */

/**
 * \defgroup    LPQDEC_Counter_Clear LPQDEC Counter Clear
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
#define LPQDEC_X_CLEAR_ILLEGAL_COUNTER      BIT5
#define LPQDEC_X_CLEAR_ACC_COUNTER          BIT0

#define IS_LPQDEC_CNT_CLEAR_CONFIG(CONFIG)  (((CONFIG) == LPQDEC_X_CLEAR_ILLEGAL_COUNTER) || \
                                             ((CONFIG) == LPQDEC_X_CLEAR_ACC_COUNTER))

/** End of LPQDEC_Counter_Clear
  * \}
  */

/**
 * \defgroup    LPQDEC_Interrupts_Flag LPQDEC Interrupts Flag
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_FLAG_NEW_DATA          BIT18
#define LPQDEC_X_INT_FLAG_OVERFLOW          BIT16
#define LPQDEC_X_INT_FLAG_UNDERFLOW         BIT17
#define LPQDEC_X_INT_FLAG_ILLEGAL           BIT19

#define IS_LPQDEC_INT_FLAG_CONFIG(CONFIG)   (((CONFIG) == LPQDEC_X_INT_FLAG_NEW_COUNT) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_OVERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_UNDERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_ILLEGAL))

/** End of LPQDEC_Interrupts_Flag
  * \}
  */

/**
 * \defgroup    LPQDEC_Axis LPQDEC Axis
 * \{
 * \ingroup     LPQDEC_Exported_Constants
 */
#define LPQDEC_AXIS_X                      (0)

/** End of LPQDEC_Axis
  * \}
  */

/** End of LPQDEC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup LPQDEC_Exported_Types LPQDEC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       LPQDEC init structure definition.
 *
 * \ingroup     LPQDEC_Exported_Types
 */
typedef struct
{
#if (LPQDEC_SUPPORT_CLK_SRC_DIV == 1)
    uint16_t LPQDEC_ScanClockDiv;              /*!< Specifies DIV for Scan clock. */
#endif

    FunctionalState LPQDEC_AxisConfigX;        /*!< Specifies the axis X function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState LPQDEC_ManualLoadInitPhase;/*!< Specifies manual-load Initphase function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    LPQDECPhase_TypeDef LPQDEC_InitPhaseX;     /*!< Specifies the axis X function. */


    FunctionalState LPQDEC_DebounceEnableX;    /*!< Specifies the axis X debounce.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint16_t LPQDEC_DebounceCountX;            /*!< Specifies the axis X debounce time. */

    LPQDECCounterScale_TypeDef LPQDEC_CounterScaleX; /*!< Specifies the axis X conter scale. */

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
    FunctionalState LPQDEC_LedEn;              /*!< Specifies LED output status. */

    LPQDECLedPolarity_TypeDef LPQDEC_LedPolarity; /*!< Specifies LED output pin polarity. */

    LPQDECLedPeriod_TypeDef LPQDEC_LedPeriod;  /*!< Time period the LED is switched ON
                                                    prior to sampling. When setting LEDPRE,
                                                    make sure sample period > LEDPRE */
#endif
} LPQDEC_InitTypeDef;

/** End of LPQDEC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup LPQDEC_Exported_Functions LPQDEC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief  Deinitializes the LPQDEC peripheral registers to their default reset values.
 *
 * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_DeInit(LPQDEC);
 * }
 * \endcode
 */
void LPQDEC_DeInit(LPQDEC_TypeDef *LPQDECx);

/**
 * \brief   Initializes the LPQDEC peripheral according to the specified
  *         parameters in the LPQDEC_InitStruct.
 *
 * \param[in]  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in]  LPQDEC_InitStruct: pointer to an LPQDEC_InitStruct structure that
  *            contains the configuration information for the specified LPQDEC peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_InitTypeDef LPQDEC_InitStruct;
 *     LPQDEC_StructInit(&LPQDEC_InitStruct);
 *     LPQDEC_InitStruct.LPQDEC_AxisConfigX       = ENABLE;
 *     LPQDEC_InitStruct.LPQDEC_DebounceEnableX   = DISABLE;
 *     LPQDEC_Init(LPQDEC, &LPQDEC_InitStruct);
 *
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_Init(LPQDEC_TypeDef *LPQDECx, LPQDEC_InitTypeDef *LPQDEC_InitStruct);

/**
 * \brief  Fills each LPQDEC_InitStruct member with its default value.
 *
 * \param[in]  LPQDEC_InitStruct: pointer to an LPQDEC_InitStruct structure which will be initialized.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *
 *     LPQDEC_InitTypeDef LPQDEC_InitStruct;
 *     LPQDEC_StructInit(&LPQDEC_InitStruct);
 *     LPQDEC_InitStruct.LPQDEC_AxisConfigX       = ENABLE;
 *     LPQDEC_InitStruct.LPQDEC_DebounceEnableX   = DISABLE;
 *     LPQDEC_Init(LPQDEC, &LPQDEC_InitStruct);
 *
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_StructInit(LPQDEC_InitTypeDef *LPQDEC_InitStruct);

/**
 * \brief  Enable or disable LPQDEC Function.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_AXIS: Specifies the LPQDEC axis.
 *            This parameter can be one of the following values:
 *            \arg LPQDEC_AXIS_X: The LPQDEC X axis.
 * \param[in] NewState: New state of the selected LPQDEC axis.
 *            This parameter can be one of the following values:
  *           \arg ENABLE: Pause.
  *           \arg DISABLE: Resume.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_Cmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS, FunctionalState NewState);

/**
 * \brief  Enables or disables the specified LPQDEC interrupts.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_INT: Specifies the LPQDEC interrupts sources to be enabled or disabled.
 *            This parameter parameter can be one of the following values:
 *            \arg LPQDEC_X_INT_NEW_DATA: The counter interrupt for X axis.
 *            \arg LPQDEC_X_INT_ILLEGAL: The illegal interrupt for X axis.
 * \param[in] NewState: New state of the specified LPQDEC interrupt.
 *            This parameter parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_INTConfig(LPQDEC, LPQDEC_X_INT_NEW_DATA, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_INTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_INT, FunctionalState NewState);

/**
 * \brief  Enables or disables mask the specified LPQDEC axis interrupts.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_AXIS: Specifies the LPQDEC axis.
 *            This parameter can be one or logical OR of the following values:
 *            \arg LPQDEC_X_INT_MASK_NEW_DATA: The LPQDEC CNT interrupt mask.
 *            \arg LPQDEC_X_INT_MASK_ILLEGAL: The LPQDEC illegal interrupt mask.
 * \param[in] NewState: New state of the specified LPQDEC interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_MaskINTConfig(LPQDEC, LPQDEC_X_INT_MASK_NEW_DATA, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_MaskINTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_MASK, FunctionalState NewState);

/**
 * \brief  Enables or disables interrupt signal to CPU NVIC.
 *
 * \param[in]  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in]  NewState: New state of the specified LPQDEC interrupts mask.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_NVICCmd(LPQDEC, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_NVICCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState);

/**
 * \brief  Enables or disables wakeup system.
 *
 * \param[in]  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in]  NewState: New state of the specified LPQDEC interrupts mask.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_WakeUpCmd(LPQDEC, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_WakeUpCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState);

/**
 * \brief  Checks whether the specified LPQDEC flag is set or not..
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg LPQDEC_X_INT_FLAG_NEW_COUNT: Status of the counter interrupt for X axis.
 *            \arg LPQDEC_X_INT_FLAG_ILLEGAL: Status of the illegal interrupt for X axis.
 *            \arg LPQDEC_X_INT_FLAG_OVERFLOW: The overflow flag for x-axis accumulation counter.
 *            \arg LPQDEC_X_INT_FLAG_UNDERFLOW: The underflow flag for x-axis accumulation counter.
 *
 * \return The New state of LPQDEC_FLAG(SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     FlagStatus flag_status = LPQDEC_GetFlagState(LPQDEC, LPQDEC_X_INT_FLAG_NEW_COUNT);
 * }
 * \endcode
 */
FlagStatus LPQDEC_GetFlagState(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_FLAG);

/**
 * \brief   Clear LPQDEC interrupt pending bit.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_FLAG: Specifies the flag to clear.
 *            This parameter parameter can be one of the following values:
 *            \arg LPQDEC_X_INT_CLEAR_ILLEGAL: The illegal interrupt for X axis.
 *            \arg LPQDEC_X_INT_CLEAR_UNDERFLOW: The underflow flag for x-axis accumulation counter.
 *            \arg LPQDEC_X_INT_CLEAR_OVERFLOW: The overflow flag for x-axis accumulation counter.
 *            \arg LPQDEC_X_INT_CLEAR_NEW_DATA: The counter interrupt for X axis.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_ClearINTPendingBit(LPQDEC, LPQDEC_X_INT_CLEAR_NEW_DATA);
 * }
 * \endcode
 */
void LPQDEC_ClearINTPendingBit(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLR_INT);

/**
 * \brief   Clear LPQDEC counter.
 *
 * \param[in]  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in]  LPQDEC_CLEAR: Specifies the counter to clear.
 *             This parameter parameter can be one of the following values:
 *             \arg LPQDEC_X_CLEAR_ILLEGAL_COUNTER: The illegal counter for X axis.
 *             \arg LPQDEC_X_CLEAR_ACC_COUNTER: The acc counter for X axis.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_ClearCounter(LPQDEC, LPQDEC_X_INT_CLEAR_ILLEGAL_CNT);
 * }
 * \endcode
 */
void LPQDEC_ClearCounter(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLEAR);

/**
 * \brief  Get LPQDEC X-Axis direction.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_AXIS: Specifies the LPQDEC axis.
 *            This parameter parameter can be one of the following values:
 *            \arg  LPQDEC_AXIS_X: The LPQDEC X axis.
 *
 * \return The direction of the axis. This parameter parameter can be one of the following values:
 *         \retval LPQDEC_AXIS_DIR_UP: The axis is rolling up.
 *         \retval LPQDEC_AXIS_DIR_DOWN: The axis is rolling down.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     bool dir = LPQDEC_GetAxisDirection(LPQDEC, LPQDEC_AXIS_X);
 * }
 * \endcode
 */
bool LPQDEC_GetAxisDirection(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS);

/**
 * \brief  Get LPQDEC X-Axis count.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_AXIS: Specifies the LPQDEC axis.
 *            This parameter parameter can be one of the following values:
 *            \arg LPQDEC_AXIS_X: The LPQDEC X axis.
 *
 * \return The count of the axis.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     uint16_t counter = LPQDEC_GetAxisCount(LPQDEC, LPQDEC_AXIS_X);
 * }
 * \endcode
 */
uint16_t LPQDEC_GetAxisCount(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS);

/**
 * \brief  Pause or resume LPQDEC Axis x.
 *
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 * \param[in] LPQDEC_AXIS: Specifies the LPQDEC axis.
 *            This parameter parameter can be one of the following values:
 *            \arg LPQDEC_AXIS_X: The LPQDEC X axis.
 * \param[in] NewState: New state of the specified LPQDEC Axis.
 *            This parameter parameter can be one of the following values:
 *            \arg ENABLE: Pause.
 *            \arg DISABLE: Resume.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_CounterPauseCmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void LPQDEC_CounterPauseCmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS,
                            FunctionalState NewState);

/**
 * \brief  Get current state of phase.
 * \param[in] LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
 *
 * \return The current state of phase. \ref LPQDECPhase_TypeDef
 *         \retval LPQDEC_PHASE_MODE0: Phase 00.
 *         \retval LPQDEC_PHASE_MODE1: Phase 01.
 *         \retval LPQDEC_PHASE_MODE2: Phase 10.
 *         \retval LPQDEC_PHASE_MODE3: Phase 11.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDECPhase_TypeDef phase = LPQDEC_GetPhaseState(LPQDEC);
 * }
 * \endcode
  */
LPQDECPhase_TypeDef LPQDEC_GetPhaseState(LPQDEC_TypeDef *LPQDECx);

/** End of LPQDEC_Exported_Functions
  * \}
  */

/** End of LPQDEC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPQDEC_H */




