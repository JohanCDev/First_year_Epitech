/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to an output stream, with va_list.
*/

#include "libmy/ascii.h"
#include "libmy/printf.h"
#include "my_printf.h"

static int print_regular(
    my_iostream_t *out, const char *start, const char *end, size_t *char_count)
{
    size_t to_write;
    size_t written;

    if (start >= end)
        return 0;
    to_write = end - start;
    written = my_fwrite(start, 1, to_write, out);
    *char_count += written;
    return written != to_write;
}

static int print_conv(my_iostream_t *out, p_my_printf_conv_t *conv,
    size_t *char_count, char const **prev)
{
    int ret;

    if (conv->specifier == P_MY_PRINTF_SPEC_NONE) {
        --(*prev);
        return 0;
    }
    ret = p_my_printf_conversion(out, conv, *char_count);
    if (ret < 0)
        return 1;
    *char_count += ret;
    return 0;
}

MY_PRINTF_API int my_vfprintf(
    my_iostream_t *out, char const *fmt, va_list va_args)
{
    size_t arg_count = p_my_printf_count_parameters(fmt);
    size_t count_pos[2] = {0};
    p_my_printf_arg_type_t types[arg_count];
    p_my_printf_arg_t args[arg_count];
    p_my_printf_conv_t conv;
    char const *prev = fmt;

    p_my_printf_fill_types(fmt, types);
    p_my_printf_fill_args(arg_count, args, types, va_args);
    while (p_my_printf_next_conversion(&fmt)) {
        if (print_regular(out, prev, fmt - 1, count_pos))
            return -1;
        conv = p_my_printf_parse_conversion(&fmt, args, types, count_pos + 1);
        prev = fmt;
        if (print_conv(out, &conv, count_pos, &prev))
            return -1;
    }
    if (print_regular(out, prev, my_strchr(prev, 0), count_pos))
        return -1;
    return (int)count_pos[0];
}
