/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** my_free_array
*/

#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
}