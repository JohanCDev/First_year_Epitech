/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The set builtin
*/

#include <libmy/ascii.h>
#include <libmy/printf.h>
#include <stdlib.h>

#include "builtin.h"
#include "shell.h"
#include "variables.h"

static int sh_set_print_vars(sh_ctx_t *ctx, bool filter_ro)
{
    sh_lstr_t *keys = malloc(sizeof(*keys) * ctx->vars.length);
    my_hash_map_iter_t iter;
    size_t count = 0;

    if (keys == NULL)
        return 1;
    my_hash_map_iter_init(&iter, &ctx->vars);
    for (size_t i = 0; my_hash_map_iter_next(&iter); ++i)
        if (!filter_ro || ((sh_var_value_t *)iter.value)->read_only)
            keys[count++] = *(sh_lstr_t *)iter.key;
    qsort(keys, count, sizeof(*keys), (my_comparator_t)&sh_lstr_cmp);
    for (size_t i = 0; i < count; ++i) {
        sh_lstr_t key = keys[i];
        sh_lstr_t value = sh_var_get(ctx, key);

        my_printf(
            "%.*s\t%.*s\n", key.length, key.value, value.length, value.value);
    }
    free(keys);
    return 0;
}

static sh_error_t sh_set_var(
    sh_ctx_t *ctx, sh_lstr_t key, sh_lstr_t value, bool read_only)
{
    sh_var_value_t *old_value = my_hash_map_get(&ctx->vars, &key);

    if (old_value != NULL && old_value->read_only)
        return SH_READ_ONLY_VAR;
    if (read_only && (value.value == NULL || value.length == 0)) {
        old_value->read_only = true;
        return SH_OK;
    }
    return sh_var_set(ctx, key, value, read_only);
}

static bool sh_set_parse_kv(
    sh_ctx_t *ctx, char const *name, char const *arg, bool read_only)
{
    char const *sep = my_strechr(arg, '=');
    sh_lstr_t key = SH_LSTR(arg, sep - arg);
    sh_lstr_t value =
        SH_LSTR(*sep ? sep + 1 : sep, my_strlen(sep ? sep + 1 : sep));
    sh_error_t ret = sh_check_var_name(key.value, key.length);

    if (ret != SH_OK)
        return sh_rerror(name, ret, false);
    ret = sh_set_var(ctx, key, value, read_only);
    if (ret == SH_READ_ONLY_VAR) {
        my_fprintf(MY_STDERR, "%s: $%.*s is read-only.\n", name, key.length,
            key.value);
        return false;
    } else if (ret != SH_OK)
        return sh_rerror(name, ret, false);
    return true;
}

int sh_builtin_set(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    bool read_only = argc > 1 && my_strcmp(argv[1], "-r") == 0;

    if (argc == 1 || (argc == 2 && read_only))
        return sh_set_print_vars(ctx, read_only);
    for (size_t i = 1 + (int)read_only; i < argc; ++i)
        if (!sh_set_parse_kv(ctx, argv[0], argv[i], read_only))
            return 1;
    (void)should_exit;
    return 0;
}
