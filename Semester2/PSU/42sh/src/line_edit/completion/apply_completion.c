/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** apply_completion
*/

#include <libmy/ascii.h>

#include "line_edit.h"
#include "token.h"

static bool can_get_next_common_char(
    glob_t *globbuf, size_t index, char *next_char)
{
    char *str;

    *next_char = 0;
    for (size_t i = 0; i < globbuf->gl_pathc; i++) {
        str = sh_get_completion_entry(globbuf, i);
        if (my_strlen(str) <= index)
            return false;
        if (!*next_char)
            *next_char = str[index];
        if (str[index] != *next_char)
            return false;
    }
    return (globbuf->gl_pathc > 0);
}

void sh_line_edit_apply_completion(
    sh_line_edit_t *line_edit, my_vec_t *line, glob_t *globbuf, char *word)
{
    char next_char = 0;
    size_t start;

    word = sh_get_path_end(word);
    if (!word)
        return;
    start = my_strlen(word);
    while (can_get_next_common_char(globbuf, start, &next_char)) {
        if (sh_is_arg_sep(next_char))
            sh_keybind_self_insert(line_edit, line, NULL, "\\");
        sh_keybind_self_insert(line_edit, line, NULL, &next_char);
        start++;
    }
}
