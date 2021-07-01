/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Swaps the passed two pointers
*/

#include <stdint.h>
#include "libmy/memory.h"

MY_MEMORY_API void my_swap_ptr(
    void const **restrict a, void const **restrict b)
{
    *a = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
    *b = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
    *a = (void *)((uintptr_t)*a ^ (uintptr_t)*b);
}
