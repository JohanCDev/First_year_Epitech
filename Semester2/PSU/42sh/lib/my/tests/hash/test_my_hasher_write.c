/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_hasher_write function
*/

#include <criterion/criterion.h>
#include "libmy/hash.h"

Test(my_hasher_write_cstr, empty_str)
{
    my_hasher_t hasher;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write_cstr(&hasher, NULL);
    cr_assert_eq(my_hasher_finish(&hasher), 0xd1fba762150c532c);
    my_hasher_write_cstr(&hasher, "");
    cr_assert_eq(my_hasher_finish(&hasher), 0xd1fba762150c532c);
}

Test(my_hasher_write_cstr, normal_strings)
{
    my_hasher_t hasher;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write_cstr(&hasher, "This is a test");
    cr_assert_eq(my_hasher_finish(&hasher), 0x55496fb20caba205);
    my_hasher_write_cstr(&hasher, "Lorem Ipsum");
    cr_assert_eq(my_hasher_finish(&hasher), 0x766ad66758b4d03f);
    my_hasher_write_cstr(&hasher, "Robert'); DROP TABLE Students;");
    cr_assert_eq(my_hasher_finish(&hasher), 0x8baa521258e648c4);
}
