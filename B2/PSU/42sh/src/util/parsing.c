/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parsing functions
*/

#include <libmy/ascii/character.h>

#include "shell.h"

sh_error_t sh_parse_int(char const *str, int *result)
{
    int negate = 0;

    if (!*str)
        return SH_BAD_NUMBER;
    if (*str == '-') {
        if (*(++str) == '-')
            return SH_BAD_NUMBER;
        negate = 1;
    }
    *result = 0;
    while (*str) {
        if (!my_isdigit(*str))
            return SH_BAD_NUMBER;
        *result = *result * 10 + (int)(*str - '0');
        ++str;
    }
    if (negate)
        *result = -*result;
    return 0;
}
