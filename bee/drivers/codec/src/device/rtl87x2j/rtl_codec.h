/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "codec/src/rtl87x2j/rtl_codec_def.h"
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
 * \defgroup    CODEC_I2S_Data_Width CODEC I2S Data Width
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_DATA_WIDTH_16BITS,
    CODEC_I2S_DATA_WIDTH_24BITS = 0x2,
    CODEC_I2S_DATA_WIDTH_8BITS = 0x3,
    CODEC_I2S_DATA_WIDTH_MAX,
} CODECI2SDataWidth_TypeDef;

#define IS_CODEC_I2S_DATA_WIDTH(WIDTH) (((WIDTH) == CODEC_I2S_DATA_WIDTH_16BITS) || \
                                        ((WIDTH) == CODEC_I2S_DATA_WIDTH_24BITS) || \
                                        ((WIDTH) == CODEC_I2S_DATA_WIDTH_8BITS))


/** End of CODEC_I2S_Data_Width
  * \}
  */

/**
 * \defgroup    CODEC_I2S_Data_Format CODEC I2S Data Format
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_DATA_FORMAT_I2S,
    CODEC_I2S_DATA_FORMAT_LEFT_JUSTIFIED,
    CODEC_I2S_DATA_FORMAT_PCM_A,
    CODEC_I2S_DATA_FORMAT_PCM_B,
    CODEC_I2S_DATA_FORMAT_MAX,
} CODECI2SDataFormat_TypeDef;

#define IS_CODEC_I2S_DATA_FORMAT(FORMAT) (((FORMAT) == CODEC_I2S_DATA_FORMAT_I2S) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_LEFT_JUSTIFIED) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_PCM_A) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_PCM_B))

/** End of CODEC_I2S_Data_Format
  * \}
  */

\
/**
 * \defgroup    CODEC_I2S_Ch_Seq CODEC I2S Ch Seq
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_I2S_CH_SEQ_L_R,
    CODEC_I2S_CH_SEQ_R_L,
    CODEC_I2S_CH_SEQ_L_L,
    CODEC_I2S_CH_SEQ_R_R,
    CODEC_I2S_CH_SEQ_SEL_MAX,
} CODECI2SChSeq_TypeDef;

#define IS_CODEC_I2S_CH_SEQ(CH) (((CH) == CODEC_I2S_CH_SEQ_L_R) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_R_L) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_L_L) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_R_R))

/** End of CODEC_I2S_Ch_Seq
  * \}
  */

/**
 * \defgroup    CODEC_Sample_Rate CODEC Sample Rate
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_SAMPLE_RATE_48KHz = 0,    // 0: 48KHz
    CODEC_SAMPLE_RATE_32KHz = 3,    // 3: 32KHz
    CODEC_SAMPLE_RATE_16KHz = 5,    // 5: 16KHz
    CODEC_SAMPLE_RATE_8KHz = 7,     // 7: 8KHz
    CODEC_SAMPLE_RATE_44100Hz = 8,  // 8: 44.1KHz
    CODEC_SAMPLE_RATE_24KHz = 10,    // 10: 24KHz
    CODEC_SAMPLE_RATE_12KHz = 11,    // 11: 12KHz
    CODEC_SAMPLE_RATE_22050Hz = 12, // 12: 22.05KHz
    CODEC_SAMPLE_RATE_11025Hz = 13, // 13: 11.025KHz
    CODEC_SAMPLE_RATE_NUM,
} CODECSampleRate_TypeDef;

#define IS_SAMPLE_RATE(RATE) (((RATE) == CODEC_SAMPLE_RATE_48KHz)   ||((RATE) == CODEC_SAMPLE_RATE_32KHz)    || \
                              ((RATE) == CODEC_SAMPLE_RATE_16KHz)   || ((RATE) == CODEC_SAMPLE_RATE_8KHz)   || \
                              ((RATE) == CODEC_SAMPLE_RATE_44100Hz) || ((RATE) == CODEC_SAMPLE_RATE_24KHz) || \
                              ((RATE) == CODEC_SAMPLE_RATE_12KHz)   || ((RATE) == CODEC_SAMPLE_RATE_22050Hz) || \
                              ((RATE) == CODEC_SAMPLE_RATE_11025Hz))

/** End of CODEC_Sample_Rate
  * \}
  */


/**
 * \defgroup    CODEC_DMIC_Clock CODEC DMIC Clock
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_DMIC_CLOCK_5MHz,
    CODEC_DMIC_CLOCK_2500KHz,
    CODEC_DMIC_CLOCK_1250KHz,
    CODEC_DMIC_CLOCK_625KHz,
    CODEC_DMIC_CLOCK_312500Hz,
    CODEC_DMIC_CLOCK_SEL_MAX,
} CODECDmicClock_TypeDef;

#define IS_CODEC_DMIC_CLOCK(CLOCK) (((CLOCK) == CODEC_DMIC_CLOCK_5MHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_2500KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_1250KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_625KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_312500Hz))

/** End of CODEC_DMIC_Clock
  * \}
  */

/**
 * \defgroup    CODEC_MicBias_Voltage CODEC MicBias Voltage
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_MICBIAS_VOLTAGE_1_507,
    CODEC_MICBIAS_VOLTAGE_1_62,
    CODEC_MICBIAS_VOLTAGE_1_705,
    CODEC_MICBIAS_VOLTAGE_1_8,
    CODEC_MICBIAS_VOLTAGE_1_906,
    CODEC_MICBIAS_VOLTAGE_2_025,
    CODEC_MICBIAS_VOLTAGE_2_16,
    CODEC_MICBIAS_VOLTAGE_2_314,
} CODECMicBiasVoltage_TypeDef;

#define IS_CODEC_MICBIAS_VOLTAGE(VOLTAGE) (((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_507) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_62)  || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_705) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_8)   || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_906) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_025) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_16)  || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_314))

/** End of CODEC_MicBias_Voltage
  * \}
  */

/**
 * \defgroup    CODEC_MicBst_Gain CODEC MicBst Gain
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_MICBST_GAIN_0dB,
    CODEC_MICBST_GAIN_3dB,
    CODEC_MICBST_GAIN_6dB,
    CODEC_MICBST_GAIN_9dB,
    CODEC_MICBST_GAIN_12dB,
    CODEC_MICBST_GAIN_18dB,
    CODEC_MICBST_GAIN_24dB,
    CODEC_MICBST_GAIN_30dB,
} CODECMicBstGain_TypeDef;

#define IS_CODEC_MICBST_GAIN(GAIN) (((GAIN) == CODEC_MICBST_GAIN_0dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_3dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_6dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_9dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_12dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_18dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_24dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_30dB))

/** End of CODEC_MicBst_Gain
  * \}
  */

/**
 * \defgroup    CODEC_Ch0_Boost_Gain CODEC Ch0 Boost Gain
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH0_BOOST_GAIN_0dB,
    CODEC_CH0_BOOST_GAIN_12dB,
    CODEC_CH0_BOOST_GAIN_24dB,
    CODEC_CH0_BOOST_GAIN_36dB,
} CODECCH0_Boost_Gain_TypeDef;

#define IS_CH0_BOOST_GAIN(GAIN) (((GAIN) == CODEC_CH0_BOOST_GAIN_0dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_12dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_24dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_36dB)))

/** End of CODEC_MicBst_Gain
  * \}
  */
/**
 * \defgroup    CODEC_MicBst_Mode CODEC MicBst Mode
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_MICBST_MODE_SINGLE,
    CODEC_MICBST_MODE_DIFFERENTIAL,
} CODECMicBstMode_TypeDef;

#define IS_CODEC_MICBST_MODE(MODE) (((MODE) == CODEC_MICBST_MODE_SINGLE) || \
                                    ((MODE) == CODEC_MICBST_MODE_DIFFERENTIAL))

/** End of CODEC_MicBst_Mode
  * \}
  */

/**
 * \defgroup    CODEC_Ch_Mute CODEC Ch Mute
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH_UNMUTE,
    CODEC_CH_MUTE,
} CODECChMute_TypeDef;

#define IS_CODEC_CH_MUTE(MUTE) (((MUTE) == CODEC_CH_MUTE) || \
                                ((MUTE) == CODEC_CH_UNMUTE))

/** End of CODEC_Ch_Mute
  * \}
  */

/**
 * \defgroup    CODEC_Ch_Mic CODEC Ch Mic
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH_DMIC,
    CODEC_CH_AMIC,
} CODECChMic_TypeDef;

#define IS_CODEC_CH_MIC(MIC) (((MIC) == CODEC_CH_AMIC) || \
                              ((MIC) == CODEC_CH_DMIC))

/** End of CODEC_Ch_Mic
  * \}
  */

/**
 * \defgroup    CODEC_Ch_Dmic_Data_Latch Dmic Data Latch
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH_DMIC_DATA_LATCH_RISING,
    CODEC_CH_DMIC_DATA_LATCH_FALLING,
} CODECChDmicDataLatch_TypeDef;

#define IS_CODEC_DMIC_DATA_LATCh(EDGE) (((EDGE) == CODEC_CH_DMIC_DATA_LATCH_RISING) || \
                                        ((EDGE) == CODEC_CH_DMIC_DATA_LATCH_FALLING))

/** End of CODEC_Ch_Dmic_Data_Latch
  * \}
  */

/**
 * \defgroup    CODEC_Ch_Detection_Timeout CODEC Ch Detection Timeout
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
typedef enum
{
    CODEC_CH_DETTIMEOUT_1024_16_SAMPLE,
    CODEC_CH_DETTIMEOUT_1024_32_SAMPLE,
    CODEC_CH_DETTIMEOUT_1024_64_SAMPLE,
    CODEC_CH_DETTIMEOUT_64_SAMPLE,//??
} CODECChDetTimeout_TypeDef;

#define IS_CODEC_CH_DET_TIMEOUT(TIMEOUT) (((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_16_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_32_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_64_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_64_SAMPLE))

/** End of CODEC_Ch_Detection_Timeout
  * \}
  */

/**
 * \defgroup    CODEC_AD_Gain CODEC AD Gain
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
#define IS_CODEC_AD_GAIN(GAIN)            (((GAIN)<= 0x7F))

/** End of CODEC_Ad_Gain
  * \}
  */

/**
 * \defgroup    CODEC_Interrupt_Definition   CODEC Interrupt Definition
 * \{
 * \ingroup     CODEC_Exported_Constants
 */
#if CODEC_SUPPORT_INT
#define CODEC_INT_POF_READY                            BIT1
#define CODEC_INT_PON_READY                            BIT0

#define IS_CODEC_INT_CONFIG(INT)          (((INT) == CODEC_INT_POF_READY) || ((INT) == CODEC_INT_POF_READY) )

#endif
/** End of CODEC_Interrupt_Definition
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
    CODECSampleRate_TypeDef CODEC_SampleRate;       /*!< Specifies the sample rate . */

    CODECDmicClock_TypeDef CODEC_DmicClock;         /*!< Specifies the dmic clock. */

    CODECI2SDataFormat_TypeDef
    CODEC_I2SDataFormat; /*!< Specifies the I2S Tx/Rx format of codec port. */

    CODECI2SDataWidth_TypeDef CODEC_I2SDataWidth;   /*!< Specifies the I2Sdata width of codec port. */

    CODECI2SChSeq_TypeDef CODEC_I2SChSequence; /*!< Specifies the I2S Tx/Rx channel sequence. */

    CODECMicBiasVoltage_TypeDef CODEC_MicBiasVolt;  /*!< Specifies the MICBIAS voltage. */

    CODECMicBstGain_TypeDef CODEC_MicBstGain;       /*!< Specifies the MicBst gain. */

    CODECMicBstMode_TypeDef CODEC_MicBstMode;       /*!< Specifies the MicBst mode. */

    /* MIC channel 0 initialization parameters section */
    CODECChMute_TypeDef CODEC_Ch0Mute;              /*!< Specifies the channel 0 dmic mute status. */

    CODECChMic_TypeDef
    CODEC_Ch0Mic;                /*!< Specifies the channel 0 mic type, which can be dmic or amic. */

    CODECChDmicDataLatch_TypeDef
    CODEC_Ch0DmicDataLatch; /*!< Specifies the channel 0 dmic data latch type. */

    uint32_t CODEC_Ch0AdGain;                       /*!< Specifies the channel 0 ADC digital volume. -17.625dB~+30dB in 0.375 dB step */

    CODECChDetTimeout_TypeDef
    CODEC_Ch0DetTimeout;  /*!< Specifies the channel 0 zero detection timeout mode control. */
    CODECCH0_Boost_Gain_TypeDef CODEC_Ch0BoostGain;        /*!< Specify the channel 0 boost gain. */
} CODEC_InitTypeDef;


/**
 * \brief       CODEC EQ part initialize parameters.
 *
 * \ingroup     CODEC_Exported_Types
 */
typedef struct
{
    uint32_t CODEC_EQChCmd;             /*!< Specifies the EQ channel status */

    uint32_t CODEC_EQCoefH0;            /*!< Specifies the EQ coef.h0. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99 */

    uint32_t CODEC_EQCoefB1;            /*!< Specifies the EQ coef.b1. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99 */

    uint32_t CODEC_EQCoefB2;            /*!< Specifies the EQ coef.b2. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99 */

    uint32_t CODEC_EQCoefA1;            /*!< Specifies the EQ coef.a1. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99 */

    uint32_t CODEC_EQCoefA2;            /*!< Specifies the EQ coef.a2. This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of-8 to 7.99 */
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
 * \return None.
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
  * \param  None.
  * \retval None
*
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *     CODEC_AnalogCircuitInit();
 *     CODEC_InitTypeDef CODEC_InitStruct;

 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_Ch0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_AnalogCircuitInit(void);
/**
 * \brief   Initializes the CODEC peripheral according to the specified
 *          parameters in the CODEC_InitStruct.
 * \param[in] CODECx: CODEC peripheral selected.
 * \param[in] CODEC_InitStruct: Pointer to a CODEC_InitTypeDef structure that
 *            contains the configuration information for the specified CODEC peripheral
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;

 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_Ch0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_Init(CODEC_TypeDef *CODECx, CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * \brief   Fills each CODEC_InitStruct member with its default value.
 * \param[in] CODEC_InitStruct: Pointer to a CODEC_InitTypeDef structure which will be initialized.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;

 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0MicType       = CODEC_Ch0_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = MICBST_Mode_Differential;
 *     CODEC_InitStruct.CODEC_SampleRate       = SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * \endcode
 */
void CODEC_StructInit(CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * \brief   Initializes the CODEC EQ module according to the specified
 *          parameters in the CODEC_EQInitStruct.
 * \param[in] CODEC_EQx: CODEC EQ channel selected.
 * \param[in] CODEC_EQInitStruct: Pointer to a CODEC_EQInitTypeDef structure that
 *            contains the configuration information for the specified CODEC EQ channel.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_StructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct. CODEC_EQChCmd    = EQ_Ch_Cmd_ENABLE;
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
 * \brief  Fills each CODEC_EQInitStruct member with its default value.
 * \param[in] CODEC_EQInitStruct: Pointer to a CODEC_EQInitTypeDef structure which will be initialized.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_StructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct. CODEC_EQChCmd    = EQ_Ch_Cmd_ENABLE;
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
 * \brief  Reset CODEC.
 * \param[in] CODECx: CODEC peripheral selected.
 * \return None.
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
void CODEC_Reset(CODEC_TypeDef *CODECx);

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
 * \return None.
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
void CODEC_SetMicBias(CODEC_TypeDef *CODECx, uint16_t Data);

/**
 * \brief  Enable or disable mic_bias output.
 * \param[in] CODECx: CODEC peripheral selected.
 * \param[in] NewState: New state of MICBIAS.
 *      This parameter can be: ENABLE or DISABLE.
 * \return none.
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
void CODEC_MicBiasCmd(CODEC_TypeDef *CODECx, FunctionalState NewState);

/**
  * \brief  Enable or disable the specified CODEC interrupts.
  * \param[in]  CODEC: selected CODEC peripheral.
  * \param[in]  CODEC_INT: specifies the CODEC interrupts sources to be enable or disable.
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \param[in]  NewState: new state of the specified CODEC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void CODEC_INTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState);

/**
  * \brief  Mask the specified CODEC interrupt
  * \param[in]  CODEC: selected CODEC peripheral.
  * \param[in]  CODEC_INT: specifies the CODEC interrupts sources to be enable or disable.
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \param[in]  NewState: new state of the specified CODEC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void CODEC_MaskINTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState);

/**
  * \brief  Get the specified CODEC flag status.
  * \param[in]  CODEC: selected CODEC peripheral.
  * \param[in]  CODEC_INT: the specified CODEC interrupt.
  *         This parameter can be one of the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \return[in] The new state of FLAG (SET or RESET).
  */
ITStatus CODEC_GetINTStatus(CODEC_TypeDef *CODECx, uint32_t CODEC_INT);

/**
  * \brief  Clears the CODEC interrupt pending bits.
  * \param[in]  CODEC: selected CODEC peripheral.
  * \param[in]  CODEC_CLEAR_INT: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *         This parameter can be the following values:
  *         \arg CODEC_INT_POF_READY: CODEC power off ready interrupt.
  *         \arg CODEC_INT_PON_READY: CODEC power on ready interrupt.
  * \return None
  */
void CODEC_ClearINTPendingBit(CODEC_TypeDef *CODECx, uint32_t CODEC_CLEAR_INT);

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
