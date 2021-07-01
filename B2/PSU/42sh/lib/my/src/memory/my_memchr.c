/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Searches for a byte in a memory area
*/

#include "libmy/memory.h"

MY_MEMORY_API void *my_memchr(
    void const *mem, unsigned char byte, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        if (((unsigned char *)mem)[i] == byte)
            return ((char *)mem) + i;
    return NULL;
}
