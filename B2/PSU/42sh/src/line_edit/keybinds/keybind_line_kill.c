/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_linestart
*/

#include "line_edit.h"

int sh_keybind_line_kill_before_cursor(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)stream;
    (void)c;
    my_vec_remove_multiple(line, NULL, 0, line_edit->pos);
    line_edit->pos = 0;
    sh_line_edit_update(line_edit, line);
    return 0;
}

int sh_keybind_line_kill_after_cursor(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)stream;
    (void)c;
    my_vec_clear_from(line, line_edit->pos, NULL);
    sh_line_edit_update(line_edit, line);
    return 0;
}

int sh_keybind_line_kill(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)stream;
    (void)c;
    my_vec_clear(line, NULL);
    line_edit->pos = 0;
    sh_line_edit_update(line_edit, line);
    return 0;
}
