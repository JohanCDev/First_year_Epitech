/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to a string, with a va_list.
*/

#include "libmy/core.h"
#include "libmy/printf.h"

MY_PRINTF_API int my_vsnprintf(
    char *str, size_t size, const char *fmt, va_list args)
{
    if (str && size > 0) {
        my_iostream_t stream;
        size_t written;
        va_list copy;

        my_finit_output_memory(str, size - 1, &stream);
        va_copy(copy, args);
        my_vfprintf(&stream, fmt, copy);
        va_end(copy);
        my_fget_buffer(&written, &stream);
        str[MY_MIN(written, size)] = '\0';
    }
    return my_vfprintf(MY_VOID_OUT, fmt, args);
}
