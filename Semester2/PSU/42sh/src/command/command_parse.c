/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses the next command
*/

#include <assert.h>

#include "command.h"

static int sh_command_parse_redirections(
    sh_command_t *command, size_t token_count, sh_token_t tokens[])
{
    size_t pos = sh_token_find(token_count, tokens, SH_TOKEN_LT);

    if (pos < token_count) {
        command->base.input = sh_token_to_str(&tokens[pos + 1]);
        if (command->base.input == NULL)
            return sh_rerror(NULL, SH_OUT_OF_MEMORY, -1);
        command->base.input_type = sh_token_type_to_str(tokens[pos + 1].type);
    }
    pos = sh_token_find(token_count, tokens, SH_TOKEN_GT | SH_TOKEN_GT_GT);
    if (pos < token_count) {
        command->base.output = sh_token_to_str(&tokens[pos + 1]);
        if (command->base.output == NULL)
            return sh_rerror(NULL, SH_OUT_OF_MEMORY, -1);
        command->base.truncate = tokens[pos].type == SH_TOKEN_GT;
        command->base.output_type = sh_token_type_to_str(tokens[pos + 1].type);
    }
    return 0;
}

static int sh_command_parse_arguments(
    sh_command_t *command, size_t token_count, sh_token_t tokens[])
{
    char const *value;
    sh_token_type_t type;
    size_t end;

    if (my_vec_ensure_capacity(&command->base.args, token_count + 1)
        || my_vec_ensure_capacity(&command->base.arg_types, token_count + 1))
        return sh_rerror(NULL, SH_OUT_OF_MEMORY, -1);
    end = sh_token_find(token_count, tokens, SH_REDIRECT_TOKENS);
    for (size_t i = 0; i < end; ++i) {
        value = sh_token_to_str(&tokens[i]);
        if (value == NULL)
            return sh_rerror(NULL, SH_OUT_OF_MEMORY, -1);
        type = sh_token_type_to_str(tokens[i].type);
        my_vec_push(&command->base.args, &value);
        my_vec_push(&command->base.arg_types, &type);
    }
    value = NULL;
    my_vec_push(&command->base.args, &value);
    return 0;
}

int sh_command_parse(sh_command_t *command, size_t token_count,
    sh_token_t tokens[], sh_pipe_pos_t pipe_pos)
{
    int ret;

    assert(tokens != NULL);
    assert(pipe_pos >= 0 && pipe_pos < SH_PIPE_INVALID);
    if (command == NULL)
        return sh_rerror(NULL, SH_OUT_OF_MEMORY, -1);
    command->base.pipe_pos = pipe_pos;
    ret = sh_command_parse_redirections(command, token_count, tokens);
    if (ret != 0)
        return ret;
    return sh_command_parse_arguments(command, token_count, tokens);
}
