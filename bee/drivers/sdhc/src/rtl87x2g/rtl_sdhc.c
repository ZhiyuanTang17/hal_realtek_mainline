/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_sdhc.c
* \brief    This file provides all SDHC(SD Host Controller) firmware functions.
* \details
* \author   Bert
* \date     2023-10-27
* \version  v1.0
*********************************************************************************************************
*/

/**
  * Abbrevations:
  * xfer = transfer     rsp = response     freq = frequency     intr = interrupt
  * sem = semaphore     inst = instance    res = result
  *
  * Prefix:
  * g = global variable k = global const   p = pointer    a = array
  * pfn = function pointer
  *
  */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_sdhc.h"
#include "rtl_nvic.h"
#include "rtl_pinmux.h"

#include "os_mem.h"
#include "os_sync.h"
#include "os_sched.h"
#include "app_section.h"

#include "clock.h"
#include "utils.h"
#include <string.h>

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define SDHC_CTL_REG             (*(volatile uint32_t *)0x40002374)
#define SDHC0_PHY0_REG           (*(volatile uint32_t *)0x40002378)


/* Specifies the interrupt priority */
#define SDHC_INTR_PRIORITY      5


/* Specifies the Clock selection */
#define CLKIN_FREQ_kHz(x)           ((x == CLKSRC_CLK_40M_VCORE4) ? (20*1000) : (50*1000))

#define CLK_OUT_MAX_FREQ_kHz(x)     (CLKIN_FREQ_kHz(x))
#define CLK_OUT_MIN_FREQ_kHz(x)     (CLKIN_FREQ_kHz(x) / (255*2))

#define DEFAULT_CLK_OUT_FREQ_kHz    (400)


/* Specifies the SDHC pin selction which there is one group only */
#define SDHC0_CLK   P9_4
#define SDHC0_CMD   P9_3
#define SDHC0_D0    P10_0
#define SDHC0_D1    P9_7
#define SDHC0_D2    P9_6
#define SDHC0_D3    P9_5
#define SDHC0_D4    P4_4
#define SDHC0_D5    P4_5
#define SDHC0_D6    P4_6
#define SDHC0_D7    P4_7

#define SDHC1_CLK   P9_4
#define SDHC1_CMD   P9_3
#define SDHC1_D0    P10_0
#define SDHC1_D1    P9_7
#define SDHC1_D2    P9_6
#define SDHC1_D3    P9_5
#define SDHC1_D4    P4_4
#define SDHC1_D5    P4_5
#define SDHC1_D6    P4_6
#define SDHC1_D7    P4_7

/*============================================================================*
 *                          Private Variables
 *============================================================================*/
static const uint8_t aSDHC0Pin[10] = {SDHC0_CLK, SDHC0_CMD, SDHC0_D0, SDHC0_D1, SDHC0_D2, SDHC0_D3, SDHC0_D4, SDHC0_D5, SDHC0_D6, SDHC0_D7};
static const uint8_t aSDHC1Pin[10] = {SDHC1_CLK, SDHC1_CMD, SDHC1_D0, SDHC1_D1, SDHC1_D2, SDHC1_D3, SDHC1_D4, SDHC1_D5, SDHC1_D6, SDHC1_D7};

void *gSDHC0Sem = NULL;
void *gSDHC1Sem = NULL;

static ClockSrcSel_t SDHC_CLK_SRC = CLKSRC_CLK_40M_VCORE4;

/*============================================================================*
 *                          Private Functions
 *============================================================================*/

/* Only use interrupt-driven DMA mode.
   Polling mode and reading/writing data by CPU is not used. */

static SDHCRes_t CheckResponseByIntr(SDHC_TypeDef *SDHCx);

static SDHCRes_t SendCmdWithRxDataByDma(SDHC_TypeDef *SDHCx,
                                        const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                        const DataInfo_t *pDataInfo, void *pRxDataBuf);
static SDHCRes_t SendCmdWithTxDataByDma(SDHC_TypeDef *SDHCx,
                                        const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                        const DataInfo_t *pDataInfo, const void *pDataToTx);

static void InitDmaDesc(SDHC_TypeDef *SDHCx, uint32_t DataAddr, uint32_t DataBytes);
static SDHCRes_t CheckRxDataXferByIntr(SDHC_TypeDef *SDHCx);
static SDHCRes_t CheckTxDataXferByIntr(SDHC_TypeDef *SDHCx);
static SDHCRes_t CheckDmaStateByIntr(SDHC_TypeDef *SDHCx);

// static void ResetAll(SDHC_TypeDef *SDHCx);
static void EnableIntrByNvic(SDHC_TypeDef *SDHCx);

static void SetFieldByCmdInfo(SDHC_CMD_t *pCmd, const CmdInfo_t *pCmdInfo);
static void GetResponse(SDHC_TypeDef *SDHCx, bool IsR2Rsp, void *pBuf);

// static void InitClk(SDHC_TypeDef *SDHCx);
static void DeInitClk(SDHC_TypeDef *SDHCx);
static void SwitchClk(SDHC_TypeDef *SDHCx, uint32_t ClockSrc);

static uint8_t GetPinCnt(DataWidth_t DataWidth);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Initializes the SDHC Pad.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  DataWidth: Specifies the data width.
  * \return None
  */
void SDHC_InitPad(SDHC_TypeDef *SDHCx, DataWidth_t DataWidth)
{
    uint8_t PinCnt = GetPinCnt(DataWidth);
    const uint8_t *pSDHCPin = (SDHCx == SDHC0) ? aSDHC0Pin : aSDHC1Pin;

    for (uint8_t i = 0; i < PinCnt; ++i)
    {
        Pad_Config(pSDHCPin[i], PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_HIGH);
        Pad_Dedicated_Config(pSDHCPin[i], ENABLE);
        Pad_SetDrivingCurrent(pSDHCPin[i], PAD_DRIVING_CURRENT_8mA);
    }
    Pinmux_HS_Config(SDHC_HS_MUX);
}

/**
  * \brief  Deinitializes the SDHC Pad.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  DataWidth: Specifies the data width.
  * \return None
  */
void SDHC_DeInitPad(SDHC_TypeDef *SDHCx, DataWidth_t DataWidth)
{
    uint8_t PinCnt = GetPinCnt(DataWidth);
    const uint8_t *pSDHCPin = (SDHCx == SDHC0) ? aSDHC0Pin : aSDHC1Pin;

    for (uint8_t i = 0; i < PinCnt; ++i)
    {
        Pad_Dedicated_Config(pSDHCPin[i], DISABLE);
        Pad_Config(pSDHCPin[i], PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_HIGH);
    }
}

/**
  * \brief  Initializes the SDHC peripheral.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return None
  */
void SDHC_Init(SDHC_TypeDef *SDHCx)
{
    InitClk(SDHCx);
    ResetAll(SDHCx);

    SDHCx->RINTSTS = 0xffffffff;
    SDHCx->INTMASK = 0;

    SDHC_CTRL_t ctrl = {.d32 = SDHCx->CTRL};
    ctrl.b.int_enable = 1;
    ctrl.b.use_internal_dmac = 1;
    SDHCx->CTRL = ctrl.d32;

    SDHC_SetClkOutFreq(SDHCx, DEFAULT_CLK_OUT_FREQ_kHz);

    if (SDHCx == SDHC0)
    {
        ASSERT(gSDHC0Sem == NULL);
        os_sem_create(&gSDHC0Sem, "gSDHC0Sem", 0, 1);
        ASSERT(gSDHC0Sem != NULL);
    }
    else
    {
        ASSERT(gSDHC1Sem == NULL);
        os_sem_create(&gSDHC1Sem, "gSDHC1Sem", 0, 1);
        ASSERT(gSDHC1Sem != NULL);
    }

    EnableIntrByNvic(SDHCx);
}


/**
  * \brief  Deinitializes the SDHC peripheral.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return None
  */
void SDHC_DeInit(SDHC_TypeDef *SDHCx)
{
    DisableIntrByNvic(SDHCx);

    if (SDHCx == SDHC0)
    {
        ASSERT(gSDHC0Sem != NULL);
        os_sem_delete(gSDHC0Sem);
        gSDHC0Sem = NULL;
    }
    else
    {
        ASSERT(gSDHC1Sem != NULL);
        os_sem_delete(gSDHC1Sem);
        gSDHC1Sem = NULL;
    }

    DeInitClk(SDHCx);
}

#define ROUND_UP_DIV(a, b)  (((a)+(b)-1)/(b))

/**
  * \brief  Set the SDHC Clock out.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Freq_kHz: Specifies the SDHC Clock out value.
            This parameter unit is kHz.
  * \return None
  */
uint32_t SDHC_SetClkOutFreq(SDHC_TypeDef *SDHCx, uint32_t Freq_kHz)
{
    if (Freq_kHz > CLKIN_FREQ_kHz(CLKSRC_CLK_40M_VCORE4))
    {
        SwitchClk(SDHCx, CLKSRC_CKO1_PLL1_VCORE4);
    }

    if (Freq_kHz >= CLK_OUT_MAX_FREQ_kHz(SDHC_CLK_SRC))
    {
        SDHCx->CLKDIV = 0;
    }
    else if (Freq_kHz <= CLK_OUT_MIN_FREQ_kHz(SDHC_CLK_SRC))
    {
        SDHCx->CLKDIV = 0xff;
    }
    else
    {
        uint32_t Divider = ROUND_UP_DIV(CLK_OUT_MAX_FREQ_kHz(SDHC_CLK_SRC), Freq_kHz);
        Divider = ROUND_UP_DIV(Divider, 2);

        ASSERT(0 < Divider && Divider <= 0xff);
        SDHCx->CLKDIV = Divider;
    }

    SDHCx->CLKSRC = 0;

    static const SDHC_CLKENA_t clkena = {.b = {.cclk_enable = 1, .cclk_low_power = 1}};
    SDHCx->CLKENA = clkena.d32;

    SDHC_CMD_t cmd = {.d32 = SDHCx->CMD};
    cmd.b.start_cmd = 1;
    cmd.b.update_clock_registers_only = 1;
    cmd.b.wait_prvdata_complete = 1;
    SDHCx->CMD = cmd.d32;
    do
    {
        cmd.d32 = SDHCx->CMD;
        // TODO: Support HLE handling. P219
    }
    while (cmd.b.start_cmd == 1);

    return SDHC_GetClkOutFreq_kHz(SDHCx);
}

/**
  * \brief  Get the SDHC Clock out.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \return SDHC Clock out: This parameter unit is kHz.
  */
uint32_t SDHC_GetClkOutFreq_kHz(SDHC_TypeDef *SDHCx)
{
    SDHC_CLKDIV_t clkdiv = {.d32 = SDHCx->CLKDIV};
    uint32_t Div = clkdiv.b.clk_divider0 * 2;
    return (Div == 0) ? CLKIN_FREQ_kHz(SDHC_CLK_SRC) : (CLKIN_FREQ_kHz(SDHC_CLK_SRC) / Div);
}

/**
  * \brief  Set the transfer data width.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Width: Specifies the transfer data width.
  * \return None
  */
void SDHC_SetHostDataWidth(SDHC_TypeDef *SDHCx, DataWidth_t Width)
{
    switch (Width)
    {
    case DATAWIDTH_1BIT:
        SDHCx->CTYPE = 0;
        break;
    case DATAWIDTH_4BIT:
    case DATAWIDTH_4BIT_DDR:
        SDHCx->CTYPE = 1;
        break;
    case DATAWIDTH_8BIT: // Only 4 pins is available in RTL87X2G.
    case DATAWIDTH_8BIT_DDR:
        SDHCx->CTYPE = 1 << 16;
        break;
    default:
        ASSERT(0);
        break;
    }

    SDHC_UHS_REG_t uhs_reg = {.d32 = SDHCx->UHS_REG};
    uhs_reg.b.ddr_reg = (Width == DATAWIDTH_4BIT_DDR || Width == DATAWIDTH_8BIT_DDR) ? 1 : 0;
    SDHCx->UHS_REG = uhs_reg.d32;
}


// TODO: Add comment to inform user that pRspBuf must be 4 bytes aligned.
/**
  * \brief  Send cmd without data.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  pCmdInfo: pointer to a cmd info, such as Cmd0.
  * \param  pRspBuf: pointer to a response buffer.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_SendNoDataCmd(SDHC_TypeDef *SDHCx, const CmdInfo_t *pCmdInfo, void *pRspBuf)
{
    ASSERT(pCmdInfo->CmdIdx <= 63);

    SDHCx->CMDARG = pCmdInfo->CmdArg;

    SDHC_CMD_t cmd = {0};
    SetFieldByCmdInfo(&cmd, pCmdInfo);
    cmd.b.data_expected = 0;
    SDHCx->CMD = cmd.d32;

    SDHCRes_t Res = CheckResponseByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        DBG_DIRECT("[%s] error%d: CheckResponseByIntr, line%d", __func__, Res, __LINE__);
        return Res;
    }
    if (pCmdInfo->IsRspExpected)
    {
        ASSERT(pRspBuf != NULL);
        GetResponse(SDHCx, pCmdInfo->IsR2Rsp, pRspBuf);
    }

    return SDHCRES_OK;
}

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
                                 const DataInfo_t *pDataInfo, void *pRxDataBuf)
{
    return SendCmdWithRxDataByDma(SDHCx, pCmdInfo, pRspBuf, pDataInfo, pRxDataBuf);
}

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
                                 const DataInfo_t *pDataInfo, const void *pDataToTx)
{
    return SendCmdWithTxDataByDma(SDHCx, pCmdInfo, pRspBuf, pDataInfo, pDataToTx);
}

/**
  * \brief  Wait Data idle.
  * \param  SDHCx: Specifies the SDHC peripheral.
  * \param  Timeout_ms: wait data idle time, which uite is ms.
  * \return SDHCRes_t: SDHC Result error
  */
SDHCRes_t SDHC_WaitData0Idle(SDHC_TypeDef *SDHCx, uint32_t Timeout_ms)
{
    for (uint32_t i = 0; i < Timeout_ms; ++i)
    {
        SDHC_STATUS_t status = {.d32 = SDHCx->STATUS};
        if (!status.b.data_busy)
        {
            return SDHCRES_OK;
        }
        os_delay(1);
    }
    return SDHCRES_WAIT_DATA0_IDLE_TIMEOUT;
}

static SDHCRes_t CheckResponseByIntr(SDHC_TypeDef *SDHCx)
{
    SDHCRes_t Res = SDHCRES_OK;

    SDHC_RINTSTS_t rintsts = {.d32 = SDHCx->RINTSTS};
    if (rintsts.b.HardwareLockedWriteError)
    {
        Res = SDHCRES_HARDWARE_LOCKED_ERROR;
        goto Exit1;
    }

    static const SDHC_INTMASK_t IntrToCtrl = {.b = {.CommandDone = 1}};
    SDHCx->INTMASK |= IntrToCtrl.d32;

    if ((SDHCx->RINTSTS & SDHCx->INTMASK) == 0)
    {
        // Wait for an interrupt.
        EnableIntrByNvic(SDHCx);
        void *Sem = (SDHCx == SDHC0) ? gSDHC0Sem : gSDHC1Sem;
        bool xRes = os_sem_take(Sem, 0xffffffff);
        ASSERT(xRes == true);
    }

    rintsts.d32 = SDHCx->RINTSTS;
    if (rintsts.b.ResponseError)
    {
        Res = SDHCRES_RESPONSE_ERROR;
        goto Exit2;
    }
    if (rintsts.b.ResponseCrcError)
    {
        Res = SDHCRES_RESPONSE_CRC_ERROR;
        goto Exit2;
    }
    if (rintsts.b.ResponseTimeout)
    {
        Res = SDHCRES_RESPONSE_TIMEOUT;
        goto Exit2;
    }

Exit2:
    SDHCx->INTMASK &= ~IntrToCtrl.d32;

    static const SDHC_RINTSTS_t IntrToClear = {.b = {
            .HardwareLockedWriteError = 1,
            .CommandDone = 1,
            .ResponseError = 1,
            .ResponseCrcError = 1,
            .ResponseTimeout = 1,
        }
    };
Exit1:
    SDHCx->RINTSTS = IntrToClear.d32;
    return Res;
}

static SDHCRes_t SendCmdWithRxDataByDma(SDHC_TypeDef *SDHCx,
                                        const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                        const DataInfo_t *pDataInfo, void *pRxDataBuf)
{
    ASSERT(pRxDataBuf != NULL && (size_t)pRxDataBuf % 4 == 0);

    uint32_t RxBytes = pDataInfo->BlockSize * pDataInfo->BlockCount;
    ASSERT(RxBytes <= MAX_BYTES_PER_XFER);

    InitDmaDesc(SDHCx, (uint32_t)pRxDataBuf, RxBytes);

    SDHC_CARDTHRCTL_t card_threshold = {.d32 = SDHCx->CARDTHRCTL};
    card_threshold.b.CardRdThrEn = 1;
    card_threshold.b.CardThreshold = BYTES_PER_BLOCK;
    SDHCx->CARDTHRCTL = card_threshold.d32;

    SDHCx->BYTCNT = RxBytes;
    SDHCx->BLKSIZ = pDataInfo->BlockSize;

    SDHCx->CMDARG = pCmdInfo->CmdArg;

    SDHC_CMD_t cmd = {0};
    SetFieldByCmdInfo(&cmd, pCmdInfo);
    cmd.b.data_expected = 1;
    cmd.b.send_auto_stop = pDataInfo->SendAutoStop ? 1 : 0;
    cmd.b.transfer_mode = BLOCK_TRANSFER;
    cmd.b.read_write = READ_DATA;
    SDHCx->CMD = cmd.d32;

    SDHCRes_t Res = CheckResponseByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }
    if (pCmdInfo->IsRspExpected)
    {
        ASSERT(pRspBuf != NULL);
        GetResponse(SDHCx, pCmdInfo->IsR2Rsp, pRspBuf);
    }

    Res = CheckRxDataXferByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }

    Res = CheckDmaStateByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }

    SCB_InvalidateDCache_by_Addr(pRxDataBuf, RxBytes);

    return SDHCRES_OK;
}


// pDataToTx must be on EXT_DATA_SRAM.
static SDHCRes_t SendCmdWithTxDataByDma(SDHC_TypeDef *SDHCx,
                                        const CmdInfo_t *pCmdInfo, void *pRspBuf,
                                        const DataInfo_t *pDataInfo, const void *pDataToTx)
{
    ASSERT(pDataToTx != NULL && (size_t)pDataToTx % 4 == 0);

    uint32_t TxBytes = pDataInfo->BlockSize * pDataInfo->BlockCount;
    ASSERT(TxBytes <= MAX_BYTES_PER_XFER);

    SCB_CleanDCache_by_Addr((volatile void *)pDataToTx, TxBytes);

    InitDmaDesc(SDHCx, (uint32_t)pDataToTx, TxBytes);

    SDHCx->BYTCNT = TxBytes;
    SDHCx->BLKSIZ = pDataInfo->BlockSize;

    SDHCx->CMDARG = pCmdInfo->CmdArg;

    SDHC_CMD_t cmd = {0};
    SetFieldByCmdInfo(&cmd, pCmdInfo);
    cmd.b.data_expected = 1;
    cmd.b.send_auto_stop = pDataInfo->SendAutoStop ? 1 : 0;
    cmd.b.transfer_mode = BLOCK_TRANSFER;
    cmd.b.read_write = WRITE_DATA;
    SDHCx->CMD = cmd.d32;

    SDHCRes_t Res = CheckResponseByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }

    if (pCmdInfo->IsRspExpected)
    {
        ASSERT(pRspBuf != NULL);
        GetResponse(SDHCx, pCmdInfo->IsR2Rsp, pRspBuf);
    }

    Res = CheckDmaStateByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }

    Res = CheckTxDataXferByIntr(SDHCx);
    if (Res != SDHCRES_OK)
    {
        return Res;
    }

    return SDHCRES_OK;
}


static void InitDmaDesc(SDHC_TypeDef *SDHCx, uint32_t DataAddr, uint32_t DataBytes)
{
    ASSERT(DataBytes <= MAX_BYTES_PER_XFER);

    SDHC_BMOD_t bmod = {.d32 = SDHCx->BMOD};
    bmod.b.de = 1;
    bmod.b.dsl = 0; //sizeof(DmaDesc_t) / 4;
    bmod.b.fb = 0;
    bmod.b.swr = 0;
    SDHCx->BMOD = bmod.d32;

    SDHCx->IDINTEN = 0x3ff; // Enable, not unmask!!!

    __ALIGNED(4) static volatile DmaDesc_t aDmaDesc0[DESC_CNT] = {0};
    __ALIGNED(4) static volatile DmaDesc_t aDmaDesc1[DESC_CNT] = {0};
    volatile DmaDesc_t *pDmaDesc = (SDHCx == SDHC0) ? aDmaDesc0 : aDmaDesc1;

    uint32_t CurrDescBytes;
    for (uint32_t RemainBytes = DataBytes, DescIdx = 0; RemainBytes > 0;
         RemainBytes -= CurrDescBytes, ++DescIdx)
    {
        ASSERT(DescIdx < DESC_CNT);

        CurrDescBytes = (RemainBytes < MAX_BYTES_PER_DESC) ? RemainBytes : MAX_BYTES_PER_DESC;

        bool IsLastDesc = (CurrDescBytes == RemainBytes);

        pDmaDesc[DescIdx].DES0.DisableInterruptOnCompletion = !IsLastDesc;
        pDmaDesc[DescIdx].DES0.LastDescriptor = IsLastDesc;
        pDmaDesc[DescIdx].DES0.FirstDescriptor = (DescIdx == 0);
        pDmaDesc[DescIdx].DES0.SecondAddressChained = 0;
        pDmaDesc[DescIdx].DES0.EndOfRing = 0;
        pDmaDesc[DescIdx].DES0.CardErrorSummary = 0;
        pDmaDesc[DescIdx].DES0.OWN = OWN_BY_DMA;
        pDmaDesc[DescIdx].DES0.Reserved0 = 0;
        pDmaDesc[DescIdx].DES0.Reserved1 = 0;

        static const uint32_t MaxBytesHalfDesc = MAX_BYTES_PER_DESC / 2;
        if (CurrDescBytes > MaxBytesHalfDesc)
        {
            pDmaDesc[DescIdx].DES1.Buffer1Size = MaxBytesHalfDesc;
            pDmaDesc[DescIdx].DES2.BufferAddressPointer1 = DataAddr;
            DataAddr += pDmaDesc[DescIdx].DES1.Buffer1Size;

            pDmaDesc[DescIdx].DES1.Buffer2Size = CurrDescBytes - MaxBytesHalfDesc;
            pDmaDesc[DescIdx].DES3.BufferAddressPointer2 = DataAddr;
            DataAddr += pDmaDesc[DescIdx].DES1.Buffer2Size;
        }
        else
        {
            pDmaDesc[DescIdx].DES1.Buffer1Size = CurrDescBytes;
            pDmaDesc[DescIdx].DES2.BufferAddressPointer1 = DataAddr;
            DataAddr += pDmaDesc[DescIdx].DES1.Buffer1Size;

            pDmaDesc[DescIdx].DES1.Buffer2Size = 0;
            pDmaDesc[DescIdx].DES3.BufferAddressPointer2 = 0;
        }

        // volatile uint32_t *pu = (volatile uint32_t *)&pDmaDesc[DescIdx];
        // DBG_DIRECT("pDmaDesc[%d]: 0x%x, 0x%x, 0x%x, 0x%x", DescIdx, pu[0], pu[1], pu[2], pu[3]);
    }

    SDHCx->DBADDR = (uint32_t)pDmaDesc;

    SDHC_FIFOTH_t fifoth = {.d32 = SDHCx->FIFOTH};
    fifoth.b.TX_Wmark = BYTES_PER_BLOCK / 4 / 2; // Half block.
    fifoth.b.RX_Wmark = BYTES_PER_BLOCK / 4 / 2;
    SDHCx->FIFOTH = fifoth.d32;
}

static SDHCRes_t CheckRxDataXferByIntr(SDHC_TypeDef *SDHCx)
{
    SDHCRes_t Res = SDHCRES_OK;

    static const SDHC_RINTSTS_t xIntrToCtrl =
    {
        .b = {
            .DataCrcError = 1,
            .DataReadTimeout = 1,
            .StartBitError_BusyClearInterrupt = 1,
            .EndBitError_WriteNoCrc = 1,
            .DataTransferOver = 1,
        }
    };

    SDHC_RINTSTS_t rintsts;
    do
    {
        SDHCx->INTMASK |= xIntrToCtrl.d32;

        void *Sem = (SDHCx == SDHC0) ? gSDHC0Sem : gSDHC1Sem;
        if ((SDHCx->RINTSTS & SDHCx->INTMASK) == 0)
        {
            // Wait for an interrupt.
            EnableIntrByNvic(SDHCx);
            bool xRes = os_sem_take(Sem, 0xffffffff);
            ASSERT(xRes == true);
        }

        rintsts.d32 = SDHCx->RINTSTS;
        if (rintsts.b.DataCrcError)
        {
            Res = SDHCRES_DATA_CRC_ERROR;
            goto Exit;
        }
        if (rintsts.b.DataReadTimeout)
        {
            Res = SDHCRES_DATA_READ_TIMEOUT;
            goto Exit;
        }
        if (rintsts.b.StartBitError_BusyClearInterrupt)
        {
            Res = SDHCRES_DATA_START_BIT_ERROR;
            goto Exit;
        }
        if (rintsts.b.EndBitError_WriteNoCrc)
        {
            Res = SDHCRES_DATA_END_BIT_ERROR;
            goto Exit;
        }
        rintsts.d32 = SDHCx->RINTSTS;
    }
    while (rintsts.b.DataTransferOver != 1);
Exit:
    SDHCx->INTMASK &= ~xIntrToCtrl.d32;

    // DBG_DIRECT("SDHCx->RINTSTS: 0x%x line%d", rintsts.d32, __LINE__);
    SDHCx->RINTSTS = xIntrToCtrl.d32;

    return Res;
}

static SDHCRes_t CheckTxDataXferByIntr(SDHC_TypeDef *SDHCx)
{
    SDHCRes_t Res = SDHCRES_OK;

    static const SDHC_RINTSTS_t xIntrToCtrl = {.b = {
            .DataCrcError = 1,
            .DataReadTimeout = 1,
            .EndBitError_WriteNoCrc = 1,
            .DataTransferOver = 1,
        }
    };

    void *Sem = (SDHCx == SDHC0) ? gSDHC0Sem : gSDHC1Sem;
    SDHC_RINTSTS_t rintsts;
    do
    {
        SDHCx->INTMASK |= xIntrToCtrl.d32;

        if ((SDHCx->RINTSTS & SDHCx->INTMASK) == 0)
        {
            // Wait for an interrupt.
            EnableIntrByNvic(SDHCx);
            bool xRes = os_sem_take(Sem, 0xffffffff);
            ASSERT(xRes == true);
        }

        rintsts.d32 = SDHCx->RINTSTS;
        if (rintsts.b.DataCrcError)
        {
            Res = SDHCRES_DATA_CRC_ERROR;
            goto Exit;
        }
        if (rintsts.b.DataReadTimeout)
        {
            Res = SDHCRES_DATA_READ_TIMEOUT;
            goto Exit;
        }
        if (rintsts.b.EndBitError_WriteNoCrc)
        {
            Res = SDHCRES_WRITE_NO_CRC;
            goto Exit;
        }
        rintsts.d32 = SDHCx->RINTSTS;
    }
    while (rintsts.b.DataTransferOver != 1);
Exit:
    SDHCx->INTMASK &= ~xIntrToCtrl.d32;;

    // DBG_DIRECT("SDHCx->RINTSTS: 0x%x", rintsts.d32);
    SDHCx->RINTSTS = xIntrToCtrl.d32;

    return Res;
}

static SDHCRes_t CheckDmaStateByIntr(SDHC_TypeDef *SDHCx)
{
    SDHCRes_t Res = SDHCRES_OK;

    void *Sem = (SDHCx == SDHC0) ? gSDHC0Sem : gSDHC1Sem;
    SDHC_IDSTS_t idsts;
    do
    {
        if ((SDHCx->IDSTS & 0x3ff) == 0)
        {
            // Wait for an interrupt.
            EnableIntrByNvic(SDHCx);
            bool xRes = os_sem_take(Sem, 0xffffffff);
            ASSERT(xRes == true);
        }

        idsts.d32 = SDHCx->IDSTS;
        // DBG_DIRECT("IDSTS: 0x%x", idsts.d32);
        if (idsts.b.fbe)
        {
            Res = SDHCRES_FATAL_BUS_ERROR;
            goto Exit;
        }
        if (idsts.b.du)
        {
            Res = SDHCRES_DESCRIPTOR_UNAVAILABLE;
            goto Exit;
        }
    }
    while (idsts.b.nis != 1);

Exit:
    SDHCx->IDSTS = 0xffffffff;
    return Res;
}

void ResetAll(SDHC_TypeDef *SDHCx)
{
    SDHC_CTRL_t ctrl = {.d32 = SDHCx->CTRL};
    ctrl.b.controller_reset = 1;
    ctrl.b.fifo_reset = 1;
    ctrl.b.dma_reset = 1;
    SDHCx->CTRL = ctrl.d32;
    do
    {
        ctrl.d32 = SDHCx->CTRL;
    }
    while (ctrl.b.controller_reset == 1 || ctrl.b.fifo_reset == 1 || ctrl.b.dma_reset == 1);
}

static void EnableIntrByNvic(SDHC_TypeDef *SDHCx)
{
    NVIC_InitTypeDef Nvic =
    {
        .NVIC_IRQChannel = (SDHCx == SDHC0) ? SDHC0_IRQn : SDHC1_IRQn,
        .NVIC_IRQChannelPriority = SDHC_INTR_PRIORITY,
        .NVIC_IRQChannelCmd = ENABLE,
    };
    NVIC_Init(&Nvic);
}

void DisableIntrByNvic(SDHC_TypeDef *SDHCx)
{
    NVIC_InitTypeDef Nvic =
    {
        .NVIC_IRQChannel = (SDHCx == SDHC0) ? SDHC0_IRQn : SDHC1_IRQn,
        .NVIC_IRQChannelPriority = SDHC_INTR_PRIORITY,
        .NVIC_IRQChannelCmd = DISABLE,
    };
    NVIC_Init(&Nvic);
}

static void SetFieldByCmdInfo(SDHC_CMD_t *pCmd, const CmdInfo_t *pCmdInfo)
{
    pCmd->b.start_cmd = 1;
    pCmd->b.use_hold_reg = 1;
    pCmd->b.update_clock_registers_only = 0;
    pCmd->b.card_number = 0;
    pCmd->b.wait_prvdata_complete = 1;

    pCmd->b.cmd_index = pCmdInfo->CmdIdx;
    pCmd->b.send_initialization = pCmdInfo->IsResetCmd;
    pCmd->b.stop_abort_cmd = pCmdInfo->IsStopCmd;
    pCmd->b.response_expect = pCmdInfo->IsRspExpected;
    pCmd->b.response_length = pCmdInfo->IsR2Rsp;
    pCmd->b.check_response_crc = pCmdInfo->CheckRspCrc;
}

static void GetResponse(SDHC_TypeDef *SDHCx, bool IsR2Rsp, void *pBuf)
{
    uint32_t aBuf[4];
    if (IsR2Rsp)
    {
        aBuf[0] = SDHCx->RESP0;
        aBuf[1] = SDHCx->RESP1;
        aBuf[2] = SDHCx->RESP2;
        aBuf[3] = SDHCx->RESP3;
        // To prevent unaligned access.
        memcpy(pBuf, aBuf, 4 * 4);
    }
    else
    {
        aBuf[0] = SDHCx->RESP0;
        memcpy(pBuf, aBuf, 4);
    }
}

static void SwitchClk(SDHC_TypeDef *SDHCx, uint32_t ClockSrc)
{
    if (ClockSrc == CLKSRC_CKO1_PLL1_VCORE4)
    {
        pm_sdhc_freq_set(CLK_PLL1_SRC, 100, 50);

        SDHC_CLK_SRC = CLKSRC_CKO1_PLL1_VCORE4;
        InitClk(SDHCx);
    }
    else if (ClockSrc == CLKSRC_CLK_40M_VCORE4)
    {
        SDHC_CLK_SRC = CLKSRC_CLK_40M_VCORE4;
        InitClk(SDHCx);
    }
}

void InitClk(SDHC_TypeDef *SDHCx)
{
    SDHC_PHY0_t sdhcphy0 = {.d32 = SDHC0_PHY0_REG};
    sdhcphy0.b.r_sdhc_clk_sel_drv = 1;
    sdhcphy0.b.r_sdhc_clk_sel_sample = 0;
    sdhcphy0.b.r_sdhc_sample_dly_sel = 64;
    SDHC0_PHY0_REG = sdhcphy0.d32;

    SDHC_CTL_t sdhcctl = {.d32 = SDHC_CTL_REG};
    if (SDHCx == SDHC0)
    {
        sdhcctl.b.sdhc_ck_en = 1;
        sdhcctl.b.sdhc_func_en = 1;
        sdhcctl.b.r_sdhc_clk_src_en = 1;
        sdhcctl.b.r_sdhc_div_sel = 0;
        sdhcctl.b.r_sdhc_div_en = 0;
        sdhcctl.b.r_sdhc_mux_clk_cg_en = 1;
        sdhcctl.b.r_sdhc_clk_src_sel1 = SDHC_CLK_SRC & 1;
        sdhcctl.b.r_sdhc_clk_src_sel0 = SDHC_CLK_SRC >> 1;
    }
    SDHC_CTL_REG = sdhcctl.d32;
}

static void DeInitClk(SDHC_TypeDef *SDHCx)
{
    SDHC_PHY0_t sdhcphy0 = {.d32 = SDHC0_PHY0_REG};
    sdhcphy0.b.r_sdhc_clk_sel_drv = 0;
    sdhcphy0.b.r_sdhc_clk_sel_sample = 0;
    sdhcphy0.b.r_sdhc_sample_dly_sel = 0;
    SDHC0_PHY0_REG = sdhcphy0.d32;

    SDHC_CTL_t sdhcctl = {.d32 = SDHC_CTL_REG};
    if (SDHCx == SDHC0)
    {
        sdhcctl.b.sdhc_ck_en = 0;
        sdhcctl.b.sdhc_func_en = 0;
        sdhcctl.b.r_sdhc_clk_src_en  = 0;
        sdhcctl.b.r_sdhc_div_sel = 0;
        sdhcctl.b.r_sdhc_div_en = 1;
        sdhcctl.b.r_sdhc_mux_clk_cg_en = 0;
        sdhcctl.b.r_sdhc_clk_src_sel1  = 0;
        sdhcctl.b.r_sdhc_clk_src_sel0  = 0;
    }
    SDHC_CTL_REG = sdhcctl.d32;
}

static uint8_t GetPinCnt(DataWidth_t DataWidth)
{
    switch (DataWidth)
    {
    case DATAWIDTH_1BIT:
        return 3;
    case DATAWIDTH_4BIT:
    case DATAWIDTH_4BIT_DDR:
        return 6;
    case DATAWIDTH_8BIT: // Only 4 pins is available in RTL87X2G.
    case DATAWIDTH_8BIT_DDR:
        return 10;
    default:
        ASSERT(0);
        return 0;
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
