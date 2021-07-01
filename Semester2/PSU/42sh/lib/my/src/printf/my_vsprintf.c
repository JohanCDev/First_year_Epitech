/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to a string, with a va_list.
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_vsprintf(char *str, char const *fmt, va_list args)
{
    return my_vsnprintf(str, SIZE_MAX, fmt, args);
}
