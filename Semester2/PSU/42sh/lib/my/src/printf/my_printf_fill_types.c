/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Fills the array of types from a given format string.
*/

#include "libmy/parsing.h"
#include "libmy/printf.h"
#include "my_printf.h"

static void fill_types_in_width(
    char const **conv, size_t *pos, p_my_printf_arg_type_t types[])
{
    if (**conv > '0' && **conv <= '9') {
        my_next_size_t(conv, NULL);
    } else if (**conv == '*') {
        size_t width_pos = *pos;

        ++(*conv);
        if (p_my_printf_get_position(conv, &width_pos))
            ++(*pos);
        types[width_pos] = P_MY_PRINTF_ARG_INT;
    }
}

static void fill_types_in_precision(
    char const **conv, size_t *pos, p_my_printf_arg_type_t types[])
{
    if (**conv != '.')
        return;
    ++(*conv);
    if (**conv == '*') {
        size_t precision_pos = *pos;

        ++(*conv);
        if (p_my_printf_get_position(conv, &precision_pos))
            ++(*pos);
        types[precision_pos] = P_MY_PRINTF_ARG_INT;
    } else {
        my_next_size_t(conv, NULL);
    }
}

static void fill_types_in_conversion(
    char const **conv, size_t *pos, p_my_printf_arg_type_t types[])
{
    size_t prev_pos = *pos;
    size_t arg_pos = *pos;
    int positional = !p_my_printf_get_position(conv, &arg_pos);
    p_my_printf_length_t len;
    p_my_printf_specifier_t spec;

    p_my_printf_get_flags(conv);
    fill_types_in_width(conv, pos, types);
    fill_types_in_precision(conv, pos, types);
    len = p_my_printf_get_len_modifier(conv);
    spec = p_my_printf_get_conv_specifier(conv);
    if (spec == P_MY_PRINTF_SPEC_NONE) {
        *pos = prev_pos;
        return;
    }
    if (!positional) {
        arg_pos = *pos;
        ++(*pos);
    }
    types[arg_pos] = p_my_printf_get_type(len, spec);
}

MY_LOCAL void p_my_printf_fill_types(
    char const *fmt, p_my_printf_arg_type_t types[])
{
    size_t pos = 0;

    while (p_my_printf_next_conversion(&fmt))
        fill_types_in_conversion(&fmt, &pos, types);
}
