/*
** EPITECH PROJECT, 2020
** LibMy - print module
** File description:
** Prints a signed integer conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static int place_sign(my_iostream_t *output, p_my_printf_conv_t const *conv)
{
    if (conv->value.sint_arg >= 0) {
        if (PGET_FLAG(PLACE_SIGN))
            return my_fputc('+', output);
        if (PGET_FLAG(SIGN_BLANK))
            return my_fputc(' ', output);
    }
    return 0;
}

MY_LOCAL int p_my_printf_sint(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    intmax_t nb = conv->value.sint_arg;
    char pad_char = ' ';

    if (PGET_FLAG(ZERO_PAD))
        pad_char = '0';
    if (p_my_printf_lpad(output, conv, len, pad_char)
        || p_my_printf_zpad(output, zeros) || place_sign(output, conv)
        || my_fputintmax_t_base(nb, "0123456789", 10, output) == 0
        || p_my_printf_rpad(output, conv, len, ' '))
        return -1;
    return MY_MAX(len, conv->field_width);
}
