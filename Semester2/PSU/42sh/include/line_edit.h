/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line_edition
*/

#ifndef LINE_EDITION_H_
#define LINE_EDITION_H_

#include <libmy/collections/vec.h>
#include <libmy/io.h>
#include <stdbool.h>
#include <sys/types.h>
#include <libmy/collections/hash_map.h>

#include "completion.h"
#include "keybinds.h"

struct sh_ctx;

typedef struct sh_keybind_value {
    keybind_t fct;
    char const *name;
} sh_keybind_value_t;

typedef struct sh_line_edit {
    my_vec_t *line_buf;
    size_t pos;
    bool is_eof;
    struct sh_ctx *ctx;
    /// A map of keybinds functions.
    /// Key type: string (char *, not allocated)
    /// Value type: sh_keybind_value_t
    my_hash_map_t keybinds_fcts;
    sh_keybind_value_t *keybinds[256];
    sh_keybind_value_t *escape_keybinds[256];
} sh_line_edit_t;

void sh_line_edit_init(sh_line_edit_t *line_edit, struct sh_ctx *ctx);
int sh_line_edit_reset(sh_line_edit_t *line_edit, my_vec_t *line_buf);
ssize_t sh_line_edit_fill(sh_line_edit_t *line_edit, my_iostream_t *stream);
void sh_line_edit_update(sh_line_edit_t *line_edit, my_vec_t *line_buf);

void sh_fill_keybinds_hashmap(sh_line_edit_t *line_edit);
sh_keybind_value_t *sh_get_keybind(
    sh_line_edit_t *line_edit, char const *name);

#endif /* !LINE_EDITION_H_ */
