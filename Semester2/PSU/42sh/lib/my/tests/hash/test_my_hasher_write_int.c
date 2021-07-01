/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the integer hashing functions
*/

#include <criterion/criterion.h>
#include "libmy/hash.h"

// Cannot test the exact hash values because of variying width
Test(my_hasher_write_uints, base)
{
    my_hasher_t hasher;

    my_hasher_init(&hasher, 0, 0);
    my_hasher_write_ushort(&hasher, 0x2a);
    my_hasher_write_uint(&hasher, 0xb9e0);
    my_hasher_write_ulong(&hasher, 0x65c08efd);
    my_hasher_write_ulong_long(&hasher, 0x6c5de4069206a66d);
    my_hasher_write_size_t(&hasher, 0x4496);
}
