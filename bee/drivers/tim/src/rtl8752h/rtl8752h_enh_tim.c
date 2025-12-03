/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_enh_tim.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define PWM_EMG_STOP        BIT8

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store ENHTIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the ENHTIM peripheral.
  * \param  StoreBuf: Store buffer to store ENHTIM register data.
  * \return None.
  */
void ENHTIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    ENHTIMStoreReg_Typedef *store_buf = (ENHTIMStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);

    store_buf->enhtim_reg[0] = ENH_TIM0->CR;
    store_buf->enhtim_reg[1] = ENH_TIM0->MAX_CNT;
    store_buf->enhtim_reg[2] = ENH_TIM0->CCR;
    store_buf->enhtim_reg[3] = ENH_TIM0->CCR_FIFO;

    store_buf->enhtim_reg[4] = ENH_TIM_SHARE->FIFO_CLR;
    store_buf->enhtim_reg[5] = ENH_TIM_SHARE->CMD;
    store_buf->enhtim_reg[6] = ENH_TIM_SHARE->INT_CMD;
    store_buf->enhtim_reg[7] = ENH_TIM_SHARE->INT_SR;
    store_buf->enhtim_reg[8] = ENH_TIM_SHARE->LC_INT_CMD0;
    store_buf->enhtim_reg[9] = ENH_TIM_SHARE->LC_INT_CMD2;
    store_buf->enhtim_reg[10] = ENH_TIM_SHARE->LC_FIFO_LEVEL0;
    store_buf->enhtim_reg[11] = ENH_TIM_SHARE->LC_FIFO_LEVEL1;

    store_buf->enhtim_reg[12] = *((volatile uint32_t *)0x40000360UL);
    store_buf->enhtim_reg[13] = *((volatile uint32_t *)0x40000368UL);

    store_buf->enhtim_reg[14] = *((volatile uint32_t *)0x4000600CUL);
    store_buf->enhtim_reg[15] = *((volatile uint32_t *)0x40000384UL);

    store_buf->enhtim_reg[16] = ENHTIM_PWM_DEADZONE_CR;
}

/**
  * \brief  Restore ENHTIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the ENHTIM peripheral.
  * \param  StoreBuf: Restore buffer to restore ENHTIM register data.
  * \return None
  */
void ENHTIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    ENHTIMStoreReg_Typedef *store_buf = (ENHTIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);

    *((volatile uint32_t *)0x40000360UL) = store_buf->enhtim_reg[12];
    *((volatile uint32_t *)0x40000368UL) = store_buf->enhtim_reg[13];

    ENH_TIM0->CR        = store_buf->enhtim_reg[0];
    ENH_TIM0->MAX_CNT   = store_buf->enhtim_reg[1];
    ENH_TIM0->CCR       = store_buf->enhtim_reg[2];
    ENH_TIM0->CCR_FIFO  = store_buf->enhtim_reg[3];

    ENH_TIM_SHARE->FIFO_CLR = store_buf->enhtim_reg[4];
    ENH_TIM_SHARE->CMD      = store_buf->enhtim_reg[5] ;
    ENH_TIM_SHARE->INT_CMD  = store_buf->enhtim_reg[6];
    ENH_TIM_SHARE->INT_SR   = store_buf->enhtim_reg[7];
    ENH_TIM_SHARE->LC_INT_CMD0  = store_buf->enhtim_reg[8];
    ENH_TIM_SHARE->LC_INT_CMD2  = store_buf->enhtim_reg[9];
    ENH_TIM_SHARE->LC_FIFO_LEVEL0   = store_buf->enhtim_reg[10];
    ENH_TIM_SHARE->LC_FIFO_LEVEL1   = store_buf->enhtim_reg[11];

    ENHTIM_PWM_DEADZONE_CR = store_buf->enhtim_reg[16];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

