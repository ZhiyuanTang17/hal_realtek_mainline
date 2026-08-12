/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "crypto_bee_psa.h"
#include "crypto_bee_psa_adapter.h"
#include <string.h>

#define BEE_PSA_CCM_BLOCK_SIZE 16U

struct bee_psa_ccm_context {
  const uint8_t *key;
  size_t key_length;
  const uint8_t *nonce;
  size_t nonce_length;
  uint8_t length_size;
  uint8_t mac[BEE_PSA_CCM_BLOCK_SIZE];
};

psa_status_t bee_psa_init(void) {
  return bee_crypto_init() == BEE_CRYPTO_SUCCESS ? PSA_SUCCESS
                                                 : PSA_ERROR_HARDWARE_FAILURE;
}

static psa_status_t bee_psa_status(int status) {
  if (status == BEE_CRYPTO_SUCCESS) {
    return PSA_SUCCESS;
  }

  return status == BEE_CRYPTO_ERROR_INVALID_ARGUMENT
             ? PSA_ERROR_INVALID_ARGUMENT
             : PSA_ERROR_HARDWARE_FAILURE;
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

psa_status_t bee_psa_cipher_encrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *iv, size_t iv_length,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length) {
  psa_status_t status =
      bee_psa_validate_key(attributes, key_buffer, key_buffer_size);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (alg != PSA_ALG_ECB_NO_PADDING || iv_length != 0U) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if (input_length != BEE_PSA_CCM_BLOCK_SIZE) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if (input == NULL || output == NULL || output_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (output_size < input_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  (void)iv;
  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  status = bee_psa_ecb_crypt(key_buffer, key_buffer_size, input, output, false);
  bee_crypto_unlock();
  if (status == PSA_SUCCESS) {
    *output_length = input_length;
  }
  return status;
}

psa_status_t bee_psa_cipher_decrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length) {
  psa_status_t status =
      bee_psa_validate_key(attributes, key_buffer, key_buffer_size);

  if (status != PSA_SUCCESS) {
    return status;
  }
  if (alg != PSA_ALG_ECB_NO_PADDING || input_length != BEE_PSA_CCM_BLOCK_SIZE) {
    return PSA_ERROR_NOT_SUPPORTED;
  }
  if (input == NULL || output == NULL || output_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (output_size < input_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }
  status = bee_psa_ecb_crypt(key_buffer, key_buffer_size, input, output, true);
  bee_crypto_unlock();
  if (status == PSA_SUCCESS) {
    *output_length = input_length;
  }
  return status;
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
  if (alg != PSA_ALG_CBC_NO_PADDING) {
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
  if (iv == NULL || iv_length != BEE_AES_BLOCK_SIZE || operation->iv_set) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }

  memcpy(operation->iv, iv, BEE_AES_BLOCK_SIZE);
  operation->iv_set = 1U;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_cipher_update(bee_psa_cipher_operation_t *operation,
                                   const uint8_t *input, size_t input_length,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length) {
  psa_status_t status = PSA_SUCCESS;
  size_t total_length = input_length;

  if (operation->algorithm != PSA_ALG_CBC_NO_PADDING || !operation->iv_set) {
    return PSA_ERROR_BAD_STATE;
  }
  if ((input_length % BEE_AES_BLOCK_SIZE) != 0U) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if ((input_length > 0U && (input == NULL || output == NULL)) ||
      output_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  if (output_size < input_length) {
    return PSA_ERROR_BUFFER_TOO_SMALL;
  }
  if (input_length == 0U) {
    *output_length = 0U;
    return PSA_SUCCESS;
  }

  if (bee_crypto_lock() != BEE_CRYPTO_SUCCESS) {
    return PSA_ERROR_HARDWARE_FAILURE;
  }

  while (input_length > 0U) {
    uint8_t next_iv[BEE_AES_BLOCK_SIZE];
    int ret;

    if (operation->decrypt) {
      memcpy(next_iv, input, sizeof(next_iv));
    }
    ret = bee_aes_hw_crypt_block(operation->key, operation->key_length,
                                 AES_MODE_CBC, input, output, operation->iv,
                                 operation->decrypt);
    if (ret != BEE_CRYPTO_SUCCESS) {
      status = bee_psa_status(ret);
      break;
    }
    if (operation->decrypt) {
      memcpy(operation->iv, next_iv, sizeof(operation->iv));
    } else {
      memcpy(operation->iv, output, sizeof(operation->iv));
    }
    input += BEE_AES_BLOCK_SIZE;
    output += BEE_AES_BLOCK_SIZE;
    input_length -= BEE_AES_BLOCK_SIZE;
  }

  bee_crypto_unlock();
  if (status == PSA_SUCCESS) {
    *output_length = total_length;
  }
  return status;
}

psa_status_t bee_psa_cipher_finish(bee_psa_cipher_operation_t *operation,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length) {
  (void)operation;
  (void)output;
  (void)output_size;
  if (output_length == NULL) {
    return PSA_ERROR_INVALID_ARGUMENT;
  }
  *output_length = 0U;
  return PSA_SUCCESS;
}

psa_status_t bee_psa_cipher_abort(bee_psa_cipher_operation_t *operation) {
  memset(operation, 0, sizeof(*operation));
  return PSA_SUCCESS;
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
