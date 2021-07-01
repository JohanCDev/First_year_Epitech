/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_hash_map_remove function
*/

#include <stdalign.h>
#include <stdlib.h>
#include <criterion/criterion.h>

#include "libmy/memory/memory.h"
#include "libmy/collections/hash_map.h"

static void init_kvtypes(my_map_kvtypes_t *kvtypes)
{
    *kvtypes = (my_map_kvtypes_t){
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(char *),
        .value_align = sizeof(char *),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };
}

static char *custom_strdup(char const *src)
{
    char const *terminator = my_memchr(src, '\0', SIZE_MAX);
    size_t size;
    char *dst;

    cr_assert_neq(NULL, terminator);
    size = terminator - src + 1;
    dst = malloc(sizeof(*dst) * size);
    cr_assert_neq(NULL, dst);
    my_memcpy(dst, src, size);
    return dst;
}

Test(my_hash_map_remove, empty_map)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "to remove";

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert_eq(0, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 16));
    cr_assert_eq(0, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_remove, not_present)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    char *value = "some value";

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 32));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "to remove";
    cr_assert_eq(0, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_remove, not_present_in_chain)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    char *value = "some value";

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    map.load_factor = 42;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "some other key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "to remove";
    cr_assert_eq(0, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_remove, is_present_in_chain)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    char *value = "some value";

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    map.load_factor = 42;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "some other key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "to remove";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(1, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_remove, present_allocated_key_and_value)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = custom_strdup("some key");
    char *value = custom_strdup("some value");

    init_kvtypes(&kvtypes);
    kvtypes.key_drop = MY_HASH_MAP_CSTR_DROP;
    kvtypes.value_drop = MY_HASH_MAP_CSTR_DROP;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(1, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_remove, present_allocated_key_and_value_in_chain)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = custom_strdup("some key");
    char *value = custom_strdup("some value");

    init_kvtypes(&kvtypes);
    kvtypes.key_drop = MY_HASH_MAP_CSTR_DROP;
    kvtypes.value_drop = MY_HASH_MAP_CSTR_DROP;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = custom_strdup("some other key");
    value = custom_strdup("some other value");
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(1, my_hash_map_remove(&map, &key));
    my_hash_map_drop(&map);
}
