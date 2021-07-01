/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line_edit_fill
*/

#include "line_edit.h"

void my_getdelim_alloc_vec(
    my_vec_t *linevec, char *line, size_t alloc_size);

ssize_t my_getdelim_add_null_byte(my_vec_t *line, ssize_t ret);

ssize_t sh_getdelim_read(sh_line_edit_t *line_edit, my_vec_t *line, char delim,
    my_iostream_t *stream)
{
    char c;

    while (my_fread(&c, sizeof(char), 1, stream) == 1 && !line_edit->is_eof) {
        if (sh_exec_keybind(line_edit, line, stream, &c) != 0)
            return -1;
        if (line_edit->is_eof || c == delim)
            return line->length;
    }
    if (my_feof(stream))
        return line->length;
    return -1;
}

ssize_t sh_line_edit_fill(sh_line_edit_t *line_edit, my_iostream_t *stream)
{
    my_vec_t linevec;
    ssize_t ret = -1;

    if (&line_edit->line_buf->data == NULL
        || &line_edit->line_buf->capacity == NULL)
        return -1;
    my_getdelim_alloc_vec(&linevec, (char *)line_edit->line_buf->data,
        line_edit->line_buf->capacity);
    if (!my_feof(stream)) {
        ret = sh_getdelim_read(line_edit, &linevec, '\n', stream);
        ret = my_getdelim_add_null_byte(&linevec, ret);
    }
    line_edit->line_buf->capacity = linevec.capacity;
    line_edit->line_buf->data = linevec.data;
    return ret;
}
