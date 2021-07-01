/*
** EPITECH PROJECT, 2021
** LibMy - collections modile
** File description:
** Computes the hash of a key
*/

#include "libmy/collections/hash_map.h"

MY_COLLECTIONS_API my_u64_t my_hash_map_hash_key(
    my_hash_map_t const *map, void const *key)
{
    my_hasher_t hasher;

    assert(map != NULL);
    assert(key != NULL);
    my_hasher_init(&hasher, map->hasher_key_1, map->hasher_key_2);
    (*map->hash)(&hasher, key);
    return my_hasher_finish(&hasher);
}
