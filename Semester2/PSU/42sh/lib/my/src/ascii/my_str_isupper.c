/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Check whether string contains only upper-case alphabetical characters
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_str_isupper(char const *str)
{
    if (!str)
        return 0;
    while (my_isupper(*str))
        ++str;
    return !*str;
}
