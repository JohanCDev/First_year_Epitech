/*
** EPITECH PROJECT, 2021
** LibMy - hash module
** File description:
** Writes fixed-size integers to a hasher
*/

#include "libmy/hash.h"

MY_HASH_API void my_hasher_write_u8(my_hasher_t *hasher, my_u8_t num)
{
    my_hasher_write(hasher, 1, &num);
}

MY_HASH_API void my_hasher_write_u16(my_hasher_t *hasher, my_u16_t num)
{
    my_hasher_write(hasher, 2, &num);
}

MY_HASH_API void my_hasher_write_u32(my_hasher_t *hasher, my_u32_t num)
{
    my_hasher_write(hasher, 4, &num);
}

MY_HASH_API void my_hasher_write_u64(my_hasher_t *hasher, my_u64_t num)
{
    my_hasher_write(hasher, 8, &num);
}
