/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses the shell arguments
*/

#include <libmy/printf.h>

#include "shell.h"

bool sh_parse_args(sh_ctx_t *ctx, int argc, char const *argv[])
{
    int i = 1;

    while (i < argc) {
        if (argv[i][0] != '-' || argv[i][1] == 'b') {
            i += argv[i][1] == 'b';
            break;
        }
        my_fprintf(MY_STDERR,
            "Unknown option: `%s'\nUsage: %s [ -b ] [ argument ... ].\n",
            argv[i], argv[0]);
        ctx->exit_code = 1;
        return false;
    }
    if (i < argc && !sh_open_script(ctx, argc - i, argv + i))
        return false;
    return true;
}
