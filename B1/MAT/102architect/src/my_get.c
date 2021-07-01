/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-102architect-johan.chrillesen
** File description:
** my_get
*/

#include "architect.h"

char get_transformation(char *str)
{
    int i = 1;

    if (str[0] != '-')
        return (0);
    while (str[i]) {
        if (str[1] == 't' || str[1] == 'z' || str[1] == 'r' || str[1] == 's')
            i++;
        else
            return (0);
    }
    if (i != 2)
        return (0);
    return (str[1]);
}