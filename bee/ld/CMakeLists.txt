# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL87X2G rtl87x2g)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL87X2J rtl87x2j)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL8752H rtl8752h)
zephyr_include_directories(inc)
