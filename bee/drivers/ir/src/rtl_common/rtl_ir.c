/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_ir.c
* \brief    This file provides all the IR firmware functions.
* \details
* \author   yuzhuo_liu
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_ir.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the IR peripheral registers to their default values.
  * \param  None
  * \return None
  */
void IR_DeInit(void)
{
    RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, DISABLE);
}

/**
  * \brief  Initializes the IR peripheral according to the specified
  *         parameters in the IR_InitStruct
  * \param  IR_InitStruct: Pointer to a IR_InitTypeDef structure that
  *         contains the configuration information for the specified IR peripheral
  * \return None
  */
void IR_Init(IR_InitTypeDef *IR_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_IR_CLOCK(IR_InitStruct->IR_Clock));

    if (IR_InitStruct->IR_Clock == 40000000)
    {
        assert_param(IS_IR_FREQUENCY_40M(IR_InitStruct->IR_Freq));
    }
#if  IR_SUPPORT_CLOCK_SOURCE_80M
    else if (IR_InitStruct->IR_Clock == 80000000)
    {
        assert_param(IS_IR_FREQUENCY_80M(IR_InitStruct->IR_Freq));
    }
#endif
#if IR_SUPPORT_CLOCK_SOURCE_90M
    else if (IR_InitStruct->IR_Clock == 90000000)
    {
        assert_param(IS_IR_FREQUENCY_90M(IR_InitStruct->IR_Freq));
    }
#endif
#if  IR_SUPPORT_CLOCK_SOURCE_100M
    else if (IR_InitStruct->IR_Clock == 100000000)
    {
        assert_param(IS_IR_FREQUENCY_100M(IR_InitStruct->IR_Freq));
    }
#endif
    assert_param(IS_IR_MODE(IR_InitStruct->IR_Mode));


    /* Configure IR clock divider. Formula: IR_CLK = IO_CLK/(1+IR_CLK_DIV) */
    uint32_t ir_clk_div_num = (IR_InitStruct->IR_Clock / IR_InitStruct->IR_Freq) - 1;
    uint32_t duty_cycle_num = ((double)(ir_clk_div_num + 1.0)) / (IR_InitStruct->IR_DutyCycle);

    IR_CLK_DIV_TypeDef ir_0x00 = {.d32 = IR->IR_CLK_DIV};
    ir_0x00.b.ir_clk_div = ir_clk_div_num;
    IR->IR_CLK_DIV = ir_0x00.d32;
    if (IR_InitStruct->IR_Mode == IR_MODE_TX)
    {
        /* Check the parameters in TX mode */
        assert_param(IS_IR_IDLE_STATUS(IR_InitStruct->IR_TxIdleLevel));
        assert_param(IS_IR_TX_DATA_TYPE(IR_InitStruct->IR_TxInverse));
        assert_param(IS_IR_TX_THRESHOLD(IR_InitStruct->IR_TxFIFOThrLevel));

        /* Stop Transmission mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_tx_start = 0;

        /* Configure TX mode parameters and disable all TX interrupt */
        ir_0x04.b.ir_mode_sel = IR_InitStruct->IR_Mode;
        ir_0x04.b.ir_tx_idel_state = IR_InitStruct->IR_TxIdleLevel;
        ir_0x04.b.ir_tx_de_inverse = IR_InitStruct->IR_TxInverse;
        ir_0x04.b.ir_tx_fifo_level_th = IR_InitStruct->IR_TxFIFOThrLevel;
        ir_0x04.b.ir_tx_duty_num = duty_cycle_num & 0x3FFF;
        IR->IR_TX_CONFIG = ir_0x04.d32;

        /* Clear all TX interrupt and TX FIFO */
        IR->IR_TX_INT_CLR = IR_TX_INT_ALL_CLR | IR_TF_CLR;

        /* Config dma tx */
        IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
        ir_0x50.d32 = 0;
        ir_0x50.b.reg_dma_tx_en = IR_InitStruct->IR_TxDmaEn;
        ir_0x50.b.reg_dma_tx_fifo_th = IR_InitStruct->IR_TxWaterLevel;
        IR->IR_DMA_CONFIG = ir_0x50.d32;
    }
    else
    {
        /* Check the parameters in RX mode */
        assert_param(IS_RX_START_MODE(IR_InitStruct->IR_RxStartMode));
        assert_param(IS_IR_RX_THRESHOLD(IR_InitStruct->IR_RxFIFOThrLevel));
        assert_param(IS_IR_RX_FIFO_FULL_CTRL(IR_InitStruct->IR_RxFIFOFullCtrl));
        assert_param(IS_RX_RX_TRIGGER_EDGE(IR_InitStruct->IR_RxTriggerMode));
        assert_param(IS_IR_RX_FILTER_TIME_CTRL(IR_InitStruct->IR_RxFilterTime));
        assert_param(IS_IR_RX_COUNT_LEVEL_CTRL(IR_InitStruct->IR_RxCntThrType));
        assert_param(IS_IR_RX_COUNTER_THRESHOLD(IR_InitStruct->IR_RxCntThr));

        /* Stop Receiving mode */
        IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
        ir_0x18.b.ir_rx_start = 0;
        IR->IR_RX_CONFIG = ir_0x18.d32;

        /* Enable RX mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_mode_sel = IR_InitStruct->IR_Mode;
        IR->IR_TX_CONFIG = ir_0x04.d32;

        /* Configure RX mode parameters and disable all RX interrupt */
        ir_0x18.b.ir_rx_start_mode = IR_InitStruct->IR_RxStartMode;
        ir_0x18.b.ir_rx_trigger_mode = IR_InitStruct->IR_RxTriggerMode;
        ir_0x18.b.ir_rx_filter_stage = IR_InitStruct->IR_RxFilterTime;
        ir_0x18.b.ir_rx_fifo_discard_set = IR_InitStruct->IR_RxFIFOFullCtrl;
        ir_0x18.b.ir_rx_fifo_level_th = IR_InitStruct->IR_RxFIFOThrLevel;
        IR->IR_RX_CONFIG = ir_0x18.d32;

        /* Configure IR RX counter threshold parameters */
        IR_RX_CNT_INT_SEL_TypeDef ir_0x24 = {.d32 = IR->IR_RX_CNT_INT_SEL};
        ir_0x24.b.ir_rx_cnt_thr_trigger_lv = IR_InitStruct->IR_RxCntThrType;
        ir_0x24.b.ir_rx_cnt_thr = IR_InitStruct->IR_RxCntThr;
        IR->IR_RX_CNT_INT_SEL = ir_0x24.d32;

        /* Clear all RX interrupt and RX FIFO */
        IR->IR_RX_INT_CLR = IR_RX_INT_ALL_CLR | IR_RF_CLR;

        /* Config dma rx */
        IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
        ir_0x50.b.reg_dma_rx_en = IR_InitStruct->IR_RxDmaEn;
        ir_0x50.b.reg_dma_rx_fifo_th = IR_InitStruct->IR_RxWaterLevel;
        IR->IR_DMA_CONFIG = ir_0x50.d32;
    }
}

/**
  * \brief  Fills each IR_InitStruct member with its default value.
  * \param  IR_InitStruct: Pointer to an IR_InitTypeDef structure which will be initialized.
  * \return None
  */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct)
{
    /* IR source clock is 40MHz */
    IR_InitStruct->IR_Clock             = IR_CLOCK_40M;
    /* IR carrier freqency is 38KHz */
    IR_InitStruct->IR_Freq              = 38000;
    IR_InitStruct->IR_DutyCycle         = 3;
    /* IR transmitting mode */
    IR_InitStruct->IR_Mode              = IR_MODE_TX;
    /* Tx pin output low when tx is idle */
    IR_InitStruct->IR_TxIdleLevel       = IR_IDLE_OUTPUT_LOW;
    /* Do not inverse tx data */
    IR_InitStruct->IR_TxInverse         = IR_TX_DATA_NORMAL;
    /* Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt */
    /* Tx fifo depth: 32 bytes */
    IR_InitStruct->IR_TxFIFOThrLevel    = 0;
    /* Rx auto start */
    IR_InitStruct->IR_RxStartMode       = IR_RX_AUTO_MODE;
    /* Rx fifo depth: 32 bytes */
    IR_InitStruct->IR_RxFIFOThrLevel    = 0;
    /* Discard the oldest received dta if RX FIFO is full */
    IR_InitStruct->IR_RxFIFOFullCtrl    = IR_RX_FIFO_FULL_DISCARD_NEWEST;
    /* Falling edge will trigger rx */
    IR_InitStruct->IR_RxTriggerMode     = IR_RX_FALL_EDGE;
    /* If high to low or low to high transition time <= 50ns,Filter out it. */
    IR_InitStruct->IR_RxFilterTime      = IR_RX_FILTER_TIME_50ns;
    /* Configure trigger type */
    IR_InitStruct->IR_RxCntThrType      = IR_RX_Count_Low_Level;
    /* Configure RX counter threshold.You can use it to decide to stop receiving IR data
       This value can be 0 to 0x7fffffff */
    IR_InitStruct->IR_RxCntThr          = 0x23a;
    /* Disable tx dma */
    IR_InitStruct->IR_TxDmaEn           = DISABLE;
    /* IR Tx waterlevel, should be less than fifo threshold.
       The best value is IR FIFO Depth - GDMA Msize */
    IR_InitStruct->IR_TxWaterLevel      = 31;
    /* Disable rx dma */
    IR_InitStruct->IR_RxDmaEn           = DISABLE;
    /* IR Rx waterlevel, should be less than fifo threshold.
       The best value is GDMA Msize */
    IR_InitStruct->IR_RxWaterLevel      = 1;
}

/**
  * \brief  Enable or disable the selected IR mode.
  * \param  mode: Selected IR operation mode.
  *         This parameter can be the following values:
  *         \arg IR_MODE_TX: Transmission mode.
  *         \arg IR_MODE_RX: Receiving mode.
  * \param  NewState: New state of the operation mode.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void IR_Cmd(uint32_t mode, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_MODE(mode));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (mode == IR_MODE_TX)
    {
        /* Start or stop Transmission mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_tx_start = NewState;
        IR->IR_TX_CONFIG = ir_0x04.d32;
    }
    else
    {
        /* Start or stop Receiving mode */
        IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
        ir_0x18.b.ir_rx_start = NewState;
        IR->IR_RX_CONFIG = ir_0x18.d32;
    }
}

/**
  * \brief  Mask or unmask the specified IR interrupts.
  * \param  IR_INT: Specifies the IR interrupts sources to be mask or unmask.
  *         This parameter can be the following values:
  *         \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
  *         \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
  *         \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
  *         \arg IR_INT_TF_FINISH: TX finish interrupt.
  *         \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
  *         \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
  *         \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
  *         \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
  *         \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
  *         \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
  *         \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
  *         \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
  * \param  NewState: New state of the specified IR interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (NewState == ENABLE)
    {
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Enable the selected IR interrupts in RX mode */
            if (IR_INT & IR_RX_EXTENSION_INT)
            {
                IR->IR_RX_EX_INT |= (IR_INT & (~IR_RX_EXTENSION_INT)) << 2;
            }
            else
            {
                IR->IR_RX_CONFIG |= (IR_INT << IR_RX_MSK_TO_EN_Pos);
            }
        }
        else
        {
            /* Enable the selected IR interrupts in TX mode */
            if (IR_INT == IR_INT_TF_OF)
            {
                IR->IR_TX_CONFIG |= (IR_INT << IR_TX_FIFO_OVER_MSK_TO_EN_Pos);
            }
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            else if (IR_INT == IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR |= IR_INT << 1;
            }
#endif
            else
            {
                IR->IR_TX_CONFIG |= (IR_INT << IR_TX_MSK_TO_EN_Pos);
            }
        }
    }
    else
    {
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Disable the selected IR interrupts in RX mode */
            if (IR_INT & IR_RX_EXTENSION_INT)
            {
                IR->IR_RX_EX_INT &= ~((IR_INT & (~IR_RX_EXTENSION_INT)) << 2);
            }
            else
            {
                IR->IR_RX_CONFIG &= (~(IR_INT << IR_RX_MSK_TO_EN_Pos));
            }
        }
        else
        {
            /* Disable the selected IR interrupts in TX mode */
            if (IR_INT == IR_INT_TF_OF)
            {
                IR->IR_TX_CONFIG &= (~(IR_INT << IR_TX_FIFO_OVER_MSK_TO_EN_Pos));
            }
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            else if (IR_INT == IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR &= ~(IR_INT << 1);
            }
#endif
            else
            {
                IR->IR_TX_CONFIG &= (~(IR_INT << IR_TX_MSK_TO_EN_Pos));
            }
        }
    }
}

/**
  * \brief  Enable or disable the specified IR interrupts.
  * \param  IR_INT: Specifies the IR interrupts sources to be enabled or disabled.
  *         This parameter can be the following values:
  *         \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
  *         \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
  *         \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
  *         \arg IR_INT_TF_FINISH: TX finish interrupt.
  *         \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
  *         \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
  *         \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
  *         \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
  *         \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
  *         \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
  *         \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
  *         \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
  * \param  NewState: New state of the specified IR interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void IR_INTConfig(uint32_t IR_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (NewState == ENABLE)
    {
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Enable the selected IR interrupts in RX mode */
            if (IR_INT & IR_RX_EXTENSION_INT)
            {
                IR->IR_RX_EX_INT |= IR_INT & (~IR_RX_EXTENSION_INT);
            }
            else
            {
                IR->IR_RX_CONFIG |= IR_INT;
            }
        }
        else
        {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            if (IR_INT == IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR |= IR_INT;
            }
            else
            {
                /* Enable the selected IR interrupts in TX mode */
                IR->IR_TX_CONFIG |= IR_INT;
            }
#else
            /* Enable the selected IR interrupts in TX mode */
            IR->IR_TX_CONFIG |= IR_INT;
#endif
        }
    }
    else
    {
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Disable the selected IR interrupts in RX mode */
            if (IR_INT & IR_RX_EXTENSION_INT)
            {
                IR->IR_RX_EX_INT &= ~(IR_INT & (~IR_RX_EXTENSION_INT));
            }
            else
            {
                IR->IR_RX_CONFIG &= (~IR_INT);
            }
        }
        else
        {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            if (IR_INT == IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR &= (~IR_INT);
            }
            else
            {
                /* Disable the selected IR interrupts in TX mode */
                IR->IR_TX_CONFIG &= (~IR_INT);
            }
#else
            /* Disable the selected IR interrupts in TX mode */
            IR->IR_TX_CONFIG &= (~IR_INT);
#endif
        }
    }
}

/**
  * \brief   Start trigger only in manual receive mode.
  * \param  None.
  * \return None
  */
void IR_StartManualRxTrigger(void)
{
    /* Start Rx manual mode */
    IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
    ir_0x18.b.ir_rx_man_start = 0x01;
    IR->IR_RX_CONFIG = ir_0x18.d32;
}

/**
  * \brief  Configure counter threshold value in receiving mode.You can use it to stop receiving IR data.
  * \param  IR_RxCntThrType: This parameter can be the following values:
  *         \arg IR_RX_Count_Low_Level: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
  *         \arg IR_RX_Count_High_Level: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
  * \param  IR_RxCntThr: Configure IR Rx counter threshold value which can be 0 to 0x7fffffffUL.
  * \return None
  */
void IR_SetRxCounterThreshold(uint32_t IR_RxCntThrType, uint32_t IR_RxCntThr)
{
    /* Check the parameters */
    assert_param(IS_IR_RX_COUNT_LEVEL_CTRL(IR_RxCntThrType));
    assert_param(IS_IR_RX_COUNTER_THRESHOLD(IR_RxCntThr));

    /* Configure IR RX counter threshold parameters */
    IR_RX_CNT_INT_SEL_TypeDef ir_0x24 = {.d32 = IR->IR_RX_CNT_INT_SEL};
    ir_0x24.b.ir_rx_cnt_thr = IR_RxCntThr;
    ir_0x24.b.ir_rx_cnt_thr_trigger_lv = IR_RxCntThrType;
    IR->IR_RX_CNT_INT_SEL = ir_0x24.d32;
}

/**
  * \brief  Send data.
  * \param  pBuf: data buffer to send.
  * \param  len: buffer length.
  * \param  IsLastPacket: Is it the last package of data.
  *         This parameter can be the following values:
  *         \arg ENABLE: The last data in IR packet and there is no continous data.In other words, An infrared data transmission is completed.
  *         \arg DISABLE: There is data to be transmitted continuously.
  * \return None
  */
void IR_SendBuf(uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(IsLastPacket));

    uint32_t i = 0;
    if (len > 0)
    {
        i = len - 1;
        while (i--)
        {
            IR->IR_TX_FIFO = *pBuf++;
        }

        /* If send the last IR packet, SET the following bit */
        if (IsLastPacket == ENABLE)
        {
            IR->IR_TX_FIFO = (IR_TX_LAST_PACKEET_Msk | *pBuf);
        }
        else
        {
            IR->IR_TX_FIFO = *pBuf;
        }
    }
}

/**
 * \brief  Send compensation data.
 * \param  comp_type: Compensation data type.
 *         \arg IR_COMPEN_FLAG_1_2_CARRIER: 1/2 carrier freqency.
 *         \arg IR_COMPEN_FLAG_1_4_CARRIER: 1/4 carrier freqency.
 *         \arg IR_COMPEN_FLAG_1_N_SYSTEM_CLK: MOD((0x48[27:16]+0x00[11:0]), 4095)/40MHz.
 *         User can call function of IR_ConfigCompParam to configure 0x48[27:16].
 * \param  buf: data buffer to send.
 * \param  length: buffer length.
 * \param  IsLastPacket: This parameter can be the following values:
 *         \arg ENABLE: The last data in IR packet and there is no continous data.In other words, An infrared data transmission is completed.
 *         \arg DISABLE: There is data to be transmitted continuously.
 * \return None
 */
void IR_SendCompenBuf(IRTxCompen_TypeDef comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(IsLastPacket));

    uint32_t i = 0;
    uint32_t temp = 0;
    if (len > 0)
    {
        i = len - 1;
        while (i--)
        {
            if (*pBuf & IR_DATA_TYPE_Msk)
            {
                IR->IR_TX_FIFO = *pBuf++;
            }
            else
            {
                IR->IR_TX_FIFO = *pBuf++ | comp_type;
            }
        }

        /* If send the last IR packet, SET the following bit */
        if (IsLastPacket == ENABLE)
        {
            temp = IR_TX_LAST_PACKEET_Msk;
        }

        if (*pBuf & IR_DATA_TYPE_Msk)
        {
            IR->IR_TX_FIFO = (temp | *pBuf);
        }
        else
        {
            IR->IR_TX_FIFO = (temp | *pBuf | comp_type);
        }
    }
}

/**
  * \brief  Read data From RX FIO.
  * \param  pBuf: Buffer address to receive data.
  * \param  len: Read data length.
  * \return None
  */
void IR_ReceiveBuf(uint32_t *pBuf, uint32_t len)
{
    while (len--)
    {
        *pBuf++ = IR->IR_RX_FIFO;
    }
}

/**
  * \brief Get the specified IR interrupt status.
  * \param  IR_INT: The specified IR interrupts.
  *         This parameter can be one of the following values:
  *         \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
  *         \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
  *         \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
  *         \arg IR_INT_TF_FINISH: TX finish interrupt.
  *         \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
  *         \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
  *         \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
  *         \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
  *         \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
  *         \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
  *         \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
  *         \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
  * \return The new state of IR_INT (SET or RESET).
  */
ITStatus IR_GetINTStatus(uint32_t IR_INT)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));

    ITStatus bit_status = RESET;

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (ir_0x04.b.ir_mode_sel)
    {
        /* Get the selected IR interrupts in RX mode */
        if (IR_INT & IR_RX_EXTENSION_INT)
        {
            if (IR->IR_RX_EX_INT & ((IR_INT & (~IR_RX_EXTENSION_INT)) << 4))
            {
                bit_status = SET;
            }
        }
        else
        {
            if (IR->IR_RX_SR & IR_INT)
            {
                bit_status = SET;
            }
        }
    }
    else
    {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
        if (IR_INT != IR_INT_TF_OF && IR_INT != IR_INT_TX_FINISH)
#else
        /* Get the selected IR interrupts in TX mode */
        if (IR_INT != IR_INT_TF_OF)
#endif
        {
            if (IR->IR_TX_SR & IR_INT)
            {
                bit_status = SET;
            }
        }
        else
        {
            if (IR->IR_TX_SR & (IR_INT >> IR_TX_STATUS_TO_EN_Pos))
            {
                bit_status = SET;
            }
        }
    }

    /* Return the IR_INT status */
    return  bit_status;
}

/**
  * \brief  Clears the IR interrupt pending bits.
  * \param  IR_IT: Specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *         \arg IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
  *         \arg IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
  *         \arg IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
  *         \arg IR_INT_TX_FINISH_CLR: Clear TX finish interrupt.
  *         \arg IR_INT_RF_FULL_CLR: Clear RX FIFO  full interrupt.
  *         \arg IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
  *         \arg IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
  *         \arg IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
  *         \arg IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
  *         \arg IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
  *         \arg IR_INT_RX_RISING_EDGE_CLR: Clear RX Rising edge interrupt.
  *         \arg IR_INT_RX_FALLING_EDGE_CLR: Clear RX Falling edge interrupt.
  * \return None
  */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CLEAR(IR_CLEAR_INT));
    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};

    if (ir_0x04.b.ir_mode_sel)
    {
        /* Clear the selected IR interrupts in RX mode */
//        if (IR_CLEAR_INT & IR_RX_EXTENSION_INT)
//        {
//            IR->IR_RX_EX_INT |= (IR_CLEAR_INT & 0xC0);
//        }
//        else
//        {
        IR->IR_RX_INT_CLR |= IR_CLEAR_INT;
//        }
    }
    else
    {
        /* Clear the selected IR interrupts in TX mode */
        IR->IR_TX_INT_CLR |= IR_CLEAR_INT;
    }
}

/**
  * \brief Get free size of TX FIFO.
  * \param None.
  * \return The free size of TX FIFO.
  */
uint16_t IR_GetTxFIFOFreeLen(void)
{
    IR_TX_SR_TypeDef ir_0x08 = {.d32 = IR->IR_TX_SR};
    return (uint16_t)(IR_TX_FIFO_SIZE - ir_0x08.b.ir_tx_fifo_offset);
}

/**
  * \brief Get data size in RX FIFO.
  * \param None.
  * \return Current data size in RX FIFO.
  */
uint16_t IR_GetRxDataLen(void)
{
    IR_RX_SR_TypeDef ir_0x1c = {.d32 = IR->IR_RX_SR};
    return ((uint16_t)(ir_0x1c.b.ir_rx_fifo_offset));
}

/**
  * \brief   Send one data.
  * \param data: Send data.
  * \return  None.
  */
void IR_SendData(uint32_t data)
{
    IR->IR_TX_FIFO = data;
}

/**
  * \brief Read one data.
  * \param None.
  * \return Data which read from RX FIFO.
  */
uint32_t IR_ReceiveData(void)
{
    return IR->IR_RX_FIFO;
}

/**
  * \brief  Set tx threshold, when TX FIFO depth <= threshold value trigger interrupt.
  * \param thd: Tx threshold.
  * \return None.
  */
void IR_SetTxThreshold(uint8_t thd)
{
    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_fifo_level_th = thd;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
  * \brief   Set tx threshold, when RX FIFO depth >= threshold value trigger interrupt.
  * \param thd: Rx threshold.
  * \return  None.
  */
void IR_SetRxThreshold(uint8_t thd)
{
    IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
    ir_0x18.b.ir_rx_fifo_level_th = thd;
    IR->IR_RX_CONFIG = ir_0x18.d32;
}

/**
  * \brief Get IR RX current count.
  * \param None.
  * \return Current counter.
  */
uint32_t IR_GetRxCurrentCount(void)
{
    IR_RX_CUR_CNT_TypeDef ir_0x30 = {.d32 = IR->IR_RX_CUR_CNT};
    return ir_0x30.b.ir_rx_cur_cnt;
}

/**
  * \brief Clear IR TX FIFO.
  * \param None.
  * \return None.
  */
void IR_ClearTxFIFO(void)
{
    IR_TX_INT_CLR_TypeDef ir_0x10 = {.d32 = IR->IR_TX_INT_CLR};
    ir_0x10.b.ir_tx_fifo_clr = 0x01;
    IR->IR_TX_INT_CLR = ir_0x10.d32;
}

/**
  * \brief Clear IR RX FIFO.
  * \param None.
  * \return  None.
  */
void IR_ClearRxFIFO(void)
{
    IR_RX_INT_CLR_TypeDef ir_0x20 = {.d32 = IR->IR_RX_INT_CLR};
    ir_0x20.b.ir_rx_fifo_clr = 0x01;
    IR->IR_RX_INT_CLR = ir_0x20.d32;
}

/**
  * \brief Check whether the specified IR flag is set.
  * \param IR_FLAG: Specifies the flag to check.
  *        This parameter can be one of the following values:
  *        \arg IR_FLAG_TF_EMPTY: TX FIFO empty or not. If SET, TX FIFO is empty.
  *        \arg IR_FLAG_TF_FULL: TX FIFO full or not. If SET, TX FIFO is full.
  *        \arg IR_FLAG_TX_RUN: TX run or not. If SET, TX is running.
  *        \arg IR_FLAG_RF_EMPTY: RX FIFO empty or not. If SET, RX FIFO is empty.
  *        \arg IR_FLAG_RF_FULL: RX FIFO full or not. If SET, RX FIFO is full.
  *        \arg IR_FLAG_RX_RUN: RX run or not. If SET, RX is running.
  *
  * \return The new state of IR_FLAG (SET or RESET).
  */
FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG)
{

    /* Check the parameters */
    assert_param(IS_IR_FLAG(IR_FLAG));

    FlagStatus bitstatus = RESET;

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (ir_0x04.b.ir_mode_sel)
    {
        if (IR->IR_RX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
    else
    {
        if (IR->IR_TX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
}

/**
  * \brief   Set or reset tx data inverse.
  * \param NewState: This parameter can be: ENABLE or DISABLE.
  * \return  None.
  */
void IR_SetTxInverse(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_de_inverse = NewState;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
  * \brief  Enbale TX output inverse or not.
  * \param NewState: This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void IR_TxOutputInverse(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_output_inverse = NewState;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
  * \brief Get IR RX Level.
  * \param None.
  * \return Current Level.
  */
uint32_t IR_GetRxCurrentLevel(void)
{
    return (IR->IR_RX_LEVEL);

}
#if IR_SUPPORT_RAP_FUNCTION
void IR_RAPModeCmd(FunctionalState NewState)
{
    IR_TASK_CTRL_TypeDef ir_0x54 = {.d32 = IR->IR_TASK_CTRL};
    ir_0x54.b.ir_rap_mode = NewState;
    IR->IR_TASK_CTRL = ir_0x54.d32;

    return;
}

void IR_TaskTrigger(uint32_t Task)
{
    IR_TASK_CTRL_TypeDef ir_0x54 = {.d32 = IR->IR_TASK_CTRL};
    if (Task == IR_TASK_START_TX)
    {
        ir_0x54.b.ir_fw_task_start_tx = 0x1;
    }
    else if (Task == IR_TASK_START_RX)
    {
        ir_0x54.b.ir_fw_task_start_rx = 0x1;
    }
    IR->IR_TASK_CTRL = ir_0x54.d32;

    return;
}

void IR_RAPQactiveCtrl(uint32_t Qactive, FunctionalState NewState)
{
    IR_QACTIVE_CTRL_TypeDef ir_0x58 = {.d32 = IR->IR_QACTIVE_CTRL};
    if (Qactive == IR_QACTIVE_ICG_PCLK)
    {
        ir_0x58.b.qact_pclk_icg_en = NewState;
    }
    if (Qactive == IR_QACTIVE_FW_FORCE_SCLK)
    {
        ir_0x58.b.qact_sclk_force_en = NewState;
    }
    if (Qactive == IR_QACTIVE_FW_FORCE_PCLK)
    {
        ir_0x58.b.qact_pclk_force_en = NewState;
    }
    IR->IR_QACTIVE_CTRL = ir_0x58.d32;

    return;
}
#endif

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

