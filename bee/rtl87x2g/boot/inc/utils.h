/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _UTILS_NS_H_
#define _UTILS_NS_H_

#ifdef __cplusplus
extern "C" {
#endif
/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "utils_nsc.h"

/** @defgroup PLATFORM_UTILS  Platform utils
  * @brief
  * @{
  */

/*============================================================================*
 *                              Macros
 *============================================================================*/
/** @defgroup PLATFORM_UTILS_Exported_Macros Platform utils Exported Macros
  * @brief
  * @{
  */

#ifndef ABS
#define ABS(x)     (((x) > 0) ? (x) : ((~(x))+1))
#endif

#define BIT64(_n)   (1ULL << (_n))

#define DIVIDE_AND_ROUND(dividend, divisor)     (((dividend) + ((divisor) >> 1)) / (divisor))

#define DIVIDE_AND_ROUNDUP(dividend, divisor)   (((dividend) + ((divisor) - 1)) / (divisor))

#define CLOCK_COUNT_DIFF(clk_begin, clk_end, bit_mask) (((((uint64_t)clk_end & ((uint64_t)bit_mask - 1)) | (uint64_t)bit_mask) - ((uint64_t)clk_begin & ((uint64_t)bit_mask - 1))) & ((uint64_t)bit_mask - 1))

#define VENDOR_COUNTER_BASE_ADDRESS 0x40006000

#define VENDOR_COUNTER_READ(Vendor_offset) \
    ((uint32_t)*((volatile uint32_t*)(VENDOR_COUNTER_BASE_ADDRESS+(Vendor_offset))))
#define VENDOR_COUNTER_WRITE(Vendor_offset, Value) \
    ((*((volatile uint32_t*)(VENDOR_COUNTER_BASE_ADDRESS + (Vendor_offset)))) = (Value))

#define CPU_CNT_BIT_NUM             BIT64(32)

#define PF_RTC_BIT_NUM              BIT64(32)

#define PLATFORM_ASSERT(x) if( ( x ) == 0 ) { vAssertHandler(__FUNCTION__, __LINE__); }

#define BUILD_BUG_ON_ZERO(e)  (sizeof(struct { int _; int:-!!(e); }) - sizeof(struct { int _; }))
#ifndef SAME_TYPE
#define SAME_TYPE(a, b)  __builtin_types_compatible_p(typeof(a), typeof(b))
#endif
#define MUST_BE_ARRAY(a)  BUILD_BUG_ON_ZERO(SAME_TYPE((a), &(*a)))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) ((sizeof(a) / sizeof(*a)) + MUST_BE_ARRAY(a))
#endif
#ifndef hex2char
#define hex2char(val) ("0123456789abcdef"[(val) & 0xf])
#endif

#define count_1bits(x) (uint8_t)__builtin_popcount(x)
#define count_0bits(x) (32 - count_1bits(x))
#define check_inverse(data, inverse_data, mask) ((data ^ inverse_data) == mask)
#define SET_BIT(val, mask)          ((val) |=  (mask))
#define CLR_BIT(val, mask)          ((val)  &= ~(mask))

extern uint32_t (*get_SystemCpuClock)(void);

#define US_TO_CPU_CLK(us, residual)\
    cal_quotient_remainder(1000000, get_SystemCpuClock(), us, &residual)

#define CPU_CLK_TO_US(cpu_clk)\
    cal_quotient_remainder(get_SystemCpuClock(), 1000000, cpu_clk, NULL)

/** End of PLATFORM_UTILS_Exported_Macros
  * @}
  */

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup PLATFORM_UTILS_Exported_Types Platform utils Exported Types
  * @brief
  * @{
  */

typedef enum
{
    ROUND                   = 0,
    ROUNDUP                 = 1,
    ROUNDDOWN               = 2,
} RoundType;

typedef enum
{
    SYSTICK_EXTERNAL_CLOCK   = 0,
    SYSTICK_PROCESSOR_CLOCK  = 1
} SYSTICK_CLK_SRC_TYPE;

/** End of PLATFORM_UTILS_Exported_Types
  * @}
  */

/*============================================================================*
*                              Functions
*============================================================================*/
/** @defgroup PLATFORM_UTILS_Exported_Functions Platform utils Exported Functions
  * @brief
  * @{
  */

#if   defined ( __CC_ARM )
/**
 * @brief Busy delay for specified micro second
 * @param t   to specify t micro seconds to delay
 * @return none
 */
extern volatile void (*platform_delay_ms)(uint32_t t);
/**
 * @brief Busy delay for specified millisecond
 * @param t   to specify t milliseconds to delay
 * @return none
 */
extern volatile void (*platform_delay_us)(uint32_t t);
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) || defined (__GNUC__)
/**
 * @brief Busy delay for specified micro second
 * @param t   to specify t micro seconds to delay
 * @return none
 */
extern void (*platform_delay_ms)(uint32_t t);
/**
 * @brief Busy delay for specified millisecond
 * @param t   to specify t milliseconds to delay
 * @return none
 */
extern void (*platform_delay_us)(uint32_t t);
#endif

extern uint32_t (*cal_quotient_remainder)(const uint64_t, const uint64_t, const uint32_t,
                                          uint32_t *);

void empty_function(void);
bool true_function(void);
void *void_ptr_function(void);

extern void vAssertHandler(const char *pFuncName, uint32_t funcLine);

uint32_t reverse_bits_in_word(uint32_t num);
bool is_overlapped(uint32_t range0[2], uint32_t range1[2]);

uint64_t clk_cnt_diff(uint64_t clk_begin, uint64_t clk_end, uint64_t bit_mask);
bool clk_cnt_cmp(uint64_t clk_begin, uint64_t clk_end_1, uint64_t clk_end_2, uint64_t bit_mask);
uint32_t us_to_rtc_clk(uint32_t us, RoundType round_type);
uint32_t rtc_clk_to_us(uint32_t rtc_clk, RoundType round_type);
void dwt_cyccnt_init(void);
uint32_t read_cpu_counter(void);

SYSTICK_CLK_SRC_TYPE get_sys_tick_clk_type(void);

uint32_t get_SystemCoreClock(void);

extern uint32_t (*get_stack_en)(void);

void update_cpu_tick_to_us(uint32_t cpu_freq);

#define IS_USE_VHCI (get_stack_en())

/**
 * @brief Generate random number given max number allowed
 * @param max   to specify max number that allowed
 * @return random number
 */

uint32_t platform_random(uint32_t max);

/** End of PLATFORM_UTILS_Exported_Functions
  * @}
  */

/** End of PLATFORM_UTILS
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

