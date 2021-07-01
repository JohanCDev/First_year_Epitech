/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Copies n bytes from src to dst
*/

#include <stddef.h>
#include "libmy/memory.h"

MY_MEMORY_API void *my_memcpy(void *dest, const void *src, size_t n)
{
    if (!dest || !src)
        return NULL;
    for (size_t i = 0; i < n; ++i)
        ((char *)dest)[i] = ((char *)src)[i];
    return dest;
}
