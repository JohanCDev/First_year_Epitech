/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Checks if an element is in the map
*/

#include "libmy/collections/hash_map.h"

MY_COLLECTIONS_API int my_hash_map_contains(
    my_hash_map_t *map, void const *key)
{
    my_hash_map_entry_t *entry;

    assert(map != NULL);
    assert(key != NULL);
    if (map->buckets == NULL)
        return 0;
    entry = map->buckets[my_hash_map_hash_key(map, key) % map->capacity];
    while (entry != NULL && (*map->compare)(key, P_MY_HM_KEY(map, entry)))
        entry = entry->next;
    return entry != NULL;
}
