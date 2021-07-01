/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Computes the length of a nul-terminated string
*/

#include "libmy/ascii.h"

MY_ASCII_API size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i])
        ++i;
    return i;
}
