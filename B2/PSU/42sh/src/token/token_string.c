/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses string tokens
*/

#include <stdlib.h>

#include "token.h"

static ssize_t sh_token_unquoted_string_copy(
    sh_token_stream_t *stream, my_vec_t *str, bool *escaped)
{
    size_t buf_len = stream->line_buf.length;
    size_t len = 0;
    char c;
    bool escape = 0;

    --stream->line_pos;
    my_vec_init(str, sizeof(char));
    *escaped = stream->line_pos < buf_len
        && *SH_STREAM_CURRENT(stream, 0) == SH_INHIBITOR;
    for (; stream->line_pos + len < buf_len; ++len) {
        c = *SH_STREAM_CURRENT(stream, len);
        if (!escape && (sh_is_arg_sep(c) || sh_is_token_char(c)))
            break;
        if ((c != SH_INHIBITOR || escape)
            && my_vec_push(str, &c) != MY_VEC_OK) {
            my_vec_free(str, NULL);
            return -1;
        }
        escape = (c == SH_INHIBITOR) && !escape;
    }
    return len;
}

int sh_token_unquoted_string(sh_token_stream_t *stream, sh_token_t *token)
{
    my_vec_t str;
    bool escaped;
    ssize_t len = sh_token_unquoted_string_copy(stream, &str, &escaped);
    char c = '\0';

    if (len < 0 || my_vec_push(&str, &c) != MY_VEC_OK) {
        my_vec_free(&str, NULL);
        return 1;
    }
    if (escaped)
        *token = (sh_token_t){.type = SH_TOKEN_ESCAPED_NAME, .str = str.data};
    else
        *token = (sh_token_t){.type = SH_TOKEN_UNQUOTED_STR, .str = str.data};
    stream->line_pos += len;
    return 0;
}
