/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a boolean conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

MY_LOCAL int p_my_printf_boolean(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    char const *to_print;

    (void)zeros;
    if (PGET_SPEC(LOWER_BOOLEAN)) {
        to_print = "true";
        if (conv->value.uint_arg == 0)
            to_print = "false";
    } else {
        to_print = "TRUE";
        if (conv->value.uint_arg == 0)
            to_print = "FALSE";
    }
    if (p_my_printf_lpad(output, conv, len, ' ') || my_fputs(to_print, output)
        || p_my_printf_rpad(output, conv, len, ' ')) {
        return -1;
    }
    return MY_MAX(len, conv->field_width);
}
