/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_upper
*/

#include <libmy/ascii.h>

#include "token.h"
#include "line_edit.h"

int sh_keybind_upcase_word(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char *line_str = line->data;
    size_t word_end = line_edit->pos;

    (void)stream;
    (void)c;
    while (word_end < line->length && sh_is_arg_sep(line_str[word_end]))
        word_end++;
    while (word_end < line->length && !sh_is_arg_sep(line_str[word_end])) {
        line_str[word_end] = my_toupper(line_str[word_end]);
        word_end++;
    }
    line_edit->pos = word_end;
    sh_line_edit_update(line_edit, line);
    return 0;
}
