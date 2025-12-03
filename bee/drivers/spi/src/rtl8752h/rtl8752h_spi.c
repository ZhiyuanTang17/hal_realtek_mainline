/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_spi.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store SPI register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the SPI peripheral.
  * \param  StoreBuf: Store buffer to store SPI register data.
  * \return None.
  */
void SPI_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }

    store_buf->spi_reg[0] = SPIx->CTRLR0;
    store_buf->spi_reg[1] = SPIx->CTRLR1;
    store_buf->spi_reg[2] = SPIx->SSIENR;
    store_buf->spi_reg[3] = SPIx->SER;
    store_buf->spi_reg[4] = SPIx->BAUDR;
    store_buf->spi_reg[5] = SPIx->TXFTLR;
    store_buf->spi_reg[6] = SPIx->RXFTLR;
    store_buf->spi_reg[7] = SPIx->IMR;
    store_buf->spi_reg[8] = SPIx->DMACR;
    store_buf->spi_reg[9] = SPIx->DMATDLR;
    store_buf->spi_reg[10] = SPIx->DMARDLR;
    store_buf->spi_reg[11] = SPIx->RX_SAMPLE_DLY;
    store_buf->spi_reg[12] = *(volatile uint32_t *)0x40000308;
    store_buf->spi_reg[13] = *(volatile uint32_t *)0x4000035CUL;
}

/**
  * \brief  Restore SPI register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the SPI peripheral.
  * \param  StoreBuf: Restore buffer to restore SPI register data.
  * \return None
  */
void SPI_DLPSExit(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }

    *(volatile uint32_t *)0x40000308 = store_buf->spi_reg[12];
    *(volatile uint32_t *)0x4000035CUL = store_buf->spi_reg[13];
    SPIx->CTRLR0 = store_buf->spi_reg[0];
    SPIx->CTRLR1 = store_buf->spi_reg[1];
    SPIx->SER = store_buf->spi_reg[3];
    SPIx->BAUDR = store_buf->spi_reg[4];
    SPIx->TXFTLR = store_buf->spi_reg[5];
    SPIx->RXFTLR = store_buf->spi_reg[6];
    SPIx->IMR = store_buf->spi_reg[7];
    SPIx->DMACR = store_buf->spi_reg[8];
    SPIx->DMATDLR = store_buf->spi_reg[9];
    SPIx->DMARDLR = store_buf->spi_reg[10];
    SPIx->RX_SAMPLE_DLY = store_buf->spi_reg[11];

    /* Enable the selected SPI peripheral */
    SPIx->SSIENR = store_buf->spi_reg[2];

}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

