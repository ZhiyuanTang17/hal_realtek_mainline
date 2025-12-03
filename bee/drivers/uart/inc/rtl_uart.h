/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_uart.h
* \brief    The header file of the peripheral UART driver.
* \details  This file provides all UART firmware functions.
* \author   Bert
* \date     2024-05-08
* \version  v0.1
* *******************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_UART_H
#define RTL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "uart/src/rtl87x2g/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "uart/src/rtl87x3e/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "uart/src/rtl87x3d/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "uart/src/rtl87x2j/rtl_uart_def.h"
#endif

/** \defgroup UART        UART
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup UART_Exported_Constants UART Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    UART_FIFO_Size UART FIFO Size
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define UART_TX_FIFO_SIZE           16
#define UART_RX_FIFO_SIZE           32

/** End of UART_FIFO_Size
  * \}
  */

/**
 * \defgroup    UART_Baudrate UART Baudrate
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_BAUD_RATE_1200,
    UART_BAUD_RATE_4800,
    UART_BAUD_RATE_7200,
    UART_BAUD_RATE_9600,
    UART_BAUD_RATE_14400,
    UART_BAUD_RATE_19200,
    UART_BAUD_RATE_28800,
    UART_BAUD_RATE_38400,
    UART_BAUD_RATE_57600,
    UART_BAUD_RATE_76800,
    UART_BAUD_RATE_115200,
    UART_BAUD_RATE_128000,
    UART_BAUD_RATE_153600,
    UART_BAUD_RATE_230400,
    UART_BAUD_RATE_460800,
    UART_BAUD_RATE_500000,
    UART_BAUD_RATE_921600,
    UART_BAUD_RATE_1000000,
    UART_BAUD_RATE_1382400,
    UART_BAUD_RATE_1444400,
    UART_BAUD_RATE_1500000,
    UART_BAUD_RATE_1843200,
    UART_BAUD_RATE_2000000,
    UART_BAUD_RATE_3000000,
    UART_BAUD_RATE_4000000,
} UARTBaudrate_TypeDef;

/** End of UART_Baudrate
  * \}
  */

/**
 * \defgroup    UART_Parity UART Parity
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_PARITY_NO_PARTY = 0x0,
    UART_PARITY_ODD = 0x1,
    UART_PARITY_EVEN = 0x3,
} UARTParity_TypeDef;

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NO_PARTY) || \
                                ((PARITY) == UART_PARITY_ODD) || \
                                ((PARITY) == UART_PARITY_EVEN))

/** End of UART_Parity
  * \}
  */

/**
 * \defgroup    UART_Stop_Bits UART Stop Bits
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_STOP_BITS_1 = 0x0,
    UART_STOP_BITS_2 = 0x1,
} UARTStopBits_TypeDef;

#define IS_UART_STOPBITS(STOP) (((STOP) == UART_STOP_BITS_1) || \
                                ((STOP) == UART_STOP_BITS_2))

/** End of UART_Stop_Bits
  * \}
  */

/**
 * \defgroup    UART_Word_Length UART Word Length
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_WORD_LENGTH_7BIT = 0x0,
    UART_WORD_LENGTH_8BIT = 0x1,
} UARTWordLen_TypeDef;

#define IS_UART_WORD_LENGTH(LEN) ((((LEN)) == UART_WORD_LENGTH_7BIT) || \
                                  (((LEN)) == UART_WORD_LENGTH_8BIT))

/** End of UART_Word_Length
  * \}
  */

/**
 * \defgroup    UART_Hardware_Flow_Control UART Hardware Flow Control
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_HW_FLOW_CTRL_DISABLE = 0x0,
    UART_HW_FLOW_CTRL_ENABLE = 0x1,
} UARTHwFlowCtrl_TypeDef;

#define IS_UART_AUTO_FLOW_CTRL(CTRL) (((CTRL) == UART_HW_FLOW_CTRL_ENABLE) || \
                                      ((CTRL) == UART_HW_FLOW_CTRL_DISABLE))

/** End of UART_Hardware_Flow_Control
  * \}
  */

/**
 * \defgroup    UART_DMA UART DMA
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_DMA_DISABLE = 0x0,
    UART_DMA_ENABLE  = 0x1,
} UARTDma_TypeDef;

#define IS_UART_DMA_CFG(CFG) (((CFG) == UART_DMA_ENABLE) || \
                              ((CFG) == UART_DMA_DISABLE))

/** End of UART_DMA
  * \}
  */

/**
 * \defgroup    UART_Rx_Idle_Time UART Rx Idle Time
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_RX_IDLE_1BYTE = 0x0,
    UART_RX_IDLE_2BYTE = 0x1,
    UART_RX_IDLE_4BYTE = 0x2,
    UART_RX_IDLE_8BYTE = 0x3,
    UART_RX_IDLE_16BYTE = 0x4,
    UART_RX_IDLE_32BYTE = 0x5,
    UART_RX_IDLE_64BYTE = 0x6,
    UART_RX_IDLE_128BYTE = 0x7,
    UART_RX_IDLE_256BYTE = 0x8,
    UART_RX_IDLE_512BYTE = 0x9,
    UART_RX_IDLE_1024BYTE = 0xA,
    UART_RX_IDLE_2048BYTE = 0xB,
    UART_RX_IDLE_4096BYTE = 0xC,
    UART_RX_IDLE_8192BYTE = 0xD,
    UART_RX_IDLE_16384BYTE = 0xE,
    UART_RX_IDLE_32768BYTE = 0xF,
} UARTTimeout_TypeDef;

#define IS_UART_IDLE_TIME(TIME) ((TIME) <= 0x0F)

/** End of UART_Rx_Idle_Time
  * \}
  */

/**
 * \defgroup    UART_Rx_FIFO_Trigger_Level UART Rx FIFO Trigger Level
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_RX_FIFO_TRIGGER_LEVEL_1BYTE = 0x1,
    UART_RX_FIFO_TRIGGER_LEVEL_4BYTE = 0x4,
    UART_RX_FIFO_TRIGGER_LEVEL_8BYTE = 0x8,
    UART_RX_FIFO_TRIGGER_LEVEL_14BYTE = 0xE,
} UARTRxFifoTriggerLevel_TypeDef;

#define IS_UART_RX_FIFO_TRIGGER_LEVEL(BYTES) ((BYTES) <= 29)

/** End of UART_Rx_FIFO_Trigger_Level
  * \}
  */

#if (UART_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    UART_Qactive_Force UART Qactive Force
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_QACTIVE_SCLK_FORCE = 0x0,
    UART_QACTIVE_PCLK_FORCE = 0x1,
    UART_QACTIVE_PCLK_ICG   = 0x2,
} UARTQactiveForce_TypeDef;

/** End of UART_Qactive_Force
  * \}
  */

#endif

/**
 * \defgroup    UART_Interrupts UART Interrupts
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define UART_INT_RD_AVA                 BIT0
#define UART_INT_TX_FIFO_EMPTY          BIT1
#define UART_INT_RX_LINE_STS            BIT2
//#define UART_INT_MODEM_STS              BIT3
#if UART_SUPPORT_TX_DONE
#define UART_INT_TX_DONE                BIT4
#endif
#if UART_SUPPORT_TX_THD
#define UART_INT_TX_THD                 BIT5
#endif
//#define UART_INT_RX_BREAK               BIT6
#define UART_INT_RX_IDLE                BIT7

#define IS_UART_INT(INT) ((((INT) & 0xFFFFFF80) == 0x00) && ((INT) != 0x00))

#define IS_UART_GET_INT(INT) ((INT) & (UART_INT_RD_AVA | \
                                       UART_INT_TX_FIFO_EMPTY | \
                                       UART_INT_RX_LINE_STS | \
                                       UART_INT_MODEM_STS | \
                                       UART_INT_TX_DONE | \
                                       UART_INT_TX_THD | \
                                       UART_INT_RX_BREAK | \
                                       UART_INT_RX_IDLE))

/** End of UART_Interrupts
  * \}
  */

/**
 * \defgroup    UART_Interrupt_Identifier UART Interrupt Identifier
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define UART_INT_PENDING                ((uint16_t)(0x01 << 0))
#define UART_INT_ID_LINE_STATUS         ((uint16_t)(0x03 << 1))
#define UART_INT_ID_RX_LEVEL_REACH      ((uint16_t)(0x02 << 1))
#define UART_INT_ID_RX_DATA_TIMEOUT     ((uint16_t)(0x06 << 1))
#define UART_INT_ID_TX_FIFO_EMPTY       ((uint16_t)(0x01 << 1))
//#define UART_INT_ID_MODEM_STATUS        ((uint16_t)(0x00 << 1))

#define IS_UART_INT_ID(ID) (((ID) == UART_INT_ID_LINE_STATUS) || \
                            ((ID) == UART_INT_ID_RX_LEVEL_REACH) || \
                            ((ID) == UART_INT_ID_RX_DATA_TIMEOUT) || \
                            ((ID) == UART_INT_ID_TX_FIFO_EMPTY) || \
                            ((ID) == UART_INT_ID_MODEM_STATUS))

/** End of UART_Interrupt_Identifier
  * \}
  */

/**
 * \defgroup    UART_Flag UART Flag
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define UART_FLAG_RX_DATA_AVA           BIT0
#define UART_FLAG_RX_OVERRUN            BIT1
#define UART_FLAG_RX_PARITY_ERR         BIT2
#define UART_FLAG_RX_FRAME_ERR          BIT3
#define UART_FLAG_RX_BREAK_ERR          BIT4
#define UART_FLAG_TX_FIFO_EMPTY         BIT5
#define UART_FLAG_TX_EMPTY              BIT6
#define UART_FLAG_RX_FIFO_ERR           BIT7
//#define UART_FLAG_RX_BREAK              BIT8
#define UART_FLAG_RX_IDLE               BIT9
#if UART_SUPPORT_TX_DONE
#define UART_FLAG_TX_DONE               BIT10
#endif
#if UART_SUPPORT_TX_THD
#define UART_FLAG_TX_THD                BIT11
#endif

#define IS_UART_GET_FLAG(FLAG) (((FLAG) == UART_FLAG_RX_DATA_RDY) || \
                                ((FLAG) == UART_FLAG_RX_OVERRUN) || \
                                ((FLAG) == UART_FLAG_PARTY_ERR) || \
                                ((FLAG) == UART_FLAG_FRAME_ERR) || \
                                ((FLAG) == UART_FLAG_BREAK_ERR) || \
                                ((FLAG) == UART_FLAG_THR_EMPTY) || \
                                ((FLAG) == UART_FLAG_THR_TSR_EMPTY) || \
                                ((FLAG) == UART_FLAG_RX_FIFO_ERR) || \
                                ((FLAG) == UART_FLAG_RX_IDLE))

/** End of UART_Flag
  * \}
  */

/**
 * \defgroup    UART_Interrupts_Mask UART Interrupts Mask
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define UART_INT_MASK_RD_AVA            BIT0
#define UART_INT_MASK_TX_FIFO_EMPTY     BIT1
#define UART_INT_MASK_RX_LINE_STS       BIT2
//#define UART_INT_MASK_MODEM_STS         BIT3
//#define UART_INT_MASK_RX_BREAK          BIT4
#define UART_INT_MASK_RX_IDLE           BIT5
#if UART_SUPPORT_TX_DONE
#define UART_INT_MASK_TX_DONE           BIT6
#endif
#if UART_SUPPORT_TX_THD
#define UART_INT_MASK_TX_THD            BIT7
#endif

#define IS_UART_INT_MASK(INT) ((INT) & (UART_INT_MASK_RD_AVA | \
                                        UART_INT_MASK_TX_FIFO_EMPTY | \
                                        UART_INT_MASK_RX_LINE_STS | \
                                        UART_INT_MASK_MODEM_STS | \
                                        UART_INT_MASK_RX_BREAK | \
                                        UART_INT_MASK_RX_IDLE | \
                                        UART_INT_MASK_TX_DONE | \
                                        UART_INT_MASK_TX_THD))

/** End of UART_Interrupts_Mask
  * \}
  */

/**
 * \defgroup    UART_TRx_Fifo_Clear_Bits UART TRx Fifo Clear Bits
 * \{
 * \ingroup     UART_Exported_Constants
 */
#define FCR_CLEAR_RX_FIFO_Set           ((uint32_t)(1 << 1))
#define FCR_CLEAR_RX_FIFO_Reset         ((uint32_t)~(1 << 1))
#define FCR_CLEAR_TX_FIFO_Set           ((uint32_t)(1 << 2))
#define FCR_CLEAR_TX_FIFO_Reset         ((uint32_t)~(1 << 2))

/** End of UART_TRx_Fifo_Clear_Bits
  * \}
  */

/** End of UART_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup UART_Exported_Types UART Exported Types
  * \brief
  * \{
  */

/**
 * \brief       UART initialize parameters
 *
 * \ingroup     UART_Exported_Types
 */
typedef struct
{
    uint16_t UART_OvsrAdj;              /*!< Specifies the baud rate setting, ovsr_adj, please refer to baudrate setting table.*/
    uint16_t UART_Div;                  /*!< Specifies the baud rate setting, div, please refer to baudrate setting table.*/
    uint16_t UART_Ovsr;                 /*!< Specifies the baud rate setting, ovsr, please refer to baudrate setting table.*/
    UARTWordLen_TypeDef UART_WordLen;   /*!< Specifies the UART Wordlength. */
    UARTStopBits_TypeDef UART_StopBits; /*!< Specifies the stop bit. */
    UARTParity_TypeDef UART_Parity;     /*!< Specifies the parity. */
    uint8_t UART_TxThdLevel;            /*!< Specifies the Tx threshold level. This parameter must range from 1 to 29.*/
    uint8_t UART_RxThdLevel;            /*!< Specifies the Rx threshold level. This parameter must range from 1 to 29.*/
    UARTTimeout_TypeDef UART_IdleTime; /*!< Specifies the idle time. */
    uint8_t UART_HardwareFlowControl;   /*!< Enable or Disable hardware flow control. */
    uint8_t UART_DmaEn;                 /*!< Enable or Disable dma mode. */
    uint8_t UART_TxDmaEn;               /*!< Enable or Disable Tx dma mode. */
    uint8_t UART_RxDmaEn;               /*!< Enable or Disable Rx dma mode. */
    uint8_t UART_TxWaterLevel;          /*!< Specifies the DMA tx water level. This parameter must range from 1 to 16.*/
    uint8_t UART_RxWaterLevel;          /*!< Specifies the DMA rx water level. This parameter must range from 1 to 31.*/
} UART_InitTypeDef;

/** End of UART_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup UART_Exported_Functions UART Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitialize the selected UART peripheral registers to their default reset values(turn off UART clock).
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *    UART_DeInit(UART0);
 * }
 * \endcode
 */
void UART_DeInit(UART_TypeDef *UARTx);

/**
 * \brief   Initialize the selected UART peripheral according to the specified
 *          parameters in  UART_InitStruct.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] UART_InitStruct: Pointer to a UART_InitTypeDef structure that
 *            contains the configuration information for the selected UART peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *    //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * \endcode
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct);

/**
 * \brief   Fills each UART_InitStruct member with its default value.
 *
 * \param[in] UART_InitStruct: pointer to an UART_InitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * \endcode
 */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct);

/**
 * \brief   Mask or unmask the specified UART interrupt source.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] UART_INT: Specified the UART interrupt source that to be mask or unmask.
 *            This parameter can be one of the following values:
 *            \arg UART_INT_MASK_RD_AVA: Mask INTCR(erbi).
 *            \arg UART_INT_MASK_FIFO_EMPTY: Mask INTCR(etbei).
 *            \arg UART_INT_MASK_LINE_STS: Mask INTCR(elsi).
 *            \arg UART_INT_MASK_MODEM_STS: Mask INTCR(edssi).
 *            \arg UART_INT_MASK_RX_BREAK: Mask rx break interrupt.
 *            \arg UART_INT_MASK_RX_IDLE: Mask rx break interrupt.
 *            \arg UART_INT_MASK_TX_DONE: Mask the interrupt tx done interrupt.
 *            \arg UART_INT_MASK_TX_THD: Mask tx fifo threshold interrupt.
 * \param[in] NewState: New state of the specified UART interrupt source.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, ENABLE);
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, DISABLE);
 * }
 * \endcode
 */
void UART_MaskINTConfig(UART_TypeDef *UARTx, uint32_t UART_INT_MASK,
                        FunctionalState NewState);
/**
 * \brief   Enable or disable the specified UART interrupts.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] UART_IT: Specified the UART interrupt source that to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg UART_INT_RD_AVA: Rx data avaliable interrupt source.
 *            \arg UART_INT_TX_FIFO_EMPTY: Tx FIFO empty interrupt source.
 *            \arg UART_INT_RX_LINE_STS: Rx line status interrupt source.
 *            \arg UART_INT_MODEM_STS: Modem status interrupt source.
 *            \arg UART_INT_TX_DONE: Tx done interrupt source.
 *            \arg UART_INT_TX_THD: Tx threshold(FIFO data length <= thredhold) interrupt source.
 *            \arg UART_INT_RX_BREAK: Rx break signal interrupt source.
 *            \arg UART_INT_RX_IDLE: Rx bus ilde interrupt source.
 * \param[in] NewState: New state of the specified UART interrupt source.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 * }
 * \endcode
 */
void UART_INTConfig(UART_TypeDef *UARTx, uint32_t UART_IT, FunctionalState NewState);

/**
 * \brief   Send data.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] inBuf: Buffer of data to be sent.
 * \param[in] count: Length of data to be sent.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_SendData(UART0, data, sizeof(data));
 * }
 * \endcode
 */
void UART_SendData(UART_TypeDef *UARTx, const uint8_t *inBuf, uint16_t Count);

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Send half word data.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] inBuf: Buffer of data to be sent.
 * \param[in] count: Length of data to be sent.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_SendHalfWordData(UART0, data, sizeof(data));
 * }
 * \endcode
 */
void UART_SendHalfWordData(UART_TypeDef *UARTx, const uint16_t *inBuf, uint16_t Count);
#endif

#if UART_SUPPORT_TXDATA_API
/**
 * \brief   Tx data.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] inBuf: Buffer of data to be sent.
 * \param[in] count: Length of data to be sent.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_TxData(UART0, data, sizeof(data));
 * }
 * \endcode
 */
void UART_TxData(UART_TypeDef *UARTx, const uint8_t *inBuf, uint16_t count);
#endif

/**
 * \brief   Receive data from RX FIFO.
 *
 * \param[in]  UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[out] outBuf: Buffer to store data which read from RX FIFO.
 * \param[in]  count: Length of data to read.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[32] = {10};
 *     UART_ReceiveData(UART0, data, 10);
 * }
 * \endcode
 */
void UART_ReceiveData(UART_TypeDef *UARTx, uint8_t *outBuf, uint16_t count);

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Receive half word data from RX FIFO.
 *
 * \param[in]  UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[out] outBuf: Buffer to store data which read from RX FIFO.
 * \param[in]  count: Length of data to read.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[32] = {10};
 *     UART_ReceiveData(UART0, data, 10);
 * }
 * \endcode
 */
void UART_ReceiveHalfWordData(UART_TypeDef *UARTx, uint16_t *outBuf, uint16_t count);
#endif

/**
 * \brief   Set UART communication baudrate.
 *
 * \param[in]  UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in]  div: Parameter of the selected UART baudrate.
 * \param[in]  ovsr: Parameter of the selected UART baudrate.
 * \param[in]  ovsr_adj: Parameter of the selected UART baudrate.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * UART BaudRate Table: Baud rate set value for different data length (clock source 40MHz only)
 *  9 bits data length: start bit + 7 data bit + stop bit
 * 10 bits data length: start bit + 8 data bit + stop bit
 * 11 bits data length: start bit + 8 data bit + parity bit + stop bit
 * 12 bits data length: start bit + 8 data bit + parity bit + stop bit+ 2nd Stop bit
    baudrate |       9 bits data length      |       10 bits data length     |      11 bits data length      |      12 bits data length      |
             |  ovsr  |  ovsr_adj  |  div    |  ovsr  |  ovsr_adj  |  div    |  ovsr  |  ovsr_adj  |  div    |  ovsr  |  ovsr_adj  |  div    |
   --------------------------------------------------------------------------------------------------------------------------------------------
   1200      |   0x5      0x16D      0xC35   |   0x9      0x112      0x91B   |   0x9      0x70       0x91B   |   0x9      0x71       0x91B   |
   4800      |   0x0      0x0        0x682   |   0x0      0x0        0x682   |   0xB      0x6DD      0x1F3   |   0xB      0x6D5      0x1F3   |
   7200      |   0x0      0x0        0x457   |   0x0      0x0        0x457   |   0xC      0x84       0x143   |   0xC      0x84       0x143   |
   9600      |   0x0      0x0        0x341   |   0x0      0x0        0x341   |   0x7      0x7EF      0x143   |   0x7      0x7EF      0x143   |
   14400     |   0x6      0x10       0xFA    |   0x9      0x10       0xC5    |   0x9      0x10       0xC5    |   0x9      0x10       0xC5    |
   19200     |   0x2      0x3        0x120   |   0x1      0x3        0x150   |   0x8      0x77B      0x97    |   0x8      0x77B      0x97    |
   28800     |   0x2      0x3        0xC0    |   0x1      0x3        0xE0    |   0x6      0x84       0x7C    |   0x6      0x84       0x7C    |
   38400     |   0x2      0x3        0x90    |   0x1      0x3        0xA8    |   0xE      0x122      0x36    |   0xE      0x122      0x36    |
   57600     |   0x2      0x3        0x60    |   0x1      0x3        0x70    |   0x6      0x84       0x3E    |   0x6      0x84       0x3E    |
   76800     |   0x2      0x3        0x48    |   0x1      0x3        0x54    |   0xE      0x122      0x1B    |   0xE      0x122      0x1B    |
   115200    |   0x2      0x3        0x30    |   0x1      0x3        0x38    |   0x6      0x84       0x1F    |   0x6      0x84       0x1F    |
   230400    |   0x2      0x3        0x18    |   0x1      0x3        0x1C    |   0xE      0x122      0x9     |   0xE      0x122      0x9     |
   460800    |   0x2      0x3        0xC     |   0x1      0x3        0xE     |   0x7      0x14A      0x7     |   0x7      0x15A      0x7     |
   500000    |   0x5      0x0        0x8     |   0x5      0x0        0x8     |   0x5      0x0        0x8     |   0x5      0x0        0x8     |
   921600    |   0x2      0x3        0x6     |   0x1      0x3        0x7     |   0x9      0x2AA      0x3     |   0x9      0x2AB      0x3     |
   1000000   |   0x0      0x0        0x8     |   0x0      0x0        0x8     |   0x5      0x0        0x4     |   0x5      0x0        0x4     |
   1382400   |   0x9      0xAA       0x2     |   0x9      0x2AA      0x2     |   0x9      0x2AA      0x2     |   0x9      0x2AB      0x2     |
   1444400   |   0x8      0x1F7      0x2     |   0x8      0x3F7      0x2     |   0x8      0x3F7      0x2     |   0x8      0x3FF      0x2     |
   1500000   |   0x8      0x92       0x2     |   0x8      0x92       0x2     |   0x8      0x492      0x2     |   0x8      0x490      0x2     |
   1843200   |   0x5      0x1F7      0x2     |   0x5      0x3F7      0x2     |   0x5      0x3F7      0x2     |   0x5      0x3FF      0x2     |
   2000000   |   0x0      0x0        0x4     |   0x0      0x0        0x4     |   0x5      0x0        0x2     |   0x5      0x0        0x2     |
   3000000   |   0x8      0x92       0x1     |   0x8      0x92       0x1     |   0x8      0x492      0x1     |   0x8      0x490      0x1     |
   4000000   |   0x5      0x0        0x1     |   0x5      0x0        0x1     |   0x5      0x0        0x1     |   0x5      0x0        0x1     |
   ---------------------------------------------------------------------------------------------------------------------------------------------
 *
 * void uart_demo(void)
 * {
 *     uint16_t div = 20;
 *     uint16_t ovsr = 12;
 *     uint16_t ovsr_adj = 0x252;
 *     UART_SetBaudRate(UART0, div, ovsr, ovsr_adj);
 * }
 *
 * \endcode
 */
void UART_SetBaudRate(UART_TypeDef *UARTx, uint16_t div, uint16_t ovsr, uint16_t ovsr_adj);

/**
 * \brief   Set UART communication parameters.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] wordLen: Data width of the selected UART peripheral.
 *            This parameter can be one of the following values:
 *            \arg UART_WORD_LENGTH_7BIT: 7-bit data length.
 *            \arg UART_WORD_LENGTH_8BIT: 8-bit data length.
 * \param[in] parity: parity of the selected UART peripheral.
 *            This parameter can be one of the following values:
 *            \arg UART_STOP_BITS_1: 1-bit stop bit.
 *            \arg UART_STOP_BITS_2: 2-bit stop bit.
 * \param[in] stopBits: Stop bit of the selected UART peripheral.
 *            This parameter can be one of the following values:
 *            \arg UART_PARITY_NO_PARTY: No parity.
 *            \arg UART_PARITY_ODD: Odd parity.
 *            \arg UART_PARITY_EVEN: Even parity.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t word_len = UART_WORD_LENGTH_8BIT;
 *     uint16_t parity = UART_PARITY_NO_PARTY;
 *     uint16_t stop_bits = UART_STOP_BITS_1;
 *     UART_SetParams(UART0, wordLen, parity, stopBits);
 * }
 * \endcode
 */
void UART_SetParams(UART_TypeDef *UARTx, uint16_t wordLen, uint16_t parity, uint16_t stopBits);

/**
 * \brief   Config UART loopback function.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] NewState: Enable or disable UART loopback function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_LoopBackCmd(UART0, ENABLE);
 * }
 * \endcode
 */
void UART_LoopBackCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief  Check whether the specified UART flag is set.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] UART_FLAG: Specified UART flag to check.
 *            This parameter can be one of the following values:
 *            \arg UART_FLAG_RX_DATA_AVA: Rx data is avaliable.
 *            \arg UART_FLAG_RX_OVERRUN: Rx FIFO overrun.
 *            \arg UART_FLAG_RX_PARITY_ERR: Rx parity error.
 *            \arg UART_FLAG_RX_FRAME_ERR: Rx frame error.
 *            \arg UART_FLAG_RX_BREAK_ERR: Rx break error.
 *            \arg UART_FLAG_TX_FIFO_EMPTY: Tx Holding Register or Tx FIFO empty
 *            \arg UART_FLAG_TX_EMPTY: Tx FIFO and Tx shift register are both empty.
 *            \arg UART_FLAG_RX_FIFO_ERR: Rx FIFO error.
 *            \arg UART_FLAG_RX_IDLE: Rx idle.
 *            \arg UART_FLAG_TX_DONE: Tx waveform done & TX_FIFO_EMPTY = 1.
 *            \arg UART_FLAG_TX_THD: TX_FIFO_LEVEL<=txfifo_trigger_level.
 *
 * \return New status of UART flag.
 *         \retval SET: The specified UART flag bit is set.
 *         \retval RESET: The specified flag is not set.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_senddata_continuous(UART_TypeDef *UARTx, const uint8_t *pSend_Buf, uint16_t vCount)
 * {
 *     uint8_t count;
 *
 *     while (vCount / UART_TX_FIFO_SIZE > 0)
 *     {
 *         while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *         for (count = UART_TX_FIFO_SIZE; count > 0; count--)
 *         {
 *             UARTx->UART_RBR_THR = *pSend_Buf++;
 *         }
 *         vCount -= UART_TX_FIFO_SIZE;
 *     }
 *
 *     while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *     while (vCount--)
 *     {
 *         UARTx->UART_RBR_THR = *pSend_Buf++;
 *     }
 * }
 * \endcode
 */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint32_t UART_FLAG);

/**
 * \brief  Check whether the specified UART flag is set.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return New status of UART flag.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint32_t line_status = UART_GetLineStatus(UART_DEMO);
 *
 * if (line_status & UART_FLAG)
 * {
 *     //Add user code here.
 * }
 *
 * \endcode
 */
uint8_t UART_GetLineStatus(UART_TypeDef *UARTx);

/**
 * \brief   Send one byte of data.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] data: Byte data to send.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = 0x55;
 *     UART_SendByte(UART0, data);
 * }
 * \endcode
 */
void UART_SendByte(UART_TypeDef *UARTx, uint8_t data);

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Send half word of data.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] data: Byte data to send.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = 0x55;
 *     UART_SendByte(UART0, data);
 * }
 * \endcode
 */
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t data);
#endif

/**
 * \brief   Read a byte of data from UART RX FIFO.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  Which byte data has been read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = UART_ReceiveByte(UART0);
 *
 * }
 * \endcode
 */
uint8_t UART_ReceiveByte(UART_TypeDef *UARTx);

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Read a byte of data from UART RX FIFO.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  Which byte data has been read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = UART_ReceiveByte(UART0);
 *
 * }
 * \endcode
 */
uint8_t UART_ReceiveHalfWord(UART_TypeDef *UARTx);
#endif

/**
 * \brief   Get interrupt identifier of the selected UART peripheral.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return The interrupt identifier value.
 *         This return value can be one or a combination of the following:
 *         \retval UART_INT_ID_LINE_STATUS: Rx line status interrupt ID.
 *         \retval UART_INT_ID_RX_LEVEL_REACH: Rx data available or trigger level reached interrupt ID.
 *         \retval UART_INT_ID_RX_TMEOUT: Rx FIFO data timeout interrupt ID.
 *         \retval UART_INT_ID_TX_FIFO_EMPTY: Tx FIFO empty interrupt ID.
 *         \retval UART_INT_ID_MODEM_STATUS: Modem status interrupt ID.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void UART0_Handler()
 * {
 *     uint16_t rx_len = 0;
 *     uint8_t uart_rev_data[32];
 *
 *     //Get interrupt ID.
 *     uint32_t int_status = UART_GetIID(UART0);
 *
 *     //Disable interrupt.
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, DISABLE);
 *
 *     if (UART_GetFlagStatus(UART0, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         UART_INTConfig(UART0, UART_INT_RX_IDLE, DISABLE);
 *         //Add user code here.
 *         UART_ClearRxFIFO(UART0);
 *         UART_INTConfig(UART0, UART_INT_RX_IDLE, ENABLE);
 *     }
 *
 * }
 * \endcode
 */
uint16_t UART_GetIID(UART_TypeDef *UARTx);

#if UART_SUPPORT_CLEAR_TX_FIFO
/**
 * \brief   Clear Tx FIFO of the selected UART peripheral.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearTxFIFO(UART0);
 * }
 * \endcode
 */
void UART_ClearTxFIFO(UART_TypeDef *UARTx);
#endif

/**
 * \brief   Clear Rx FIFO of the selected UART peripheral.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearRxFIFO(UART0);
 * }
 * \endcode
 */
void UART_ClearRxFIFO(UART_TypeDef *UARTx);

/**
 * \brief   Get the data length in Tx FIFO of the selected UART peripheral.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  Data length in UART TX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetTxFIFODataLen(UART0);
 * }
 * \endcode
 */
uint8_t UART_GetTxFIFODataLen(UART_TypeDef *UARTx);

/**
 * \brief   Get the data length in Rx FIFO of the selected UART peripheral.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 *
 * \return  Data length in UART RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetRxFIFODataLen(UART0);
 * }
 * \endcode
 */
uint8_t UART_GetRxFIFODataLen(UART_TypeDef *UARTx);

/**
 * \brief    Enable/Disable DMA mode on UART side.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] NewState: Enable or disable UART DMA mode.
 *            This parameter can be one of the following values:
 *            \arg true: Enable UART DMA mode.
 *            \arg false: Disable UART DMA mode.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     UART_TxDmaCmd(UART_DEMO, false);
 * }
 * \endcode
 */
void UART_TxDmaCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief    Enable/Disable DMA mode on UART side.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] NewState: Enable or disable UART DMA mode.
 *            This parameter can be one of the following values:
 *            \arg true: Enable UART DMA mode.
 *            \arg false: Disable UART DMA mode.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     UART_RxDmaCmd(UART_DEMO, false);
 * }
 * \endcode
 */
void UART_RxDmaCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief   UART one wire config.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] NewState: UART one wire config is set or not.
 *            This parameter can be one of the following values:
 *            \arg true: UART one wire config is set.
 *            \arg false: UART one wire config is unset.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_OneWireConfig(UART0, true);
 * }
 * \endcode
 */
void UART_OneWireConfig(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief  UART clock divider config.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[in] ClockDiv: Specifies the UART clock divider.
 *            This parameter can be one of the following values:
 *            \arg UART_CLOCK_DIVIDER_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     RCC_UARTClkDivConfig(UART0, UART_CLOCK_DIVIDER_1);
 * }
 * \endcode
 */
void UART_ClkDivConfig(UART_TypeDef *UARTx, UARTClockDiv_TypeDef ClockDiv);

/**
 * \brief  Get UART clock divider config.
 *
 * \param[in] UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param[out] ClockSrc: specifies the UART clock source.
 * \param[out] ClockDiv: Specifies the UART clock divider.
 *            This parameter can be one of the following values:
 *            \arg UART_CLOCK_DIVIDER_x: where x can refer to CLock Divider to select the specified clock divider
 *
 * \return The status of get clock.
 */
bool UART_ClkGet(UART_TypeDef *UARTx, UARTClockSrc_TypeDef *ClockSrc,
                 UARTClockDiv_TypeDef *ClockDiv);

#if (UART_SUPPORT_RAP_FUNCTION == 1)

void UART_RAPQactiveCtrl(UART_TypeDef *UARTx, uint32_t Qactive, FunctionalState NewState);

#endif

/** End of UART_Exported_Functions
  * \}
  */

/** End of UART
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_UART_H */


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/
