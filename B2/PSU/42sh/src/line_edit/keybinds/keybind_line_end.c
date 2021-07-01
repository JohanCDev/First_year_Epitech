/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_linestart
*/

#include "line_edit.h"

int sh_keybind_line_end(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)line;
    (void)stream;
    (void)c;
    line_edit->pos = line->length;
    sh_line_edit_update(line_edit, line);
    return 0;
}
