/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Finds an element in a sorted array
*/

#include <stdint.h>
#include "libmy/memory.h"

static int do_cmp(
    my_array_t const *array, void const *to_find, size_t pos, int (*cmp)())
{
    return (*cmp)(
        to_find, (void *)(((char *)array->data) + (pos * array->elem_size)));
}

static size_t array_offset(my_array_t const *base, my_array_t const *shifted)
{
    return (size_t)((uintptr_t)shifted->data - (uintptr_t)base->data)
        / base->elem_size;
}

MY_MEMORY_API size_t my_binary_search(
    my_array_t const *array_param, void const *to_find, int (*cmp)())
{
    my_array_t array = *array_param;

    if (!array.data || !cmp)
        return SIZE_MAX;
    while (array.length != 0) {
        size_t mid = array.length / 2;
        int comparison = do_cmp(&array, to_find, mid, cmp);

        if (comparison == 0)
            return array_offset(array_param, &array) + mid;
        if (comparison < 0) {
            array.length = mid;
            continue;
        } else if (mid + 1 >= array.length) {
            return SIZE_MAX;
        }
        array.data = (char *)array.data + array.elem_size * (mid + 1);
        array.length -= mid + 1;
    }
    return SIZE_MAX;
}
