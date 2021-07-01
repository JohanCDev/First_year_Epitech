/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to stdout, with va_list.
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_vprintf(char const *fmt, va_list args)
{
    return my_vdprintf(1, fmt, args);
}
