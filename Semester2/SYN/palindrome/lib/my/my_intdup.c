/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** $
*/

#include <stdlib.h>

int *my_intdup(int nb)
{
    int *int_to_ret = malloc(sizeof(int));

    if (int_to_ret == NULL)
        return (NULL);
    *int_to_ret = nb;
    return (int_to_ret);
}

int *my_intdup_ptr(int *nb)
{
    int *int_to_ret = malloc(sizeof(int));

    if (int_to_ret == NULL)
        return NULL;
    *int_to_ret = *nb;
    return int_to_ret;
}