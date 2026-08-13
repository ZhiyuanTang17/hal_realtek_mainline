/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef REALTEK_BEE_CRYPTO_PSA_TYPES_H_
#define REALTEK_BEE_CRYPTO_PSA_TYPES_H_

#include <psa/crypto_driver_common.h>
#include <stddef.h>
#include <stdint.h>

#if defined(BEE_CRYPTO_RTL87X2G)
#include <crypto_engine_nsc.h>
#elif defined(BEE_CRYPTO_RTL8752H)
#include <rtl876x_hw_sha256.h>
#else
#error "Unsupported Realtek Bee SoC"
#endif

typedef struct {
  HW_SHA256_CTX context;
  psa_algorithm_t algorithm;
} bee_psa_hash_operation_t;

typedef struct {
  uint8_t key[32];
  uint8_t iv[16];
  uint8_t buffer[16];
  uint8_t stream[16];
  size_t key_length;
  size_t buffer_length;
  size_t stream_used;
  psa_algorithm_t algorithm;
  uint8_t decrypt;
  uint8_t iv_set;
} bee_psa_cipher_operation_t;

typedef struct {
  uint8_t key[32];
  uint8_t nonce[13];
  uint8_t mac[16];
  uint8_t b0[16];
  uint8_t aad_block[16];
  uint8_t payload_block[16];
  uint8_t counter[16];
  uint8_t stream[16];
  uint8_t tag[16];
  size_t key_length;
  size_t nonce_length;
  size_t tag_length;
  size_t aad_length;
  size_t aad_processed;
  size_t payload_length;
  size_t payload_processed;
  size_t aad_block_used;
  size_t payload_block_used;
  size_t stream_used;
  uint8_t length_size;
  uint8_t decrypt;
  uint8_t nonce_set;
  uint8_t lengths_set;
  uint8_t b0_processed;
  uint8_t aad_finished;
  uint8_t tag_ready;
} bee_psa_aead_operation_t;

#endif /* REALTEK_BEE_CRYPTO_PSA_TYPES_H_ */
