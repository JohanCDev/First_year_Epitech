/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the length of a string conversion
*/

#include "libmy/ascii.h"
#include "libmy/printf.h"
#include "my_printf.h"

static size_t count_char(unsigned char c, int is_octal)
{
    if (is_octal && (c < ' ' || c > '~'))
        return 4;
    return 1;
}

static size_t string_conv_len(char const *str, size_t max, int is_octal)
{
    size_t i = 0;
    size_t len = 0;

    if (max == SIZE_MAX && !is_octal)
        return my_strlen(str);
    while (i < max && str[i]) {
        len += count_char((unsigned char)str[i], is_octal);
        ++i;
    }
    return len;
}

MY_LOCAL size_t p_my_printf_string_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    char const *str = conv->value.string_arg;
    size_t max = SIZE_MAX;
    size_t len = 0;

    (void)zeros;
    if (!str)
        return 6;
    if (PGET_FLAG(HAS_PRECISION))
        max = (size_t)conv->precision;
    len = string_conv_len(str, max, PGET_SPEC(STRING_OCTAL));
    if (PGET_FLAG(ALT))
        len += 2;
    return len;
}
