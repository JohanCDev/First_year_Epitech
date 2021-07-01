/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Handles the exit status of a process
*/

#include <libmy/io.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

static void sh_print_signal(int signum)
{
    if (signum == SIGFPE)
        my_eputs("Floating exception");
    else
        my_eputs(strsignal(signum));
}

int sh_handle_status(sh_ctx_t *ctx, int status)
{
    if (WIFEXITED(status)) {
        ctx->exit_code = WEXITSTATUS(status);
        return 0;
    } else if (WIFSIGNALED(status)) {
        sh_print_signal(WTERMSIG(status));
        if (WCOREDUMP(status))
            my_eputs(" (core dumped)");
        my_eputc('\n');
        my_flush_stderr();
        return 0;
    }
    return 1;
}
