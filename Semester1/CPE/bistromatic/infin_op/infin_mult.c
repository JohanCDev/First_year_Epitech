/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** infin_mult
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_infin_mult(char *number, char *times)
{
    char *res = malloc(sizeof(char) * 128);
    int is_neg1 = get_sign(number);
    int is_neg2 = get_sign(times);

    number = clean_zeros(number);
    times = clean_zeros(times);
    number += is_neg1;
    times += is_neg2;
    while (is_nb1_greater(times, "1")) {
        res = my_infin_add(res, number);
        times = my_infin_sub(times, "1");
    }
    if ((is_neg1 || is_neg2) && !(is_neg1 && is_neg2))
        res = negate(res);
    return (res);
}
