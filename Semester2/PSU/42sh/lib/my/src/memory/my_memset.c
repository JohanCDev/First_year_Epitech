/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Fills the first n bytes with given byte
*/

#include "libmy/memory.h"

MY_MEMORY_API void *my_memset(void *mem, unsigned char byte, size_t size)
{
    if (!mem)
        return mem;
    for (size_t i = 0; i < size; ++i)
        ((unsigned char *)mem)[i] = byte;
    return mem;
}
