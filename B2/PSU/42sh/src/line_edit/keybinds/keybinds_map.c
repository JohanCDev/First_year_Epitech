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

static void sh_keybind_add(
    my_hash_map_t *map, keybind_t keybind, char const *name)
{
    sh_keybind_value_t value;

    value.fct = keybind;
    value.name = name;
    my_hash_map_insert(map, &name, &value);
}

static void sh_fill_keybinds_hashmap_3(sh_line_edit_t *line_edit)
{
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_downcase_word, "downcase-word");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_upcase_word, "upcase-word");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_arrow, "arrows-sequence");
    sh_keybind_add(&line_edit->keybinds_fcts, &sh_keybind_delete_backward_word,
        "backward-delete-word");
}

static void sh_fill_keybinds_hashmap_2(sh_line_edit_t *line_edit)
{
    sh_keybind_add(&line_edit->keybinds_fcts,
        &sh_keybind_line_kill_after_cursor, "line-kill-after-cursor");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_clear_screen, "clear-screen");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_line_kill, "line-kill");
    sh_keybind_add(&line_edit->keybinds_fcts,
        &sh_keybind_line_kill_before_cursor, "line-kill-before-cursor");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_send_cmd, "send-cmd");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_escape, "escape-sequence");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_backward_word, "backward-word");
    sh_keybind_add(&line_edit->keybinds_fcts, &sh_keybind_capitalize_word,
        "capitalize-word");
    sh_keybind_add(&line_edit->keybinds_fcts, &sh_keybind_delete_next_word,
        "forward-delete-word");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_forward_word, "forward-word");
}

void sh_fill_keybinds_hashmap(sh_line_edit_t *line_edit)
{
    sh_keybind_add(&line_edit->keybinds_fcts, &sh_keybind_empty, "empty");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_self_insert, "self-insert");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_line_start, "line-start");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_move_left, "backward-char");
    sh_keybind_add(&line_edit->keybinds_fcts, &sh_keybind_eof, "raise-eof");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_line_end, "line-end");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_move_right, "forward-char");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_delete, "backward-delete-char");
    sh_keybind_add(
        &line_edit->keybinds_fcts, &sh_keybind_tty_complete, "complete");
    sh_keybind_add(&line_edit->keybinds_fcts,
        &sh_keybind_line_kill_after_cursor, "line-kill-after-cursor");
    sh_fill_keybinds_hashmap_2(line_edit);
    sh_fill_keybinds_hashmap_3(line_edit);
}

sh_keybind_value_t *sh_get_keybind(sh_line_edit_t *line_edit, char const *name)
{
    return my_hash_map_get(&line_edit->keybinds_fcts, &name);
}
