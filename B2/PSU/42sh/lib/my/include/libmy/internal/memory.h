/*
** EPITECH PROJECT, 2020
** LibMy - memory module internals
** File description:
** The internals for the memory module
*/

#ifndef __LIBMY_INTERNAL_MEMORY_H__
#define __LIBMY_INTERNAL_MEMORY_H__

#include "libmy/internal/attributes.h"

MY_API_BEGIN

#include "libmy/internal/types.h"
#include "libmy/memory/cbuffer.h"

typedef union {
    my_u8_t data[2];
    my_u16_t num;
} my_m16_t;

typedef union {
    my_u8_t data[4];
    my_u32_t num;
} my_m32_t;

typedef union {
    my_u8_t data[8];
    my_u64_t num;
} my_m64_t;

MY_INLINE size_t my_cbuffer_wrap_add(
    my_cbuffer_t const *buf, size_t index, size_t to_add)
{
    if (index >= buf->cap - to_add)
        return to_add - (buf->cap - index);
    else
        return index + to_add;
}

MY_INLINE size_t my_cbuffer_wrap_sub(
    my_cbuffer_t const *buf, size_t index, size_t to_sub)
{
    if (to_sub > index)
        return buf->cap + index - to_sub;
    else
        return index - to_sub;
}

MY_API_END

#endif // !defined(__LIBMY_INTERNAL_MEMORY_H__)
