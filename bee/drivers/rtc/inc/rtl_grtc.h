/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_GRTC_H
#define RTL_GRTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "rtc/src/device/rtl87x2j/rtl_grtc_def.h"
#endif
#if defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "rtc/src/device/rtl87x3j/rtl_grtc_def.h"
#endif

/** \defgroup GRTC         GRTC
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup GRTC_Exported_Constants GRTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    GRTC_Comparator GRTC Comparator
 * \{
 * \ingroup     GRTC_Exported_Constants
 */
typedef enum
{
    GRTC_COMP0 = 0x00,
#if (GRTC_COMP_NUM > 1)
    GRTC_COMP1 = 0x01,
#endif
#if (GRTC_COMP_NUM > 2)
    GRTC_COMP2 = 0x02,
#endif
#if (GRTC_COMP_NUM > 3)
    GRTC_COMP3 = 0x03,
#endif
#if (GRTC_COMP_NUM > 4)
    GRTC_COMP4 = 0x04,
#endif
#if (GRTC_COMP_NUM > 5)
    GRTC_COMP5 = 0x05,
#endif
#if (GRTC_COMP_NUM > 6)
    GRTC_COMP6 = 0x06,
#endif
#if (GRTC_COMP_NUM > 7)
    GRTC_COMP7 = 0x07,
#endif
#if (GRTC_COMP_NUM > 8)
    GRTC_COMP8 = 0x08,
#endif
#if (GRTC_COMP_NUM > 9)
    GRTC_COMP9 = 0x09,
#endif
} GRTCCompIndex_TypeDef;

#define IS_GRTC_COMP(COMP)  ((COMP) < GRTC_COMP_NUM)

/** End of GRTC_Comparator
  * \}
  */


/**
 * \defgroup    GRTC_Interrupts GRTC Interrupts
 * \{
 * \ingroup     GRTC_Exported_Constants
 */
#define GRTC_INT_COMP0          BIT0
#if (GRTC_COMP_NUM > 1)
#define GRTC_INT_COMP1          BIT1
#endif
#if (GRTC_COMP_NUM > 2)
#define GRTC_INT_COMP2          BIT2
#endif
#if (GRTC_COMP_NUM > 3)
#define GRTC_INT_COMP3          BIT3
#endif
#if (GRTC_COMP_NUM > 4)
#define GRTC_INT_COMP4          BIT4
#endif
#if (GRTC_COMP_NUM > 5)
#define GRTC_INT_COMP5          BIT5
#endif
#if (GRTC_COMP_NUM > 6)
#define GRTC_INT_COMP6          BIT6
#endif
#if (GRTC_COMP_NUM > 7)
#define GRTC_INT_COMP7          BIT7
#endif
#if (GRTC_COMP_NUM > 8)
#define GRTC_INT_COMP8          BIT8
#endif
#if (GRTC_COMP_NUM > 9)
#define GRTC_INT_COMP9          BIT9
#endif

#define IS_GRTC_INT(INT)  ((INT) & (BIT(GRTC_COMP_NUM)  -1))

/** End of GRTC_Interrupts
  * \}
  */

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    GRTC_Action GRTC Action
 * \{
 * \ingroup     GRTC_Exported_Constants
 */
typedef enum
{
    GRTC_ACTION_RELOAD_COMP = 0,
} GRTCAction_TypeDef;

/** End of GRTC_Action
  * \}
  */
#endif

/** End of GRTC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup GRTC_Exported_Functions GRTC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Reset all registers of GRTC.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_DeInit();
 * }
 * \endcode
 */
void GRTC_DeInit(void);

/**
 * \brief     Enable or disable the specified GRTC interrupt.
 *
 * \param[in] GRTC_INT: Specifies the GRTC interrupt source which to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg GRTC_INT_COMP0: compare 0 interrupt source
 *            \arg GRTC_INT_COMP1: compare 1 interrupt source
 *            \arg GRTC_INT_COMP2: compare 2 interrupt source
 *            \arg GRTC_INT_COMP3: compare 3 interrupt source
 *            \arg GRTC_INT_COMP4: compare 4 interrupt source
 *            \arg GRTC_INT_COMP5: compare 5 interrupt source
 *            \arg GRTC_INT_COMP6: compare 6 interrupt source
 *            \arg GRTC_INT_COMP7: compare 7 interrupt source
 * \param[in] NewState: New state of the specified GRTC interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_grtc_init(void)
 * {
 *     GRTC_INTConfig(GRTC_COMP_INDEX_INT, ENABLE);
 * }
 * \endcode
 */
void GRTC_INTConfig(uint32_t GRTC_INT, FunctionalState NewState);

/**
 * \brief  Check whether the specified GRTC interrupt is set.
 *
 * \param[in] GRTC_INT: Specifies the GRTC interrupt source to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg GRTC_INT_COMP0: compare 0 interrupt source
 *            \arg GRTC_INT_COMP1: compare 1 interrupt source
 *            \arg GRTC_INT_COMP2: compare 2 interrupt source
 *            \arg GRTC_INT_COMP3: compare 3 interrupt source
 *            \arg GRTC_INT_COMP4: compare 4 interrupt source
 *            \arg GRTC_INT_COMP5: compare 5 interrupt source
 *            \arg GRTC_INT_COMP6: compare 6 interrupt source
 *            \arg GRTC_INT_COMP7: compare 7 interrupt source
 *
 * \return     The new state of GRTC_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     ITStatus int_status = GRTC_GetINTStatus(GRTC_INT_COMP0);
 * }
 * \endcode
 */
ITStatus GRTC_GetINTStatus(uint32_t GRTC_INT);

/**
 * \brief     Clear the interrupt pending bits of GRTC.
 *
 * \param[in] GRTC_INT: specifies the GRTC interrupt flag to clear.
 *            This parameter can be any combination of the following values:
 *            \arg GRTC_INT_COMP0: compare 0 interrupt source
 *            \arg GRTC_INT_COMP1: compare 1 interrupt source
 *            \arg GRTC_INT_COMP2: compare 2 interrupt source
 *            \arg GRTC_INT_COMP3: compare 3 interrupt source
 *            \arg GRTC_INT_COMP4: compare 4 interrupt source
 *            \arg GRTC_INT_COMP5: compare 5 interrupt source
 *            \arg GRTC_INT_COMP6: compare 6 interrupt source
 *            \arg GRTC_INT_COMP7: compare 7 interrupt source
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ClearINTPendingBit(GRTC_INT_COMP0);
 * }
 * \endcode
 */
void GRTC_ClearINTPendingBit(uint32_t GRTC_INT);

#if (GRTC_SUPPORT_ERROR_INTERRUPT == 1)
/**
 * \brief     Checks whether the specified GRTC error interrupt is set or not.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 *
 * \return    The new state of GRTC error interrupt (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     ITStatus int_status = GRTC_GetErrorINTStatus(GRTC_COMP0);
 * }
 * \endcode
 */
ITStatus GRTC_GetErrorINTStatus(GRTCCompIndex_TypeDef Index);

/**
 * \brief     Clear the error interrupt pending bits of GRTC.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ClearErrorINTPendingBit(GRTC_COMP0);
 * }
 * \endcode
 */
void GRTC_ClearErrorINTPendingBit(GRTCCompIndex_TypeDef Index);
#endif

#if (GRTC_SUPPORT_FORCE_QACTIVE == 1)
/**
 * \brief     Enable or Disable the GRTC force qactive function.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] NewState: new state of GRTC peripheral.
 *            This parameter can be the following values:
 *            \arg ENABLE: Enable GRTC force qactive function.
 *            \arg DISABLE: Disable GRTC force qactive function.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ForceQactiveCmd(GRTC_COMP0, ENABLE);
 * }
 * \endcode
 */
void GRTC_ForceQactiveCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);
#endif

/**
 * \brief     Set GRTC comparator value.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] Value: The comparator value.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define GRTC_COMP_INDEX          GRTC_COMP3
 * #define GRTC_COMP_VALUE          (1000)
 *
 * void driver_grtc_init(void)
 * {
 *     GRTC_SetCompValue(GRTC_COMP_INDEX, GRTC_COMP_VALUE);
 * }
 * \endcode
 */
void GRTC_SetCompValue(GRTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * \brief     Get GRTC comparator value.
 *
 * \param[in] Index: The comparator number.
 *
 * \return    The comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void grtc_demo(void)
 * {
 *     uint32_t data = GRTC_GetCompValue(GRTC_COMP0);
 * }
 * \endcode
 */
uint32_t GRTC_GetCompValue(GRTCCompIndex_TypeDef Index);

/**
 * \brief     Enable or Disable the GRTC comparator reload function.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] NewState: new state of GRTC peripheral.
 *            This parameter can be the following values:
 *            \arg ENABLE: start GRTC.
 *            \arg DISABLE: stop GRTC.
 *
 * \return    None.
 */
void GRTC_CompReloadCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

/**
 * \brief     Set GRTC comparator reload value.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] Value: The comparator reload value.
 *
 * \return    None.
 */
void GRTC_SetCompReloadValue(GRTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * \brief     Get GRTC comparator reload value.
 *
 * \param[in] Index: The comparator number.
 *
 * \return    The comparator reload value.
 */
uint32_t GRTC_GetCompReloadValue(GRTCCompIndex_TypeDef Index);

/**
 * \brief     Enable or Disable the GRTC function of sleep control.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] NewState: new state of GRTC peripheral.
 *            This parameter can be the following values:
 *            \arg ENABLE: start GRTC.
 *            \arg DISABLE: stop GRTC.
 *
 * \return    None.
 */
void GRTC_SleepCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

/**
 * \brief     Get GRTC sleep counter.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 *
 * \return    The sleep counter.
 */
uint32_t GRTC_GetSleepCounter(GRTCCompIndex_TypeDef Index);

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)

/**
 * \brief     Enable or Disable the GRTC RAP mode function.
 *
 * \param[in] Index: The comparator number which can be 0 ~ 7.
 * \param[in] NewState: new state of GRTC peripheral.
 *            This parameter can be the following values:
 *            \arg ENABLE: start GRTC.
 *            \arg DISABLE: stop GRTC.
 *
 * \return The result of config GRTC RAP mode function.
 *         \arg true: Config GRTC RAP mode function success.
 *         \arg false: The GRTC comp is not support RAP mode.
 */
bool GRTC_RAPModeCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

/**
 * \brief     Trigger a GRTC task.
 *
 * \param[in] Action: The task to be triggered.
 *
 * \return The result of trigger a GRTC task.
 *         \arg true: Config trigger a GRTC task success.
 *         \arg false: The GRTC comp is not support to trigger a GRTC task.
 */
bool GRTC_ActionTrigger(GRTCCompIndex_TypeDef Index, uint32_t Action);

#endif

/** End of GRTC_Exported_Functions
  * \}
  */

/** End of GRTC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GRTC_H */



