/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Executes the given builtin command
*/

#include <libmy/io.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "builtin.h"
#include "command.h"
#include "shell.h"
#include "util.h"

int sh_execute_builtin_fork_run(sh_ctx_t *ctx, sh_builtin_command_t *command)
{
    int ret;

    if (command->base.pipe_out[1] != -1)
        dup2(command->base.pipe_out[1], STDOUT_FILENO);
    sh_sclose_pipe(command->base.pipe_in);
    sh_sclose_pipe(command->base.pipe_out);
    ret = (*command->builtin->run)(
        ctx, &ret, command->base.args.length - 1, command->base.args.data);
    my_flush_stdout();
    my_flush_stderr();
    exit(ret);
}

int sh_execute_builtin_fork(sh_ctx_t *ctx, sh_builtin_command_t *command)
{
    pid_t child_pid = fork();
    int status;

    if (child_pid < 0)
        return 1;
    else if (child_pid == 0)
        sh_execute_builtin_fork_run(ctx, command);
    sh_sclose_pipe(command->base.pipe_in);
    if (command->base.pipe_pos == SH_PIPE_END)
        do {
            waitpid(child_pid, &status, 0);
        } while (sh_handle_status(ctx, status));
    return 0;
}

int sh_execute_builtin(sh_ctx_t *ctx, sh_builtin_command_t *command)
{
    int should_exit = 0;

    if (command->base.pipe_out[1] != -1)
        return sh_execute_builtin_fork(ctx, command);
    ctx->exit_code = (*command->builtin->run)(ctx, &should_exit,
        command->base.args.length - 1, command->base.args.data);
    if (should_exit && command->builtin->run == &sh_builtin_exit) {
        ctx->had_exit_cmd = should_exit;
        should_exit = 0;
    }
    my_flush_stdout();
    my_flush_stderr();
    if (should_exit)
        return -1;
    return 0;
}
