/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Initializes hash maps
*/

#include <stdlib.h>

#include "libmy/memory.h"
#include "libmy/collections/hash_map.h"

MY_LOCAL int p_my_hash_map_init_buckets(my_hash_map_t *map)
{
    map->capacity = 16;
    map->buckets = my_calloc(16, sizeof(*map->buckets));
    return map->buckets == NULL;
}

MY_COLLECTIONS_API my_map_err_t my_hash_map_init(
    my_hash_map_t *map, my_map_kvtypes_t const *kvtypes)
{
    return my_hash_map_init_capacity(map, kvtypes, 0);
}

/// Adjusts the given capacity to the next-power of two
static size_t my_hash_map_adjust_capacity(size_t capacity)
{
    capacity -= 1;
    capacity |= capacity >> 1;
    capacity |= capacity >> 2;
    capacity |= capacity >> 4;
    capacity |= capacity >> 8;
    capacity |= capacity >> 16;
    if (sizeof(size_t) > 4)
        capacity |= capacity >> 32;
    return capacity + 1;
}

/// Computes offsets for the key and value fields of an entry.
static void my_hash_map_set_offsets(
    my_hash_map_t *map, my_map_kvtypes_t const *kvtypes)
{
    size_t kvoffset = offsetof(my_hash_map_entry_t, kv);
    size_t d = kvtypes->key_align - kvoffset % kvtypes->key_align;

    map->key_offset = (d == kvtypes->key_align ? 0 : d) + kvoffset;
    d = kvtypes->value_align - kvtypes->key_size % kvtypes->value_align;
    map->value_offset =
        (d == kvtypes->value_align ? 0 : d) + map->key_size + map->key_offset;
}

MY_COLLECTIONS_API my_map_err_t my_hash_map_init_capacity(
    my_hash_map_t *map, my_map_kvtypes_t const *kvtypes, size_t capacity)
{
    assert(map != NULL);
    assert(kvtypes != NULL);
    if (!p_my_map_kvtypes_is_valid(kvtypes) || kvtypes->hash == NULL)
        return MY_MAP_INVALID_KVTYPES;
    capacity = my_hash_map_adjust_capacity(capacity);
    *map = (my_hash_map_t){
        .capacity = capacity,
        .load_factor = .75,
        .buckets = my_calloc(capacity, sizeof(void *)),
        .key_size = kvtypes->key_size,
        .value_size = kvtypes->value_size,
        .hash = kvtypes->hash,
        .compare = kvtypes->compare,
        .key_drop = kvtypes->key_drop,
        .value_drop = kvtypes->value_drop,
    };
    my_hash_map_set_offsets(map, kvtypes);
    if (capacity > 0 && map->buckets == NULL)
        return MY_MAP_ALLOC;
    return MY_MAP_OK;
}
