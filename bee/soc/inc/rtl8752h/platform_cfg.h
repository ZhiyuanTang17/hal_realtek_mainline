/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PLATFORM_CFG_H
#define _PLATFORM_CFG_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @struct EFUSE_PLATFORM_CONFIG_
 * @brief Platform EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
typedef struct EFUSE_PLATFORM_CONFIG_
{
    uint64_t trace_mask[4];              /* need to be put to first to avoid alignment access fault */

    uint16_t stack_en : 1;
    uint16_t cpu_sleep_en: 1;            /* default = 0 */
    uint16_t run_in_app : 1;             /* boot runs in app */
    uint16_t ftl_init_in_rom : 1;
    uint16_t rsvd0 : 12;

    uint32_t logPin : 6;                 /* default = P0_3 */
    uint32_t logChannel : 2;             /* LogChannel_TypeDef: default is LOG_CHANNEL_LOG1_UART */
    uint32_t logBaudRate : 5;            /* UartBaudRate_TypeDef: default is BAUD_RATE_2000000 */
    uint32_t enableROMMPU : 1;           /* protect rom as Read-only region, default = 1 */
    uint32_t logThreshold : 3;           /* Log threshold: default = 3 (256 = 1 << (5 + 3) */
    uint32_t logDisable : 1;             /* Disable all DBG_DIRECT and DBG_BUFFER log */

    /* rsvd more */
} __attribute__((packed)) SYS_INIT_CONFIG;

extern SYS_INIT_CONFIG sys_init_cfg;

typedef struct __attribute__((packed)) _FLASH_NOR_QUERY_INFO_STRUCT
{
    /* If tbbo equals to 0x7F means BP supports lock all, lock half, lock none,
       and if tbbo equals to 0xFF means BP only supports lock all, lock none */
    /* If adsbo equals to 0xFF means flash size is smaller than 16MB, so only
       needs 3 bytes address */
    uint32_t flash_size;                /* Nor flash size in byte */
    uint8_t qebo;                       /* QE bit offset in status register */
    uint8_t wsbo;                       /* Write suspend flag bit offset in status register */
    uint8_t esbo;                       /* Erase suspend flag bit offset in status register */
    uint8_t tbbo;                       /* Top-bottom bit offset in status register */
    uint8_t cmpbo;                      /* Complement bit offset in status register */
    uint8_t adsbo;                      /* Current address mode bit offset in status register */
    uint8_t bp_all;                     /* Block protect all level in status register */
    uint8_t bp_mask;                    /* Block protect configurable bit mask in status register */
    uint32_t resume_to_suspend_delay_us;/* Delay time for a resume command to next suspend command */
} FLASH_NOR_QUERY_INFO_STRUCT;

typedef struct __attribute__((packed)) _FLASH_NOR_QUERY_INFO_TABLE_STRUCT
{
    uint8_t manu_id;
    uint16_t device_id;
    uint8_t flash_info; // BIT0 = is_sr2_exist
    FLASH_NOR_QUERY_INFO_STRUCT query;
} FLASH_NOR_QUERY_INFO_TABLE_STRUCT;

typedef struct _FLASH_NOR_SETTINGS_CFG
{
    uint32_t flash_cmd_list_len : 2;
    uint32_t flash_busy_wait_tick : 6;
    uint32_t hpm_en : 1;
    uint32_t is_4_byte_address_mode : 1;
    uint32_t init_cmd_from_cfg : 1;
    uint32_t init_query_from_cfg : 1;
    uint32_t flash_dma_ch : 4;
    uint32_t flash_dma_ch_priority : 8;
    uint32_t flash_dma_irq_priority : 8;

    uint32_t wait_max_retry : 27;
    uint32_t erase_max_retry : 4;
    uint32_t reg_wren_type : 1;

    uint32_t turn_on_off_rf: 1;   // 0, no turn on/off rf; 1, turn on/off rf
    uint32_t spic_baud : 12;
    uint32_t dp_release_cyc_len : 3;
    uint32_t dp_release_delay_us : 8;
    uint32_t sw_reset_delay_us : 8;


    uint32_t bp_enable : 1;
    uint32_t bp_tb : 1;
    uint32_t bp_lv : 8;
    uint32_t bp_ignore : 1;
    uint32_t cache_enable : 1; //enable cache or not
    // 2'b00 for non-MCM flash, use VDDC power cut;
    // 2'b01 for 1.8V MCM flash;
    // 2'b10 for wide range MCM flash;
    // 2'b11 for non-MCM flash, do not need VDDC power cut (default);
    uint32_t disable_irq_lv: 3;
    uint32_t read_turn_on_off_rf: 1;
    uint32_t active_power: 2;
    uint32_t init_cmd_rdid : 8;
    uint32_t dp_enter_delay_us: 6;

    uint32_t init_cmd_rd_data : 8;
    uint32_t init_cmd_dp_release : 8;
    uint32_t init_cmd_en_reset : 8;
    uint32_t init_cmd_reset : 8;

    uint8_t  flash_power_on_delay_100us_cnt;
    uint8_t  flash_init_delay_1ms_cnt;
    uint16_t flash_init_whether_check_wip: 1;
    uint16_t flash_check_wip_delay_1ms_cnt: 15;

    T_FLASH_INFO_TBL flash_info_tbl;     /* store Flash related information */ //18 bytes
    FLASH_NOR_QUERY_INFO_TABLE_STRUCT query_info;

} __attribute__((packed)) FLASH_NOR_SETTINGS_CFG;

typedef struct _BT_EFUSE_BOOT_CFG
{
    uint32_t SWD_ENABLE: 1;
    uint32_t aon_reg_parsing_tag: 8;
    uint32_t is_bypass_flash: 1;
    uint32_t is_do_lop_pon_setting: 1;
    uint32_t is_hw_auto_pwm_pfm: 1;
    uint32_t ota_copy_image_before_secure_boot: 1;
    uint32_t rsvd: 19;

    uint32_t is_need_delay_for_32k_deglitch: 1;
    uint32_t deglitch_sync_begin_cnt: 26;
    uint32_t rsvd1: 5;

    FLASH_NOR_SETTINGS_CFG flash_setting;

} __attribute__((packed)) BT_EFUSE_BOOT_CFG;

extern BT_EFUSE_BOOT_CFG boot_cfg;

#endif /* _PLATFORM_CFG_H */
