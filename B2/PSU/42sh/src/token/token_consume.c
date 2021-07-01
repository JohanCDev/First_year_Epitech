/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Consumes a token from the given array
*/

#include "token.h"

bool sh_token_consume(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types)
{
    if (sh_token_match(*token_count, *tokens, token_types)) {
        ++(*tokens);
        --(*token_count);
        return true;
    }
    return false;
}

bool sh_token_consume_except(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types)
{
    if (sh_token_match_except(*token_count, *tokens, token_types)) {
        ++(*tokens);
        --(*token_count);
        return true;
    }
    return false;
}
