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
#if defined(BEE_CRYPTO_RTL8752H)
  swap_buf(src, (uint8_t *)dst, (uint16_t)len);
#else
  memcpy(dst, src, len);
#endif
}

static void bee_aes_copy_from_hw(const uint32_t *src, uint8_t *dst,
                                 size_t len) {
#if defined(BEE_CRYPTO_RTL8752H)
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

int bee_sha256_hw_compute(const uint8_t *input, size_t input_length,
                          uint8_t *hash) {
  uint32_t result[8];
  uint8_t empty = 0U;
  int status;
  bool ret;

  if ((input == NULL && input_length != 0U) || hash == NULL ||
      input_length > UINT32_MAX) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  status = bee_crypto_lock();
  if (status != BEE_CRYPTO_SUCCESS) {
    return status;
  }
  ret = hw_sha256(input_length == 0U ? &empty : (uint8_t *)input,
                  (uint32_t)input_length, result, HW_SHA256_CPU_MODE);
  bee_crypto_unlock();

  if (!ret) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }
  memcpy(hash, result, sizeof(result));
  return BEE_CRYPTO_SUCCESS;
}

int bee_sha256_hw_start(HW_SHA256_CTX *ctx) {
  int status;

  if (ctx == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  status = bee_crypto_lock();
  if (status != BEE_CRYPTO_SUCCESS) {
    return status;
  }
  hw_sha256_start(ctx, NULL);
  bee_crypto_unlock();
  return BEE_CRYPTO_SUCCESS;
}

int bee_sha256_hw_update(HW_SHA256_CTX *ctx, const uint8_t *input,
                         size_t input_length) {
  int status;
  bool ret;

  if (ctx == NULL || (input == NULL && input_length != 0U) ||
      input_length > UINT32_MAX) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }
  if (input_length == 0U) {
    return BEE_CRYPTO_SUCCESS;
  }

  status = bee_crypto_lock();
  if (status != BEE_CRYPTO_SUCCESS) {
    return status;
  }
  ret = hw_sha256_cpu_update(ctx, (uint8_t *)input, (uint32_t)input_length);
  bee_crypto_unlock();

  return ret ? BEE_CRYPTO_SUCCESS : BEE_CRYPTO_ERROR_HARDWARE;
}

int bee_sha256_hw_finish(HW_SHA256_CTX *ctx, uint8_t *hash) {
  uint32_t result[8];
  int status;
  bool ret;

  if (ctx == NULL || hash == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  status = bee_crypto_lock();
  if (status != BEE_CRYPTO_SUCCESS) {
    return status;
  }
  ret = hw_sha256_finish(ctx, result);
  bee_crypto_unlock();

  if (!ret) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }
  memcpy(hash, result, sizeof(result));
  return BEE_CRYPTO_SUCCESS;
}

#if defined(BEE_CRYPTO_RTL87X2G)
#define BEE_PKE_MMEM_ADDR 0x50090000U
#define BEE_ECC_N_ADDR (BEE_PKE_MMEM_ADDR + 0x000U)
#define BEE_ECC_A_ADDR (BEE_PKE_MMEM_ADDR + 0x080U)
#define BEE_ECC_B_ADDR (BEE_PKE_MMEM_ADDR + 0x100U)
#define BEE_ECC_X_ADDR (BEE_PKE_MMEM_ADDR + 0x140U)
#define BEE_ECC_Y_ADDR (BEE_PKE_MMEM_ADDR + 0x180U)
#define BEE_ECC_Z_ADDR (BEE_PKE_MMEM_ADDR + 0x1c0U)
#define BEE_ECC_RX_ADDR (BEE_PKE_MMEM_ADDR + 0x200U)
#define BEE_ECC_RY_ADDR (BEE_PKE_MMEM_ADDR + 0x240U)
#define BEE_ECC_RZ_ADDR (BEE_PKE_MMEM_ADDR + 0x280U)

#define BEE_ECC_MUL_ENTRY 0x1U
#define BEE_MOD_MUL_ENTRY 0x2U
#define BEE_MOD_ADD_ENTRY 0x3U
#define BEE_R_SQUARE_ENTRY 0x5U
#define BEE_N_INVERSE_ENTRY 0x6U
#define BEE_MOD_INVERSE_ENTRY 0x7U
#define BEE_ECC_ADD_ENTRY 0x8U
#define BEE_MOD_REDUCE_ENTRY 0xeU

#define BEE_ECC_GO_TO_END true
#define BEE_ECC_RR_READY true

static const uint32_t bee_p256_prime[BEE_ECC_P256_WORDS] = {
    0xffffffffU, 0xffffffffU, 0xffffffffU, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000001U, 0xffffffffU,
};
static const uint32_t bee_p256_order[BEE_ECC_P256_WORDS] = {
    0xfc632551U, 0xf3b9cac2U, 0xa7179e84U, 0xbce6faadU,
    0xffffffffU, 0xffffffffU, 0x00000000U, 0xffffffffU,
};
static const uint32_t bee_p256_a[BEE_ECC_P256_WORDS] = {
    0xfffffffcU, 0xffffffffU, 0xffffffffU, 0x00000000U,
    0x00000000U, 0x00000000U, 0x00000001U, 0xffffffffU,
};
static const uint32_t bee_p256_b[BEE_ECC_P256_WORDS] = {
    0x27d2604bU, 0x3bce3c3eU, 0xcc53b0f6U, 0x651d06b0U,
    0x769886bcU, 0xb3ebbd55U, 0xaa3a93e7U, 0x5ac635d8U,
};

static int bee_ecc_result(ERR_CODE status) {
  return status == ERR_NONE ? BEE_CRYPTO_SUCCESS : BEE_CRYPTO_ERROR_HARDWARE;
}

int bee_ecc_p256_enable(void) {
  hw_pke_clock(true);
  hw_pke_init(false, false, 0U);
  return BEE_CRYPTO_SUCCESS;
}

void bee_ecc_p256_disable(void) { hw_pke_clock(false); }

int bee_ecc_p256_mod_prepare(const uint32_t modulus[BEE_ECC_P256_WORDS]) {
  uint32_t temporary[16];

  if (modulus == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, !BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_N_ADDR, (uint32_t *)modulus,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  if (hw_ecc_compute(temporary, BEE_ECC_RX_ADDR, BEE_N_INVERSE_ENTRY) !=
      ERR_NONE) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, !BEE_ECC_RR_READY);
  return bee_ecc_result(
      hw_ecc_compute(temporary, BEE_ECC_RX_ADDR, BEE_R_SQUARE_ENTRY));
}

int bee_ecc_p256_mod_reduce(uint32_t value[BEE_ECC_P256_WORDS]) {
  if (value == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, !BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_N_ADDR, (uint32_t *)bee_p256_order,
                         sizeof(bee_p256_order));
  hw_ecc_set_sub_operand(BEE_ECC_RX_ADDR, value,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  return bee_ecc_result(
      hw_ecc_compute(value, BEE_ECC_RX_ADDR, BEE_MOD_REDUCE_ENTRY));
}

int bee_ecc_p256_mod_mul(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  if (left == NULL || right == NULL || result == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_A_ADDR, (uint32_t *)left,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  hw_ecc_set_sub_operand(BEE_ECC_B_ADDR, (uint32_t *)right,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  return bee_ecc_result(
      hw_ecc_compute(result, BEE_ECC_A_ADDR, BEE_MOD_MUL_ENTRY));
}

int bee_ecc_p256_mod_add(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  if (left == NULL || right == NULL || result == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_A_ADDR, (uint32_t *)left,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  hw_ecc_set_sub_operand(BEE_ECC_B_ADDR, (uint32_t *)right,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  return bee_ecc_result(
      hw_ecc_compute(result, BEE_ECC_A_ADDR, BEE_MOD_ADD_ENTRY));
}

int bee_ecc_p256_mod_inv(const uint32_t value[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  if (value == NULL || result == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_B_ADDR, (uint32_t *)value,
                         BEE_ECC_P256_WORDS * sizeof(uint32_t));
  return bee_ecc_result(
      hw_ecc_compute(result, BEE_ECC_B_ADDR, BEE_MOD_INVERSE_ENTRY));
}

static int bee_ecc_p256_compare(const uint32_t left[BEE_ECC_P256_WORDS],
                                const uint32_t right[BEE_ECC_P256_WORDS]) {
  for (size_t i = BEE_ECC_P256_WORDS; i > 0U; i--) {
    if (left[i - 1U] < right[i - 1U]) {
      return -1;
    }
    if (left[i - 1U] > right[i - 1U]) {
      return 1;
    }
  }
  return 0;
}

int bee_ecc_p256_validate_public(const struct bee_ecc_point *point) {
  uint32_t left[BEE_ECC_P256_WORDS];
  uint32_t right[BEE_ECC_P256_WORDS];
  uint32_t temporary[BEE_ECC_P256_WORDS];
  int status;

  if (point == NULL || bee_ecc_p256_compare(point->x, bee_p256_prime) >= 0 ||
      bee_ecc_p256_compare(point->y, bee_p256_prime) >= 0) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  status = bee_ecc_p256_mod_prepare(bee_p256_prime);
  if (status == BEE_CRYPTO_SUCCESS) {
    status = bee_ecc_p256_mod_mul(point->y, point->y, left);
  }
  if (status == BEE_CRYPTO_SUCCESS) {
    status = bee_ecc_p256_mod_mul(point->x, point->x, temporary);
  }
  if (status == BEE_CRYPTO_SUCCESS) {
    status = bee_ecc_p256_mod_add(temporary, bee_p256_a, temporary);
  }
  if (status == BEE_CRYPTO_SUCCESS) {
    status = bee_ecc_p256_mod_mul(temporary, point->x, right);
  }
  if (status == BEE_CRYPTO_SUCCESS) {
    status = bee_ecc_p256_mod_add(right, bee_p256_b, right);
  }
  if (status != BEE_CRYPTO_SUCCESS) {
    return status;
  }
  return memcmp(left, right, sizeof(left)) == 0
             ? BEE_CRYPTO_SUCCESS
             : BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
}

int bee_ecc_p256_mul(const uint32_t scalar[BEE_ECC_P256_WORDS],
                     const struct bee_ecc_point *point,
                     struct bee_ecc_point *result) {
  ECC_GROUP group = {0};
  ECC_POINT base = {0};
  ECC_POINT hardware_result = {0};
  uint32_t a[BEE_ECC_P256_WORDS];
  uint32_t b[BEE_ECC_P256_WORDS];
  uint32_t n[BEE_ECC_P256_WORDS];

  if (scalar == NULL || point == NULL || result == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  memcpy(a, bee_p256_a, sizeof(a));
  memcpy(b, bee_p256_b, sizeof(b));
  memcpy(n, bee_p256_order, sizeof(n));
  memcpy(base.x, point->x, sizeof(point->x));
  memcpy(base.y, point->y, sizeof(point->y));
  memcpy(base.z, point->z, sizeof(point->z));
  group.N = (uint32_t *)bee_p256_prime;
  group.A = a;
  group.B = b;
  group.n = n;
  group.G = base;
  group.key_bits = 256U;
  group.mode = ECC_PRIME_MODE;

  hw_ecc_init(256U, ECC_PRIME_MODE, !BEE_ECC_GO_TO_END, !BEE_ECC_RR_READY);
  if (!hw_ecc_set_all_operands(&group, (uint32_t *)scalar,
                               BEE_ECC_P256_WORDS * sizeof(uint32_t))) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }
  if (hw_ecc_compute(&hardware_result, BEE_ECC_RX_ADDR, BEE_ECC_MUL_ENTRY) !=
      ERR_NONE) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }

  memcpy(result->x, hardware_result.x, sizeof(result->x));
  memcpy(result->y, hardware_result.y, sizeof(result->y));
  memset(result->z, 0, sizeof(result->z));
  result->z[0] = 1U;
  return BEE_CRYPTO_SUCCESS;
}

int bee_ecc_p256_add(const struct bee_ecc_point *left,
                     const struct bee_ecc_point *right,
                     struct bee_ecc_point *result) {
  ECC_POINT hardware_result = {0};

  if (left == NULL || right == NULL || result == NULL) {
    return BEE_CRYPTO_ERROR_INVALID_ARGUMENT;
  }

  if (bee_ecc_p256_mod_prepare(bee_p256_prime) != BEE_CRYPTO_SUCCESS) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }
  hw_ecc_init(256U, ECC_PRIME_MODE, BEE_ECC_GO_TO_END, BEE_ECC_RR_READY);
  hw_ecc_set_sub_operand(BEE_ECC_A_ADDR, (uint32_t *)bee_p256_a,
                         sizeof(bee_p256_a));
  hw_ecc_set_sub_operand(BEE_ECC_B_ADDR, (uint32_t *)bee_p256_b,
                         sizeof(bee_p256_b));
  hw_ecc_set_sub_operand(BEE_ECC_X_ADDR, (uint32_t *)left->x, sizeof(left->x));
  hw_ecc_set_sub_operand(BEE_ECC_Y_ADDR, (uint32_t *)left->y, sizeof(left->y));
  hw_ecc_set_sub_operand(BEE_ECC_Z_ADDR, (uint32_t *)left->z, sizeof(left->z));
  hw_ecc_set_sub_operand(BEE_ECC_RX_ADDR, (uint32_t *)right->x,
                         sizeof(right->x));
  hw_ecc_set_sub_operand(BEE_ECC_RY_ADDR, (uint32_t *)right->y,
                         sizeof(right->y));
  hw_ecc_set_sub_operand(BEE_ECC_RZ_ADDR, (uint32_t *)right->z,
                         sizeof(right->z));
  if (hw_ecc_compute(&hardware_result, BEE_ECC_RX_ADDR, BEE_ECC_ADD_ENTRY) !=
      ERR_NONE) {
    return BEE_CRYPTO_ERROR_HARDWARE;
  }

  memcpy(result->x, hardware_result.x, sizeof(result->x));
  memcpy(result->y, hardware_result.y, sizeof(result->y));
  memset(result->z, 0, sizeof(result->z));
  result->z[0] = 1U;
  return BEE_CRYPTO_SUCCESS;
}
#else
int bee_ecc_p256_enable(void) { return BEE_CRYPTO_ERROR_NOT_SUPPORTED; }

void bee_ecc_p256_disable(void) {}

int bee_ecc_p256_mod_prepare(const uint32_t modulus[BEE_ECC_P256_WORDS]) {
  (void)modulus;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_mod_reduce(uint32_t value[BEE_ECC_P256_WORDS]) {
  (void)value;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_mod_mul(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  (void)left;
  (void)right;
  (void)result;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_mod_add(const uint32_t left[BEE_ECC_P256_WORDS],
                         const uint32_t right[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  (void)left;
  (void)right;
  (void)result;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_mod_inv(const uint32_t value[BEE_ECC_P256_WORDS],
                         uint32_t result[BEE_ECC_P256_WORDS]) {
  (void)value;
  (void)result;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_mul(const uint32_t scalar[BEE_ECC_P256_WORDS],
                     const struct bee_ecc_point *point,
                     struct bee_ecc_point *result) {
  (void)scalar;
  (void)point;
  (void)result;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_validate_public(const struct bee_ecc_point *point) {
  (void)point;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}

int bee_ecc_p256_add(const struct bee_ecc_point *left,
                     const struct bee_ecc_point *right,
                     struct bee_ecc_point *result) {
  (void)left;
  (void)right;
  (void)result;
  return BEE_CRYPTO_ERROR_NOT_SUPPORTED;
}
#endif
