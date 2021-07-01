/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_put_adress
*/

#include "../../include/my.h"

int my_putnbr_base_long(long number, char *base)
{
    int size_base = my_strlen(base);
    int result = 0;
    long nbr;

    if (number < 0) {
        result++;
        number = number * -1;
        my_putchar('-');
    }
    if (number > 0) {
        nbr = number;
        number /= size_base;
        result += my_putnbr_base_long(number, base);
        result++;
        my_putchar(base[nbr % size_base]);
    }
    return (result);
}

int my_putnbr_base_int(int number, char const *base)
{
    int res = 0;
    int pow = 1;
    int base_size = my_strlen(base);

    if (number == -1) {
        my_putstr("FFFFFFFF");
        return (0);
    }
    if (number < 0) {
        my_putchar('-');
        number = -number;
    }
    while ((number / pow) >= base_size)
        pow *= base_size;
    while (pow > 0) {
        res = (number / pow) % base_size;
        my_putchar(base[res]);
        pow = pow / base_size;
    }
    return (1);
}

int my_put_address(long long nbr)
{
    int res = 0;

    if (nbr == '\0') {
        my_put_error("nbr is null\n");
        return (84);
    }
    else {
        res += my_putstr("0x");
        res += my_putnbr_base_long(nbr, "0123456789abcdef");
    }
    return (0);
}