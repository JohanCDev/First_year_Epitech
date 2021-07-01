/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the number of characters that will be printed
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const p_my_printf_conv_len_t CONV_LEN[P_MY_PRINTF_ARG_MAX_VALUE] = {
    [P_MY_PRINTF_ARG_INTMAX_T] = &p_my_printf_sint_len,
    [P_MY_PRINTF_ARG_UINTMAX_T] = &p_my_printf_uint_len,
    [P_MY_PRINTF_ARG_STRING] = &p_my_printf_string_len,
    [P_MY_PRINTF_ARG_POINTER] = &p_my_printf_pointer_len,
};

MY_LOCAL size_t p_my_printf_conversion_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    p_my_printf_conv_len_t func = CONV_LEN[conv->type];

    *zeros = 0;
    if (!func)
        return 0;
    return (*func)(conv, zeros);
}
