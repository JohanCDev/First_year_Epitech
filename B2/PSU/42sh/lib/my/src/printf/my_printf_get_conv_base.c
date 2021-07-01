/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the base associated with a given conversion
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const char *BINARY_BASE = "01";
static const char *OCTAL_BASE = "01234567";
static const char *DECIMAL_BASE = "0123456789";
static const char *LOWER_HEX_BASE = "0123456789abcdef";
static const char *UPPER_HEX_BASE = "0123456789ABCDEF";

static unsigned set_base(unsigned radix, char const **dst, char const *src)
{
    if (dst)
        *dst = src;
    return radix;
}

MY_LOCAL unsigned p_my_printf_get_conv_base(
    p_my_printf_conv_t const *conv, char const **base)
{
    switch (conv->specifier) {
        case P_MY_PRINTF_SPEC_LOWER_BINARY:
        case P_MY_PRINTF_SPEC_UPPER_BINARY:
            return set_base(2, base, BINARY_BASE);
        case P_MY_PRINTF_SPEC_OCTAL: return set_base(8, base, OCTAL_BASE);
        case P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL:
            return set_base(16, base, LOWER_HEX_BASE);
        case P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL:
            return set_base(16, base, UPPER_HEX_BASE);
        default: return set_base(10, base, DECIMAL_BASE);
    }
}
