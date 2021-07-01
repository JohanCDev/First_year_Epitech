/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** swap_func
*/

#include "mydb.h"
#include <string.h>
#include <stdlib.h>

void swap_numbers(int *int_1, int *int_2)
{
    if (*int_1 > *int_2) {
        int stock = *int_1;

        *int_1 = *int_2;
        *int_2 = stock;
    }
}

void swap_str(char **str1, char **str2)
{
    char *tmp = malloc(sizeof(char) * 128);

    if (strcmp(*str1, *str2) > 0) {
        strcpy(tmp, *str1);
        strcpy(*str1, *str2);
        strcpy(*str2, tmp);
    }
    my_free_str(tmp);
}