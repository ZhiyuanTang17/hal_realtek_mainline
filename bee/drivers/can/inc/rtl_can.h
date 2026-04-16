/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _RTL_CAN_H_
#define _RTL_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "can/src/device/rtl87x2g/rtl_can_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3EP)
#include "can/src/device/rtl87x3ep/rtl_can_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "can/src/device/rtl87x2j/rtl_can_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3EU)
#include "can/src/device/rtl87x3eu/rtl_can_def.h"
#endif

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define CAN_MESSAGE_BUFFER_MAX_CNT      16
#define CAN_MESSAGE_BUFFER_MAX_INDEX    (CAN_MESSAGE_BUFFER_MAX_CNT - 1)
#define CAN_MESSAGE_BUFFER_DEFAULT_LEN  20
#define CAN_MESSAGE_FIFO_START_ID       12
#define CAN_DEFAULT_ERR_WARN_TH         96
#define CAN_STAND_DATA_MAX_LEN          8
#define CAN_RAM_DATA_MAX_INDEX          1
#define CAN_STD_FRAME_ID_POS            18
#define CAN_EXT_FRAME_ID_POS            0
#define CAN_RAM_ACC_DATA_POS            11
#define CAN_STAND_FRAME_ID_MAX_VALUE    0x7FFUL
#define CAN_EXTEND_FRAME_ID_MAX_VALUE   0x3FFFFUL
#define CAN_FRAME_ID_MASK_MAX_VALUE     0x1FFFFFFFUL

/** \defgroup CAN         CAN
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup CAN_Exported_Constants CAN Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    CAN_DLC_Byte CAN DLC Byte
 * \{
 * \ingroup     CAN_Exported_Constants
 */
#define CAN_DLC_BYTES_0                 (0x0UL)     //!< Data length = 0 byte.
#define CAN_DLC_BYTES_1                 (0x1UL)     //!< Data length = 1 byte.
#define CAN_DLC_BYTES_2                 (0x2UL)     //!< Data length = 2 bytes.
#define CAN_DLC_BYTES_3                 (0x3UL)     //!< Data length = 3 bytes.
#define CAN_DLC_BYTES_4                 (0x4UL)     //!< Data length = 4 bytes.
#define CAN_DLC_BYTES_5                 (0x5UL)     //!< Data length = 5 bytes.
#define CAN_DLC_BYTES_6                 (0x6UL)     //!< Data length = 6 bytes.
#define CAN_DLC_BYTES_7                 (0x7UL)     //!< Data length = 7 bytes.
#define CAN_DLC_BYTES_8                 (0x8UL)     //!< Data length = 8 bytes.

/** End of CAN_DLC_Byte
  * \}
  */

/**
 * \defgroup    CAN_Interrupt_Definition CAN Interrupt Definition
 * \{
 * \ingroup     CAN_Exported_Constants
 */
#define CAN_RAM_MOVE_DONE_INT                       BIT5    //!< Triggered when data move from register to CAN IP internal RAM finished.
#define CAN_BUS_OFF_INT                             BIT4    //!< Triggered when the bus is off.
#define CAN_WAKE_UP_INT                             BIT3    //!< Triggered when CAN awakened from low power mode.
#define CAN_ERROR_INT                               BIT2    //!< Triggered by an error during transmission.
#define CAN_RX_INT                                  BIT1    //!< Triggered when data is received.
#define CAN_TX_INT                                  BIT0    //!< Triggered when sending is completed.

#define IS_CAN_INT_CONFIG(CONFIG)     (((CONFIG) == CAN_RAM_MOVE_DONE_INT)  || \
                                       ((CONFIG) == CAN_BUS_OFF_INT)        || \
                                       ((CONFIG) == CAN_WAKE_UP_INT)        || \
                                       ((CONFIG) == CAN_ERROR_INT)          || \
                                       ((CONFIG) == CAN_RX_INT)             || \
                                       ((CONFIG) == CAN_TX_INT))

/** End of CAN_Interrupt_Definition
  * \}
  */

/**
 * \defgroup    CAN_Interrupt_Flag CAN Interrupt Flag
 * \{
 * \ingroup     CAN_Exported_Constants
 */
#define CAN_RAM_MOVE_DONE_INT_FLAG                  BIT5    //!< Triggered when data move from register to CAN IP internal RAM finished.
#define CAN_BUS_OFF_INT_FLAG                        BIT4    //!< Triggered when the bus is off.
#define CAN_WAKE_UP_INT_FLAG                        BIT3    //!< Triggered when CAN awakened from low power mode.
#define CAN_ERROR_INT_FLAG                          BIT2    //!< Triggered by an error during transmission.
#define CAN_RX_INT_FLAG                             BIT1    //!< Triggered when data is received.
#define CAN_TX_INT_FLAG                             BIT0    //!< Triggered when sending is completed.

#define IS_CAN_INT_FLAG(FLAG)         (((CONFIG) == CAN_RAM_MOVE_DONE_INT_FLAG) || \
                                       ((CONFIG) == CAN_BUS_OFF_INT_FLAG)       || \
                                       ((CONFIG) == CAN_WAKE_UP_INT_FLAG)       || \
                                       ((CONFIG) == CAN_ERROR_INT_FLAG)         || \
                                       ((CONFIG) == CAN_RX_INT_FLAG)            || \
                                       ((CONFIG) == CAN_TX_INT_FLAG))

/** End of CAN_Interrupt_Flag
  * \}
  */

/**
 * \defgroup    CAN_Error_Mask CAN Error Mask
 * \{
 * \ingroup     CAN_Exported_Constants
 */
#define CAN_ERROR_RX                                BIT9    //!< Receiving error occurred.
#define CAN_ERROR_TX                                BIT8    //!< Sending error occurred.
#define CAN_ERROR_ACK                               BIT5    //!< Ack error occurred.
#define CAN_ERROR_STUFF                             BIT4    //!< Stuff error occurred.
#define CAN_ERROR_CRC                               BIT3    //!< CRC error occurred.
#define CAN_ERROR_FORM                              BIT2    //!< Form error occurred.
#define CAN_ERROR_BIT1                              BIT1    //!< BIT1 error occurred.
#define CAN_ERROR_BIT0                              BIT0    //!< BIT0 error occurred.

#define IS_CAN_ERROR_STATUS(STATUS)   (((STATUS) == CAN_ERROR_RX)   || \
                                       ((STATUS) == CAN_ERROR_TX)   || \
                                       ((STATUS) == CAN_ERROR_ACK)  || \
                                       ((STATUS) == CAN_ERROR_CRC)  || \
                                       ((STATUS) == CAN_ERROR_FORM) || \
                                       ((STATUS) == CAN_ERROR_BIT1) || \
                                       ((STATUS) == CAN_ERROR_BIT0))

/** End of CAN_Error_Mask
  * \}
  */

/** End of CAN_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup CAN_Exported_Types CAN Exported Types
  * \brief
  * \{
  */

/**
 * \brief       CAN init structure definition.
 *
 * \ingroup     CAN_Exported_Types
 */
typedef struct
{
    uint8_t CAN_AutoReTxEn;                 /*!< Specifies Whether the auto re-transmission function is enable. */
    uint8_t CAN_RxFifoEn;                   /*!< Specifies Whether the rx fifo function is enable. */
    uint8_t CAN_RxDMAEn;                    /*!< Specifies Whether the rx dma function is enable. */
    uint8_t CAN_TestModeSel;                /*!< Specifies the test mode of CAN.
                                                        This parameter can be a value of @ref CANTestModeSel_TypeDef */
    uint16_t CAN_ErrorWarnThd;              /*!< Specifies error counter warning threshold. */
    CAN_0x0C_TYPE_TypeDef CAN_BitTiming;    /*!< Specifies the bit timing of CAN. */
    CAN_0x40_TYPE_TypeDef CAN_TimeStamp;    /*!< Specifies the timestamp function of CAN. */
} CAN_InitTypeDef;

typedef enum
{
    CAN_BUS_STATE_OFF,          //!< CAN state on.
    CAN_BUS_STATE_ON,           //!< CAN state off.
} CANBusStateSel_TypeDef;

typedef enum
{
    CAN_RAM_STATE_IDLE,         //!< CAN RAM is idle.
    CAN_RAM_STATE_EXCHANGING,   //!< CAN RAM is exchanging.
} CANRamStateSel_TypeDef;

typedef enum
{
    CAN_TEST_MODE_SILENCE,          //!< Silence mode.
#if CAN_SUPPORT_EXT_LOOPBACK
    CAN_TEST_MODE_EXT_LOOPBACK,     //!< External loopback mode.
#endif
    CAN_TEST_MODE_INT_LOOPBACK,     //!< Internal loopback mode.
    CAN_TEST_MODE_NONE,             //!< No test mode.
} CANTestModeSel_TypeDef;

typedef enum
{
    CAN_RTR_DATA_FRAME = 0,         //!< Data frame.
    CAN_RTR_REMOTE_FRAME = 1,       //!< Remote frame.
} CANRtrSel_TypeDef;

typedef enum
{
    CAN_IDE_STANDARD_FORMAT = 0,    //!< Standard ID.
    CAN_IDE_EXTEND_FORMAT = 1,      //!< Extend ID.
} CANIdeSel_TypeDef;

typedef enum
{
    CAN_EDL_STARDARD_FRAME = 0,     //!< Standard frame.
} CANEdlSel_TypeDef;

typedef enum
{
    CAN_INVALID_DATA_FRAME,             //!< Invalide data frame.
    CAN_STD_DATA_FRAME,                 //!< Standard data frame.
    CAN_EXT_DATA_FRAME,                 //!< Extend data frame.
    CAN_STD_REMOTE_FRAME,               //!< Standard remote frame.
    CAN_EXT_REMOTE_FRAME,               //!< Extend remote frame.
} CANDataFrameSel_TypeDef;

typedef enum
{
    CAN_NO_ERR = 0,                     //!< No error.
    CAN_MSG_ID_ERR = 1,                 //!< Can message id error.
    CAN_ID_ERR = 2,                     //!< Can frame id error.
    CAN_DATA_LEN_ERR = 3,               //!< Can frame data length error.
    CAN_TYPE_ERR = 4,                   //!< Can frame type error.
    CAN_RAM_STATE_ERR = 5,              //!< Can frame ram status error.
    CAN_TIMEOUT_ERR = 6,                //!< Can timeout error.
} CANError_TypeDef;

typedef struct
{
    uint8_t msg_buf_id;                 //!< Message buffer ID.
    uint8_t auto_reply_bit;             //!< The auto reply bit of frame.
    CANDataFrameSel_TypeDef frame_type; //!< The type of frame.
    uint16_t standard_frame_id;         //!< The standard frame ID.
    uint32_t extend_frame_id;           //!< The extend frame ID.
} CANTxFrame_TypeDef;

typedef struct
{
    uint8_t msg_buf_id;                         //!< Message buffer ID.
    uint8_t rx_dma_en;                          //!< The dma enable bit of RX frame.
    CANFrameRTRMask_TypeDef frame_rtr_mask;     //!< Can frame RTR mask.
    CANFrameIDEMask_TypeDef frame_ide_mask;     //!< Can frame IDE mask.
    uint32_t frame_id_mask;                     //!< Can frame ID mask.
    uint8_t frame_rtr_bit;                      //!< Can frame RTR bit, determine DATA or REMOTE frame.
    uint8_t frame_ide_bit;                      //!< Can frame IDE bit, determine standard or extend format.
    uint8_t auto_reply_bit;                     //!< The auto reply bit of RX frame.
    uint16_t standard_frame_id;                 //!< Standard frame ID.
    uint32_t extend_frame_id;                   //!< Extend frame ID.
    bool rx_msg_buf_enable;                     //!< Enable oor disable rx mst buffer.
} CANRxFrame_TypeDef;

typedef struct
{
    uint8_t rtr_mask;                   //!< The mask of rtr.
    uint8_t ide_mask;                   //!< The mask of ide.
    uint8_t id_mask;                    //!< The mask of id.
    uint8_t esi_bit;                    //!< The mask of esi.
    uint8_t auto_reply_bit;             //!< The auto reply bit.
    uint8_t rxtx_bit;                   //!< The rxtx bit.
    uint8_t rx_lost_bit;                //!< The rx lost bit.
    uint8_t data_length;                //!< The data length.
    uint8_t rx_dma_en;                  //!< The dma enable bit.
    CANRtrSel_TypeDef rtr_bit;          //!< The rtr bit \ref CANRtrSel_TypeDef.
    CANIdeSel_TypeDef ide_bit;          //!< The ide bit \ref CANIdeSel_TypeDef.
    uint16_t rx_timestamp;              //!< The time stamp.
    uint16_t standard_frame_id;         //!< Standard frame ID.
    uint32_t extend_frame_id;           //!< Extend frame ID.
} CANMsgBufInfo_TypeDef;

typedef struct
{
    uint8_t fifo_msg_lvl;               //!< Indicates the number of message in fifo.
    uint8_t fifo_msg_overflow;          //!< Indicates whether the fifo is overflow.
    uint8_t fifo_msg_empty;             //!< Indicates whether the fifo is empty.
    uint8_t fifo_msg_full;              //!< Indicates whether the fifo is full.
} CANFifoStatus_TypeDef;

typedef struct
{
    CAN_0x340_TYPE_TypeDef can_ram_arb;         //!< ARB
    CAN_0x348_TYPE_TypeDef can_ram_cs;          //!< CS
    uint8_t rx_dma_data[CAN_STAND_DATA_MAX_LEN];
} CANRxDMAData_TypeDef;

/** End of CAN_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup CAN_Exported_Functions CAN Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitializes the CAN peripheral registers to their default values.
 * \param[in] CANx: selected CAN peripheral.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     CAN_DeInit(CAN0);
 * }
 * \endcode
 */
void CAN_DeInit(CAN_TypeDef *CANx);
/**
 * \brief   Initializes the CAN peripheral according to the specified
 *          parameters in the CAN_InitStruct
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_InitStruct: Pointer to a CAN_InitTypeDef structure that
 *            contains the configuration information for the specified CAN peripheral
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     RCC_ClockCmd(CAN0_CLOCK, ENABLE);
 *
 *     CAN_InitTypeDef init_struct;
 *
 *     CAN_StructInit(&init_struct);
 *     init_struct.CAN_AutoReTxEn = DISABLE;
 *     init_struct.CAN_BitTiming.can_brp = 7;
 *     init_struct.CAN_BitTiming.can_sjw = 3;
 *     init_struct.CAN_BitTiming.can_tseg1 = 4;
 *     init_struct.CAN_BitTiming.can_tseg2 = 3;
 *
 *     CAN_Init(CAN0, &init_struct);
 *     CAN_Cmd(CAN0, ENABLE);
 * }
 * \endcode
 */
void CAN_Init(CAN_TypeDef *CANx, CAN_InitTypeDef *CAN_InitStruct);
/**
 * \brief   Fills each CAN_InitStruct member with its default value.
 * \param[in] CAN_InitStruct: Pointer to an CAN_InitTypeDef structure which will be initialized.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     RCC_ClockCmd(CAN_CLOCK, ENABLE);
 *
 *     CAN_InitTypeDef init_struct;
 *
 *     CAN_StructInit(&init_struct);
 *     init_struct.CAN_AutoReTxEn = DISABLE;
 *     init_struct.CAN_BitTiming.can_brp = 7;
 *     init_struct.CAN_BitTiming.can_sjw = 3;
 *     init_struct.CAN_BitTiming.can_tseg1 = 4;
 *     init_struct.CAN_BitTiming.can_tseg2 = 3;
 *
 *     CAN_Init(CAN0, &init_struct);
 *     CAN_Cmd(CAN0, ENABLE);
 * }
 * \endcode
 */
void CAN_StructInit(CAN_InitTypeDef *CAN_InitStruct);
/**
 * \brief   Enable or disable the selected CAN mode.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] NewState: New state of the operation mode.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     RCC_ClockCmd(CAN0_CLOCK, ENABLE);
 *
 *     CAN_InitTypeDef init_struct;
 *
 *     CAN_StructInit(&init_struct);
 *     init_struct.CAN_AutoReTxEn = DISABLE;
 *     init_struct.CAN_BitTiming.can_brp = 7;
 *     init_struct.CAN_BitTiming.can_sjw = 3;
 *     init_struct.CAN_BitTiming.can_tseg1 = 4;
 *     init_struct.CAN_BitTiming.can_tseg2 = 3;
 *
 *     CAN_Init(CAN0, &init_struct);
 *     CAN_Cmd(CAN0, ENABLE);
 * }
 * \endcode
 */
void CAN_Cmd(CAN_TypeDef *CANx, FunctionalState NewState);
/**
 * \brief   Enable or disable the specified CAN interrupt source.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_INT: Specifies the CAN interrupt source to be enable or disable.
 *      This parameter can be the following values:
 *      \arg CAN_RAM_MOVE_DONE_INT: This bit is set to 1 when data move from register to CAN IP internal RAM finished.
 *      \arg CAN_BUS_OFF_INT: This bit is set to 1 when the state of bus is off.
 *      \arg CAN_WAKE_UP_INT: This bit is set to 1 when CAN awakened from low power mode.
 *      \arg CAN_ERROR_INT: This bit is set to 1 when there is an error during transmission.
 *      \arg CAN_RX_INT: This bit is set to 1 when data is received.
 *      \arg CAN_TX_INT: This bit is set to 1 when sending is completed.
 * \param[in]  NewState: New state of the specified CAN interrupt.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     CAN_INTConfig(CAN0, (CAN_RAM_MOVE_DONE_INT | CAN_BUS_OFF_INT | CAN_WAKE_UP_INT |
 *                      CAN_ERROR_INT | CAN_RX_INT | CAN_TX_INT), ENABLE);
 * }
 * \endcode
 */
void CAN_INTConfig(CAN_TypeDef *CANx, uint32_t CAN_INT, FunctionalState newState);
#if (CAN_SUPPORT_INT_MSK_STS == 1)
/**
 * \brief   Mask or unmask the specified CAN interrupt source.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_INT: Specifies the CAN interrupt source to be enable or disable.
 *      This parameter can be the following values:
 *      \arg CAN_RAM_MOVE_DONE_INT: This bit is set to 1 when data move from register to CAN IP internal RAM finished.
 *      \arg CAN_BUS_OFF_INT: This bit is set to 1 when the state of bus is off.
 *      \arg CAN_WAKE_UP_INT: This bit is set to 1 when CAN awakened from low power mode.
 *      \arg CAN_ERROR_INT: This bit is set to 1 when there is an error during transmission.
 *      \arg CAN_RX_INT: This bit is set to 1 when data is received.
 *      \arg CAN_TX_INT: This bit is set to 1 when sending is completed.
 * \param[in]  NewState: New state of the specified CAN interrupt.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void can_driver_init(void)
 * {
 *     CAN_MaskINTConfig(CAN0, (CAN_RAM_MOVE_DONE_INT | CAN_BUS_OFF_INT | CAN_WAKE_UP_INT |
 *                      CAN_ERROR_INT | CAN_RX_INT | CAN_TX_INT), ENABLE);
 * }
 * \endcode
 */

void CAN_MaskINTConfig(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG, FunctionalState NewState);
#endif
/**
 * \brief   Get the specified CAN interrupt raw status.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_INT: the specified CAN interrupt.
 *     This parameter can be one of the following values:
 *     \arg CAN_RAM_MOVE_DONE_INT_FLAG: This bit is set to 1 when data move from register to CAN IP internal RAM finished.
 *     \arg CAN_BUS_OFF_INT_FLAG: This bit is set to 1 when the state of bus is off.
 *     \arg CAN_WAKE_UP_INT_FLAG: This bit is set to 1 when CAN awakened from low power mode.
 *     \arg CAN_ERROR_INT_FLAG: This bit is set to 1 when there is an error during transmission.
 *     \arg CAN_RX_INT_FLAG: This bit is set to 1 when data is received.
 *     \arg CAN_TX_INT_FLAG: This bit is set to 1 when sending is completed.
 * \return The new state of CAN_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void CAN_Handler(void)
 * {
 *     if (SET == CAN_GetINTRawStatus(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG))
 *  {
 *      DBG_DIRECT("[CAN] CAN_Handler CAN_RAM_MOVE_DONE_INT_FLAG");
 *      CAN_ClearINTPendingBit(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG);
 *  }
 * }
 * \endcode
 */
ITStatus CAN_GetINTRawStatus(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG);
/**
 * \brief   Get the specified CAN interrupt status.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_INT: the specified CAN interrupt.
 *     This parameter can be one of the following values:
 *     \arg CAN_RAM_MOVE_DONE_INT_FLAG: This bit is set to 1 when data move from register to CAN IP internal RAM finished.
 *     \arg CAN_BUS_OFF_INT_FLAG: This bit is set to 1 when the state of bus is off.
 *     \arg CAN_WAKE_UP_INT_FLAG: This bit is set to 1 when CAN awakened from low power mode.
 *     \arg CAN_ERROR_INT_FLAG: This bit is set to 1 when there is an error during transmission.
 *     \arg CAN_RX_INT_FLAG: This bit is set to 1 when data is received.
 *     \arg CAN_TX_INT_FLAG: This bit is set to 1 when sending is completed.
 * \return The new state of CAN_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void CAN_Handler(void)
 * {
 *     if (SET == CAN_GetINTStatus(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG))
 *  {
 *      DBG_DIRECT("[CAN] CAN_Handler CAN_RAM_MOVE_DONE_INT_FLAG");
 *      CAN_ClearINTPendingBit(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG);
 *  }
 * }
 * \endcode
 */
ITStatus CAN_GetINTStatus(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG);
/**
 * \brief  Clear the CAN interrupt pending bit.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_INT_FLAG: Specifies the interrupt pending bit to clear.
 *     This parameter can be any combination of the following values:
 *     \arg CAN_RAM_MOVE_DONE_INT_FLAG: This bit is set to 1 when data move from register to CAN IP internal RAM finished.
 *     \arg CAN_BUS_OFF_INT_FLAG: This bit is set to 1 when the state of bus is off.
 *     \arg CAN_WAKE_UP_INT_FLAG: This bit is set to 1 when CAN awakened from low power mode.
 *     \arg CAN_ERROR_INT_FLAG: This bit is set to 1 when there is an error during transmission.
 *     \arg CAN_RX_INT_FLAG: This bit is set to 1 when data is received.
 *     \arg CAN_TX_INT_FLAG: This bit is set to 1 when sending is completed.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void CAN_Handler(void)
 * {
 *     if (SET == CAN_GetINTStatus(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG))
 *     {
 *      DBG_DIRECT("[CAN] CAN_Handler CAN_RAM_MOVE_DONE_INT_FLAG");
 *      CAN_ClearINTPendingBit(CAN0, CAN_RAM_MOVE_DONE_INT_FLAG);
 *     }
 * }
 * \endcode
 */
void CAN_ClearINTPendingBit(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG);
/**
 * \brief  Gets the specified CAN error status.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  CAN_ERR_STAT: the specified CAN error.
 *     This parameter can be one of the following values:
 *     \arg CAN_ERROR_RX: This bit is set to 1 when an error occurred during the receiving process.
 *     \arg CAN_ERROR_TX: This bit is set to 1 when an error occurred during the sending process.
 *     \arg CAN_ERROR_ACK: This bit is set to 1 when the latest error is ack error.
 *     \arg CAN_ERROR_STUFF: This bit is set to 1 when the latest error is stuff error.
 *     \arg CAN_ERROR_CRC: This bit is set to 1 when the latest error is crc error.
 *     \arg CAN_ERROR_FORM: This bit is set to 1 when the latest error is form error.
 *     \arg CAN_ERROR_BIT1: This bit is set to 1 when the latest error is bit error, tx=1 but rx=0.
 *     \arg CAN_ERROR_BIT0: This bit is set to 1 when the latest error is bit error, tx=0 but rx=1.
 * \return The new state of CAN_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void CAN_Handler(void)
 * {
 *     if (SET == CAN_GetErrorStatus(CAN0, CAN_ERROR_TX))
 *     {
 *          DBG_DIRECT("[CAN] CAN_ERROR_TX");
 *          CAN_CLearErrorStatus(CAN0, CAN_ERROR_TX);
 *     }
 * }
 * \endcode
 */
FlagStatus CAN_GetErrorStatus(CAN_TypeDef *CANx, uint32_t CAN_ERR_STAT);
/**
 * \brief  Clears the specified CAN error status.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  CAN_ERR_STAT: the specified CAN error.
 *     This parameter can be one of the following values:
 *     \arg CAN_ERROR_RX: This bit is set to 1 when an error occurred during the receiving process.
 *     \arg CAN_ERROR_TX: This bit is set to 1 when an error occurred during the sending process.
 *     \arg CAN_ERROR_ACK: This bit is set to 1 when the latest error is ack error.
 *     \arg CAN_ERROR_STUFF: This bit is set to 1 when the latest error is stuff error.
 *     \arg CAN_ERROR_CRC: This bit is set to 1 when the latest error is crc error.
 *     \arg CAN_ERROR_FORM: This bit is set to 1 when the latest error is form error.
 *     \arg CAN_ERROR_BIT1: This bit is set to 1 when the latest error is bit error, tx=1 but rx=0.
 *     \arg CAN_ERROR_BIT0: This bit is set to 1 when the latest error is bit error, tx=0 but rx=1.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void CAN_Handler(void)
 * {
 *     if (SET == CAN_GetErrorStatus(CAN0, CAN_ERROR_TX))
 *     {
 *          DBG_DIRECT("[CAN] CAN_ERROR_TX");
 *          CAN_CLearErrorStatus(CAN0, CAN_ERROR_TX);
 *     }
 * }
 * \endcode
 */
void CAN_CLearErrorStatus(CAN_TypeDef *CANx, uint32_t CAN_ERR_STAT);
/**
 * \brief  Sets the CAN message buffer Tx mode.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  p_tx_frame_params: the CAN frame parameter.
 * \param[in]  p_frame_data: the specified CAN data.
 * \param[in]  data_len: the length of CAN data to be sent.
 * \return the state of set buffer @ref CANError_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_basic_tx(uint32_t buf_id, CANDataFrameSel_TypeDef frame_type, \
 *                        uint16_t frame_id, uint32_t ext_id, uint8_t *tx_data, uint8_t data_len)
 * {
 *
 *   CANError_TypeDef tx_error;
 *
 *   CANTxFrame_TypeDef tx_frame_type;
 *
 *   tx_frame_type.msg_buf_id = buf_id;
 *   tx_frame_type.frame_type = frame_type;
 *   tx_frame_type.standard_frame_id = frame_id;
 *   tx_frame_type.auto_reply_bit = DISABLE;
 *   tx_frame_type.extend_frame_id = 0;
 *
 *   switch (frame_type)
 *   {
 *   case CAN_EXT_DATA_FRAME:
 *   case CAN_EXT_REMOTE_FRAME:
 *       tx_frame_type.extend_frame_id = ext_id;
 *   case CAN_STD_DATA_FRAME:
 *   case CAN_STD_REMOTE_FRAME:
 *       break;
 *       break;
 *   }
 *
 *   CAN_MBTxINTConfig(CAN0, tx_frame_type.msg_buf_id, ENABLE);
 *   tx_error = CAN_SetMsgBufTxMode(CAN0, &tx_frame_type, tx_data, data_len);
 *
 *   while (CAN_GetRamState(CAN0) != CAN_RAM_STATE_IDLE);
 *
 *   if (tx_error != CAN_NO_ERR)
 *   {
 *       IO_PRINT_INFO1("can_basic_tx: tx error %d", tx_error);
 *   }
 *  }
 * \endcode
 */
CANError_TypeDef CAN_SetMsgBufTxMode(CAN_TypeDef *CANx, CANTxFrame_TypeDef *p_tx_frame_params,
                                     const uint8_t *p_frame_data,
                                     uint8_t data_len);
/**
 * \brief  Sets the CAN message buffer Rx mode.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  p_rx_frame_params: the CAN frame parameter.
 * \return the state of set buffer @ref CANError_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_basic_rx(void)
 * {
 *     CANError_TypeDef rx_error;
 *     CANRxFrame_TypeDef rx_frame_type;
 *     rx_frame_type.msg_buf_id = 7;
 *
 *     rx_frame_type.extend_frame_id = 0;
 *     rx_frame_type.standard_frame_id = 0;
 *     rx_frame_type.frame_rtr_mask = CAN_RX_FRAME_MASK_RTR;
 *     rx_frame_type.frame_ide_mask = CAN_RX_FRAME_MASK_IDE;
 *     rx_frame_type.frame_id_mask = CAN_RX_FRAME_MASK_ID;
 *     rx_frame_type.rx_dma_en = RESET;
 *     rx_frame_type.auto_reply_bit = RESET;
 *     rx_error = CAN_SetMsgBufRxMode(CAN0, &rx_frame_type);
 *
 *     CAN_MBRxINTConfig(CAN0, rx_frame_type.msg_buf_id, ENABLE);
 *
 *     while (CAN_GetRamState(CAN0) != CAN_RAM_STATE_IDLE);
 *
 *     if (rx_error != CAN_NO_ERR)
 *     {
 *         IO_PRINT_INFO1("can_basic_rx: rx error %d", rx_error);
 *     }
 *
 *     IO_PRINT_INFO0("can_basic_rx: waiting for rx...");
 * }
 * \endcode
 */
CANError_TypeDef CAN_SetMsgBufRxMode(CAN_TypeDef *CANx, CANRxFrame_TypeDef *p_rx_frame_params);
/**
 * \brief  Gets message buffer information.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  msg_buf_id: message buffer id.
 * \param[out] p_mb_info: message buffer information.
 * \return the state of get buffer information @ref CANError_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_msg_info(void)
 * {
 *     uint8_t index = 0
 *     uint8_t rx_data[64];
 *     CANMsgBufInfo_TypeDef mb_info;
 *     CAN_GetMsgBufInfo(CAN0, index, &mb_info);
 *     CAN_GetRamData(CAN0, mb_info.data_length, rx_data);
 * }
 * \endcode
 */
CANError_TypeDef CAN_GetMsgBufInfo(CAN_TypeDef *CANx, uint8_t msg_buf_id,
                                   CANMsgBufInfo_TypeDef *p_mb_info);
/**
 * \brief  Gets the RAM data of message buffer.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  data_len: the length of RAM data.
 * \param[out] p_data: data buffer to be received.
 * \return the state of get RAM data @ref CANError_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_ram_data(void)
 * {
 *     uint8_t index = 0
 *     uint8_t rx_data[64];
 *     CANMsgBufInfo_TypeDef mb_info;
 *     CAN_GetMsgBufInfo(CAN0, index, &mb_info);
 *     CAN_GetRamData(CAN0, mb_info.data_length, rx_data);
 * }
 * \endcode
 */
CANError_TypeDef CAN_GetRamData(CAN_TypeDef *CANx, uint8_t data_len, uint8_t *p_data);
/**
 * \brief  Check the type of frame.
 * \param[in]  rtr_bit.
 * \param[in]  ide_bit.
 * \param[in]  edl_bit.
 * \return the type of frame @ref CANDataFrameSel_TypeDef.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_ram_data(void)
 * {
 *     uint8_t index = 0
 *     uint8_t rx_data[64];
 *     CANMsgBufInfo_TypeDef mb_info;
 *     CAN_GetMsgBufInfo(CAN0, index, &mb_info);
 *     CANDataFrameSel_TypeDef frame_type = CAN_CheckFrameType(mb_info.rtr_bit, mb_info.ide_bit);
 * }
 * \endcode
 */
CANDataFrameSel_TypeDef CAN_CheckFrameType(uint8_t rtr_bit, uint8_t ide_bit);
/**
 * \brief  Config message buffer tx interrupt.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \param[in]  newState: the tx state of message buffer.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_basic_tx(uint32_t buf_id, CANDataFrameSel_TypeDef frame_type, \
 *                        uint16_t frame_id, uint32_t ext_id, uint8_t *tx_data, uint8_t data_len)
 * {
 *
 *   CANError_TypeDef tx_error;
 *
 *   CANTxFrame_TypeDef tx_frame_type;
 *
 *   tx_frame_type.msg_buf_id = buf_id;
 *   tx_frame_type.frame_type = frame_type;
 *   tx_frame_type.standard_frame_id = frame_id;
 *   tx_frame_type.auto_reply_bit = DISABLE;
 *   tx_frame_type.extend_frame_id = 0;
 *
 *   switch (frame_type)
 *   {
 *   case CAN_EXT_DATA_FRAME:
 *   case CAN_EXT_REMOTE_FRAME:
 *       tx_frame_type.extend_frame_id = ext_id;
 *   case CAN_STD_DATA_FRAME:
 *   case CAN_STD_REMOTE_FRAME:
 *       break;
 *       break;
 *   }
 *
 *   CAN_MBTxINTConfig(CAN0, tx_frame_type.msg_buf_id, ENABLE);
 *   tx_error = CAN_SetMsgBufTxMode(CAN0, &tx_frame_type, tx_data, data_len);
 *
 *   while (CAN_GetRamState(CAN0) != CAN_RAM_STATE_IDLE);
 *
 *   if (tx_error != CAN_NO_ERR)
 *   {
 *       IO_PRINT_INFO1("can_basic_tx: tx error %d", tx_error);
 *   }
 *  }
 * \endcode
 */
void CAN_MBTxINTConfig(CAN_TypeDef *CANx, uint8_t message_buffer_index, FunctionalState newState);
/**
 * \brief  Config message buffer rx interrupt.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \param[in]  newState: the rx state of message buffer.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_basic_rx(void)
 * {
 *     CANError_TypeDef rx_error;
 *     CANRxFrame_TypeDef rx_frame_type;
 *     rx_frame_type.msg_buf_id = 7;
 *
 *     rx_frame_type.extend_frame_id = 0;
 *     rx_frame_type.standard_frame_id = 0;
 *     rx_frame_type.frame_rtr_mask = CAN_RX_FRAME_MASK_RTR;
 *     rx_frame_type.frame_ide_mask = CAN_RX_FRAME_MASK_IDE;
 *     rx_frame_type.frame_id_mask = CAN_RX_FRAME_MASK_ID;
 *     rx_frame_type.rx_dma_en = RESET;
 *     rx_frame_type.auto_reply_bit = RESET;
 *     rx_error = CAN_SetMsgBufRxMode(CAN0, &rx_frame_type);
 *
 *     CAN_MBRxINTConfig(CAN0, rx_frame_type.msg_buf_id, ENABLE);
 *
 *     while (CAN_GetRamState(CAN0) != CAN_RAM_STATE_IDLE);
 *
 *     if (rx_error != CAN_NO_ERR)
 *     {
 *         IO_PRINT_INFO1("can_basic_rx: rx error %d", rx_error);
 *     }
 *
 *     IO_PRINT_INFO0("can_basic_rx: waiting for rx...");
 * }
 * \endcode
 */
void CAN_MBRxINTConfig(CAN_TypeDef *CANx, uint8_t message_buffer_index, FunctionalState newState);
/**
 * \brief  Gets CAN FIFO status.
 * \param[in] CANx: selected CAN peripheral.
 * \param[out]  CAN_FifoStatus: the status of CAN FIFO.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_fifo_status(void)
 * {
 *     CANFifoStatus_TypeDef fifo_status;
 *     CAN_GetFifoStatus(CAN0, &fifo_status);
 * }
 * \endcode
 */
void CAN_GetFifoStatus(CAN_TypeDef *CANx, CANFifoStatus_TypeDef *CAN_FifoStatus);
/**
 * \brief  Sets tx message trigger by timestamp timer.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  newState: the state of tx trigger.
 * \param[in]  trigger_timestamp_begin: end of trigger time.
 * \param[in]  close_offset: start of trigger time.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_tx_trigger(void)
 * {
 *     uint16_t begin_ts = CAN_GetTimeStampCount(CAN0);
 *     begin_ts += 1000;
 *     CAN_TxTriggerConfig(CAN0, ENABLE, begin_ts, 100);
 * }
 * \endcode
 */
void CAN_TxTriggerConfig(CAN_TypeDef *CANx, FunctionalState newState,
                         uint16_t trigger_timestamp_begin,
                         uint16_t close_offset);
/**
 * \brief  Get can bus state.
 * \param[in] CANx: selected CAN peripheral.
 * \return The state of bus(CAN_BUS_STATE_ON or CAN_BUS_STATE_OFF).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_bus_state(void)
 * {
 *     while (CAN_GetBusState(CAN0) != CAN_BUS_STATE_ON);
 * }
 * \endcode
 */
uint32_t CAN_GetBusState(CAN_TypeDef *CANx);
/**
 * \brief  Get message buffer ram state.
 * \param[in] CANx: selected CAN peripheral.
 * \return The state of message buffer ram(CAN_RAM_STATE_EXCHANGING or CAN_RAM_STATE_IDLE).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_ram_state(void)
 * {
 *     while (CAN_GetRamState(CAN0) != CAN_RAM_STATE_IDLE);
 * }
 * \endcode
 */
uint32_t CAN_GetRamState(CAN_TypeDef *CANx);
/**
 * \brief  Get message buffer tx done flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer tx done.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_done_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnTxDoneFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: MB_%d tx done", index);
 *              CAN_ClearMBnTxDoneFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnTxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Clear message buffer tx done flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_done_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnTxDoneFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: MB_%d tx done", index);
 *              CAN_ClearMBnTxDoneFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
void CAN_ClearMBnTxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer tx error flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer tx error.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_error_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnTxErrorFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: CAN ERROR TX MB_%d", index);
 *              CAN_ClearMBnTxErrorFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnTxErrorFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Clear message buffer tx error flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_error_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnTxErrorFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: CAN ERROR TX MB_%d", index);
 *              CAN_ClearMBnTxErrorFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
void CAN_ClearMBnTxErrorFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer tx finish flag, it indicates the tx message in the message buffer finish sending.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer tx finish.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_finish_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnStatusTxFinishFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_get_tx_finish_flag: TX finish MB_%d", index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnStatusTxFinishFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer tx request flag, it indicates the tx message in buffer is pending for transmit.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer tx request.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_tx_req_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnStatusTxReqFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_get_tx_req_flag: TX pending MB_%d", index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnStatusTxReqFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer rx done flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer rx done.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_rx_done_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnRxDoneFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: MB_%d rx done", index);
 *              CAN_ClearMBnRxDoneFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnRxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Clear message buffer rx done flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_clear_rx_done_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnRxDoneFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_trx_handler: MB_%d rx done", index);
 *              CAN_ClearMBnRxDoneFlag(CAN0, index);
 *          }
 *      }
 * }
 * \endcode
 */
void CAN_ClearMBnRxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer rx valid flag, it indicates new message has been received in the message buffer.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer rx valid.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_rx_valid_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnStatusRxValidFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_get_rx_valid_flag: MB_%d rx valid", index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnStatusRxValidFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Get message buffer rx ready flag, it indicates the message buffer is ready for receiving a new message.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer rx ready.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_rx_ready_flag(void)
 * {
 *     for (uint8_t index = 0; index < CAN_MESSAGE_BUFFER_MAX_CNT; index++)
 *     {
 *          if (SET == CAN_GetMBnStatusRxReadyFlag(CAN0, index))
 *          {
 *              IO_PRINT_INFO1("can_get_rx_ready_flag: MB_%d rx ready", index);
 *          }
 *      }
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnStatusRxReadyFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Enable or disable can time stamp.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  newState: New state of the time stamp.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_enable_timestamp(void)
 * {
 *     CAN_TimeStampConfig(CAN0, ENABLE);
 * }
 * \endcode
 */
void CAN_TimeStampConfig(CAN_TypeDef *CANx, FunctionalState newState);
/**
 * \brief  Get time stamp count.
 * \param[in] CANx: selected CAN peripheral.
 * \return Time stamp count.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_timestamp(void)
 * {
 *     uint16_t begin_ts = CAN_GetTimeStampCount(CAN0);
 * }
 * \endcode
 */
uint16_t CAN_GetTimeStampCount(CAN_TypeDef *CANx);
/**
 * \brief  Get rx dma block size(word).
 * \param[in] CANx: selected CAN peripheral.
 * \return Rx dma block size.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_dma_msize(void)
 * {
 *     uint32_t dma_buffer_size = CAN_GetRxDMAMsize(CAN0);
 * }
 * \endcode
 */
uint32_t CAN_GetRxDMAMsize(CAN_TypeDef *CANx);
/**
 * \brief  Get message buffer rx dma enable flag.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \return The flag of message buffer rx dma enable.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_rx_dma_enable_flag(void)
 * {
 *     FlagStatus dma_en_flag = CAN_GetMBnRxDMAEnFlag(CAN0, index);
 * }
 * \endcode
 */
FlagStatus CAN_GetMBnRxDMAEnFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index);
/**
 * \brief  Set message buffer rx dma enable.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  message_buffer_index: CAN message buffer index.
 * \param[in]  newState: New state of the message buffer rx dma enable.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_set_rx_dma_enable(void)
 * {
 *     CAN_SetMBnRxDMAEnFlag(CAN0, RX_DMA_BUF_ID, ENABLE);
 * }
 * \endcode
 */
void CAN_SetMBnRxDMAEnFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index,
                           FunctionalState newState);

/**
 * \brief  Config CAN clock source div.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in]  div: CAN clock div @ref CANClockDiv_TypeDef.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_config_clock(void)
 * {
 *     CAN_SetClockDiv(CAN0, CAN_CLK_DIV_1);
 * }
 * \endcode
 */
void CAN_SetClockDiv(CAN_TypeDef *CANx, CANClockDiv_TypeDef div);

/**
 * \brief  Get CAN clock source.
 * \param[out]  ClockSrc: CAN clock src.
 * \param[out]  ClockDiv: CAN clock div.
 * \return The status of get clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_get_clock(void)
 * {
 *     CANClockSrc_TypeDef clk_src;
 *     CANClockDiv_TypeDef clk_div;
 *     CAN_GetClock(CAN0, &clk_src, &clk_div);
 * }
 * \endcode
 */
bool CAN_GetClock(CAN_TypeDef *CANx, CANClockSrc_TypeDef *ClockSrc, CANClockDiv_TypeDef *ClockDiv);

/**
 * \brief  Set test mode.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_TestModeSel: Test mode to set @ref CANTestModeSel_TypeDef.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_set_test_mode(void)
 * {
 *     CAN_SetTestMode(CAN0, CAN_TEST_MODE_NONE);
 * }
 * \endcode
 */
void CAN_SetTestMode(CAN_TypeDef *CANx, uint8_t CAN_TestModeSel);

/**
 * \brief  Enable or disable CAN auto-re-tx function.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] newState: the state of CAN auto-re-tx function.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_enable_auto_retx(void)
 * {
 *     CAN_AutoReTxCmd(CAN0, ENABLE);
 * }
 * \endcode
 */
void CAN_AutoReTxCmd(CAN_TypeDef *CANx, FunctionalState NewState);

/**
 * \brief  Set can bit timing.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] CAN_BitTiming:  Pointer to a CAN_0x0C_TYPE_TypeDef structure that
 *            contains the bit timing information for the specified CAN peripheral.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_set_timing(void)
 * {
 *     CAN_0x0C_TYPE_TypeDef CAN_BitTiming;
 *     CAN_BitTiming.can_brp = 7;
 *     CAN_BitTiming.can_sjw = 3;
 *     CAN_BitTiming.can_tseg1 = 4;
 *     CAN_BitTiming.can_tseg2 = 3;
 *     CAN_SetTiming(CAN0, &CAN_BitTiming);
 * }
 * \endcode
 */
void CAN_SetTiming(CAN_TypeDef *CANx, CAN_0x0C_TYPE_TypeDef *CAN_BitTiming);

/**
 * \brief  Get error passive status.
 * \param[in] CANx: selected CAN peripheral.
 * \return The flag of error passive status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static FlagStatus can_get_error_passive_status(void)
 * {
 *     return CAN_GetErrorPassiveStatus(CAN0);
 * }
 * \endcode
 */
FlagStatus CAN_GetErrorPassiveStatus(CAN_TypeDef *CANx);

/**
 * \brief  Get error warning status.
 * \param[in] CANx: selected CAN peripheral.
 * \return The flag of error warning status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static FlagStatus can_get_error_warning_status(void)
 * {
 *     return CAN_GetErrorWarningStatus(CAN0);
 * }
 * \endcode
 */
FlagStatus CAN_GetErrorWarningStatus(CAN_TypeDef *CANx);

/**
 * \brief  Get tx error counter.
 * \param[in] CANx: selected CAN peripheral.
 * \return The counter of tx error.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static int can_get_tx_error_cnt(void)
 * {
 *     return CAN_GetTxErrorCnt(CAN0);
 * }
 * \endcode
 */
int CAN_GetTxErrorCnt(CAN_TypeDef *CANx);

/**
 * \brief  Get rx error counter.
 * \param[in] CANx: selected CAN peripheral.
 * \return The counter of rx error.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static int can_get_rx_error_cnt(void)
 * {
 *     return CAN_GetRxErrorCnt(CAN0);
 * }
 * \endcode
 */
int CAN_GetRxErrorCnt(CAN_TypeDef *CANx);

#if (CAN_SUPPORT_SLEEP_MODE == 1)
/**
 * \brief  Check CAN sleep state.
 * \param[in] CANx: selected CAN peripheral.
 * \return The flag of CAN sleep state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_check_sleep_status(void)
 * {
 *     FlagStatus status = CAN_CheckSleepStatus(CAN0);
 * }
 * \endcode
 */
FlagStatus CAN_CheckSleepStatus(CAN_TypeDef *CANx);

/**
 * \brief  Enable or disable CAN lower power clock.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] newState: Enable or disable CAN lower power clock.
 * \param[in] div: Low power clock div @ref CANLowPowerClkDIV_TypeDef.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_enable_lower_power_clk(void)
 * {
 *     CAN_LowPowerClkCmd(CAN0, ENABLE, CAN_LOW_CLK_DIV_5);
 *     CAN_SetWakeUpPinFltFunction(CAN0, ENABLE, 10);
 *     CAN_RequestToSleepMode(CAN0);
 * }
 * \endcode
 */
void CAN_LowPowerClkCmd(CAN_TypeDef *CANx, FunctionalState newState, CANLowPowerClkDIV_TypeDef div);

/**
 * \brief  Config wake up pin fit function.
 * \param[in] CANx: selected CAN peripheral.
 * \param[in] newState: Enable or disable CAN wake up pin fit function.
 * \param[in] flt_length: Config wake up pin fit length.
 *                        minimu value is 1. The unit is low power clock period.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_config_wake_up_pin(void)
 * {
 *     CAN_LowPowerClkCmd(CAN0, ENABLE, CAN_LOW_CLK_DIV_5);
 *     CAN_SetWakeUpPinFltFunction(CAN0, ENABLE, 10);
 *     CAN_RequestToSleepMode(CAN0);
 * }
 * \endcode
 */
void CAN_SetWakeUpPinFltFunction(CAN_TypeDef *CANx, FunctionalState newState, uint8_t flt_length);
/**
 * \brief  Request CAN to sleep mode.
 * \param[in] CANx: selected CAN peripheral.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_request_sleep(void)
 * {
 *     CAN_LowPowerClkCmd(CAN0, ENABLE, CAN_LOW_CLK_DIV_5);
 *     CAN_SetWakeUpPinFltFunction(CAN0, ENABLE, 10);
 *     CAN_RequestToSleepMode(CAN0);
 * }
 * \endcode
 */
void CAN_RequestToSleepMode(CAN_TypeDef *CANx);

/**
 * \brief  Manual wake up CAN.
 * \param[in] CANx: selected CAN peripheral.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * static void can_manual_wake_up(void)
 * {
 *     CAN_ManualWakeup(CAN0);
 * }
 * \endcode
 */
void CAN_ManualWakeup(CAN_TypeDef *CANx);
#endif

#if (CAN_SUPPORT_AUTO_CLOCK == 1)

void CAN_ClockAutoModeCmd(CAN_TypeDef *CANx, FunctionalState Newstate);

#endif

/** End of CAN_Exported_Functions
  * \}
  */
/** End of CAN
  * \}
  */
#ifdef __cplusplus
}
#endif
#endif /* _RTL_CAN_H_ */


