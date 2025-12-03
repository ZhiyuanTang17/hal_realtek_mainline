/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_uart.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store UART register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the UART peripheral.
  * \param  StoreBuf: Store buffer to store UART register data.
  * \return None.
  */
void UART_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    UART_TypeDef *UARTx = (UART_TypeDef *)PeriReg;
    UARTStoreReg_Typedef *store_buf = (UARTStoreReg_Typedef *)StoreBuf;

    if (UARTx == UART0)
    {
        RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
    }
    else if (UARTx == UART1)
    {
        RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE);
    }
    else if (UARTx == UART2)
    {
        RCC_PeriphClockCmd(APBPeriph_UART2, APBPeriph_UART2_CLOCK, ENABLE);
    }

    //access DLH and DLL
    UARTx->LCR |= (1 << 7);
    store_buf->uart_reg[0] = UARTx->DLL;
    store_buf->uart_reg[1] = UARTx->DLH_INTCR;
    UARTx->LCR &= (~(1 << 7));

    //save other registers
    store_buf->uart_reg[2] = UARTx->DLH_INTCR;
    store_buf->uart_reg[4] = UARTx->LCR;
    store_buf->uart_reg[5] = UARTx->MCR;
    store_buf->uart_reg[6] = UARTx->SPR;
    store_buf->uart_reg[7] = UARTx->STSR;
    store_buf->uart_reg[8] = UARTx->RX_IDLE_TOCR;
    store_buf->uart_reg[9] = UARTx->RX_IDLE_INTCR;
    store_buf->uart_reg[10] = UARTx->MISCR;
    store_buf->uart_reg[11] = UARTx->INTMASK;

    return;
}

/**
  * \brief  Restore UART register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the UART peripheral.
  * \param  StoreBuf: Restore buffer to restore UART register data.
  * \return None
  */
void UART_DLPSExit(void *PeriReg, void *StoreBuf)
{
    UART_TypeDef *UARTx = (UART_TypeDef *)PeriReg;
    UARTStoreReg_Typedef *store_buf = (UARTStoreReg_Typedef *)StoreBuf;

    if (UARTx == UART0)
    {
        RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
    }
    else if (UARTx == UART1)
    {
        RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE);
    }
    else if (UARTx == UART2)
    {
        RCC_PeriphClockCmd(APBPeriph_UART2, APBPeriph_UART2_CLOCK, ENABLE);
    }

    UARTx->LCR &= (~(1 << 7));
    UARTx->DLH_INTCR =  0;
    (void)UARTx->LSR;
    UARTx->INTID_FCR |= (FCR_CLEAR_RX_FIFO_Set | FCR_CLEAR_TX_FIFO_Set);

    //access DLH and DLL
    UARTx->LCR |= (1 << 7);
    UARTx->STSR = store_buf->uart_reg[7];
    UARTx->SPR = store_buf->uart_reg[6];
    UARTx->DLL = store_buf->uart_reg[0];
    UARTx->DLH_INTCR =  store_buf->uart_reg[1];
    UARTx->LCR &= (~(1 << 7));

    //access other registers
    UARTx->INTID_FCR = (((store_buf->uart_reg[7] & BIT24) >> 21) | ((store_buf->uart_reg[7] &
                                                                     0x7C000000) >>
                                                                    18) |
                        (1));
    UARTx->LCR = store_buf->uart_reg[4];
    UARTx->MCR = store_buf->uart_reg[5];
    UARTx->DLH_INTCR = store_buf->uart_reg[2];
    UARTx->RX_IDLE_TOCR = store_buf->uart_reg[8];
    UARTx->RX_IDLE_INTCR = store_buf->uart_reg[9];
    UARTx->MISCR = store_buf->uart_reg[10];
    UARTx->INTMASK = store_buf->uart_reg[11];

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

