# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(rom)
zephyr_include_directories(rom/portable/rtl87x2g)
zephyr_include_directories(inc)
zephyr_library_sources(src/mac_802154_frame_parser.c)
zephyr_library_sources(src/mac_802154_xip.c)
zephyr_code_relocate(FILES src/mac_802154_xip.c LOCATION ITCM)
