/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** infin_div
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bistromatic.h"

char *my_infin_div(char *nb1, char *nb2)
{
    char *index = malloc(sizeof(char) * 128);
    int is_neg1 = get_sign(nb1);
    int is_neg2 = get_sign(nb2);

    nb1 = clean_zeros(nb1);
    nb2 = clean_zeros(nb2);
    nb1 += is_neg1;
    nb2 += is_neg2;
    if (nb2[0] == '0')
        return (ERROR_MSG);
    index[0] = '0';
    while (is_nb1_greater(nb1, nb2)) {
        nb1 = my_infin_sub(nb1, nb2);
        index = my_infin_add(index, "1");
    }
    return (index);
}