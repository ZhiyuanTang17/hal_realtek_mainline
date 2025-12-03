/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_spi.c
* \brief    This file provides all the SPI firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_spi.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                        Public Functions
 *============================================================================*/
void SPI_ClkDivConfig(SPI_TypeDef *SPIx, SPIClockDiv_TypeDef ClockDiv)
{
    assert_param(IS_SPI_DIV(ClockDiv));

    /* Config SPI clock divider */
    if (SPIx == SPI0 || SPIx == SPI0_HS)
    {
        /* disable clock first */
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 1;
    }
    else if (SPIx == SPI1)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 1;

    }
    else if (SPIx == SPI0_SLAVE)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 1;
    }
    return;
}

bool SPI_ClkGet(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef *ClockSrc, SPIClockDiv_TypeDef *ClockDiv)
{
    if (SPIx == SPI0)
    {
        // read clk div
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en == 0) ? SPI_CLOCK_DIVIDER_1 :
                    (SPIClockDiv_TypeDef)PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_sel;
        // read clk src
        *ClockSrc = (PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel1 == 0) ? SPI_CLOCK_SRC_40M :
                    (SPIClockSrc_TypeDef)PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel0;
    }
    else if (SPIx == SPI0_SLAVE)
    {
        // read clk div
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en == 0) ? SPI_CLOCK_DIVIDER_1 :
                    (SPIClockDiv_TypeDef)PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_sel;
        // read clk src
        *ClockSrc = (PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel1 == 0) ? SPI_CLOCK_SRC_40M :
                    (SPIClockSrc_TypeDef)PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel0;
    }
    else if (SPIx == SPI1)
    {
        *ClockSrc = SPI_CLOCK_SRC_40M;
        *ClockDiv = (PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en == 0) ? SPI_CLOCK_DIVIDER_1 :
                    (SPIClockDiv_TypeDef)PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_sel;
    }
    else
    {
        return false;
    }

    return true;
}

void SPI_ClkConfig(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc, SPIClockDiv_TypeDef ClockDiv)
{
    assert_param(IS_SPI_DIV(ClockDiv));
    assert_param(IS_SPI_CLK_SOURCE(ClockSrc));
    if (SPIx == SPI0)
    {
        /* disable clock first */
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 0;
        if (ClockSrc == SPI_CLOCK_SRC_40M)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel1 = 0;
        }
        else if (ClockSrc == SPI_CLOCK_SRC_PLL1)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel1 = 1;
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel0 = 0;
        }
        else if (ClockSrc == SPI_CLOCK_SRC_PLL2)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel1 = 1;
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_src_clk_sel0 = 1;
        }
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 1;
    }
    else if (SPIx == SPI0_SLAVE)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 0;
        if (ClockSrc == SPI_CLOCK_SRC_40M)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel1 = 0;
        }
        else if (ClockSrc == SPI_CLOCK_SRC_PLL1)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel1 = 1;
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel0 = 0;
        }
        else if (ClockSrc == SPI_CLOCK_SRC_PLL2)
        {
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel1 = 1;
            PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_src_clk_sel0 = 1;
        }
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 1;
    }
    else if (SPIx == SPI1)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 1;
    }
    return;
}

void SPI_SPI0AHBBridgeConfig(FunctionalState NewState)
{
    if (NewState == ENABLE)
    {
        /* Open SPI0 AHB bridge*/
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_hs_ck_en = 1;
    }
    else
    {
        /* Close SPI0 AHB bridge*/
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_hs_ck_en = 0;
    }
}

void SPI_ConfigAPHBridge(SPI_TypeDef *SPIx)
{
    if (SPIx == SPI0)
    {
        /*Open SPI0 APB Bridge for high speed*/
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_brg_en = 1;
    }
    else if (SPIx == SPI1)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_brg_en = 1;
    }
    else if (SPIx == SPI0_HS)
    {
        /*Close SPI0 APB Bridge for high speed*/
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_brg_en = 0;
    }
}


RAM_FUNCTION
void SPI_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI0_SLAVE)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0_SLAVE, APBPeriph_SPI0_SLAVE_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }

    store_buf->spi_reg[0] = SPIx->SPI_M_S_CTRL0;        /*!< 0x00 */
    store_buf->spi_reg[1] = SPIx->SPI_M_CTRL1;          /*!< 0x04 */
    store_buf->spi_reg[2] = SPIx->SPI_SPIENR;           /*!< 0x08 */
    store_buf->spi_reg[3] = SPIx->SPI_M_SER;            /*!< 0x10 */
    store_buf->spi_reg[4] = SPIx->SPI_M_BAUDR;          /*!< 0x14 */
    store_buf->spi_reg[5] = SPIx->SPI_TXFTLR;           /*!< 0x18 */
    store_buf->spi_reg[6] = SPIx->SPI_RXFTLR;           /*!< 0x1C */
    store_buf->spi_reg[7] = SPIx->SPI_M_S_IMR;          /*!< 0x2C */
    store_buf->spi_reg[8] = SPIx->SPI_DMACR;            /*!< 0x4C */
    store_buf->spi_reg[9] = SPIx->SPI_DMATDLR;          /*!< 0x50 */
    store_buf->spi_reg[10] = SPIx->SPI_DMARDLR;         /*!< 0x54 */
    store_buf->spi_reg[11] = SPIx->SPI_M_RSDR;          /*!< 0xF0 */
}


RAM_FUNCTION
void SPI_DLPSExit(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI0_SLAVE)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0_SLAVE, APBPeriph_SPI0_SLAVE_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }
    if (SPIx == SPI0_HS)
    {
        SPI_ConfigAPHBridge(SPIx);
        SPI_SPI0AHBBridgeConfig(ENABLE);
    }

    SPIx->SPI_M_S_CTRL0 = store_buf->spi_reg[0];
    SPIx->SPI_M_CTRL1   = store_buf->spi_reg[1];
    SPIx->SPI_M_SER     = store_buf->spi_reg[3];
    SPIx->SPI_M_BAUDR   = store_buf->spi_reg[4];
    SPIx->SPI_TXFTLR    = store_buf->spi_reg[5];
    SPIx->SPI_RXFTLR    = store_buf->spi_reg[6];
    SPIx->SPI_M_S_IMR   = store_buf->spi_reg[7];
    SPIx->SPI_DMACR     = store_buf->spi_reg[8];
    SPIx->SPI_DMATDLR   = store_buf->spi_reg[9];
    SPIx->SPI_DMARDLR   = store_buf->spi_reg[10];
    SPIx->SPI_M_RSDR    = store_buf->spi_reg[11];

    /* Enable the selected SPI peripheral */
    SPIx->SPI_SPIENR    = store_buf->spi_reg[2];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

