/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses n tokens to the token buffer
*/

#include <libmy/io/iostream.h>

#include "shell.h"
#include "token.h"
#include "line_edit.h"

static int sh_token_stream_fill_line(
    sh_token_stream_t *stream, struct sh_ctx *ctx)
{
    ssize_t bytes_read = ctx->is_tty
        ? sh_line_edit_fill(&ctx->line_edit, ctx->input)
        : my_getline((char **)&stream->line_buf.data,
            &stream->line_buf.capacity, ctx->input);

    if (bytes_read <= 0) {
        stream->line_buf.length = 0;
    } else if (MY_VEC_GET(char, &stream->line_buf, bytes_read - 1) == '\n') {
        stream->line_buf.length = bytes_read - 1;
    } else {
        stream->line_buf.length = bytes_read;
    }
    stream->line_pos = 0;
    return bytes_read <= 0;
}

ssize_t sh_token_stream_push(
    sh_token_stream_t *stream, sh_ctx_t *ctx, size_t token_count)
{
    size_t c = 1;
    int ret;

    assert(stream != NULL);
    sh_line_edit_reset(&ctx->line_edit, &stream->line_buf);
    if (token_count == 0 || sh_token_stream_fill_line(stream, ctx))
        return 0;
    for (; c < token_count; ++c) {
        if (my_vec_reserve(&stream->tokens, 1) != MY_VEC_OK)
            return SH_OUT_OF_MEMORY;
        ret = sh_token_parse(
            stream, ctx, my_vec_get(&stream->tokens, stream->tokens.length));
        if (ret < 0)
            break;
        if (ret > 0)
            return -1;
        ++stream->tokens.length;
    }
    return c;
}
