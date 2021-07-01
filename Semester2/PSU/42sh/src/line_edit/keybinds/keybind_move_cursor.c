/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_move_cursor
*/

#include <libmy/collections/vec.h>
#include <unistd.h>

#include "line_edit.h"

int sh_keybind_move_left(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char backspace = '\b';

    if (line_edit->pos == 0)
        return 0;
    (void)stream;
    (void)c;
    (void)line;
    line_edit->pos--;
    write(STDOUT_FILENO, &backspace, 1);
    return 0;
}

int sh_keybind_move_right(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char c_replace = MY_VEC_GET_ELEM(char, line, line_edit->pos);

    if (line_edit->pos >= line->length || c_replace == 0)
        return 0;
    (void)stream;
    (void)c;
    line_edit->pos++;
    write(STDOUT_FILENO, &c_replace, 1);
    return 0;
}
