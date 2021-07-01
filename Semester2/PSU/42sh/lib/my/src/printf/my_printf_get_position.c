/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Gets the index of a positional argument
*/

#include "libmy/parsing.h"
#include "libmy/printf.h"

MY_LOCAL int p_my_printf_get_position(char const **conv, size_t *arg_pos)
{
    size_t position;
    char const *digit_str = *conv;

    if (my_next_size_t(&digit_str, &position) == 0 && *digit_str == '$') {
        *conv = digit_str + 1;
        *arg_pos = position - 1;
        return 0;
    }
    return 1;
}
