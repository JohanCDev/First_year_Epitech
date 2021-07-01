/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_hash_map_iter function
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

static const char *DATA[][2] = {
    {"some key", "some value"},
    {"volume", "14"},
    {"name", "LibMy unit test"},
    {"cStandard", "c11"},
    {"", ""},
    {"key_size", "sizeof(char *)"},
    {"key_align", "alignof(char *)"},
    {"value_size", "sizeof(char *)"},
    {"value_align", "sizeof(char *)"},
    {"compare", "MY_HASH_MAP_CSTR_CMP"},
    {"hash", "MY_HASH_MAP_CSTR_HASH"},
    {NULL, NULL},
};

static int find_kv(char const *key, char const *value)
{
    if (key == NULL || value == NULL)
        return 0;
    for (size_t i = 0; DATA[i][0] != NULL; ++i)
        if (DATA[i][0] == key)
            return DATA[i][1] == value;
    return 0;
}

Test(my_hash_map_iter, base)
{
    my_hash_map_t map;
    my_map_kvtypes_t kvtypes;
    my_hash_map_iter_t iter;

    init_kvtypes(&kvtypes);
    cr_assert_eq(MY_MAP_OK, my_hash_map_init(&map, &kvtypes));
    for (size_t i = 0; DATA[i][0] != NULL; ++i)
        cr_assert_eq(MY_MAP_OK,
            my_hash_map_insert(
                &map, (void *)&DATA[i][0], (void *)&DATA[i][1]));
    my_hash_map_iter_init(&iter, &map);
    while (my_hash_map_iter_next(&iter)) {
        cr_assert_neq(NULL, iter.key);
        cr_assert_neq(NULL, iter.value);
        cr_assert(find_kv(*(char **)iter.key, *(char **)iter.value));
    }
    cr_assert(!my_hash_map_iter_has_next(&iter));
    cr_assert(!my_hash_map_iter_next(&iter));
    my_hash_map_drop(&map);
}
