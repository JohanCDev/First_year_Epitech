/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Shell variables
*/

#include <libmy/ascii.h>
#include <libmy/memory/alloc.h>
#include <stdlib.h>

#include "shell.h"
#include "variables.h"

sh_lstr_t sh_var_get(sh_ctx_t *ctx, sh_lstr_t key)
{
    sh_lstr_t *value = my_hash_map_get(&ctx->vars, &key);

    if (value == NULL)
        return (sh_lstr_t){.value = NULL, .length = 0};
    return *value;
}

sh_lstr_t sh_var_get_any(sh_ctx_t *ctx, sh_lstr_t key)
{
    sh_lstr_t value = sh_var_get(ctx, key);
    char **entry;

    if (value.value != NULL)
        return value;
    entry = sh_env_get_entry(ctx, key);
    if (entry == NULL)
        return value;
    value.value = my_strechr(*entry, '=') + 1;
    value.length = my_strlen(value.value);
    return value;
}

sh_error_t sh_var_set(
    sh_ctx_t *ctx, sh_lstr_t key, sh_lstr_t value, bool read_only)
{
    sh_var_value_t *old_value = my_hash_map_get(&ctx->vars, &key);
    sh_lstr_t new_key;
    sh_var_value_t new_value = {.read_only = read_only};

    if (old_value != NULL) {
        if (old_value->read_only)
            return SH_READ_ONLY_VAR;
        my_hash_map_remove(&ctx->vars, &key);
    }
    if (!sh_lstr_dup(key, &new_key) || !sh_lstr_dup(value, &new_value.inner)
        || my_hash_map_insert(&ctx->vars, &new_key, &new_value)) {
        free(new_key.value);
        free(new_value.inner.value);
        return SH_OUT_OF_MEMORY;
    }
    return SH_OK;
}

sh_error_t sh_var_remove(sh_ctx_t *ctx, sh_lstr_t key)
{
    sh_var_value_t *old_value = my_hash_map_get(&ctx->vars, &key);

    if (old_value != NULL && old_value->read_only)
        return SH_READ_ONLY_VAR;
    my_hash_map_remove(&ctx->vars, &key);
    return SH_OK;
}
