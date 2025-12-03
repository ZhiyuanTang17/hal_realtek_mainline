/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_adc.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * \brief  Store ADC register values when system enter DLPS.
 * \param  PeriReg: Specifies to select the ADC peripheral.
 * \param  StoreBuf: Store buffer to store ADC register data.
 * \return None.
 */
void ADC_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    ADCStoreReg_TypeDef *store_buf = (ADCStoreReg_TypeDef *)StoreBuf;

    /*Open 10M clock source*/
    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

    store_buf->adc_reg[0] =  ADC->CR;          //0x04
    store_buf->adc_reg[1] =  ADC->SCHCR;       //0x08
    store_buf->adc_reg[2] =  ADC->INTCR;       //0x0C
    store_buf->adc_reg[3] =  ADC->SCHTAB0;     //0x10
    store_buf->adc_reg[4] =  ADC->SCHTAB1;     //0x14
    store_buf->adc_reg[5] =  ADC->SCHTAB2;     //0x18
    store_buf->adc_reg[6] =  ADC->SCHTAB3;     //0x1C
    store_buf->adc_reg[7] =  ADC->SCHTAB4;     //0x20
    store_buf->adc_reg[8] =  ADC->SCHTAB5;     //0x24
    store_buf->adc_reg[9] =  ADC->SCHTAB6;     //0x28
    store_buf->adc_reg[10] =  ADC->SCHTAB7;    //0x2C
    store_buf->adc_reg[11] =  ADC->PWRDLY;
    store_buf->adc_reg[12] =  ADC->DATCLK;
    store_buf->adc_reg[13] =  ADC->ANACTL;
    store_buf->adc_reg[14] =  ADC->SAMTIM;
    store_buf->adc_reg[15] = btaon_fast_read_safe(0x110);

    return;
}

/**
 * \brief  Restore ADC register values when system enter DLPS.
 * \param  PeriReg: Specifies to select the ADC peripheral.
 * \param  StoreBuf: Restore buffer to restore ADC register data.
 * \return None
 */
void ADC_DLPSExit(void *PeriReg, void *StoreBuf)
{
    ADCStoreReg_TypeDef *store_buf = (ADCStoreReg_TypeDef *)StoreBuf;

    /*Open 10M clock source*/
    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

    /*Disable all interrupt.*/
    ADC->INTCR &= (~0x1f);

    /* Set power mode first */
    ADC->PWRDLY = store_buf->adc_reg[11];

    /* Disable schedule table */
    ADC->SCHCR &= (~0xffff);

    ADC->SCHTAB0 = store_buf->adc_reg[3];
    ADC->SCHTAB1 = store_buf->adc_reg[4];
    ADC->SCHTAB2 = store_buf->adc_reg[5];
    ADC->SCHTAB3 = store_buf->adc_reg[6];
    ADC->SCHTAB4 = store_buf->adc_reg[7];
    ADC->SCHTAB5 = store_buf->adc_reg[8];
    ADC->SCHTAB6 = store_buf->adc_reg[9];
    ADC->SCHTAB7 = store_buf->adc_reg[10];
    ADC->SCHCR   = store_buf->adc_reg[1];
    ADC->CR = (store_buf->adc_reg[0] & (~((uint32_t)0x03)));
    ADC->DATCLK = store_buf->adc_reg[12];
    ADC->ANACTL = store_buf->adc_reg[13];
    ADC->SAMTIM = store_buf->adc_reg[14];

    /*Clear ADC FIFO */
    ADC->CR |= BIT26;
    /* Clear all interrupt */
    ADC->INTCR |= (0x1f << 8);

    /* Restore specify interrupt */
    ADC->INTCR = store_buf->adc_reg[2];

    btaon_fast_write(0x110, store_buf->adc_reg[15]);

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
