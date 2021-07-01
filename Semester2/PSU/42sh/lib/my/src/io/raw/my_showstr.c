/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints the string, displaying non-printable characters
*/

#include "libmy/io.h"

static const char *BASE_HEXADECIMAL = "0123456789abcdef";

static void display_non_printable_char(char c)
{
    my_putchar('\\');
    my_putchar(BASE_HEXADECIMAL[(int)c / 16]);
    my_putchar(BASE_HEXADECIMAL[(int)c % 16]);
}

MY_IO_API int my_showstr(char const *str)
{
    if (!str)
        return -1;
    while (*str) {
        if (*str < ' ' || *str > '~')
            display_non_printable_char(*str);
        else
            my_putchar(*str);
        ++str;
    }
    return 0;
}
