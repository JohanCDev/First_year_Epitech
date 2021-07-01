/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Starts the shell
*/

#include <libmy/io/iostream.h>

#include "shell.h"

void sh_start(sh_ctx_t *ctx)
{
    sh_token_stream_t stream;

    sh_token_stream_init(&stream);
    while (1) {
        sh_print_prompt(ctx);
        if (sh_token_stream_next(&stream, ctx, SIZE_MAX) < 0)
            continue;
        if ((stream.line_buf.length == 0
                && (my_feof(MY_STDIN) || ctx->line_edit.is_eof))
            || sh_execute(ctx, stream.tokens.length, stream.tokens.data) < 0)
            break;
        my_fflush(MY_STDERR);
    }
    my_fflush(MY_STDERR);
    sh_print(ctx, "exit\n");
    sh_token_stream_drop(&stream);
}
