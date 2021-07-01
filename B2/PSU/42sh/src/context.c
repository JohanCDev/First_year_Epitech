/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Shell context functions
*/

#include <libmy/ascii.h>
#include <libmy/io.h>
#include <stdalign.h>
#include <stdlib.h>
#include <unistd.h>

#include "command.h"
#include "shell.h"
#include "variables.h"

static const my_map_kvtypes_t SH_VARS_MAP_KVTYPES = {
    .key_size = sizeof(sh_lstr_t),
    .key_align = alignof(sh_lstr_t),
    .value_size = sizeof(sh_var_value_t),
    .value_align = alignof(sh_var_value_t),
    .compare = (my_map_compare_keys_t)&sh_lstr_cmp,
    .hash = (my_map_hash_key_t)&sh_lstr_hash,
    .key_drop = MY_HASH_MAP_CSTR_DROP,
    .value_drop = MY_HASH_MAP_CSTR_DROP,
};

static const my_map_kvtypes_t SH_ALIASES_MAP_KVTYPES = {
    .key_size = sizeof(sh_lstr_t),
    .key_align = alignof(sh_lstr_t),
    .value_size = sizeof(sh_alias_t),
    .value_align = alignof(sh_alias_t),
    .compare = (my_map_compare_keys_t)&sh_lstr_cmp,
    .hash = (my_map_hash_key_t)&sh_lstr_hash,
    .key_drop = MY_HASH_MAP_CSTR_DROP,
    .value_drop = MY_HASH_MAP_CSTR_DROP,
};

static int sh_copy_env(sh_ctx_t *ctx, char **envp)
{
    size_t env_size = 0;
    char *entry = NULL;

    env_size = 0;
    while (envp[env_size])
        ++env_size;
    if (my_vec_init_capacity(&ctx->env, env_size + 1, sizeof(*envp)))
        return 84;
    for (size_t i = 0; i < env_size; ++i) {
        entry = my_strdup(envp[i]);
        if (!entry) {
            my_vec_free(&ctx->env, &sh_free_entry);
            return 84;
        }
        my_vec_push(&ctx->env, &entry);
    }
    entry = NULL;
    my_vec_push(&ctx->env, &entry);
    return 0;
}

int sh_ctx_init(sh_ctx_t *ctx, int argc, char const *argv[], char **envp)
{
    if (sh_copy_env(ctx, envp))
        return 84;
    my_vec_init(&ctx->path, sizeof(char *));
    sh_ctx_reset_path(ctx);
    my_hash_map_init(&ctx->vars, &SH_VARS_MAP_KVTYPES);
    my_hash_map_init(&ctx->aliases, &SH_ALIASES_MAP_KVTYPES);
    my_vec_init(&ctx->pipeline, sizeof(sh_command_t));
    ctx->is_tty = isatty(MY_STDIN->unix_stream.fd);
    ctx->exit_code = 0;
    ctx->old_pwd = NULL;
    ctx->had_exit_cmd = -1;
    ctx->input = MY_STDIN;
    sh_line_edit_init(&ctx->line_edit, ctx);
    ctx->argc = argc;
    ctx->argv = argv;
    return 0;
}

void sh_ctx_drop(sh_ctx_t *ctx)
{
    my_hash_map_drop(&ctx->line_edit.keybinds_fcts);
    my_vec_free(&ctx->env, &sh_free_entry);
    my_hash_map_drop(&ctx->vars);
    my_hash_map_drop(&ctx->aliases);
    my_vec_free(&ctx->path, &sh_free_entry);
    my_vec_free(&ctx->pipeline, (void (*)(void *))(&sh_command_drop));
    free(ctx->old_pwd);
    ctx->old_pwd = NULL;
    if (ctx->input != MY_STDIN) {
        my_fclose(ctx->input);
        free(ctx->input);
    }
}
