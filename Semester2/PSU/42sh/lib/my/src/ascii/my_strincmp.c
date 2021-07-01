/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Compares the first n-bytes of the two strings, ignoring case
*/

#include "libmy/ascii.h"

MY_ASCII_API int my_strincmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    unsigned char *str1;
    unsigned char *str2;

    if (!s1 || !s2 || n == 0)
        return 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    while (i < n - 1 && str1[i] && my_tolower(str1[i]) == my_tolower(str2[i]))
        ++i;
    return (int)(my_tolower(str1[i]) - my_tolower(str2[i]));
}
