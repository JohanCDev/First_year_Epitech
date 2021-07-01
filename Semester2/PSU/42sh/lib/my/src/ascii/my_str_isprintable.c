/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Check whether string contains only printable characters
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_str_isprintable(char const *str)
{
    if (!str)
        return 0;
    while (my_isprint(*str))
        ++str;
    return !*str;
}
