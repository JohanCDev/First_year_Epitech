/*
** EPITECH PROJECT, 2021
** LibMy - hash module
** File description:
** Finishes the hash process
*/

#include "hash.h"
#include "libmy/hash.h"

MY_HASH_API my_u64_t my_hasher_finish(my_hasher_t const *hasher_outer)
{
    p_my_hasher_t hasher = hasher_outer->inner;
    my_u64_t data = ((((my_u64_t)hasher.length) & 0xff) << 56) | hasher.tail;

    hasher.state_3 ^= data;
    p_my_siphash13_c_rounds(&hasher);
    hasher.state_0 ^= data;
    hasher.state_2 ^= 0xff;
    p_my_siphash13_d_rounds(&hasher);
    return hasher.state_0 ^ hasher.state_1 ^ hasher.state_2 ^ hasher.state_3;
}
