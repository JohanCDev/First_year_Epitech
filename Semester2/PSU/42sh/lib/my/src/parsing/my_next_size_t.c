/*
** EPITECH PROJECT, 2020
** LibMy - parsing module
** File description:
** Parses the next size_t
*/

#include <stdint.h>
#include "libmy/parsing.h"

static int my_next_size_t_set_zero(size_t *dst)
{
    if (dst)
        *dst = 0;
    return 0;
}

MY_PARSING_API int my_next_size_t(char const **str, size_t *dst)
{
    size_t num = 0;

    if (!str || !*str || **str < '0' || **str > '9')
        return 1;
    num = (size_t)(**str - '0');
    ++(*str);
    if (num == 0 && **str == '0')
        return my_next_size_t_set_zero(dst);
    while (**str >= '0' && **str <= '9') {
        size_t digit = (size_t)(**str - '0');

        ++(*str);
        if (num > SIZE_MAX / 10 || num * 10 > SIZE_MAX - digit)
            continue;
        num = num * 10 + digit;
    }
    if (dst)
        *dst = num;
    return 0;
}
