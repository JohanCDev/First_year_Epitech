/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_capitalize_word
*/

#include <libmy/ascii.h>

#include "token.h"
#include "line_edit.h"

int sh_keybind_capitalize_word(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char *line_str = line->data;
    size_t word_start = line_edit->pos;

    (void)stream;
    (void)c;
    while (word_start < line->length && sh_is_arg_sep(line_str[word_start]))
        word_start++;
    if (word_start < line->length)
        line_str[word_start] = my_toupper(line_str[word_start]);
    return sh_keybind_forward_word(line_edit, line, stream, c);
}
