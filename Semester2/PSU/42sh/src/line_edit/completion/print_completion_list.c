/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** print_completion_list
*/

#include <glob.h>
#include <libmy/ascii.h>
#include <libmy/printf.h>

#include "context.h"
#include "util.h"
#include "line_edit.h"

char *sh_get_path_end(char *path)
{
    size_t i = 0;
    char *end = path;
    size_t len = my_strlen(path);

    if (!path)
        return NULL;
    while (path[i] && i != len - 1) {
        if (path[i] == '/')
            end = path + i + 1;
        i++;
    }
    return end;
}

char *sh_get_completion_entry(glob_t *globbuf, size_t index)
{
    return sh_get_path_end(globbuf->gl_pathv[index]);
}

static bool sh_is_entry_duplicate(glob_t *globbuf, size_t index, char *entry)
{
    char *other;

    for (size_t i = 0; i < index; i++) {
        other = sh_get_completion_entry(globbuf, i);
        if (my_strcmp(entry, other) == 0)
            return true;
    }
    return false;
}

static char *sh_get_next_completion_entry(glob_t *globbuf, size_t *index)
{
    char *entry = sh_get_completion_entry(globbuf, *index);
    bool is_duplicate = sh_is_entry_duplicate(globbuf, *index, entry);

    while (is_duplicate && *index < globbuf->gl_pathc - 1) {
        (*index)++;
        entry = sh_get_completion_entry(globbuf, *index);
        is_duplicate = sh_is_entry_duplicate(globbuf, *index, entry);
    }
    return (is_duplicate) ? NULL : entry;
}

void sh_print_completion_list(
    sh_line_edit_t *line_edit, my_vec_t *line, bool apply)
{
    glob_t buf;
    my_vec_t entries;

    sh_line_edit_fill_completion_list(line_edit, line, &buf, apply);
    if (buf.gl_pathc <= 1) {
        globfree(&buf);
        return;
    }
    my_putc('\n');
    my_vec_init(&entries, sizeof(char *));
    my_flush_stdout();
    for (size_t i = 0; i < buf.gl_pathc; i++) {
        if (sh_get_next_completion_entry(&buf, &i))
            my_vec_push(&entries, sh_get_completion_entry(&buf, i));
    }
    sh_column_print(
        line_edit->ctx->is_tty, entries.length, entries.data, MY_STDOUT);
    my_vec_free(&entries, NULL);
    sh_line_edit_update(line_edit, line);
    globfree(&buf);
}
