/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the length of a signed integer conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static size_t sint_len(intmax_t num)
{
    size_t len = 1;

    if (num < 0)
        num /= -10;
    else
        num /= 10;
    while (num > 0) {
        num /= 10;
        ++len;
    }
    return len;
}

MY_LOCAL size_t p_my_printf_sint_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    intmax_t num = conv->value.sint_arg;
    size_t len = sint_len(num);
    int has_sign = PGET_FLAG(SIGN_BLANK) || PGET_FLAG(PLACE_SIGN) || num < 0;

    if (!PGET_FLAG(HAS_PRECISION) || conv->precision <= len)
        return has_sign + len;
    *zeros = conv->precision - len;
    return has_sign + conv->precision;
}
