/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_show
*/

#include <libmy/io.h>
#include <unistd.h>

#include "line_edit.h"

int sh_keybind_self_insert(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    int code = my_vec_insert(line, c, line_edit->pos);

    (void)stream;
    line_edit->pos++;
    sh_line_edit_update(line_edit, line);
    return code;
}
