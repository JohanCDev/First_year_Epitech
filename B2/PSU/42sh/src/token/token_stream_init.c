/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Initializes a token stream
*/

#include "token.h"

void sh_token_stream_init(sh_token_stream_t *stream)
{
    assert(stream != NULL);
    my_vec_init(&stream->line_buf, sizeof(char));
    my_vec_init(&stream->tokens, sizeof(sh_token_t));
    sh_token_stream_reset(stream);
}

void sh_token_stream_reset(sh_token_stream_t *stream)
{
    assert(stream != NULL);
    my_vec_clear(&stream->line_buf, NULL);
    my_vec_clear(&stream->tokens, &sh_drop_token);
    stream->line_pos = 0;
}
