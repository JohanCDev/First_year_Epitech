/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a conversion to the supplied io stream
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const p_my_printf_conv_impl_t CONV[P_MY_PRINTF_ARG_MAX_VALUE] = {
    [P_MY_PRINTF_ARG_INTMAX_T] = &p_my_printf_sint,
    [P_MY_PRINTF_ARG_UINTMAX_T] = &p_my_printf_uint,
    [P_MY_PRINTF_ARG_CHAR] = &p_my_printf_char,
    [P_MY_PRINTF_ARG_STRING] = &p_my_printf_string,
    [P_MY_PRINTF_ARG_POINTER] = &p_my_printf_pointer,
    [P_MY_PRINTF_ARG_PERCENT] = &p_my_printf_percent,
};

static void store_char_count2(
    p_my_printf_conv_t const *conv, size_t char_count)
{
    switch (conv->type) {
        case P_MY_PRINTF_ARG_PTR_SIZE_T:
            (*conv->value.size_t_ptr_arg) = (size_t)char_count;
            break;
        case P_MY_PRINTF_ARG_PTR_PTRDIFF_T:
            (*conv->value.ptrdiff_t_ptr_arg) = (ptrdiff_t)char_count;
            break;
        default: (*conv->value.int_ptr_arg) = (int)char_count;
    }
}

static void store_char_count1(
    p_my_printf_conv_t const *conv, size_t char_count)
{
    switch (conv->type) {
        case P_MY_PRINTF_ARG_PTR_SCHAR:
            (*conv->value.schar_ptr_arg) = (signed char)char_count;
            break;
        case P_MY_PRINTF_ARG_PTR_SHORT:
            (*conv->value.short_ptr_arg) = (short)char_count;
            break;
        case P_MY_PRINTF_ARG_PTR_LONG:
            (*conv->value.long_ptr_arg) = (long)char_count;
            break;
        case P_MY_PRINTF_ARG_PTR_LONG_LONG:
            (*conv->value.long_long_ptr_arg) = (long long)char_count;
            break;
        case P_MY_PRINTF_ARG_PTR_INTMAX_T:
            (*conv->value.intmax_t_ptr_arg) = (intmax_t)char_count;
            break;
        default: store_char_count2(conv, char_count);
    }
}

MY_LOCAL int p_my_printf_conversion(
    my_iostream_t *output, p_my_printf_conv_t const *conv, size_t char_count)
{
    p_my_printf_conv_impl_t func = CONV[conv->type];
    size_t zeros;
    size_t len = p_my_printf_conversion_len(conv, &zeros);

    if (PGET_SPEC(COUNT)) {
        store_char_count1(conv, char_count);
        return 0;
    }
    if (!func)
        return -1;
    return (*func)(output, conv, len, zeros);
}
