/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** bindkey
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libmy/collections/hash_map.h>

#include "builtin.h"
#include "shell.h"
#include "line_edit.h"

static char *get_char_code(char buff[3], int c)
{
    int i = 0;

    if (c < ' ') {
        buff[i++] = '^';
        buff[i++] = c + '@';
    }
    if (c == 127) {
        buff[i++] = '^';
        buff[i++] = '?';
    }
    if (i == 0)
        buff[i++] = c;
    buff[i] = 0;
    return buff;
}

static int print_keybinds(sh_line_edit_t *line_edit)
{
    keybind_t empty = &sh_keybind_empty;
    char buf[3];

    my_puts("Standard key bindings:\n");
    my_flush_stdout();
    for (int i = 0; i < 128; i++) {
        if (line_edit->keybinds[i]->fct == empty)
            continue;
        my_printf("%#s\t\t\t->  %s\n", get_char_code(buf, i),
            line_edit->keybinds[i]->name);
    }
    my_puts("\nEscape key bindings:\n");
    my_flush_stdout();
    for (int i = 0; i < 128; i++) {
        if (line_edit->escape_keybinds[i]->fct == empty)
            continue;
        my_printf("\"^[%s\"\t\t\t->  %s\n", get_char_code(buf, i),
            line_edit->escape_keybinds[i]->name);
    }
    return 0;
}

static bool get_key_sequence(int key[2], char const *arg, size_t len)
{
    if (!key[0]
        && ((!my_strncmp(arg, "^", 1) && len == 2)
            || (!my_strncmp(arg, "C-", 2) && len == 3))) {
        if (arg[len - 1] < '@' || arg[len - 1] > ']')
            return false;
        key[0] = arg[len - 1] - '@';
    }
    if (!key[0] && (!my_strncmp(arg, "M-", 2) && len == 3)) {
        key[0] = -1;
        key[1] = arg[len - 1];
    }
    return (key[0] || !my_strcmp(arg, "^@") || !my_strcmp(arg, "C-@"));
}

static bool get_key(int key[2], char const *arg)
{
    size_t len = my_strlen(arg);

    if (len > 3) {
        if (!my_strcmp(arg, "M-^?")) {
            key[0] = -1;
            key[1] = 127;
            return true;
        }
        return false;
    }
    if (len == 1)
        key[0] = arg[0];
    if (!my_strcmp(arg, "^?"))
        key[0] = 127;
    return get_key_sequence(key, arg, len);
}

int sh_builtin_bindkey(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    int key[2] = {0, 0};
    sh_keybind_value_t *value = NULL;

    (void)should_exit;
    if (argc == 1)
        return print_keybinds(&ctx->line_edit);
    if (argc != 3)
        return sh_rerror(
            argv[0], (argc < 3) ? SH_TOO_FEW_ARGS : SH_TOO_MANY_ARGS, 1);
    if (!get_key(key, argv[1]))
        return sh_rerror(argv[0], SH_UNKNOWN_KEY, 1);
    value = my_hash_map_get(&ctx->line_edit.keybinds_fcts, argv + 2);
    if (!value)
        return sh_rerror(argv[0], SH_UNKNOWN_KEYBIND_FUNCTION, 1);
    if (key[0] == -1)
        ctx->line_edit.escape_keybinds[key[1]] = value;
    else
        ctx->line_edit.keybinds[key[0]] = value;
    return 0;
}
