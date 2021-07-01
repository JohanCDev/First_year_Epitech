/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints the passed number
*/

#include "libmy/io.h"

static int my_put_nbr_get_power_of_ten(int nb)
{
    int power;

    if (nb < 0) {
        if (nb > -10)
            return 1;
        nb /= -10;
        power = 10;
    } else {
        power = 1;
    }

    while (nb >= 10) {
        nb /= 10;
        power *= 10;
    }
    return power;
}

MY_IO_API int my_put_nbr_fd(int fd, int nb)
{
    int power = my_put_nbr_get_power_of_ten(nb);

    if (nb < 0) {
        my_putchar_fd(fd, '-');
        my_putchar_fd(fd, (char)(nb / -power) + '0');
        nb = -(nb % power);
        power /= 10;
    }
    while (power != 0) {
        my_putchar_fd(fd, (char)(nb / power % 10) + '0');
        power /= 10;
    }
    return 0;
}

MY_IO_API int my_put_nbr(int nb)
{
    return my_put_nbr_fd(1, nb);
}
