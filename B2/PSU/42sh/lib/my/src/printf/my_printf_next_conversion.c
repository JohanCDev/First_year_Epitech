/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Jumpts to the next conversion specifier
*/

#include "libmy/printf.h"

MY_LOCAL size_t p_my_printf_next_conversion(char const **str)
{
    size_t offset = 0;

    while ((*str)[offset]) {
        if ((*str)[offset++] != '%')
            continue;
        *str += offset;
        if (**str)
            return offset;
        return 0;
    }
    *str += offset;
    return 0;
}
