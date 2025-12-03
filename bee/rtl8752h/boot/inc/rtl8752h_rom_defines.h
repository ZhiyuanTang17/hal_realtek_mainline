#ifndef _RTL8752H_ROM_DEFINE_H_
#define _RTL8752H_ROM_DEFINE_H_

#define TEST_USB                                        0
#define TEST_ZIGBEE                                     0

#define _IS_RTL87X2G_SERIES_                                1
#define DIRECTLY_BRANCH_TO_NS                           0
#define TZ_FPU_NS_USAGE                                 0
#define IS_BFHFNMI_NS                                   1
#define BOOT_DEBUG_LOG_MODE                             BOOT_DEBUG_LOG_DIRECT_LOG
#define BOOT_ONLY_RAM_OVERLAY                           0
#define SUPPORT_RECORD_BOOT_ERROR_CODE                  1

#define BUILD_WITH_FTL                                  0
#define SUPPORT_SINGLE_OTA_BANK                         1  /*if 0, only support daul bank ota*/
#define PRE_INIT_PF_RTC_IN_SECURE_ROM                   0
#define SYS_TIMESTAMP_USE_HW_TIMER                      0

#define _IS_ASIC_
#define SUPPORT_SINGLE_WIRE                             1
#define SECURE_IP_VERIFICATION                          0 /* Secure IP Verification Flag */
#define ROM_VERION_STRING                               "rtl8752h Boot ROM: 0x%08x%08x%08x%08x"

//#define MAX_PAYLOAD_SIZE                                0x0800000 //8MB
#define BOOTPATCH_ADDRESS                               0x04003000

#define TOTAL_ROM_SIZE                                  360448  //(352 * 1024), no caculation for script usage

#define BOOT_ROM_ADDRESS                                0x0
#define PLATFORM_ROM_ADDRESS                            0x0
#define PLATFORM_ROM_SIZE                               151552  //(148 * 1024)  //direct number is convenient for simulation script parser

#define STACK_ROM_ADDRESS                               (PLATFORM_ROM_ADDRESS + PLATFORM_ROM_SIZE)
#define STACK_ROM_SIZE                                  200704  //(196 * 1024)

#define PROPRIETARY_ROM_ADDRESS                         (STACK_ROM_ADDRESS + STACK_ROM_SIZE)
#define PROPRIETARY_ROM_SIZE                            (TOTAL_ROM_SIZE - PLATFORM_ROM_SIZE - STACK_ROM_SIZE)
#define VECTORS_TABLE_OFFSET                            0x2000  // boot rom header offset

#define OUTPUT_PLATROM_NAME                             "rtl8752h_platform"
#define OUTPUT_UPPERSTACK_NAME                          "rtl8752h_upperstack"
#define XO_OFFSET                                       0x2000
#define OS_MINIMAL_SECURE_STACK_SIZE                    1024

#ifdef _IS_ASIC_
#define CPU_CLOCK                                       (40000000)
#define USE_EXTERNAL_RF                                 0
#else
#define CPU_CLOCK                                       (20000000)
#define USE_EXTERNAL_RF                                 1
#endif
#define RXI300_ISR_DUMP_REGISTER_ONLY                   0
/*--------------------------------------------*/
/* fw sim compiler flags                      */
/*--------------------------------------------*/
// #define FOR_SIMULATION
//#define FAKE_UART_ADDRESS                               0x200000
//#define _DLPS_SIMU_TEST_
#endif /* _RTL8752H_ROM_DEFINE_H_ */
