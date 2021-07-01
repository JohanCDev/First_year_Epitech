/*
** EPITECH PROJECT, 2021
** LibMy - hash module
** File description:
** The main header for the hash module
*/

/// @file
///
/// Various hashing-related utilities
/// @since 0.2.0

#ifndef __LIBMY_HASH_HASH_H__
#define __LIBMY_HASH_HASH_H__

#include "libmy/hash/config.h"

MY_API_BEGIN

#include "libmy/internal/hash.h"

/// SipHasher13-based hasher
/// @since 0.2.0
typedef union {
    /// @private
    p_my_hasher_t inner;
} my_hasher_t;

/// Initializes the passed hasher with the given keys @c key_1 and @c key_2.
///
/// @param hasher The hasher to initialize.
/// @param key_1 The first key.
/// @param key_2 The second key.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_init(
    my_hasher_t *hasher, my_u64_t key_1, my_u64_t key_2);

/// Writes @c size bytes of @c data to the given hasher.
///
/// @param hasher The hasher.
/// @param size The number of bytes to write to @c hasher.
/// @param data A pointer to the data to write, must be at least @c size bytes
/// long.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write(
    my_hasher_t *hasher, size_t size, void const *data);

/// Finishes the hashing process and returns the final hash value.
///
/// @param hasher The hasher.
///
/// @returns The final 64-bit hash value.
/// @since 0.2.0
MY_HASH_API my_u64_t my_hasher_finish(my_hasher_t const *hasher);

/// Writes a null-terminated string to the given hasher.
///
/// @param hasher The hasher.
/// @param str A null-terminated string.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_cstr(my_hasher_t *hasher, char const *str);

/// Writes a byte to the given hasher.
///
/// @param hasher The hasher.
/// @param num The byte.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_u8(my_hasher_t *hasher, my_u8_t num);

/// Writes two bytes in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_u16(my_hasher_t *hasher, my_u16_t num);

/// Writes four bytes in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_u32(my_hasher_t *hasher, my_u32_t num);

/// Writes eight bytes in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_u64(my_hasher_t *hasher, my_u64_t num);

/// Writes an unsigned short in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_ushort(
    my_hasher_t *hasher, unsigned short num);

/// Writes an unsigned int in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_uint(my_hasher_t *hasher, unsigned int num);

/// Writes an unsigned long in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_ulong(my_hasher_t *hasher, unsigned long num);

/// Writes an unsigned long long in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_ulong_long(
    my_hasher_t *hasher, unsigned long long num);

/// Writes a size_t in native endian to the given hasher.
///
/// @param hasher The hasher.
/// @param num The bytes.
///
/// @since 0.2.0
MY_HASH_API void my_hasher_write_size_t(my_hasher_t *hasher, size_t num);

MY_API_END

#endif // !defined(__LIBMY_HASH_HASH_H__)
