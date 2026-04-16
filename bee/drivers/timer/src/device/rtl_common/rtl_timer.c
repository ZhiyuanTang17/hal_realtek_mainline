/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_timer.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern uint32_t TIMER_GetTimerID(TIMER_TypeDef *TIMERx);
extern TIMERCASE_TypeDef TIMER_GetTimerCase(TIMER_TypeDef *TIMERx);
extern TIMER_ShareTypeDef *TIMER_GetTimerShareBase(TIMER_TypeDef *TIMERx);
extern void TIMER_SetPWMDZClock(TIMER_TypeDef *TIMERx, uint16_t ClockSrc, uint16_t ClockDiv);
extern void TIMER_DynamicConfigCmd(TIMER_TypeDef *TIMERx, FunctionalState Newstate);

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
extern void TIMER_SetLatchTriggerPad(TIMER_TypeDef *TIMERx, uint8_t Pin_num);
extern void TIMER_LatchDebCmd(TIMER_TypeDef *TIMERx, FunctionalState Newstate);
extern void TIMER_SetLatchDebClock(TIMER_TypeDef *TIMERx, uint16_t ClockSrc, uint16_t ClockDiv,
                                   uint16_t CountLimit);
#endif


/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the TIMERx peripheral registers to their default reset values.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return None
  */
void TIMER_DeInit(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    /* Disable timer IP clock and function */
#ifdef IS_TIMER0_PERIPH
    if (IS_TIMER0_PERIPH(TIMERx))
    {
        RCC_ClockCmd(TIMER0_CLOCK, DISABLE);
    }
#endif
#ifdef IS_TIMER1_PERIPH
    if (IS_TIMER1_PERIPH(TIMERx))
    {
        RCC_ClockCmd(TIMER1_CLOCK, DISABLE);
    }
#endif
#ifdef IS_TIMER2_PERIPH
    if (IS_TIMER2_PERIPH(TIMERx))
    {
        RCC_ClockCmd(TIMER2_CLOCK, DISABLE);
    }
#endif
}

/**
  * \brief  Initializes the TIMERx Time Base Unit peripheral according to
  *         the specified parameters in the TIMER_InitStruct.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  TIMER_InitStruct: pointer to a TIMER_TimeBaseInitTypeDef
  *         structure that contains the configuration information for the
  *         specified TIMER peripheral.
  * \return None
  */
void TIMER_TimeBaseInit(TIMER_TypeDef *TIMERx, TIMER_TimeBaseInitTypeDef *TIMER_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_TIMER_MODE(TIMER_InitStruct->TIMER_Mode));
    assert_param(IS_PWM_DeadZone_En(TIMER_InitStruct->PWMDeadZone_En));

    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);

    /* Clock source config */
    TIMER_SetClock(TIMERx,
                   TIMER_InitStruct->TIMER_ClockSrc,
                   TIMER_InitStruct->TIMER_ClockDiv);

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)
    /* Dynamic Config CCR & MAX_CNT */
    TIMER_DynamicConfigCmd(TIMERx, TIMER_InitStruct->TIMER_DynConfigEn);
#endif

    /* Set timer mode */
    TIMER_MODE_CFG_TypeDef timer_0x04 = {.d32 = TIMERx->TIMER_MODE_CFG};
    timer_0x04.b.reg_timer_mode = TIMER_InitStruct->TIMER_Mode;
    timer_0x04.b.reg_timer_oneshot_mode_en = TIMER_InitStruct->TIMER_OneShotEn;
    TIMERx->TIMER_MODE_CFG = timer_0x04.d32;

    if (TIMER_InitStruct->TIMER_Mode == TIMER_MODE_FREERUN)
    {
        if (timercase >= TIMER_CASE4)
        {
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
            /* Config latch0 function. */
            TIMER_LAT_CNT_0_CFG_TypeDef timer_0x1C = {.d32 = TIMERx->TIMER_LAT_CNT_0_CFG};
            timer_0x1C.b.reg_timer_latch_cnt_0_en = TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[0];
            timer_0x1C.b.reg_timer_latch_cnt_0_trig_mode =
                TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[0];
            timer_0x1C.b.reg_timer_latch_cnt_0_fifo_th = TIMER_InitStruct->TIMER_Latch.TIMER_LatchThreshold;
            TIMERx->TIMER_LAT_CNT_0_CFG = timer_0x1C.d32;

            /* Config latch0 trigger. */
            if (TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[0] == ENABLE)
            {
                TIMER_SetLatchTriggerPad(TIMERx, TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerPad);
            }
            /* Config latch0 trigger debounce. */
            if (TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebEn == ENABLE)
            {
                TIMER_LatchDebCmd(TIMERx, ENABLE);
                TIMER_SetLatchDebClock(TIMERx, TIMER_CLOCK_SRC_40M,
                                       TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebClockDiv,
                                       TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebCountLimit);
            }
            else
            {
                TIMER_LatchDebCmd(TIMERx, DISABLE);
            }
#endif
            if (timercase >= TIMER_CASE5)
            {
#if (TIMER_SUPPORT_LATCH_CNT_1 == 1)
                /* Config latch1 function. */
                TIMER_LAT_CNT_1_CFG_TypeDef timer_0x28 = {.d32 = TIMERx->TIMER_LAT_CNT_1_CFG};
                timer_0x28.b.reg_timer_latch_cnt_1_en = TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[1];
                timer_0x28.b.reg_timer_latch_cnt_1_trig_mode =
                    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[1];
                TIMERx->TIMER_LAT_CNT_1_CFG = timer_0x28.d32;

#endif
#if (TIMER_SUPPORT_LATCH_CNT_2 == 1)
                /* Config latch2 function. */
                TIMER_LAT_CNT_2_CFG_TypeDef timer_0x34 = {.d32 = TIMERx->TIMER_LAT_CNT_2_CFG};
                timer_0x34.b.reg_timer_latch_cnt_2_en = TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[2];
                timer_0x34.b.reg_timer_latch_cnt_2_trig_mode =
                    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[2];
                TIMERx->TIMER_LAT_CNT_2_CFG = timer_0x34.d32;
#endif
            }
        }
    }
    else if ((TIMER_InitStruct->TIMER_Mode == TIMER_MODE_USERDEFINE) ||
             (TIMER_InitStruct->TIMER_Mode == TIMER_MODE_USERDEFINE_AUTO))
    {
        /* set timer period */
        TIMERx->TIMER_MAX_CNT = TIMER_InitStruct->TIMER_Period;

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
        if (timercase >= TIMER_CASE7)
        {
            TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
            if (TIMER_InitStruct->PWM_En == DISABLE)
            {
                timer_0x14.b.reg_timer_pwm_en = DISABLE;
                TIMERx->TIMER_PWM_CFG = timer_0x14.d32;
            }
            else
            {
                timer_0x14.b.reg_timer_pwm_en = ENABLE;
                timer_0x14.b.reg_timer_pwm_polarity = TIMER_InitStruct->PWM_Polarity;
                timer_0x14.b.reg_timer_pwm_open_drain_en = TIMER_InitStruct->PWM_OutputMode;
                TIMERx->TIMER_PWM_CFG = timer_0x14.d32;

                /* set pwm high count */
                if (TIMER_InitStruct->TIMER_Mode == TIMER_MODE_USERDEFINE)
                {
                    if (TIMER_InitStruct->PWM_HighCount > TIMER_InitStruct->TIMER_Period)
                    {
                        TIMER_InitStruct->PWM_HighCount = TIMER_InitStruct->TIMER_Period;
                    }
                    if (TIMER_InitStruct->PWM_Polarity == PWM_POLARITY_HIGH)
                    {
                        TIMERx->TIMER_CCR = ((TIMER_InitStruct->TIMER_Period) - \
                                             (TIMER_InitStruct->PWM_HighCount));
                    }
                    else
                    {
                        TIMERx->TIMER_CCR = TIMER_InitStruct->PWM_HighCount;
                    }
                }
            }
        }
#endif
    }

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
    if (timercase >= TIMER_CASE6)
    {
        /* Config PWM Deadzone */
        if (TIMER_InitStruct->PWM_DZ.PWM_DZEn == ENABLE)
        {
            /* Set deadzone clock source and div */
            TIMER_SetPWMDZClock(TIMERx, \
                                TIMER_InitStruct->PWM_DZ.PWM_DZClockSrc, \
                                TIMER_InitStruct->PWM_DZ.PWM_DZClockDiv);

            /* Enable pwm deadzone mode. */
            TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
            timer_0x14.b.reg_timer_pwm_dz_en = ENABLE;
            timer_0x14.b.reg_timer_pwm_dz_stop_state_p = TIMER_InitStruct->PWM_DZ.PWM_DZStopStateP;
            timer_0x14.b.reg_timer_pwm_dz_stop_state_n = TIMER_InitStruct->PWM_DZ.PWM_DZStopStateN;
            timer_0x14.b.reg_timer_pwm_dz_ref_p_inv_en = TIMER_InitStruct->PWM_DZ.PWM_DZInvertP;
            timer_0x14.b.reg_timer_pwm_dz_ref_n_inv_en = TIMER_InitStruct->PWM_DZ.PWM_DZInvertN;
            timer_0x14.b.reg_timer_pwm_dz_size = TIMER_InitStruct->PWM_DZ.PWM_DZSize;
            TIMERx->TIMER_PWM_CFG = timer_0x14.d32;
        }
        else
        {
            /* Disable pwm deadzone mode. */
            TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
            timer_0x14.b.reg_timer_pwm_dz_en = DISABLE;
            TIMERx->TIMER_PWM_CFG = timer_0x14.d32;
        }
    }
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
    if (timercase >= TIMER_CASE3)
    {
        /* DMA function. */
        if (TIMER_InitStruct->TIMER_DMAEn != DISABLE)
        {
            TIMER_DMA_CFG_TypeDef timer_0x40 = {.d32 = TIMERx->TIMER_DMA_CFG};
            timer_0x40.b.reg_timer_dma_en = 1;
            timer_0x40.b.reg_timer_dma_mode = 0;
            timer_0x40.b.reg_timer_dma_target = TIMER_InitStruct->TIMER_DMATarget;
            TIMERx->TIMER_DMA_CFG = timer_0x40.d32;
        }
    }
#endif

    /* Clear the IT */
    TIMER_ClearINT(TIMERx, TIMER_INT_TIMEOUT
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
                   | TIMER_INT_LATCH_FIFO_FULL
                   | TIMER_INT_LATCH_FIFO_THRESHOLD
#endif
                   | TIMER_INT_PAUSE);
}

/**
  * \brief  Fills each TIMER_InitStruct member with its default value.
  * \param  TIMER_InitStruct : pointer to a TIMER_InitTypeDef structure which will be initialized.
  * \return None
  */
void TIMER_StructInit(TIMER_TimeBaseInitTypeDef *TIMER_InitStruct)
{
    TIMER_InitStruct->TIMER_ClockSrc  = TIMER_CLOCK_SRC_40M;
    TIMER_InitStruct->TIMER_ClockDiv  = TIMER_CLOCK_DIV_1;
    TIMER_InitStruct->TIMER_Mode      = TIMER_MODE_USERDEFINE;
    TIMER_InitStruct->TIMER_Period    = 0xfffffff;
    TIMER_InitStruct->TIMER_OneShotEn = DISABLE;

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
    TIMER_InitStruct->PWM_En = DISABLE;
    TIMER_InitStruct->PWM_Polarity   = PWM_POLARITY_HIGH;
    TIMER_InitStruct->PWM_OutputMode = PWM_PUSH_PULL;
    TIMER_InitStruct->PWM_HighCount  = 0;
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
    TIMER_InitStruct->PWM_DZ.PWM_DZClockSrc   = PWM_DZ_CLOCK_SRC_TIMER;
    TIMER_InitStruct->PWM_DZ.PWM_DZClockDiv   = PWM_DZ_CLOCK_DIV_1;
    TIMER_InitStruct->PWM_DZ.PWM_DZStopStateP = PWM_DZ_STOP_AT_LOW;
    TIMER_InitStruct->PWM_DZ.PWM_DZStopStateN = PWM_DZ_STOP_AT_HIGH;
    TIMER_InitStruct->PWM_DZ.PWM_DZInvertP    = DISABLE;
    TIMER_InitStruct->PWM_DZ.PWM_DZInvertN    = DISABLE;
    TIMER_InitStruct->PWM_DZ.PWM_DZEn         = DISABLE;
    TIMER_InitStruct->PWM_DZ.PWM_DZSize       = 10;
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[0]          = DISABLE;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[0] = TIMER_LATCH_TRIGGER_RISING_EDGE;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchThreshold      = 0;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerPad     = 0;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebEn          = DISABLE;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebCountLimit  = 10;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchDebClockDiv    = TIMER_CLOCK_DIV_1;
#endif
#if (TIMER_SUPPORT_LATCH_CNT_1 == 1)
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[1]          = DISABLE;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[1] = TIMER_LATCH_TRIGGER_RISING_EDGE;
#endif
#if (TIMER_SUPPORT_LATCH_CNT_2 == 1)
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchEn[2]          = DISABLE;
    TIMER_InitStruct->TIMER_Latch.TIMER_LatchTriggerMode[2] = TIMER_LATCH_TRIGGER_RISING_EDGE;
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
    TIMER_InitStruct->TIMER_DMAEn     = DISABLE;
    TIMER_InitStruct->TIMER_DMATarget = TIMER_DMA_CCR_FIFO;
#endif

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)
    /* Support dynamic adjustment of CCR & MAX_CNT.  When this
       feature is enabled, dynamic adjustment is supported.
       When this feature is disabled, dynamic adjustment is
       not supported, resulting in lower power consumption.*/
    TIMER_InitStruct->TIMER_DynConfigEn = ENABLE;
#endif
}

/**
  * \brief  Enables or disables the specified TIMER peripheral.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  NewState: new state of the TIMERx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void TIMER_Cmd(TIMER_TypeDef *TIMERx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (NewState != DISABLE)
    {
        sharebase->TIMER_EN_CTRL |= BIT(timerid);
        TIMER_MODE_CFG_TypeDef timer_0x04 = {.d32 = TIMERx->TIMER_MODE_CFG};
        if (timer_0x04.b.reg_timer_oneshot_mode_en)
        {
            sharebase->TIMER_ONESHOT_GO_CTRL |= BIT(timerid);
        }
    }
    else
    {
        sharebase->TIMER_EN_CTRL &= ~(BIT(timerid));
    }
}

/**
  * \brief  Enables or disables the specified TIMERx interrupt.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  NewState: new state of the TIMERx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void TIMER_INTConfig(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (NewState != DISABLE)
    {
        if (TIMER_INT & TIMER_INT_TIMEOUT)
        {
            sharebase->TIMER_INTR_EN_CTRL |= BIT(timerid);
        }
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
        if ((TIMER_INT & TIMER_INT_LATCH_FIFO_FULL) && (timercase >= TIMER_CASE4))
        {
            sharebase->TIMER_LAT_CNT_0_FIFO_FULL_INTR_EN_CTRL |= BIT(timerid);
        }
        if ((TIMER_INT & TIMER_INT_LATCH_FIFO_THRESHOLD) && (timercase >= TIMER_CASE4))
        {
            sharebase->TIMER_LAT_CNT_0_FIFO_MET_THRESHOLD_INTR_EN_CTRL |= BIT(timerid);
        }
#endif
        if (TIMER_INT & TIMER_INT_PAUSE)
        {
            sharebase->TIMER_PAUSE_INTR_EN_CTRL |= BIT(timerid);
        }
    }
    else
    {

        if (TIMER_INT & TIMER_INT_TIMEOUT)
        {
            sharebase->TIMER_INTR_EN_CTRL &= ~(BIT(timerid));
        }
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
        if ((TIMER_INT & TIMER_INT_LATCH_FIFO_FULL) && (timercase >= TIMER_CASE4))
        {
            sharebase->TIMER_LAT_CNT_0_FIFO_FULL_INTR_EN_CTRL &= ~(BIT(timerid));
        }
        if ((TIMER_INT & TIMER_INT_LATCH_FIFO_THRESHOLD) && (timercase >= TIMER_CASE4))
        {
            sharebase->TIMER_LAT_CNT_0_FIFO_MET_THRESHOLD_INTR_EN_CTRL &= ~(BIT(timerid));
        }
#endif
        if (TIMER_INT & TIMER_INT_PAUSE)
        {
            sharebase->TIMER_PAUSE_INTR_EN_CTRL &= ~(BIT(timerid));
        }
    }
}


/**
 * \brief   Check whether the TIMER interrupt has occurred or not.
 * \param   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \return  The new state of the TIMER_INTR(SET or RESET).
 */
ITStatus TIMER_GetINTStatus(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    ITStatus itstatus = RESET;
    if (TIMER_INT == TIMER_INT_TIMEOUT)
    {
        if (sharebase->TIMER_INTR & BIT(timerid))
        {
            itstatus = SET;
        }
    }
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
    else if ((TIMER_INT == TIMER_INT_LATCH_FIFO_FULL) && (timercase >= TIMER_CASE4))
    {
        if (sharebase->TIMER_LAT_CNT_0_FIFO_FULL_INTR & BIT(timerid))
        {
            itstatus = SET;
        }
    }
    else if ((TIMER_INT == TIMER_INT_LATCH_FIFO_THRESHOLD) && (timercase >= TIMER_CASE4))
    {
        if (sharebase->TIMER_LAT_CNT_0_FIFO_MET_THRESHOLD_INTR & BIT(timerid))
        {
            itstatus = SET;
        }
    }
#endif
    else if (TIMER_INT == TIMER_INT_PAUSE)
    {
        if (sharebase->TIMER_PAUSE_INTR & BIT(timerid))
        {
            itstatus = SET;
        }
    }

    return itstatus;
}


/**
 * \brief   Clear TIMER interrupt.
 * \param   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \return  None.
 */
void TIMER_ClearINT(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    /* Clear the IT */
    if (TIMER_INT & TIMER_INT_TIMEOUT)
    {
        sharebase->TIMER_INTR_STS = BIT(timerid);
    }
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
    if ((TIMER_INT & TIMER_INT_LATCH_FIFO_FULL) && (timercase >= TIMER_CASE4))
    {
        sharebase->TIMER_LAT_CNT_0_FIFO_FULL_INTR = BIT(timerid);
    }
    if ((TIMER_INT & TIMER_INT_LATCH_FIFO_THRESHOLD) && (timercase >= TIMER_CASE4))
    {
        sharebase->TIMER_LAT_CNT_0_FIFO_MET_THRESHOLD_INTR = BIT(timerid);
    }
#endif
    if (TIMER_INT & TIMER_INT_PAUSE)
    {
        sharebase->TIMER_PAUSE_INTR_STS = BIT(timerid);
    }
}

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Check whether the specified TIMER flag is set.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  TIMER_FLAG: Specifies the flag to check.
  * \return The new state of TIMER_FLAG (SET or RESET).
  */
FlagStatus TIMER_GetFIFOFlagStatus(TIMER_TypeDef *TIMERx, uint32_t TIMER_FLAG)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);
    FlagStatus flagstatus = RESET;

    if ((TIMER_FLAG == TIMER_FLAG_CCR_FIFO_FULL) && (timercase >= TIMER_CASE2))
    {
        if (sharebase->TIMER_CCR_FIFO_FULL_STS & BIT(timerid))
        {
            flagstatus = SET;
        }
    }
    else if ((TIMER_FLAG == TIMER_FLAG_CCR_FIFO_EMPTY) && (timercase >= TIMER_CASE2))
    {
        if (sharebase->TIMER_CCR_FIFO_EMPTY_STS & BIT(timerid))
        {
            flagstatus = SET;
        }
    }
    else if ((TIMER_FLAG == TIMER_FLAG_LATCH_FIFO_EMPTY) && (timercase >= TIMER_CASE4))
    {
        if (sharebase->TIMER_LAT_CNT_0_FIFO_EMPTY_STS & BIT(timerid))
        {
            flagstatus = SET;
        }
    }

    return flagstatus;
}
#endif

/**
  * \brief  change TIMER period value.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return The new state of success or not  (SET or RESET).
  */
void TIMER_ChangePeriod(TIMER_TypeDef *TIMERx, uint32_t period)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->TIMER_MAX_CNT = period;

    return;
}

/**
  * \brief  Get TIMER period value.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return TIMER period value.
  */
uint32_t TIMER_GetPeriod(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return TIMERx->TIMER_MAX_CNT;
}

/**
 * \brief   Get TIMERx current value when timer is running.
 * \param   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \return  The counter value.
 */
uint32_t TIMER_GetCurrentValue(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return TIMERx->TIMER_CUR_CNT;
}

/**
 * \brief  Get TIMERx elapsed value when timer is running.
 * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \return The elapsed counter value.
 */
uint32_t TIMER_GetElapsedValue(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return (TIMERx->TIMER_MAX_CNT - TIMERx->TIMER_CUR_CNT);
}

/**
 * \brief   Check whether the TIMER is in operation or not.
 * \param   TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \return  The new state of the timer operation status (SET or RESET).
 */
FlagStatus TIMER_GetOperationStatus(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);
    FlagStatus flagstatus = RESET;

    TIMER_MODE_CFG_TypeDef timer_0x04 = {.d32 = TIMERx->TIMER_MODE_CFG};

    if (timer_0x04.b.reg_timer_oneshot_mode_en)
    {
        if (sharebase->TIMER_ONESHOT_GO_CTRL & BIT(timerid))
        {
            flagstatus = SET;
        }
    }
    else
    {
        if (sharebase->TIMER_EN_CTRL & BIT(timerid))
        {
            flagstatus = SET;
        }
    }

    return flagstatus;
}

/**
  * \brief  Enable/disable to pause timer counter.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  NewState: New state of the TIMERx peripheral.
  * \return None.
  */
void TIMER_PauseCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (NewState != DISABLE)
    {
        sharebase->TIMER_PAUSE_CTRL |= BIT(timerid);
    }
    else
    {
        sharebase->TIMER_PAUSE_CTRL &= ~(BIT(timerid));
    }
}

#if (TIMER_SUPPORT_CCR_FIFO == 1)
/**
  * \brief  Set TIMERx capture/compare value for user-define PWM auto mode.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  value:  User-defined TIMER capture/compare value for PWM auto mode,
  *         ranging from 0 to 2^31.
  * \return None
  */
void TIMER_SetCompareFIFO(TIMER_TypeDef *TIMERx, uint32_t value)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->TIMER_CCR_FIFO = value;
}
#endif

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Clear capture/compare or latch count0 fifo.
  * \param  TIMERx: Select the ENHTIMER peripheral. \ref TIMER_Declaration
  * \param  FIFO_CLR: Specifies the FIFO type which to be clear.
  * \return FIFO data length.
  */
void TIMER_ClearFIFO(TIMER_TypeDef *TIMERx, uint8_t FIFO_CLR)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);

    if (FIFO_CLR == TIMER_CLEAR_CCR_FIFO)
    {
        TIMER_MODE_CFG_TypeDef timer_0x04 = {.d32 = TIMERx->TIMER_MODE_CFG};
        timer_0x04.b.reg_timer_ccr_fifo_clr = 1;
        TIMERx->TIMER_MODE_CFG = timer_0x04.d32;
    }
    else if (FIFO_CLR == TIMER_CLEAR_LATCH_FIFO)
    {
        TIMER_LAT_CNT_0_CFG_TypeDef timer_0x1c = {.d32 = TIMERx->TIMER_LAT_CNT_0_CFG};
        timer_0x1c.b.reg_timer_latch_cnt_0_fifo_clr = 1;
        TIMERx->TIMER_LAT_CNT_0_CFG = timer_0x1c.d32;
    }
}
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Read TIMERx latch counter0 fifo data.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  length: Latch count0 fifo length, max 8.
  * \pBuf   pBuf: FIFO data out buffer.
  * \return None.
  */
void TIMER_GetLatchFIFO(TIMER_TypeDef *TIMERx, uint32_t *pBuf, uint8_t length)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    if ((pBuf == NULL) || (length > 8))
    {
        return;
    }

    for (uint8_t i = 0; i < length; i++)
    {
        pBuf[i] = TIMERx->TIMER_LAT_CNT_0;
    }
}

/**
  * \brief  Get TIMER latch counter0 fifo length.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return FIFO data length.
  */
uint8_t TIMER_GetLatchFIFOLength(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    return (uint8_t)(TIMERx->TIMER_LAT_CNT_0_FIFO_DEPTH) & 0xFF;
}
#endif

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
/**
  * \brief  Change PWM freq and duty according high_cnt and low_cnt
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  period: This parameter controls the frequency, ranging from 0x0000 to 0xFFFFFFFF.
  * \param  high_count: This parameter controls the duty cycle, ranging from 0x0000 to 0xFFFFFFFF.
  * \return None
  */
void TIMER_PWMChangeFreqAndDuty(TIMER_TypeDef *TIMERx, uint32_t period, uint32_t high_count)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMER_MODE_CFG_TypeDef timer_0x04 = {.d32 = TIMERx->TIMER_MODE_CFG};
    uint16_t timer_mode = timer_0x04.b.reg_timer_mode;

    TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
    uint16_t timer_polarity = timer_0x14.b.reg_timer_pwm_polarity;

    TIMERx->TIMER_MAX_CNT = period;

    if (timer_polarity == PWM_POLARITY_HIGH)
    {
        if (high_count > period)
        {
            high_count = period;
        }
        if (timer_mode == TIMER_MODE_USERDEFINE)
        {
            TIMERx->TIMER_CCR = (period - high_count);
        }
        else if (timer_mode == TIMER_MODE_USERDEFINE_AUTO)
        {
            TIMERx->TIMER_CCR_FIFO = (period - high_count);
        }
    }
    else
    {
        if (timer_mode == TIMER_MODE_USERDEFINE)
        {
            TIMERx->TIMER_CCR = high_count;
        }
        else if (timer_mode == TIMER_MODE_USERDEFINE_AUTO)
        {
            TIMERx->TIMER_CCR_FIFO = high_count;
        }
    }
}

/**
  * \brief  Get TIMER toggle state
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \return The new state of toggle state(SET or RESET).
  */
bool TIMER_GetToggleState(TIMER_TypeDef *TIMERx)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMERCASE_TypeDef timercase = TIMER_GetTimerCase(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (((sharebase->TIMER_PWM_STATE & BIT(timerid)) != 0) && (timercase > TIMER_CASE1))
    {
        return true;
    }

    return false;
}

/**
  * \brief  Change TIMER pwm_phase_shift count
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  PhaseShiftCnt:This parameter can be 0 to ccr;
  * \return None
  */
#if (TIMER_SUPPORT_PWM_PHASE_SHIFT == 1)
void TIMER_SetShiftCount(TIMER_TypeDef *TIMERx, uint32_t ShiftCount)
{
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMERx->TIMER_PWM_SHIFT_CNT = ShiftCount;
}
#endif


#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
/**
 * \brief  TIMER PWMP/N Source Select.
 * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
 * \param  PWMSrcSel: State of the TIMERx PWMP/N.
 * \return None.
 */
void TIMER_SetPWMDZRef(TIMER_TypeDef *TIMERx, PWMDZRef_TypeDef PWMDZRef)
{
    /* Check the parameters. */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
    timer_0x14.b.reg_timer_pwm_dz_ref_sel = PWMDZRef;
    TIMERx->TIMER_PWM_CFG = timer_0x14.d32;
}
#endif

/**
 * \brief  PWM complementary output emergency stop.
 *         PWM_P emergency stop level state is configured by PWM_Stop_State_P,
 *         PWM_N emergency stop level state is configured by PWM_Stop_State_N.
 * \param  PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param  NewState: New state of complementary output.
 *         \arg DISABLE: Resume PWM complementary output.
 *         \arg ENABLE: PWM complementary output emergency stop.
 * \return None.
 * \note   To use this function, need to configure the corresponding timer.
 *         PWM2 ->> TIMER2, PWM3 ->> TIMER3.
 */
void TIMER_PWMComplOutputEMCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    TIMER_PWM_CFG_TypeDef timer_0x14 = {.d32 = TIMERx->TIMER_PWM_CFG};
    timer_0x14.b.reg_timer_pwm_dz_emg_stop = NewState;
    TIMERx->TIMER_PWM_CFG = timer_0x14.d32;
}
#endif

#if (TIMER_SUPPORT_RAP_FUNCTION == 1)

void TIMER_RAPModeCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (NewState != DISABLE)
    {
        sharebase->TIMER_RAP_CTRL0 |= BIT(timerid);
        sharebase->TIMER_RAP_CTRL1 |= BIT(timerid);
    }
    else
    {
        sharebase->TIMER_RAP_CTRL0 &= ~BIT(timerid);
        sharebase->TIMER_RAP_CTRL1 &= ~BIT(timerid);
    }
    return;
}

void TIMER_ActionTrigger(TIMER_TypeDef *TIMERx, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (Action == TIMER_ACTION_START)
    {
        sharebase->TIMER_RAP_FW_TSAK_START |= BIT(timerid);
    }
    else if (Action == TIMER_ACTION_PAUSE)
    {
        sharebase->TIMER_RAP_FW_TASK_PAUSE |= BIT(timerid);
    }
    else if (Action == TIMER_ACTION_STOP)
    {
        sharebase->TIMER_RAP_FW_TASK_DISABLE |= BIT(timerid);
    }

    return;
}

void TIMER_ShortcutCmd(TIMER_TypeDef *TIMERx, uint32_t Action, uint32_t Event,
                       FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (NewState != DISABLE)
    {
        if (Action == TIMER_SHORTCUT_ACTION_PAUSE)
        {
            sharebase->TIMER_RAP_SHORTCUT_SUB_TASK_PAUSE |= BIT(timerid);
        }
        else if (Action == TIMER_SHORTCUT_ACTION_STOP)
        {
            sharebase->TIMER_RAP_SHORTCUT_SUB_TASK_DISABLE |= BIT(timerid);
        }
        if (Event == TIMER_SHORTCUT_EVENT_TIMEOUT)
        {
            sharebase->TIMER_RAP_SHORTCUT_PUB_EVENT_TIMEOUT |= BIT(timerid);
        }
    }
    else
    {
        if (Action == TIMER_SHORTCUT_ACTION_PAUSE)
        {
            sharebase->TIMER_RAP_SHORTCUT_SUB_TASK_PAUSE &= ~BIT(timerid);
        }
        else if (Action == TIMER_SHORTCUT_ACTION_STOP)
        {
            sharebase->TIMER_RAP_SHORTCUT_SUB_TASK_DISABLE &= ~BIT(timerid);
        }
        if (Event == TIMER_SHORTCUT_EVENT_TIMEOUT)
        {
            sharebase->TIMER_RAP_SHORTCUT_PUB_EVENT_TIMEOUT &= ~BIT(timerid);
        }
    }
    return;
}
#endif


