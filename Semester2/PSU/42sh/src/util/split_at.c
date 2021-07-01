/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Splits
*/

#include <libmy/ascii/character.h>

#include "util.h"

void sh_split_at(
    sh_lstr_t src, sh_lstr_t *first, sh_lstr_t *second, size_t pos)
{
    *first = SH_LSTR(src.value, pos);
    *second = SH_LSTR(src.value + pos, src.length - pos);
    if ((pos == 0 || !my_isspace(src.value[pos - 1]))
        && !my_isspace(src.value[pos]))
        return;
    while (first->length > 0 && my_isspace(src.value[first->length - 1]))
        --first->length;
    while ((size_t)(second->value - src.value) < src.length
        && my_isspace(*second->value)) {
        ++second->value;
        --second->length;
    }
}
