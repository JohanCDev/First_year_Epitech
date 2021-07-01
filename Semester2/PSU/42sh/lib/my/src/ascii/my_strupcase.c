/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Uppercases the given string
*/

#include "libmy/ascii.h"

MY_ASCII_API char *my_strupcase(char *str)
{
    if (!str)
        return str;
    for (char *s = str; *s; ++s)
        *s = my_toupper(*s);
    return str;
}
