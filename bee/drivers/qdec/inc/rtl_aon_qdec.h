/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_aon_qdec.h
* \brief    The header file of the peripheral AON_QDECODER driver.
* \details  This file provides all AON_QDECODER firmware functions.
* \author   Grace_yan
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_AON_QDEC_H
#define RTL_AON_QDEC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "qdec/src/rtl87x2g/rtl_aon_qdec_def.h"
#endif

/** \defgroup AON_QDEC    AON_QDEC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup AON_QDEC_Exported_Constants AON_QDEC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    AON_QDEC_Counter_Scale AON_QDEC Counter Scale
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
typedef enum
{
    CounterScale_1_Phase = 0x00,
    CounterScale_2_Phase = 0x01,
} AONQDECAxisCntScale_TypeDef;

#define IS_CNT_SCALE_PHASE_TYPE(TYPE) ((TYPE) <= 0x01)

/** End of AON_QDEC_Counter_Scale
  * \}
  */

/**
 * \defgroup    AON_QDEC_Init_Phase AON_QDEC Init Phase
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
typedef enum
{
    phaseMode0 = 0x00,                              //phase 00
    phaseMode1 = 0x01,                              //phase 01
    phaseMode2 = 0x02,                              //phase 10
    phaseMode3 = 0x03,                              //phase 11
} AONQDECInitPhase_TypeDef;

#define IS_PHSAE_MODE_TYPE(TYPE) ((TYPE) <= 0x03)

/** End of AON_QDEC_Init_Phase
  * \}
  */

/**
 * \defgroup    AON_QDEC_Axis_Direction AON_QDEC Axis Direction
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
typedef enum
{
    AON_QDEC_AXIS_DIR_DOWN = 0x00,
    AON_QDEC_AXIS_DIR_UP = 0x01,
} AONQDECAxisDir_TypeDef;

#define IS_AON_QDEC_AXIS_DIR_TYPE(TYPE) ((TYPE) <= 0x01)

/** End of AON_QDEC_Axis_Direction
  * \}
  */

/**
 * \defgroup    AON_QDEC_Interrupts AON_QDEC Interrupts
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_X_INT_NEW_DATA                     BIT0//get New data and state change
#define AON_QDEC_X_INT_ILLEAGE                      BIT1//illeage

#define IS_AON_QDEC_INT_CONFIG(CONFIG) (((CONFIG) == AON_QDEC_X_INT_NEW_DATA) || ((CONFIG) == AON_QDEC_X_INT_ILLEAGE))

/** End of AON_QDEC_Interrupts
  * \}
  */

/**
 * \defgroup    AON_QDEC_Interrupts_Mask AON_QDEC Interrupts Mask
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_X_INT_MASK                         BIT24
#define AON_QDEC_X_WAKE_AON_MASK                    BIT23
#define AON_QDEC_X_CT_INT_MASK                      BIT8//get New data and state change
#define AON_QDEC_X_ILLEAGE_INT_MASK                 BIT7//illeage

#define IS_AON_QDEC_INT_MASK_CONFIG(CONFIG) (((CONFIG) == AON_QDEC_X_CT_INT_MASK) || ((CONFIG) == AON_QDEC_X_ILLEAGE_INT_MASK))

/** End of AON_QDEC_Interrupts_Mask
  * \}
  */

/**
 * \defgroup    AON_QDEC_Clr_Flag AON_QDEC Clr Flag
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_CLR_ILLEGAL_CT_X                   BIT5
#define AON_QDEC_CLR_ILLEGAL_INT_X                  BIT4
#define AON_QDEC_CLR_UNDERFLOW_X                    BIT3
#define AON_QDEC_CLR_OVERFLOW_X                     BIT2
#define AON_QDEC_CLR_NEW_CT_X                       BIT1
#define AON_QDEC_CLR_ACC_CT_X                       BIT0

#define IS_AON_QDEC_INT_CLR_CONFIG(CONFIG) (((CONFIG) == AON_QDEC_CLR_ACC_CT_X) ||  ((CONFIG) == AON_QDEC_CLR_ILLEGAL_INT_X)\
                                            || ((CONFIG) == AON_QDEC_CLR_UNDERFLOW_X) ||((CONFIG) == AON_QDEC_CLR_OVERFLOW_X)\
                                            || ((CONFIG) == AON_QDEC_CLR_NEW_CT_X))

/** End of AON_QDEC_Clr_Flag
  * \}
  */

/**
 * \defgroup    AON_QDEC_Flag AON_QDEC Flag
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_FLAG_NEW_CT_STATUS_X               BIT0
#define AON_QDEC_FLAG_OVERFLOW_X                    BIT1
#define AON_QDEC_FLAG_UNDERFLOW_X                   BIT2
#define AON_QDEC_FLAG_ILLEGAL_STATUS_X              BIT4

#define IS_AON_QDEC_CLR_INT_STATUS(INT) (((INT) == AON_QDEC_FLAG_ILLEGAL_STATUS_X) || ((INT) == AON_QDEC_FLAG_NEW_CT_STATUS_X)\
                                         || ((INT) == AON_QDEC_FLAG_OVERFLOW_X) || ((INT) == AON_QDEC_FLAG_UNDERFLOW_X)\
                                         || ((INT) == AON_QDEC_FLAG_AUTO_STATUS_X))

/** End of AON_QDEC_Flag
  * \}
  */

/**
 * \defgroup    AON_QDEC_Axis AON_QDEC Axis
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_AXIS_X                             BIT0

/** End of AON_QDEC_Axis
  * \}
  */

/**
 * \defgroup    AON_QDEC_Immediate_Number AON_QDEC Immediate Number
 * \{
 * \ingroup     AON_QDEC_Exported_Constants
 */
#define AON_QDEC_0X04_CNT_DIR           BIT20
#define AON_QDEC_0X00_AXIS_EN           BIT31

/** End of AON_QDEC_Immediate_Number
  * \}
  */

/** End of AON_QDEC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup AON_QDEC_Exported_Types AON_QDEC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       Qdecoder init structure definition.
 *
 * \ingroup     AON_QDEC_Exported_Types
 */
typedef struct
{
    FunctionalState axisConfigX;          /*!< Specifies the axis X function.
                                                   This parameter can be a value of ENABLE or DISABLE. */
    FunctionalState manualLoadInitPhase;  /*!< Specifies manual-load Initphase function.
                                                   This parameter can be a value of ENABLE or DISABLE. */
    AONQDECAxisCntScale_TypeDef counterScaleX; /*!< Specifies the axis X conter scale. */
    FunctionalState debounceEnableX;      /*!< Specifies the axis X debounce.
                                                   This parameter can be a value of ENABLE or DISABLE. */
    uint16_t debounceTimeX;               /*!< Specifies the axis X debounce time. */
    AONQDECInitPhase_TypeDef initPhaseX;  /*!< Specifies the axis X function. */
} AON_QDEC_InitTypeDef;

/** End of AON_QDEC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup AON_QDEC_Exported_Functions AON_QDEC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Initializes the AON Qdecoder peripheral according to the specified
 *          parameters in the AON_QDEC_InitStruct
 *
 * \param[in]  AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in]  AON_QDEC_InitStruct: Pointer to a AON_QDEC_InitStruct structure that
 *             contains the configuration information for the specified AON Qdecoder peripheral
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_aon_qdec_init(void)
 * {
 *
 *     AON_QDEC_InitTypeDef AON_QDEC_InitStruct;
 *     AON_QDEC_StructInit(&AON_QDEC_InitStruct);
 *     AON_QDEC_InitStruct.axisConfigX       = ENABLE;
 *     AON_QDEC_InitStruct.debounceEnableX   = Debounce_Enable;
 *     AON_QDEC_Init(AON_QDEC, &AON_QDEC_InitStruct);
 *
 *     AON_QDEC_Cmd(AON_QDEC, AON_QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void AON_QDEC_Init(AON_QDEC_TypeDef *AON_QDECx, AON_QDEC_InitTypeDef *AON_QDEC_InitStruct);

/**
 * \brief  Fills each AON_QDEC_InitStruct member with its default value.
 *
 * \param[in]  AON_QDEC_InitStruct: Pointer to an AON_QDEC_InitStruct structure which will be initialized.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_aon_qdec_init(void)
 * {
 *
 *     AON_QDEC_InitTypeDef AON_QDEC_InitStruct;
 *     AON_QDEC_StructInit(&AON_QDEC_InitStruct);
 *     AON_QDEC_InitStruct.axisConfigX       = ENABLE;
 *     AON_QDEC_InitStruct.debounceEnableX   = Debounce_Enable;
 *     AON_QDEC_Init(AON_QDEC, &AON_QDEC_InitStruct);
 *
 *     AON_QDEC_Cmd(AON_QDEC, AON_QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void AON_QDEC_StructInit(AON_QDEC_InitTypeDef *AON_QDEC_InitStruct);

/**
 * \brief  Enable or disable the specified AON Qdecoder interrupt source.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_IT: Specifies the AON QDECODER interrupts sources to be enabled or disabled.
 *            This parameter parameter can be one of the following values:
 *            \arg AON_QDEC_X_INT_NEW_DATA: The counter interrupt for X axis.
 *            \arg AON_QDEC_X_INT_ILLEAGE: The illegal interrupt for X axis.
 * \param[in] NewState: New state of the specified QDECODER interrupt.
 *            This parameter parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_aon_qdec_init(void)
 * {
 *     AON_QDEC_INTConfig(AON_QDEC, AON_QDEC_X_INT_NEW_DATA, ENABLE);
 * }
 * \endcode
 */
void AON_QDEC_INTConfig(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_IT,
                        FunctionalState NewState);

/**
 * \brief  Check whether the specified AON Qdecoder flag is set.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_FLAG: Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            \arg AON_QDEC_FLAG_NEW_CT_STATUS_X: Status of the counter interrupt for X axis.
 *            \arg AON_QDEC_FLAG_ILLEGAL_STATUS_X: Status of the illegal interrupt for X axis.
 *            \arg AON_QDEC_FLAG_OVERFLOW_X: The overflow flag for x-axis accumulation counter.
 *            \arg AON_QDEC_FLAG_UNDERFLOW_X: The underflow flag for x-axis accumulation counter.
 *
 * \return The new state of AON_QDEC_FLAG (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     FlagStatus flag_status = AON_QDEC_GetFlagState(AON_QDEC, AON_QDEC_FLAG_NEW_CT_STATUS_X);
 * }
 * \endcode
 */
FlagStatus AON_QDEC_GetFlagState(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_FLAG);

/**
 * \brief  Enable or disable mask the specified AON Qdecoder axis interrupts.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_AXIS: Specifies the AON Qdecoder axis.
 *            This parameter can be one or logical OR of the following values:
 *            \arg AON_QDEC_X_CT_INT_MASK: The x-axis counter interrupt mask.
 *            \arg AON_QDEC_X_ILLEAGE_INT_MASK: The x-axis illegal interrupt mask.
 * \param[in] NewState: New state of the specified AON Qdecoder interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *
 *     AON_QDEC_INTMask(AON_QDEC, AON_QDEC_X_CT_INT_MASK, ENABLE);
 *
 * }
 * \endcode
 */
void AON_QDEC_INTMask(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_AXIS,
                      FunctionalState NewState);

/**
 * \brief  Enable or disable the selected AON Qdecoder axis x.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_AXIS: Specifies the AON Qdecoder axis.
 *            This parameter can be one of the following values:
 *            \arg AON_QDEC_AXIS_X: The AON qdecoder X axis.
 * \param[in] NewState: New state of the selected AON Qdecoder axis.
 *            This parameter can be : ENABLE or DISABLE.
 *
 * \return The count of the axis.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     AON_QDEC_Cmd(AON_QDEC, AON_QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void AON_QDEC_Cmd(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_AXIS,
                  FunctionalState NewState);

/**
 * \brief   Clear AON Qdecoder interrupt pending bit.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_FLAG: Specifies the flag to clear.
 *            This parameter parameter can be one of the following values:
 *            \arg AON_QDEC_CLR_OVERFLOW_X: The overflow flag for x-axis accumulation counter.
 *            \arg AON_QDEC_CLR_ILLEGAL_INT_X: The illegal interrupt for X axis.
 *            \arg AON_QDEC_CLR_UNDERFLOW_X: The underflow flag for x-axis accumulation counter.
 *            \arg AON_QDEC_CLR_NEW_CT_X: The counter interrupt for X axis.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     AON_QDEC_ClearINTPendingBit(AON_QDEC, AON_QDEC_CLR_OVERFLOW_X);
 * }
 * \endcode
 */

void AON_QDEC_ClearINTPendingBit(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_CLR_INT);
/**
 * \brief  Get AON Qdecoder Axis(x/y/z) direction.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_AXIS: Specifies the AON Qdecoder axis.
 *            This parameter parameter can be one of the following values:
 *            \arg  AON_QDEC_AXIS_X: The AON qdecoder X axis.
 *
 * \return The direction of the axis.
 * \retval AON_QDEC_AXIS_DIR_UP: The axis is rolling up.
 * \retval AON_QDEC_AXIS_DIR_DOWN: The axis is rolling down.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     uint16_t dir = AON_QDEC_GetAxisDirection(AON_QDEC, AON_QDEC_AXIS_X);
 * }
 * \endcode
 */
uint16_t AON_QDEC_GetAxisDirection(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_AXIS);

/**
 * \brief  Get AON Qdecoder Axis(x/y/z) count.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_AXIS: Specifies the AON Qdecoder axis.
 *            This parameter parameter can be one of the following values:
 *            \arg AON_QDEC_AXIS_X: The AON qdecoder X axis.
 *
 * \return The count of the axis.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     uint16_t counter = AON_QDEC_GetAxisCount(AON_QDEC, AON_QDEC_AXIS_X);
 * }
 * \endcode
 */
uint16_t AON_QDEC_GetAxisCount(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_AXIS);

/**
 * \brief  Pause or resume AON Qdecoder Axis x.
 *
 * \param[in] AON_QDECx: Selected AON Qdecoder peripheral.
 * \param[in] AON_QDEC_AXIS: Specifies the AON Qdecoder axis.
 *            This parameter parameter can be one of the following values:
 *            \arg AON_QDEC_AXIS_X: The AON qdecoder X axis.
 * \param[in] NewState: New state of the specified AON Qdecoder Axis.
 *            This parameter parameter can be one of the following values:
 *            \arg ENABLE: Pause.
 *            \arg DISABLE: Resume.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void aon_qdec_demo(void)
 * {
 *     AON_QDEC_CounterPauseCmd(AON_QDEC, AON_QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void AON_QDEC_CounterPauseCmd(AON_QDEC_TypeDef *AON_QDECx, uint32_t AON_QDEC_AXIS,
                              FunctionalState NewState);

/** End of AON_QDEC_Exported_Functions
  * \}
  */

/** End of AON_QDEC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_AON_QDEC_H */


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/

