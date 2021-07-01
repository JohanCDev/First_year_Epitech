/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Check whether string contains only lower-case alphabetical characters
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_str_islower(char const *str)
{
    if (!str)
        return 0;
    while (my_islower(*str))
        ++str;
    return !*str;
}
