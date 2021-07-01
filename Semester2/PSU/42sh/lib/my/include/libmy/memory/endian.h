/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Endian-related utilities
*/

/// @file
/// Endian-releated utilities.
///
/// @since 0.3.2

#ifndef __LIBMY_MEMORY_ENDIAN_H__
#define __LIBMY_MEMORY_ENDIAN_H__

#include "libmy/memory/config.h"

MY_API_BEGIN

#include "libmy/internal/memory.h"

#if LIBMY_ENDIAN == LIBMY_LITTLE_ENDIAN
/// Converts a native-endian 16-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u16_t my_u16_to_le(my_u16_t num)
{
    return num;
}

/// Converts a native-endian 32-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u32_t my_u32_to_le(my_u32_t num)
{
    return num;
}

/// Converts a native-endian 64-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_to_le(my_u64_t num)
{
    return num;
}

/// Converts a native-endian 16-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u16_t my_u16_to_be(my_u16_t num)
{
    my_m16_t n = {.num = num};

    return ((my_m16_t){.data = {n.data[1], n.data[0]}}).num;
}

/// Converts a native-endian 32-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u32_t my_u32_to_be(my_u32_t num)
{
    my_m32_t n = {.num = num};

    return ((my_m32_t){.data = {n.data[3], n.data[2], n.data[1], n.data[0]}})
        .num;
}

/// Converts a native-endian 64-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_to_be(my_u64_t num)
{
    my_m64_t n = {.num = num};
    my_m64_t res = {.data = {n.data[7], n.data[6], n.data[5], n.data[4],
                        n.data[3], n.data[2], n.data[1], n.data[0]}};

    return res.num;
}
#elif LIBMY_ENDIAN == LIBMY_BIG_ENDIAN
/// Converts a native-endian 16-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u16_t my_u16_to_le(my_u16_t num)
{
    my_m16_t n = {.num = num};

    return ((my_m16_t){.data = {n.data[1], n.data[0]}}).num;
}

/// Converts a native-endian 32-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u32_t my_u32_to_le(my_u32_t num)
{
    my_m32_t n = {.num = num};

    return ((my_m32_t){.data = {n.data[3], n.data[2], n.data[1], n.data[0]}})
        .num;
}

/// Converts a native-endian 64-bit unsigned integer to little endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to little endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_to_le(my_u64_t num)
{
    my_m64_t n = {.num = num};
    my_m64_t res = {.data = {n.data[7], n.data[6], n.data[5], n.data[4],
                        n.data[3], n.data[2], n.data[1], n.data[0]}};

    return res.num;
}

/// Converts a native-endian 16-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u16_t my_u16_to_be(my_u16_t num)
{
    return num;
}

/// Converts a native-endian 32-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u32_t my_u32_to_be(my_u32_t num)
{
    return num;
}

/// Converts a native-endian 64-bit unsigned integer to big endian.
///
/// @param num The integer.
///
/// @returns The integer, converted to big endian if neccessary.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_to_be(my_u64_t num)
{
    return num;
}
#else
    #error "LibMy memory module requires LIBMY_ENDIAN to be set to either \
        LIBMY_LITTLE_ENDIAN or LIBMY_BIG_ENDIAN to be defined"
#endif

MY_API_END

#endif // !defined(__LIBMY_MEMORY_ENDIAN_H__)
