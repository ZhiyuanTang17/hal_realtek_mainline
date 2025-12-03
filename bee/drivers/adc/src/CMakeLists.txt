# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

if(DEFINED CONFIG_REALTEK_USING_RTL876X_DRIVER)
    if(DEFINED CONFIG_SOC_SERIES_RTL8752H)
        zephyr_include_directories(rtl8752h)
    endif()
else()
    add_subdirectory(rtl_common)
endif()

add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL8752H rtl8752h)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL87X2G rtl87x2g)
