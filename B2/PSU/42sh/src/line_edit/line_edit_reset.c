/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line_edit_init
*/

#include <libmy/io.h>
#include <libmy/printf.h>
#include <stdalign.h>
#include <stdio.h>
#include <unistd.h>

#include "shell.h"

static const my_map_kvtypes_t SH_KEYBINDS_MAP_KVTYPES = {
    .key_size = sizeof(char *),
    .key_align = alignof(char *),
    .value_size = sizeof(sh_keybind_value_t),
    .value_align = alignof(sh_keybind_value_t),
    .compare = MY_HASH_MAP_CSTR_CMP,
    .hash = MY_HASH_MAP_CSTR_HASH,
};

void sh_line_edit_init(sh_line_edit_t *line_edit, struct sh_ctx *ctx)
{
    line_edit->ctx = ctx;
    line_edit->keybinds[0] = NULL;
    line_edit->escape_keybinds[0] = NULL;
    my_hash_map_init(&line_edit->keybinds_fcts, &SH_KEYBINDS_MAP_KVTYPES);
    sh_exec_keybind(line_edit, NULL, NULL, NULL);
    sh_keybind_escape(line_edit, NULL, NULL, NULL);
}

int sh_line_edit_reset(sh_line_edit_t *line_edit, my_vec_t *line_buf)
{
    line_edit->line_buf = line_buf;
    line_edit->pos = 0;
    line_edit->is_eof = my_feof(line_edit->ctx->input);
    return 0;
}

void sh_line_edit_update(sh_line_edit_t *line_edit, my_vec_t *line_buf)
{
    size_t back_steps_write = line_buf->length - line_edit->pos;
    char back_buff_aft_write[back_steps_write];
    char tmp[] = "\x1b[2K\r";

    if (!isatty(STDIN_FILENO))
        return;
    write(STDOUT_FILENO, tmp, 5);
    sh_print_prompt(line_edit->ctx);
    write(STDOUT_FILENO, line_buf->data, line_buf->length);
    for (size_t i = 0; i < back_steps_write; i++)
        back_buff_aft_write[i] = '\b';
    write(STDOUT_FILENO, back_buff_aft_write, back_steps_write);
}
