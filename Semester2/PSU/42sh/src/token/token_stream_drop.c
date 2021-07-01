/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Uninitializes a token stream
*/

#include <stdlib.h>

#include "token.h"

void sh_drop_token(void *token)
{
    sh_token_t *t = token;

    if (t->type & SH_STRING_TOKENS)
        free(t->str);
    *t = (sh_token_t){0};
}

void sh_token_stream_drop(sh_token_stream_t *stream)
{
    if (stream == NULL)
        return;
    my_vec_free(&stream->line_buf, NULL);
    my_vec_free(&stream->tokens, &sh_drop_token);
}
