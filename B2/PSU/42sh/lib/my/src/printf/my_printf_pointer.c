/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a pointer conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static int print_pointer_as_uint(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    p_my_printf_conv_t int_conv = {
        .value = {.uint_arg = (uintptr_t)conv->value.pointer_arg},
        .type = P_MY_PRINTF_ARG_UINTMAX_T,
        .specifier = P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL,
        .flags = conv->flags | P_MY_PRINTF_FLAG_ALT,
        .field_width = conv->field_width,
        .precision = conv->precision};

    return p_my_printf_uint(output, &int_conv, len, zeros);
}

MY_LOCAL int p_my_printf_pointer(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    if (!conv->value.pointer_arg) {
        if (my_fputs("(nil)", output))
            return -1;
        return MY_MAX(len, conv->field_width);
    }
    return print_pointer_as_uint(output, conv, len, zeros);
}
