/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Concatenates two strings, safely
*/

#include "libmy/ascii.h"

MY_ASCII_API char *my_strncat(char *dest, char const *src, int nb)
{
    char *d = dest;

    if (!src || nb <= 0)
        return dest;
    while (*d)
        ++d;
    for (int i = 0; i < nb && src[i]; ++i) {
        *d = src[i];
        ++d;
    }
    *d = 0;
    return dest;
}
