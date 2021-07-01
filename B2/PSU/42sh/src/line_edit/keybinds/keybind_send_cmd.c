/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_send_cmd
*/

#include <libmy/io.h>
#include <unistd.h>

#include "line_edit.h"

int sh_keybind_send_cmd(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char end_char = '\n';

    (void)stream;
    (void)line_edit;
    (void)c;
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, &end_char, 1);
    return my_vec_push(line, &end_char);
}
