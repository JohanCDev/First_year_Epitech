/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Checks if a key-value pair is present in the hash map
*/

#include <stdalign.h>
#include <criterion/criterion.h>

#include "libmy/collections/hash_map.h"

Test(my_hash_map_contains, not_present_empty_map)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };
    char const *key = "to find";

    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert(!my_hash_map_contains(&map, &key));
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 16));
    cr_assert(!my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_contains, not_present_map_with_one_item)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };
    char const *key = "some key";
    int value = 42;

    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 1));
    map.load_factor = 42.0;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "to find";
    cr_assert(!my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_contains, present)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };
    char const *key = "to find";
    int value = 42;

    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert(my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}
