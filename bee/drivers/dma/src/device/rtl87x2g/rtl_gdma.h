/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_GDMA_H
#define RTL_GDMA_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "rtl_gdma_def.h"

/** \defgroup GDMA        GDMA
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup GDMA_Exported_Constants GDMA Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    GDMA_Channel_Num GDMA Channel Num
 * \{
 * \ingroup     GDMA_Exported_Constants
 */

#define GDMA_CH_NUM0             (0)       //!< GDMA channel number0.
#define GDMA_CH_NUM1             (1)       //!< GDMA channel number1.
#define GDMA_CH_NUM2             (2)       //!< GDMA channel number2.
#define GDMA_CH_NUM3             (3)       //!< GDMA channel number3.
#define GDMA_CH_NUM4             (4)       //!< GDMA channel number4.
#define GDMA_CH_NUM5             (5)       //!< GDMA channel number5.
#if (CHIP_GDMA_CHANNEL_NUM >= 9)
#define GDMA_CH_NUM6             (6)       //!< GDMA channel number6.
#define GDMA_CH_NUM7             (7)       //!< GDMA channel number7.
#define GDMA_CH_NUM8             (8)       //!< GDMA channel number8.
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 10)
#define GDMA_CH_NUM9             (9)       //!< GDMA channel number9.
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 12)
#define GDMA_CH_NUM10            (10)       //!< GDMA channel number10.
#define GDMA_CH_NUM11            (11)       //!< GDMA channel number11.
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 24)
#define GDMA_CH_NUM12            (12)       //!< GDMA channel number12.
#define GDMA_CH_NUM13            (13)       //!< GDMA channel number13.
#define GDMA_CH_NUM14            (14)       //!< GDMA channel number14.
#define GDMA_CH_NUM15            (15)       //!< GDMA channel number15.
#define GDMA_CH_NUM16            (16)       //!< GDMA channel number16.
#define GDMA_CH_NUM17            (17)       //!< GDMA channel number17.
#define GDMA_CH_NUM18            (18)       //!< GDMA channel number18.
#define GDMA_CH_NUM19            (19)       //!< GDMA channel number19.
#define GDMA_CH_NUM20            (20)       //!< GDMA channel number20.
#define GDMA_CH_NUM21            (21)       //!< GDMA channel number21.
#define GDMA_CH_NUM22            (22)       //!< GDMA channel number22.
#define GDMA_CH_NUM23            (23)       //!< GDMA channel number23.
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 33)
#define GDMA_CH_NUM24            (24)       //!< GDMA channel number24.
#define GDMA_CH_NUM25            (25)       //!< GDMA channel number25.
#define GDMA_CH_NUM26            (26)       //!< GDMA channel number26.
#define GDMA_CH_NUM27            (27)       //!< GDMA channel number27.
#define GDMA_CH_NUM28            (28)       //!< GDMA channel number28.
#define GDMA_CH_NUM29            (29)       //!< GDMA channel number29.
#define GDMA_CH_NUM30            (30)       //!< GDMA channel number30.
#define GDMA_CH_NUM31            (31)       //!< GDMA channel number31.
#define GDMA_CH_NUM32            (32)       //!< GDMA channel number32.
#endif

#define IS_GDMA_ChannelNum(NUM)  ((NUM) < CHIP_GDMA_CHANNEL_NUM) //!< Specify the maximum GDMA channel number.

/** End of GDMA_Channel_Num
  * \}
  */

/**
 * \defgroup   GDMA_Data_Transfer_Direction GDMA Data Transfer Direction
 * \{
 * \ingroup    GDMA_Exported_Constants
 */

typedef enum
{
    GDMA_DIR_MemoryToMemory = 0x0,             //!< Configure the direction of GDMA as memory to memory.
    GDMA_DIR_MemoryToPeripheral = 0x1,         //!< Configure the direction of GDMA as memory to peripheral.
    GDMA_DIR_PeripheralToMemory = 0x2,         //!< Configure the direction of GDMA as peripheral to memory.
    GDMA_DIR_PeripheralToPeripheral = 0x3,     //!< Configure the direction of GDMA as peripheral to peripheral.
} GDMADirection_TypeDef;

#define IS_GDMA_DIR(DIR) (((DIR) == GDMA_DIR_MemoryToMemory) || \
                          ((DIR) == GDMA_DIR_MemoryToPeripheral) || \
                          ((DIR) == GDMA_DIR_PeripheralToMemory) || \
                          ((DIR) == GDMA_DIR_PeripheralToPeripheral)) //!< Check if the input parameter is valid.

/** End of GDMA_Data_Transfer_Direction
  * \}
  */

/**
 * \defgroup    GDMA_Source_Incremented_Mode GDMA Source Incremented Mode
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
typedef enum
{
    DMA_SourceInc_Inc = 0x0,        //!< Configure the source address to increment.
#if (GDMA_SUPPORT_ADDRESS_DEC == 1)
    DMA_SourceInc_Dec = 0x1,        //!< Configure the source address to decrement.
#endif
    DMA_SourceInc_Fix = 0x2,        //!< Configure the source address to be fixed.
} GDMASrcInc_TypeDef;

#define IS_GDMA_SourceInc(STATE) (((STATE) == DMA_SourceInc_Inc) || \
                                  ((STATE) == DMA_SourceInc_Dec) || \
                                  ((STATE) == DMA_SourceInc_Fix)) //!< Check if the input parameter is valid.

/** End of GDMA_Source_Incremented_Mode
  * \}
  */

/**
 * \defgroup    GDMA_Destination_Incremented_Mode GDMA Destination Incremented Mode
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
typedef enum
{
    DMA_DestinationInc_Inc = 0x0,    //!< Configure the destination address to increment.
#if (GDMA_SUPPORT_ADDRESS_DEC == 1)
    DMA_DestinationInc_Dec = 0x1,    //!< Configure the destination address to decrement.
#endif
    DMA_DestinationInc_Fix = 0x2,    //!< Configure the destination address to be fixed.
} GDMADestInc_TypeDef;

#define IS_GDMA_DestinationInc(STATE) (((STATE) == DMA_DestinationInc_Inc) || \
                                       ((STATE) == DMA_DestinationInc_Dec) || \
                                       ((STATE) == DMA_DestinationInc_Fix)) //!< Check if the input parameter is valid.

/** End of GDMA_Destination_Incremented_Mode
  * \}
  */

/**
 * \defgroup    GDMA_Data_Size GDMA Data Size
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
typedef enum
{
    GDMA_DataSize_Byte     = 0x0,    //!< Configure the source or destination data size as byte.
    GDMA_DataSize_HalfWord = 0x1,    //!< Configure the source or destination data size as half word.
    GDMA_DataSize_Word     = 0x2,    //!< Configure the source or destination data size as word.
} GDMADataSize_TypeDef;

#define IS_GDMA_DATA_SIZE(SIZE) (((SIZE) == GDMA_DataSize_Byte) || \
                                 ((SIZE) == GDMA_DataSize_HalfWord) || \
                                 ((SIZE) == GDMA_DataSize_Word)) //!< Check if the input parameter is valid.

/** End of GDMA_Data_Size
  * \}
  */

/**
 * \defgroup    GDMA_Msize GDMA Msize
 * \{
 * \ingroup     GDMA_Exported_Constants
 */

typedef enum
{
    GDMA_Msize_1   = 0x0,          //!< Configure the number of data items to be transferred as 1.
    GDMA_Msize_4   = 0x1,          //!< Configure the number of data items to be transferred as 4.
    GDMA_Msize_8   = 0x2,          //!< Configure the number of data items to be transferred as 8.
    GDMA_Msize_16  = 0x3,          //!< Configure the number of data items to be transferred as 16.
    GDMA_Msize_32  = 0x4,          //!< Configure the number of data items to be transferred as 32.
    GDMA_Msize_64  = 0x5,          //!< Configure the number of data items to be transferred as 64.
    GDMA_Msize_128 = 0x6,          //!< Configure the number of data items to be transferred as 128.
    GDMA_Msize_256 = 0x7,          //!< Configure the number of data items to be transferred as 256.
} GDMAMSize_TypeDef;

#define IS_GDMA_MSIZE(SIZE) (((SIZE) == GDMA_Msize_1) || \
                             ((SIZE) == GDMA_Msize_4) || \
                             ((SIZE) == GDMA_Msize_8) || \
                             ((SIZE) == GDMA_Msize_16) || \
                             ((SIZE) == GDMA_Msize_32) || \
                             ((SIZE) == GDMA_Msize_64) || \
                             ((SIZE) == GDMA_Msize_128) || \
                             ((SIZE) == GDMA_Msize_256)) //!< Check if the input parameter is valid.

/** End of GDMA_Msize
  * \}
  */

/**
 * \defgroup    GDMA_Interrupts  GDMA Interrupts
 * \{
 * \ingroup     GDMA_Exported_Constants
 */

#define GDMA_INT_Transfer               (BIT0)  //!< The interrupt is generated on GDMA transfer completion to the destination.
#define GDMA_INT_Block                  (BIT1)  //!< The interrupt is generated on GDMA block transfer completion to the destination.
#define GDMA_INT_Error                  (BIT4)  //!< The interrupt is generated when an ERROR response is received from the slave on the SRESP bus during a GDMA transfer.
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
#define GDMA_INT_Half_Block             (BIT5)  //!< The interrupt is generated on GDMA half block transfer completion to the destination.
#endif

#define IS_GDMA_CONFIG_IT(IT) ((((IT) & 0xFFFFFFE0) == 0x00) && ((IT) != 0x00)) //!< Check if the input parameter is valid.

/** End of GDMA_Interrupts
  * \}
  */

/**
 * \defgroup    GDMA_Multi-block_Mode GDMA Multi-block Mode
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
#define AUTO_RELOAD_WITH_CONTIGUOUS_SAR (BIT31)  //!< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to auto-reload.
#define AUTO_RELOAD_WITH_CONTIGUOUS_DAR (BIT30)  //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to continuous.
#define AUTO_RELOAD_TRANSFER            (BIT30 | BIT31)  //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to auto-reload.
#define LLI_WITH_CONTIGUOUS_SAR         (BIT27)  //!< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to LLI.
#define LLI_WITH_AUTO_RELOAD_SAR        (BIT27 | BIT30)  //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to LLI.
#define LLI_WITH_CONTIGUOUS_DAR         (BIT28)  //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to continuous.
#define LLI_WITH_AUTO_RELOAD_DAR        (BIT28 | BIT31)  //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to auto-reload.
#define LLI_TRANSFER                    (BIT27 | BIT28)  //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to LLI.

#define IS_GDMA_MULTIBLOCKMODE(MODE) (((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_SAR) || \
                                      ((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_DAR) || \
                                      ((MODE) == AUTO_RELOAD_TRANSFER) || \
                                      ((MODE) == LLI_WITH_CONTIGUOUS_SAR) || \
                                      ((MODE) == LLI_WITH_AUTO_RELOAD_SAR) || \
                                      ((MODE) == LLI_WITH_CONTIGUOUS_DAR) || \
                                      ((MODE) == LLI_WITH_AUTO_RELOAD_DAR) || \
                                      ((MODE) == LLI_TRANSFER)) //!< Check if the input parameter is valid.

/** End of GDMA_Multi-block_Mode
  * \}
  */

/**
 * \defgroup    GDMA_Multi-Block_Select_Bit GDMA Multi-Block Select Bit
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
#define AUTO_RELOAD_SELECTED_BIT        (BIT30 | BIT31)   //!< The bit for GDMA auto-reload.
#define LLP_SELECTED_BIT                (BIT27 | BIT28)   //!< The bit for GDMA LLI.

/** End of GDMA_Multi-Block_Select_Bit
  * \}
  */

/**
 * \defgroup    GDMA_Suspend_Flag GDMA Suspend Flag
 * \{
 * \ingroup     GDMA_Exported_Constants
 */
#define GDMA_FIFO_STATUS                (BIT(9))                //!< The bit for GDMA fifo status.
#define GDMA_SUSPEND_TRANSMISSSION      (BIT(8))                //!< The bit for GDMA suspend transmisssion.
#define GDMA_SUSPEND_CMD_STATUS         (BIT(2) | BIT(1))       //!< The bit for GDMA suspend command.
#define GDMA_SUSPEND_CHANNEL_STATUS     (BIT(0))                //!< The bit for GDMA suspend channel status.

/** End of GDMA_Suspend_Flag
  * \}
  */

/** End of GDMA_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup GDMA_Exported_Types GDMA Exported Types
  * \brief
  * \{
  */

/**
 * \brief       GDMA init structure definition.
 *
 * \ingroup     GDMA_Exported_Types
 */

typedef struct
{
    uint8_t GDMA_ChannelNum;                /*!< Specify the channel number for GDMA.
                                                 This parameter can be set from 0 to 9. Refer to \ref GDMA_Channel_Num. */

    GDMADirection_TypeDef GDMA_DIR;         /*!< Specify transfer direction.
                                                 This parameter can be a value of \ref GDMA_Data_Transfer_Direction. */

    uint32_t GDMA_BufferSize;               /*!< Specify the buffer size(RTL8762G <= 65535, RTL8772F: GDMA1 is 65535 and GDMA2 is 524287).
                                                 The data unit is equal to the configuration set in DMA_PeripheralDataSize
                                                 or DMA_MemoryDataSize members depending in the transfer direction. */

    GDMASrcInc_TypeDef
    GDMA_SourceInc;      /*!< Specify whether the source address register is incremented or not.
                                                 This parameter can be a value of \ref GDMA_Source_Incremented_Mode. */

    GDMADestInc_TypeDef
    GDMA_DestinationInc; /*!< Specify whether the destination address register is incremented or not.
                                                  This parameter can be a value of \ref GDMA_Destination_Incremented_Mode. */

    GDMADataSize_TypeDef GDMA_SourceDataSize; /*!< Specify the source data width.
                                                   This parameter can be a value of \ref GDMA_Data_Size. */

    GDMADataSize_TypeDef GDMA_DestinationDataSize; /*!< Specify the destination data width.
                                                        This parameter can be a value of \ref GDMA_Data_Size. */

    GDMAMSize_TypeDef GDMA_SourceMsize;     /*!< Specify items number to be transferred.
                                                 This parameter can be a value of \ref GDMA_Msize. */

    GDMAMSize_TypeDef GDMA_DestinationMsize;/*!< Specify items number to be transferred.
                                                 This parameter can be a value of \ref GDMA_Msize. */

    uint32_t GDMA_SourceAddr;               /*!< Specify the source base address for GDMA Channelx. */

    uint32_t GDMA_DestinationAddr;          /*!< Specify the destination base address for GDMA Channelx. */

    uint32_t GDMA_ChannelPriority;          /*!< Specify the software priority for the GDMA Channelx.
                                                 This parameter can be a value of 0~9(RTL8762G); 0~7 for GDMA1 and 0~15 for GDMA2(RTL8772F). */

    uint32_t GDMA_Multi_Block_Mode;         /*!< Specify the multi block transfer mode. */

    uint32_t GDMA_Multi_Block_Struct;       /*!< Pointer to the first struct of LLI. */

    uint8_t GDMA_Multi_Block_En;            /*!< Enable or disable multi-block function.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    uint8_t GDMA_SourceHandshake;           /*!< Specify the handshake index in source.
                                                 This parameter can be a value of \ref GDMA_Handshake_Type. */

    uint8_t GDMA_DestHandshake;             /*!< Specify the handshake index in Destination.
                                                This parameter can be a value of \ref GDMA_Handshake_Type. */
#if (GDMA_SUPPORT_SECURE_MODE == 1)
    uint8_t GDMA_Secure_En;                 /*!< Enable or disable Secure function. */
#endif

#if (GDMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    uint8_t  GDMA_Gather_En;                /*!< Enable or disable Gather function. NOTE:4 bytes ALIGN.*/
    uint32_t GDMA_GatherCount;              /*!< Specify the GatherCount.NOTE:4 bytes ALIGN.*/
    uint32_t GDMA_GatherInterval;           /*!< Specify the GatherInterval. */
    uint8_t  GDMA_Scatter_En;               /*!< Enable or disable Scatter function. */
    uint32_t GDMA_ScatterCount;             /*!< Specify the ScatterCount. */
    uint32_t GDMA_ScatterInterval;          /*!< Specify the ScatterInterval. */
    uint32_t GDMA_GatherCircularStreamingNum;  /*!< Specify the GatherCircularStreamingNum. */
    uint32_t GDMA_ScatterCircularStreamingNum; /*!< Specify the ScatterCircularStreamingNum. */
#endif

} GDMA_InitTypeDef;

/**
 * \brief       GDMA link list item structure definition.
 *
 * \ingroup     GDMA_Exported_Types
 */

typedef struct
{
    __IO uint32_t SAR;          /*!< Specify the source base address for LLI. */
    __IO uint32_t DAR;          /*!< Specify the destination base address for LLI. */
    __IO uint32_t LLP;          /*!< Specify the next pointer to the struct of LLI. */
    __IO uint32_t CTL_LOW;      /*!< Specify the CTL_LOW register for LLI. */
    __IO uint32_t CTL_HIGH;     /*!< Specify the CTL_HIGH register for LLI. */
} GDMA_LLIDef;

/** End of GDMA_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup GDMA_Exported_Functions GDMA Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Deinitialize the GDMA registers to their default reset values.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     GDMA_DeInit();
 * }
 * \endcode
 */
void GDMA_DeInit(void);

/**
 * \brief     Initialize the GDMA Channelx according to the specified
 *            parameters in the GDMA_InitStruct.
 *
 * \param[in] GDMA_Channelx    Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] GDMA_InitStruct  Pointer to a GDMA_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     for (uint32_t i = 0; i < UART_TX_GDMA_BUFFER_SIZE; i++)
 *     {
 *         GDMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = 1;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = UART_TX_GDMA_BUFFER_SIZE;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendData_Buffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA0_Handshake_UART0_TX;
 *     GDMA_InitStruct.GDMA_ChannelPriority = 2;
 *     GDMA_Init(UART_TX_GDMA_CHANNEL, &GDMA_InitStruct);
 *
 *     GDMA_INTConfig(UART_TX_GDMA_CHANNEL_NUM, GDMA_INT_Transfer, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_GDMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     GDMA_Cmd(UART_TX_GDMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void GDMA_Init(GDMA_ChannelTypeDef *GDMA_Channelx, GDMA_InitTypeDef *GDMA_InitStruct);

/**
 * \brief     Fill each GDMA_InitStruct member with its default value.
 *
 * \param[in] GDMA_InitStruct  Pointer to a GDMA_InitTypeDef structure which will be initialized.
 *
 * \note   The default settings for the GDMA_InitStruct member are shown in the following table:
 *         | GDMA_InitStruct member      | Default value                      |
 *         |:---------------------------:|:----------------------------------:|
 *         | GDMA_ChannelNum             | \ref GDMA_CH_NUM0                 |
 *         | GDMA_DIR                    | \ref GDMA_DIR_PeripheralToMemory   |
 *         | GDMA_BufferSize             | 200                                |
 *         | GDMA_SourceInc              | \ref DMA_SourceInc_Fix             |
 *         | GDMA_DestinationInc         | \ref DMA_DestinationInc_Inc        |
 *         | GDMA_SourceDataSize         | \ref GDMA_DataSize_Byte            |
 *         | GDMA_DestinationDataSize    | \ref GDMA_DataSize_Byte            |
 *         | GDMA_SourceMsize            | \ref GDMA_Msize_1                  |
 *         | GDMA_DestinationMsize       | \ref GDMA_Msize_1                  |
 *         | GDMA_SourceAddr             | 0                                  |
 *         | GDMA_DestinationAddr        | 0                                  |
 *         | GDMA_ChannelPriority        | 0                                  |
 *         | GDMA_Multi_Block_Mode       | \ref LLI_TRANSFER                  |
 *         | GDMA_SourceHandshake        | 0                                  |
 *         | GDMA_DestHandshake          | 0                                  |
 *         | GDMA_Multi_Block_En         | DISABLE                            |
 *         | GDMA_Scatter_En             | DISABLE                            |
 *         | GDMA_Gather_En              | DISABLE                            |
 *         | GDMA_Source_Cir_Gather_Num  | 1                                  |
 *         | GDMA_Dest_Cir_Sca_Num       | 1                                  |
 *         | GDMA_Multi_Block_Struct     | 0                                  |
 *         | GDMA_ScatterCount           | 0                                  |
 *         | GDMA_ScatterInterval        | 0                                  |
 *         | GDMA_GatherCount            | 0                                  |
 *         | GDMA_GatherInterval         | 0                                  |
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_GDMA_BUFFER_SIZE; i++)
 *     {
 *         GDMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = 1;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = UART_TX_GDMA_BUFFER_SIZE;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendData_Buffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA0_Handshake_UART0_TX;
 *     GDMA_InitStruct.GDMA_ChannelPriority = 2;
 *     GDMA_Init(UART_TX_GDMA_CHANNEL, &GDMA_InitStruct);
 *
 * }
 * \endcode
 */
void GDMA_StructInit(GDMA_InitTypeDef *GDMA_InitStruct);

/**
 * \brief  Enable or disable the selected GDMA channel.
 *
 * \param[in]  GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 * \param[in]  NewState         New state of the selected DMA channel.
 *                              This parameter can be one of the following values:
 *                              - ENABLE: Enable the selected GDMA channel.
 *                              - DISABLE: Disable the selected GDMA channel.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_GDMA_BUFFER_SIZE; i++)
 *     {
 *         GDMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = 1;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = UART_TX_GDMA_BUFFER_SIZE;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendData_Buffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA0_Handshake_UART0_TX;
 *     GDMA_InitStruct.GDMA_ChannelPriority = 2;
 *     GDMA_Init(UART_TX_GDMA_CHANNEL, &GDMA_InitStruct);
 *
 *     GDMA_INTConfig(UART_TX_GDMA_CHANNEL_NUM, GDMA_INT_Transfer, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_GDMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     GDMA_Cmd(UART_TX_GDMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void GDMA_Cmd(uint8_t GDMA_ChannelNum, FunctionalState NewState);

/**
 * \brief   Enable or disable the specified DMA channelx interrupt source.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 * \param[in] GDMA_IT          Specify the GDMA interrupt source to be enabled or disabled.
 *                             This parameter can be any combination of the following values.
 *                             Refer to \ref GDMA_Interrupts.
 *                             \arg GDMA_INT_Transfer: Transfer complete interrupt source.
 *                             \arg GDMA_INT_Block: Block transfer interrupt source.
 *                             \arg GDMA_INT_Error: Transfer error interrupt source.
 *                             \arg GDMA_INT_Half_Block: Half Block transfer interrupt source.
 * \param[in] NewState         New state of the specified DMA interrupt source.
 *                             This parameter can be one of the following values:
 *                             - ENABLE: Enable the specified GDMA channelx interrupt source.
 *                             - DISABLE: Disable the specified GDMA channelx interrupt source.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_GDMA_BUFFER_SIZE; i++)
 *     {
 *         GDMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = 1;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = UART_TX_GDMA_BUFFER_SIZE;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendData_Buffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA0_Handshake_UART0_TX;
 *     GDMA_InitStruct.GDMA_ChannelPriority = 2;
 *     GDMA_Init(UART_TX_GDMA_CHANNEL, &GDMA_InitStruct);
 *
 *     GDMA_INTConfig(UART_TX_GDMA_CHANNEL_NUM, GDMA_INT_Transfer, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_GDMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     GDMA_Cmd(UART_TX_GDMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void GDMA_INTConfig(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT, FunctionalState NewState);

/**
 * \brief     Get the GDMA channel transfer interrupt status.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * \return   Transfer interrupt status.
 *          - SET: The GDMA channel transfer interrupt has been set.
 *          - RESET: The GDMA channel transfer interrupt has been reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     ITStatus int_status = GDMA_GetTransferINTStatus(GDMA_CH_NUM0);
 * }
 * \endcode
 */
ITStatus GDMA_GetTransferINTStatus(uint8_t GDMA_ChannelNum);

/**
 * \brief  Clear the specified DMA channelx interrupt pending bit.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 * \param[in] GDMA_IT          Specify the GDMA interrupts sources to be enabled or disabled.
 *                             This parameter can be any combination of the following values.
 *                             Refer to \ref GDMA_Interrupts.
 *                             - GDMA_INT_Transfer: Transfer complete interrupt source.
 *                             - GDMA_INT_Block: Block transfer interrupt source.
 *                             - GDMA_INT_Error: Transfer error interrupt source.
 *                             - GDMA_INT_Half_Block: Half Block transfer interrupt source.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     driver_gdma_init();
 * }
 *
 * void UART_TX_GDMA_Handler(void)
 * {
 *     GDMA_ClearINTPendingBit(GDMA_CH_NUM1, GDMA_INT_Transfer);
 *     //Add user code here.
 * }
 * \endcode
 */
void GDMA_ClearINTPendingBit(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT);

/**
 * \brief     Clear GDMAx Channelx all type interrupt.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_ClearAllTypeINT(GDMA_CH_NUM2);
 * }
 * \endcode
 */
void GDMA_ClearAllTypeINT(uint8_t GDMA_ChannelNum);

/**
 * \brief   Get selected GDMA channel status.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * \return  GDMA channel status.
 *          -SET: Channel is be used
 *          -RESET: Channel is free.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     FlagStatus flag_status = GDMA_GetChannelStatus(GDMA_CH_NUM3);
 * }
 * \endcode
 */
FlagStatus GDMA_GetChannelStatus(uint8_t GDMA_ChannelNum);

#if (GDMA_SUPPORT_SECURE_MODE == 1)
/**
 * \brief     Enable or disable the specified DMA channel secure function.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] NewState       Specify the GDMA channel secure function.
 *                           This parameter can be one of the following values:
 *                           - ENABLE: Enable the specified DMA channel secure function.
 *                           - DISABLE: Disable the specified DMA channel secure function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SecureCmd(GDMA_Channel3, ENABLE);
 * }
 *
 * \endcode
 */
void GDMA_SecureCmd(GDMA_ChannelTypeDef *GDMA_Channelx, FunctionalState NewState);
#endif

#if (GDMA_SUPPORT_OSW_OSR_CHANGE == 1)
/**
 * \brief     Set GDMA OSW.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 * \param[in] osw_count        Outstanding write count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SetOSW(GDMA_CH_NUM0, 10);
 * }
 * \endcode
 */
void GDMA_SetOSW(uint8_t GDMA_ChannelNum, uint8_t osw_count);

/**
 * \brief  Set GDMA OSR.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 * \param[in] osr_count        Outstanding read count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SetOSR(GDMA_CH_NUM0, 10);
 * }
 * \endcode
 */
void GDMA_SetOSR(uint8_t GDMA_ChannelNum, uint8_t osr_count);

/**
 * \brief     Get GDMA OSW.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * \return    osw_count: outstanding write count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t osw_count = GDMA_GetOSWCount(GDMA_CH_NUM0);
 * }
 * \endcode
 */
uint8_t GDMA_GetOSWCount(uint8_t GDMA_ChannelNum);

/**
 * \brief     Get GDMA OSR.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * \return    osr_count: outstanding read count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint8_t osr_count = GDMA_GetOSRCount(GDMA_CH_NUM0);
 * }
 * \endcode
 */
uint8_t GDMA_GetOSRCount(uint8_t GDMA_ChannelNum);
#endif

/**
 * \brief     Set GDMA transmission source address.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] Address        Source address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     GDMA_SetSourceAddress(GDMA2_Channel0,(uint32_t)data_buf);
 * }
 * \endcode
 */
void GDMA_SetSourceAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address);

/**
 * \brief     Set GDMA transmission destination address.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] Address        Destination address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     GDMA_SetDestinationAddress(GDMA_Channel0,(uint32_t)data_buf);
 * }
 * \endcode
 */
void GDMA_SetDestinationAddress(GDMA_ChannelTypeDef *GDMA_Channelx,
                                uint32_t Address);

/**
 * \brief     Set GDMA LLP stucture address.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] Address        LLP stucture address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_LLIDef GDMA_LLIStruct[4000];
 *     GDMA_SetLLPAddress(GDMA2_Channel0,(uint32_t)GDMA_LLIStruct);
 * }
 * \endcode
 */
void GDMA_SetLLPAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address);

/**
 * \brief     Set GDMA buffer size.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] buffer_size    Set GDMA_BufferSize, max 65535 for RTL8762G (RTL8772F: GDMA1 is 65535 and GDMA2 is 524287).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf_size = 4095;
 *     GDMA_SetBufferSize(GDMA_Channel0,data_buf_size);
 * }
 * \endcode
 */
void GDMA_SetBufferSize(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t buffer_size);

/**
 * \brief  Get GDMA source address.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 *
 * \return Source address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t address = GDMA_GetSrcTransferAddress(GDMA2_Channel0);
 * }
 * \endcode
 */
uint32_t GDMA_GetSrcTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 * \brief  Get GDMA destination address.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 *
 * \return Destination address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t address = GDMA_GetDstTransferAddress(GDMA2_Channel0);
 * }
 * \endcode
 */
uint32_t GDMA_GetDstTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx);
/**
 * \brief     Get GDMA transfer data length.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 *
 * \return    GDMA transfer data length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint16_t data_len = GDMA_GetTransferLen(GDMA2_Channel0);
 * }
 * \endcode
 */
uint16_t GDMA_GetTransferLen(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 * \brief     Check GDMA FIFO status.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 *
 * \return GDMA FIFO status.
 *         - SET: FIFO empty.
 *         - RESET: FIFO not empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     FlagStatus flag_status = GDMA_GetFIFOStatus(GDMA2_Channel0);
 * }
 * \endcode
 */
FlagStatus GDMA_GetFIFOStatus(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 * \brief     Suspend GDMA transmission from the source.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] NewState       New state of the GDMAx Channelx.
 *                           This parameter can be one of the following values:
 *                           - ENABLE: Enable suspend GDMA transmission.
 *                           - DISABLE: Disable suspend GDMA transmission.
 *
 * \note       To prevent data loss, it is necessary to check whether FIFO data transmission is completed
 *             after suspend, and judge by checking whether GDMA FIFO is empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SuspendCmd(GDMA2_Channel0, ENABLE);
 * }
 * \endcode
 */
void GDMA_SuspendCmd(GDMA_ChannelTypeDef *GDMA_Channelx,
                     FunctionalState NewState);

/**
 * \brief     Get GDMA Channelx of the specified DMA Channel Number.
 *
 * \param[in] GDMA_ChannelNum  Select the GDMA channel number. Refer to \ref GDMA_Channel_Num.
 *
 * \return    GDMA_Channelx.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     uint8_t channel_num = GDMA_CH_NUM0;
 *     GDMA_ChannelTypeDef *GDMA_Channelx = GDMA_GetGDMAChannelx(channel_num);
 * }
 * \endcode
 */
GDMA_ChannelTypeDef *GDMA_GetGDMAChannelx(uint8_t GDMA_ChannelNum);

/**
 * \brief  Update GDMA LLP mode in multi-block.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 * \param[in] mode           GDMA LLP mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SetLLPMode(GDMA_Channel0, LLI_TRANSFER);
 * }
 * \endcode
 */
void GDMA_SetLLPMode(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t mode);

/**
 * \brief  Suspend GDMA transmission safe from the source. Please check GDMA FIFO empty to guarnatee without losing data.
 *
 * \param[in] GDMA_Channelx  Select the GDMA peripheral. Refer to \ref GDMA_Declaration.
 *
 * \return The result of suspend GDMA transmission.
 *         - true: suspend GDMA transmission success.
 *         - false: suspend GDMA transmission failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SafeSuspend(GDMA_Channel0);
 * }
 * \endcode
 */
bool GDMA_SafeSuspend(GDMA_ChannelTypeDef *GDMA_Channelx);

/** End of GDMA_Exported_Functions
  * \}
  */

/** End of GDMA
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GDMA_H */


