/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Counts the number of parameters required by the given format string
*/

#include "libmy/core.h"
#include "libmy/parsing.h"
#include "libmy/printf.h"
#include "my_printf.h"

static void set_position(char const **conv, size_t *max_pos, size_t *arg_len)
{
    size_t position;
    char const *digit_str = *conv;

    if (my_next_size_t(&digit_str, &position) == 0 && *digit_str == '$') {
        *conv = digit_str + 1;
        *max_pos = MY_MAX(position, *max_pos);
    } else {
        ++(*arg_len);
    }
}

static void count_parameters_in_width(
    char const **conv, size_t *max_pos, size_t *arg_len)
{
    if (**conv > '0' && **conv <= '9') {
        size_t tmp = 0;
        my_next_size_t(conv, &tmp);
    } else if (**conv == '*') {
        ++(*conv);
        set_position(conv, max_pos, arg_len);
    }
}

static void count_parameters_in_precision(
    char const **conv, size_t *max_pos, size_t *arg_len)
{
    if (**conv != '.')
        return;
    ++(*conv);
    if (**conv == '*') {
        ++(*conv);
        set_position(conv, max_pos, arg_len);
    } else {
        my_next_size_t(conv, NULL);
    }
}

static void count_parameters_in_conversion(
    char const **conv, size_t *max_pos, size_t *arg_len)
{
    size_t prev_max = *max_pos;
    size_t prev_len = *arg_len;
    p_my_printf_specifier_t spec;

    set_position(conv, max_pos, arg_len);
    p_my_printf_get_flags(conv);
    count_parameters_in_width(conv, max_pos, arg_len);
    count_parameters_in_precision(conv, max_pos, arg_len);
    p_my_printf_get_len_modifier(conv);
    spec = p_my_printf_get_conv_specifier(conv);
    if (spec == P_MY_PRINTF_SPEC_NONE) {
        *max_pos = prev_max;
        *arg_len = prev_len;
    }
}

MY_LOCAL size_t p_my_printf_count_parameters(char const *fmt)
{
    size_t max_pos = 0;
    size_t arg_len = 0;

    while (p_my_printf_next_conversion(&fmt))
        count_parameters_in_conversion(&fmt, &max_pos, &arg_len);
    return MY_MAX(arg_len, max_pos);
}
