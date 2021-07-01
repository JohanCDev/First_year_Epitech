/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_asprintf function
*/

#include <criterion/criterion.h>
#include "libmy/printf.h"

Test(my_asprintf, null_strp)
{
    cr_assert_eq(my_asprintf(NULL, "test"), 4);
}

Test(my_asprintf, normal)
{
    char *str;

    cr_assert_eq(my_asprintf(&str, "%d, the meaning of%5s.", 42, "life"), 24);
    cr_assert_str_eq(str, "42, the meaning of life.");
    free(str);
}
