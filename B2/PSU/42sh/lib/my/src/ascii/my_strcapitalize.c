/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Capitalizes the given string
*/

#include "libmy/ascii.h"

static char capitalize_char(char c, int word_start)
{
    if (word_start)
        return my_toupper(c);
    return my_tolower(c);
}

MY_ASCII_API char *my_strcapitalize(char *str)
{
    int word_start = 1;

    if (!str)
        return str;
    for (char *s = str; *s; ++s) {
        if (my_isalpha(*s)) {
            *s = capitalize_char(*s, word_start);
            word_start = 0;
        } else if (*s >= '0' && *s <= '9') {
            word_start = 0;
        } else {
            word_start = 1;
        }
    }
    return str;
}
