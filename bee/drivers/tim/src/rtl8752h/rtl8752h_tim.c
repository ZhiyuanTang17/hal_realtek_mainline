/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_tim.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store TIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Store buffer to store TIM register data.
  * \return None.
  */
void TIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    TIM_TypeDef *TIMx = (TIM_TypeDef *)PeriReg;
    TIMStoreReg_Typedef *store_buf = (TIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);

    store_buf->tim_reg[0] = TIMx->LoadCount;
    store_buf->tim_reg[1] = TIMx->ControlReg;
    store_buf->tim_reg[2] = *(volatile uint32_t *)((uint32_t)&TIMER0_LOAD_COUNT2 +
                                                   4 * ((uint32_t)TIMx - (uint32_t)TIM0_REG_BASE) / sizeof(TIM_TypeDef));

    store_buf->tim_reg[3] = *((volatile uint32_t *)0x4000035CUL);
    store_buf->tim_reg[4] = *((volatile uint32_t *)0x40000360UL);
    store_buf->tim_reg[5] = *((volatile uint32_t *)0x40000364UL);

    store_buf->tim_reg[6] = *((volatile uint32_t *)0x4000600CUL);
    store_buf->tim_reg[7] = *((volatile uint32_t *)0x40000384UL);

    store_buf->tim_reg[8] = TIMER_PWM2_CR;

}

/**
  * \brief  Restore TIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Restore buffer to restore TIM register data.
  * \return None
  */
void TIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    TIM_TypeDef *TIMx = (TIM_TypeDef *)PeriReg;
    TIMStoreReg_Typedef *store_buf = (TIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);

    *((volatile uint32_t *)0x4000035CUL) = store_buf->tim_reg[3];
    *((volatile uint32_t *)0x40000360UL) = store_buf->tim_reg[4];
    *((volatile uint32_t *)0x40000364UL) = store_buf->tim_reg[5];

    TIMx->LoadCount = store_buf->tim_reg[0];
    TIMx->ControlReg = store_buf->tim_reg[1];
    *(volatile uint32_t *)((uint32_t)&TIMER0_LOAD_COUNT2 +
                           4 * ((uint32_t)TIMx - (uint32_t)TIM0_REG_BASE) / sizeof(TIM_TypeDef)) = store_buf->tim_reg[2];

    TIMER_PWM2_CR = store_buf->tim_reg[8];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

