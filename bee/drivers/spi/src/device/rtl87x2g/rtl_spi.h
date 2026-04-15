/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_SPI_H
#define RTL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "rtl_spi_def.h"

/** \defgroup SPI         SPI
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup SPI_Exported_Constants SPI Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    SPI_Clock_Speed SPI Clock Speed
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define IS_SPI_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && \
                                   ((SPEED) <= 40000000)) //!< SPI clock speed is between 1 and 40000000.

/** End of SPI_Clock_Speed
  * \}
  */

/**
 * \defgroup    SPI_Data_Direction SPI Data Direction
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_Direction_FullDuplex = 0x00, //!< Data can be transmitted and received at the same time.
    SPI_Direction_TxOnly     = 0x01, //!< Data can only be transmitted at a time.
    SPI_Direction_RxOnly     = 0x02, //!< Data can only be received at a time.
    SPI_Direction_EEPROM     = 0x03, //!< Send data first to read target numbers of data.
} SPIDataDirection_TypeDef;

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_FullDuplex) || \
                                     ((MODE) == SPI_Direction_RxOnly) || \
                                     ((MODE) == SPI_Direction_TxOnly) || \
                                     ((MODE) == SPI_Direction_EEPROM)) //!< Check if the input parameter is valid.

/** End of SPI_Data_Direction
  * \}
  */

/**
 * \defgroup    SPI_Data_Size SPI Data Size
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_DataSize_4b  = 0x03,     //!< The data frame size is programmed to 4bits.
    SPI_DataSize_5b  = 0x04,     //!< The data frame size is programmed to 5bits.
    SPI_DataSize_6b  = 0x05,     //!< The data frame size is programmed to 6bits.
    SPI_DataSize_7b  = 0x06,     //!< The data frame size is programmed to 7bits.
    SPI_DataSize_8b  = 0x07,     //!< The data frame size is programmed to 8bits.
    SPI_DataSize_9b  = 0x08,     //!< The data frame size is programmed to 9bits.
    SPI_DataSize_10b = 0x09,     //!< The data frame size is programmed to 10bits.
    SPI_DataSize_11b = 0x0a,     //!< The data frame size is programmed to 11bits.
    SPI_DataSize_12b = 0x0b,     //!< The data frame size is programmed to 12bits.
    SPI_DataSize_13b = 0x0c,     //!< The data frame size is programmed to 13bits.
    SPI_DataSize_14b = 0x0d,     //!< The data frame size is programmed to 14bits.
    SPI_DataSize_15b = 0x0e,     //!< The data frame size is programmed to 15bits.
    SPI_DataSize_16b = 0x0f,     //!< The data frame size is programmed to 16bits.
    SPI_DataSize_17b = 0x10,     //!< The data frame size is programmed to 17bits.
    SPI_DataSize_18b = 0x11,     //!< The data frame size is programmed to 18bits.
    SPI_DataSize_19b = 0x12,     //!< The data frame size is programmed to 19bits.
    SPI_DataSize_20b = 0x13,     //!< The data frame size is programmed to 20bits.
    SPI_DataSize_21b = 0x14,     //!< The data frame size is programmed to 21bits.
    SPI_DataSize_22b = 0x15,     //!< The data frame size is programmed to 22bits.
    SPI_DataSize_23b = 0x16,     //!< The data frame size is programmed to 23bits.
    SPI_DataSize_24b = 0x17,     //!< The data frame size is programmed to 24bits.
    SPI_DataSize_25b = 0x18,     //!< The data frame size is programmed to 25bits.
    SPI_DataSize_26b = 0x19,     //!< The data frame size is programmed to 26bits.
    SPI_DataSize_27b = 0x1A,     //!< The data frame size is programmed to 27bits.
    SPI_DataSize_28b = 0x1B,     //!< The data frame size is programmed to 28bits.
    SPI_DataSize_29b = 0x1C,     //!< The data frame size is programmed to 29bits.
    SPI_DataSize_30b = 0x1D,     //!< The data frame size is programmed to 30bits.
    SPI_DataSize_31b = 0x1E,     //!< The data frame size is programmed to 31bits.
    SPI_DataSize_32b = 0x1F,     //!< The data frame size is programmed to 32bits.
} SPIDataSize_TypeDef;

#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DataSize_4b)  || \
                                   ((DATASIZE) == SPI_DataSize_5b)  || \
                                   ((DATASIZE) == SPI_DataSize_6b)  || \
                                   ((DATASIZE) == SPI_DataSize_7b)  || \
                                   ((DATASIZE) == SPI_DataSize_8b)  || \
                                   ((DATASIZE) == SPI_DataSize_9b)  || \
                                   ((DATASIZE) == SPI_DataSize_10b) || \
                                   ((DATASIZE) == SPI_DataSize_11b) || \
                                   ((DATASIZE) == SPI_DataSize_12b) || \
                                   ((DATASIZE) == SPI_DataSize_13b) || \
                                   ((DATASIZE) == SPI_DataSize_14b) || \
                                   ((DATASIZE) == SPI_DataSize_15b) || \
                                   ((DATASIZE) == SPI_DataSize_16b) || \
                                   ((DATASIZE) == SPI_DataSize_17b) || \
                                   ((DATASIZE) == SPI_DataSize_18b) || \
                                   ((DATASIZE) == SPI_DataSize_19b) || \
                                   ((DATASIZE) == SPI_DataSize_20b) || \
                                   ((DATASIZE) == SPI_DataSize_21b) || \
                                   ((DATASIZE) == SPI_DataSize_22b) || \
                                   ((DATASIZE) == SPI_DataSize_23b) || \
                                   ((DATASIZE) == SPI_DataSize_24b) || \
                                   ((DATASIZE) == SPI_DataSize_25b) || \
                                   ((DATASIZE) == SPI_DataSize_26b) || \
                                   ((DATASIZE) == SPI_DataSize_27b) || \
                                   ((DATASIZE) == SPI_DataSize_28b) || \
                                   ((DATASIZE) == SPI_DataSize_29b) || \
                                   ((DATASIZE) == SPI_DataSize_30b) || \
                                   ((DATASIZE) == SPI_DataSize_31b) || \
                                   ((DATASIZE) == SPI_DataSize_32b)) //!< Check if the input parameter is valid.

/** End of SPI_Data_Size
  * \}
  */

/**
 * \defgroup    SPI_Clock_Polarity SPI Clock Polarity
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_CPOL_Low = 0x00,  //!< Inactive state of serial clock is low.
    SPI_CPOL_High = 0x01, //!< Inactive state of serial clock is high.
} SPIClockPolarity_TypeDef;

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High)) //!< Check if the input parameter is valid.

/** End of SPI_Clock_Polarity
  * \}
  */

/**
 * \defgroup    SPI_Clock_Phase SPI Clock Phase
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_CPHA_1Edge = 0x00, //!< Serial clock toggles in middle of first data bit.
    SPI_CPHA_2Edge = 0x01, //!< Serial clock toggles at start of first data bit.
} SPIClockPhase_TypeDef;

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge)) //!< Check if the input parameter is valid.

/** End of SPI_Clock_Phase
  * \}
  */

/**
 * \defgroup    SPI_BaudRate_Prescaler_Value SPI BaudRate Prescaler Value
 * \{
 * \ingroup     SPI_Exported_Constants
 */

#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFF) //!< Check if the input parameter is valid.

/** End of SPI_BaudRate_Prescaler_Value
  * \}
  */

/**
 * \defgroup    SPI_Frame_Format SPI Frame Format
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_Frame_Motorola      = 0x00, //!< Standard SPI frame format.
    SPI_Frame_TI_SSP        = 0x01, //!< Texas instruments SSP frame format.
    SPI_Frame_NS_MICROWIRE  = 0x02, //!< National microwire frame format.
    SPI_Frame_Reserve       = 0x03, //!< Reserved value.
} SPIFrameFormat_TypeDef;

#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_Frame_Motorola) || \
                                    ((FRAME) == SPI_Frame_TI_SSP) || \
                                    ((FRAME) == SPI_Frame_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_Frame_Reserve)) //!< Check if the input parameter is valid.

/** End of SPI_Frame_Format
  * \}
  */

/**
 * \defgroup    SPI_GDMA_Transfer_Request SPI GDMA Transfer Request
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_GDMAReq_Rx = 0x01, //!< RX buffer GDMA transfer request.
    SPI_GDMAReq_Tx = 0x02, //!< TX buffer GDMA transfer request.
} SPIGdmaTransferRequests_TypeDef;

#define IS_SPI_GDMAREQ(GDMAREQ) (((GDMAREQ)  == SPI_GDMAReq_Rx) || \
                                 ((GDMAREQ) == SPI_GDMAReq_Tx)) //!< Check if the input parameter is valid.

/** End of SPI_GDMA_Transfer_Request
  * \}
  */

/**
 * \defgroup    SPI_Flags SPI Flags
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define SPI_FLAG_BUSY                   BIT0  /**< SPI Busy flag. Set if it is actively transferring data. Reset if it is idle or disabled. */
#define SPI_FLAG_TFNF                   BIT1  /**< Transmit FIFO not full flag. Set if transmit FIFO is not full. */
#define SPI_FLAG_TFE                    BIT2  /**< Transmit FIFO empty flag. Set if transmit FIFO is empty. */
#define SPI_FLAG_RFNE                   BIT3  /**< Receive FIFO not empty flag. Set if receive FIFO is not empty. */
#define SPI_FLAG_RFF                    BIT4  /**< Receive FIFO full flag. Set if the receive FIFO is completely full. */
#define SPI_FLAG_TXE                    BIT5  /**< Transmission error flag. Set if the transmit FIFO is empty when a transfer is started in slave mode. */
#define SPI_FLAG_DCOL                   BIT6  /**< Data collision error flag. Set if it is actively transmitting in master mode when another master selects this device as a slave. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
#define SPI_FLAG_WRAP_CS_EN             BIT8
#define SPI_FLAG_WRAP_TFNF              BIT9
#define SPI_FLAG_WRAP_TFE               BIT10
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY) || \
                                 ((FLAG) == SPI_FLAG_WRAP_CS_EN) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFNF) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFE)) //!< Check if the input parameter is valid.
#else
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY)) //!< Check if the input parameter is valid.
#endif

/** End of SPI_Flags
  * \}
  */

/**
 * \defgroup    SPI_Interrupt SPI Interrupt
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define SPI_INT_TXE                    BIT0 //!< Transmit FIFO empty interrupt.
#define SPI_INT_TXO                    BIT1 //!< Transmit FIFO overflow interrupt.
#define SPI_INT_RXU                    BIT2 //!< Receive FIFO underflow interrupt.
#define SPI_INT_RXO                    BIT3 //!< Receive FIFO overflow interrupt.
#define SPI_INT_RXF                    BIT4 //!< Receive FIFO full interrupt.
#define SPI_INT_MST                    BIT5 //!< Multi-Master contention interrupt. (master only)
#define SPI_INT_FAE                    BIT5 //!< The data of slave rx does not match DFS. (slave only)
#define SPI_INT_TUF                    BIT6 //!< Transmit FIFO underflow interrupt. (slave only)
#define SPI_INT_RIG                    BIT7 //!< CS rising edge detect interrupt. (slave only)
#if (SPI_SUPPORT_WRAP_MODE == 1)
#define SPI_INT_WRAP_TXE               BIT8
#define SPI_INT_WRAP_TXO               BIT9
#define SPI_INT_WRAP_TXD               BIT10
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) || \
                              ((IT) == SPI_INT_WRAP_TXE) || \
                              ((IT) == SPI_INT_WRAP_TXO) || \
                              ((IT) == SPI_INT_WRAP_TXD)) //!< Check if the input parameter is valid.
#else
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) ) //!< Check if the input parameter is valid.
#endif

/** End of SPI_Interrupt
  * \}
  */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)

/**
 * \defgroup    SPI_mode SPI Mode
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_Mode_Master = ((uint16_t)0x0104), //!< SPI device operating mode as master.
    SPI_Mode_Slave  = ((uint16_t)0x0000)  //!< SPI device operating mode as slave.
} SPIMode_Typedef;

#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave)) //!< Check if the input parameter is valid.

/** End of SPI_mode
  * \}
  */
#endif

#if (SPI_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    SPI_TaskEvent SPI Task Event
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_TASK_START  = 0,
    SPI_EVENT_START = 1,
    SPI_EVENT_END   = 2,
} SPITaskEvent_TypeDef;

/** End of SPI_TaskEvent
  * \}
  */
#endif

/** End of SPI_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup SPI_Exported_Types SPI Exported Types
  * \brief
  * \{
  */

/**
 * \brief       SPI init structure definition.
 *
 * \ingroup     SPI_Exported_Types
 */
typedef struct
{
    SPIDataDirection_TypeDef
    SPI_Direction;    /*!< Specify the SPI unidirectional or bidirectional data mode.
                                                    This parameter can be a value of \ref SPI_Data_Direction. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
    uint32_t SPI_TXNDF;                        /*!< Specify the trigger condition in TxOnly or FullDuplex mode.
                                                    This parameter should be the value of the length of read data,
                                                    from 1 to 65536. */

    FunctionalState SPI_CSHighActiveEn;        /*!< Specify whether to enable CS high active.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState
    SPI_WrapModeEn;            /*!< Specify the TX waper mode (TX NDF) enable. Only SPI1 have txndf mode.
                                                    ENABLE: Hardware won't automatically pull SPI_CSN high when TX FIFO is empty.
                                                    DISABLE: SPI_CSN pull high when TX data number = SPI_TXNDF+1. */

    FunctionalState SPI_WrapModeDmaEn;         /*!< Specify the TX waper mode(TX NDF) DMA enable.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  SPI_TxNdfWaterlevel;              /*!< Specify the TX NDF DMA tx water level max number is 63. */
#endif

    uint32_t SPI_RXNDF;                        /*!< Specify the trigger condition in RxOnly or EEPROM mode.
                                                    This parameter should be a value of the length of read data,
                                                    ranging from 1 to 65536. */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
    SPIMode_Typedef SPI_Mode;                  /*!< Specify the SPI Mode.
                                                    This parameter can be a value of \ref SPI_mode. */
#endif

    SPIDataSize_TypeDef SPI_DataSize;          /*!< Specify the SPI data size.
                                                    This parameter can be a value of \ref SPI_Data_Size. */

    SPIClockPolarity_TypeDef SPI_CPOL;         /*!< Specify the serial clock steady state.
                                                    This parameter can be a value of \ref SPI_Clock_Polarity. */

    SPIClockPhase_TypeDef SPI_CPHA;            /*!< Specify clock active edge for bit capture.
                                                    This parameter can be a value of \ref SPI_Clock_Phase. */

    SPIFrameFormat_TypeDef
    SPI_FrameFormat;                           /*!< Specify which serial protocol transfers the data.
                                                    This parameter can be a value of \ref SPI_Frame_Format. */

    uint32_t SPI_BaudRatePrescaler;            /*!< Specify the divider of SPI clock. SPI Clock Speed = clk source/SPI_BaudRatePrescaler.
                                                    This parameter can be any even value between 2 and 65534.
                                                    This parameter can also refer to the listed values of \ref SPI_BaudRate_Prescaler_Value. */

#if (SPI_SUPPORT_SWAP == 1)
    FunctionalState SPI_SwapTxBitEn;           /*!< Specify whether to swap SPI Tx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxBitEn;           /*!< Specify whether to swap SPI Rx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapTxByteEn;          /*!< Specify whether to swap SPI Tx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxByteEn;          /*!< Specify whether to swap SPI Rx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */
#endif

    FunctionalState SPI_ToggleEn;              /*!< Specify whether to toggle when transfer done.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint32_t SPI_TxThresholdLevel;             /*!< Specify the transmit FIFO Threshold.
                                                    This parameter can be a value less than 64.*/

    uint32_t SPI_RxThresholdLevel;             /*!< Specify the receive FIFO Threshold.
                                                    This parameter can be a value less than 64.*/

    FunctionalState SPI_TxDmaEn;               /*!< Specify the Tx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_RxDmaEn;               /*!< Specify the Rx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t SPI_TxWaterlevel;                  /*!< Specify the DMA Tx water level.
                                                    The best value is SPI fifo depth - Tx GDMA MSize. */

    uint8_t SPI_RxWaterlevel;                  /*!< Specify the DMA Rx water level.
                                                    The best value is SPI Rx GDMA MSize. */
} SPI_InitTypeDef;

/** End of SPI_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup SPI_Exported_Functions SPI Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitialize the SPIx peripheral registers to their default reset values.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_DeInit(SPI0);
 * }
 * \endcode
 */
void SPI_DeInit(SPI_TypeDef *SPIx);

/**
 * \brief   Initialize the SPIx peripheral according to the specified
 *          parameters in the SPI_InitStruct.
 *
 * \param[in] SPIx            Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_InitStruct  Pointer to a SPI_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);

 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);

/**
 * \brief  Fill each SPI_InitStruct member with its default value.
 *
 * \note   The default settings for the SPI_InitStruct member are shown in the following table:
 *         | SPI_InitStruct member  | Default value                  |
 *         |:----------------------:|:------------------------------:|
 *         | SPI_Direction          | \ref SPI_Direction_FullDuplex  |
 *         | SPI_RXNDF              | 1                              |
 *         | SPI_DataSize           | \ref SPI_DataSize_8b           |
 *         | SPI_CPOL               | \ref SPI_CPOL_High             |
 *         | SPI_CPHA               | \ref SPI_CPHA_2Edge            |
 *         | SPI_FrameFormat        | \ref SPI_Frame_Motorola        |
 *         | SPI_BaudRatePrescaler  | 128                            |
 *         | SPI_ToggleEn           | DISABLE                        |
 *         | SPI_TxThresholdLevel   | 1                              |
 *         | SPI_RxThresholdLevel   | 0                              |
 *         | SPI_TxDmaEn            | DISABLE                        |
 *         | SPI_RxDmaEn            | DISABLE                        |
 *         | SPI_TxWaterlevel       | SPI_TX_FIFO_SIZE - 1           |
 *         | SPI_RxWaterlevel       | 1                              |
 *
 * \param[in] SPI_InitStruct  Pointer to a SPI_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);

 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct);

/**
 * \brief  Enable or disable the selected SPI peripheral.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] NewState  New state of the SPIx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the selected SPI peripheral.
 *                      - DISABLE: Disable the selected SPI peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 *     SPI_Cmd(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief  Transmit a number of bytes through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] pBuf  Bytes to be transmitted.
 * \param[in] len   Byte length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_buf[] = {0x01,0x02,0x03};
 *     SPI_SendBuffer(SPI0, data_buf, sizeof(data_buf));
 * }
 * \endcode
 */
void SPI_SendBuffer(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len);

/**
 * \brief  Transmit a number of halfword through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] pBuf  Halfwords to be transmitted.
 * \param[in] len   Halfwords length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint16_t));
 * }
 * \endcode
  */
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

/**
 * \brief  Transmit a number of words through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] pBuf  Words to be transmitted.
 * \param[in] len   Word length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint32_t));
 * }
 * \endcode
 */
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);

/**
 * \brief  Enable or disable the specified SPI interrupt source.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_IT    Specify the SPI interrupt source to be enabled or disabled.
 *                      This parameter can be one of the following values, refer to \ref SPI_Interrupt.
 *                      \arg SPI_INT_TXE: Transmit FIFO empty interrupt.
 *                      \arg SPI_INT_TXO: Transmit FIFO overflow interrupt.
 *                      \arg SPI_INT_RXU: Receive FIFO underflow interrupt.
 *                      \arg SPI_INT_RXO: Receive FIFO overflow interrupt.
 *                      \arg SPI_INT_RXF: Receive FIFO full interrupt.
 *                      \arg SPI_INT_MST: Multi-Master Contention Interrupt.
 *                      \arg SPI_INT_FAE: TX Frame Alignment interrupt.
 *                      \arg SPI_INT_TUF: Transmit FIFO underflow interrupt.
 *                      \arg SPI_INT_RIG: Rising edge detect interrupt.
 * \param[in] NewState  New state of the specified SPI interrupt source.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified SPI interrupt source.
 *                      - DISABLE: Disable the specified SPI interrupt source.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_INTConfig(SPI0, SPI_INT_RXF, ENABLE);
 * }
 * \endcode
 */
void SPI_INTConfig(SPI_TypeDef *SPIx, uint16_t SPI_IT, FunctionalState NewState);

/**
 * \brief  Clear the specified SPI interrupt pending bit.
 *
 * \param[in] SPIx    Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_IT  Specify the SPI interrupt to clear.
 *                    This parameter can be one of the following values, refer to \ref SPI_Interrupt.
 *                    - SPI_INT_TXO: Transmit FIFO Overflow Interrupt.
 *                    - SPI_INT_RXO: Receive FIFO Overflow Interrupt.
 *                    - SPI_INT_RXU: Receive FIFO Underflow Interrupt.
 *                    - SPI_INT_MST: Multi-Master Contention Interrupt.
 *                    - SPI_INT_FAE: TX Frame Alignment Interrupt.
 *                    - SPI_INT_TUF: Transmit FIFO Underflow Interrupt.
 *                    - SPI_INT_RIG: Rising edge detect Interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ClearINTPendingBit(SPI0, SPI_INT_RXF);
 * }
 * \endcode
 */
void SPI_ClearINTPendingBit(SPI_TypeDef *SPIx, uint16_t SPI_IT);

/**
 * \brief  Transmit a data through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] Data  Data to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data = 0x01020304;
 *     SPI_SendData(SPI0, data);
 * }
 * \endcode
 */
void SPI_SendData(SPI_TypeDef *SPIx, uint32_t Data);

/**
 * \brief   Receive data by the SPI peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 *
 * \return  The most recent received data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data = SPI_ReceiveData(SPI0);
 * }
 * \endcode
 */
uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx);

/**
 * \brief   Get data length in Tx FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 *
 * \return  Data length in Tx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_len = SPI_GetTxFIFOLen(SPI0);
 * }
 * \endcode
 */
uint8_t SPI_GetTxFIFOLen(SPI_TypeDef *SPIx);

/**
 * \brief   Get data length in Rx FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 *
 * \return  Data length in Rx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_len = SPI_GetRxFIFOLen(SPI0);
 * }
 * \endcode
 */
uint8_t SPI_GetRxFIFOLen(SPI_TypeDef *SPIx);

/**
 * \brief   Change SPI direction mode.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] dir   Value of direction mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ChangeDirection(SPI0, SPI_Direction_EEPROM);
 * }
 * \endcode
 */
void SPI_ChangeDirection(SPI_TypeDef *SPIx, uint16_t dir);

/**
 * \brief   Set read Data length only in EEPROM mode through the SPIx peripheral,which
            enables you to receive up to 64 KB of data in a continuous transfer.
 *
 * \param[in] SPIx  Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] len   Length of read data which can be 1 to 65536.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetReadLen(SPI0, 100);
 * }
 * \endcode
 */
void SPI_SetReadLen(SPI_TypeDef *SPIx, uint16_t len);

/**
 * \brief   Set cs number through the SPIx peripheral.
 *
 * \param[in] SPIx    Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] number  Number can be 0 to 2.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetCSNumber(SPI1, 1);
 * }
 * \endcode
 */
void SPI_SetCSNumber(SPI_TypeDef *SPIx, uint8_t number);

/**
 * \brief  Get the specified SPI interrupt status.
 *
 * \param[in] SPIx    Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_IT  Specify the SPI interrupt to check.
 *                    This parameter can be one of the following values, refer to \ref SPI_Interrupt.
 *                    \arg SPI_INT_MST: Multi-Master Contention Interrupt.
 *                    \arg SPI_INT_FAE: TX Frame Alignment Interrupt.
 *                    \arg SPI_INT_RXF: Receive FIFO Full Interrupt.
 *                    \arg SPI_INT_RXO: Receive FIFO Overflow Interrupt.
 *                    \arg SPI_INT_RXU: Receive FIFO Underflow Interrupt.
 *                    \arg SPI_INT_TXO: Transmit FIFO Overflow Interrupt .
 *                    \arg SPI_INT_TXE: Transmit FIFO Empty Interrupt.
 *                    \arg SPI_INT_WRAP_TXE: TX NDF mode FIFO Transmit FIFO Empty Interrupt.
 *                    \arg SPI_INT_WRAP_TXO: TX NDF mode FIFO Overflow Interrupt.
 *                    \arg SPI_INT_WRAP_TXD: TX NDF mode transmit done Interrupt.
 *
 * \return  The status of the SPI interrupt.
 *          - SET: The SPI interrupt status has been set.
 *          - RESET: The SPI interrupt status has been reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     ITStatus int_status = SPI_GetINTStatus(SPI0, SPI_INT_RXF);
 * }
 * \endcode
 */
ITStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, uint32_t SPI_IT);

/**
 * \brief  Get the specified SPI flag status.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_FLAG  Specify the SPI flag to check.
 *                      This parameter can be one of the following values, refer to \ref SPI_Flags.
 *                      \arg SPI_FLAG_DCOL: Data Collision Error flag.Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *                      \arg SPI_FLAG_TXE: Transmission error flag.Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *                      \arg SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *                      \arg SPI_FLAG_RFNE: Receive FIFO Not Empty flag.Set if receive FIFO is not empty.
 *                      \arg SPI_FLAG_TFE: Transmit FIFO Empty flag.Set if transmit FIFO is empty.
 *                      \arg SPI_FLAG_TFNF: Transmit FIFO Not Full flag.Set if transmit FIFO is not full.
 *                      \arg SPI_FLAG_BUSY: SPI Busy flag.Set if it is actively transferring data.reset if it is idle or disabled.
 *                      \arg SPI_FLAG_TXNDF_BUSY: TX NDF mode Busy flag.
 *                      \arg SPI_FLAG_TXNDF_TFNF: TX NDF mode FIFO Not Full flag.
 *                      \arg SPI_FLAG_TXNDF_TFE: TX NDF mode FIFO Empty flag.
 *
 * \return  The status of SPI flag.
 *          - SET: The SPI flag has been set.
 *          - RESET: The SPI flag has been reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     FlagStatus flag_status = SPI_GetFlagState(SPI0, SPI_FLAG_TXE);
 *
 * }
 * \endcode
 */
FlagStatus SPI_GetFlagState(SPI_TypeDef *SPIx, uint16_t SPI_FLAG);

/**
 * \brief   Enable or disable the SPIx GDMA interface.
 *
 * \param[in] SPIx         Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] SPI_GDMAReq  Specify the SPI GDMA transfer request to be enabled or disabled.
 *                         This parameter can be one of the following values:
 *                         \arg SPI_GDMAReq_Tx: Tx buffer DMA transfer request.
 *                         \arg SPI_GDMAReq_Rx: Rx buffer DMA transfer request.
 * \param[in] NewState     New state of the selected SPI GDMA transfer request.
 *                         This parameter can be one of the following values:
 *                         - ENABLE: Enable the SPIx GDMA interface.
 *                         - DISABLE: Disable the SPIx GDMA interface.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_GDMACmd(SPI0, SPI_GDMAReq_Tx, ENABLE);
 * }
 * \endcode
 */
void SPI_GDMACmd(SPI_TypeDef *SPIx, SPIGdmaTransferRequests_TypeDef SPI_GDMAReq,
                 FunctionalState NewState);

/**
 * \brief  Change SPI speed daynamically.
 *
 * \param[in] SPIx       Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] precalser  Value of prescaler.
 *                       This parameter can be any even value between 2 and 65534.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ChangeClock(SPI0, 2);
 * }
 * \endcode
 */
void SPI_ChangeClock(SPI_TypeDef *SPIx, uint32_t prescaler);

/**
 * \brief   Set SPI Rx sample delay.
 *
 * \param[in] SPIx   Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] delay  This parameter can be 0 to 255.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetRxSampleDly(SPI0, 1);
 * }
 * \endcode
 */
void SPI_SetRxSampleDly(SPI_TypeDef *SPIx, uint32_t delay);

#if (SPI_SUPPORT_WRAP_MODE == 1)

/**
 * \brief   Enable or disable the specified SPI wrap mode start transfer.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] NewState  New state of the SPIx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified SPI wrap mode start transfer.
 *                      - DISABLE: Disable the specified SPI wrap mode start transfer.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_WrapModeStartTx(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_WrapModeStartTx(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Enable or disable inverse CS active polarity.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] NewState  New state of the SPIx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Inverse CS active polarity, which means CS is low active.
 *                      - DISABLE: Not inverse CS active polarity, which means CS is high active.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_InverseCSActivePolarity(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_InverseCSActivePolarity(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Enable or disable driving MOSI low during the idle state.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] NewState  New state of the SPIx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Drive MOSI low in idle state.
 *                      - DISABLE: Set MOSI to high-impedance (Hi-Z) in idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_DriveMOSILow(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_DriveMOSILow(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Enable or disable the MOSI pull function in the idle state.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] NewState  New state of the SPIx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: MOSI is pull down in idle state.
 *                      - DISABLE: MOSI is pull none in idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_PullMOSIEn(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_PullMOSIEn(SPI_TypeDef *SPIx, FunctionalState NewState);

#endif

/**
 * \brief     Configure the SPI clock divider.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] ClockDiv  Specify the SPI clock divider.
 *                      This parameter can refer to \ref SPI_Clock_Divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_SPIClkDivConfig(SPI0, CLOCK_DIV_1);
 * }
 * \endcode
 */
void SPI_ClkDivConfig(SPI_TypeDef *SPIx, SPIClockDiv_TypeDef ClockDiv);

#if SPI_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * \brief  Configure the SPI clock.
 *
 * \param[in]  SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in]  ClockSrc  Specify the clock source to gates its clock.
 * \param[in]  ClockDiv  Specify the clock divider to gates its clock.
 */
void SPI_ClkConfig(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc,
                   SPIClockDiv_TypeDef ClockDiv);

/**
 * \brief  Get the SPI clock configuration.
 *
 * \param[in] SPIx      Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] ClockSrc  Specify the clock source to gates its clock.
 * \param[in] ClockDiv  Specify the clock divide to gates its clock.
 *
 * \return The status of get clock.
 */
bool SPI_ClkGet(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef *ClockSrc, SPIClockDiv_TypeDef *ClockDiv);
#endif

#if SPI_SUPPORT_CLOCK_SOURCE_SWTICH
/**
 * \brief  SPI clock source switch.
 *
 * \param[in] SPIx         Select the SPI peripheral. Refer to \ref SPI_Declaration.
 * \param[in] ClockSource  SPI clock source to switch.
 *                         This parameter can be one of the following values:
 *                         - SPI_CLOCK_SOURCE_40M: Select SPI clock source of 40MHz.
 *                         - SPI_CLOCK_SOURCE_PLL: Select SPI clock source of PLL.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_ClkSourceSwitch(SPI0, SPI_CLOCK_SOURCE_40M);
 * }
 * \endcode
 */
extern void SPI_ClkSourceSwitch(SPI_TypeDef *SPIx, uint16_t ClockSource);
#endif


#if (SPI_SUPPORT_RAP_FUNCTION == 1)

void SPI_RAPModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState);

void SPI_SetTaskCmdNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_SetTaskWaitNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_SetTaskTransferNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_TaskTrigger(SPI_TypeDef *SPIx, uint32_t task);

bool SPI_TaskEventStsCheck(SPI_TypeDef *SPIx, uint32_t te);

void SPI_TaskEventStsClear(SPI_TypeDef *SPIx, uint32_t te);

#endif
/** End of SPI_Exported_Functions
  * \}
  */

/** End of SPI
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_SPI_H */


