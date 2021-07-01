/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Executes the given external command
*/

#include <assert.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <libmy/io.h>
#include <libmy/printf.h>

#include "command.h"
#include "shell.h"
#include "util.h"

static void sh_run_child(sh_ctx_t *ctx, char const *path, char const *argv[])
{
    execve(path, (char *const *)argv, ctx->env.data);
    if (errno == ENOEXEC) {
        my_fprintf(MY_STDERR, "%s: Exec format error. Wrong Architecture.\n",
            argv[0]);
        my_flush_stderr();
    } else
        sh_perror_errno(argv[0]);
    exit(1);
}

int sh_execute_external_impl(sh_ctx_t *ctx, sh_external_command_t *command)
{
    pid_t child_pid = fork();
    int status;

    if (child_pid < 0) {
        return 1;
    } else if (child_pid == 0) {
        if (command->base.pipe_in[0] != -1)
            dup2(command->base.pipe_in[0], STDIN_FILENO);
        if (command->base.pipe_out[1] != -1)
            dup2(command->base.pipe_out[1], STDOUT_FILENO);
        sh_sclose_pipe(command->base.pipe_in);
        sh_sclose_pipe(command->base.pipe_out);
        sh_run_child(ctx, command->path, command->base.args.data);
    }
    sh_sclose_pipe(command->base.pipe_in);
    if (command->base.pipe_pos == SH_PIPE_END)
        do {
            waitpid(child_pid, &status, 0);
        } while (sh_handle_status(ctx, status));
    return 0;
}

int sh_execute_external(sh_ctx_t *ctx, sh_external_command_t *command)
{
    if (access(command->path, X_OK | R_OK) < 0) {
        ctx->exit_code = 1;
        return sh_rerror_errno(command->path, 0);
    }
    return sh_execute_external_impl(ctx, command);
}
