/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Concatenates two strings
*/

#include "libmy/ascii.h"

MY_ASCII_API char *my_strcat(char *dest, char const *src)
{
    char *d = dest;

    if (!src)
        return dest;
    while (*d)
        ++d;
    while (*src) {
        *d = *src;
        ++d;
        ++src;
    }
    *d = 0;
    return dest;
}
