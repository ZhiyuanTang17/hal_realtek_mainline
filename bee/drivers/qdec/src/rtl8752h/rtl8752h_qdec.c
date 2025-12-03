/*
 * Copyright (c) 2026 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_qdec.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store QDEC register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the QDEC peripheral.
  * \param  StoreBuf: Store buffer to store QDEC register data.
  * \return None.
  */
void QDEC_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    QDEC_TypeDef *QDECx = (QDEC_TypeDef *)PeriReg;
    QDECStoreReg_Typedef *store_buf = (QDECStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_QDEC, APBPeriph_QDEC_CLOCK, ENABLE);

    store_buf->qdec_reg[0] = QDECx->REG_DIV;
    store_buf->qdec_reg[1] = QDECx->REG_CR_X;
    store_buf->qdec_reg[2] = QDECx->REG_CR_Y;
    store_buf->qdec_reg[3] = QDECx->REG_CR_Z;
    store_buf->qdec_reg[4] = QDECx->INT_MASK;

    return;
}

/**
  * \brief  Restore QDEC register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the QDEC peripheral.
  * \param  StoreBuf: Restore buffer to restore QDEC register data.
  * \return None
  */
void QDEC_DLPSExit(void *PeriReg, void *StoreBuf)
{
    QDEC_TypeDef *QDECx = (QDEC_TypeDef *)PeriReg;
    QDECStoreReg_Typedef *store_buf = (QDECStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_QDEC, APBPeriph_QDEC_CLOCK, ENABLE);

    QDECx->REG_DIV  = store_buf->qdec_reg[0];
    QDECx->REG_CR_X = store_buf->qdec_reg[1];
    QDECx->REG_CR_Y = store_buf->qdec_reg[2];
    QDECx->REG_CR_Z = store_buf->qdec_reg[3];
    QDECx->INT_MASK = store_buf->qdec_reg[4];

    return;
}

/******************* (C) COPYRIGHT 2025 Realtek Semiconductor Corporation *****END OF FILE****/

