/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_sdhc.h
* \brief    The header file of the peripheral SDHC driver.
* \details  This file provides all SDHC(SD Host Controller) firmware functions.
* \author   Bert
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_SDHC_H
#define RTL_SDHC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_sdhc_reg.h"

/*============================================================================*
 *                          Private Functions
 *============================================================================*/
extern void *gSDHC0Sem;
extern void *gSDHC1Sem;

/** \defgroup 87X2G_SDHC        SDHC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup SDHC_Exported_Constants SDHC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    SDHC_Macros SDHC Macros
 * \{
 * \ingroup     SDHC_Exported_Constants
 */
#define SDHC0_IRQn          SDHC_IRQn
#define SDHC1_IRQn          SDHC_IRQn
#define SDHC0_Handler       SDHC_Handler

/** End of SDHC_Macros
  * \}
  */

/**
 * \defgroup    MAX_BLOCK_PER_DESC MAX BLOCK PER DESC
 * \{
 * \ingroup     SDHC_Exported_Constants
 */
#define DESC_CNT  4
#define MAX_BLOCK_PER_DESC  16
#define BYTES_PER_BLOCK  512

#define MAX_BYTES_PER_DESC  (MAX_BLOCK_PER_DESC * BYTES_PER_BLOCK)
#define MAX_BLOCK_PER_XFER  (MAX_BLOCK_PER_DESC * DESC_CNT)
#define MAX_BYTES_PER_XFER  (MAX_BYTES_PER_DESC * DESC_CNT)

/** End of MAX_BLOCK_PER_DESC
  * \}
  */

#ifndef NDEBUG
#include "trace.h"
#include "utils.h"
#define ASSERT(e) \
    do { \
        if(!(e)) { \
            platform_delay_ms(1000); \
            DBG_DIRECT("(" #e ") assert failed! Func: %s. Line: %d.", __func__, __LINE__); \
            DBG_DIRECT("(" #e ") assert failed! Func: %s. Line: %d.", __func__, __LINE__); \
            *(volatile int *)0x1 = 0; \
        } \
    } while(0)
#else
#define ASSERT(e) ((void)0)
#endif // NDEBUG

/**
 * \brief       Specifies the data width.
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    DATAWIDTH_1BIT,
    DATAWIDTH_4BIT,
    DATAWIDTH_8BIT,
    DATAWIDTH_4BIT_DDR,
    DATAWIDTH_8BIT_DDR,
} DataWidth_t;

/**
 * \brief       Specifies the data transfer direction,
 *              whether the transfer is a read or write.
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    READ_DATA = 0,
    WRITE_DATA = 1,
} SDHC_TransferDir_t;

/**
 * \brief       Specifies whether data transfer is in stream or block mode.
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    BLOCK_TRANSFER = 0,
    STREAM_TRANSFER = 1,
} SDHC_TransferMode_t;

/**
 * \brief       Specifies whether data transfer by dma or host.
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    OWN_BY_HOST = 0,
    OWN_BY_DMA = 1,
} SDHC_TransferDma_t;

/**
 * \brief       SDHC Clock Source Selection
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    CLKSRC_CLK_40M_VCORE4 = 0,
    CLKSRC_CKO1_PLL1_VCORE4 = 1,
    CLKSRC_CKO1_PLL2_VCORE4 = 3,
} ClockSrcSel_t;


/**
 * \brief       SDHC Result Error
 *
 * \ingroup     SDHC_Exported_Constants
 */
typedef enum
{
    SDHCRES_OK = 0,

    SDHCRES_HARDWARE_LOCKED_ERROR, // 1
    SDHCRES_RESPONSE_ERROR,
    SDHCRES_RESPONSE_CRC_ERROR,
    SDHCRES_RESPONSE_TIMEOUT,

    SDHCRES_DATA_CRC_ERROR, // 5
    SDHCRES_DATA_READ_TIMEOUT,
    SDHCRES_DATA_START_BIT_ERROR,
    SDHCRES_DATA_END_BIT_ERROR,
    SDHCRES_WRITE_NO_CRC, // 9

    SDHCRES_FATAL_BUS_ERROR,
    SDHCRES_DESCRIPTOR_UNAVAILABLE,
    SDHCRES_CARD_ERROR, // 12

    SDHCRES_WAIT_DATA0_IDLE_TIMEOUT,
} SDHCRes_t;

/** End of SDHC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup SDHC_Exported_Types SDHC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       SDHC init structure definition.
 *
 * \ingroup     SDHC_Exported_Types
 */
typedef struct
{
    uint8_t CmdIdx;        /*!< Specifies the SDHC command index. It must be lower than 0x40 */

    uint32_t CmdArg;       /*!< Specifies the SDHC command argument which is sent
                                to a card as part of a command message. If a command
                                contains an argument, it must be loaded into this register
                                before writing the command to the command register */

    bool IsResetCmd;       /*!< Specifies whether Send initialization sequence before sending
                                this command After power on.
                                Such as CMD0 is ResetCmd */

    bool IsStopCmd;        /*!< Specifies whether stop current data transfer in progress.
                                Such as CMD12 is StopCmd */

    bool IsRspExpected;    /*!< Specifies wethcer response is expected from card.
                                Such as CMD0, CMD4, CMD15... have no response */

    bool IsR2Rsp;          /*!< Specifies wethcer long response is expected from card.
                                Such as R2 is long response.*/

    bool CheckRspCrc;      /*!< Specifies wethcer check response CRC.
                                Some of command responses do not return valid CRC bits,
                                such as ACMD41 for eMMC and CMD8 for SD.*/
} CmdInfo_t;


typedef struct
{
    uint32_t BlockSize;    /*!< Specifies the data block size for block transfer.
                                This parameter usually is 512 bytes */

    uint32_t BlockCount;   /*!< Specifies the block counts you want to transfer */

    bool SendAutoStop;     /*!< Specifies wethcer send stop command at end of data transfer.
                                Such as CMD12 will be sent automatically after data transfer. */
} DataInfo_t;


typedef struct
{
    struct
    {
        uint32_t Reserved0: 1;
        uint32_t DisableInterruptOnCompletion: 1;
        uint32_t LastDescriptor: 1;
        uint32_t FirstDescriptor: 1;
        uint32_t SecondAddressChained: 1;
        uint32_t EndOfRing: 1;
        uint32_t Reserved1: 24;
        uint32_t CardErrorSummary: 1;
        uint32_t OWN: 1;
    } DES0;
    struct
    {
        uint32_t Buffer1Size: 13;
        uint32_t Buffer2Size: 13;
        uint32_t Reserved: 6;
    } DES1;
    struct
    {
        uint32_t BufferAddressPointer1: 32;
    } DES2;
    struct
    {
        uint32_t BufferAddressPointer2: 32;
    } DES3;
} __attribute__((packed)) DmaDesc_t;

/** End of SDHC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup SDHC_Exported_Functions SDHC Exported Functions
  * \brief
  * \{
  */

/**
  * \brief  Initializes the SDHC Pad.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  DataWidth: Specifies the data width.
  * \return None
  */
void SDHC_InitPad(SDHC_TypeDef *SDHCx, DataWidth_t DataWidth);

/**
  * \brief  Deinitializes the SDHC Pad.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  DataWidth: Specifies the data width.
  * \return None
  */
void SDHC_DeInitPad(SDHC_TypeDef *SDHCx, DataWidth_t DataWidth);

/**
  * \brief  Initializes the SDHC peripheral.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return None
  */
void SDHC_Init(SDHC_TypeDef *SDHCx);

/**
  * \brief  Deinitializes the SDHC peripheral.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return None
  */
void SDHC_DeInit(SDHC_TypeDef *SDHCx);

/**
  * \brief  Set the SDHC Clock out.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Freq_kHz: Specifies the SDHC Clock out value.
            This parameter unit is kHz.
  * \return None
  */
uint32_t SDHC_SetClkOutFreq(SDHC_TypeDef *SDHCx, uint32_t Freq_kHz);

/**
  * \brief  Get the SDHC Clock out.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return SDHC Clock out: This parameter unit is kHz.
  */
uint32_t SDHC_GetClkOutFreq_kHz(SDHC_TypeDef *SDHCx);

/**
  * \brief  Set the transfer data width.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Width: Specifies the transfer data width.
  * \return None
  */
void SDHC_SetHostDataWidth(SDHC_TypeDef *SDHCx, DataWidth_t Width);

/**
  * \brief  Send cmd without data.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  pCmdInfo: pointer to a cmd info, such as Cmd0.
  * \param  pRspBuf: pointer to a response buffer.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_SendNoDataCmd(SDHC_TypeDef *SDHCx, const CmdInfo_t *pCmdInfo, void *pRspBuf);

/**
  * \brief  Send cmd without rx data.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  pCmdInfo: pointer to a cmd info, such as Cmd18.
  * \param  pRspBuf: pointer to a response buffer.
  * \param  pDataInfo: pointer to a data info.
  * \param  pRxDataBuf: pointer to a rx data buffer.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_SendCmdWithRxData(SDHC_TypeDef *SDHCx,
                                 const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                 const DataInfo_t *pDataInfo, void *pRxDataBuf);

/**
  * \brief  Send cmd without tx data.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  pCmdInfo: pointer to a cmd info, such as Cmd25.
  * \param  pRspBuf: pointer to a response buffer.
  * \param  pDataInfo: pointer to a data info.
  * \param  pRxDataBuf: pointer to a tx data buffer.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_SendCmdWithTxData(SDHC_TypeDef *SDHCx,
                                 const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                 const DataInfo_t *pDataInfo, const void *pDataToTx);

/**
  * \brief  Wait Data idle.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Timeout_ms: wait data idle time, which uite is ms.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_WaitData0Idle(SDHC_TypeDef *SDHCx, uint32_t Timeout_ms);

/**
  * \brief  Disable Interrupt nvic.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return SDHCRes_t: SDHC Result error
  */
void DisableIntrByNvic(SDHC_TypeDef *SDHCx);


void ResetAll(SDHC_TypeDef *SDHCx);
void InitClk(SDHC_TypeDef *SDHCx);

/* pParm is shallow copied, and must keep valid during the whole SDHC session. */

/* All the APIs must run in task environment. */

/* The asynchronous API may not be needed because if it is,
   you can build a separate task to do it using the synchronous API. */

/** End of SDHC_Exported_Functions
  * \}
  */

/** End of SDHC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_SDHC_H */
