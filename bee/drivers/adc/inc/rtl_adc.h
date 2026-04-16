/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_ADC_H
#define RTL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "adc/src/device/rtl87x2g/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "adc/src/device/rtl87x3e/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "adc/src/device/rtl87x3d/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "adc/src/device/rtl87x2j/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "adc/src/device/rtl87x3j/rtl_adc_def.h"
#endif

/** \defgroup ADC         ADC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup ADC_Exported_Constants ADC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    ADC_Channel_Index ADC Channel Index
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_Channel_Index_0           0
#define ADC_Channel_Index_1           1
#define ADC_Channel_Index_2           2
#define ADC_Channel_Index_3           3
#define ADC_Channel_Index_4           4
#if (CHIP_ADC_CHANNEL_NUM > 4)
#define ADC_Channel_Index_5           5
#define ADC_Channel_Index_6           6
#define ADC_Channel_Index_7           7
#endif
#if (CHIP_ADC_CHANNEL_NUM > 8)
#define ADC_Channel_Index_8           8
#define ADC_Channel_Index_9           9
#define ADC_Channel_Index_10          10
#define ADC_Channel_Index_11          11
#define ADC_Channel_Index_12          12
#define ADC_Channel_Index_13          13
#define ADC_Channel_Index_14          14
#define ADC_Channel_Index_15          15
#endif
#define IS_ADC_CHANNEL(ch)      ((ch) < CHIP_ADC_CHANNEL_NUM)

/** End of ADC_Channel_Index
  * \}
  */

/**
 * \defgroup    ADC_Schedule_Index ADC Schedule Index
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_Schedule_Index_0          0
#define ADC_Schedule_Index_1          1
#define ADC_Schedule_Index_2          2
#define ADC_Schedule_Index_3          3
#define ADC_Schedule_Index_4          4
#define ADC_Schedule_Index_5          5
#define ADC_Schedule_Index_6          6
#define ADC_Schedule_Index_7          7
#define ADC_Schedule_Index_8          8
#define ADC_Schedule_Index_9          9
#define ADC_Schedule_Index_10         10
#define ADC_Schedule_Index_11         11
#define ADC_Schedule_Index_12         12
#define ADC_Schedule_Index_13         13
#define ADC_Schedule_Index_14         14
#define ADC_Schedule_Index_15         15
#if (CHIP_ADC_SCHEDULE_NUM > 16)
#define ADC_Schedule_Index_16         16
#define ADC_Schedule_Index_17         17
#define ADC_Schedule_Index_18         18
#define ADC_Schedule_Index_19         19
#endif
#define IS_ADC_SCH_INDEX(IDEX) ((IDEX) < CHIP_ADC_SCHEDULE_NUM)

/** End of ADC_Schedule_Index
  * \}
  */

/**
 * \defgroup    ADC_Schedule_Table ADC Channel and Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define SCHEDULE_TABLE(Index)         (Index)
#define EXT_SINGLE_ENDED(Index)       ((uint16_t)((ADC_MODE_SINGLE_ENDED_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_EXTERNAL_CH_NUM(Index)))
#define EXT_DIFFERENTIAL(Index)       ((uint16_t)((ADC_MODE_DIFFERENTIAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_EXTERNAL_CH_NUM(Index)))

#define INTERNAL_VBAT_MODE            ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_INTERNAL_VBAT_CH_NUM))
#if ADC_SUPPORT_VADPIN_MODE
#define INTERNAL_VADPIN_MODE          ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_INTERNAL_VADPIN_CH_NUM))
#endif


#if ADC_SUPPORT_VADPIN_MODE
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE || \
                                               (CONFIG) == INTERNAL_VADPIN_MODE))
#else
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE))
#endif

/** End of ADC_Schedule_Table
  * \}
  */

/**
 * \defgroup    ADC_Convert_Time ADC Convert Time
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_CONVERT_TIME,
} ADCConvertTime_TypeDef;

/** End of ADC_Convert_Time
  * \}
  */

/**
 * \defgroup    ADC_Data_Latch ADC Data Latch
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_DATA_LATCH_POSITIVE,
    ADC_DATA_LATCH_NEGATIVE,
} ADCDataLatch_TypeDef;

#define IS_ADC_DATA_LATCH(DATA_LATCH) (((DATA_LATCH) == ADC_DATA_LATCH_POSITIVE) || ((MODE) == ADC_DATA_LATCH_NEGATIVE))

/** End of ADC_Data_Latch
  * \}
  */

/**
 * \defgroup    ADC_Data_Align ADC Data Align
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_DATA_ALIGN_LSB,
    ADC_DATA_ALIGN_MSB,
} ADCDataAlign_TypeDef;

#define IS_ADC_DATA_ALIGN(DATA_ALIGN) (((DATA_ALIGN) == ADC_DATA_ALIGN_LSB) || ((DATA_ALIGN) == ADC_DATA_ALIGN_MSB))

/** End of ADC_Data_Align
  * \}
  */


/**
 * \defgroup    ADC_Data_Average ADC Data Average
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_DATA_AVERAGE_OF_2,
    ADC_DATA_AVERAGE_OF_4,
    ADC_DATA_AVERAGE_OF_8,
    ADC_DATA_AVERAGE_OF_16,
    ADC_DATA_AVERAGE_OF_32,
    ADC_DATA_AVERAGE_OF_64,
    ADC_DATA_AVERAGE_OF_128,
    ADC_DATA_AVERAGE_OF_256,
    ADC_DATA_AVERAGE_MAX,
} ADCDataAverage_TypeDef;

#define IS_ADC_DATA_AVERAGE(_DATA_AVERAGE) (((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_2) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_4) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_8) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_16) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_32) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_64) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_128) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_256))

/** End of ADC_Data_Average
  * \}
  */


/**
 * \defgroup    ADC_FIFO_Threshold ADC FIFO Threshold
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define IS_ADC_FIFO_THRESHOLD(THD) ((THD) <= 0x3F)

/** End of ADC_FIFO_Threshold
  * \}
  */

/**
 * \defgroup    ADC_Burst_Size ADC Burst Size
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define IS_ADC_BURST_SIZE(SIZE) ((SIZE) <= 0x3F)

/** End of ADC_Burst_Size
  * \}
  */

/**
 * \defgroup    ADC_Operation_Mode ADC Operation Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_CONTINUOUS_MODE,
    ADC_ONE_SHOT_MODE,
} ADCOperationMode_TypeDef;

#define IS_ADC_OPERATION_MODE(MODE) (((MODE) == ADC_CONTINUOUS_MODE) || ((MODE) == ADC_ONE_SHOT_MODE))

/** End of ADC_Operation_Mode
  * \}
  */

/**
 * \defgroup    ADC_Power_On_Mode  ADC Power On Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_POWER_ON_AUTO,
#ifdef ADC_POWER_MODE_CTRL_EN
    ADC_POWER_ON_MANUAL,
#endif
} ADCPowerOnMode_TypeDef;

#define IS_ADC_POWER_ON_MODE(MODE) (((MODE) == ADC_POWER_ON_AUTO) || ((MODE) == ADC_POWER_ON_MANUAL))

/** End of ADC_Power_On_Mode
  * \}
  */

/**
 * \defgroup    ADC_Interrupts_Definition ADC Interrupts Definition
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_INT_FIFO_RD_REQ           ((uint32_t)(1 << 0))
#define ADC_INT_FIFO_RD_ERR           ((uint32_t)(1 << 1))
#define ADC_INT_FIFO_THD              ((uint32_t)(1 << 2))
#define ADC_INT_ONE_SHOT_DONE         ((uint32_t)(1 << 4))
#if (ADC_SUPPORT_INT_FIFO_FULL == 1)
#define ADC_INT_FIFO_FULL             ((uint32_t)(1 << 3))
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 5))
#else
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 3))
#endif

#define IS_ADC_INT(INT) (((INT) == ADC_INT_FIFO_RD_REQ) || \
                         ((INT) == ADC_INT_FIFO_RD_ERR) || \
                         ((INT) == ADC_INT_FIFO_THD) || \
                         ((INT) == ADC_INT_FIFO_OVERFLOW) || \
                         ((INT) == ADC_INT_ONE_SHOT_DONE) || \
                         ((INT) == ADC_INT_FIFO_FULL))

/** End of ADC_Interrupts_Definition
  * \}
  */

#if (ADC_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    ADC_Action ADC Action
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_ACTION_ONE_SHOT_SAMPLE = 0,
} ADCAction_TypeDef;

/** End of ADC_Action
  * \}
  */
#endif

/** End of ADC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup ADC_Exported_Types ADC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       ADC init structure definition.
 *
 * \ingroup     ADC_Exported_Types
 */
typedef struct
{
    uint16_t ADC_SampleTime;                /*!< Specifies the ADC Sample clock. (n+1) cycles of 10MHz (19~16383).*/

    ADCConvertTime_TypeDef ADC_ConvertTime; /**< Specifies the ADC Sample convert time.*/

    FunctionalState ADC_DataWriteToFIFO;    /*!< Write ADC one shot mode data into fifo.*/

    uint8_t ADC_FIFOThdLevel;               /*!< Specifies the ADC fifo threshold to trigger interrupt ADC_INT_FIFO_TH.
                                                 This parameter can be a value of 0 to 31. */

    uint8_t ADC_WaterLevel;                 /*!< Specifies the ADC fifo Burst Size to trigger DMA.
                                                 This parameter can be a value of 0 to 31. */

    FunctionalState ADC_FIFOOverWriteEn;    /*!< Specifies if Over Write fifo when fifo overflow.*/

#if (ADC_SUPPORT_DMA_EN == 1)
    FunctionalState ADC_DMAEn;              /*!< Specifies if DMA enable.*/
#endif

    uint16_t ADC_SchIndex[CHIP_ADC_SCHEDULE_NUM]; /*!< Specifies ADC mode and channel for schedule table.*/

    uint32_t ADC_Bitmap;                    /*!< Specifies the schedule table channel map.
                                                 This parameter can be a value of 16Bits map. */

    FunctionalState ADC_TimerTriggerEn;     /*!< Enable ADC one-shot mode when tim7 toggles. */

    ADCDataAlign_TypeDef ADC_DataAlign;     /*!< ADC Data MSB or LSB aligned. */

#if (ADC_SUPPORT_DATAMINUS==1)
    FunctionalState ADC_DataMinusEn;        /**< Enable or disable function that adc data latched
                                                 minus the given offset before writes to reg/FIFO. */

    uint16_t ADC_DataMinusOffset;           /**< Offset to be minused from adc data latched.
                                                 This parameter can be a value of 0 to 4095. */
#endif

    ADCDataAverage_TypeDef ADC_DataAverage; /**< Number of data for calculate average. */

    uint8_t ADC_DataAverageEn;              /**< Enable the calculation for average result of the one shot data. */

    FunctionalState ADC_FIFOStopWriteEn;    /*!< Stop fifo from writing data. This bit will be asserted
                                                 automatically as fifo overflow, (not automatically when
                                                 ADC_FIFO_OVER_WRITE_ENABLE), need to be cleared in order
                                                 to write data again. This will not stop overwrite mode.*/
#ifdef ADC_POWER_MODE_CTRL_EN
    ADCPowerOnMode_TypeDef ADC_PowerOnMode; /**< Specifies ADC power on mode.
                                                 This parameter can be a value of \ref ADC_Power_On_Mode. */
#endif


    FunctionalState ADC_PowerAlwaysOnEn;    /*!< Specifies the power always on. */

#if (ADC_SUPPORT_POWER_ON_DELAY ==1 )
    FunctionalState ADC_PowerOnDlyEn;       /*!< Enable or Disable ADC 8ms delay after adc power on. */
#endif

#if (ADC_SUPPORT_DATA_CLIP ==1 )
    FunctionalState ADC_DataClippingEn;     /*!< Enable or Disable ADC data clipping ,the controller to
                                                 clipping the data with gain/offset mapping when the data value (ouput code) over 4095*/
#endif
} ADC_InitTypeDef;

/** End of ADC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup ADC_Exported_Functions ADC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Deinitializes the ADC peripheral registers to their
 *          default reset values(turn off ADC clock).
 *
 * \param[in] ADCx: Specify ADC peripheral, can only be ADC.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    ADC_DeInit(ADC);
 * }
 * \endcode
 */
void ADC_DeInit(ADC_TypeDef *ADCx);

/**
 * \brief Initializes the ADC peripheral according to the specified parameters in the ADC_InitStruct.
 *
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_InitStruct: pointer to a ADC_InitTypeDef structure that contains the configuration information for the specified ADC peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * \endcode
 */
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);

/**
 * \brief   Fills each ADC_InitStruct member with its default value.
 *
 * \param[in] ADC_InitStruct: Pointer to an ADC_InitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * \endcode
 * \callgraph
 *
 */
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct);

/**
 * \brief   Enables or disables the ADC peripheral.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  ADCMode: ADC operation mode selection.
 *             This parameter can be one of the following values:
 *             \arg ADC_ONE_SHOT_MODE: One shot mode.
 *             \arg ADC_CONTINUOUS_MODE: Continuous sampling mode.
 * \param[in]  NewState: New state of the ADC peripheral.
 *              This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 * }
 * \endcode
 */
void ADC_Cmd(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef ADCMode, FunctionalState NewState);

/**
 * \brief   Enables or disables the specified ADC interrupts.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  ADC_INT: Specify the ADC interrupts sources to be enabled or disabled.
 *             This parameter can be any combination of the following values:
 *             \arg ADC_INT_FIFO_RD_REQ : FIFO read request.
 *             \arg ADC_INT_FIFO_RD_ERR : FIFO read error.
 *             \arg ADC_INT_FIFO_THD : ADC FIFO size > thd.
 *             \arg ADC_INT_FIFO_OVERFLOW : ADC FIFO overflow.
 *             \arg ADC_INT_ONE_SHOT_DONE : ADC one shot mode done.
 * \param[in]  NewState: New state of the specified ADC interrupt.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_FIFO_RD_ERR, ENABLE);
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 * \endcode
 *
 */
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_INT, FunctionalState NewState);

/**
 * \brief  Check whether the specified ADC interrupt flag is set.
 *
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_INT_FLAG: Specifies the interrupt flag to check.
 *             This parameter can be one of the following values:
 *             \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *             \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *             \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *             \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *             \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
 *
 * \return The new state of ADC_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     ITStatus int_status = RESET;
 *     int_status = ADC_GetINTStatus(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * \endcode
 */
ITStatus ADC_GetINTStatus(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * \brief   Get all adc interrupt flag status.
 *
 * \param[in] ADCx: Specify ADC peripheral.
 *
 * \return  All ADC interrupt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint8_t all_flag_status = 0;
 *   all_flag_status = ADC_GetAllFlagStatus(ADC);
 * }
 * \endcode
 *
 */
uint8_t ADC_GetAllFlagStatus(ADC_TypeDef *ADCx);

/**
 * \brief  Clear the ADC interrupt pending bit.
 *
 * \param[in] ADCx: Specify ADC peripheral.
 * \param[in] ADC_INT: Specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *            \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *            \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *            \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *            \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearINTPendingBit(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * \endcode
 */
void ADC_ClearINTPendingBit(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * \brief      Read ADC data according to specific channel.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  Index: Can be 0 to 15.
 *
 * \return     The 12-bit converted ADC raw data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data_0 = ADC_ReadRawData(ADC, 0);
 *    uint16_t raw_data_1 = ADC_ReadRawData(ADC, 1);
 * }
 * \endcode
 */
ADCDataWidth ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t Index);

/**
 * \brief   Get ADC average data from ADC schedule table0.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] OutBuf: Buffer to save data read from ADC FIFO.
 *
 * \return  The 12-bit converted ADC raw data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataAvgEn  = ADC_DATA_AVERAGE_ENABLE;
 *    ADC_InitStruct.ADC_DataAvgSel = ADC_DATA_AVERAGE_OF_2;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadAvgRawData(ADC);
 * }
 * \endcode
 *
 */
ADCDataWidth ADC_ReadAvgRawData(ADC_TypeDef *ADCx);

/**
 * \brief  Read one byte data from ADC FIFO.
 *
 * \param[in]  ADCx: selected ADC peripheral.
 *
 * \return ADC FIFO data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataWriteToFIFO = ADC_DATA_WRITE_TO_FIFO_DISABLE;
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadFIFO(ADC);
 * }
 * \endcode
 */
ADCDataWidth ADC_ReadFIFO(ADC_TypeDef *ADCx);

/**
 * \brief   Get data from ADC FIFO.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] outBuf: Buffer to save data read from ADC FIFO.
 * \param[in]  Num: Number of data to be read.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * \endcode
 *
 */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, ADCDataWidth *outBuf, uint16_t Num);

/**
 * \brief   Get ADC fifo data number.
 *
 * \param[in] ADCx: selected ADC peripheral.
 *
 * \return  Current data number in ADC FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * \endcode
 *
 */
uint8_t ADC_GetFIFODataLen(ADC_TypeDef *ADCx);

/**
 * \brief   Config ADC schedule table.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  ADCMode: ADC operation mode.
 *             This parameter can be one of the following values:
 *             \arg EXT_SINGLE_ENDED(index)
 *             \arg EXT_DIFFERENTIAL(index)
 *             \arg INTERNAL_VBAT_MODE
 * \param[in]  Index: Schedule table index.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_SchIndexConfig(ADC,INTERNAL_VBAT_MODE,0);
 * }
 * \endcode
 *
 */
void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t ADCMode, uint16_t Index);

/**
 * \brief   Config adc schedule table.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  BitMap: ADC bit map.
 * \param[in]  NewState: New state of the ADC peripheral.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint16_t bit_map = 0x03;
 *   ADC_BitMapConfig(ADC,bit_map,ENABLE);
 * }
 * \endcode
 */
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap);

/**
 * \brief   Enbale or disable stop FIFO from writing data.
 *
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  NewState: New state of the ADC FIFO write.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_WriteFIFOCmd(ADC, ENABLE);
 * }
 * \endcode
 */
void ADC_WriteFIFOCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
 * \brief     Config ADC bypass resistor.
 *
 * \param[in] channelNum: External channel number, can be 0~7.
 * \param[in] NewState: Specifies whether the channel enables bypass mode.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
 *
 * \attention The input voltage of channel pin using bypass mode cannot exceed 0.9V!
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_BypassCmd(0,ENABLE);
 * }
 * \endcode
 */
void ADC_BypassCmd(uint8_t ChannelNum, FunctionalState NewState);

/**
 * \brief   Clear ADC FIFO.
 *
 * \param[in] ADCx: Specify ADC peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearFIFO(ADC);
 * }
 * \endcode
 */
void ADC_ClearFIFO(ADC_TypeDef *ADCx);

/**
  * \brief  Enables or disables the ADC power always on.
  *
  * \param  ADCx: selected ADC peripheral.
  * \param  NewState: new state of the specified ADC power always on.
  *         This parameter can be: ENABLE or DISABLE.
  *
  * \return None
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_PowerAlwaysOnCmd(ADC, ENABLE);
  * }
  * \endcode
  */
void ADC_PowerAlwaysOnCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

#if (ADC_SUPPORT_RAP_FUNCTION == 1)
/**
  * \brief  Enables or disables RAP Mode.
  *
  * \param[in]  ADCx: Pointer to the selected ADC peripheral. \ref ADC Declaration
  * \param[in]  NewState: New state of the RAP mode.
  *             This parameter can be: ENABLE or DISABLE.
  *
  * \return None
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_RAPModeCmd(ADC, ENABLE);
  * }
  * \endcode
  */
void ADC_RAPModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
  * \brief  Trigger an task which special of by firmware.
  *
  * \param[in]  ADCx: Pointer to the selected ADC peripheral. \ref ADC Declaration
  * \param[in]  Action: ADC task to be trigger. \ref ADC_Action.
  *
  * \return None
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_ActionTrigger(ADC, ADC_ACTION_ONE_SHOT_SAMPLE);
  * }
  * \endcode
  */
void ADC_ActionTrigger(ADC_TypeDef *ADCx, uint32_t Action);

#endif

#if (ADC_SUPPORT_AUTO_CLOCK == 1)
/**
  * \brief  Enable or disable ADC auto mode.
  *
  * \param[in]  ADCx: Pointer to the selected ADC peripheral. \ref ADC Declaration
  * \param[in]  NewState: New state of the RAP mode. This parameter can be:
  *             \ENABLE:  Enable ADC auto mode which ADC can auto clolk gating.
  *             \DISABLE: Disable ADC auto mode which ADC clock is always on.
  *
  * \return None
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_ClockAutoModeCmd(ADC, ENABLE);
  * }
  * \endcode
  */
void ADC_ClockAutoModeCmd(ADC_TypeDef *ADCx, FunctionalState Newstate);

#endif
#if (ADC_SUPPORT_GET_VOTAGE_API == 1)
/**
  * \brief  Converts ADC sample data to voltage based on the selected sampling mode.
  *
  * \param[in]  SampleMode: ADC sampling mode that determines the voltage conversion formula
  *             This parameter can bethe values, please refer to \ref ADC_Constant_Private
  * \param[in]  SampleData: ADC raw sample data to be converted
  * \param[in]  ErrorStatus: Pointer to an variable to store error information. \ref ADCStatus_TypeDef
  *
  * \return Converted voltage value in millivolts (mV).
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void adc_demo(void)
  * {
  *      ADCStatus_TypeDef adc_error = 0;
  *      float adc_voltage = ADC_GetVoltage(ADC, ADC_SAMPLE_DIVIDE_SINGLE_MODE, &adc_error);
  * }
  * \endcode
  */

float ADC_GetVoltage(const ADCSampleMode_TypeDef SampleMode, ADCDataWidth SampleData,
                     ADCStatus_TypeDef *ErrorStatus);
#endif

/** End of ADC_Exported_Functions
  * \}
  */

/** End of ADC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_ADC_H */


