/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** A function that compares two strings
*/

#include <assert.h>

#include "libmy/memory/memory.h"

MY_MEMORY_API int my_memcmp(const void *p1, const void *p2, size_t len)
{
    unsigned char const *s1 = p1;
    unsigned char const *s2 = p2;
    size_t i = 0;

    assert(p1 != NULL);
    assert(p2 != NULL);
    while (i < len && s1[i] == s2[i])
        ++i;
    if (i == len)
        return 0;
    return (int)s1[i] - (int)s2[i];
}
