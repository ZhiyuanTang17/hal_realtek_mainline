/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
#include "rtl_ir_def.h"

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
#define IR_TX_FIFO_SIZE                   32  //!< I2C TX FIFO SIZE is 32.
#define IR_RX_FIFO_SIZE                   32  //!< I2C RX FIFO SIZE is 32.

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
    IR_MODE_TX = 0x00, //!< IR TX mode.
    IR_MODE_RX = 0x01, //!< IR RX mode.
} IRMode_TypeDef;

#define IS_IR_MODE(MODE) (((MODE) == IR_MODE_TX) || ((MODE) == IR_MODE_RX)) //!< Check if the input parameter is valid.

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
    IR_IDLE_OUTPUT_LOW = 0x00,  //!< TX output high level in idle.
    IR_IDLE_OUTPUT_HIGH = 0x01, //!< TX output low level in idle.
} IRIdleStatus_TypeDef;

#define IS_IR_IDLE_STATUS(LEVEL) (((LEVEL) == IR_IDLE_OUTPUT_HIGH) || ((LEVEL) == IR_IDLE_OUTPUT_LOW)) //!< Check if the input parameter is valid.

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
    IR_TX_DATA_NORMAL = 0x00,  //!< Not inverse TX FIFO define.
    IR_TX_DATA_INVERSE = 0x01, //!< Inverse TX FIFO define.
} IRTxDataType_TypeDef;

#define IS_IR_TX_DATA_TYPE(TYPE) (((TYPE) == IR_TX_DATA_NORMAL) || ((TYPE) == IR_TX_DATA_INVERSE)) //!< Check if the input parameter is valid.

/** End of IR_TX_Data_Type
  * \}
  */

/**
 * \defgroup    IR_Threshold IR Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_TX_THRESHOLD(THD)  ((THD) <= IR_TX_FIFO_SIZE) //!< IR TX Threshold must range from 0 to 32.
#define IS_IR_RX_THRESHOLD(THD) ((THD) <= IR_RX_FIFO_SIZE)  //!< IR RX Threshold must range from 0 to 32.

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
    IR_RX_MANUAL_MODE = 0x00, //!< Manual mode.
    IR_RX_AUTO_MODE = 0x01,   //!< Auto mode.
} IRRxStartMode_TypeDef;

#define IS_RX_START_MODE(MODE) (((MODE) == IR_RX_AUTO_MODE) || ((MODE) == IR_RX_MANUAL_MODE)) //!< Check if the input parameter is valid.

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
    IR_RX_FIFO_FULL_DISCARD_NEWEST = 0x00, //!< Discard oldest data in FIFO when RX FIFO is full and new data send to FIFO.
    IR_RX_FIFO_FULL_DISCARD_OLDEST = 0x01, //!< Reject new data data send to FIFO when RX FIFO is full.
} IRRxFifoDiscardSetting_TypeDef;

#define IS_IR_RX_FIFO_FULL_CTRL(CTRL)  (((CTRL) == IR_RX_FIFO_FULL_DISCARD_NEWEST) || ((CTRL) == IR_RX_FIFO_FULL_DISCARD_OLDEST)) //!< Check if the input parameter is valid.

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
    IR_RX_FALL_EDGE = 0x00,   //!< IR RX trigger mode is falling edge trigger.
    IR_RX_RISING_EDGE = 0x01, //!< IR RX trigger mode is rising edge trigger.
    IR_RX_DOUBLE_EDGE = 0x02, //!< IR RX trigger mode is double edge trigger.
} IRRxTriggerMode_TypeDef;

#define IS_RX_RX_TRIGGER_EDGE(EDGE) (((EDGE) == IR_RX_FALL_EDGE) || ((EDGE) == IR_RX_RISING_EDGE) || ((EDGE) == IR_RX_DOUBLE_EDGE)) //!< Check if the input parameter is valid.

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
    IR_RX_FILTER_TIME_50ns  = 0x00, //!< IR RX filter time is 50ns.
    IR_RX_FILTER_TIME_75ns  = 0x01, //!< IR RX filter time is 75ns.
    IR_RX_FILTER_TIME_100ns = 0x02, //!< IR RX filter time is 100ns.
    IR_RX_FILTER_TIME_125ns = 0x03, //!< IR RX filter time is 125ns.
    IR_RX_FILTER_TIME_150ns = 0x04, //!< IR RX filter time is 150ns.
    IR_RX_FILTER_TIME_175ns = 0x05, //!< IR RX filter time is 175ns.
    IR_RX_FILTER_TIME_200ns = 0x06, //!< IR RX filter time is 200ns.
    IR_RX_FILTER_TIME_225ns = 0x07, //!< IR RX filter time is 225ns.
} IRRxFilterTime_TypeDef;

#define IS_IR_RX_FILTER_TIME_CTRL(CTRL)  (((CTRL) == IR_RX_FILTER_TIME_50ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_75ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_100ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_125ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_150ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_175ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_200ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_225ns)) //!< Check if the input parameter is valid.

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
    IR_RX_Count_Low_Level  = 0x00,  //!< RX level timeout interrupt is low level trigger.
    IR_RX_Count_High_Level  = 0x01, //!< RX level timeout interrupt is high level trigger.
} IRRxCounterThresholdType_TypeDef;

#define IS_IR_RX_COUNT_LEVEL_CTRL(CTRL)  (((CTRL) == IR_RX_Count_Low_Level) || ((CTRL) == IR_RX_Count_High_Level)) //!< Check if the input parameter is valid.

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
    IR_COMPEN_FLAG_1_2_CARRIER = BIT28,            //!< 1/2 carrier cycle.
    IR_COMPEN_FLAG_1_4_CARRIER = BIT29,            //!< 1/4 carrier cycle.
    IR_COMPEN_FLAG_1_N_SYSTEM_CLK = BIT28 | BIT29, //!< 1/N carrier cycle.
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
#define IS_IR_RX_COUNTER_THRESHOLD(THD) ((THD) <= 0x7fffffffUL) //!< IR RX counter threshold value must range from 0x0 to 0x7FFFFFFF.

/** End of IR_RX_Counter_Threshold
  * \}
  */

/**
 * \defgroup    IR_Interrupt IR Interrupt
 * \{
 * \ingroup     IR_Exported_Constants
 */
/* All interrupts in transmission mode */
#define IR_INT_TF_EMPTY                             BIT0 //!< TX FIFO empty interrupt source.
#define IR_INT_TF_LEVEL                             BIT1 //!< TX FIFO threshold interrupt source.
#define IR_INT_TF_OF                                BIT4 //!< TX FIFO overflow interrupt source.
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH                            BIT5
#endif

/* All interrupts in receiving mode */
#define IR_INT_RF_FULL                              BIT0 //!< RX FIFO full interrupt source.
#define IR_INT_RF_LEVEL                             BIT1 //!< RX FIFO threshold interrupt source.
#define IR_INT_RX_CNT_OF                            BIT2 //!< RX counter overflow interrupt source.
#define IR_INT_RF_OF                                BIT3 //!< RX FIFO overflow interrupt source.
#define IR_INT_RX_CNT_THR                           BIT4 //!< RX counter timeout interrupt source.
#define IR_INT_RF_ERROR                             BIT5 //!< RX FIFO error read interrupt source. Trigger when RX FIFO empty and read RX FIFO.
#define IR_INT_RISING_EDGE                          ((uint32_t)(IR_RX_EXTENSION_INT | BIT1)) //!< RX rising edge interrupt source.
#define IR_INT_FALLING_EDGE                         ((uint32_t)(IR_RX_EXTENSION_INT | BIT0)) //!< RX falling edge interrupt source.

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)      || \
                                       ((CONFIG) == IR_INT_TX_FINISH)) //!< Check if the input parameter is valid.
#else
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF))) //!< Check if the input parameter is valid.
#endif

#define IS_IR_RX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_RF_FULL)     || \
                                       ((CONFIG) == IR_INT_RF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_RX_CNT_OF)  || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RX_CNT_THR) || \
                                       ((CONFIG) == IR_INT_RF_ERROR)      || \
                                       ((CONFIG) == IR_INT_RISING_EDGE) || \
                                       ((CONFIG) == IR_INT_FALLING_EDGE)) //!< Check if the input parameter is valid.
#define IS_IR_INT_CONFIG(CONFIG)      (IS_IR_TX_INT_CONFIG(CONFIG) || IS_IR_RX_INT_CONFIG(CONFIG)) //!< Check if the input parameter is valid.

/** End of IR_Interrupt
  * \}
  */

/**
 * \defgroup    IR_Interrupts_Clear_Flag IR Interrupts Clear Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
/* Clear all interrupts in transmission mode */
#define IR_TF_CLR                                   BIT0  //!< Clear TX FIFO interrupt status.
#define IR_INT_TF_EMPTY_CLR                         BIT1  //!< Clear TX FIFO empty interrupt status.
#define IR_INT_TF_LEVEL_CLR                         BIT2  //!< Clear TX FIFO threshold interrupt status.
#define IR_INT_TF_OF_CLR                            BIT3  //!< Clear TX FIFO overflow interrupt status.
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH_CLR                        BIT4
#endif

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR    | \
                                            IR_INT_TX_FINISH_CLR) //!< Check if the input parameter is valid.
#else
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR) //!< Check if the input parameter is valid.
#endif

/* Clear all interrupts in receiving mode */
#define IR_INT_RF_FULL_CLR                         BIT0  //!< Clear RX FIFO full interrupt status.
#define IR_INT_RF_LEVEL_CLR                        BIT1  //!< Clear RX FIFO threshold interrupt status.
#define IR_INT_RX_CNT_OF_CLR                       BIT2  //!< Clear RX counter overflow interrupt status.
#define IR_INT_RF_OF_CLR                           BIT3  //!< Clear RX FIFO overflow interrupt status.
#define IR_INT_RX_CNT_THR_CLR                      BIT4  //!< Clear RX counter timeout interrupt status.
#define IR_INT_RF_ERROR_CLR                        BIT5  //!< Clear RX FIFO error read interrupt status.
#define IR_INT_RX_FALLING_EDGE_CLR                 BIT6  //!< Clear RX falling edge interrupt status.
#define IR_INT_RX_RISING_EDGE_CLR                  BIT7  //!< Clear RX rising edge interrupt status.
#define IR_RF_CLR                                  BIT8  //!< Clear RX FIFO interrupt status.

#define IR_RX_INT_ALL_CLR                (IR_INT_RF_FULL_CLR | IR_INT_RF_LEVEL_CLR | \
                                          IR_INT_RX_CNT_OF_CLR | IR_INT_RF_OF_CLR | \
                                          IR_INT_RX_CNT_THR_CLR | IR_INT_RF_ERROR_CLR | \
                                          IR_INT_RX_RISING_EDGE_CLR|IR_INT_RX_FALLING_EDGE_CLR) //!< Check if the input parameter is valid.

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_TX_FINISH_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR)) //!< Check if the input parameter is valid.
#else
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR)) //!< Check if the input parameter is valid.
#endif

/** End of IR_Interrupts_Clear_Flag
  * \}
  */

/**
 * \defgroup    IR_Flag IR Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_FLAG_TF_EMPTY                       BIT15 //!< TX FIFO is empty or not.
#define IR_FLAG_TF_FULL                        BIT14 //!< TX FIFO is full or not.
#define IR_FLAG_TX_RUN                         BIT4  //!< TX state is running or idle.
#define IR_FLAG_RF_EMPTY                       BIT17 //!< RX FIFO is empty or not.
#define IR_FLAG_RF_FULL                        BIT16 //!< RX FIFO is full or not.
#define IR_FLAG_RX_RUN                         BIT7  //!< RX state is running or idle.

#define IS_IR_FLAG(FLAG)                (((FLAG) == IR_FLAG_TF_EMPTY) || ((FLAG) == IR_FLAG_TF_FULL) || \
                                         ((FLAG) == IR_FLAG_TX_RUN) || ((FLAG) == IR_FLAG_RF_EMPTY) || \
                                         ((FLAG) == IR_FLAG_RF_FULL) || ((FLAG) == IR_FLAG_RX_RUN)) //!< Check if the input parameter is valid.

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
    IRClock_TypeDef IR_Clock;                         /*!< Specify the source clock frequency.
                                                           This parameter can be a value of \ref IR_Clock. */

    uint32_t IR_Freq;                                 /*!< Specify the clock frequency.
                                                           This parameter is IR carrier freqency whose unit is Hz. */

    float IR_DutyCycle;                               /*!< Specify the IR duty cycle. */

    IRMode_TypeDef IR_Mode;                           /*!< Specify the IR mode.
                                                           This parameter can be a value of \ref IR_Mode. */

    IRIdleStatus_TypeDef IR_TxIdleLevel;              /*!< Specify the IR output level in Tx mode.
                                                           This parameter can be a value of \ref IR_Idle_Status. */

    IRTxDataType_TypeDef
    IR_TxInverse;                                     /*!< Specify inverse FIFO data or not in TX mode.
                                                           This parameter can be a value of \ref IR_TX_Data_Type. */

    uint32_t IR_TxFIFOThrLevel;                       /*!< Specify TX FIFO interrupt threshold in TX mode.
                                                           When TX FIFO depth <= threshold value, trigger interrupt.
                                                           This parameter can be a value of 1 ~ 32. */

    IRRxStartMode_TypeDef IR_RxStartMode;             /*!< Specify Start mode in RX mode.
                                                           This parameter can be a value of \ref IR_RX_Start_Mode. */

    uint32_t IR_RxFIFOThrLevel;                       /*!< Specify RX FIFO interrupt threshold in RX mode.
                                                           When RX FIFO depth > threshold value, trigger interrupt.
                                                           This parameter can be a value of 1 ~ 32. */

    IRRxFifoDiscardSetting_TypeDef
    IR_RxFIFOFullCtrl; /*!< Specify data discard mode in RX mode when RX FIFO is full and receiving new data.
                                                           This parameter can be a value of \ref IR_RX_FIFO_Discard_Setting. */

    IRRxTriggerMode_TypeDef IR_RxTriggerMode;         /*!< Specify trigger in RX mode.
                                                           This parameter can be a value of \ref IR_RX_Trigger_Mode. */

    IRRxFilterTime_TypeDef IR_RxFilterTime;           /*!< Specify filter time in RX mode.
                                                           This parameter can be a value of \ref IR_RX_Filter_Time. */

    IRRxCounterThresholdType_TypeDef
    IR_RxCntThrType; /*!< Specify counter level type when trigger IR_INT_RX_CNT_THR interrupt in RX mode.
                                                           This parameter can be a value of \ref IR_RX_Counter_Level. */

    uint32_t IR_RxCntThr;                             /*!< Specify counter threshold value
                                                           when trigger IR_INT_RX_CNT_THR interrupt in RX mode. */

    FunctionalState IR_TxDmaEn;                       /*!< Specify the Tx dma mode.
                                                           This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_TxWaterLevel;                          /*!< Specify the DMA tx water level.
                                                           This parameter must range from 0 to 32.*/

    FunctionalState IR_RxDmaEn;                       /*!< Specify the Rx dma mode.
                                                           This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_RxWaterLevel;                          /*!< Specify the DMA rx water level.
                                                           This parameter must range from 0 to 32.*/

#if IR_SUPPORT_TX_MODE_CONFIG
    IRTxOutputMode_TypeDef
    IR_TxOutputMode;                                  /*!< Specify the IR Tx output mode.
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
 * \brief Deinitialize the IR peripheral registers to their default values.
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
 * \brief   Initialize the IR peripheral according to the specified
 *          parameters in IR_InitStruct.
 *
 * \param[in] IR_InitStruct  Pointer to a IR_InitTypeDef structure which will be initialized.
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
 * \note   The default settings for the IR_InitStruct member are shown in the following table:
 *         | IR_InitStruct member  | Default value                            |
 *         |:---------------------:|:----------------------------------------:|
 *         | IR_Clock              | \ref IR_CLOCK_40M                        |
 *         | IR_Freq               | 38000                                    |
 *         | IR_DutyCycle          | 3                                        |
 *         | IR_Mode               | \ref IR_MODE_TX                          |
 *         | IR_TxIdleLevel        | \ref IR_IDLE_OUTPUT_LOW                  |
 *         | IR_TxInverse          | \ref IR_TX_DATA_NORMAL                   |
 *         | IR_TxFIFOThrLevel     | 0                                        |
 *         | IR_RxStartMode        | \ref IR_RX_AUTO_MODE                     |
 *         | IR_RxFIFOThrLevel     | 0                                        |
 *         | IR_RxFIFOFullCtrl     | \ref IR_RX_FIFO_FULL_DISCARD_NEWEST      |
 *         | IR_RxTriggerMode      | \ref IR_RX_FALL_EDGE                     |
 *         | IR_RxFilterTime       | \ref IR_RX_FILTER_TIME_50ns              |
 *         | IR_RxCntThrType       | \ref IR_RX_Count_Low_Level               |
 *         | IR_RxCntThr           | 0x23a                                    |
 *         | IR_TxDmaEn            | DISABLE                                  |
 *         | IR_TxWaterLevel       | 31                                       |
 *         | IR_RxDmaEn            | DISABLE                                  |
 *         | IR_RxWaterLevel       | 1                                        |
 *
 * \param[in] IR_InitStruct: Pointer to an IR_InitTypeDef structure which will be initialized.
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
 * \param[in] mode      Selected IR operation mode.
 *                      This parameter can be one of the following values:
 *                      \arg IR_MODE_TX: Transmission mode.
 *                      \arg IR_MODE_RX: Receiving mode.
 * \param[in] NewState  New state of the operation mode.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the selected IR mode.
 *                      - DISABLE: Disable the selected IR mode.
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
 * \brief   Config counter threshold value in receiving mode. You can use it to stop receiving IR data.
 *
 * \param[in] IR_RxCntThrType  Count threshold type.
 *                             This parameter can be the following values:
 *                             \arg IR_RX_Count_Low_Level: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 *                             \arg IR_RX_Count_High_Level: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 * \param[in] IR_RxCntThr      Configure IR Rx counter threshold value which can be 0 to 0x7fffffffUL.
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
 * \param[in] pBuf          Data buffer to send.
 * \param[in] len           Send data length.
 * \param[in] IsLastPacket  Is it the last package of data.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: The last data in IR packet and there is no continous data.
 *                            In other words, an infrared data transmission is completed.
 *                          - DISABLE: There is data to be transmitted continuously.
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
 * \param[in] comp_type     Compensation data type.
 *                          This parameter can be one of the following values:
 *                          \arg IR_COMPEN_FLAG_1_2_CARRIER: 1/2 carrier freqency.
 *                          \arg IR_COMPEN_FLAG_1_4_CARRIER: 1/4 carrier freqency.
 *                          \arg IR_COMPEN_FLAG_1_N_SYSTEM_CLK: MOD((0x48[27:16]+0x00[11:0]), 4095)/40MHz.
 *                          User can call function of IR_ConfigCompParam to configure 0x48[27:16].
 * \param[in] buf           Data buffer to send.
 * \param[in] length        Data length.
 * \param[in] IsLastPacket  Is it the last package of data.
 *                          This parameter can be the following values:
 *                          - ENABLE: The last data in IR packet and there is no continous data.
 *                            In other words, an infrared data transmission is completed.
 *                          - DISABLE: There is data to be transmitted continuously.
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
 * \param[in] pBuf    Buffer address to receive data.
 * \param[in] length  Read data length.
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
 * \brief     Enable or disable the specified IR interrupt source.
 *
 * \param[in] IR_INT    Specify the IR interrupt source to be enabled or disabled.
 *                      This parameter can be oen of the following values, refer to \ref IR_Interrupt.
 *                      \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt source.
 *                      \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt source.
 *                      \arg IR_INT_TF_OF: TX FIFO overflow interrupt source.
 *                      \arg IR_INT_RF_FULL: RX FIFO  full interrupt source.
 *                      \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt source.
 *                      \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt source.
 *                      \arg IR_INT_RF_OF: RX FIFO overflow interrupt source.
 *                      \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt source.
 *                      \arg IR_INT_RF_ERROR: RX FIFO error read interrupt source. Trigger when RX FIFO empty and read RX FIFO.
 *                      \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *                      \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 * \param[in] NewState  New state of the specified IR interrupt.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified IR interrupt source.
 *                      - DISABLE: Disable the specified IR interrupt source.
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
 * \param[in] IR_INT    Specify the IR interrupts sources to be mask or unmask.
 *                      This parameter can be the following values, refer to \ref IR_Interrupt.
 *                      \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *                      \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *                      \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
 *                      \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
 *                      \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *                      \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *                      \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
 *                      \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *                      \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *                      \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *                      \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 * \param[in] NewState  New state of the specified IR interrupts.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Mask the specified IR interrupt source.
 *                      - DISABLE: Unmask the specified IR interrupt source.
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
 * \param[in] IR_INT  The specified IR interrupts.
 *                    This parameter can be one of the following values, refer to \ref IR_Interrupt.
 *                    \arg IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *                    \arg IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *                    \arg IR_INT_TF_OF: TX FIFO overflow interrupt.
 *                    \arg IR_INT_RF_FULL: RX FIFO  full interrupt.
 *                    \arg IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *                    \arg IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *                    \arg IR_INT_RF_OF: RX FIFO overflow interrupt.
 *                    \arg IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *                    \arg IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *                    \arg IR_INT_RISING_EDGE: IR RX Rising edge interrupt.
 *                    \arg IR_INT_FALLING_EDGE: IR RX Falling edge interrupt.
 *
 * \return  The status of IR interrupt.
 *          - SET: The IR interrupt status is set.
 *          - RESET: The IR interrupt status is not set.
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
 * \param[in] IR_CLEAR_INT  Specify the interrupt pending bit to clear.
 *                          This parameter can be any combination of the following values, refer to \ref IR_Interrupts_Clear_Flag.
 *                          - IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *                          - IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *                          - IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *                          - IR_INT_RF_FULL_CLR: Clear RX FIFO  full interrupt.
 *                          - IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *                          - IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *                          - IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *                          - IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
 *                          - IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *                          - IR_INT_RX_RISING_EDGE_CLR: Clear RX Rising edge interrupt.
 *                          - IR_INT_RX_FALLING_EDGE_CLR: Clear RX Falling edge interrupt.
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
 * \param[in] data  Send data.
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
 * \param[in] thd  Tx threshold.
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
 * \param[in] thd  Rx threshold.
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
 * \brief  Get the specified IR flag status.
 *
 * \param[in] IR_FLAG  Specify the flag to check.
 *                     This parameter can be one of the following values, refer to \ref IR_Flag.
 *                     \arg IR_FLAG_TF_EMPTY: TX FIFO empty or not. If SET, TX FIFO is empty.
 *                     \arg IR_FLAG_TF_FULL: TX FIFO full or not. If SET, TX FIFO is full.
 *                     \arg IR_FLAG_TX_RUN: TX run or not. If SET, TX is running.
 *                     \arg IR_FLAG_RF_EMPTY: RX FIFO empty or not. If SET, RX FIFO is empty.
 *                     \arg IR_FLAG_RF_FULL: RX FIFO full or not. If SET, RX FIFO is full.
 *                     \arg IR_FLAG_RX_RUN: RX run or not. If SET, RX is running.
 *
 * \return  The status of IR flag.
 *          - SET: The IR flag is set.
 *          - RESET: The IR flag is reset.
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
 * \param[in] NewState  This parameter can be: ENABLE or DISABLE.
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
 * \param[in] NewState  This parameter can be: ENABLE or DISABLE.
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
 *
 * \param[in]  ClockSrc  Specify the clock source to gates its clock.
 * \param[in]  ClockDiv  Specify the clock divide to gates its clock.
 */
void IR_ClkConfig(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv);

/**
 * \brief  Get IR clock config.
 *
 * \param[in]  ClockSrc  Specify the clock source to gates its clock.
 * \param[in]  ClockDiv  Specify the clock divide to gates its clock.
 *
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



