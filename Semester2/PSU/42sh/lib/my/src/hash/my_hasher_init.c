/*
** EPITECH PROJECT, 2021
** Libmy - hash module
** File description:
** Creates a hasher from a pair of keys
*/

#include "libmy/hash.h"

MY_LOCAL void p_my_hasher_reset(p_my_hasher_t *hasher)
{
    hasher->length = 0;
    hasher->ntail = 0;
    hasher->state_0 = hasher->key_1 ^ 0x736f6d6570736575;
    hasher->state_1 = hasher->key_2 ^ 0x646f72616e646f6d;
    hasher->state_2 = hasher->key_1 ^ 0x6c7967656e657261;
    hasher->state_3 = hasher->key_2 ^ 0x7465646279746573;
}

MY_HASH_API void my_hasher_init(
    my_hasher_t *hasher_outer, my_u64_t key_1, my_u64_t key_2)
{
    p_my_hasher_t *hasher = &hasher_outer->inner;

    hasher->key_1 = key_1;
    hasher->key_2 = key_2;
    hasher->tail = 0;
    p_my_hasher_reset(hasher);
}
