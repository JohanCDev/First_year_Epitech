/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Returns the length of a boolean covertion
*/

#include "libmy/printf.h"
#include "my_printf.h"

MY_LOCAL size_t p_my_printf_boolean_len(
    p_my_printf_conv_t const *conv, size_t *zeros)
{
    (void)zeros;
    if (conv->value.uint_arg == 0)
        return 5;
    return 4;
}
