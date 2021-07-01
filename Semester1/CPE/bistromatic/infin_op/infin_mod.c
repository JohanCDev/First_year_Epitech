/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** infin_mod
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bistromatic.h"

char *my_infin_mod(char *nb1, char *nb2)
{
    if (nb2[0] != '0')
        return (my_infin_sub(nb1, my_infin_mult(nb2, my_infin_div(nb1, nb2))));
    else
        return (ERROR_MSG);
}