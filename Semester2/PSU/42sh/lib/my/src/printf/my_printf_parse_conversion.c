/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Parses the next conversion specifier
*/

#include "libmy/core.h"
#include "libmy/parsing.h"
#include "libmy/printf.h"
#include "my_printf.h"

static void parse_field_width(char const **src, p_my_printf_arg_t const args[],
    size_t *pos, p_my_printf_conv_t *conv)
{
    size_t width_or_pos = *pos;
    int field_width;

    conv->field_width = 0;
    if (**src > '0' && **src <= '9') {
        my_next_size_t(src, &width_or_pos);
        conv->field_width = (int)width_or_pos;
        conv->flags |= P_MY_PRINTF_FLAG_HAS_FIELD_WIDTH;
    } else if (**src == '*') {
        ++(*src);
        if (p_my_printf_get_position(src, &width_or_pos))
            ++(*pos);
        field_width = (int)args[width_or_pos].uint_arg;
        conv->field_width = (unsigned int)MY_ABS(field_width);
        conv->flags |= P_MY_PRINTF_FLAG_HAS_FIELD_WIDTH;
        if (field_width < 0)
            conv->flags |= P_MY_PRINTF_FLAG_LEFT_ADJUST;
    }
}

static void parse_precision(char const **src, p_my_printf_arg_t const args[],
    size_t *pos, p_my_printf_conv_t *conv)
{
    size_t precision_or_pos = *pos;

    conv->precision = 0;
    if (**src != '.')
        return;
    conv->flags |= P_MY_PRINTF_FLAG_HAS_PRECISION;
    if (*(++(*src)) == '*') {
        ++(*src);
        if (p_my_printf_get_position(src, &precision_or_pos))
            ++(*pos);
        conv->precision = (unsigned)args[precision_or_pos].uint_arg;
        if (args[precision_or_pos].sint_arg < 0) {
            conv->precision = 0;
            conv->flags &= ~P_MY_PRINTF_FLAG_HAS_PRECISION;
        }
    } else {
        precision_or_pos = 0;
        my_next_size_t(src, &precision_or_pos);
        conv->precision = (int)precision_or_pos;
    }
}

static void parse_flags_width_precision(char const **src,
    p_my_printf_arg_t const args[], size_t *pos, p_my_printf_conv_t *conv)
{
    conv->flags = p_my_printf_get_flags(src);
    parse_field_width(src, args, pos, conv);
    parse_precision(src, args, pos, conv);
}

MY_LOCAL p_my_printf_conv_t p_my_printf_parse_conversion(char const **src,
    p_my_printf_arg_t const args[], p_my_printf_arg_type_t const types[],
    size_t *pos)
{
    p_my_printf_conv_t conv;
    char const *prev_src = *src;
    size_t prev_pos = *pos;
    size_t arg_pos = *pos;
    int positional = !p_my_printf_get_position(src, &arg_pos);

    parse_flags_width_precision(src, args, pos, &conv);
    p_my_printf_get_len_modifier(src);
    conv.specifier = p_my_printf_get_conv_specifier(src);
    if (conv.specifier == P_MY_PRINTF_SPEC_NONE) {
        *src = prev_src;
        *pos = prev_pos;
    } else {
        if (!positional)
            arg_pos = (*pos)++;
        conv.type = types[arg_pos];
        conv.value = args[arg_pos];
    }
    return conv;
}
