/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_keyscan.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define KEYSCAN_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define KEYSCAN_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F)

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

void KEYSCAN_ClockAutoModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(KEYSCANx));

    if (Newstate == ENABLE)
    {
        KEYSCANx->KEYSCAN_QACTIVE_CTRL = KEYSCAN_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        KEYSCANx->KEYSCAN_QACTIVE_CTRL = KEYSCAN_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

void KEYSCAN_FIFOConfig(KEYSCAN_TypeDef *KEYSCANx, uint32_t FIFOTriggerLevel, uint32_t KeyLimit)
{
    KEYSCAN_CONFIG3_TypeDef keyscan_0x40 = {.d32 = KEYSCANx->KEYSCAN_CONFIG3};
    /* fifo threshol setting */
    keyscan_0x40.b.keyscan_fifo_th_level = FIFOTriggerLevel;
    /* Key limit setting */
    keyscan_0x40.b.keyscan_fifo_limit = KeyLimit;
    KEYSCANx->KEYSCAN_CONFIG3 =  keyscan_0x40.d32;

    return;
}

/**
  * \brief  Store KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Store buffer to store KEYSCAN register data.
  * \return None.
  */
void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
//    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

//    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

//    store_buf->keyscan_reg[0] = KEYSCAN->KEYSCAN_CLK_DIV;         /* 0x00 */
//    store_buf->keyscan_reg[1] = KEYSCAN->KEYSCAN_CONFIG1;         /* 0x04 */
//    store_buf->keyscan_reg[2] = KEYSCAN->KEYSCAN_CONFIG2;         /* 0x08 */
//    store_buf->keyscan_reg[3] = KEYSCAN->KEYSCAN_COLUMN_CONFIG;   /* 0x0C */
//    store_buf->keyscan_reg[4] = KEYSCAN->KEYSCAN_ROW_CONFIG;      /* 0x10 */
//    store_buf->keyscan_reg[6] = KEYSCAN->KEYSCAN_INT_MASK;        /* 0x18 */

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
//    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

//    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

//    /* Set FSM to idle state */
//    KEYSCAN->KEYSCAN_CONFIG2 &= ~BIT31;
//    KEYSCAN->KEYSCAN_CLK_DIV = store_buf->keyscan_reg[0];
//    KEYSCAN->KEYSCAN_CONFIG2 = (store_buf->keyscan_reg[2] & (~(BIT31)));
//    KEYSCAN->KEYSCAN_CONFIG1 = store_buf->keyscan_reg[1];
//    KEYSCAN->KEYSCAN_COLUMN_CONFIG = store_buf->keyscan_reg[3];
//    KEYSCAN->KEYSCAN_ROW_CONFIG = store_buf->keyscan_reg[4];
//    KEYSCAN->KEYSCAN_INT_MASK = store_buf->keyscan_reg[6];
//    KEYSCAN->KEYSCAN_CONFIG2 |= (store_buf->keyscan_reg[2] & ((BIT31)));

    return;
}



