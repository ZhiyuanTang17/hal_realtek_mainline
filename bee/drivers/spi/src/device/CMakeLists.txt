# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_REALTEK_BEE_COMMON_DRIVER)
    file(GLOB BEE_DRIVER_COMMON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/rtl_common/*.c")
    zephyr_library_sources(${BEE_DRIVER_COMMON_SOURCES})
endif()

add_soc_series_subdir(rtl8752h)
add_soc_series_subdir(rtl87x2g)
add_soc_series_subdir(rtl87x2j)
