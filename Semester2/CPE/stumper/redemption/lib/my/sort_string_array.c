/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** sort_string_array
*/

#include <stdlib.h>
#include "my.h"

void check_if_swap_str_needed(char **str1, char **str2)
{
    if (my_strcmp(*str1, *str2) > 0) {
        my_swap_str(str1, str2);
    }
}

unsigned int get_size_array_string(char **array)
{
    unsigned int size = 0;

    while (array[size])
        size++;
    return (size);
}

char **sort_string_array(char **array)
{
    unsigned int size = get_size_array_string(array);

    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size - i - 1; j++)
            check_if_swap_str_needed(&array[j], &array[j + 1]);
    return (array);
}