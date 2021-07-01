/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Repeats command builtin
*/

#include <libmy/parsing.h>
#include <libmy/printf.h>

#include "builtin.h"
#include "command.h"
#include "util.h"

static bool sh_repeat_parse_args(
    int *repeat_count, size_t argc, char const *argv[])
{
    char const *repeat_arg;

    if (argc < 3) {
        my_fprintf(MY_STDERR, "%s: Too few arguments.\n", argv[0]);
        return false;
    }
    repeat_arg = *argv[1] == '+' ? argv[1] + 1 : argv[1];
    if (sh_parse_int(repeat_arg, repeat_count)) {
        my_fprintf(MY_STDERR, "%s: Badly formed number.\n", argv[0]);
        return false;
    }
    return true;
}

int sh_builtin_repeat(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    int repeat_count = 0;
    sh_command_t cmd;
    const sh_token_type_t type = SH_TOKEN_SINGLE_STR;

    if (!sh_repeat_parse_args(&repeat_count, argc, argv))
        return 1;
    sh_command_init(&cmd);
    cmd.base.args.data = argv + 2;
    cmd.base.args.length = argc - 1;
    my_vec_init(&cmd.base.arg_types, sizeof(type));
    if (my_vec_extend_to_length(&cmd.base.arg_types, (void *)&type, argc - 1))
        return sh_rerror(argv[0], SH_OUT_OF_MEMORY, 1);
    cmd.base.pipe_pos = SH_PIPE_END;
    sh_command_resolve(ctx, &cmd);
    for (int i = 0; i < repeat_count; ++i) {
        sh_command_execute(ctx, &cmd, NULL);
        if (cmd.base.command_type == SH_COMMAND_NOT_FOUND)
            return 1;
    }
    (void)should_exit;
    return 0;
}
