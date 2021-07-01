/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Swaps the contents of two pointers
*/

#include <assert.h>
#include <stddef.h>

#include "libmy/memory/config.h"

// This function has a inline version of itself in memory/memory.h
// this implementation is only used when the address of my_memswap is taken.
MY_MEMORY_API void my_memswap(void *restrict a, void *restrict b, size_t size)
{
    assert(a != b);
    for (size_t i = 0; i < size; ++i) {
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)b)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
    }
}
