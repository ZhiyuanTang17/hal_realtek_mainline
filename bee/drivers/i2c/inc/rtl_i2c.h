/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_i2c.h
* \brief    The header file of the peripheral I2C driver.
* \details  This file provides all I2C firmware functions.
* \author   yuzhuo_liu
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
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
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "i2c/src/rtl87x2g/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "i2c/src/rtl87x3e/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "i2c/src/rtl87x3d/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "i2c/src/rtl87x2j/rtl_i2c_def.h"
#endif

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
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && ((SPEED) <= I2C_CLOCK_MAX_SPEED))

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
    I2C_DeviveMode_Slave = 0x00,
    I2C_DeviveMode_Master = 0x01,
} I2CDeviceMode_TypeDef;

#define IS_I2C_DEVICE_MODE(MODE) (((MODE) == I2C_DeviveMode_Slave) || ((MODE) == I2C_DeviveMode_Master))

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
    I2C_AddressMode_7BIT = 0x00,
    I2C_AddressMode_10BIT = 0x01,
} I2CAddressMode_TypeDef;

#define IS_I2C_ADDRESS_MODE(ADDR) (((ADDR) == I2C_AddressMode_7BIT) || ((ADDR) == I2C_AddressMode_10BIT))

/** End of I2C_Address_Mode
  * \}
  */

/**
 * \defgroup    I2C_Acknowledgement I2C Acknowledgement
 * \{
 * \ingroup     I2C_Exported_Constants
 */
#define IS_I2C_ACKNOWLEDGEMENT(ACK) (((ACK) == ENABLE) || ((ACK) == DISABLE))

/** End of I2C_Acknowledgement
  * \}
  */

/**
 * \defgroup    I2C_Send_Stop I2C Send Stop
 * \{
 * \ingroup     I2C_Exported_Constants
 */
#define IS_I2C_STOP(CMD) (((CMD) == I2C_STOP_ENABLE) || ((CMD) == I2C_STOP_DISABLE))

/** End of I2C_Send_Stop
  * \}
  */

/**
 * \defgroup    I2C_Send_Command I2C Send Command
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_WRITE_CMD = 0x00,
    I2C_READ_CMD = 0x01,
} I2CSendCommend_TypeDef;

#define IS_I2C_CMD(CMD) (((CMD) == I2C_WRITE_CMD) || ((CMD) == I2C_READ_CMD))

/** End of I2C_Send_Command
  * \}
  */

/**
 * \defgroup    I2C_GDMA_transfer_requests I2C GDMA transfer requests
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_GDMAReq_Rx = 0x01,
    I2C_GDMAReq_Tx = 0x02,
} I2CGdmaTransferRequests_TypeDef;

#define IS_I2C_GDMAREQ(GDMAREQ) (((GDMAREQ) == I2C_GDMAReq_Rx) || ((GDMAREQ) == I2C_GDMAReq_Tx))

/** End of I2C_GDMA_transfer_requests
  * \}
  */

/**
 * \defgroup    I2C_Status I2C Status
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_Success,
    I2C_ARB_LOST,
    I2C_ABRT_MASTER_DIS,
    I2C_ABRT_TXDATA_NOACK,
    I2C_ABRT_10ADDR2_NOACK,
    I2C_ABRT_10ADDR1_NOACK,
    I2C_ABRT_7B_ADDR_NOACK,
    I2C_ERR_TIMEOUT
} I2C_Status;

/** End of I2C_Status
  * \}
  */

/**
 * \defgroup    I2C_Interrupts I2C Interrupts
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_INT_MST_ON_HOLD                     BIT13
#define I2C_INT_GEN_CALL                        BIT11
#define I2C_INT_START_DET                       BIT10
#define I2C_INT_STOP_DET                        BIT9
#define I2C_INT_ACTIVITY                        BIT8
#define I2C_INT_RX_DONE                         BIT7
#define I2C_INT_TX_ABRT                         BIT6
#define I2C_INT_RD_REQ                          BIT5
#define I2C_INT_TX_EMPTY                        BIT4
#define I2C_INT_TX_OVER                         BIT3
#define I2C_INT_RX_FULL                         BIT2
#define I2C_INT_RX_OVER                         BIT1
#define I2C_INT_RX_UNDER                        BIT0

#define I2C_GET_INT(INT)    (((INT) == I2C_INT_GEN_CALL) || ((INT) == I2C_INT_START_DET) || \
                             ((INT) == I2C_INT_STOP_DET) || ((INT) == I2C_INT_ACTIVITY) || \
                             ((INT) == I2C_INT_RX_DONE)  || ((INT) == I2C_INT_TX_ABRT) || \
                             ((INT) == I2C_INT_RD_REQ)   || ((INT) == I2C_INT_TX_EMPTY) || \
                             ((INT) == I2C_INT_TX_OVER)  || ((INT) == I2C_INT_RX_FULL) || \
                             ((INT) == I2C_INT_RX_OVER)  || ((INT) == I2C_INT_RX_UNDER) || ((INT) == I2C_INT_MST_ON_HOLD))

/** End of I2C_Interrupts
  * \}
  */

/**
 * \defgroup    I2C_Flags I2C Flags
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_FLAG_SLV_HOLD_RX_FIFO_FULL          BIT10
#define I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY         BIT9
#define I2C_FLAG_MST_HOLD_RX_FIFO_FULL          BIT8
#define I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY         BIT7
#define I2C_FLAG_SLV_ACTIVITY                   BIT6
#define I2C_FLAG_MST_ACTIVITY                   BIT5
#define I2C_FLAG_RFF                            BIT4
#define I2C_FLAG_RFNE                           BIT3
#define I2C_FLAG_TFE                            BIT2
#define I2C_FLAG_TFNF                           BIT1
#define I2C_FLAG_ACTIVITY                       BIT0

#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_SLV_HOLD_RX_FIFO_FULL) || ((FLAG) == I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_MST_HOLD_RX_FIFO_FULL) || ((FLAG) == I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_SLV_ACTIVITY) || ((FLAG) == I2C_FLAG_MST_ACTIVITY) || \
                               ((FLAG) == I2C_FLAG_RFF) || ((FLAG) == I2C_FLAG_RFNE) || \
                               ((FLAG) == I2C_FLAG_TFE) || ((FLAG) == I2C_FLAG_TFNF) || \
                               ((FLAG) == I2C_FLAG_ACTIVITY))

/** End of I2C_Flags
  * \}
  */

/**
 * \defgroup    I2C_Transmit_Abort_Source I2C Transmit Abort Source
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define ABRT_SLVRD_INTX                         BIT15
#define ABRT_SLV_ARBLOST                        BIT14
#define ABRT_SLVFLUSH_TXFIFO                    BIT13
#define ARB_LOST                                BIT12
#define ABRT_MASTER_DIS                         BIT11
#define ABRT_10B_RD_NORSTRT                     BIT10
#define ABRT_SBYTE_NORSTRT                      BIT9
#define ABRT_HS_NORSTRT                         BIT8
#define ABRT_SBYTE_ACKDET                       BIT7
#define ABRT_HS_ACKDET                          BIT6
#define ABRT_GCALL_READ                         BIT5
#define ABRT_GCALL_NOACK                        BIT4
#define ABRT_TXDATA_NOACK                       BIT3
#define ABRT_10ADDR2_NOACK                      BIT2
#define ABRT_10ADDR1_NOACK                      BIT1
#define ABRT_7B_ADDR_NOACK                      BIT0

#define MS_ALL_ABORT                            (ARB_LOST | ABRT_MASTER_DIS | ABRT_TXDATA_NOACK |\
                                                 ABRT_10ADDR2_NOACK | ABRT_10ADDR1_NOACK | ABRT_7B_ADDR_NOACK)

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
                             ((EVENT) == ABRT_7B_ADDR_NOACK))

/** End of I2C_Transmit_Abort_Source
  * \}
  */

/**
 * \defgroup    I2C_Immediate_Number I2C Immediate Number
 * \{
 * \ingroup     I2C_Exported_Constants
 */

#define I2C_0X10_CMD         BIT8
#define I2C_0X10_STOP        BIT9

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
    uint32_t I2C_Clock;                    /*!< Specifies source clock frequency, default 40000000.
                                                This parameter must be set with I2C clock div. */

    uint32_t I2C_ClockSpeed;               /*!< Specifies SCK speed.
                                                This parameter must be set to a value lower than 1MHz. */

    I2CDeviceMode_TypeDef I2C_DeviveMode;  /*!< Specifies the I2C devie mode. */

    I2CAddressMode_TypeDef I2C_AddressMode; /*!< Specifies the I2C address mode. */

    uint16_t I2C_SlaveAddress;             /*!< Specifies the first device own address.
                                                This parameter can be a 7-bit or 10-bit address. */

    FunctionalState I2C_Ack;               /*!< Enable or disable the acknowledgement
                                                only in slave mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint32_t I2C_TxThresholdLevel;         /* !< Specifies the transmit FIFO Threshold
                                                 to trigger interrupt I2C_INT_TX_EMPTY.
                                                 This parameter can be a value less than I2C_TX_FIFO_SIZE.*/

    uint32_t I2C_RxThresholdLevel;         /* !<Specifies the receive FIFO Threshold
                                                to trigger interrupt I2C_INT_RX_FULL.
                                                This parameter can be a value less than I2C_RX_FIFO_SIZE.*/

    FunctionalState I2C_TxDmaEn;           /*!< Specifies the Tx dma mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState I2C_RxDmaEn;           /*!< Specifies the Rx dma mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  I2C_TxWaterlevel;             /*!< Specifies the DMA tx water level.
                                                The best value is I2C Tx fifo depth - Tx GDMA MSize. */

    uint8_t  I2C_RxWaterlevel;             /*!< Specifies the DMA rx water level.
                                                The best value is I2C Rx GDMA MSize. */

    uint8_t  I2C_RisingTimeNs;            /*!< Specifies the I2C SDA/SCL rising time.
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
 * \brief   Deinitializes the I2Cx peripheral registers to their default reset values.
 *
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 *
 * \return  None.
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
 * \brief   Initializes the I2Cx peripheral according to the specified
 *          parameters in the I2C_InitStruct.
 *
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_InitStruct: Pointer to a I2C_InitTypeDef structure that
 *            contains the configuration information for the specified I2C peripheral.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] NewState: New state of the I2Cx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 *
 * \return I2C_Status: The status of I2Cx. \ref I2C_Status
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
 * \brief   Fills each I2C_InitStruct member with its default value.
 *
 * \param[in] I2C_InitStruct: Pointer to a I2C_InitTypeDef structure which will be initialized.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] pBuf: Byte to be transmitted.
 * \param[in] len: Data length to send.
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
 * rtl876x_i2c.h
 *
 * \brief   Read data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] pBuf: Byte to be transmitted.
 * \param[in] len: Data length to send.
 * \param[in] pBuf2: Byte to be transmitted.
 * \param[in] len2: Data length to send.
 *
 * \return I2C status, please refer to \ref I2C_Status.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] pBuf: Data buffer to receive data.
 * \param[in] len: Read data length.
 *
 * \return I2C_Status: The status of I2Cx.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] pWriteBuf: Data buffer to send before read.
 * \param[in] Writelen: Send data length.
 * \param[in] pReadBuf: Data buffer to receive.
 * \param[in] Readlen: Receive data length.
 *
 * \return I2C_Status: The status of I2Cx.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_IT: This parameter can be one of the following values:
 *            \arg I2C_INT_MST_ON_HOLD: Indicates whether a master is holding the bus.
 *            \arg I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *            \arg I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                 interface regardless of whether I2C is operating in slave or master mode.
 *            \arg I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                 of whether I2C is operating in slave or master mode
 *            \arg I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *            \arg I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                 master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                 transmission, indicating that the transmission is done.
 *            \arg I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                 intended actions on the contents of the transmit FIFO.
 *            \arg I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                 attempting to read data.
 *            \arg I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value set
 *                 in the IC_TX_TL register.
 *            \arg I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                 the processor attempts to issue another I2C command.
 *            \arg I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                 IC_RX_TL register
 *            \arg I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                 additional byte is received from an external I2C device.
 *            \arg I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 * \param[in] NewState: Disable or enable I2C interrupt.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_IT: This parameter can be one of the following values:
 *            \arg I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *            \arg I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                 interface regardless of whether I2C is operating in slave or master mode.
 *            \arg I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                 of whether I2C is operating in slave or master mode
 *            \arg I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *            \arg I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                 master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                 transmission, indicating that the transmission is done.
 *            \arg I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                 intended actions on the contents of the transmit FIFO.
 *            \arg I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                 attempting to read data.
 *            \arg I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value set
 *                 in the IC_TX_TL register.
 *            \arg I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                 the processor attempts to issue another I2C command.
 *            \arg I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                 IC_RX_TL register
 *            \arg I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                 additional byte is received from an external I2C device.
 *            \arg I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] Address: Specifies the slave address which will be transmitte.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] command: Command of write or read.
 *            \arg I2C_READ_CMD: Read command. Data which want to transmit can be 0 in this situation.
 *            \arg I2C_WRITE_CMD: Write command.
 * \param[in] data: Data which to be transmitted.
 * \param[in] StopState: Whether send stop signal.
 *            \arg ENABLE: Send stop signal.
 *            \arg DISABLE: Do not send stop signal.
 *
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 *
 * \return  None.
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
 * \brief  Check whether the specified I2C flag is set.
 *
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg I2C_FLAG_SLV_HOLD_RX_FIFO_FULL: The BUS Hold in Slave mode due to the Rx FIFO being Full and an additional byte being received.
 *            \arg I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY: The BUS Hold in Slave mode for the Read request when the Tx FIFO is empty.
 *            \arg I2C_FLAG_MST_HOLD_RX_FIFO_FULL: The BUS Hold in Master mode due to Rx FIFO is full and additional byte has been received.
 *            \arg I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY: The BUS hold when the master holds the bus because of the Tx FIFO being empty.
 *            \arg I2C_FLAG_SLV_ACTIVITY: Slave FSM activity status.
 *            \arg I2C_FLAG_MST_ACTIVITY: Master FSM activity status.
 *            \arg I2C_FLAG_RFF: Receive FIFO completely full.
 *            \arg I2C_FLAG_RFNE: Receive FIFO not empty.
 *            \arg I2C_FLAG_TFE: Transmit FIFO completely empty.
 *            \arg I2C_FLAG_TFNF: Transmit FIFO not full.
 *            \arg I2C_FLAG_ACTIVITY: I2C activity status.
 *
 * \return  The new state of I2C_FLAG (SET or RESET).
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_EVENT: specifies the event to be checked about I2C Transmit Abort Status Register.
 *            This parameter can be one of the following values:
 *            \arg ABRT_SLVRD_INTX: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
 *            \arg ABRT_SLV_ARBLOST: Slave lost the bus while transmitting data to a remote master.
 *            \arg ABRT_SLVFLUSH_TXFIFO: Slave has received a read command and some data exists in the TX FIFO so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO.
 *            \arg ARB_LOST: Master has lost arbitration or the slave transmitter has lost arbitration.
 *            \arg ABRT_MASTER_DIS: User tries to initiate a Master operation with the Master mode disabled
 *            \arg ABRT_10B_RD_NORSTRT: The restart is disabled and the master sends a read command in 10-bit addressing mode.
 *            \arg ABRT_SBYTE_NORSTRT: The restart is disabled and the user is trying to send a START Byte.
 *            \arg ABRT_HS_NORSTRT: The restart is disabled and the user is trying to use the master to transfer data in High Speed mode.
 *            \arg ABRT_SBYTE_ACKDET: Master has sent a START Byte and the START Byte was acknowledged (wrong behavior).
 *            \arg ABRT_HS_ACKDET: Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior).
 *            \arg ABRT_GCALL_READ: Sent a General Call but the user programmed the byte following the General Call to be a read from the bus.
 *            \arg ABRT_GCALL_NOACK: Sent a General Call and no slave on the bus acknowledged the General Call.
 *            \arg ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave.
 *            \arg ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 *            \arg ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 *            \arg ABRT_7B_ADDR_NOACK: Master is in 7-bit addressing mode and th address sent was not acknowledged by any slave.
 *
 * \return  An ErrorStatus enumeration value.
 * \retval  SUCCESS: Last event is equal to the I2C_EVENT.
 * \retval  ERROR: Last event is different from the I2C_EVENT.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_IT: This parameter can be one of the following values:
 *            \arg I2C_INT_MST_ON_HOLD: Indicates whether a master is holding the bus.
 *            \arg I2C_INT_GEN_CALL: Set only when a General Call address is received and it is acknowledged.
 *            \arg I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                 interface regardless of whether DW_apb_i2c is operating in slave or master mode.
 *            \arg I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                 of whether DW_apb_i2c is operating in slave or master mode
 *            \arg I2C_INT_ACTIVITY: This bit captures DW_apb_i2c activity and stays set until it is cleared.
 *            \arg I2C_INT_RX_DONE: When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the
 *                 master does not acknowledge a transmitted byte. This occurs on the last byte of
 *                 the transmission, indicating that the transmission is done.
 *            \arg I2C_INT_TX_ABRT: This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the
 *                 intended actions on the contents of the transmit FIFO.
 *            \arg I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master
 *                 is attempting to read data.
 *            \arg I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value set
 *                 in the IC_TX_TL register.
 *            \arg I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and
 *                 the processor attempts to issue another I2C command.
 *            \arg I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                 IC_RX_TL register
 *            \arg I2C_INT_RX_OVER: Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an
 *                 additional byte is received from an external I2C device.
 *            \arg I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * \return  The new state of I2C_IT (SET or RESET).
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_GDMAReq: Specifies the I2C GDMA transfer request to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg I2C_GDMAReq_Tx: Tx buffer GDMA transfer request.
 *            \arg I2C_GDMAReq_Rx: Rx buffer GDMA transfer request.
 * \param[in] NewState: New state of the selected I2C GDMA transfer request.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] I2C_ClockSpeed: Secified the I2C interrupt sources.
 * \return  None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[in] ClockDiv: Specifies the I2C clock divider.
 *            This parameter can be one of the following values:
 *            \arg I2C_CLOCK_DIVIDER_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
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
 * \param[in] I2Cx: Select the I2C peripheral. \ref I2C_Declaration
 * \param[out] ClockSrc: specifies the clock source to gates its clock.
 * \param[out] ClockDiv: Specifies the I2C clock divider.
 *            This parameter can be one of the following values:
 *            \arg I2C_CLOCK_DIVIDER_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return The status of get clock.
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


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

