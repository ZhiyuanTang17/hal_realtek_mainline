# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_RTC rtl87x2j_rtc.c)
zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_GRTC rtl87x2j_grtc.c)
