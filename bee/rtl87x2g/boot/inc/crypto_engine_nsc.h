/**
*****************************************************************************************
*     Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    crypto_engine_nsc.h
  * @brief
  * @author
  * @date    2024.7.17
  * @version v1.0
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2024 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */


/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _CRYPTO_ENGINE_NSC_H_
#define _CRYPTO_ENGINE_NSC_H_

#include <stdint.h>
#include <stdbool.h>

/** @defgroup CRYPTO_ENGINE Crypto Engine
  * @brief
  * @{
  */

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup CRYPTO_ENGINE_Exported_Types Crypto Engine Exported Types
  * @brief
  * @{
  */
/* public key engine */
typedef enum
{
    ERR_NONE            = 0x0,
    ERR_PRIME           = 0x1,
    ERR_R2_MOD_N        = 0x2,
    ERR_ECC_ODD_POINT   = 0x4,
    ERR_ECC_Z           = 0x8,
    ERR_MODULAR_INV     = 0x10,
    ERR_N_ST_INPUT      = 0x20,
    ERR_NO_VALID_EXP    = 0x40,
    ERR_INVALID_INPUT   = 0x80,
} ERR_CODE;

typedef enum
{
    ECC_PRIME_MODE       = 0,   // 3'b000
    ECC_BINARY_MODE      = 1,   // 3'b001
    RSA_MODE             = 2,   // 3'b010
    ECC_EDWARDS_CURVE    = 3,   // 3'b011
    ECC_MONTGOMERY_CURVE = 7,   // 3'b111
} PKE_MODE;

typedef struct
{
    uint32_t x[16];
    uint32_t y[16];
    uint32_t z[16];
} ECC_POINT;

typedef struct
{
    uint32_t *N;    // modular, also called p
    uint32_t *A;    // curve parameter a
    uint32_t *B;    // curve parameter b
    uint32_t *n;    // order of G
    ECC_POINT G;    // base point

    uint32_t key_bits;
    PKE_MODE mode;

} ECC_GROUP;

/* SHA2-256 */

typedef enum
{
    HW_SHA256_CPU_MODE,
    HW_SHA256_DMA_MODE
} HW_SHA256_ACCESS_MODE;

typedef struct
{
    uint32_t total[2];          /*!< The number of Bytes processed.  */
    uint32_t state[8];          /*!< The intermediate digest state.  */
    uint8_t buffer[64];         /*!< The data block being processed. */
    int is224;                  /*!< unused, just align mbedtls structure */
} HW_SHA256_CTX;
/** End of CRYPTO_ENGINE_Exported_Types
  * @}
  */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup CRYPTO_ENGINE_Exported_Functions Crypto Engine Exported Functions
  * @brief
  * @{
  */
/**
    * @brief  hardware sha256 process
    * @param  input input buffer pointer
    * @param  byte_len    size
    * @param  result      output buffer pointer
    * @param  mode        hardware sha256 mode
    * @return hardware sha256 results
    * @retval true      successful
    * @retval false     fail
    */
bool hw_sha256(uint8_t *input, uint32_t byte_len, uint32_t *result, int mode);

/**
    * @brief  hardware sha256 init
    * @param  none
    * @return void
    */
void hw_sha256_init(void);

/**
    * @brief  hardware sha256 start
    * @param  ctx pointer of ctx
    * @param  iv pointer of iv
    * @return void
    */
void hw_sha256_start(HW_SHA256_CTX *ctx, uint32_t *iv);

/**
    * @brief  hardware sha256 cpu update
    * @param  ctx pointer of ctx
    * @param  input input buffer pointer
    * @param  byte_len    size
    * @return hardware sha256 update results
    * @retval true      successful
    * @retval false     fail
    */
bool hw_sha256_cpu_update(HW_SHA256_CTX *ctx, uint8_t *input, uint32_t byte_len);

/**
    * @brief  hardware sha256 finish
    * @param  ctx pointer of ctx
    * @param  result      output buffer pointer
    * @return hardware sha256 finish results
    * @retval true      successful
    * @retval false     fail
    */
bool hw_sha256_finish(HW_SHA256_CTX *ctx, uint32_t *result);

/** End of CRYPTO_ENGINE_Exported_Functions
  * @}
  */

/** End of CRYPTO_ENGINE
  * @}
  */

#endif