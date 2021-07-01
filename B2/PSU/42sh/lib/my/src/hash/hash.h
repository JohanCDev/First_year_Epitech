/*
** EPITECH PROJECT, 2020
** LibMy - hash module sources
** File description:
** Hasher internal functions
*/

#ifndef __LIBMY_SRC_HASH_HASH_H__
#define __LIBMY_SRC_HASH_HASH_H__

#include <stddef.h>

#include "libmy/internal/hash.h"

/// Resets the state of a hasher.
MY_LOCAL void p_my_hasher_reset(p_my_hasher_t *hasher);

/// Loads up to 7 bytes from the given buffer in little endian.
///
/// @param length MUST be lower than 8.
MY_LOCAL my_u64_t p_my_hash_load_from_mem(
    unsigned char const *buf, size_t start, size_t length);

#define P_MY_UNWRAP_STATE(H) &H->state_0, &H->state_1, &H->state_2, &H->state_3

MY_LOCAL void p_my_siphash13_c_rounds(p_my_hasher_t *hasher);
MY_LOCAL void p_my_siphash13_d_rounds(p_my_hasher_t *hasher);

#endif // !defined(__LIBMY_SRC_HASH_HASH_H__)
