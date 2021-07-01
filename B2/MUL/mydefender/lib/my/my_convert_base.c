/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-tanguy.bellicha
** File description:
** my_convert_base
*/

#include "my.h"

int convert_decimal_to_octal(int dec_nb)
{
    int oct_nb = 0;
    int i = 1;

    while (dec_nb != 0) {
        oct_nb += (dec_nb % 8) * i;
        dec_nb /= 8;
        i *= 10;
    }
    return (oct_nb);
}

int convert_decimal_to_binary(int dec_nb)
{
    int bin_nb = 0;
    int i = 1;

    while (dec_nb != 0) {
        bin_nb += (dec_nb % 2) * i;
        dec_nb /= 2;
        i *= 10;
    }
    return (bin_nb);
}