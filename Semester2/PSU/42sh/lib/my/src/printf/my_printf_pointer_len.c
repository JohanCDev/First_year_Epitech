/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the length of a pointer conversion
*/

#include "libmy/printf.h"
#include "my_printf.h"

static size_t pointer_len_as_uint(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    p_my_printf_conv_t int_conv = {
        .value = {.uint_arg = (uintptr_t)conv->value.pointer_arg},
        .type = P_MY_PRINTF_ARG_UINTMAX_T,
        .specifier = P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL,
        .flags = conv->flags | P_MY_PRINTF_FLAG_ALT,
        .field_width = conv->field_width,
        .precision = conv->precision};

    return p_my_printf_uint_len(&int_conv, zeros);
}

MY_LOCAL size_t p_my_printf_pointer_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    if (!conv->value.pointer_arg)
        return 5;
    return pointer_len_as_uint(conv, zeros);
}
