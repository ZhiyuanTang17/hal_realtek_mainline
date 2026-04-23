/**
 * Copyright (c) 2017, Realtek Semiconductor Corporation. All rights reserved.
 */

#ifndef _LOG_CORE_H_
#define _LOG_CORE_H_

#include <stdint.h>
#include <stdbool.h>
#include "section.h"
#ifdef __cplusplus
extern "C" {
#endif


/**
 * \defgroup    TRACE       Trace
 *
 * \brief       Defines debug trace macros for each module.
 *
 */

#if defined(CONFIG_SOC_SERIES_RTL87X3J_NETPROCESSOR)
#define RTL87X3J_NETPROCESSOR_SUBTYPE_MASK  (0x20)
#define SUBTYPE_MASK  (0x1F)
#define GET_SUBTYPE(subtype) ((subtype) | RTL87X3J_NETPROCESSOR_SUBTYPE_MASK)
#define GET_SUBTYPE_MASK_VALUE(subtype)  (subtype & SUBTYPE_MASK)
#else
#define GET_SUBTYPE(subtype) (subtype)
#define GET_SUBTYPE_MASK_VALUE(subtype)  (subtype)
#endif


/* Log Section Definition */
#define TRACE_DATA __attribute__((section(".TRACE"))) __attribute__((aligned(4))) __attribute__((used))

#define LOG_MESSAGE_SYNC_CODE       0x7E
#define MAX_LOG_MESSAGE_LEN         252
#define MAX_ARGUMENT_SIZE           20


#define LOG_BINARY_MASK             BIT0
#define LOG_ASCII_MASK              BIT1

#define LOG_OUTPUT_UART_MASK        BIT0
#define LOG_OUTPUT_FLASH_MASK       BIT1
#define LOG_OUTPUT_VENDOR_MASK      BIT2

/**
 * log_core.h
 *
 * \name    TRACE_LEVEL
 * \brief   Log Level Definition.
 * \anchor  TRACE_LEVEL
 */
/**
 * \ingroup TRACE
 */
/**@{*/
#define LEVEL_OFF       (-1)
#define LEVEL_ERROR     (0)
#define LEVEL_WARN      (1)
#define LEVEL_INFO      (2)
#define LEVEL_TRACE     (3)
#define LEVEL_NUM       (4)
/**@}*/

/*
 * DBG_LEVEL is used to control the log printed by DBG_BUFFER(), DBG_INDEX() and DBG_TEXT().
 * LEVEL_OFF   : Print None
 * LEVEL_ERROR : Print ERROR
 * LEVEL_WARN  : Print ERROR, WARN
 * LEVEL_INFO  : Print ERROR, WARN, INFO
 * LEVEL_TRACE : Print ERROR, WARN, INFO, TRACE
 */
#define DBG_LEVEL               LEVEL_TRACE

/** Log subtype definition:
 * bit0 ~ bit4: sub type value,
 * bit5 ~ bit6: log version 0 (reserved),
 *              log version 1( b'00: AP core, b'01: NP core, b'10 and b'11: reserved).
 * bit7: 1 dsp log, 0 mcu log.
 * max subtype value is 0x1F.
*/
typedef enum
{
    SUBTYPE_BDADDR                  = 0x00,
    SUBTYPE_STRING                  = 0x01,
    SUBTYPE_BINARY                  = 0x02,
    SUBTYPE_DOUBLE                  = 0x03,
    SUBTYPE_UINT64                  = 0x04,

    SUBTYPE_FORMAT                  = 0x10,
    SUBTYPE_DIRECT                  = 0x11,
    SUBTYPE_TEXT                    = 0x12,
    SUBTYPE_DOWN_MESSAGE            = 0x13,
    SUBTYPE_UP_MESSAGE              = 0x14,
    SUBTYPE_DOWN_SNOOP              = 0x15,
    SUBTYPE_UP_SNOOP                = 0x16,
    SUBTYPE_LOWERSTACK              = 0x17,
    SUBTYPE_INDEX                   = 0x18,
    SUBTYPE_STACK_INDEX             = 0x19,
    SUBTYPE_SNOOP2                  = 0x1A,

    SUBTYPE_MAX                     = 0x1F,

} T_LOG_SUBTYPE;

/* Internal function that is used by internal macro DBG_DIRECT. */
extern void log_direct(const char *fmt, ...);

/* Internal function that is used by internal macro DBG_BUFFER. */
void log_buffer(uint8_t module, uint8_t param_no, uint32_t str_index, ...);

/* Internal function that is used by internal macro DBG_LOWERSTACK. */
void log_buffer_bt_controller(uint32_t str_index, uint32_t param_num, ...);

/* Internal function that is used by internal macro DBG_INDEX. */
void log_index(uint8_t subtype, uint8_t module, uint8_t param_no, uint32_t str_index,  ...);

/* Internal function that is used by internal macro DBG_TEXT. */
void log_text(uint32_t info, const char *fmt, ...);

/* Internal function that is used by internal macro DBG_STREAM. */
void log_stream(T_LOG_SUBTYPE subtype, uint8_t module, uint16_t length, uint8_t *p_data);

/* Internal function that is used by internal macro TRACE_STRING. */
uint32_t trace_string(char *p_data);

/* Internal function that is used by internal macro TRACE_BINARY. */
uint32_t log_trace_binary(uint16_t length, char *p_data);

/* Internal function that is used by internal macro TRACE_BDADDR. */
uint32_t log_trace_bdaddr(char *bd_addr);

/* Internal function that is used by internal macro DBG_SNOOP2. */
extern void log_snoop2(uint32_t info, uint16_t length, uint8_t *p_snoop);

/* Internal function that is used by public macro TRACE_FLOAT. */
static inline uint32_t trace_float(float param)
{
    return *((uint32_t *)&param);
}

/* Internal function that is used by public macro TRACE_UINT64. */
uint32_t trace_uint64(uint64_t param);

/* Internal function that is used by public macro TRACE_DOUBLE. */
uint32_t trace_double(double param);

/* Internal macro */
#define COMBINE_TRACE_INFO(module, level)   (uint8_t)( ((level) << 6) | ((module) & 0x3F))
#define COMBINE_SNOOP_INFO(entity_id, protocol_type, dir)  (uint32_t)((dir << 16) + (protocol_type << 8) + entity_id)


#define COUNT_ARGS_(t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,cnt,...) cnt
#define COUNT_ARGS(...) COUNT_ARGS_(,##__VA_ARGS__,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

/* Internal macro that is wrapped by internal macro DBG_BUFFER. */
#define DBG_BUFFER_INTERNAL_WRAPPER( sub_type, module, level, fmt, param_num, ...) do {\
        static const char format[] TRACE_DATA = fmt;\
        log_buffer(COMBINE_TRACE_INFO(module, level), param_num,(uint32_t)format, ##__VA_ARGS__);\
    } while (0)
#define DBG_INDEX_INTERNAL_WRAPPER( sub_type, module, level, fmt, param_num, ...) do {\
        log_index(sub_type, COMBINE_TRACE_INFO(module, level), param_num, fmt, ##__VA_ARGS__);\
    } while (0)

/* Internal macro to remove param num. */
#define DBG_BUFFER_INTERNAL(sub_type, module, level, fmt, ...)  do {\
        DBG_BUFFER_INTERNAL_WRAPPER(sub_type, module, level, fmt, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__) ;\
    } while (0)
#define DBG_INDEX_INTERNAL(sub_type, module, level, fmt, ...) do {\
        DBG_INDEX_INTERNAL_WRAPPER(sub_type, module, level, fmt, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__);\
    } while (0)


#if (DBG_LEVEL >= LEVEL_ERROR)
#define DBG_BUFFER_LEVEL_ERROR( sub_type, module, fmt, ...) do {\
        DBG_BUFFER_INTERNAL( sub_type, module, LEVEL_ERROR, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_INDEX_LEVEL_ERROR( sub_type, module, fmt, ...) do {\
        DBG_INDEX_INTERNAL(sub_type, module, LEVEL_ERROR, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_TEXT_LEVEL_ERROR( sub_type, module, fmt, ...) do {\
        log_text(COMBINE_TRACE_INFO(module, LEVEL_ERROR), fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_STREAM_LEVEL_ERROR(  sub_type, module, level, length, p_data) do {\
        log_stream(sub_type, COMBINE_TRACE_INFO( module, LEVEL_ERROR), length, (uint8_t *)p_data);\
    } while (0)
#else
#define DBG_BUFFER_LEVEL_ERROR( sub_type, module, fmt, ...)
#define DBG_INDEX_LEVEL_ERROR( sub_type, module, fmt, ...)
#define DBG_TEXT_LEVEL_ERROR( sub_type, module, fmt, ...)
#define DBG_STREAM_LEVEL_ERROR(  sub_type, module, level, length, p_data)
#endif

#if (DBG_LEVEL >= LEVEL_WARN)
#define DBG_BUFFER_LEVEL_WARN( sub_type, module, fmt, ...)  do {\
        DBG_BUFFER_INTERNAL( sub_type, module, LEVEL_WARN, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_INDEX_LEVEL_WARN( sub_type, module, fmt, ...) do {\
        DBG_INDEX_INTERNAL(sub_type, module, LEVEL_WARN, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_TEXT_LEVEL_WARN( sub_type, module, fmt, ...) do {\
        log_text(COMBINE_TRACE_INFO(module, LEVEL_WARN), fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_STREAM_LEVEL_WARN( sub_type, module, level, length, p_data) do {\
        log_stream(sub_type, COMBINE_TRACE_INFO( module, LEVEL_WARN), length, (uint8_t *)p_data);\
    } while (0)
#else
#define DBG_BUFFER_LEVEL_WARN( sub_type, module, fmt, ...)
#define DBG_INDEX_LEVEL_WARN( sub_type, module, fmt, ...)
#define DBG_TEXT_LEVEL_WARN( sub_type, module, fmt, ...)
#define DBG_STREAM_LEVEL_ERROR( sub_type, module, level, length, p_data)
#endif

#if (DBG_LEVEL >= LEVEL_INFO)
#define DBG_BUFFER_LEVEL_INFO( sub_type, module, fmt, ...)  do {\
        DBG_BUFFER_INTERNAL( sub_type, module, LEVEL_INFO, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_INDEX_LEVEL_INFO( sub_type, module, fmt, ...) do {\
        DBG_INDEX_INTERNAL(sub_type, module, LEVEL_INFO, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_TEXT_LEVEL_INFO( sub_type, module, fmt, ...) do {\
        log_text(COMBINE_TRACE_INFO(module, LEVEL_INFO), fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_STREAM_LEVEL_INFO(  sub_type, module, level, length, p_data) do {\
        log_stream(sub_type, COMBINE_TRACE_INFO(module, LEVEL_INFO), length, (uint8_t *)p_data);\
    } while (0)
#else
#define DBG_BUFFER_LEVEL_INFO( sub_type, module, fmt, ...)
#define DBG_INDEX_LEVEL_INFO( sub_type, module, fmt, ...)
#define DBG_TEXT_LEVEL_INFO( sub_type, module, fmt, ...)
#define DBG_STREAM_LEVEL_ERROR( sub_type, module, level, length, p_data)
#endif

#if (DBG_LEVEL >= LEVEL_TRACE)
#define DBG_BUFFER_LEVEL_TRACE( sub_type, module, fmt, ...) do {\
        DBG_BUFFER_INTERNAL( sub_type, module, LEVEL_TRACE, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_INDEX_LEVEL_TRACE( sub_type, module, fmt, ...) do {\
        DBG_INDEX_INTERNAL(sub_type, module, LEVEL_TRACE, fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_TEXT_LEVEL_TRACE( sub_type, module, fmt, ...) do {\
        log_text(COMBINE_TRACE_INFO(module, LEVEL_TRACE), fmt, ##__VA_ARGS__);\
    } while (0)
#define DBG_STREAM_LEVEL_TRACE(  sub_type, module, level, length, p_data) do {\
        log_stream(sub_type, COMBINE_TRACE_INFO( module, LEVEL_TRACE), length, (uint8_t *)p_data);\
    } while (0)
#else
#define DBG_BUFFER_LEVEL_TRACE( sub_type, module, fmt, ...)
#define DBG_INDEX_LEVEL_TRACE( sub_type, module, fmt, ...)
#define DBG_TEXT_LEVEL_TRACE( sub_type, module, fmt, ...)
#define DBG_STREAM_LEVEL_ERROR( sub_type, module, fmt, ...)
#endif

#define DBG_BUFFER( sub_type, module, level, fmt,...)   \
    DBG_BUFFER_##level( sub_type, module, fmt, ##__VA_ARGS__)

#define DBG_INDEX( sub_type, module, level, fmt,...)   \
    DBG_INDEX_##level( sub_type, module, fmt, ##__VA_ARGS__)

#define DBG_TEXT( sub_type, module, level, fmt, ...)   \
    DBG_TEXT_##level( sub_type, module, fmt, ##__VA_ARGS__)

#define DBG_STREAM( sub_type, module, level, length, p_data)   \
    DBG_STREAM_##level( sub_type, module, level, length, p_data)

#define DBG_LOWERSTACK(color, file_num, line_num, str_index, ...)     do {\
        log_buffer_bt_controller(str_index, COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__);\
    } while (0)

#define DIRECT_LOG(fmt, ...)     do {\
        DBG_BUFFER_INTERNAL(GET_SUBTYPE(SUBTYPE_FORMAT), MODULE_BOOT, LEVEL_ERROR, fmt, ##__VA_ARGS__);\
    } while (0)


#define DBG_DIRECT(...)   do {\
        log_direct(__VA_ARGS__);\
    } while (0)

/**
 * log_core.h
 *
 * \name    AUXILIARY_PRINT_BDADDR
 * \brief   Auxiliary Interface that is used to print BD address.
 * \anchor  AUXILIARY_PRINT_BDADDR
 */
/**
 * \ingroup TRACE
 */
#define TRACE_BDADDR(bd_addr)   \
    log_trace_bdaddr((char *)bd_addr)

/**
 * log_core.h
 *
 * \name    AUXILIARY_PRINT_STRING
 * \brief   Auxiliary Interface that is used to print string.
 * \anchor  AUXILIARY_PRINT_STRING
 */
/**
 * \ingroup TRACE
 */
#define TRACE_STRING(data)    \
    trace_string((char *)(data))

/**
 * log_core.h
 *
 * \name    AUXILIARY_PRINT_BINARY
 * \brief   Auxiliary Interface that is used to print binary string.
 * \anchor  AUXILIARY_PRINT_BINARY
 */
/**
 * \ingroup TRACE
 */
/**@{*/
#define TRACE_BINARY(length, data)  \
    log_trace_binary(length, (char *)(data))
/**@}*/

/**
 * log_core.h
 *
 * \name    AUXILIARY_PRINT_FLOAT
 * \brief   Auxiliary Interface that is used to print float.
 * \anchor  AUXILIARY_PRINT_FLOAT
 */
/**
 * \ingroup TRACE
 */
/**@{*/
#define TRACE_FLOAT(param)   trace_float(param)
/**@}*/

/**
 * log_core.h
 *
 * \name    AUXILIARY_PRINT_DOUBLE
 * \brief   Auxiliary Interface that is used to print double.
 * \anchor  AUXILIARY_PRINT_DOUBLE
 */
/**
 * \ingroup TRACE
 */
/**@{*/
#define TRACE_DOUBLE(param)  \
    trace_double(param)
/**
 * trace.h
 *
 * \name    AUXILIARY_PRINT_UINT64
 * \brief   Auxiliary Interface that is used to print uint64.
 * \anchor  AUXILIARY_PRINT_UINT64
 */
/**
 * \ingroup TRACE
 */
/**@{*/
#define TRACE_UINT64(param)  \
    trace_uint64(param)
/**@}*/


#define DBG_SNOOP(subtype, length, snoop)    do {\
        log_snoop(subtype, length, snoop);\
    } while (0)

/*DBG_SNOOP2 with sub type SUBTYPE_SNOOP2*/
#define DBG_SNOOP2(entity_id, protocol_type, dir, length, p_snoop)    do {\
        log_snoop2(COMBINE_SNOOP_INFO(entity_id, protocol_type, dir), length, p_snoop);\
    } while (0)

#define LOG_ERROR( module, ...) \
    DBG_BUFFER(GET_SUBTYPE(SUBTYPE_FORMAT), module, LEVEL_ERROR,  ##__VA_ARGS__)

#define LOG_WARN( module, ...) \
    DBG_BUFFER(GET_SUBTYPE(SUBTYPE_FORMAT), module, LEVEL_WARN,  ##__VA_ARGS__)

#define LOG_INFO( module, ...) \
    DBG_BUFFER(GET_SUBTYPE(SUBTYPE_FORMAT), module, LEVEL_INFO,  ##__VA_ARGS__)

#define LOG_TRACE( module, ...) \
    DBG_BUFFER(GET_SUBTYPE(SUBTYPE_FORMAT), module, LEVEL_TRACE, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* _TRACE_H_ */
