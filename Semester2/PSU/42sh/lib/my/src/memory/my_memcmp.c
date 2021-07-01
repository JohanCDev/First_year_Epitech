/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** A function that compares two strings
*/

#include <assert.h>
#include <stdlib.h>

#include "libmy/memory/memory.h"

MY_MEMORY_API void *my_memdup(void const *mem, size_t size)
{
    unsigned char *dup;

    assert(mem != NULL);
    if (size == 0)
        return NULL;
    dup = malloc(size);
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; i < size; ++i)
        dup[i] = ((unsigned char *)mem)[i];
    return dup;
}
