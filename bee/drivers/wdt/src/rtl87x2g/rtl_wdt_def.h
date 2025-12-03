/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_wdt_def.h
* \brief    WDT related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_WDT_DEF_H
#define RTL_WDT_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          WDT Defines
 *============================================================================*/

/*============================================================================*
 *                         WDT Registers Memory Map
 *============================================================================*/
typedef struct                              /*!< WDT Structure */
{
    __IO uint32_t WDT_WP : 16;                  /*!< 0x00 */
    __IO uint32_t RSVD0 : 16;
    __IO uint32_t WDT_CLK_DIV_FACTOR : 16;      /*!< 0x04 */
    __IO uint32_t WDT_CNT_LIMIT : 12;
    __IO uint32_t WDT_MODE : 2;
    __IO uint32_t WDT_TIMEOUT_FLG : 1;
    __IO uint32_t WDT_ENABLE : 1;
    __IO uint32_t WDT_CNT_RESET : 16;           /*!< 0x08 */
    __IO uint32_t RSVD1 : 16;
    __IO uint32_t WDT_WP_SEC : 1;               /*!< 0x0C */
    __IO uint32_t WDT_CONFIG_SEC : 1;
    __IO uint32_t WDT_RESET_SEC : 1;
    __IO uint32_t RSVD2 : 29;
} WDT_TypeDef;

/*============================================================================*
 *                         WDT Declaration
 *============================================================================*/
/** \defgroup WDT         WDT
  * \brief
  * \{
  */

/** \defgroup WDT_Exported_Constants WDT Exported Constants
  * \brief
  * \{
  */

/** \defgroup WDT_Declaration WDT Declaration
  * \brief
  * \{
  */

#define WDT_REG_BASE                       (SOC_VENDOR_REG_BASE + 0x100)
#define WDT                ((WDT_TypeDef *) WDT_REG_BASE)


/** End of WDT_Declaration
  * \}
  */

/** End of WDT_Exported_Constants
  * \}
  */

/** End of WDT
  * \}
  */

/*============================================================================*
 *                         WDT Private Types
 *============================================================================*/


/*============================================================================*
 *                         WDT Registers and Field Descriptions
 *============================================================================*/


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_WDT_DEF_H */
