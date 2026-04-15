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
#include "rtl_i2s_def.h"

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

/**
 * \defgroup    I2S_Clock_Source I2S Clock Source
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CLK_40M,      //!< I2S Clock Source is 40MHz.
#if I2S_SUPPORT_PLL_CLK
    I2S_CLK_PLL2,     //!< I2S Clock Source is PLL2.
#else
    I2S_CLK_128fs,    //!< I2S Clock Source is 128fs.
    I2S_CLK_256fs,    //!< I2S Clock Source is 256fs.
#endif
} I2SSrcClk_TypeDef;

#if I2S_SUPPORT_PLL_CLK
#define IS_I2S_CLK_SOURCE(CLK) (((CLK) == I2S_CLK_40M) || \
                                ((CLK) == I2S_CLK_PLL2))) //!< Check if the input parameter is valid.
#else
#define IS_I2S_CLK_SOURCE(CLK) (((CLK) == I2S_CLK_40M) || \
                                ((CLK) == I2S_CLK_128fs) || \
                                ((CLK) == I2S_CLK_256fs)) //!< Check if the input parameter is valid.
#endif
/** End of I2S_Clock_Source
  * \}
  */

/**
 * \defgroup    I2S_Format_Mode I2S Format Mode
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_Mode,                   //!< I2S mode.
    Left_Justified_Mode,        //!< Left justified mode.
    PCM_Mode_A,                 //!< PCM mode A.
    PCM_Mode_B,                 //!< PCM mode B.
} I2SDataFormat_TypeDef;

#define IS_I2S_DATA_FORMAT(FORMAT)      (((FORMAT) == I2S_Mode) || ((FORMAT) == Left_Justified_Mode) || \
                                         ((FORMAT) == PCM_Mode_A) || ((FORMAT) == PCM_Mode_B)) //!< Check if the input parameter is valid.

/** End of I2S_Format_Mode
  * \}
  */

/**
 * \defgroup    I2S_Channel_Type I2S Channel Type
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_Channel_stereo,      //!< The channel format of the I2S is stereo.
    I2S_Channel_Mono,        //!< The channel format of the I2S is mono.
} I2SChannelType_TypeDef;

#define IS_I2S_CHANNEL_TYPE(TYPE)       (((TYPE) == I2S_Channel_Mono) || ((TYPE) == I2S_Channel_stereo)) //!< Check if the input parameter is valid.

/** End of I2S_Channel_Type
  * \}
  */

/**
 * \defgroup    I2S_Data_Width I2S Data Width
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_Width_16Bits = 0x00,      //!< The I2S data width is 16 bits.
    I2S_Width_24Bits = 0x02,      //!< The I2S data width is 24 bits.
    I2S_Width_8Bits = 0x03,       //!< The I2S data width is 8 bits.
#if I2S_SUPPORT_DATE_WIDTH_32BIT
    I2S_Width_20Bits = 0x01,      //!< The I2S data width is 20 bits.
    I2S_Width_32Bits = 0x04,      //!< The I2S data width is 32 bits.
#endif
} I2SDataWidth_TypeDef;

#define IS_I2S_DATA_WIDTH(WIDTH)        (((WIDTH) == I2S_Width_16Bits) || \
                                         ((WIDTH) == I2S_Width_8Bits)) || \
((WIDTH) == I2S_Width_24Bits) || \
((WIDTH) == I2S_Width_20Bits) || \
((WIDTH) == I2S_Width_32Bits)) //!< Check if the input parameter is valid.


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
    I2S_DeviceMode_Master,      //!< I2S master mode.
    I2S_DeviceMode_Slave,       //!< I2S slave mode.
} I2SDeviceMode_TypeDef;

#define IS_I2S_DEVICE_MODE(DEVICE)      (((DEVICE) == I2S_DeviceMode_Master) || ((DEVICE) == I2S_DeviceMode_Slave)) //!< Check if the input parameter is valid.

/** End of I2S_Device_Mode
  * \}
  */

/**
 * \defgroup    I2S_Channel_Sequence I2S Channel Sequence
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CH_L_R,      //!< I2S channel sequence from left to right.
    I2S_CH_R_L,      //!< I2S channel sequence from right to left.
    I2S_CH_L_L,      //!< I2S channel sequence from left to left.
    I2S_CH_R_R,      //!< I2S channel sequence from right to right.
} I2SCHSeq_TypeDef;

#define IS_I2S_CH_SEQ(SEQ)       (((SEQ) == I2S_CH_L_R) || ((SEQ) == I2S_CH_R_L) || \
                                  ((SEQ) == I2S_CH_L_L) || ((SEQ) == I2S_CH_R_R)) //!< Check if the input parameter is valid.

/** End of I2S_Transmission_Channel_Sequence
  * \}
  */

/**
 * \defgroup    I2S_Bit_Sequence I2S Bit Sequence
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_MSB_First,      //!< I2S Bit_Sequence MSB first.
    I2S_LSB_First,      //!< I2S Bit_Sequence LSB first.
} I2SBitSeq_TypeDef;

#define IS_I2S_BIT_SEQ(SEQ)      (((SEQ) == I2S_MSB_First) || ((SEQ) == I2S_LSB_First)) //!< Check if the input parameter is valid.

/** End of I2S_Bit_Sequence
  * \}
  */
#if I2S_SUPPORT_TRX_FIFO
/**
 * \defgroup    I2S_FIFO_USE I2S FIFO USE
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum t_sport_fifo_use
{
    I2S_FIFO_USE_0_REG_0 = BIT0,      //!< Enable first two channel of I2S FIFO.
    I2S_FIFO_USE_0_REG_1 = BIT1,      //!< Enable last two channel of I2S FIFO.
} I2SFifoUse_TypeDef;

/** End of I2S_FIFO_USE
  * \}
  */
#endif

#if I2S_SUPPORT_MCLK_OUTPUT_SEL
/**
 * \defgroup    I2S_MCLK_Output I2S MCLK Output
 * \{
 * \ingroup     I2S_Exported_Constants
 */

typedef enum
{
    I2S_MCLK_128fs,    //!< I2S MCLK output 128fs.
    I2S_MCLK_256fs,    //!< I2S MCLK output 256fs.
} I2SMClkSel;

#define IS_I2S_MCLK_OUTPUT_TYPE(TYPE)       (((TYPE) == I2S_MCLK_128fs) || ((TYPE) == I2S_MCLK_256fs)) //!< Check if the input parameter is valid.

/** End of I2S_MCLK_Output
  * \}
  */
#endif

/**
 * \defgroup    I2S_Mode I2S Mode
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#define I2S_MODE_TX                                 (0x0)     //!< I2S TX mode.
#define I2S_MODE_RX                                 (0x1)     //!< I2S RX mode.

#define IS_I2S_MODE(MODE)      (((MODE) == I2S_MODE_TX) || ((MODE) == I2S_MODE_RX)) //!< Check if the input parameter is valid.

/** End of I2S_Mode
  * \}
  */

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
    I2SSrcClk_TypeDef I2S_ClockSource;        /*!< Specify the I2S clock source.
                                                   This parameter can be a value of \ref I2S_Clock_Source */
#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL


    uint32_t I2S_TxBClockMi;                  /*!< Specify the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                   This parameter must range from 1 to 0xffff. */

    uint32_t I2S_TxBClockNi;                  /*!< Specify the BLCK clock speed.
                                                   This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_TxBClockDiv;                 /*!< Specify the BLCK clock divider. The actual BCLK clock divider = I2S_TxBClockDiv + 1.
                                                   This parameter must range from 1 to 0xFF. */

    uint32_t I2S_RxBClockMi;                  /*!< Specify the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                   This parameter must range from 1 to 0xffff. */

    uint32_t I2S_RxBClockNi;                  /*!< Specify the BLCK clock speed.
                                                   This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_RxBClockDiv;                 /*!< Specify the BLCK clock divider. The actual BCLK clock divider = I2S_RxBClockDiv + 1.
                                                   This parameter must range from 1 to 0xFF. */

    I2SChannelType_TypeDef
    I2S_TxChannelType;                        /*!< Specify the channel type used for the I2S communication.
                                                   This parameter can be a value of \ref I2S_Channel_Type. */
    I2SChannelType_TypeDef
    I2S_RxChannelType;                        /*!< Specify the channel type used for the I2S communication.
                                                   This parameter can be a value of \ref I2S_Channel_Type. */

    I2SDataFormat_TypeDef I2S_TxDataFormat;   /*!< Specify the I2S Data format mode.
                                                   This parameter can be a value of \ref I2S_Format_Mode. */

    I2SDataFormat_TypeDef I2S_RxDataFormat;   /*!< Specify the I2S Data format mode.
                                                   This parameter can be a value of \ref I2S_Format_Mode. */

    I2SDataWidth_TypeDef I2S_TxDataWidth;     /*!< Specify the I2S Tx Data width.
                                                   This parameter can be a value of \ref I2S_Data_Width. */

    I2SDataWidth_TypeDef I2S_RxDataWidth;     /*!< Specify the I2S Rx Data width.
                                                   This parameter can be a value of \ref I2S_Data_Width. */

    I2SDataWidth_TypeDef I2S_TxChannelWidth;  /*!< Specify the I2S Tx channel width.
                                                   This parameter can be a value of \ref I2S_Data_Width. */

    I2SDataWidth_TypeDef I2S_RxChannelWidth;  /*!< Specify the I2S Rx channel width.
                                                   This parameter can be a value of \ref I2S_Data_Width. */
#else
    uint32_t I2S_BClockMi;                    /*!< Specify the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                   This parameter must range from 1 to 0xffff. */

    uint32_t I2S_BClockNi;                    /*!< Specify the BLCK clock speed.
                                                   This parameter must range from 1 to 0x7FFF. */
    I2SChannelType_TypeDef
    I2S_ChannelType;                          /*!< Specify the channel type used for the I2S communication.
                                                   This parameter can be a value of \ref I2S_Channel_Type. */

    I2SDataFormat_TypeDef I2S_DataFormat;     /*!< Specify the I2S Data format mode.
                                                   This parameter can be a value of \ref I2S_Format_Mode. */

    I2SDataWidth_TypeDef I2S_DataWidth;       /*!< Specify the I2S Data width.
                                                   This parameter can be a value of \ref I2S_Data_Width. */
#endif

#if I2S_SUPPORT_TRX_FIFO
    I2SFifoUse_TypeDef I2S_TxFifoUsed;        /*!< Specify the I2S Tx FIFO.
                                                   This parameter can be a value of \ref I2S_FIFO_USE. */

    I2SFifoUse_TypeDef I2S_RxFifoUsed;        /*!< Specify the I2S Rx FIFO.
                                                   This parameter can be a value of \ref I2S_FIFO_USE. */
#endif
    I2SDeviceMode_TypeDef I2S_DeviceMode;     /*!< Specify the I2S device mode.
                                                   This parameter can be a value of \ref I2S_Device_Mode. */

    I2SCHSeq_TypeDef
    I2S_RxChSequence;        /*!< Specify the Rx channel seqence used for the I2S communication.
                                  This parameter can be a value of \ref I2S_Channel_Sequence. */

    I2SCHSeq_TypeDef
    I2S_TxChSequence;        /*!< Specify the Tx channel seqence used for the I2S communication.
                                  This parameter can be a value of \ref I2S_Channel_Sequence. */

    I2SBitSeq_TypeDef I2S_TxBitSequence;      /*!< Specify the I2S Tx Data bits sequences.
                                                   This parameter can be a value of \ref I2S_Bit_Sequence. */

    I2SBitSeq_TypeDef I2S_RxBitSequence;      /*!< Specify the I2S Rx Data bits sequences.
                                                   This parameter can be a value of \ref I2S_Bit_Sequence. */

    uint32_t I2S_TxWaterlevel;                /*!< Specify the dma watermark level in Tx mode.
                                                   This parameter must range from 1 to 63. */

    uint32_t I2S_RxWaterlevel;                /*!< Specify the dma watermark level in Rx mode.
                                                   This parameter must range from 1 to 63. */
#if I2S_SUPPORT_MCLK_OUTPUT_SEL
    uint32_t I2S_MCLKOutput;                  /*!< Specify the I2S MCLK output freqency.
                                                   This parameter can be a value of \ref I2S_MCLK_Output. */
#endif

} I2S_InitTypeDef;

#if I2S_SUPPORT_TRX_FIFO
/**
 * \brief       I2S Data Select
 *
 * \ingroup     I2S_Exported_Types
 */
typedef struct
{
    uint8_t tx_channel_map[4];     //!< I2S Tx channel map.
    uint8_t rx_fifo_map[4];        //!< I2S Rx fifo map.
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
 * \defgroup    I2S_All_Periph   I2S All Periph
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#define IS_I2S_ALL_PERIPH(PERIPH) (((PERIPH) == I2S0) || \
                                   ((PERIPH) == I2S1))     //!< I2S all peripheral.

/** End of I2S_All_Periph
  * \}
  */

/**
 * \defgroup    I2S_Interrupt_Definition   I2S Interrupt Definition
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#if I2S_SUPPORT_INT_TX_VALID
#define I2S_INT_TX_VALID                           BIT7  //!< The I2S interrupt for TX valid.
#endif
#define I2S_INT_TX_IDLE                            BIT6  //!< The I2S interrupt for TX is working, but FIFO_0 is empty.
#define I2S_INT_RF_EMPTY                           BIT5  //!< The I2S interrupt for RX FIFO_0 is empty (MIC path).
#define I2S_INT_TF_EMPTY                           BIT4  //!< The I2S interrupt for TX FIFO_0 is empty (SPK path).
#define I2S_INT_RF_FULL                            BIT3  //!< The I2S interrupt for RX FIFO_0 is full (MIC path).
#define I2S_INT_TF_FULL                            BIT2  //!< The I2S interrupt for TX FIFO_0 is full (SPK path).
#define I2S_INT_RX_READY                           BIT1  //!< The I2S interrupt is ready to receive data (MIC path).
#define I2S_INT_TX_READY                           BIT0  //!< The I2S interrupt is ready to send data out (SPK path).

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
#define I2S_CLEAR_INT_TX_VALID                      BIT14 //!< Clear the I2S interrupt for TX valid.
#define I2S_CLEAR_INT_TX_IDLE                       BIT6  //!< Clear the I2S interrupt for TX is working, but FIFO_0 is empty.
#define I2S_CLEAR_INT_RF_EMPTY                      BIT5  //!< Clear the I2S interrupt for RX FIFO_0 is empty (MIC path).
#define I2S_CLEAR_INT_TF_EMPTY                      BIT4  //!< Clear the I2S interrupt for TX FIFO_0 is empty (SPK path).
#define I2S_CLEAR_INT_RF_FULL                       BIT3  //!< Clear the I2S interrupt for RX FIFO_0 is full (MIC path).
#define I2S_CLEAR_INT_TF_FULL                       BIT2  //!< Clear the I2S interrupt for TX FIFO_0 is full (SPK path).
#define I2S_CLEAR_INT_RX_READY                      BIT1  //!< Clear the I2S interrupt is ready to receive data (MIC path).
#define I2S_CLEAR_INT_TX_READY                      BIT0  //!< Clear the I2S interrupt is ready to send data out (SPK path).

#define IS_I2S_CLEAR_INT(CLEAR)          (((CLEAR) == I2S_CLEAR_INT_RX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_RX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TX_READY))

/** End of I2S_Clear_Interrupt_Definition
  * \}
  */

/**
 * \defgroup    I2S_TX_Selection I2S TX Selection
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_TX_FIFO_0_REG_0_L,                        //!< I2S left channel FIFO data storage selects the REG_0 register.
    I2S_TX_FIFO_0_REG_0_R,                        //!< I2S right channel FIFO data storage selects the REG_0 register.
    I2S_TX_FIFO_0_REG_1_L,                        //!< I2S left channel FIFO data storage selects the REG_1 register.
    I2S_TX_FIFO_0_REG_1_R,                        //!< I2S right channel FIFO data storage selects the REG_1 register.
    I2S_TX_SEL_MAX,                               //!< Maximum I2S TX selection.
} I2STxSel_TypeDef;

/** End of I2S_TX_Selection
  * \}
  */

/**
 * \defgroup    I2S_RX_Channel_Selection I2S RX Channel Selection
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_RX_CHANNEL_0,                             //!< I2S RX channel 0.
    I2S_RX_CHANNEL_1,                             //!< I2S RX channel 1.
    I2S_RX_CHANNEL_2,                             //!< I2S RX channel 2.
    I2S_RX_CHANNEL_3,                             //!< I2S RX channel 3.
    I2S_RX_SEL_MAX,                               //!< Maximum I2S RX channel selection.
} I2SRxSel_TypeDef;

/** End of I2S_RX_Channel_Selection
  * \}
  */

/** End of I2S_Exported_Constants
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
 * \brief   Deinitialize the I2S peripheral registers to their default values.
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
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
 * \brief   Initialize the I2S peripheral according to the specified parameters in the I2S_InitStruct.
 *
 * \param[in] I2Sx            Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] I2S_InitStruct  Pointer to a I2S_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_PeriphClockCmd(APB_I2S, APB_I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLK_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DeviceMode_Master;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_Channel_stereo;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_Width_16Bits;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_Mode;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_Init(I2S_TypeDef *I2Sx, I2S_InitTypeDef *I2S_InitStruct);

/**
 * \brief   Fill each I2S_InitStruct member with its default value.
 *
 * \note The default settings for the I2S_InitStruct member are shown in the following table:
 *       | I2S_InitStruct member        | Default value                        |
 *       |:----------------------------:|:------------------------------------:|
 *       | I2S_ClockSource              | \ref I2S_CLK_40M                     |
 *       | I2S_Scheme                   | \ref I2S_SCHEME_SEPARATE             |
 *       | I2S_TxBClockMi               | 0x271                                |
 *       | I2S_TxBClockNi               | 0x10                                 |
 *       | I2S_TxBClockDiv              | 0x3F                                 |
 *       | I2S_RxBClockMi               | 0x271                                |
 *       | I2S_RxBClockNi               | 0x10                                 |
 *       | I2S_RxBClockDiv              | 0x3F                                 |
 *       | I2S_DeviceMode               | \ref I2S_DeviceMode_Master           |
 *       | I2S_TxChannelType            | \ref I2S_Channel_Mono                |
 *       | I2S_RxChannelType            | \ref I2S_Channel_Mono                |
 *       | I2S_TxChSequence             | \ref I2S_CH_L_R                      |
 *       | I2S_RxChSequence             | \ref I2S_CH_L_R                      |
 *       | I2S_TxDataFormat             | \ref I2S_Mode                        |
 *       | I2S_RxDataFormat             | \ref I2S_Mode                        |
 *       | I2S_TxBitSequence            | \ref I2S_MSB_First                   |
 *       | I2S_RxBitSequence            | \ref I2S_MSB_First                   |
 *       | I2S_TxDataWidth              | \ref I2S_Width_16Bits                |
 *       | I2S_RxDataWidth              | \ref I2S_Width_16Bits                |
 *       | I2S_TxChannelWidth           | \ref I2S_Width_32Bits                |
 *       | I2S_RxChannelWidth           | \ref I2S_Width_32Bits                |
 *       | I2S_TxFifoUsed               | \ref I2S_FIFO_USE_0_REG_0            |
 *       | I2S_RxFifoUsed               | \ref I2S_FIFO_USE_0_REG_0            |
 *       | I2S_TxWaterlevel             | 16                                   |
 *       | I2S_RxWaterlevel             | 16                                   |
 *       | I2S_BClockFixEn              | DISABLE                              |
 *
 * \param[in] I2S_InitStruct  Pointer to an I2S_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_PeriphClockCmd(APB_I2S, APB_I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLK_40M;
 *     I2S_InitStruct.I2S_TxBClockMi         = 0x271;
 *     I2S_InitStruct.I2S_TxBClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DeviceMode_Master;
 *     I2S_InitStruct.I2S_TxChannelType      = I2S_Channel_stereo;
 *     I2S_InitStruct.I2S_TxDataWidth        = I2S_Width_16Bits;
 *     I2S_InitStruct.I2S_TxDataFormat       = I2S_Mode;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct);
/**
 * \brief   Enable or disable the selected I2S mode.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] mode      Selected I2S operation mode.
 *                      This parameter can be the following values:
 *                      \arg I2S_MODE_TX: Transmission mode.
 *                      \arg I2S_MODE_RX: Receiving mode.
 * \param[in] NewState  New state of the operation mode.
 *                      - ENABLE: Enable the specified mode of I2S.
 *                      - DISABLE: Disable the specified mode of I2S.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_PeriphClockCmd(APB_I2S, APB_I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLK_40M;
 *     I2S_InitStruct.I2S_TxBClockMi         = 0x271;
 *     I2S_InitStruct.I2S_TxBClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DeviceMode_Master;
 *     I2S_InitStruct.I2S_TxChannelType      = I2S_Channel_stereo;
 *     I2S_InitStruct.I2S_TxDataWidth        = I2S_Width_16Bits;
 *     I2S_InitStruct.I2S_TxDataFormat       = I2S_Mode;
 *     I2S_InitStruct.I2S_DMACmd           = I2S_DMA_DISABLE;
 *     I2S_Init(I2S_NUM, &I2S_InitStruct);
 *     I2S_Cmd(I2S_NUM, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_Cmd(I2S_TypeDef *I2Sx, uint32_t mode, FunctionalState NewState);

/**
 * \brief   Enable or disable the specified I2S interrupt source.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] I2S_INT   Specify the specified interrupt of I2S.
 *                      This parameter can be the following values, refer to \ref I2S_Interrupt_Definition.
 *                      \arg I2S_INT_TX_IDLE: Transmit idle interrupt source.
 *                      \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt source.
 *                      \arg I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt source.
 *                      \arg I2S_INT_RF_FULL: Receive FIFO full interrupt source.
 *                      \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt source.
 *                      \arg I2S_INT_RX_READY: Ready to receive interrupt source.
 *                      \arg I2S_INT_TX_READY: Ready to transmit interrupt source.
 * \param[in] newState  New state of the specified I2S interrupt.
 *                      - ENABLE: Enable the specified interrupt of I2S.
 *                      - DISABLE: Disable the specified interrupt of I2S.
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
 *
 * \param[in] I2Sx     Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] I2S_INT  Specify the specified interrupt of I2S.
 *                     This parameter can be one of the following values, refer to \ref I2S_Interrupt_Definition.
 *                     \arg I2S_INT_TX_IDLE: Transmit idle interrupt.
 *                     \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt.
 *                     \arg I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt.
 *                     \arg I2S_INT_RF_FULL: Receive FIFO full interrupt.
 *                     \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt.
 *                     \arg I2S_INT_RX_READY: Ready to receive interrupt.
 *                     \arg I2S_INT_TX_READY: Ready to transmit interrupt.
 *
 * \return The status of I2S specified interrupt.
 *         - SET: The interrupt status of I2S is set.
 *         - RESET: The interrupt status of I2S has not been set.
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
 *
 * \param[in] I2Sx           Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] I2S_CLEAR_INT  Specify the interrupt pending bit to clear.
 *                           This parameter can be any combination of the following values:
 *                           - I2S_CLEAR_INT_RX_READY: Clear ready to receive interrupt.
 *                           - I2S_CLEAR_INT_TX_READY: Clear ready to transmit interrupt.
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
 * \brief   Transmits a data through the I2Sx peripheral.
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] Data  Data to be transmitted.
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
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return Return the most recent received data.
 *
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
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  The free length of transmit FIFO .
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
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
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
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  The send error counter value.
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
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  The reception error counter value.
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
 * \brief   Swap audio data bytes sequence that is sent by the I2Sx peripheral.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of the bytes sequence.
 *                      - ENABLE: Enable swapping of the sent audio data byte sequence.
 *                      - DISABLE: Disable swapping of the sent audio data byte sequence.
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
 * \brief   Swap audio data bytes sequence that is read by the I2Sx peripheral.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of the bytes sequence.
 *                      - ENABLE: Enable the swapping of the audio data byte sequence that is read.
 *                      - DISABLE: Disable the swapping of the audio data byte sequence that is read.
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
 * \brief  Swap audio channel data that is sent by the I2Sx peripheral.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of the left and right channel data sequence.
 *                      - ENABLE: Enable swapping of the sent audio channel data sequence.
 *                      - DISABLE: Disable swapping of the sent audio channel data sequence.
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
 * \brief   Swap audio channel data that is read by the I2Sx peripheral.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of the left and right channel data sequence.
 *                      - ENABLE: Enable the swapping of the audio channel data sequence that is read.
 *                      - DISABLE: Disable the swapping of the audio channel data sequence that is read.
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
 * \brief   Enable or disable the MCLK output selection.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of MCLK output.
 *                      - ENABLE: Enable the MCLK output selection.
 *                      - DISABLE: Disable the MCLK output selection.
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
void I2S_MCLKOutputSelectCmd(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * \brief   I2S0 communication selection which can be from internal codec or external codec.
 *
 * \param[in] I2Sx      Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] NewState  New state of I2S0 communication selection.
 *                      - ENABLE: I2S communication selects the internal codec.
 *                      - DISABLE: I2S communication selects the external codec.
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
 * \brief   Configure BCLK clock.
 *
 * \param[in] I2Sx          Selected I2S peripheral. Refer to \ref I2S_Declaration.
 * \param[in] dir           Selected I2S operation mode.
 *                          This parameter can be the following values:
 *                          \arg I2S_MODE_TX: Transmission mode.
 *                          \arg I2S_MODE_RX: Receiving mode.
 * \param[in] I2S_BClockMi  Mi parameter.
 * \param[in] I2S_BClockNi  Ni parameter.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_UpdateBClk(I2S0, 0x271, 0x10);
 * }
 * \endcode
 */
void I2S_UpdateBClk(I2S_TypeDef *I2Sx, uint32_t dir, uint16_t I2S_BClockMi,
                    uint16_t I2S_BClockNi);

#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
 * \brief   Get Tx BCLK clock status.
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  Execution status.
 *          - SET: BLCK is updating.
 *          - RESET: BLCK update is done.
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
 * \brief   Get Rx BCLK clock status.
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  Execution status.
 *          - SET: BLCK is updating.
 *          - RESET: BLCK update is done.
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
 * \brief   Get BCLK clock status.
 *
 * \param[in] I2Sx  Selected I2S peripheral. Refer to \ref I2S_Declaration.
 *
 * \return  Execution status.
 *          - SET: BLCK is updating.
 *          - RESET: BLCK update is done.
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



