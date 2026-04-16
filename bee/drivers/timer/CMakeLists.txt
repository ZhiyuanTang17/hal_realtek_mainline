# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_REALTEK_BEE_COMMON_DRIVER)
    zephyr_include_directories(inc)
endif()

if (CONFIG_REALTEK_BEE_TIMER OR CONFIG_REALTEK_BEE_ENHTIMER)
    add_subdirectory(src)
endif()
