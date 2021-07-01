/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A function that compares two strings
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 && s2)
        return -1;
    if (!s2 && s1)
        return 1;
    if (!s1)
        return 0;
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return (int)*s1 - (int)*s2;
}
