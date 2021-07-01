/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Check whether string contains only alphabetical characters
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_str_isalpha(char const *str)
{
    if (!str)
        return 0;
    while (my_isalpha(*str))
        ++str;
    return !*str;
}
