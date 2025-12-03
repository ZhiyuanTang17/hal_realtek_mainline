/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_codec.c
* \brief    This file provides all the CODEC firmware functions.
* \details
* \author   echo gao
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_codec.h"
#include "rtl_rcc.h"
#include "utils.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define AUXADC_AON_REG0X1B90              ((AON_NS_REG0X_LDO_TYPE *)0x40001B90UL)
#define LPC_AON_AUXADC                      ((AON_NS_REG0X_SD_TYPE *)0x40001B98UL)
#define PERI_ON_ADC_CLOCK_CTRL               *((volatile uint32_t *)0x4000231CUL)

extern void force_vddcore_1v2_for_auxadc(bool enable);
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
    force_vddcore_1v2_for_auxadc(true);
    AUXADC_AON_REG0X1B90->hw_pd = 0x0;
    AUXADC_AON_REG0X1B90->anapar_pow_ad_0 = 0x1;
    platform_delay_us(10);
    AUXADC_AON_REG0X1B90->EN_ILIMIT = 0x1;
    AUXADC_AON_REG0X1B90->LDOBW  = 0x0;
    AUXADC_AON_REG0X1B90->Power = 0x0;
    AUXADC_AON_REG0X1B90->anapar_pow_ad_2 = 0x1;
    AUXADC_AON_REG0X1B90->REG_LDO_TUNE_6_0 = 0x57; //  7'b1010111
    AUXADC_AON_REG0X1B90->SELLDO = 0x1;
    platform_delay_us(10);
    AUXADC_AON_REG0X1B90->anapar_pow_ad_1 = 0x1;

    if (AUXADC_AON_REG0X1B90->EN_ILIMIT == 0x0)
    {
        platform_delay_us(20);
    }
    else
    {
        platform_delay_us(15);
        AUXADC_AON_REG0X1B90->EN_ILIMIT = 0x0;
    }
    platform_delay_us(2);

}

/**
  * \brief  Deinitialize the CODEC analog registers in AON area.
  * \param  None.
  * \return None
  */
static void CODEC_AnalogCircuitDeInit(void)
{
    uint32_t adc_clk_en = (PERI_ON_ADC_CLOCK_CTRL & BIT1) >> 1;
    if (LPC_AON_AUXADC->POW_SD_H != 1 && adc_clk_en != 1)
    {
        AUXADC_AON_REG0X1B90->anapar_pow_ad_2 = 0x0;
        AUXADC_AON_REG0X1B90->anapar_pow_ad_0 = 0x0;
        AUXADC_AON_REG0X1B90->anapar_pow_ad_1 = 0x0;
        AUXADC_AON_REG0X1B90->hw_pd  = 0x1;
    }
    force_vddcore_1v2_for_auxadc(false);

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

    RCC_PeriphClockCmd(APBPeriph_CODEC, APBPeriph_CODEC_CLOCK, DISABLE);

    CODEC_AnalogCircuitDeInit();
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
    assert_param(IS_CODEC_I2S_DATA_FORMAT(CODEC_InitStruct->CODEC_I2SFormat));
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

    CODEC_ANA_00_BUS_t codec_0x000 = {.d32 = CODEC_ANA->CODEC_ANA_00_BUS};
    CODEC_ANA_01_BUS_t codec_0x004 = {.d32 = CODEC_ANA->CODEC_ANA_01_BUS};
    CODEC_ANA_02_BUS_t codec_0x008 = {.d32 = CODEC_ANA->CODEC_ANA_02_BUS};
    CODEC_ANA_03_BUS_t codec_0x00C = {.d32 = CODEC_ANA->CODEC_ANA_03_BUS};

    AUDIO_CONTROL_0_t codec_0x100 = {.d32 = CODEC->AUDIO_CONTROL_0};
    AUDIO_CONTROL_1_t codec_0x104 = {.d32 = CODEC->AUDIO_CONTROL_1};
    CLOCK_CONTROL_1_t codec_0x108 = {.d32 = CODEC->CLOCK_CONTROL_1};
    CLOCK_CONTROL_3_t codec_0x110 = {.d32 = CODEC->CLOCK_CONTROL_3};
    CLOCK_CONTROL_4_t codec_0x114 = {.d32 = CODEC->CLOCK_CONTROL_4};
    CLOCK_CONTROL_7_t codec_0x118 = {.d32 = CODEC->CLOCK_CONTROL_7};
    CLOCK_CONTROL_5_t codec_0x11C = {.d32 = CODEC->CLOCK_CONTROL_5};

    I2S_0_CONTROL_t codec_0x148 = {.d32 = CODEC->I2S_0_CONTROL};

    ADC_0_CONTROL_0_t codec_0x164 = {.d32 = CODEC->ADC_0_CONTROL_0};
    ADC_0_CONTROL_1_t codec_0x168 = {.d32 = CODEC->ADC_0_CONTROL_1};
    ADC_1_CONTROL_0_t codec_0x16C = {.d32 = CODEC->ADC_1_CONTROL_0};
    ADC_1_CONTROL_1_t codec_0x170 = {.d32 = CODEC->ADC_1_CONTROL_1};

    DAC_L_CONTROL_0_t codec_0x194 = {.d32 = CODEC->DAC_L_CONTROL_0};
    DAC_L_CONTROL_1_t codec_0x198 = {.d32 = CODEC->DAC_L_CONTROL_1};

    /* Enable audio IP*/
    codec_0x100.b.audio_ip_en = ENABLE;

    /* Clock configuration */
    codec_0x108.b.ad_ana_clk_en      = ENABLE;
    codec_0x108.b.ad_fifo_en      = ENABLE;

    if (CODEC_InitStruct->CODEC_Ch0Mute == CODEC_UNMUTE)
    {
        codec_0x108.b.ad_0_en           = ENABLE;
        codec_0x108.b.ad_ana_0_en       = ENABLE;

    }
    if (CODEC_InitStruct->CODEC_Ch1Mute == CODEC_UNMUTE)
    {
        codec_0x108.b.ad_1_en           = ENABLE;
        codec_0x108.b.ad_ana_1_en       = ENABLE;
    }
    if (CODEC_InitStruct->CODEC_DaMute != CODEC_MUTE)
    {
        codec_0x108.b.da_ana_clk_en = ENABLE;
        codec_0x108.b.da_fifo_en = ENABLE;  //dac fifo clock control
        codec_0x108.b.da_l_en = ENABLE;
        codec_0x108.b.mod_l_en = ENABLE;
        codec_0x118.b.dac_fs_src_sel  = CODEC_InitStruct->CODEC_DaSampleRateSrc;
        /* enable DAC power*/
        codec_0x00C.b.CODEC_DAC_POW = 0x1;
        codec_0x00C.b.CODEC_DAC_CK_POW = 0x1;

    }
    codec_0x11C.b.ad_asrc_en = 1;
    codec_0x11C.b.da_asrc_en = 1;

    /* DMIC clock configuration */
    if (((CODEC_InitStruct->CODEC_Ch0Mute   == CODEC_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch0MicType == CODEC_CH_DMIC))  || \
        ((CODEC_InitStruct->CODEC_Ch1Mute   == CODEC_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch1MicType == CODEC_CH_DMIC)))
    {

        codec_0x110.b.dmic1_clk_en = 0x1;
        codec_0x110.b.dmic1_clk_sel = CODEC_InitStruct->CODEC_DmicClock;
        codec_0x110.b.dmic1_src_clk_sel = 0x0; //digital MIC 1 clock soruce selection 1: 8MHz 0:10MHz
        codec_0x118.b.adc_fs_src_sel  = CODEC_InitStruct->CODEC_AdSampleRateSrc;
    }
    /* Sample rate section */
    codec_0x114.b.sample_rate_0        = CODEC_InitStruct->CODEC_SampleRate0;
    codec_0x114.b.sample_rate_1        = CODEC_InitStruct->CODEC_SampleRate1;

    /* MICBIAS Setting On*/
    codec_0x004.b.MICBIAS_ENCHX = 0x1;
    codec_0x004.b.MICBIAS_VSET = CODEC_InitStruct->CODEC_MicBIAS;
    codec_0x104.b.ckx_micbias_en = 0x1;
    codec_0x004.b.MICBIAS_POW = 0x1;

    codec_0x008.b.MICBIAS_ILIMIT = 0x0;
    codec_0x008.b.MICBIAS_POWSHDT = 0x0;
    codec_0x008.b.MICBIAS_OCSEL = 0x1;
    codec_0x008.b.MICBIAS_COUNT = 0x1;
    codec_0x004.b.VREF_POW = 0x1;
    /* Analog initialization */
    if (((CODEC_InitStruct->CODEC_Ch0Mute   == CODEC_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch0MicType == CODEC_CH_AMIC))  || \
        ((CODEC_InitStruct->CODEC_Ch1Mute   == CODEC_UNMUTE) && \
         (CODEC_InitStruct->CODEC_Ch1MicType == CODEC_CH_AMIC)) || \
        (CODEC_InitStruct->CODEC_DaMute   == CODEC_UNMUTE))
    {
        /* Analog initialization in AON register */
        CODEC_AnalogCircuitInit();

        /* Enable AD/DA clock and ADC analog power */
        codec_0x000.b.DAC_ADDACK_POW = 0x1;
        codec_0x000.b.DTSDM_CKXEN = 0x1;
        codec_0x000.b.DTSDM_POW_L = 0x1;

        codec_0x004.b.MICBST_GSELL = CODEC_InitStruct->CODEC_MicBstGain;
        codec_0x004.b.MICBST_ENDFL = CODEC_InitStruct->CODEC_MicBstMode;
        codec_0x004.b.VREF_VREFSEL = 0x2;
        codec_0x004.b.MICBST_POW = 0x1;
        codec_0x004.b.MICBST_MUTE_L = 0x2;


        /* Clock enable */

        codec_0x118.b.adc_fs_src_sel  = CODEC_InitStruct->CODEC_AdSampleRateSrc;
        codec_0x118.b.dac_fs_src_sel  = CODEC_InitStruct->CODEC_DaSampleRateSrc;

    }
    /*default config*/
    codec_0x104.b.sel_bb_ck_depop =
        0x01; // 2'b00:40MHz/1024  2'b01:40MHz/2048 2'b10:40MHz/4096 2'b11:40MHz/8192
    codec_0x104.b.pdm_ch_swap =
        0x2;  // PDM DATA channel SWAP 2'b00: L/L 2'b01: L/R 2'b10: R/L 2'b11: R/R
    codec_0x104.b.pdm_data_phase_sel = 0x1;  //add delay in PDM DATA
    codec_0x104.b.pdm_gain_shift_en = 0x1;  //1: backoff 6 dB to prevent overloading for PDM
    codec_0x104.b.i2s_data_rnd_en = 0x1;  //i2s data with rounding

    /* Configure I2S parameters */
    codec_0x148.b.i2s_0_rst_n = 1;
    codec_0x148.b.i2s_0_inv_sclk = 0;
    codec_0x148.b.i2s_0_self_lpbk_en = 0;
    codec_0x148.b.i2s_0_same_lrc_en = CODEC_InitStruct->CODEC_I2SSameLrcEn;
    codec_0x148.b.i2s_0_data_format_sel_tx = CODEC_InitStruct->CODEC_I2SFormat;
    codec_0x148.b.i2s_0_data_format_sel_rx = CODEC_InitStruct->CODEC_I2SFormat;
    codec_0x148.b.i2s_0_data_len_sel_tx = CODEC_InitStruct->CODEC_I2STxDataWidth;
    codec_0x148.b.i2s_0_data_len_sel_rx = CODEC_InitStruct->CODEC_I2SRxDataWidth;
    codec_0x148.b.i2s_0_ch_len_sel_tx = CODEC_InitStruct->CODEC_I2SChannelLen;
    codec_0x148.b.i2s_0_ch_len_sel_rx = CODEC_InitStruct->CODEC_I2SChannelLen;
    codec_0x148.b.i2s_0_data_ch_sel_tx = CODEC_InitStruct->CODEC_I2SChSequence;
    codec_0x148.b.i2s_0_data_ch_sel_rx = CODEC_InitStruct->CODEC_I2SChSequence;

    /* Configuer mic channel 0 parameters */
    codec_0x164.b.adc_0_admic_sel = CODEC_InitStruct->CODEC_Ch0MicType;
    codec_0x164.b.adc_0_dmic_src_sel = CODEC_InitStruct->CODEC_Ch0DmicDataLatch;
    codec_0x164.b.adc_0_ad_src_sel = 0x0;
    codec_0x164.b.adc_0_ad_mute = CODEC_InitStruct->CODEC_Ch0Mute;
    codec_0x164.b.adc_0_dchpf_en = DISABLE;
    codec_0x164.b.adc_0_dchpf_fc_sel = 0x4;  /*3'b000: high corner freq. ~ 3'b111: low corner freq.*/
    codec_0x164.b.adc_0_ad_lpf1st_en = 0x1;
    codec_0x164.b.adc_0_ad_lpf2nd_en = 0x1;
    codec_0x164.b.adc_0_ad_zdet_func = 0X2;
    codec_0x164.b.adc_0_ad_zdet_tout = CODEC_InitStruct->CODEC_Ch0ZeroDetTimeout;

    codec_0x168.b.adc_0_ad_gain = CODEC_InitStruct->CODEC_Ch0AdGain;
    codec_0x168.b.adc_0_depop_en = 0x0;

    /* Configuer mic channel 1 parameters */
    codec_0x16C.b.adc_1_admic_sel = CODEC_InitStruct->CODEC_Ch1MicType;
    codec_0x16C.b.adc_1_dmic_src_sel = CODEC_InitStruct->CODEC_Ch1DmicDataLatch;
    codec_0x16C.b.adc_1_ad_src_sel = 0x0;
    codec_0x16C.b.adc_1_ad_mute = CODEC_InitStruct->CODEC_Ch1Mute;
    codec_0x16C.b.adc_1_dchpf_en = 0x0;;
    codec_0x16C.b.adc_1_dchpf_fc_sel = 0x4;  /*3'b000: high corner freq. ~ 3'b111: low corner freq.*/
    codec_0x16C.b.adc_1_ad_lpf1st_en = 0x1;
    codec_0x16C.b.adc_1_ad_lpf2nd_en = 0x1;
    codec_0x16C.b.adc_1_ad_zdet_func =
        0x2; //Channel 1 ADC path zero detection function select 2'b00 : immediate change 2'b01 : zero detection & immediate change 2'b10:zdet & step 2'b11: zdet&timeout step
    codec_0x16C.b.adc_1_ad_zdet_tout = CODEC_InitStruct->CODEC_Ch1ZeroDetTimeout;

    codec_0x170.b.adc_1_ad_gain = CODEC_InitStruct->CODEC_Ch1AdGain;
    codec_0x170.b.adc_1_depop_en = 0x0;

    /* Configure PDM parametes */
    codec_0x194.b.dac_l_da_gain = CODEC_InitStruct->CODEC_DaGain;   // da dvol gain
    codec_0x198.b.dac_l_da_mute = (CODEC_InitStruct->CODEC_DaGain == 0x00);// -65.625 dB
    codec_0x198.b.dac_l_da_dither_sel = DAC_DA_DITHER_LSB;
    codec_0x198.b.dac_l_dmix_mute_da = DISABLE;
    codec_0x198.b.dac_l_dmix_mute_dc = ENABLE;
    codec_0x198.b.dac_l_pdm_en = 1;

    codec_0x198.b.dac_l_sdm_dither_sel = DAC_DA_DITHER_DISABLE;
    codec_0x198.b.dac_l_da_zdet_func =
        0x2; //Channel L DAC path zero detection function select 2'b00 : immediate change 2'b01 : zero detection & immediate
    codec_0x198.b.dac_l_hpf_fc_sel = 0x0;

    CODEC_ANA->CODEC_ANA_00_BUS = codec_0x000.d32;
    CODEC_ANA->CODEC_ANA_01_BUS = codec_0x004.d32;
    CODEC_ANA->CODEC_ANA_02_BUS = codec_0x008.d32;
    CODEC_ANA->CODEC_ANA_03_BUS = codec_0x00C.d32;

    CODEC->AUDIO_CONTROL_0 = codec_0x100.d32;

    CODEC->AUDIO_CONTROL_1 = codec_0x104.d32;
    CODEC->CLOCK_CONTROL_1 = codec_0x108.d32;
    CODEC->CLOCK_CONTROL_3 = codec_0x110.d32;
    CODEC->CLOCK_CONTROL_4 = codec_0x114.d32;
    CODEC->CLOCK_CONTROL_7 = codec_0x118.d32;
    CODEC->CLOCK_CONTROL_5 = codec_0x11C.d32;
    CODEC->I2S_0_CONTROL =  codec_0x148.d32;

    CODEC->ADC_0_CONTROL_0 = codec_0x164.d32;
    CODEC->ADC_0_CONTROL_1 = codec_0x168.d32;
    CODEC->ADC_1_CONTROL_0 = codec_0x16C.d32;
    CODEC->ADC_1_CONTROL_1 = codec_0x170.d32;

    CODEC->DAC_L_CONTROL_0 = codec_0x194.d32;
    CODEC->DAC_L_CONTROL_1 = codec_0x198.d32;
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

    if (((uint32_t)CODEC_EQx) <= CODEC_DAC_L_EQ9_REG_BASE)
    {
        bit_pos = ((uint32_t)CODEC_EQx -  CODEC_DAC_L_EQ0_REG_BASE) / 20;
        if (CODEC_EQInitStruct->CODEC_EQChCmd != DISABLE)
        {
            CODEC_DAC_L_CR |= ENABLE << bit_pos;
        }
        else
        {
            CODEC_DAC_L_CR &= ~(ENABLE << bit_pos);
        }
    }
    else if ((((uint32_t)CODEC_EQx) >= CODEC_ADC_CH0_CR_REG_BASE) &&
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
    else if ((((uint32_t)CODEC_EQx) >= CODEC_ADC_CH1_EQ0_REG_BASE) &&
             (((uint32_t)CODEC_EQx) <= CODEC_ADC_CH1_EQ4_REG_BASE))
    {
        bit_pos = ((uint32_t)CODEC_EQx -  CODEC_ADC_CH1_EQ0_REG_BASE) / 20;
        if (CODEC_EQInitStruct->CODEC_EQChCmd != DISABLE)
        {
            CODEC_ADC_CH1_CR |= ENABLE << bit_pos;
        }
        else
        {
            CODEC_ADC_CH1_CR &= ~(ENABLE << bit_pos);
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
    CODEC_InitStruct->CODEC_AdSampleRateSrc = SAMPLE_RATE_SRC0;
    CODEC_InitStruct->CODEC_DaSampleRateSrc = SAMPLE_RATE_SRC0;
    CODEC_InitStruct->CODEC_SampleRate0 = SAMPLE_RATE_16KHz;
    CODEC_InitStruct->CODEC_SampleRate1 = SAMPLE_RATE_16KHz;

    CODEC_InitStruct->CODEC_I2SChSequence = CODEC_I2S_CH_L_R;
    CODEC_InitStruct->CODEC_I2STxDataWidth = CODEC_I2S_Tx_DataWidth_16Bits;
    CODEC_InitStruct->CODEC_I2SRxDataWidth = CODEC_I2S_Rx_DataWidth_16Bits;
    CODEC_InitStruct->CODEC_I2SChannelLen = I2S_CHANNELLEN_32;
    CODEC_InitStruct->CODEC_I2SFormat = CODEC_I2S_DataFormat_I2S;
    CODEC_InitStruct->CODEC_I2SSameLrcEn = DISABLE;

    CODEC_InitStruct->CODEC_MicBIAS = MICBIAS_VOLTAGE_1_8;
    CODEC_InitStruct->CODEC_MicBstMode = MICBST_Mode_Single;
    CODEC_InitStruct->CODEC_MicBstGain = MICBST_Gain_20dB;
    CODEC_InitStruct->CODEC_DmicClock = DMIC_Clock_2500KHz;
    /* MIC channel 0 initialization parameters section */
    CODEC_InitStruct->CODEC_Ch0Mute = CODEC_UNMUTE;
    CODEC_InitStruct->CODEC_Ch0MicType = CODEC_CH_AMIC;
    CODEC_InitStruct->CODEC_Ch0DmicDataLatch = DMIC_Ch_Rising_Latch;
    CODEC_InitStruct->CODEC_Ch0AdGain = 0x2F;
    CODEC_InitStruct->CODEC_Ch0ZeroDetTimeout = Ch_ADC_Zero_DetTimeout_1024_16_Sample;
    /* MIC channel 1 initialization parameters section */
    CODEC_InitStruct->CODEC_Ch1Mute = CODEC_MUTE;
    CODEC_InitStruct->CODEC_Ch1MicType = CODEC_CH_DMIC;
    CODEC_InitStruct->CODEC_Ch1DmicDataLatch = DMIC_Ch_Falling_Latch;
    CODEC_InitStruct->CODEC_Ch1AdGain  = 0x2F;
    CODEC_InitStruct->CODEC_Ch1ZeroDetTimeout = Ch_ADC_Zero_DetTimeout_1024_16_Sample;
    /* PDM initialization parameters section */
    CODEC_InitStruct->CODEC_DaMute = CODEC_MUTE;
    CODEC_InitStruct->CODEC_DaGain = 0xAF;
    CODEC_InitStruct->CODEC_DaC_Dither = DAC_DA_DITHER_DISABLE;
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
  * \brief  Enable or disable mic_bias output.
  * \param  CODECx: selected CODEC peripheral.
  * \param  NewState: new state of MICBIAS.
  *   This parameter can be: ENABLE or DISABLE.
  * \return none.
  */
void CODEC_MICBIASCmd(CODEC_TypeDef *CODECx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    CODEC_ANA_00_BUS_t codec_0x000 = {.d32 = CODEC_ANA->CODEC_ANA_00_BUS};
    CODEC_ANA_01_BUS_t codec_0x004 = {.d32 = CODEC_ANA->CODEC_ANA_01_BUS};
    AUDIO_CONTROL_1_t codec_0x104 = {.d32 = CODEC->AUDIO_CONTROL_1};

    if (NewState == ENABLE)
    {
        if (!(codec_0x004.b.MICBIAS_POW))
        {
            /* Analog initialization in AON register */
            CODEC_AnalogCircuitInit();

            /* MICBIAS power on */
            codec_0x004.b.VREF_VREFSEL = 0x2;
            codec_0x004.b.MICBST_POW = 0x1;
            codec_0x004.b.VREF_POW = 0x1;
            codec_0x004.b.MICBIAS_POW = 0x1;
            codec_0x004.b.MICBIAS_ENCHX = 0x1;

            codec_0x000.b.DAC_ADDACK_POW = 0x1;
            codec_0x000.b.DTSDM_CKXEN = 0x1;
            codec_0x000.b.DTSDM_POW_L = 0x1;

            /* Clock enable */
            codec_0x104.b.ckx_micbias_en = 0x1;
        }
    }
    else
    {
        codec_0x000.b.DTSDM_POW_L = 0x0;
        codec_0x000.b.DAC_ADDACK_POW = 0x0;
        codec_0x000.b.DTSDM_CKXEN = 0x0;
        codec_0x004.b.MICBST_POW = 0x0;
        codec_0x004.b.MICBIAS_ENCHX = 0x0;
        codec_0x004.b.VREF_POW = 0x0;
        CODEC_AnalogCircuitDeInit();
    }
    CODEC_ANA->CODEC_ANA_01_BUS = codec_0x004.d32;
    CODEC_ANA->CODEC_ANA_02_BUS = codec_0x000.d32;
    CODEC->AUDIO_CONTROL_1 = codec_0x104.d32;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/