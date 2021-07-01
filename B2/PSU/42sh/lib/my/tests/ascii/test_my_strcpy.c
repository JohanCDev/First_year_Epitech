/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strcpy function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strcpy, null_strings)
{
    my_strcpy(NULL, NULL);
}

Test(my_strcpy, null_src_string)
{
    char dest[42];

    my_strcpy(NULL, dest);
}

Test(my_strcpy, null_dest_string)
{
    my_strcpy("This is a test", NULL);
}

Test(my_strcpy, normal_buffer)
{
    char *src = "test";
    char dest[5];

    my_strcpy(dest, src);
    cr_assert(strcmp(dest, src) == 0);
}

Test(my_strcpy, bigger_buffer)
{
    char *src = "test";
    char dest[10];

    my_strcpy(dest, src);
    cr_assert(strcmp(dest, src) == 0);
}
