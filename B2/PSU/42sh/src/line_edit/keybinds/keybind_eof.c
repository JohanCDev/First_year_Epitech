/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_eof
*/

#include "line_edit.h"

int sh_keybind_eof(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)line;
    (void)stream;
    (void)c;
    line_edit->is_eof = true;
    return 0;
}
