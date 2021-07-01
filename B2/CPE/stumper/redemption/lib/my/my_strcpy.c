/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string into an other
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
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