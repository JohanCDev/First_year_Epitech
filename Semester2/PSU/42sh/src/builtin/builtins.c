/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The builtins builtin
*/

#include "builtin.h"
#include "util.h"

int sh_builtin_builtins(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    char const *builtin_names[BUILTIN_COUNT];

    if (argc > 1)
        return sh_rerror(argv[0], SH_TOO_MANY_ARGS, 1);
    for (size_t i = 0; i < BUILTIN_COUNT; ++i)
        builtin_names[i] = BUILTINS[i].name;
    sh_column_print(ctx, BUILTIN_COUNT, builtin_names, MY_STDOUT);
    (void)should_exit;
    return 0;
}
