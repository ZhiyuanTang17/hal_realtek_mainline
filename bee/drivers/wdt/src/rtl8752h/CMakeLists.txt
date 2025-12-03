# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_REALTEK_AON_WDT rtl876x_aon_wdg.c)
zephyr_library_sources_ifdef(CONFIG_REALTEK_CORE_WDT rtl876x_wdg.c)
