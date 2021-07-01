/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Finds a substring in a string
*/

#include <stddef.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_strstr(char const *str, char const *to_find)
{
    if (!str || !to_find)
        return NULL;
    if (!*to_find)
        return (char *)(str + my_strlen(str));
    for (char const *start = str; *start; ++start) {
        int i = 0;

        while (start[i] && to_find[i] && start[i] == to_find[i])
            ++i;
        if (!to_find[i])
            return (char *)start;
    }
    return NULL;
}
