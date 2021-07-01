/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Executes a token array
*/

#include "command.h"
#include "shell.h"

int sh_pipeline_execute(sh_ctx_t *ctx)
{
    int ret = 0;
    size_t len = ctx->pipeline.length;
    sh_command_t *command;

    for (size_t i = 0; i < len; ++i)
        sh_command_resolve(ctx, my_vec_get(&ctx->pipeline, i));
    for (size_t i = 0; i < len; ++i) {
        command = my_vec_get(&ctx->pipeline, i);
        ret = sh_command_execute(ctx, command,
            i + 1 < len ? my_vec_get(&ctx->pipeline, i + 1) : NULL);
        if (ret != 0)
            break;
    }
    my_vec_clear(&ctx->pipeline, (void (*)(void *))(&sh_command_drop));
    return ret;
}
