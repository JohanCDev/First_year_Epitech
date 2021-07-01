/*
** EPITECH PROJECT, 2020
** LibMy - hash module internals
** File description:
** Hasher type definition
*/

#ifndef __LIBMY_INTERNAL_HASH_H__
#define __LIBMY_INTERNAL_HASH_H__

#include <stddef.h>

#include "libmy/internal/attributes.h"
#include "libmy/internal/types.h"

typedef struct {
    my_u64_t key_1;
    my_u64_t key_2;
    /// The number of bytes processed.
    size_t length;
    /// Unprocessed bytes (Little Endian).
    my_u64_t tail;
    /// Number of valid bytes in @c tail
    size_t ntail;
    my_u64_t state_0;
    my_u64_t state_1;
    my_u64_t state_2;
    my_u64_t state_3;
} p_my_hasher_t;

#endif // !defined(__LIBMY_INTERNAL_HASH_H__)
