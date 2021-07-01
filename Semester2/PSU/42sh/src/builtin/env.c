/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The env builtin
*/

#include <libmy/io.h>

#include "builtin.h"

int sh_builtin_env(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    size_t env_len = ctx->env.length - 1;

    for (size_t i = 0; i < env_len; ++i)
        my_puts_endl(MY_VEC_GET_ELEM(char *, &ctx->env, i));
    (void)should_exit;
    (void)argc;
    (void)argv;
    return 0;
}
