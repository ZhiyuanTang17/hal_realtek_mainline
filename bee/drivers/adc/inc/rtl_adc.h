/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_adc.h
* \brief    The header file of the peripheral ADC driver.
* \details  This file provides all ADC firmware functions.
* \author   echo
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
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
#include "adc/src/rtl87x2g/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "adc/src/rtl87x3e/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "adc/src/rtl87x3d/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL8762J)
#include "adc/src/rtl87x2j/rtl_adc_def.h"
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
#define EXT_SINGLE_ENDED(Index)       ((uint16_t)((ADC_MODE_SINGLE_ENDED_VALUE << CHIP_ADC_MODE_OFFSET) | (Index)))
#define EXT_DIFFERENTIAL(Index)       ((uint16_t)((ADC_MODE_DIFFERENTIAL_VALUE << CHIP_ADC_MODE_OFFSET) | (Index)))

#define INTERNAL_VBAT_MODE            ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | 0x00))
#if ADC_SUPPORT_VADPIN_MODE
#define INTERNAL_VADPIN_MODE          ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | 0x01))
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
    ADC_CONVERT_TIME_500NS,
    ADC_CONVERT_TIME_700NS,
    ADC_CONVERT_TIME_900NS,
    ADC_CONVERT_TIME_1100NS,
} ADCConvertTim_TypeDef;

#define IS_ADC_CONVERT_TIME(TIME) (((TIME) == ADC_CONVERT_TIME_500NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_700NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_900NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_1100NS))

/** End of ADC_Convert_Time
  * \}
  */

/**
 * \defgroup    ADC_Latch_Data_Edge ADC Latch Data Edge
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_LATCH_DATA_Positive,
    ADC_LATCH_DATA_Negative,
} ADCDataLatchEdge_TypeDef;

#define IS_ADC_LATCH_MODE(MODE) (((MODE) == ADC_LATCH_DATA_Positive) || ((MODE) == ADC_LATCH_DATA_Negative))

/** End of ADC_Latch_Data_Edge
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
} ADCAlign_TypeDef;

#define IS_ADC_DATA_ALIGN(DATA_ALIGN) (((DATA_ALIGN) == ADC_DATA_ALIGN_LSB) || ((DATA_ALIGN) == ADC_DATA_ALIGN_MSB))

/** End of ADC_Data_Align
  * \}
  */

/**
 * \defgroup    ADC_Clock ADC Clock
 * \{
 * \ingroup     ADC_Exported_Constants
 */
/*  adc sample clock frequence default value as follow, other vaule(0~0x1fff) is also support if user wanted */
#define ADC_CLK_625K                  (0x0f)
#define ADC_CLK_312_5K                (0x1f)
#define ADC_CLK_156_25K               (0x3f)
#define ADC_CLK_78_125K               (0x7f)
#define ADC_CLK_39K                   (0xff)

#define ADC_CLK_19_5K                 (0x1ff)
#define ADC_CLK_9_8K                  (0x3ff)
#define ADC_CLK_4_88K                 (0x7ff)
#define ADC_CLK_2_44K                 (0xfff)
#define ADC_CLK_1_22K                 (0x1fff)

/** End of ADC_Clock
  * \}
  */

/**
 * \defgroup    ADC_Raw_Data_Average ADC Raw Data Average
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
} ADCDataAvgSel_TypeDef;

#define IS_ADC_DATA_AVG_NUM(NUM) (((NUM) == ADC_DATA_AVERAGE_OF_2) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_4) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_8) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_16) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_32) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_64) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_128) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_256))

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
#define IS_ADC_BURST_SIZE_CONFIG(CONFIG) ((CONFIG) <= 0x3F)

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

#define IS_ADC_MODE(MODE) (((MODE) == ADC_CONTINUOUS_MODE) || ((MODE) == ADC_ONE_SHOT_MODE))

/** End of ADC_Operation_Mode
  * \}
  */

/**
 * \defgroup    ADC_Power_Mode  ADC Power Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_POWER_ON_AUTO,
    ADC_POWER_ON_MANUAL,
} ADCPowerMode_TypeDef;

#define IS_ADC_POWER_MODE(MODE) (((MODE) == ADC_POWER_ON_AUTO) || ((MODE) == ADC_POWER_ON_MANUAL))

/** End of ADC_Power_Mode
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
#if ADC_SUPPORT_INT_FIFO_FULL
#define ADC_INT_FIFO_FULL             ((uint32_t)(1 << 3))
#else
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 3))
#endif
#define ADC_INT_ONE_SHOT_DONE         ((uint32_t)(1 << 4))
#if ADC_SUPPORT_INT_FIFO_FULL
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 5))
#endif

#if ADC_SUPPORT_INT_FIFO_FULL
#define IS_ADC_INT(INT) (((INT) == ADC_INT_FIFO_RD_REQ) || \
                         ((INT) == ADC_INT_FIFO_RD_ERR) || \
                         ((INT) == ADC_INT_FIFO_THD) || \
                         ((INT) == ADC_INT_FIFO_OVERFLOW) || \
                         ((INT) == ADC_INT_ONE_SHOT_DONE) || \
                         ((INT) == ADC_INT_FIFO_FULL))
#else
#define IS_ADC_INT(INT) (((INT) == ADC_INT_FIFO_RD_REQ) || \
                         ((INT) == ADC_INT_FIFO_RD_ERR) || \
                         ((INT) == ADC_INT_FIFO_THD) || \
                         ((INT) == ADC_INT_FIFO_OVERFLOW) || \
                         ((INT) == ADC_INT_ONE_SHOT_DONE))
#endif

/** End of ADC_Interrupts_Definition
  * \}
  */

/**
 * \defgroup    ADC_Data_Minus ADC Data Minus
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define IS_ADC_DATA_MINUS(DATA_MINUS) (((DATA_MINUS) == ENABLE) || ((DATA_MINUS) == DISABLE))

/** End of ADC_Data_Minus
  * \}
  */

/**
 * \defgroup    ADC_Overwrite_Mode ADC Overwrite Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define IS_ADC_OVERWRITE_MODE(MODE) (((MODE) == ENABLE) || ((MODE) == DISABLE))

/** End of ADC_Overwrite_Mode
  * \}
  */

/**
 * \defgroup    ADC_Power_Always_On ADC Power Always On
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define IS_ADC_POWER_ALWAYS_ON(CMD) (((CMD) == ENABLE) || ((CMD) == DISABLE))

/** End of ADC_Power_Always_On
  * \}
  */

#if (ADC_SUPPORT_RAP_FUNCTION == 1)

/**
 * \defgroup    ADC_Qactive_Force TIM Qactive Force
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_QACTIVE_FW_SCLK_FORCE = 0x0,
    ADC_QACTIVE_FW_PCLK_FORCE = 0x1,
    ADC_QACTIVE_FW_PCLK_ICG = 0x1,
} ADCQactiveForce_TypeDef;

/** End of ADC_Qactive_Force
  * \}
  */

/**
 * \defgroup    ADC_Task TIM Task
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_TASK_ONE_SHOT_SAMPLE = 0,
} ADCTask_TypeDef;

/** End of ADC_Task
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

    ADCConvertTim_TypeDef ADC_ConvertTime;  /**< Specifies the ADC Sample convert time.*/

    FunctionalState ADC_DataWriteToFifo;    /*!< Write ADC one shot mode data into fifo.*/

    uint8_t ADC_FifoThdLevel;               /*!< Specifies the ADC fifo threshold to trigger interrupt ADC_INT_FIFO_TH.
                                                This parameter can be a value of 0 to 31. */

    uint8_t ADC_WaterLevel;                 /*!< Specifies the ADC fifo Burst Size to trigger GDMA.
                                                This parameter can be a value of 0 to 31. */

    FunctionalState ADC_FifoOverWriteEn;    /*!< Specifies if Over Write fifo when fifo overflow.*/

#if ADC_SUPPORT_DMA_EN
    FunctionalState ADC_DmaEn;              /*!< Specifies if DMA enable.*/
#endif

    uint16_t ADC_SchIndex[CHIP_ADC_SCHEDULE_NUM]; /*!< Specifies ADC mode and channel for schedule table.*/

    uint32_t ADC_Bitmap;                    /*!< Specifies the schedule table channel map.
                                                 This parameter can be a value of 16Bits map. */

    FunctionalState ADC_TimerTriggerEn;     /*!< Enable ADC one-shot mode when tim7 toggles. */

    ADCAlign_TypeDef ADC_DataAlign;         /*!< ADC Data MSB or LSB aligned. */

    FunctionalState ADC_DataMinusEn;        /**< Enable or disable function that adc data latched
                                                 minus the given offset before writes to reg/FIFO. */

    uint16_t ADC_DataMinusOffset;           /**< Offset to be minused from adc data latched.
                                                 This parameter can be a value of 0 to 4095. */

    ADCDataAvgSel_TypeDef ADC_DataAvgSel;   /**< Number of data for calculate average. */

    uint8_t ADC_DataAvgEn;                  /**< Enable the calculation for average result of the one shot data. */

    uint8_t ADC_DataLatchDly;               /*!< Specifies delay of ck_ad to latch data.*/

    FunctionalState ADC_FifoStopWriteEn;    /*!< Stop fifo from writing data. This bit will be asserted
                                                 automatically as fifo overflow, (not automatically when
                                                 ADC_FIFO_OVER_WRITE_ENABLE), need to be cleared in order
                                                 to write data again. This will not stop overwrite mode.*/

    ADCPowerMode_TypeDef ADC_PowerOnMode;   /**< Specifies ADC power on mode.
                                                 This parameter can be a value of \ref ADC_Power_On_Mode. */

    FunctionalState ADC_PowerAlwaysOnEn;    /*!< Specifies the power always on. */

#if ADC_SUPPORT_POWER_ON_DELAY
    FunctionalState ADC_PowerOnDlyEn;       /*!< Enable or Disable ADC 8ms delay after adc power on. */
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
 * \details
 * \param[in] ADCx: Specify ADC peripheral, can only be ADC.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn off the clock.
 *    ADC_DeInit(ADC);
 * }
 * \endcode
 */
void ADC_DeInit(ADC_TypeDef *ADCx);

/**
 * \brief Initializes the ADC peripheral according to the specified
 *     parameters in the ADC_InitStruct
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_InitStruct: pointer to a ADC_InitTypeDef structure that
 *     contains the configuration information for the specified ADC peripheral
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

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
 * \param[in] ADC_InitStruct: Pointer to an ADC_InitTypeDef structure which will be initialized.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

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
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  adcMode: ADC operation mode selection.
        This parameter can be one of the following values:
 *     \arg ADC_ONE_SHOT_MODE: One shot mode.
 *     \arg ADC_CONTINUOUS_MODE: Continuous sampling mode.
 * \param[in]  NewState: New state of the ADC peripheral.
 *     This parameter can be: ENABLE or DISABLE.
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
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
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
void ADC_Cmd(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef AdcMode, FunctionalState NewState);

/**
 * \brief   Enables or disables the specified ADC interrupts.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  ADC_IT: Specify the ADC interrupts sources to be enabled or disabled.
 *     This parameter can be any combination of the following values:
 *     \arg ADC_INT_FIFO_RD_REQ : FIFO read request.
 *     \arg ADC_INT_FIFO_RD_ERR : FIFO read error.
 *     \arg ADC_INT_FIFO_THD : ADC FIFO size > thd.
 *     \arg ADC_INT_FIFO_OVERFLOW : ADC FIFO overflow.
 *     \arg ADC_INT_ONE_SHOT_DONE : ADC one shot mode done.
 * \param[in]  NewState: New state of the specified ADC interrupt.
 *     This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
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
 * \brief      Read ADC data according to specific channel.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  Index: Can be 0 to 15.
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
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
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
uint16_t ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t Index);

/**
 * \brief   Get ADC average data from ADC schedule table0.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] OutBuf: Buffer to save data read from ADC FIFO.
 * \return  The 12-bit converted ADC raw data.
 * \callgraph
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
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
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
uint16_t ADC_ReadAvgRawData(ADC_TypeDef *ADCx);

/**
 * \brief  Read one byte data from ADC FIFO.
 * \param[in]  ADCx: selected ADC peripheral.
 * \return adc FIFO data.
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
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataWriteToFifo = ADC_DATA_WRITE_TO_FIFO_DISABLE;
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
uint16_t ADC_ReadFIFO(ADC_TypeDef *ADCx);

/**
 * \brief   Get data from ADC FIFO.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] outBuf: Buffer to save data read from ADC FIFO.
 * \param[in]  Num: Number of data to be read.
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
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, uint16_t *outBuf, uint16_t Num);

/**
 * \brief   Get ADC fifo data number.
 * \param[in] ADCx: selected ADC peripheral.
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
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  AdcMode: ADC operation mode.
 *     This parameter can be one of the following values:
 *     \arg EXT_SINGLE_ENDED(index)
 *     \arg EXT_DIFFERENTIAL(index)
 *     \arg INTERNAL_VBAT_MODE
 * \param[in]  Index: Schedule table index.
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
void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t AdcMode, uint16_t Index);

/**
 * \brief   Config adc schedule table.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  BitMap: ADC bit map.
 * \param[in]  NewState: New state of the ADC peripheral.
 *      This parameter can be: ENABLE or DISABLE.
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
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap, FunctionalState NewState);

/**
 * \brief   Enbale or disable stop FIFO from writing data.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  NewState: New state of the ADC FIFO write.
 *     This parameter can be: ENABLE or DISABLE.
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
 * \param[in] channelNum: External channel number, can be 0~7.
 * \param[in] NewState: Specifies whether the channel enables bypass mode.
 *            This parameter can be: ENABLE or DISABLE.
 * \return    None.
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
 * \brief  Check whether the specified ADC interrupt flag is set.
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_INT_FLAG: Specifies the interrupt flag to check.
 *     This parameter can be one of the following values:
 *     \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *     \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *     \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *     \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *     \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
 *
 * \return The new state of ADC_INT (SET or RESET).
 * \retval SET.
 * \retval RESET.
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
 * \brief  Clear the ADC interrupt pending bit.
 * \param[in] ADCx: Specify ADC peripheral.
 * \param[in] ADC_INT: Specifies the interrupt pending bit to clear.
 *     This parameter can be any combination of the following values:
 *     \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *     \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *     \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *     \arg ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *     \arg ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
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
 * \brief   Clear ADC FIFO.
 * \param[in] ADCx: Specify ADC peripheral.
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
 * \brief   Get all adc interrupt flag status.
 * \param[in] ADCx: Specify ADC peripheral.
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
  * \brief  Get the index state of ADC controller.
  * \param[in]  ADCx: Specify ADC peripheral.
  * \return BIT15:0 stores the data in the fifo, BIT31:28 stores the index of the data.
  */
uint32_t ADC_ReadScheduleIndexandFifoData(ADC_TypeDef *ADCx);

#if (ADC_SUPPORT_RAP_FUNCTION == 1)

void ADC_RAPModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

void ADC_RAPQactiveCtrl(ADC_TypeDef *ADCx, uint32_t Qactive, FunctionalState NewState);

void ADC_TaskTrigger(ADC_TypeDef *ADCx, uint32_t Task);

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

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/
