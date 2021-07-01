/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the length of a unsigned integer conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static size_t get_uint_len(uintmax_t num, unsigned radix)
{
    size_t len = 1;

    num /= radix;
    while (num > 0) {
        num /= radix;
        ++len;
    }
    return len;
}

static size_t uint_len(p_my_printf_conv_t const *conv, size_t *zeros)
{
    uintmax_t num = conv->value.uint_arg;
    unsigned radix = p_my_printf_get_conv_base(conv, NULL);
    size_t len = get_uint_len(num, radix);
    size_t prefix = 0;

    if (PGET_FLAG(ALT)) {
        if (radix == 8)
            prefix = 1;
        else if (radix == 2 || radix == 16)
            prefix = 2;
    }
    if (!PGET_FLAG(HAS_PRECISION) || conv->precision <= len)
        return prefix + len;
    *zeros = conv->precision - len;
    return prefix + conv->precision;
}

MY_LOCAL size_t p_my_printf_uint_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    if (!PGET_SPEC(LOWER_BOOLEAN) && !PGET_SPEC(UPPER_BOOLEAN))
        return uint_len(conv, zeros);
    return p_my_printf_boolean_len(conv, zeros);
}
