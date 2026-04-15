# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

zephyr_library_sources(rtl_pinmux.c)
zephyr_code_relocate(FILES rtl_pinmux.c LOCATION ITCM)
