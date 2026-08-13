# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(inc adapter/inc)
zephyr_library_sources(src/crypto_bee_psa.c adapter/src/crypto_bee_psa_adapter.c)

if(CONFIG_SOC_SERIES_RTL87X2G)
  zephyr_compile_definitions(BEE_CRYPTO_RTL87X2G)
elseif(CONFIG_SOC_SERIES_RTL8752H)
  zephyr_compile_definitions(BEE_CRYPTO_RTL8752H)
endif()
