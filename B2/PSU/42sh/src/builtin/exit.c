/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The exit builtin
*/

#include <libmy/ascii.h>

#include "builtin.h"
#include "shell.h"
#include "util.h"

int sh_builtin_exit(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    int code = 0;

    if (argc > 2 || (argc == 2 && !my_isdigit(*argv[1])))
        return sh_perror(argv[0], SH_EXPRESSION_SYNTAX) * 0 + 1;
    if (argc == 2) {
        sh_error_t error = sh_parse_int(argv[1], &code);

        if (error != SH_OK)
            return sh_perror(argv[0], error) * 0 + 1;
    }
    (void)ctx;
    *should_exit = 1;
    return (int)(unsigned char)code;
}
