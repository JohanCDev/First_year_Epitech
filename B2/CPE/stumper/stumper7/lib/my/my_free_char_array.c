/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_free_char_array.c
*/

#include "my.h"

void my_free_char_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}