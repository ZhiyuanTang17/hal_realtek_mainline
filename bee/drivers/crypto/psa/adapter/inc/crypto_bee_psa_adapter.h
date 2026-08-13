/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef REALTEK_BEE_PSA_ADAPTER_H_
#define REALTEK_BEE_PSA_ADAPTER_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(BEE_CRYPTO_RTL87X2G)
#include <crypto_engine_nsc.h>
#elif defined(BEE_CRYPTO_RTL8752H)
#include <hw_aes.h>
#include <rtl876x_hw_sha256.h>
#else
#error "Unsupported Realtek Bee SoC"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BEE_AES_BLOCK_SIZE 16U
#define BEE_ECC_P256_WORDS 8U

struct bee_ecc_point {
  uint32_t x[BEE_ECC_P256_WORDS];
  uint32_t y[BEE_ECC_P256_WORDS];
  uint32_t z[BEE_ECC_P256_WORDS];
};

enum bee_crypto_status {
  BEE_CRYPTO_SUCCESS = 0,
  BEE_CRYPTO_ERROR_INVALID_ARGUMENT = -1,
  BEE_CRYPTO_ERROR_HARDWARE = -2,
  BEE_CRYPTO_ERROR_SYNC = -3,
  BEE_CRYPTO_ERROR_NOT_SUPPORTED = -4,
};

int bee_crypto_init(void);
int bee_crypto_lock(void);
void bee_crypto_unlock(void);

int bee_aes_hw_crypt_block(const uint8_t *key, size_t key_len,
                           T_HW_AES_MODE mode, const uint8_t *in, uint8_t *out,
                           const uint8_t *iv, bool decrypt);

int bee_sha256_hw_compute(const uint8_t *input, size_t input_length,
                          uint8_t *hash);
int bee_sha256_hw_start(HW_SHA256_CTX *ctx);
int bee_sha256_hw_update(HW_SHA256_CTX *ctx, const uint8_t *input,
                         size_t input_length);
int bee_sha256_hw_finish(HW_SHA256_CTX *ctx, uint8_t *hash);

int bee_ecc_p256_enable(void);
void bee_ecc_p256_disable(void);
int bee_ecc_p256_mod_prepare(const uint32_t modulus[BEE_ECC_P256_WORDS]);
int bee_ecc_p256_mod_reduce(uint32_t value[BEE_ECC_P256_WORDS]);
int bee_ecc_p256_mod_mul(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]);
int bee_ecc_p256_mod_add(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]);
int bee_ecc_p256_mod_inv(const uint32_t value[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]);
int bee_ecc_p256_mul(const uint32_t scalar[BEE_ECC_P256_WORDS],
                     const struct bee_ecc_point *point,
                     struct bee_ecc_point *result);
int bee_ecc_p256_validate_public(const struct bee_ecc_point *point);
int bee_ecc_p256_add(const struct bee_ecc_point *left,
                     const struct bee_ecc_point *right,
                     struct bee_ecc_point *result);

#ifdef __cplusplus
}
#endif

#endif /* REALTEK_BEE_PSA_ADAPTER_H_ */
