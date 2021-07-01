/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints memory in a neat way
*/

#include <limits.h>
#include "libmy/io.h"

static const char *HEXADECIMAL_BASE = "0123456789abcdef";

static void show_offset(unsigned int offset)
{
    unsigned int power = UINT_MAX / 16;

    while (power != 0) {
        my_putchar(HEXADECIMAL_BASE[offset / power % 16]);
        power /= 16;
    }
    my_putchar(HEXADECIMAL_BASE[offset % 16]);
}

static void show_byte(char const *str, int pos, int size)
{
    if (pos >= size) {
        my_putchar(' ');
        my_putchar(' ');
    } else {
        my_putchar(HEXADECIMAL_BASE[((unsigned char)str[pos]) / 16]);
        my_putchar(HEXADECIMAL_BASE[((unsigned char)str[pos]) % 16]);
    }
}

static void show_line(char const *str, int offset, int size)
{
    show_offset(offset);
    my_putchar(':');
    my_putchar(' ');
    for (int i = offset; i < offset + 16; ++i) {
        show_byte(str, i, size);
        if (i & 1)
            my_putchar(' ');
    }
    for (int i = offset; i < offset + 16; ++i) {
        if (i < size && (str[i] < ' ' || str[i] > '~'))
            my_putchar('.');
        else if (i < size)
            my_putchar(str[i]);
    }
    my_putchar('\n');
}

MY_IO_API int my_showmem(char const *str, int size)
{
    int aligned_size;

    if (!str || size <= 0)
        return -1;
    aligned_size = size & (~0xf);
    if (aligned_size != size)
        aligned_size += 16;
    for (int offset = 0; offset < aligned_size; offset += 16)
        show_line(str, offset, size);
    return 0;
}
