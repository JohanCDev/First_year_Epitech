/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** requirement
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb >= 13)
        return 0;
    if (nb == 0)
        return 1;
    else {
        return nb * my_factrec_synthesis(nb - 1);
    }
}

int my_squareroot_synthesis(int nb)
{
    int count_times = 1;
    int sub = 1;

    if (nb == 0)
        return 0;
    while (nb > 0) {
        nb -= sub;
        if (nb == 0)
            return count_times;
        if (nb < 0)
            return -1;
        count_times++;
        sub += 2;
    }
    return -1;
}