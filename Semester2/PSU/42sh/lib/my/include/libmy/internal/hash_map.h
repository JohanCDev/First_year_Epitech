/*
** EPITECH PROJECT, 2021
** LibMy - collection module internals
** File description:
** The hash map internals
*/

#ifndef __LIBMY_INTERNAL_HASH_MAP_H__
#define __LIBMY_INTERNAL_HASH_MAP_H__

#include <stddef.h>
#include <stdint.h>
#include "libmy/internal/attributes.h"
#include "libmy/internal/types.h"
#include "libmy/collections/hash_map.h"

typedef struct p_my_hash_map_entry {
    my_u64_t hash;
    struct p_my_hash_map_entry *next;
    char kv;
} my_hash_map_entry_t;

#define P_MY_HM_KEY(m, e) ((void *)(((char *)(e)) + (m)->key_offset))
#define P_MY_HM_VAL(m, e) ((void *)(((char *)(e)) + (m)->value_offset))

MY_INLINE int p_my_map_kvtypes_is_valid(my_map_kvtypes_t const *kvtypes)
{
    return kvtypes->key_size > 0 && kvtypes->key_align > 0
        && kvtypes->value_align > 0 && kvtypes->compare != NULL;
}

MY_LOCAL int p_my_hash_map_init_buckets(my_hash_map_t *map);

MY_COLLECTIONS_API void p_my_hash_map_cstr_drop(char **str);
MY_COLLECTIONS_API int p_my_hash_map_cstr_cmp(char **str_1, char **str_2);
MY_COLLECTIONS_API void p_my_hash_map_cstr_hash(
    my_hasher_t *hasher, char **str);

#endif // !defined(__LIBMY_INTERNAL_HASH_MAP_H__)
