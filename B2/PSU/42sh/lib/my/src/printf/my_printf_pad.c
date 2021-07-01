/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Writes padding if needed
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

MY_LOCAL int p_my_printf_lpad(
    my_iostream_t *output, p_my_printf_conv_t const *conv, size_t len, char c)
{
    int need_padding = PGET_FLAG(HAS_FIELD_WIDTH) && conv->field_width > len;

    if (need_padding && !PGET_FLAG(LEFT_ADJUST)
        && my_frputc(c, conv->field_width - len, output))
        return 1;
    return 0;
}

MY_LOCAL int p_my_printf_rpad(
    my_iostream_t *output, p_my_printf_conv_t const *conv, size_t len, char c)
{
    int need_padding = PGET_FLAG(HAS_FIELD_WIDTH) && conv->field_width > len;

    if (need_padding && PGET_FLAG(LEFT_ADJUST)
        && my_frputc(c, conv->field_width - len, output))
        return 1;
    return 0;
}

MY_LOCAL int p_my_printf_zpad(my_iostream_t *output, size_t zeros)
{
    return my_frputc('0', zeros, output);
}
