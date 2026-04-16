/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_KEYSCAN_H
#define RTL_KEYSCAN_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "keyscan/src/device/rtl87x2g/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "keyscan/src/device/rtl87x3e/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "keyscan/src/device/rtl87x3d/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "keyscan/src/device/rtl87x2j/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "keyscan/src/device/rtl87x3j/rtl_keyscan_def.h"
#endif

/** \defgroup KEYSCAN     KEYSCAN
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup KEYSCAN_Exported_Constants KEYSCAN Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    KEYSCAN_FIFO_Depth KEYSCAN FIFO Depth
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define KEYSCAN_FIFO_DEPTH              26

/** End of KEYSCAN_FIFO_Depth
  * \}
  */

/**
 * \defgroup    KEYSCAN_Row_Number KEYSCAN Row Number
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define IS_KEYSCAN_ROW_NUM(ROW) ((ROW) <= 12)

/** End of KEYSCAN_Row_Number
  * \}
  */

/**
 * \defgroup    KEYSCAN_Column_Number KEYSCAN Column Number
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define IS_KEYSCAN_COL_NUM(COL) ((COL) <= 20)

/** End of KEYSCAN_Column_Number
  * \}
  */

/**
 * \defgroup    KEYSCAN_Scan_mode KEYSCAN Scan mode
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
typedef enum
{
    KEYSCAN_MANUAL_SCAN_MODE = 0x00,
    KEYSCAN_AUTO_SCAN_MODE = 0x01,
} KEYSCANScanMode_TypeDef;

#define IS_KEYSCAN_SCAN_MODE(MODE)  (((MODE) == KEYSCAN_MANUAL_SCAN_MODE) || ((MODE) == KEYSCAN_AUTO_SCAN_MODE))

/** End of KEYSCAN_Scan_mode
  * \}
  */

/**
 * \defgroup    KEYSCAN_Detect_Mode KEYSCAN Detect Mode
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
typedef enum
{
    KEYSCAN_DETECT_MODE_EDGE = 0x00,
    KEYSCAN_DETECT_MODE_LEVEL = 0x01,
} KEYSCANDetectMode_TypeDef;

#define IS_KEYSCAN_DETECT_MODE(MODE)    (((MODE) == KEYSCAN_DETECT_MODE_EDGE) || ((MODE) == KEYSCAN_DETECT_MODE_LEVEL))

/** End of KEYSCAN_Detect_Mode
  * \}
  */

/**
 * \defgroup    KEYSCAN_FIFO_Overflow_Control KEYSCAN FIFO Overflow Control
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
typedef enum
{
    KEYSCAN_FIFO_OVFL_CTRL_DIS_NEWEST = 0x00,
    KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST = 0x01,
} KEYSCANFIFOvflCtl_TypeDef;

#define IS_KEYSCAN_FIFO_OVFL_CTRL(CTRL)  (((CTRL) == KEYSCAN_FIFO_OVFL_CTRL_DIS_NEWEST) || ((CTRL) == KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST))

/** End of KEYSCAN_FIFO_Overflow_Control
  * \}
  */

/**
 * \defgroup    KEYSCAN_Manual_Sel KEYSCAN Manual Sel
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
typedef enum
{
    KEYSCAN_MANUAL_SEL_BIT = 0x00,
    KEYSCAN_MANUAL_SEL_KEY = 0x01,
} KEYSCANManualSel_TypeDef;

#define IS_KEYSCAN_MANUAL_SELECT(SEL)  (((SEL) == KEYSCAN_MANUAL_SEL_BIT) || ((SEL) == KEYSCAN_MANUAL_SEL_KEY))

/** End of KEYSCAN_Manual_Sel
  * \}
  */

#if (KEYSCAN_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    KEYSCAN_Action KEYSCAN Action
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
typedef enum
{
    KEYSCAN_ACTION_MANUAL = 0,
} KEYSCANAction_TypeDef;

/** End of KEYSCAN_Action
  * \}
  */
#endif

/**
 * \defgroup    KEYSCAN_Key_Limit KEYSCAN Key Limit
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define IS_KEYSCAN_KEY_LIMIT(DATA_NUM) ((DATA_NUM) <= KEYSCAN_FIFO_DEPTH) //0 means no limit

/** End of KEYSCAN_Key_Limit
  * \}
  */

/**
 * \defgroup    KEYSCAN_Interrupt KEYSCAN Interrupt
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define KEYSCAN_INT_THRESHOLD                    BIT4
#define KEYSCAN_INT_OVER_READ                    BIT3
#define KEYSCAN_INT_SCAN_END                     BIT2
#define KEYSCAN_INT_FIFO_NOT_EMPTY               BIT1
#define KEYSCAN_INT_ALL_RELEASE                  BIT0
#define IS_KEYSCAN_CONFIG_INT(INT) ((((INT) & (uint32_t)0xFFF8) == 0x00) && ((INT) != 0x00))

/** End of KEYSCAN_Interrupt
  * \}
  */

/**
 * \defgroup    KEYSCAN_Flag KEYSCAN Flag
 * \{
 * \ingroup     KEYSCAN_Exported_Constants
 */
#define KEYSCAN_FLAG_FIFOLIMIT                       BIT20
#define KEYSCAN_INT_FLAG_THRESHOLD                   BIT19
#define KEYSCAN_INT_FLAG_OVER_READ                   BIT18
#define KEYSCAN_INT_FLAG_SCAN_END                    BIT17
#define KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY              BIT16
#define KEYSCAN_INT_FLAG_ALL_RELEASE                 BIT15
#define KEYSCAN_FLAG_DATAFILTER                      BIT3
#define KEYSCAN_FLAG_OVR                             BIT2
#define KEYSCAN_FLAG_FULL                            BIT1
#define KEYSCAN_FLAG_EMPTY                           BIT0
#define IS_KEYSCAN_FLAG(FLAG)       ((((FLAG) & (uint32_t)0x01FF) == 0x00) && ((FLAG) != (uint32_t)0x00))
#define IS_KEYSCAN_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0x00C0) == 0x00) && ((FLAG) != (uint32_t)0x00))

/** End of KEYSCAN_Flag
  * \}
  */

/** End of KEYSCAN_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup KEYSCAN_Exported_Types KEYSCAN Exported Types
  * \brief
  * \{
  */

/**
 * \brief       KEYSCAN initialize parameters
 *
 * \ingroup     KEYSCAN_Exported_Types
 */
typedef struct
{
    uint16_t KEYSCAN_RowSize;                 /*!< Specifies KEYSCAN Row Size.
                                                   This parameter can be a value <=12. */

    uint16_t KEYSCAN_ColSize;                 /*!< Specifies KEYSCAN Column Size.
                                                   This parameter can be a value <=20. */

    uint16_t KEYSCAN_ClockDiv;                /*!< Specifies KEYSCAN clock divider.
                                                   scan clock = system clock/(SCAN_DIV+1). */

    uint8_t KEYSCAN_ClockDelayDiv;            /*!< Specifies KEYSCAN clock delay divider.
                                                   delay clock = scan clock/(DELAY_DIV+1). */

    FunctionalState KEYSCAN_DebounceEn;       /*!< Enable or disable debounce. */

    FunctionalState KEYSCAN_ScanTimerEn;      /*!< Enable or disable scan timer. */

    FunctionalState KEYSCAN_DetectTimerEn;    /*!< Enable or disable detect timer. */

    uint16_t KEYSCAN_DebounceCnt;             /*!< Specifies KEYSCAN Debounce time. */

    uint16_t KEYSCAN_ScanInterval;            /*!< Specifies KEYSCAN release time. */

    uint16_t KEYSCAN_ReleaseCnt;              /*!< Specifies KEYSCAN release time. */

    KEYSCANScanMode_TypeDef KEYSCAN_ScanMode; /*!< Specifies KEYSCAN mode. */

    KEYSCANDetectMode_TypeDef KEYSCAN_DetectMode; /*!< Specifies Key Detect mode. */

    uint16_t KEYSCAN_FIFOTriggerLevel;        /*!< Specifies KEYSCAN fifo threshold
                                                   to trigger interrupt KEYSCAN_INT_THRESHOLD. */

    KEYSCANFIFOvflCtl_TypeDef KEYSCAN_FIFOOvflCtrl; /*!< Specifies KEYSCAN fifo over flow control. */

    uint8_t KEYSCAN_KeyLimit;                 /*!< Specifies max scan data allowable in each scan. */

    KEYSCANManualSel_TypeDef KEYSCAN_ManualSel; /*!< Specifies trigger mode in manual mode. */

    uint8_t KEYSCAN_PreGuardCnt;              /*!< Specifies KEYSCAN preguard time. */

    uint8_t KEYSCAN_PostGuardCnt;             /*!< Specifies KEYSCAN postguard time. */

#if KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE
    FunctionalState KEYSCAN_RowPullHighEn;
#endif

#if KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE
    FunctionalState KEYSCAN_ColunmOutputHighEn;
#endif

} KEYSCAN_InitTypeDef;

/** End of KEYSCAN_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup KEYSCAN_Exported_Functions KEYSCAN Exported Functions
  * \brief
  * \{
  */

/**
 * \brief  Deinitializes the KEYSCAN peripheral registers to their default reset values(turn off KEYSCAN clock).
 *
 * \param[in]  KEYSCANx: Selected KEYSCAN peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     KEYSCAN_DeInit(KEYSCAN);
 * }
 * \endcode
 */
void KEYSCAN_DeInit(KEYSCAN_TypeDef *KEYSCANx);

/**
 * \brief   Initializes the KEYSCAN peripheral according to the specified
 *          parameters in the KEYSCAN_InitStruct
 *
 * \param[in]  KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in]  KEYSCAN_InitStruct: Pointer to a KEYSCAN_InitTypeDef structure that
 *             contains the configuration information for the specified KEYSCAN peripheral
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     RCC_ClockCmd(KEYSCAN_CLOCK, ENABLE);

 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KEYSCAN_StructInit(&KEYSCAN_InitStruct);

 *     KEYSCAN_InitStruct.rowSize  = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.colSize  = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.scanmode     = KEYSCAN_Manual_Scan_Mode;
 *     KEYSCAN_InitStruct.debounceEn   = KEYSCAN_Debounce_Enable;

 *     KEYSCAN_Init(KEYSCAN, &KEYSCAN_InitStruct);

 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);  // Unmask keyscan interrupt
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * \endcode
 */
void KEYSCAN_Init(KEYSCAN_TypeDef *KEYSCANx, KEYSCAN_InitTypeDef *KEYSCAN_InitStruct);

/**
 * \brief  Fills each KEYSCAN_InitStruct member with its default value.
 *
 * \param[in]  KEYSCAN_InitStruct: Pointer to a KEYSCAN_InitTypeDef structure which will be initialized.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     RCC_ClockCmd(KEYSCAN_CLOCK, ENABLE);

 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KEYSCAN_StructInit(&KEYSCAN_InitStruct);

 *     KEYSCAN_InitStruct.rowSize  = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.colSize  = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.scanmode     = KEYSCAN_Manual_Scan_Mode;
 *     KEYSCAN_InitStruct.debounceEn   = KEYSCAN_Debounce_Enable;

 *     KEYSCAN_Init(KEYSCAN, &KEYSCAN_InitStruct);

 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);  // Unmask keyscan interrupt
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * \endcode
 */
void KEYSCAN_StructInit(KEYSCAN_InitTypeDef *KEYSCAN_InitStruct);

/**
 * \brief  Enables or disables the specified KEYSCAN interrupt.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] KEYSCAN_INT: Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg KEYSCAN_INT_THRESHOLD: Kescan FIFO data over threshold interrupt.
 *            \arg KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            \arg KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            \arg KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            \arg KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * \param[in] NewState: New state of the specified KEYSCAN interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);
 * }
 * \endcode
 */
void KEYSCAN_INTConfig(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT,
                       FunctionalState NewState);

/**
 * \brief  Mask the specified KEYSCAN interrupt.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] KEYSCAN_INT: Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg KEYSCAN_INT_THRESHOLD: Kescan FIFO data over threshold interrupt.
 *            \arg KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            \arg KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            \arg KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            \arg KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * \param[in] NewState: New state of the specified KEYSCAN interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 * }
 * \endcode
 */
void KEYSCAN_INTMask(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT,
                     FunctionalState NewState);

/**
 * \brief  Read data from KEYSCAN FIFO.
 *
 * \param[in]  KEYSCANx: Selected KEYSCAN peripheral.
 * \param[out] outBuf: Buffer to save data read from KEYSCAN FIFO.
 * \param[in]  count: Data length to be read.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     uint16_t data[3] = {0};
 *     KEYSCAN_Read(KEYSCAN, data, 3);
 * }
 * \endcode
 */
void KEYSCAN_Read(KEYSCAN_TypeDef *KEYSCANx, uint16_t *outBuf, uint16_t count);

/**
 * \brief   Enable or disable the KEYSCAN peripheral.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] NewState: New state of the KEYSCAN peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * \endcode
 */
void KEYSCAN_Cmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState);

/**
 * \brief   Set filter data.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] data: Config the data to be filtered.
 *            This parameter should not be more than 9 bits.
 * \param[in] NewState: New state of the KEYSCAN peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_FilterDataConfig(KEYSCAN, 0x01, ENABLE);
 *
 * }
 * \endcode
 */
void KEYSCAN_FilterDataConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t data,
                              FunctionalState NewState);

/**
 * \brief   KEYSCAN debounce time config.
 *
 * \param[in] KEYSCANx: selected KEYSCAN peripheral.
 * \param[in] time: KEYSCAN hardware debounce time.
 * \param[in] NewState: New state of the KEYSCAN debounce function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_debounceConfig(KEYSCAN, 10, ENABLE);
 *
 * }
 * \endcode
 */
void KEYSCAN_DebounceConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t time,
                            FunctionalState NewState);

/**
 * \brief   Get KEYSCAN FIFO data num.
 *
 * \param[in]  KEYSCANx: Selected KEYSCAN peripheral.
 *
 * \return  Data length in FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     uint16_t data_len = KEYSCAN_GetFIFODataNum(KEYSCAN);
 * }
 * \endcode
 */
uint16_t KEYSCAN_GetFIFODataNum(KEYSCAN_TypeDef *KEYSCANx);

/**
 * \brief  Clear the KEYSCAN interrupt pending bit.
 *
 * \param[in] KEYSCANx: selected KEYSCAN peripheral.
 * \param[in] KEYSCAN_INT: specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            \arg KEYSCAN_INT_THRESHOLD: Kescan FIFO data over threshold interrupt.
 *            \arg KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            \arg KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            \arg KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            \arg KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 * }
 * \endcode
 */
void KEYSCAN_ClearINTPendingBit(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT);

/**
 * \brief   Clear the specified KEYSCAN flag.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] KEYSCAN_FLAG: Specifies the flag to clear.
 *            This parameter can be one of the following values:
 *            \arg KEYSCAN_FLAG_FIFOLIMIT
 *            \arg KEYSCAN_FLAG_DATAFILTER
 *            \arg KEYSCAN_FLAG_OVR
 *
 * \return  None.
 * \note    KEYSCAN_FLAG_FULL and KEYSCAN_FLAG_EMPTY can't be cleared manually.
 *          They are cleared by hardware automatically.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ClearFlags(KEYSCAN, KEYSCAN_FLAG_FIFOLIMIT);
 * }
 * \endcode
 */
void KEYSCAN_ClearFlags(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG);

/**
 * \brief   Check whether the specified KEYSCAN flag is set.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] KEYSCAN_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg KEYSCAN_FLAG_FIFOLIMIT:
 *            \arg KEYSCAN_FLAG_THRESHOLD:
 *            \arg KEYSCAN_FLAG_OVER_READ:
 *            \arg KEYSCAN_FLAG_SCAN_END:
 *            \arg KEYSCAN_FLAG_FIFO_NOT_EMPTY:
 *            \arg KEYSCAN_FLAG_ALL_RELEASE:
 *            \arg KEYSCAN_FLAG_DATAFILTER:
 *            \arg KEYSCAN_FLAG_OVR:
 *            \arg KEYSCAN_FLAG_FULL:
 *            \arg KEYSCAN_FLAG_EMPTY:
 *
 * \return  The new state of KEYSCAN_FLAG (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     FlagStatus flag_status = KEYSCAN_GetFlagState(KEYSCAN, KEYSCAN_FLAG_OVR);
 *
 * }
 * \endcode
 */
FlagStatus KEYSCAN_GetFlagState(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG);

/**
 * \brief  Read FIFO data.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 *
 * \return KEYSCAN FIFO data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     uint16_t data = KEYSCAN_ReadFIFOData(KEYSCAN);
 * }
 * \endcode
 */
uint16_t KEYSCAN_ReadFIFOData(KEYSCAN_TypeDef *KEYSCANx);

/**
 * \brief  Set manual scan trigger mode. This function is only effective when keyscan is manual scan mode.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] manual_sel: Specifies the KEYSCAN manual trigger mode.
 *                        This parameter can be one of the following values:
 *                        \arg KEYSCAN_MANUAL_SEL_BIT: scan trigger by register (Call API KEYSCAN_Cmd).
 *                        \arg KEYSCAN_MANUAL_SEL_KEY: scan trigger by key.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetManualSelect(KEYSCAN, KEYSCAN_MANUAL_SEL_BIT);
 * }
 * \endcode
 */
void KEYSCAN_SetManualSelect(KEYSCAN_TypeDef *KEYSCANx, KEYSCANManualSel_TypeDef manual_sel);

/**
 * \brief  Set preguard time. Preguard time = preguard_cnt * scan clock.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] preguard_cnt: Specifies the preguard count. This parameter can be configured from 0 to 7.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetPreGuardTime(KEYSCAN, 3);
 * }
 * \endcode
 */
void KEYSCAN_SetPreGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t preguard_cnt);

/**
 * \brief  Set postguard time. Postguard time = postguard_cnt * scan clock.
 *
 * \param[in] KEYSCANx: Selected KEYSCAN peripheral.
 * \param[in] postguard_cnt: Specifies the postguard count. This parameter can be configured from 0 to 7.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetPostGuardTime(KEYSCAN, 3);
 * }
 * \endcode
 */
void KEYSCAN_SetPostGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t postguard_cnt);

#if (KEYSCAN_SUPPORT_RAP_FUNCTION == 1)

void KEYSCAN_RAPModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState);

void KEYSCAN_ActionTrigger(KEYSCAN_TypeDef *KEYSCANx, uint32_t Action);

#endif

#if (KEYSCAN_SUPPORT_AUTO_CLOCK == 1)

void KEYSCAN_SetClockAutoMode(KEYSCAN_TypeDef *KEYSCANx, uint32_t AutoMode);

#endif

/** End of KEYSCAN_Exported_Functions
  * \}
  */

/** End of KEYSCAN
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_KEYSCAN_H */



