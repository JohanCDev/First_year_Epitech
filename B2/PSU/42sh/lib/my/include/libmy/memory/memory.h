/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** The memory module's main functions
*/

/// @file
///
/// The memory module's main functions
///
/// @since 0.3.0

#ifndef __LIBMY_MEMORY_MEMORY_H__
#define __LIBMY_MEMORY_MEMORY_H__

#include "libmy/memory/config.h"

MY_API_BEGIN

#include <assert.h>
#include <stddef.h>
#include "libmy/internal/types.h"

#include "libmy/internal/memory.h"

/// Array info.
/// @since 0.2.0
typedef struct {
    /// The data pointer, must be either @c NULL or point to a contigous array
    /// of elements of size @c elem_size.
    void *data;
    /// The number of elements in the array.
    size_t length;
    /// The size (in bytes) of an element.
    size_t elem_size;
} my_array_t;

/// Performs a binary search on a sorted pointer array.
///
/// @param array   The source array, must be sorted and be shorter
///                than @c SIZE_MAX.
/// @param to_find The element to find in @c array.
/// @param cmp     The comparison function,
///                takes @c to_find as the first parameter,
///                a pointer to the nth element in @c array
///                and returns an integer less than, equal to,
///                or greater than zero if @c to_find is found respectively
///                to be less than, to match, or be greater
///                than the second parameter.
///
/// @returns The position of found element, or @c SIZE_MAX if not found.
/// @since 0.2.0
MY_MEMORY_API size_t my_binary_search(
    my_array_t const *array, void const *to_find, int (*cmp)());

/// Copies @c n bytes from @c src to @c dest.
///
/// @param[out] dest The destination memory, must be a valid address.
/// @param src       The source memory, must be a valid address.
/// @param n         The number of bytes to copy.
///
/// @returns The passed @c dest pointer.
/// @since 0.1.0
MY_MEMORY_API void *my_memcpy(void *dest, const void *src, size_t n);

/// Copies @c n bytes from @c src to @c dest.
/// The memory areas may overlap.
///
/// @param[out] dest The destination memory, must be a valid address.
/// @param src       The source memory, must be a valid address.
/// @param n         The number of bytes to copy.
///
/// @returns The passed @c dest pointer.
/// @since 0.1.0
MY_MEMORY_API void *my_memmove(void *dest, const void *src, size_t n);

/// Swaps the contents of the given pointers @c a and @c b.
///
/// @param a The first memory location, pointed memory must be at least of
/// @c size bytes.
/// @param b The first memory location, pointed memory must be at least of
/// @c size bytes.
/// @param size The number of bytes to swap.
///
/// @since 0.3.5
MY_INLINE void my_memswap(void *restrict a, void *restrict b, size_t size)
{
    assert(a != b);
    for (size_t i = 0; i < size; ++i) {
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)b)[i] = ((char *)a)[i] ^ ((char *)b)[i];
        ((char *)a)[i] = ((char *)a)[i] ^ ((char *)b)[i];
    }
}

/// Reverses @c nmemb elements of size @c size in @c mem
///
/// @param mem A pointer to the memory area, must not be @c NULL.
/// @param nmemb The number of elements in @c data.
/// @param size  The size of an individual element of @c data.
///
/// @returns The passed @c mem pointer.
/// @since 0.3.5
MY_MEMORY_API void *my_memrev(void *mem, size_t nmemb, size_t size);

/// Swaps the two passed pointers, @c a and @c b must not alias.
///
/// @param a Set to the value of @c b.
/// @param b Set to the valud of @c a.
///
/// @since 0.1.0
MY_MEMORY_API void my_swap_ptr(
    void const **restrict a, void const **restrict b);

/// Fills the first @c size bytes of the memory area pointed to by @c mem
/// with the constant byte @c byte.
///
/// @param mem  The memory location, can be @c NULL.
/// @param byte The byte to write.
/// @param size The number of bytes to fill.
///
/// @returns A pointer to the memory area @c mem.
/// @since 0.1.0
MY_MEMORY_API void *my_memset(void *mem, unsigned char byte, size_t size);

/// Scans the given memory for a byte.
///
/// @param mem A pointer to the memory area, must not be @c NULL.
/// @param byte The byte to find in @c mem.
/// @param length The maximum size of @c mem.
///
/// @returns A pointer to the matching byte or @c NULL if the byte does not
/// occur in the given memory area.
/// @since 0.1.0
MY_MEMORY_API void *my_memchr(
    void const *mem, unsigned char byte, size_t length);

/// Compares the first @c len bytes (each interpreted as unsigned char) if the
/// memory areas @c s1 and @c s2.
///
/// @param s1 A pointer to the first memory area, cannot be @c NULL.
/// @param s2 A pointer to the second memory area, cannot be @c NULL.
/// @param len The number of bytes to compare.
///
/// @returns An int less than, equal to, or greater than zero if the first n
/// bytes of @c s1 is found, respectively, to be less than, to match or be
/// greater than the first n bytes of @c s2.
/// If @c len is zero, 0 is returned.
/// @since 0.3.7
MY_MEMORY_API int my_memcmp(const void *s1, const void *s2, size_t len);

/// The type of comparision function used by @ref my_msort.
///
/// This function is called passing as arguments pointers to
/// two array elements to be compared.
/// This function should return a value the way @c my_strcmp does.
///
/// @since 0.2.0
typedef int (*my_comparator_t)(void const *, void const *);

/// Sorts the given data using Merge Sort.
///
/// @param data  A pair of arrays,
///              the first one is the data to sort and the second one is
///              the buffer array.
/// @param nmemb The number of elements in @c data.
/// @param size  The size of an individual element of @c data.
/// @param cmp   The comparison function,
///              see @ref my_comparator_t for more detals.
///
/// @since 0.2.0
MY_MEMORY_API void my_msort(
    void *data[2], size_t nmemb, size_t size, my_comparator_t cmp);

/// Rotates @c num left by @c shift bits.
///
/// @param num The number the rotate.
/// @param shift The amount of bits to rotate.
///
/// @returns The rotated number.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_rotate_left(my_u64_t num, unsigned shift)
{
    shift &= 63;
    if (shift == 0)
        return num;
    return (num << shift) | (num >> (64 - shift));
}

/// Rotates @c num right by @c shift bits.
///
/// @param num The number the rotate.
/// @param shift The amount of bits to rotate.
///
/// @returns The rotated number.
/// @since 0.2.0
MY_INLINE my_u64_t my_u64_rotate_right(my_u64_t num, unsigned shift)
{
    shift &= 63;
    if (shift == 0)
        return num;
    return (num >> shift) | (num << (64 - shift));
}

MY_API_END

#endif // !defined(__LIBMY_MEMORY_MEMORY_H__)
