/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a character conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

MY_LOCAL int p_my_printf_char(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    (void)zeros;
    (void)len;
    if (p_my_printf_lpad(output, conv, 1, ' ')
        || my_fputc(conv->value.char_arg, output)
        || p_my_printf_rpad(output, conv, 1, ' '))
        return -1;
    return MY_MAX(1, conv->field_width);
}
