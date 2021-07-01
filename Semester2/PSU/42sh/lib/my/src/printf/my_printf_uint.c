/*
** EPITECH PROJECT, 2020
** LibMy - print module
** File description:
** Prints a unsigned integer conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static int place_prefix(my_iostream_t *output, p_my_printf_conv_t const *conv)
{
    if (!PGET_FLAG(ALT))
        return 0;
    switch (conv->specifier) {
        case P_MY_PRINTF_SPEC_LOWER_BINARY: return my_fputs("0b", output);
        case P_MY_PRINTF_SPEC_UPPER_BINARY: return my_fputs("0B", output);
        case P_MY_PRINTF_SPEC_OCTAL: return my_fputc('0', output);
        case P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL: return my_fputs("0x", output);
        case P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL: return my_fputs("0X", output);
        default: return 0;
    }
}

static int print_uint(my_iostream_t *output, p_my_printf_conv_t const *conv,
    size_t len, size_t zeros)
{
    uintmax_t nb = conv->value.uint_arg;
    char pad_char = ' ';
    char const *base;
    size_t radix = p_my_printf_get_conv_base(conv, &base);

    if (PGET_FLAG(ZERO_PAD))
        pad_char = '0';
    if (p_my_printf_lpad(output, conv, len, pad_char)
        || p_my_printf_zpad(output, zeros) || place_prefix(output, conv)
        || my_fputuintmax_t_base(nb, base, radix, output) == 0
        || p_my_printf_rpad(output, conv, len, ' ')) {
        return -1;
    }
    return MY_MAX(len, conv->field_width);
}

MY_LOCAL int p_my_printf_uint(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    if (PGET_SPEC(LOWER_BOOLEAN) || PGET_SPEC(UPPER_BOOLEAN))
        return p_my_printf_boolean(output, conv, len, zeros);
    return print_uint(output, conv, len, zeros);
}
