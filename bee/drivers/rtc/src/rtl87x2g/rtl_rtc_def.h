/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_rtc_def.h
* \brief    RTC Registers Structures Section
* \details
* \author   grace_yan
* \date     2023-02-14
* \version  v2.1.0
* *********************************************************************************************************
*/

#ifndef RTL_RTC_DEF_H
#define RTL_RTC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"
#include "armv81mml_setting.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/*============================================================================*
 *                          RTC Defines
 *============================================================================*/
/** \defgroup RTC         RTC
  * \brief
  * \{
  */

/** \defgroup RTC_Exported_Constants RTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup RTC_Defines RTC Defines
 * \{
 * \ingroup  RTC_Exported_Constants
 */
#define RTC_SUPPORT_CLK_INPUT_FROM_PAD_SEL             (1)
#define RTC_SUPPORT_PRE_COMP_OVF_TICK_WAKE_UP          (1)
#define RTC_SUPPORT_COMPARE_GUARDTIME                  (1)

/** End of RTC_Defines
  * \}
  */

/** End of RTC_Exported_Constants
  * \}
  */

/** End of RTC
  * \}
  */

/*============================================================================*
 *                         RTC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t RTC_CR0;                  /*!< 0X00 */
    __IO uint32_t RTC_INT_CLEAR;            /*!< 0X04 */
    __IO uint32_t RTC_INT_SR;               /*!< 0X08 */
    __IO uint32_t RTC_PRESCALER0;           /*!< 0X0C */
    __IO uint32_t RTC_COMP_0;               /*!< 0X10 */
    __IO uint32_t RTC_COMP_1;               /*!< 0X14 */
    __IO uint32_t RTC_COMP_2;               /*!< 0X18 */
    __IO uint32_t RTC_COMP_3;               /*!< 0X1C */
    __IO uint32_t RTC_COMP0_GT;             /*!< 0X20 */
    __IO uint32_t RTC_COMP1_GT;             /*!< 0X24 */
    __IO uint32_t RTC_COMP2_GT;             /*!< 0X28 */
    __IO uint32_t RTC_COMP3_GT;             /*!< 0X2C */
    __I  uint32_t RTC_CNT0;                 /*!< 0X30 */
    __IO uint32_t RTC_PRESCALE_CNT0;        /*!< 0X34 */
    __IO uint32_t RTC_PRESCALE_CMP0;        /*!< 0X38 */
    __IO uint32_t RTC_BACKUP;               /*!< 0X3C */
    __I  uint32_t RTC_RTL_VERSION0;         /*!< 0X40 */
} RTC_TypeDef;

/*============================================================================*
 *                         RTC Declaration
 *============================================================================*/
#define RTC                ((RTC_TypeDef *) RTC_REG_BASE)

/*============================================================================*
 *                         RTC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   0       R/W    rtc_cnt_start           1'b0
   1       R/W    rtc_cnt_rst             1'b0
   2       R/W    rtc_pre_cnt_rst         1'b0
   7:3     R/W    rtc_cr0_dummy0          5'b0
   8       R/W    rtc_tick_ie             1'b0
   9       R/W    rtc_cnt_ov_ie           1'b0
   10      R/W    rtc_precmp_ie           1'b0
   11      R/W    rtc_precmp_cmp3_ie      1'b0
   12      R/W    rtc_cmp0gt_ie           1'b0
   13      R/W    rtc_cmp1gt_ie           1'b0
   14      R/W    rtc_cmp2gt_ie           1'b0
   15      R/W    rtc_cmp3gt_ie           1'b0
   16      R/W    rtc_cmp0_nv_ie          1'b0
   17      R/W    rtc_cmp1_nv_ie          1'b0
   18      R/W    rtc_cmp2_nv_ie          1'b0
   19      R/W    rtc_cmp3_nv_ie          1'b0
   20      R/W    rtc_cmp0_wk_ie          1'b0
   21      R/W    rtc_cmp1_wk_ie          1'b0
   22      R/W    rtc_cmp2_wk_ie          1'b0
   23      R/W    rtc_cmp3_wk_ie          1'b0
   28:24   R/W    rtc_cr0_dummy1          5'b0
   29      R/W    rtc_wk_ie               1'b0
   30      R/W    rtc_nv_ie               1'b0
   31      R/W    rtc_rst                 1'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cnt_start: 1;
        uint32_t rtc_cnt_rst: 1;
        uint32_t rtc_pre_cnt_rst: 1;
        uint32_t rtc_cr0_dummy0: 5;
        uint32_t rtc_tick_ie: 1;
        uint32_t rtc_cnt_ov_ie: 1;
        uint32_t rtc_precmp_ie: 1;
        uint32_t rtc_precmp_cmp3_ie: 1;
        uint32_t rtc_cmp0gt_ie: 1;
        uint32_t rtc_cmp1gt_ie: 1;
        uint32_t rtc_cmp2gt_ie: 1;
        uint32_t rtc_cmp3gt_ie: 1;
        uint32_t rtc_cmp0_nv_ie: 1;
        uint32_t rtc_cmp1_nv_ie: 1;
        uint32_t rtc_cmp2_nv_ie: 1;
        uint32_t rtc_cmp3_nv_ie: 1;
        uint32_t rtc_cmp0_wk_ie: 1;
        uint32_t rtc_cmp1_wk_ie: 1;
        uint32_t rtc_cmp2_wk_ie: 1;
        uint32_t rtc_cmp3_wk_ie: 1;
        uint32_t rtc_cr0_dummy1: 5;
        uint32_t rtc_wk_ie: 1;
        uint32_t rtc_nv_ie: 1;
        uint32_t rtc_rst: 1;
    } b;
} RTC_CR0_TypeDef;



/* 0x04
   0       R/WAC  rtc_tick_clr            1'b0
   1       R/WAC  rtc_cnt_ov_clr          1'b0
   2       R/WAC  rtc_precmp_clr          1'b0
   3       R/WAC  rtc_precmp_cmp3_clr     1'b0
   4       R/WAC  rtc_cmp0gt_clr          1'b0
   5       R/WAC  rtc_cmp1gt_clr          1'b0
   6       R/WAC  rtc_cmp2gt_clr          1'b0
   7       R/WAC  rtc_cmp3gt_clr          1'b0
   8       R/WAC  rtc_cmp0_nv_clr         1'b0
   9       R/WAC  rtc_cmp1_nv_clr         1'b0
   10      R/WAC  rtc_cmp2_nv_clr         1'b0
   11      R/WAC  rtc_cmp3_nv_clr         1'b0
   12      R/WAC  rtc_cmp0_wk_clr         1'b0
   13      R/WAC  rtc_cmp1_wk_clr         1'b0
   14      R/WAC  rtc_cmp2_wk_clr         1'b0
   15      R/WAC  rtc_cmp3_wk_clr         1'b0
   31:16   R/W    rtc_int_clear_dummy     16'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_tick_clr: 1;
        uint32_t rtc_cnt_ov_clr: 1;
        uint32_t rtc_precmp_clr: 1;
        uint32_t rtc_precmp_cmp3_clr: 1;
        uint32_t rtc_cmp0gt_clr: 1;
        uint32_t rtc_cmp1gt_clr: 1;
        uint32_t rtc_cmp2gt_clr: 1;
        uint32_t rtc_cmp3gt_clr: 1;
        uint32_t rtc_cmp0_nv_clr: 1;
        uint32_t rtc_cmp1_nv_clr: 1;
        uint32_t rtc_cmp2_nv_clr: 1;
        uint32_t rtc_cmp3_nv_clr: 1;
        uint32_t rtc_cmp0_wk_clr: 1;
        uint32_t rtc_cmp1_wk_clr: 1;
        uint32_t rtc_cmp2_wk_clr: 1;
        uint32_t rtc_cmp3_wk_clr: 1;
        uint32_t rtc_int_clear_dummy: 16;
    } b;
} RTC_INT_CLEAR_TypeDef;



/* 0x08
   0       R/W1C  rtc_tick_sr             1'b0
   1       R/W1C  rtc_cnt_ov_sr           1'b0
   2       R/W1C  rtc_precmp_sr           1'b0
   3       R/W1C  rtc_precmp_cmp3_sr      1'b0
   4       R/W1C  rtc_cmp0gt_sr           1'b0
   5       R/W1C  rtc_cmp1gt_sr           1'b0
   6       R/W1C  rtc_cmp2gt_sr           1'b0
   7       R/W1C  rtc_cmp3gt_sr           1'b0
   8       R/W1C  rtc_cmp0_nv_sr          1'b0
   9       R/W1C  rtc_cmp1_nv_sr          1'b0
   10      R/W1C  rtc_cmp2_nv_sr          1'b0
   11      R/W1C  rtc_cmp3_nv_sr          1'b0
   12      R/W1C  rtc_cmp0_wk_sr          1'b0
   13      R/W1C  rtc_cmp1_wk_sr          1'b0
   14      R/W1C  rtc_cmp2_wk_sr          1'b0
   15      R/W1C  rtc_cmp3_wk_sr          1'b0
   31:16   R/W    rtc_int_sr_dummy        16'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_tick_sr: 1;
        uint32_t rtc_cnt_ov_sr: 1;
        uint32_t rtc_precmp_sr: 1;
        uint32_t rtc_precmp_cmp3_sr: 1;
        uint32_t rtc_cmp0gt_sr: 1;
        uint32_t rtc_cmp1gt_sr: 1;
        uint32_t rtc_cmp2gt_sr: 1;
        uint32_t rtc_cmp3gt_sr: 1;
        uint32_t rtc_cmp0_nv_sr: 1;
        uint32_t rtc_cmp1_nv_sr: 1;
        uint32_t rtc_cmp2_nv_sr: 1;
        uint32_t rtc_cmp3_nv_sr: 1;
        uint32_t rtc_cmp0_wk_sr: 1;
        uint32_t rtc_cmp1_wk_sr: 1;
        uint32_t rtc_cmp2_wk_sr: 1;
        uint32_t rtc_cmp3_wk_sr: 1;
        uint32_t rtc_int_sr_dummy: 16;
    } b;
} RTC_INT_SR_TypeDef;



/* 0x0C
   11:0    R/W    rtc_prescaler           12'b0
   31:12   R/W    rtc_prescaler_dummy     20'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_prescaler: 12;
        uint32_t rtc_prescaler_dummy: 20;
    } b;
} RTC_PRESCALER0_TypeDef;



/* 0x10
   31:0    R/W    rtc_cmp0                32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp0: 32;
    } b;
} RTC_COMP_0_TypeDef;



/* 0x14
   31:0    R/W    rtc_cmp1                32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp1: 32;
    } b;
} RTC_COMP_1_TypeDef;



/* 0x18
   31:0    R/W    rtc_cmp2                32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp2: 32;
    } b;
} RTC_COMP_2_TypeDef;



/* 0x1C
   31:0    R/W    rtc_cmp3                32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp3: 32;
    } b;
} RTC_COMP_3_TypeDef;



/* 0x20
   31:0    R/W    rtc_cmp0gt              32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp0gt: 32;
    } b;
} RTC_COMP0_GT_TypeDef;



/* 0x24
   31:0    R/W    rtc_cmp1gt              32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp1gt: 32;
    } b;
} RTC_COMP1_GT_TypeDef;



/* 0x28
   31:0    R/W    rtc_cmp2gt              32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp2gt: 32;
    } b;
} RTC_COMP2_GT_TypeDef;



/* 0x2C
   31:0    R/W    rtc_cmp3gt              32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t rtc_cmp3gt: 32;
    } b;
} RTC_COMP3_GT_TypeDef;



/* 0x30
   31:0    R      rtc_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t rtc_cnt: 32;
        } b;
    } RTC_CNT0_TypeDef;



    /* 0x34
       11:0    R      rtc_prescale_cnt        12'b0
       31:12   R/W    rtc_prescale_cnt_dummy  20'b0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rtc_prescale_cnt: 12;
                uint32_t rtc_prescale_cnt_dummy: 20;
            } b;
        } RTC_PRESCALE_CNT0_TypeDef;



    /* 0x38
       11:0    R/W    rtc_prescale_cmp        12'b0
       31:12   R/W    rtc_prescale_cmp_dummy  20'b0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rtc_prescale_cmp: 12;
                uint32_t rtc_prescale_cmp_dummy: 20;
            } b;
        } RTC_PRESCALE_CMP0_TypeDef;



    /* 0x3C
       31:0    R/W    rtc_backup              32'b0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rtc_backup: 32;
            } b;
        } RTC_BACKUP_TypeDef;



    /* 0x40
       31:0    R      rtc_rtl_version         32'h2112180A
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rtc_rtl_version: 32;
            } b;
        } RTC_RTL_VERSION0_TypeDef;


    /*============================================================================*
     *                          RTC Constants
     *============================================================================*/
    /** \defgroup RTC        RTC
      * \brief
      * \{
      */

    /** \defgroup RTC_Exported_Constants RTC Exported Constants
      * \brief
      * \{
      */

    /**
     * \defgroup    RTC_IN_PAD_Select RTC IN PAD Select
     * \{
     * \ingroup     RTC_Exported_Constants
     */
    typedef enum
{
    PAD_RTC_IN_DISABLE,
    PAD_32KXI_RTC_IN,
    PAD_P2_4_RTC_IN,
    RTC_IN_SEL_DEFAULT = PAD_RTC_IN_DISABLE,
} RTCInSel_TypeDef;

#define RTC_ALL_IN_SEL         (PAD_RTC_IN_DISABLE | PAD_32KXI_RTC_IN | \
                                PAD_P2_4_RTC_IN | RTC_IN_SEL_DEFAULT)

/** End of RTC_IN_PAD_Select
  * \}
  */

/** End of RTC_Exported_Constants
  * \}
  */

/** End of RTC
  * \}
  */


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_RTC_DEF_H */
