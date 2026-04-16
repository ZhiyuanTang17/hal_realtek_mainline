/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_spi.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define SPI_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00000)
#define SPI_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x3003F)
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  SPI clock config.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void SPI_SetClock(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc, SPIClockDiv_TypeDef ClockDiv)
{
    assert_param(IS_SPI_CLOCK_DIV(ClockDiv));
    assert_param(IS_SPI_CLOCK_SRC(ClockSrc));

    if ((SPIx == SPI0) || (SPIx == SPI0_HS))
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, R_SPI0_CLK_SRC_SEL, ClockSrc);
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, R_SPI0_CLK_DIV_SEL, ClockDiv);
    }
    else if ((SPIx == SPI1) || (SPIx == SPI1_HS))
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI1, R_SPI1_CLK_SRC_SEL, ClockSrc);
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI1, R_SPI1_CLK_DIV_SEL, ClockDiv);
    }
    else if (SPIx == SPI2)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI2, R_SPI2_CLK_SRC_SEL, ClockSrc);
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI2, R_SPI2_CLK_DIV_SEL, ClockDiv);
    }

    return;
}

void SPI_ClockAutoModeCmd(SPI_TypeDef *SPIx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    if (Newstate == ENABLE)
    {
        SPIx->SPI_WRAP_QACTIVE_MAN = SPI_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        SPIx->SPI_WRAP_QACTIVE_MAN = SPI_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

void SPI_SPI0AHBBridgeConfig(FunctionalState NewState)
{
    if (NewState == ENABLE)
    {
        /* Open SPI0 AHB bridge*/
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, PON_SPI0_H2S_BRG_EN, 1);
    }
    else
    {
        /* Close SPI0 AHB bridge*/
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, PON_SPI0_H2S_BRG_EN, 0);
    }
}

void SPI_SPI1AHBBridgeConfig(FunctionalState NewState)
{
    if (NewState == ENABLE)
    {
        /* Open SPI1 AHB bridge*/
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI1, PON_SPI1_H2S_BRG_EN, 1);
    }
    else
    {
        /* Close SPI1 AHB bridge*/
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI1, PON_SPI1_H2S_BRG_EN, 0);
    }
}


void SPI_ConfigAPHBridge(SPI_TypeDef *SPIx)
{
    if (SPIx == SPI0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, PON_SPI0_BRG_EN, 1);
    }
    else if (SPIx == SPI1)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI1, PON_SPI1_BRG_EN, 1);
    }
    else if (SPIx == SPI2)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI2, PON_SPI2_BRG_EN, 1);
    }
}

void SPI_ConfigMasterSlave(SPIMode_Typedef SPI_Mode)
{
    if (SPI_Mode == SPI_MODE_MASTER)
    {
        /* Enable SPI0 master mode */
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, PON_SPI0_MST, 1);
    }
    else if (SPI_Mode == SPI_MODE_SLAVE)
    {
        /* Enable SPI0 slave mode */
        PCC_REG_WRITE_BITFIELD(PCC_REG_SPI0, PON_SPI0_MST, 0);
    }
}



