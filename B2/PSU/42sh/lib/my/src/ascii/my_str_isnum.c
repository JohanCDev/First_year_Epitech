/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Check whether string contains only digit characters
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_str_isnum(char const *str)
{
    if (!str)
        return 0;
    while (my_isdigit(*str))
        ++str;
    return !*str;
}
