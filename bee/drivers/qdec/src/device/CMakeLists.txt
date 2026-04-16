# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_COMMON_DRIVER rtl_common)

add_soc_series_subdir(rtl8752h)
add_soc_series_subdir(rtl87x2g)
add_soc_series_subdir(rtl87x2j)
