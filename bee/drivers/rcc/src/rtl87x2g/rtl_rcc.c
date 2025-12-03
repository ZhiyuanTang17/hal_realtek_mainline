/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_rcc.c
* \brief    This file provides all the IO clock firmware functions..
* \details
* \author   Echo
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_rcc.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define PERI_ON_CLOCK_CTRL            *((volatile uint32_t *)PERI_ON_RCC_REG_BASE)
#define PERI_ON_AUDIO_CLOCK_CTRL      *((volatile uint32_t *)PERIBLKCTRL_AUDIO_REG_BASE)

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Enable or disable the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriphClockCmd(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t tmp_1 = APBPeriph & 0x800;
    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk = APBPeriph_Clock;
    uint32_t clk_func = APBPeriph_Clock;

    if (tmp_1 == 0x800)
    {
        clk_func += clk << 1;
    }
    else
    {
        clk_func += clk >> 1;
    }


    if (NewState == ENABLE)
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }

        else
        {
            if (APBPeriph == APBPeriph_SPI0)
            {
                if (APBPeriph_Clock == APBPeriph_SPI0_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_mux_clk_cg_en = 1;
                }
                else if (APBPeriph_Clock == APBPeriph_SPI0_SLAVE_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_mux_clk_cg_en = 1;
                }
            }
            if (APBPeriph == APBPeriph_IR)
            {
                if (APBPeriph_Clock == APBPeriph_IR_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_ir_mux_clk_cg_en = 1;
                }
            }
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            if (APBPeriph == APBPeriph_SPI0)
            {
                if (APBPeriph_Clock == APBPeriph_SPI0_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_mux_clk_cg_en = 0;
                }
                else if (APBPeriph_Clock == APBPeriph_SPI0_SLAVE_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_mux_clk_cg_en = 0;
                }
            }
            if (APBPeriph == APBPeriph_IR)
            {
                if (APBPeriph_Clock == APBPeriph_IR_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_ir_mux_clk_cg_en = 0;
                }
            }
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }

    return;
}

/**
  * \brief  Enable or disable the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriFunctionConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_APB_PERIPH(APBPeriph));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t tmp_1 = APBPeriph & 0x800;
    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk = APBPeriph_Clock;
    uint32_t clk_func = APBPeriph_Clock;

    if (tmp_1 == 0x800)
    {
        clk_func = clk << 1;
    }
    else
    {
        clk_func = clk >> 1;
    }


    if (NewState == ENABLE)
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
        else
        {
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }
    return;
}

/**
  * \brief  Enable or disable the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriClockConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk_func = APBPeriph_Clock;

    if (NewState == ENABLE)
    {

        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
        else
        {
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
