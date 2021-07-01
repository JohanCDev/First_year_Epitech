/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The setenv builtin
*/

#include <libmy/ascii.h>
#include <libmy/io.h>

#include "builtin.h"
#include "shell.h"
#include "variables.h"

int sh_builtin_setenv(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    sh_error_t code;

    if (argc == 1)
        return sh_builtin_env(ctx, should_exit, 1, argv);
    if (argc > 3)
        return sh_rerror(argv[0], SH_TOO_MANY_ARGS, 1);
    code = sh_check_var_name(argv[1], my_strlen(argv[1]));
    if (code != SH_OK)
        return sh_rerror(argv[0], code, 1);
    sh_env_set(ctx, SH_TO_LSTR(argv[1]),
        argc == 3 ? SH_TO_LSTR(argv[2]) : SH_LSTR("", 0));
    if (my_strcmp(argv[1], "PATH") == 0)
        sh_ctx_reset_path(ctx);
    return 0;
}
