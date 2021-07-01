/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Expands the aliases in the first argument, recursively
*/

#include <libmy/ascii/ascii.h>
#include <stdlib.h>

#include "command.h"

static bool sh_command_get_alias(
    sh_ctx_t *ctx, my_vec_t *args, sh_alias_t *alias, my_vec_t *excl)
{
    sh_lstr_t arg = SH_TO_LSTR(MY_VEC_GET(char *, args, 0));
    sh_alias_t *value;

    for (size_t i = 0; i + 1 < excl->length; ++i) {
        if (my_strcmp(arg.value, MY_VEC_GET(char *, excl, i)) != 0)
            continue;
        my_vec_free(excl, &sh_free_entry);
        excl->length = SIZE_MAX;
        ctx->exit_code = ctx->exit_code ? ctx->exit_code : 1;
        return (bool)sh_rerror(NULL, SH_ALIAS_LOOP, false);
    }
    value = my_hash_map_get(&ctx->aliases, &arg);
    if ((excl->length > 0
            && !my_strcmp(
                arg.value, MY_VEC_GET(char *, excl, excl->length - 1)))
        || value == NULL) {
        my_vec_free(excl, &sh_free_entry);
        return false;
    }
    *alias = *value;
    return true;
}

static void sh_command_alias_init_stream(
    sh_token_stream_t *stream, sh_alias_t const *alias)
{
    sh_token_stream_init(stream);
    stream->line_buf.data = my_strndup(alias->value, alias->length);
    stream->line_buf.capacity = alias->length;
    stream->line_buf.length = alias->length;
}

static bool sh_command_alias_insert_alias(
    sh_ctx_t *ctx, sh_command_base_t *command, sh_alias_t const *alias)
{
    sh_token_stream_t stream;
    sh_token_t token;
    size_t pos = 0;

    sh_command_alias_init_stream(&stream, alias);
    while (sh_token_parse(&stream, ctx, &token) == 0) {
        if (!sh_token_into_str(&token)
            || my_vec_insert(&command->args, &token.str, pos)) {
            sh_token_stream_drop(&stream);
            sh_drop_token(&token);
            return false;
        }
        if (my_vec_insert(&command->arg_types, &token.type, pos)) {
            sh_token_stream_drop(&stream);
            return false;
        }
        ++pos;
    }
    sh_token_stream_drop(&stream);
    return true;
}

bool sh_command_expand_aliases(sh_ctx_t *ctx, sh_command_t *command)
{
    sh_alias_t alias;
    my_vec_t prev;

    my_vec_init(&prev, sizeof(char *));
    if (MY_VEC_GET(sh_token_type_t, &command->base.arg_types, 0)
            == SH_TOKEN_ESCAPED_NAME
        || !sh_command_get_alias(ctx, &command->base.args, &alias, &prev))
        return true;
    do {
        if (my_vec_reserve(&prev, 1) != MY_VEC_OK)
            return false;
        my_vec_remove(&command->base.args, my_vec_get(&prev, prev.length), 0);
        ++prev.length;
        my_vec_remove(&command->base.arg_types, NULL, 0);
        if (!sh_command_alias_insert_alias(ctx, &command->base, &alias))
            return (bool)sh_rerror(NULL, SH_OUT_OF_MEMORY, false);
    } while (sh_command_get_alias(ctx, &command->base.args, &alias, &prev));
    sh_command_resolve(ctx, command);
    return prev.length != SIZE_MAX;
}
