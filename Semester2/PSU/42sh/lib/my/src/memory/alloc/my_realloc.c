/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** A recreation of realloc
*/

#include <stdlib.h>
#include "libmy/core.h"
#include "libmy/memory.h"

MY_MEMORY_API void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (!ptr)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (old_size == new_size)
        return ptr;
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    my_memcpy(new_ptr, ptr, MY_MIN(old_size, new_size));
    free(ptr);
    return new_ptr;
}
