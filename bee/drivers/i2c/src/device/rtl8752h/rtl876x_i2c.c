/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Includes ------------------------------------------------------------------*/
#include "rtl876x_rcc.h"
#include "rtl876x_i2c.h"
#include "app_section.h"

/* Private defines -----------------------------------------------------------*/
/* I2C Data Cmd Mask */
#define I2C_CMD_READ_BIT                             (BIT8)
#define I2C_CMD_STOP_BIT                             (BIT9)
#define I2C_CMD_RESTART_BIT                          (BIT10)

/* SDA Setup Time */
#define I2C_SDA_SETUP_TIME_VALUE                     (2)
/* Rising Time */
#define I2C_RISING_TIME_NS                           (50)
/* SCL Low/High Period Time */
#define I2C_SCL_HIGH_PERIOD_COMPENSATE               (7)
#define I2C_SCL_LOW_PERIOD_COMPENSATE                (1)
#define NS_PER_SECOND                                (1000000000)

/* I2C SCL High/Low min period according to spec */
#define I2C_FAST_MODE_PLUS_SCL_LOW_PERIOD_MIN_NS     (500)
#define I2C_FAST_MODE_PLUS_SCL_HIGH_PERIOD_MIN_NS    (260)
#define I2C_FAST_MODE_SCL_LOW_PERIOD_MIN_NS          (1300)
#define I2C_FAST_MODE_SCL_HIGH_PERIOD_MIN_NS         (600)
#define I2C_STANDARD_MODE_SCL_LOW_PERIOD_MIN_NS      (4700)
#define I2C_STANDARD_MODE_SCL_HIGH_PERIOD_MIN_NS     (4000)
/* SDA Hold Time */
#define I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS      (600)
#define I2C_FAST_MODE_PLUS_SDA_HOLD_TIME_NS          (300)

#define ROUNDUP(a, b)                                (((a + b - 1) / b))

uint32_t I2CSrcClk;
uint32_t I2C_TimeOut = 0xFFF;
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed);

/**
  * @brief  Initializes the I2Cx peripheral according to the specified
  *   parameters in the I2C_InitStruct.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @param  I2C_InitStruct: pointer to a I2C_InitTypeDef structure that
  *   contains the configuration information for the specified I2C peripheral.
  * @retval None
  */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_CLOCK_SPEED(I2C_InitStruct->I2C_ClockSpeed));

    I2CSrcClk = I2C_InitStruct->I2C_Clock;
    /* Disable I2C device before change configuration */
    I2Cx->IC_ENABLE &= ~0x0001;

    /* Config sda tx hold time in different clock speed */
    uint8_t sda_tx_hold = 0;
    /* Tick of I2C clock source in ns. */
    uint32_t tick_clksrc_ns = NS_PER_SECOND / I2CSrcClk;

    switch (I2CSrcClk)
    {
    case 40000000:
        if (I2C_InitStruct->I2C_ClockSpeed <= 400000)
        {
            sda_tx_hold = I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / tick_clksrc_ns;
        }
        else
        {
            sda_tx_hold = I2C_FAST_MODE_PLUS_SDA_HOLD_TIME_NS / tick_clksrc_ns;
        }
        break;
    case 20000000:
        sda_tx_hold = I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / tick_clksrc_ns;
        break;
    case 10000000:
        sda_tx_hold = I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / tick_clksrc_ns;
        break;
    case 5000000:
        sda_tx_hold = I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / tick_clksrc_ns;
        break;
    default:
        break;
    }

    /* ------------------------------ Initialize I2C device ------------------------------*/
    if (I2C_DeviveMode_Master == I2C_InitStruct->I2C_DeviveMode)
    {
        /*configure I2C device mode which can be selected for master or slave*/
        I2Cx->IC_CON = I2C_InitStruct->I2C_DeviveMode | (I2C_InitStruct->I2C_AddressMode << 4) | BIT(5);

        /*set target address*/
        I2Cx->IC_TAR = (I2C_InitStruct->I2C_SlaveAddress & 0x3ff)
                       | (I2C_InitStruct->I2C_AddressMode << 12);
        /*set SDA hold time in master mode*/
        I2Cx->IC_SDA_HOLD = (0x1 << 16) | (sda_tx_hold);

        /* Configure I2C speed */
        I2C_SetClockSpeed(I2Cx, I2C_InitStruct->I2C_ClockSpeed);
    }
    else
    {
        /* set to slave mode */
        I2Cx->IC_CON = (I2C_InitStruct->I2C_DeviveMode) | (I2C_InitStruct->I2C_AddressMode << 3);
        /* set Ack in slave mode */
        I2Cx->IC_ACK_GENERAL_CALL &= I2C_InitStruct->I2C_Ack;
        /* set slave address */
        I2Cx->IC_SAR = I2C_InitStruct->I2C_SlaveAddress;
        /* set SDA hold time in slave mode */
        I2Cx->IC_SDA_HOLD = (0x08 << 16) | (sda_tx_hold);
        /* set SDA setup time delay only in slave transmitter mode(greater than 2) ,delay time:[(IC_SDA_SETUP - 1) * (ic_clk_period)]*/
        I2Cx->IC_SDA_SETUP = I2C_SDA_SETUP_TIME_VALUE;
    }

#if 1
    /*set Tx empty level*/
    I2Cx->IC_TX_TL = I2C_InitStruct->I2C_TxThresholdLevel;
    /*set Rx full level*/
    I2Cx->IC_RX_TL = I2C_InitStruct->I2C_RxThresholdLevel;
#endif

    /*Config I2C dma mode*/
    I2Cx->IC_DMA_CR = ((I2C_InitStruct->I2C_RxDmaEn)\
                       | ((I2C_InitStruct->I2C_TxDmaEn) << 1));

    /*Config I2C waterlevel*/
    I2Cx->IC_DMA_RDLR = I2C_InitStruct->I2C_RxWaterlevel;
    I2Cx->IC_DMA_TDLR = I2C_InitStruct->I2C_TxWaterlevel;

    I2Cx->IC_INTR_MASK = 0;
}

/**
  * @brief  Deinitializes the I2Cx peripheral registers to their default reset values.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @retval None
  */
void I2C_DeInit(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /*Disable I2C IP*/
    if (I2Cx == I2C0)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, DISABLE);
    }
    else if (I2Cx == I2C1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C1, APBPeriph_I2C1_CLOCK, DISABLE);
    }
}

/**
  * @brief  Fills each I2C_InitStruct member with its default value.
  * @param  I2C_InitStruct : pointer to a I2C_InitTypeDef structure which will be initialized.
  * @retval None
  */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->I2C_Clock             = 40000000;               /* depend on clock divider */
    I2C_InitStruct->I2C_ClockSpeed        = 400000;
    I2C_InitStruct->I2C_DeviveMode        = I2C_DeviveMode_Master;  /* Master mode */
    I2C_InitStruct->I2C_AddressMode       = I2C_AddressMode_7BIT;   /* 7-bit address mode */
    I2C_InitStruct->I2C_SlaveAddress      = 0;
    I2C_InitStruct->I2C_Ack               = I2C_Ack_Enable;
    I2C_InitStruct->I2C_TxThresholdLevel  = 0x00;                 /* tx fifo depth: 24 * 8bits */
    I2C_InitStruct->I2C_RxThresholdLevel  = 0x00;                 /* rx fifo depth: 40 * 8bits */
    I2C_InitStruct->I2C_TxDmaEn           = DISABLE;
    I2C_InitStruct->I2C_RxDmaEn           = DISABLE;
    I2C_InitStruct->I2C_RxWaterlevel      = 1;                    /* Best to equal GDMA Source MSize */
    I2C_InitStruct->I2C_TxWaterlevel      = 15;                   /* Best to equal Tx fifo minus
                                                                      GDMA Dest MSize */
}


/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @param  NewState: new state of the I2Cx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected I2C peripheral */
        I2Cx->IC_ENABLE |= 0x0001;
    }
    else
    {
        /* Disable the selected I2C peripheral */
        I2Cx->IC_ENABLE &= ~0x0001;
    }
}


/**
  * @brief  Checks whether the last I2Cx abort status.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @retval the status of I2Cx.
  */
I2C_Status I2C_CheckAbortStatus(I2C_TypeDef *I2Cx)
{
    uint32_t abort_status = 0;

    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /* Get abort status */
    abort_status = I2Cx->IC_TX_ABRT_SOURCE;

    if (abort_status & MS_ALL_ABORT)
    {
        /* Clear abort status */
        (void)I2Cx->IC_CLR_TX_ABRT;

        /* Check abort type */
        if (abort_status & ABRT_TXDATA_NOACK)
        {
            return I2C_ABRT_TXDATA_NOACK;
        }

        if (abort_status & ABRT_7B_ADDR_NOACK)
        {
            return I2C_ABRT_7B_ADDR_NOACK;
        }

        if (abort_status & ARB_LOST)
        {
            return I2C_ARB_LOST;
        }

        if (abort_status & ABRT_MASTER_DIS)
        {
            return I2C_ABRT_MASTER_DIS;
        }

        if (abort_status & ABRT_10ADDR1_NOACK)
        {
            return I2C_ABRT_10ADDR1_NOACK;
        }

        if (abort_status & ABRT_10ADDR2_NOACK)
        {
            return I2C_ABRT_10ADDR2_NOACK;
        }
    }

    return I2C_Success;
}


I2C_Status I2C_WaitForFIFO(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG)
{
    uint32_t timeout = I2C_TimeOut;

    /* Wait until the FIFO condition selected by I2C_FLAG becomes true:
     * - TX: writable (TX FIFO Not Full, space available)
     * - RX: readable (RX FIFO Not Empty, data available)
     */
    while (((I2Cx->IC_STATUS & I2C_FLAG) == 0) && (timeout != 0))
    {
        I2C_Status status = I2C_CheckAbortStatus(I2Cx);
        if (status != I2C_Success)
        {
            return status;
        }

        if (--timeout == 0)
        {
            return I2C_ERR_TIMEOUT;
        }
    }

    return I2C_CheckAbortStatus(I2Cx);
}

I2C_Status I2C_WaitTXIdle(I2C_TypeDef *I2Cx)
{
    uint32_t timeout = I2C_TimeOut;

    /* Wait until the transmit is fully completed:
     * - Bus becomes idle (ACTIVITY == 0)
     * - TX FIFO is empty (TFE == 1)
     */
    while ((((I2Cx->IC_STATUS & I2C_FLAG_ACTIVITY) != 0) ||
            ((I2Cx->IC_STATUS & I2C_FLAG_TFE) == 0)) &&
           (timeout != 0))
    {
        I2C_Status status = I2C_CheckAbortStatus(I2Cx);
        if (status != I2C_Success)
        {
            return status;
        }

        if (--timeout == 0)
        {
            return I2C_ERR_TIMEOUT;
        }
    }

    return I2C_Success;
}

/**
  * \brief  Send data in master mode through the I2Cx peripheral.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  pBuf: Byte to be transmitted.
  * \param  len: Data length to send.
  * \return I2C_Status: The status of I2Cx. \ref I2C_Status
  */
I2C_Status I2C_MasterWrite(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    I2C_Status status = I2C_Success;

    for (uint16_t i = 0; i < len; i++)
    {
        uint32_t cmd = *pBuf++;
        if (i == (len - 1))
        {
            cmd |= I2C_CMD_STOP_BIT;
        }
        I2Cx->IC_DATA_CMD = cmd;

        status = I2C_WaitForFIFO(I2Cx, I2C_FLAG_TFNF);
        if (status != I2C_Success)
        {
            return status;
        }
    }

    return I2C_WaitTXIdle(I2Cx);
}

/**
  * \brief  Read data in master mode through the I2Cx peripheral.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  pBuf: Data buffer to receive data.
  * \param  len: Read data length.
  * \return I2C_Status: The status of I2Cx. \ref I2C_Status
  */
I2C_Status I2C_MasterRead(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    I2C_Status status = I2C_Success;

    if (len == 0)
    {
        return status;
    }

    /* Issue the first read cmd. If only one byte is requested, append STOP immediately. */
    uint32_t cmd = 0x0 | I2C_CMD_READ_BIT;
    if (len == 1)
    {
        cmd |= I2C_CMD_STOP_BIT;
    }
    I2Cx->IC_DATA_CMD = cmd;

    for (uint16_t i = 1; i < len; i++)
    {
        /* Issue the remaining read cmd. */
        cmd = 0x0 | I2C_CMD_READ_BIT;
        if (i == (len - 1))
        {
            cmd |= I2C_CMD_STOP_BIT;
        }
        I2Cx->IC_DATA_CMD = cmd;

        /* Read byte produced by the read. */
        status = I2C_WaitForFIFO(I2Cx, I2C_FLAG_RFNE);
        if (status != I2C_Success)
        {
            return status;
        }
        *pBuf++ = (uint8_t)I2Cx->IC_DATA_CMD;
    }

    /* Read the final byte produced by the last command. */
    status = I2C_WaitForFIFO(I2Cx, I2C_FLAG_RFNE);
    if (status != I2C_Success)
    {
        return status;
    }
    *pBuf = (uint8_t)I2Cx->IC_DATA_CMD;

    return status;
}

/**
  * \brief  Sends data and read data in master mode through the I2Cx peripheral.Attention:Read data with time out mechanism.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  pWriteBuf: Data buffer to send before read.
  * \param  Writelen: Send data length.
  * \param  pReadBuf: Data buffer to receive.
  * \param  Readlen: Receive data length.
  * \return I2C_Status: The status of I2Cx. \ref I2C_Status
  */
I2C_Status I2C_RepeatRead(I2C_TypeDef *I2Cx, uint8_t *pWriteBuf, uint16_t Writelen,
                          uint8_t *pReadBuf, uint16_t Readlen)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    I2C_Status status = I2C_Success;

    for (uint16_t i = 0; i < Writelen; i++)
    {
        I2Cx->IC_DATA_CMD = *pWriteBuf++;

        status = I2C_WaitForFIFO(I2Cx, I2C_FLAG_TFNF);
        if (status != I2C_Success)
        {
            return status;
        }
    }

    for (uint16_t i = 0; i < Readlen; i++)
    {
        /* Issue the read cmd. */
        uint32_t cmd = 0x0 | I2C_CMD_READ_BIT;
        if (i == (Readlen - 1))
        {
            cmd |= I2C_CMD_STOP_BIT;
        }
        I2Cx->IC_DATA_CMD = cmd;

        /* Read byte produced by the read. */
        status = I2C_WaitForFIFO(I2Cx, I2C_FLAG_RFNE);
        if (status != I2C_Success)
        {
            return status;
        }
        *pReadBuf++ = (uint8_t)I2Cx->IC_DATA_CMD;
    }


    return status;
}

/**
  * @brief mask the specified I2C interrupt.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @param  I2C_INT
  * This parameter can be one of the following values:
  *     @arg I2C_INT_GEN_CALL: When a General Call address is received and it is acknowledged.
  *     @arg I2C_INT_START_DET: When a START or RESTART condition has occurred on the I2C interface
  *                            regardless of whether I2C is operating in slave or master mode.
  *     @arg I2C_INT_STOP_DET: When a STOP condition has occurred on the I2C interface
  *                            regardless of whether I2C is operating in slave or master mode.
  *     @arg I2C_INT_ACTIVITY: When I2C is activity on the bus. Stays set until it is cleared.
  *     @arg I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter and the master does
  *                           not acknowledge a transmitted byte.
  *                           This occurs on the last byte of the transmission,
  *                           indicating that the transmission is done.
  *     @arg I2C_INT_TX_ABRT: When an I2C transmitter is unable to complete the intended actions
  *                           on the contents of the transmit FIFO.
  *     @arg I2C_INT_RD_REQ:  When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
  *     @arg I2C_INT_TX_EMPTY: When the transmit buffer is at or below the threshold value set in the REG_IC_TXFLR register.
  *     @arg I2C_INT_TX_OVER: When transmit buffer is filled to IC_TX_BUFFER_DEPTH and
  *                           the processor attempts to issue another I2C command by writing to the REG_IC_DATA_CMD register.
  *     @arg I2C_INT_RX_FULL: When the receive buffer reaches or goes above the RX_TL threshold in the REG_IC_RX_TL register.
  *                           A value of 0 sets the threshold for 1 entry, and a value of 255 sets the threshold for 256 entries.
  *     @arg I2C_INT_RX_OVER: When the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and
  *                           an additional byte is received from an external I2C device.
  *     @arg I2C_INT_RX_UNDER: When the processor attempts to read the receive buffer
  *                            when it is empty by reading from the REG_IC_DATA_CMD register.
  * @retval None.
  */
void I2C_INTConfig(I2C_TypeDef *I2Cx, uint16_t I2C_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(I2C_GET_INT(I2C_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected I2C interrupts */
        I2Cx->IC_INTR_MASK |= I2C_INT;
    }
    else
    {
        /* Disable the selected I2C interrupts */
        I2Cx->IC_INTR_MASK &= (uint16_t)~I2C_INT;
    }
}

/**
  * @brief Clear the specified I2C interrupt.
  * @param  I2Cx: where x can be 0 or 1 to select the I2C peripheral.
  * @param  I2C_INT
  * This parameter can be one of the following values:
  *     @arg I2C_INT_GEN_CALL: When a General Call address is received and it is acknowledged.
  *     @arg I2C_INT_START_DET: When a START or RESTART condition has occurred on the I2C interface
  *                            regardless of whether I2C is operating in slave or master mode.
  *     @arg I2C_INT_STOP_DET: When a STOP condition has occurred on the I2C interface
  *                            regardless of whether I2C is operating in slave or master mode.
  *     @arg I2C_INT_ACTIVITY: When I2C is activity on the bus. Stays set until it is cleared.
  *     @arg I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter and the master does
  *                           not acknowledge a transmitted byte.
  *                           This occurs on the last byte of the transmission,
  *                           indicating that the transmission is done.
  *     @arg I2C_INT_TX_ABRT: When an I2C transmitter is unable to complete the intended actions
  *                           on the contents of the transmit FIFO.
  *     @arg I2C_INT_RD_REQ:  When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
  *     @arg I2C_INT_TX_EMPTY: When the transmit buffer is at or below the threshold value set in the REG_IC_TXFLR register.
  *     @arg I2C_INT_TX_OVER: When transmit buffer is filled to IC_TX_BUFFER_DEPTH and
  *                           the processor attempts to issue another I2C command by writing to the REG_IC_DATA_CMD register.
  *     @arg I2C_INT_RX_FULL: When the receive buffer reaches or goes above the RX_TL threshold in the REG_IC_RX_TL register.
  *                           A value of 0 sets the threshold for 1 entry, and a value of 255 sets the threshold for 256 entries.
  *     @arg I2C_INT_RX_OVER: When the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and
  *                           an additional byte is received from an external I2C device.
  *     @arg I2C_INT_RX_UNDER: When the processor attempts to read the receive buffer
  *                            when it is empty by reading from the REG_IC_DATA_CMD register.
  * @retval None.
  */
void I2C_ClearINTPendingBit(I2C_TypeDef *I2Cx, uint16_t I2C_IT)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(I2C_GET_INT(I2C_IT));

    switch (I2C_IT)
    {
    case I2C_INT_RX_UNDER:
        {
            (void)I2Cx->IC_CLR_RX_UNDER;
            break;
        }
    case I2C_INT_RX_OVER:
        {
            (void)I2Cx->IC_CLR_RX_OVER;
            break;
        }
    case I2C_INT_TX_OVER:
        {
            (void)I2Cx->IC_CLR_TX_OVER;
            break;
        }
    case I2C_INT_RD_REQ:
        {
            (void)I2Cx->IC_CLR_RD_REQ;
            break;
        }
    case I2C_INT_TX_ABRT:
        {
            (void)I2Cx->IC_CLR_TX_ABRT;
            break;
        }
    case I2C_INT_RX_DONE:
        {
            (void)I2Cx->IC_CLR_RX_DONE;
            break;
        }
    case I2C_INT_ACTIVITY:
        {
            (void)I2Cx->IC_CLR_ACTIVITY;
            break;
        }
    case I2C_INT_STOP_DET:
        {
            (void)I2Cx->IC_CLR_STOP_DET;
            break;
        }
    case I2C_INT_START_DET:
        {
            (void)I2Cx->IC_CLR_START_DET;
            break;
        }
    case I2C_INT_GEN_CALL:
        {
            (void)I2Cx->IC_CLR_GEN_CALL;
            break;
        }
    default:
        {
            break;
        }
    }
}

/**
  * \brief  Set Clock Speed through the I2Cx peripheral.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  I2C_ClockSpeed: CLock speed.
  * \return None
  */
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed)
{
    uint32_t tick_clksrc_ns = 0;
    uint32_t allowedSpeed = 0;
    uint32_t spklen = 0;
    uint32_t scl_low_period_spec_min_ns = 0;
    uint32_t scl_high_period_spec_min_ns = 0;
    uint32_t scl_lcnt_min = 0;
    uint32_t scl_hcnt_min = 0;
    uint32_t scl_low_period_min_ns = 0;
    uint32_t scl_high_period_min_ns = 0;
    uint32_t tick_clkspeed_ns = 0;
    uint32_t total_period_ns = 0;
    uint32_t total_hcnt_lcnt = 0;
    int32_t remaining = 0;
    uint32_t scl_lcnt = 0;
    uint32_t scl_hcnt = 0;

    /* Tick of I2C clock source in ns. */
    tick_clksrc_ns = NS_PER_SECOND / I2CSrcClk;

    /* Limit the maximum I2C speed according to the I2C clock source. */
    if (I2CSrcClk == 40000000)
    {
        allowedSpeed = 1000000;
    }
    else if (I2CSrcClk == 20000000)
    {
        allowedSpeed = 400000;
    }
    else
    {
        allowedSpeed = 100000;
    }
    /* Set Max I2C Clock speed. */
    I2C_ClockSpeed = (I2C_ClockSpeed > allowedSpeed) ? allowedSpeed : I2C_ClockSpeed;

    /* Set the spike time according to SPEC */
    /* For Standard mode, there is no limit on spike suppression time, use default value. */
    if (I2C_ClockSpeed <= 100000)
    {
        spklen = 0x05;
    }
    /* For Fast mode (plus), the max spike suppression time is 50ns. */
    else
    {
        spklen = 0x01;
    }

    /* Set suppression limit */
    I2Cx->IC_FS_SPKLEN = spklen & 0xFFFF;

    /******************* Calulate the SCL low high count based on SPEC *******************/
    /* Get the minimum of scl low high period specified in the spec */
    if (I2C_ClockSpeed <= 100000)
    {
        scl_low_period_spec_min_ns = I2C_STANDARD_MODE_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_STANDARD_MODE_SCL_HIGH_PERIOD_MIN_NS;
    }
    else if (I2C_ClockSpeed <= 400000)
    {
        scl_low_period_spec_min_ns = I2C_FAST_MODE_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_FAST_MODE_SCL_HIGH_PERIOD_MIN_NS;
    }
    else
    {
        scl_low_period_spec_min_ns = I2C_FAST_MODE_PLUS_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_FAST_MODE_PLUS_SCL_HIGH_PERIOD_MIN_NS;
    }


    /* Calulate the minimum of scl low high period based on LCNT/HCNT specified in hardware:
     *
     * Firstly, get the minimum LCNT HCNT specified in hardware.
     * - LCNT: IC_SS_SCL_LCNT and IC_FS_SCL_LCNT register values must be larger than IC_FS_SPKLEN + 7.
     * - HCNT: IC_SS_SCL_HCNT and IC_FS_SCL_HCNT register values must be larger than IC_FS_SPKLEN + 5.
     * Use +1 to enforce strictly greater with integer registers.
     *
     * Secondly, calulate the minimum of scl high/low period based on the LCNT/HCNT.
     */

    scl_lcnt_min = spklen + 7 + 1;
    scl_hcnt_min = spklen + 5 + 1;
    scl_low_period_min_ns = (scl_lcnt_min + I2C_SCL_LOW_PERIOD_COMPENSATE) * tick_clksrc_ns;
    scl_high_period_min_ns = (scl_hcnt_min + spklen + I2C_SCL_HIGH_PERIOD_COMPENSATE) *
                             tick_clksrc_ns;

    /* Final minimum: satisfy both spec and hardware. */
    scl_low_period_min_ns = (scl_low_period_min_ns > scl_low_period_spec_min_ns) ?
                            scl_low_period_min_ns : scl_low_period_spec_min_ns;
    scl_high_period_min_ns = (scl_high_period_min_ns > scl_high_period_spec_min_ns) ?
                             scl_high_period_min_ns : scl_high_period_spec_min_ns;

    scl_lcnt_min = ROUNDUP(scl_low_period_min_ns, tick_clksrc_ns) - I2C_SCL_LOW_PERIOD_COMPENSATE;
    scl_hcnt_min = ROUNDUP(scl_high_period_min_ns,
                           tick_clksrc_ns) - spklen - I2C_SCL_HIGH_PERIOD_COMPENSATE;

    /*************** Calulate the SCL low high count based on I2C_Clock_Speed ***************/

    /* Calculate target total (high+low) counter based on the desired frequency of I2C SCL.
     * Firstly, calulate the total period: tick_clkspeed_ns minus I2C_RisingTimeNs.
     *   - Notes: I2C_RisingTimeNs should be below the range.
     * Secondly, total_period_ns div tick_clksrc_ns, round up.
     * Then subtract SPKLEN and path compensations to get pure HCNT+LCNT sum.
     */

    tick_clkspeed_ns = NS_PER_SECOND / I2C_ClockSpeed;
    total_period_ns = tick_clkspeed_ns - I2C_RISING_TIME_NS;
    total_hcnt_lcnt = (ROUNDUP(total_period_ns, tick_clksrc_ns)
                       - spklen - I2C_SCL_HIGH_PERIOD_COMPENSATE - I2C_SCL_LOW_PERIOD_COMPENSATE);

    /***************** Distibute the remaining count to the SCL low high *****************/

    /* Calculate the remaining as total_hcnt_lcnt - (scl_lcnt_min + scl_hcnt_min),
     * distribute the remaining counts between low and high count.
     */

    remaining = total_hcnt_lcnt - scl_lcnt_min - scl_hcnt_min;
    scl_lcnt = scl_lcnt_min;
    scl_hcnt = scl_hcnt_min;
    if (remaining > 0)
    {
        scl_lcnt = scl_lcnt_min + (uint32_t)(remaining / 2);
        scl_hcnt = total_hcnt_lcnt - scl_lcnt;
    }

    /* Set speed mode and write counters to responsing registers */
    if (I2C_ClockSpeed <= 100000)
    {
        /*Configure I2C speed in standard mode*/
        I2Cx->IC_CON |= (0x3 << 1);
        I2Cx->IC_CON &= 0xfffb;
        I2Cx->IC_SS_SCL_LCNT = scl_lcnt & 0xFFFF;
        I2Cx->IC_SS_SCL_HCNT = scl_hcnt & 0xFFFF;
    }
    else
    {
        /* Configure I2C speed in fast mode or fast mode plus*/
        I2Cx->IC_CON |= (0x3 << 1);
        I2Cx->IC_CON &= 0xfffd;
        I2Cx->IC_FS_SCL_LCNT = scl_lcnt & 0xFFFF;
        I2Cx->IC_FS_SCL_HCNT = scl_hcnt & 0xFFFF;
    }
}

/**
  * \brief  Store I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Store buffer to store I2C register data.
  * \return None.
  */
DATA_RAM_FUNCTION
void I2C_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    I2C_TypeDef *I2Cx = (I2C_TypeDef *)PeriReg;
    I2CStoreReg_TypeDef *store_buf = (I2CStoreReg_TypeDef *)StoreBuf;

    if (I2Cx == I2C0)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C1, APBPeriph_I2C1_CLOCK, ENABLE);
    }

    store_buf->i2c_reg[0]  = I2Cx->IC_CON;
    store_buf->i2c_reg[1]  = I2Cx->IC_TAR;
    store_buf->i2c_reg[2]  = I2Cx->IC_SAR;
    store_buf->i2c_reg[3]  = I2Cx->IC_SS_SCL_HCNT;
    store_buf->i2c_reg[4]  = I2Cx->IC_SS_SCL_LCNT;
    store_buf->i2c_reg[5]  = I2Cx->IC_FS_SCL_HCNT;
    store_buf->i2c_reg[6]  = I2Cx->IC_FS_SCL_LCNT;
    store_buf->i2c_reg[7] = I2Cx->IC_INTR_MASK;
    store_buf->i2c_reg[8] = I2Cx->IC_RX_TL;
    store_buf->i2c_reg[9] = I2Cx->IC_TX_TL;
    store_buf->i2c_reg[10] = I2Cx->IC_ENABLE;
    store_buf->i2c_reg[11] = I2Cx->IC_SDA_HOLD;
    store_buf->i2c_reg[12] = I2Cx->IC_SLV_DATA_NACK_ONLY;
    store_buf->i2c_reg[13] = I2Cx->IC_DMA_CR;
    store_buf->i2c_reg[14] = I2Cx->IC_DMA_TDLR;
    store_buf->i2c_reg[15] = I2Cx->IC_DMA_RDLR;
    store_buf->i2c_reg[16] = I2Cx->IC_SDA_SETUP;
    store_buf->i2c_reg[17] = I2Cx->IC_FS_SPKLEN;
}

/**
  * \brief  Restore I2C register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the I2C peripheral.
  * \param  StoreBuf: Restore buffer to restore I2C register data.
  * \return None
  */
DATA_RAM_FUNCTION
void I2C_DLPSExit(void *PeriReg, void *StoreBuf)
{
    I2C_TypeDef *I2Cx = (I2C_TypeDef *)PeriReg;
    I2CStoreReg_TypeDef *store_buf = (I2CStoreReg_TypeDef *)StoreBuf;

    if (I2Cx == I2C0)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
    }
    else if (I2Cx == I2C1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2C1, APBPeriph_I2C1_CLOCK, ENABLE);
    }

    I2Cx->IC_CON         = store_buf->i2c_reg[0];
    I2Cx->IC_TAR         = store_buf->i2c_reg[1];
    I2Cx->IC_SAR         = store_buf->i2c_reg[2];
    I2Cx->IC_SS_SCL_HCNT = store_buf->i2c_reg[3];
    I2Cx->IC_SS_SCL_LCNT = store_buf->i2c_reg[4];
    I2Cx->IC_FS_SCL_HCNT = store_buf->i2c_reg[5];
    I2Cx->IC_FS_SCL_LCNT = store_buf->i2c_reg[6];
    I2Cx->IC_INTR_MASK   = store_buf->i2c_reg[7];
    I2Cx->IC_RX_TL       = store_buf->i2c_reg[8];
    I2Cx->IC_TX_TL       = store_buf->i2c_reg[9];
    I2Cx->IC_SDA_HOLD    = store_buf->i2c_reg[11];
    I2Cx->IC_SLV_DATA_NACK_ONLY = store_buf->i2c_reg[12];
    I2Cx->IC_DMA_CR      = store_buf->i2c_reg[13];
    I2Cx->IC_DMA_TDLR    = store_buf->i2c_reg[14];
    I2Cx->IC_DMA_RDLR    = store_buf->i2c_reg[15];
    I2Cx->IC_SDA_SETUP   = store_buf->i2c_reg[16];
    I2Cx->IC_FS_SPKLEN   = store_buf->i2c_reg[17];
    I2Cx->IC_ENABLE      = store_buf->i2c_reg[10];

}


