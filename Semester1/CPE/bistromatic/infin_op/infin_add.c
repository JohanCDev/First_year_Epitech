/*
** EPITECH PROJECT, 2020
** Infin_add
** File description:
** infin_add
*/

#include <stdlib.h>
#include "../include/my.h"

#define c_to_i(c) (c - 48)

#define i_to_c(i) (i + 48)

char *negate(char *str) {
    char *neg_str = (char *)malloc(my_strlen(str) + 1);
    char *p = neg_str;

    *neg_str++ = '-';
    while (*str)
        *neg_str++ = *str++;
    return (p);
}

char *calculate_add(char *nb1, char *nb2)
{
    int inb1 = 0;
    int inb2 = 0;
    int ir = 0;
    int carry = 0;
    int add = 0;
    char *res = (char *)malloc(my_strlen(nb1)+1 + my_strlen(nb2)+1);

    while (nb1[inb1]) {
        add = nb2[inb2] ? c_to_i(nb1[inb1]) + c_to_i(nb2[inb2]) + carry
            : c_to_i(nb1[inb1]) + carry;
        inb2 += 1;
        carry = add > 9 ? 1 : 0;
        add = add > 9 ? add - 10 : add;
        inb1 += 1;
        res[ir++] = i_to_c(add);
    }
    if (carry == 1)
        res[ir++] = '1';
    res[ir + 1] = 0;
    return (res);
}

char *my_infin_add(char *nb1, char *nb2)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 2));
    int is_neg1 = get_sign(nb1);
    int is_neg2 = get_sign(nb2);

    if (is_neg2)
        return (my_infin_sub(nb1, nb2+1));
    if (is_neg1)
        return (my_infin_sub(nb1, negate(nb2)));
    nb1 = my_revstr(clean_zeros(nb1));
    nb2 = my_revstr(clean_zeros(nb2));
    if (is_nb1_greater(nb1, nb2))
        result = calculate_add(nb1 , nb2);
    else
        result = calculate_add(nb2, nb1);
    return (my_revstr(result));
}