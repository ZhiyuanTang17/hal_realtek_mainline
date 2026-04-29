# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_link_libraries(gcc -T${CMAKE_CURRENT_SOURCE_DIR}/bootloader.ld)
zephyr_link_libraries(gcc -T${CMAKE_CURRENT_SOURCE_DIR}/ROM.ld)
