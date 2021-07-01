/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A function that copies n characters from a string into another
*/

#include <stddef.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    while (src[i] && i < n) {
        dest[i] = src[i];
        ++i;
    }
    while (i < n)
        dest[i++] = 0;
    return dest;
}
