/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** get_size_array
*/

#include "my.h"

int get_size_array(void **array)
{
    int i = 0;

    while (array[i])
        i++;
    return (i);
}