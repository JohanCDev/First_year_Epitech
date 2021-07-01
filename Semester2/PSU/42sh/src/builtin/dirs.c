/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The dirs builtin
*/

#include <libmy/printf.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "shell.h"

void sh_dirs_run(sh_ctx_t *ctx, sh_dirs_options_t options)
{
    char *cwd = sh_get_cwd();

    if (!cwd || options == 0) {
        free(cwd);
        return;
    }
    if (options & SH_DIRS_FULL)
        my_printf("%-7d %s\n", 0, cwd);
    else
        my_puts_endl(cwd);
    (void)ctx;
}

int sh_builtin_dirs(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    my_fprintf(MY_STDERR, "%s: Not yet implemented.\n");
    (void)ctx;
    (void)should_exit;
    (void)argc;
    (void)argv;
    return 1;
}
