/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Frees the value of the given pointer and sets it to NULL
*/

#include <stdlib.h>

#include "libmy/memory/alloc.h"

MY_MEMORY_API void *my_sfree(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
    return NULL;
}
