# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_TIMER rtl876x_tim.c)
zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_ENHTIMER rtl876x_enh_tim.c)
