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
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "spi/src/device/rtl87x2g/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "spi/src/device/rtl87x3e/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "spi/src/device/rtl87x3d/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "spi/src/device/rtl87x2j/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "spi/src/device/rtl87x3j/rtl_spi_def.h"
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
 * \defgroup    SPI_Direction SPI Direction
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_DIRECTION_FULLDUPLEX = 0x00,
    SPI_DIRECTION_TXONLY     = 0x01,
    SPI_DIRECTION_RXONLY     = 0x02,
    SPI_DIRECTION_EEPROM     = 0x03,
} SPIDirection_TypeDef;

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_DIRECTION_FULLDUPLEX) || \
                                     ((MODE) == SPI_DIRECTION_TXONLY) || \
                                     ((MODE) == SPI_DIRECTION_RXONLY) || \
                                     ((MODE) == SPI_DIRECTION_EEPROM))

/** End of SPI_Direction
  * \}
  */

/**
 * \defgroup    SPI_Data_Size SPI Data Size
 * \{
 * \ingroup     SPI_Exported_Constants
 */

typedef enum
{
    SPI_DATA_SIZE_4b  = 0x03,
    SPI_DATA_SIZE_5b  = 0x04,
    SPI_DATA_SIZE_6b  = 0x05,
    SPI_DATA_SIZE_7b  = 0x06,
    SPI_DATA_SIZE_8b  = 0x07,
    SPI_DATA_SIZE_9b  = 0x08,
    SPI_DATA_SIZE_10b = 0x09,
    SPI_DATA_SIZE_11b = 0x0a,
    SPI_DATA_SIZE_12b = 0x0b,
    SPI_DATA_SIZE_13b = 0x0c,
    SPI_DATA_SIZE_14b = 0x0d,
    SPI_DATA_SIZE_15b = 0x0e,
    SPI_DATA_SIZE_16b = 0x0f,
#if (SPI_SUPPORT_DFS_4BIT_TO_16BIT == 0)
    SPI_DATA_SIZE_17b = 0x10,
    SPI_DATA_SIZE_18b = 0x11,
    SPI_DATA_SIZE_19b = 0x12,
    SPI_DATA_SIZE_20b = 0x13,
    SPI_DATA_SIZE_21b = 0x14,
    SPI_DATA_SIZE_22b = 0x15,
    SPI_DATA_SIZE_23b = 0x16,
    SPI_DATA_SIZE_24b = 0x17,
    SPI_DATA_SIZE_25b = 0x18,
    SPI_DATA_SIZE_26b = 0x19,
    SPI_DATA_SIZE_27b = 0x1A,
    SPI_DATA_SIZE_28b = 0x1B,
    SPI_DATA_SIZE_29b = 0x1C,
    SPI_DATA_SIZE_30b = 0x1D,
    SPI_DATA_SIZE_31b = 0x1E,
    SPI_DATA_SIZE_32b = 0x1F,
#endif
} SPIDataSize_TypeDef;

#if (SPI_SUPPORT_DFS_4BIT_TO_16BIT == 1)
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DATA_SIZE_4b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_5b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_6b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_7b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_8b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_9b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_10b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_11b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_12b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_13b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_14b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_15b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_16b))

#else
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DATA_SIZE_4b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_5b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_6b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_7b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_8b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_9b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_10b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_11b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_12b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_13b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_14b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_15b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_16b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_17b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_18b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_19b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_20b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_21b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_22b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_23b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_24b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_25b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_26b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_27b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_28b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_29b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_30b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_31b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_32b))
#endif

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
    SPI_CPOL_LOW = 0x00,
    SPI_CPOL_HIGH = 0x01,
} SPIClockPolarity_TypeDef;

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_LOW) || \
                           ((CPOL) == SPI_CPOL_HIGH))

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
    SPI_CPHA_1EDGE = 0x00,
    SPI_CPHA_2EDGE = 0x01,
} SPIClockPhase_TypeDef;

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1EDGE) || \
                           ((CPHA) == SPI_CPHA_2EDGE))

/** End of SPI_Clock_Phase
  * \}
  */

/**
 * \defgroup    SPI_BaudRate_Prescaler SPI BaudRate Prescaler
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_BAUDRATE_PRESCALER_2   = 0x02,
    SPI_BAUDRATE_PRESCALER_4   = 0x04,
    SPI_BAUDRATE_PRESCALER_6   = 0x06,
    SPI_BAUDRATE_PRESCALER_8   = 0x08,
    SPI_BAUDRATE_PRESCALER_10  = 0x0A,
    SPI_BAUDRATE_PRESCALER_12  = 0x0C,
    SPI_BAUDRATE_PRESCALER_14  = 0x0E,
    SPI_BAUDRATE_PRESCALER_16  = 0x10,
    SPI_BAUDRATE_PRESCALER_32  = 0x20,
    SPI_BAUDRATE_PRESCALER_64  = 0x40,
    SPI_BAUDRATE_PRESCALER_128 = 0x80,
    SPI_BAUDRATE_PRESCALER_256 = 0x100,
} SPIBaudRatePrescaler_TypeDef;

#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFF)

/** End of SPI_BaudRate_Prescaler
  * \}
  */

#if (SPI_FIXED_FRAME_FORMAT == 0)
/**
 * \defgroup    SPI_Frame_Format SPI Frame Format
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_FRAME_MOTOROLA      = 0x00,
    SPI_FRAME_TI_SSP        = 0x01,
    SPI_FRAME_NS_MICROWIRE  = 0x02,
    SPI_FRAME_RESERVE       = 0x03,
} SPIFrameFormat_TypeDef;

#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_FRAME_MOTOROLA) || \
                                    ((FRAME) == SPI_Frame_TI_SSP) || \
                                    ((FRAME) == SPI_Frame_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_FRAME_RESERVE))

/** End of SPI_Frame_Format
  * \}
  */
#endif

/**
 * \defgroup    SPI_DMA_Transfer_Request SPI DMA Transfer Request
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_DMA_REQ_RX = 0x01,
    SPI_DMA_REQ_TX = 0x02,
#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_DMA_REQ_TX = 0x03,
#endif
} SPIDMARequests_TypeDef;

#if (SPI_SUPPORT_WRAP_MODE == 0)
#define IS_SPI_DMAREQ(REQ) (((REQ) == SPI_DMA_REQ_RX) || \
                            ((REQ) == SPI_DMA_REQ_TX))
#else
#define IS_SPI_DMAREQ(REQ) (((REQ) == SPI_DMA_REQ_RX) || \
                            ((REQ) == SPI_DMA_REQ_TX) || \
                            ((REQ) == SPI_WRAP_DMA_REQ_TX))
#endif

/** End of SPI_DMA_Transfer_Request
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
    SPI_MODE_MASTER = ((uint16_t)0x0104),
    SPI_MODE_SLAVE  = ((uint16_t)0x0000)
} SPIMode_Typedef;

#define IS_SPI_MODE(MODE) (((MODE) == SPI_MODE_MASTER) || \
                           ((MODE) == SPI_MODE_SLAVE))

/** End of SPI_mode
  * \}
  */
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
/**
 * \defgroup    SPI_Wrap_CS_Clock_Divider SPI Wrap CS Clock Divider
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_WRAP_CS_CLOCK_DIV_1 = 0x0,
    SPI_WRAP_CS_CLOCK_DIV_2 = 0x1,
    SPI_WRAP_CS_CLOCK_DIV_4 = 0x2,
    SPI_WRAP_CS_CLOCK_DIV_8 = 0x3,
    SPI_WRAP_CS_CLOCK_DIV_16 = 0x4,
    SPI_WRAP_CS_CLOCK_DIV_32 = 0x5,
    SPI_WRAP_CS_CLOCK_DIV_64 = 0x6,
    SPI_WRAP_CS_CLOCK_DIV_128 = 0x7,
    SPI_WRAP_CS_CLOCK_DIV_256 = 0x8,
} SPIWrapCSClockDiv_TypeDef;

/** End of SPI_Wrap_CS_Clock_Divider
  * \}
  */

#endif

/**
 * \defgroup    SPI_ActionEvent SPI Action Event
 * \{
 * \ingroup     SPI_Exported_Constants
 */
#if (SPI_SUPPORT_RAP_FUNCTION == 1)
typedef enum
{
    SPI_ACTION_START  = 0,
    SPI_EVENT_START = 1,
    SPI_EVENT_END   = 2,
} SPIActionEvent_TypeDef;
#endif

/** End of SPI_ActionEvent
  * \}
  */

#if (SPI_SUPPORT_REPEAT_MODE == 1)
/**
 * \defgroup    SPI_Repeat_Reg_Mode SPI Repeat Register Mode
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_REPEAT_WRAPPER_FIFO = 0x00, /*!< Repeat data output from wrapper FIFO. */
    SPI_REPEAT_NORMAL_FIFO = 0x01,  /*!< Repeat data output from SPI data register. */
} SPIRepeatMode_TypeDef;

/** End of SPI_Repeat_Reg_Mode
  * \}
  */

/**
 * \defgroup    SPI_Repeat_Transfer_Size SPI Repeat Transfer Size
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_REPEAT_SIZE_8BIT = 0x00, /*!< 8bit mode. */
    SPI_REPEAT_SIZE_16BIT = 0x01,  /*!< 16bit mode. */
} SPIRepeatSize_TypeDef;

/** End of SPI_Repeat_Transfer_Size
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
    SPIDirection_TypeDef SPI_Direction;        /*!< Specifies the SPI unidirectional
                                                    or bidirectional data mode. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
    uint32_t SPI_TXNDF;                        /*!< Specifies the trigger condition in TxOnly or FullDuplex mode.
                                                    This parameter sets the number of data frames to be continuously transmitted,
                                                    from 1 to 65536. */

    FunctionalState SPI_CSHighActiveEn;        /*!< Specifies whether to enable CS high active.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_WrapModeEn;            /*!< Specifies the TX waper mode (TX NDF) enable.
                                                    Only SPI1 have txndf mode.
                                                    ENABLE: Hardware won't automatically pull
                                                    SPI_CSN high when TX FIFO is empty.
                                                    DISABLE: SPI_CSN pull high when
                                                    TX data number = SPI_TXNDF+1.*/

    FunctionalState SPI_WrapModeDMAEn;      /*!< Specifies the TX waper mode(TX NDF) DMA enable. */

    uint8_t  SPI_WrapTxThresholdLevel;      /*!< Specifies the wrapper transmit FIFO Threshold.
                                                This parameter can be a value equal or less than SPI_WRAPPER_TX_FIFO_SIZE. */

    uint8_t  SPI_WrapTxWaterlevel;           /*!< Specifies the TX NDF DMA tx water.
                                                  The best value is SPI_WRAPPER_TX_FIFO_SIZE - Tx GDMA MSize. */

    SPIWrapCSClockDiv_TypeDef SPI_WrapCSClockDiv;  /*!< Specifies the CS clock divider.
                                                  This parameter can be a value of \ref SPI_Wrap_CS_Clock_Divider. */

    uint8_t SPI_WrapCSHoldDlyCount;             /*!< Specifies the CS hold delay count.
                                                     The hold delay time = cs_divider * (hold_delay_count + 2.5) * 25ns.
                                                     This parameter can be a value from 0 to 15. */
    uint8_t SPI_WrapCSSetupDlyCount;            /*!< Specifies the CS setup delay count.
                                                     The setup delay time = cs_divider * (setup_delay_count + 1) * 25ns.
                                                     This parameter can be a value from 0 to 15. */
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
#if (SPI_FIXED_FRAME_FORMAT == 0)
    SPIFrameFormat_TypeDef SPI_FrameFormat;    /*!< Specifies frame format which serial
                                                    protocol transfers the data. */
#endif
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
                                                    This parameter can be a value equal or less than SPI_TX_FIFO_SIZE. */

    uint32_t SPI_RxThresholdLevel;             /*!< Specifies the receive FIFO Threshold.
                                                    This parameter can be a value equal or less than SPI_RX_FIFO_SIZE. */

    FunctionalState SPI_TxDMAEn;               /*!< Specifies the Tx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_RxDMAEn;               /*!< Specifies the Rx dma mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t SPI_TxWaterlevel;                  /*!< Specifies the DMA tx water level.
                                                    The best value is SPI_TX_FIFO_SIZE - Tx GDMA MSize. */

    uint8_t SPI_RxWaterlevel;                  /*!< Specifies the DMA rx water level.
                                                    The best value is SPI Rx DMA MSize. */
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
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);

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
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);

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
 * \brief  Enables or disables the selected SPI peripheral.
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
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);
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
 * \brief  Transmits a number of bytes through the SPIx peripheral without polling.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref SPI_Declaration.
 * \param[in] pBuf: Bytes to be transmitted.
 * \param[in] len: Byte length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_buf[] = {0x01,0x02,0x03};
 *     SPI_SendBufferDirect(SPI0, data_buf, sizeof(data_buf));
 * }
 * \endcode
 */
void SPI_SendBufferDirect(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len);

/**
 * \brief  Transmits a number of halfWords through the SPIx peripheral.
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
 * \brief  Transmits a number of halfWords through the SPIx peripheral without polling.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref SPI_Declaration.
 * \param[in] pBuf: Halfwords to be transmitted.
 * \param[in] len: Halfwords length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWordDirect(SPI0, data_buf, sizeof(data_buf)/sizeof(uint16_t));
 * }
 * \endcode
  */
void SPI_SendHalfWordDirect(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

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
 * \brief  Transmits a number of words through the SPIx peripheral without polling.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref SPI_Declaration.
 * \param[in] pBuf: Words to be transmitted.
 * \param[in] len: Word length to be transmitted.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWordDirect(SPI0, data_buf, sizeof(data_buf)/sizeof(uint32_t));
 * }
 * \endcode
 */
void SPI_SendWordDirect(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);

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
 *     SPI_SetDirection(SPI0, SPI_Direction_EEPROM);
 * }
 * \endcode
 */
void SPI_SetDirection(SPI_TypeDef *SPIx, uint16_t dir);

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
 * \brief   Enables or disables the SPIx DMA interface.
 *
 * \param[in] SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param[in] SPI_DMAReq: Specifies the SPI DMA transfer request to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg SPI_DMAReq_Tx: Tx buffer DMA transfer request.
 *            \arg SPI_DMAReq_Rx: Rx buffer DMA transfer request.
 * \param[in] NewState: New state of the selected SPI DMA transfer request.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_DMACmd(SPI0, SPI_DMAReq_Tx, ENABLE);
 * }
 * \endcode
 */
void SPI_DMACmd(SPI_TypeDef *SPIx, SPIDMARequests_TypeDef SPI_DMAReq,
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
 *     SPI_SetPrescaler(SPI0, SPI_BaudRatePrescaler_2);
 * }
 * \endcode
 */
void SPI_SetPrescaler(SPI_TypeDef *SPIx, uint32_t prescaler);

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
 * \brief   Enables or disables the specified SPI wrap mode start transfer.
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

void SPI_WrapModeSetTxNdf(SPI_TypeDef *SPIx, uint16_t tx_ndf);

void SPI_WrapModeResetTxFIFO(SPI_TypeDef *SPIx);
#endif

#if SPI_SUPPORT_CLOCK_SOURCE_CONFIG
/**
  * \brief  SPI clock config.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void SPI_SetClock(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc, SPIClockDiv_TypeDef ClockDiv);
#endif

#if (SPI_SUPPORT_RAP_FUNCTION == 1)

void SPI_RAPModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState);

void SPI_SetActionCmdNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_SetActionWaitNum(SPI_TypeDef *SPIx, uint16_t num);

void SPI_SetActionTransferNum(SPI_TypeDef *SPIx, uint16_t num);

void SPI_ActionTrigger(SPI_TypeDef *SPIx, uint32_t task);

bool SPI_ActionEventStsCheck(SPI_TypeDef *SPIx, uint32_t te);

void SPI_ActionEventStsClear(SPI_TypeDef *SPIx, uint32_t te);

void SPI_SetActionTransfer(SPI_TypeDef *SPIx, uint8_t cmd_len, uint16_t wati_cnt,
                           uint16_t dummy_len);

#endif

#if (SPI_SUPPORT_AUTO_CLOCK == 1)

void SPI_ClockAutoModeCmd(SPI_TypeDef *SPIx, FunctionalState Newstate);

#endif

#if (SPI_SUPPORT_REPEAT_MODE == 1)

void SPI_SetRepeatMode(SPI_TypeDef *SPIx, SPIRepeatMode_TypeDef mode);
void SPI_SetRepeatSize(SPI_TypeDef *SPIx, SPIRepeatSize_TypeDef size);
void SPI_SendRepeatData(SPI_TypeDef *SPIx, uint32_t data_l, uint32_t data_h);

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




