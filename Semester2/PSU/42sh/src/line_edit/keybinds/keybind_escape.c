/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybind_escape
*/

#include "line_edit.h"

int sh_keybind_arrow(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char next_c;

    (void)c;
    if (my_fread(&next_c, sizeof(char), 1, stream) != 1)
        return -1;
    switch (next_c) {
        case 'D':
            return sh_keybind_move_left(line_edit, line, stream, &next_c);
        case 'C':
            return sh_keybind_move_right(line_edit, line, stream, &next_c);
        default: return 0;
    }
}

static void init_escape_keybinds(
    sh_line_edit_t *line_edit, sh_keybind_value_t *keybinds[256])
{
    for (int i = 0; i < 256; i++)
        keybinds[i] = sh_get_keybind(line_edit, "empty");
    keybinds[66] = sh_get_keybind(line_edit, "backward-word");
    keybinds[67] = sh_get_keybind(line_edit, "capitalize-word");
    keybinds[68] = sh_get_keybind(line_edit, "forward-delete-word");
    keybinds[70] = sh_get_keybind(line_edit, "forward-word");
    keybinds[76] = sh_get_keybind(line_edit, "downcase-word");
    keybinds[85] = sh_get_keybind(line_edit, "upcase-word");
    keybinds[91] = sh_get_keybind(line_edit, "arrows-sequence");
    keybinds[98] = sh_get_keybind(line_edit, "backward-word");
    keybinds[99] = sh_get_keybind(line_edit, "capitalize-word");
    keybinds[100] = sh_get_keybind(line_edit, "forward-delete-word");
    keybinds[102] = sh_get_keybind(line_edit, "forward-word");
    keybinds[108] = sh_get_keybind(line_edit, "downcase-word");
    keybinds[117] = sh_get_keybind(line_edit, "upcase-word");
    keybinds[127] = sh_get_keybind(line_edit, "backward-delete-word");
}

int sh_keybind_escape(
    sh_line_edit_t *line_edit, my_vec_t *line, my_iostream_t *stream, char *c)
{
    char next_c;

    (void)c;
    if (line_edit->escape_keybinds[0] == NULL)
        init_escape_keybinds(line_edit, line_edit->escape_keybinds);
    if (!stream || my_fread(&next_c, sizeof(char), 1, stream) != 1)
        return -1;
    return (*line_edit->escape_keybinds[(unsigned char)(next_c)]->fct)(
        line_edit, line, stream, &next_c);
}
