/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A function that compares the first n-bytes of the two strings
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    unsigned char *str1;
    unsigned char *str2;

    if (!s1 || !s2 || n == 0)
        return 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    while (i < n - 1 && str1[i] && str1[i] == str2[i])
        ++i;
    return (int)(str1[i] - str2[i]);
}
