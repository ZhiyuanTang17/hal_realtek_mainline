/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "crypto_bee_psa.h"
#include "crypto_bee_psa_adapter.h"
#include <string.h>

#define BEE_PSA_CCM_BLOCK_SIZE 16U
#define BEE_PSA_P256_BYTES 32U
#define BEE_PSA_P256_SIGNATURE_BYTES (2U * BEE_PSA_P256_BYTES)

static const uint32_t bee_psa_p256_order[BEE_ECC_P256_WORDS] = {
    0xfc632551U, 0xf3b9cac2U, 0xa7179e84U, 0xbce6faadU,
    0xffffffffU, 0xffffffffU, 0x00000000U, 0xffffffffU,
};
static const struct bee_ecc_point bee_psa_p256_generator = {
    .x = {0xd898c296U, 0xf4a13945U, 0x2deb33a0U, 0x77037d81U, 0x63a440f2U,
          0xf8bce6e5U, 0xe12c4247U, 0x6b17d1f2U},
    .y = {0x37bf51f5U, 0xcbb64068U, 0x6b315eceU, 0x2bce3357U, 0x7c0f9e16U,
          0x8ee7eb4aU, 0xfe1a7f9bU, 0x4fe342e2U},
    .z = {1U},
};

struct bee_psa_ccm_context {
  const uint8_t *key;
  size_t key_length;
  const uint8_t *nonce;
  size_t nonce_length;
  uint8_t length_size;
  uint8_t mac[BEE_PSA_CCM_BLOCK_SIZE];
};

psa_status_t bee_psa_init(void) {
  int status = bee_crypto_init();

  if (status != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }

  hw_sha256_init();
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_status(int status) {
  if (status == BEE_CRYPTO_SUCCESS) {
    return PSA_SUCCESS;
  }
  if (status == BEE_CRYPTO_ERROR_NOT_SUPPORTED) {
    return PSA_ERROR_NOT_SUPPORTED;
  }

  return status == BEE_CRYPTO_ERROR_INVALID_ARGUMENT
             ? PSA_ERROR_INVALID_ARGUMENT
             : PSA_ERROR_HARDWARE_FAILURE;
}

psa_status_t bee_psa_hash_compute(psa_algorithm_t alg, const uint8_t *input,
                                  size_t input_length, uint8_t *hash,
                                  size_t hash_size, size_t *hash_length) {
  size_t required_size = PSA_HASH_LENGTH(PSA_ALG_SHA_256);
  psa_status_t status;

  if (alg != PSA_ALG_SHA_256) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if ((input == NULL && input_length != 0U) || hash_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (hash_size < required_size) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (hash == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  status = bee_psa_status(bee_sha256_hw_compute(input, input_length, hash));
  if (status == PSA_SUCCESS) {
    *hash_length = required_size;
  }
  return status;
}

psa_status_t bee_psa_hash_setup(bee_psa_hash_operation_t *operation,
                                psa_algorithm_t alg) {
  psa_status_t status;

  if (operation == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (alg != PSA_ALG_SHA_256) {
    return PSA_ERROR_NOT_SUPPORTED;
  }

  memset(operation, 0, sizeof(*operation));
  status = bee_psa_status(bee_sha256_hw_start(&operation->context));
  if (status == PSA_SUCCESS) {
    operation->algorithm = alg;
  }
  return status;
}

psa_status_t bee_psa_hash_clone(const bee_psa_hash_operation_t *source_operation,
                                bee_psa_hash_operation_t *target_operation) {
  if (source_operation == NULL || target_operation == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (source_operation->algorithm != PSA_ALG_SHA_256) {
    return PSA_ERROR_BAD_STATE;
  }

  memcpy(target_operation, source_operation, sizeof(*target_operation));
  return PSA_SUCCESS;
}

psa_status_t bee_psa_hash_update(bee_psa_hash_operation_t *operation,
                                 const uint8_t *input, size_t input_length) {
  if (operation == NULL || (input == NULL && input_length != 0U)) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (operation->algorithm != PSA_ALG_SHA_256) {
    return PSA_ERROR_BAD_STATE;
  }

  return bee_psa_status(
      bee_sha256_hw_update(&operation->context, input, input_length));
}

psa_status_t bee_psa_hash_finish(bee_psa_hash_operation_t *operation,
                                 uint8_t *hash, size_t hash_size,
                                 size_t *hash_length) {
  size_t required_size = PSA_HASH_LENGTH(PSA_ALG_SHA_256);
  psa_status_t status;

  if (operation == NULL || hash_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (operation->algorithm != PSA_ALG_SHA_256) {
    return PSA_ERROR_BAD_STATE;
  }
  if (hash_size < required_size) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (hash == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  status = bee_psa_status(bee_sha256_hw_finish(&operation->context, hash));
  if (status == PSA_SUCCESS) {
    *hash_length = required_size;
  }
  return status;
}

psa_status_t bee_psa_hash_abort(bee_psa_hash_operation_t *operation) {
  if (operation == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  memset(operation, 0, sizeof(*operation));
  return PSA_SUCCESS;
}

static void bee_psa_p256_read(const uint8_t *input, size_t input_length,
                              uint32_t output[BEE_ECC_P256_WORDS]) {
  size_t used =
      input_length > BEE_PSA_P256_BYTES ? BEE_PSA_P256_BYTES : input_length;

  memset(output, 0, BEE_PSA_P256_BYTES);
  for (size_t i = 0; i < used; i++) {
    output[(used - 1U - i) / sizeof(uint32_t)] |=
        (uint32_t)input[i] << (8U * ((used - 1U - i) % sizeof(uint32_t)));
  }
}

static void bee_psa_p256_write(const uint32_t input[BEE_ECC_P256_WORDS],
                               uint8_t output[BEE_PSA_P256_BYTES]) {
  for (size_t i = 0; i < BEE_PSA_P256_BYTES; i++) {
    output[BEE_PSA_P256_BYTES - 1U - i] =
        (uint8_t)(input[i / sizeof(uint32_t)] >> (8U * (i % sizeof(uint32_t))));
  }
}

static int bee_psa_p256_is_zero(const uint32_t value[BEE_ECC_P256_WORDS]) {
  uint32_t result = 0U;

  for (size_t i = 0; i < BEE_ECC_P256_WORDS; i++) {
    result |= value[i];
  }
  return result == 0U;
}

static int bee_psa_p256_compare(const uint32_t left[BEE_ECC_P256_WORDS],
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

static void bee_psa_p256_reduce_order(uint32_t value[BEE_ECC_P256_WORDS]) {
  uint64_t borrow = 0U;

  if (bee_psa_p256_compare(value, bee_psa_p256_order) < 0) {
    return;
  }
  for (size_t i = 0; i < BEE_ECC_P256_WORDS; i++) {
    uint64_t subtrahend = (uint64_t)bee_psa_p256_order[i] + borrow;
    uint64_t current = value[i];

    value[i] = (uint32_t)(current - subtrahend);
    borrow = current < subtrahend;
  }
}

static int bee_psa_p256_point_is_zero(const struct bee_ecc_point *point) {
  return bee_psa_p256_is_zero(point->x) && bee_psa_p256_is_zero(point->y);
}

static psa_status_t
bee_psa_validate_ecdsa(const psa_key_attributes_t *attributes,
                       psa_algorithm_t alg, bool signing) {
  psa_key_type_t type = psa_get_key_type(attributes);

#if !defined(BEE_CRYPTO_RTL87X2G)
  (void)type;
  (void)alg;
  (void)signing;
  return PSA_ERROR_NOT_SUPPORTED;
#else
  if (!PSA_ALG_IS_RANDOMIZED_ECDSA(alg) ||
      PSA_KEY_TYPE_ECC_GET_FAMILY(type) != PSA_ECC_FAMILY_SECP_R1 ||
      psa_get_key_bits(attributes) != 256U) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if (signing) {
    return type == PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1)
               ? PSA_SUCCESS
               : PSA_ERROR_NOT_SUPPORTED;
  }
  return (type == PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1) ||
          type == PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1))
             ? PSA_SUCCESS
             : PSA_ERROR_NOT_SUPPORTED;
#endif
}

static psa_status_t bee_psa_validate_ecdh(
    const psa_key_attributes_t *attributes, psa_algorithm_t alg) {
#if !defined(BEE_CRYPTO_RTL87X2G)
  (void)attributes;
  (void)alg;
  return PSA_ERROR_NOT_SUPPORTED;
#else
  psa_key_type_t type = psa_get_key_type(attributes);

  if (!PSA_ALG_IS_ECDH(alg) ||
      type != PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1) ||
      psa_get_key_bits(attributes) != 256U) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  return PSA_SUCCESS;
#endif
}

psa_status_t bee_psa_key_agreement(const psa_key_attributes_t *attributes,
                                   const uint8_t *key_buffer,
                                   size_t key_buffer_size, psa_algorithm_t alg,
                                   const uint8_t *peer_key,
                                   size_t peer_key_length,
                                   uint8_t *shared_secret,
                                   size_t shared_secret_size,
                                   size_t *shared_secret_length) {
  uint32_t private_key[BEE_ECC_P256_WORDS];
  struct bee_ecc_point peer_point = {0};
  struct bee_ecc_point result = {0};
  psa_status_t status = bee_psa_validate_ecdh(attributes, alg);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (key_buffer == NULL || peer_key == NULL || shared_secret == NULL ||
      shared_secret_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (key_buffer_size != BEE_PSA_P256_BYTES ||
      peer_key_length != 1U + 2U * BEE_PSA_P256_BYTES ||
      peer_key[0] != 0x04U) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (shared_secret_size < BEE_PSA_P256_BYTES) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  bee_psa_p256_read(key_buffer, key_buffer_size, private_key);
  if (bee_psa_p256_is_zero(private_key) ||
      bee_psa_p256_compare(private_key, bee_psa_p256_order) >= 0) {
    status = PSA_ERROR_INVALID_ARGUMENT;
    goto exit;
  }

  bee_psa_p256_read(&peer_key[1], BEE_PSA_P256_BYTES, peer_point.x);
  bee_psa_p256_read(&peer_key[1U + BEE_PSA_P256_BYTES], BEE_PSA_P256_BYTES,
                    peer_point.y);
  if (bee_psa_p256_is_zero(peer_point.x) &&
      bee_psa_p256_is_zero(peer_point.y)) {
    status = PSA_ERROR_INVALID_ARGUMENT;
    goto exit;
  }
  peer_point.z[0] = 1U;

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    status = PSA_ERROR_HARDWARE_FAILURE;
    goto exit;
  }
  status = bee_psa_status(bee_ecc_p256_enable());
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_validate_public(&peer_point));
  }
  if (status == PSA_SUCCESS) {
    status =
        bee_psa_status(bee_ecc_p256_mul(private_key, &peer_point, &result));
  }
  bee_ecc_p256_disable();
  bee_crypto_unlock();

  if (status == PSA_SUCCESS && bee_psa_p256_point_is_zero(&result)) {
    status = PSA_ERROR_INVALID_ARGUMENT;
  }
  if (status == PSA_SUCCESS) {
    bee_psa_p256_write(result.x, shared_secret);
    *shared_secret_length = BEE_PSA_P256_BYTES;
  }

exit:
  memset(private_key, 0, sizeof(private_key));
  memset(&result, 0, sizeof(result));
  return status;
}

static psa_status_t
bee_psa_p256_public_from_key(psa_key_type_t type, const uint8_t *key_buffer,
                             size_t key_buffer_size,
                             struct bee_ecc_point *public_key) {
  if (type == PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1)) {
    if (key_buffer_size != 1U + 2U * BEE_PSA_P256_BYTES ||
        key_buffer[0] != 0x04U) {
      return PSA_ERROR_INVALID_ARGUMENT;
    }
    bee_psa_p256_read(&key_buffer[1], BEE_PSA_P256_BYTES, public_key->x);
    bee_psa_p256_read(&key_buffer[1U + BEE_PSA_P256_BYTES], BEE_PSA_P256_BYTES,
                      public_key->y);
    public_key->z[0] = 1U;
    return PSA_SUCCESS;
  }

  if (key_buffer_size != BEE_PSA_P256_BYTES) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  uint32_t private_key[BEE_ECC_P256_WORDS];
  bee_psa_p256_read(key_buffer, key_buffer_size, private_key);
  if (bee_psa_p256_is_zero(private_key) ||
      bee_psa_p256_compare(private_key, bee_psa_p256_order) >= 0) {
    memset(private_key, 0, sizeof(private_key));
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  int ret = bee_ecc_p256_mul(private_key, &bee_psa_p256_generator, public_key);
  memset(private_key, 0, sizeof(private_key));
  return bee_psa_status(ret);
}

psa_status_t bee_psa_sign_hash(const psa_key_attributes_t *attributes,
                               const uint8_t *key_buffer,
                               size_t key_buffer_size, psa_algorithm_t alg,
                               const uint8_t *hash, size_t hash_length,
                               uint8_t *signature, size_t signature_size,
                               size_t *signature_length) {
  uint32_t private_key[BEE_ECC_P256_WORDS];
  uint32_t e[BEE_ECC_P256_WORDS];
  uint32_t k[BEE_ECC_P256_WORDS];
  uint32_t r[BEE_ECC_P256_WORDS];
  uint32_t s[BEE_ECC_P256_WORDS];
  uint32_t temporary[BEE_ECC_P256_WORDS];
  struct bee_ecc_point point;
  psa_status_t status = bee_psa_validate_ecdsa(attributes, alg, true);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (key_buffer == NULL || hash == NULL || signature == NULL ||
      signature_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (key_buffer_size != BEE_PSA_P256_BYTES) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (signature_size < BEE_PSA_P256_SIGNATURE_BYTES) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  bee_psa_p256_read(key_buffer, key_buffer_size, private_key);
  bee_psa_p256_read(hash, hash_length, e);
  bee_psa_p256_reduce_order(e);
  if (bee_psa_p256_is_zero(private_key) ||
      bee_psa_p256_compare(private_key, bee_psa_p256_order) >= 0) {
    status = PSA_ERROR_INVALID_ARGUMENT;
    goto exit;
  }

  for (unsigned int attempt = 0; attempt < 10U; attempt++) {
    uint8_t random[BEE_PSA_P256_BYTES];

    status = psa_generate_random(random, sizeof(random));
    if (status != PSA_SUCCESS) {
      break;
    }
    bee_psa_p256_read(random, sizeof(random), k);
    memset(random, 0, sizeof(random));
    if (bee_psa_p256_is_zero(k) ||
        bee_psa_p256_compare(k, bee_psa_p256_order) >= 0) {
      continue;
    }

    if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
      status = PSA_ERROR_HARDWARE_FAILURE;
      break;
    }
    status = bee_psa_status(bee_ecc_p256_enable());
    if (status == PSA_SUCCESS) {
      status =
          bee_psa_status(bee_ecc_p256_mul(k, &bee_psa_p256_generator, &point));
    }
    if (status == PSA_SUCCESS) {
      status = bee_psa_status(bee_ecc_p256_mod_prepare(bee_psa_p256_order));
    }
    if (status == PSA_SUCCESS) {
      memcpy(r, point.x, sizeof(r));
      status = bee_psa_status(bee_ecc_p256_mod_reduce(r));
    }
    if (status == PSA_SUCCESS && !bee_psa_p256_is_zero(r)) {
      status = bee_psa_status(bee_ecc_p256_mod_mul(r, private_key, temporary));
    }
    if (status == PSA_SUCCESS && !bee_psa_p256_is_zero(r)) {
      status = bee_psa_status(bee_ecc_p256_mod_add(e, temporary, temporary));
    }
    if (status == PSA_SUCCESS && !bee_psa_p256_is_zero(r)) {
      status = bee_psa_status(bee_ecc_p256_mod_inv(k, s));
    }
    if (status == PSA_SUCCESS && !bee_psa_p256_is_zero(r)) {
      status = bee_psa_status(bee_ecc_p256_mod_mul(s, temporary, s));
    }
    bee_ecc_p256_disable();
    bee_crypto_unlock();

    if (status != PSA_SUCCESS) {
      break;
    }
    if (bee_psa_p256_is_zero(r) || bee_psa_p256_is_zero(s)) {
      continue;
    }

    bee_psa_p256_write(r, signature);
    bee_psa_p256_write(s, signature + BEE_PSA_P256_BYTES);
    *signature_length = BEE_PSA_P256_SIGNATURE_BYTES;
    status = PSA_SUCCESS;
    goto exit;
  }

  if (status == PSA_SUCCESS) {
    status = PSA_ERROR_INSUFFICIENT_ENTROPY;
  }

exit:
  memset(private_key, 0, sizeof(private_key));
  memset(k, 0, sizeof(k));
  memset(temporary, 0, sizeof(temporary));
  return status;
}

psa_status_t bee_psa_verify_hash(const psa_key_attributes_t *attributes,
                                 const uint8_t *key_buffer,
                                 size_t key_buffer_size, psa_algorithm_t alg,
                                 const uint8_t *hash, size_t hash_length,
                                 const uint8_t *signature,
                                 size_t signature_length) {
  struct bee_ecc_point public_key = {0};
  struct bee_ecc_point point1;
  struct bee_ecc_point point2;
  struct bee_ecc_point result;
  uint32_t e[BEE_ECC_P256_WORDS];
  uint32_t r[BEE_ECC_P256_WORDS];
  uint32_t s[BEE_ECC_P256_WORDS];
  uint32_t inverse[BEE_ECC_P256_WORDS];
  uint32_t u1[BEE_ECC_P256_WORDS];
  uint32_t u2[BEE_ECC_P256_WORDS];
  psa_key_type_t type = psa_get_key_type(attributes);
  psa_status_t status = bee_psa_validate_ecdsa(attributes, alg, false);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (key_buffer == NULL || hash == NULL || signature == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (signature_length != BEE_PSA_P256_SIGNATURE_BYTES) {
    return PSA_ERROR_INVALID_SIGNATURE;
  }

  bee_psa_p256_read(hash, hash_length, e);
  bee_psa_p256_reduce_order(e);
  bee_psa_p256_read(signature, BEE_PSA_P256_BYTES, r);
  bee_psa_p256_read(signature + BEE_PSA_P256_BYTES, BEE_PSA_P256_BYTES, s);
  if (bee_psa_p256_is_zero(r) || bee_psa_p256_is_zero(s) ||
      bee_psa_p256_compare(r, bee_psa_p256_order) >= 0 ||
      bee_psa_p256_compare(s, bee_psa_p256_order) >= 0) {
    return PSA_ERROR_INVALID_SIGNATURE;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  status = bee_psa_status(bee_ecc_p256_enable());
  if (status == PSA_SUCCESS) {
    status = bee_psa_p256_public_from_key(type, key_buffer, key_buffer_size,
                                          &public_key);
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mod_prepare(bee_psa_p256_order));
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mod_inv(s, inverse));
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mod_mul(inverse, e, u1));
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mod_mul(inverse, r, u2));
  }
  if (status == PSA_SUCCESS) {
    status =
        bee_psa_status(bee_ecc_p256_mul(u1, &bee_psa_p256_generator, &point1));
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mul(u2, &public_key, &point2));
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_add(&point1, &point2, &result));
  }
  if (status == PSA_SUCCESS && bee_psa_p256_point_is_zero(&result)) {
    status = PSA_ERROR_INVALID_SIGNATURE;
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_status(bee_ecc_p256_mod_reduce(result.x));
  }
  if (status == PSA_SUCCESS && memcmp(result.x, r, BEE_PSA_P256_BYTES) != 0) {
    status = PSA_ERROR_INVALID_SIGNATURE;
  }
  bee_ecc_p256_disable();
  bee_crypto_unlock();
  return status;
}

static psa_status_t bee_psa_validate_key(const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size) {
  if (psa_get_key_type(attributes) != PSA_KEY_TYPE_AES ||
      (key_buffer_size != 16U && key_buffer_size != 32U)) {
    return PSA_ERROR_NOT_SUPPORTED;
  }

  if (key_buffer == NULL ||
      psa_get_key_bits(attributes) != PSA_BYTES_TO_BITS(key_buffer_size)) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  return PSA_SUCCESS;
}

static psa_status_t bee_psa_ecb_crypt(const uint8_t *key, size_t key_length,
                                      const uint8_t *input, uint8_t *output,
                                      bool decrypt) {
  return bee_psa_status(bee_aes_hw_crypt_block(key, key_length, AES_MODE_ECB,
                                               input, output, NULL, decrypt));
}

static psa_status_t
bee_psa_ccm_mac_block(struct bee_psa_ccm_context *ctx,
                      const uint8_t block[BEE_PSA_CCM_BLOCK_SIZE]) {
  uint8_t input[BEE_PSA_CCM_BLOCK_SIZE];

  for (size_t i = 0; i < BEE_PSA_CCM_BLOCK_SIZE; i++) {
    input[i] = ctx->mac[i] ^ block[i];
  }

  return bee_psa_ecb_crypt(ctx->key, ctx->key_length, input, ctx->mac, false);
}

static psa_status_t bee_psa_ccm_mac_data(struct bee_psa_ccm_context *ctx,
                                         const uint8_t *data,
                                         size_t data_length) {
  while (data_length > 0U) {
    uint8_t block[BEE_PSA_CCM_BLOCK_SIZE] = {0};
    size_t chunk = data_length > sizeof(block) ? sizeof(block) : data_length;
    psa_status_t status;

    memcpy(block, data, chunk);
    status = bee_psa_ccm_mac_block(ctx, block);
    if (status != PSA_SUCCESS) {
      return status;
    }
    data += chunk;
    data_length -= chunk;
  }

  return PSA_SUCCESS;
}

static psa_status_t bee_psa_ccm_mac_aad(struct bee_psa_ccm_context *ctx,
                                        const uint8_t *aad, size_t aad_length) {
  uint8_t block[BEE_PSA_CCM_BLOCK_SIZE] = {0};
  size_t block_used = 2U;
  psa_status_t status;

  if (aad_length == 0U) {
    return PSA_SUCCESS;
  }

  block[0] = (uint8_t)(aad_length >> 8);
  block[1] = (uint8_t)aad_length;
  while (aad_length > 0U) {
    size_t chunk = aad_length;

    if (chunk > sizeof(block) - block_used) {
      chunk = sizeof(block) - block_used;
    }
    memcpy(&block[block_used], aad, chunk);
    block_used += chunk;
    aad += chunk;
    aad_length -= chunk;

    if (block_used == sizeof(block)) {
      status = bee_psa_ccm_mac_block(ctx, block);
      if (status != PSA_SUCCESS) {
        return status;
      }
      memset(block, 0, sizeof(block));
      block_used = 0U;
    }
  }

  return block_used == 0U ? PSA_SUCCESS : bee_psa_ccm_mac_block(ctx, block);
}

static void bee_psa_ccm_counter(const struct bee_psa_ccm_context *ctx,
                                uint8_t counter[BEE_PSA_CCM_BLOCK_SIZE],
                                uint64_t value) {
  memset(counter, 0, BEE_PSA_CCM_BLOCK_SIZE);
  counter[0] = ctx->length_size - 1U;
  memcpy(&counter[1], ctx->nonce, ctx->nonce_length);
  for (size_t i = 0; i < ctx->length_size; i++) {
    counter[BEE_PSA_CCM_BLOCK_SIZE - 1U - i] = (uint8_t)value;
    value >>= 8;
  }
}

static void bee_psa_ccm_increment(uint8_t counter[BEE_PSA_CCM_BLOCK_SIZE],
                                  size_t offset) {
  for (int i = BEE_PSA_CCM_BLOCK_SIZE - 1; i >= (int)offset; i--) {
    if (++counter[i] != 0U) {
      break;
    }
  }
}

static psa_status_t bee_psa_ccm_crypt(const struct bee_psa_ccm_context *ctx,
                                      const uint8_t *input, size_t input_length,
                                      uint8_t *output) {
  uint8_t counter[BEE_PSA_CCM_BLOCK_SIZE];

  bee_psa_ccm_counter(ctx, counter, 1U);
  while (input_length > 0U) {
    uint8_t stream[BEE_PSA_CCM_BLOCK_SIZE];
    size_t chunk =
        input_length > sizeof(stream) ? sizeof(stream) : input_length;
    psa_status_t status =
        bee_psa_ecb_crypt(ctx->key, ctx->key_length, counter, stream, false);

    if (status != PSA_SUCCESS) {
      return status;
    }
    for (size_t i = 0; i < chunk; i++) {
      output[i] = input[i] ^ stream[i];
    }
    bee_psa_ccm_increment(counter, 1U + ctx->nonce_length);
    input += chunk;
    output += chunk;
    input_length -= chunk;
  }

  return PSA_SUCCESS;
}

static psa_status_t bee_psa_ccm_tag(struct bee_psa_ccm_context *ctx,
                                    const uint8_t *aad, size_t aad_length,
                                    const uint8_t *plaintext,
                                    size_t plaintext_length, size_t tag_length,
                                    uint8_t *tag) {
  uint8_t b0[BEE_PSA_CCM_BLOCK_SIZE] = {0};
  uint8_t counter[BEE_PSA_CCM_BLOCK_SIZE];
  uint8_t s0[BEE_PSA_CCM_BLOCK_SIZE];
  uint64_t length = plaintext_length;
  psa_status_t status;

  b0[0] = (aad_length > 0U ? 0x40U : 0U) | (((tag_length - 2U) / 2U) << 3) |
          (ctx->length_size - 1U);
  memcpy(&b0[1], ctx->nonce, ctx->nonce_length);
  for (size_t i = 0; i < ctx->length_size; i++) {
    b0[BEE_PSA_CCM_BLOCK_SIZE - 1U - i] = (uint8_t)length;
    length >>= 8;
  }

  status = bee_psa_ccm_mac_block(ctx, b0);
  if (status == PSA_SUCCESS) {
    status = bee_psa_ccm_mac_aad(ctx, aad, aad_length);
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_ccm_mac_data(ctx, plaintext, plaintext_length);
  }
  if (status == PSA_SUCCESS) {
    bee_psa_ccm_counter(ctx, counter, 0U);
    status = bee_psa_ecb_crypt(ctx->key, ctx->key_length, counter, s0, false);
  }
  if (status == PSA_SUCCESS) {
    for (size_t i = 0; i < tag_length; i++) {
      tag[i] = ctx->mac[i] ^ s0[i];
    }
  }
  return status;
}

static psa_status_t bee_psa_ccm_prepare(
    struct bee_psa_ccm_context *ctx, const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *nonce, size_t nonce_length, size_t aad_length,
    size_t message_length, size_t *tag_length) {
  uint64_t length = message_length;
  psa_status_t status =
      bee_psa_validate_key(attributes, key_buffer, key_buffer_size);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (PSA_ALG_AEAD_WITH_SHORTENED_TAG(alg, 0) !=
      PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_CCM, 0)) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  *tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
  if (*tag_length < 4U || *tag_length > BEE_PSA_CCM_BLOCK_SIZE ||
      (*tag_length & 1U) != 0U || nonce == NULL || nonce_length < 7U ||
      nonce_length > 13U) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (aad_length >= 0xff00U) {
    return PSA_ERROR_NOT_SUPPORTED;
  }

  memset(ctx, 0, sizeof(*ctx));
  ctx->key = key_buffer;
  ctx->key_length = key_buffer_size;
  ctx->nonce = nonce;
  ctx->nonce_length = nonce_length;
  ctx->length_size = BEE_PSA_CCM_BLOCK_SIZE - 1U - nonce_length;
  if (ctx->length_size < sizeof(length) &&
      length >= (UINT64_C(1) << (8U * ctx->length_size))) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_cipher_setup(bee_psa_cipher_operation_t *operation,
                                         const psa_key_attributes_t *attributes,
                                         const uint8_t *key_buffer,
                                         size_t key_buffer_size,
                                         psa_algorithm_t alg, bool decrypt) {
  psa_status_t status =
      bee_psa_validate_key(attributes, key_buffer, key_buffer_size);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (alg != PSA_ALG_CBC_NO_PADDING && alg != PSA_ALG_CBC_PKCS7 &&
      alg != PSA_ALG_CFB && alg != PSA_ALG_OFB && alg != PSA_ALG_CTR) {
    return PSA_ERROR_NOT_SUPPORTED;
  }

  memset(operation, 0, sizeof(*operation));
  memcpy(operation->key, key_buffer, key_buffer_size);
  operation->key_length = key_buffer_size;
  operation->algorithm = alg;
  operation->decrypt = decrypt;
  return PSA_SUCCESS;
}

psa_status_t
bee_psa_cipher_encrypt_setup(bee_psa_cipher_operation_t *operation,
                             const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer, size_t key_buffer_size,
                             psa_algorithm_t alg) {
  return bee_psa_cipher_setup(operation, attributes, key_buffer,
                              key_buffer_size, alg, false);
}

psa_status_t
bee_psa_cipher_decrypt_setup(bee_psa_cipher_operation_t *operation,
                             const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer, size_t key_buffer_size,
                             psa_algorithm_t alg) {
  return bee_psa_cipher_setup(operation, attributes, key_buffer,
                              key_buffer_size, alg, true);
}

psa_status_t bee_psa_cipher_set_iv(bee_psa_cipher_operation_t *operation,
                                   const uint8_t *iv, size_t iv_length) {
  psa_status_t status = PSA_SUCCESS;

  if (operation == NULL || iv == NULL || iv_length != BEE_AES_BLOCK_SIZE ||
      operation->iv_set) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  memcpy(operation->iv, iv, BEE_AES_BLOCK_SIZE);
  if (operation->algorithm == PSA_ALG_CFB ||
      operation->algorithm == PSA_ALG_OFB ||
      operation->algorithm == PSA_ALG_CTR) {
    if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    status = bee_psa_ecb_crypt(operation->key, operation->key_length,
                               operation->iv, operation->stream, false);
    bee_crypto_unlock();
  }
  if (status == PSA_SUCCESS) {
    operation->iv_set = 1U;
  }
  return status;
}

static int bee_psa_cipher_cbc_block(bee_psa_cipher_operation_t *operation,
                                    const uint8_t input[BEE_AES_BLOCK_SIZE],
                                    uint8_t output[BEE_AES_BLOCK_SIZE]) {
  uint8_t next_iv[BEE_AES_BLOCK_SIZE];
  int ret;

  if (operation->decrypt) {
    memcpy(next_iv, input, sizeof(next_iv));
  }
  ret = bee_aes_hw_crypt_block(operation->key, operation->key_length,
                               AES_MODE_CBC, input, output, operation->iv,
                               operation->decrypt);
  if (ret != BEE_CRYPTO_SUCCESS) {
    return ret;
  }
  memcpy(operation->iv, operation->decrypt ? next_iv : output,
         BEE_AES_BLOCK_SIZE);
  return BEE_CRYPTO_SUCCESS;
}

static psa_status_t bee_psa_cipher_update_cbc_no_padding(
    bee_psa_cipher_operation_t *operation, const uint8_t *input,
    size_t input_length, uint8_t *output, size_t *output_length) {
  size_t produced = 0U;

  while (input_length > 0U) {
    size_t chunk = BEE_AES_BLOCK_SIZE - operation->buffer_length;

    if (chunk > input_length) {
      chunk = input_length;
    }
    memcpy(&operation->buffer[operation->buffer_length], input, chunk);
    operation->buffer_length += chunk;
    input += chunk;
    input_length -= chunk;

    if (operation->buffer_length == BEE_AES_BLOCK_SIZE) {
      int ret = bee_psa_cipher_cbc_block(operation, operation->buffer, output);

      if (ret != BEE_CRYPTO_SUCCESS) {
        return bee_psa_status(ret);
      }
      operation->buffer_length = 0U;
      output += BEE_AES_BLOCK_SIZE;
      produced += BEE_AES_BLOCK_SIZE;
    }
  }
  *output_length = produced;
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_cipher_update_cbc_pkcs7(
    bee_psa_cipher_operation_t *operation, const uint8_t *input,
    size_t input_length, uint8_t *output, size_t *output_length) {
  size_t produced = 0U;

  while (input_length > 0U) {
    size_t chunk;

    if (operation->decrypt &&
        operation->buffer_length == BEE_AES_BLOCK_SIZE) {
      int ret = bee_psa_cipher_cbc_block(operation, operation->buffer, output);

      if (ret != BEE_CRYPTO_SUCCESS) {
        return bee_psa_status(ret);
      }
      operation->buffer_length = 0U;
      output += BEE_AES_BLOCK_SIZE;
      produced += BEE_AES_BLOCK_SIZE;
    }

    chunk = BEE_AES_BLOCK_SIZE - operation->buffer_length;
    if (chunk > input_length) {
      chunk = input_length;
    }
    memcpy(&operation->buffer[operation->buffer_length], input, chunk);
    operation->buffer_length += chunk;
    input += chunk;
    input_length -= chunk;

    if (!operation->decrypt &&
        operation->buffer_length == BEE_AES_BLOCK_SIZE) {
      int ret = bee_psa_cipher_cbc_block(operation, operation->buffer, output);

      if (ret != BEE_CRYPTO_SUCCESS) {
        return bee_psa_status(ret);
      }
      operation->buffer_length = 0U;
      output += BEE_AES_BLOCK_SIZE;
      produced += BEE_AES_BLOCK_SIZE;
    }
  }
  *output_length = produced;
  return PSA_SUCCESS;
}

static void bee_psa_cipher_increment_counter(uint8_t counter[16]) {
  for (int i = BEE_AES_BLOCK_SIZE - 1; i >= 0; i--) {
    if (++counter[i] != 0U) {
      break;
    }
  }
}

static int bee_psa_cipher_next_stream(bee_psa_cipher_operation_t *operation) {
  if (operation->algorithm == PSA_ALG_CFB) {
    memcpy(operation->iv, operation->buffer, BEE_AES_BLOCK_SIZE);
  } else if (operation->algorithm == PSA_ALG_OFB) {
    memcpy(operation->iv, operation->stream, BEE_AES_BLOCK_SIZE);
  } else {
    bee_psa_cipher_increment_counter(operation->iv);
  }

  operation->stream_used = 0U;
  return bee_psa_ecb_crypt(operation->key, operation->key_length,
                           operation->iv, operation->stream, false) == PSA_SUCCESS
             ? BEE_CRYPTO_SUCCESS
             : BEE_CRYPTO_ERROR_HARDWARE;
}

static psa_status_t bee_psa_cipher_update_stream(
    bee_psa_cipher_operation_t *operation, const uint8_t *input,
    size_t input_length, uint8_t *output, size_t *output_length) {
  size_t produced = input_length;

  while (input_length > 0U) {
    if (operation->stream_used == BEE_AES_BLOCK_SIZE) {
      int ret = bee_psa_cipher_next_stream(operation);

      if (ret != BEE_CRYPTO_SUCCESS) {
        return bee_psa_status(ret);
      }
    }

    if (operation->algorithm == PSA_ALG_CFB) {
      uint8_t ciphertext;

      ciphertext = *input ^ operation->stream[operation->stream_used];
      operation->buffer[operation->stream_used] =
          operation->decrypt ? *input : ciphertext;
      *output = ciphertext;
    } else {
      *output = *input ^ operation->stream[operation->stream_used];
    }
    operation->stream_used++;
    input++;
    output++;
    input_length--;
  }
  *output_length = produced;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_cipher_update(bee_psa_cipher_operation_t *operation,
                                   const uint8_t *input, size_t input_length,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length) {
  psa_status_t status;
  size_t required_size;

  if (operation == NULL || output_length == NULL ||
      (input_length > 0U && (input == NULL || output == NULL))) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (!operation->iv_set) {
    return PSA_ERROR_BAD_STATE;
  }
  if (operation->algorithm == PSA_ALG_CBC_NO_PADDING) {
    size_t available = operation->buffer_length + input_length;

    required_size = (available / BEE_AES_BLOCK_SIZE) * BEE_AES_BLOCK_SIZE;
  } else if (operation->algorithm == PSA_ALG_CBC_PKCS7) {
    size_t available = operation->buffer_length + input_length;

    if (operation->decrypt) {
      required_size = available > BEE_AES_BLOCK_SIZE
                          ? ((available - 1U) / BEE_AES_BLOCK_SIZE) *
                                BEE_AES_BLOCK_SIZE
                          : 0U;
    } else {
      required_size = (available / BEE_AES_BLOCK_SIZE) * BEE_AES_BLOCK_SIZE;
    }
  } else if (operation->algorithm == PSA_ALG_CFB ||
             operation->algorithm == PSA_ALG_OFB ||
             operation->algorithm == PSA_ALG_CTR) {
    required_size = input_length;
  } else {
    return PSA_ERROR_BAD_STATE;
  }
  if (output_size < required_size) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (input_length == 0U) {
    *output_length = 0U;
    return PSA_SUCCESS;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  if (operation->algorithm == PSA_ALG_CBC_NO_PADDING) {
    status = bee_psa_cipher_update_cbc_no_padding(
        operation, input, input_length, output, output_length);
  } else if (operation->algorithm == PSA_ALG_CBC_PKCS7) {
    status = bee_psa_cipher_update_cbc_pkcs7(
        operation, input, input_length, output, output_length);
  } else {
    status = bee_psa_cipher_update_stream(
        operation, input, input_length, output, output_length);
  }
  bee_crypto_unlock();
  return status;
}

psa_status_t bee_psa_cipher_finish(bee_psa_cipher_operation_t *operation,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length) {
  psa_status_t status = PSA_SUCCESS;

  if (operation == NULL || output_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  *output_length = 0U;
  if (operation->algorithm == PSA_ALG_CBC_NO_PADDING) {
    return operation->buffer_length == 0U ? PSA_SUCCESS
                                          : PSA_ERROR_INVALID_ARGUMENT;
  }
  if (operation->algorithm != PSA_ALG_CBC_PKCS7) {
    return operation->algorithm == PSA_ALG_CFB ||
                   operation->algorithm == PSA_ALG_OFB ||
                   operation->algorithm == PSA_ALG_CTR
               ? PSA_SUCCESS
               : PSA_ERROR_BAD_STATE;
  }
  if (operation->decrypt && operation->buffer_length != BEE_AES_BLOCK_SIZE) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (output_size < BEE_AES_BLOCK_SIZE) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (output == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  if (!operation->decrypt) {
    uint8_t padding = BEE_AES_BLOCK_SIZE - operation->buffer_length;

    memset(&operation->buffer[operation->buffer_length], padding, padding);
    status = bee_psa_status(
        bee_psa_cipher_cbc_block(operation, operation->buffer, output));
    if (status == PSA_SUCCESS) {
      *output_length = BEE_AES_BLOCK_SIZE;
    }
  } else {
    uint8_t plaintext[BEE_AES_BLOCK_SIZE] = {0};
    uint8_t padding = 0U;
    uint8_t diff = 0U;

    status = bee_psa_status(
        bee_psa_cipher_cbc_block(operation, operation->buffer, plaintext));
    if (status == PSA_SUCCESS) {
      padding = plaintext[BEE_AES_BLOCK_SIZE - 1U];
      for (size_t i = 0; i < BEE_AES_BLOCK_SIZE; i++) {
        uint8_t mask = (uint8_t)-(i < padding);

        diff |= (plaintext[BEE_AES_BLOCK_SIZE - 1U - i] ^ padding) & mask;
      }
      if (padding == 0U || padding > BEE_AES_BLOCK_SIZE || diff != 0U) {
        status = PSA_ERROR_INVALID_PADDING;
      }
    }
    if (status == PSA_SUCCESS) {
      *output_length = BEE_AES_BLOCK_SIZE - padding;
      memcpy(output, plaintext, *output_length);
    }
    memset(plaintext, 0, sizeof(plaintext));
  }
  bee_crypto_unlock();
  return status;
}

psa_status_t bee_psa_cipher_abort(bee_psa_cipher_operation_t *operation) {
  memset(operation, 0, sizeof(*operation));
  return PSA_SUCCESS;
}

psa_status_t bee_psa_cipher_encrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *iv, size_t iv_length,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length) {
  bee_psa_cipher_operation_t operation;
  size_t update_length;
  size_t finish_length;
  psa_status_t status;

  if (output_length == NULL || (input_length > 0U && input == NULL) ||
      output == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (alg == PSA_ALG_ECB_NO_PADDING) {
    status = bee_psa_validate_key(attributes, key_buffer, key_buffer_size);
    if (status != PSA_SUCCESS) {
      return status;
    }
    if (iv_length != 0U || input_length != BEE_AES_BLOCK_SIZE) {
      return PSA_ERROR_NOT_SUPPORTED;
    }
    if (output_size < BEE_AES_BLOCK_SIZE) {
      return PSA_ERROR_BUFFER_TOO_SMALL;
    }
    if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    status = bee_psa_ecb_crypt(key_buffer, key_buffer_size, input, output, false);
    bee_crypto_unlock();
    if (status == PSA_SUCCESS) {
      *output_length = BEE_AES_BLOCK_SIZE;
    }
    return status;
  }

  status = bee_psa_cipher_encrypt_setup(&operation, attributes, key_buffer,
                                        key_buffer_size, alg);
  if (status != PSA_SUCCESS) {
    return status;
  }
  status = bee_psa_cipher_set_iv(&operation, iv, iv_length);
  if (status == PSA_SUCCESS) {
    status = bee_psa_cipher_update(&operation, input, input_length, output,
                                   output_size, &update_length);
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_cipher_finish(&operation, output + update_length,
                                   output_size - update_length, &finish_length);
  }
  if (status == PSA_SUCCESS) {
    *output_length = update_length + finish_length;
  }
  bee_psa_cipher_abort(&operation);
  return status;
}

psa_status_t bee_psa_cipher_decrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length) {
  bee_psa_cipher_operation_t operation;
  size_t update_length;
  size_t finish_length;
  psa_status_t status;

  if (output_length == NULL || input == NULL || output == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (alg == PSA_ALG_ECB_NO_PADDING) {
    status = bee_psa_validate_key(attributes, key_buffer, key_buffer_size);
    if (status != PSA_SUCCESS) {
      return status;
    }
    if (input_length != BEE_AES_BLOCK_SIZE) {
      return PSA_ERROR_NOT_SUPPORTED;
    }
    if (output_size < BEE_AES_BLOCK_SIZE) {
      return PSA_ERROR_BUFFER_TOO_SMALL;
    }
    if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    status = bee_psa_ecb_crypt(key_buffer, key_buffer_size, input, output, true);
    bee_crypto_unlock();
    if (status == PSA_SUCCESS) {
      *output_length = BEE_AES_BLOCK_SIZE;
    }
    return status;
  }
  if (input_length < BEE_AES_BLOCK_SIZE) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  status = bee_psa_cipher_decrypt_setup(&operation, attributes, key_buffer,
                                        key_buffer_size, alg);
  if (status != PSA_SUCCESS) {
    return status;
  }
  status = bee_psa_cipher_set_iv(&operation, input, BEE_AES_BLOCK_SIZE);
  if (status == PSA_SUCCESS) {
    status = bee_psa_cipher_update(
        &operation, input + BEE_AES_BLOCK_SIZE, input_length - BEE_AES_BLOCK_SIZE,
        output, output_size, &update_length);
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_cipher_finish(&operation, output + update_length,
                                   output_size - update_length, &finish_length);
  }
  if (status == PSA_SUCCESS) {
    *output_length = update_length + finish_length;
  }
  bee_psa_cipher_abort(&operation);
  return status;
}

psa_status_t
bee_psa_aead_encrypt(const psa_key_attributes_t *attributes,
                     const uint8_t *key_buffer, size_t key_buffer_size,
                     psa_algorithm_t alg, const uint8_t *nonce,
                     size_t nonce_length, const uint8_t *additional_data,
                     size_t additional_data_length, const uint8_t *plaintext,
                     size_t plaintext_length, uint8_t *ciphertext,
                     size_t ciphertext_size, size_t *ciphertext_length) {
  struct bee_psa_ccm_context ctx;
  size_t tag_length;
  psa_status_t status = bee_psa_ccm_prepare(
      &ctx, attributes, key_buffer, key_buffer_size, alg, nonce, nonce_length,
      additional_data_length, plaintext_length, &tag_length);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if ((additional_data_length > 0U && additional_data == NULL) ||
      (plaintext_length > 0U && plaintext == NULL) || ciphertext == NULL ||
      ciphertext_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (ciphertext_size < plaintext_length + tag_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  status = bee_psa_ccm_tag(&ctx, additional_data, additional_data_length,
                           plaintext, plaintext_length, tag_length,
                           &ciphertext[plaintext_length]);
  if (status == PSA_SUCCESS) {
    status = bee_psa_ccm_crypt(&ctx, plaintext, plaintext_length, ciphertext);
  }
  bee_crypto_unlock();
  if (status == PSA_SUCCESS) {
    *ciphertext_length = plaintext_length + tag_length;
  }
  return status;
}

psa_status_t
bee_psa_aead_decrypt(const psa_key_attributes_t *attributes,
                     const uint8_t *key_buffer, size_t key_buffer_size,
                     psa_algorithm_t alg, const uint8_t *nonce,
                     size_t nonce_length, const uint8_t *additional_data,
                     size_t additional_data_length, const uint8_t *ciphertext,
                     size_t ciphertext_length, uint8_t *plaintext,
                     size_t plaintext_size, size_t *plaintext_length) {
  struct bee_psa_ccm_context ctx;
  uint8_t tag[BEE_PSA_CCM_BLOCK_SIZE];
  uint8_t diff = 0U;
  size_t tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
  size_t payload_length;
  psa_status_t status;

  if (tag_length > ciphertext_length) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  payload_length = ciphertext_length - tag_length;
  status = bee_psa_ccm_prepare(&ctx, attributes, key_buffer, key_buffer_size,
                               alg, nonce, nonce_length, additional_data_length,
                               payload_length, &tag_length);
  if (status != PSA_SUCCESS) {
    return status;
  }
  if ((additional_data_length > 0U && additional_data == NULL) ||
      ciphertext == NULL || (payload_length > 0U && plaintext == NULL) ||
      plaintext_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (plaintext_size < payload_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  status = bee_psa_ccm_crypt(&ctx, ciphertext, payload_length, plaintext);
  if (status == PSA_SUCCESS) {
    status = bee_psa_ccm_tag(&ctx, additional_data, additional_data_length,
                             plaintext, payload_length, tag_length, tag);
  }
  bee_crypto_unlock();
  if (status != PSA_SUCCESS) {
    memset(plaintext, 0, payload_length);
    return status;
  }

  for (size_t i = 0; i < tag_length; i++) {
    diff |= tag[i] ^ ciphertext[payload_length + i];
  }
  memset(tag, 0, sizeof(tag));
  if (diff != 0U) {
    memset(plaintext, 0, payload_length);
    return PSA_ERROR_INVALID_SIGNATURE;
  }

  *plaintext_length = payload_length;
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_aead_setup(bee_psa_aead_operation_t *operation,
                                       const psa_key_attributes_t *attributes,
                                       const uint8_t *key_buffer,
                                       size_t key_buffer_size,
                                       psa_algorithm_t alg, bool decrypt) {
  size_t tag_length;
  psa_status_t status =
      bee_psa_validate_key(attributes, key_buffer, key_buffer_size);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (PSA_ALG_AEAD_WITH_SHORTENED_TAG(alg, 0) !=
      PSA_ALG_AEAD_WITH_SHORTENED_TAG(PSA_ALG_CCM, 0)) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  tag_length = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);
  if (tag_length < 4U || tag_length > BEE_PSA_CCM_BLOCK_SIZE ||
      (tag_length & 1U) != 0U) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  memset(operation, 0, sizeof(*operation));
  memcpy(operation->key, key_buffer, key_buffer_size);
  operation->key_length = key_buffer_size;
  operation->tag_length = tag_length;
  operation->decrypt = decrypt;
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_aead_mac_block(bee_psa_aead_operation_t *operation,
                                           const uint8_t block[16]) {
  uint8_t input[16];

  for (size_t i = 0; i < sizeof(input); i++) {
    input[i] = operation->mac[i] ^ block[i];
  }
  return bee_psa_ecb_crypt(operation->key, operation->key_length, input,
                           operation->mac, false);
}

static void bee_psa_aead_counter(bee_psa_aead_operation_t *operation,
                                 uint64_t value) {
  memset(operation->counter, 0, sizeof(operation->counter));
  operation->counter[0] = operation->length_size - 1U;
  memcpy(&operation->counter[1], operation->nonce, operation->nonce_length);
  for (size_t i = 0; i < operation->length_size; i++) {
    operation->counter[15U - i] = (uint8_t)value;
    value >>= 8;
  }
  operation->stream_used = sizeof(operation->stream);
}

static void bee_psa_aead_counter_inc(bee_psa_aead_operation_t *operation) {
  for (int i = 15; i >= 1 + (int)operation->nonce_length; i--) {
    if (++operation->counter[i] != 0U) {
      break;
    }
  }
}

static psa_status_t
bee_psa_aead_process_b0(bee_psa_aead_operation_t *operation) {
  psa_status_t status;

  if (operation->b0_processed) {
    return PSA_SUCCESS;
  }

  status = bee_psa_aead_mac_block(operation, operation->b0);
  if (status == PSA_SUCCESS) {
    operation->b0_processed = 1U;
  }
  return status;
}

static psa_status_t
bee_psa_aead_finish_aad(bee_psa_aead_operation_t *operation) {
  psa_status_t status;

  if (operation->aad_finished) {
    return PSA_SUCCESS;
  }
  if (operation->aad_processed != operation->aad_length) {
    return PSA_ERROR_BAD_STATE;
  }

  status = bee_psa_aead_process_b0(operation);
  if (status != PSA_SUCCESS) {
    return status;
  }
  if (operation->aad_block_used != 0U) {
    status = bee_psa_aead_mac_block(operation, operation->aad_block);
    if (status != PSA_SUCCESS) {
      return status;
    }
  }
  operation->aad_finished = 1U;
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_aead_mac_update(bee_psa_aead_operation_t *operation,
                                            const uint8_t *input,
                                            size_t input_length) {
  while (input_length > 0U) {
    size_t chunk =
        sizeof(operation->payload_block) - operation->payload_block_used;
    psa_status_t status;

    if (chunk > input_length) {
      chunk = input_length;
    }
    memcpy(&operation->payload_block[operation->payload_block_used], input,
           chunk);
    operation->payload_block_used += chunk;
    input += chunk;
    input_length -= chunk;
    if (operation->payload_block_used == sizeof(operation->payload_block)) {
      status = bee_psa_aead_mac_block(operation, operation->payload_block);
      if (status != PSA_SUCCESS) {
        return status;
      }
      memset(operation->payload_block, 0, sizeof(operation->payload_block));
      operation->payload_block_used = 0U;
    }
  }
  return PSA_SUCCESS;
}

static psa_status_t bee_psa_aead_crypt(bee_psa_aead_operation_t *operation,
                                       const uint8_t *input,
                                       size_t input_length, uint8_t *output) {
  while (input_length > 0U) {
    if (operation->stream_used == sizeof(operation->stream)) {
      psa_status_t status =
          bee_psa_ecb_crypt(operation->key, operation->key_length,
                            operation->counter, operation->stream, false);

      if (status != PSA_SUCCESS) {
        return status;
      }
      bee_psa_aead_counter_inc(operation);
      operation->stream_used = 0U;
    }
    *output++ = *input++ ^ operation->stream[operation->stream_used++];
    input_length--;
  }
  return PSA_SUCCESS;
}

psa_status_t bee_psa_aead_encrypt_setup(bee_psa_aead_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg) {
  return bee_psa_aead_setup(operation, attributes, key_buffer, key_buffer_size,
                            alg, false);
}

psa_status_t bee_psa_aead_decrypt_setup(bee_psa_aead_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg) {
  return bee_psa_aead_setup(operation, attributes, key_buffer, key_buffer_size,
                            alg, true);
}

psa_status_t bee_psa_aead_set_nonce(bee_psa_aead_operation_t *operation,
                                    const uint8_t *nonce, size_t nonce_length) {
  if (nonce == NULL || nonce_length < 7U || nonce_length > 13U) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  memcpy(operation->nonce, nonce, nonce_length);
  operation->nonce_length = nonce_length;
  operation->length_size = 15U - nonce_length;
  operation->nonce_set = 1U;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_aead_set_lengths(bee_psa_aead_operation_t *operation,
                                      size_t ad_length,
                                      size_t plaintext_length) {
  uint64_t length = plaintext_length;

  if (!operation->nonce_set) {
    return PSA_ERROR_BAD_STATE;
  }
  if (ad_length >= 0xff00U) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if (operation->length_size < sizeof(length) &&
      length >= (UINT64_C(1) << (8U * operation->length_size))) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  operation->aad_length = ad_length;
  operation->payload_length = plaintext_length;
  operation->b0[0] = (ad_length > 0U ? 0x40U : 0U) |
                     (((operation->tag_length - 2U) / 2U) << 3) |
                     (operation->length_size - 1U);
  memcpy(&operation->b0[1], operation->nonce, operation->nonce_length);
  for (size_t i = 0; i < operation->length_size; i++) {
    operation->b0[15U - i] = (uint8_t)length;
    length >>= 8;
  }

  if (ad_length > 0U) {
    operation->aad_block[0] = (uint8_t)(ad_length >> 8);
    operation->aad_block[1] = (uint8_t)ad_length;
    operation->aad_block_used = 2U;
  }
  bee_psa_aead_counter(operation, 1U);
  operation->lengths_set = 1U;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_aead_update_ad(bee_psa_aead_operation_t *operation,
                                    const uint8_t *input, size_t input_length) {
  psa_status_t status = PSA_SUCCESS;

  if (!operation->lengths_set || operation->payload_processed != 0U ||
      input_length > operation->aad_length - operation->aad_processed ||
      (input_length > 0U && input == NULL)) {
    return PSA_ERROR_BAD_STATE;
  }

  while (input_length > 0U) {
    size_t chunk = sizeof(operation->aad_block) - operation->aad_block_used;

    if (chunk > input_length) {
      chunk = input_length;
    }
    memcpy(&operation->aad_block[operation->aad_block_used], input, chunk);
    operation->aad_block_used += chunk;
    operation->aad_processed += chunk;
    input += chunk;
    input_length -= chunk;

    if (operation->aad_block_used == sizeof(operation->aad_block)) {
      if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
        return PSA_ERROR_HARDWARE_FAILURE;
      }
      status = bee_psa_aead_process_b0(operation);
      if (status == PSA_SUCCESS) {
        status = bee_psa_aead_mac_block(operation, operation->aad_block);
      }
      bee_crypto_unlock();
      if (status != PSA_SUCCESS) {
        return status;
      }
      memset(operation->aad_block, 0, sizeof(operation->aad_block));
      operation->aad_block_used = 0U;
    }
  }
  return status;
}

static psa_status_t
bee_psa_aead_finalize_tag(bee_psa_aead_operation_t *operation) {
  uint8_t counter[16];
  uint8_t s0[16];
  psa_status_t status;

  if (operation->tag_ready) {
    return PSA_SUCCESS;
  }
  status = bee_psa_aead_finish_aad(operation);
  if (status == PSA_SUCCESS && operation->payload_block_used != 0U) {
    status = bee_psa_aead_mac_block(operation, operation->payload_block);
  }
  if (status == PSA_SUCCESS) {
    bee_psa_aead_counter(operation, 0U);
    memcpy(counter, operation->counter, sizeof(counter));
    status = bee_psa_ecb_crypt(operation->key, operation->key_length, counter,
                               s0, false);
  }
  if (status == PSA_SUCCESS) {
    for (size_t i = 0; i < operation->tag_length; i++) {
      operation->tag[i] = operation->mac[i] ^ s0[i];
    }
    operation->tag_ready = 1U;
  }
  return status;
}

psa_status_t bee_psa_aead_update(bee_psa_aead_operation_t *operation,
                                 const uint8_t *input, size_t input_length,
                                 uint8_t *output, size_t output_size,
                                 size_t *output_length) {
  psa_status_t status;

  if (!operation->lengths_set ||
      input_length > operation->payload_length - operation->payload_processed ||
      (input_length > 0U && (input == NULL || output == NULL)) ||
      output_length == NULL) {
    return PSA_ERROR_BAD_STATE;
  }
  if (output_size < input_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }

  status = bee_psa_aead_finish_aad(operation);
  if (status == PSA_SUCCESS && !operation->decrypt) {
    status = bee_psa_aead_mac_update(operation, input, input_length);
  }
  if (status == PSA_SUCCESS) {
    status = bee_psa_aead_crypt(operation, input, input_length, output);
  }
  if (status == PSA_SUCCESS && operation->decrypt) {
    status = bee_psa_aead_mac_update(operation, output, input_length);
  }
  if (status == PSA_SUCCESS && operation->payload_processed + input_length ==
                                   operation->payload_length) {
    status = bee_psa_aead_finalize_tag(operation);
  }
  bee_crypto_unlock();

  if (status == PSA_SUCCESS) {
    operation->payload_processed += input_length;
    *output_length = input_length;
  }
  return status;
}

psa_status_t bee_psa_aead_finish(bee_psa_aead_operation_t *operation,
                                 uint8_t *ciphertext, size_t ciphertext_size,
                                 size_t *ciphertext_length, uint8_t *tag,
                                 size_t tag_size, size_t *tag_length) {
  psa_status_t status = PSA_SUCCESS;

  if (operation->payload_processed != operation->payload_length ||
      tag == NULL || ciphertext_length == NULL || tag_length == NULL ||
      tag_size < operation->tag_length) {
    return PSA_ERROR_BAD_STATE;
  }
  (void)ciphertext;
  (void)ciphertext_size;

  if (!operation->tag_ready) {
    if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
      return PSA_ERROR_HARDWARE_FAILURE;
    }
    status = bee_psa_aead_finalize_tag(operation);
    bee_crypto_unlock();
  }
  if (status == PSA_SUCCESS) {
    memcpy(tag, operation->tag, operation->tag_length);
    *ciphertext_length = 0U;
    *tag_length = operation->tag_length;
  }
  return status;
}

psa_status_t bee_psa_aead_verify(bee_psa_aead_operation_t *operation,
                                 uint8_t *plaintext, size_t plaintext_size,
                                 size_t *plaintext_length, const uint8_t *tag,
                                 size_t tag_length) {
  uint8_t calculated[16];
  uint8_t diff = 0U;
  size_t calculated_length;
  size_t finish_length;
  psa_status_t status;

  if (tag == NULL || tag_length != operation->tag_length ||
      plaintext_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  status =
      bee_psa_aead_finish(operation, plaintext, plaintext_size, &finish_length,
                          calculated, sizeof(calculated), &calculated_length);
  if (status != PSA_SUCCESS) {
    return status;
  }
  for (size_t i = 0; i < tag_length; i++) {
    diff |= calculated[i] ^ tag[i];
  }
  memset(calculated, 0, sizeof(calculated));
  if (diff != 0U) {
    return PSA_ERROR_INVALID_SIGNATURE;
  }
  *plaintext_length = finish_length;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_aead_abort(bee_psa_aead_operation_t *operation) {
  memset(operation, 0, sizeof(*operation));
  return PSA_SUCCESS;
}
