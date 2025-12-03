/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_aon_qdec_def.h
* \brief    AON QDEC Registers Structures Section
* \details
* \author   grace yan
* \date     2023-02-20
* \version  v1.1
* *********************************************************************************************************
*/
#ifndef RTL_AON_QDEC_DEF_H
#define RTL_AON_QDEC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         AON QDEC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t AON_QDEC_CONFIG;           /*!< 0x00 */
    __I  uint32_t AON_QDEC_SR_X;             /*!< 0x04 */
    __IO uint32_t AON_QDEC_INT_CLR;          /*!< 0x08 */
} AON_QDEC_TypeDef;

/*============================================================================*
 *                         AON QDEC Declaration
 *============================================================================*/
#define AON_QDEC                    ((AON_QDEC_TypeDef *)  QUAD_DECODER_REG_BASE)

#define IS_AON_QDEC_PERIPH(PERIPH)  ((PERIPH) == AON_QDEC)

/*============================================================================*
 *                         AON QDEC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   1:0     R/W    x_initial_phase         2'h0
   2       R/W    x_set_initial_phase     1'h0
   3       R/W    x_cnt_pause             1'h0
   4       R/W    x_cnt_scale             1'h0
   5       R/W    x_illegal_int_en        1'h0
   6       R/W    x_cnt_int_en            1'h0
   7       R/W    illegal_int_mask        1'h1
   8       R/W    cnt_int_mask            1'h1
   21:9    R/W    x_debounce_cnt          13'h0
   22      R/W    x_debounce_en           1'h0
   23      R/W    x_wake_aon_mask         1'b1
   24      R/W    x_int_mask              1'b1
   28:25   R/W    reg_config_dummy1       4'b0
   29      R/W    x_rst                   1'b0
   30      R/WAC  x_fsm_en                1'h0
   31      R/W    x_axis_en               1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t x_initial_phase: 2;
        uint32_t x_set_initial_phase: 1;
        uint32_t x_cnt_pause: 1;
        uint32_t x_cnt_scale: 1;
        uint32_t x_illegal_int_en: 1;
        uint32_t x_cnt_int_en: 1;
        uint32_t illegal_int_mask: 1;
        uint32_t cnt_int_mask: 1;
        uint32_t x_debounce_cnt: 13;
        uint32_t x_debounce_en: 1;
        uint32_t x_wake_aon_mask: 1;
        uint32_t x_int_mask: 1;
        uint32_t reg_config_dummy1: 4;
        uint32_t x_rst: 1;
        uint32_t x_fsm_en: 1;
        uint32_t x_axis_en: 1;
    } b;
} AON_QDEC_CONFIG_TypeDef;



/* 0x04
   15:0    R      acc_cnt                 16'h0
   16      R/W1C  cnt_of_flg              1'h0
   17      R/W1C  cnt_uf_flg              1'h0
   18      R/W1C  cnt_int_sta             1'h0
   19      R/W1C  illegal_int_sta         1'h0
   20      R      cnt_dir                 1'h0
   21      R/W    reg_sr_x_dummy          1'h0
   23:22   R      debug_state_x           2'h0
   31:24   R      debug_illegal_counter_x 8'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const  uint32_t acc_cnt: 16;
            uint32_t cnt_of_flg: 1;
            uint32_t cnt_uf_flg: 1;
            uint32_t cnt_int_sta: 1;
            uint32_t illegal_int_sta: 1;
            const  uint32_t cnt_dir: 1;
            uint32_t reserved_0: 1;
            const  uint32_t debug_state_x: 2;
            const  uint32_t debug_illegal_counter_x: 8;
        } b;
    } AON_QDEC_SR_X_TypeDef;



    /* 0x08
       0       W1C    acc_cnt_clr                 1'h0
       1       W1C    cnt_int_clr                 1'h0
       2       W1C    of_flg_clr                  1'h0
       3       W1C    uf_flg_clr                  1'h0
       4       W1C    illegal_int_clr             1'h0
       5       W1C    illegal_cnt_clr             1'h0
       31:6    R/W    reserved31_6                26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t acc_cnt_clr: 1;
                uint32_t cnt_int_clr: 1;
                uint32_t of_flg_clr: 1;
                uint32_t uf_flg_clr: 1;
                uint32_t illegal_int_clr: 1;
                uint32_t illegal_cnt_clr: 1;
                uint32_t reserved_0: 26;
            } b;
        } AON_QDEC_INT_CLR_TypeDef;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_AON_QDEC_DEF_H */
