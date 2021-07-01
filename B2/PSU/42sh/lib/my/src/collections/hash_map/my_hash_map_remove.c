/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Removes an entry from the hash map
*/

#include "libmy/memory/alloc.h"
#include "libmy/collections/hash_map.h"

static void my_hash_map_drop_kv(my_hash_map_t *map, my_hash_map_entry_t *entry)
{
    if (map->key_drop)
        (*map->key_drop)(P_MY_HM_KEY(map, entry));
    if (map->value_drop)
        (*map->value_drop)(P_MY_HM_VAL(map, entry));
}

MY_COLLECTIONS_API int my_hash_map_remove(my_hash_map_t *map, void const *key)
{
    my_hash_map_entry_t **entry;

    assert(map != NULL);
    assert(key != NULL);
    if (map->buckets == NULL)
        return 0;
    entry = &map->buckets[my_hash_map_hash_key(map, key) % map->capacity];
    while (*entry != NULL && (*map->compare)(key, P_MY_HM_KEY(map, *entry)))
        entry = &(*entry)->next;
    if (*entry == NULL)
        return 0;
    my_hash_map_drop_kv(map, *entry);
    my_sfree((void **)entry);
    --(map->length);
    return 1;
}
