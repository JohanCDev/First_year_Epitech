/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Compares two strings, ignoring case
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_stricmp(char const *s1, char const *s2)
{
    if (!s1 && s2)
        return -1;
    if (!s2 && s1)
        return 1;
    if (!s1)
        return 0;
    while (*s1 && *s2 && my_tolower(*s1) == my_tolower(*s2)) {
        ++s1;
        ++s2;
    }
    return (int)my_tolower(*s1) - (int)my_tolower(*s2);
}
