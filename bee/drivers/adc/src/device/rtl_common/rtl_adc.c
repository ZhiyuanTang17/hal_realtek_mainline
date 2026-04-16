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

#if (ADC_SUPPORT_POWER_ON_DELAY == 1)
#include "utils.h"
#endif

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern void ADC_SISet(void);
extern void ADC_DelayConfig(ADC_InitTypeDef *ADC_InitStruct);
extern void ADC_SampleTimeConfig(ADC_InitTypeDef *ADC_InitStruct);
extern void ADC_PowerOff(void);
extern void ADC_ManualModePowerOn(void);
extern void ADC_ManualModePowerOff(void);
extern void ADC_BypassDisable(void);
extern void ADC_BypassEnable(void);
extern void ADC_AnalogControlCmd(void);
extern void ADC_HWMappingEnable(void);

uint16_t adc_bypass_status = 0;

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the ADC peripheral registers to their default reset values.
  * \param  ADCx: selected ADC peripheral.
  * \return None.
  */
void ADC_DeInit(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

#if (ADC_SUPPORT_POWER_OFF == 1)
    ADC_PowerOff();
#endif

    RCC_ClockCmd(ADC_CLOCK, DISABLE);
}

/**
  * \brief Initializes the ADC peripheral according to the specified
  *   parameters in the ADC_InitStruct
  * \param  ADCx: selected ADC peripheral.
  * \param  ADC_InitStruct: pointer to a ADCInitTypeDef structure that
  *   contains the configuration information for the specified ADC peripheral
  * \return None
  */
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_LATCH_MODE(ADC_InitStruct->ADC_DataLatchEdge));
    assert_param(IS_ADC_POWER_MODE(ADC_InitStruct->ADC_PowerOnMode));
    assert_param(IS_ADC_RG2X_0_DELAY_TIME(ADC_InitStruct->ADC_RG2X0Dly));
    assert_param(IS_ADC_RG0X_1_DELAY_TIME(ADC_InitStruct->ADC_RG0X1Dly));
    assert_param(IS_ADC_RG0X_0_DELAY_TIME(ADC_InitStruct->ADC_RG0X0Dly));
    assert_param(IS_ADC_BURST_SIZE_CONFIG(ADC_InitStruct->ADC_WaterLevel));
    assert_param(IS_ADC_FIFO_THRESHOLD(ADC_InitStruct->ADC_FIFOThdLevel));

    /* Set SI */
    ADC_SISet();

    /* Disable all interrupts */
    ADCx->ADC_INT &= (~0x1f);

    /* ---------- Configure Power Mode ---------- */
    ADC_POW_DATA_DLY_CTRL_TypeDef adc_pow_data_dly_ctrl = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
    adc_pow_data_dly_ctrl.b.adc_poweron_only_en  = ADC_InitStruct->ADC_PowerAlwaysOnEn;
    adc_pow_data_dly_ctrl.b.adc_fifo_stop_wr     = ADC_InitStruct->ADC_FIFOStopWriteEn;
    adc_pow_data_dly_ctrl.b.adc_data_avg_en      = ADC_InitStruct->ADC_DataAverageEn;
    adc_pow_data_dly_ctrl.b.adc_data_avg_sel     = (ADC_InitStruct->ADC_DataAverageEn == ENABLE) ?
                                                   ADC_InitStruct->ADC_DataAverage : 0;
#ifdef ADC_POWER_MODE_CTRL_EN
    adc_pow_data_dly_ctrl.b.adc_manual_poweron   = ADC_InitStruct->ADC_PowerOnMode;
#endif
#if (ADC_SUPPORT_DATA_CLIP == 1)
    adc_pow_data_dly_ctrl.b.adc_data_clipping_en = ADC_InitStruct->ADC_DataClippingEn;
#endif
    ADCx->ADC_POW_DATA_DLY_CTRL = adc_pow_data_dly_ctrl.d32;

    /* Configure ADC auto power on delay parameters */
    ADC_DelayConfig(ADC_InitStruct);

#if (ADC_SUPPORT_POWER_ON_DELAY == 1)
    if (ADC_InitStruct->ADC_PowerOnDlyEn == ENABLE && ADC_InitStruct->ADC_PowerAlwaysOnEn == ENABLE)
    {
        /* After ADC power on, there is a re-settle time about 8ms,
         * during which the acquired voltage may be 0-10mV higher than actual.
         * Enable this delay to avoid such error, only effective when
         * ADC_PowerAlwaysOnEn is set to ENABLE.
         */
        platform_delay_ms(8);
    }
#endif

    /* ---------- Configure Schedule Table ---------- */
    uint32_t sch_index = 0;
    for (uint8_t index = 0; index < 8; index++)
    {
        sch_index = (ADC_InitStruct->ADC_SchIndex[index * 2]) |
                    (ADC_InitStruct->ADC_SchIndex[index * 2 + 1] << 16);
        *((volatile uint32_t *)(&ADCx->ADC_SCHTAB0) + index) = sch_index;
    }
#if (CHIP_ADC_SCHEDULE_NUM > 16)
    for (uint8_t index = 0; index < 4; index++)
    {
        sch_ind = (ADC_InitStruct->ADC_SchIndex[16 + index] << 16);
        *((volatile uint32_t *)(&ADCx->ADC_SCHTABD16) + index) = sch_ind;
    }
#endif

    /* Configure schedule control register */
    ADC_SCHED_CTRL_TypeDef adc_sched_ctrl = {.d32 = ADCx->ADC_SCHED_CTRL};
    adc_sched_ctrl.b.adc_schedule_idx_sel = ADC_InitStruct->ADC_Bitmap;
    ADCx->ADC_SCHED_CTRL = adc_sched_ctrl.d32;

    /* ---------- Configure ADC Mode ---------- */
    ADC_CTRL_TypeDef adc_ctrl = {.d32 = ADCx->ADC_CTRL};
    adc_ctrl.b.adc_one_shot_fifo   = ADC_InitStruct->ADC_DataWriteToFIFO;
    adc_ctrl.b.adc_fifo_thd        = ADC_InitStruct->ADC_FIFOThdLevel & 0x1F;
    adc_ctrl.b.adc_burst_size      = ADC_InitStruct->ADC_WaterLevel;
    adc_ctrl.b.adc_fifo_overwrite  = ADC_InitStruct->ADC_FIFOOverWriteEn;
#if (ADC_SUPPORT_DMA_EN == 1)
    adc_ctrl.b.adc_dma_mode        = ADC_InitStruct->ADC_DMAEn;
#endif
    ADCx->ADC_CTRL = adc_ctrl.d32;

    /* Configure data clock control register */
    ADC_DATA_CLK_CTRL_TypeDef adc_data_clk_ctrl = { .d32 = ADCx->ADC_DATA_CLK_CTRL };
#if ADC_SUPPORT_TIMER_TRIGGER
    adc_data_clk_ctrl.b.adc_timer_trigger_en = ADC_InitStruct->ADC_TimerTriggerEn;
#endif
    adc_data_clk_ctrl.b.adc_data_align_msb = ADC_InitStruct->ADC_DataAlign;
#if (ADC_SUPPORT_DATAMINUS == 1)
    adc_data_clk_ctrl.b.adc_data_offset_en   = ADC_InitStruct->ADC_DataMinusEn;
    adc_data_clk_ctrl.b.adc_data_offset      = ADC_InitStruct->ADC_DataMinusOffset;
#endif
    ADCx->ADC_DATA_CLK_CTRL = adc_data_clk_ctrl.d32;

#if (ADC_SUPPORT_HW_MAPPING ==1)
    ADC_HWMappingEnable();
#endif

    /* ---------- Configure Sample Time ---------- */
    ADC_TIME_PERIOD_TypeDef adc_time_period = {.d32 = ADCx->ADC_TIME_PERIOD};
    ADC_SampleTimeConfig(ADC_InitStruct);
    adc_time_period.b.adc_convert_time_period_sel = ADC_InitStruct->ADC_ConvertTime;
    adc_time_period.b.adc_sample_time_period      = ADC_InitStruct->ADC_SampleTime & 0x3FFF;
    ADCx->ADC_TIME_PERIOD = adc_time_period.d32;

    /* Clear ADC FIFO */
    adc_ctrl.b.adc_fifo_clr = 0x1;
    ADCx->ADC_CTRL = adc_ctrl.d32;

    /* Clear all interrupt flags */
    ADCx->ADC_INT |= (0x1f << 8);

    return;
}

/**
  * \brief  Fills each ADC_InitStruct member with its default value.
  * \param  ADC_InitStruct: pointer to an ADC_InitTypeDef structure which will be initialized.
  * \return None
  */
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct)
{
    ADC_InitStruct->ADC_SampleTime      = 0x3E7;
#if (ADC_SUPPORT_SAMPLE_RATE_GUARDTIME == 1)
    ADC_InitStruct->ADC_ConvertTime     = ADC_CONVERT_TIME_600NS;
#else
    ADC_InitStruct->ADC_ConvertTime     = ADC_CONVERT_TIME_500NS;
#endif
    ADC_InitStruct->ADC_DataWriteToFIFO = DISABLE;
    ADC_InitStruct->ADC_FIFOThdLevel    = 0x06;
    ADC_InitStruct->ADC_WaterLevel      = 0x1;
    ADC_InitStruct->ADC_FIFOOverWriteEn = ENABLE;
    for (uint8_t i = 0; i < CHIP_ADC_SCHEDULE_NUM; ++i)
    {
        ADC_InitStruct->ADC_SchIndex[i] = 0;
    }
    ADC_InitStruct->ADC_Bitmap          = 0x0;
#if ADC_SUPPORT_TIMER_TRIGGER
    ADC_InitStruct->ADC_TimerTriggerEn  = DISABLE;
#endif
    ADC_InitStruct->ADC_DataAlign       = ADC_DATA_ALIGN_LSB;
#if (ADC_SUPPORT_DATAMINUS==1)
    ADC_InitStruct->ADC_DataMinusEn     = DISABLE;
    ADC_InitStruct->ADC_DataMinusOffset = 0;
#endif
#if (ADC_SUPPORT_DMA_EN == 1)
    ADC_InitStruct->ADC_DMAEn           = DISABLE;
#endif
    ADC_InitStruct->ADC_FIFOStopWriteEn = DISABLE;
    ADC_InitStruct->ADC_DataAverageEn   = DISABLE;
    ADC_InitStruct->ADC_DataAverage     = ADC_DATA_AVERAGE_OF_2;

    /*Reserved parameter, please do not change values*/
    ADC_InitStruct->ADC_PowerAlwaysOnEn = DISABLE;
#if (ADC_SUPPORT_POWER_ON_DELAY == 1)
    ADC_InitStruct->ADC_PowerOnDlyEn    = DISABLE;
#endif
#ifdef ADC_POWER_MODE_CTRL_EN
    ADC_InitStruct->ADC_PowerOnMode     = ADC_POWER_ON_AUTO;
#endif

#if (ADC_SUPPORT_DATA_CLIP ==1 )
    ADC_InitStruct->ADC_DataClippingEn  = ENABLE;
#endif
    return;
}

/**
  * \brief  Enables or disables the ADC peripheral.
  * \param  ADCx: selected ADC peripheral.
  * \param  AdcMode: adc mode select.
  *         This parameter can be one of the following values:
  *         \arg ADC_ONE_SHOT_MODE: one shot mode.
  *         \arg ADC_CONTINUOUS_MODE: continuous mode.
  * \param  NewState: new state of the ADC peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void ADC_Cmd(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef AdcMode, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_ADC_MODE(AdcMode));

    ADC_CTRL_TypeDef adc_ctrl = {.d32 = ADCx->ADC_CTRL};
    ADC_POW_DATA_DLY_CTRL_TypeDef adc_pow_data_dly_ctrl = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};

    if (NewState == ENABLE)
    {
        ADC_BypassEnable();
#ifdef ADC_POWER_MODE_CTRL_EN
        if (adc_pow_data_dly_ctrl.b.adc_manual_poweron == ADC_POWER_ON_MANUAL)
        {
            ADC_ManualModePowerOn();
        }
#endif
        if (AdcMode == ADC_ONE_SHOT_MODE)
        {
            adc_ctrl.b.en_adc_one_shot_mode = 1;
            adc_ctrl.b.en_adc_continuous_mode = 0;
        }
        else
        {
            adc_ctrl.b.en_adc_one_shot_mode = 0;
            adc_ctrl.b.en_adc_continuous_mode = 1;
        }
        ADCx->ADC_CTRL = adc_ctrl.d32;
    }
    else
    {
#ifdef ADC_POWER_MODE_CTRL_EN
        if (adc_pow_data_dly_ctrl.b.adc_manual_poweron == ADC_POWER_ON_MANUAL)
        {
            ADC_ManualModePowerOff();
        }
#endif
        adc_ctrl.b.en_adc_one_shot_mode = 0;
        adc_ctrl.b.en_adc_continuous_mode = 0;
        ADCx->ADC_CTRL = adc_ctrl.d32;
#if (ADC_SUPPORT_BYPASS_AUTO_REVERT == 0)
        ADC_BypassDisable();
#endif
    }

    return;
}

/**
  * \brief  Enables or disables the specified ADC interrupts.
  * \param  ADCx: selected ADC peripheral.
  * \param  ADC_INT: specifies the ADC interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg ADC_INT_FIFO_RD_REQ :FIFO read request
  *         \arg ADC_INT_FIFO_RD_ERR :FIFO read error
  *         \arg ADC_INT_FIFO_THD :ADC FIFO size > thd
  *         \arg ADC_INT_FIFO_FULL :ADC FIFO overflow
  *         \arg ADC_INT_ONE_SHOT_DONE :ADC one shot mode done
  * \param  NewState: new state of the specified ADC interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_INT(ADC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        ADCx->ADC_INT |= ADC_INT;
    }
    else
    {
        ADCx->ADC_INT &= ~ADC_INT;
    }
}

/**
  * \brief  Checks whether the specified ADC interrupt status flag is set or not.
  * \param  ADCx: selected ADC peripheral.
  * \param  ADC_INT_FLAG: specifies the interrupt status flag to check.
  *     This parameter can be one of the following values:
  *     \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt
  *     \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt
  *     \arg ADC_INT_FIFO_THD: fifo larger than threshold
  *     \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt
  *     \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt
  * \return The new state of ADC_INT (SET or RESET).
  */
ITStatus ADC_GetINTStatus(ADC_TypeDef *ADCx, uint32_t ADC_INT)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_INT(ADC_INT));

    return (ITStatus)((ADCx->ADC_INT & (ADC_INT << 16)) != 0);
}

/**
  * \brief  Get all adc interrupt flag status.
  * \param  ADCx: Specify ADC peripheral.
  * \return All ADC interrupt status.
  */
uint8_t ADC_GetAllFlagStatus(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    return ((uint8_t)(((ADCx->ADC_INT) & (0x1F << 16)) >> 16));
}

/**
  * \brief  Clear the ADC interrupt pending bit.
  * \param  ADCx: selected ADC peripheral.
  * \param  ADC_INT: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *         \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt
  *         \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt
  *         \arg ADC_INT_FIFO_THD: fifo larger than threshold
  *         \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt
  *         \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt
  * \return None
  */
void ADC_ClearINTPendingBit(ADC_TypeDef *ADCx, uint32_t ADC_INT)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_INT(ADC_INT));

    ADCx->ADC_INT |= (ADC_INT << 8);

    return;
}

/**
  * \brief  Read ADC data according to specific channel.
  * \param  ADCx: selected ADC peripheral.
  * \param  Index: can be 0 to 15.
  * \return The 12-bit converted ADC data.
  */
ADCDataWidth ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t Index)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(Index < CHIP_ADC_SCHEDULE_NUM);

#if(ADC_SUPPORT_18BIT_RAW_DATA == 1)
    return (*((volatile uint32_t *)(&ADCx->ADC_DATA0) + Index));
#else
#if (CHIP_ADC_SCHEDULE_NUM > 16)
    if (Index >= 16)
    {
        return (*((volatile uint32_t *)(&ADCx->ADC_SCHTABD16) + Index - 16));
    }
#endif

    if (Index & BIT(0))
    {
        return ((*((volatile uint32_t *)(&ADCx->ADC_SCHD0) + (Index >> 1))) >> 16);
    }
    else
    {
        return (*((volatile uint32_t *)(&ADCx->ADC_SCHD0) + (Index >> 1)));
    }
#endif
}

/**
  * \brief  Read ADC average data from ADC schedule table0.
  * \param  ADCx: selected ADC peripheral.
  * \param[out]  OutBuf: buffer to save data read from ADC FIFO.
  * \return The 12-bit converted ADC data.
  */
ADCDataWidth ADC_ReadAvgRawData(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

#if(ADC_SUPPORT_18BIT_RAW_DATA == 1)
    return (ADCx->ADC_DATA0);
#else
    return (uint16_t)(ADCx->ADC_SCHD0);
#endif
}

/**
  * \brief  Get one data from ADC FIFO.
  * \param  ADCx: selected ADC peripheral.
  * \return Adc FIFO data.
  */
ADCDataWidth ADC_ReadFIFO(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

#if(ADC_SUPPORT_18BIT_RAW_DATA == 1)
    return ((ADCx->ADC_FIFO));
#else
    return (uint16_t)((ADCx->ADC_FIFO_READ) & 0xFFF);
#endif
}

/**
  * \brief  Read data from ADC FIFO.
  * \param  ADCx: selected ADC peripheral.
  * \param[out]  OutBuf: buffer to save data read from ADC FIFO.
  * \param  Num: number of data to be read.
  * \return None
  */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, ADCDataWidth *OutBuf, uint16_t Num)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    while (Num--)
    {
#if(ADC_SUPPORT_18BIT_RAW_DATA == 1)
        *OutBuf++ = ADCx->ADC_FIFO;
#else
        *OutBuf++ = (uint16_t)ADCx->ADC_FIFO_READ;
#endif
    }

    return;
}

/**
  * \brief  Get ADC fifo data number.
  * \param  ADCx: selected ADC peripheral.
  * \return current data number in adc fifo.
  */
uint8_t ADC_GetFIFODataLen(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    ADC_SCHED_CTRL_TypeDef adc_sched_ctrl = {.d32 = ADCx->ADC_SCHED_CTRL};
    return ((uint8_t) adc_sched_ctrl.b.adc_fifo_data_level);
}

/**
 * \brief  Config ADC schedule table.
 * \param  ADCx: Specify ADC peripheral.
 * \param  ADCMode: ADC operation mode.
 * \return  None.

 */
void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t ADCMode, uint16_t Index)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_SCHEDULE_INDEX_CONFIG(AdcMode));

#if (CHIP_ADC_SCHEDULE_NUM > 16)
    if (index >= 16)
    {
        *((volatile uint32_t *)(&ADCx->ADC_SCHTABD16) + Index - 16) |= (AdcMode << 16);
    }
#endif

    if (Index & BIT0)
    {
        *((volatile uint32_t *)(&ADCx->ADC_SCHTAB0) + (Index >> 1)) |= (ADCMode << 16);
    }
    else
    {
        *((volatile uint32_t *)(&ADCx->ADC_SCHTAB0) + (Index >> 1)) |= ADCMode;
    }

    return;
}

/**
  * \brief  Set adc schedule table.
  * \param  ADCx: selected ADC peripheral.
  * \param  BitMap: ADC bit map.
  * \param  NewState: new state of the ADC peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * \return none.
  */
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    ADC_SCHED_CTRL_TypeDef adc_sched_ctrl = {.d32 = ADCx->ADC_SCHED_CTRL};
    adc_sched_ctrl.b.adc_schedule_idx_sel = BitMap;
    ADCx->ADC_SCHED_CTRL = adc_sched_ctrl.d32;

    return;
}

/**
  * \brief  Enbale or disable stop fifo from writing data.
  * \param  ADCx: selected ADC peripheral.
  * \param  NewState: new state of the ADC fifo write.
  *     This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void ADC_WriteFIFOCmd(ADC_TypeDef *ADCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    ADC_CTRL_TypeDef adc_ctrl = {.d32 = ADCx->ADC_CTRL};
    adc_ctrl.b.adc_one_shot_fifo = NewState;
    ADCx->ADC_CTRL = adc_ctrl.d32;

    return;
}

/**
  * \brief  Config ADC bypass resistor.Attention!!!Channels using bypass mode cannot over 0.9V!!!!
  * \param  ChannelNum: external channel number, can be 0~15.
  * \param  NewState: ENABLE or DISABLE.
  * \return None
  */
void ADC_BypassCmd(uint8_t ChannelNum, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(ChannelNum <= CHIP_ADC_CHANNEL_NUM);
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (!IS_ADC_CHANNEL(ChannelNum))
    {
        return;
    }

    if (NewState != DISABLE)
    {
        adc_bypass_status |= BIT(ChannelNum);
    }
    else
    {
        adc_bypass_status &= ~BIT(ChannelNum);
    }
}

/**
  * \brief  Clear ADC FIFO.
  * \param  ADCx: Specify ADC peripheral.
  * \return None
  */
void ADC_ClearFIFO(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    ADC_CTRL_TypeDef adc_ctrl = {.d32 = ADCx->ADC_CTRL};
    adc_ctrl.b.adc_fifo_clr = 0x1;
    ADCx->ADC_CTRL = adc_ctrl.d32;

    return;
}

/**
  * \brief  Enables or disables the ADC power always on.
  * \param  ADCx: selected ADC peripheral.
  * \param  NewState: new state of the specified ADC power always on.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void ADC_PowerAlwaysOnCmd(ADC_TypeDef *ADCx, FunctionalState NewState)
{
    ADC_POW_DATA_DLY_CTRL_TypeDef adc_pow_data_dly_ctrl = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
    adc_pow_data_dly_ctrl.b.adc_poweron_only_en = NewState;
    ADCx->ADC_POW_DATA_DLY_CTRL =  adc_pow_data_dly_ctrl.d32;

#if(ADC_SUPPORT_AUTO_POWER_ON_PROTECT == 1)
    ADC_AnalogControlCmd();
#endif
}

#if (ADC_SUPPORT_RAP_FUNCTION == 1)
/**
  * \brief  Enables or disables RAP Mode.
  * \param  ADCx: Pointer to the selected ADC peripheral. \ref ADC Declaration
  * \param  NewState: New state of the RAP mode.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void ADC_RAPModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_TASK_CTRL_TypeDef adc_task_ctrl = {.d32 = ADCx->ADC_TASK_CTRL};
    adc_task_ctrl.b.adc_rap_mode = NewState;
    ADCx->ADC_TASK_CTRL = adc_task_ctrl.d32;

    return;
}

/**
  * \brief  Trigger an task which special of by firmware.
  * \param  ADCx: Pointer to the selected ADC peripheral. \ref ADC Declaration
  * \param  Action: ADC task to be trigger. \ref ADC_Action.
  * \return None
  */
void ADC_ActionTrigger(ADC_TypeDef *ADCx, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_TASK_CTRL_TypeDef adc_task_ctrl = {.d32 = ADCx->ADC_TASK_CTRL};
    if (Action == ADC_ACTION_ONE_SHOT_SAMPLE)
    {
        adc_task_ctrl.b.adc_fw_task_one_shot_sample = 0x1;
    }
    ADCx->ADC_TASK_CTRL = adc_task_ctrl.d32;

    return;
}
#endif


