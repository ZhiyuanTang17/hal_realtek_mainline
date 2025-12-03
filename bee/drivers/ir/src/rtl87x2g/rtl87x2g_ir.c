/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_ir.c
* \brief    This file provides all the IR firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_ir.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  IR clock config.
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void IR_ClkConfig(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv)
{
    if (ClockSrc == IR_CLOCK_SRC_40M)
    {
        PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_sclk_ir_src_sel = 0;
    }
    else
    {
        PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_sclk_ir_src_sel = 1;
        PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_pll_ir_div_sel = ClockDiv;
        if (ClockSrc == IR_CLOCK_SRC_PLL1)
        {
            PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_pll_ir_src_sel = 0;
        }
        else if (ClockSrc == IR_CLOCK_SRC_PLL2)
        {
            PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_pll_ir_src_sel = 1;
        }
    }

    return;
}

bool IR_ClkGet(IRClockSrc_TypeDef *ClockSrc, IRClockDiv_TypeDef *ClockDiv)
{
    if (PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_sclk_ir_src_sel == 0)
    {
        *ClockSrc = IR_CLOCK_SRC_40M;
        *ClockDiv = IR_CLOCK_DIVIDER_1;
    }
    else
    {
        *ClockDiv = (IRClockDiv_TypeDef)PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_pll_ir_div_sel;
        *ClockSrc = (PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_pll_ir_src_sel == 0) ? \
                    IR_CLOCK_SRC_PLL1 : IR_CLOCK_SRC_PLL2;
    }

    return true;
}

/**
  * \brief  Store IR register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the IR peripheral.
  * \param  StoreBuf: Store buffer to store IR register data.
  * \return None.
  */
RAM_FUNCTION
void IR_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

    store_buf->ir_reg[0] = IR->IR_CLK_DIV;
    store_buf->ir_reg[1] = IR->IR_TX_CONFIG;
    store_buf->ir_reg[2] = IR->IR_RX_CONFIG;
    store_buf->ir_reg[3] = IR->IR_RX_CNT_INT_SEL;

    return;
}

/**
  * \brief  Restore IR register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the IR peripheral.
  * \param  StoreBuf: Restore buffer to restore IR register data.
  * \return None
  */
RAM_FUNCTION
void IR_DLPSExit(void *PeriReg, void *StoreBuf)
{
    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

    IR->IR_CLK_DIV = store_buf->ir_reg[0];
    if (store_buf->ir_reg[1] & BIT31)
    {
        /* RX MODE */
        IR->IR_TX_CONFIG  = store_buf->ir_reg[1];
        IR->IR_RX_CONFIG  = store_buf->ir_reg[2];
        IR->IR_RX_CNT_INT_SEL  = store_buf->ir_reg[3];
    }
    else
    {
        /* TX MODE */
        IR->IR_TX_CONFIG  = store_buf->ir_reg[1];
        /* If IR TX mode is idle, must write one data firstly */
        IR->IR_TX_FIFO = 0;
    }

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

