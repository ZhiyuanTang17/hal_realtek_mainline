/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_ir.h
* \brief    The header file of the peripheral IR driver.
* \details  This file provides all IR firmware functions.
* \author   yuzhuo_liu
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_IR_H
#define RTL_IR_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "ir/src/rtl87x2g/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "ir/src/rtl87x3e/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "ir/src/rtl87x3d/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "ir/src/rtl87x2j/rtl_ir_def.h"
#endif

/** \defgroup IR          IR
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup IR_Exported_Constants IR Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    IR_FIFO_Size IR FIFO Size
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_TX_FIFO_SIZE                   32
#define IR_RX_FIFO_SIZE                   32

/** End of IR_FIFO_Size
  * \}
  */

/**
 * \defgroup    IR_Mode IR Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_MODE_TX = 0x00,
    IR_MODE_RX = 0x01,
} IRMode_TypeDef;

#define IS_IR_MODE(MODE) (((MODE) == IR_MODE_TX) || ((MODE) == IR_MODE_RX))

/** End of IR_Mode
  * \}
  */

/**
 * \defgroup    IR_Idle_Status IR Idle Status
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_IDLE_OUTPUT_LOW = 0x00,
    IR_IDLE_OUTPUT_HIGH = 0x01,
} IRIdleStatus_TypeDef;

#define IS_IR_IDLE_STATUS(LEVEL) (((LEVEL) == IR_IDLE_OUTPUT_HIGH) || ((LEVEL) == IR_IDLE_OUTPUT_LOW))

/** End of IR_Idle_Status
  * \}
  */

/**
 * \defgroup    IR_TX_Data_Type IR TX Data Type
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_TX_DATA_NORMAL = 0x00,
    IR_TX_DATA_INVERSE = 0x01,
} IRTxDataType_TypeDef;

#define IS_IR_TX_DATA_TYPE(TYPE) (((TYPE) == IR_TX_DATA_NORMAL) || ((TYPE) == IR_TX_DATA_INVERSE))

/** End of IR_TX_Data_Type
  * \}
  */

/**
 * \defgroup    IR_Threshold IR Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_TX_THRESHOLD(THD)  ((THD) <= IR_TX_FIFO_SIZE)
#define IS_IR_RX_THRESHOLD(THD) ((THD) <= IR_RX_FIFO_SIZE)

/** End of IR_Threshold
  * \}
  */

/**
 * \defgroup    IR_RX_Start_Mode IR RX Start Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_RX_MANUAL_MODE = 0x00,
    IR_RX_AUTO_MODE = 0x01,
} IRRxStartMode_TypeDef;

#define IS_RX_START_MODE(MODE) (((MODE) == IR_RX_AUTO_MODE) || ((MODE) == IR_RX_MANUAL_MODE))

/** End of RX_Start_Mode
  * \}
  */

/**
 * \defgroup    IR_RX_FIFO_Discard_Setting IR RX FIFO Discard Setting
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_RX_FIFO_FULL_DISCARD_NEWEST = 0x00,
    IR_RX_FIFO_FULL_DISCARD_OLDEST = 0x01,
} IRRxFifoDiscardSetting_TypeDef;

#define IS_IR_RX_FIFO_FULL_CTRL(CTRL)  (((CTRL) == IR_RX_FIFO_FULL_DISCARD_NEWEST) || ((CTRL) == IR_RX_FIFO_FULL_DISCARD_OLDEST))

/** End of IR_RX_FIFO_Discard_Setting
  * \}
  */

/**
 * \defgroup    IR_RX_Trigger_Mode IR RX Trigger Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_RX_FALL_EDGE = 0x00,
    IR_RX_RISING_EDGE = 0x01,
    IR_RX_DOUBLE_EDGE = 0x02,
} IRRxTriggerMode_TypeDef;

#define IS_RX_RX_TRIGGER_EDGE(EDGE) (((EDGE) == IR_RX_FALL_EDGE) || ((EDGE) == IR_RX_RISING_EDGE) || ((EDGE) == IR_RX_DOUBLE_EDGE))

/** End of RX_Trigger_Mode
  * \}
  */

/**
 * \defgroup    IR_RX_Filter_Time IR RX Filter Time
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_RX_FILTER_TIME_50ns  = 0x00,
    IR_RX_FILTER_TIME_75ns  = 0x01,
    IR_RX_FILTER_TIME_100ns = 0x02,
    IR_RX_FILTER_TIME_125ns = 0x03,
    IR_RX_FILTER_TIME_150ns = 0x04,
    IR_RX_FILTER_TIME_175ns = 0x05,
    IR_RX_FILTER_TIME_200ns = 0x06,
    IR_RX_FILTER_TIME_225ns = 0x07,
} IRRxFilterTime_TypeDef;

#define IS_IR_RX_FILTER_TIME_CTRL(CTRL)  (((CTRL) == IR_RX_FILTER_TIME_50ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_75ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_100ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_125ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_150ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_175ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_200ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_225ns))

/** End of RX_Filter_Time
  * \}
  */

/**
 * \defgroup    IR_RX_Counter_Level IR RX Counter Level
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_RX_Count_Low_Level  = 0x00,
    IR_RX_Count_High_Level  = 0x01,
} IRRxCounterThresholdType_TypeDef;

#define IS_IR_RX_COUNT_LEVEL_CTRL(CTRL)  (((CTRL) == IR_RX_Count_Low_Level) || ((CTRL) == IR_RX_Count_High_Level))

/** End of IR_RX_Counter_Level
  * \}
  */

/**
 * \defgroup    IR_Compensation_Flag IR Compensation Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_COMPEN_FLAG_1_2_CARRIER = BIT28,
    IR_COMPEN_FLAG_1_4_CARRIER = BIT29,
    IR_COMPEN_FLAG_1_N_SYSTEM_CLK = BIT28 | BIT29,
} IRTxCompen_TypeDef;

/** End of IR_Compensation_Flag
  * \}
  */

#if IR_SUPPORT_TX_MODE_CONFIG
/**
 * \defgroup    IR_Compensation_Flag IR Compensation Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_TX_PUSH_PULL,
    IR_TX_OPEN_DRAIN,
} IRTxOutputMode_TypeDef;

/** End of IR_Compensation_Flag
  * \}
  */
#endif

/**
 * \defgroup    IR_RX_Counter_Threshold IR RX Counter Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_RX_COUNTER_THRESHOLD(THD) ((THD) <= 0x7fffffffUL)

/** End of IR_RX_Counter_Threshold
  * \}
  */

/**
 * \defgroup    IR_Interrupt IR Interrupt
 * \{
 * \ingroup     IR_Exported_Constants
 */
/* All interrupts in transmission mode */
#define IR_INT_TF_EMPTY                             BIT0
#define IR_INT_TF_LEVEL                             BIT1
#define IR_INT_TF_OF                                BIT4
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH                            BIT5
#endif

/* All interrupts in receiving mode */
#define IR_INT_RF_FULL                              BIT0
#define IR_INT_RF_LEVEL                             BIT1
#define IR_INT_RX_CNT_OF                            BIT2
#define IR_INT_RF_OF                                BIT3
#define IR_INT_RX_CNT_THR                           BIT4
#define IR_INT_RF_ERROR                             BIT5
#define IR_INT_RISING_EDGE                          ((uint32_t)(IR_RX_EXTENSION_INT | BIT1))
#define IR_INT_FALLING_EDGE                         ((uint32_t)(IR_RX_EXTENSION_INT | BIT0))

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)      || \
                                       ((CONFIG) == IR_INT_TX_FINISH))
#else
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)))
#endif

#define IS_IR_RX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_RF_FULL)     || \
                                       ((CONFIG) == IR_INT_RF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_RX_CNT_OF)  || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RX_CNT_THR) || \
                                       ((CONFIG) == IR_INT_RF_ERROR)      || \
                                       ((CONFIG) == IR_INT_RISING_EDGE) || \
                                       ((CONFIG) == IR_INT_FALLING_EDGE))
#define IS_IR_INT_CONFIG(CONFIG)      (IS_IR_TX_INT_CONFIG(CONFIG) || IS_IR_RX_INT_CONFIG(CONFIG))

/** End of IR_Interrupt
  * \}
  */

/**
 * \defgroup    IR_Interrupts_Clear_Flag IR Interrupts Clear Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
/* Clear all interrupts in transmission mode */
#define IR_TF_CLR                                   BIT0
#define IR_INT_TF_EMPTY_CLR                         BIT1
#define IR_INT_TF_LEVEL_CLR                         BIT2
#define IR_INT_TF_OF_CLR                            BIT3
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH_CLR                        BIT4
#endif

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR    | \
                                            IR_INT_TX_FINISH_CLR)
#else
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR)
#endif

/* Clear all interrupts in receiving mode */
#define IR_INT_RF_FULL_CLR                         BIT0
#define IR_INT_RF_LEVEL_CLR                        BIT1
#define IR_INT_RX_CNT_OF_CLR                       BIT2
#define IR_INT_RF_OF_CLR                           BIT3
#define IR_INT_RX_CNT_THR_CLR                      BIT4
#define IR_INT_RF_ERROR_CLR                        BIT5
#define IR_INT_RX_FALLING_EDGE_CLR                 BIT6
#define IR_INT_RX_RISING_EDGE_CLR                  BIT7
#define IR_RF_CLR                                  BIT8

#define IR_RX_INT_ALL_CLR                (IR_INT_RF_FULL_CLR | IR_INT_RF_LEVEL_CLR | \
                                          IR_INT_RX_CNT_OF_CLR | IR_INT_RF_OF_CLR | \
                                          IR_INT_RX_CNT_THR_CLR | IR_INT_RF_ERROR_CLR | \
                                          IR_INT_RX_RISING_EDGE_CLR|IR_INT_RX_FALLING_EDGE_CLR)

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_TX_FINISH_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR))
#else
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR))
#endif

/** End of IR_Interrupts_Clear_Flag
  * \}
  */

/**
 * \defgroup    IR_Flag IR Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_FLAG_TF_EMPTY                       BIT15
#define IR_FLAG_TF_FULL                        BIT14
#define IR_FLAG_TX_RUN                         BIT4
#define IR_FLAG_RF_EMPTY                       BIT17
#define IR_FLAG_RF_FULL                        BIT16
#define IR_FLAG_RX_RUN                         BIT7

#define IS_IR_FLAG(FLAG)                (((FLAG) == IR_FLAG_TF_EMPTY) || ((FLAG) == IR_FLAG_TF_FULL) || \
                                         ((FLAG) == IR_FLAG_TX_RUN) || ((FLAG) == IR_FLAG_RF_EMPTY) || \
                                         ((FLAG) == IR_FLAG_RF_FULL) || ((FLAG) == IR_FLAG_RX_RUN))

/** End of IR_Flag
  * \}
  */

#if (IR_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    IR_Qactive_Force TIM Qactive Force
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_QACTIVE_ICG_PCLK = 0x0,
    IR_QACTIVE_FW_FORCE_SCLK = 0x1,
    IR_QACTIVE_FW_FORCE_PCLK = 0x2,
} IRQactive_TypeDef;

/** End of IR_Qactive_Force
  * \}
  */

/**
 * \defgroup    IR_Task TIM Task
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_TASK_START_RX = 0,
    IR_TASK_START_TX = 1,
} IRTask_TypeDef;

/** End of IR_Task
  * \}
  */
#endif

/**
 * \defgroup    IR_Immediate_Number IR Immediate Number
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_RX_EXTENSION_INT                         0x8000
#define IR_RX_MSK_TO_EN_Pos                         14
#define IR_TX_FIFO_OVER_MSK_TO_EN_Pos               1
#define IR_TX_MSK_TO_EN_Pos                         2
#define IR_TX_STATUS_TO_EN_Pos                      2

#define IR_DATA_TYPE_Msk                          BIT31
#define IR_TX_LAST_PACKEET_Msk                    BIT30

/** End of IR_Immediate_Number
  * \}
  */

/** End of IR_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup IR_Exported_Types IR Exported Types
  * \brief
  * \{
  */

/**
 * \brief       IR init structure definition.
 *
 * \ingroup     IR_Exported_Types
 */
typedef struct
{
    IRClock_TypeDef IR_Clock;                        /*!< Specifies the source clock frequency. */

    uint32_t IR_Freq;                                /*!< Specifies the clock frequency.
                                                          This parameter is IR carrier freqency whose unit is Hz. */

    float IR_DutyCycle;                              /*!< Specifies the IR duty cycle. */

    IRMode_TypeDef IR_Mode;                          /*!< Specifies the IR mode. */

    IRIdleStatus_TypeDef IR_TxIdleLevel;             /*!< Specifies the IR output level in Tx mode. */

    IRTxDataType_TypeDef
    IR_TxInverse;               /*!< Specifies inverse FIFO data or not in TX mode. */

    uint32_t IR_TxFIFOThrLevel;                      /*!< Specifies TX FIFO interrupt threshold in TX mode.
                                                          When TX FIFO depth <= threshold value, trigger interrupt.
                                                          This parameter can be a value of 1 ~ 32.
                                                          This parameter can be a value of \ref IR_Tx_Threshold. */

    IRRxStartMode_TypeDef IR_RxStartMode;            /*!< Specifies Start mode in RX mode. */

    uint32_t IR_RxFIFOThrLevel;                      /*!< Specifies RX FIFO interrupt threshold in RX mode.
                                                          When RX FIFO depth > threshold value, trigger interrupt.
                                                          This parameter can be a value of 1 ~ 32.
                                                          This parameter can be a value of \ref IR_Rx_Threshold. */

    IRRxFifoDiscardSetting_TypeDef IR_RxFIFOFullCtrl;        /*!< Specifies data discard mode
                                                                in RX mode when RX FIFO is full and receiving new data. */

    IRRxTriggerMode_TypeDef IR_RxTriggerMode;                 /*!< Specifies trigger in RX mode. */

    IRRxFilterTime_TypeDef IR_RxFilterTime;                   /*!< Specifies filter time in RX mode. */

    IRRxCounterThresholdType_TypeDef IR_RxCntThrType;        /*!< Specifies counter level type
                                                                when trigger IR_INT_RX_CNT_THR interrupt in RX mode. */

    uint32_t IR_RxCntThr;                                  /*!< Specifies counter threshold value
                                                                when trigger IR_INT_RX_CNT_THR interrupt in RX mode. */

    FunctionalState IR_TxDmaEn;                            /*!< Specifies the Tx dma mode.
                                                                This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_TxWaterLevel;                               /*!< Specifies the DMA tx water level.
                                                                This parameter must range from 0 to 32.*/

    FunctionalState IR_RxDmaEn;                            /*!< Specifies the Rx dma mode.
                                                                This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_RxWaterLevel;                               /*!< Specifies the DMA rx water level.
                                                                This parameter must range from 0 to 32.*/

#if IR_SUPPORT_TX_MODE_CONFIG
    IRTxOutputMode_TypeDef
    IR_TxOutputMode;                          /*!< Specifies the IR Tx output mode.
                                                                   This parameter can be a value of \ref IR_TxOutputMode. */
#endif
} IR_InitTypeDef;

/** End of IR_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup IR_Exported_Functions IR Exported Functions
  * \brief
  * \{
  */

/**
 * \brief Deinitializes the IR peripheral registers to their default values.
 *
 * \param[in] None.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     IR_DeInit();
 * }
 * \endcode
 */
void IR_DeInit(void);

/**
 * \brief   Initializes the IR peripheral according to the specified
 *          parameters in IR_InitStruct.
 *
 * \param[in] IR_InitStruct: Pointer to a IR_InitTypeDef structure that
 *            contains the configuration information for the specified IR peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = IR_RX_FIFO_THR_LEVEL;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50ns;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_Count_High_Level;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_Init(IR_InitTypeDef *IR_InitStruct);

/**
 * \brief  Fills each IR_InitStruct member with its default value.
 *
 * \param[in] IR_InitStruct: Pointer to an IR_InitTypeDef structure which will be initialized.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = IR_RX_FIFO_THR_LEVEL;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50ns;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_Count_High_Level;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct);

/**
 * \brief   Enable or disable the selected IR mode.
 *
 * \param[in] mode: Selected IR operation mode.
 *            This parameter can be one of the following values:
 *            \arg IR_MODE_TX: Transmission mode.
 *            \arg IR_MODE_RX: Receiving mode.
 * \param[in] NewState: New state of the operation mode.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = IR_RX_FIFO_THR_LEVEL;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50ns;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_Count_High_Level;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_Cmd(uint32_t mode, FunctionalState NewState);

/**
 * \brief Start trigger receive, only in manual receive mode.
 *
 * \param[in] None.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_StartManualRxTrigger();
 * }
 * \endcode
 */
void IR_StartManualRxTrigger(void);

/**
 * \brief   Config counter threshold value in receiving mode.You can use it to stop receiving IR data.
 *
 * \param[in] IR_RxCntThrType: Count threshold type.
 *            This parameter can be the following values:
 *            \arg IR_RX_Count_Low_Level: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 *            \arg IR_RX_Count_High_Level: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 * \param[in] IR_RxCntThr: Configure IR Rx counter threshold value which can be 0 to 0x7fffffffUL.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetRxCounterThreshold(IR_RX_Count_Low_Level, 0x100);
 * }
 * \endcode
 */
void IR_SetRxCounterThreshold(uint32_t IR_RxCntThrType, uint32_t IR_RxCntThr);

/**
 * \brief   Send data.
 *
 * \param[in] pBuf: Data buffer to send.
 * \param[in] len: Send data length.
 * \param[in] IsLastPacket: Is it the last package of data.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: The last data in IR packet and there is no continous data.In other words, an infrared data transmission is completed.
 *            \arg DISABLE: There is data to be transmitted continuously.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendBuf(data_buf, 68, DISABLE);
 * }
 * \endcode
 */
void IR_SendBuf(uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket);

/**
 * \brief  Send compensation data.
 *
 * \param[in] comp_type: Compensation data type.
 *            This parameter can be one of the following values:
 *            \arg IR_COMPEN_FLAG_1_2_CARRIER: 1/2 carrier freqency.
 *            \arg IR_COMPEN_FLAG_1_4_CARRIER: 1/4 carrier freqency.
 *            \arg IR_COMPEN_FLAG_1_N_SYSTEM_CLK: MOD((0x48[27:16]+0x00[11:0]), 4095)/40MHz.
 *            User can call function of IR_ConfigCompParam to configure 0x48[27:16].
 * \param[in] buf: Data buffer to send.
 * \param[in] length: Data length.
 * \param[in] IsLastPacket: Is it the last package of data.
 *            This parameter can be the following values:
 *            \arg ENABLE: The last data in IR packet and there is no continous data.In other words, an infrared data transmission is completed.
 *            \arg DISABLE: There is data to be transmitted continuously.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendCompenBuf(IR_COMPEN_FLAG_1_2_CARRIER, data_buf, 68, DISABLE);
 * }
 * \endcode
 */
void IR_SendCompenBuf(IRTxCompen_TypeDef comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket);

/**
 * \brief   Read data From RX FIO.
 *
 * \param[in] pBuf: Buffer address to receive data.
 * \param[in] length: Read data length.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_ReceiveBuf(data_buf, 68);
 * }
 * \endcode
 */
void IR_ReceiveBuf(uint32_t *pBuf, uint32_t length);

/**
 * \brief     Enables or disables the specified IR interrupt source.
 *
 * \param[in] IR_INT: Specifies the IR interrupt source to be enabled or disabled.
 *            This parameter can be oen of the following values:
 *            \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt source.
 *            \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt source.
 *            \arg IR_INT_TF_OF: TX FIFO overflow interrupt source.
 *            \arg IR_INT_RF_FULL: RX FIFO  full interrupt source.
 *            \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt source.
 *            \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt source.
 *            \arg IR_INT_RF_OF: RX FIFO overflow interrupt source.
 *            \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt source.
 *            \arg IR_INT_RF_ERROR: RX FIFO error read interrupt source. Trigger when RX FIFO empty and read RX FIFO.
 *            \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *            \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 * \param[in] NewState: New state of the specified IR interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_INTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * \endcode
 */
void IR_INTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 * \brief     Mask or unmask the specified IR interrupt source.
 *
 * \param[in] IR_INT: Specifies the IR interrupts sources to be mask or unmask.
 *            This parameter can be the following values:
 *            \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
 *            \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *            \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 * \param[in] NewState: New state of the specified IR interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_MaskINTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * \endcode
 */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 * \brief     Get the specified IR interrupt status.
 *
 * \param[in] IR_INT: The specified IR interrupts.
 *            This parameter can be one of the following values:
 *            \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
 *            \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *            \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 *
 * \return  The new state of IR_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     ITStatus int_status = IR_GetINTStatus(IR_INT_TF_EMPTY);
 * }
 * \endcode
 */
ITStatus IR_GetINTStatus(uint32_t IR_INT);

/**
 * \brief     Clear the IR interrupt pending bit.
 *
 * \param[in] IR_CLEAR_INT: specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            \arg IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *            \arg IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *            \arg IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *            \arg IR_INT_RF_FULL_CLR: Clear RX FIFO  full interrupt.
 *            \arg IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *            \arg IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *            \arg IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *            \arg IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
 *            \arg IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            \arg IR_INT_RX_RISING_EDGE_CLR: Clear RX Rising edge interrupt.
 *            \arg IR_INT_RX_FALLING_EDGE_CLR: Clear RX Falling edge interrupt.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearINTPendingBit(IR_INT_RX_CNT_OF_CLR);
 * }
 * \endcode
 */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT);

/**
 * \brief Get free size of TX FIFO.
 *
 * \param[in] None.
 *
 * \return The free size of TX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetTxFIFOFreeLen();
 * }
 * \endcode
 */
uint16_t IR_GetTxFIFOFreeLen(void);

/**
 * \brief Get data size in RX FIFO.
 *
 * \param[in] None.
 *
 * \return Current data size in RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetRxDataLen();
 * }
 * \endcode
 */
uint16_t IR_GetRxDataLen(void);

/**
 * \brief   Send one data.
 *
 * \param[in] data: Send data.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SendData(0x80000100);
 * }
 * \endcode
 */
void IR_SendData(uint32_t data);

/**
 * \brief Read one data.
 *
 * \param[in] None.
 *
 * \return Data which read from RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data = IR_ReceiveData();
 * }
 * \endcode
 */
uint32_t IR_ReceiveData(void);

/**
 * \brief  Set tx threshold, when TX FIFO depth <= threshold value trigger interrupt.
 *
 * \param[in] thd: Tx threshold.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetTxThreshold(30);
 * }
 * \endcode
 */
void IR_SetTxThreshold(uint8_t thd);

/**
 * \brief   Set tx threshold, when RX FIFO depth >= threshold value trigger interrupt.
 *
 * \param[in] thd: Rx threshold.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetRxThreshold(2);
 * }
 * \endcode
 */
void IR_SetRxThreshold(uint8_t thd);

/**
 * \brief Get IR RX current count.
 *
 * \param[in] None.
 *
 * \return Current counter.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t count = IR_GetRxCurrentCount();
 * }
 * \endcode
 */
uint32_t IR_GetRxCurrentCount(void);

/**
 * \brief Clear IR TX FIFO.
 *
 * \param[in] None.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearTxFIFO();
 * }
 * \endcode
 */
void IR_ClearTxFIFO(void);

/**
 * \brief Clear IR RX FIFO.
 *
 * \param[in] None.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_ClearRxFIFO(void);

/**
 * \brief Check whether the specified IR flag is set.
 *
 * \param[in] IR_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg IR_FLAG_TF_EMPTY: TX FIFO empty or not. If SET, TX FIFO is empty.
 *            \arg IR_FLAG_TF_FULL: TX FIFO full or not. If SET, TX FIFO is full.
 *            \arg IR_FLAG_TX_RUN: TX run or not. If SET, TX is running.
 *            \arg IR_FLAG_RF_EMPTY: RX FIFO empty or not. If SET, RX FIFO is empty.
 *            \arg IR_FLAG_RF_FULL: RX FIFO full or not. If SET, RX FIFO is full.
 *            \arg IR_FLAG_RX_RUN: RX run or not. If SET, RX is running.
 *
 * \return The new state of IR_FLAG (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     FlagStatus flag_status = IR_GetFlagStatus(IR_FLAG_TF_EMPTY);
 * }
 * \endcode
 */
FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG);

/**
 * \brief   Set or reset tx data inverse.
 *
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetTxInverse(ENABLE);
 * }
 * \endcode
 */
void IR_SetTxInverse(FunctionalState NewState);

/**
 * \brief  Enbale TX output inverse or not.
 *
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_TxOutputInverse(ENABLE);
 * }
 * \endcode
 */
void IR_TxOutputInverse(FunctionalState NewState);

/**
 * \brief Get IR RX Level.
 *
 * \param[in] None.
 *
 * \return Current Level.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t level = IR_GetRxCurrentLevel();
 * }
 * \endcode
 */
uint32_t IR_GetRxCurrentLevel(void);

/**
  * \brief  IR clock config.
  * \param[in]  ClockSrc: specifies the clock source to gates its clock.
  * \param[in]  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void IR_ClkConfig(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv);

/**
  * \brief  Get IR clock config.
  * \param[in]  ClockSrc: specifies the clock source to gates its clock.
  * \param[in]  ClockDiv: specifies the clock divide to gates its clock.
  * \return The status of get clock.
  */
bool IR_ClkGet(IRClockSrc_TypeDef *ClockSrc, IRClockDiv_TypeDef *ClockDiv);

#if (IR_SUPPORT_RAP_FUNCTION == 1)
void IR_RAPModeCmd(FunctionalState NewState);

void IR_RAPQactiveCtrl(uint32_t Qactive, FunctionalState NewState);

void IR_TaskTrigger(uint32_t Task);
#endif

/** End of IR_Exported_Functions
  * \}
  */

/** End of IR
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_IR_H */



/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

