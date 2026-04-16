# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_REALTEK_BEE_COMMON_DRIVER)
    zephyr_include_directories(inc)
endif()

if(CONFIG_REALTEK_BEE_QDEC OR CONFIG_REALTEK_BEE_AON_QDEC OR CONFIG_REALTEK_BEE_LPQDEC)
    add_subdirectory(src)
endif()
