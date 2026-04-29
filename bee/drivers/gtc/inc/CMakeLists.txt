#
# Copyright (c) 2026, Realtek Semiconductor Corporation
#
# SPDX-License-Identifier: Apache-2.0
#

if(DEFINED ZEPHYR_BASE)
    zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
else()
    register_module_include_directories(driver ${driver_public_type} ${CMAKE_CURRENT_SOURCE_DIR})
endif()