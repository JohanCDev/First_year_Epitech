/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Environment variable functions
*/

#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <stdlib.h>

#include "shell.h"

char **sh_env_get_entry(sh_ctx_t *ctx, sh_lstr_t key)
{
    size_t len = ctx->env.length - 1;

    for (size_t i = 0; i < len; ++i) {
        char **entry = my_vec_get(&ctx->env, i);

        if (my_strncmp(key.value, *entry, key.length) == 0)
            return entry;
    }
    return NULL;
}

void sh_env_set(sh_ctx_t *ctx, sh_lstr_t key, sh_lstr_t value)
{
    char *new_entry =
        malloc(sizeof(*new_entry) * (key.length + value.length + 2));
    char **old_entry = sh_env_get_entry(ctx, key);

    if (!new_entry)
        return;
    my_memcpy(new_entry, key.value, key.length);
    new_entry[key.length] = '=';
    my_memcpy(new_entry + key.length + 1, value.value, value.length);
    new_entry[key.length + value.length + 1] = '\0';
    if (old_entry) {
        free(*old_entry);
        *old_entry = new_entry;
    } else {
        my_vec_push(&ctx->env, &old_entry);
        *((char **)my_vec_get(&ctx->env, ctx->env.length - 2)) = new_entry;
    }
}

bool sh_env_remove(sh_ctx_t *ctx, sh_lstr_t key)
{
    char **entry = sh_env_get_entry(ctx, key);
    char **new_env;
    size_t index;

    if (!entry)
        return false;
    index = (size_t)(entry - (char **)ctx->env.data);
    new_env = malloc(sizeof(*new_env) * (ctx->env.length - 1));
    if (!new_env)
        return false;
    free(*entry);
    for (size_t i = 0; i < index; ++i)
        new_env[i] = MY_VEC_GET_ELEM(char *, &ctx->env, i);
    for (size_t i = index + 1; i < ctx->env.length; ++i)
        new_env[i - 1] = MY_VEC_GET_ELEM(char *, &ctx->env, i);
    free(ctx->env.data);
    ctx->env.data = new_env;
    ctx->env.capacity = ctx->env.length - 1;
    --ctx->env.length;
    return true;
}
