/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_enhtim_def.h
* @brief    ENH_TIM related definitions for RTL87x2G
* @details
* @author   Grace_yan
* @date     2023.02.14
* @version  v1.0.1
*********************************************************************************************************
*/
#ifndef RTL_ENHTIM_DEF_H
#define RTL_ENHTIM_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "platform_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          ENHTIM Defines
 *============================================================================*/
/** \defgroup ENHTIM      ENHTIM
  * \brief
  * \{
  */

/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup ENHTIM_Defines ENHTIM Defines
 * \{
 * \ingroup  ENHTIM_Exported_Constants
 */
#define CHIP_ENHTIM_CHANNEL_NUM                        (4)
#define ENHTIM_SUPPORT_LATCH_CNT_0                     (1)
#define ENHTIM_SUPPORT_LATCH_CNT_1                     (1)
#define ENHTIM_SUPPORT_LATCH_CNT_2                     (1)
#define ENHTIM_SUPPORT_PWM_SRC_SELECT                  (1)
#define ENHTIM_SUPPORT_PWM_PHASE_SHIFT                 (1)
#define ENHTIM_SUPPORT_ONESHOT_CMD                     (1)
#define ENHTIM_SUPPORT_CLOCK_SOURCE_CONFIG             (1)

/** End of ENHTIM_Defines
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */

/** End of ENHTIM
  * \}
  */
/*============================================================================*
 *                         ENHTIM Registers Memory Map
 *============================================================================*/
typedef struct
{
    __I  uint32_t ENHTIM_CUR_CNT;                /*!< 0x00 */
    __I  uint32_t ENHTIM_LATCH_CNT_0;            /*!< 0x04 */
    __I  uint32_t ENHTIM_LATCH_CNT_1;            /*!< 0x08 */
    __I  uint32_t ENHTIM_LATCH_CNT_2;            /*!< 0x0C */
    __IO uint32_t ENHTIM_CONFIGURE;              /*!< 0x10 */
    __IO uint32_t ENHTIM_MAX_CNT;                /*!< 0x14 */
    __IO uint32_t ENHTIM_CCR;                    /*!< 0x18 */
    __IO uint32_t ENHTIM_CCR_FIFO_ENTRY;         /*!< 0x1C */
    __IO uint32_t PHASE_SHIFT_CNT;               /*!< 0x20*/
} ENHTIM_TypeDef;

typedef struct
{
    __IO uint32_t ENHTIM_LACTH_FIFO_TH_STATUS;   /*!< 0x120 */
    __IO uint32_t ENHTIM_LATCH_CNT_FIFO_STATUS;  /*!< 0x124 */
    __I  uint32_t ENHTIM_CCR_FIFO_STATUS;        /*!< 0x128 */
    __IO uint32_t ENHTIM_FIFO_CLR;               /*!< 0x12C */
    __IO uint32_t ENHTIM_CONTROL;                /*!< 0x130 */
    __IO uint32_t ENHTIM_INT_CONTROL;            /*!< 0x134 */
    __IO uint32_t ENHTIM_STATUS;                 /*!< 0x138 */
    __I  uint32_t ENHTIM_INT_STATUS;             /*!< 0x13C */
    __IO uint32_t ENHTIM_LATCH_INT_CONTROL_0;    /*!< 0x140 */
    __IO uint32_t RESERVED0;                     /*!< 0x144 */
    __IO uint32_t ENHTIM_LATCH_INT_CONTROL_2;    /*!< 0x148 */
    __IO uint32_t RESERVED1;                     /*!< 0x14C */
    __I  uint32_t ENHTIM0_LATCH_FIFO_DEPTH;      /*!< 0x150 */
    __I  uint32_t ENHTIM1_LATCH_FIFO_DEPTH;      /*!< 0x154 */
    __I  uint32_t ENHTIM2_LATCH_FIFO_DEPTH;      /*!< 0x158 */
    __I  uint32_t ENHTIM3_LATCH_FIFO_DEPTH;      /*!< 0x15C */
    __I  uint32_t RSVD[4];                       /*!< 0x160 - 0x16C */
    __I  uint32_t ENHTIM_TOGGLE_STATE;           /*!< 0x170 */
} ENHTIM_ShareTypeDef;

typedef struct
{
    __IO uint32_t ENHTIMER_PWM_CFG;              /*!< 0x300 */
} ENHPWM_TypeDef;

/*============================================================================*
 *                         ENHTIM Declaration
 *============================================================================*/
/** \defgroup ENHTIM      ENHTIM
  * \brief
  * \{
  */

/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/** \defgroup ENHTIM_Declaration ENHTIM Declaration
  * \{
  * \ingroup  ENHTIM_Exported_Constants
  */
#define ENHANCED_TIMER0_REG_BASE        (ENHANCED_TIMER_REG_BASE + 0x0000)
#define ENHANCED_TIMER1_REG_BASE        (ENHANCED_TIMER_REG_BASE + 0x0024)
#define ENHANCED_TIMER2_REG_BASE        (ENHANCED_TIMER_REG_BASE + 0x0048)
#define ENHANCED_TIMER3_REG_BASE        (ENHANCED_TIMER_REG_BASE + 0x006c)
#define ENHTIM_SHARE_REG_BASE           (ENHANCED_TIMER_REG_BASE + 0x0120)
#define ENHANCED_PWM0_REG_BASE          (ENHANCED_TIMER_REG_BASE + 0x0300)
#define ENHANCED_PWM1_REG_BASE          (ENHANCED_TIMER_REG_BASE + 0x0304)
#define ENHANCED_PWM2_REG_BASE          (ENHANCED_TIMER_REG_BASE + 0x0308)
#define ENHANCED_PWM3_REG_BASE          (ENHANCED_TIMER_REG_BASE + 0x030C)
#define REG_ENHTIMER_ONESHOT_CFG        (ENHANCED_TIMER_REG_BASE + 0x0320)

#define ENH_TIM0                        ((ENHTIM_TypeDef      *) ENHANCED_TIMER0_REG_BASE)
#define ENH_TIM1                        ((ENHTIM_TypeDef      *) ENHANCED_TIMER1_REG_BASE)
#define ENH_TIM2                        ((ENHTIM_TypeDef      *) ENHANCED_TIMER2_REG_BASE)
#define ENH_TIM3                        ((ENHTIM_TypeDef      *) ENHANCED_TIMER3_REG_BASE)
#define ENH_TIM_SHARE                   ((ENHTIM_ShareTypeDef *) ENHTIM_SHARE_REG_BASE)
#define ENH_TIM0_PWM                    ((ENHPWM_TypeDef      *) ENHANCED_PWM0_REG_BASE)
#define ENH_TIM1_PWM                    ((ENHPWM_TypeDef      *) ENHANCED_PWM1_REG_BASE)
#define ENH_TIM2_PWM                    ((ENHPWM_TypeDef      *) ENHANCED_PWM2_REG_BASE)
#define ENH_TIM3_PWM                    ((ENHPWM_TypeDef      *) ENHANCED_PWM3_REG_BASE)

#define IS_ENHTIM_ALL_PERIPH(PERIPH)    (((PERIPH) == ENH_ENHTIM0) || \
                                         ((PERIPH) == ENH_ENHTIM1) || \
                                         ((PERIPH) == ENH_ENHTIM2) || \
                                         ((PERIPH) == ENH_ENHTIM3))
/** End of ENHTIM_Declaration
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */

/** End of ENHTIM
  * \}
  */

/*============================================================================*
 *                         ENHTIM Private Defines
 *============================================================================*/
#define REG_ENHTIMER_CLOCK_CTRL            *((volatile uint32_t *)0x40002344UL)
#define REG_ENHTIMER_0_LATCH_TRIG_CFG      *((volatile uint32_t *)0x400030C0UL)
#define REG_ENHTIMER_1_LATCH_TRIG_CFG      *((volatile uint32_t *)0x400030C4UL)
#define REG_ENHTIMER_2_LATCH_TRIG_CFG      *((volatile uint32_t *)0x400030C8UL)
#define REG_ENHTIMER_3_LATCH_TRIG_CFG      *((volatile uint32_t *)0x400030CCUL)
#define REG_BT_GPIO_TRIG_ENHTIMER_CTRL     *((volatile uint32_t *)0x400030D0UL)
#define REG_BT_TX_ON_TRIG_ENHTIMER_CTRL    *((volatile uint32_t *)0x400030D4UL)
#define REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL  *((volatile uint32_t *)0x400030D8UL)
#define REG_ENHTIMER_ONESHOT               *((volatile uint32_t *)REG_ENHTIMER_ONESHOT_CFG)

/*============================================================================*
 *                         ENHTIM Private Types
 *============================================================================*/
typedef struct
{
    uint32_t enhtim_reg[31];
    uint32_t enhpwm_reg[4];
} ENHTIMStoreReg_Typedef;

/*============================================================================*
 *                         ENHTIM Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R      Enhtimer_cur_cnt                            32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t Enhtimer_cur_cnt: 32;
        } b;
    } ENHTIM_CUR_CNT_TypeDef;



    /* 0x04
       31:0    R      Enhtimer_latch_cnt_0                        32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer_latch_cnt_0: 32;
            } b;
        } ENHTIM_LATCH_CNT_0_TypeDef;



    /* 0x08
       31:0    R      Enhtimer_latch_cnt_1                        32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t reg_timer_0_latch_cnt_1: 32;
            } b;
        } ENHTIM_LATCH_CNT_1_TypeDef;



    /* 0x0C
       31:0    R      Enhtimer_latch_cnt_2                        32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t reg_timer_0_latch_cnt_2: 32;
            } b;
        } ENHTIM_LATCH_CNT_2_TypeDef;



    /* 0x10
       1:0     R/W    Enhtimer_mode                               2'h0
       2       R/W    Enhtimer_PWM_polarity                       1'h0
       3       R/W    Enhtimer_PWM_output_en                      1'h0
       5:4     R/W    Enhtimer_latch_cnt_0_trig_mode              2'h0
       7:6     R/W    Enhtimer_latch_cnt_1_trig_mode              2'h0
       9:8     R/W    Enhtimer_latch_cnt_2_trig_mode              2'h0
       10      R/W    Enhtimer_Latch_cnt_0_en                     1'h0
       11      R/W    Enhtimer_Latch_cnt_1_en                     1'h0
       12      R/W    Enhtimer_Latch_cnt_2_en                     1'h0
       17:13   R/W    Enhtimer_latch_cnt_0_fifo_th                5'h1
       22:18   R/W    RSVD                                        5'h1
       27:23   R/W    RSVD                                        5'h1
       28      R/W    Enhtimer_dma_en                             1'h0
       29      R/W    Enhtimer_dma_mode                           1'h0
       31:30   R/W    Enhtimer_dma_target                         2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_mode: 2;
                uint32_t Enhtimer_PWM_polarity: 1;
                uint32_t Enhtimer_PWM_output_en: 1;
                uint32_t Enhtimer_latch_cnt_0_trig_mode: 2;
                uint32_t Enhtimer_latch_cnt_1_trig_mode: 2;
                uint32_t Enhtimer_latch_cnt_2_trig_mode: 2;
                uint32_t Enhtimer_Latch_cnt_0_en: 1;
                uint32_t Enhtimer_Latch_cnt_1_en: 1;
                uint32_t Enhtimer_Latch_cnt_2_en: 1;
                uint32_t Enhtimer_latch_cnt_0_fifo_th: 5;
                uint32_t reserved_1: 5;
                uint32_t reserved_0: 5;
                uint32_t Enhtimer_dma_en: 1;
                uint32_t Enhtimer_dma_mode: 1;
                uint32_t Enhtimer_dma_target: 2;
            } b;
        } ENHTIM_CONFIGURE_TypeDef;



    /* 0x14
       31:0    R/W    Enhtimer_max_cnt                            32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_max_cnt: 32;
            } b;
        } ENHTIM_MAX_CNT_TypeDef;



    /* 0x18
       31:0    R/W    Enhtimer_ccr                                32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_ccr: 32;
            } b;
        } ENHTIM_CCR_TypeDef;



    /* 0x1C
       31:0    R/W    Enhtimer_ccr_fifo_entry                     32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_ccr_fifo_entry: 32;
            } b;
        } ENHTIM_CCR_FIFO_ENTRY_TypeDef;




    /* 0x20
        31:0    R/W    Enhtimer_pwm_phase_shift_cnt             32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_pwm_phase_shift_cnt: 32;
            } b;
        } ENHTIMER_0_PWM_SHIFT_CNT_TypeDef;



    /* 0x120
       0       R/W1C  Enhtimer0_latch_cnt_0_fifo_met_th           1'h0
       1       R/W1C  Enhtimer1_latch_cnt_0_fifo_met_th           1'h0
       2       R/W1C  Enhtimer2_latch_cnt_0_fifo_met_th           1'h0
       3       R/W1C  Enhtimer3_latch_cnt_0_fifo_met_th           1'h0
       31:4    R      RSVD                                        28'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer0_latch_cnt_0_fifo_met_th: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_met_th: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_met_th: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_met_th: 1;
                const uint32_t reserved_0: 28;
            } b;
        } ENHTIM_LACTH_FIFO_TH_STATUS_TypeDef;



    /* 0x124
       0       R/W1C  Enhtimerr0_latch_cnt_0_fifo_full            1'h0
       1       R      Enhtimer0_latch_cnt_0_fifo_empty            1'h1
       2       R/W1C  Enhtimer1_latch_cnt_0_fifo_full             1'h0
       3       R      Enhtimer1_latch_cnt_0_fifo_empty            1'h1
       4       R/W1C  Enhtimer2_latch_cnt_0_fifo_full             1'h0
       5       R      Enhtimer2_latch_cnt_0_fifo_empty            1'h1
       6       R/W1C  Enhtimer3_latch_cnt_0_fifo_full             1'h0
       7       R      Enhtimer3_latch_cnt_0_fifo_empty            1'h1
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimerr0_latch_cnt_0_fifo_full: 1;
                const uint32_t Enhtimer0_latch_cnt_0_fifo_empty: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_full: 1;
                const uint32_t Enhtimer1_latch_cnt_0_fifo_empty: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_full: 1;
                const uint32_t Enhtimer2_latch_cnt_0_fifo_empty: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_full: 1;
                const uint32_t Enhtimer3_latch_cnt_0_fifo_empty: 1;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM_LATCH_CNT_FIFO_STATUS_TypeDef;



    /* 0x128
       0       R      Enhtimerr0_ccr_fifo_full                    1'h0
       1       R      Enhtimer0_ccr_fifo_empty                    1'h1
       2       R      Enhtimer1_ccr_fifo_full                     1'h0
       3       R      Enhtimer1_ccr_fifo_empty                    1'h1
       4       R      Enhtimer2_ccr_fifo_full                     1'h0
       5       R      Enhtimer2_ccr_fifo_empty                    1'h1
       6       R      Enhtimer3_ccr_fifo_full                     1'h0
       7       R      Enhtimer3_ccr_fifo_empty                    1'h1
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimerr0_ccr_fifo_full: 1;
                const uint32_t Enhtimer0_ccr_fifo_empty: 1;
                const uint32_t Enhtimer1_ccr_fifo_full: 1;
                const uint32_t Enhtimer1_ccr_fifo_empty: 1;
                const uint32_t Enhtimer2_ccr_fifo_full: 1;
                const uint32_t Enhtimer2_ccr_fifo_empty: 1;
                const uint32_t Enhtimer3_ccr_fifo_full: 1;
                const uint32_t Enhtimer3_ccr_fifo_empty: 1;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM_CCR_FIFO_STATUS_TypeDef;



    /* 0x12C
       0       R/W1C  Enhtimer0_ccr_fifo_clr                      1'h0
       1       R/W1C  Enhtimer1_ccr_fifo_clr                      1'h0
       2       R/W1C  Enhtimer2_ccr_fifo_clr                      1'h0
       3       R/W1C  Enhtimer3_ccr_fifo_clr                      1'h0
       7:4     R      RSVD0                                       4'h0
       8       R/W1C  Enhtimer0_latch_cnt_0_fifo_clr              1'h0
       9       R/W1C  Enhtimer1_latch_cnt_0_fifo_clr              1'h0
       10      R/W1C  Enhtimer2_latch_cnt_0_fifo_clr              1'h0
       11      R/W1C  Enhtimer3_latch_cnt_0_fifo_clr              1'h0
       31:12   R      RSVD1                                       20'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer0_ccr_fifo_clr: 1;
                uint32_t Enhtimer1_ccr_fifo_clr: 1;
                uint32_t Enhtimer2_ccr_fifo_clr: 1;
                uint32_t Enhtimer3_ccr_fifo_clr: 1;
                const  uint32_t reserved_0: 4;
                uint32_t Enhtimer0_latch_cnt_0_fifo_clr: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_clr: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_clr: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_clr: 1;
                const  uint32_t reserved_1: 20;
            } b;
        } ENHTIM_FIFO_CLR_TypeDef;



    /* 0x130
       0       R/W    Enhtimer0_enable                            1'h0
       1       R/W    Enhtimer1_enable                            1'h0
       2       R/W    Enhtimer2_enable                            1'h0
       3       R/W    Enhtimer3_enable                            1'h0
       31:4    R      RSVD                                        28'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer0_enable: 1;
                uint32_t Enhtimer1_enable: 1;
                uint32_t Enhtimer2_enable: 1;
                uint32_t Enhtimer3_enable: 1;
                const uint32_t reserved_0: 28;
            } b;
        } ENHTIM_CONTROL_TypeDef;



    /* 0x134
       0       R/W    Enhtimer0_Interrupt_enable                  1'h0
       1       R/W    Enhtimer1_Interrupt_enable                  1'h0
       2       R/W    Enhtimer2_Interrupt_enable                  1'h0
       3       R/W    Enhtimer3_Interrupt_enable                  1'h0
       31:4    R      RSVD                                        28'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer0_Interrupt_enable: 1;
                uint32_t Enhtimer1_Interrupt_enable: 1;
                uint32_t Enhtimer2_Interrupt_enable: 1;
                uint32_t Enhtimer3_Interrupt_enable: 1;
                uint32_t reserved_0: 28;
            } b;
        } ENHTIM_INT_CONTROL_TypeDef;



    /* 0x138
       0       R/W1C  Enhtimer0_Status                            1'h0
       1       R/W1C  Enhtimer1_Status                            1'h0
       2       R/W1C  Enhtimer2_Status                            1'h0
       3       R/W1C  Enhtimer3_Status                            1'h0
       7:4     R      RSVD0                                       4'h0
       8       R/W1C  Enhtimer0_latch_cnt_0_fifo_intr_status      1'h0
       9       R/W1C  Enhtimer1_latch_cnt_0_fifo_intr_status      1'h0
       10      R/W1C  Enhtimer2_latch_cnt_0_fifo_intr_status      1'h0
       11      R/W1C  Enhtimer3_latch_cnt_0_fifo_intr_status      1'h0
       31:12   R      RSVD1                                       20'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer0_Status: 1;
                uint32_t Enhtimer1_Status: 1;
                uint32_t Enhtimer2_Status: 1;
                uint32_t Enhtimer3_Status: 1;
                uint32_t reserved_0: 4;
                uint32_t Enhtimer0_latch_cnt_0_fifo_intr_status: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_intr_status: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_intr_status: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_intr_status: 1;
                uint32_t reserved_1: 20;
            } b;
        } ENHTIM_STATUS_TypeDef;



    /* 0x13C
       0       R      reg_timer_0_interrupt_masked                1'h0
       1       R      reg_timer_1_interrupt_masked                1'h0
       2       R      reg_timer_2_interrupt_masked                1'h0
       3       R      reg_timer_3_interrupt_masked                1'h0
       31:8    R      RSVD                                        28'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t reg_timer_0_interrupt_masked: 1;
                const uint32_t reg_timer_1_interrupt_masked: 1;
                const uint32_t reg_timer_2_interrupt_masked: 1;
                const uint32_t reg_timer_3_interrupt_masked: 1;
                const uint32_t reserved_0: 28;
            } b;
        } ENHTIM_INT_STATUS_TypeDef;



    /* 0x140
       7:0     R      RSVD                                        8'h0
       8       R/W    Enhtimer0_latch_cnt_0_fifo_full_intr_en     1'h0
       9       R/W    Enhtimer1_latch_cnt_0_fifo_full_intr_en     1'h0
       10      R/W    Enhtimer2_latch_cnt_0_fifo_full_intr_en     1'h0
       11      R/W    Enhtimer3_latch_cnt_0_fifo_full_intr_en     1'h0
       31:12   R      RSVD                                        16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t reserved_16: 8;
                uint32_t Enhtimer0_latch_cnt_0_fifo_full_intr_en: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_full_intr_en: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_full_intr_en: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_full_intr_en: 1;
                const  uint32_t reserved_0: 20;
            } b;
        } ENHTIM_LATCH_INT_CONTROL_0_TypeDef;



    /* 0x148
       7:0     R      RSVD                                        8'h0
       8       R/W    Enhtimer0_latch_cnt_0_fifo_met_th_intr_en   1'h0
       9       R/W    Enhtimer1_latch_cnt_0_fifo_met_th_intr_en   1'h0
       10      R/W    Enhtimer2_latch_cnt_0_fifo_met_th_intr_en   1'h0
       11      R/W    Enhtimer3_latch_cnt_0_fifo_met_th_intr_en   1'h0
       31:12   R      RSVD                                        20'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const  uint32_t reserved_1: 8;
                uint32_t Enhtimer0_latch_cnt_0_fifo_met_th_intr_en: 1;
                uint32_t Enhtimer1_latch_cnt_0_fifo_met_th_intr_en: 1;
                uint32_t Enhtimer2_latch_cnt_0_fifo_met_th_intr_en: 1;
                uint32_t Enhtimer3_latch_cnt_0_fifo_met_th_intr_en: 1;
                const  uint32_t reserved_0: 20;
            } b;
        } ENHTIM_LATCH_INT_CONTROL_2_TypeDef;




    /* 0x150
       7:0     R      Enhtimer0_latch_cnt_0_fifo_depth            8'h0
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer0_latch_cnt_0_fifo_depth: 8;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM0_LATCH_FIFO_DEPTH_TypeDef;



    /* 0x154
       7:0     R      Enhtimer1_latch_cnt_0_fifo_depth            8'h0
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer1_latch_cnt_0_fifo_depth: 8;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM1_LATCH_FIFO_DEPTH_TypeDef;



    /* 0x158
       7:0     R      Enhtimer2_latch_cnt_0_fifo_depth            8'h0
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer2_latch_cnt_0_fifo_depth: 8;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM2_LATCH_FIFO_DEPTH_TypeDef;



    /* 0x15C
       7:0     R      Enhtimer3_latch_cnt_0_fifo_depth            8'h0
       31:8    R      RSVD                                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer3_latch_cnt_0_fifo_depth: 8;
                const uint32_t reserved_0: 24;
            } b;
        } ENHTIM3_LATCH_FIFO_DEPTH_TypeDef;



    /* 0x170
       0       R      Enhtimer0_toggle_state                      1'h0
       1       R      Enhtimer1_toggle_state                      1'h0
       2       R      Enhtimer2_toggle_state                      1'h0
       3       R      Enhtimer3_toggle_state                      1'h0
       31:4    R      RSVD                                        28'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t Enhtimer0_toggle_state: 1;
                const uint32_t Enhtimer1_toggle_state: 1;
                const uint32_t Enhtimer2_toggle_state: 1;
                const uint32_t Enhtimer3_toggle_state: 1;
                const uint32_t reserved_0: 28;
            } b;
        } ENHTIM_TOGGLE_STATE_TypeDef;



    /* 0x300
        7:0     R/W    enhtimer_pwm_dz_size                     8'h0
        8       R/W    enhtimer_pwm_dz_emg_stop                 1'h0
        9       R/W    enhtimer_pwm_dz_stop_state_n             1'h0
        10      R/W    enhtimer_pwm_dz_stop_state_p             1'h0
        11      R/W    enhtimer_pwm_dz_en                       1'h0
        13:12   R/W    enhtimer_pwm_dz_ref_sel                  2'h0
        14      R/W    enhtimer_pwm_dz_ref_n_inv_en             1'h0
        15      R/W    enhtimer_pwm_dz_ref_p_inv_en             1'h0
        16      R/W    enhtimer_pwm_open_drain_en               1'h0
        31:17   R      RSVD529                                     15'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t enhtimer_pwm_dz_size: 8;
                uint32_t enhtimer_pwm_dz_emg_stop: 1;
                uint32_t enhtimer_pwm_dz_stop_state_n: 1;
                uint32_t enhtimer_pwm_dz_stop_state_p: 1;
                uint32_t enhtimer_pwm_dz_en: 1;
                uint32_t enhtimer_pwm_dz_ref_sel: 2;
                uint32_t enhtimer_pwm_dz_ref_n_inv_en: 1;
                uint32_t enhtimer_pwm_dz_ref_p_inv_en: 1;
                uint32_t enhtimer_pwm_open_drain_en: 1;
                const uint32_t RSVD529: 15;
            } b;
        } ENHTIMER_PWM_CFG_TypeDef;



    /* 0x320
        0       R/W    Enhtimer_0_oneshot_mode_en                 1'h0
        1       R/W    Enhtimer_1_oneshot_mode_en                 1'h0
        2       R/W    Enhtimer_2_oneshot_mode_en                 1'h0
        3       R/W    Enhtimer_3_oneshot_mode_en                 1'h0
        7:4     R/W    RSVD0                                       4'h0
        8       R/WAC  Enhtimer_0_oneshot_go                      1'h0
        9       R/WAC  Enhtimer_1_oneshot_go                      1'h0
        10      R/WAC  Enhtimer_2_oneshot_go                      1'h0
        11      R/WAC  Enhtimer_3_oneshot_go                      1'h0
        31:12   R/W    RSVD1                                       20'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t Enhtimer_0_oneshot_mode_en: 1;
                uint32_t Enhtimer_1_oneshot_mode_en: 1;
                uint32_t Enhtimer_2_oneshot_mode_en: 1;
                uint32_t Enhtimer_3_oneshot_mode_en: 1;
                const  uint32_t RSVD0: 4;
                uint32_t Enhtimer_0_oneshot_go: 1;
                uint32_t Enhtimer_1_oneshot_go: 1;
                uint32_t Enhtimer_2_oneshot_go: 1;
                uint32_t Enhtimer_3_oneshot_go: 1;
                const  uint32_t RSVD1: 20;
            } b;
        } ENHTIMER_ONESHOT_CFG_TypeDef;

    /*============================================================================*
     *                          ENHTIM Constants
     *============================================================================*/
    /** \defgroup ENHTIM      ENHTIM
      * \brief
      * \{
      */

    /** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
      * \brief
      * \{
      */

    /**
     * \defgroup  ENHTIM_Clock_Source ENHTIM Clock Source
     * \{
     * \ingroup   ENHTIM_Exported_Constants
     */
    typedef enum
{
    ENHTIM_CLOCK_SOURCE_40M = 0x00,
    ENHTIM_CLOCK_SOURCE_PLL1 = 0x01,
    ENHTIM_CLOCK_SOURCE_PLL2 = 0x02,
    ENHTIM_CLOCK_SOURCE_32K = 0x04,
} ENHTIMClkSrc_TypdDef;

#define IS_ENHTIM_CLK_SOURCE(src) (((src) == ENHTIM_CLOCK_SOURCE_40M) || \
                                   ((src) == ENHTIM_CLOCK_SOURCE_32K)|| \\
                                   ((src) == ENHTIM_CLOCK_SOURCE_PLL2)|| \\
                                   ((src) == ENHTIM_CLOCK_SOURCE_PLL1))

/** End of ENHTIM_Clock_Source
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */

/** End of ENHTIM
  * \}
  */

/*============================================================================*
 *                          ENHTIM TYPE/API Wrappers
 *============================================================================*/
/** \defgroup ENHTIM         ENHTIM
  * \brief
  * \{
  */

/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/**
 * \brief       To be compatible with the previous driver.
 * \defgroup    ENHTIM_API_Wrapper ENHTIM API Wrapper
 * \{
 * \ingroup     ENHTIM_Exported_Constants
 */
#define ENHTIM_SOURCE_CLOCK_40M     ENHTIM_CLOCK_SOURCE_40M
#define ENHTIM_SOURCE_CLOCK_PLL1    ENHTIM_CLOCK_SOURCE_PLL1
#define ENHTIM_SOURCE_CLOCK_PLL2    ENHTIM_CLOCK_SOURCE_PLL2

/** End of ENHTIM_API_Wrapper
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */

/** End of ENHTIM
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_ENHTIM_DEF_H */
