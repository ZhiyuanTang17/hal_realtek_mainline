/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
   * @file      platform_utils_int.h
   * @brief     utils header file for internal project
   * @details
   * @author
   * @date
   * @version
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
  *                   Define to prevent recursive inclusion
  *============================================================================*/
#ifndef _PLATFORM_UTILS_INT_H_
#define _PLATFORM_UTILS_INT_H_


/*============================================================================*
  *                               Header Files
  *============================================================================*/
#include "platform_utils.h"


/*============================================================================*
  *                                   Types
  *============================================================================*/

#define PF_RTC_BIT_NUM              BIT64(32)
#define VENDOR_CNT_BIT_NUM          BIT64(32)

typedef enum
{
    ROUND                   = 0,
    ROUNDUP                 = 1,
    ROUNDDOWN               = 2,
} RoundType;


/*============================================================================*
  *                                Functions
  *============================================================================*/


/************************************ assert ************************************/

#define PLATFORM_ASSERT(x) configASSERT(x)
#define EMPTY_FUNCTION  empty_function

extern void empty_function(void);

extern volatile void (*platform_delay_ms)(uint32_t t);
extern volatile void (*platform_delay_us)(uint32_t t);
extern uint32_t (*cal_quotient_remainder)(const uint64_t divisor_upper,
                                          const uint64_t divisor_lower,
                                          const uint32_t dividend, uint32_t *remainder);
void sw_delay_func_reinit(uint32_t SysCpuClk);
uint32_t read_cpu_counter(void);

#define US_TO_CPU_CLK(us, residual)\
    cal_quotient_remainder(1000000, SystemCpuClock, us, &residual)

#define CPU_CLK_TO_US(cpu_clk)\
    cal_quotient_remainder(SystemCpuClock, 1000000, cpu_clk, NULL)

#define DIVIDE_AND_ROUND(dividend, divisor)     ((dividend + (divisor >> 1)) / divisor)
#define DIVIDE_AND_ROUNDUP(dividend, divisor)   ((dividend + (divisor - 1)) / divisor)

uint64_t clk_cnt_diff(uint64_t clk_begin, uint64_t clk_end, uint64_t bit_mask);
bool clk_cnt_cmp(uint64_t clk_begin, uint64_t clk_end_1, uint64_t clk_end_2, uint64_t bit_mask);

uint32_t us_to_rtc_clk(uint32_t us, RoundType round_type);

uint32_t rtc_clk_to_us(uint32_t rtc_clk, RoundType round_type);


#define DEFAULT_HCI_UART_RX                                 P3_1
#define DEFAULT_HCI_UART_TX                                 P3_0

#endif
