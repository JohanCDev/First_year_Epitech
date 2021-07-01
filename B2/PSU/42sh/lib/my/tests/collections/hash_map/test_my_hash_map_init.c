/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the hash map init functions
*/

#include <stdalign.h>
#include <criterion/criterion.h>

#include "libmy/collections/hash_map.h"

Test(my_hash_map_init, base)
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

    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
}

Test(my_hash_map_init_capacity, zero_key_size)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = 0,
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(
        MY_MAP_INVALID_KVTYPES, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, zero_key_align)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = 0,
        .value_size = sizeof(int),
        .value_align = sizeof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(
        MY_MAP_INVALID_KVTYPES, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, zero_value_align)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = 0,
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(
        MY_MAP_INVALID_KVTYPES, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, null_compare_function)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = alignof(int),
        .compare = NULL,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(
        MY_MAP_INVALID_KVTYPES, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, null_hash_function)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = alignof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = NULL,
    };

    cr_assert_eq(
        MY_MAP_INVALID_KVTYPES, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, unaligned_key_values)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = 1,
        .key_align = 47,
        .value_size = 1,
        .value_align = 13,
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 0));
}

Test(my_hash_map_init_capacity, large_capacity)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = alignof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(MY_MAP_ALLOC,
        my_hash_map_init_capacity(&map, &kvtypes, SIZE_MAX / sizeof(void *)));
}

Test(my_hash_map_init_capacity, normal_capacity)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes = {
        .key_size = sizeof(char *),
        .key_align = alignof(char *),
        .value_size = sizeof(int),
        .value_align = alignof(int),
        .compare = MY_HASH_MAP_CSTR_CMP,
        .hash = MY_HASH_MAP_CSTR_HASH,
    };

    cr_assert_eq(MY_MAP_OK, my_hash_map_init_capacity(&map, &kvtypes, 16));
    my_hash_map_drop(&map);
}
