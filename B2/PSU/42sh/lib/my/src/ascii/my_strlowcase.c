/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Lowercases the given string
*/

#include "libmy/ascii.h"

MY_ASCII_API char *my_strlowcase(char *str)
{
    if (!str)
        return str;
    for (char *s = str; *s; ++s)
        *s = my_tolower(*s);
    return str;
}
