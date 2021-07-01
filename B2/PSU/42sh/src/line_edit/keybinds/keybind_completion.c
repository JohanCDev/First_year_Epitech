/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_completion
*/

#include <unistd.h>

#include "line_edit.h"

int sh_keybind_complete(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    (void)c;
    (void)stream;
    sh_print_completion_list(line_edit, line, true);
    return 0;
}

int sh_keybind_tty_complete(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    if (isatty(STDIN_FILENO))
        sh_print_completion_list(line_edit, line, true);
    else
        sh_keybind_self_insert(line_edit, line, stream, c);
    return 0;
}
