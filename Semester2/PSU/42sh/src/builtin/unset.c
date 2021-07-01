/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The unset builtin
*/

#include <fnmatch.h>

#include "builtin.h"

static void sh_builtin_unset_matching(my_hash_map_t *vars, char const *pattern)
{
    my_hash_map_iter_t iter;
    sh_lstr_t *key;

    my_hash_map_iter_init(&iter, vars);
    while (my_hash_map_iter_next(&iter)) {
        key = iter.key;
        if (fnmatch(pattern, key->value, 0) == 0)
            my_hash_map_remove(vars, key);
    }
}

int sh_builtin_unset(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    if (argc < 2)
        return sh_rerror(argv[0], SH_TOO_FEW_ARGS, 1);
    for (size_t i = 1; i < argc; ++i)
        sh_builtin_unset_matching(&ctx->vars, argv[i]);
    (void)should_exit;
    return 0;
}
