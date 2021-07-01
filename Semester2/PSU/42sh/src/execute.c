/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Executes a token array
*/

#include "command.h"
#include "shell.h"

int sh_pipeline_execute(sh_ctx_t *ctx);

static sh_command_t *sh_pipeline_push(sh_ctx_t *ctx)
{
    sh_command_t *command;

    if (my_vec_reserve(&ctx->pipeline, 1) != MY_VEC_OK)
        return NULL;
    command = my_vec_get(&ctx->pipeline, ctx->pipeline.length++);
    sh_command_init(command);
    return command;
}

static int sh_exec_parse_pipes(
    sh_ctx_t *ctx, size_t tcount, sh_token_t tokens[tcount])
{
    size_t end;
    int ret;
    sh_pipe_pos_t pipe_pos = SH_PIPE_BEGIN;

    while (tcount > 0) {
        end = sh_token_find(tcount, tokens, SH_TOKEN_PIPE);
        ret = sh_command_parse(sh_pipeline_push(ctx), end, tokens,
            end == tcount ? SH_PIPE_END : pipe_pos);
        if (ret != 0)
            return ret;
        sh_token_advance(&tcount, &tokens, end);
        pipe_pos = SH_PIPE_MIDDLE;
        sh_token_consume(&tcount, &tokens, SH_TOKEN_PIPE);
    }
    return sh_pipeline_execute(ctx);
}

static int sh_exec_parse_logicals(
    sh_ctx_t *ctx, size_t token_count, sh_token_t tokens[token_count])
{
    int ret;
    size_t or;
    size_t and;
    size_t end;
    bool exec_next = 1;

    do {
        or = sh_token_find(token_count, tokens, SH_TOKEN_PIPE_PIPE);
        and = sh_token_find(token_count, tokens, SH_TOKEN_AND_AND);
        end = (or != 0 && and != 0) ? MY_MIN(or, and) : ((or == 0) ? and : or);
        if (exec_next)
            ret = sh_exec_parse_pipes(ctx, end, tokens);
        if (ret != 0)
            return ret;
        sh_token_advance(&token_count, &tokens, end);
        exec_next =
            ((ctx->exit_code && end == or) || (!ctx->exit_code && end == and));
        sh_token_consume(
            &token_count, &tokens, SH_TOKEN_PIPE_PIPE | SH_TOKEN_AND_AND);
    } while (end != 0);
    return 0;
}

static int sh_exec_parse_semicolons(
    sh_ctx_t *ctx, size_t token_count, sh_token_t tokens[token_count])
{
    size_t end;
    int ret;

    do {
        sh_token_consume_while(&token_count, &tokens, SH_TOKEN_SEMICOLON);
        end = sh_token_find(token_count, tokens, SH_TOKEN_SEMICOLON);
        ret = sh_exec_parse_logicals(ctx, end, tokens);
        if (ret != 0)
            return ret;
        sh_token_advance(&token_count, &tokens, end);
    } while (end != 0);
    return 0;
}

int sh_execute(
    sh_ctx_t *ctx, size_t token_count, sh_token_t tokens[token_count])
{
    sh_error_t err;
    int ret;

    err = sh_lint(token_count, tokens);
    if (err != SH_OK) {
        ctx->exit_code = 1;
        sh_perror(NULL, err);
        return ctx->is_tty ? 1 : -1;
    }
    ret = sh_exec_parse_semicolons(ctx, token_count, tokens);
    if (ret > 0)
        ctx->exit_code = 1;
    if (ctx->had_exit_cmd != -1)
        return (-1);
    return ret;
}
