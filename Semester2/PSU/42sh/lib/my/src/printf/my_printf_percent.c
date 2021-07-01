/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a percent conversion
*/

#include "libmy/printf.h"
#include "my_printf.h"

MY_LOCAL int p_my_printf_percent(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    (void)conv;
    (void)len;
    (void)zeros;
    if (my_fputc('%', output))
        return -1;
    return 1;
}
