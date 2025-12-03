/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_i2c.c
* \brief    This file provides all the GPIO firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_i2c.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
uint8_t I2C_GetCompIndex(I2C_TypeDef *I2Cx)
{
    uint8_t compensate_index = 3;

    if (I2Cx == I2C0)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_sel;
    }
    else if (I2Cx == I2C1)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_sel;
    }
    else if (I2Cx == I2C2)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_sel;
    }
    else if (I2Cx == I2C3)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_sel;
    }

    return compensate_index;
}

bool I2C_ClkGet(I2C_TypeDef *I2Cx, I2CClockSrc_TypeDef *ClockSrc, I2CClockDiv_TypeDef *ClockDiv)
{
    *ClockSrc = I2C_CLOCK_SRC_40M;
    if (I2Cx == I2C0)
    {
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_en == 0) ? \
                    0 : PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_sel;
    }
    else if (I2Cx == I2C1)
    {
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_en == 0) ? \
                    0 : PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_sel;
    }
    else if (I2Cx == I2C2)
    {
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_en == 0) ? \
                    0 : PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_sel;
    }
    else if (I2Cx == I2C3)
    {
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_en == 0) ? \
                    0 : PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_sel;
    }
    else
    {
        return false;
    }
    return true;
}

/**
  * \brief  I2C clock divider config.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock. \ref Clock_Divider
  * \return None
  */
void I2C_ClkDivConfig(I2C_TypeDef *I2Cx, I2CClockDiv_TypeDef ClockDiv)
{
    assert_param(IS_I2C_DIV(ClockDiv));

    /* Config I2C clock divider */
    if (I2Cx == I2C0)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_en = 1;
    }
    else if (I2Cx == I2C1)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_en = 1;
    }
    else if (I2Cx == I2C2)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_en = 1;
    }
    else if (I2Cx == I2C3)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_en = 1;
    }
    return;
}

/**
  * \brief  Store I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Store buffer to store I2C register data.
  * \return None.
  */
RAM_FUNCTION
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
    else if (I2Cx == I2C2)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C2, APBPeriph_I2C2_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C3)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C3, APBPeriph_I2C3_CLOCK, ENABLE);
    }

    store_buf->i2c_reg[0] = I2Cx->IC_CON;                 /*!< 0x00 */
    store_buf->i2c_reg[1] = I2Cx->IC_TAR;                 /*!< 0x04 */
    store_buf->i2c_reg[2] = I2Cx->IC_SAR;                 /*!< 0x08 */
    store_buf->i2c_reg[3] = I2Cx->IC_FS_SPKLEN;           /*!< 0xA0 */

    store_buf->i2c_reg[4] = I2Cx->IC_SS_SCL_HCNT;         /*!< 0x14 */
    store_buf->i2c_reg[5] = I2Cx->IC_SS_SCL_LCNT;         /*!< 0x18 */
    store_buf->i2c_reg[6] = I2Cx->IC_FS_SCL_HCNT;         /*!< 0x1C */
    store_buf->i2c_reg[7] = I2Cx->IC_FS_SCL_LCNT;         /*!< 0x20 */

    store_buf->i2c_reg[8] = I2Cx->IC_INTR_MASK;           /*!< 0x30 */
    store_buf->i2c_reg[9] = I2Cx->IC_RX_TL;               /*!< 0x38 */
    store_buf->i2c_reg[10] = I2Cx->IC_TX_TL;              /*!< 0x3C */
    store_buf->i2c_reg[11] = I2Cx->IC_ENABLE;             /*!< 0x6C */
    store_buf->i2c_reg[12] = I2Cx->IC_SDA_HOLD;           /*!< 0x7C */
    store_buf->i2c_reg[13] = I2Cx->IC_SLV_DATA_NACK_ONLY; /*!< 0x84 */
    store_buf->i2c_reg[14] = I2Cx->IC_DMA_CR;             /*!< 0x88 */
    store_buf->i2c_reg[15] = I2Cx->IC_DMA_TDLR;           /*!< 0x8C */
    store_buf->i2c_reg[16] = I2Cx->IC_DMA_RDLR;           /*!< 0x90 */

    store_buf->i2c_reg[17] = I2Cx->IC_SDA_SETUP;          /*!< 0x94 */
}

/**
  * \brief  Restore I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Restore buffer to restore I2C register data.
  * \return None
  */
RAM_FUNCTION
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
    else if (I2Cx == I2C2)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C2, APBPeriph_I2C2_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C3)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C3, APBPeriph_I2C3_CLOCK, ENABLE);
    }

    I2Cx->IC_CON         = store_buf->i2c_reg[0];
    I2Cx->IC_TAR         = store_buf->i2c_reg[1];
    I2Cx->IC_SAR         = store_buf->i2c_reg[2];
    I2Cx->IC_FS_SPKLEN   = store_buf->i2c_reg[3];

    I2Cx->IC_SS_SCL_HCNT = store_buf->i2c_reg[4];
    I2Cx->IC_SS_SCL_LCNT = store_buf->i2c_reg[5];
    I2Cx->IC_FS_SCL_HCNT = store_buf->i2c_reg[6];
    I2Cx->IC_FS_SCL_LCNT = store_buf->i2c_reg[7];

    I2Cx->IC_INTR_MASK   = store_buf->i2c_reg[8];
    I2Cx->IC_RX_TL       = store_buf->i2c_reg[9];
    I2Cx->IC_TX_TL       = store_buf->i2c_reg[10];
    I2Cx->IC_ENABLE      = store_buf->i2c_reg[11];
    I2Cx->IC_SDA_HOLD    = store_buf->i2c_reg[12];
    I2Cx->IC_SLV_DATA_NACK_ONLY = store_buf->i2c_reg[13];
    I2Cx->IC_DMA_CR      = store_buf->i2c_reg[14];
    I2Cx->IC_DMA_TDLR    = store_buf->i2c_reg[15];
    I2Cx->IC_DMA_RDLR    = store_buf->i2c_reg[16];

    I2Cx->IC_SDA_SETUP   = store_buf->i2c_reg[17];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

