/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_codec.h
* \brief    The header file of the peripheral CODEC driver.
* \details  This file provides all CODEC firmware functions.
* \author   echo gao
* \date     2023-10-17
* \version  v1.0
* *******************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_CODEC_H
#define RTL_CODEC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "codec/src/rtl87x2g/rtl_codec_def.h"
#endif

/** \defgroup CODEC       CODEC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup CODEC_Exported_Constants CODEC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    I2S_Rx_Data_Width I2S Rx Data Width
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_Rx_DataWidth_16Bits,          //!< The I2S Rx data width is 16 bits.
    CODEC_I2S_Rx_DataWidth_8Bits = 0x3,     //!< The I2S Rx data width is 8 bits.
    CODEC_I2S_Rx_DataWidth_MAX,             //!< The maximum of I2S data width.
} CodecI2SRxDatalenSel_TypeDef;

/** End of I2S_Rx_Data_Width
  * \}
  */

/**
 * \defgroup    I2S_Tx_Data_Width I2S Tx Data Width
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_Tx_DataWidth_16Bits,           //!< The I2S Tx data width is 16 bits.
    CODEC_I2S_Tx_DataWidth_24Bits = 0x2,     //!< The I2S Tx data width is 24 bits.
    CODEC_I2S_Tx_DataWidth_8Bits = 0x3,      //!< The I2S Tx data width is 8 bits.
    CODEC_I2S_Tx_DataWidth_MAX,              //!< The maximum of I2S data width.
} CodecI2STxDatalenSel_TypeDef;

/** End of I2S_Tx_Data_Width
  * \}
  */

/**
 * \defgroup    I2S_Channel_Lenth I2S Channel Lenth
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    I2S_CHANNELLEN_16,     //!< The I2S channel lenth is 16 bits.
    I2S_CHANNELLEN_32,     //!< The I2S channel lenth is 32 bits.
    I2S_CHANNELLEN_24,     //!< The I2S channel lenth is 24 bits.
    I2S_CHANNELLEN_8,      //!< The I2S channel lenth is 8 bits.
    I2S_CHANNELLEN_MAX,    //!< The maximum of I2S channel lenth.
} CodecI2SChannellenSel_TypeDef;

/** End of I2S_Channel_Lenth
  * \}
  */

/**
 * \defgroup    I2S_Data_Format I2S Data Format
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_DataFormat_I2S,            //!< The I2S Rx channel data format is I2S.
    CODEC_I2S_DataFormat_LeftJustified,  //!< The I2S Rx channel data format is left justified.
    CODEC_I2S_DataFormat_PCM_A,          //!< The I2S Rx channel data format is PCM mode A.
    CODEC_I2S_DataFormat_PCM_B,          //!< The I2S Rx channel data format is PCM mode B.
    CODEC_I2S_DataFormat_MAX,            //!< The maximum of I2S data format.
} CodecI2SFormatSel_TypeDef;

#define IS_CODEC_I2S_DATA_FORMAT(FORMAT) (((FORMAT) == CODEC_I2S_DataFormat_I2S) || \
                                          ((FORMAT) == CODEC_I2S_DataFormat_LeftJustified) || \
                                          ((FORMAT) == CODEC_I2S_DataFormat_PCM_A) || \
                                          ((FORMAT) == CODEC_I2S_DataFormat_PCM_B))

/** End of I2S_Data_Format
  * \}
  */

/**
 * \defgroup    CODEC_DAC_Dither CODEC DAC Dither
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    DAC_DA_DITHER_DISABLE = 0,    //!< The SDM dither in the DAC path of the audio channel is disabled.
    DAC_DA_DITHER_LSB = 1,        //!< The SDM dither in the DAC path of the audio channel is set to LSB.
    DAC_DA_DITHER_LSB_PLUS_1 = 2, //!< The SDM dither in the DAC path of the audio channel is set to LSB+1.
    DAC_DA_DITHER_LSB_PLUS_2 = 3, //!< The SDM dither in the DAC path of the audio channel is set to LSB+2.
} CodecDacDADitherSel_TypeDef;

/** End of CODEC_DAC_Dither
  * \}
  */

/**
 * \defgroup    CODEC_I2S_CH CODEC I2S CH
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_CH_L_R,        //!< I2S transmission channel sequence from left to right.
    CODEC_I2S_CH_R_L,        //!< I2S transmission channel sequence from right to left.
    CODEC_I2S_CH_L_L,        //!< I2S transmission channel sequence from left to left.
    CODEC_I2S_CH_R_R,        //!< I2S transmission channel sequence from right to right.
    CODEC_I2S_CH_SEL_MAX,    //!< The maximum of I2S transmission channel sequence.
} CodecI2SCHSequenceSel_TypeDef;

#define IS_CODEC_I2S_CH(CH)             (((CH) == CODEC_I2S_CH_L_R) || \
                                         ((CH) == CODEC_I2S_CH_R_L) || \
                                         ((CH) == CODEC_I2S_CH_L_L) || \
                                         ((CH) == CODEC_I2S_CH_R_R))

/** End of CODEC_I2S_CH
  * \}
  */

/**
 * \defgroup    Sample_Rate_Definition Sample Rate Definition
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    SAMPLE_RATE_48KHz,      //!< CODEC sample rate is 48KHz.
    SAMPLE_RATE_96KHz,      //!< CODEC sample rate is 96KHz.
    SAMPLE_RATE_192KHz,     //!< CODEC sample rate is 192KHz.
    SAMPLE_RATE_32KHz,      //!< CODEC sample rate is 32KHz.
    SAMPLE_RATE_176KHz,     //!< CODEC sample rate is 176.4KHz.
    SAMPLE_RATE_16KHz,      //!< CODEC sample rate is 16KHz.
    SAMPLE_RATE_RSV_1,      //!< This parameter is meaningless.
    SAMPLE_RATE_8KHz,       //!< CODEC sample rate is 8KHz
    SAMPLE_RATE_44100Hz,    //!< CODEC sample rate is 44.1KHz
    SAMPLE_RATE_88200Hz,    //!< CODEC sample rate is 88.2KHz
    SAMPLE_RATE_24KHz,      //!< CODEC sample rate is 24KHz
    SAMPLE_RATE_12KHz,      //!< CODEC sample rate is 12KHz
    SAMPLE_RATE_22050Hz,    //!< CODEC sample rate is 22.05KHz
    SAMPLE_RATE_11025Hz,    //!< CODEC sample rate is 11.025KHz
    SAMPLE_RATE_NUM,        //!< The maximum of CODEC sample rate.
} CodecSampleRate_TypeDef;

#define IS_SAMPLE_RATE(RATE) (((RATE) == SAMPLE_RATE_48KHz)   || ((RATE) == SAMPLE_RATE_96KHz)   || \
                              ((RATE) == SAMPLE_RATE_192KHz)   || ((RATE) == SAMPLE_RATE_176KHz)   || \
                              ((RATE) == SAMPLE_RATE_32KHz)   || ((RATE) == SAMPLE_RATE_16KHz)   || \
                              ((RATE) == SAMPLE_RATE_8KHz)    || ((RATE) == SAMPLE_RATE_44100Hz) || \
                              ((RATE) == SAMPLE_RATE_88200Hz) || ((RATE) == SAMPLE_RATE_24KHz)   || \
                              ((RATE) == SAMPLE_RATE_12KHz)   || ((RATE) == SAMPLE_RATE_22050Hz) || \
                              ((RATE) == SAMPLE_RATE_11025Hz))

/** End of Sample_Rate_Definition
  * \}
  */

/**
 * \defgroup    CODEC_Sample_Rate_SRC CODEC Sample Rate SRC
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    SAMPLE_RATE_SRC0 = 0,
    SAMPLE_RATE_SRC1 = 1,
    SAMPLE_RATE_SRC2 = 2,
    SAMPLE_RATE_SRC3_DA = 3,
    SAMPLE_RATE_SRC_MAX = 4,
} CodecSampleRateSrc_TypeDef;

/** End of CODEC_Sample_Rate_SRC
  * \}
  */

/**
 * \defgroup    DMIC_Clock_Type_Definition DMIC Clock Type Definition
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    DMIC_Clock_5MHz,         //!< CODEC DMIC clock source is 5MHz.
    DMIC_Clock_2500KHz,      //!< CODEC DMIC clock source is 2500KHz.
    DMIC_Clock_1250KHz,      //!< CODEC DMIC clock source is 1250KHz.
    DMIC_Clock_625KHz,       //!< CODEC DMIC clock source is 625KHz.
    DMIC_Clock_312500Hz,     //!< CODEC DMIC clock source is 312500Hz.
    DMIC_CLK_SEL_MAX,        //!< The maximum of CODEC DMIC clock source.
} CodecDmicClkSel_TypeDef;

#define IS_CODEC_DMIC_CLOCK(CLOCK) (((CLOCK) == DMIC_Clock_5MHz) || ((CLOCK) == DMIC_Clock_2500KHz) || \
                                    ((CLOCK) == DMIC_Clock_1250KHz) || ((CLOCK) == DMIC_Clock_625KHz) || \
                                    ((CLOCK) == DMIC_Clock_312500Hz))

/** End of DMIC_Clock_Type_Definition
  * \}
  */

/**
 * \defgroup    CODEC_MIC_BIAS_Config CODEC MIC BIAS Config
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    MICBIAS_VOLTAGE_1_507,     //!< Vref voltage is 1.507V.
    MICBIAS_VOLTAGE_1_62,      //!< Vref voltage is 1.62V.
    MICBIAS_VOLTAGE_1_705,     //!< Vref voltage is 1.705V.
    MICBIAS_VOLTAGE_1_8,       //!< Vref voltage is 1.8V.
    MICBIAS_VOLTAGE_1_906,     //!< Vref voltage is 1.906V.
    MICBIAS_VOLTAGE_2_025,     //!< Vref voltage is 2.025V.
    MICBIAS_VOLTAGE_2_16,      //!< Vref voltage is 2.16V.
    MICBIAS_VOLTAGE_2_314,     //!< Vref voltage is 2.314V.
} MicbiasVoltageSel_TypeDef;

#define IS_MICBIAS_CONFIG(CONFIG) (((CONFIG) == MICBIAS_VOLTAGE_1_507) || ((CONFIG) == MICBIAS_VOLTAGE_1_62) || \
                                   ((CONFIG) == MICBIAS_VOLTAGE_1_705) || ((CONFIG) == MICBIAS_VOLTAGE_1_8) || \
                                   ((CONFIG) == MICBIAS_VOLTAGE_1_906) || ((CONFIG) == MICBIAS_VOLTAGE_2_025) || \
                                   ((CONFIG) == MICBIAS_VOLTAGE_2_16) || ((CONFIG) == MICBIAS_VOLTAGE_2_314))

/** End of CODEC_MIC_BIAS_Config
  * \}
  */

/**
 * \defgroup    MICBST_Gain MICBST Gain
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    MICBST_Gain_0dB,     //!< MICBST Gain is 0dB.
    MICBST_Gain_20dB,    //!< MICBST Gain is 20dB.
    MICBST_Gain_30dB,    //!< MICBST Gain is 30dB.
    MICBST_Gain_40dB,    //!< MICBST Gain is 40dB.
} MicbiasGainSel_TypeDef;

#define IS_MICBST_GAIN(GAIN)            (((GAIN) == MICBST_Gain_0dB) || \
                                         ((GAIN) == MICBST_Gain_20dB) || \
                                         ((GAIN) == MICBST_Gain_30dB) || \
                                         ((GAIN) == MICBST_Gain_40dB))

/** End of MICBST_Gain
  * \}
  */

/**
 * \defgroup    MICBST_Mode MICBST Mode
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    MICBST_Mode_Single,           //!< MICBST channel mode is single-ended mode.
    MICBST_Mode_Differential,     //!< MICBST channel mode is differential mode.
} MicbiasModeSel_TypeDef;

#define IS_MICBST_MODE(MODE)            (((MODE) == MICBST_Mode_Single) || \
                                         ((MODE) == MICBST_Mode_Differential))

/** End of MICBST_Mode
  * \}
  */

/**
 * \defgroup    CODEC_Mute_Type CODEC Mute Type
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_UNMUTE,    //!< The microphone boost is un-muted or active.
    CODEC_MUTE,      //!< The microphone input is muted.
} CodecMuteSel_TypeDef;

#define IS_CODEC_MIC_MUTE(MUTE) (((MUTE) == CODEC_MUTE) || ((MUTE) == CODEC_UNMUTE))

/** End of CODEC_Mute_Type
  * \}
  */

/**
 * \defgroup    CODEC_Ch_Mic_Type CODEC Ch Mic Type
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH_DMIC,      //!< Select the Digital Microphone.
    CODEC_CH_AMIC,      //!< Select the Analog Microphone.
} CodecCHMicSel_TypeDef;

#define IS_CODEC_CH_MIC_TYPE(TYPE) (((TYPE) == CODEC_CH_AMIC) || ((TYPE) == CODEC_CH_DMIC))

/** End of CODEC_Ch_Mic_Type
  * \}
  */

/**
 * \defgroup    DMIC_Data_Latch_Edge DMIC Data Latch Edge
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    DMIC_Ch_Rising_Latch,       //!< DMIC is set to rising edge trigger.
    DMIC_Ch_Falling_Latch,      //!< DMIC is set to falling edge trigger.
} CdecCHLatchEdgeSel_TypeDef;

#define IS_DMIC_CH_LATCH_EDGE(EDGE) (((EDGE) == DMIC_Ch_Rising_Latch) || ((EDGE) == DMIC_Ch_Falling_Latch))

/** End of DMIC_Data_Latch_Edge
  * \}
  */

/**
 * \defgroup    Ch_ADC_Zero_Detection_Timeout Ch ADC Zero Detection Timeout
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    Ch_ADC_Zero_DetTimeout_1024_16_Sample,      //!< Ch ADC Zero Detection Timeout is 1024_16_Sample.
    Ch_ADC_Zero_DetTimeout_1024_32_Sample,      //!< Ch ADC Zero Detection Timeout is 1024_32_Sample.
    Ch_ADC_Zero_DetTimeout_1024_64_Sample,      //!< Ch ADC Zero Detection Timeout is 1024_64_Sample.
    Ch_ADC_Zero_DetTimeout_64_Sample,           //!< Ch ADC Zero Detection Timeout is 64_Sample.
} CodecCHZDTSel_TypeDef;

#define IS_CH_ADC_ZERO_DET_TIMEOUT(TIMEOUT) (((TIMEOUT) == Ch_ADC_Zero_DetTimeout_1024_16_Sample) || \
                                             ((TIMEOUT) == Ch_ADC_Zero_DetTimeout_1024_32_Sample) || \
                                             ((TIMEOUT) == Ch_ADC_Zero_DetTimeout_1024_64_Sample) || \
                                             ((TIMEOUT) == Ch_ADC_Zero_DetTimeout_64_Sample))

/** End of Ch_ADC_Zero_Detection_Timeout
  * \}
  */

/**
 * \defgroup    Codec_Ad_Gain Codec Ad Gain
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
#define IS_AD_GAIN(GAIN)            (((GAIN)<= 0x7F))     //!< Codec Ad Gain.

/** End of Codec_Ad_Gain
  * \}
  */

/** End of CODEC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup CODEC_Exported_Types CODEC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       CODEC initialize parameters.
 *
 * \ingroup     CODEC_Exported_Types
 */
typedef struct
{
    /* Basic parameters section */
    CodecSampleRateSrc_TypeDef CODEC_AdSampleRateSrc; /*!< Specify the ADC path sample rate source.
                                                           This parameter can be a value of \ref CODEC_Sample_Rate_SRC. */

    CodecSampleRateSrc_TypeDef CODEC_DaSampleRateSrc; /*!< Specify the DAC path sample rate source.
                                                           This parameter can be a value of \ref CODEC_Sample_Rate_SRC. */

    CodecSampleRate_TypeDef CODEC_SampleRate0;        /*!< Specify the sample rate 0.
                                                           This parameter can be a value of \ref Sample_Rate_Definition. */

    CodecSampleRate_TypeDef CODEC_SampleRate1;        /*!< Specify the sample rate 1.
                                                           This parameter can be a value of \ref Sample_Rate_Definition. */

    CodecDmicClkSel_TypeDef CODEC_DmicClock;          /*!< Specify the dmic clock.
                                                           This parameter can be a value of \ref DMIC_Clock_Type_Definition. */

    CodecI2SFormatSel_TypeDef CODEC_I2SFormat;        /*!< Specify the I2S Tx/Rx format of codec port.
                                                           This parameter can be a value of \ref I2S_Data_Format. */
    CodecI2STxDatalenSel_TypeDef
    CODEC_I2STxDataWidth;                             /*!< Specify the I2S Tx data width of codec port.
                                                           This parameter can be a value of \ref I2S_Tx_Data_Width. */

    CodecI2SRxDatalenSel_TypeDef
    CODEC_I2SRxDataWidth;                             /*!< Specify the I2S Rx data width of codec port.
                                                           This parameter can be a value of \ref I2S_Rx_Data_Width. */

    CodecI2SChannellenSel_TypeDef
    CODEC_I2SChannelLen;                              /*!< Specify the I2S Tx/Rx channel width of codec port.
                                                           This parameter can be a value of \ref I2S_Channel_Lenth. */

    CodecI2SCHSequenceSel_TypeDef CODEC_I2SChSequence;/*!< Specify the I2S Tx/Rx channel sequence.
                                                           This parameter can be a value of \ref CODEC_I2S_CH. */

    uint8_t CODEC_I2SSameLrcEn;                       /*!< Enable or disable Tx and Rx using the same transmission mode.
                                                           This parameter can be a value of DISABLE or ENABLE. */

    MicbiasVoltageSel_TypeDef CODEC_MicBIAS;          /*!< Specify the MICBIAS voltage.
                                                           This parameter can be a value of \ref CODEC_MIC_BIAS_Config */

    MicbiasGainSel_TypeDef CODEC_MicBstGain;          /*!< Specify the MICBST gain.
                                                           This parameter can be a value of \ref MICBST_Gain. */

    MicbiasModeSel_TypeDef CODEC_MicBstMode;          /*!< Specify the MICBST mode.
                                                           This parameter can be a value of \ref MICBST_Mode. */

    /* MIC channel 0 initialization parameters section */
    CodecMuteSel_TypeDef CODEC_Ch0Mute;               /*!< Specify the channel 0 dmic mute status.
                                                           This parameter can be a value of \ref CODEC_Mute_Type. */

    CodecCHMicSel_TypeDef
    CODEC_Ch0MicType;                                 /*!< Specify the channel 0 mic type, which can be dmic or amic.
                                                           This parameter can be a value of \ref CODEC_Ch_Mic_Type. */

    CdecCHLatchEdgeSel_TypeDef
    CODEC_Ch0DmicDataLatch;                           /*!< Specify the channel 0 dmic data latch type.
                                                           This parameter can be a value of \ref DMIC_Data_Latch_Edge. */

    uint32_t CODEC_Ch0AdGain;                         /*!< Specify the channel 0 ADC digital volume.
                                                           This parameter can be a value of 0x0 ~ 0x10f. */

    CodecCHZDTSel_TypeDef
    CODEC_Ch0ZeroDetTimeout;                          /*!< Specify the channel 0 zero detection timeout mode control.
                                                           This parameter can be a value of \ref Ch_ADC_Zero_Detection_Timeout. */

    /* MIC channel 1 initialization parameters section */
    CodecMuteSel_TypeDef CODEC_Ch1Mute;               /*!< Specify the channel 1 dmic mute status.
                                                           This parameter can be a value of \ref CODEC_Mute_Type. */
    CodecCHMicSel_TypeDef
    CODEC_Ch1MicType;                                 /*!< Specify the channel 1 mic type, which can be dmic or amic.
                                                           This parameter can be a value of \ref CODEC_Ch_Mic_Type. */

    CdecCHLatchEdgeSel_TypeDef
    CODEC_Ch1DmicDataLatch;                           /*!< Specify the channel 1 dmic data latch type.
                                                           This parameter can be a value of \ref DMIC_Data_Latch_Edge. */

    uint32_t CODEC_Ch1AdGain;                         /*!< Specify the channel 1 ADC digital volume.
                                                           This parameter can be a value of 0x0 ~ 0x10f. */

    CodecCHZDTSel_TypeDef
    CODEC_Ch1ZeroDetTimeout;                          /*!< Specify the channel 0 zero detection timeout mode control.
                                                           This parameter can be a value of \ref Ch_ADC_Zero_Detection_Timeout. */

    /* PDM initialization parameters section */
    CodecMuteSel_TypeDef CODEC_DaMute;                /*!< Specify the DAC mute status.
                                                           This parameter can be a value of \ref CODEC_Mute_Type. */

    uint32_t CODEC_DaGain;                            /*!< Specify the DAC gain control.
                                                           This parameter can be a value of 0x0 ~ 0xAF. */

    CodecDacDADitherSel_TypeDef
    CODEC_DaC_Dither;     /*!< Specify the SDM dither in the DAC path of the audio channel.
                                                           This parameter can be a value of \ref CODEC_DAC_Dither. */
} CODEC_InitTypeDef;


/**
 * \brief       CODEC EQ part initialize parameters.
 *
 * \ingroup     CODEC_Exported_Types
 */
typedef struct
{
    uint32_t CODEC_EQChCmd;             /*!< Specify the EQ channel status.
                                             This parameter can be a value of DISABLE or ENABLE. */

    uint32_t CODEC_EQCoefH0;            /*!< Specify the EQ coef.h0. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99. */

    uint32_t CODEC_EQCoefB1;            /*!< Specify the EQ coef.b1. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99. */

    uint32_t CODEC_EQCoefB2;            /*!< Specify the EQ coef.b2. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99. */

    uint32_t CODEC_EQCoefA1;            /*!< Specify the EQ coef.a1. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99. */

    uint32_t CODEC_EQCoefA2;            /*!< Specify the EQ coef.a2. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99. */
} CODEC_EQInitTypeDef;

/** End of CODEC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup CODEC_Exported_Functions CODEC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitializes the CODEC peripheral registers to their default reset values(turn off CODEC clock).
 * \param[in] CODECx: CODEC peripheral selected .
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     CODEC_DeInit(CODEC);
 * }
 * \endcode
 */
void CODEC_DeInit(CODEC_TypeDef *CODECx);
/**
 * \brief    Initialize the CODEC analog registers in AON area.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_CODEC, APBPeriph_CODEC_CLOCK, ENABLE);
 *     CODEC_AnalogCircuitInit();
 *     CODEC_InitTypeDef CODEC_InitStruct;
 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_CH0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SFormat        = CODEC_I2S_DataFormat_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DataWidth_16Bits;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_AnalogCircuitInit(void);
/**
 * \brief   Initialize the CODEC peripheral according to the specified
 *          parameters in the CODEC_InitStruct.
 * \param[in] CODECx: CODEC peripheral selected.
 * \param[in] CODEC_InitStruct: Pointer to a CODEC_InitTypeDef structure that
 *            contains the configuration information for the specified CODEC peripheral
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_CODEC, APBPeriph_CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;

 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_CH0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SFormat        = CODEC_I2S_DataFormat_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DataWidth_16Bits;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_Init(CODEC_TypeDef *CODECx, CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * \brief   Fill each CODEC_InitStruct member with its default value.
 *
 * \note The default settings for the CODEC_InitTypeDef member are shown in the following table:
 *       | CODEC_InitTypeDef member     | Default value                              |
 *       |:----------------------------:|:------------------------------------------:|
 *       | CODEC_AdSampleRateSrc        | \ref SAMPLE_RATE_SRC0                      |
 *       | CODEC_DaSampleRateSrc        | \ref SAMPLE_RATE_SRC0                      |
 *       | CODEC_SampleRate0            | \ref SAMPLE_RATE_16KHz                     |
 *       | CODEC_SampleRate1            | \ref SAMPLE_RATE_16KHz                     |
 *       | CODEC_I2SChSequence          | \ref CODEC_I2S_CH_L_R                      |
 *       | CODEC_I2STxDataWidth         | \ref CODEC_I2S_Tx_DataWidth_16Bits         |
 *       | CODEC_I2SRxDataWidth         | \ref CODEC_I2S_Rx_DataWidth_16Bits         |
 *       | CODEC_I2SChannelLen          | \ref I2S_CHANNELLEN_32                     |
 *       | CODEC_I2SFormat              | \ref CODEC_I2S_DataFormat_I2S              |
 *       | CODEC_I2SSameLrcEn           | DISABLE                                    |
 *       | CODEC_MicBIAS                | \ref MICBIAS_VOLTAGE_1_8                   |
 *       | CODEC_MicBstMode             | \ref MICBST_Mode_Single                    |
 *       | CODEC_MicBstGain             | \ref MICBST_Gain_20dB                      |
 *       | CODEC_DmicClock              | \ref DMIC_Clock_2500KHz                    |
 *       | CODEC_Ch0Mute                | \ref CODEC_UNMUTE                          |
 *       | CODEC_Ch0MicType             | \ref CODEC_CH_AMIC                         |
 *       | CODEC_Ch0DmicDataLatch       | \ref DMIC_Ch_Rising_Latch                  |
 *       | CODEC_Ch0AdGain              | 0x2F                                       |
 *       | CODEC_Ch0ZeroDetTimeout      | \ref Ch_ADC_Zero_DetTimeout_1024_16_Sample |
 *       | CODEC_Ch1Mute                | \ref CODEC_MUTE                            |
 *       | CODEC_Ch1MicType             | \ref CODEC_CH_DMIC                         |
 *       | CODEC_Ch1DmicDataLatch       | \ref DMIC_Ch_Falling_Latch                 |
 *       | CODEC_Ch1AdGain              | 0x2F                                       |
 *       | CODEC_Ch1ZeroDetTimeout      | \ref Ch_ADC_Zero_DetTimeout_1024_16_Sample |
 *       | CODEC_DaMute                 | \ref CODEC_MUTE                            |
 *       | CODEC_DaGain                 | 0xAF                                       |
 *       | CODEC_DaC_Dither             | \ref DAC_DA_DITHER_DISABLE                 |
 *
 * \param[in] CODEC_InitStruct: Pointer to a CODEC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_CODEC, APBPeriph_CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;

 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_CH0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SFormat        = CODEC_I2S_DataFormat_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DataWidth_16Bits;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_StructInit(CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * \brief   Initialize the CODEC EQ module according to the specified
 *          parameters in the CODEC_EQInitStruct.
 * \param[in] CODEC_EQx: CODEC EQ channel selected.
 * \param[in] CODEC_EQInitStruct: Pointer to a CODEC_EQInitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_StructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct. CODEC_EQChCmd    = EQ_CH_Cmd_ENABLE;
 *     CODEC_EQInitStruct.CODEC_EQCoefH0    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB2    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA2    = 0xFF;
 *     CODEC_EQInit(CODEC_EQ1, CODEC_EQInitStruct);
 * }
 * \endcode
 */
void CODEC_EQInit(CODEC_EQTypeDef *CODEC_EQx, CODEC_EQInitTypeDef *CODEC_EQInitStruct);

/**
 * \brief  Fill each CODEC_EQInitStruct member with its default value.
 * \param[in] CODEC_EQInitStruct: Pointer to a CODEC_EQInitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_StructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct. CODEC_EQChCmd    = EQ_CH_Cmd_ENABLE;
 *     CODEC_EQInitStruct.CODEC_EQCoefH0    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB2    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA2    = 0xFF;
 *     CODEC_EQInit(CODEC_EQ1, CODEC_EQInitStruct);
 * }
 * \endcode
 */
void CODEC_EQStructInit(CODEC_EQInitTypeDef *CODEC_EQInitStruct);

/**
 * \brief  Enable or disable mic_bias output.
 * \param[in] CODECx: CODEC peripheral selected.
 * \param[in] NewState: New state of MICBIAS.
 *      This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_MICBIASCmd(CODEC, ENABLE);
 * }
 * \endcode
 */
void CODEC_MICBIASCmd(CODEC_TypeDef *CODECx, FunctionalState NewState);

/**
 * \brief  Reset CODEC.
 * \param[in] CODECx: CODEC peripheral selected.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_Reset(CODEC);
 * }
 * \endcode
 */
__STATIC_INLINE void CODEC_Reset(CODEC_TypeDef *CODECx)
{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    AUDIO_CONTROL_0_t codec_0x100 = {.d32 = CODEC->AUDIO_CONTROL_0};

    /* CODEC IP reset */
    codec_0x100.b.audio_ip_en = 0;
    CODEC->AUDIO_CONTROL_0 = codec_0x100.d32;
    codec_0x100.b.audio_ip_en = 1;
    CODEC->AUDIO_CONTROL_0 = codec_0x100.d32;
}

/**
 * \brief   Config MIC BIAS Vref voltage.
 * \param[in] CODECx: CODEC peripheral selected.
 * \param[in] data: New value of MIC BIAS.
 *   This parameter can be one of the following values:
 *     \arg MICBIAS_VOLTAGE_1_507: Vref voltage is 1.507V.
 *     \arg MICBIAS_VOLTAGE_1_62:  Vref voltage is 1.62V.
 *     \arg MICBIAS_VOLTAGE_1_705: Vref voltage is 1.705V.
 *     \arg MICBIAS_VOLTAGE_1_8: Vref voltage is 1.8V.
 *     \arg MICBIAS_VOLTAGE_1_906: Vref voltage is 1.906V.
 *     \arg MICBIAS_VOLTAGE_2_025:  Vref voltage is 2.025V.
 *     \arg MICBIAS_VOLTAGE_2_16: Vref voltage is 2.16V.
 *     \arg MICBIAS_VOLTAGE_2_314: Vref voltage is 2.314V.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_SetMICBIAS(CODEC, MICBIAS_VOLTAGE_1_507);
 * }
 * \endcode
 */
__STATIC_INLINE void CODEC_SetMICBIAS(CODEC_TypeDef *CODECx,  uint16_t data)

{
    /* Check the parameters */
    assert_param(IS_CODEC_PERIPH(CODECx));
    assert_param(IS_MICBIAS_CONFIG(data));
    CODEC_ANA_01_BUS_t codec_0x004 = {.d32 = CODEC_ANA->CODEC_ANA_01_BUS};

    codec_0x004.b.MICBIAS_VSET =  data;

    CODEC_ANA->CODEC_ANA_01_BUS = codec_0x004.d32;
}

/** End of CODEC_Exported_Functions
  * \}
  */

/** End of CODEC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_CODEC_H */
