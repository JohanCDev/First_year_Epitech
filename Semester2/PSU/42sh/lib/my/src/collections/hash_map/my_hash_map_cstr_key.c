/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Functions to operate on null-terminated string keys
*/

#include "libmy/memory/alloc.h"
#include "libmy/collections/hash_map.h"

MY_COLLECTIONS_API void p_my_hash_map_cstr_drop(char **str)
{
    assert(str != NULL);
    my_sfree((void **)str);
}

// Only checks for string equality without returning the proper comparision.
// We do not use my_strcmp to to avoid the ascii module dependency.
//
// returns 1 if both strings are equal
static int p_my_hash_map_cstr_eq(char const *s1, char const *s2)
{
    if (!s1 != !s2)
        return 0;
    if (s1 == s2)
        return 1;
    while (*s1 && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return *s1 == *s2;
}

MY_COLLECTIONS_API int p_my_hash_map_cstr_cmp(char **str_1, char **str_2)
{
    assert(str_1 != NULL);
    assert(str_2 != NULL);
    return !p_my_hash_map_cstr_eq(*str_1, *str_2);
}

MY_COLLECTIONS_API void p_my_hash_map_cstr_hash(
    my_hasher_t *hasher, char **str)
{
    assert(hasher != NULL);
    assert(str != NULL);
    my_hasher_write_cstr(hasher, *str);
}
