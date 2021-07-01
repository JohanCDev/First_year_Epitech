/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The source builtin
*/

#include <stdlib.h>

#include "builtin.h"
#include "command.h"
#include "shell.h"

int sh_builtin_source(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    int is_tty = ctx->is_tty;
    my_iostream_t *input = ctx->input;
    my_vec_t pipeline = ctx->pipeline;

    ctx->input = NULL;
    if (argc < 2)
        return sh_rerror(argv[0], SH_TOO_FEW_ARGS, 1);
    my_vec_init(&ctx->pipeline, sizeof(sh_command_t));
    if (sh_open_script(ctx, argc - 1, argv + 1))
        sh_start(ctx);
    if (ctx->input != NULL) {
        my_fclose(ctx->input);
        free(ctx->input);
    }
    my_vec_free(&ctx->pipeline, (void (*)(void *))(&sh_command_drop));
    ctx->pipeline = pipeline;
    ctx->input = input;
    ctx->is_tty = is_tty;
    (void)should_exit;
    return ctx->exit_code;
}
