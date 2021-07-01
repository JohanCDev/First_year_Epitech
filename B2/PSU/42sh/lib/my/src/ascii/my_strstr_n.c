/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Finds a substring in a string
*/

#include <limits.h>
#include <stddef.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_strstr_n(
    char const *str, int str_len, char const *to_find, int to_find_len)
{
    if (!str || !to_find || to_find_len == 0)
        return NULL;
    if (str_len < 0)
        str_len = INT_MAX;
    if (to_find_len < 0)
        to_find_len = INT_MAX;
    for (int i = 0; i < str_len && str[i]; ++i) {
        char const *start = str + i;
        int j = 0;

        while (j < to_find_len && start[j] && to_find[j]
            && start[j] == to_find[j])
            ++j;
        if (j == to_find_len || !to_find[j])
            return (char *)start;
    }
    return NULL;
}
