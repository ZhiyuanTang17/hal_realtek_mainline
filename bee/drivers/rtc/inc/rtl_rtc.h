/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_RTC_H
#define RTL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "rtc/src/device/rtl87x2g/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "rtc/src/device/rtl87x3e/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "rtc/src/device/rtl87x3d/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "rtc/src/device/rtl87x2j/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3EU)
#include "rtc/src/device/rtl87x3eu/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "rtc/src/device/rtl87x3j/rtl_rtc_def.h"
#endif

/** \defgroup RTC         RTC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup RTC_Exported_Constants RTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    RTC_Compare_Index RTC Compare Index
 * \{
 * \ingroup     RTC_Exported_Constants
 */

typedef enum
{
    RTC_COMP0 = 0x00,
    RTC_COMP1 = 0x01,
    RTC_COMP2 = 0x02,
    RTC_COMP3 = 0x03,
} RTCCompIndex_TypeDef;

#define IS_RTC_COMPARE(COMP) (((COMP) == RTC_COMP0) || \
                              ((COMP) == RTC_COMP1) || \
                              ((COMP) == RTC_COMP2) || \
                              ((COMP) == RTC_COMP3))

/** End of RTC_Compare_Index
  * \}
  */

/**
 * \defgroup    RTC_Interrupts RTC Interrupts
 * \{
 * \ingroup     RTC_Exported_Constants
 */
#define RTC_INT_TICK                (BIT8)
#define RTC_INT_OVERFLOW            (BIT9)
#define RTC_INT_PRECOMP             (BIT10)
#define RTC_INT_PRECOMP_COMP3       (BIT11)
#define RTC_INT_COMP0               (BIT16)
#define RTC_INT_COMP1               (BIT17)
#define RTC_INT_COMP2               (BIT18)
#define RTC_INT_COMP3               (BIT19)

#define IS_RTC_INTERRUPT(INT)       (((INT) == RTC_INT_TICK) || \
                                     ((INT) == RTC_INT_OVERFLOW) || \
                                     ((INT) == RTC_INT_PRECOMP) || \
                                     ((INT) == RTC_INT_PRECOMP_COMP3) || \
                                     ((INT) == RTC_INT_COMP0) || \
                                     ((INT) == RTC_INT_COMP1) || \
                                     ((INT) == RTC_INT_COMP2) || \
                                     ((INT) == RTC_INT_COMP3))

/** End of RTC_Interrupts
  * \}
  */

/**
 * \defgroup    RTC_WakeUp RTC WakeUp
 * \{
 * \ingroup     RTC_Exported_Constants
 */
#if (RTC_SUPPORT_WAKEUP_MORE_SOURCE == 1)
#define RTC_WAKEUP_TICK             (BIT8)
#define RTC_WAKEUP_OVERFLOW         (BIT9)
#define RTC_WAKEUP_PRECOMP          (BIT10)
#define RTC_WAKEUP_PRECOMP_COMP3    (BIT11)
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
#define RTC_WAKEUP_COMP0GT          (BIT12)
#define RTC_WAKEUP_COMP1GT          (BIT13)
#define RTC_WAKEUP_COMP2GT          (BIT14)
#define RTC_WAKEUP_COMP3GT          (BIT15)
#endif

#define RTC_WAKEUP_COMP0            (BIT20)
#define RTC_WAKEUP_COMP1            (BIT21)
#define RTC_WAKEUP_COMP2            (BIT22)
#define RTC_WAKEUP_COMP3            (BIT23)

#if (RTC_SUPPORT_WAKEUP_MORE_SOURCE == 1)
#define IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP) (((WAKEUP) == RTC_WAKEUP_TICK) || \
                                           ((WAKEUP) == RTC_WAKEUP_OVERFLOW) || \
                                           ((WAKEUP) == RTC_WAKEUP_PRECOMP) || \
                                           ((WAKEUP) == RTC_WAKEUP_PRECOMP_COMP3))
#else
#define IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP) (0)
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
#define IS_RTC_WAKEUP_COMPGT(WAKEUP)      (((WAKEUP) == RTC_WAKEUP_COMP0GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP1GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP2GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP3GT))
#else
#define IS_RTC_WAKEUP_COMPGT(WAKEUP)      (0)
#endif

#define IS_RTC_WAKUP(WAKEUP)              (((WAKEUP) == RTC_WAKEUP_COMP0) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP1) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP2) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP3) || \
                                           (IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP)) || \
                                           (IS_RTC_WAKEUP_COMPGT(WAKEUP)))
/** End of RTC_WakeUp
  * \}
  */


#if (RTC_SUPPORT_RAP_FUNCTION == 1)
/**
 * \defgroup    RTC_Action RTC Action
 * \{
 * \ingroup     RTC_Exported_Constants
 */
typedef enum
{
    RTC_ACTION_START = 0,
    RTC_ACTION_STOP  = 1,
    RTC_ACTION_CLEAR = 2,
    RTC_ACTION_RELOAD_COMP0 = 3,
    RTC_ACTION_RELOAD_COMP1 = 4,
    RTC_ACTION_RELOAD_COMP2 = 5,
    RTC_ACTION_RELOAD_COMP3 = 6,
} RTCAction_TypeDef;

/** End of RTC_Action
  * \}
  */

/**
 * \defgroup    RTC_Event RTC Event
 * \{
 * \ingroup     RTC_Exported_Constants
 */
typedef enum
{
    RTC_EVENT_COMP0 = 0,
    RTC_EVENT_COMP1 = 1,
    RTC_EVENT_COMP2 = 2,
    RTC_EVENT_COMP3 = 3,
} RTCEvent_TypeDef;

/** End of RTC_Event
  * \}
  */
#endif

/** End of RTC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup RTC_Exported_Functions RTC Exported Functions
  * \brief
  * \{
  */
/**
 * \brief     Deinitializes the RTC peripheral registers to their default reset values(turn off clock).
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 * }
 * \endcode
 */
void RTC_DeInit(void);

/**
 * \brief     Set RTC prescaler value.
 *
 * \param[in] Vaule: The prescaler value to be set.Should be no more than 12 bits!
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetPrescaler(uint16_t Vaule);

/**
 * \brief     Start or stop RTC peripheral.
 *
 * \param[in] NewState: New state of RTC peripheral.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Start RTC.
 *            \arg DISABLE: Stop RTC.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_Cmd(FunctionalState NewState);

/**
 * \brief     Enable or disable the specified RTC interrupt source.
 *
 * \param[in] RTC_INT: Specifies the RTC interrupt source which to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_INT_TICK: Tick interrupt source.
 *            \arg RTC_INT_OVERFLOW: counter overflow interrupt
 *            \arg RTC_INT_COMP0: Compare 0 interrupt source.
 *            \arg RTC_INT_COMP1: Compare 1 interrupt source.
 *            \arg RTC_INT_COMP2: Compare 2 interrupt source.
 *            \arg RTC_INT_COMP3: Compare 3 interrupt source.
 *            \arg RTC_INT_PRECOMP: Prescale compare interrupt source.
 *            \arg RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 * \param[in] NewState: New state of the specified RTC interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_INTConfig(uint32_t RTC_INT, FunctionalState NewState);

/**
 * \brief  Enable or disable the specified RTC wakeup function.
 *
 * \param[in] RTC_WAKEUP: specifies the RTC wakeup function to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_WAKEUP_TICK: tick wakeup function
 *            \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
 *            \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
 *            \arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
 *            \arg RTC_WAKEUP_COMP0GT: compare 0 gt wakeup function
 *            \arg RTC_WAKEUP_COMP1GT: compare 1 gt wakeup function
 *            \arg RTC_WAKEUP_COMP2GT: compare 2 gt wakeup function
 *            \arg RTC_WAKEUP_COMP3GT: compare 3 gt wakeup function
 *            \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
 *            \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
 *            \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
 *            \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
 * \param[in] NewState: new state of the specified RTC wakeup function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_WakeUpConfig(uint32_t RTC_WAKEUP, FunctionalState NewState);

/**
 * \brief     Enable RTC interrupt signal to CPU NVIC.
 *
 * \param[in] NewState: Enable or disable RTC interrupt signal to MCU.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_NVICCmd(FunctionalState NewState);

/**
 * \brief     Enable or disable system wake up function of RTC.
 *
 * \param[in] NewState: new state of the wake up function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_WakeUpConfig(ENABLE);
 * }
 * \endcode
 */
void RTC_WakeUpCmd(FunctionalState NewState);

/**
 * \brief  Check whether the specified RTC interrupt is set.
 *
 * \param[in] RTC_INT: Specifies the RTC interrupt source to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_INT_TICK: RTC tick interrupt source.
 *            \arg RTC_INT_COMP0: Compare 0 interrupt source.
 *            \arg RTC_INT_COMP1: Compare 1 interrupt source.
 *            \arg RTC_INT_COMP2: Compare 2 interrupt source.
 *            \arg RTC_INT_COMP3: Compare 3 interrupt source.
 *            \arg RTC_INT_PRECOMP: Prescale compare interrupt source.
 *            \arg RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 *
 * \return The new state of RTC_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     ITStatus int_status = RTC_GetINTStatus(RTC_INT_COMP0);
 * }
 * \endcode
 */
ITStatus RTC_GetINTStatus(uint32_t RTC_INT);

/**
 * \brief  Checks whether the specified RTC wakeup state is set or not.
 *
 * \param[in] RTC_WAKEUP: specifies the RTC interrupt source to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_WAKEUP_TICK: tick wakeup function
 *            \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
 *            \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
 *            \arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
 *            \arg RTC_WAKEUP_COMP0GT: compare 0 gt wakeup function
 *            \arg RTC_WAKEUP_COMP1GT: compare 1 gt wakeup function
 *            \arg RTC_WAKEUP_COMP2GT: compare 2 gt wakeup function
 *            \arg RTC_WAKEUP_COMP3GT: compare 3 gt wakeup function
 *            \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
 *            \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
 *            \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
 *            \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
 *
 * \return The new state of RTC_INT (SET or RESET).
 */
ITStatus RTC_GetWakeUpStatus(uint32_t RTC_WAKEUP);

/**
 * \brief     Clear the interrupt pending bits of RTC.
 *
 * \param[in] RTC_INT: specifies the RTC interrupt flag to clear.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_INT_TICK: RTC tick interrupt source.
 *            \arg RTC_INT_OVERFLOW: RTC counter overflow interrupt source.
 *            \arg RTC_INT_COMP0: Compare 0 interrupt source.
 *            \arg RTC_INT_COMP1: Compare 1 interrupt source.
 *            \arg RTC_INT_COMP2: Compare 2 interrupt source.
 *            \arg RTC_INT_COMP3: Compare 3 interrupt source.
 *            \arg RTC_INT_PRECOMP: Prescale compare interrupt source.
 *            \arg RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearINTPendingBit(RTC_INT_COMP0);
 * }
 * \endcode
 */
void RTC_ClearINTPendingBit(uint32_t RTC_INT);

/**
 * \brief  Clear the wakeup status bits of RTC.
 *
 * \param[in] RTC_WAKEUP: specifies the RTC wakeup flag to clear.
 *            This parameter can be any combination of the following values:
 *            \arg RTC_WAKEUP_TICK: tick wakeup function
 *            \arg RTC_WAKEUP_OVERFLOW: tick wakeup function
 *            \arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
 *            \arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
 *            \arg RTC_WAKEUP_COMP0GT: compare 0 gt wakeup function
 *            \arg RTC_WAKEUP_COMP1GT: compare 1 gt wakeup function
 *            \arg RTC_WAKEUP_COMP2GT: compare 2 gt wakeup function
 *            \arg RTC_WAKEUP_COMP3GT: compare 3 gt wakeup function
 *            \arg RTC_WAKEUP_COMP0: compare 0 wakeup function
 *            \arg RTC_WAKEUP_COMP1: compare 1 wakeup function
 *            \arg RTC_WAKEUP_COMP2: compare 2 wakeup function
 *            \arg RTC_WAKEUP_COMP3: compare 3 wakeup function
 *
 * \return None.
 */
void RTC_ClearWakeUpStatusBit(uint32_t RTC_WAKEUP);

/**
 * \brief     Clear the interrupt pending bit of the select comparator of RTC.
 *
 * \param[in] Index: the comparator number.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearCompINT(0);
 * }
 * \endcode
 */
void RTC_ClearCompINT(RTCCompIndex_TypeDef Index);

/**
 * \brief     Clear the overflow interrupt pending bit of RTC.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearOverFlowINT();
 * }
 * \endcode
 */
void RTC_ClearOverFlowINT(void);

/**
 * \brief     Clear the tick interrupt pending bit of RTC.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearTickINT();
 * }
 * \endcode
 */
void RTC_ClearTickINT(void);

/**
 * \brief     Set RTC comparator value.
 *
 * \param[in] Index: The comparator number,can be 0 ~ 3.
 * \param[in] Vaule: The comparator value to be set.Should be no more than 24 bits!
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetCompValue(RTCCompIndex_TypeDef Index, uint32_t Vaule);

/**
 * \brief     Get RTC comparator value.
 *
 * \param[in] Index: The comparator number.
 *
 * \return    The comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompValue(RTC_COMP0);
 * }
 * \endcode
 */
uint32_t RTC_GetCompValue(RTCCompIndex_TypeDef Index);

/**
 * \brief     Set RTC prescaler comparator value.
 *
 * \param[in] Vaule: The comparator value to be set.Should be no more than 12 bits!
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     (3200 - 1)//max 4095
 * #define RTC_PRECOMP_VALUE       (320)//max 4095
 * #define RTC_COMP3_VALUE         (10)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetPreCompValue(RTC_PRECOMP_VALUE);
 *     RTC_SetCompValue(RTC_COMP3, RTC_COMP3_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_INT_PRECOMP_COMP3, DISABLE);
 *     RTC_INTConfig(RTC_INT_PRECOMP_COMP3, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetPreCompValue(uint32_t Vaule);

/**
 * \brief     Get RTC prescaler comparator value.
 *
 * \param[in] None.
 *
 * \return    The prescaler comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t data = RTC_GetPreCompValue();
 * }
 * \endcode
 */
uint32_t RTC_GetPreCompValue(void);

/**
 * \brief     Reset counter value of RTC.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetCounter();
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_ResetCounter(void);

/**
 * \brief     Get counter value of RTC.
 *
 * \param[in] None.
 *
 * \return    The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t counter = RTC_GetCounter();
 * }
 * \endcode
 */
uint32_t RTC_GetCounter(void);

/**
 * \brief     Reset prescaler counter value of RTC.
 *
 * \param[in] None.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetPrescalerCounter();
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_ResetPrescalerCounter(void);

/**
 * \brief     Get prescaler counter value of RTC.
 *
 * \param[in] None.
 *
 * \return    The prescaler counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t pre_counter = RTC_GetPreCounter();
 * }
 * \endcode
 */
uint32_t RTC_GetPreCounter(void);

/**
 * \brief     Write backup register for store time information.
 *
 * \param[in] Vaule: valuer=write to back up reister
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_SetBackupReg(0x01020304);
 * }
 * \endcode
 */
void RTC_SetBackupReg(uint32_t Vaule);

/**
 * \brief     Read backup register.
 *
 * \param[in] None.
 *
 * \return    Register value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t reg_data = RTC_GetBackupReg();
 * }
 * \endcode
 */
uint32_t RTC_GetBackupReg(void);

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
/**
 * \brief     Set RTC comparator auto reload value.
 *
 * \param[in] Index: The comparator number,can be 0 ~ 3.
 * \param[in] Vaule: The comparator value to be set.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_COMP_INDEX          RTC_COMP3
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_SetCompReloadValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 * }
 * \endcode
 */
void RTC_SetCompReloadValue(RTCCompIndex_TypeDef Index, uint32_t Vaule);

/**
 * \brief     Get RTC comparator auto reload value.
 *
 * \param[in] Index: The comparator number.
 *
 * \return    The comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompReloadValue(RTC_COMP0);
 * }
 * \endcode
 */
uint32_t RTC_GetCompReloadValue(RTCCompIndex_TypeDef Index);

/**
 * \brief     Enable RTC comparator auto reload.
 * When the counter value reaches the value of comparator, it automatically adds the compare value,
 * which equals Current Compare + Reload Value.
 * \param[in] comp_value: The initialize value of comparator.
 * \param[in] reload_value: The comparator auto reload value.
 *
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_EnableCompAutoReload(RTC_COMP0, 1000, 1000);
 * }
 * \endcode
 */
void RTC_EnableCompAutoReload(RTCCompIndex_TypeDef Index, uint32_t Comp_Value,
                              uint32_t Reload_Value);

/**
 * \brief     Disable RTC comparator auto reload.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DisableCompAutoReload(RTC_COMP0);
 * }
 * \endcode
 */
void RTC_DisableCompAutoReload(RTCCompIndex_TypeDef Index);
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
/**
 * \brief     Set RTC comparator GT value.
 *
 * \param[in] Index: The comparator gt number, can be 0 ~ 3.
 * \param[in] Vaule: The comparator value to be set.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_COMP_INDEX_INT, DISABLE);
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_NvCmd(ENABLE);
 *     RTC_Cmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetCompGTValue(RTCCompIndex_TypeDef Index, uint32_t Vaule);

/**
 * \brief     Get RTC comparator gt value.
 *
 * \param[in] Index: The comparator number 0~3.
 *
 * \return    The comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t data = RTC_GetCompGTValue(0);
 * }
 * \endcode
 */
uint32_t RTC_GetCompGTValue(RTCCompIndex_TypeDef Index);
#endif

#if (RTC_SUPPORT_RAP_FUNCTION == 1)

void RTC_RAPModeCmd(FunctionalState NewState);

void RTC_ActionTrigger(uint32_t Action);

void RTC_ShortcutCmd(uint32_t Action, uint32_t Event, FunctionalState NewState);

#endif

#if (RTC_SUPPORT_CLOCK_IN_FROM_OUTSIDE_PAD == 1)
/**
 * \brief  Enable or disable using external clock for RTC.
 *
 * \param[in]  ClockIn: Select which externel pad as RTC clock in.
 *
 * \param[in] NewState: Newstate of RTC peripheral.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockInCmd(PAD_RTC_IN_P0_1, ENABLE);
 * }
 * \endcode
 */
void RTC_ClockInCmd(RTCClockIn_TypeDef ClockIn, FunctionalState NewState);
#endif

#if (RTC_SUPPORT_CLOCK_OUT_TO_OUTSIDE_PAD == 1)
/**
 * \brief  Enable or disable the clock output to the pad for RTC.
 *
 * \param[in]  ClockOut: Select RTC clock output pad and type.
 *
 * \param[in] NewState: Newstate of RTC peripheral.
 *
 * \return None
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockOutCmd(RTC_CLOCK_OUT_P0_1_OSC, ENABLE);
 * }
 * \endcode
 */
void RTC_ClockOutCmd(RTCClockOut_TypeDef ClockOut, FunctionalState NewState);
#endif

/** End of RTC_Exported_Functions
  * \}
  */

/** End of RTC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_RTC_H */




