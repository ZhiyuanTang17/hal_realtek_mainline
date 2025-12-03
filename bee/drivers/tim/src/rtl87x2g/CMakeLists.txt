# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_REALTEK_TIM rtl87x2g_tim.c)
zephyr_library_sources_ifdef(CONFIG_REALTEK_ENHTIM rtl87x2g_enh_tim.c)
