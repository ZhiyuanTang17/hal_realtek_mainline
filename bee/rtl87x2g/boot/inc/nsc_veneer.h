/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __NSC_VENEER_H__
#define __NSC_VENEER_H__

#include <stdint.h>
#include "rtl876x.h"

typedef void (*NonSecure_func)(void);

typedef enum
{
    SECURE_APP_FUNCTION_OPCODE_INIT = 0,
} SECURE_APP_FUNCTION_OPCODE;

typedef enum
{
    SECURE_FUNCTION_OPCODE_INIT = 0,
    EFUSE_ACCESS  = 1,
    EFUSE_RAM_ACCESS  = 2,
    SECURE_REGION_ACCESS = 3,
    DISABLE_SWD_PIN = 4,
    SPIC_SET_INTERFACE = 5,
    XTAL_40M_AAC_CAL = 6,
    PSRAM_LMP_CTRL = 7,
    WDT_GET_TIMEOUT_MS = 8,
    WDT_GET_MODE = 9,
    HW_AES_SET = 10,
    AON_WDT_GET_TIMEOUT_MS = 11,
    AON_WDT_GET_MODE = 12,
    AON_WDT_IS_ENABLE = 13,
} SECURE_FUNCTION_OPCODE;

typedef enum
{
    SEC_FPTR_OPCODE_OS_AES_SEM_TAKE = 0,
    SEC_FPTR_OPCODE_OS_AES_SEM_GIVE,
    SEC_FPTR_OPCODE_PRINT_LOG_BUFF,
    SEC_FPTR_OPCODE_APP_CB_WDG_RESET,
    SEC_FPTR_OPCODE_OS_LOCK,
    SEC_FPTR_OPCODE_OS_UNLOCK,
    SEC_FPTR_OPCODE_OS_TASK_HDL_GET,
    SEC_FPTR_OPCODE_OS_TASK_PRI_GET,
    SEC_FPTR_OPCODE_WRITE_INFO_TO_FLASH_BEFORE_RESET,
    SEC_FPTR_OPCODE_SAVE_SYSTEM_STATUS_TO_FLASH,
    SEC_FPTR_OPCODE_OS_MEM_ALLOC,
} SECURE_FPTR;

void secure_app_function_call(SECURE_APP_FUNCTION_OPCODE opcode, void *param);
void secure_function_call(SECURE_FUNCTION_OPCODE opcode, void *param);
void set_secure_func_ptr(SECURE_FPTR opcode, NonSecure_func func);



#endif /* __NSC_VENEER_H__ */
