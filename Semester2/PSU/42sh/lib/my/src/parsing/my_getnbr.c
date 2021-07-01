/*
** EPITECH PROJECT, 2020
** LibMy - parsing module
** File description:
** parses an int from the given string
*/

#include <limits.h>
#include "libmy/parsing.h"

static void get_negative(char const **str, int *neg)
{
    while (**str) {
        if (**str == '-')
            *neg = !*neg;
        else if (**str != '+')
            break;
        *str = *str + 1;
    }
}

static int my_getnbr_start(char const **str)
{
    long long n = 0;
    int neg = 0;

    if (!*str)
        return 0;
    get_negative(str, &neg);
    while (**str) {
        if (**str < '0' || **str > '9')
            return (int)(neg ? -n : n);
        n = n * 10 + (long long)(**str - '0');
        if (n > (long long)INT_MAX + neg)
            return 0;
        ++(*str);
    }
    return (int)(neg ? -n : n);
}

MY_PARSING_API int my_getnbr(char const *str)
{
    return my_getnbr_start(&str);
}

MY_PARSING_API int my_getnbr_strict(char const *str)
{
    int result = my_getnbr_start(&str);

    if (str && *str)
        return 0;
    return result;
}
