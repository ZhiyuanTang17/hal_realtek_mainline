/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _UTILS_NSC_H_
#define _UTILS_NSC_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdbool.h>
#include <stdint.h>
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#include "cmsis_armclang.h"
#endif

#define PLATFORM_STATIC_ASSERT(condition, identifier) typedef char PALStaticAssert_##identifier[(condition) ? 1 : -1]

#define DIVIDE_AND_ROUND(dividend, divisor)     (((dividend) + ((divisor) >> 1)) / (divisor))

#define DIVIDE_AND_ROUNDUP(dividend, divisor)   (((dividend) + ((divisor) - 1)) / (divisor))

/*============================================================================*
 *                              Variables
 *============================================================================*/
typedef enum
{
    PERION_000_NS     = 0x01,
    PERION_004_NS     = 0x02,
    PERION_008_NS     = 0x04,
    PERION_00C_NS     = 0x08,
    PERION_010_NS     = 0x10,
    PERION_014_NS     = 0x20,
    PERION_018_NS     = 0x40,
    PERION_020_NS     = 0x80,
    PERION_024_NS     = 0x100,
    PERION_028_NS     = 0x200,
    PERION_02C_NS     = 0x400,
    PERION_SPIC0_NS   = 0x800,
    PERION_SPIC1_NS   = 0x1000,
    PERION_SPIC2_NS   = 0x2000,
    PERION_RSVD       = 0x4000,
    PERION_400_NS     = 0x8000,
    PERION_ALL_NS     = 0xFFFF,
} PERION_NS_ACCESS_PERMISSION;


/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup UTILS_Exported_Functions Platform Utils Exported Functions
    * @brief
    * @{
    */

/**
 * @brief Generate random number given max number allowed
 * @param max   to specify max number that allowed
 * @return random number
 */

uint32_t platform_random(uint32_t max);

void deinit_swd_pinmux(void);

void setup_non_secure_nvic(void);

bool get_disable_hci_set_uart_baudrate(void);
bool get_disable_hci_rf_dbg_func(void);
bool get_disable_hci_read_chip_info(void);
bool get_disable_hci_bt_extension(void);
bool get_airplane_mode(void);
void set_airplane_mode(bool airplane_mode);
bool get_disable_hci_flash_access(void);
bool get_disable_hci_system_access(void);
bool get_disable_hci_efuse_access(void);
bool get_timer_clk_src_from_40m(void);
bool get_disable_hci_wifi_coexist_func(void);
bool get_disable_hci_bt_test(void);
uint8_t get_default_hci_rx_pin(void);
uint8_t get_default_hci_tx_pin(void);
uint8_t get_stack_patch_valid(void);
uint32_t get_stack_patch_rom_header_addr(void);
void update_cpu_tick_to_us_nsc(uint32_t cpu_freq);
void enable_nonsecure_access_peri_on_register(PERION_NS_ACCESS_PERMISSION perm_bitmap, bool enable);
uint32_t get_occd_addr(void);
uint32_t get_occd_size(void);
uint32_t get_extra_occd_addr(void);
uint32_t get_extra_occd_size(void);

/** @} */ /* End of group UTILS_Exported_Functions */


/** @} */ /* End of group UTILS */

#ifdef __cplusplus
}
#endif

#endif

