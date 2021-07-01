/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses string tokens
*/

#include <assert.h>
#include <libmy/memory/alloc.h>
#include <libmy/printf.h>
#include <stdlib.h>

#include "token.h"

static size_t sh_token_quoted_string_get_len(
    char *src, size_t src_len, char *end)
{
    size_t len = src_len;
    bool inhibitor = false;
    bool skip_quotes;

    assert(src != NULL);
    skip_quotes = !sh_is_arg_quote(*end);
    for (size_t i = 0; i < len; i++) {
        inhibitor = (src[i] == SH_INHIBITOR) && !inhibitor;
        len -= (inhibitor && len && sh_is_arg_inhibitable(src[i]));
        if (!inhibitor && skip_quotes && sh_is_arg_quote(src[i]))
            len--;
    }
    return len;
}

static char *sh_token_quoted_string_copy(char *src, size_t src_len, char *end)
{
    size_t len = sh_token_quoted_string_get_len(src, src_len, end);
    char *str = NULL;
    bool inhibitor = false;
    bool skip_quotes = !sh_is_arg_quote(*end);

    if (len == 0)
        return NULL;
    str = malloc(sizeof(char) * len);
    if (!str)
        return NULL;
    len = 0;
    for (size_t i = 0; i < src_len; i++) {
        inhibitor = (src[i] == SH_INHIBITOR) && !inhibitor;
        if ((inhibitor && sh_is_arg_inhibitable(src[i]))
            || (!inhibitor && skip_quotes && sh_is_arg_quote(src[i])))
            continue;
        str[len++] = src[i];
    }
    str[len - 1] = 0;
    return str;
}

static bool is_char_token_end(
    char *str, char term, size_t i, bool *found_quote)
{
    if (*found_quote)
        return sh_is_arg_sep(str[i]);
    if (str[i] == term) {
        *found_quote = true;
        return sh_is_arg_sep(str[i + 1])
            || (sh_is_token_char(str[i + 1]) && !sh_is_arg_quote(str[i + 1]));
    }
    return false;
}

static char *sh_token_quoted_string_get_end(char *str, char term, size_t len)
{
    bool inhibitor = false;
    bool found_quote = false;

    if (str == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        if (!inhibitor && is_char_token_end(str, term, i, &found_quote))
            return str + i;
        inhibitor = (str[i] == SH_INHIBITOR) && !inhibitor;
    }
    if (found_quote)
        return str + len;
    return NULL;
}

int sh_token_quoted_string(
    sh_token_stream_t *stream, sh_token_t *token, char term)
{
    char *end = sh_token_quoted_string_get_end(
        SH_STREAM_CURRENT(stream, 0), term, SH_STREAM_CURRENT_LEN(stream));
    size_t len;
    sh_token_type_t type =
        term == '"' ? SH_TOKEN_DOUBLE_STR : SH_TOKEN_SINGLE_STR;

    if (end == NULL) {
        my_fprintf(MY_STDERR, "Unmatched '%c'.\n", term);
        my_flush_stderr();
        return 1;
    }
    len = (end - SH_STREAM_CURRENT(stream, 0)) + 1;
    *token = (sh_token_t){.type = type,
        .str = sh_token_quoted_string_copy(
            SH_STREAM_CURRENT(stream, 0), len, end)};
    if (token->str == NULL)
        return 1;
    stream->line_pos += len;
    return 0;
}
