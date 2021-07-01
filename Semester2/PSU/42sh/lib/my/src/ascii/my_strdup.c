/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Duplicates the given string
*/

#include <stdlib.h>

#include "libmy/ascii/ascii.h"
#include "libmy/memory/memory.h"

MY_ASCII_API char *my_strdup(char const *src)
{
    char *dup;
    size_t len;

    if (!src)
        return NULL;
    len = my_strlen(src);
    dup = malloc(sizeof(*dup) * (len + 1));
    if (!dup)
        return NULL;
    my_memcpy(dup, src, len);
    dup[len] = '\0';
    return dup;
}
