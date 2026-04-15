/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_I2C_H
#define RTL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "rtl_i2c_def.h"

/** \defgroup I2C         I2C
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup I2C_Exported_Constants I2C Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    I2C_Clock_Speed I2C Clock Speed
 * \{
 * \ingroup     I2C_Exported_Constants
 */
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && ((SPEED) <= I2C_CLOCK_MAX_SPEED)) //!< Specify the maximum clock speed.

/** End of I2C_Clock_Speed
  * \}
  */

/**
 * \defgroup    I2C_Device_Mode I2C Device Mode
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_DeviveMode_Slave = 0x00,        //!< I2C slave device.
    I2C_DeviveMode_Master = 0x01,       //!< I2C master device.
} I2CDeviceMode_TypeDef;

#define IS_I2C_DEVICE_MODE(MODE) (((MODE) == I2C_DeviveMode_Slave) || ((MODE) == I2C_DeviveMode_Master)) //!< Check if the input parameter is valid.

/** End of I2C_Device_Mode
  * \}
  */

/**
 * \defgroup    I2C_Address_Mode I2C Address Mode
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_AddressMode_7BIT = 0x00,        //!< I2C 7-bit address mode.
    I2C_AddressMode_10BIT = 0x01,       //!< I2C 10-bit address mode.
} I2CAddressMode_TypeDef;

#define IS_I2C_ADDRESS_MODE(ADDR) (((ADDR) == I2C_AddressMode_7BIT) || ((ADDR) == I2C_AddressMode_10BIT)) //!< Check if the input parameter is valid.

/** End of I2C_Address_Mode
  * \}
  */

/**
 * \defgroup    I2C_Send_Command I2C Send Command
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_WRITE_CMD = 0x00,       //!< Data write command.
    I2C_READ_CMD = 0x01,        //!< Data read command.
} I2CSendCommend_TypeDef;

#define IS_I2C_CMD(CMD) (((CMD) == I2C_WRITE_CMD) || ((CMD) == I2C_READ_CMD)) //!< Check if the input parameter is valid.

/** End of I2C_Send_Command
  * \}
  */

/**
 * \defgroup    I2C_GDMA_Transfer_Requests I2C GDMA Transfer Requests
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_GDMAReq_Rx = 0x01,      //!< GDMA transfer receiving request.
    I2C_GDMAReq_Tx = 0x02,      //!< GDMA transfer sending request.
} I2CGdmaTransferRequests_TypeDef;

#define IS_I2C_GDMAREQ(GDMAREQ) (((GDMAREQ) == I2C_GDMAReq_Rx) || ((GDMAREQ) == I2C_GDMAReq_Tx)) //!< Check if the input parameter is valid.

/** End of I2C_GDMA_Transfer_Requests
  * \}
  */

/**
 * \defgroup    I2C_Status I2C Status
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_Success,                    //!< I2C transfer success.
    I2C_ARB_LOST,                   //!< Master has lost arbitration or the slave transmitter has lost arbitration.
    I2C_ABRT_MASTER_DIS,            //!< User tries to initiate a Master operation with the Master mode disabled.
    I2C_ABRT_TXDATA_NOACK,          //!< Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave. Only for Master.
    I2C_ABRT_10ADDR2_NOACK,         //!< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
    I2C_ABRT_10ADDR1_NOACK,         //!< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
    I2C_ABRT_7B_ADDR_NOACK,         //!< Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave.
    I2C_ERR_TIMEOUT                 //!< I2C transfer time out error.
} I2C_Status;

/** End of I2C_Status
  * \}
  */

/**
 * \defgroup    I2C_Interrupts I2C Interrupts
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_INT_MST_ON_HOLD                     BIT13           //!< When Master TX FIFO is empty and no stop bit command is issued, master will hold the SCL low.
#define I2C_INT_GEN_CALL                        BIT11           //!< Set only when a General Call address is received and it is acknowledged.
#define I2C_INT_START_DET                       BIT10           //!< Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether I2C is operating in slave or master mode.
#define I2C_INT_STOP_DET                        BIT9            //!< Indicates whether a STOP condition has occurred on the I2C interface regardless of whether I2C is operating in slave or master mode.
#define I2C_INT_ACTIVITY                        BIT8            //!< This bit captures I2C activity and stays set until it is cleared.          
#define I2C_INT_RX_DONE                         BIT7            //!< When the I2C is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.
#define I2C_INT_TX_ABRT                         BIT6            //!< This bit indicates if I2C as an I2C transmitter, is unable to complete the intended actions on the contents of the transmit FIFO.
#define I2C_INT_RD_REQ                          BIT5            //!< This bit is set to 1 when acting as a slave and another I2C master is attempting to read data.
#define I2C_INT_TX_EMPTY                        BIT4            //!< This bit is set to 1 when the transmit buffer is at or below the threshold value set in the IC_TX_TL register.
#define I2C_INT_TX_OVER                         BIT3            //!< Set during transmit if the transmit buffer is filled to TX FIFO depth and the processor attempts to issue another I2C command.
#define I2C_INT_RX_FULL                         BIT2            //!< Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register.
#define I2C_INT_RX_OVER                         BIT1            //!< Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an additional byte is received from an external I2C device.
#define I2C_INT_RX_UNDER                        BIT0            //!< Set if the processor attempts to read the receive buffer when it is empty by reading.

#define I2C_GET_INT(INT)    (((INT) == I2C_INT_GEN_CALL) || ((INT) == I2C_INT_START_DET) || \
                             ((INT) == I2C_INT_STOP_DET) || ((INT) == I2C_INT_ACTIVITY) || \
                             ((INT) == I2C_INT_RX_DONE)  || ((INT) == I2C_INT_TX_ABRT) || \
                             ((INT) == I2C_INT_RD_REQ)   || ((INT) == I2C_INT_TX_EMPTY) || \
                             ((INT) == I2C_INT_TX_OVER)  || ((INT) == I2C_INT_RX_FULL) || \
                             ((INT) == I2C_INT_RX_OVER)  || ((INT) == I2C_INT_RX_UNDER) || ((INT) == I2C_INT_MST_ON_HOLD)) //!< Check if the input parameter is valid.

/** End of I2C_Interrupts
  * \}
  */

/**
 * \defgroup    I2C_Flags I2C Flags
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_FLAG_SLV_HOLD_RX_FIFO_FULL          BIT10           //!< The BUS hold in Slave mode due to the RX FIFO being full and an additional byte being received.
#define I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY         BIT9            //!< The BUS hold in Slave mode for the read request when the TX FIFO is empty.
#define I2C_FLAG_MST_HOLD_RX_FIFO_FULL          BIT8            //!< The BUS hold in Master mode due to Rx FIFO is full and additional byte has been received.
#define I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY         BIT7            //!< The BUS hold when the master holds the bus because of the TX FIFO being empty.
#define I2C_FLAG_SLV_ACTIVITY                   BIT6            //!< Slave FSM activity status.
#define I2C_FLAG_MST_ACTIVITY                   BIT5            //!< Master FSM activity status.
#define I2C_FLAG_RFF                            BIT4            //!< Receive FIFO completely full.
#define I2C_FLAG_RFNE                           BIT3            //!< Receive FIFO not empty.
#define I2C_FLAG_TFE                            BIT2            //!< Transmit FIFO completely empty.
#define I2C_FLAG_TFNF                           BIT1            //!< Transmit FIFO not full.
#define I2C_FLAG_ACTIVITY                       BIT0            //!< I2C activity status.

#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_SLV_HOLD_RX_FIFO_FULL) || ((FLAG) == I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_MST_HOLD_RX_FIFO_FULL) || ((FLAG) == I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_SLV_ACTIVITY) || ((FLAG) == I2C_FLAG_MST_ACTIVITY) || \
                               ((FLAG) == I2C_FLAG_RFF) || ((FLAG) == I2C_FLAG_RFNE) || \
                               ((FLAG) == I2C_FLAG_TFE) || ((FLAG) == I2C_FLAG_TFNF) || \
                               ((FLAG) == I2C_FLAG_ACTIVITY)) //!< Check if the input parameter is valid.

/** End of I2C_Flags
  * \}
  */

/**
 * \defgroup    I2C_Transmit_Abort_Source I2C Transmit Abort Source
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define ABRT_SLVRD_INTX                         BIT15           //!< When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
#define ABRT_SLV_ARBLOST                        BIT14           //!< Slave lost the bus while transmitting data to a remote master.
#define ABRT_SLVFLUSH_TXFIFO                    BIT13           //!< Slave has received a read command and some data exists in the TX FIFO so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO.
#define ARB_LOST                                BIT12           //!< Master has lost arbitration or the slave transmitter has lost arbitration.
#define ABRT_MASTER_DIS                         BIT11           //!< User tries to initiate a Master operation with the Master mode disabled
#define ABRT_10B_RD_NORSTRT                     BIT10           //!< The restart is disabled and the master sends a read command in 10-bit addressing mode.
#define ABRT_SBYTE_NORSTRT                      BIT9            //!< The restart is disabled and the user is trying to send a START byte.
#define ABRT_HS_NORSTRT                         BIT8            //!< The restart is disabled and the user is trying to use the master to transfer data in high speed mode.
#define ABRT_SBYTE_ACKDET                       BIT7            //!< Master has sent a START Byte and the START Byte was acknowledged (wrong behavior).
#define ABRT_HS_ACKDET                          BIT6            //!< Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior).
#define ABRT_GCALL_READ                         BIT5            //!< Sent a General Call but the user programmed the byte following the General Call to be a read from the bus.
#define ABRT_GCALL_NOACK                        BIT4            //!< Sent a General Call and no slave on the bus acknowledged the General Call.
#define ABRT_TXDATA_NOACK                       BIT3            //!< Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave.
#define ABRT_10ADDR2_NOACK                      BIT2            //!< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
#define ABRT_10ADDR1_NOACK                      BIT1            //!< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
#define ABRT_7B_ADDR_NOACK                      BIT0            //!< Master is in 7-bit addressing mode and th address sent was not acknowledged by any slave.

#define MS_ALL_ABORT                            (ARB_LOST | ABRT_MASTER_DIS | ABRT_TXDATA_NOACK |\
                                                 ABRT_10ADDR2_NOACK | ABRT_10ADDR1_NOACK | ABRT_7B_ADDR_NOACK) //!< All types of ABORT.

#define IS_I2C_EVENT(EVENT) (((EVENT) == ABRT_SLVRD_INTX) || \
                             ((EVENT) == ABRT_SLV_ARBLOST) || \
                             ((EVENT) == ABRT_SLVFLUSH_TXFIFO) || \
                             ((EVENT) == ARB_LOST) || \
                             ((EVENT) == ABRT_MASTER_DIS) || \
                             ((EVENT) == ABRT_10B_RD_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_NORSTRT) || \
                             ((EVENT) == ABRT_HS_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_ACKDET) || \
                             ((EVENT) == ABRT_HS_ACKDET) || \
                             ((EVENT) == ABRT_GCALL_READ) || \
                             ((EVENT) == ABRT_GCALL_NOACK) || \
                             ((EVENT) == ABRT_TXDATA_NOACK) || \
                             ((EVENT) == ABRT_10ADDR2_NOACK) || \
                             ((EVENT) == ABRT_10ADDR1_NOACK) || \
                             ((EVENT) == ABRT_7B_ADDR_NOACK)) //!< Check if the input parameter is valid.

/** End of I2C_Transmit_Abort_Source
  * \}
  */

/**
 * \defgroup    I2C_Immediate_Number I2C Immediate Number
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_0X10_CMD         BIT8           //!< If the data is ORed with this immediate value, it indicates a master device read command.
#define I2C_0X10_STOP        BIT9           //!< If the data is ORed with this immediate value, it indicates sending a stop bit.

/** End of I2C_Immediate_Number
  * \}
  */

#if (I2C_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    I2C_Wrapper_Trans_Mode I2C Wrapper Trans Mode
 * \{
 * \ingroup     I2C_Exported_Constants
 */

typedef enum
{
    I2C_WRAPPER_TRANS_MODE_WRITE       = 0,
    I2C_WRAPPER_TRANS_MODE_READ        = 1,
    I2C_WRAPPER_TRANS_MODE_REPEAT_READ = 2,
    I2C_WRAPPER_TRANS_MODE_DMA         = 3,
} I2CWrapperTransMode_TypeDef;

/** End of I2C_Wrapper_Trans_Mode
  * \}
  */

/**
 * \defgroup    I2C_Task I2C Task Number
 * \{
 * \ingroup     I2C_Exported_Constants
 */

typedef enum
{
    I2C_TASK_START = 0,
} I2CTask_TypeDef;

/** End of I2C_Task
  * \}
  */

#endif

/** End of I2C_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup I2C_Exported_Types I2C Exported Types
  * \brief
  * \{
  */

/**
 * \brief       I2C Init structure definition.
 *
 * \ingroup     I2C_Exported_Types
 */

typedef struct
{
    uint32_t I2C_Clock;                    /*!< Specify source clock frequency, default 40000000.
                                                This parameter must be set with I2C clock div. */

    uint32_t I2C_ClockSpeed;               /*!< Specify SCK speed on the I2C bus.
                                                This parameter must be set to a value lower than 1MHz. */

    I2CDeviceMode_TypeDef I2C_DeviveMode;  /*!< Specify the I2C devie mode.
                                                This parameter can be a value of \ref I2C_Device_Mode. */

    I2CAddressMode_TypeDef I2C_AddressMode;/*!< Specify the I2C address mode.
                                                This parameter can be a value of \ref I2C_Address_Mode. */

    uint16_t I2C_SlaveAddress;             /*!< Specify the first device own address.
                                                This parameter can be a 7-bit or 10-bit address. */

    FunctionalState
    I2C_Ack;               /*!< Enable or disable the acknowledgement only in slave mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint32_t I2C_TxThresholdLevel;         /*!< Specify the transmit FIFO Threshold to trigger interrupt I2C_INT_TX_EMPTY.
                                                This parameter can be a value less than I2C_TX_FIFO_SIZE.*/

    uint32_t I2C_RxThresholdLevel;         /*!< Specify the receive FIFO Threshold to trigger interrupt I2C_INT_RX_FULL.
                                                This parameter can be a value less than I2C_RX_FIFO_SIZE.*/

    FunctionalState I2C_TxDmaEn;           /*!< Specify the Tx dma mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState I2C_RxDmaEn;           /*!< Specify the Rx dma mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  I2C_TxWaterlevel;             /*!< Specify the DMA tx water level.
                                                The best value is I2C Tx fifo depth - Tx GDMA MSize. */

    uint8_t  I2C_RxWaterlevel;             /*!< Specify the DMA rx water level.
                                                The best value is I2C Rx GDMA MSize. */

    uint8_t  I2C_RisingTimeNs;             /*!< Specify the I2C SDA/SCL rising time.
                                                The unit is ns and must be an integer multiple of clock src period. */

} I2C_InitTypeDef;

/** End of GPIO_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup I2C_Exported_Functions I2C Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitialize the I2Cx peripheral registers to their default reset values.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     I2C_DeInit(I2C0);
 * }
 * \endcode
 */
void I2C_DeInit(I2C_TypeDef *I2Cx);

/**
 * \brief   Initialize the I2Cx peripheral according to the specified parameters in the I2C_InitStruct.
 *
 * \param[in] I2Cx            Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_InitStruct  Pointer to a I2C_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviveMode    = I2C_DeviveMode_Master;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_AddressMode_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = STK8321_ADDRESS;
 *     I2C_InitStruct.I2C_Ack           = I2C_Ack_Enable;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * \endcode
 */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct);

/**
 * \brief  Enable or disable the specified I2C peripheral.
 *
 * \param[in] I2Cx      Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] NewState  New state of the I2Cx peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified I2C peripheral.
 *                      - DISABLE: Disable the specified I2C peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviveMode    = I2C_DeviveMode_Master;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_AddressMode_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = STK8321_ADDRESS;
 *     I2C_InitStruct.I2C_Ack           = I2C_Ack_Enable;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * \endcode
 */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

/**
 * \brief  Enable or disable the specified I2C peripheral.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * \return The status of I2Cx. Refer to \ref I2C_Status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_CheckAbortStatus(I2C0);
 * }
 * \endcode
 */
I2C_Status I2C_CheckAbortStatus(I2C_TypeDef *I2Cx);

/**
 * \brief   Fill each I2C_InitStruct member with its default value.
 *
 * \note   The default settings for the I2C_InitStruct member are shown in the following table:
 *         | I2C_InitStruct member | Default value                    |
 *         |:---------------------:|:--------------------------------:|
 *         | I2C_Clock             | 40000000                         |
 *         | I2C_ClockSpeed        | 400000                           |
 *         | I2C_DeviveMode        | \ref I2C_DeviveMode_Master       |
 *         | I2C_AddressMode       | \ref I2C_AddressMode_7BIT        |
 *         | I2C_SlaveAddress      | 0                                |
 *         | I2C_Ack               | ENABLE                           |
 *         | I2C_TxThresholdLevel  | 0                                |
 *         | I2C_RxThresholdLevel  | 0                                |
 *         | I2C_TxDmaEn           | DISABLE                          |
 *         | I2C_RxDmaEn           | DISABLE                          |
 *         | I2C_TxWaterlevel      | 23                               |
 *         | I2C_RxWaterlevel      | 1                                |
 *         | I2C_RisingTimeNs      | 50                               |
 *
 * \param[in] I2C_InitStruct  Pointer to a I2C_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviveMode    = I2C_DeviveMode_Master;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_AddressMode_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = STK8321_ADDRESS;
 *     I2C_InitStruct.I2C_Ack           = I2C_Ack_Enable;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * \endcode
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);

/**
 * \brief   Send data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] pBuf  Byte to be transmitted.
 * \param[in] len   Data length to send.
 *
 * \return I2C_Status: The status of I2Cx.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01,x0x02,0x03,0x04};
 *     I2C_MasterWrite(I2C0, data, 4);
 * }
 * \endcode
 */
I2C_Status I2C_MasterWrite(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 * \brief   Read data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx   Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] pBuf   Byte to be transmitted.
 * \param[in] len    Data length to send.
 * \param[in] pBuf2  Byte to be transmitted.
 * \param[in] len2   Data length to send.
 *
 * \return I2C status: The status of I2Cx, refer to \ref I2C_Status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01,x0x02,0x03,0x04};
 *     uint8_t data1[10] = {0x01,x0x02,0x03,0x04};
 *     I2C_MasterWriteDevice(I2C0, data, 4, data, 4);
 * }
 * \endcode
 */
I2C_Status I2C_MasterWriteDevice(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len, uint8_t *pbuf2,
                                 uint32_t len2);

/**
 * \brief   Read data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx   Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[out] pBuf  Data buffer to receive data.
 * \param[in] len    Read data length.
 *
 * \return I2C_Status: The status of I2Cx, refer to \ref I2C_Status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0};
 *     I2C_MasterRead(I2C0, data, 10);
 * }
 * \endcode
 */
I2C_Status I2C_MasterRead(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 * \brief   Sends data and read data in master mode through the I2Cx peripheral.
 *          Attention:Read data with time out mechanism.
 *
 * \param[in] I2Cx       Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] pWriteBuf  Data buffer to send before read.
 * \param[in] Writelen   Send data length.
 * \param[out] pReadBuf  Data buffer to receive.
 * \param[in] Readlen    Receive data length.
 *
 * \return I2C_Status: The status of I2Cx, refer to \ref I2C_Status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t tx_data[10] = {0x01,x0x02,0x03,0x04};
 *     uint8_t rx_data[10] = {0};
 *     I2C_RepeatRead(I2C0, tx_data, 4, rx_data, 10);
 * }
 * \endcode
 */
I2C_Status I2C_RepeatRead(I2C_TypeDef *I2Cx, uint8_t *pWriteBuf, uint16_t Writelen,
                          uint8_t *pReadBuf, uint16_t Readlen);

/**
 * \brief Mask the specified I2C interrupt.
 *
 * \param[in] I2Cx      Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_IT    This parameter can be one of the following values, refer to \ref I2C_Interrupts.
 *                      \arg I2C_INT_MST_ON_HOLD: Indicates whether a master is holding the bus.
 *                      \arg I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *                      \arg I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                           interface regardless of whether I2C is operating in slave or master mode.
 *                      \arg I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface
 *                           regardless of whether I2C is operating in slave or master mode
 *                      \arg I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *                      \arg I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                           master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                           transmission, indicating that the transmission is done.
 *                      \arg I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                           intended actions on the contents of the transmit FIFO.
 *                      \arg I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                           attempting to read data.
 *                      \arg I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold
 *                            value set in the IC_TX_TL register.
 *                      \arg I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                           the processor attempts to issue another I2C command.
 *                      \arg I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                           IC_RX_TL register
 *                      \arg I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                           additional byte is received from an external I2C device.
 *                      \arg I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 * \param[in] NewState  Mask the specified I2C interrupt or not.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Mask the specified I2C interrupt.
 *                      - DISABLE: Unmask the specified I2C interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     I2C_INTConfig(I2C0, I2C_INT_STOP_DET, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = I2C0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * \endcode
 */
void I2C_INTConfig(I2C_TypeDef *I2Cx, uint16_t I2C_IT, FunctionalState NewState);

/**
 * \brief   Clear the specified I2C interrupt pending bit.
 *
 * \param[in] I2Cx    Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_IT  This parameter can be one of the following values, refer to \ref I2C_Interrupts.
 *                    - I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *                    - I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                      interface regardless of whether I2C is operating in slave or master mode.
 *                    - I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                      of whether I2C is operating in slave or master mode
 *                    - I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *                    - I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                      master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                      transmission, indicating that the transmission is done.
 *                    - I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                      intended actions on the contents of the transmit FIFO.
 *                    - I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                      attempting to read data.
 *                    - I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value set
 *                      in the IC_TX_TL register.
 *                    - I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                      the processor attempts to issue another I2C command.
 *                    - I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                      IC_RX_TL register
 *                    - I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                      additional byte is received from an external I2C device.
 *                    - I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void I2C0_Handler(void)
 * {
 *     if (I2C_GetINTStatus(I2C0, I2C_INT_STOP_DET) == SET)
 *     {
 *         //Add user code here.
 *         I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     }
 * }
 * \endcode
 */
void I2C_ClearINTPendingBit(I2C_TypeDef *I2Cx, uint16_t I2C_IT);

/**
 * \brief   Set slave device address.
 *
 * \param[in] I2Cx     Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] Address  Specify the slave address which will be transmitte.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_SetSlaveAddress(I2C0, 0x55);
 * }
 * \endcode
 */
void I2C_SetSlaveAddress(I2C_TypeDef *I2Cx, uint16_t Address);

/**
 * \brief   Write command through the I2Cx peripheral.
 *
 * \param[in] I2Cx       Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] command    Command of write or read.
 *                       \arg I2C_READ_CMD: Read command. Data which want to transmit can be 0 in this situation.
 *                       \arg I2C_WRITE_CMD: Write command.
 * \param[in] data       Data which to be transmitted.
 * \param[in] StopState  Whether to send a stop signal.
 *                       - ENABLE: Send stop signal.
 *                       - DISABLE: Do not send stop signal.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_SendCmd(I2C0, 0x01, 0xAA, ENABLE);
 * }
 * \endcode
 */
void I2C_SendCmd(I2C_TypeDef *I2Cx, I2CSendCommend_TypeDef command, uint8_t data,
                 FunctionalState StopState);

/**
 * \brief  Received data by the I2Cx peripheral.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * \return Return the most recent received data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data = I2C_ReceiveData(I2C0);
 * }
 * \endcode
 */
uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx);

/**
 * \brief   Get data length in Rx FIFO of the I2Cx peripheral.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * \return  Current data number in Rx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_GetRxFIFOLen(I2C0);
 * }
 * \endcode
 */
uint8_t I2C_GetRxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * \brief   Get data length in Tx FIFO of the I2Cx peripheral.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * \return  Current data number in Tx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_GetTxFIFOLen(I2C0);
 * }
 * \endcode
 */
uint8_t I2C_GetTxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * \brief   Clear all I2C interrupt.
 *
 * \param[in] I2Cx  Select the I2C peripheral. Refer to \ref I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_ClearAllINT(I2C0);
 * }
 * \endcode
 */
void I2C_ClearAllINT(I2C_TypeDef *I2Cx);

/**
 * \brief  Get the specified I2C flag status.
 *
 * \param[in] I2Cx      Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_FLAG  Specify the flag to check.
 *                      This parameter can be one of the following values, refer to \ref I2C_Flags.
 *                      - I2C_FLAG_SLV_HOLD_RX_FIFO_FULL: The BUS hold in Slave mode due to the RX FIFO being Full and an additional byte being received.
 *                      - I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY: The BUS hold in Slave mode for the read request when the TX FIFO is empty.
 *                      - I2C_FLAG_MST_HOLD_RX_FIFO_FULL: The BUS hold in Master mode due to TX FIFO is full and additional byte has been received.
 *                      - I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY: The BUS hold when the master holds the bus because of the TX FIFO being empty.
 *                      - I2C_FLAG_SLV_ACTIVITY: Slave FSM activity status.
 *                      - I2C_FLAG_MST_ACTIVITY: Master FSM activity status.
 *                      - I2C_FLAG_RFF: Receive FIFO completely full.
 *                      - I2C_FLAG_RFNE: Receive FIFO not empty.
 *                      - I2C_FLAG_TFE: Transmit FIFO completely empty.
 *                      - I2C_FLAG_TFNF: Transmit FIFO not full.
 *                      - I2C_FLAG_ACTIVITY: I2C activity status.
 *
 * \return  The status of I2C flag.
 *          - SET: The I2C flag has been set.
 *          - RESET: The I2C flag has been reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     FlagStatus flag_status = I2C_GetFlagState(I2C0, I2C_FLAG_RFF);
 * }
 * \endcode
 */
FlagStatus I2C_GetFlagState(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG);

/**
 * \brief  Check whether the last I2Cx event is equal to the one passed as parameter.
 *
 * \param[in] I2Cx       Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_EVENT  Specify the event to be checked about I2C Transmit Abort Status Register.
 *                       This parameter can be one of the following values, refer to \ref I2C_Transmit_Abort_Source.
 *                       - ABRT_SLVRD_INTX: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
 *                       - ABRT_SLV_ARBLOST: Slave lost the bus while transmitting data to a remote master.
 *                       - ABRT_SLVFLUSH_TXFIFO: Slave has received a read command and some data exists in the TX FIFO so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO.
 *                       - ARB_LOST: Master has lost arbitration or the slave transmitter has lost arbitration.
 *                       - ABRT_MASTER_DIS: User tries to initiate a Master operation with the Master mode disabled
 *                       - ABRT_10B_RD_NORSTRT: The restart is disabled and the master sends a read command in 10-bit addressing mode.
 *                       - ABRT_SBYTE_NORSTRT: The restart is disabled and the user is trying to send a START Byte.
 *                       - ABRT_HS_NORSTRT: The restart is disabled and the user is trying to use the master to transfer data in High Speed mode.
 *                       - ABRT_SBYTE_ACKDET: Master has sent a START Byte and the START Byte was acknowledged (wrong behavior).
 *                       - ABRT_HS_ACKDET: Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior).
 *                       - ABRT_GCALL_READ: Sent a General Call but the user programmed the byte following the General Call to be a read from the bus.
 *                       - ABRT_GCALL_NOACK: Sent a General Call and no slave on the bus acknowledged the General Call.
 *                       - ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave.
 *                       - ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 *                       - ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 *                       - ABRT_7B_ADDR_NOACK: Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave.
 *
 * \return  An ErrorStatus enumeration value.
 *          - SUCCESS: Last event is equal to the I2C_EVENT.
 *          - ERROR: Last event is different from the I2C_EVENT.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     FlagStatus flag_status = I2C_CheckEvent(I2C0, ABRT_SLVRD_INTX);
 * }
 * \endcode
 */
FlagStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT);

/**
 * \brief   Get the specified I2C interrupt status.
 *
 * \param[in] I2Cx    Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_IT  This parameter can be one of the following values, refer to \ref I2C_Interrupts.
 *                    \arg I2C_INT_MST_ON_HOLD: Indicates whether a master is holding the bus.
 *                    \arg I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *                    \arg I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                         interface regardless of whether DW_apb_i2c is operating in slave or master mode.
 *                    \arg I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                         of whether DW_apb_i2c is operating in slave or master mode
 *                    \arg I2C_INT_ACTIVITY: This bit captures DW_apb_i2c activity and stays set until it is cleared.
 *                    \arg I2C_INT_RX_DONE: When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the
 *                         master does not acknowledge a transmitted byte. This occurs on the last byte of
 *                         the transmission, indicating that the transmission is done.
 *                    \arg I2C_INT_TX_ABRT: This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the
 *                         intended actions on the contents of the transmit FIFO.
 *                    \arg I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master
 *                         is attempting to read data.
 *                    \arg I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value set
 *                         in the IC_TX_TL register.
 *                    \arg I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                         the processor attempts to issue another I2C command.
 *                    \arg I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                         IC_RX_TL register
 *                    \arg I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                         additional byte is received from an external I2C device.
 *                    \arg I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * \return  The status of I2C interrupt.
 *          - SET: The I2C interrupt has been set.
 *          - RESET: The I2C interrupt has been reset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     ITStatus int_status = I2C_GetINTStatus(I2C0, I2C_INT_RD_REQ);
 * }
 * \endcode
 */
ITStatus I2C_GetINTStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT);

/**
 * \brief   Enable or disable the I2Cx GDMA interface.
 *
 * \param[in] I2Cx         Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_GDMAReq  Specify the I2C GDMA transfer request to be enabled or disabled.
 *                         This parameter can be one of the following values:
 *                         \arg I2C_GDMAReq_Tx: Tx buffer GDMA transfer request.
 *                         \arg I2C_GDMAReq_Rx: Rx buffer GDMA transfer request.
 * \param[in] NewState     New state of the selected I2C GDMA transfer request.
 *                         This parameter can be one of the following values:
 *                         \arg ENABLE: Enable the I2Cx GDMA interface.
 *                         \arg DISABLE: Disable the I2Cx GDMA interface.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_GDMACmd(I2C0, I2C_GDMAReq_Tx, ENABLE);
 * }
 * \endcode
 */
void I2C_GDMACmd(I2C_TypeDef *I2Cx, I2CGdmaTransferRequests_TypeDef I2C_GDMAReq,
                 FunctionalState NewState);

/**
 * \brief   Set the I2C clock speed, the function need to be called when I2C disabled.
 *
 * \param[in] I2Cx            Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] I2C_ClockSpeed  Specify the I2C clock speed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_demo(void)
 * {
 *     I2C_SetClockSpeed(I2C0, 400000);
 * }
 * \endcode
 */
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed);

/**
 * \brief  I2C clock divider config.
 *
 * \param[in] I2Cx      Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[in] ClockDiv  Specify the I2C clock divider.
 *                      This parameter can refer to \ref I2C_Clock_Divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     I2C_ClkDivConfig(I2C0, I2C_CLOCK_DIVIDER_1);
 * }
 * \endcode
 */
void I2C_ClkDivConfig(I2C_TypeDef *I2Cx, I2CClockDiv_TypeDef ClockDiv);

/**
 * \brief  Get I2C clock divider.
 *
 * \param[in] I2Cx       Select the I2C peripheral. Refer to \ref I2C_Declaration.
 * \param[out] ClockSrc  Specify the clock source to gates its clock.
 * \param[out] ClockDiv  Specify the I2C clock divider.
 *                       This parameter can refer to \ref I2C_Clock_Divider.
 *
 * \return The status of get clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     I2C_ClkGet(I2C0, I2C_CLOCK_SRC,I2C_CLOCK_DIVIDER_1);
 * }
 * \endcode
 */
bool I2C_ClkGet(I2C_TypeDef *I2Cx, I2CClockSrc_TypeDef *ClockSrc, I2CClockDiv_TypeDef *ClockDiv);


#if (I2C_SUPPORT_RAP_FUNCTION == 1)
void I2C_WrapperModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

bool I2C_WrapperTransModeSet(I2C_TypeDef *I2Cx, uint32_t mode);

void I2C_WrapperWriteDataSet(I2C_TypeDef *I2Cx, uint8_t num, const uint8_t *buf);

uint8_t I2C_WrapperGetTxFIFOLen(I2C_TypeDef *I2Cx);

void I2C_WrapperTxFIFOClear(I2C_TypeDef *I2Cx);

void I2C_WrapperReadNumSet(I2C_TypeDef *I2Cx, uint16_t num);

uint8_t I2C_WrapperReceiveData(I2C_TypeDef *I2Cx);

uint8_t I2C_WrapperGetRxFIFOLen(I2C_TypeDef *I2Cx);

void I2C_WrapperTransStart(I2C_TypeDef *I2Cx);

bool I2C_WrapperBusyCheck(I2C_TypeDef *I2Cx);

void I2C_RAPModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

void I2C_TaskTrigger(I2C_TypeDef *I2Cx, uint32_t Task);

#endif


/** End of I2C_Exported_Functions
  * \}
  */

/** End of I2C
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /*RTL_I2C_H*/


