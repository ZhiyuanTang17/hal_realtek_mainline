/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_grtc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
extern bool GRTC_IsSupportRAPComp(GRTCCompIndex_TypeDef Index);
#endif

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Reset all registers of GRTC.
  * \param  None
  * \return None
  */
void GRTC_DeInit(void)
{
    /* Reset GRTC all registers */
    GRTC_CTRL_TypeDef grtc_0x00 = {.d32 = GRTC->GRTC_CTRL};
    grtc_0x00.b.grtc_rst = 1;
    GRTC->GRTC_CTRL = grtc_0x00.d32;
    __NOP();
    __NOP();
    grtc_0x00.b.grtc_rst = 0;
    GRTC->GRTC_CTRL = grtc_0x00.d32;
}

/**
  * \brief  Enable or disable the specified GRTC interrupt.
  * \param  GRTC_INT: specifies the GRTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg GRTC_INT_COMP0: compare 0 interrupt source
  *         \arg GRTC_INT_COMP1: compare 1 interrupt source
  *         \arg GRTC_INT_COMP2: compare 2 interrupt source
  *         \arg GRTC_INT_COMP3: compare 3 interrupt source
  *         \arg GRTC_INT_COMP4: compare 4 interrupt source
  *         \arg GRTC_INT_COMP5: compare 5 interrupt source
  *         \arg GRTC_INT_COMP6: compare 6 interrupt source
  *         \arg GRTC_INT_COMP7: compare 7 interrupt source
  * \param  NewState: New state of the specified GRTC interrupt.
  * \return None.
  */
void GRTC_INTConfig(uint32_t GRTC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GRTC_INT(GRTC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        GRTC->GRTC_INTR_CTRL |= GRTC_INT;
    }
    else
    {
        GRTC->GRTC_INTR_CTRL &= (~GRTC_INT);
    }
}

/**
  * \brief  Checks whether the specified GRTC interrupt is set or not.
  * \param  GRTC_INT: specifies the GRTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg GRTC_INT_COMP0: compare 0 interrupt source
  *         \arg GRTC_INT_COMP1: compare 1 interrupt source
  *         \arg GRTC_INT_COMP2: compare 2 interrupt source
  *         \arg GRTC_INT_COMP3: compare 3 interrupt source
  *         \arg GRTC_INT_COMP4: compare 4 interrupt source
  *         \arg GRTC_INT_COMP5: compare 5 interrupt source
  *         \arg GRTC_INT_COMP6: compare 6 interrupt source
  *         \arg GRTC_INT_COMP7: compare 7 interrupt source
  * \return The new state of GRTC_INT (SET or RESET).
  */
ITStatus GRTC_GetINTStatus(uint32_t GRTC_INT)
{
    /* Check the parameters */
    assert_param(IS_GRTC_CONFIG_INT(GRTC_INT));

    if ((GRTC->GRTC_COMP_INTR_SR & GRTC_INT) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

/**
  * \brief  Clear the interrupt pending bits of GRTC.
  * \param  GRTC_INT: specifies the GRTC interrupt flag to clear.
  *         This parameter can be any combination of the following values:
  *         \arg GRTC_INT_COMP0: compare 0 interrupt source
  *         \arg GRTC_INT_COMP1: compare 1 interrupt source
  *         \arg GRTC_INT_COMP2: compare 2 interrupt source
  *         \arg GRTC_INT_COMP3: compare 3 interrupt source
  *         \arg GRTC_INT_COMP4: compare 4 interrupt source
  *         \arg GRTC_INT_COMP5: compare 5 interrupt source
  *         \arg GRTC_INT_COMP6: compare 6 interrupt source
  *         \arg GRTC_INT_COMP7: compare 7 interrupt source
  * \return None
  */
void GRTC_ClearINTPendingBit(uint32_t GRTC_INT)
{
    /* Check the parameters */
    assert_param(IS_GRTC_INT(GRTC_INT));

    GRTC_COMP_INT_CLR_TypeDef grtc_clr = {.d32 = GRTC->GRTC_COMP_INT_CLR};
    grtc_clr.d32 |= GRTC_INT;
    GRTC->GRTC_COMP_INT_CLR = grtc_clr.d32;
}

#if (GRTC_SUPPORT_ERROR_INTERRUPT == 1)
/**
  * \brief  Checks whether the specified GRTC error interrupt is set or not.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \return The new state of GRTC error interrupt (SET or RESET).
  */
ITStatus GRTC_GetErrorINTStatus(GRTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    if ((GRTC->GRTC_COMP_TIMEOUT_OV_ERR_SR & BIT(Index)) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

/**
  * \brief  Clear the error interrupt pending bits of GRTC.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \return None
  */
void GRTC_ClearErrorINTPendingBit(GRTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    GRTC->GRTC_COMP_TIMEOUT_OV_ERR_CLR = BIT(Index);
}
#endif

/**
  * \brief  Set GRTC comparator value.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \param  Value: The comparator value.
  * \return None
  */
void GRTC_SetCompValue(GRTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    (*((volatile uint32_t *)(&GRTC->GRTC_COMP_0) + Index)) = Value;
}

/**
  * \brief  Get GRTC comparator value.
  * \param  Index: The comparator number.
  * \return The comparator value.
  */
uint32_t GRTC_GetCompValue(GRTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    return (*((volatile uint32_t *)(&GRTC->GRTC_COMP_0) + Index));
}

/**
  * \brief  Enable or Disable the GRTC comparator reload function.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \param  NewState: new state of GRTC peripheral.
  *         This parameter can be the following values:
  *         \arg ENABLE: start GRTC.
  *         \arg DISABLE: stop GRTC.
  * \return None
  */
void GRTC_CompReloadCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        GRTC->GRTC_RELOAD_CTRL |= BIT(Index);
    }
    else
    {
        GRTC->GRTC_RELOAD_CTRL &= ~BIT(Index);
    }
}

/**
  * \brief  Set GRTC comparator reload value.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \param  Value: The comparator reload value.
  * \return None
  */
void GRTC_SetCompReloadValue(GRTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    (*((volatile uint32_t *)(&GRTC->GRTC_COMP_0_RELOAD) + Index)) = Value;
}

/**
  * \brief  Get GRTC comparator reload value.
  * \param  Index: The comparator number.
  * \return The comparator reload value.
  */
uint32_t GRTC_GetCompReloadValue(GRTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    return (*((volatile uint32_t *)(&GRTC->GRTC_COMP_0_RELOAD) + Index));
}

/**
  * \brief  Enable or Disable the GRTC function of sleep control.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \param  NewState: new state of GRTC peripheral.
  *         This parameter can be the following values:
  *         \arg ENABLE: start GRTC.
  *         \arg DISABLE: stop GRTC.
  * \return None
  */
void GRTC_SleepCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        GRTC->GRTC_SLEEP_CTRL |= BIT(Index);
    }
    else
    {
        GRTC->GRTC_SLEEP_CTRL &= ~BIT(Index);
    }
}

/**
  * \brief  Get GRTC sleep counter.
  * \param  Index: The comparator number which can be 0 ~ 7.
  * \return The sleep counter.
  */
uint32_t GRTC_GetSleepCounter(GRTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));

    return (*((volatile uint32_t *)(&GRTC->GRTC_COMP_0_SLEEP_PENDING_CNT) + Index));
}

/*============================================================================*
 *                        RAP Functions
 *============================================================================*/
#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
bool GRTC_RAPModeCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState)
{
    if (GRTC_IsSupportRAPComp(Index) == 0)
    {
        return false;
    }

    if (NewState == ENABLE)
    {
        GRTC->GRTC_TASK_CTRL |= BIT(Index);
    }
    else
    {
        GRTC->GRTC_TASK_CTRL &= ~BIT(Index);
    }

    return true;
}

bool GRTC_ActionTrigger(GRTCCompIndex_TypeDef Index, uint32_t Action)
{
    if (GRTC_IsSupportRAPComp(Index) == 0)
    {
        return false;
    }

    GRTC->GRTC_TASK_CTRL |= BIT(Index + 8 + (GRTC_COMP_NUM > 8) * 8);

    return true;
}
#endif

#if (GRTC_SUPPORT_FORCE_QACTIVE == 1)
void GRTC_ForceQactiveCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GRTC_COMP(Index));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        GRTC->GRTC_QACTIVE_CTRL |= BIT(8 + Index);
    }
    else
    {
        GRTC->GRTC_QACTIVE_CTRL &= ~BIT(8 + Index);
    }
}
#endif

