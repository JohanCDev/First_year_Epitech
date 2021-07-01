/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Duplicates the given string up to n bytes
*/

#include <stdlib.h>

#include "libmy/ascii/ascii.h"
#include "libmy/core.h"
#include "libmy/memory/memory.h"

MY_ASCII_API char *my_strndup(char const *src, size_t n)
{
    char *dup;
    size_t len;

    if (!src)
        return NULL;
    len = my_strlen(src);
    len = MY_MIN(len, n);
    dup = malloc(sizeof(*dup) * (len + 1));
    if (!dup)
        return NULL;
    my_memcpy(dup, src, len);
    dup[len] = '\0';
    return dup;
}
