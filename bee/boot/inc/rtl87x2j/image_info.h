/*
  ******************************************************************************
  * @file    image_info.h
  * @author  Grace
  * @version V0.0.1
  * @date    2025-07-29
  * @brief   This file contains all the functions regarding patch header check.
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2025, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _IMAGE_INFO_H_
#define _IMAGE_INFO_H_
#include <stdbool.h>
#include <stdint.h>

/** @addtogroup  FLASH_DEVICE    Flash Device
    * @{
    */
/*============================================================================*
  *                                   Constants
  *============================================================================*/
// *INDENT-ON*
#define DEFAULT_HEADER_SIZE                 (0x400)
#define CMAC_BYTE_SIZE                      (16)
#define RSA_PUBLIC_KEY_BYTE_SIZE            (384)
#define ECDSA_PUBLIC_KEY_BYTE_SIZE          (32)
// ecdsa uncompressed key len = (public key byte len * 2) + 1
#define ECDSA_UNCOMPRESSED_PUBLIC_KEY_LEN   (65)
#define ED25519_PUBLIC_KEY_BYTE_SIZE        (32)
#define SHA256_BYTE_SIZE                    (32)

#define RSA_SIGNATURE_BYTE_SIZE             (RSA_PUBLIC_KEY_BYTE_SIZE)
#define ECDSA_SIGNATURE_BYTE_SIZE           (ECDSA_PUBLIC_KEY_BYTE_SIZE * 2)
#define ED25519_SIGNATURE_BYTE_SIZE         (ED25519_PUBLIC_KEY_BYTE_SIZE * 2)

/*
        - mac range         = signature + hash + header content + payload
        - signature range   = hash + header content + payload
        - hash range        = header content + payload
*/
#define OUT_OF_CMAC_RANGE           (offsetof(T_IMG_HEADER_FORMAT, auth) + offsetof(T_AUTH_HEADER_FORMAT, image_signature))
#define OUT_OF_SIGN_RANGE           (offsetof(T_IMG_HEADER_FORMAT, auth) + offsetof(T_AUTH_HEADER_FORMAT, image_hash))
#define OUT_OF_HASH_RANGE           (offsetof(T_IMG_HEADER_FORMAT, auth) + offsetof(T_AUTH_HEADER_FORMAT, PubKey))

#define MAC_RANGE(header)           (((T_IMG_HEADER_FORMAT *)(header))->ctrl_header.payload_len + image_header_size_get() - OUT_OF_CMAC_RANGE)

#define SIGNATURE_RANGE(header)     (((T_IMG_HEADER_FORMAT *)(header))->ctrl_header.payload_len + image_header_size_get() - OUT_OF_SIGN_RANGE)

#define HASH_RANGE(header)          (((T_IMG_HEADER_FORMAT *)(header))->ctrl_header.payload_len + image_header_size_get() - OUT_OF_HASH_RANGE)


/*IC Type refer to WIKI: https://wiki.realtek.com/display/Bee1/BT+SOC+IC+Type*/
#define IMG_IC_TYPE                  18

#define UUID_SIZE                    16

#define DFU_HEADER_SIZE              16 //sizeof(T_IMG_CTRL_HEADER_FORMAT)

#define IMG_HEADER_SIZE              1024
#define OTA_HEADER_SIZE              0x400

#define IMG_DFU_FIRST                (IMG_MCUPATCH)
#define IMG_DFU_MAX                  (IMG_MAX)

#define UP_ALIGN(size, align)        (((size) + (align) - 1) & ~(align - 1))

#define SYS_CFG_SIGNATURE            0x12345bb3
#define FLASH_TABLE_MAGIC_PATTERN    (0x5A5A12A5)

#define GOLDEN_PATTERN_WORD_LEN  (20)
#define GOLDEN_PATTERN_SIZE      (sizeof(uint32_t) * GOLDEN_PATTERN_WORD_LEN)

#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#define CONFIG_IMG_BT_CONTROLLER_BOOT
#define CONFIG_IMG_BT_HOST_BOOT

#define PRE_IMG_PARTITION_FIRST   (IMG_PARTITION_BT_CONTROLLER)
#endif

/*============================================================================*
  *                                   Types
  *============================================================================*/
/** @defgroup FLASH_DEVICE_Exported_Types Flash Device Exported Types
  * @brief
  * @{
  */
typedef enum
{
    IMAGE_FIRST       = 0x278D,
    IMG_SCCD          = 0x278D,
    IMG_OCCD          = 0x278E,
    IMG_BOOTPATCH     = 0x278F,
    IMG_OTA           = 0x2790, /**< OTA header */
    IMG_RSVD          = 0x2791,
    IMG_BANK_FIRST    = IMG_RSVD,
    IMG_MCUPATCH      = 0x2792,
    IMG_MCUAPP        = 0x2793,
    IMG_MCUAPPDATA1   = 0x2794,
    IMG_MCUAPPDATA2   = 0x2795,
    IMG_MCUAPPDATA3   = 0x2796,
    IMG_MCUAPPDATA4   = 0x2797,
    IMG_MCUAPPDATA5   = 0x2798,
    IMG_MCUCFGDATA    = 0x2799,
    IMG_BT_HOST_PATCH       = 0x279a,
    IMG_BT_CONTROLLER_PATCH = 0x279b,
    IMG_MAX,

    PRE_IMAGE_FIRST       = 0x27a2,
    PRE_IMG_BT_CONTROLLER = PRE_IMAGE_FIRST,
    PRE_IMG_BT_HOST       = 0x27a3,
    PRE_IMG_MAX,

    IMG_USER_DATA8       = 0xFFF7,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA_FIRST  = IMG_USER_DATA8,
    IMG_USER_DATA7       = 0xFFF8,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA6       = 0xFFF9,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA5       = 0xFFFA,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA4       = 0xFFFB,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA3       = 0xFFFC,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA2       = 0xFFFD,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA1       = 0xFFFE,    /*!< the image data only support unsafe single bank ota */
    IMG_USER_DATA_MAX    = 0xFFFF,    /*!< the image data only support unsafe single bank ota */
} IMG_ID;

typedef enum
{
    IMG_PARTITION_OCCD,
    IMG_PARTITION_BOOT_PATCH,
#ifdef CONFIG_IMG_PLATFORM_BOOT
    IMG_PARTITION_PLATFORM,
#endif
#ifdef CONFIG_IMG_BT_CONTROLLER_BOOT
    IMG_PARTITION_BT_CONTROLLER,
#endif
#ifdef CONFIG_IMG_BT_HOST_BOOT
    IMG_PARTITION_BT_HOST,
#endif
    IMG_PARTITION_OTA_BANK_0,
    IMG_PARTITION_OTA_BANK_1,
    IMG_PARTITION_BKP_DATA1,
    IMG_PARTITION_BKP_DATA2,
    IMG_PARTITION_OTA_TMP,
    IMG_PARTITION_FTL,
    IMG_PARTITION_TOTAL,
} T_IMG_PARTITION_NAME;

typedef enum _ENC_KEY_SELECT
{
    ENC_KEY_SCEK = 0,
    ENC_KEY_SCEK_WITH_RTKCONST,
    ENC_KEY_OCEK,
    ENC_KEY_OCEK_WITH_OEMCONST,
    ENC_KEY_ON_FLASH,
    ENC_KEY_MAX,
} ENC_KEY_SELECT;

typedef enum _IMG_ENC_TYPE
{
    IMG_ENC_TYPE_NORMAL_AES       = 1,
    IMG_ENC_TYPE_ON_THE_FLY       = 2,
    IMG_ENC_TYPE_MAX
} IMG_ENC_TYPE;

typedef union
{
    uint8_t d8[ECDSA_UNCOMPRESSED_PUBLIC_KEY_LEN];
    struct
    {
        uint8_t flag; /*04 for uncompressed public key*/
        uint8_t x[ECDSA_PUBLIC_KEY_BYTE_SIZE];
        uint8_t y[ECDSA_PUBLIC_KEY_BYTE_SIZE];
    } ecdsa_pb_key;
} PUBLIC_KEY;

typedef enum _APP_IMAGE_TYPE
{
    IMAGE_NORMAL              = 0,
    IMAGE_COMPRESSED          = 1,
    //2-7 are reserved
} T_IMAGE_TYPE;

typedef struct _IMG_CTRL_HEADER_FORMAT
{
    union
    {
        uint32_t value;
        struct
        {
            uint32_t header_version: 8;
            uint32_t device_type: 4; /* eflash: 4; nor: 3; nand: 2; sd: 1; emmc: 0;
                                      * nand\sd\emmc: 14, whatever: 15 */
            uint32_t integrity_check_en_in_boot: 1; // enable image integrity check in boot flow
            uint32_t load_when_boot: 1; // load image when boot
            uint32_t not_ready: 1; //for copy image in ota
            uint32_t not_obsolete: 1; //for copy image in ota
            uint32_t compressed_not_ready: 1;
            uint32_t compressed_not_obsolete: 1;
            uint32_t compressed_image_type: 3;
            uint32_t ctrl_flag_reserved: 11;
        };
    } ctrl_flag;
    uint8_t ic_type;
    uint8_t secure_version;
    uint16_t image_id;
    uint32_t header_len;
    uint32_t payload_len;
} T_IMG_CTRL_HEADER_FORMAT;

typedef struct
{
    union
    {
        uint64_t version;
        struct
        {
            uint64_t _version_reserve: 32;   //!< reserved
            uint64_t _version_revision: 16; //!< revision version
            uint64_t _version_minor: 8;     //!< minor version
            uint64_t _version_major: 8;     //!< major version
        } img_sub_version;
    } ver_info;
} __attribute__((packed)) T_IMAGE_VERSION;

typedef struct
{
    union
    {
        uint64_t version;
        struct
        {
            uint64_t _version_reserve: 32;   //!< reserved
            uint64_t _version_revision: 16; //!< revision version
            uint64_t _version_minor: 8;     //!< minor version
            uint64_t _version_major: 8;     //!< major version
        } sub_version;
    };
    uint32_t _version_commitid;     //!< git commit id
    uint8_t _customer_name[8];      //!< branch name for customer patch
    uint8_t version_reserved[4];
} __attribute__((packed)) T_VERSION_FORMAT;

typedef struct _AUTH_HEADER_FORMAT
{
    uint8_t img_string[6];// "IMGHDR"
    uint16_t auth_length;
    uint8_t auth_type;
    uint8_t auth_reserved[7]; //for cmac 16bytes align
    uint8_t cmac[CMAC_BYTE_SIZE];
    uint8_t image_signature[ECDSA_SIGNATURE_BYTE_SIZE];
    uint8_t image_hash[SHA256_BYTE_SIZE];
    PUBLIC_KEY PubKey;
    uint8_t auth_reserved1[3];
} T_AUTH_HEADER_FORMAT; // 196 bytes

typedef union
{
    uint8_t bytes[12];
    struct
    {
        uint32_t app_ram_data_addr;
        uint32_t app_ram_data_size;
        uint32_t app_heap_data_on_size;
    } app_ram_info;
} T_EXTRA_INFO_FORMAT;

typedef struct
{
    union
    {
        uint32_t value;
        struct
        {
            uint32_t enc: 1;
            uint32_t enc_type: 3; // 1: normal AES 2: on the fly
            uint32_t mode: 4; // gcm mode:0b00, ctr mode:0b01, mix mode:0b10
            uint32_t key_select: 4;
            uint32_t is_encrypted: 1;
            uint32_t rsvd: 19;
        };
    } ctrl_flag;
    uint32_t encryption_load_addr; // load base  nor: flash address nand/sd/emmc: psram
    uint32_t encryption_size;  // load size
    uint32_t encryption_exe_addr;  // exe base  nor: ram address nand/sd/emmc: psram
    uint8_t dec_key[16];
    union
    {
        uint8_t iv[16];
        struct
        {
            uint8_t  iv_high[4];
            uint8_t  iv_low[4];
            uint8_t  iv_reserved[8];
        };
    };

} T_ENCRYPT_FORMAT; //48bytes

typedef struct
{
    uint32_t  image_load_base;
    uint32_t  image_load_size;
    uint32_t  image_exe_base;
    uint32_t  image_exe_size;
} T_IMAGE_INFO;

typedef union
{
    uint8_t  common_reserved[64];
    struct
    {
        uint8_t  common_reserved1[5];
        uint8_t  dev_id_valid;
        uint16_t dev_id;
        uint8_t  image_feature[16];         // used for image feature string
        uint64_t image_release_version;     //used for image release version
    };
} T_COMMON_EXTRA_INFO_FORMAT;

typedef union _IMG_HEADER_FORMAT
{
    uint8_t bytes[DEFAULT_HEADER_SIZE];
    struct
    {
        T_AUTH_HEADER_FORMAT auth;   //196 bytes
        T_IMG_CTRL_HEADER_FORMAT ctrl_header; //16 bytes
        T_ENCRYPT_FORMAT encrypt_header; //48bytes
        uint8_t uuid[16]; //16bytes
        uint32_t magic_pattern; //4 bytes
        T_VERSION_FORMAT git_ver;  //24bytes
        T_COMMON_EXTRA_INFO_FORMAT extra_info; //64 bytes
        union //656bytes
        {
            struct  // data 8bytes
            {
                uint16_t reserved[1];
                uint16_t tool_version;
                uint32_t timestamp;
                uint8_t  data_reserved[648];
            };

            struct // image_header
            {
                uint32_t exe_entry;
                uint32_t image_base; //image begin: nor:flash address   nand/sd/emmc: psram address
                uint32_t ram_load_src; // ram code load base
                uint32_t ram_load_len; // ram code load size
                uint32_t ram_load_dst; // ram code exe base
                union
                {
                    uint8_t  exe_image_reserved[636]; //T_EXTRA_INFO_FORMAT ex_info; //uint8_t comiple_stamp[16];
                    struct // boot patch image_header 148
                    {
                        uint32_t resv_golden_pattern[GOLDEN_PATTERN_WORD_LEN];
                        uint32_t pre_image_num;
                        T_IMAGE_INFO ext_image_excute_info[(PRE_IMG_MAX - PRE_IMAGE_FIRST)]; //3x4
                        uint8_t boot_patch_header_reserved[504];
                    };
                    struct
                    {
                        T_EXTRA_INFO_FORMAT ex_info;
                        uint8_t app_header_reserved[624];
                    };
                };
            };
            struct   // ota header 264
            {
                uint32_t layout_size; // K
                uint32_t ota_image_num;
                T_IMAGE_INFO image_excute_info[(IMG_MAX - IMG_BANK_FIRST)];  //11x4
                uint8_t  ota_header_reserved[452];
            };
        };
    };
}  __attribute__((packed)) T_IMG_HEADER_FORMAT;

typedef struct _COMP_IMG_CTRL_HEADER_FORMAT
{
    uint8_t img_string[3]; //"COM"
    union
    {
        uint16_t value;
        struct
        {
            uint16_t not_ready: 1;
            uint16_t not_obsolete: 1;
            uint16_t integrity_check_en_in_boot: 1; // enable image integrity check in boot flow
            uint16_t rsvd: 13;
        };
    } ctrl_flag;
    uint8_t ic_type;
    uint16_t image_id;
    uint32_t payload_len;
} __attribute__((packed)) T_COMP_IMG_CTRL_HEADER_FORMAT;


typedef struct _COMP_IMG_HEADER_FORMAT //128 bytes
{
    T_COMP_IMG_CTRL_HEADER_FORMAT ctrl_header; //12bytes
    uint8_t uuid[16];
    uint64_t version;
    uint8_t uncompressed_image_hash[32];
    uint8_t compressed_image_hash[32];
    uint32_t compress_algo;
    uint8_t reverved[24];
} __attribute__((packed)) T_COMP_IMG_HEADER_FORMAT;


/*************************************************************************************************
*                          Image info functions
*************************************************************************************************/
#define get_active_bank_image_addr_by_img_id image_addr_get //todo: remove after btc port

/**
 * @brief  Get the image header size
 * @return uint32_t - Size of the image header in bytes
 */
uint32_t image_header_size_get(void);

/**
 * @brief  Get pointer to the extra image information
 * @return T_EXTRA_INFO_FORMAT* - Pointer to the extra info structure
 */
T_EXTRA_INFO_FORMAT *image_extra_info_get(void);

/**
 * @brief  Get the version information for a specific image
 * @param  image_id - ID of the image to query
 * @return T_IMAGE_VERSION* - Pointer to the version structure
 */
T_IMAGE_VERSION *image_version_get(IMG_ID image_id);

/**
 * @brief  Get the base address of a specific image
 * @param  image_id - ID of the image to query
 * @return uint32_t - Base address of the image
 */
uint32_t image_addr_get(IMG_ID image_id);

/**
 * @brief  Get the size of a specific image
 * @param  image_id - ID of the image to query
 * @return uint32_t - Size of the image in bytes
 */
uint32_t image_size_get(IMG_ID image_id);

/**
 * @brief  Get the image payload addr
 * @param  image_id - ID of the image to query
 * @return uint32_t - Base address of the image payload
 */
uint32_t image_payload_addr_get(IMG_ID image_id);

/**
 * @brief  Get the image payload size
 * @param  image_id - ID of the image to query
 * @return uint32_t - Size of the image payload
 */
uint32_t image_payload_size_get(IMG_ID image_id);

/**
 * @brief  Get the load address of a specific image
 * @param  image_id - ID of the image to query
 * @return uint32_t - Load address of the image
 */
uint32_t image_load_addr_get(IMG_ID image_id);

/**
 * @brief  Get the load size of a specific image
 * @param  image_id - ID of the image to query
 * @return uint32_t - Load size of the image in bytes
 */
uint32_t image_load_size_get(IMG_ID image_id);

/*************************************************************************************************
*                          image info functions for DFU
*************************************************************************************************/
/**
 * @brief  Check if dual bank OTA is enabled
 * @return bool - true if dual bank OTA is enabled, false otherwise
 */
bool ota_dual_bank_enable(void);

/**
 * @brief  Get the base address of OTA bank
 * @return uint32_t - Base address of the OTA bank
 */
uint32_t ota_bank_addr_get(void);

/**
 * @brief  Get the temporary address for image during DFU
 * @param  image_id - ID of the image to query
 * @return uint32_t - Temporary address for the image
 */
uint32_t image_temp_addr_get(IMG_ID image_id);

/**
 * @brief  Get the temporary size for image during DFU
 * @param  image_id - ID of the image to query
 * @return uint32_t - Temporary size for the image in bytes
 */
uint32_t image_temp_size_get(IMG_ID image_id);

/**
 * @brief  Get the base address of a specific image partition
 * @param  name - Name of the partition to query
 * @return uint32_t - Base address of the partition
 */
uint32_t image_partition_addr_get(T_IMG_PARTITION_NAME name);

/**
 * @brief  Get the size of a specific image partition
 * @param  name - Name of the partition to query
 * @return uint32_t - Size of the partition in bytes
 */
uint32_t image_partition_size_get(T_IMG_PARTITION_NAME name);

/**
 * @brief  entry the specific image
 * @param  image_id - Id of the image to entry
 */
void image_entry_validation(IMG_ID image_id);

/**
 * @brief  Get the customer name of a specific image partition
 * @param  image_id - Id of the image to entry
 * @return uint8_t* - Address of image customer name
 */
uint8_t *image_customer_name_get(IMG_ID image_id);

#endif // _IMAGE_INFO_H_
