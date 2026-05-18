/**
 * Copyright (c) 2017, Realtek Semiconductor Corporation. All rights reserved.
 */

#ifndef _SOC_LOG_H_
#define _SOC_LOG_H_

#include <stdint.h>
#include <stdbool.h>
#include "log_core.h"
#ifdef __cplusplus
extern "C" {
#endif


/**
 * \defgroup    TRACE       Trace
 *
 * \brief       Defines debug trace macros for each module.
 *
 */
#define LOG_VERSION    (1)

/**
 * log.h
 *
 * \name    MODULE_ID
 * \brief   Module ID definition.
 * \anchor  MODULE_ID
 */
/**
 * \ingroup TRACE
 */
/**@{*/
typedef enum
{
    /* platform modules */
    MODULE_BOOT,
    MODULE_PATCH,
    MODULE_OS,
    MODULE_OSIF,
    MODULE_FS,
    MODULE_DFU,
    MODULE_DEBUG,
    MODULE_CLOCK,

    /* device modules */
    MODULE_PERIPH,
    MODULE_FMC,
    MODULE_CRYPTO,

    MODULE_PM,
    MODULE_PHY,
    MODULE_DVFS,
    MODULE_CHARGER,

    /* stack modules */
    MODULE_PROFILE,
    MODULE_PROTOCOL,
    MODULE_GAP,
    MODULE_BTE,
    MODULE_BTIF,
    MODULE_GATT,
    MODULE_SMP,
    MODULE_SDP,
    MODULE_L2CAP,
    MODULE_HCI,
    MODULE_SNOOP,
    MODULE_BTH,
    MODULE_BTC,

    MODULE_REG_BEGIN,

    MODULE_NUM = 64,
} T_MODULE_ID;
/**@}*/

/* Bluetooth HCI Snoop Trace Interfaces */
#define BT_SNOOP_DOWN_TRACE(entity_id, length, snoop)  \
    DBG_SNOOP2(entity_id, 0, SUBTYPE_DOWN_SNOOP,length, snoop)
#define BT_SNOOP_UP_TRACE(entity_id, length, snoop)  \
    DBG_SNOOP2(entity_id, 0, SUBTYPE_UP_SNOOP,length, snoop)


/* Bluetooth Message Trace Interfaces */
#define BT_MESSAGE_DOWN_PRINT_ERROR(length, message)   \
    DBG_STREAM( SUBTYPE_DOWN_MESSAGE, MODULE_BTH, LEVEL_ERROR, length, message)
#define BT_MESSAGE_DOWN_PRINT_WARN(length, message)   \
    DBG_STREAM( SUBTYPE_DOWN_MESSAGE, MODULE_BTH, LEVEL_WARN, length, message)
#define BT_MESSAGE_DOWN_PRINT_INFO(length, message)   \
    DBG_STREAM( SUBTYPE_DOWN_MESSAGE, MODULE_BTH, LEVEL_INFO, length, message)
#define BT_MESSAGE_DOWN_PRINT_TRACE(length, message)   \
    DBG_STREAM( SUBTYPE_DOWN_MESSAGE, MODULE_BTH, LEVEL_TRACE, length, message)
#define BT_MESSAGE_UP_PRINT_ERROR(length, message)   \
    DBG_STREAM( SUBTYPE_UP_MESSAGE, MODULE_BTH, LEVEL_ERROR,  length, message)
#define BT_MESSAGE_UP_PRINT_WARN(length, message)   \
    DBG_STREAM( SUBTYPE_UP_MESSAGE, MODULE_BTH, LEVEL_WARN, length, message)
#define BT_MESSAGE_UP_PRINT_INFO(length, message)   \
    DBG_STREAM( SUBTYPE_UP_MESSAGE, MODULE_BTH, LEVEL_INFO, length, message)
#define BT_MESSAGE_UP_PRINT_TRACE(length, message)   \
    DBG_STREAM( SUBTYPE_UP_MESSAGE, MODULE_BTH, LEVEL_TRACE, length, message)

/*  PATCH Trace Interfaces */
#define PATCH_PRINT_ERROR(...)   \
    DBG_INDEX( SUBTYPE_INDEX, MODULE_PATCH, LEVEL_ERROR, __VA_ARGS__)
#define PATCH_PRINT_WARN(...)   \
    DBG_INDEX( SUBTYPE_INDEX, MODULE_PATCH, LEVEL_WARN, __VA_ARGS__)
#define PATCH_PRINT_INFO(...)   \
    DBG_INDEX( SUBTYPE_INDEX, MODULE_PATCH, LEVEL_INFO, __VA_ARGS__)
#define PATCH_PRINT_TRACE(...)   \
    DBG_INDEX( SUBTYPE_INDEX, MODULE_PATCH, LEVEL_TRACE, __VA_ARGS__)

/* Bluetooth Lower Stack Trace Interfaces */
#define LOWERSTACK_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_BTC, ##__VA_ARGS__)
#define LOWERSTACK_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_BTC,   ##__VA_ARGS__)
#define LOWERSTACK_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_BTC,   ##__VA_ARGS__)
#define LOWERSTACK_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_BTC,   ##__VA_ARGS__)

/* Bluetooth PROTOCOL Trace Interfaces */
#define PROTOCOL_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_PROTOCOL,   ##__VA_ARGS__)
#define PROTOCOL_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_PROTOCOL,   ##__VA_ARGS__)
#define PROTOCOL_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_PROTOCOL,   ##__VA_ARGS__)
#define PROTOCOL_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_PROTOCOL,   ##__VA_ARGS__)

/* Bluetooth PROFILE Trace Interfaces */
#define PROFILE_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_PROFILE,   ##__VA_ARGS__)
#define PROFILE_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_PROFILE,   ##__VA_ARGS__)
#define PROFILE_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_PROFILE,   ##__VA_ARGS__)
#define PROFILE_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_PROFILE,   ##__VA_ARGS__)

/*  BOOT Trace Interfaces */
#define BOOT_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_BOOT,   ##__VA_ARGS__)
#define BOOT_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_BOOT,   ##__VA_ARGS__)
#define BOOT_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_BOOT,   ##__VA_ARGS__)
#define BOOT_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_BOOT,   ##__VA_ARGS__)

/* OS Trace Interfaces */
#define OS_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_OS,   ##__VA_ARGS__)
#define OS_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_OS,   ##__VA_ARGS__)
#define OS_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_OS,   ##__VA_ARGS__)
#define OS_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_OS,   ##__VA_ARGS__)

/* OSIF Trace Interfaces */
#define OSIF_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_OSIF,   ##__VA_ARGS__)
#define OSIF_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_OSIF,   ##__VA_ARGS__)
#define OSIF_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_OSIF,   ##__VA_ARGS__)
#define OSIF_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_OSIF,   ##__VA_ARGS__)

/*  FLASH Trace Interfaces */
#define FLASH_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_FMC,   ##__VA_ARGS__)
#define FLASH_PRINT_WARN(...)   \
    LOG_WARN( MODULE_FMC,   ##__VA_ARGS__)
#define FLASH_PRINT_INFO(...)   \
    LOG_INFO( MODULE_FMC,   ##__VA_ARGS__)
#define FLASH_PRINT_TRACE(...)   \
    LOG_TRACE( MODULE_FMC,   ##__VA_ARGS__)

/*  CRYPTO Trace Interfaces */
#define CRYPTO_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_CRYPTO,   ##__VA_ARGS__)
#define CRYPTO_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_CRYPTO,   ##__VA_ARGS__)
#define CRYPTO_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_CRYPTO,   ##__VA_ARGS__)
#define CRYPTO_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_CRYPTO,   ##__VA_ARGS__)

/*  DFU Trace Interfaces */
#define DFU_PRINT_ERROR(...)   \
    LOG_ERROR(MODULE_DFU,   ##__VA_ARGS__)
#define DFU_PRINT_WARN(...)   \
    LOG_WARN( MODULE_DFU,   ##__VA_ARGS__)
#define DFU_PRINT_INFO(...)   \
    LOG_INFO( MODULE_DFU,   ##__VA_ARGS__)
#define DFU_PRINT_TRACE(...)   \
    LOG_TRACE( MODULE_DFU,   ##__VA_ARGS__)

/*  CLOCK Trace Interfaces */
#define CLOCK_PRINT_ERROR(...)   \
    LOG_ERROR(MODULE_CLOCK,   ##__VA_ARGS__)
#define CLOCK_PRINT_WARN(...)   \
    LOG_WARN( MODULE_CLOCK,   ##__VA_ARGS__)
#define CLOCK_PRINT_INFO(...)   \
    LOG_INFO( MODULE_CLOCK,   ##__VA_ARGS__)
#define CLOCK_PRINT_TRACE(...)   \
    LOG_TRACE( MODULE_CLOCK,   ##__VA_ARGS__)

/*  IO Trace Interfaces */
#define IO_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_IO,   ##__VA_ARGS__)
#define IO_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_IO,   ##__VA_ARGS__)
#define IO_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_IO,   ##__VA_ARGS__)
#define IO_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_IO,   ##__VA_ARGS__)

/*  PM Trace Interfaces */
#define PM_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_PM,   ##__VA_ARGS__)
#define PM_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_PM,   ##__VA_ARGS__)
#define PM_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_PM,   ##__VA_ARGS__)
#define PM_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_PM,   ##__VA_ARGS__)

/*  PHY Trace Interfaces */
#define PHY_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_PHY,   ##__VA_ARGS__)
#define PHY_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_PHY,   ##__VA_ARGS__)
#define PHY_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_PHY,   ##__VA_ARGS__)
#define PHY_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_PHY,   ##__VA_ARGS__)

/*  DVFS Trace Interfaces */
#define DVFS_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_DVFS,   ##__VA_ARGS__)
#define DVFS_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_DVFS,   ##__VA_ARGS__)
#define DVFS_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_DVFS,   ##__VA_ARGS__)
#define DVFS_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_DVFS,   ##__VA_ARGS__)

/*  CHARGER Trace Interfaces */
#define CHARGER_PRINT_ERROR(...)   \
    LOG_ERROR( MODULE_CHARGER,   ##__VA_ARGS__)
#define CHARGER_PRINT_WARN( ...)   \
    LOG_WARN( MODULE_CHARGER,   ##__VA_ARGS__)
#define CHARGER_PRINT_INFO( ...)   \
    LOG_INFO( MODULE_CHARGER,   ##__VA_ARGS__)
#define CHARGER_PRINT_TRACE( ...)   \
    LOG_TRACE( MODULE_CHARGER,   ##__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif /* _SOC_LOG_H_ */
