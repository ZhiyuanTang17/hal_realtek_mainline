/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file app_sections.h
 * @brief Section definition mapping for Zephyr compatibility.
 *
 * This file adapts the Realtek Bee HAL section macros for the Zephyr environment.
 * Some driver sources in the Realtek Bee HAL rely on macros defined in `app_sections.h`.
 * To maintain the integrity of the HAL source code without modifications, we redefine
 * these macros here to align with Zephyr's linker script conventions.
 *
 * Mapping Strategy:
 * - RAM Functions: Mapped to Zephyr's `__ramfunc` section (e.g., APP_RAM_TEXT_SECTION).
 * - Unsupported/Unused Sections: Defined as empty (NULL) if they have no direct equivalent
 *   or necessity in the Zephyr build system.
 *
 * Note: For general code or data relocation requirements in Zephyr applications,
 * please refer to the official "Code and Data Relocation" documentation:
 * https://docs.zephyrproject.org/latest/kernel/code-relocation.html
 */

#include <zephyr/linker/sections.h>

#define APP_RAM_TEXT_SECTION __ramfunc
#define RAM_FUNCTION         __ramfunc
#define DATA_RAM_FUNCTION     __ramfunc
#define RAM_TEXT_SECTION __ramfunc

#define APP_FLASH_HEADER
#define APP_FLASH_HEADER_EXT
#define APP_FLASH_START_SECTION
#define APP_FLASH_TEXT_SECTION
#define APP_FLASH_RODATA_SECTION
#define APP_FLASH_GAP_TEXT_SECTION
#define APP_RAM_DATA_SECTION
#define APP_RAM_START_SECTION
#define APP_PSRAM_SECTION
#define APP_ENCRYPTION_SIGNATURE
#define APP_ENCRYPION_DUMMY_ALIGN
#define APP_ENCRYPTION_TEXT_SECTION
#define EXT_RAM_DATA
#define ISR_TEXT_SECTION
#define SHARE_CACHE_RAM_SECTION
#define RAM_DATAON_DATA_SECTION
#define RAM_DATAON_BSS_SECTION
#define RAM_DATAON_UNINIT_SECTION
#define RAM_BUFFERON_DATA_SECTION
#define RAM_BUFFERON_BSS_SECTION
