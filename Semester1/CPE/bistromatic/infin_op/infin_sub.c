/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** infin_sub2
*/

#include "../include/my.h"
#include <stdlib.h>

#define c_to_i(c) (c - 48)

#define i_to_c(i) (i + 48)

char *calculate_sub(char *nb1, char *nb2, int neg1, int neg2)
{
    int inb1 = 0;
    int inb2 = 0;
    int ir = 0;
    int carry = 0;
    int sub = 0;
    char *res = (char *)malloc(my_strlen(nb1)+1 + my_strlen(nb2)+1);

    while (nb1[inb1]) {
        sub = nb2[inb2]
            ? sub_nbrs(c_to_i(nb1[inb1]), c_to_i(nb2[inb2]), neg1, neg2) - carry
            : c_to_i(nb1[inb1]) - carry;
        inb2 += 1;
        carry = sub < 0 ? 1 : 0;
        sub = sub < 0 ? sub + 10 : sub;
        inb1 += 1;
        res[ir++] = i_to_c(sub);
    }
    res[ir + 1] = 0;
    return (res);
}

char *reverse_and_calc(char *nb1, char *nb2, int neg1, int neg2)
{
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    return (calculate_sub(nb1, nb2, neg1, neg2));
}

char *clean_zeros(char *nbr_in_str)
{
    int index_source = 0;
    int index_f = 0;
    char *final_str = malloc(sizeof(char) * my_strlen(nbr_in_str));

    if (nbr_in_str[0] == '-')
        final_str[index_f++] = '-';
    while (nbr_in_str[index_source] == '0' || nbr_in_str[index_source] == '-')
        index_source++;
    while (nbr_in_str[index_source])
        final_str[index_f++] = nbr_in_str[index_source++];
    if (!final_str[0])
        final_str[0] = '0';
    return (final_str);
}

int get_sign(char *nb)
{
    if (nb[0] == '-')
        return (1);
    else
        return (0);
}

char *my_infin_sub(char *nb1, char *nb2)
{
    char *result = malloc(sizeof(char) * \
    (my_strlen(nb1) + my_strlen(nb2) + 2));
    int neg1 = get_sign(nb1);
    int neg2 = get_sign(nb2);

    nb1 = clean_zeros(nb1);
    nb2 = clean_zeros(nb2);
    nb1 = neg1 ? nb1+1 : nb1;
    nb2 = neg2 ? nb2+1 : nb2;
    if (is_nb1_greater(nb1, nb2)) {
        result = reverse_and_calc(nb1, nb2, neg1, neg2);
        if (neg1)
            result[my_strlen(result)] = '-';
    } else {
        result = reverse_and_calc(nb2, nb1, neg2, neg1);
        if ((!neg1 && !neg2) || (neg1 && !neg2))
            result[my_strlen(result)] = '-';
    }
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    return (clean_zeros(my_revstr(result)));
}