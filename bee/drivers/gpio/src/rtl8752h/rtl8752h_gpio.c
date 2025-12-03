/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_gpio.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store GPIO register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Store buffer to store GPIO register data.
  * \return None.
  */
void GPIO_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIOStoreReg_Typedef *store_buf = (GPIOStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, ENABLE);

    store_buf->gpio_reg[0] = GPIOx->DATAOUT;
    store_buf->gpio_reg[1] = GPIOx->DATADIR;
    store_buf->gpio_reg[2] = GPIOx->DATASRC;
    store_buf->gpio_reg[3] = GPIOx->INTEN;
    store_buf->gpio_reg[4] = GPIOx->INTMASK;
    store_buf->gpio_reg[5] = GPIOx->INTTYPE;
    store_buf->gpio_reg[6] = GPIOx->INTPOLARITY;
    store_buf->gpio_reg[7] = GPIOx->DEBOUNCE;
    store_buf->gpio_reg[8] = *(__IO uint32_t *)(0x40000344UL);
    store_buf->gpio_reg[9] = GPIOx->INTBOTHEDGE;

    return;
}

/**
  * \brief  Restore GPIO register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Restore buffer to restore GPIO register data.
  * \return None
  */
void GPIO_DLPSExit(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIOStoreReg_Typedef *store_buf = (GPIOStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, ENABLE);

    GPIOx->DATADIR       = store_buf->gpio_reg[1];
    GPIOx->DATASRC       = store_buf->gpio_reg[2];
    GPIOx->INTMASK       = store_buf->gpio_reg[4];
    GPIOx->INTTYPE       = store_buf->gpio_reg[5];
    GPIOx->INTPOLARITY   = store_buf->gpio_reg[6];
    GPIOx->DEBOUNCE      = store_buf->gpio_reg[7];
    GPIOx->DATAOUT       = store_buf->gpio_reg[0];
    GPIOx->INTCLR        = ~(store_buf->gpio_reg[1]);
    GPIOx->INTEN         = store_buf->gpio_reg[3];
    *(__IO uint32_t *)(0x40000344UL) = store_buf->gpio_reg[8];
    GPIOx->INTBOTHEDGE = store_buf->gpio_reg[9];

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

