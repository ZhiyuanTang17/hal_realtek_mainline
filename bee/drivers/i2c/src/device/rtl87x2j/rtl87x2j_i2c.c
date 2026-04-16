/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_i2c.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define I2C_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC        (0x00000)
#define I2C_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN        (0x3000F)//Force off 0x2000A

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

uint8_t I2C_GetIndex(I2C_TypeDef *I2Cx)
{
    if (I2Cx == I2C0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

uint8_t I2C_GetCompIndex(I2C_TypeDef *I2Cx)
{
    uint8_t compensate_index = 3;

    if (I2Cx == I2C0)
    {
        compensate_index = PCC_REG_READ_BITFIELD(PCC_REG_I2C0, R_I2C0_CLK_DIV_SEL);
    }
    else if (I2Cx == I2C1)
    {
        compensate_index = PCC_REG_READ_BITFIELD(PCC_REG_I2C1, R_I2C1_CLK_DIV_SEL);
    }

    return compensate_index;
}


/**
  * \brief  I2C clock divider config.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock. \ref Clock_Divider
  * \return None
  */
void I2C_SetClock(I2C_TypeDef *I2Cx, uint16_t ClockSrc, uint16_t ClockDiv)
{
    assert_param(IS_I2C_DIV(ClockDiv));

    /* Config I2C clock divider */
    if (I2Cx == I2C0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_I2C0, R_I2C0_CLK_DIV_SEL, ClockDiv);
    }
    else if (I2Cx == I2C1)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_I2C1, R_I2C1_CLK_DIV_SEL, ClockDiv);
    }

    return;
}


uint32_t I2C_GetClock(I2C_TypeDef *I2Cx)
{
    uint32_t I2CClkSrc = 0;
    uint8_t compensate_index = I2C_GetCompIndex(I2Cx);
    if (compensate_index == 6)
    {
        I2CClkSrc = 1000000;
    }
    else if (compensate_index == 7)
    {
        I2CClkSrc = 625000;
    }
    else
    {
        I2CClkSrc = 40000000 / BIT(compensate_index);
    }

    return I2CClkSrc;
}

void I2C_ClockAutoModeCmd(I2C_TypeDef *I2Cx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    if (Newstate == ENABLE)
    {
        I2Cx->QACTIVE_MANUAL_CTRL = I2C_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        I2Cx->QACTIVE_MANUAL_CTRL = I2C_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}



