/*
** EPITECH PROJECT, 2020
** Infin_add
** File description:
** infin_add
*/

#include <stdlib.h>
#include "my.h"

void my_infin_add(char *nb1, char *nb2, int carry)
{
    int digit1 = 0;
    int digit2 = 0;
    int len1 = my_strlen(nb1)-1;
    int len2 = my_strlen(nb2)-1;
    int res;

    if (len1 >= 0) {
        digit1 = nb1[len1] - 48;
        nb1[len1] = '\0';
    }
    if (len2 >= 0) {
        digit2 = nb2[len2] - 48;
        nb2[len2] = '\0';
    }
    res = digit1 + digit2 + carry;
    carry = (res - (res % 10)) / 10;
    res = res % 10;
    len1 -= 1;
    len2 -= 1;
    if (len1 >= 0 || len2 >= 0)
        my_infin_add(nb1, nb2, carry);
    else if (carry == 1)
        my_putchar('1');
    my_put_nbr(res);
}

int main(int ac, char **av) {
    if (ac != 3 || !my_str_isnum(av[1]) || !my_str_isnum(av[2])) {
        return (84);
    }
    my_infin_add(av[1], av[2], 0);
    my_putchar('\n');
    return (0);
}