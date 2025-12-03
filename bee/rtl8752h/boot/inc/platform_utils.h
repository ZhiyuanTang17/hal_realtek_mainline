/**
*****************************************************************************************
*               Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
************************************************************************************************************
  * @file    platform_utils.h
  * @brief   utility helper function for user application
  * @author  lory_xu
  * @date    2017-02
  * @version v1.0
  ***************************************************************************************
    * @attention
  * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
  ***************************************************************************************
  */

#ifndef _PLATFORM_UTILS_H_
#define _PLATFORM_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "rtl876x.h"

/** @defgroup  PLATFORM_UTILS Platform Utilities
    * @brief Utility helper functions
    * @{
    */

#if (PLATFORM_SUPPORT_CLOCK_MANAGER == 1)
#include "clock_manager.h"
#else
#define CLOCK_100MHZ    100000000
#define CLOCK_90MHZ     90000000
#define CLOCK_40MHZ     40000000
#define CLOCK_53MHZ     53333333
#define CLOCK_80MHZ     80000000
#define CLOCK_20MHZ     20000000
#define CLOCK_10MHZ     10000000
#define CLOCK_5MHZ      5000000
#define CLOCK_2P5MHZ    2500000
#define CLOCK_1P25MHZ   1250000
#define CLOCK_625KHZ    625000
#endif

/*============================================================================*
 *                              Macros
 *============================================================================*/
#ifndef ABS
#define ABS(x)     (((x) > 0) ? (x) : ((~(x))+1))
#endif

#define CLOCK_COUNT_DIFF(clk_begin, clk_end, bit_mask) (((((uint64_t)clk_end & ((uint64_t)bit_mask - 1)) | (uint64_t)bit_mask) - ((uint64_t)clk_begin & ((uint64_t)bit_mask - 1))) & ((uint64_t)bit_mask - 1))

#define VENDOR_COUNTER_BASE_ADDRESS 0x40006000

#define VENDOR_COUNTER_READ(Vendor_offset) \
    ((uint32_t)*((volatile uint32_t*)(VENDOR_COUNTER_BASE_ADDRESS+(Vendor_offset))))
#define VENDOR_COUNTER_WRITE(Vendor_offset, Value) \
    ((*((volatile uint32_t*)(VENDOR_COUNTER_BASE_ADDRESS + (Vendor_offset)))) = (Value))

//#define count_1bits(x) (uint8_t)__builtin_popcount(x)

#define CPU_CNT_BIT_NUM             BIT64(32)

#define PF_RTC_BIT_NUM              BIT64(32)

#define BUILD_BUG_ON_ZERO(e)  (sizeof(struct { int _; int:-!!(e); }) - sizeof(struct { int _; }))

#ifndef SAME_TYPE
#define SAME_TYPE(a, b)  __builtin_types_compatible_p(typeof(a), typeof(b))
#endif

#define MUST_BE_ARRAY(a)  BUILD_BUG_ON_ZERO(SAME_TYPE((a), &(*a)))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) ((sizeof(a) / sizeof(*a)) + MUST_BE_ARRAY(a))
#endif

#define EFUSE_INVALID_TXSCALEFACTOR 0xFE
#define EFUSE_INVALID_TXDAC_CURRENT 0xFE

#define PON_F00_REG                        0xF00  // struct: PON_F00_REG_S

typedef enum
{
    EXTERNAL_CLOCK  = 0,
    CORE_CLOCK      = 1
} SYSTICK_CLK_SRC_TYPE;

typedef union PON_F00_REG_S  /* Vendor 0xF00 */
{
    uint32_t d32;
    struct
    {
        uint32_t ind_32k_wdata: 16;     //[15:0]  R/W   (32k register write date. Read data)
        uint32_t ind_32k_addr: 6;       //[21:16] R/W   (32k register address)
        uint32_t ind_32k_rw: 1;         //[22]    W     (1: write 32k register)
        uint32_t rsvd: 9;               //[31:23] R/W
    };
} PON_F00_REG_S_TYPE;

/* ===================== AON State Machine Section ======================*/
#define pf_delay_us(us) platform_delay_us(us)

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup PLATFORM_UTILS_Exported_Functions Platform Utilities Exported Functions
    * @brief
    * @{
    */

/**
 * @brief Generate random number given max number allowed
 * @param max   to specify max number that allowed
 * @return random number
 */

extern uint32_t platform_random(uint32_t max);


/**
 * @brief Busy delay for specified millisecond
 * @param t   to specify t milliseconds to delay
 * @return none
 */
extern volatile void (*platform_delay_ms)(uint32_t t);

/**
 * @brief Busy delay for specified micro second
 * @param t   to specify t micro seconds to delay
 * @return none
 */
extern volatile void (*platform_delay_us)(uint32_t t);

/**
 * @brief Get the vendor timer tick

 * @param none
 * @return none
 * @note Features of the vendor timer:
 *         (1) clock rate is 40M
 *         (2) width is 26 bits (max 0x3FFFFFF)
 *         (3) tick counter is incremental
 *
 */
static inline uint32_t platform_vendor_tick(void)
{
    return HAL_READ32(VENDOR_REG_BASE, 0x30);
}

uint8_t count_1bits(uint32_t x);
int32_t saturate_by_boundary(int32_t value, int32_t upperbound, int32_t lowerbound);
uint32_t reverse_bits_in_word(uint32_t num);
bool true_function(void);
SYSTICK_CLK_SRC_TYPE get_sys_tick_clk_type(void);

/* =========================== vendor section ===========================*/
#define VENDOR_BASE_ADDRESS 0x40058000

#define VENDOR_REG_ADDR(offset) (VENDOR_BASE_ADDRESS + (offset))
#define VENDOR_READ(Vendor_offset) \
    ((uint32_t)*((volatile uint32_t*)(VENDOR_BASE_ADDRESS+(Vendor_offset))))
#define VENDOR_WRITE(Vendor_offset, Value) \
    ((*((volatile uint32_t*)(VENDOR_BASE_ADDRESS + (Vendor_offset)))) = (Value))
#define VENDOR_U16_READ(Vendor_offset) \
    ((uint16_t)*((volatile uint16_t*)(VENDOR_BASE_ADDRESS+(Vendor_offset))))
#define VENDOR_U16_WRITE(Vendor_offset, Value) \
    ((*((volatile uint16_t*)(VENDOR_BASE_ADDRESS + (Vendor_offset)))) = (Value))
#define VENDOR_BYTE_READ(Vendor_offset) \
    (*((volatile uint8_t*)(VENDOR_BASE_ADDRESS+(Vendor_offset))))
#define VENDOR_BYTE_WRITE(Vendor_offset, Value) \
    ((*((volatile uint8_t*)(VENDOR_BASE_ADDRESS + (Vendor_offset)))) = (Value))
#define VENDOR_U32_REG_UPDATE(Vendor_offset, Mask, Value) \
    {uint32_t temp; \
        temp = VENDOR_READ(Vendor_offset) & ~(Mask);\
        VENDOR_WRITE(Vendor_offset, (temp | ((Value) & (Mask))));}
#define VENDOR_U16_REG_UPDATE(Vendor_offset, Mask, Value) \
    {uint16_t temp; \
        temp = VENDOR_U16_READ(Vendor_offset) & ~(Mask);\
        VENDOR_U16_WRITE(Vendor_offset, (temp | ((Value) & (Mask))));}
#define VENDOR_U8_REG_UPDATE(Vendor_offset, Mask, Value) \
    {uint8_t temp; \
        temp = VENDOR_BYTE_READ(Vendor_offset) & ~(Mask);\
        VENDOR_BYTE_WRITE(Vendor_offset, (temp | ((Value) & (Mask))));}



__STATIC_INLINE uint32_t read_vendor_counter_no_display(void)
{
    return HAL_READ32(VENDOR_REG_BASE, 0x30);
}

extern void (*proprietary_set_enhance_timer)(bool enable, uint8_t cnt);

extern uint32_t (*get_stack_en)(void);

#define IS_USE_VHCI (get_stack_en())

extern uint32_t (*get_occd_addr)();
extern uint32_t (*get_occd_size)();
extern uint32_t (*get_extra_occd_addr)();
extern uint32_t (*get_extra_occd_size)();

bool get_disable_hci_read_chip_info(void);
bool get_disable_hci_bt_extension(void);
bool get_disable_hci_bt_dbg_func(void);
bool get_disable_hci_bt_test(void);
bool get_disable_hci_set_uart_baudrate(void);
bool get_disable_hci_wifi_coexist_func(void);
bool get_disable_hci_mac_rf_access(void);
bool get_disable_hci_flash_access(void);
bool get_disable_hci_system_access(void);
bool get_disable_hci_efuse_access(void);
bool get_disable_hci_rf_dbg_func(void);
bool get_disable_hci_rf_test(void);
uint8_t get_default_hci_rx_pin(void);
uint8_t get_default_hci_tx_pin(void);
bool get_airplane_mode(void);
void set_airplane_mode(bool airplane_mode);
bool get_timer_clk_src_from_40m(void);
uint8_t get_stack_patch_valid(void);
uint32_t get_stack_patch_rom_header_addr(void);

/** @} */ /* End of group PLATFORM_UTILS_Exported_Functions */

/** @} */ /* End of group PLATFORM_UTILS */


#ifdef __cplusplus
}
#endif

#endif

