/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_codec.h"
#include "rtl_rcc.h"
#include "utils.h"
/*============================================================================*
 *                           Private Macros
 *============================================================================*/
#define AUXADC_AON_REG0X1B90              ((AON_NS_REG0X_LDO_TYPE *)0x40001B90UL)
#define LPC_AON_AUXADC                    ((AON_NS_REG0X_SD_TYPE *)0x40001B98UL)
#define PERI_ON_ADC_CLOCK_CTRL             *((volatile uint32_t *)0x4000231CUL)
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Initialize the CODEC analog registers in AON area.
  * \param  None.
  * \return None
  */
void CODEC_AnalogCircuitInit(void)
{
    /*Added to stabilize the power supply!*/
    /* set to LDO mode */
//    AUXADC_AON_REG0X1B90->hw_pd = 0x0;
//    AUXADC_AON_REG0X1B90->anapar_pow_ad_0 = 0x1;
//    platform_delay_us(10);
//    AUXADC_AON_REG0X1B90->EN_ILIMIT = 0x1;
//    AUXADC_AON_REG0X1B90->LDOBW  = 0x0;
//    AUXADC_AON_REG0X1B90->Power = 0x0;
//    AUXADC_AON_REG0X1B90->anapar_pow_ad_2 = 0x1;
//    AUXADC_AON_REG0X1B90->REG_LDO_TUNE_6_0 = 0x57; //  7'b1010111
//    AUXADC_AON_REG0X1B90->SELLDO = 0x1;
//    platform_delay_us(10);
//    AUXADC_AON_REG0X1B90->anapar_pow_ad_1 = 0x1;

//    if (AUXADC_AON_REG0X1B90->EN_ILIMIT == 0x0)
//    {
//        platform_delay_us(20);
//    }
//    else
//    {
//        platform_delay_us(15);
//        AUXADC_AON_REG0X1B90->EN_ILIMIT = 0x0;
//    }
//    platform_delay_us(2);

}

/**
  * \brief  Deinitialize the CODEC analog registers in AON area.
  * \param  None.
  * \return None
  */
static void CODEC_POF(void)
{
    AUDIO_CLOCK_CONTROL_2_TypeDef codec_0x10C = {.d32 = CODEC->AUDIO_CLOCK_CONTROL_2};
    if ((codec_0x10C.b.dmic1_clk_sel == CODEC_CH_AMIC))
    {
        AUDIO_PON_POF_TypeDef  codec_0x020 =  {.d32 = CODEC_ANA->AUDIO_PON_POF};
        codec_0x020.b.audio_pof_en = 0x1;
        CODEC_ANA->AUDIO_PON_POF =  codec_0x020.d32;
        /* Polling audio pon ready init*/
        while ((CODEC_ANA->AUDIO_INT_CONTROL & 0x2) == 0);
        /* Clear Audio PON Ready interrupt */
        CODEC_ANA->AUDIO_INT_CONTROL |= BIT1;
    }
    else  // DMIC
    {
        AUDIO_PON_POF_TypeDef  codec_0x020 =  {.d32 = CODEC_ANA->AUDIO_PON_POF};
        codec_0x020.b.audio_pof_en = 0x1;
        CODEC_ANA->AUDIO_PON_POF =  codec_0x020.d32;
        /* Polling audio pof ready init*/
        while ((CODEC_ANA->AUDIO_INT_CONTROL & 0x2) == 0);
        /* Clear Audio PON Ready interrupt */
        CODEC_ANA->AUDIO_INT_CONTROL |= BIT1;
    }

}

/**
  * \brief  Deinitializes the CODEC peripheral registers to their default reset values(turn off CODEC clock).
  * \param  CODECx: selected CODEC peripheral.
  * \return None
  */
void CODEC_DeInit(CODEC_TypeDef *CODECx)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    CODEC_POF();
    RCC_ClockCmd(CODEC_CLOCK, DISABLE);


}

/**
  * \brief Initializes the CODEC peripheral according to the specified
  *   parameters in the CODEC_InitStruct
  * \param  CODECx: selected CODEC peripheral.
  * \param  CODEC_InitStruct: pointer to a CODEC_InitTypeDef structure that
  *   contains the configuration information for the specified CODEC peripheral
  * \return None
  */
void CODEC_Init(CODEC_TypeDef *CODECx, CODEC_InitTypeDef *CODEC_InitStruct)
{
    /* Check the parameters */
    /* MIC initialization parameters for input */
    assert_param(IS_CODEC_PERIPH(CODECx));
    assert_param(IS_SAMPLE_RATE(CODEC_InitStruct->CODEC_SampleRate));
    assert_param(IS_CODEC_I2S_DATA_FORMAT(CODEC_InitStruct->CODEC_I2SDataFormat));
    assert_param(IS_CODEC_I2S_DATA_WIDTH(CODEC_InitStruct->CODEC_I2SDataWidth));
    assert_param(IS_MICBIAS_CONFIG(CODEC_InitStruct->CODEC_MicBIAS));
    assert_param(IS_MICBST_MODE(CODEC_InitStruct->CODEC_MicBstMode));
    assert_param(IS_MICBST_GAIN(CODEC_InitStruct->CODEC_MicBstGain));
    assert_param(IS_CODEC_DMIC_CLOCK(CODEC_InitStruct->CODEC_DmicClock));
    /* MIC channel 0 initialization parameters */
    assert_param(IS_CODEC_CH0_MIC_MUTE(CODEC_InitStruct->CODEC_Ch0Mute));
    assert_param(IS_CODEC_CH0_MIC_TYPE(CODEC_InitStruct->CODEC_Ch0MicType));
    assert_param(IS_DMIC_CH0_LATCH_EDGE(CODEC_InitStruct->CODEC_Ch0DmicDataLatch));
    assert_param(IS_AD_GAIN(CODEC_InitStruct->CODEC_Ch0AdGain));
    /* MIC channel 1 initialization parameters */
    assert_param(IS_CODEC_CH1_MIC_MUTE(CODEC_InitStruct->CODEC_Ch1Mute));
    assert_param(IS_CODEC_CH1_MIC_TYPE(CODEC_InitStruct->CODEC_Ch1MicType));
    assert_param(IS_DMIC_CH1_LATCH_EDGE(CODEC_InitStruct->CODEC_Ch1DmicDataLatch));
    assert_param(IS_AD_GAIN(CODEC_InitStruct->CODEC_Ch1AdGain));
    /* PDM initialization parameters */
    assert_param(IS_DAC_MUTE(CODEC_InitStruct->CODEC_DaMute));
    assert_param(IS_DA_GAIN(CODEC_InitStruct->CODEC_DaGain));
    extern uint8_t (*pmu_get_va18_tune)(void);

    /*get LDO318 form pmu */
    REG8X_CODEC_ANA_TypeDef codec_0x010 = {.d32 = CODEC_ANA->REG8X_CODEC_ANA};
    codec_0x010.b.ldo318_aud_tune = pmu_get_va18_tune();
    CODEC_ANA->REG8X_CODEC_ANA = codec_0x010.d32;
    
    ADC_0_CONTROL_0_TypeDef codec_0x120 = {.d32 = CODEC->ADC_0_CONTROL_0};
    codec_0x120.b.adc_0_admic_sel = CODEC_InitStruct->CODEC_Ch0Mic;
    CODEC->ADC_0_CONTROL_0 =  codec_0x120.d32;

    AUDIO_PON_POF_TypeDef  codec_0x020 =  {.d32 = CODEC_ANA->AUDIO_PON_POF}; 
    
    codec_0x020.b.pon_st1_delay_sel = 0x2;
    codec_0x020.b.pon_st2_delay_sel = 0x0;
    codec_0x020.b.pon_st3_delay_sel = 0x2;
    
    CODEC_ANA->AUDIO_PON_POF =  codec_0x020.d32;
    
    /*Analog performance dependency*/
    REG6X_CODEC_ANA_TypeDef codec_0x006 = {.d32 = CODEC_ANA->REG6X_CODEC_ANA};


    /* Analog initialization */
    if (((CODEC_InitStruct->CODEC_Ch0Mute == CODEC_CH_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch0Mic == CODEC_CH_AMIC)))
    {
        codec_0x006.b.isel_micbias = 0x2;
        codec_0x006.b.isel_dtsdm = 0x2;
        codec_0x006.b.isel_micbst = 0x2;
        CODEC_ANA->REG6X_CODEC_ANA = codec_0x006.d32;

        codec_0x010.b.ldo318_aud_bw_sel = 0x1;
        CODEC_ANA->REG8X_CODEC_ANA = codec_0x010.d32;

        AUDIO_CLOCK_CONTROL_3_TypeDef codec_0x110 = {.d32 = CODEC->AUDIO_CLOCK_CONTROL_3};
        codec_0x110.b.ana_clk_rate_sel = 0x1;
        CODEC->AUDIO_CLOCK_CONTROL_3 = codec_0x110.d32;

        REG2X_CODEC_ANA_TypeDef codec_0x004 = {.d32 = CODEC_ANA->REG2X_CODEC_ANA};
        codec_0x004.b.micbst_gsel = CODEC_InitStruct->CODEC_MicBstGain;
        codec_0x004.b.micbst_endf = CODEC_InitStruct->CODEC_MicBstMode;
        CODEC_ANA->REG2X_CODEC_ANA = codec_0x004.d32;


    }

    REG4X_CODEC_ANA_TypeDef codec_0x008 = {.d32 = CODEC_ANA->REG4X_CODEC_ANA};
    codec_0x008.b.micbias_vset = CODEC_InitStruct->CODEC_MicBiasVolt;
    CODEC_ANA->REG4X_CODEC_ANA = codec_0x008.d32;

    AUDIO_CLOCK_CONTROL_2_TypeDef codec_0x10C = {.d32 = CODEC->AUDIO_CLOCK_CONTROL_2};
    /* DMIC clock configuration */
    if (((CODEC_InitStruct->CODEC_Ch0Mute == CODEC_CH_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch0Mic == CODEC_CH_DMIC)))
    {
        codec_0x006.b.isel_micbias = 0x3;
        CODEC_ANA->REG6X_CODEC_ANA = codec_0x006.d32;
        codec_0x10C.b.dmic1_clk_sel = CODEC_InitStruct->CODEC_DmicClock;
    }
    CODEC->AUDIO_CLOCK_CONTROL_2 =  codec_0x10C.d32;

    /* Configuer mic channel 0 parameters */

    codec_0x120.b.adc_0_ad_mute = CODEC_InitStruct->CODEC_Ch0Mute;

    codec_0x120.b.adc_0_dmic_src_sel = CODEC_InitStruct->CODEC_Ch0DmicDataLatch;
    codec_0x120.b.adc_0_dchpf_fc_sel = 0x2;  /*3'b000: high corner freq. ~ 3'b111: low corner freq.*/
    CODEC->ADC_0_CONTROL_0 =  codec_0x120.d32;

    /* Sample rate section */
    AUDIO_CLOCK_CONTROL_3_TypeDef codec_0x110 = {.d32 = CODEC->AUDIO_CLOCK_CONTROL_3};
    codec_0x110.b.sample_rate_0 = CODEC_InitStruct->CODEC_SampleRate;
    CODEC->AUDIO_CLOCK_CONTROL_3 = codec_0x110.d32;

    I2S_0_CONTROL_0_TypeDef codec_0x11C = {.d32 = CODEC->I2S_0_CONTROL_0};
    codec_0x11C.b.i2s_0_data_len_sel_rx = CODEC_InitStruct->CODEC_I2SDataWidth;
    codec_0x11C.b.i2s_0_data_format_sel_rx = CODEC_InitStruct->CODEC_I2SDataFormat;
    codec_0x11C.b.i2s_0_data_ch_sel_rx = CODEC_InitStruct->CODEC_I2SChSequence;
    CODEC->I2S_0_CONTROL_0 = codec_0x11C.d32;

    ADC_0_CONTROL_1_TypeDef codec_0x124 = {.d32 = CODEC->ADC_0_CONTROL_1};
    codec_0x124.b.adc_0_ad_gain = CODEC_InitStruct->CODEC_Ch0AdGain;
    CODEC->ADC_0_CONTROL_1 = codec_0x124.d32;


    codec_0x020.b.audio_pon_en = 0x1;
    CODEC_ANA->AUDIO_PON_POF =  codec_0x020.d32;

    /* Polling audio pon ready init*/
    while ((CODEC_ANA->AUDIO_INT_CONTROL & 0x1) == 0);
    /* Clear Audio PON Ready interrupt */
    CODEC_ANA->AUDIO_INT_CONTROL |= BIT0;


}

/**
  * \brief Initializes the CODEC EQ module according to the specified
  *   parameters in the CODEC_EQInitStruct
  * \param  CODEC_EQx: the selected CODEC EQ channel.
  *   which can be CODEC_CH0_EQ1~CODEC_CH0_EQ5, or CODEC_CH1_EQ1~CODEC_CH1_EQ5.
  * \param  CODEC_EQInitStruct: pointer to a CODEC_EQInitTypeDef structure that
  *   contains the configuration information for the specified CODEC EQ channel
  * \return None
  */
void CODEC_EQInit(CODEC_EQTypeDef *CODEC_EQx, CODEC_EQInitTypeDef *CODEC_EQInitStruct)
{
    uint32_t bit_pos = 0;

    CODEC_EQx->EQ_H0 = CODEC_EQInitStruct->CODEC_EQCoefH0;
    CODEC_EQx->EQ_B1 = CODEC_EQInitStruct->CODEC_EQCoefB1;
    CODEC_EQx->EQ_B2 = CODEC_EQInitStruct->CODEC_EQCoefB2;
    CODEC_EQx->EQ_A1 = CODEC_EQInitStruct->CODEC_EQCoefA1;
    CODEC_EQx->EQ_A2 = CODEC_EQInitStruct->CODEC_EQCoefA2;

    if ((((uint32_t)CODEC_EQx) >= CODEC_ADC_CH0_CR_REG_BASE) &&
        (((uint32_t)CODEC_EQx) <= CODEC_ADC_CH0_EQ4_REG_BASE))
    {
        bit_pos = ((uint32_t)CODEC_EQx -  CODEC_ADC_CH0_EQ0_REG_BASE) / 20;
        if (CODEC_EQInitStruct->CODEC_EQChCmd != DISABLE)
        {
            CODEC_ADC_CH0_CR |= ENABLE << bit_pos;
        }
        else
        {
            CODEC_ADC_CH0_CR &= ~(ENABLE << bit_pos);
        }
    }
}

/**
  * \brief  Fills each CODEC_InitStruct member with its default value.
  * \param  CODEC_InitStruct: pointer to an CODEC_InitTypeDef structure which will be initialized.
  * \return None
  */
void CODEC_StructInit(CODEC_InitTypeDef *CODEC_InitStruct)
{
    /* Basic parameters section */
    CODEC_InitStruct->CODEC_SampleRate    = CODEC_SAMPLE_RATE_16KHz;
    CODEC_InitStruct->CODEC_DmicClock     = CODEC_DMIC_CLOCK_2500KHz;

    CODEC_InitStruct->CODEC_I2SChSequence = CODEC_I2S_CH_SEQ_L_R;
    CODEC_InitStruct->CODEC_I2SDataWidth  = CODEC_I2S_DATA_WIDTH_16BITS;
    CODEC_InitStruct->CODEC_I2SDataFormat = CODEC_I2S_DATA_FORMAT_I2S;

    CODEC_InitStruct->CODEC_MicBiasVolt   = CODEC_MICBIAS_VOLTAGE_1_8;
    CODEC_InitStruct->CODEC_MicBstMode    = CODEC_MICBST_MODE_DIFFERENTIAL;
    CODEC_InitStruct->CODEC_MicBstGain    = CODEC_MICBST_GAIN_0dB;

    /* MIC channel 0 initialization parameters section */
    CODEC_InitStruct->CODEC_Ch0Mute          = CODEC_CH_UNMUTE;
    CODEC_InitStruct->CODEC_Ch0Mic           = CODEC_CH_AMIC;
    CODEC_InitStruct->CODEC_Ch0DmicDataLatch = CODEC_CH_DMIC_DATA_LATCH_RISING;
    CODEC_InitStruct->CODEC_Ch0AdGain        = 0x7F;
    CODEC_InitStruct->CODEC_Ch0DetTimeout    = CODEC_CH_DETTIMEOUT_1024_16_SAMPLE;
}


/**
  * \brief  Fills each CODEC_EQInitStruct member with its default value.
  * \param  CODEC_EQInitStruct: pointer to an CODEC_EQInitTypeDef structure which will be initialized.
  * \return None
  */
void CODEC_EQStructInit(CODEC_EQInitTypeDef *CODEC_EQInitStruct)
{
    CODEC_EQInitStruct->CODEC_EQChCmd   = DISABLE;
    /*!< The following all parameters can be 0 to 0x7FFFF, whose physical meaning represents a range of -8 to 7.99 */
    CODEC_EQInitStruct->CODEC_EQCoefH0  = 0;
    CODEC_EQInitStruct->CODEC_EQCoefB1  = 0;
    CODEC_EQInitStruct->CODEC_EQCoefB2  = 0;
    CODEC_EQInitStruct->CODEC_EQCoefA1  = 0;
    CODEC_EQInitStruct->CODEC_EQCoefA2  = 0;
}

/**
  * \brief  Enable or disable the specified CODEC interrupts.
  * \param  CODEC: selected CODEC peripheral.
  * \param  CODEC_INT: specifies the CODEC interrupts sources to be enable or disable.
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \param  NewState: new state of the specified CODEC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void CODEC_INTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CODEC_INT_CONFIG(CODEC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        CODEC_ANA->AUDIO_INT_CONTROL |= CODEC_INT << 8;
    }
    else
    {
        CODEC_ANA->AUDIO_INT_CONTROL &= ~(CODEC_INT << 8);
    }
}

/**
  * \brief  Mask the specified CODEC interrupt
  * \param  CODEC: selected CODEC peripheral.
  * \param  CODEC_INT: specifies the CODEC interrupts sources to be enable or disable.
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \param  NewState: new state of the specified CODEC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void CODEC_MaskINTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CODEC_INT_CONFIG(CODEC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        CODEC_ANA->AUDIO_INT_CONTROL |= CODEC_INT << 16;
    }
    else
    {
        CODEC_ANA->AUDIO_INT_CONTROL &= ~(CODEC_INT << 16);
    }
}

/**
  * \brief  Get the specified CODEC flag status.
  * \param  CODEC: selected CODEC peripheral.
  * \param  CODEC_INT: the specified CODEC interrupt.
  *         This parameter can be one of the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \return The new state of FLAG (SET or RESET).
  */
ITStatus CODEC_GetINTStatus(CODEC_TypeDef *CODECx, uint32_t CODEC_INT)
{
    ITStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_CODEC_INT_CONFIG(CODEC_INT));

    if ((CODEC_ANA->AUDIO_INT_CONTROL & (CODEC_INT & 0x3)))
    {
        bit_status = SET;
    }

    /* Return the I2S_INT status */
    return  bit_status;
}

/**
  * \brief  Clears the CODEC interrupt pending bits.
  * \param  CODEC: selected CODEC peripheral.
  * \param  CODEC_CLEAR_INT: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \return None
  */
void CODEC_ClearINTPendingBit(CODEC_TypeDef *CODECx, uint32_t CODEC_CLEAR_INT)
{
    /* Check the parameters */
    assert_param(IS_I2S_INT_CONFIG(I2S_CLEAR_INT));
    CODEC_ANA->AUDIO_INT_CONTROL |= CODEC_CLEAR_INT;
}
/**
  * \brief  Enable or disable mic_bias output.
  * \param  CODECx: selected CODEC peripheral.
  * \param  NewState: new state of MICBIAS.
  *   This parameter can be: ENABLE or DISABLE.
  * \return none.
  */
void CODEC_MicBiasCmd(CODEC_TypeDef *CODECx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    REG4X_CODEC_ANA_TypeDef codec_0x008 = {.d32 = CODEC_ANA->REG4X_CODEC_ANA};
    AUDIO_ANA_CONTROL_1_TypeDef codec_0x104 = {.d32 = CODEC->AUDIO_ANA_CONTROL_1};
    if (NewState == ENABLE)
    {
        if (!(codec_0x008.b.micbias_pow))
        {
            /* Analog initialization in AON register */
            CODEC_AnalogCircuitInit();

            /* MICBIAS power on */
            codec_0x008.b.micbias_pow = 0x1;
            codec_0x008.b.micbias_enchx = 0x1;

            /* Clock enable */
            codec_0x104.b.ckx_micbias_en = 0x1;
        }
    }
    else
    {
        codec_0x008.b.micbias_pow = 0x0;
        codec_0x008.b.micbias_enchx = 0x0;
    }
    CODEC_ANA->REG4X_CODEC_ANA = codec_0x008.d32;
    CODEC->AUDIO_ANA_CONTROL_1 = codec_0x104.d32;
}

void CODEC_Reset(CODEC_TypeDef *CODECx)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));

    /* CODEC IP reset */
    AUDIO_CONTROL_1_TypeDef codec_0x100 = {.d32 = CODEC->AUDIO_CONTROL_1};
    codec_0x100.b.audio_ip_en = 0;
    CODEC->AUDIO_CONTROL_1 = codec_0x100.d32;
    codec_0x100.b.audio_ip_en = 1;
    CODEC->AUDIO_CONTROL_1 = codec_0x100.d32;
}

void CODEC_SetMicBias(CODEC_TypeDef *CODECx, uint16_t Data)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    assert_param(IS_MICBIAS_CONFIG(data));

    REG4X_CODEC_ANA_TypeDef codec_0x008 = {.d32 = CODEC_ANA->REG4X_CODEC_ANA};
    codec_0x008.b.micbias_vset = Data;
    CODEC_ANA->REG4X_CODEC_ANA = codec_0x008.d32;
}

