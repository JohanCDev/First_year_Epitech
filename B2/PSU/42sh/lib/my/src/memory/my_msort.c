/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Sorts an array with merge sort.
*/

#include "libmy/memory.h"

static size_t split(size_t dims[3], size_t beg[2])
{
    size_t mid = mid = (dims[1] + dims[2]) / 2;

    beg[0] = dims[1];
    beg[1] = mid + 1;
    return mid;
}

// "copy to work array", shortened name due to restrictions...
static void c2wa(void *dst, void const *src, size_t size, size_t *begin)
{
    my_memcpy(dst, src, size);
    ++(*begin);
}

// This function code is serverly mangled due
// to the *Coding Style* restrictions...
//
// parameters:
// da = destination array,
// db = work array,
// dims = {
//     size = size of an element,
//     start = start of da/db,
//     end = end of da/db
// },
// cmp = comparator function
static void merge_sort(char *da, char *db, size_t dims[3], my_comparator_t cmp)
{
    size_t mid;
    size_t beg[2];

    if (dims[2] <= dims[1])
        return;
    mid = split(dims, beg);
    merge_sort(da, db, (size_t[3]){dims[0], dims[1], mid}, cmp);
    merge_sort(da, db, (size_t[3]){dims[0], mid + 1, dims[2]}, cmp);
    beg[0] = dims[1];
    beg[1] = mid + 1;
    for (size_t i = dims[1]; i <= dims[2]; ++i) {
        if (beg[0] == mid + 1
            || (beg[1] != dims[2] + 1
                && (*cmp)(da + beg[0] * dims[0], da + beg[1] * dims[0]) >= 0))
            c2wa(db + i * dims[0], da + beg[1] * dims[0], dims[0], beg + 1);
        else
            c2wa(db + i * dims[0], da + beg[0] * dims[0], dims[0], beg);
    }
    my_memcpy(da + dims[1] * dims[0], db + dims[1] * dims[0],
        (dims[2] - dims[1] + 1) * dims[0]);
}

MY_MEMORY_API void my_msort(
    void *data[2], size_t nmemb, size_t size, my_comparator_t cmp)
{
    if (nmemb <= 1)
        return;
    merge_sort(data[0], data[1], (size_t[3]){size, 0, nmemb - 1}, cmp);
}
