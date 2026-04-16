/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_rtc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
extern void RTC_CompAutoReloadCmd(RTCCompIndex_TypeDef Index, FunctionalState NewState);
#endif

#define DELAY_BETWEEN_SET_COMP()          platform_delay_us(47)   //1.5T 32K
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Reset RTC.
  * \param  None
  * \return None
  */
void RTC_DeInit(void)
{
#if (RTC_SUPPORT_RESET_REGISTER_TO_DEFAULT == 1)
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = 0};
    rtc_0x00.b.rtc_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    RTC_WRITE(RTC_CR0, 0);
#else
    /* Stop RTC counter */
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_start = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);

    /* Disable wakeup signal */
    rtc_0x00.b.rtc_nv_ie = 0;
    rtc_0x00.b.rtc_wk_ie = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);

    /* Clear all RTC interrupt & wakeup */
    RTC_WRITE_DELAY(RTC_INT_CLEAR, 0xFFFF);

    /* Clear prescale and prescale comparator register */
    RTC_WRITE(RTC_PRESCALER0, 0);
    RTC_WRITE(RTC_PRESCALE_CMP0, 0);

    /* Clear all comparator register */
    RTC_WRITE(RTC_COMP_0, 0);
    RTC_WRITE(RTC_COMP_1, 0);
    RTC_WRITE(RTC_COMP_2, 0);
    RTC_WRITE(RTC_COMP_3, 0);

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
    RTC_WRITE(RTC_COMP0_GT, 0);
    RTC_WRITE(RTC_COMP1_GT, 0);
    RTC_WRITE(RTC_COMP2_GT, 0);
    RTC_WRITE(RTC_COMP3_GT, 0);
#endif

    /* Reset prescale counter and counter */
    rtc_0x00.d32 = 0;
    rtc_0x00.b.rtc_cnt_rst = 1;
    rtc_0x00.b.rtc_pre_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    RTC_WRITE(RTC_CR0, 0);
#endif

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * \brief  Set RTC prescaler value.
  * \param  value: the prescaler value to be set.Should be no more than 12 bits!
  * \return None
  */
void RTC_SetPrescaler(uint16_t Value)
{
    RTC_WRITE(RTC_PRESCALER0, Value & 0xFFF);
}

/**
  * \brief  Start or stop RTC peripheral.
  * \param  NewState: new state of RTC peripheral.
  *         This parameter can be the following values:
  *         \arg ENABLE: start RTC.
  *         \arg DISABLE: stop RTC.
  * \return None
  */
void RTC_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Start or stop RTC */
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_start = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Enable or disable the specified RTC interrupts.
  * \param  RTC_INT: specifies the RTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_INT_TICK: tick interrupt
  *         \arg RTC_INT_OVERFLOW: counter overflow interrupt
  *         \arg RTC_INT_PRECOMP: prescale compare interrupt
  *         \arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt
  *         \arg RTC_INT_COMP0: compare 0 interrupt
  *         \arg RTC_INT_COMP1: compare 1 interrupt
  *         \arg RTC_INT_COMP2: compare 2 interrupt
  *         \arg RTC_INT_COMP3: compare 3 interrupt
  * \param  NewState: new state of the specified RTC interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void RTC_INTConfig(uint32_t RTC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_INT(RTC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    if (NewState == ENABLE)
    {
        rtc_0x00.d32 |= RTC_INT;
    }
    else
    {
        rtc_0x00.d32 &= ~RTC_INT;
    }
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Enable or disable the specified RTC wakeup function.
  * \param  RTC_WAKEUP: specifies the RTC wakeup function to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_WAKEUP_TICK: tick wakeup function
  *         \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         \arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
  *         \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  * \param  NewState: new state of the specified RTC wakeup function.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void RTC_WakeUpConfig(uint32_t RTC_WAKEUP, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_WAKUP(RTC_WAKEUP));
    assert_param(IS_FUNCTIONAL_STATE(NewState));


    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    if (NewState == ENABLE)
    {
        rtc_0x00.d32 |= RTC_WAKEUP;
    }
    else
    {
        rtc_0x00.d32 &= ~RTC_WAKEUP;
    }
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Enable interrupt signal to CPU NVIC.
  * \param  This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void RTC_NVICCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_nv_ie = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
 * \brief  Enable or disable system wake up of RTC.
 * \param  NewState: new state of the wake up function.
 *         This parameter can be: ENABLE or DISABLE.
 * \return None
 */
void RTC_WakeUpCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_wk_ie = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Checks whether the specified RTC interrupt is set or not.
  * \param  RTC_INT: specifies the RTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_INT_TICK: RTC tick interrupt source
  *         \arg RTC_INT_PRECOMP: prescale compare interrupt source
  *         \arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt source
  *         \arg RTC_INT_COMP0: compare 0 interrupt source
  *         \arg RTC_INT_COMP1: compare 1 interrupt source
  *         \arg RTC_INT_COMP2: compare 2 interrupt source
  *         \arg RTC_INT_COMP3: compare 3 interrupt source
  * \return The new state of RTC_INT (SET or RESET).
  */
ITStatus RTC_GetINTStatus(uint32_t RTC_INT)
{
    /* Check the parameters */
    assert_param(IS_RTC_CONFIG_INT(RTC_INT));

    if ((RTC->RTC_INT_SR & (RTC_INT >> 8)) != (uint32_t)RESET)
    {
        return SET;
    }
    return  RESET;
}

/**
  * \brief  Checks whether the specified RTC wakeup state is set or not.
  * \param  RTC_WAKEUP: specifies the RTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_WAKEUP_TICK: tick wakeup function
  *         \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         \arg RTC_WAKEUP_PREOCOMP_COMP3: prescale & compare 3 wakeup function
  *         \arg RTC_WAKEUP_COMP0GT: compare 0 gt wakeup function
  *         \arg RTC_WAKEUP_COMP1GT: compare 1 gt wakeup function
  *         \arg RTC_WAKEUP_COMP2GT: compare 2 gt wakeup function
  *         \arg RTC_WAKEUP_COMP3GT: compare 3 gt wakeup function
  *         \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  * \return The new state of RTC_INT (SET or RESET).
  */
ITStatus RTC_GetWakeUpStatus(uint32_t RTC_WAKEUP)
{
    /* Check the parameters */
    assert_param(IS_RTC_CONFIG_INT(RTC_WAKEUP));

    if ((RTC->RTC_INT_SR & (RTC_WAKEUP >> 8)) != (uint32_t)RESET)
    {
        return SET;
    }
    return  RESET;
}

/**
  * \brief  Clear the interrupt pending bits of RTC.
  * \param  RTC_INT: specifies the RTC interrupt flag to clear.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_INT_TICK: RTC tick interrupt source
  *         \arg RTC_INT_OVERFLOW: RTC counter overflow interrupt source
  *         \arg RTC_INT_PRECOMP: prescale compare interrupt source
  *         \arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt source
  *         \arg RTC_INT_COMP0: compare 0 interrupt source
  *         \arg RTC_INT_COMP1: compare 1 interrupt source
  *         \arg RTC_INT_COMP2: compare 2 interrupt source
  *         \arg RTC_INT_COMP3: compare 3 interrupt source
  * \return None
  */
void RTC_ClearINTPendingBit(uint32_t RTC_INT)
{
    /* Check the parameters */
    assert_param(IS_RTC_INT(RTC_INT));

    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = RTC->RTC_INT_CLEAR};
    rtc_0x04.d32 |= RTC_INT >> 8;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * \brief  Clear the wakeup status bits of RTC.
  * \param  RTC_WAKEUP: specifies the RTC wakeup flag to clear.
  *         This parameter can be any combination of the following values:
  *         \arg RTC_WAKEUP_TICK: tick wakeup function
  *         \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         \arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
  *         \arg RTC_WAKEUP_COMP0GT: compare 0 gt wakeup function
  *         \arg RTC_WAKEUP_COMP1GT: compare 1 gt wakeup function
  *         \arg RTC_WAKEUP_COMP2GT: compare 2 gt wakeup function
  *         \arg RTC_WAKEUP_COMP3GT: compare 3 gt wakeup function
  *         \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  * \return None
  */
void RTC_ClearWakeUpStatusBit(uint32_t RTC_WAKEUP)
{
    /* Check the parameters */
    assert_param(IS_RTC_WAKEUP(RTC_WAKEUP));

    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = RTC->RTC_INT_CLEAR};
    rtc_0x04.d32 |= RTC_WAKEUP >> 8;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * \brief  Clear the interrupt pending bit of the select comparator of RTC.
  * \param  Index: the comparator number 0~3.
  * \return None
  */
void RTC_ClearCompINT(RTCCompIndex_TypeDef Index)
{
    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = RTC->RTC_INT_CLEAR};
    rtc_0x04.d32 |= (RTC_INT_COMP0 >> 8) << (uint32_t)Index;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * \brief  Clear the overflow interrupt pending bit of RTC.
  * \param  None
  * \return None
  */
void RTC_ClearOverFlowINT(void)
{
    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = RTC->RTC_INT_CLEAR};
    rtc_0x04.b.rtc_cnt_ov_clr = 0x1;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * \brief  Clear the tick interrupt pending bit of RTC.
  * \param  None
  * \return None
  */
void RTC_ClearTickINT(void)
{
    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = RTC->RTC_INT_CLEAR};
    rtc_0x04.b.rtc_tick_clr = 0x1;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * \brief  Set RTC comparator value.
  * \param  Index: The comparator number,can be 0 ~ 3.
  * \param  value: The comparator value to be set.Should be no more than 24 bits!
  * \return None
  */
void RTC_SetCompValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMP(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP_0, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP_1, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP_2, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP_3, Value);
        break;
    default:
        break;
    }

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * \brief  Get RTC comparator value.
  * \param  Index: The comparator number.
  * \return The comparator value.
  */
uint32_t RTC_GetCompValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP_0) + Index));
}

/**
  * \brief  Set RTC prescaler comparator value.
  * \param  value: The comparator value to be set.Should be no more than 12 bits!
  * \return None
  */
void RTC_SetPreCompValue(uint32_t Value)
{
    RTC_WRITE(RTC_PRESCALE_CMP0, Value & 0xFFF);
}

/**
  * \brief  Get RTC prescaler comparator value.
  * \param  None.
  * \return The prescaler comparator value.
  */
uint32_t RTC_GetPreCompValue(void)
{
    return RTC->RTC_PRESCALE_CMP0;
}

/**
  * \brief  Reset counter value of RTC.
  * \param  None
  * \return None
  */
void RTC_ResetCounter(void)
{
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    rtc_0x00.b.rtc_cnt_rst = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Get counter value of RTC.
  * \param  None.
  * \return The counter value.
  */
uint32_t RTC_GetCounter(void)
{
    return RTC->RTC_CNT0;
}

/**
  * \brief  Reset prescaler counter value of RTC.
  * \param  None
  * \return None
  */
void RTC_ResetPrescalerCounter(void)
{
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_pre_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    rtc_0x00.b.rtc_pre_cnt_rst = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * \brief  Get prescaler counter value of RTC.
  * \param  None.
  * \return The prescaler counter value.
  */
uint32_t RTC_GetPreCounter(void)
{
    return RTC->RTC_PRESCALE_CNT0;
}

/**
  * \brief  Set backup register for store time information.
  * \param  value: the value which is set to backup reister
  * \return None.
  */
void RTC_SetBackupReg(uint32_t Value)
{
    RTC_WRITE(RTC_BACKUP, Value);
}

/**
  * \brief  Get backup register for store time information.
  * \param  None.
  * \return Register value.
  */
uint32_t RTC_GetBackupReg(void)
{
    return RTC->RTC_BACKUP;
}

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
void RTC_SetCompReloadValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMP(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP_0_RELOAD, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP_1_RELOAD, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP_2_RELOAD, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP_3_RELOAD, Value);
        break;
    default:
        break;
    }
}

uint32_t RTC_GetCompReloadValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP_0_RELOAD) + Index));
}

void RTC_EnableCompAutoReload(RTCCompIndex_TypeDef Index, uint32_t Comp_Value,
                              uint32_t Reload_Value)
{
    /* Set comp value before enable auto reload */
    RTC_SetCompValue(Index, Comp_Value);
    RTC_SetCompReloadValue(Index, Reload_Value);

    RTC_CompAutoReloadCmd(Index, ENABLE);
}

void RTC_DisableCompAutoReload(RTCCompIndex_TypeDef Index)
{
    RTC_CompAutoReloadCmd(Index, DISABLE);
}
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
/**
  * \brief  Set RTC comparator GT value.
  * \param  Index: The comparator gt number, can be 0 ~ 3.
  * \param  value: The comparator value to be set.
  * \return None
  */
void RTC_SetCompGTValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMPGT(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP0_GT, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP1_GT, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP2_GT, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP3_GT, Value);
        break;
    default:
        break;
    }

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * \brief  Get RTC comparator gt value.
  * \param  Index: The comparator number 0~3.
  * \return The comparator value.
  */
uint32_t RTC_GetCompGTValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP0_GT) + Index));
}
#endif

#if (RTC_SUPPORT_RAP_FUNCTION == 1)

void RTC_RAPModeCmd(FunctionalState NewState)
{
    RTC_TASK_CTRL_TypeDef rtc_ctrl = {.d32 = RTC->RTC_TASK_CTRL};
    rtc_ctrl.b.rtc_rap_mode = NewState;
    RTC_WRITE_DELAY(RTC_TASK_CTRL, rtc_ctrl.d32);

    return;
}

void RTC_ActionTrigger(uint32_t Action)
{
    RTC->RTC_TASK_CTRL |= BIT(Action + 1);

    return;
}

void RTC_ShortcutCmd(uint32_t Action, uint32_t Event, FunctionalState NewState)
{
    if (Action == RTC_ACTION_START)
    {
        return;
    }

    if (NewState == ENABLE)
    {
        RTC->RTC_SHOT_CTRL |= (BIT(Action - 1) | BIT(Event + 16));
    }
    else
    {
        RTC->RTC_SHOT_CTRL &= ~(BIT(Action - 1) | BIT(Event + 16));
    }

    return;
}
#endif



