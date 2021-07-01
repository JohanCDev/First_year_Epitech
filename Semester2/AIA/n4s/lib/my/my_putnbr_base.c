/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-tanguy.bellicha
** File description:
** my_putnbr_base
*/

#include "my.h"
#include <stddef.h>

int my_put_nbr_base_int(int nb, char const *base)
{
    int res = 0;
    int power = 1;
    int length = my_strlen(base);

    if (nb == -1) {
        my_putstr("FFFFFFFF");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    while ((nb / power) >= length)
        power *= length;
    while (power > 0) {
        res = (nb / power) % length;
        my_putchar(base[res]);
        power /= length;
    }
    return (1);
}

int my_put_nbr_base_long(long nb1, char *base)
{
    int i = 0;
    int size = 0;
    long nb2;

    if (nb1 < 0) {
        my_putchar('-');
        nb1 *= (-1);
        i++;
    }
    size = my_strlen(base);
    if (nb1 > 0) {
        nb2 = nb1;
        nb1 /= size;
        i += my_put_nbr_base_long(nb1, base);
        i++;
        my_putchar(base[nb2 % size]);
    }
    return (i);
}

int my_put_adress(long long nb)
{
    int i = 0;

    if (nb == 0) {
        i += my_putstr("NULL");
        return (84);
    } else {
        i += my_putstr("0x");
        i += my_put_nbr_base_long(nb, "0123456789abcdef");
    }
    return (i);
}

void my_put_unsigned(unsigned int nb)
{
    unsigned int digit;

    if (nb > 9)
        my_put_unsigned(nb/10);
    digit = nb % 10;
    my_putchar(digit + '0');
}

void my_put_ascii(int nb)
{
    if (nb < 32 || nb >= 127) {
        my_putchar('\\');
        if (nb < 100)
            my_putchar('0');
        if (nb < 10)
            my_putchar('0');
        my_put_nbr(nb);
    } else
        my_putchar(nb);
}