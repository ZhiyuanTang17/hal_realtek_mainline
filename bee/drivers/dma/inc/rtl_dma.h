/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_DMA_H
#define RTL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "dma/src/device/rtl87x2g/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "dma/src/device/rtl87x3e/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "dma/src/device/rtl87x3d/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "dma/src/device/rtl87x2j/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3EU)
#include "dma/src/device/rtl87x3eu/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "dma/src/device/rtl87x3j/rtl_dma_def.h"
#endif

/** \defgroup DMA        DMA
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup DMA_Exported_Constants DMA Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    DMA_CHANNEL_NUM DMA CHANNEL NUM
 * \{
 * \ingroup     DMA_Exported_Constants
 */

#define DMA_CH_NUM0             (0)
#define DMA_CH_NUM1             (1)
#define DMA_CH_NUM2             (2)
#define DMA_CH_NUM3             (3)
#define DMA_CH_NUM4             (4)
#define DMA_CH_NUM5             (5)
#if (CHIP_DMA_CHANNEL_NUM >= 9)
#define DMA_CH_NUM6             (6)
#define DMA_CH_NUM7             (7)
#define DMA_CH_NUM8             (8)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 10)
#define DMA_CH_NUM9             (9)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 12)
#define DMA_CH_NUM10            (10)
#define DMA_CH_NUM11            (11)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 16)
#define DMA_CH_NUM12            (12)
#define DMA_CH_NUM13            (13)
#define DMA_CH_NUM14            (14)
#define DMA_CH_NUM15            (15)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 24)
#define DMA_CH_NUM16            (16)
#define DMA_CH_NUM17            (17)
#define DMA_CH_NUM18            (18)
#define DMA_CH_NUM19            (19)
#define DMA_CH_NUM20            (20)
#define DMA_CH_NUM21            (21)
#define DMA_CH_NUM22            (22)
#define DMA_CH_NUM23            (23)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 27)
#define DMA_CH_NUM24            (24)
#define DMA_CH_NUM25            (25)
#define DMA_CH_NUM26            (26)
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 33)
#define DMA_CH_NUM27            (27)
#define DMA_CH_NUM28            (28)
#define DMA_CH_NUM29            (29)
#define DMA_CH_NUM30            (30)
#define DMA_CH_NUM31            (31)
#define DMA_CH_NUM32            (32)
#endif

#define IS_DMA_ChannelNum(NUM)  ((NUM) < CHIP_DMA_CHANNEL_NUM)

/** End of DMA_Define
  * \}
  */

/**
 * \defgroup   DMA_Data_Transfer_Direction DMA Data Transfer Direction
 * \{
 * \ingroup    DMA_Exported_Constants
 */

typedef enum
{
    DMA_DIR_MEMORY_TO_MEMORY = 0x0,
    DMA_DIR_MEMORY_TO_PERIPHERAL = 0x1,
    DMA_DIR_PERIPHERAL_TO_MEMORY = 0x2,
    DMA_DIR_PERIPHERAL_TO_PERIPHERAL = 0x3,
#if (DMA_SUPPORT_PERIPHERAL_FLOW_CONTROL == 1)
    DMA_DIR_PERIPHERAL_TO_MEMORY_FLOW_CTRL = 0x4,
    DMA_DIR_MEMORY_TO_PERIPHERAL_FLOW_CTRL = 0x6,
#endif
} DMADirection_TypeDef;

#define IS_DMA_DIR(DIR) (((DIR) == DMA_DIR_MEMORY_TO_MEMORY) || \
                         ((DIR) == DMA_DIR_MEMORY_TO_PERIPHERAL) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_MEMORY) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_PERIPHERAL) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_MEMORY_FLOW_CTRL) || \
                         ((DIR) == DMA_DIR_MEMORY_TO_PERIPHERAL_FLOW_CTRL))

/** End of DMA_Data_Transfer_Direction
  * \}
  */

/**
 * \defgroup    DMA_Source_Mode DMA Source Mode
 * \{
 * \ingroup     DMA_Exported_Constants
 */
typedef enum
{
    DMA_SOURCE_INC = 0x0,
#if (DMA_SUPPORT_ADDRESS_DECREASE == 1)
    DMA_SOURCE_DEC = 0x1,
#endif
    DMA_SOURCE_FIX = 0x2,
} DMASrcMode_TypeDef;

#define IS_DMA_SOURCE_MODE(MODE) (((MODE) == DMA_SOURCE_INC) || \
                                  ((MODE) == DMA_SOURCE_DEC) || \
                                  ((MODE) == DMA_SOURCE_FIX))

/** End of DMA_Source_Mode
  * \}
  */

/**
 * \defgroup    DMA_Destination_Mode DMA Destination Mode
 * \{
 * \ingroup     DMA_Exported_Constants
 */
typedef enum
{
    DMA_DESTINATION_INC = 0x0,
#if (DMA_SUPPORT_ADDRESS_DECREASE == 1)
    DMA_DESTINATION_DEC = 0x1,
#endif
    DMA_DESTINATION_FIX = 0x2,
} DMADestMode_TypeDef;

#define IS_DMA_DESTINATION_MODE(MODE) (((MODE) == DMA_DESTINATION_INC) || \
                                       ((MODE) == DMA_DESTINATION_DEC) || \
                                       ((MODE) == DMA_DESTINATION_FIX))

/** End of DMA_Destination_Mode
  * \}
  */

/**
 * \defgroup    DMA_Data_Size DMA Data Size
 * \{
 * \ingroup     DMA_Exported_Constants
 */
typedef enum
{
    DMA_DATA_SIZE_BYTE           = 0x0,
    DMA_DATA_SIZE_HALFWORD       = 0x1,
    DMA_DATA_SIZE_WORD           = 0x2,
#if (DMA_SUPPORT_DATA_SIZE_DOUBLE_WORD == 1)
    DMA_DATA_SIZE_DOUBLEWORD     = 0x3,
#endif
    DMA_DATA_SIZE_MAX,
} DMADataSize_TypeDef;

#define IS_DMA_DATA_SIZE(SIZE) ((SIZE) < DMA_DATA_SIZE_MAX)

/** End of DMA_Data_Size
  * \}
  */

/**
 * \defgroup    DMA_Msize DMA Msize
 * \{
 * \ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_MSIZE_1   = 0x0,
    DMA_MSIZE_4   = 0x1,
    DMA_MSIZE_8   = 0x2,
    DMA_MSIZE_16  = 0x3,
    DMA_MSIZE_32  = 0x4,
#if (DMA_SUPPORT_MSIZE_64 == 1)
    DMA_MSIZE_64  = 0x5,
#endif
#if (DMA_SUPPORT_MSIZE_128 == 1)
    DMA_MSIZE_128 = 0x6,
#endif
#if (DMA_SUPPORT_MSIZE_256 == 1)
    DMA_MSIZE_256 = 0x7,
#endif
    DMA_MSIZE_MAX,
} DMAMSize_TypeDef;

#define IS_DMA_MSIZE(SIZE) ((SIZE) < DMA_MSIZE_MAX)

/** End of DMA_Msize
  * \}
  */

#if (DMA_SUPPORT_AUTO_SLOW_CONFIG == 1)
/**
 * \defgroup    DMA_AutoSlow DMA Auto Slow
 * \{
 * \ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE  = 0x0,
    DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE = 0x1,
} DMAAutoSlow_TypeDef;

#define IS_DMA_AUTO_SLOW(MODE) (((MODE) == DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE) || \
                                ((MODE) == DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE))

/** End of DMA_AutoSlow
  * \}
  */
#endif
/**
 * \defgroup    DMA_Interrupts  DMA Interrupts
 * \{
 * \ingroup     DMA_Exported_Constants
 */

#define DMA_INT_TRANSFER               (BIT0)
#define DMA_INT_BLOCK                  (BIT1)
#define DMA_INT_ERROR                  (BIT4)
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
#define DMA_INT_HALF_BLOCK             (BIT5)
#endif
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
#define DMA_INT_BLOCK_COUNTER          (BIT6)
#endif

#define IS_DMA_CONFIG_IT(IT) ((((IT) & 0xFFFFFFE0) == 0x00) && ((IT) != 0x00))

/** End of DMA_Interrupts
  * \}
  */

/**
 * \defgroup    DMA_Multi-block_Mode DMA Multi-block Mode
 * \{
 * \ingroup     DMA_Exported_Constants
 */
#define AUTO_RELOAD_WITH_CONTIGUOUS_SAR (BIT31)
#define AUTO_RELOAD_WITH_CONTIGUOUS_DAR (BIT30)
#define AUTO_RELOAD_TRANSFER            (BIT30 | BIT31)
#define LLI_WITH_CONTIGUOUS_SAR         (BIT27)
#define LLI_WITH_AUTO_RELOAD_SAR        (BIT27 | BIT30)
#define LLI_WITH_CONTIGUOUS_DAR         (BIT28)
#define LLI_WITH_AUTO_RELOAD_DAR        (BIT28 | BIT31)
#define LLI_TRANSFER                    (BIT27 | BIT28)

#define IS_DMA_MULTIBLOCKMODE(MODE) (((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_SAR) || \
                                     ((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_DAR) || \
                                     ((MODE) == AUTO_RELOAD_TRANSFER) || \
                                     ((MODE) == LLI_WITH_CONTIGUOUS_SAR) || \
                                     ((MODE) == LLI_WITH_AUTO_RELOAD_SAR) || \
                                     ((MODE) == LLI_WITH_CONTIGUOUS_DAR) || \
                                     ((MODE) == LLI_WITH_AUTO_RELOAD_DAR) || \
                                     ((MODE) == LLI_TRANSFER))

/** End of DMA_Multi-block_Mode
  * \}
  */

/**
 * \defgroup    DMA_Multi-Block_Select_Bit DMA Multi-Block Select Bit
 * \{
 * \ingroup     DMA_Exported_Constants
 */
#define AUTO_RELOAD_SELECTED_BIT        (BIT30 | BIT31)
#define LLP_SELECTED_BIT                (BIT27 | BIT28)

/** End of DMA_Multi-Block_Select_Bit
  * \}
  */

/** End of DMA_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup DMA_Exported_Types DMA Exported Types
  * \brief
  * \{
  */

/**
 * \brief       DMA init structure definition.
 *
 * \ingroup     DMA_Exported_Types
 */

typedef struct
{
    uint8_t DMA_ChannelNum;               /*!< Specifies channel number for DMA. */

    DMADirection_TypeDef DMA_Direction;   /*!< Specifies transfer direction. */

    uint32_t DMA_BufferSize;              /*!< Specifies the buffer size(RTL8762G <= 65535, RTL8772F: DMA1 is 65535 and DMA2 is 524287).
                                               The data unit is equal to the configuration set in DMA_PeripheralDataSize
                                               or DMA_MemoryDataSize members depending in the transfer direction. */

    DMASrcMode_TypeDef DMA_SourceInc;     /*!< Specifies whether the source address
                                               register is incremented or not. */

    DMADestMode_TypeDef DMA_DestinationInc; /*!< Specifies whether the destination address
                                                 register is incremented or not.*/

    DMADataSize_TypeDef DMA_SourceDataSize; /*!< Specifies the source data width. */

    DMADataSize_TypeDef DMA_DestinationDataSize; /*!< Specifies the destination data width. */

    DMAMSize_TypeDef DMA_SourceMsize;     /*!< Specifies items number to be transferred. */

    DMAMSize_TypeDef DMA_DestinationMsize;/*!< Specifies items number to be transferred. */

    uint32_t DMA_SourceAddr;              /*!< Specifies the source base address for DMA Channelx. */

    uint32_t DMA_DestinationAddr;         /*!< Specifies the destination base address for DMA Channelx. */

    uint32_t DMA_ChannelPriority;         /*!< Specifies the software priority for the DMA Channelx.
                                                This parameter can be a value of 0~9(RTL8762G); 0~7 for DMA1 and 0~15 for DMA2(RTL8772F). */

    uint32_t DMA_MultiBlockMode;          /*!< Specifies the multi block transfer mode.
                                                This parameter can be a value of \ref DMA_Multiblock_Mode. */

    uint32_t DMA_MultiBlockStruct;      /*!< Pointer to the first struct of LLI. */

    uint8_t DMA_MultiBlockEn;           /*!< Enable or disable multi-block function. */

    uint8_t DMA_SourceHandshake;          /*!< Specifies the handshake index in source.
                                               This parameter can be a value of \ref DMA_Handshake_Type. */

    uint8_t DMA_DestHandshake;            /*!< Specifies the handshake index in Destination.
                                               This parameter can be a value of \ref DMA_Handshake_Type. */

#if (DMA_SUPPORT_SECURE_MODE == 1)
    uint8_t DMA_SecureEn;                /*!< Enable or disable Secure function. */
#endif

#if (DMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    uint8_t  DMA_GatherEn;               /*!< Enable or disable Gather function. NOTE:4 bytes ALIGN.*/
    uint32_t DMA_GatherCount;             /*!< Specifies the GatherCount.NOTE:4 bytes ALIGN.*/
    uint32_t DMA_GatherInterval;          /*!< Specifies the GatherInterval. */
    uint8_t  DMA_ScatterEn;              /*!< Enable or disable Scatter function. */
    uint32_t DMA_ScatterCount;            /*!< Specifies the ScatterCount. */
    uint32_t DMA_ScatterInterval;         /*!< Specifies the ScatterInterval. */
    uint32_t DMA_GatherCircularStreamingNum;  /*!< Specifies the GatherCircularStreamingNum. */
    uint32_t DMA_ScatterCircularStreamingNum; /*!< Specifies the ScatterCircularStreamingNum. */
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
    FunctionalState DMA_ContSarEn;        /**< Enable or disable DMA continuous source
                                                address between single block interrupt. */

    FunctionalState DMA_ContDarEn;        /**< Enable or disable DMA continuous destination
                                                address between single block interrupt. */
#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    uint32_t DMA_BlockCounter;            /*!< Specifies the block counter.
                                                After each block transfer is completed, 1 is
                                                subtracted from the block counter until it reaches
                                                0, at which point it can no longer be reduced. */
#endif

} DMA_InitTypeDef;

/**
 * \brief       DMA link list item structure definition.
 *
 * \ingroup     DMA_Exported_Types
 */

typedef struct
{
    __IO uint32_t SAR;
    __IO uint32_t DAR;
    __IO uint32_t LLP;
    __IO uint32_t CTL_LOW;
    __IO uint32_t CTL_HIGH;
} DMA_LLIDef;

/** End of DMA_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup DMA_Exported_Functions DMA Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Deinitializes the DMA registers to their default reset
 *            values.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     DMA_DeInit();
 * }
 * \endcode
 */
void DMA_DeInit(void);

/**
 * \brief     Initializes the DMA Channelx according to the specified
 *            parameters in the DMA_InitStruct.
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] DMA_InitStruct: Pointer to a DMA_InitTypeDef structure that
 *            contains the configuration information for the specified DMA Channel.
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCEINC_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATIONINC_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_Msize_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_Msize_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void DMA_Init(DMA_ChannelTypeDef *DMA_Channelx, DMA_InitTypeDef *DMA_InitStruct);

/**
 * \brief     Fills each DMA_InitStruct member with its default value.
 *
 * \param[in] DMA_InitStruct : pointer to a DMA_InitTypeDef structure which will
 *            be initialized.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCEINC_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATIONINC_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_Msize_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_Msize_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 * }
 * \endcode
 */
void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct);

/**
 * \brief  Enables or disables the selected DMA channel.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 * \param[in]  NewState: New state of the selected DMA channel.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCEINC_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATIONINC_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_Msize_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_Msize_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void DMA_Cmd(uint8_t DMA_ChannelNum, FunctionalState NewState);

/**
 * \brief   Enables or disables the specified DMA channelx interrupt source.
 * \param[in] DMA_Channel_Num: can be 0 to 9 to select the DMA Channel(for RTL8762G, 3 to 26 for RTL8772F).
 * \param[in] DMA_IT: Specifies the DMA interrupt source to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg DMA_INT_TRANSFER: Transfer complete interrupt source.
 *            \arg DMA_INT_Block: Block transfer interrupt source.
 *            \arg DMA_INT_Error: Transfer error interrupt source.
 *            \arg DMA_INT_Half_Block: Half Block transfer interrupt source.
 * \param[in] NewState: New state of the specified DMA interrupt source.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCEINC_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATIONINC_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DataSize_Byte;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_Msize_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_Msize_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
void DMA_INTConfig(uint8_t DMA_ChannelNum, uint32_t DMA_IT, FunctionalState NewState);

/**
 * \brief     Check whether DMA Channel transfer interrupt is set.
 *
 * \param[in] DMA_Channel_Num: can be 0 to 9 to select the DMA Channel(for RTL8762G, 3 to 26 for RTL8772F).
 *
 * \return    Transfer interrupt status, SET or RESET.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     ITStatus int_status = DMA_GetTransferINTStatus(0);
 * }
 * \endcode
 */
ITStatus DMA_GetTransferINTStatus(uint8_t DMA_ChannelNum);

/**
  * \brief  Check whether DMA Channel block interrupt is set.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM.
  * \param  DMA_IT: specifies the DMA interrupts status to get.
  *         This parameter can be any combination of the following values:
  *         \arg DMA_INT_TRANSFER:  Transfer complete interrupt status.
  *         \arg DMA_INT_BLOCK:  Block transfer interrupt status.
  *         \arg DMA_INT_ERROR :  Transfer error interrupt status.
  *         \arg DMA_INT_HALF_BLOCK: Half Block transfer interrupt status.
  *         \arg DMA_INT_BLOCK_COUNTER: Block counter interrupt status.
  * \return Block interrupt status, SET or RESET.
  */
ITStatus DMA_GetINTStatus(uint8_t DMA_ChannelNum, uint32_t DMA_IT);

/**
 * \brief  Clear the specified DMA channelx interrupt pending bit.
 * \param[in] DMA_Channel_Num: can be 0 to 9 to select the DMA Channel(for RTL8762G, 3 to 26 for RTL8772F).
 * \param[in] DMA_IT: Specifies the DMA interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg DMA_INT_TRANSFER: Transfer complete interrupt source.
 *            \arg DMA_INT_Block: Block transfer interrupt source.
 *            \arg DMA_INT_Error: Transfer error interrupt source.
 *            \arg DMA_INT_Half_Block: Half Block transfer interrupt source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     driver_dma_init();
 * }
 *
 * void UART_TX_DMA_Handler(void)
 * {
 *     DMA_ClearINTPendingBit(1, DMA_INT_TRANSFER);
 *     //Add user code here.
 * }
 * \endcode
 */
void DMA_ClearINTPendingBit(uint8_t DMA_ChannelNum, uint32_t DMA_IT);

/**
 * \brief     Clear DMAx Channelx all type interrupt.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_ClearAllTypeINT(DMA2, 0);
 * }
 * \endcode
 */
void DMA_ClearAllTypeINT(uint8_t DMA_ChannelNum);

/**
 * \brief   Get selected DMA channel status.
 *
 * \param[in] DMA_Channel_Num: can be 0 to 9 to select the DMA Channel(for RTL8762G, 3 to 26 for RTL8772F).
 *
 * \return  DMA channel status.
 * \retval  SET: Channel is be used
 * \retval  RESET: Channel is free.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     FlagStatus flag_status = DMA_GetChannelStatus(3);
 * }
 * \endcode
 */
FlagStatus DMA_GetChannelStatus(uint8_t DMA_ChannelNum);

/**
 * \brief     Check DMA FIFO status.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 *
 * \return DMA FIFO status.
 * \retval SET: FIFO empty.
 * \retval RESET: FIFO not empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     FlagStatus flag_status = DMA_GetFIFOStatus(DMA2_Channel0);
 * }
 * \endcode
 */
FlagStatus DMA_GetFIFOStatus(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * \brief      Suspend DMA transmission from the source.
 *
 * \param[in]  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in]  NewState: New state of the DMAx Channelx.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return     None.
 * \note       To prevent data loss, it is necessary to check whether FIFO data transmission is completed
 *             after suspend, and judge by checking whether DMA FIFO is empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SuspendCmd(DMA2_Channel0, ENABLE);
 * }
 * \endcode
 */
void DMA_SuspendCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

/**
 * rtl_dma.h
 *
 * \brief  Suspend DMA transmission safe from the source. Please check DMA FIFO empty to guarnatee without losing data.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 *
 * \return The result of suspend DMA transmission.
 * \retval true: suspend DMA transmission success.
 * \retval false: suspend DMA transmission failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_rx_dma_ch_num = 0xa5;
 * #define UART_RX_DMA_CHANNEL_NUM   uart_rx_dma_ch_num
 * #define UART_RX_DMA_CHANNEL       DMA_CH_BASE(uart_rx_dma_ch_num)
 *
 * void dma_demo(void)
 * {
 *     DMA_SafeSuspend(UART_RX_DMA_CHANNEL);
 *     //Add user code here.
 * }
 * \endcode
 */
bool DMA_SafeSuspend(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * \brief      Set DMA transmission source address.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in]  Address: Source address.
 *
 * \return     None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     DMA_SetSourceAddress(DMA2_Channel0,(uint32_t)data_buf);
 * }
 * \endcode
 */
void DMA_SetSourceAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address);

/**
 * \brief     Set DMA transmission destination address.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] Address: Destination address.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     DMA_SetDestinationAddress(DMA_Channel0,(uint32_t)data_buf);
 * }
 * \endcode
 */
void DMA_SetDestinationAddress(DMA_ChannelTypeDef *DMA_Channelx,
                               uint32_t Address);

/**
 * \brief     Set DMA LLP stucture address.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] Address: LLP stucture address.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_LLIDef DMA_LLIStruct[4000];
 *     DMA_SetLLPAddress(DMA2_Channel0,(uint32_t)DMA_LLIStruct);
 * }
 * \endcode
 */
void DMA_SetLLPAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address);

/**
 * \brief     Set DMA buffer size.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] buffer_size: Set DMA_BufferSize, max 65535 for RTL8762G (RTL8772F: DMA1 is 65535 and DMA2 is 524287).
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf_size = 4095;
 *     DMA_SetBufferSize(DMA_Channel0,data_buf_size);
 * }
 * \endcode
 */
void DMA_SetBufferSize(DMA_ChannelTypeDef *DMA_Channelx, uint32_t buffer_size);

/**
 * \brief  Get DMA source address.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 *
 * \return Source address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetSrcTransferAddress(DMA2_Channel0);
 * }
 * \endcode
 */
uint32_t DMA_GetSrcTransferAddress(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * \brief  Get DMA destination address.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 *
 * \return Destination address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetDstTransferAddress(DMA2_Channel0);
 * }
 * \endcode
 */
uint32_t DMA_GetDstTransferAddress(DMA_ChannelTypeDef *DMA_Channelx);
/**
 * \brief     Get DMA transfer data length.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 *
 * \return    DMA transfer data length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint16_t data_len = DMA_GetTransferLen(DMA2_Channel0);
 * }
 * \endcode
 */
uint16_t DMA_GetTransferLen(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * rtl876x_dma.h
 *
 * \brief  Update DMA LLP mode in multi-block.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] DMA LLP mode
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetLLPMode(LLI_TRANSFER);
 * }
 * \endcode
 */
void DMA_SetLLPMode(DMA_ChannelTypeDef *DMA_Channelx, uint32_t mode);

/**
 * \brief     Get DMA Channelx of the specified DMA Channel Number.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 *
 * \return    DMA_Channelx.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     uint8_t channel_num = DMA_ChannelNum;
 *     DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);
 * }
 * \endcode
 */
DMA_ChannelTypeDef *DMA_GetDMAChannelx(uint8_t DMA_ChannelNum);

/**
 * \brief     Get DMA IRQx of the specified DMA Channel Number.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 *
 * \return    DMA_IRQx.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     IRQn_Type irqx;
 *     IRQn_Type irqx = DMA_GetDMAIRQx(DMA_ChannelNum);
 * }
 * \endcode
 */
IRQn_Type DMA_GetDMAIRQx(uint8_t DMA_ChannelNum);

/**
 * \brief     Get DMA number by the specified DMA IRQx.
 *
 * \param[in]  irq: Select the DMA IRQx.
 *
 * \return    DMA number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     uint8_t dma_num;
 *     dma_num = DMA_GetDMANumByIRQx(DMA1_CH0_IRQn);
 * }
 * \endcode
 */
uint8_t DMA_GetDMANumByIRQx(IRQn_Type irq);

#if (DMA_SUPPORT_SECURE_MODE == 1)
/**
 * \brief     Enable or disable the specified DMA channel secure functions.
 *
 * \param[in] DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param[in] NewState: Specifies the DMA channel secure function to be enabled or disabled.
 *            This parameter can be ENABLE or DISABLE.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SecureCmd(DMA_Channel3, ENABLE);
 * }
 *
 * \endcode
 */
void DMA_SecureCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);
#endif

#if (DMA_SUPPORT_OSW_OSR_CHANGE == 1)
/**
 * \brief     Set DMA OSW.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 * \param[in] osw_count: outstanding write count.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetOSW(DMA_Channel0, 10);
 * }
 * \endcode
 */
void DMA_SetOSW(uint8_t DMA_ChannelNum, uint8_t osw_count);

/**
 * \brief  Set DMA OSR.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 * \param[in] osr_count: outstanding read count.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetOSR(DMA_Channel0, 10);
 * }
 * \endcode
 */
void DMA_SetOSR(uint8_t DMA_ChannelNum, uint8_t osr_count);

/**
 * \brief     Get DMA OSW.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 *
 * \return    osw_count: outstanding write count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t osw_count = DMA_GetOSWCount(DMA_Channel0);
 * }
 * \endcode
 */
uint8_t DMA_GetOSWCount(uint8_t DMA_ChannelNum);

/**
 * \brief     Get DMA OSR.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
 *
 * \return    osr_count: outstanding read count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint8_t osr_count = DMA_GetOSRCount(DMA_Channel0);
 * }
 * \endcode
 */
uint8_t DMA_GetOSRCount(uint8_t DMA_ChannelNum);
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)

void DMA_ContSarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

void DMA_ContDarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)

void DMA_SetBlockCounter(DMA_ChannelTypeDef *DMA_Channelx, uint32_t block_counter);

#endif

#if (DMA_SUPPORT_RAP_FUNCTION == 1)

bool DMA_RAPModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

#endif

#if (DMA_SUPPORT_AUTO_CLOCK == 1)

void DMA_ClockAutoModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState Newstate);

#endif

#if (DMA_SUPPORT_AUTO_SLOW_CONFIG == 1)
/**
 * \brief     DMA auto slow config.
 *
 * \param[in]  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM.
 *
 * \param[in]  AutoSlowMode: Select the DMA auto slow mode. \ref DMAAutoSlow_TypeDef.
 *            This parameter can be any combination of the following values:
 *            - DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE: DMA not allow auto slow when DMA enable but in idle state.
 *            - DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE: DMA allow auto slow when DMA enable but in idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_AutoSlowConfig(0, DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE);
 * }
 * \endcode
 */
void DMA_AutoSlowConfig(uint8_t DMA_ChannelNum, DMAAutoSlow_TypeDef AutoSlowMode);
#endif
/** End of DMA_Exported_Functions
  * \}
  */

/** End of DMA
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_DMA_H */




