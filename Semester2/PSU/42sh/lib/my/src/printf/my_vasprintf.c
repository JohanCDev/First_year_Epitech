/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to an allocated string, with a va_list.
*/

#include <stdlib.h>
#include "libmy/core.h"
#include "libmy/printf.h"

MY_PRINTF_API int my_vasprintf(char **strp, const char *fmt, va_list args)
{
    va_list copy;
    int len;

    va_copy(copy, args);
    len = my_vfprintf(MY_VOID_OUT, fmt, copy);
    va_end(copy);
    if (!strp || len < 0)
        return len;
    *strp = malloc(sizeof(**strp) * ((size_t)len + 1));
    if (!*strp)
        return -1;
    return my_vsnprintf(*strp, (size_t)len + 1, fmt, args);
}
