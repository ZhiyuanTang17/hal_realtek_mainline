# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(rtl_pinmux.c)
zephyr_code_relocate(FILES rtl_pinmux.c LOCATION ITCM)
