# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(drivers)
zephyr_include_directories(drivers)

add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL87X2G rtl87x2g)
add_subdirectory_ifdef(CONFIG_SOC_SERIES_RTL8752H rtl8752h)
