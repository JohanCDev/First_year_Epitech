/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** convert_all
*/

#include "pal.h"
#include "my.h"
#include <stdlib.h>

int get_value(char c)
{
    if (c >= '0' && c <= '9') {
        return ((int)c - '0');
    } else if (c < '0') {
        return -1;
    } else {
        return ((int)c - 'A' + 10);
    }
}

char *my_convert_any_base_to_dec(char *str, int base)
{
    int pow = 1;
    int res = 0;

    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        res += get_value(str[i]) * pow;
        pow = pow * base;
    }
    return (my_itoa(res));
}

char *change_base_to_dec(char *nb, int base)
{
    switch (base) {
    case 2:
        return my_convert_any_base_to_dec(nb, base);
    case 3:
        return my_convert_any_base_to_dec(nb, base);
    case 4:
        return my_convert_any_base_to_dec(nb, base);
    case 5:
        return my_convert_any_base_to_dec(nb, base);
    case 6:
        return my_convert_any_base_to_dec(nb, base);
    case 7:
        return my_convert_any_base_to_dec(nb, base);
    case 8:
        return my_convert_any_base_to_dec(nb, base);
    case 9:
        return my_convert_any_base_to_dec(nb, base);
    default:
        return nb;
    }
}