/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A function that copies a string into another
*/

#include <stddef.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_strcpy(char *dest, char const *src)
{
    if (!dest || !src)
        return NULL;
    while (*src) {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
    return dest;
}
