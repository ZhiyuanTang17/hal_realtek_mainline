/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_adc.h"
#include "rtl_rcc.h"
#include "utils.h"

/*============================================================================*
 *                           Private Macros
 *============================================================================*/
#define ADC_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define ADC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x7E)//Force off 0x54

extern uint16_t adc_bypass_status;

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

void ADC_PowerOff(void)
{
    /*Power off control flow!*/
}

void ADC_SampleTimeConfig(ADC_InitTypeDef *ADC_InitStruct)
{
    uint8_t adc_divide_mode = 0;
    uint8_t adc_bitnum = 0;
    uint8_t adc_sch_table = 0;
    uint8_t adc_mode = 0;
    uint8_t adc_channel;
    uint16_t adc_bitmap = ADC->ADC_SCHED_CTRL & 0xFFFF;

    while (adc_bitmap)
    {
        adc_bitnum = __builtin_ffs(adc_bitmap) - 1;
        adc_bitmap &= ~BIT(adc_bitnum);
        adc_sch_table = (adc_bitnum & 0x1) ? \
                        ((*((volatile uint32_t *)(&ADC->ADC_SCHTAB0) + (adc_bitnum >> 1))) >> 16) :
                        (*((volatile uint32_t *)(&ADC->ADC_SCHTAB0) + (adc_bitnum >> 1))) ;
        adc_mode = (adc_sch_table >> 3) & 0x3;
        adc_channel = adc_sch_table & 0x7;

        if (adc_mode == ADC_MODE_INTERNAL_VALUE)
        {
            adc_divide_mode = 1;
            break;
        }

        if ((BIT(adc_channel) & adc_bypass_status) != BIT(adc_channel))
        {
            adc_divide_mode = 1;
            break;
        }
    }

    uint16_t min_time = adc_divide_mode ? 18 : 3;
    uint16_t max_time = 0x3FFF;

    if (ADC_InitStruct->ADC_SampleTime < min_time)
    {
        ADC_InitStruct->ADC_SampleTime = min_time;
    }
    else if (ADC_InitStruct->ADC_SampleTime > max_time)
    {
        ADC_InitStruct->ADC_SampleTime = max_time;
    }
}

void ADC_BypassDisable(void)
{
    if (adc_bypass_status)
    {
        REG0X_AUX_TypeDef adc_reg0x_aux = {.d32 = ADC->REG0X_AUX};
        adc_reg0x_aux.b.bypassen &= ~adc_bypass_status;
        ADC->REG0X_AUX = adc_reg0x_aux.d32;
    }
}

void ADC_BypassEnable(void)
{
    if (adc_bypass_status)
    {
        uint8_t adc_bitnum = 0;
        uint8_t adc_sch_table = 0;
        uint8_t adc_mode = 0;
        uint8_t adc_channel = 0;
        uint16_t adc_bitmap = ADC->ADC_SCHED_CTRL & 0xFFFF;
        REG0X_AUX_TypeDef adc_reg0x_aux = {.d32 = ADC->REG0X_AUX};

        while (adc_bitmap)
        {
            adc_bitnum = __builtin_ffs(adc_bitmap) - 1;
            adc_bitmap &= ~BIT(adc_bitnum);
            adc_sch_table = (adc_bitnum & 0x1) ?
                            ((*((volatile uint32_t *)(&ADC->ADC_SCHTAB0) + (adc_bitnum >> 1))) >> 16) :
                            (*((volatile uint32_t *)(&ADC->ADC_SCHTAB0) + (adc_bitnum >> 1))) ;
            adc_mode = (adc_sch_table >> 3) & 0x3;
            adc_channel = adc_sch_table & 0x7;

            if ((adc_mode >= ADC_MODE_SINGLE_ENDED_VALUE) &&
                (adc_mode <= ADC_MODE_DIFFERENTIAL_VALUE) &&
                (BIT(adc_channel) & adc_bypass_status))
            {
                adc_reg0x_aux.b.bypassen |= BIT(adc_channel);
                if (adc_mode == ADC_MODE_DIFFERENTIAL_VALUE)
                {
                    adc_channel = (adc_channel & 0x1) ? (adc_channel - 1) : (adc_channel + 1);
                    if (BIT(adc_channel) & adc_bypass_status)
                    {
                        adc_reg0x_aux.b.bypassen |= BIT(adc_channel);
                    }
                }
            }
        }

        ADC->REG0X_AUX = adc_reg0x_aux.d32;
    }
}

void ADC_ClockAutoModeCmd(ADC_TypeDef *ADCx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    if (Newstate == ENABLE)
    {
        ADCx->ADC_QACTIVE_CTRL = ADC_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        ADCx->ADC_QACTIVE_CTRL = ADC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}



