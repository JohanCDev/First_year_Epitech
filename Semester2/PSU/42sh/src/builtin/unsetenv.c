/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The unsetenv builtin
*/

#include <libmy/ascii.h>
#include <libmy/io.h>
#include "builtin.h"
#include "context.h"
#include "shell.h"

int sh_builtin_unsetenv(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    if (argc == 1)
        return sh_rerror(argv[0], SH_TOO_FEW_ARGS, 1);
    for (size_t i = 1; i < argc; ++i)
        if (sh_env_remove(ctx, SH_LSTR(argv[i], my_strlen(argv[i])))
            && my_strcmp(argv[i], "PATH") == 0)
            sh_ctx_reset_path(ctx);
    (void)should_exit;
    return 0;
}
