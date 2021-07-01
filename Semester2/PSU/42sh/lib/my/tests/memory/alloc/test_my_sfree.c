/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_sfree function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_sfree, base)
{
    char *data = malloc(sizeof(char) * 15);

    cr_assert_neq(NULL, data);
    my_memcpy(data, "This is a test", 15);
    cr_assert_eq(NULL, my_sfree((void **)&data));
}
