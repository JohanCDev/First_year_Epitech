/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Inserts a key-value pair into a hash map
*/

#include "libmy/collections/hash_map.h"

MY_COLLECTIONS_API my_map_err_t my_hash_map_insert(
    my_hash_map_t *map, void *key, void *value)
{
    if (my_hash_map_insert_entry(map, key, value) != NULL || value == NULL)
        return MY_MAP_OK;
    return MY_MAP_ALLOC;
}
