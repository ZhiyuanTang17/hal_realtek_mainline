/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_i2c.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Store buffer to store I2C register data.
  * \return None.
  */
void I2C_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    I2C_TypeDef *I2Cx = (I2C_TypeDef *)PeriReg;
    I2CStoreReg_Typedef *store_buf = (I2CStoreReg_Typedef *)StoreBuf;

    if (I2Cx == I2C0)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C1, APBPeriph_I2C1_CLOCK, ENABLE);
    }

    store_buf->i2c_reg[0] = I2Cx->IC_CON;
    store_buf->i2c_reg[1] = I2Cx->IC_TAR;
    store_buf->i2c_reg[2] = I2Cx->IC_SAR;
    store_buf->i2c_reg[3] = I2Cx->IC_HS_MADDR;

    store_buf->i2c_reg[4] = I2Cx->IC_SS_SCL_HCNT;
    store_buf->i2c_reg[5] = I2Cx->IC_SS_SCL_LCNT;
    store_buf->i2c_reg[6] = I2Cx->IC_FS_SCL_HCNT;
    store_buf->i2c_reg[7] = I2Cx->IC_FS_SCL_LCNT;
    store_buf->i2c_reg[8] = I2Cx->IC_HS_SCL_HCNT;
    store_buf->i2c_reg[9] = I2Cx->IC_HS_SCL_LCNT;

    store_buf->i2c_reg[10] = I2Cx->IC_INTR_MASK;
    store_buf->i2c_reg[11] = I2Cx->IC_RX_TL;
    store_buf->i2c_reg[12] = I2Cx->IC_TX_TL;
    store_buf->i2c_reg[13] = I2Cx->IC_ENABLE;
    store_buf->i2c_reg[14] = I2Cx->IC_SDA_HOLD;
    store_buf->i2c_reg[15] = I2Cx->IC_SLV_DATA_NACK_ONLY;
    store_buf->i2c_reg[16] = I2Cx->IC_DMA_CR;
    store_buf->i2c_reg[17] = I2Cx->IC_DMA_TDLR;
    store_buf->i2c_reg[18] = I2Cx->IC_DMA_RDLR;

    store_buf->i2c_reg[19] = I2Cx->IC_SDA_SETUP;
}

/**
  * \brief  Restore I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Restore buffer to restore I2C register data.
  * \return None
  */
void I2C_DLPSExit(void *PeriReg, void *StoreBuf)
{
    I2C_TypeDef *I2Cx = (I2C_TypeDef *)PeriReg;
    I2CStoreReg_Typedef *store_buf = (I2CStoreReg_Typedef *)StoreBuf;

    if (I2Cx == I2C0)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C1, APBPeriph_I2C1_CLOCK, ENABLE);
    }

    I2Cx->IC_CON = store_buf->i2c_reg[0];
    I2Cx->IC_TAR = store_buf->i2c_reg[1];
    I2Cx->IC_SAR = store_buf->i2c_reg[2];
    I2Cx->IC_HS_MADDR = store_buf->i2c_reg[3];

    I2Cx->IC_SS_SCL_HCNT = store_buf->i2c_reg[4];
    I2Cx->IC_SS_SCL_LCNT = store_buf->i2c_reg[5];
    I2Cx->IC_FS_SCL_HCNT = store_buf->i2c_reg[6];
    I2Cx->IC_FS_SCL_LCNT = store_buf->i2c_reg[7];
    I2Cx->IC_HS_SCL_HCNT = store_buf->i2c_reg[8];
    I2Cx->IC_HS_SCL_LCNT = store_buf->i2c_reg[9];

    I2Cx->IC_INTR_MASK = store_buf->i2c_reg[10];
    I2Cx->IC_RX_TL = store_buf->i2c_reg[11];
    I2Cx->IC_TX_TL = store_buf->i2c_reg[12];
    I2Cx->IC_SDA_HOLD = store_buf->i2c_reg[14];
    I2Cx->IC_SLV_DATA_NACK_ONLY = store_buf->i2c_reg[15];
    I2Cx->IC_DMA_CR = store_buf->i2c_reg[16];
    I2Cx->IC_DMA_TDLR = store_buf->i2c_reg[17];
    I2Cx->IC_DMA_RDLR = store_buf->i2c_reg[18];
    I2Cx->IC_SDA_SETUP = store_buf->i2c_reg[19];

    I2Cx->IC_ENABLE = store_buf->i2c_reg[13];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

