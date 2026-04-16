/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_dma.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
/* DMA Suspend Flag */
#define DMA_FIFO_STATUS                 (BIT(9))
#define DMA_SUSPEND_TRANSMISSSION       (BIT(8))
#define DMA_SUSPEND_CMD_STATUS          (BIT(2) | BIT(1))
#define DMA_SUSPEND_CHANNEL_STATUS      (BIT(0))

/* DMA Channel Bit */
#define CHANNEL_BIT(ch)                 ((ch < 8) ? BIT(ch) : BIT(ch + 8))
#define CHANNEL_WE_BIT(ch)              ((ch < 8) ? BIT(ch + 8) : BIT(ch + 16))

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern uint8_t DMA_GetDMAChNumByCh(uint8_t DMA_ChannelNum);
extern DMA_TypeDef *DMA_GetDMAxByCh(uint8_t DMA_ChannelNum);
extern DMA_TypeDef *DMA_GetDMAx(DMA_ChannelTypeDef *DMA_Channelx);
extern uint8_t DMA_GetHandshakeNum(DMA_ChannelTypeDef *DMA_Channelx, uint8_t handshake);
extern bool DMA_IsValidHandshake(uint8_t hs_src, uint8_t hs_dest);
extern bool DMA_IsGatherScatterChannel(DMA_ChannelTypeDef *DMA_Channelx);
extern bool DMA_IsHalfBlcokChannel(DMA_TypeDef *DMAx);
extern bool DMA_IsSupportContinuousAddrChannel(DMA_ChannelTypeDef *DMA_Channelx);
extern bool DMA_IsSupportBlockCounterChannel(DMA_ChannelTypeDef *DMA_Channelx);
extern bool DMA_IsSupportRAPChannel(DMA_ChannelTypeDef *DMA_Channelx);
FlagStatus DMA_GetSuspendCmdStatus(DMA_ChannelTypeDef *DMA_Channelx);
FlagStatus DMA_GetSuspendChannelStatus(DMA_ChannelTypeDef *DMA_Channelx);
#if (DMA_SUPPORT_MSIZE_BIGGER_THAN_FIFO_DEPTH == 1)
extern void DMA_CheckDataSizeAndMsize(DMA_ChannelTypeDef *DMA_Channelx,
                                      DMA_InitTypeDef *DMA_InitStruct);
#endif
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the DMA registers to their default reset values.
  * \param  None
  * \return None
  */
void DMA_DeInit(void)
{
    /* Disable DMA clock */
#ifdef IS_DMA_PERIPH
    RCC_ClockCmd(DMA_CLOCK, DISABLE);
#endif
#ifdef IS_DMA1_PERIPH
    RCC_ClockCmd(DMA1_CLOCK, DISABLE);
#endif
#ifdef IS_DMA2_PERIPH
    RCC_ClockCmd(DMA2_CLOCK, DISABLE);
#endif
}

/**
  * \brief  Initializes the DMA Channelx according to the specified
  *         parameters in the DMA_InitStruct.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
  * \param  DMA_InitStruct: pointer to a DMA_InitTypeDef structure that
  *         contains the configuration information for the specified DMA Channel.
  * \return None.
  */
void DMA_Init(DMA_ChannelTypeDef *DMA_Channelx, DMA_InitTypeDef *DMA_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));
    assert_param(IS_DMAx_ChannelNum(DMA_InitStruct->DMA_ChannelNum));
    assert_param(IS_DMA_DIR(DMA_InitStruct->DMA_Direction));
    assert_param(IS_DMA_SourceInc(DMA_InitStruct->DMA_SourceInc));
    assert_param(IS_DMA_DestinationInc(DMA_InitStruct->DMA_DestinationInc));
    assert_param(IS_DMA_DATA_SIZE(DMA_InitStruct->DMA_SourceDataSize));
    assert_param(IS_DMA_DATA_SIZE(DMA_InitStruct->DMA_DestinationDataSize));

    DMA_TypeDef *DMAx = DMA_GetDMAx(DMA_Channelx);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_InitStruct->DMA_ChannelNum);
    uint8_t temp_hs_src = DMA_GetHandshakeNum(DMA_Channelx, DMA_InitStruct->DMA_SourceHandshake);
    uint8_t temp_hs_dst = DMA_GetHandshakeNum(DMA_Channelx, DMA_InitStruct->DMA_DestHandshake);

    /* ---------------- Configure source and destination address of DMA ---------------- */
    /* Program SARx register to set source address */
    DMA_Channelx->DMA_SARx = DMA_InitStruct->DMA_SourceAddr;
    /* Program DARx register to set destination address */
    DMA_Channelx->DMA_DARx = DMA_InitStruct->DMA_DestinationAddr;

    /* Enable DMA in DmaCfgReg */
    DMAx->DMA_DMACFGREG_L = 0x01;

    /* ---------------- DMA Configuration ---------------- */
    /* Clear pending interrupts of corresponding DMA channel */
    uint32_t temp_bit = BIT(channel_num);
    DMAx->DMA_CLEARTFR_L = temp_bit;
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMAx->DMA_CLEARTFR_H = temp_bit;
#endif
    DMAx->DMA_CLEARBLOCK_L = temp_bit;
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    DMAx->DMA_CLEARBLOCK_H = temp_bit;
#endif
    DMAx->DMA_CLEARERR_L = temp_bit;

    /* Mask pending interrupts of corresponding DMA channel */
    temp_bit = CHANNEL_WE_BIT(channel_num);
    DMAx->DMA_MASKTFR_L = temp_bit;
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMAx->DMA_MASKTFR_H = temp_bit;
#endif
    DMAx->DMA_MASKBLOCK_L = temp_bit;
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    DMAx->DMA_MASKBLOCK_H = temp_bit;
#endif
    DMAx->DMA_MASKERR_L = temp_bit;

#if (DMA_SUPPORT_MSIZE_BIGGER_THAN_FIFO_DEPTH == 1)
    DMA_CheckDataSizeAndMsize(DMA_Channelx, DMA_InitStruct);
#endif

    /* ---------------- Configure CTL register ---------------- */
    /* Config low 32 bits of CTL register  */
    DMA_CTLx_L_TypeDef dma_ctlxl = {.d32 = DMA_Channelx->DMA_CTLx_L};
    dma_ctlxl.b.int_en = ENABLE;
    dma_ctlxl.b.dst_tr_width = DMA_InitStruct->DMA_DestinationDataSize;
    dma_ctlxl.b.src_tr_width = DMA_InitStruct->DMA_SourceDataSize;
    dma_ctlxl.b.dinc = DMA_InitStruct->DMA_DestinationInc;
    dma_ctlxl.b.sinc = DMA_InitStruct->DMA_SourceInc;
    dma_ctlxl.b.dest_msize = DMA_InitStruct->DMA_DestinationMsize;
    dma_ctlxl.b.src_msize = DMA_InitStruct->DMA_SourceMsize;
    dma_ctlxl.b.tt_fc = DMA_InitStruct->DMA_Direction;
    DMA_Channelx->DMA_CTLx_L = dma_ctlxl.d32;

    /* Config high 32 bits of CTL register */
    DMA_Channelx->DMA_CTLx_H = DMA_InitStruct->DMA_BufferSize;

    /* ---------------- Configure CFG register ---------------- */
    DMA_CFGx_L_TypeDef dma_cfgxl = {.d32 = DMA_Channelx->DMA_CFGx_L};
    switch (DMA_InitStruct->DMA_Direction)
    {
    case DMA_DIR_MEMORY_TO_MEMORY:
        dma_cfgxl.b.hs_sel_dst = 0x1;
        dma_cfgxl.b.hs_sel_src = 0x1;
        break;
    case DMA_DIR_MEMORY_TO_PERIPHERAL:
        dma_cfgxl.b.hs_sel_dst = 0x0;
        dma_cfgxl.b.hs_sel_src = 0x1;
        break;
    case DMA_DIR_PERIPHERAL_TO_MEMORY:
        dma_cfgxl.b.hs_sel_dst = 0x1;
        dma_cfgxl.b.hs_sel_src = 0x0;
        break;
    case DMA_DIR_PERIPHERAL_TO_PERIPHERAL:
        dma_cfgxl.b.hs_sel_dst = 0x0;
        dma_cfgxl.b.hs_sel_src = 0x0;
        break;
    default:
        dma_cfgxl.b.hs_sel_dst = 0x0;
        dma_cfgxl.b.hs_sel_src = 0x0;
        break;
    }
    DMA_Channelx->DMA_CFGx_L = dma_cfgxl.d32;

    /* Set DMA channel priority level */
    dma_cfgxl.b.ch_prior = DMA_InitStruct->DMA_ChannelPriority;
    DMA_Channelx->DMA_CFGx_L = dma_cfgxl.d32;

    /* Set for secure mode */
    DMA_CFGx_H_TypeDef dma_cfgxh = {.d32 = DMA_Channelx->DMA_CFGx_H};

#if (DMA_SUPPORT_SECURE_MODE == 1)
    if (DMA_InitStruct->DMA_SecureEn == 1)
    {
        dma_cfgxh.b.protctl = 0x0;
    }
    DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
    if (DMA_IsSupportContinuousAddrChannel(DMA_Channelx))
    {
        dma_cfgxh.b.cont_sar = DMA_InitStruct->DMA_ContSarEn;
        dma_cfgxh.b.cont_dar = DMA_InitStruct->DMA_ContDarEn;
        DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
    }
#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    if (DMA_IsSupportContinuousAddrChannel(DMA_Channelx))
    {
        DMA_Channelx->DMA_BLK_COUNTER_REGx = DMA_InitStruct->DMA_BlockCounter;
    }
#endif

    /* Config multi-block mode */
    if (DMA_InitStruct->DMA_MultiBlockEn == 1)
    {
        if (DMA_InitStruct->DMA_MultiBlockMode & LLP_SELECTED_BIT)
        {
            DMA_Channelx->DMA_LLPx_L = DMA_InitStruct->DMA_MultiBlockStruct;
            dma_ctlxl.b.llp_dst_en = (DMA_InitStruct->DMA_MultiBlockMode & BIT27) >> 27;
            dma_ctlxl.b.llp_src_en = (DMA_InitStruct->DMA_MultiBlockMode & BIT28) >> 28;
            DMA_Channelx->DMA_CTLx_L = dma_ctlxl.d32;
        }
        dma_cfgxl.b.reload_src = (DMA_InitStruct->DMA_MultiBlockMode & BIT30) >> 30;
        dma_cfgxl.b.reload_dst = (DMA_InitStruct->DMA_MultiBlockMode & BIT31) >> 31;
        DMA_Channelx->DMA_CFGx_L = dma_cfgxl.d32;
    }
    else
    {
        /* Clear automatic source/destination reload */
        dma_cfgxl.b.reload_src = 0x0;
        dma_cfgxl.b.reload_dst = 0x0;
        DMA_Channelx->DMA_CFGx_L = dma_cfgxl.d32;
        /* Clear LLI for source/destination */
        dma_ctlxl.b.llp_dst_en = 0x0;
        dma_ctlxl.b.llp_src_en = 0x0;
        DMA_Channelx->DMA_CTLx_L = dma_ctlxl.d32;
    }

    /* ---------------- Set handshake ---------------- */
    /* Configure peripheral parameters and configure source or destination hardware handshaking interface */
    if (DMA_IsValidHandshake(temp_hs_src, temp_hs_dst) == true)
    {
        dma_cfgxh.b.src_per = temp_hs_src & 0x0F;
        dma_cfgxh.b.extended_src_per1 = (temp_hs_src & 0x10) >> 4;
        dma_cfgxh.b.extended_src_per2 = (temp_hs_src & 0x20) >> 5;
        dma_cfgxh.b.extended_src_per3 = (temp_hs_src & 0x40) >> 6;

        dma_cfgxh.b.dest_per = temp_hs_dst & 0x0F;
        dma_cfgxh.b.extended_dest_per1 = (temp_hs_dst & 0x10) >> 4;
        dma_cfgxh.b.extended_dest_per2 = (temp_hs_dst & 0x20) >> 5;
        dma_cfgxh.b.extended_dest_per3 = (temp_hs_dst & 0x40) >> 6;

        DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
    }

    /* ---------------- Configure scatter and gather ---------------- */
#if (DMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    /* Set for gather */
    if (DMA_IsGatherScatterChannel(DMA_Channelx))
    {
        dma_ctlxl.b.src_gather_en = DMA_InitStruct->DMA_GatherEn;
        DMA_Channelx->DMA_CTLx_L = dma_ctlxl.d32;

        if (DMA_InitStruct->DMA_GatherEn == 1)
        {
            DMA_SGRx_L_TypeDef dma_sgrxl = {.d32 = DMA_Channelx->DMA_SGRx_L};
            dma_sgrxl.b.sgi = DMA_InitStruct->DMA_GatherInterval & 0xFFFFF;
            dma_sgrxl.b.sgc = DMA_InitStruct->DMA_GatherCount & 0xFFF;
            DMA_Channelx->DMA_SGRx_L = dma_sgrxl.d32;

            DMA_SGRx_H_TypeDef dma_sgrxh = {.d32 = DMA_Channelx->DMA_SGRx_H};
            dma_sgrxh.b.sgsn = DMA_InitStruct->DMA_GatherCircularStreamingNum;
            DMA_Channelx->DMA_SGRx_H = dma_sgrxh.d32;
        }
    }
    /* Set for scatter */
    if (DMA_IsGatherScatterChannel(DMA_Channelx))
    {
        dma_ctlxl.b.dst_scatter_en = DMA_InitStruct->DMA_ScatterEn;
        DMA_Channelx->DMA_CTLx_L = dma_ctlxl.d32;

        if ((DMA_InitStruct->DMA_ScatterEn == 1))
        {
            DMA_DSRx_L_TypeDef dma_dsrxl = {.d32 = DMA_Channelx->DMA_DSRx_L};
            dma_dsrxl.b.dsi = DMA_InitStruct->DMA_ScatterInterval & 0xFFFFF;
            dma_dsrxl.b.dsc = DMA_InitStruct->DMA_ScatterCount & 0xFFF;
            DMA_Channelx->DMA_DSRx_L = dma_dsrxl.d32;

            DMA_DSRx_H_TypeDef dma_dsrxh = {.d32 = DMA_Channelx->DMA_DSRx_H};
            dma_dsrxh.b.dssn = DMA_InitStruct->DMA_ScatterCircularStreamingNum;
            DMA_Channelx->DMA_DSRx_H = dma_dsrxh.d32;
        }
    }
#endif

    /* Clear pending interrupts of corresponding DMA channel */
    temp_bit = BIT(channel_num);
    DMAx->DMA_CLEARTFR_L = temp_bit;
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMAx->DMA_CLEARTFR_H = temp_bit;
#endif
    DMAx->DMA_CLEARBLOCK_L = temp_bit;
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    DMAx->DMA_CLEARBLOCK_H = temp_bit;
#endif
    DMAx->DMA_CLEARERR_L = temp_bit;
}

/**
  * \brief  Fills each DMA_InitStruct member with its default value.
  * \param  DMA_InitStruct: pointer to a DMA_InitTypeDef structure which will
  *         be initialized.
  * \return None.
  */
void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct)
{
    /*-------------- Reset DMA init structure parameters values ------------------*/
    DMA_InitStruct->DMA_ChannelNum            = 0;
    DMA_InitStruct->DMA_Direction             = DMA_DIR_PERIPHERAL_TO_MEMORY;
    DMA_InitStruct->DMA_BufferSize            = 200;
    DMA_InitStruct->DMA_SourceInc             = DMA_SOURCE_FIX;
    DMA_InitStruct->DMA_DestinationInc        = DMA_DESTINATION_INC;
    DMA_InitStruct->DMA_SourceDataSize        = DMA_DATA_SIZE_BYTE;
    DMA_InitStruct->DMA_DestinationDataSize   = DMA_DATA_SIZE_BYTE;
    DMA_InitStruct->DMA_SourceMsize           = DMA_MSIZE_1;
    DMA_InitStruct->DMA_DestinationMsize      = DMA_MSIZE_1;
    DMA_InitStruct->DMA_SourceAddr            = 0;
    DMA_InitStruct->DMA_DestinationAddr       = 0;
    DMA_InitStruct->DMA_SourceHandshake       = 0;
    DMA_InitStruct->DMA_DestHandshake         = 0;
    DMA_InitStruct->DMA_ChannelPriority       = 4;

    DMA_InitStruct->DMA_MultiBlockEn          = DISABLE;
    DMA_InitStruct->DMA_MultiBlockMode        = LLI_TRANSFER;
    DMA_InitStruct->DMA_MultiBlockStruct      = 0;

#if (DMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    DMA_InitStruct->DMA_GatherEn             = DISABLE;
    DMA_InitStruct->DMA_GatherCount           = 0;
    DMA_InitStruct->DMA_GatherInterval        = 0;
    DMA_InitStruct->DMA_ScatterEn            = DISABLE;
    DMA_InitStruct->DMA_ScatterCount          = 0;
    DMA_InitStruct->DMA_ScatterInterval       = 0;
    DMA_InitStruct->DMA_GatherCircularStreamingNum = 0;
    DMA_InitStruct->DMA_ScatterCircularStreamingNum = 0;
#endif

#if (DMA_SUPPORT_SECURE_MODE == 1)
    DMA_InitStruct->DMA_SecureEn             = ENABLE;
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
    DMA_InitStruct->DMA_ContSarEn             = DISABLE;
    DMA_InitStruct->DMA_ContDarEn             = DISABLE;
#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMA_InitStruct->DMA_BlockCounter          = 0;
#endif
}

/**
  * \brief  Enables or disables the specified DMA Channelx.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  NewState: new state of the DMA Channelx.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void DMA_Cmd(uint8_t DMA_ChannelNum, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint8_t bit_need_set_times = 10;
    uint8_t bit_need_check_times = 50;
    uint8_t timeout = bit_need_check_times ;
    uint8_t bit_set_time = 0;

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);
    DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);

    if (NewState == ENABLE)
    {
#if (DMA_MEMORY_BARRIER_BEFORE_ENABLE == 1)
        __DSB();
#endif
        /* Enable the selected DMA Channel */
        DMAx->DMA_CHENREG_L = CHANNEL_BIT(channel_num) | CHANNEL_WE_BIT(channel_num);
    }
    else if (NewState == DISABLE)
    {
        /* Disable the selected DMA Channel */

        /* DMA transfer not finished */
        if (DMAx->DMA_CHENREG_L & CHANNEL_BIT(channel_num))
        {
            /* suspend dma channel */
            DMA_Channelx->DMA_CFGx_L |= DMA_SUSPEND_TRANSMISSSION;
        }
        /* Polling fifo empty */
        while ((DMA_GetSuspendChannelStatus(DMA_Channelx) != SET) && --timeout);

        /*cfg bit0 not set */
        if (DMA_GetSuspendChannelStatus(DMA_Channelx) != SET)
        {
            timeout = bit_need_check_times;
            /* Polling cfg[1:2] 10 times set in 100timer check */
            while (--timeout)
            {
                if (DMA_GetSuspendCmdStatus(DMA_Channelx))
                {
                    bit_set_time++;
                    if (bit_set_time >= bit_need_set_times)
                    {
                        break;
                    }
                }
            }
        }

        /* Disable the selected DMAy Channelx */
        DMAx->DMA_CHENREG_L = CHANNEL_WE_BIT(channel_num);

        /* unsuspend dma channel */
        DMA_Channelx->DMA_CFGx_L &= ~(DMA_SUSPEND_TRANSMISSSION);
    }
}

/**
  * \brief  Enables or disables the specified DMA Channelx interrupts.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  DMA_IT: specifies the DMA interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg DMA_INT_TRANSFER:  Transfer complete interrupt unmask
  *         \arg DMA_INT_BLOCK:  Block transfer interrupt unmask
  *         \arg DMA_INT_ERROR :  Transfer error interrupt unmask
  *         \arg DMA_INT_HALF_BLOCK: Half Block transfer interrupt unmask
  * \param  NewState: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void DMA_INTConfig(uint8_t DMA_ChannelNum, uint32_t DMA_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMAx_ChannelNum(DMA_ChannelNum));
    assert_param(IS_DMA_CONFIG_IT(DMA_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);
    DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);
    uint32_t temp_bit = 0;

    if (NewState == ENABLE)
    {
        /* Enable the selected DMA interrupts */
        temp_bit = CHANNEL_BIT(channel_num) | CHANNEL_WE_BIT(channel_num);
    }
    else
    {
        /* Disable the selected DMA interrupts */
        temp_bit = CHANNEL_WE_BIT(channel_num);
    }

    if (DMA_IT & DMA_INT_TRANSFER)
    {
        DMAx->DMA_MASKTFR_L = temp_bit;
    }
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    if ((DMA_IT & DMA_INT_BLOCK_COUNTER) && DMA_IsSupportBlockCounterChannel(DMA_Channelx))
    {
        DMAx->DMA_MASKTFR_H = temp_bit;
    }
#endif
    if (DMA_IT & DMA_INT_BLOCK)
    {
        DMAx->DMA_MASKBLOCK_L = temp_bit;
    }
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    if ((DMA_IT & DMA_INT_HALF_BLOCK) && DMA_IsHalfBlcokChannel(DMAx))
    {
        DMAx->DMA_MASKBLOCK_H = temp_bit;
    }
#endif
    if (DMA_IT & DMA_INT_ERROR)
    {
        DMAx->DMA_MASKERR_L = temp_bit;
    }
}

/**
  * \brief  Check whether DMA Channel transfer interrupt is set.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \return Transfer interrupt status, SET or RESET.
  */
ITStatus DMA_GetTransferINTStatus(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMAx_Channel_Num));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);

    if ((DMAx->DMA_STATUSTFR_L & BIT(channel_num)) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

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
ITStatus DMA_GetINTStatus(uint8_t DMA_ChannelNum, uint32_t DMA_IT)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMAx_Channel_Num));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);

    if (DMA_IT & DMA_INT_TRANSFER)
    {
        if ((DMAx->DMA_STATUSTFR_L & BIT(channel_num)) != (uint32_t)RESET)
        {
            return SET;
        }
    }

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);
    if ((DMA_IT & DMA_INT_BLOCK_COUNTER) && DMA_IsSupportBlockCounterChannel(DMA_Channelx))
    {
        if ((DMAx->DMA_STATUSTFR_H & BIT(channel_num)) != (uint32_t)RESET)
        {
            return SET;
        }
    }
#endif

    if (DMA_IT & DMA_INT_BLOCK)
    {
        if ((DMAx->DMA_STATUSBLOCK_L & BIT(channel_num)) != (uint32_t)RESET)
        {
            return SET;
        }
    }

#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    if ((DMA_IT & DMA_INT_HALF_BLOCK) && DMA_IsHalfBlcokChannel(DMAx))
    {
        if ((DMAx->DMA_STATUSBLOCK_H & BIT(channel_num)) != (uint32_t)RESET)
        {
            return SET;
        }
    }
#endif

    if (DMA_IT & DMA_INT_ERROR)
    {
        if ((DMAx->DMA_STATUSERR_L & BIT(channel_num)) != (uint32_t)RESET)
        {
            return SET;
        }
    }

    return RESET;
}

/**
  * \brief  Clear the specified DMA Channelx interrupts.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  DMA_IT: specifies the DMA interrupts sources to be enabled
  *         or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg DMA_INT_TRANSFER:  clear transfer complete interrupt.
  *         \arg DMA_INT_BLOCK:  clear Block transfer interrupt.
  *         \arg DMA_INT_ERROR  :  clear Transfer error interrupt.
  *         \arg DMA_INT_HALF_BLOCK:  clear Half Block transfer interrupt.
  * \param  NewState: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void DMA_ClearINTPendingBit(uint8_t DMA_ChannelNum, uint32_t DMA_IT)
{
    /* Check the parameters */
    assert_param(IS_DMAx_ChannelNum(DMAx_ChannelNum));
    assert_param(IS_DMA_CONFIG_IT(DMA_IT));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);
    DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);
    uint32_t temp_bit = BIT(channel_num);

    /* clear the selected DMA interrupts */
    if (DMA_IT & DMA_INT_TRANSFER)
    {
        DMAx->DMA_CLEARTFR_L = temp_bit;
#if (DMA_READ_REG_AFTER_CLEAR == 1)
        DMAx->DMA_CLEARTFR_L;
#endif
    }
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    if ((DMA_IT & DMA_INT_BLOCK_COUNTER) && DMA_IsSupportBlockCounterChannel(DMA_Channelx))
    {
        DMAx->DMA_CLEARTFR_H = temp_bit;
#if (DMA_READ_REG_AFTER_CLEAR == 1)
        DMAx->DMA_CLEARTFR_H;
#endif
    }
#endif
    if (DMA_IT & DMA_INT_BLOCK)
    {
        DMAx->DMA_CLEARBLOCK_L = temp_bit;
#if (DMA_READ_REG_AFTER_CLEAR == 1)
        DMAx->DMA_CLEARBLOCK_L;
#endif
    }
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    if ((DMA_IT & DMA_INT_HALF_BLOCK) && DMA_IsHalfBlcokChannel(DMAx))
    {
        DMAx->DMA_CLEARBLOCK_H = temp_bit;
#if (DMA_READ_REG_AFTER_CLEAR == 1)
        DMAx->DMA_CLEARBLOCK_H;
#endif
    }
#endif
    if (DMA_IT & DMA_INT_ERROR)
    {
        DMAx->DMA_CLEARERR_L = temp_bit;
#if (DMA_READ_REG_AFTER_CLEAR == 1)
        DMAx->DMA_CLEARERR_L;
#endif
    }
}

/**
  * \brief  Clear DMAx Channelx all type interrupt.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \return None.
  */
void DMA_ClearAllTypeINT(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_Num(DMAx));
    assert_param(IS_DMA_ChannelNum(DMA_Channel_Num));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);
    uint32_t temp_bit = BIT(channel_num);

    DMAx->DMA_CLEARTFR_L = temp_bit;
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    DMAx->DMA_CLEARTFR_H = temp_bit;
#endif
    DMAx->DMA_CLEARBLOCK_L = temp_bit;
#if (DMA_SUPPORT_INT_HAIF_BLOCK == 1)
    DMAx->DMA_CLEARBLOCK_H = temp_bit;
#endif
    DMAx->DMA_CLEARERR_L = temp_bit;

#if (DMA_READ_REG_AFTER_CLEAR == 1)
    DMAx->DMA_CLEARTFR_L;
#endif
}

/**
  * \brief  Get selected DMA channel status.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \return DMA channel status: can be SET or RESET.
  * \return None.
  */
FlagStatus DMA_GetChannelStatus(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);
    uint8_t channel_num = DMA_GetDMAChNumByCh(DMA_ChannelNum);

    if ((DMAx->DMA_CHENREG_L & CHANNEL_BIT(channel_num)) != (uint32_t)RESET)
    {
        return SET;
    }
    return  RESET;
}

/**
 * \brief  Check DMA FIFO status.
 * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return DMA FIFO status.
 */
FlagStatus DMA_GetFIFOStatus(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if ((DMA_Channelx->DMA_CFGx_L & DMA_FIFO_STATUS) != (uint32_t)RESET)
    {
        if (DMA_GetSuspendCmdStatus(DMA_Channelx))
        {
            return SET;
        }
    }
    return  RESET;
}

/**
 * \brief  Check DMA suspend command status.
 * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return DMA suspend command status.
 */
FlagStatus DMA_GetSuspendCmdStatus(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if ((DMA_Channelx->DMA_CFGx_L & DMA_SUSPEND_CMD_STATUS) == DMA_SUSPEND_CMD_STATUS)
    {
        return SET;
    }
    return  RESET;
}

/**
 * \brief  Check DMA suspend channel status.
 * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return DMA suspend channel status.
 */
FlagStatus DMA_GetSuspendChannelStatus(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if ((DMA_Channelx->DMA_CFGx_L & DMA_SUSPEND_CHANNEL_STATUS) == DMA_SUSPEND_CHANNEL_STATUS)
    {
        return SET;
    }
    return  RESET;
}

/**
 * \brief  Suspend DMA transmission from the source.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  NewState: New state of the DMAx Channelx.
 * \return None.
 */
void DMA_SuspendCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == DISABLE)
    {
        /* Not suspend transmission*/
        DMA_Channelx->DMA_CFGx_L &= ~(DMA_SUSPEND_TRANSMISSSION);
    }
    else
    {
        /* Suspend transmission */
        DMA_Channelx->DMA_CFGx_L |= DMA_SUSPEND_TRANSMISSSION;
    }
}

/**
  * \brief  Suspend DMA transmission safe from the source.Please check DMA FIFO empty to guarnatee without losing data.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
  * \return true: suspend success, false: suspend failed
  */
bool DMA_SafeSuspend(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    uint8_t bit_set_time = 0;
    uint8_t bit_need_set_times = 10;
    uint8_t bit_need_check_times = 50;
    uint8_t timeout = bit_need_check_times;

    /* Suspend transmission */
    DMA_Channelx->DMA_CFGx_L |= DMA_SUSPEND_TRANSMISSSION;

    /* Disable the selected DMAy Channelx */
    /* polling fifo empty */
    while ((DMA_GetSuspendChannelStatus(DMA_Channelx) != SET) && timeout--);
    if (DMA_GetSuspendChannelStatus(DMA_Channelx) != SET)
    {
        timeout = bit_need_check_times;
        /*polling cfg[1:2] 10 times set in 100timer check */
        while (--timeout)
        {
            if (DMA_GetSuspendCmdStatus(DMA_Channelx))
            {
                bit_set_time++;
                if (bit_set_time >= bit_need_set_times)
                {
                    break;
                }
            }
        }
        if (timeout == 0)
        {
            /* unsuspend dma channel */
            DMA_Channelx->DMA_CFGx_L &= ~(DMA_SUSPEND_TRANSMISSSION);
            return false;
        }
    }

    return true;
}

/**
 * \brief  Set DMA transmission source address.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  Address: Source address.
 * \return None.
 */
void DMA_SetSourceAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_Channelx->DMA_SARx = Address;
}

/**
 * \brief  Set DMA transmission destination address.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  Address: Destination address.
 * \return None.
 */
void DMA_SetDestinationAddress(DMA_ChannelTypeDef *DMA_Channelx,
                               uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_Channelx->DMA_DARx = Address;
}

/**
 * \brief  Set DMA LLP stucture address.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  Address: LLP stucture address.
 * \return None.
 */
void DMA_SetLLPAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_Channelx->DMA_LLPx_L = Address & 0xFFFFFFFC;
}

/**
 * \brief  Set DMA buffer size.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  buffer_size: Set DMA_BufferSize, max 65535.
 * \return None.
 */
void DMA_SetBufferSize(DMA_ChannelTypeDef *DMA_Channelx, uint32_t buffer_size)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    /* Configure high 32 bit of CTL register */
    DMA_Channelx->DMA_CTLx_H = buffer_size;
}

/**
 * \brief  Get DMA source address.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return Source address.
 */
uint32_t DMA_GetSrcTransferAddress(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return DMA_Channelx->DMA_SARx;
}

/**
 * \brief  Get DMA destination address.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return Destination address.
 */
uint32_t DMA_GetDstTransferAddress(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return DMA_Channelx->DMA_DARx;
}

/**
 * \brief  Get DMA transfer data length.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \return DMA transfer data length.
 */
uint16_t DMA_GetTransferLen(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return (uint16_t)(DMA_Channelx->DMA_CTLx_H & 0xFFFFFFFF);
}

/**
 * \brief  Update DMA LLP mode in multi-block.
  * \param  DMA_Channelx: Select the DMA peripheral. \ref DMA_Declaration
 * \param  DMA LLP mode
 * \return None.
 */
void DMA_SetLLPMode(DMA_ChannelTypeDef *DMA_Channelx, uint32_t mode)
{
    DMA_Channelx->DMA_CTLx_L = ((DMA_Channelx->DMA_CTLx_L & (~LLI_TRANSFER)) | mode);
}

#if (DMA_SUPPORT_SECURE_MODE == 1)
/**
  * \brief  Enable or disable the specified DMA channel secure functions.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  NewState: Specifies the DMA channel secure function to be enabled or disabled.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void DMA_SecureCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_CFGx_H_TypeDef dma_cfgxh = {.d32 = DMA_Channelx->DMA_CFGx_H};
    dma_cfgxh.b.protctl = !NewState;
    DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
}
#endif

#if (DMA_SUPPORT_OSW_OSR_CHANGE == 1)
/**
  * \brief  Set DMA OSW.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  osw_count: outstanding write count.
  * \return None.
  */
void DMA_SetOSW(uint8_t DMA_ChannelNum, uint8_t osw_count)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);

    DMA_DMAOSNUM_L_TypeDef dma_osnum = {.d32 = DMAx->DMA_DMAOSNUM_L};
    dma_osnum.b.osw = osw_count & 0xFF;
    DMAx->DMA_DMAOSNUM_L = dma_osnum.d32;
}

/**
  * \brief  Set DMA OSR.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  osr_count: outstanding read count.
  * \return None.
  */
void DMA_SetOSR(uint8_t DMA_ChannelNum, uint8_t osr_count)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);

    DMA_DMAOSNUM_L_TypeDef dma_osnum = {.d32 = DMAx->DMA_DMAOSNUM_L};
    dma_osnum.b.osr = osr_count & 0xFF;
    DMAx->DMA_DMAOSNUM_L = dma_osnum.d32;
}

/**
  * \brief  Get DMA OSW.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \return osw_count: outstanding write count.
  */
uint8_t DMA_GetOSWCount(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);

    DMA_DMAOSNUM_L_TypeDef dma_osnum = {.d32 = DMAx->DMA_DMAOSNUM_L};

    return dma_osnum.b.osw & 0xFF;
}

/**
  * \brief  Get DMA OSR.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \return osr_count: outstanding read count.
  */
uint8_t DMA_GetOSRCount(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    DMA_TypeDef *DMAx = DMA_GetDMAxByCh(DMA_ChannelNum);

    DMA_DMAOSNUM_L_TypeDef dma_osnum = {.d32 = DMAx->DMA_DMAOSNUM_L};

    return dma_osnum.b.osr & 0xFF;
}
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
/**
  * \brief  Continous source address.
  * \param  DMA_ChannelNum: Select the DMA channel number. \ref DMA_CHANNEL_NUM
  * \param  osw_count: outstanding write count.
  * \return None.
  */
void DMA_ContSarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if (DMA_IsSupportContinuousAddrChannel(DMA_Channelx) == 0)
    {
        return;
    }

    DMA_CFGx_H_TypeDef dma_cfgxh = {.d32 = DMA_Channelx->DMA_CFGx_H};
    dma_cfgxh.b.cont_sar = NewState;
    DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
}

void DMA_ContDarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if (DMA_IsSupportContinuousAddrChannel(DMA_Channelx) == 0)
    {
        return;
    }

    DMA_CFGx_H_TypeDef dma_cfgxh = {.d32 = DMA_Channelx->DMA_CFGx_H};
    dma_cfgxh.b.cont_dar = NewState;
    DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;
}
#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
void DMA_SetBlockCounter(DMA_ChannelTypeDef *DMA_Channelx, uint32_t block_counter)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if (DMA_IsSupportBlockCounterChannel(DMA_Channelx) == 0)
    {
        return;
    }

    DMA_Channelx->DMA_BLK_COUNTER_REGx = block_counter;
}
#endif

#if (DMA_SUPPORT_RAP_FUNCTION == 1)

bool DMA_RAPModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if (DMA_IsSupportRAPChannel(DMA_Channelx) == 0)
    {
        return false;
    }

    DMA_CFGx_H_TypeDef dma_cfgxh = {.d32 = DMA_Channelx->DMA_CFGx_H};
    dma_cfgxh.b.direct_ctl_en = NewState;
    DMA_Channelx->DMA_CFGx_H = dma_cfgxh.d32;

    return true;
}

#endif



