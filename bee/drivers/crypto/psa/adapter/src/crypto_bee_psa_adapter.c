/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "crypto_bee_psa_adapter.h"
#include <os_sync.h>
#include <string.h>

#define BEE_CRYPTO_WAIT_FOREVER UINT32_MAX

static void *bee_crypto_mutex;

int bee_crypto_init(void) {
  if (bee_crypto_mutex != NULL) {
    return BEE_CRYPTO_SUCCESS;
  }

  return os_mutex_create(&bee_crypto_mutex) ? BEE_CRYPTO_SUCCESS
                                            : BEE_CRYPTO_ERROR_SYNC;
}

int bee_crypto_lock(void) {
  if (bee_crypto_mutex == NULL && bee_crypto_init() != BEE_CRYPTO_SUCCESS) {
    return BEE_CRYPTO_ERROR_SYNC;
  }

  return os_mutex_take(bee_crypto_mutex, BEE_CRYPTO_WAIT_FOREVER)
             ? BEE_CRYPTO_SUCCESS
             : BEE_CRYPTO_ERROR_SYNC;
}

void bee_crypto_unlock(void) {
  if (bee_crypto_mutex != NULL) {
    (void)os_mutex_give(bee_crypto_mutex);
  }
}

static void bee_aes_copy_to_hw(const uint8_t *src, uint32_t *dst, size_t len) {
#if defined(BEE_CRYPTO_SWAP_BUFFER)
  swap_buf(src, (uint8_t *)dst, (uint16_t)len);
#else
  memcpy(dst, src, len);
#endif
}

static void bee_aes_copy_from_hw(const uint32_t *src, uint8_t *dst,
                                 size_t len) {
#if defined(BEE_CRYPTO_SWAP_BUFFER)
  swap_buf((const uint8_t *)src, dst, (uint16_t)len);
#else
  memcpy(dst, src, len);
#endif
}

int bee_aes_hw_crypt_block(const uint8_t *key, size_t key_len,
                           T_HW_AES_MODE mode, const uint8_t *in, uint8_t *out,
                           const uint8_t *iv, bool decrypt) {
  uint32_t in_hw[BEE_AES_BLOCK_SIZE / sizeof(uint32_t)];
  uint32_t out_hw[BEE_AES_BLOCK_SIZE / sizeof(uint32_t)];
  uint32_t key_hw[32U / sizeof(uint32_t)];
  uint32_t iv_hw[BEE_AES_BLOCK_SIZE / sizeof(uint32_t)];
  uint32_t *iv_arg = NULL;
  bool ret;

  if (key == NULL || in == NULL || out == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  bee_aes_copy_to_hw(in, in_hw, BEE_AES_BLOCK_SIZE);
  bee_aes_copy_to_hw(key, key_hw, key_len);

  if (iv != NULL) {
    bee_aes_copy_to_hw(iv, iv_hw, BEE_AES_BLOCK_SIZE);
    iv_arg = iv_hw;
  }

  if (key_len == 16U) {
    if (decrypt) {
      ret = hw_aes_decrypt128(in_hw, out_hw, 4, key_hw, iv_arg, mode);
    } else {
      ret = hw_aes_encrypt128(in_hw, out_hw, 4, key_hw, iv_arg, mode);
    }
  } else if (key_len == 32U) {
    if (decrypt) {
      ret = hw_aes_decrypt256(in_hw, out_hw, 4, key_hw, iv_arg, mode);
    } else {
      ret = hw_aes_encrypt256(in_hw, out_hw, 4, key_hw, iv_arg, mode);
    }
  } else {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  if (!ret) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }

  bee_aes_copy_from_hw(out_hw, out, BEE_AES_BLOCK_SIZE);
  return BEE_CRYPTO_SUCCESS;
}
