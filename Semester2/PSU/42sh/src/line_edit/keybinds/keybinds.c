/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybinds
*/

#include <glob.h>
#include <libmy/ascii.h>
#include <limits.h>
#include <unistd.h>

#include "line_edit.h"

static void init_keybinds(
    sh_line_edit_t *line_edit, sh_keybind_value_t *keybinds[256])
{
    sh_fill_keybinds_hashmap(line_edit);
    for (int i = 0; i < 256; i++)
        keybinds[i] = (my_isprint(i) || i > 127)
            ? sh_get_keybind(line_edit, "self-insert")
            : sh_get_keybind(line_edit, "empty");
    keybinds[1] = sh_get_keybind(line_edit, "line-start");
    keybinds[2] = sh_get_keybind(line_edit, "backward-char");
    keybinds[4] = sh_get_keybind(line_edit, "raise-eof");
    keybinds[5] = sh_get_keybind(line_edit, "line-end");
    keybinds[6] = sh_get_keybind(line_edit, "forward-char");
    keybinds[8] = sh_get_keybind(line_edit, "backward-delete-char");
    keybinds[9] = sh_get_keybind(line_edit, "complete");
    keybinds[11] = sh_get_keybind(line_edit, "line-kill-after-cursor");
    keybinds[12] = sh_get_keybind(line_edit, "clear-screen");
    keybinds[21] = sh_get_keybind(line_edit, "line-kill");
    keybinds[23] = sh_get_keybind(line_edit, "line-kill-before-cursor");
    keybinds[127] = sh_get_keybind(line_edit, "backward-delete-char");
    keybinds['\n'] = sh_get_keybind(line_edit, "send-cmd");
    keybinds[27] = sh_get_keybind(line_edit, "escape-sequence");
}

int sh_exec_keybind(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    int code;

    if (!line_edit->keybinds[0])
        init_keybinds(line_edit, line_edit->keybinds);
    if (!c)
        return 0;
    code = (*line_edit->keybinds[(unsigned char)(*c)]->fct)(
        line_edit, line, stream, c);
    return code;
}
