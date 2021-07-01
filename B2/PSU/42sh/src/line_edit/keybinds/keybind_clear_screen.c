/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_clear_screen
*/

#include <unistd.h>

#include "line_edit.h"

int sh_keybind_clear_screen(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    const char *clear_screen_ansi = "\e[1;1H\e[2J";

    (void)stream;
    (void)c;
    write(STDOUT_FILENO, clear_screen_ansi, 11);
    sh_line_edit_update(line_edit, line);
    return 0;
}
