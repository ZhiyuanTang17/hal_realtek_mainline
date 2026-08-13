/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef REALTEK_BEE_CRYPTO_PSA_H_
#define REALTEK_BEE_CRYPTO_PSA_H_

#include "crypto_bee_psa_types.h"
#include <psa/crypto.h>

#ifdef __cplusplus
extern "C" {
#endif

psa_status_t bee_psa_init(void);

psa_status_t bee_psa_hash_compute(psa_algorithm_t alg, const uint8_t *input,
                                  size_t input_length, uint8_t *hash,
                                  size_t hash_size, size_t *hash_length);
psa_status_t bee_psa_hash_setup(bee_psa_hash_operation_t *operation,
                                psa_algorithm_t alg);
psa_status_t bee_psa_hash_clone(const bee_psa_hash_operation_t *source_operation,
                                bee_psa_hash_operation_t *target_operation);
psa_status_t bee_psa_hash_update(bee_psa_hash_operation_t *operation,
                                 const uint8_t *input, size_t input_length);
psa_status_t bee_psa_hash_finish(bee_psa_hash_operation_t *operation,
                                 uint8_t *hash, size_t hash_size,
                                 size_t *hash_length);
psa_status_t bee_psa_hash_abort(bee_psa_hash_operation_t *operation);

psa_status_t bee_psa_sign_hash(const psa_key_attributes_t *attributes,
                               const uint8_t *key_buffer,
                               size_t key_buffer_size, psa_algorithm_t alg,
                               const uint8_t *hash, size_t hash_length,
                               uint8_t *signature, size_t signature_size,
                               size_t *signature_length);
psa_status_t bee_psa_verify_hash(const psa_key_attributes_t *attributes,
                                 const uint8_t *key_buffer,
                                 size_t key_buffer_size, psa_algorithm_t alg,
                                 const uint8_t *hash, size_t hash_length,
                                 const uint8_t *signature,
                                 size_t signature_length);
psa_status_t bee_psa_key_agreement(const psa_key_attributes_t *attributes,
                                   const uint8_t *key_buffer,
                                   size_t key_buffer_size, psa_algorithm_t alg,
                                   const uint8_t *peer_key,
                                   size_t peer_key_length,
                                   uint8_t *shared_secret,
                                   size_t shared_secret_size,
                                   size_t *shared_secret_length);

psa_status_t bee_psa_cipher_encrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *iv, size_t iv_length,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length);

psa_status_t bee_psa_cipher_decrypt(const psa_key_attributes_t *attributes,
                                    const uint8_t *key_buffer,
                                    size_t key_buffer_size, psa_algorithm_t alg,
                                    const uint8_t *input, size_t input_length,
                                    uint8_t *output, size_t output_size,
                                    size_t *output_length);

psa_status_t
bee_psa_cipher_encrypt_setup(bee_psa_cipher_operation_t *operation,
                             const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer, size_t key_buffer_size,
                             psa_algorithm_t alg);
psa_status_t
bee_psa_cipher_decrypt_setup(bee_psa_cipher_operation_t *operation,
                             const psa_key_attributes_t *attributes,
                             const uint8_t *key_buffer, size_t key_buffer_size,
                             psa_algorithm_t alg);
psa_status_t bee_psa_cipher_set_iv(bee_psa_cipher_operation_t *operation,
                                   const uint8_t *iv, size_t iv_length);
psa_status_t bee_psa_cipher_update(bee_psa_cipher_operation_t *operation,
                                   const uint8_t *input, size_t input_length,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length);
psa_status_t bee_psa_cipher_finish(bee_psa_cipher_operation_t *operation,
                                   uint8_t *output, size_t output_size,
                                   size_t *output_length);
psa_status_t bee_psa_cipher_abort(bee_psa_cipher_operation_t *operation);

psa_status_t bee_psa_aead_encrypt_setup(bee_psa_aead_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg);
psa_status_t bee_psa_aead_decrypt_setup(bee_psa_aead_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg);
psa_status_t bee_psa_aead_set_nonce(bee_psa_aead_operation_t *operation,
                                    const uint8_t *nonce, size_t nonce_length);
psa_status_t bee_psa_aead_set_lengths(bee_psa_aead_operation_t *operation,
                                      size_t ad_length,
                                      size_t plaintext_length);
psa_status_t bee_psa_aead_update_ad(bee_psa_aead_operation_t *operation,
                                    const uint8_t *input, size_t input_length);
psa_status_t bee_psa_aead_update(bee_psa_aead_operation_t *operation,
                                 const uint8_t *input, size_t input_length,
                                 uint8_t *output, size_t output_size,
                                 size_t *output_length);
psa_status_t bee_psa_aead_finish(bee_psa_aead_operation_t *operation,
                                 uint8_t *ciphertext, size_t ciphertext_size,
                                 size_t *ciphertext_length, uint8_t *tag,
                                 size_t tag_size, size_t *tag_length);
psa_status_t bee_psa_aead_verify(bee_psa_aead_operation_t *operation,
                                 uint8_t *plaintext, size_t plaintext_size,
                                 size_t *plaintext_length, const uint8_t *tag,
                                 size_t tag_length);
psa_status_t bee_psa_aead_abort(bee_psa_aead_operation_t *operation);

psa_status_t
bee_psa_aead_encrypt(const psa_key_attributes_t *attributes,
                     const uint8_t *key_buffer, size_t key_buffer_size,
                     psa_algorithm_t alg, const uint8_t *nonce,
                     size_t nonce_length, const uint8_t *additional_data,
                     size_t additional_data_length, const uint8_t *plaintext,
                     size_t plaintext_length, uint8_t *ciphertext,
                     size_t ciphertext_size, size_t *ciphertext_length);

psa_status_t
bee_psa_aead_decrypt(const psa_key_attributes_t *attributes,
                     const uint8_t *key_buffer, size_t key_buffer_size,
                     psa_algorithm_t alg, const uint8_t *nonce,
                     size_t nonce_length, const uint8_t *additional_data,
                     size_t additional_data_length, const uint8_t *ciphertext,
                     size_t ciphertext_length, uint8_t *plaintext,
                     size_t plaintext_size, size_t *plaintext_length);

#ifdef __cplusplus
}
#endif

#endif /* REALTEK_BEE_CRYPTO_PSA_H_ */
