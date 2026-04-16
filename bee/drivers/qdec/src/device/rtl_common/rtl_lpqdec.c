/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lpqdec.h"
#include "utils.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the LPQDEC peripheral registers to their default reset values.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \return None
  */
void LPQDEC_DeInit(LPQDEC_TypeDef *LPQDECx)
{
    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_rst = 0x1;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
    __NOP();
    __NOP();
    lpqdec_config.b.x_rst = 0x0;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
}

/**
  * \brief  Initializes the LPQDEC peripheral according to the specified
  *         parameters in the LPQDEC_InitStruct.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_InitStruct: pointer to an LPQDEC_InitStruct structure that
  *         contains the configuration information for the specified LPQDEC peripheral.
  * \return None
  */
void LPQDEC_Init(LPQDEC_TypeDef *LPQDECx, LPQDEC_InitTypeDef *LPQDEC_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_QDEC_PERIPH(LPQDECx));

#if (LPQDEC_SUPPORT_CLK_SRC_DIV == 1)
    LPQDEC_DIV_TypeDef lpqdec_div = {.d32 = LPQDECx->LPQDEC_DIV};
    lpqdec_div.b.scan_div = LPQDEC_InitStruct->LPQDEC_ScanClockDiv;
    LPQDECx->LPQDEC_DIV = lpqdec_div.d32;
#endif

    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_fsm_en = 0x1;
    lpqdec_config.b.x_axis_en = 0x0;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
    platform_delay_us(63);

    /* Set Manual Initial Phase*/
    if (LPQDEC_InitStruct->LPQDEC_ManualLoadInitPhase == ENABLE)
    {
        lpqdec_config.b.x_set_inital_phase = 0x1;
        LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
        platform_delay_us(63);
        lpqdec_config.b.x_initial_phase = LPQDEC_InitStruct->LPQDEC_InitPhaseX;
        LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;

        lpqdec_config.b.x_set_inital_phase = 0x0;
        LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
    }

    /* The max debounce cnt is 0x1FFF*/
    if (LPQDEC_InitStruct->LPQDEC_DebounceCountX >= 0x1FFF)
    {
        LPQDEC_InitStruct->LPQDEC_DebounceCountX = 0x1FFF;
    }
    lpqdec_config.b.x_debounce_en = LPQDEC_InitStruct->LPQDEC_DebounceEnableX;
    lpqdec_config.b.x_debounce_cnt = LPQDEC_InitStruct->LPQDEC_DebounceCountX;
    lpqdec_config.b.x_cnt_scale = LPQDEC_InitStruct->LPQDEC_CounterScaleX;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;

    /* write 1 to clear acc counter and illegal counter */
    LPQDEC_INT_CLR_TypeDef lpqdec_clear = {.d32 = LPQDECx->LPQDEC_INT_CLR};
    lpqdec_clear.b.acc_cnt_clr = 0x1;
    lpqdec_clear.b.illegal_cnt_clr = 0x1;
    LPQDECx->LPQDEC_INT_CLR = lpqdec_clear.d32;

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
    /* Configure the optical roller function */
    LPQDEC_LED_CTRL_TypeDef lpqdec_led = {.d32 = LPQDECx->LPQDEC_LED_CTRL};
    lpqdec_led.b.led_en = LPQDEC_InitStruct->LPQDEC_LedEn;
    lpqdec_led.b.ledpol = LPQDEC_InitStruct->LPQDEC_LedPolarity;
    lpqdec_led.b.ledpre = LPQDEC_InitStruct->LPQDEC_LedPeriod;
    LPQDECx->LPQDEC_LED_CTRL = lpqdec_led.d32;
#endif

    /* Accessing some registers requires 2T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    platform_delay_us(63);
}

/**
  * \brief  Fills each LPQDEC_InitStruct member with its default value.
  * \param  LPQDEC_InitStruct: pointer to an LPQDEC_InitStruct structure which will be initialized.
  * \return None
  */
void LPQDEC_StructInit(LPQDEC_InitTypeDef *LPQDEC_InitStruct)
{
#if (LPQDEC_SUPPORT_CLK_SRC_DIV == 1)
    LPQDEC_InitStruct->LPQDEC_ScanClockDiv        = 0x0;
#endif
    LPQDEC_InitStruct->LPQDEC_AxisConfigX         = DISABLE;
    LPQDEC_InitStruct->LPQDEC_ManualLoadInitPhase = DISABLE;
    LPQDEC_InitStruct->LPQDEC_InitPhaseX          = LPQDEC_PHASE_MODE0;
    LPQDEC_InitStruct->LPQDEC_DebounceEnableX     = DISABLE;
    LPQDEC_InitStruct->LPQDEC_DebounceCountX      = 32 * 5; /*!< 5ms */
    LPQDEC_InitStruct->LPQDEC_CounterScaleX       = LPQDEC_COUNTER_SCALE_1_PHASE;
#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
    LPQDEC_InitStruct->LPQDEC_LedEn               = DISABLE;
    LPQDEC_InitStruct->LPQDEC_LedPolarity         = LPQDEC_LED_POLARITY_LOW;
    LPQDEC_InitStruct->LPQDEC_LedPeriod           = LPQDEC_LED_PERIOD_0US;
#endif

    return;
}

/**
  * \brief  Enable or disable LPQDEC Function.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter can be one of the following values:
  *         \arg QDEC_AXIS_X: The LPQDEC X axis.
  * \param  NewState: New state of the selected LPQDEC axis.
  *         This parameter can be one of the following values:
  *         \arg ENABLE: Pause.
  *         \arg DISABLE: Resume.
  * \return None.
  */
void LPQDEC_Cmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS_DIR(LPQDEC_AXIS));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_axis_en = NewState;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
}

/**
  * \brief  Enables or disables the specified LPQDEC interrupts.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_INT: Specifies the LPQDEC interrupts sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg LPQDEC_X_INT_NEW_DATA: The counter interrupt for X axis.
  *         \arg LPQDEC_X_INT_ILLEGAL: The illegal interrupt for X axis.
  * \param  NewState: New state of the specified LPQDEC interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPQDEC_INTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_INT_CONFIG(LPQDEC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        LPQDECx->LPQDEC_CONFIG |= LPQDEC_INT;
    }
    else
    {
        LPQDECx->LPQDEC_CONFIG &= ~LPQDEC_INT;
    }

    return;
}

/**
  * \brief  Enables or disables mask the specified LPQDEC axis interrupts.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter can be one or logical OR of the following values:
  *         \arg LPQDEC_X_INT_MASK_NEW_DATA: The LPQDEC CNT interrupt mask.
  *         \arg LPQDEC_X_INT_MASK_ILLEGAL: The LPQDEC illegal interrupt mask.
  * \param  NewState: New state of the specified LPQDEC interrupts mask.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPQDEC_MaskINTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_MASK, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_INT_MASK_CONFIG(LPQDEC_AXIS));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        LPQDECx->LPQDEC_CONFIG |= LPQDEC_MASK;
    }
    else
    {
        LPQDECx->LPQDEC_CONFIG &= ~LPQDEC_MASK;
    }

    return;
}

/**
  * \brief  Enables or disables interrupt signal to CPU NVIC.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  NewState: New state of the specified LPQDEC interrupts mask.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPQDEC_NVICCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_int_mask = !NewState;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
}

/**
  * \brief  Enables or disables wakeup system.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  NewState: New state of the specified LPQDEC interrupts mask.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPQDEC_WakeUpCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_wake_aon_mask = !NewState;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
}

/**
  * \brief  Checks whether the specified LPQDEC flag is set or not.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         \arg LPQDEC_X_INT_FLAG_NEW_COUNT: Status of the counter interrupt for X axis.
  *         \arg LPQDEC_X_INT_FLAG_ILLEGAL: Status of the illegal interrupt for X axis.
  *         \arg LPQDEC_X_INT_FLAG_OVERFLOW: The overflow flag for x-axis accumulation counter.
  *         \arg LPQDEC_X_INT_FLAG_UNDERFLOW: The underflow flag for x-axis accumulation counter.
  * \return The New state of LPQDEC_FLAG (SET or RESET).
  */
FlagStatus LPQDEC_GetFlagState(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_FLAG)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_CLR_INT_STATUS(LPQDEC_FLAG));

    if ((LPQDECx->LPQDEC_SR_1_X & LPQDEC_FLAG) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

/**
  * \brief  Clear LPQDEC interrupt pending bit.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_FLAG: Specifies the flag to clear.
  *         This parameter parameter can be one of the following values:
  *         \arg LPQDEC_X_INT_CLEAR_ILLEGAL: The illegal interrupt for X axis.
  *         \arg LPQDEC_X_INT_CLEAR_UNDERFLOW: The underflow flag for x-axis accumulation counter.
  *         \arg LPQDEC_X_INT_CLEAR_OVERFLOW: The overflow flag for x-axis accumulation counter.
  *         \arg LPQDEC_X_INT_CLEAR_NEW_DATA: The counter interrupt for X axis.
  * \return None.
  */
void LPQDEC_ClearINTPendingBit(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLEAR)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_INT_CLEAR_CONFIG(LPQDEC_CLEAR));

    LPQDECx->LPQDEC_INT_CLR |= LPQDEC_CLEAR;

    return;
}

/**
  * \brief  Clear LPQDEC counter.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_CLEAR: Specifies the counter to clear.
  *         This parameter parameter can be one of the following values:
  *         \arg LPQDEC_X_CLEAR_ILLEGAL_COUNTER: The illegal counter for X axis.
  *         \arg LPQDEC_X_CLEAR_ACC_COUNTER: The acc counter for X axis.
  * \return None.
  */
void LPQDEC_ClearCounter(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLEAR)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_CNT_CLEAR_CONFIG(LPQDEC_CLEAR));

    LPQDECx->LPQDEC_INT_CLR |= LPQDEC_CLEAR;

    return;
}

/**
  * \brief  Get LPQDEC X-Axis count.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter parameter can be one of the following values:
  *         \arg LPQDEC_AXIS_X: The LPQDEC X axis.
  * \return The count of the axis.
  */
uint16_t LPQDEC_GetAxisCount(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS_DIR(LPQDEC_AXIS));

    LPQDEC_SR_2_X_TypeDef lpqdec_sr2x = {.d32 = LPQDECx->LPQDEC_SR_2_X};
    return lpqdec_sr2x.b.acc_cnt;
}

/**
  * \brief  Pause or resume LPQDEC Axis x.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter parameter can be one of the following values:
  *         \arg LPQDEC_AXIS_X: The LPQDEC X axis.
  * \param  NewState: New state of the specified LPQDEC Axis.
  *         This parameter parameter can be one of the following values:
  *         \arg ENABLE: Pause.
  *         \arg DISABLE: Resume.
  * \return None.
  */
void LPQDEC_CounterPauseCmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS_DIR(LPQDEC_AXIS));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPQDEC_CONFIG_TypeDef lpqdec_config = {.d32 = LPQDECx->LPQDEC_CONFIG};
    lpqdec_config.b.x_cnt_pause = NewState;
    LPQDECx->LPQDEC_CONFIG = lpqdec_config.d32;
}



