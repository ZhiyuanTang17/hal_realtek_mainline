# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_REALTEK_BEE_COMMON_DRIVER)
    zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif()

add_soc_series_subdir(rtl87x2g)
add_soc_series_subdir(rtl87x2j)
