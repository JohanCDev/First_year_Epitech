/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** infin_sub_needed
*/

#include "my.h"

int is_nb1_greater(char *nb1, char *nb2)
{
    int inb1 = 0;
    int inb2 = 0;

    while (nb1[inb1] && nb2[inb2]) {
        if ((nb1[inb1] > nb2[inb2]) && (my_strlen(nb1) >= my_strlen(nb2)))
            return (1);
        if ((nb1[inb1] < nb2[inb2]) && (my_strlen(nb1) <= my_strlen(nb2)))
            return (0);
        inb1 += 1;
        inb2 += 1;
    }
    if (nb1[inb1] >= nb2[inb2])
        return (1);
    return (0);
}

int sub_nbrs(int nb1, int nb2, int neg1, int neg2)
{
    int res = 0;

    nb1 = neg1 ? -nb1 : nb1;
    nb2 = neg2 ? -nb2 : nb2;
    res = nb1 - nb2;
    if (neg1)
        return (-res);
    else
        return (res);
    return (res);
}

int add_nbrs(int nb1, int nb2, int neg1, int neg2)
{
    int res = 0;

    nb1 = neg1 ? -nb1 : nb1;
    nb2 = neg2 ? -nb2 : nb2;
    res = nb1 + nb2;
    if (neg1)
        return (-res);
    else
        return (res);
    return (res);
}