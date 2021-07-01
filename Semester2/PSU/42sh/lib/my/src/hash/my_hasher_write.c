/*
** EPITECH PROJECT, 2021
** LibMy - hash module
** File description:
** Writes data to be hashed
*/

#include "hash.h"
#include "libmy/core.h"
#include "libmy/hash.h"
#include "libmy/memory.h"

static my_u64_t hash_load_u64(unsigned char const *buf, size_t start)
{
    my_m64_t out = {0};

    out.data[0] = buf[start];
    out.data[1] = buf[start + 1];
    out.data[2] = buf[start + 2];
    out.data[3] = buf[start + 3];
    out.data[4] = buf[start + 4];
    out.data[5] = buf[start + 5];
    out.data[6] = buf[start + 6];
    out.data[7] = buf[start + 7];
    return (my_u64_t)my_u64_to_le(out.num);
}

static size_t my_hasher_write_flush(
    p_my_hasher_t *hasher, size_t size, void const *data)
{
    size_t needed = 0;

    hasher->length += size;
    if (hasher->ntail != 0) {
        needed = 8 - hasher->ntail;
        hasher->tail |= p_my_hash_load_from_mem(data, 0, MY_MIN(size, needed))
            << 8 * hasher->ntail;
        if (size < needed) {
            hasher->ntail += size;
            return SIZE_MAX;
        }
        hasher->state_3 ^= hasher->tail;
        p_my_siphash13_c_rounds(hasher);
        hasher->state_0 ^= hasher->tail;
        hasher->ntail = 0;
    }
    return needed;
}

static void my_hasher_write_data(
    p_my_hasher_t *hasher, size_t size, void const *data, size_t needed)
{
    size_t length = size - needed;
    size_t left = length & 7;
    size_t i = needed;

    while (i < length - left) {
        size_t mi = hash_load_u64(data, i);

        hasher->state_3 ^= mi;
        p_my_siphash13_c_rounds(hasher);
        hasher->state_0 ^= mi;
        i += 8;
    }
    hasher->tail = p_my_hash_load_from_mem(data, i, left);
    hasher->ntail = left;
}

MY_HASH_API void my_hasher_write(
    my_hasher_t *hasher_outer, size_t size, void const *data)
{
    p_my_hasher_t *hasher = &hasher_outer->inner;
    size_t needed = my_hasher_write_flush(hasher, size, data);

    if (needed != SIZE_MAX)
        my_hasher_write_data(hasher, size, data, needed);
}

MY_HASH_API void my_hasher_write_cstr(my_hasher_t *hasher, char const *str)
{
    size_t len;

    if (str == NULL)
        return;
    len = (char *)my_memchr(str, 0, SIZE_MAX) - str;
    if (len > 0)
        my_hasher_write(hasher, len, str);
}
