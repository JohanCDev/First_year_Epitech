/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Length-annotated string functions
*/

#include <libmy/memory/memory.h>
#include <stdlib.h>

#include "util.h"

bool sh_lstr_dup(sh_lstr_t src, sh_lstr_t *dst)
{
    char *new_value = malloc(sizeof(src.value) * (src.length + 1));

    if (new_value == NULL)
        return false;
    my_memcpy(new_value, src.value, src.length);
    new_value[src.length] = '\0';
    dst->length = src.length;
    dst->value = new_value;
    return true;
}

int sh_lstr_cmp(sh_lstr_t const *a, sh_lstr_t const *b)
{
    return my_memcmp(a->value, b->value, MY_MIN(a->length, b->length));
}

void sh_lstr_hash(my_hasher_t *hasher, sh_lstr_t *str)
{
    my_hasher_write(hasher, str->length, str->value);
}
