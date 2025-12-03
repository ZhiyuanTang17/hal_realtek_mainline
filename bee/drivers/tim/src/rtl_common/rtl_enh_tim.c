/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_enh_tim.c
* \brief    This file provides all the Timer firmware functions.
* \details
* \author   Grace_yan
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_enh_tim.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                          Private Functions
 *============================================================================*/
extern uint32_t ENHTIM_GetTimerID(ENHTIM_TypeDef *ENHTIMx);

extern void ENHTIM_ConfigLatchTrigger(uint32_t enhtim_id, \
                                      const ENHTIM_InitTypeDef *ENHTIM_InitStruct);
extern void ENHTIM_ConfigLatchTriggerBtTxOn(uint32_t enhtim_id,
                                            const ENHTIM_InitTypeDef *ENHTIM_InitStruct);
extern void ENHTIM_ConfigLatchTriggerBtAccHit(uint32_t enhtim_id,
                                              const ENHTIM_InitTypeDef *ENHTIM_InitStruct);
extern void ENHTIM_PWMDeadzoneConfig(uint32_t enhtim_id, \
                                     const ENHTIM_InitTypeDef *ENHTIM_InitStruct);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Initializes the ENHTIMx peripheral according to
  *         the specified parameters in the ENHTIM_InitStruct.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ENHTIM_InitStruct: pointer to a ENHTIM_InitTypeDef structure
  *         that contains the configuration information for the specified ENHTIM peripheral.
  * \return None
  */
void ENHTIM_Init(ENHTIM_TypeDef *ENHTIMx, ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    /* Clock source config */
    ENH_TIM_SHARE->ENHTIM_CONTROL &= ~BIT(enhtim_id);
    ENH_TIM_SHARE->ENHTIM_INT_CONTROL &= ~BIT(enhtim_id);

    /* Clock source config */
    ENHTIM_ClkConfig(ENHTIMx,
                     ENHTIM_InitStruct->ENHTIM_ClockSource,
                     ENHTIM_InitStruct->ENHTIM_ClockDiv);

#if ENHTIM_SUPPORT_ONESHOT_CMD
    if (ENHTIM_InitStruct->ENHTIM_OneShotEn == ENABLE)
    {
        REG_ENHTIMER_ONESHOT |= BIT(enhtim_id);
    }
    else
    {
        REG_ENHTIMER_ONESHOT &= ~BIT(enhtim_id);
    }
#endif
    /* Config latch function. */
    ENHTIM_CONFIGURE_TypeDef enhtim_0x10 = {.d32 = ENHTIMx->ENHTIM_CONFIGURE};
    enhtim_0x10.b.Enhtimer_mode = 0x0;
    ENHTIMx->ENHTIM_CONFIGURE = enhtim_0x10.d32;

    enhtim_0x10.d32 = ENHTIMx->ENHTIM_CONFIGURE;
#if ENHTIM_SUPPORT_LATCH_CNT_0
    enhtim_0x10.b.Enhtimer_Latch_cnt_0_en = ENHTIM_InitStruct->ENHTIM_LatchCountEn[0] & 0x01;
    enhtim_0x10.b.Enhtimer_latch_cnt_0_trig_mode = ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[0] &
                                                   0x03;
    enhtim_0x10.b.Enhtimer_latch_cnt_0_fifo_th = ENHTIM_InitStruct->ENHTIM_LatchCountThd & 0x1F;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    enhtim_0x10.b.Enhtimer_Latch_cnt_1_en = ENHTIM_InitStruct->ENHTIM_LatchCountEn[1] & 0x01;
    enhtim_0x10.b.Enhtimer_latch_cnt_1_trig_mode = ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[1] &
                                                   0x03;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    enhtim_0x10.b.Enhtimer_Latch_cnt_2_en = ENHTIM_InitStruct->ENHTIM_LatchCountEn[2] & 0x01;
    enhtim_0x10.b.Enhtimer_latch_cnt_2_trig_mode = ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[2] &
                                                   0x03;
#endif
    ENHTIMx->ENHTIM_CONFIGURE = enhtim_0x10.d32;

    /* Config latch trigger. */
#if ENHTIM_SUPPORT_LATCH_CNT_0
    if (ENHTIM_InitStruct->ENHTIM_LatchCountEn[0] == ENABLE)
    {
        ENHTIM_ConfigLatchTrigger(enhtim_id, ENHTIM_InitStruct);
    }
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    if (ENHTIM_InitStruct->ENHTIM_LatchCountEn[1] == ENABLE)
    {
        ENHTIM_ConfigLatchTriggerBtTxOn(enhtim_id, ENHTIM_InitStruct);
    }
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    if (ENHTIM_InitStruct->ENHTIM_LatchCountEn[2] == ENABLE)
    {
        ENHTIM_ConfigLatchTriggerBtAccHit(enhtim_id, ENHTIM_InitStruct);
    }
#endif

    /* Config PWM mode. */
    if ((ENHTIM_InitStruct->ENHTIM_Mode == ENHTIM_MODE_PWM_AUTO) ||
        (ENHTIM_InitStruct->ENHTIM_Mode == ENHTIM_MODE_PWM_MANUAL))
    {
        enhtim_0x10.d32 = ENHTIMx->ENHTIM_CONFIGURE;
        enhtim_0x10.b.Enhtimer_PWM_polarity = ENHTIM_InitStruct->ENHTIM_PWMStartPolarity;
        enhtim_0x10.b.Enhtimer_PWM_output_en = ENHTIM_InitStruct->ENHTIM_PWMOutputEn;
        enhtim_0x10.b.Enhtimer_mode = ENHTIM_InitStruct->ENHTIM_Mode;
        ENHTIMx->ENHTIM_CONFIGURE = enhtim_0x10.d32;

        ENHTIM_MAX_CNT_TypeDef enhtim_0x14 = {.d32 = ENHTIMx->ENHTIM_MAX_CNT};
        enhtim_0x14.b.Enhtimer_max_cnt = ENHTIM_InitStruct->ENHTIM_MaxCount;
        ENHTIMx->ENHTIM_MAX_CNT = enhtim_0x14.d32;
    }

    if (ENHTIM_InitStruct->ENHTIM_Mode == ENHTIM_MODE_PWM_MANUAL)
    {
        ENHTIM_CCR_TypeDef enhtim_0x18 = {.d32 = ENHTIMx->ENHTIM_CCR};
        enhtim_0x18.b.Enhtimer_ccr = ENHTIM_InitStruct->ENHTIM_CCValue;
        ENHTIMx->ENHTIM_CCR = enhtim_0x18.d32;
    }

    /* Config PWM Deadzone */
    ENHTIM_PWMDeadzoneConfig(enhtim_id, ENHTIM_InitStruct);

    /* DMA function. */
    if (ENHTIM_InitStruct->ENHTIM_DmaEn != DISABLE)
    {
        enhtim_0x10.b.Enhtimer_dma_en = ENABLE;
        enhtim_0x10.b.Enhtimer_dma_mode = ENHTIM_DMAC_FLOW_CONTROL;
        enhtim_0x10.b.Enhtimer_dma_target = ENHTIM_InitStruct->ENHTIM_DmaTragget;
        ENHTIMx->ENHTIM_CONFIGURE = enhtim_0x10.d32;
    }

    /* Clear the IT status */
    ENH_TIM_SHARE->ENHTIM_LACTH_FIFO_TH_STATUS |= BIT(enhtim_id);
    ENH_TIM_SHARE->ENHTIM_LATCH_CNT_FIFO_STATUS |= BIT(enhtim_id * 2);
    ENH_TIM_SHARE->ENHTIM_STATUS |= BIT(enhtim_id);
    ENH_TIM_SHARE->ENHTIM_STATUS |= BIT(enhtim_id + 8);
}

/**
  * \brief  Fills each ENHTIM_InitStruct member with its default value.
  * \param  ENHTIM_InitStruct: Pointer to a ENHTIM_InitStruct structure which will be initialized.
  * \return None.
  */
void ENHTIM_StructInit(ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    ENHTIM_InitStruct->ENHTIM_ClockSource           = ENHTIM_CLOCK_SOURCE_40M;
    ENHTIM_InitStruct->ENHTIM_ClockDiv_En           = DISABLE;
    ENHTIM_InitStruct->ENHTIM_ClockDiv              = ENHTIM_CLOCK_DIVIDER_1;
    ENHTIM_InitStruct->ENHTIM_Mode                  = ENHTIM_MODE_FreeRun;
    ENHTIM_InitStruct->ENHTIM_PWMOutputEn           = DISABLE;
    ENHTIM_InitStruct->ENHTIM_PWMStartPolarity      = ENHTIM_PWM_START_WITH_LOW;
#if ENHTIM_SUPPORT_ONESHOT_CMD
    ENHTIM_InitStruct->ENHTIM_OneShotEn             = DISABLE;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_0
    ENHTIM_InitStruct->ENHTIM_LatchCountEn[0]       = DISABLE;
    ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[0]  = ENHTIM_LATCH_TRIGGER_RISING_EDGE;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    ENHTIM_InitStruct->ENHTIM_LatchCountEn[1]       = DISABLE;
    ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[1]  = ENHTIM_LATCH_TRIGGER_RISING_EDGE;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    ENHTIM_InitStruct->ENHTIM_LatchCountEn[2]       = DISABLE;
    ENHTIM_InitStruct->ENHTIM_LatchCountTrigger[2]  = ENHTIM_LATCH_TRIGGER_RISING_EDGE;
#endif
    ENHTIM_InitStruct->ENHTIM_LatchCountThd         = 3;
    ENHTIM_InitStruct->ENHTIM_LatchTriggerPad       = P0_0;
    ENHTIM_InitStruct->ENHTIM_MaxCount              = 0xFFFFFFFE;//range 0x1~0xFFFFFFFE
    ENHTIM_InitStruct->ENHTIM_CCValue               = 0x0;

    ENHTIM_InitStruct->ENHTIM_PWMDeadZoneClockSource    = ENHTIM_PWM_DZCLKSRCE_32K;
    ENHTIM_InitStruct->ENHTIM_PWMDeadZone_ClockDivEn    = DISABLE;
    ENHTIM_InitStruct->ENHTIM_PWMDeadZone_ClockDiv      = ENHTIM_CLOCK_DIVIDER_1;
    ENHTIM_InitStruct->ENHTIM_PWMDeadZoneEn             = DISABLE;
    ENHTIM_InitStruct->ENHTIM_PWMStopStateP             = ENHTIM_PWM_STOP_AT_HIGH;
    ENHTIM_InitStruct->ENHTIM_PWMStopStateN             = ENHTIM_PWM_STOP_AT_LOW;
    ENHTIM_InitStruct->ENHTIM_DeadZoneSize              = 0xFF;/*!< range 0x1 ~ 0xFF */
    ENHTIM_InitStruct->ENHTIM_DmaEn                   = DISABLE;

    ENHTIM_InitStruct->ENHTIM_DmaTragget              = ENHTIM_DMA_CCR_FIFO;
}

/**
  * \brief  Enable or disable the specified ENHTIM peripheral.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  NewState: New state of the ENHTIMx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void ENHTIM_Cmd(ENHTIM_TypeDef *ENHTIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    if (NewState != DISABLE)
    {
        /* Enable the TIM Counter */
        ENH_TIM_SHARE->ENHTIM_CONTROL |= BIT(enhtim_id);
    }
    else
    {
        /* Disable the TIM Counter */
        ENH_TIM_SHARE->ENHTIM_CONTROL &= ~(BIT(enhtim_id));
    }
}

/**
  * \brief  Enable or disable the specified ENHTIM peripheral.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  NewState: New state of the ENHTIMx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
#if ENHTIM_SUPPORT_ONESHOT_CMD
void ENHTIM_OneShotCmd(ENHTIM_TypeDef *ENHTIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    if (NewState != DISABLE)
    {
        /*oneshot_mode_en*/
        REG_ENHTIMER_ONESHOT |= BIT(enhtim_id);

        /* Enable the TIM Counter */
        ENH_TIM_SHARE->ENHTIM_CONTROL |= BIT(enhtim_id);

        /*oneshot_mode_go*/
        REG_ENHTIMER_ONESHOT |= BIT(enhtim_id + 8);
    }
    else
    {
        /*oneshot_mode_en*/
        REG_ENHTIMER_ONESHOT &= ~BIT(enhtim_id);

        /* Disable the TIM Counter */
        ENH_TIM_SHARE->ENHTIM_CONTROL &= ~(BIT(enhtim_id));

        /*oneshot_mode_en*/
        REG_ENHTIMER_ONESHOT &= ~BIT(enhtim_id + 8);
    }
}
#endif

/**
  * \brief  Enable or disable ENHTIMx interrupt.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 interrupt source.
  * \param  NewState: New state of the ENHTIMx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void ENHTIM_INTConfig(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));
    assert_param(IS_ENHTIM_INT(ENHTIM_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    if (NewState != DISABLE)
    {
        /* Enable the ENHTIM Interrupt */
        if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_FULL)
        {
            ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_0 |= BIT(8) << enhtim_id;
        }
        else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_THD)
        {
            ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_2 |= BIT(8) << enhtim_id;
        }
        else
        {
            ENH_TIM_SHARE->ENHTIM_INT_CONTROL |= BIT(enhtim_id);
        }
    }
    else
    {
        /* Disable the ENHTIM Interrupt */
        if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_FULL)
        {
            ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_0 &= ~(BIT(8) << enhtim_id);
        }
        else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_THD)
        {
            ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_2 &= ~ BIT(8) << enhtim_id;
        }
        else
        {
            ENH_TIM_SHARE->ENHTIM_INT_CONTROL &= ~BIT(enhtim_id);
        }
    }
}

/**
  * \brief  Check whether the ENHTIM latch count0 fifo has data or not.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \return The new state of the specified ENHTIMx peripheral
  *         latch count0 fifo (SET or RESET).
  */
ITStatus ENHTIM_GetLCFIFOStatus(ENHTIM_TypeDef *ENHTIMx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    if (ENH_TIM_SHARE->ENHTIM_STATUS & ((BIT(8) << enhtim_id)))
    {
        return SET;
    }

    return RESET;
}

/**
  * \brief  Read ENHTIMx latch counter fifo data.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  length: Latch count0 fifo length, max 32.
  * \pBuf   pBuf: FIFO data out buffer.
  * \return None.
  */
void ENHTIM_ReadLatchCountFIFO(ENHTIM_TypeDef *ENHTIMx, uint32_t *pBuf, uint8_t length)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    if ((pBuf == 0) || (length > 31))
    {
        return;
    }

    for (uint8_t i = 0; i < length; i++)
    {
        pBuf[i] = ENHTIMx->ENHTIM_LATCH_CNT_0;
    }
}

/**
  * \brief  Check whether the ENHTIM interrupt has occurred or not.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_EMPTY: Enhance Timer latch count0 fifo empty interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
  * \return The new state of the ENHTIM_INT(SET or RESET).
  */
ITStatus ENHTIM_GetINTStatus(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));
    assert_param(IS_ENHTIM_INT(INT));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);
    ITStatus itstatus = RESET;

    if (ENHTIM_INT == ENHTIM_INT_TIM)
    {
        itstatus = (ITStatus)((ENH_TIM_SHARE->ENHTIM_STATUS) >> (enhtim_id));
    }
    else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_FULL)
    {
        itstatus = (ITStatus)(((ENH_TIM_SHARE->ENHTIM_LATCH_CNT_FIFO_STATUS) >> (enhtim_id * 2)) & 0x01);
    }
    else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_THD)
    {
        itstatus = (ITStatus)(((ENH_TIM_SHARE->ENHTIM_LACTH_FIFO_TH_STATUS) >> (enhtim_id)) & 0x01);
    }
    else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_EMPTY)
    {
        itstatus = (ITStatus)(((ENH_TIM_SHARE->ENHTIM_LATCH_CNT_FIFO_STATUS) >>
                               (1 + enhtim_id * 2)) & 0x01);
    }

    return itstatus;
}

/**
  * \brief  Clear ENHTIM interrupt.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ENHTIM_INT: Specifies the ENHTIMx interrupt source which to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg ENHTIM_INT_TIM: Enhance Timer interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_FULL: Enhance Timer latch count0 fifo full interrupt source.
  *         \arg ENHTIM_INT_LATCH_CNT_FIFO_THD: Enhance Timer latch count0 fifo threshold interrupt source.
  * \return None.
 */
void ENHTIM_ClearINTPendingBit(ENHTIM_TypeDef *ENHTIMx, uint8_t ENHTIM_INT)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    /* Clear the IT */
    if (ENHTIM_INT == ENHTIM_INT_TIM)
    {
        ENH_TIM_SHARE->ENHTIM_STATUS |= BIT(enhtim_id);
    }
    else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_FULL)
    {
        ENH_TIM_SHARE->ENHTIM_LATCH_CNT_FIFO_STATUS |= BIT(enhtim_id * 2);
    }
    else if (ENHTIM_INT == ENHTIM_INT_LATCH_CNT_FIFO_THD)
    {
        ENH_TIM_SHARE->ENHTIM_LACTH_FIFO_TH_STATUS |= BIT(enhtim_id);
    }
}

/**
  * \brief  Change ENHTIME PWM freq and duty according high_cnt
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  enhtim_mode: This parameter can be ENHTIM_MODE_PWM_MANUAL or ENHTIM_MODE_PWM_AUTO.
  * \param  max_count: Timer max counter value for user-define mode
  *         This parameter can be 1 ~ 2^32-2
  * \param  high_count: Timer capture/compare value for user-define manual mode or timer capture/compare fifo entry for user-define auto mode.
  *         This parameter can be 0 ~ 2^32-2
  * \return None
  */
void ENHTIM_PWMChangeFreqAndDuty(ENHTIM_TypeDef *ENHTIMx, uint16_t enhtim_mode, uint32_t max_count,
                                 uint32_t high_count)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIMx->ENHTIM_MAX_CNT = max_count;

    if (enhtim_mode == ENHTIM_MODE_PWM_MANUAL)
    {
        ENHTIMx->ENHTIM_CCR = high_count;
    }
    else if (enhtim_mode == ENHTIM_MODE_PWM_AUTO)
    {
        ENHTIMx->ENHTIM_CCR_FIFO_ENTRY = high_count;
    }
}

/**
  * \brief  Get ENHTIME toggle state
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \return The new state of toggle state(SET or RESET).
  */
bool ENHTIM_GetToggleState(ENHTIM_TypeDef *ENHTIMx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    if (((ENH_TIM_SHARE->ENHTIM_TOGGLE_STATE)&BIT(enhtim_id)) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
  * \brief  Change Enhtimer pwm_phase_shift count
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  PhaseShiftCnt:This parameter can be 0 to ccr ;
  * \return None
  */
#if ENHTIM_SUPPORT_PWM_PHASE_SHIFT
void ENHTIM_PhaseShiftCnt(ENHTIM_TypeDef *ENHTIMx, uint32_t PhaseShiftCnt)
{
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));
    if (PhaseShiftCnt > 0xFFFFFFFF)
    {
        PhaseShiftCnt = 0xFFFFFFFF;
    }
    ENHTIMx->PHASE_SHIFT_CNT  =  PhaseShiftCnt ;
}
#endif

/**
  * \brief  Get Enhtimer current count
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \return None
  */
uint32_t ENHTIM_GetCurrentCount(ENHTIM_TypeDef *ENHTIMx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    return ENHTIMx->ENHTIM_CUR_CNT;
}

/**
  * \brief  Set Max Count value.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  count: Max counter value for user-define PWM mode (leagel value: 0 ~ 2^32-2).
  * \return None
  */
void ENHTIM_SetMaxCount(ENHTIM_TypeDef *ENHTIMx, uint32_t count)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIMx->ENHTIM_MAX_CNT = count & 0xFFFFFFFE;
}

/**
  * \brief  Set ENHTIMx capture/compare value for user-define PWM manual mode.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  value: User-defined EnhtimerN capture/compare value for PWM manual mode,
  *            ranging from 0 to 2^31.
  * \return None
  */
void ENHTIM_SetCCValue(ENHTIM_TypeDef *ENHTIMx, uint32_t value)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIMx->ENHTIM_CCR = value;
}

/**
  * \brief  Set ENHTIMx capture/compare value for user-define PWM auto mode.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  value:  User-defined EnhtimerN capture/compare value for PWM manual mode,
  *            ranging from 0 to 2^31.
  * \return None
  */
void ENHTIM_WriteCCFIFO(ENHTIM_TypeDef *ENHTIMx, uint32_t value)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIMx->ENHTIM_CCR_FIFO_ENTRY = value;
}

/**
  * \brief  Check whether the specified ENHTIM flag is set.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ENHTIM_FLAG: Specifies the flag to check.
  * \return The new state of ENHTIM_FLAG (SET or RESET).
  */
FlagStatus ENHTIM_GetFIFOFlagStatus(ENHTIM_TypeDef *ENHTIMx, uint32_t ENHTIM_FLAG)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_FIFO_FLAG(ENHTIM_FLAG));

    FlagStatus bitstatus = RESET;
    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);
    uint32_t pos = ENHTIM_FLAG & BIT0;
    uint32_t bit_id = BIT(enhtim_id * 2);

    if (ENHTIM_FLAG == ENHTIM_FLAG_LC_FIFO_FULL || ENHTIM_FLAG == ENHTIM_FLAG_LC_FIFO_EMPTY)
    {
        if (ENH_TIM_SHARE -> ENHTIM_LATCH_CNT_FIFO_STATUS & (bit_id << pos))
        {
            bitstatus = SET;
        }
    }
    else if (ENHTIM_FLAG == ENHTIM_FLAG_CCR_FIFO_FULL || ENHTIM_FLAG == ENHTIM_FLAG_CCR_FIFO_EMPTY)
    {

        if (ENH_TIM_SHARE -> ENHTIM_CCR_FIFO_STATUS & (bit_id << pos))
        {
            bitstatus = SET;
        }
    }

    return bitstatus;
}

/**
  * \brief  Enable ENHTIMx latch counter.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
  * \return None.
  */
void ENHTIM_LatchCountEnable(ENHTIM_TypeDef *ENHTIMx,
                             ENHTIMLatchCnt_TypeDef LatchCntIdx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIM_CONFIGURE_TypeDef ENHTIM_0x10 = {.d32 = ENHTIMx->ENHTIM_CONFIGURE};

    switch (LatchCntIdx)
    {
#if ENHTIM_SUPPORT_LATCH_CNT_0
    case LATCH_CNT_0:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_0_en = 0x1;
        break;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    case LATCH_CNT_1:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_1_en = 0x1;
        break;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    case LATCH_CNT_2:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_2_en = 0x1;
        break;
#endif
    default:
        break;
    }

    ENHTIMx->ENHTIM_CONFIGURE = ENHTIM_0x10.d32;
}

/**
  * \brief  Disable ENHTIMx latch counter.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
  * \return None.
  */
void ENHTIM_LatchCountDisable(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    ENHTIM_CONFIGURE_TypeDef ENHTIM_0x10 = {.d32 = ENHTIMx->ENHTIM_CONFIGURE};
    switch (LatchCntIdx)
    {
#if ENHTIM_SUPPORT_LATCH_CNT_0
    case LATCH_CNT_0:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_0_en = 0x0;
        break;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_1
    case LATCH_CNT_1:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_1_en = 0x0;
        break;
#endif
#if ENHTIM_SUPPORT_LATCH_CNT_2
    case LATCH_CNT_2:
        ENHTIM_0x10.b.Enhtimer_Latch_cnt_2_en = 0x0;
        break;
#endif
    default:
        break;
    }

    ENHTIMx->ENHTIM_CONFIGURE = ENHTIM_0x10.d32;
}

/**
  * \brief  Get ENHTIMx latch count value.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  LatchCntIdx: E_ENHTIM_LATCHCNT enum value.
  * \return None.
  */
uint32_t ENHTIM_GetLatchCount(ENHTIM_TypeDef *ENHTIMx,
                              ENHTIMLatchCnt_TypeDef LatchCntIdx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    return *(volatile uint32_t *)(&(ENHTIMx->ENHTIM_LATCH_CNT_0) + LatchCntIdx);
}

/**
  * \brief  Get ENHTIMx latch counter2 fifo length.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \return FIFO data length.
  */
uint8_t ENHTIM_GetLatchCountFIFOLength(ENHTIM_TypeDef *ENHTIMx)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    return (uint8_t)(*(&(ENH_TIM_SHARE->ENHTIM0_LATCH_FIFO_DEPTH) + enhtim_id)) & 0xF;
}

/**
  * \brief  Clear capture/compare or latch count2 fifo.
  * \param  ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  FIFO_CLR: Specifies the FIFO type which to be clear.
  * \return FIFO data length.
  */
void ENHTIM_ClearFIFO(ENHTIM_TypeDef *ENHTIMx, uint8_t FIFO_CLR)
{
    /* Check the parameters */
    assert_param(IS_ENHTIM_ALL_PERIPH(ENHTIMx));

    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);

    ENH_TIM_SHARE->ENHTIM_FIFO_CLR |= (BIT(FIFO_CLR + enhtim_id));
}


/**
  * \brief  Get all the ENHTIM interrupt status.
  * \param  None.
  * \return All the state of the ENHTIM_INT.
  */
uint32_t ENHTIM_GetAllINTStatus(void)
{
    return ENH_TIM_SHARE->ENHTIM_INT_STATUS;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

