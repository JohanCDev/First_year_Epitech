/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Finds the next token of the given type.
*/

#include "token.h"

size_t sh_token_find(
    size_t token_count, sh_token_t const tokens[], sh_token_type_t token_types)
{
    size_t pos = 0;

    while (pos < token_count && !(tokens[pos].type & token_types))
        ++pos;
    return pos;
}
