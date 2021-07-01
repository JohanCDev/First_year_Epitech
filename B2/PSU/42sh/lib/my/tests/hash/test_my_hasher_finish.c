/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the hashing functions
*/

#include <criterion/criterion.h>
#include "libmy/hash.h"

Test(my_hasher_finish, zero_keys_42_zero_values)
{
    my_hasher_t hasher;
    char data[42] = {0};
    my_u64_t expected = 0xf5b4ade1dfc51c5e;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write(&hasher, 42, data);
    cr_assert_eq(my_hasher_finish(&hasher), expected);
}

Test(my_hasher_finish, zero_keys_random_values)
{
    my_hasher_t hasher;
    my_u64_t data_1 = 0x2b8c1ddbfdd1f8ef;
    my_u64_t data_2 = 0x3d14b7f4bb679;
    my_u64_t data_3 = 0xca1d371a080175d4;
    my_u64_t data_4 = 0xc450063d3698a9cd;
    my_u64_t expected = 0x99736224d984c188;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write(&hasher, 8, &data_1);
    my_hasher_write(&hasher, 8, &data_2);
    my_hasher_write(&hasher, 8, &data_3);
    my_hasher_write(&hasher, 8, &data_4);
    cr_assert_eq(my_hasher_finish(&hasher), expected);
}

Test(my_hasher_finish, random_keys_random_values)
{
    my_hasher_t hasher;
    my_u64_t data_1 = 0x2b8c1ddbfdd1f8ef;
    my_u64_t data_2 = 0x3d14b7f4bb679;
    my_u64_t data_3 = 0xca1d371a080175d4;
    my_u64_t data_4 = 0x3d3698a9cd;
    my_u64_t expected = 0xe1ef1aee2c01b528;

    my_hasher_init(&hasher, 0x62c1e04d4f1, 0x272fdd29a8902547);
    my_hasher_write(&hasher, 8, &data_1);
    my_hasher_write(&hasher, 8, &data_2);
    my_hasher_write(&hasher, 8, &data_3);
    my_hasher_write(&hasher, 5, &data_4);
    cr_assert_eq(my_hasher_finish(&hasher), expected);
}

Test(my_hasher_finish, random_keys_big_string_data)
{
    my_hasher_t hasher;
    char *data_1 =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
        "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char *data_2 =
        "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
        "nisi ut aliquip ex ea commodo consequat.";
    my_u64_t expected = 0x13204c427ffe442;

    my_hasher_init(&hasher, 0x62c1e04d4f1, 0x272fdd29a8902547);
    my_hasher_write(&hasher, 123, data_1);
    my_hasher_write(&hasher, 107, data_2);
    cr_assert_eq(my_hasher_finish(&hasher), expected);
}

Test(my_hasher_finish, random_keys_big_and_small_string_data)
{
    my_hasher_t hasher;
    char *data_1 =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
        "eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char *data_2 = "test";
    my_u64_t expected = 0xc5b6cd10be24e381;

    my_hasher_init(&hasher, 0x2ed8cb453caa, 0x5fb0eadc4051);
    my_hasher_write(&hasher, 123, data_1);
    my_hasher_write(&hasher, 4, data_2);
    cr_assert_eq(my_hasher_finish(&hasher), expected);
}
