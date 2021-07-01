/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Executes a token array
*/

#include <libmy/ascii.h>
#include <libmy/printf.h>

#include "shell.h"

static int sh_lint_redirects(size_t token_count,
    sh_token_t tokens[token_count], sh_error_t *err,
    sh_token_type_t token_type)
{
    bool has_redirect = false;
    int token_types = token_type | (token_type << 1);

    while (token_count > 0) {
        bool new_redirect =
            sh_token_consume_until(&token_count, &tokens, token_types);

        if (sh_token_consume(&token_count, &tokens, token_types)
            && !sh_token_consume(&token_count, &tokens, SH_STRING_TOKENS))
            return sh_serror(err, SH_MISSING_REDIRECT_NAME, -1);
        if (has_redirect && new_redirect)
            return 2;
        has_redirect |= new_redirect;
    }
    return (int)has_redirect;
}

static bool sh_lint_pipes(
    size_t tcount, sh_token_t tokens[tcount], sh_error_t *err)
{
    size_t old_tcount = tcount;
    size_t end;
    int input_count;
    int output_count;

    while (tcount > 0) {
        end = sh_token_find(tcount, tokens, SH_TOKEN_PIPE);
        input_count = sh_lint_redirects(end, tokens, err, SH_TOKEN_LT);
        output_count = sh_lint_redirects(end, tokens, err, SH_TOKEN_GT);
        if (input_count < 0 || output_count < 0)
            return false;
        if (input_count > 1 || (input_count == 1 && old_tcount != tcount))
            return sh_serror(err, SH_AMBIGUOUS_INPUT_REDIRECT, false);
        if (output_count + (end < tcount) > 1)
            return sh_serror(err, SH_AMBIGUOUS_OUTPUT_REDIRECT, false);
        sh_token_advance(&tcount, &tokens, end);
        if (sh_token_consume(&tcount, &tokens, SH_TOKEN_PIPE) && tcount == 0)
            return sh_serror(err, SH_INVALID_NULL_COMMAND, false);
    }
    return true;
}

sh_error_t sh_lint(size_t token_count, sh_token_t tokens[token_count])
{
    size_t end;

    while (token_count != 0) {
        sh_error_t err;

        sh_token_consume_while(&token_count, &tokens, SH_TOKEN_SEMICOLON);
        end = sh_token_find(token_count, tokens, SH_TOKEN_SEMICOLON);
        if (!sh_lint_pipes(end, tokens, &err))
            return err;
        sh_token_advance(&token_count, &tokens, end);
    }
    return SH_OK;
}
