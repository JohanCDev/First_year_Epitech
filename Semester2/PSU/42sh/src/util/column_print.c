/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Prints entries in multiple columns if possible
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>
#include <sys/ioctl.h>

#include "util.h"

static void sh_column_print_formatted(unsigned width, size_t entry_count,
    char const **entries, my_iostream_t *out)
{
    size_t len;
    size_t max_size = 0;
    size_t pos;
    size_t i;

    for (i = 0; i < entry_count; ++i) {
        len = my_strlen(entries[i]) + 1;
        max_size = MY_MAX(max_size, len);
    }
    pos = max_size;
    for (i = 0; i + 1 < entry_count; ++i) {
        pos += max_size;
        if (pos > width) {
            my_fputs_endl(entries[i], out);
            pos = max_size;
        } else {
            my_fprintf(out, "%-*s", max_size, entries[i]);
        }
    }
    if (i < entry_count)
        my_fputs_endl(entries[i], out);
}

void sh_column_print(
    bool is_tty, size_t entry_count, char const **entries, my_iostream_t *out)
{
    struct winsize size;

    if (!is_tty || ioctl(0, TIOCGWINSZ, &size) == -1)
        sh_column_print_formatted(0, entry_count, entries, out);
    else
        sh_column_print_formatted(size.ws_col, entry_count, entries, out);
}
