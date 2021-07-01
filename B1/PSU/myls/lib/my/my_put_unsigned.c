/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_check_unisgned
*/

#include <stdarg.h>
#include "../../include/my.h"

unsigned int my_put_unsigned_nbr(unsigned int nbr)
{
    unsigned int res;

    if (nbr > 9) {
        my_put_unsigned_nbr(nbr / 10);
    }
    res = nbr % 10 + 48;
    my_putchar(res);
    return (res);
}