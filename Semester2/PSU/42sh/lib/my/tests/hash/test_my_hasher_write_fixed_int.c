/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the fixed-size integer hashing functions
*/

#include <criterion/criterion.h>
#include "libmy/hash.h"

Test(my_hasher_write_ux, base)
{
    my_hasher_t hasher;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write_u8(&hasher, 0x2a);
    cr_assert_eq(my_hasher_finish(&hasher), 0xdec44d52172e44d4);
    my_hasher_write_u16(&hasher, 0xb9e0);
    cr_assert_eq(my_hasher_finish(&hasher), 0x8744cc37363503);
    my_hasher_write_u32(&hasher, 0x65c08efd);
    cr_assert_eq(my_hasher_finish(&hasher), 0x2eb8e0d29ac18894);
    my_hasher_write_u64(&hasher, 0x6c5de4069206a66d);
    cr_assert_eq(my_hasher_finish(&hasher), 0x649997c38b65b63);
}
