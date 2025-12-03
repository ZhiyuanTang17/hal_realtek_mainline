/**
*****************************************************************************************
*     Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    System_rtl876x_int.h
  * @brief   CMSIS Device System Header file
  * @details CMSIS Device System Header File for RTL876x Device Series
  * @author
  * @date    3. March 2016
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2016 Realtek Semiconductor Corporation</center></h2>
   * ************************************************************************************
   */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef SYSTEM_RTL876X_INT_H
#define SYSTEM_RTL876X_INT_H


/*============================================================================*
 *                      Headers
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "system_rtl876x.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SYSTEM_RTL876X_API  System Rtl876x
  * @brief CMSIS API sets for RTL876x Device Series
  * @{
  */


#define SRAM_POW_F0C_REG                   0xF0C /* ISO_BT2PP = 0, used in active mode */
#define SRAM_POW_F10_REG                   0xF10 /* ISO_BT2PP = 1, used in low power mode */
#define SRAM_POW_F14_REG                   0xF14
#define SRAM_POW_F18_REG                   0xF18
#define SRAM_POW_F1C_REG                   0xF1C
#define SRAM_POW_F20_REG                   0xF20
#define SRAM_POW_F24_REG                   0xF24
#define SRAM_POW_F28_REG                   0xF28

typedef enum
{
    ADP_DET_ING = 0,
    ADP_DET_IN,
    ADP_DET_OUT,
} ADP_DET_Type;

typedef enum
{
    BYPASS_EFUSE_VALID = 0,
    BYPASS_EFUSE_INVALID,
    NORMAL_EFUSE_VALID,
    NORMAL_EFUSE_INVALID,
} BOOT_Type;

typedef enum
{
    EFUSE_INVALID = 0,
    FLASH_INVALID,
} BOOT_ERROR_Type;

typedef enum
{
    LOAD_NONE                   = 0,
    LOAD_FT_PARA                = 1,
    LOAD_OEM_PARA               = 2,
    LOAD_ALL                    = 3,
} EFUSE_LOAD_Type;

typedef enum
{
    CHECK_NONE                  = 0x0000,
    CHECK_EUID                  = 0x0001,
    CHECK_SYSTEM_FUNC_CTRL      = 0x0002,
    CHECK_KEY                   = 0x0004,
    CHECK_ALL                   = 0x0007,
} EFUSE_CHECK_Type;

typedef enum
{
    SWD_CLOSE = 0,
    SWD_NOT_DEFINE,
    SWD_PROTECT,
    SWD_OPEN,
} SWD_CONTROL_Type;

typedef enum
{
    FSBL_IMG_INVALID = 0,
    FSBL_IMG_RETURN_FAILED,
    FSBL_IMG_RETURN_SUCCESS,
    FSBL_IMG_RETURN_BYPASS_REMAINING_AUTH,
} FSBL_IMG_RETURN_Type;


typedef union _AUTO_SWITCH_TYPE
{
    unsigned int d32;
    struct
    {
        unsigned int EA_INIT:           1;
        unsigned int Enable_FPWM:       1;
        unsigned int DIGI_PC:           1;
        unsigned int VDIGI_TUNE:        4;
        unsigned int I_ZCD_P:           2;
        unsigned int pMOS_HIGH_CAP:     1;
        unsigned int pMOS_LOW_CAP:      1;
        unsigned int OCP_RES:           2;
        unsigned int PWM_ZCD_RES:       5;
        unsigned int Vref_OCP:          3;
        unsigned int PWM_Vout:          6;
        unsigned int PFM_Vout:          4;
        unsigned int PWM_TYPE:          1;
    };
} AUTO_SWITCH_TYPE;

typedef union _AUTO_SWITCH_2fc_TYPE
{
    unsigned int d32;
    struct
    {
        unsigned int rsvd1:             1;
        unsigned int PFM_ZCD_RES_2e8:   5;
        unsigned int rsvd2:             1;
        unsigned int PFM_ZCD_RES_2ec:   5;
        unsigned int rsvd3:             1;
        unsigned int PFM_ZCD_RES_2f0:   5;
        unsigned int rsvd4:             1;
        unsigned int PFM_ZCD_RES_2f4:   5;
        unsigned int rsvd5:             1;
        unsigned int PFM_ZCD_RES_2f8:   5;
    };
} AUTO_SWITCH_2fc_TYPE;


#define INVALID_CNT_THRESHOLD   15
/** @} */ /* End of group SYSTEM_RTL876X_Exported_types */

extern uint32_t SystemCpuClock;         /*!< CPU Clock Frequency */
extern uint32_t SystemCpuClockSlow;     /*!< CPU Clock Frequency in Slow Mode */
extern uint32_t FlashSrcClk;            /*!< Flash Clock Frequency */
extern uint32_t UartSrcClk;             /*!< Uart Clock Frequency */


extern ADP_DET_Type ADP_DET_status;
extern uint8_t SystemInitFailInfo[3];

/*============================================================================*
 *                      Functions
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Functions System RTL876X Sets Exported Functions
    * @brief
    * @{
    */

extern bool check_power_on_trap(bool is_whole_chip_reset);
extern void (*set_cpu_clock)(uint8_t clk_src, uint8_t div, uint8_t div_slow);
extern void (*(set_active_clk_src[]))(bool);
extern void (*pmu_system_init)(void);

extern void set_auto_pwm_pfm_active_rom(void);
extern void (*ft_paras_apply)(void);
extern void (*si_flow_data_init)(void);
extern void (*si_flow_before_power_on_sequence_restart)(void);
extern void (*si_flow_after_power_on_sequence_restart)(void);
extern void (*si_flow_before_enter_dlps)(void);
extern void (*si_flow_resume_from_dlps)(void);
extern void turn_on_needed_clock_source(void);
extern void hal_setup_hardware(void);
extern void hal_setup_cpu(void);
extern void prepare_rom_boot(void);
#if (BOOT_ONLY_RAM_OVERLAY == 1)
extern void overlay_boot_only_ram_init(void);
extern void overlay_vector_table_ram_init(void);
#endif
extern void LOGUARTDriverInit(void);
extern uint8_t Hex2Char(uint8_t hex);
extern void ProgramStart(void);
extern void efuse_temper_check(uint8_t *data, uint8_t byte_size, uint8_t num_of_zeros,
                               uint8_t inv_num_of_zeros);
extern bool efuse_temper_dectect(void);
extern bool efuse_validation(EFUSE_LOAD_Type load_type, EFUSE_CHECK_Type check_type);
extern void efuse_system_general_control(void);
extern void efuse_swd_control(bool before_secure_boot);
extern void efuse_update_parameter(void);
extern void enter_debug_password(uint16_t *password);
extern bool check_debug_password(void);
extern void boot_error_handler(BOOT_ERROR_Type boot_error_type);
extern void set_clk_when_wakeup(void);

extern uint8_t count_0bits(uint32_t x);
extern uint8_t count_1bits(uint32_t x);
extern uint8_t count_zeros(uint8_t *data, uint8_t byte_size);
extern bool check_inverse(uint8_t data, uint8_t inverse_data);
extern bool check_zero_count_and_inverse(uint8_t *data, uint8_t byte_size, uint8_t num_of_zeros,
                                         uint8_t inv_num_of_zeros);
extern uint8_t check_field(uint8_t field, uint8_t field_bit_size);
extern bool data_cmp(const void *d1, const void *d2, uint32_t length);
extern uint32_t occd_addr;
/** @} */ /* End of group SYSTEM_RTL876X_Exported_Functions */

/** @} */ /* End of group SYSTEM_RTL876X_API */

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_RTL876X_INT_H */
