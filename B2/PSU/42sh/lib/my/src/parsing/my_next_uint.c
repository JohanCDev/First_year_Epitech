/*
** EPITECH PROJECT, 2021
** LibMy - parsing module
** File description:
** Parses the next unsigned int
*/

#include <limits.h>
#include "libmy/parsing.h"

static int my_next_uint_set_zero(unsigned *dst)
{
    if (dst)
        *dst = 0;
    return 0;
}

MY_PARSING_API int my_next_uint(char const **str, unsigned *dst)
{
    unsigned num = 0;

    if (!str || !*str || **str < '0' || **str > '9')
        return 1;
    num = (unsigned)(**str - '0');
    ++(*str);
    if (num == 0 && **str == '0')
        return my_next_uint_set_zero(dst);
    while (**str >= '0' && **str <= '9') {
        unsigned digit = (unsigned)(**str - '0');

        ++(*str);
        if (num > UINT_MAX / 10 || num * 10 > UINT_MAX - digit)
            continue;
        num = num * 10 + digit;
    }
    if (dst)
        *dst = num;
    return 0;
}
