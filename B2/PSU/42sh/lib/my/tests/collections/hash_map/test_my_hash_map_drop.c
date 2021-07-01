/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the hash map drop function
*/

#include <stdalign.h>
#include <stdlib.h>
#include <criterion/criterion.h>

#include "libmy/memory.h"
#include "libmy/collections/hash_map.h"

static void init_kvtypes(my_map_kvtypes_t *kvtypes)
{
    *kvtypes = (my_map_kvtypes_t){
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };
}

static void bad_hash_function(my_hasher_t *hasher, void const *value)
{
    my_hasher_write_u32(hasher, 42);
    (void)value;
}

Test(my_hash_map_drop, empty_map)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    my_hash_map_drop(&map);
    map.buckets = (void *)"some random non-null address";
    my_hash_map_drop(&map);
}

Test(my_hash_map_drop, map_with_collisions)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    int value = 84;

    init_kvtypes(&kvtypes);
    kvtypes.hash = &bad_hash_function;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 16));
    map.load_factor = 42;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "some other key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    my_hash_map_drop(&map);
}

Test(my_hash_map_drop, map_with_allocated_keys_values)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = malloc(sizeof(*key) * 15);
    char *value = malloc(sizeof(*value) * 5);

    init_kvtypes(&kvtypes);
    kvtypes.value_size = sizeof(char *);
    kvtypes.value_align = alignof(char *);
    kvtypes.key_drop = MY_HASH_MAP_CSTR_DROP;
    kvtypes.value_drop = MY_HASH_MAP_CSTR_DROP;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 4));
    my_memcpy(key, "This is a test", 15);
    my_memcpy(value, "yeet", 5);
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = malloc(sizeof(*key) * 9);
    my_memcpy(key, "Some Key", 9);
    value = malloc(sizeof(*value) * 26);
    my_memcpy(value, "An allocated string value", 26);
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    my_hash_map_drop(&map);
}
