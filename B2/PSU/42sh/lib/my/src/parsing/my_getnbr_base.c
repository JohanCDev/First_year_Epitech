/*
** EPITECH PROJECT, 2020
** LibMy - parsing module
** File description:
** A function that parses the given string as a integer
*/

#include <limits.h>
#include "libmy/ascii.h"
#include "libmy/parsing.h"

static int my_char_pos(char const *str, char c, int len)
{
    for (int i = 0; i < len; ++i)
        if (str[i] == c)
            return i;
    return -1;
}

static int get_negative(char const **str, int *neg)
{
    while (**str) {
        if (**str == '-')
            *neg = !*neg;
        else if (**str != '+')
            break;
        *str = *str + 1;
    }
    return 0;
}

MY_PARSING_API int my_getnbr_base(char const *str, char const *base)
{
    int radix;
    long long n = 0;
    int neg = 0;

    if (!base || !str)
        return 0;
    radix = (int)my_strlen(base) + get_negative(&str, &neg);
    if (radix <= 1)
        return 0;
    while (*str) {
        int digit = my_char_pos(base, *str, radix);

        if (digit < 0)
            return 0;
        n = n * radix + (long long)digit;
        if (n > (long long)INT_MAX + neg)
            return 0;
        ++str;
    }
    return (int)(neg ? -n : n);
}
