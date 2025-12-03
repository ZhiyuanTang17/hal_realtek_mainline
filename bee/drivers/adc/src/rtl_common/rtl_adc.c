/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_adc.c
* \brief    This file provides all the 24BIT SDADC firmware functions.
* \details
* \author   ECHO
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_adc.h"
#include "rtl_rcc.h"
#if ADC_SUPPORT_POWER_ON_DELAY
#include "utils.h"
#endif

/*============================================================================*
 *                          Private Functions
 *============================================================================*/
extern void ADC_SISet(void);
extern void ADC_DelayConfig(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);
extern void ADC_BypassRegConfig(uint8_t ChannelNum, FunctionalState NewState);
extern void ADC_ManualModeConfig(void);
extern void ADC_PowerOff(void);
extern void ADC_ManualModePowerOn(void);
extern void ADC_ManualModePowerOff(void);

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

#if ADC_SUPPORT_POWER_OFF
    ADC_PowerOff();
#endif

    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, DISABLE);
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
    assert_param(IS_ADC_FIFO_THRESHOLD(ADC_InitStruct->ADC_FifoThdLevel));

    uint8_t index = 0;
    uint32_t sch_ind = 0;
    if (ADC_InitStruct->ADC_DataAvgEn == DISABLE)
    {
        ADC_InitStruct->ADC_DataAvgSel = 0x0;
    }

    /* Set SI */
    ADC_SISet();

    /* Disable all interrupt */
    ADCx->ADC_CTRL_INT &= (~0x1f);

    /* Set power mode first */
    ADC_POW_DATA_DLY_CTRL_TypeDef adc_0x50 = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
    adc_0x50.b.adc_poweron_select = 0x1; // bit 10
#if ADC_SUPPORT_POWER_MODE_CTRL
    adc_0x50.b.adc_manual_poweron = ADC_InitStruct->ADC_PowerOnMode; //default auto power mode
#endif
    adc_0x50.b.adc_poweron_only_en = ADC_InitStruct->ADC_PowerAlwaysOnEn;
    adc_0x50.b.adc_data_delay =  ADC_InitStruct->ADC_DataLatchDly;
    adc_0x50.b.adc_fifo_stop_wr = ADC_InitStruct->ADC_FifoStopWriteEn;
    adc_0x50.b.adc_data_avg_en = ADC_InitStruct->ADC_DataAvgEn;
    adc_0x50.b.adc_data_avg_sel = ADC_InitStruct->ADC_DataAvgSel;
    ADCx->ADC_POW_DATA_DLY_CTRL = adc_0x50.d32;
    ADC_DelayConfig(ADCx, ADC_InitStruct);

#if ADC_SUPPORT_POWER_ON_DELAY
    if (ADC_InitStruct->ADC_PowerOnDlyEn == ENABLE && ADC_InitStruct->ADC_PowerAlwaysOnEn == ENABLE)
    {
        /* After the ADC is powered up, there is a re-settle time of about 8ms,
        during which the voltage acquired by the ADC has an error of about 0-10mV higher.
        This error can be avoided by turning on this delay.
        This delay is only effective when ADC_PowerAlwaysOnEn is set to ENABLE. */
        platform_delay_ms(8);
    }
#endif

    /* Set schedule table */

    for (index = 0; index < 8; index++)
    {
        sch_ind = (ADC_InitStruct->ADC_SchIndex[index * 2]) | \
                  (ADC_InitStruct->ADC_SchIndex[index * 2 + 1] << 16);
        *(__IO uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTAB0) + index) = sch_ind;
    }
#if CHIP_ADC_SCHEDULE_NUM > 16
    for (Index = 0; index < 4; index++)
    {
        sch_ind = (ADC_InitStruct->ADC_SchIndex[16 + index] << 16);
        *(__IO uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTABD16) + index) = sch_ind;
    }
#endif

    ADC_SCHED_CTRL_TypeDef adc_0x08 = {.d32 = ADCx->ADC_SCHED_CTRL};
    adc_0x08.b.adc_schedule_idx_sel =  ADC_InitStruct->ADC_Bitmap;
    ADCx->ADC_SCHED_CTRL = adc_0x08.d32;

    /* Set ADC mode */
    ADC_DIG_CTRL_TypeDef adc_0x04 = {.d32 = ADCx->ADC_DIG_CTRL};
    adc_0x04.b.adc_one_shot_fifo = ADC_InitStruct->ADC_DataWriteToFifo;
    adc_0x04.b.adc_fifo_thd = ADC_InitStruct->ADC_FifoThdLevel & 0x1F;
    adc_0x04.b.adc_burst_size = ADC_InitStruct->ADC_WaterLevel;
    adc_0x04.b.adc_fifo_overwrite = ADC_InitStruct->ADC_FifoOverWriteEn;
#if ADC_SUPPORT_DMA_EN
    adc_0x04.b.dma_mode = ADC_InitStruct->ADC_DmaEn;
#endif
    ADCx->ADC_DIG_CTRL = adc_0x04.d32;

    ADC_DATA_CLK_CTRL_TypeDef adc_0x54 = {.d32 = ADCx->ADC_DATA_CLK_CTRL};
    adc_0x54.b.adc_timer_trigger_en = ADC_InitStruct-> ADC_TimerTriggerEn;
    adc_0x54.b.adc_data_align_msb = ADC_InitStruct->ADC_DataAlign;
    adc_0x54.b.adc_data_offset_en = ADC_InitStruct->ADC_DataMinusEn;
    adc_0x54.b.adc_data_offset = ADC_InitStruct->ADC_DataMinusOffset;
    ADCx->ADC_DATA_CLK_CTRL = adc_0x54.d32;

    ADC_TIME_PERIOD_TypeDef adc_0x5C = {.d32 = ADCx->ADC_TIME_PERIOD};
    if (ADC_InitStruct->ADC_SampleTime >= 0x3FFF)
    {
        ADC_InitStruct->ADC_SampleTime = 0x3FFF;
    }

    adc_0x5C.b.adc_convert_time_period_sel = ADC_InitStruct->ADC_ConvertTime;
    adc_0x5C.b.adc_sample_time_period = ADC_InitStruct->ADC_SampleTime;
    ADCx->ADC_TIME_PERIOD = adc_0x5C.d32;

    /*clear adc fifo*/
    adc_0x04.b.adc_fifo_clr = 0x1;
    ADCx->ADC_DIG_CTRL = adc_0x04.d32;

    /*clear all interrupt*/
    ADCx->ADC_CTRL_INT |= (0x1f << 8);

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
    ADC_InitStruct->ADC_ConvertTime     = ADC_CONVERT_TIME_500NS;
    ADC_InitStruct->ADC_DataWriteToFifo = DISABLE;
    ADC_InitStruct->ADC_FifoThdLevel    = 0x06;
    ADC_InitStruct->ADC_WaterLevel      = 0x1;
    ADC_InitStruct->ADC_FifoOverWriteEn = ENABLE;
    for (uint8_t i = 0; i < CHIP_ADC_SCHEDULE_NUM; ++i)
    {
        ADC_InitStruct->ADC_SchIndex[i] = 0;
    }
    ADC_InitStruct->ADC_Bitmap          = 0x0;
    ADC_InitStruct->ADC_TimerTriggerEn  = DISABLE;
    ADC_InitStruct->ADC_DataAlign       = ADC_DATA_ALIGN_LSB;
    ADC_InitStruct->ADC_DataMinusEn     = DISABLE;
    ADC_InitStruct->ADC_DataMinusOffset = 0;
#if ADC_SUPPORT_DMA_EN
    ADC_InitStruct->ADC_DmaEn           = DISABLE;
#endif
    ADC_InitStruct->ADC_FifoStopWriteEn = DISABLE;
    ADC_InitStruct->ADC_DataAvgEn       = DISABLE;
    ADC_InitStruct->ADC_DataAvgSel      = ADC_DATA_AVERAGE_OF_2;

    /*Reserved parameter, please do not change values*/
    ADC_InitStruct->ADC_PowerAlwaysOnEn = DISABLE;
    ADC_InitStruct->ADC_DataLatchDly    = 0x1;
#if ADC_SUPPORT_POWER_ON_DELAY
    ADC_InitStruct->ADC_PowerOnDlyEn    = DISABLE;
#endif
#if ADC_SUPPORT_POWER_MODE_CTRL
    ADC_InitStruct->ADC_PowerOnMode     = ADC_POWER_ON_AUTO;
#endif
    return;
}

/**
  * \brief  Enable or disable the ADC peripheral.
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
    assert_param(IS_ADC_MODE(adcMode));

    ADC_DIG_CTRL_TypeDef adc_0x04 = {.d32 = ADCx->ADC_DIG_CTRL};
    if (NewState == ENABLE)
    {
#if ADC_SUPPORT_POWER_MODE_CTRL
        ADC_POW_DATA_DLY_CTRL_TypeDef adc_0x50 = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
        if (adc_0x50.b.adc_manual_poweron  == ADC_POWER_ON_MANUAL)
        {
            ADC_ManualModePowerOn();
        }
#endif
        if (AdcMode == ADC_ONE_SHOT_MODE)
        {
            adc_0x04.b.en_adc_one_shot_mode = 1;
            adc_0x04.b.en_adc_continous_mode = 0;
        }
        else
        {
            adc_0x04.b.en_adc_one_shot_mode = 0;
            adc_0x04.b.en_adc_continous_mode = 1;
        }
    }
    else
    {
#if ADC_SUPPORT_POWER_MODE_CTRL
        ADC_POW_DATA_DLY_CTRL_TypeDef adc_0x50 = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
        if (adc_0x50.b.adc_manual_poweron  == ADC_POWER_ON_MANUAL)
        {
            ADC_ManualModePowerOff();
        }
#endif
        adc_0x04.b.en_adc_one_shot_mode = 0;
        adc_0x04.b.en_adc_continous_mode = 0;
    }
    ADCx->ADC_DIG_CTRL = adc_0x04.d32;

    return;
}

/**
  * \brief  Enable or disable the specified ADC interrupts.
  * \param  ADCx: selected ADC peripheral.
  * \param  ADC_IT: specifies the ADC interrupts sources to be enabled or disabled.
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
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_IT(ADC_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        ADCx->ADC_CTRL_INT |= ADC_IT;
    }
    else
    {
        ADCx->ADC_CTRL_INT &= (uint32_t)~ADC_IT;
    }
}

/**
  * \brief  Read ADC data according to specific channel.
  * \param  ADCx: selected ADC peripheral.
  * \param  Index: can be 0 to 15.
  * \return The 12-bit converted ADC data.
  */
uint16_t ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t Index)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(Index < CHIP_ADC_SCHEDULE_NUM);

#if CHIP_ADC_SCHEDULE_NUM > 16
    if (Index >= 16)
    {
        return (*(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTABD16) + Index - 16));
    }
#endif

    if (Index & BIT(0))
    {
        return ((*(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHD0) + (Index >> 1))) >> 16);
    }
    else
    {
        return (*(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHD0) + (Index >> 1)));
    }
}

/**
  * \brief  Read ADC average data from ADC schedule table0.
  * \param  ADCx: selected ADC peripheral.
  * \param[out]  OutBuf: buffer to save data read from ADC FIFO.
  * \return The 12-bit converted ADC data.
  */
uint16_t ADC_ReadAvgRawData(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    return (uint16_t)(ADCx->ADC_SCHD0);
}

/**
  * \brief  Get one data from ADC FIFO.
  * \param  ADCx: selected ADC peripheral.
  * \return Adc FIFO data.
  */
uint16_t ADC_ReadFIFO(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    return (uint16_t)((ADCx->ADC_FIFO_READ) & 0xFFF);
}

/**
  * \brief  Read data from ADC FIFO.
  * \param  ADCx: selected ADC peripheral.
  * \param[out]  outBuf: buffer to save data read from ADC FIFO.
  * \param  Num: number of data to be read.
  * \return None
  */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, uint16_t *outBuf, uint16_t Num)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    while (Num--)
    {
        *outBuf++ = (uint16_t)ADCx->ADC_FIFO_READ;
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

    return ((uint8_t)(((ADCx->ADC_SCHED_CTRL) >> CHIP_ADC_SCHEDULE_NUM) & 0x3F));
}


void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t AdcMode, uint16_t Index)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_ADC_SCHEDULE_INDEX_CONFIG(adcMode));

#if CHIP_ADC_SCHEDULE_NUM > 16
    if (index >= 16)
    {
        *(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTABD16) + Index - 16) |= (AdcMode << 16);
    }
#endif

    if (Index & BIT0)
    {
        *(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTAB0) + (Index >> 1)) |= (AdcMode << 16);
    }
    else
    {
        *(uint32_t *)((uint32_t *)(&ADCx->ADC_SCHTAB0) + (Index >> 1)) |= AdcMode;
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
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    ADC_SCHED_CTRL_TypeDef adc_0x08 = {.d32 = ADCx->ADC_SCHED_CTRL};
    adc_0x08.b.adc_schedule_idx_sel = ENABLE ? BitMap : (~BitMap);
    ADCx->ADC_SCHED_CTRL = adc_0x08.d32;

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

    ADC_DIG_CTRL_TypeDef adc_0x04 = {.d32 = ADCx->ADC_DIG_CTRL};
    adc_0x04.b.adc_one_shot_fifo = NewState;
    ADCx->ADC_DIG_CTRL = adc_0x04.d32;

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
    assert_param(ChannelNum <= 16);
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    ADC_BypassRegConfig(ChannelNum, NewState);
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

    return ((ADCx->ADC_CTRL_INT & (ADC_INT << 16)) != 0);
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

    ADCx->ADC_CTRL_INT |= (ADC_INT << 8);

    return;
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

    ADC_DIG_CTRL_TypeDef adc_0x04 = {.d32 = ADCx->ADC_DIG_CTRL};
    adc_0x04.b.adc_fifo_clr = 0x1;
    ADCx->ADC_DIG_CTRL = adc_0x04.d32;

    return;
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

    return ((uint8_t)(((ADCx->ADC_CTRL_INT) & (0x1f << 16)) >> 16));
}

/**
  * \brief  Clear ADC_FIFO_STOP_WRITE status. For ADC_FIFO_STOP_WRITE bit will be asserted automatically
  *         as fifo overflow, need to be cleared in order to write data again.
  * \param  ADCx: Specify ADC peripheral.
  * \return All ADC interrupt status.
  */
void ADC_StopwriteFifoStatusClear(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    ADC_POW_DATA_DLY_CTRL_TypeDef adc_0x50 = {.d32 = ADCx->ADC_POW_DATA_DLY_CTRL};
    adc_0x50.b.adc_fifo_stop_wr = 0;
    ADCx->ADC_POW_DATA_DLY_CTRL = adc_0x50.d32;

    return;
}

/**
  * \brief  Get the index state of ADC controller.
  * \param  ADCx: Specify ADC peripheral.
  * \return BIT15:0 stores the data in the fifo, BIT31:28 stores the index of the data.
  */
uint32_t ADC_ReadScheduleIndexandFifoData(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    return ADCx->ADC_FIFO_READ ;
}

#if (ADC_SUPPORT_RAP_FUNCTION == 1)

void ADC_RAPModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_TASK_CTRL_TypeDef adc_0x64 = {.d32 = ADCx->ADC_TASK_CTRL};
    adc_0x64.b.adc_rap_mode = NewState;
    ADCx->ADC_TASK_CTRL = adc_0x64.d32;

    return;
}

void ADC_TaskTrigger(ADC_TypeDef *ADCx, uint32_t Task)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_TASK_CTRL_TypeDef adc_0x64 = {.d32 = ADCx->ADC_TASK_CTRL};
    if (Task == ADC_TASK_ONE_SHOT_SAMPLE)
    {
        adc_0x64.b.adc_fw_task_one_shot_sample = 0x1;
    }
    ADCx->ADC_TASK_CTRL = adc_0x64.d32;

    return;
}

void ADC_RAPICGCtrl(ADC_TypeDef *ADCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_QACTIVE_CTRL_TypeDef adc_0x68 = {.d32 = ADCx->ADC_QACTIVE_CTRL};
    adc_0x68.b.qact_pclk_icg_en = NewState;
    ADCx->ADC_QACTIVE_CTRL = adc_0x68.d32;

    return;
}

void ADC_RAPQactiveCtrl(ADC_TypeDef *ADCx, uint32_t Qactive, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(ADCx));

    ADC_QACTIVE_CTRL_TypeDef adc_0x68 = {.d32 = ADCx->ADC_QACTIVE_CTRL};
    if (Qactive == ADC_QACTIVE_FW_SCLK_FORCE)
    {
        adc_0x68.b.qact_sclk_force_en = NewState;
    }
    if (Qactive == ADC_QACTIVE_FW_PCLK_FORCE)
    {
        adc_0x68.b.qact_pclk_force_en = NewState;
    }
    if (Qactive == ADC_QACTIVE_FW_PCLK_ICG)
    {
        adc_0x68.b.qact_pclk_icg_en = NewState;
    }
    ADCx->ADC_QACTIVE_CTRL = adc_0x68.d32;

    return;
}
#endif
/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
