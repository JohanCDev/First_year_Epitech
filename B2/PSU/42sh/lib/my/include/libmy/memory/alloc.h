/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Allocation/Deallocation functions
*/

/// @file
/// Allocation/Deallocation utilities.
///
/// @since 0.3.2

#ifndef __LIBMY_MEMORY_ALLOC_H__
#define __LIBMY_MEMORY_ALLOC_H__

#include "libmy/memory/config.h"

#if LIBMY_ALLOW_MALLOC_FREE

    #include <stddef.h>
    #include "libmy/internal/types.h"

MY_API_BEGIN

/// Allocates set zero-initializes a memory foran array of @c nmemb elements of
/// size @c size.
///
/// @param nmemb The number of elements in the array.
/// @param size The size of a single element in the array.
///
/// @return @c NULL if allocation failed or <tt>nmemb * size > SIZE_MAX</tt>.
/// Returns a pointer to the allocted memory block otherwise.
///
/// @since 0.3.2
MY_MEMORY_API void *my_calloc(size_t nmemb, size_t size);

/// Changes the size of the memory pointed to by @c ptr from @c old_size
/// to @c new_size bytes.
/// The contents will be unchanged in the range from the start of the
/// region up to the minimum of the old and new sizes.
/// If @c new_size if larger than @c old_size, the added memory will @b not
/// be initialized.
/// If @c ptr is @c NULL then the call is equivalent to
/// <tt>malloc(new_size)</tt>.
/// If @c new_size if zero, and @c ptr is not @c NULL,
/// then the call is equivalent to <tt>free(ptr)</tt>.
///
/// @note
/// This function requires the @c alloc_malloc flag to be used.
///
/// @param ptr      A pointer to the memory block to resize.
/// @param old_size The current size of the memory block.
/// @param new_size The new size of the memory block.
///
/// @returns A pointer to the resized memory block.
/// @since 0.1.0
MY_MEMORY_API void *my_realloc(void *ptr, size_t old_size, size_t new_size);

/// Frees the value of the passed pointer and sets it to @c NULL.
///
/// @param[in,out] ptr A pointer to the pointer to free, cannot be @c NULL.
///
/// @returns Always @c NULL.
/// @since 0.3.2
MY_MEMORY_API void *my_sfree(void **ptr);

/// Allocates a copy of the first @c size bytes of the passed memory area.
///
/// @param mem A pointer to the memory area to duplicate, cannot be @c NULL.
/// @param size The size of the memory to duplicate.
///
/// @returns A pointer to the duplicated memory area, or @c NULL if either @c
/// size if zero or allocation failed.
/// @since 0.3.7
MY_MEMORY_API void *my_memdup(void const *mem, size_t size);

MY_API_END

#endif // LIBMY_ALLOW_MALLOC_FREE
#endif // !defined(__LIBMY_MEMORY_ALLOC_H__)
