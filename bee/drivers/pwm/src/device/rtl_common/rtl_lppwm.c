/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lppwm.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

void LPPWM_Init(LPPWM_TypeDef *LPPWMx, LPPWM_InitTypeDef *LPPWM_InitStruct)
{
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = LPPWMx->LPPWM_CH0_CTL};
    lppwm_ctrl.b.lppwm_ch0_polarity = LPPWM_InitStruct->LPPWM_Polarity;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    LPPWMx->LPPWM_CH0_P0_H = LPPWM_InitStruct->LPPWM_PeriodHigh & 0xFFFF;
    LPPWMx->LPPWM_CH0_P0_L = LPPWM_InitStruct->LPPWM_PeriodLow & 0xFFFF;

    return;
}

void LPPWM_StructInit(LPPWM_InitTypeDef *LPPWM_InitStruct)
{
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    /* High Polarity is selected as default polarity */
    LPPWM_InitStruct->LPPWM_Polarity = LPPWM_POLARITY_NORMAL;

    /* Set default high & low count  */
    LPPWM_InitStruct->LPPWM_PeriodHigh = 0;
    LPPWM_InitStruct->LPPWM_PeriodLow = 0;

    return;
}

void LPPWM_Cmd(LPPWM_TypeDef *LPPWMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = LPPWMx->LPPWM_CH0_CTL};
    lppwm_ctrl.b.lppwm_ch0_en = NewState;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    return;
}

void LPPWM_Reset(LPPWM_TypeDef *LPPWMx)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = LPPWMx->LPPWM_CH0_CTL};
    lppwm_ctrl.b.lppwm_ch0_reg_rst_n = 1;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    return;
}

void LPPWM_ChangePWMCount(LPPWM_TypeDef *LPPWMx, uint32_t period_high, uint32_t period_low)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    LPPWMx->LPPWM_CH0_P0_H = period_high & 0xFFFF;
    LPPWMx->LPPWM_CH0_P0_L = period_low & 0xFFFF;
}

uint32_t LPPWM_GetCurrentValue(LPPWM_TypeDef *LPPWMx)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    return LPPWMx->LPPWM_CH0_CURRENT & 0xFFFF;
}



