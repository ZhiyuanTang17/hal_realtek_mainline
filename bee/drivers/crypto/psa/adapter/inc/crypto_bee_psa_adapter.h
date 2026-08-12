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
#else
#error "Unsupported Realtek Bee SoC"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BEE_AES_BLOCK_SIZE 16U

enum bee_crypto_status {
  BEE_CRYPTO_SUCCESS = 0,
  BEE_CRYPTO_ERROR_INVALID_ARGUMENT = -1,
  BEE_CRYPTO_ERROR_HARDWARE = -2,
  BEE_CRYPTO_ERROR_SYNC = -3,
};

int bee_crypto_init(void);
int bee_crypto_lock(void);
void bee_crypto_unlock(void);

int bee_aes_hw_crypt_block(const uint8_t *key, size_t key_len,
                           T_HW_AES_MODE mode, const uint8_t *in, uint8_t *out,
                           const uint8_t *iv, bool decrypt);

#ifdef __cplusplus
}
#endif

#endif /* REALTEK_BEE_PSA_ADAPTER_H_ */
