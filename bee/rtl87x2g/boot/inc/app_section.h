/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    app_section.h
  * @brief
  * @author
  * @date    2017.6.7
  * @version v1.0
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef APP_SECTION_H
#define APP_SECTION_H


/** @defgroup APP_SECTION APP Section
  * @brief memory section definition for user application.
  * @{
  */

/*============================================================================*
 *                              Macro
*============================================================================*/
/** @defgroup APP_SECTION_Exported_Macros APP Section Sets Exported Macros
  * @{
  */
/** @defgroup APP_FLASH_SECTION APP Flash Section
  *@brief  const data or flash function
  * @{
  */
#define APP_FLASH_HEADER           __attribute__((section(".app.flash.header")))     __attribute__((used))
#define APP_FLASH_HEADER_EXT       __attribute__((section(".app.flash.header_ext"))) __attribute__((used))
#define APP_FLASH_START_SECTION    __attribute__((section(".app.flash.start")))      __attribute__((used))
#define APP_FLASH_TEXT_SECTION     __attribute__((section(".app.flash.text")))
#define APP_FLASH_RODATA_SECTION   __attribute__((section(".app.flash.rodata")))
#define APP_FLASH_GAP_TEXT_SECTION __attribute__((section(".app.flash.gap.text")))

#define ISR_TEXT_SECTION           __attribute__((section(".isr.text"))) /*not very urgent isr*/

/** End of APP_FLASH_SECTION
  * @}
  */

/** @defgroup APP_RAM_SECTION RAM Data Section
    *@brief  global variable or ram function,  data on (default)
    * @{
    */
#define APP_RAM_DATA_SECTION       __attribute__((section(".app.ram.data")))
#define EXT_DATA_SRAM_SECTION      __attribute__((section(".app.ext.datasram.data")))

#define RAM_DATA                   APP_RAM_DATA_SECTION
#define EXT_RAM_DATA               EXT_DATA_SRAM_SECTION

/** End of APP_RAM_SECTION
  * @}
  */


/** @defgroup APP_FUNCTION_SECTION RAM Function Section Sets
  *@brief  ram code
  * @{
  */
#define APP_RAM_START_SECTION      __attribute__((section(".app.ram.start")))
#define APP_RAM_TEXT_SECTION       __attribute__((section(".app.ram.text")))
#define APP_PSRAM_SECTION         __attribute__((section(".app.psram.data")))

#define RAM_FUNCTION               APP_RAM_TEXT_SECTION
#define DATA_RAM_FUNCTION          RAM_FUNCTION


/* app encryption */
#define APP_ENCRYPTION_SIGNATURE   __attribute__((section(".encryption.signature")))
#define APP_ENCRYPION_DUMMY_ALIGN  __attribute__((section(".encryption.dummy.align"))) __attribute__((aligned(16)))
/* app encryption code*/
#define APP_ENCRYPTION_TEXT_SECTION __attribute__((section(".app.encryption.text")))

/** End of APP_FUNCTION_SECTION
  * @}
  */

/** End of APP_SECTION_Exported_Macros
  * @}
  */

/** End of APP_SECTION
  * @}
  */



#endif // APP_SECTION_H
