#ifndef __CLOCK_MANAGER_H
#define __CLOCK_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "platform_utils_int.h"

#define CLOCK_40MHZ     40000000
#define CLOCK_30MHZ     30000000
#define CLOCK_20MHZ     20000000
#define CLOCK_10MHZ     10000000
#define CLOCK_8MHZ      8000000
#define CLOCK_5MHZ      5000000
#define CLOCK_4MHZ      4000000
#define CLOCK_3P3MHZ    3333333
#define CLOCK_2P5MHZ    2500000
#define CLOCK_1P25MHZ   1250000
#define CLOCK_625KHZ    625000

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define INTERNAL_32K_FW_CAL_TIMER_ID        0x00
#define PON_F08_REG                         0xF08  // struct: PON_F00_REG_S
#define SDM_K_CLK_BIT_NUM                   19
#define FAON_REG_LPS_CKMODE_DIV_256         7
#define SPIC0_DIV_2                   0
#define SPIC0_DIV_4                   1
#define SPIC0_DIV_8                   2
#define SPIC0_DIV_16                  3

/* 32k empty function */
#define internal_32k_bypass_sdm_ini           empty_function
#define internal_32k_bypass_sdm_en            empty_function
#define internal_32k_bypass_sdm_check_lock    (uint8_t(*)(void))true_function

/*============================================================================*
 *                      Types
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_types System RTL876X Exported types
  * @{
  */


typedef enum
{
    USE_32K_RCOSC = 0,
    USE_40M_LP_MODE,
    NUM_SDM_CLK_SRC,
} USE_SDM_CLK_SRC_TYPE;

typedef enum
{
    USE_32K_RCOSC_BYPASS_SDM = 0,
    USE_SDM_SRC,
    NUM_CLK_SRC,
} USE_32K_CLK_SRC_TYPE;


typedef enum _CLK_FREQ_TYPE
{
    CLK_625KHZ,  //XTAL div64
    CLK_1P25MHZ, //XTAL div32
    CLK_2P5MHZ,  //XTAL div16
    CLK_3P3MHZ,  //XTAL div12
    CLK_4MHZ,    // XTAL div10
    CLK_5MHZ,    // XTAL div8
    CLK_8MHZ,    // XTAL div5
    CLK_10MHZ,   // XTAL div4
    CLK_20MHZ,   // XTAL div2
    CLK_30MHZ,   // XTAL div(3/4)
    CLK_40MHZ,   // XTAL max freq
    CLK_MAX_FREQ,
} CLK_FREQ_TYPE;


typedef enum _ACTIVE_CLK_SRC
{
    CLK_SRC_XTAL = 0,
    CLK_SRC_OSC,
    CLK_SRC_DEF_MAX,
} ACTIVE_CLK_SRC_TYPE;

typedef enum _ACTIVE_CLK_TYPE
{
    CLK_CPU,
    CLK_SPIC0,
    CLK_40M,
    CLK_MAX
} ACTIVE_CLK_TYPE;

typedef enum
{
    CORE_NORMAL   = 0,
    CORE_SLOW     = 1,
    CORE_MODE_MAX = 2,
} CORE_MODE;

typedef enum
{
    PF_RTC_MODULE   = 0,
    BTMAC_MODULE    = 1,
    AON_MODULE      = 2,
    NUM_MODULE,
} LOW_POW_MODULE_TYPE;

#define _ALPHA_TRACKER_FB_ALG               1

typedef enum _OSC_K_METHOD_SEL_TYPE
{
#if (_ALPHA_TRACKER_FB_ALG == 1)
    SLEEP_K_ALPHA_TRACKER_FB_REG = 0,
#endif
    SLEEP_K_ALPHA_TRACKER,
#if (_ALPHA_TRACKER_FB_ALG == 1)
    ACTIVE_K_ALPHA_TRACKER_FB_REG,
#endif
    ACTIVE_K_ALPHA_TRACKER,
    MAX_K_METHOD_SEL_TYPE,
} OSC_K_METHOD_SEL_TYPE;

typedef enum _CAL_MODE_TYPE
{
    LINEAR_CAL = 0,
    BINEARY_CAL,
    DSM_CAL,
    DSM_CAL_OUT_SEL,
} CAL_MODE_TYPE;

typedef union _BT_EFUSE_CLOCK_CFG
{
    uint32_t value[3] __attribute__((packed));
    struct
    {
        uint32_t clk_src_spic0 : 2;
        uint32_t clk_src_40m :   2;
        uint32_t clk_src_cpu :   2;
        uint32_t clk_src_adc_dac: 2;
        uint32_t clk_freq_cpu : 5;
        uint32_t clk_freq_cpu_slow : 5;
        uint32_t clk_freq_spic0 : 5;
        uint32_t clk_src_non_aon: 1; // BTMAC, RTC
        uint32_t clk_src_aon_32k: 1;
        uint32_t clk_src_sdm: 1;
        uint32_t is_sdm_k : 1;
        uint32_t cal_log_option : 1;
        uint32_t sdm_log_option : 1;
        uint32_t cal_lock_flag : 1;
        uint32_t en_rcosc_aon : 1;
        uint32_t is_lpxtal_pdck_enable : 1;

        uint32_t xtal_aac_pk_sel : 4;
        uint32_t xtal_aac_pk_lp_sel : 4;
        uint32_t is_xtal_aac_enable : 3;
        uint32_t osc_k_method_sel : 2;
        uint32_t osc_periodic_k_interval_sec : 5;
        uint32_t osc_sdmk_num_32k_cyc: 4;
        uint32_t cpu_slow_enable:   1;
        uint32_t cpu_slow_opt_wfi : 1;
        uint32_t cpu_slow_opt_spi0 : 1;
        uint32_t cpu_slow_opt_lcd  : 1;
        uint32_t cpu_slow_opt_at_tx : 1;
        uint32_t cpu_slow_opt_at_rx : 1;
        uint32_t report0_ref_num_shift : 2;
        uint32_t lps_use_new_cal_ini_by_old: 1;
        uint32_t en_osc_debug: 1;

        /**
         * @struct EFUSE_XTAL_CONFIG
         * @brief Xtal EFuse settings.
         *
         * Refer to EFUSE[0x].
         */
        uint8_t sc_xi_40m;
        uint8_t sc_xo_40m;
        uint8_t sc_xi_32k;
        uint8_t sc_xo_32k;
    } __attribute__((packed));
} CLOCK_TREE_CONFIG;

typedef struct
{
    uint8_t cpu_slow_enable :    1;
    uint8_t cpu_slow_opt_wfi :   1;
    uint8_t cpu_slow_opt_spi0 :  1;
    uint8_t cpu_slow_opt_lcd :   1;
    uint8_t cpu_slow_opt_at_tx : 1;
    uint8_t cpu_slow_opt_at_rx : 1;
    uint8_t rsvd               : 2;

} CPU_AUTO_SLOW_TypeDef;

typedef struct INTERNAL32k_SDM_SETTING_S
{
    uint8_t num_32k_cyc;
    uint8_t min_32k_cyc;
    uint16_t tm_n_int;
    uint16_t tm_n_frac;
    uint16_t rsvd_0;
    uint32_t en_sdmk_in_dlps: 1;
    uint32_t alpha_fb_reg_sel: 1;     //select alpha_fb_reg as the alpha tracker feedback value
    uint32_t alpha_ls_5: 5;           //alpha = alpha_ls_5 / 32,  alpha_ls_5 = 0~31
    uint32_t alpha_fb_reg: 22;
    uint32_t already_enabled_sdm_cal: 1;
    uint32_t rsvd_1: 2;
} INTERNAL32k_SDM_SETTING_S_TYPE;

typedef union PON_F08_REG_S  /* Vendor 0xF08 */
{
    uint32_t d32;
    struct
    {
        uint32_t en_osc_debug: 1;          //[0] R/W
        uint32_t cal_auto_resume: 1;       //[1] R/W
        uint32_t min_force_done: 1;        //[2] R/W
        uint32_t cal_mode: 2;              //[4:3]   R/W
        uint32_t min_32k_cyc: 3;           //[7:5]   R/W
        uint32_t num_32k_cyc: 8;           //[15:8]  R/W
        uint32_t src_sel: 1;               //[16]    R/W
        uint32_t rsvd: 15;                 //[31:17] R/W
    };
} PON_F08_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_00_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x00 */
{
    uint16_t d16;
    struct
    {
        uint16_t fw_stop_cal: 1;            //[0]   R/W
        uint16_t reg_sdm_reset_n: 1;        //[1]   R/W
        uint16_t bs_start_bit: 4;           //[5:2]   R/W
        uint16_t cal_mode: 2;               //[7:6]   R/W
        uint16_t cnt_read_mode: 1;          //[8]     R/W
        uint16_t inc_mode: 1;               //[9]     R/W
        uint16_t reg_hw_cal_en: 1;          //[10]    R/W
        uint16_t reg_reset_n: 1;            //[11]    R/W
        uint16_t dsm_fo_sel: 1;             //[12]    R/W
        uint16_t cnt_fref_st_opt: 1;        //[13]    R/W
        uint16_t rsvd_0: 1;                 //[14]    R/W
        uint16_t sw_cal_en: 1;              //[15]    R/W
    };
} BTON_INDIR_32K_00_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_01_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x01 */
{
    uint16_t d16;
    struct
    {
        uint16_t center_cnt_fref_15_0: 16;  //[15:0]  R/W
    };
} BTON_INDIR_32K_01_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_02_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x02 */
{
    uint16_t d16;
    struct
    {
        uint16_t kt_lim: 6;                 //[5:0]   R/W
        uint16_t num_32k_cyc: 8;            //[13:6]  R/W
        uint16_t rsvd: 2;                   //[15:14] R/W
    };
} BTON_INDIR_32K_02_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_03_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x03 */
{
    uint16_t d16;
    struct
    {
        uint16_t tm_RCAL: 15;               //[14:0]  R/W
        uint16_t test_mode: 1;              //[15]    R/W
    };
} BTON_INDIR_32K_03_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_04_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x04 */
{
    uint16_t d16;
    struct
    {
        uint16_t inc_step: 4;               //[3:0]   R/W
        uint16_t num_settle_3_0: 4;         //[7:4]   R/W
        uint16_t center_cnt_fref_21_16: 6;  //[13:8]  R/W
        uint16_t rsvd: 2;                   //[15:14] R/W
    };
} BTON_INDIR_32K_04_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_05_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x05 */
{
    uint16_t d16;
    struct
    {
        uint16_t tm_N_int: 10;              //[9:0]   R/W
        uint16_t rsvd_0: 2;                 //[11:10] R/W
        uint16_t num_settle_6_4: 3;         //[14:12] R/W
        uint16_t rscd_1: 1;                 //[15]    R/W
    };
} BTON_INDIR_32K_05_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_06_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x06 */
{
    uint16_t d16;
    struct
    {
        uint16_t tm_N_frac: 15;             //[14:0]  R/W
        uint16_t rsvd: 1;                   //[15]    R/W
    };
} BTON_INDIR_32K_06_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_07_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x07 */
{
    uint16_t d16;
    struct
    {
        uint16_t N_frac_os: 15;             //[14:0]  R/W
        uint16_t rsvd: 1;                   //[15]    R/W
    };
} BTON_INDIR_32K_07_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_08_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x08 */
{
    uint16_t d16;
    struct
    {
        uint16_t criter0: 10;               //[9:0]   R/W
        uint16_t RCAL_h: 4;                 //[13:10] R/W
        uint16_t dbg_sel: 1;                //[14]    R/W
        uint16_t rsvd: 1;                   //[15]    R/W
    };
} BTON_INDIR_32K_08_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_09_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x09 */
{
    uint16_t d16;
    struct
    {
        uint16_t RCAL: 15;                  //[14:0]  R
        uint16_t rsvd: 1;                   //[15]    R
    };
} BTON_INDIR_32K_09_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_0A_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0A */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_0_15_0: 16;   //[15:0]  R
    };
} BTON_INDIR_32K_0A_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_0B_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0B */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_1_15_0: 16;   //[15:0]  R
    };
} BTON_INDIR_32K_0B_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_0C_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0C */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_2_15_0: 16;   //[15:0]  R
    };
} BTON_INDIR_32K_0C_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_0D_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0D */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_3_15_0: 16;   //[15:0]  R
    };
} BTON_INDIR_32K_0D_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_0E_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0E */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_0_21_16: 6;   //[5:0]   R
        uint16_t Cnt_fref_rep_3_21_16: 6;   //[11:6]  R
        uint16_t rsvd: 4;                   //[15:12] R
    };
} BTON_INDIR_32K_0E_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_0F_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x0F */
{
    uint16_t d16;
    struct
    {
        uint16_t N_int: 10;                 //[9:0]   R
        uint16_t Cnt_fref_rep_1_19_16: 4;   //[13:10] R
        uint16_t rsvd: 2;                   //[15:14] R
    };
} BTON_INDIR_32K_0F_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_10_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x10 */
{
    uint16_t d16;
    struct
    {
        uint16_t N_frac: 15;                //[14:0]  R
        uint16_t rsvd: 1;                   //[15]    R
    };
} BTON_INDIR_32K_10_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_11_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x11 */
{
    uint16_t d16;
    struct
    {
        uint16_t Cnt_fref_rep_2_21_16: 6;   //[5:0]   R
        uint16_t kt_cnt: 6;                 //[11:6]  R
        uint16_t LOCK: 2;                   //[13:12] R
        uint16_t rsvd: 2;                   //[15:14] R/W
    };
} BTON_INDIR_32K_11_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_12_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x12 */
{
    uint16_t d16;
    struct
    {
        uint16_t dbg_cnt_32k: 14;           //[13:0]  R
        uint16_t cal_stop_ready: 1;         //[14]    R
        uint16_t rsvd_15: 1;                //[15] R
    };
} BTON_INDIR_32K_12_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_13_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x13 */
{
    uint16_t d16;
    struct
    {
        uint16_t dsm_cnt_32k: 14;           //[13:0]  R
        uint16_t rsvd_14: 2;                //[15:14] R
    };
} BTON_INDIR_32K_13_REG_S_TYPE;


typedef union
    BTON_INDIR_32K_14_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x14 */
{
    uint16_t d16;
    struct
    {
        uint16_t alpha_ls_5: 5;             //[4:0]   R
        uint16_t lp_xtal_dbg_cnt_18_16: 3;  //[7:5]   R
        uint16_t alpha_fb_reg_21_16: 6;     //[13:8]  R/W
        uint16_t alpha_fb_reg_sel: 1;       //[14]    R/W
        uint16_t rsvd_15: 1;                //[15]    R
    };
} BTON_INDIR_32K_14_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_15_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x15 */
{
    uint16_t d16;
    struct
    {
        uint16_t lp_xtal_dbg_cnt_15_0: 16;  //[15:0]  R
    };
} BTON_INDIR_32K_15_REG_S_TYPE;

typedef union
    BTON_INDIR_32K_16_REG_S  /* Indirect Access by 0x5C.Bit[22] 32k_rw: register offset: 0x16 */
{
    uint16_t d16;
    struct
    {
        uint16_t alpha_fb_reg_15_0: 16;     //[15:0]  R
    };
} BTON_INDIR_32K_16_REG_S_TYPE;

#define get_spic0_clk_div()\
    count_clk_src_div(clk_freq_all_map[clk_cfg.clk_freq_spic0])

typedef struct ALPHA_TRACKER_FB_ALG_DATA_S
{
    int32_t sdm_k_tmeter;
    uint32_t sdm_k_clock;
    uint32_t sdm_k_clock_diff;
    uint32_t sdm_k_osc_f;
} ALPHA_TRACKER_FB_ALG_DATA;

typedef volatile struct ALPHA_TRACKER_FB_ALG_S
{
    uint8_t en_alg;
    uint8_t restart_threshold;
    uint8_t report0_ref_num;
    uint8_t cur_index;
    uint8_t last_used_num_32k_cyc;
    uint16_t normal_k_countdown;
    uint32_t last_report0;
    ALPHA_TRACKER_FB_ALG_DATA(*data)[];
} ALPHA_TRACKER_FB_ALG_S_TYPE;

void init_sdm_setting(void);
void set_xtal40_aac_calibration_rom(void);
void set_xtal40_low_power_pdck_rom(void);
void use_32k_fw_cal_and_reduce_early_time(bool enable);
void init_osc_sdm_timer(void);
void gated_unused_cpu_clock(void);
bool check_required_clk_gen(ACTIVE_CLK_SRC_TYPE active_clk_src);
bool check_required_sdm_clk_src(USE_SDM_CLK_SRC_TYPE clk_src);
bool check_required_bypass_sdm_clk_src(void);
void get_clock_gen_rate(ACTIVE_CLK_TYPE clk_load, CLK_FREQ_TYPE *clk_rate,
                        CLK_FREQ_TYPE *clk_rate_slow);
uint32_t low_stack_get_cpu_clock(void);
void settle_essential_clock(void);
bool check_required_32k_clk_src(USE_32K_CLK_SRC_TYPE clk_src);

extern bool is_switch_sdm_src;
extern USE_32K_CLK_SRC_TYPE aon_32k_src_before_restart;
extern USE_32K_CLK_SRC_TYPE non_aon_32k_src_before_restart;

extern void (*set_cpu_auto_slow)(CPU_AUTO_SLOW_TypeDef cpu_slow_type);
extern uint8_t (*count_clk_src_div)(uint32_t clk_rate_wanted);
extern void (*set_clock_gen)(ACTIVE_CLK_TYPE type, ACTIVE_CLK_SRC_TYPE clk_src);
extern void (*set_active_mode_clk_src)(void);
#define IS_USE_ALPHA_TRACKER_FB_REG()       \
    (clk_cfg.osc_k_method_sel == SLEEP_K_ALPHA_TRACKER_FB_REG \
     || clk_cfg.osc_k_method_sel == ACTIVE_K_ALPHA_TRACKER_FB_REG)

#define IS_USE_ALPHA_TRACKER()       \
    (clk_cfg.osc_k_method_sel == SLEEP_K_ALPHA_TRACKER \
     || clk_cfg.osc_k_method_sel == ACTIVE_K_ALPHA_TRACKER)

#define IS_RESTART_NECESSARY() is_alpha_tracker_fb_alg_restart_necessary()

extern CLOCK_TREE_CONFIG clk_cfg;
extern INTERNAL32k_SDM_SETTING_S_TYPE sdm_setting;
extern ALPHA_TRACKER_FB_ALG_S_TYPE altrac_fb_alg_setting;
extern void (*set_xtal40_low_power_pdck)(void);
extern void (*set_xtal40_aac_calibration)(void);
extern void (*set_clock_output)(ACTIVE_CLK_SRC_TYPE type, bool is_enable);
extern void (*set_clock_gen)(ACTIVE_CLK_TYPE type, ACTIVE_CLK_SRC_TYPE clk_src);
extern void (*set_clock_gen_rate)(ACTIVE_CLK_TYPE clk_load, CLK_FREQ_TYPE clk_rate,
                                  CLK_FREQ_TYPE clk_rate_slow);
extern void (*set_xtal40_capacity)(uint8_t xtal_sc_xi, uint8_t xtal_sc_xo);
extern void (*internal_32k_linear_cal_ini)(void);
extern void (*internal_32k_linear_cal_en)(void);
extern uint8_t(*internal_32k_linear_check_lock)(void);
extern void (*set_32k_clock_setting)(void); \
extern void (*prepare_next_internal_32k_alpha_tracker_sdm_k)(void);
extern bool internal_32k_need_sdmk_by_timer;
extern void (*init_32k_clk_src)(void);
extern void (*alpha_tracker_fb_alg_restart)(uint16_t countdown, bool with_init,
                                            uint32_t restart_reason);
extern void(*handle_alpha_tracker_fb_alg)(void);
extern void (*update_alpha_tracker_fb_para)(void);
extern void (*prepare_next_internal_32k_alpha_tracker_sdm_k)(void);
extern void (*set_32k_clk_src_path)(void);
extern void (*(bton_32k_cal_ini[NUM_CLK_SRC]))(void);
extern void (*(bton_32k_cal_en[NUM_CLK_SRC]))(void);
extern uint8_t (*(bton_32k_cal_check_lock[NUM_CLK_SRC]))(void);
extern bool(*(is_module_clk_32000Hz[NUM_MODULE]))(void) ;
extern uint16_t (*get_btmac_32k_drift_ppm)(void);
extern void (*set_up_32k_clk_src)(void);
extern void (*(sdm_32k_cal_ini[NUM_SDM_CLK_SRC]))(void);
extern void (*(sdm_32k_cal_en[NUM_SDM_CLK_SRC]))(void);
extern void (*work_around_32k_power_glitch)(void);
extern void (*work_around_32k_power_glitch_after_restart)(void);
extern void (*set_xtal_nm_mode_power_cut)(bool enable);
#endif
