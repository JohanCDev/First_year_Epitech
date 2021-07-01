/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_free_str_array function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_free_str_array, null_array)
{
    my_free_str_array(NULL, 78);
}

Test(my_free_str_array, null_in_array)
{
    char **array = malloc(sizeof(*array) * 1);

    array[0] = NULL;
    my_free_str_array(array, 1);
}

Test(my_free_str_array, regular_str_array)
{
    char **array = malloc(sizeof(*array) * 4);

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");
    my_free_str_array(array, 4);
}

Test(my_free_str_array, str_array_with_null_elem)
{
    char **array = malloc(sizeof(*array) * 5);

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = NULL;
    array[4] = strdup("test");
    my_free_str_array(array, 5);
}
