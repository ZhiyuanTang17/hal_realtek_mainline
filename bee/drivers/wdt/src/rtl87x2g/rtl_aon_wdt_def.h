/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_aon_wdt_def.h
* \brief    AON WDT related definitions for RTL87x2G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_AON_WDT_DEF_H
#define RTL_AON_WDT_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          AON WDT Defines
 *============================================================================*/


/*============================================================================*
 *                         AON WDT Registers Memory Map
 *============================================================================*/
typedef struct
{
    /*!< 0x00 0xA5A5: disable AON_WDT_CONFIG write protect; other: enable AON_WDT_CONFIG write protect */
    __IO uint32_t aon_wdt_wp : 16;
    __IO uint32_t aon_wdt_rscd0 : 16;
    /*!< Dividing factor. Watch dog timer is count with /(divfactor+1). Minimum dividing factor is 1. */
    __IO uint32_t aon_wdt_clk_div_factor : 16; /*!< 0x04 */
    /*!< when AON_WDT_CNT>=AON_WDT_CNT_LIMIT then WDT timeout  */
    __IO uint32_t aon_wdt_cnt_limit : 12;
    /*!< "01:Level 1:whole reset chip except xxx; 00:Level 0:whole chip reset(include LV1)" */
    __IO uint32_t aon_wdt_mode : 1;
    /*!< "1:WDT countine count in DLPS 0:WDT stop count in DLPS" */
    __IO uint32_t aon_wdt_cnt_ctl : 1;
    /*!< "when  reg_aon_wdt_cnt_ctl ==0 1:reload counter when exit DLPS 0:not reload counter when exit DLPS" */
    __IO uint32_t aon_wdt_cnt_reload : 1;
    /*!< "0:stop & reset AON_WDT_CNT; 1:enable AON_WDT_CNT run" */
    __IO uint32_t aon_wdt_en : 1;
    /*!< 0x08 0x5A5A: reset watch dog counter(not stop counter) other: no effect */
    __IO uint32_t aon_wdt_cnt_reset : 16;
    __IO uint32_t aon_wdt_rscd1 : 16;
    /*!< 0x0c "0: AON_WDT_WP register can be accessed by Secure accesses
               1: AON_WDT_WP register can be accessed by Non-secure accesses" */
    __IO uint32_t aon_wdt_wp_sec : 1;
    /*!< "0: AON_WDT_CONFIG register can be accessed by Secure accesses
          1: AON_WDT_CONFIG register can be accessed by Non-secure accesses" */
    __IO uint32_t aon_wdt_config_sec : 1;
    /*!< "0: AON_WDT_RESET_SEC register can be accessed by Secure accesses
          1: AON_WDT_RESET_SEC register can be accessed by Non-secure accesses" */
    __IO uint32_t aon_wdt_reset_sec : 1;
    __IO uint32_t aon_wdt_rscd2 : 29;
} AON_WDT_TypeDef;

/*============================================================================*
 *                         AON WDT Declaration
 *============================================================================*/
/** \defgroup AON_WDT         AON_WDT
  * \brief
  * \{
  */

/** \defgroup AON_WDT_Exported_Constants AON_WDT Exported Constants
  * \brief
  * \{
  */

/** \defgroup AON_WDT_Declaration AON_WDT Declaration
  * \brief
  * \{
  */

#define AON_WDT            ((AON_WDT_TypeDef *) AON_WDT_REG_BASE)

/** End of AON_WDT_Declaration
  * \}
  */

/** End of AON_WDT_Exported_Constants
  * \}
  */

/** End of AON_WDT
  * \}
  */

/*============================================================================*
 *                         AON WDT Private Types
 *============================================================================*/


/*============================================================================*
 *                         AON WDT Registers and Field Descriptions
 *============================================================================*/


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_AON_WDT_DEF_H */
