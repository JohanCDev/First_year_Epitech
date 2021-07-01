/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Copies src to dest, src may overlap with dest
*/

#include "libmy/memory.h"

MY_MEMORY_API void *my_memmove(void *d, const void *s, size_t n)
{
    unsigned char *dst = (unsigned char *)d;
    unsigned char *src = (unsigned char *)s;

    if (!d || !s)
        return NULL;
    if (d == s || !n)
        return d;
    if (src < dst) {
        while (n--)
            dst[n] = src[n];
    } else {
        my_memcpy(d, s, n);
    }
    return d;
}
