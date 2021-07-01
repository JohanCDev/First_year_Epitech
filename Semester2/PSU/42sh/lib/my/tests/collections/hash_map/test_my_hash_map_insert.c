/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_hash_map_insert function
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
        .value_size = sizeof(int),
        .value_align = sizeof(int),
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

static void bad_hash_function(my_hasher_t *hasher, void const *value)
{
    my_hasher_write_u32(hasher, 42);
    (void)value;
}

Test(my_hash_map_insert, null_value)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    int value = 42;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert(my_hash_map_contains(&map, &key));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, NULL));
    cr_assert(!my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_insert, map_growth)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    int value = 42;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 16));
    map.load_factor = 0;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "some other key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "yet another key";
    cr_assert_neq(NULL, my_hash_map_insert_entry(&map, &key, &value));
    cr_assert(my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_insert, map_growth_with_collisions)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    int value = 42;

    init_kvtypes(&kvtypes);
    kvtypes.hash = &bad_hash_function;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 1));
    map.load_factor = 1;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "some other key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    key = "yet another key";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert(my_hash_map_contains(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_insert, update_value)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    int value = 42;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 1));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    value = 21;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(21, *(int *)my_hash_map_get(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_insert, update_value_null_key)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = NULL;
    int value = 42;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 1));
    map.load_factor = 42.0;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    value = 21;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(21, *(int *)my_hash_map_get(&map, &key));
    key = "";
    value = -42;
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(-42, *(int *)my_hash_map_get(&map, &key));
    key = "other";
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_eq(-42, *(int *)my_hash_map_get(&map, &key));
    my_hash_map_drop(&map);
}

Test(my_hash_map_insert, update_allocated_value)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    char *key = "some key";
    char *value = custom_strdup("some value");

    init_kvtypes(&kvtypes);
    kvtypes.value_size = alignof(char *);
    kvtypes.value_align = alignof(char *);
    kvtypes.value_drop = MY_HASH_MAP_CSTR_DROP;
    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 1));
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    value = custom_strdup("...");
    cr_assert_eq(MY_MAP_OK, my_hash_map_insert(&map, &key, &value));
    cr_assert_str_eq("...", *(char **)my_hash_map_get(&map, &key));
    my_hash_map_drop(&map);
}
