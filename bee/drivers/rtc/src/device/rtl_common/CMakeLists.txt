# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_RTC rtl_rtc.c)
zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_GRTC rtl_grtc.c)
