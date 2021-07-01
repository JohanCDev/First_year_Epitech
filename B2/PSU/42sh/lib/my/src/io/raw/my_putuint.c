/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints the passed number
*/

#include "libmy/io.h"

MY_IO_API int my_putuint_fd(int fd, unsigned nb)
{
    unsigned power = 1;

    for (unsigned n = nb; n >= 10; n /= 10)
        power *= 10;
    while (power != 0) {
        my_putchar_fd(fd, (char)(nb / power % 10) + '0');
        power /= 10;
    }
    return 0;
}

MY_IO_API int my_putuint(unsigned nb)
{
    return my_putuint_fd(1, nb);
}
