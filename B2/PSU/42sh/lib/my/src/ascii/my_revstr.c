/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A functions that reverses a string
*/

#include <stddef.h>
#include "libmy/ascii.h"

MY_ASCII_API char *my_revstr(char *str)
{
    int len = 0;
    int mid;

    if (!str)
        return NULL;
    while (str[len])
        ++len;
    mid = len / 2;
    for (int i = 0; i < mid; ++i) {
        int j = len - i - 1;

        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
    return str;
}
