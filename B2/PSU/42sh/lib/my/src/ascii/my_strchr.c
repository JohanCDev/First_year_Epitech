/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Returns a pointer to the first occurence of the character c in the string
*/

#include <stdlib.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_strchr(const char *str, char c)
{
    if (!str)
        return NULL;
    while (*str) {
        if (*str == c)
            return (char *)str;
        ++str;
    }
    if (*str == c)
        return (char *)str;
    return NULL;
}
