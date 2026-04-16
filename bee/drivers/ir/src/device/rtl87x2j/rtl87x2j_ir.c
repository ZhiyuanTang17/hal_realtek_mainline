/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_ir.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define IR_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define IR_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x7E)//Force off 0x54

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  IR clock config.
  * \param  ClockSrc: specifies the clock source to gates its clock.\ref IR_Source_Clock
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void IR_SetClock(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv)
{
    PCC_REG_UPDATE(PCC_REG_IR,
                   3 << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos,
                   ClockSrc << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos);
    return;
}

void IR_ClockAutoModeCmd(FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Newstate == ENABLE)
    {
        // ir qactive auto gating
        PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_IRRC, 0);
    }
    else
    {
        // ir qactive force on
        PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_IRRC, 1);
        // polling ir clk en ready
        while (!PCC_REG_READ_BITFIELD(PCC_REG_PERION_CLK_REG0X, CLKEN_O_IRRC));
    }

    return;
}

/**
  * \brief  Store IR register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the IR peripheral.
  * \param  StoreBuf: Store buffer to store IR register data.
  * \return None.
  */
void IR_DLPSEnter(void *PeriReg, void *StoreBuf)
{
//    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

//    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

//    store_buf->ir_reg[0] = IR->IR_CLK_DIV;
//    store_buf->ir_reg[1] = IR->IR_TX_CONFIG;
//    store_buf->ir_reg[2] = IR->IR_RX_CONFIG;
//    store_buf->ir_reg[3] = IR->IR_RX_CNT_INT_SEL;

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
//    IRStoreReg_Typedef *store_buf = (IRStoreReg_Typedef *)StoreBuf;

//    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

//    IR->IR_CLK_DIV = store_buf->ir_reg[0];
//    if (store_buf->ir_reg[1] & BIT31)
//    {
//        /* RX MODE */
//        IR->IR_TX_CONFIG  = store_buf->ir_reg[1];
//        IR->IR_RX_CONFIG  = store_buf->ir_reg[2];
//        IR->IR_RX_CNT_INT_SEL  = store_buf->ir_reg[3];
//    }
//    else
//    {
//        /* TX MODE */
//        IR->IR_TX_CONFIG  = store_buf->ir_reg[1];
//        /* If IR TX mode is idle, must write one data firstly */
//        IR->IR_TX_FIFO = 0;
//    }

    return;
}



