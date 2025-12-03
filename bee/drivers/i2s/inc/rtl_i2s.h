/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_i2s.h
* \brief    The header file of the peripheral I2S driver.
* \details  This file provides all I2S firmware functions.
* \author   echo gao
* \date     2024-07-24
* \version  v1.0
* *******************************************************************************************************
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
#include "i2s/src/rtl87x2g/rtl_i2s_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "i2s/src/rtl87x2j/rtl_i2s_def.h"
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
                                ((CLK) == I2S_CLK_PLL2)))
#else
#define IS_I2S_CLK_SOURCE(CLK) (((CLK) == I2S_CLK_40M) || \
                                ((CLK) == I2S_CLK_128fs) || \
                                ((CLK) == I2S_CLK_256fs))
#endif
/** End of I2S_Clock_Source
  * \}
  */

#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
 * \defgroup    I2S_Scheme I2S Scheme
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_SCHEME_SEPARATE,       //!< I2S Scheme Separate.
    I2S_SCHEME_DEPENDENT,      //!< I2S Scheme Dependent.
} I2SScheme_TypeDef;

/** End of I2S_Scheme
  * \}
  */
#endif

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
                                         ((FORMAT) == PCM_Mode_A) || ((FORMAT) == PCM_Mode_B))

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
    I2S_Channel_stereo,      //!< The channel format of the MIC path is stereo.
    I2S_Channel_Mono,        //!< The channel format of the MIC path is mono.
} I2SChannelType_TypeDef;

#define IS_I2S_CHANNEL_TYPE(TYPE)       (((TYPE) == I2S_Channel_Mono) || ((TYPE) == I2S_Channel_stereo))

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
((WIDTH) == I2S_Width_32Bits))


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

#define IS_I2S_DEVICE_MODE(DEVICE)      (((DEVICE) == I2S_DeviceMode_Master) || ((DEVICE) == I2S_DeviceMode_Slave))

/** End of I2S_Device_Mode
  * \}
  */

/**
 * \defgroup    I2S_Transmission_Channel_Sequence I2S Transmission Channel Sequence
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CH_L_R,      //!< I2S transmission channel sequence from left to right.
    I2S_CH_R_L,      //!< I2S transmission channel sequence from right to left.
    I2S_CH_L_L,      //!< I2S transmission channel sequence from left to left.
    I2S_CH_R_R,      //!< I2S transmission channel sequence from right to right.
} I2SCHSeq_TypeDef;

#define IS_I2S_CH_SEQ(SEQ)       (((SEQ) == I2S_CH_L_R) || ((SEQ) == I2S_CH_R_L) || \
                                  ((SEQ) == I2S_CH_L_L) || ((SEQ) == I2S_CH_R_R))

/** End of I2S_Transmission_Channel_Sequence
  * \}
  */

/**
 * \defgroup    I2S_Tx_Bit_Sequence I2S Tx Bit Sequence
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_MSB_First,      //!< Set MSB first.
    I2S_LSB_First,      //!< Set LSB first.
} I2SBitSeq_TypeDef;

#define IS_I2S_BIT_SEQ(SEQ)      (((SEQ) == I2S_MSB_First) || ((SEQ) == I2S_LSB_First))

/** End of I2S_Tx_Bit_Sequence
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
    I2S_FIFO_USE_0_REG_0 = BIT0,      //!< Enable first two channel of RX_FIFO_0 or TX_FIFO_0.
    I2S_FIFO_USE_0_REG_1 = BIT1,      //!< Enable last two channel of RX_FIFO_0 or TX_FIFO_0.
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
    I2S_MCLK_128fs,
    I2S_MCLK_256fs,
} I2SMClkSel;
/*
 * \}
 */

#define IS_I2S_MCLK_OUTPUT_TYPE(TYPE)       (((TYPE) == I2S_MCLK_128fs) || ((TYPE) == I2S_MCLK_256fs))

#endif

/**
 * \defgroup    I2S_ERR_CLR I2S ERR CLR
 * \{
 * \ingroup     I2S_Exported_Constants
 */
/*  I2S_CLR_RX_ERR_CNT. */
#define I2S_CLR_RX_ERR_CNT_MSK        (0x1 << 13)               //!< clear RX error counter.
#define I2S_CLR_RX_ERR_CNT_CLR        (~I2S_CLR_RX_ERR_CNT_MSK) //!< clear RX error counter.
/* I2S_CLR_TX_ERR_CNT. */
#define I2S_CLR_TX_ERR_CNT_MSK        (0x1 << 12)               //!< clear TX error counter.
#define I2S_CLR_TX_ERR_CNT_CLR        (~I2S_CLR_TX_ERR_CNT_MSK) //!< clear TX error counter.

#define I2S_RX_FIFO_DEPTH_CNT_0_POS   (8)                       //!< RX FIFO_0 depth counter status.
#define I2S_RX_ERR_CNT_POS            (15)                      //!< TX error counter status.
#define I2S_MI_NI_UPDATE_MSK          ((uint32_t)0x1 << 31)     //!< I2S TX needs to update mi and ni to obtain the new clock rate.

#define I2S_FRAME_SYNC_OFFSET_DEFAULT (0x81)                    //!< Synchronize the configuration of TX and RX.

/** End of I2S_ERR_CLR
  * \}
  */

/**
 * \defgroup    I2S_Mode I2S Mode
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#define I2S_MODE_TX                                 (0x0)     //!< I2S TX mode.
#define I2S_MODE_RX                                 (0x1)     //!< I2S RX mode.

#define IS_I2S_MODE(MODE)      (((MODE) == I2S_MODE_TX) || ((MODE) == I2S_MODE_RX))

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
    I2SScheme_TypeDef I2S_Scheme;             /*!< Specify the I2S Scheme.
                                                   This parameter can be a value of \ref I2S_Scheme */

    uint32_t I2S_TxBClockMi;                  /*!< Specify the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                   This parameter must range from 1 to 0xffff. */

    uint32_t I2S_TxBClockNi;                  /*!< Specify the BLCK clock speed.
                                                   This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_TxBClockDiv;                 /*!< Specify the BLCK clock divider.
                                                   This parameter must range from 1 to 0xFF. */

    uint32_t I2S_RxBClockMi;                  /*!< Specify the BLCK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                   This parameter must range from 1 to 0xffff. */

    uint32_t I2S_RxBClockNi;                  /*!< Specify the BLCK clock speed.
                                                   This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_RxBClockDiv;                 /*!< Specify the BLCK clock divider.
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
    FunctionalState
    I2S_BClockFixEn;                          /*!< Specify the I2S BCLK fix. If ENABLE, BCLK is fixed as 40M/4.
                                                   This parameter can be a value of DISABLE or ENABLE. */
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
    I2SFifoUse_TypeDef I2S_TxFifoUsed;        /*!< Specify the I2S TX FIFO.
                                                   This parameter can be a value of \ref I2S_FIFO_USE. */

    I2SFifoUse_TypeDef I2S_RxFifoUsed;        /*!< Specify the I2S RX FIFO.
                                                   This parameter can be a value of \ref I2S_FIFO_USE. */
#endif
    I2SDeviceMode_TypeDef I2S_DeviceMode;     /*!< Specify the I2S device mode.
                                                   This parameter can be a value of \ref I2S_Device_Mode. */

    I2SCHSeq_TypeDef
    I2S_RxChSequence;        /*!< Specify the receiving channel seqence used for the I2S communication.
                                  This parameter can be a value of \ref I2S_Transmission_Channel_Sequence. */

    I2SCHSeq_TypeDef
    I2S_TxChSequence;        /*!< Specify the transmission channel seqence used for the I2S communication.
                                  This parameter can be a value of \ref I2S_Transmission_Channel_Sequence. */

    I2SBitSeq_TypeDef I2S_TxBitSequence;      /*!< Specify the I2S TX Data bits sequences.
                                                   This parameter can be a value of \ref I2S_Tx_Bit_Sequence. */

    I2SBitSeq_TypeDef I2S_RxBitSequence;      /*!< Specify the I2S RX Data bits sequences.
                                                   This parameter can be a value of \ref I2S_Tx_Bit_Sequence. */

    uint32_t I2S_TxWaterlevel;                /*!< Specify the dma watermark level in transmit mode.
                                                   This parameter must range from 1 to 63. */

    uint32_t I2S_RxWaterlevel;                /*!< Specify the dma watermark level in receive mode.
                                                   This parameter must range from 1 to 63. */
#if I2S_SUPPORT_MCLK_OUTPUT_SEL
    uint32_t I2S_MCLKOutput;                  /*!< Specify the I2S MCLK output freqency.
                                                   This parameter can be a value of \ref I2S_MCLK_Output. */
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
    uint8_t tx_channel_map[4];     //!< I2S TX channel map.
    uint8_t rx_fifo_map[4];        //!< I2S RX fifo map.
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
                                   ((PERIPH) == I2S1))     //!< I2S all periph.

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
                                          (CLEAR) == I2S_CLEAR_INT_RX_READY) || \
((CLEAR) == I2S_CLEAR_INT_TX_READY) )

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
 * \param[in] I2S_InitStruct: Pointer to a I2S_InitTypeDef structure which will be initialized.
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
 * \param[in] I2S_InitStruct: Pointer to an I2S_InitTypeDef structure which will be initialized.
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
 *     I2S_Init(I2S_NUM, &I2S_InitStruct);
 *     I2S_Cmd(I2S_NUM, I2S_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void I2S_Cmd(I2S_TypeDef *I2Sx, uint32_t mode, FunctionalState NewState);

/**
 * \brief   Enable or disable the specified I2S interrupt source.
 * \param[in] I2S_INT: Specify the I2S interrupt source to be enable or disable.
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
 * \return The new state of I2S_INT (SET or RESET).
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
 * \param[in] I2S_CLEAR_INT: Specify the interrupt pending bit to clear.
 *      This parameter can be any combination of the following values:
 *      \arg I2S_CLEAR_INT_RX_READY: Clear ready to receive interrupt.
 *      \arg I2S_CLEAR_INT_TX_READY: Clear ready to transmit interrupt.
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
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  the transmit FIFO free length.
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
 * \return  The reception error counter value .
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


/******************* (C) COPYRIGHT 2024 Realtek Semiconductor Corporation *****END OF FILE****/

