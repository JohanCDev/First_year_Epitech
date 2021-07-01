/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Inserts a key-value pair into a hash map
*/

#include <stdlib.h>

#include "libmy/memory.h"
#include "libmy/collections/hash_map.h"

static void my_hash_map_move_entry(
    my_hash_map_entry_t **buckets, size_t capacity, my_hash_map_iter_t *iter)
{
    my_hash_map_entry_t **loc;
    my_hash_map_entry_t *entry = (my_hash_map_entry_t *)iter->next_entry;

    my_hash_map_iter_next(iter);
    entry->next = NULL;
    loc = buckets + (entry->hash % capacity);
    while (*loc != NULL)
        loc = &(*loc)->next;
    *loc = entry;
}

static int my_hash_map_grow(my_hash_map_t *map)
{
    size_t capacity = map->capacity * 2;
    my_hash_map_entry_t **buckets = my_calloc(capacity, sizeof(*buckets));
    my_hash_map_iter_t iter;

    if (buckets == NULL)
        return 1;
    my_hash_map_iter_init(&iter, map);
    while (my_hash_map_iter_has_next(&iter))
        my_hash_map_move_entry(buckets, capacity, &iter);
    free(map->buckets);
    map->buckets = buckets;
    map->capacity = capacity;
    return 0;
}

static my_hash_map_entry_t *my_hash_update_entry(
    my_hash_map_t *map, my_hash_map_entry_t *entry, void *value_src)
{
    void *value_dst = my_hash_map_entry_value(map, entry);

    if (map->value_drop != NULL)
        (*map->value_drop)(value_dst);
    my_memcpy(value_dst, value_src, map->value_size);
    return entry;
}

static int my_hash_map_add_entry(
    my_hash_map_t *map, my_hash_map_entry_t **loc, void *kv[2], my_u64_t hash)
{
    *loc = malloc(map->value_offset + map->value_size);
    if (*loc == NULL)
        return 1;
    (*loc)->hash = hash;
    (*loc)->next = NULL;
    my_memcpy((void *)my_hash_map_entry_key(map, *loc), kv[0], map->key_size);
    my_memcpy(my_hash_map_entry_value(map, *loc), kv[1], map->value_size);
    ++(map->length);
    return 0;
}

MY_COLLECTIONS_API my_hash_map_entry_t *my_hash_map_insert_entry(
    my_hash_map_t *map, void *key, void *value)
{
    my_u64_t hash;
    my_hash_map_entry_t **loc;

    assert(map != NULL);
    if (value == NULL)
        return my_hash_map_remove(map, key) * 0 + NULL;
    if ((map->buckets == NULL && p_my_hash_map_init_buckets(map))
        || (map->length + 1 > map->load_factor * ((double)map->capacity)
            && my_hash_map_grow(map)))
        return NULL;
    hash = my_hash_map_hash_key(map, key);
    loc = map->buckets + (hash % map->capacity);
    while (*loc != NULL) {
        if ((*map->compare)(P_MY_HM_KEY(map, *loc), key) == 0)
            return my_hash_update_entry(map, *loc, value);
        loc = &(*loc)->next;
    }
    if (my_hash_map_add_entry(map, loc, (void *[2]){key, value}, hash))
        return NULL;
    return *loc;
}
