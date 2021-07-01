/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** putnbr_base
*/

#include "assembler.h"

char *my_putnbr_base_int(int number, char const *base)
{
    int res = 0;
    int i = 0;
    int pow = 1;
    int base_size = my_strlen(base);
    char *str_nb = malloc(sizeof(char) * 8);

    while ((number / pow) >= base_size)
        pow *= base_size;
    while (pow > 0) {
        res = (number / pow) % base_size;
        str_nb[i] = base[res];
        pow = pow / base_size;
        i++;
    }
    str_nb[i] = 0;
    return (str_nb);
}