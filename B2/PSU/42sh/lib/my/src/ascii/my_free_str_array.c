/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Frees an array of strings
*/

#include <stdlib.h>
#include "libmy/ascii.h"

MY_ASCII_API void my_free_str_array(char *array[], int len)
{
    if (!array)
        return;
    for (int i = 0; i < len; ++i)
        if (array[i])
            free(array[i]);
    free(array);
}
