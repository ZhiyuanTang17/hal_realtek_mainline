/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_spi.h
* \brief    The header file of the peripheral SPI driver.
* \details  This file provides all SPI firmware functions.
* \author   yuzhuo_liu
* \date     2023-10-17
* \version  v1.0
* *******************************************************************************************************
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
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "spi/src/rtl87x2g/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "spi/src/rtl87x3e/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "spi/src/rtl87x3d/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "spi/src/rtl87x2j/rtl_spi_def.h"
#endif

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
                                   ((SPEED) <= 40000000))

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
    SPI_Direction_FullDuplex = 0x00,
    SPI_Direction_TxOnly     = 0x01,
    SPI_Direction_RxOnly     = 0x02,
    SPI_Direction_EEPROM     = 0x03,
} SPIDataDirection_TypeDef;

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_FullDuplex) || \
                                     ((MODE) == SPI_Direction_RxOnly) || \
                                     ((MODE) == SPI_Direction_TxOnly) || \
                                     ((MODE) == SPI_Direction_EEPROM))

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
    SPI_DataSize_4b  = 0x03,
    SPI_DataSize_5b  = 0x04,
    SPI_DataSize_6b  = 0x05,
    SPI_DataSize_7b  = 0x06,
    SPI_DataSize_8b  = 0x07,
    SPI_DataSize_9b  = 0x08,
    SPI_DataSize_10b = 0x09,
    SPI_DataSize_11b = 0x0a,
    SPI_DataSize_12b = 0x0b,
    SPI_DataSize_13b = 0x0c,
    SPI_DataSize_14b = 0x0d,
    SPI_DataSize_15b = 0x0e,
    SPI_DataSize_16b = 0x0f,
    SPI_DataSize_17b = 0x10,
    SPI_DataSize_18b = 0x11,
    SPI_DataSize_19b = 0x12,
    SPI_DataSize_20b = 0x13,
    SPI_DataSize_21b = 0x14,
    SPI_DataSize_22b = 0x15,
    SPI_DataSize_23b = 0x16,
    SPI_DataSize_24b = 0x17,
    SPI_DataSize_25b = 0x18,
    SPI_DataSize_26b = 0x19,
    SPI_DataSize_27b = 0x1A,
    SPI_DataSize_28b = 0x1B,
    SPI_DataSize_29b = 0x1C,
    SPI_DataSize_30b = 0x1D,
    SPI_DataSize_31b = 0x1E,
    SPI_DataSize_32b = 0x1F,
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
                                   ((DATASIZE) == SPI_DataSize_32b))

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
    SPI_CPOL_Low = 0x00,
    SPI_CPOL_High = 0x01,
} SPIClockPolarity_TypeDef;

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High))

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
    SPI_CPHA_1Edge = 0x00,
    SPI_CPHA_2Edge = 0x01,
} SPIClockPhase_TypeDef;

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge))

/** End of SPI_Clock_Phase
  * \}
  */

/**
 * \defgroup    SPI_BaudRate_Prescaler_Value SPI BaudRate Prescaler Value
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define SPI_BaudRatePrescaler_2      0x02
#define SPI_BaudRatePrescaler_4      0x04
#define SPI_BaudRatePrescaler_6      0x06
#define SPI_BaudRatePrescaler_8      0x08
#define SPI_BaudRatePrescaler_10     0x0A
#define SPI_BaudRatePrescaler_12     0x0C
#define SPI_BaudRatePrescaler_14     0x0E
#define SPI_BaudRatePrescaler_16     0x10
#define SPI_BaudRatePrescaler_32     0x20
#define SPI_BaudRatePrescaler_64     0x40
#define SPI_BaudRatePrescaler_128    0x80
#define SPI_BaudRatePrescaler_256    0x100

#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFF)

/** End of SPI_BaudRate_Prescaler_Value
  * \}
  */

/**
 * \defgroup    SPI_Swap_Enable SPI Swap Enable
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define IS_SPI_SWAPMODE(mode) (((mode) == DISABLE) || \
                               ((mode) == ENABLE))

/** End of SPI_Swap_Enable
  * \}
  */

/**
 * \defgroup    SPI_Frame_Format SPI Frame Format
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_Frame_Motorola      = 0x00,
    SPI_Frame_TI_SSP        = 0x01,
    SPI_Frame_NS_MICROWIRE  = 0x02,
    SPI_Frame_Reserve       = 0x03,
} SPIFrameFormat_TypeDef;

#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_Frame_Motorola) || \
                                    ((FRAME) == SPI_Frame_TI_SSP) || \
                                    ((FRAME) == SPI_Frame_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_Frame_Reserve))

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
    SPI_GDMAReq_Rx = 0x01,
    SPI_GDMAReq_Tx = 0x02,
} SPIGdmaTransferRequests_TypeDef;

#define IS_SPI_GDMAREQ(GDMAREQ) (((GDMAREQ)  == SPI_GDMAReq_Rx) || \
                                 ((GDMAREQ) == SPI_GDMAReq_Tx))

/** End of SPI_GDMA_Transfer_Request
  * \}
  */

/**
 * \defgroup    SPI_Flags SPI Flags
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define SPI_FLAG_BUSY                   BIT0
#define SPI_FLAG_TFNF                   BIT1
#define SPI_FLAG_TFE                    BIT2
#define SPI_FLAG_RFNE                   BIT3
#define SPI_FLAG_RFF                    BIT4
#define SPI_FLAG_TXE                    BIT5
#define SPI_FLAG_DCOL                   BIT6
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
                                 ((FLAG) == SPI_FLAG_WRAP_TFE))
#else
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY))
#endif

/** End of SPI_Flags
  * \}
  */

/**
 * \defgroup    SPI_Interrupt SPI Interrupt
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#define SPI_INT_TXE                    BIT0
#define SPI_INT_TXO                    BIT1
#define SPI_INT_RXU                    BIT2
#define SPI_INT_RXO                    BIT3
#define SPI_INT_RXF                    BIT4
#define SPI_INT_MST                    BIT5  //only MASTER
#define SPI_INT_FAE                    BIT5  //only SLAVE
#define SPI_INT_TUF                    BIT6  //only SLAVE
#define SPI_INT_RIG                    BIT7  //only SLAVE
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
                              ((IT) == SPI_INT_WRAP_TXD))
#else
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) )
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
    SPI_Mode_Master = ((uint16_t)0x0104),
    SPI_Mode_Slave  = ((uint16_t)0x0000)
} SPIMode_Typedef;

#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave))

/** End of SPI_mode
  * \}
  */
#endif

/**
 * \defgroup    SPI_TaskEvent SPI Task Event
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#if (SPI_SUPPORT_RAP_FUNCTION == 1)
typedef enum
{
    SPI_TASK_START  = 0,
    SPI_EVENT_START = 1,
    SPI_EVENT_END   = 2,
} SPITaskEvent_TypeDef;
#endif

/** End of SPI_TaskEvent
  * \}
  */

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
    SPIDataDirection_TypeDef SPI_Direction;    /*!< Specifies the SPI unidirectional
                                                    or bidirectional data mode. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
    uint32_t SPI_TXNDF;                        /*!< Specifies the trigger condition in TxOnly or FullDuplex mode.
                                                    This parameter should be the value of the length of read data,
                                                    from 1 to 65536. */

    FunctionalState SPI_CSHighActiveEn;        /*!< Specifies whether to enable CS high active.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_WrapModeEn;            /*!< Specifies the TX waper mode (TX NDF) enable.
                                                    Only SPI1 have txndf mode.
                                                    ENABLE: Hardware won't automatically pull
                                                    SPI_CSN high when TX FIFO is empty.
                                                    DISABLE: SPI_CSN pull high when
                                                    TX data number = SPI_TXNDF+1.*/

    FunctionalState SPI_WrapModeDmaEn;         /*!< Specifies the TX waper mode(TX NDF) DMA enable.*/

    uint8_t  SPI_TxNdfWaterlevel;              /*!< Specifies the TX NDF DMA tx water level max number is 63. >*/
#endif

    uint32_t SPI_RXNDF;                        /*!< Specifies the trigger condition in RxOnly or EEPROM mode.
                                                    This parameter should be the value of the length of read data,
                                                    from 1 to 65536. */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
    SPIMode_Typedef           SPI_Mode;        /*!< Specifies the SPI Mode. */
#endif

    SPIDataSize_TypeDef SPI_DataSize;          /*!< Specifies the SPI data size. */

    SPIClockPolarity_TypeDef SPI_CPOL;         /*!< Specifies the serial clock steady state. */

    SPIClockPhase_TypeDef SPI_CPHA;            /*!< Specifies clock active edge for bit capture. */

    SPIFrameFormat_TypeDef
    SPI_FrameFormat;    /*!< Specifies which serial protocol transfers the data. */

    uint32_t SPI_BaudRatePrescaler;            /*!< Specifies the speed of SCK clock.
                                                    SPI Clock Speed = clk source/SPI_ClkDIV.
                                                    This parameter can be a value of \ref SPI_BaudRate_Prescaler.
                                                    \note The communication clock is derived from the master clock.
                                                    The slave clock does not need to be set. */

#if (SPI_SUPPORT_SWAP == 1)
    FunctionalState SPI_SwapTxBitEn;           /*!< Specifies whether to swap SPI Tx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxBitEn;           /*!< Specifies whether to swap SPI Rx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapTxByteEn;          /*!< Specifies whether to swap SPI Tx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxByteEn;          /*!< Specifies whether to swap SPI Rx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */
#endif

    FunctionalState SPI_ToggleEn;              /*!< Specifies whether to toggle when transfer done.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint32_t SPI_TxThresholdLevel;             /*!< Specifies the transmit FIFO Threshold.
                                                    This parameter can be a value less than 64.*/

    uint32_t SPI_RxThresholdLevel;             /*!< Specifies the receive FIFO Threshold.
                                                    This parameter can be a value less than 64.*/

    FunctionalState SPI_TxDmaEn;               /*!< Specifies the Tx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_RxDmaEn;               /*!< Specifies the Rx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t SPI_TxWaterlevel;                  /*!< Specifies the DMA tx water level.
                                                    The best value is SPI fifo depth - Tx GDMA MSize. */

    uint8_t SPI_RxWaterlevel;                  /*!< Specifies the DMA rx water level.
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
 * \brief   Deinitializes the SPIx peripheral registers to their default reset values.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 *
 * \return  None.
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
 * \brief   Initializes the SPIx peripheral according to the specified
 *          parameters in the SPI_InitStruct.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_InitStruct: Pointer to a SPI_InitTypeDef structure that
 *            contains the configuration information for the specified SPI peripheral.
 *
 * \return None.
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
 * \brief  Fills each SPI_InitStruct member with its default value.
 *
 * \param[in]  SPI_InitStruct: Pointer to a SPI_InitTypeDef structure which will be initialized.
 *
 * \return None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] NewState: New state of the SPIx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \brief  Transmits a number of bytes through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] pBuf: Bytes to be transmitted.
 * \param[in] len: Byte length to be transmitted.
 *
 * \return None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] pBuf: Halfwords to be transmitted.
 * \param[in] len: Halfwords length to be transmitted.
 *
 * \return None.
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
 * \brief  Transmits a number of words through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] pBuf: Words to be transmitted.
 * \param[in] len: Word length to be transmitted.
 *
 * \return None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_IT: Specifies the SPI interrupt source to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_TXE: Transmit FIFO empty interrupt.
 *            \arg SPI_INT_TXO: Transmit FIFO overflow interrupt.
 *            \arg SPI_INT_RXU: Receive FIFO underflow interrupt.
 *            \arg SPI_INT_RXO: Receive FIFO overflow interrupt.
 *            \arg SPI_INT_RXF: Receive FIFO full interrupt.
 *            \arg SPI_INT_MST: Multi-Master Contention Interrupt.
 *            \arg SPI_INT_FAE: TX Frame Alignment interrupt.
 *            \arg SPI_INT_TUF: Transmit FIFO underflow interrupt.
 *            \arg SPI_INT_RIG: Rising edge detect interrupt.
 * \param[in] NewState: New state of the specified SPI interrupt source.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_IT: Specifies the SPI interrupt to clear.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_TXO: Transmit FIFO Overflow Interrupt.
 *            \arg SPI_INT_RXO: Receive FIFO Overflow Interrupt.
 *            \arg SPI_INT_RXU: Receive FIFO Underflow Interrupt.
 *            \arg SPI_INT_MST: Multi-Master Contention Interrupt.
 *            \arg SPI_INT_FAE: TX Frame Alignment Interrupt.
 *            \arg SPI_INT_TUF: Transmit FIFO Underflow Interrupt.
 *            \arg SPI_INT_RIG: Rising edge detect Interrupt.
 *
 * \return None.
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
 * \brief  Transmits a data through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] Data: Data to be transmitted.
 *
 * \return None.
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
 * \brief   Received data by the SPI peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] dir: Value of direction mode.
 *
 * \return  None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] len: Length of read data which can be 1 to 65536.
 *
 * \return  None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] number: Number can be 0 to 2.
 *
 * \return  None.
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
 * \brief  Check whether the specified SPI interrupt is set.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_IT: Specifies the SPI interrupt to check.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_MST: Multi-Master Contention Interrupt.
 *            \arg SPI_INT_FAE: TX Frame Alignment Interrupt.
 *            \arg SPI_INT_RXF: Receive FIFO Full Interrupt.
 *            \arg SPI_INT_RXO: Receive FIFO Overflow Interrupt.
 *            \arg SPI_INT_RXU: Receive FIFO Underflow Interrupt.
 *            \arg SPI_INT_TXO: Transmit FIFO Overflow Interrupt .
 *            \arg SPI_INT_TXE: Transmit FIFO Empty Interrupt.
 *            \arg SPI_INT_WRAP_TXE: TX NDF mode FIFO Transmit FIFO Empty Interrupt.
 *            \arg SPI_INT_WRAP_TXO: TX NDF mode FIFO Overflow Interrupt.
 *            \arg SPI_INT_WRAP_TXD: TX NDF mode transmit done Interrupt.
 *
 * \return The new state of SPI_IT (SET or RESET).
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
 * \brief  Check whether the specified SPI flag is set.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_FLAG: Specifies the SPI flag to check.
 *            This parameter can be one of the following values:
 *            \arg SPI_FLAG_DCOL: Data Collision Error flag.Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *            \arg SPI_FLAG_TXE: Transmission error flag.Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *            \arg SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *            \arg SPI_FLAG_RFNE: Receive FIFO Not Empty flag.Set if receive FIFO is not empty.
 *            \arg SPI_FLAG_TFE: Transmit FIFO Empty flag.Set if transmit FIFO is empty.
 *            \arg SPI_FLAG_TFNF: Transmit FIFO Not Full flag.Set if transmit FIFO is not full.
 *            \arg SPI_FLAG_BUSY: SPI Busy flag.Set if it is actively transferring data.reset if it is idle or disabled.
 *            \arg SPI_FLAG_TXNDF_BUSY: TX NDF mode Busy flag.
 *            \arg SPI_FLAG_TXNDF_TFNF: TX NDF mode FIFO Not Full flag.
 *            \arg SPI_FLAG_TXNDF_TFE: TX NDF mode FIFO Empty flag.
 *
 * \return The new state of SPI_FLAG (SET or RESET).
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_GDMAReq: Specifies the SPI GDMA transfer request to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg SPI_GDMAReq_Tx: Tx buffer DMA transfer request.
 *            \arg SPI_GDMAReq_Rx: Rx buffer DMA transfer request.
 * \param[in] NewState: New state of the selected SPI GDMA transfer request.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] precalser: Value of prescaler.
 *            This parameter can be one of the following values:
 *            \arg  SPI_BaudRatePrescaler_2
 *            \arg  SPI_BaudRatePrescaler_4
 *            \arg  SPI_BaudRatePrescaler_6
 *            \arg  SPI_BaudRatePrescaler_8
 *            \arg  SPI_BaudRatePrescaler_10
 *            \arg  SPI_BaudRatePrescaler_12
 *            \arg  SPI_BaudRatePrescaler_14
 *            \arg  SPI_BaudRatePrescaler_16
 *            \arg  SPI_BaudRatePrescaler_32
 *            \arg  SPI_BaudRatePrescaler_64
 *            \arg  SPI_BaudRatePrescaler_128
 *            \arg  SPI_BaudRatePrescaler_256
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ChangeClock(SPI0, SPI_BaudRatePrescaler_2);
 * }
 * \endcode
 */
void SPI_ChangeClock(SPI_TypeDef *SPIx, uint32_t prescaler);

/**
 * \brief   Set SPI Rx sample delay.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] delay: This parameter can be 0 to 255.
 *
 * \return  None.
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
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] NewState: new state of the SPIx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None
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
 * \brief   Whether inverse CS active polarity.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] NewState: new state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            \arg  ENABLE: Inverse CS active polarity, which means CS is low active.
 *            \arg  DISABLE: Not inverse CS active polarity, which means CS is high active.
 *
 * \return  None
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
 * \brief   Whether drive MOSI low in idle state.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] NewState: new state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            \arg  ENABLE: Drive MOSI low in idle state.
 *            \arg  DISABLE: Not drive MOSI low in idle state, which means MOSI is Hi-Z in idle state.
 *
 * \return  None
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
 * \brief   Whether enable MOSI pull in idle state.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] NewState: new state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            \arg  ENABLE: MOSI is pull down in idle state.
 *            \arg  DISABLE: MOSI is pull none in idle state.
 *
 * \return  None
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
 * \brief     SPI clock divider config.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] ClockDiv: Specifies the SPI clock divider.
 *            This parameter can be one of the following values:
 *            \arg CLOCK_DIV_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
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
  * \brief  SPI clock config.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void SPI_ClkConfig(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc,
                   SPIClockDiv_TypeDef ClockDiv);

/**
  * \brief  Get SPI clock config.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return The status of get clock.
  */
bool SPI_ClkGet(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef *ClockSrc, SPIClockDiv_TypeDef *ClockDiv);
#endif

#if SPI_SUPPORT_CLOCK_SOURCE_SWTICH
/**
 * rtl876x_rcc.h
 *
 * \brief  SPI clock source switch.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] ClockSource: SPI clock source to switch.
 *            This parameter can be one of the following values:
 *            \arg SPI_CLOCK_SOURCE_40M: Select SPI clock source of 40MHz.
 *            \arg SPI_CLOCK_SOURCE_PLL: Select SPI clock source of PLL.
 *
 * \return None.
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


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

