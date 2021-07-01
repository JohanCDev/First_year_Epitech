/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Expands all the variables in a command
*/

#include <libmy/ascii.h>
#include <libmy/memory/alloc.h>

#include "command.h"
#include "variables.h"

/// Modifies its arg_pos and arg_len argument.
///
/// @returns whether the string need splitting again, or -1 on error.
static int sh_split_arg_at(
    my_vec_t *args, size_t *arg_pos, size_t *arg_len, size_t split_pos)
{
    sh_lstr_t parts[2];
    sh_lstr_t arg = SH_LSTR(MY_VEC_GET(char *, args, *arg_pos), *arg_len);

    sh_split_at(arg, &parts[0], &parts[1], split_pos);
    if (arg.value + parts[0].length == parts[1].value)
        return 1;
    arg.value[parts[0].length] = '\0';
    *arg_len = parts[0].length;
    if (parts[1].length == 0)
        return 0;
    *arg_len = parts[1].length;
    if (parts[0].length == 0) {
        my_memmove(arg.value, parts[1].value, parts[1].length);
        arg.value[parts[1].length] = '\0';
        return 1;
    }
    parts[1].value = my_strndup(parts[1].value, parts[1].length);
    if (!parts[1].value || my_vec_insert(args, &parts[1].value, ++(*arg_pos)))
        return sh_rerror(NULL, SH_OUT_OF_MEMORY,
            ((intptr_t)my_sfree((void **)&parts[1].value)) * 0 - 1);
    return 1;
}

/// @returns the position of the next argument to split, or -1 on error.
static ssize_t sh_split_arg_expansion(
    sh_expansion_t exp, my_vec_t *args, size_t arg_pos)
{
    int need_split =
        sh_split_arg_at(args, &arg_pos, &exp.value_end, exp.value_begin);
    char *arg = MY_VEC_GET(char *, args, arg_pos);
    sh_lstr_t word = sh_next_word(arg);

    if (need_split <= 0)
        return need_split == 0 ? (ssize_t)arg_pos : -1;
    word = sh_next_word(word.value ? word.value + word.length : NULL);
    while (word.value != NULL) {
        need_split =
            sh_split_arg_at(args, &arg_pos, &exp.value_end, word.value - arg);
        if (need_split <= 0)
            return need_split == 0 ? (ssize_t)arg_pos : -1;
        arg = MY_VEC_GET(char *, args, arg_pos);
        word = sh_next_word(arg);
        word = sh_next_word(word.value ? word.value + word.length : NULL);
    }
    return (ssize_t)arg_pos;
}

/// @returns the position of the next argument to split, or -1 on error.
static ssize_t sh_command_expand_unquoted_str(
    sh_ctx_t *ctx, my_vec_t *args, size_t pos)
{
    sh_expansion_t exp = {.str = MY_VEC_GET(char *, args, pos)};
    sh_lstr_t name;
    ssize_t curr_pos = pos;
    sh_error_t ret;

    ret = sh_expand_var(ctx, &exp, &name, false);
    *((char **)my_vec_get(args, pos)) = exp.str;
    while (ret == SH_OK && exp.value_begin != exp.value_end) {
        curr_pos = sh_split_arg_expansion(exp, args, curr_pos);
        if (curr_pos < 0)
            return -1;
        ret = sh_expand_var(ctx, &exp, &name, false);
        *((char **)my_vec_get(args, pos)) = exp.str;
    }
    if (!sh_print_var_error(ret, name))
        return -1;
    if (sh_count_words(exp.str) == 0) {
        my_vec_remove(args, NULL, curr_pos);
        return curr_pos;
    }
    return curr_pos + 1;
}

static bool sh_command_expand_double_str(
    sh_ctx_t *ctx, my_vec_t *args, size_t pos)
{
    sh_lstr_t name;
    sh_error_t ret = sh_expand_vars(ctx, my_vec_get(args, pos), &name, false);

    return sh_print_var_error(ret, name);
}

bool sh_command_expand_vars(sh_ctx_t *ctx, sh_command_t *cmd)
{
    size_t arg_count = cmd->base.args.length;
    size_t i = 0;
    int exit_code = ctx->exit_code;

    ctx->exit_code = 1;
    while (i < arg_count - 1) {
        ssize_t next_pos = i + 1;
        sh_token_type_t type =
            MY_VEC_GET(sh_token_type_t, &cmd->base.arg_types, i);

        if (type == SH_TOKEN_DOUBLE_STR
            && !sh_command_expand_double_str(ctx, &cmd->base.args, i))
            return false;
        if (type & SH_UNQUOTED_TOKENS)
            next_pos = sh_command_expand_unquoted_str(ctx, &cmd->base.args, i);
        if (next_pos < 0)
            return false;
        i = next_pos;
    }
    ctx->exit_code = exit_code;
    return true;
}
