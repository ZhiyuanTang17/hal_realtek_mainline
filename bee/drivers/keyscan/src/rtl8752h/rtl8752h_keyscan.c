/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_keyscan.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Store buffer to store KEYSCAN register data.
  * \return None.
  */
void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    store_buf->keyscan_reg[0] = KEYSCAN->CLKDIV;               /* 0x00 */
    store_buf->keyscan_reg[1] = KEYSCAN->TIMERCR;              /* 0x04 */
    store_buf->keyscan_reg[2] = KEYSCAN->CR;                   /* 0x08 */
    store_buf->keyscan_reg[3] = KEYSCAN->COLCR;                /* 0x0C */
    store_buf->keyscan_reg[4] = KEYSCAN->ROWCR;                /* 0x10 */
    store_buf->keyscan_reg[6] = KEYSCAN->INTMASK;              /* 0x18 */

    return;
}

/**
  * \brief  Restore KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Restore buffer to restore KEYSCAN register data.
  * \return None
  */
void KEYSCAN_DLPSExit(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    /* Set FSM to idle state */
    KEYSCAN->CR &= ~BIT31;
    KEYSCAN->CLKDIV = store_buf->keyscan_reg[0];
    KEYSCAN->CR = (store_buf->keyscan_reg[2] & (~(BIT31)));
    KEYSCAN->TIMERCR = store_buf->keyscan_reg[1];
    KEYSCAN->COLCR = store_buf->keyscan_reg[3];
    KEYSCAN->ROWCR = store_buf->keyscan_reg[4];
    KEYSCAN->INTMASK = store_buf->keyscan_reg[6];
    KEYSCAN->CR |= (store_buf->keyscan_reg[2] & ((BIT31)));

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

