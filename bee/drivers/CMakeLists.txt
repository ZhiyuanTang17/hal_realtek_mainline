# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_REALTEK_ADC adc)

add_subdirectory_ifdef(CONFIG_REALTEK_UART uart)

add_subdirectory_ifdef(CONFIG_REALTEK_RCC rcc)

add_subdirectory_ifdef(CONFIG_REALTEK_PINMUX pinmux)

add_subdirectory_ifdef(CONFIG_REALTEK_NVIC nvic)

if (CONFIG_REALTEK_TIM OR CONFIG_REALTEK_ENHTIM)
	add_subdirectory(tim)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_RTC rtc)

add_subdirectory_ifdef(CONFIG_REALTEK_DMA dma)

add_subdirectory_ifdef(CONFIG_REALTEK_GPIO gpio)

add_subdirectory_ifdef(CONFIG_REALTEK_I2C i2c)

add_subdirectory_ifdef(CONFIG_REALTEK_KEYSCAN keyscan)

add_subdirectory_ifdef(CONFIG_REALTEK_IR ir)

add_subdirectory_ifdef(CONFIG_REALTEK_I2S i2s)

add_subdirectory_ifdef(CONFIG_REALTEK_CODEC codec)

if (CONFIG_REALTEK_AON_QDEC OR CONFIG_REALTEK_QDEC)
add_subdirectory(qdec)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_CAN can)

add_subdirectory_ifdef(CONFIG_REALTEK_SPI spi)
add_subdirectory_ifdef(CONFIG_REALTEK_SDHC sdhc)

add_subdirectory_ifdef(CONFIG_REALTEK_USB usb)
add_subdirectory_ifdef(CONFIG_REALTEK_BT bluetooth)

if (CONFIG_REALTEK_CORE_WDT OR CONFIG_REALTEK_AON_WDT)
add_subdirectory(wdt)
endif()
if (CONFIG_REALTEK_MAC_802154)
add_subdirectory(mac_802154)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_USING_RTL876X_DRIVER rtl876x)
