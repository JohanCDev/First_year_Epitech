/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_delete
*/

#include <unistd.h>
#include <libmy/collections/vec.h>

#include "line_edit.h"

int sh_keybind_delete(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    if (line_edit->pos == 0)
        return 0;
    (void)stream;
    (void)c;
    my_vec_remove(line, NULL, line_edit->pos - 1);
    line_edit->pos--;
    sh_line_edit_update(line_edit, line);
    return 0;
}
