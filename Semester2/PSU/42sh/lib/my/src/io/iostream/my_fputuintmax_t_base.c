/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts an uintmax_t into the speicified stream
*/

#include "libmy/io.h"

MY_IO_API size_t my_fputuintmax_t_base(
    uintmax_t nb, char const *base, size_t radix, my_iostream_t *stream)
{
    size_t bytes = 0;
    uintmax_t pow = 1;

    for (uintmax_t n = nb; n >= radix; n /= radix)
        pow *= radix;
    while (pow != 0) {
        if (my_fputc(base[nb / pow % radix], stream))
            return 0;
        pow /= radix;
        ++bytes;
    }
    return bytes;
}
