/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** path_completion
*/

#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <stdlib.h>

#include "completion.h"
#include "context.h"
#include "token.h"

void sh_append_completion_list(
    glob_t *globbuf, char *prefix, char *word, bool first)
{
    int flags = GLOB_TILDE | GLOB_MARK;
    bool need_sep = (prefix && prefix[my_strlen(prefix) - 1] != '/' && word
        && word[0] != '/');
    size_t pattern_len = my_strlen(prefix) + my_strlen(word) + 2 + need_sep;
    char pattern[pattern_len];

    if (!prefix || !word)
        return;
    my_memset(pattern, 0, pattern_len);
    my_strcpy(pattern, prefix);
    if (need_sep)
        my_strcat(pattern, "/");
    my_strcat(pattern, word);
    my_strcat(pattern, "*");
    if (!first)
        flags |= GLOB_APPEND;
    globbuf->gl_offs = 0;
    glob(pattern, flags, NULL, globbuf);
}

void sh_fill_completion_list(sh_ctx_t *ctx, glob_t *globbuf, char *word)
{
    char **paths = ctx->path.data;

    if (!word)
        word = "";
    if (word[0] == '/') {
        sh_append_completion_list(globbuf, "", word, true);
        return;
    }
    sh_append_completion_list(globbuf, "./", word, true);
    if (!word[0] || sh_is_arg_sep(word[0]) || word[0] == '~'
        || my_strncmp(word, "./", 2) == 0 || my_strncmp(word, "../", 3) == 0)
        return;
    for (size_t i = 0; i < ctx->path.length; i++)
        sh_append_completion_list(globbuf, paths[i], word, false);
}

void sh_line_edit_fill_completion_list(sh_line_edit_t *line_edit,
    my_vec_t *line, glob_t *globbuf, bool apply_completion)
{
    char *line_str = (line->data) ? line->data : " ";
    char *str;
    size_t word_start = line_edit->pos - (line_edit->pos > 0);

    if (sh_is_arg_sep(line_str[word_start])) {
        sh_fill_completion_list(line_edit->ctx, globbuf, NULL);
        return;
    }
    while (word_start > 0 && !sh_is_arg_sep(line_str[word_start]))
        word_start--;
    word_start += sh_is_arg_sep(line_str[word_start]);
    str = my_calloc(sizeof(char), line_edit->pos - word_start + 1);
    my_memcpy(str, line_str + word_start, line_edit->pos - word_start);
    sh_fill_completion_list(line_edit->ctx, globbuf, str);
    if (apply_completion)
        sh_line_edit_apply_completion(line_edit, line, globbuf, str);
    free(str);
}
