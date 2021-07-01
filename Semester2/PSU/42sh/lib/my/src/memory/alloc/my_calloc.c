/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Allocates a zero-initialized array
*/

#include <stdint.h>
#include <stdlib.h>
#include "libmy/memory.h"

MY_MEMORY_API void *my_calloc(size_t nmemb, size_t size)
{
    void *array;
    size_t alloc_size;

    if (nmemb == 0 || size == 0 || SIZE_MAX / nmemb < size)
        return NULL;
    alloc_size = nmemb * size;
    array = malloc(alloc_size);
    return my_memset(array, 0, alloc_size);
}
