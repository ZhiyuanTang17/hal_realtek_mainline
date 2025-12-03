/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_ir.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store IR register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the IR peripheral.
  * \param  StoreBuf: Store buffer to store IR register data.
  * \return None.
  */
void IR_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    IR_TypeDef *IRx = (IR_TypeDef *)PeriReg;
    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

    store_buf->ir_reg[0] = IRx->CLK_DIV;
    store_buf->ir_reg[1] = IRx->TX_CONFIG;
    store_buf->ir_reg[2] = IRx->RX_CONFIG;
    store_buf->ir_reg[3] = IRx->RX_CNT_INT_SEL;


    return;
}

/**
  * \brief  Restore IR register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the IR peripheral.
  * \param  StoreBuf: Restore buffer to restore IR register data.
  * \return None
  */
void IR_DLPSExit(void *PeriReg, void *StoreBuf)
{
    IR_TypeDef *IRx = (IR_TypeDef *)PeriReg;
    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

    IRx->CLK_DIV = store_buf->ir_reg[0];
    if (store_buf->ir_reg[1] & BIT31)
    {
        /* RX MODE */
        IRx->TX_CONFIG  = store_buf->ir_reg[1];
        IRx->RX_CONFIG  = store_buf->ir_reg[2];
        IRx->RX_CNT_INT_SEL  = store_buf->ir_reg[3];
    }
    else
    {
        /* TX MODE */
        IRx->TX_CONFIG  = store_buf->ir_reg[1];
        /* If IR TX mode is idle, must write one data firstly */
        IRx->TX_FIFO = 0;
    }

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

