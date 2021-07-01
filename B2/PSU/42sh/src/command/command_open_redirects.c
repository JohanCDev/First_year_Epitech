/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Expands thens opens the input and output redirects
*/

#include <fcntl.h>
#include <unistd.h>

#include "command.h"

static bool sh_command_open_input_redirect(
    sh_ctx_t *ctx, sh_command_base_t *cmd)
{
    if (!sh_command_expand_redirect(ctx, &cmd->input, &cmd->input_type)) {
        ctx->exit_code = 1;
        return false;
    }
    cmd->pipe_in[0] = open(cmd->input, SH_INPUT_FLAGS);
    if (cmd->pipe_in[0] < 0) {
        ctx->exit_code = 1;
        return (bool)sh_rerror_errno(cmd->input, false);
    }
    return true;
}

static bool sh_command_open_output_redirect(
    sh_ctx_t *ctx, sh_command_base_t *cmd)
{
    if (!sh_command_expand_redirect(ctx, &cmd->output, &cmd->output_type)) {
        ctx->exit_code = 1;
        return false;
    }
    cmd->pipe_out[1] = open(cmd->output, SH_OUTPUT_FLAGS(cmd), SH_OUTPUT_MODE);
    if (cmd->pipe_out[1] < 0) {
        ctx->exit_code = 1;
        return (bool)sh_rerror_errno(cmd->output, false);
    }
    return true;
}

bool sh_command_open_redirects(
    sh_ctx_t *ctx, sh_command_t *c1, sh_command_t *c2)
{
    if (c1->base.input != NULL
        && !sh_command_open_input_redirect(ctx, &c1->base))
        return false;
    if (c1->base.output != NULL) {
        if (!sh_command_open_output_redirect(ctx, &c1->base))
            return false;
    } else if (c2 != NULL) {
        pipe(c1->base.pipe_out);
        c2->base.pipe_in[0] = c1->base.pipe_out[0];
        c2->base.pipe_in[1] = c1->base.pipe_out[1];
    }
    return true;
}
