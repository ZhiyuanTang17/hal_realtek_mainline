/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_I2S_H
#define RTL_I2S_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "i2s/src/device/rtl87x2g/rtl_i2s_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "i2s/src/device/rtl87x2j/rtl_i2s_def.h"
#endif

/** \defgroup I2S         I2S
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup I2S_Exported_Constants I2S Exported Constants
  * \brief
  * \{
  */


#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
* \defgroup    I2S_Scheme  I2S Scheme
* \{
* \ingroup     I2S_Exported_Constants
*/
typedef enum
{
    I2S_SCHEME_SEPARATE,
    I2S_SCHEME_DEPENDENT,
} I2SScheme_TypeDef;

#define IS_I2S_SCHEME(SCHEME) (((SCHEME) == I2S_SCHEME_SEPARATE) || \
                               ((SCHEME) == I2S_SCHEME_DEPENDENT)))

/** End of I2S_Scheme
  * \}
  */

#endif

/**
 * \defgroup    I2S_DATA_Format  I2S Data Format
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_DATA_FORMAT_I2S,
    I2S_DATA_FORMAT_LEFT_JUSTIFIED,
    I2S_DATA_FORMAT_PCM_A,
    I2S_DATA_FORMAT_PCM_B,
} I2SDataFormat_TypeDef;

#define IS_I2S_DATA_FORMAT(FORMAT)      (((FORMAT) == I2S_DATA_FORMAT_I2S) || ((FORMAT) == I2S_DATA_FORMAT_LEFT_JUSTIFIED) || \
                                         ((FORMAT) == I2S_DATA_FORMAT_PCM_A) || ((FORMAT) == I2S_DATA_FORMAT_PCM_B))

/** End of I2S_DATA_Format
  * \}
  */

/**
 * \defgroup    I2S_Channel_Type I2S Channel Type
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CHANNEL_STEREO,
    I2S_CHANNEL_MONO,
} I2SChannelType_TypeDef;

#define IS_I2S_CHANNEL_TYPE(TYPE)       (((TYPE) == I2S_CHANNEL_MONO) || ((TYPE) == I2S_CHANNEL_STEREO))

/** End of I2S_Channel_Type
  * \}
  */

/**
 * \defgroup    I2S_Width I2S  Width
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_WIDTH_16BITS = 0x00,
    I2S_WIDTH_24BITS = 0x02,
    I2S_WIDTH_8BITS = 0x03,
#if I2S_SUPPORT_DATE_WIDTH_32BIT
    I2S_WIDTH_20BITS = 0x01,
    I2S_WIDTH_32BITS = 0x04,
#endif
} I2SWidth_TypeDef;

#define IS_I2S_WIDTH(WIDTH)        (((WIDTH) == I2S_WIDTH_16BITS) || \
                                    ((WIDTH) == I2S_WIDTH_8BITS)  || \
                                    ((WIDTH) == I2S_WIDTH_24BITS) || \
                                    ((WIDTH) == I2S_WIDTH_20BITS) || \
                                    ((WIDTH) == I2S_WIDTH_32BITS))

/** End of I2S_Data_Width
  * \}
  */

/**
 * \defgroup    I2S_Device_Mode I2S Device Mode
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_DEVICE_MODE_MASTER,
    I2S_DEVICE_MODE_SLAVE,
} I2SDeviceMode_TypeDef;

#define IS_I2S_DEVICE_MODE(DEVICE)      (((DEVICE) == I2S_DEVICE_MODE_MASTER) || ((DEVICE) == I2S_DEVICE_MODE_SLAVE))

/** End of I2S_Device_Mode
  * \}
  */

/**
 * \defgroup    I2S_Ch_Seq I2S Ch Seq
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CH_SEQ_L_R,
    I2S_CH_SEQ_R_L,
    I2S_CH_SEQ_L_L,
    I2S_CH_SEQ_R_R,
} I2SChSeq_TypeDef;

#define IS_I2S_CH_SEQ(SEQ)       (((SEQ) == I2S_CH_SEQ_L_R) || ((SEQ) == I2S_CH_SEQ_R_L) || \
                                  ((SEQ) == I2S_CH_SEQ_L_L) || ((SEQ) == I2S_CH_SEQ_R_R))

/** End of I2S_Ch_Seq
  * \}
  */

/**
 * \defgroup    I2S_Bit_Seq I2S Bit Seq
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_MSB_FIRST,
    I2S_LSB_FIRST,
} I2SBitSeq_TypeDef;

#define IS_I2S_BIT_SEQ(SEQ)      (((SEQ) == I2S_MSB_FIRST) || ((SEQ) == I2S_LSB_FIRST))

/** End of I2S_Tx_Bit_Seq
  * \}
  */
#if I2S_SUPPORT_TRX_FIFO
/**
 * \defgroup    I2S_FIFO_Sel I2S FIFO Sel
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_FIFO_USE_0_REG_0 = BIT0,
    I2S_FIFO_USE_0_REG_1 = BIT1,
} I2SFIFOSel_TypeDef;

/** End of I2S_FIFO_Sel
  * \}
  */
#endif
#if I2S_SUPPORT_MCLK_OUTPUT
/**
 * \defgroup    I2S_MCLK_Output I2S MCLK Output
 * \{
 * \ingroup     I2S_Exported_Constants
 */

typedef enum
{
    I2S_MCLK_128FS,
    I2S_MCLK_256FS,
} I2SMClkOutput_TypeDef;

#define IS_I2S_MCLK_OUTPUT(TYPE)       (((TYPE) == I2S_MCLK_128FS) || ((TYPE) == I2S_MCLK_256FS))

/** End of I2S_MCLK_Output
  * \}
  */

#endif

/**
 * \defgroup    I2S_ERR_CLR I2S ERR CLR
 * \{
 * \ingroup     I2S_Exported_Constants
 */
/*  I2S_CLR_RX_ERR_CNT. */
#define I2S_CLR_RX_ERR_CNT_MSK          (0x1 << 13)
#define I2S_CLR_RX_ERR_CNT_CLR          (~I2S_CLR_RX_ERR_CNT_MSK)
/* I2S_CLR_TX_ERR_CNT. */
#define I2S_CLR_TX_ERR_CNT_MSK          (0x1 << 12)
#define I2S_CLR_TX_ERR_CNT_CLR          (~I2S_CLR_TX_ERR_CNT_MSK)

#define I2S_RX_FIFO_DEPTH_CNT_0_POS       (8)
#define I2S_RX_ERR_CNT_POS                (15)
#define I2S_MI_NI_UPDATE_MSK             ((uint32_t)0x1 << 31)

#define I2S_FRAME_SYNC_OFFSET_DEFAULT    (0x81 )
/** End of I2S_ERR_CLR
  * \}
  */

/**
 * \defgroup    I2S_Mode I2S Mode
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_MODE_TX,
    I2S_MODE_RX,
} I2SMode_TypeDef;

#define IS_I2S_MODE(MODE)      (((MODE) == I2S_MODE_TX) || ((MODE) == I2S_MODE_RX))

/** End of I2S_Mode
  * \}
  */


#if I2S_SUPPORT_TRX_FIFO
/**
 * \defgroup    I2S_Tx_FIFO_Sel I2S Tx FIFO Sel
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_TX_FIFO_0_REG_0_L,                        // 0
    I2S_TX_FIFO_0_REG_0_R,                        // 1
    I2S_TX_FIFO_0_REG_1_L,                        // 2
    I2S_TX_FIFO_0_REG_1_R,                        // 3
    I2S_TX_SEL_MAX,
} I2STxFIFOSel_TypeDef;

#define IS_I2S_TX_FIFO_SEL(FIFO)       (((FIFO) == I2S_TX_FIFO_0_REG_0_L) || ((FIFO) == I2S_TX_FIFO_0_REG_0_R) || \
                                        ((FIFO) == I2S_TX_FIFO_0_REG_1_L) || ((FIFO) == I2S_TX_FIFO_0_REG_1_R))

/** End of I2S_Tx_FIFO_Sel
  * \}
  */

/**
 * \defgroup    I2S_Rx_Channel_Sel I2S Rx Channel Sel
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_RX_CHANNEL_0,                             // 0
    I2S_RX_CHANNEL_1,                             // 1
    I2S_RX_CHANNEL_2,                             // 2
    I2S_RX_CHANNEL_3,                             // 3
    I2S_RX_SEL_MAX,
} I2SRxChannel_TypeDef;

#define IS_I2S_RX_CHANNEL(CHANNEL)       (((CHANNEL) == I2S_RX_CHANNEL_0) || ((CHANNEL) == I2S_RX_CHANNEL_1) || \
                                          ((CHANNEL) == I2S_RX_CHANNEL_2) || ((CHANNEL) == I2S_RX_CHANNEL_3))
/** End of I2S_Tx_FIFO_Sel
  * \}
  */

#endif
/** End of I2S_Exported_Constants
  * \}
  */
/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup I2S_Exported_Types I2S Exported Types
 * \brief
 * \{
 */

/**
 * \brief       I2S initialize parameters.
 *
 * \ingroup     I2S_Exported_Types
 */
typedef struct
{
    I2SClockSrc_TypeDef I2S_ClockSource;          /*!< Specifies the I2S clock source.*/

#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
    I2SScheme_TypeDef I2S_Scheme;               /*!< Specifies the I2S Scheme.*/

    uint32_t I2S_TxBClockMi;                    /*!< Specifies the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                     This parameter must range from 1 to 0xffff. */

    uint32_t I2S_TxBClockNi;                    /*!< Specifies the BLCK clock speed.
                                                     This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_TxBClockDiv;                   /*!< Specifies the BLCK clock divider.
                                                     This parameter must range from 1 to 0xFF. */

    uint32_t I2S_RxBClockMi;                    /*!< Specifies the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                     This parameter must range from 1 to 0xffff. */

    uint32_t I2S_RxBClockNi;                    /*!< Specifies the BLCK clock speed.
                                                     This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_RxBClockDiv;                   /*!< Specifies the BLCK clock divider.
                                                     This parameter must range from 1 to 0xFF. */

    I2SChannelType_TypeDef I2S_TxChannelType;   /*!< Specifies the channel type.
                                                     It is used for the I2S communication. */

    I2SChannelType_TypeDef I2S_RxChannelType;   /*!< Specifies the channel type.
                                                     It is used for the I2S communication. */

    I2SDataFormat_TypeDef I2S_TxDataFormat;     /*!< Specifies the I2S Data format mode.*/

    I2SDataFormat_TypeDef I2S_RxDataFormat;     /*!< Specifies the I2S Data format mode.*/

    I2SWidth_TypeDef I2S_TxDataWidth;           /*!< Specifies the I2S Data width. */

    I2SWidth_TypeDef I2S_RxDataWidth;           /*!< Specifies the I2S Data width. */

    I2SWidth_TypeDef I2S_TxChannelWidth;        /*!< Specifies the I2S channle width.*/

    I2SWidth_TypeDef I2S_RxChannelWidth;        /*!< Specifies the I2S channle width.*/

    FunctionalState I2S_BClockFixEn;            /*!< Specifies the I2S BCLK fix.
                                                     If ENABLE, BCLK is fixed as 40M/4.*/

#else
    uint32_t I2S_BClockMi;                      /*!< Specifies the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                     This parameter must range from 1 to 0xffff */

    uint32_t I2S_BClockNi;                      /*!< Specifies the BLCK clock speed.
                                                     This parameter must range from 1 to 0x7FFF */

    I2SChannelType_TypeDef I2S_ChannelType;     /*!< Specifies the channel type.
                                                     It is used for the I2S communication.
                                                     This parameter can be a value of \ref I2S_Channel_Type */

    I2SDataFormat_TypeDef I2S_DataFormat;       /*!< Specifies the I2S Data format mode.
                                                     This parameter can be a value of \ref I2S_Format_Mode*/

    I2SWidth_TypeDef I2S_DataWidth;             /*!< Specifies the I2S Data width.
                                                     This parameter can be a value of \ref I2S_Data_Width */
#endif

#if I2S_SUPPORT_TRX_FIFO
    I2SFIFOSel_TypeDef I2S_TxFIFOSel;           /*!< Specifies the I2S FIFO.*/

    I2SFIFOSel_TypeDef I2S_RxFIFOSel;           /*!< Specifies the I2S FIFO.*/
#endif

    I2SDeviceMode_TypeDef I2S_DeviceMode;       /*!< Specifies the I2S device mode. */

    I2SChSeq_TypeDef I2S_RxChannelSequence;     /*!< Specifies the receiving channel seqence.
                                                     It is used for the I2S communication.*/

    I2SChSeq_TypeDef I2S_TxChannelSequence;     /*!< Specifies the transmission channel seqence.
                                                     It is used for the I2S communication.*/

    I2SBitSeq_TypeDef I2S_TxBitSequence;        /*!< Specifies the I2S Data bits sequences.*/

    I2SBitSeq_TypeDef I2S_RxBitSequence;        /*!< Specifies the I2S Data bits sequences.*/

    uint32_t I2S_TxWaterlevel;                  /*!< Specifies the dma watermark level in transmit mode.
                                                     This parameter must range from 1 to 63. */

    uint32_t I2S_RxWaterlevel;                  /*!< Specifies the dma watermark level in receive mode.
                                                     This parameter must range from 1 to 63. */

#if I2S_SUPPORT_MCLK_OUTPUT
    I2SMClkOutput_TypeDef I2S_MClockOutput;     /*!< Specifies the I2S MCLK output freqency.
                                                     This parameter can be a value of \ref I2S_MCLK_Output */
#endif
} I2S_InitTypeDef;

#if I2S_SUPPORT_TRX_FIFO
/**
 * \brief       I2S Data Sel
 *
 * \ingroup     I2S_Exported_Types
 */
typedef struct
{
    uint8_t tx_channel_map[4];
    uint8_t rx_fifo_map[4];
} I2S_DataSelTypeDef;
#endif

/** End of I2S_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup I2S_Exported_Constants I2S Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    I2S_Interrupt_Definition   I2S Interrupt Definition
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#if I2S_SUPPORT_INT_TX_VALID
#define I2S_INT_TX_VALID                            BIT7//(I2S_TX_IDLE_MSK)
#endif
#define I2S_INT_TX_IDLE                             BIT6//(I2S_TX_IDLE_MSK)
#define I2S_INT_RF_EMPTY                            BIT5//(I2S_RF_EMPTY_MSK)
#define I2S_INT_TF_EMPTY                            BIT4// (I2S_TF_EMPTY_MSK)
#define I2S_INT_RF_FULL                             BIT3// (I2S_RX_FULL_MSK)
#define I2S_INT_TF_FULL                             BIT2// (I2S_TX_FULL_MSK)
#define I2S_INT_RX_READY                            BIT1// (I2S_READY_TO_RX_MSK)
#define I2S_INT_TX_READY                            BIT0// (I2S_READY_TO_TX_MSK)

#define IS_I2S_INT_CONFIG(INT)          (((INT) == I2S_INT_TX_IDLE) || ((INT) == I2S_INT_RF_EMPTY) || \
                                         ((INT) == I2S_INT_TF_EMPTY) || ((INT) == I2S_INT_RF_FULL) || \
                                         ((INT) == I2S_INT_TF_FULL) || ((INT) == I2S_INT_RX_READY) || \
                                         ((INT) == I2S_INT_TX_READY) )

/** End of I2S_Interrupt_Definition
  * \}
  */

/**
 * \defgroup    I2S_Clear_Interrupt_Definition     I2S Clear Interrupt Definition
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#define I2S_CLEAR_INT_TX_VALID                            BIT14//(I2S_TX_IDLE_MSK)
#define I2S_CLEAR_INT_TX_IDLE                             BIT6//(I2S_TX_IDLE_MSK)
#define I2S_CLEAR_INT_RF_EMPTY                            BIT5//(I2S_RF_EMPTY_MSK)
#define I2S_CLEAR_INT_TF_EMPTY                            BIT4// (I2S_TF_EMPTY_MSK)
#define I2S_CLEAR_INT_RF_FULL                             BIT3// (I2S_RX_FULL_MSK)
#define I2S_CLEAR_INT_TF_FULL                             BIT2// (I2S_TX_FULL_MSK)
#define I2S_CLEAR_INT_RX_READY                            BIT1// (I2S_READY_TO_RX_MSK)
#define I2S_CLEAR_INT_TX_READY                            BIT0// (I2S_READY_TO_TX_MSK)

#define IS_I2S_CLEAR_INT(CLEAR)          (((CLEAR) == I2S_CLEAR_INT_RX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TX_READY) || \
                                          (CLEAR) == I2S_CLEAR_INT_RX_READY) || \
((CLEAR) == I2S_CLEAR_INT_TX_READY) )

/** End of I2S_Clear_Interrupt_Definition
  * \}
  */



/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup I2S_Exported_Functions I2S Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitializes the I2S peripheral registers to their default values.
 * \param   None.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     I2S_DeInit(I2S0);
 * }
 * \endcode
 */
void I2S_DeInit(I2S_TypeDef *I2Sx);

/**
 * \brief   Initializes the I2S peripheral according to the specified
 *          parameters in the I2S_InitStruct
 * \param[in] I2Sx: Selected I2S peripheral.
 * \param[in] I2S_InitStruct: Pointer to a I2S_InitTypeDef structure that
 *            contains the configuration information for the specified I2S peripheral
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLK_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_Channel_stereo;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_Init(I2S_TypeDef *I2Sx, I2S_InitTypeDef *I2S_InitStruct);

/**
 * \brief   Fills each I2S_InitStruct member with its default value.
 * \param[in] I2S_InitStruct: Pointer to an I2S_InitTypeDef structure which will be initialized.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLOCK_SRC_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_Channel_stereo;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct);
/**
 * \brief   Enable or disable the selected I2S mode.
 * \param[in] I2Sx: Selected I2S peripheral.
 * \param[in] mode: Selected I2S operation mode.
 *      This parameter can be the following values:
 *      \arg I2S_MODE_TX: Transmission mode.
 *      \arg I2S_MODE_RX: Receiving mode.
 * \param[in] NewState: New state of the operation mode.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLOCK_SRC_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_CHANNEL_STEREO;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S_NUM, &I2S_InitStruct);
 *     I2S_Cmd(I2S_NUM, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_Cmd(I2S_TypeDef *I2Sx, I2SMode_TypeDef I2S_Mode, FunctionalState NewState);

/**
 * \brief   Enable or disable the specified I2S interrupt source.
 * \param[in] I2S_INT: Specifies the I2S interrupt source to be enable or disable.
 *      This parameter can be the following values:
 *      \arg I2S_INT_TX_IDLE: Transmit idle interrupt source.
 *      \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt source.
 *      \arg I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt source.
 *      \arg I2S_INT_RF_FULL: Receive FIFO full interrupt source.
 *      \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt source.
 *      \arg I2S_INT_RX_READY: Ready to receive interrupt source.
 *      \arg I2S_INT_TX_READY: Ready to transmit interrupt source.
 * \param[in]  NewState: New state of the specified I2S interrupt.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_INTConfig(I2S0, I2S_INT_TF_EMPTY, ENABLE);
 * }
 * \endcode
 */
void I2S_INTConfig(I2S_TypeDef *I2Sx, uint32_t I2S_INT, FunctionalState newState);
/**
 * \brief   Get the specified I2S interrupt status.
 * \param[in] I2S_INT: the specified I2S interrupt.
 *      This parameter can be one of the following values:
 *      \arg I2S_INT_TX_IDLE: Transmit idle interrupt.
 *      \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt.
 *      \arg I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt.
 *      \arg I2S_INT_RF_FULL: Receive FIFO full interrupt.
 *      \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt.
 *      \arg I2S_INT_RX_READY: Ready to receive interrupt.
 *      \arg I2S_INT_TX_READY: Ready to transmit interrupt.
 * \retval The new state of I2S_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     ITStatus int_status = I2S_GetINTStatus(I2S0, I2S_INT_TF_EMPTY);
 * }
 * \endcode
 */
ITStatus I2S_GetINTStatus(I2S_TypeDef *I2Sx, uint32_t I2S_INT);

/**
 * \brief  Clear the I2S interrupt pending bit.
 * \param[in] I2S_CLEAR_INT: Specifies the interrupt pending bit to clear.
 *      This parameter can be any combination of the following values:
 *      \arg I2S_CLEAR_INT_RX_READY: Clear ready to receive interrupt.
 *      \arg I2S_CLEAR_INT_TX_READY: Clear ready to transmit interrupt.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_ClearINTPendingBit(I2S0, I2S_CLEAR_INT_RX_READY);
 * }
 * \endcode
 */
void I2S_ClearINTPendingBit(I2S_TypeDef *I2Sx, uint32_t I2S_CLEAR_INT);

/**
 * \brief   Transmits a data through the SPIx/I2Sx peripheral.
 * \param[in] I2Sx: To select the I2Sx peripheral, x can be 0 or 1.
 * \param[in] Data: Data to be transmitted.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SendData(I2S0, 0x02);
 * }
 * \endcode
 */
void I2S_SendData(I2S_TypeDef *I2Sx, uint32_t Data);


/**
 * \brief  Received data by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return Return the most recent received data.
 * \
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint32_t data = I2S_ReceiveData(I2S0);
 * }
 * \endcode
 */
uint32_t I2S_ReceiveFIFOData(I2S_TypeDef *I2Sx);

/**
 * \brief   Get transmit FIFO free length by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \retval  Return the transmit FIFO free length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t data_len = I2S_GetTxFIFOFreeLen(I2S0);
 * }
 * \endcode
 */
uint8_t I2S_GetTxFIFOFreeLen(I2S_TypeDef *I2Sx);

/**
 * \brief   Get receive FIFO data length by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  The data length of the receive FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t data_len = I2S_GetRxFIFOLen(I2S0);
 * }
 * \endcode
 */
uint8_t I2S_GetRxFIFOLen(I2S_TypeDef *I2Sx);

/**
 * \brief   Get the send error counter value by the I2Sx peripheral.
 * \param[in]  I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  The send error counter value .
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t conter = I2S_GetTxErrCnt(I2S0);
 * }
 * \endcode
 */
uint8_t I2S_GetTxErrCnt(I2S_TypeDef *I2Sx);

/**
 * \brief  Get the reception error counter value by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \retval  The reception error counter value .
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t conter = I2S_GetRxErrCnt(I2S0);
 * }
 * \endcode
 */
uint8_t I2S_GetRxErrCnt(I2S_TypeDef *I2Sx);

/**
 * \brief   Swap audio data bytes sequence which sent by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the bytes sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapBytesForSend(I2S0, ENABLE);
 * }
 * \endcode
 */
void I2S_SwapBytesForSend(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * \brief   Swap audio data bytes sequence which read by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the bytes sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapBytesForRead(I2S0, ENABLE);
 * }
 * \endcode
 */
void I2S_SwapBytesForRead(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * \brief  Swap audio channel data which sent by the I2Sx peripheral..
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the left and right channel data sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapLRChDataForSend(I2S0, ENABLE);
 * }
 * \endcode
 */
void I2S_SwapLRChDataForSend(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * \brief   Swap audio channel data which read by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the left and right channel data sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapLRChDataForRead(I2S0, ENABLE);
 * }
 * \endcode
 */
void I2S_SwapLRChDataForRead(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * \brief   MCLK output selection which can be from I2S0 or I2S1.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of MCLK output.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_MCLKOutputSelectCmd(I2S0);
 * }
 * \endcode
 */
void I2S_MCLKOutputSelectCmd(I2S_TypeDef *I2Sx);

/**
 * \brief   I2S0 communication selection which can be from intrnal codec or external codec.
 * \param[in] NewState: new state of I2S0 communication selection.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_WithExtCodecCmd(ENABLE);
 * }
 * \endcode
 */
void I2S_WithExtCodecCmd(I2S_TypeDef *I2Sx, FunctionalState NewState);


/**
 * \brief   Config BClk clock.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] I2S_BClockMi: Mi parameter.
 * \param[in] I2S_BClockNi: Ni parameter.
 * \return  Execution status.
 * \retval  SET: Success.
 * \retval  RESET: Failure.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_UpdateBClk(I2S0, 0x271, 0x10);
 * }
 * \endcode
 */
void I2S_UpdateBClk(I2S_TypeDef *I2Sx, uint32_t dir, uint16_t I2S_BClockMi,
                    uint16_t I2S_BClockNi);
#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GetTxBClkStatus(I2S0);
 * }
 * \endcode
 */
FlagStatus I2S_GetTxBClkStatus(I2S_TypeDef *I2Sx);

/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GeRxBClkStatus(I2S0);
 * }
 * \endcode
 */
FlagStatus I2S_GetRxBClkStatus(I2S_TypeDef *I2Sx);

#else
/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GeRxBClkStatus(I2S0);
 * }
 * \endcode
 */
FlagStatus I2S_GetBClkStatus(I2S_TypeDef *I2Sx);


#if (I2S_SUPPORT_AUTO_CLOCK == 1)
void I2S_ClockAutoModeCmd(I2S_TypeDef *I2Sx, FunctionalState Newstate);
#endif


#endif
/** End of I2S_Exported_Functions
  * \}
  */

/** End of I2S
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_I2S_H */




