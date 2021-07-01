/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts an intmax_t into the speicified stream
*/

#include "libmy/io.h"

static intmax_t get_pow_of_radix(intmax_t nb, intmax_t radix)
{
    intmax_t power;

    if (nb < 0) {
        if (nb > -radix)
            return 1;
        nb /= -radix;
        power = radix;
    } else {
        power = 1;
    }
    while (nb >= radix) {
        nb /= radix;
        power *= radix;
    }
    return power;
}

MY_IO_API size_t my_fputintmax_t_base(
    intmax_t nb, char const *base, size_t radix, my_iostream_t *stream)
{
    size_t bytes = 0;
    intmax_t pow = get_pow_of_radix(nb, radix);

    if (nb < 0) {
        if (my_fputc('-', stream) || my_fputc(base[nb / -pow], stream))
            return 0;
        nb = -(nb % pow);
        pow /= radix;
        bytes = 2;
    }
    while (pow != 0) {
        if (my_fputc(base[nb / pow % radix], stream))
            return 0;
        pow /= radix;
        ++bytes;
    }
    return bytes;
}
