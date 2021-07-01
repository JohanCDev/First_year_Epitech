/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** The vector definitions
*/

/// @file
///
/// Defines the vector type, @ref my_vec_t ways to operate on it.
/// Vectors have O(1) indexing, amortized O(1) push (to the end)
/// and O(1) pop (from the end).
///
/// @since 0.1.0

#ifndef __LIBMY_VEC_H__
#define __LIBMY_VEC_H__

#include "libmy/collections/config.h"

MY_API_BEGIN

#include <assert.h>
#include <stddef.h>

#include "libmy/memory/memory.h"

/// A contiguous growable array type.
///
/// It is generally not recommended to directly modify the fields
/// unless you know what you are doing.
///
/// @since 0.1.0
struct my_vec {
    /// Where the data is stored.
    void *data;
    /// The number of elements currently stored in this vector.
    /// Must not exceed @ref my_vec::capacity.
    size_t length;
    /// The number of elements this vector can hold without reallocating.
    size_t capacity;
    /// The size (in bytes) of an element.
    /// Cannot be zero.
    size_t elem_size;
};

/// Same as @ref my_vec.
///
/// @since 0.1.0
typedef struct my_vec my_vec_t;

/// The error type for @ref my_vec_t operations.
///
/// @since 0.1.0
enum my_vec_err {
    /// The operation has succeded.
    MY_VEC_OK = 0,
    /// The index is out of bounds.
    MY_VEC_OUT_OF_BOUNDS,
    /// The memory allocator returned an error.
    MY_VEC_ALLOC,
    /// Error due to the computed capacity exceeding the vec's maximum.
    MY_VEC_CAPACITY_OVERFLOW,
    /// The vector was initialized with an element size of zero.
    MY_VEC_ZERO_ELEM_SIZE
};

/// Same as @ref my_vec_err.
///
/// @since 0.1.0
typedef enum my_vec_err my_vec_err_t;

/// Writes an error code the given pointer as well as returning it.
///
/// @param[out] loc Where the error will be written to.
/// @param err      The error code.
///
/// @returns The given error code.
/// @since 0.1.0
MY_INLINE my_vec_err_t my_vec_wrap_err(my_vec_err_t *loc, my_vec_err_t err)
{
    if (err != MY_VEC_OK)
        *loc = err;
    return err;
}

/// Initializes a @ref my_vec_t with the specified capacity.
///
/// @param[out] vec  The vector, must be a valid pointer.
/// @param capacity  The capacity of the vector,
///                  if @c 0 the vector will not allocate
/// @param elem_size The size (in bytes) of an element,
///                  as returned by the @c sizeof operator
/// @returns @ref MY_VEC_ZERO_ELEM_SIZE if @c elem_size is zero,
///          @ref MY_VEC_ALLOC if an allocation error has occured,
///          or @ref MY_VEC_OK othewise.
///
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_init_capacity(
    my_vec_t *vec, size_t capacity, size_t elem_size);

/// Initializes a @ref my_vec_t with a capacity of zero.
///
/// @param[out] vec  The vector, must be a valid pointer.
/// @param elem_size The size (in bytes) of an element,
///                  as returned by the @c sizeof operator
///
/// @since 0.1.0
MY_INLINE my_vec_err_t my_vec_init(my_vec_t *vec, size_t elem_size)
{
    return my_vec_init_capacity(vec, 0, elem_size);
}

/// Copies the contents of @c src into dst with a new allocation.
/// The copy will overwrite any previous data that may have been in dst.
///
/// @param[out] dst The destination, may not be initialized.
/// @param src      The source, must be initialized.
///
/// @return @ref MY_VEC_ALLOC if an allocation error has occured.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_copy(
    my_vec_t *dst, my_vec_t const *src);

/// Copies the contents of @c src into dst, reusing dst's memory if enough
/// capacity is present @b and the element size is the same.
/// The copy will overwrite any previous data that may have been in dst.
///
/// @note The elements of @c dst will @b not be freed, please call
///       @ref my_vec_remove_multiple beforehand if @c dst is not empty.
///
/// @param dst       The destination, @b must be initialized.
/// @param src       The source, must be initialized.
///
/// @return @ref MY_VEC_ALLOC if an allocation error has occured.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_copy_into(
    my_vec_t *dst, my_vec_t const *src);

/// Frees the given @ref my_vec_t.
///
/// @param vec       The vector, can be @c NULL.
/// @param elem_free A function that free elements of this vector,
///                  called @ref my_vec_t::length times.
///                  Can be @c NULL.
///
/// @since 0.1.0
MY_COLLECTIONS_API void my_vec_free(my_vec_t *vec, void (*elem_free)(void *));

/// Returns a pointer at position @c index of the given vector.
/// For a checked version, see @ref my_vec_try_get.
///
/// @param vec   The vector, must be initialized.
/// @param index The position of the element.
///              Must not exceed @ref my_vec_t::capacity.
///              If @c index is greater than @ref my_vec_t::length,
///              the returned memory may not be initialized.
///
/// @returns A pointer to the element.
/// @since 0.1.0
MY_INLINE void *my_vec_get(my_vec_t const *vec, size_t index)
{
    assert(vec != NULL);
    assert(vec->data != NULL);
    return (void *)((char *)vec->data + vec->elem_size * index);
}

/// Stores the pointer to the element at position @c index of the given vector.
/// A checked version of @ref my_vec_get.
///
/// @param vec       The vector, must be initialized.
/// @param index     The position of the element.
///                  Must not exceed @ref my_vec_t::length.
/// @param[out] elem Where the element pointer will be stored.
///
/// @returns @ref MY_VEC_OUT_OF_BOUNDS if index is greater than
///          @ref my_vec_t::length, @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_INLINE my_vec_err_t my_vec_try_get(
    my_vec_t const *vec, size_t index, void **elem)
{
    assert(vec != NULL);
    if (index >= vec->length)
        return MY_VEC_OUT_OF_BOUNDS;
    *elem = my_vec_get(vec, index);
    return MY_VEC_OK;
}

/// Grows or shrinks the given vector, depending on @c new_capacity.
/// Does nothing if @c new_capacity is zero.
///
/// @param vec          The vector, must be initialized.
/// @param new_capacity The new capacity of the vector.
/// @param elem_free    A function that frees elements of this vector.
///                     Can be @c NULL.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_set_capacity(
    my_vec_t *vec, size_t new_capacity, void (*elem_free)(void *));

/// Frees all the elements contained inside this vector while conserving the
/// current capacity.
///
/// @param vec The vector, must be initialized.
/// @param elem_free A function that frees elements of this vector,
/// called @ref my_vec_t::length times. Can be @c NULL.
/// @since 0.3.7
MY_COLLECTIONS_API void my_vec_clear(my_vec_t *vec, void (*elem_free)(void *));

/// Frees all the elements contained inside this vector after @c start_index
/// (included) while conserving the current capacity.
///
/// @param vec The vector, must be initialized.
/// @param start_index The index from which the clear must start,
/// @param elem_free A function that frees elements of this vector,
/// called @ref my_vec_t::length times. Can be @c NULL.
/// @author Andréas Leroux
/// @since 0.3.11
MY_COLLECTIONS_API void my_vec_clear_from(
    my_vec_t *vec, size_t start_index, void (*elem_free)(void *));

/// Reserves capacity for at least @c additional more elements.
/// The collection may reserve more space to avoid frequent reallocations.
/// After calling reserve, capacity will be greater than or equal to
/// <tt>vec->length + additional</tt>.
/// Does nothing if capacity is already sufficient.
///
/// @param vec        The vector, must be initialized.
/// @param additional The additional number of elements.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_reserve(
    my_vec_t *vec, size_t additional);

/// Shrinks the capacity of the vector as much as possible.
///
/// @param vec        The vector, must be initialized.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_shrink_to_fit(my_vec_t *vec);

/// Appends an element to the back of the collection.
/// The contents of @c elem will be copied into the vector and
/// the vector's length incremented by one.
///
/// @param vec  The vector, must be initialized.
/// @param elem The element data to copy to the vector.
///             Must be a valid pointer.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_push(my_vec_t *vec, void *elem);

/// Appends multiple elements to the back of the collection.
/// The contents of @c elem will be copied into the vector and
/// the vector's length incremented by @c count.
///
/// @param vec   The vector, must be initialized.
/// @param elems The elements data to copy to the vector.
///              Must be a valid pointer.
/// @param count The number of elements to append to the vector.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_CAPACITY_OVERFLOW if the new capacity exceeds
///          the vec's maximum, @ref MY_VEC_OK otherwise.
/// @since 0.1.0
MY_COLLECTIONS_API my_vec_err_t my_vec_push_multiple(
    my_vec_t *vec, void *elems, size_t count);

/// Removes the last element from a vector and writes it to @c dst.
/// This does not shrink the vector's capacity.
///
/// @param vec      The vector, must be initialized.
/// @param[out] dst Where the popped element will be written to.
///
/// @since 0.1.0
MY_COLLECTIONS_API void my_vec_pop(my_vec_t *vec, void *dst);

/// Removes the last @c count elements from a vector and writes them to @c dst.
/// This does not shrink the vector's capacity.
///
/// @param vec      The vector, must be initialized.
/// @param[out] dst Where the popped elements will be written to,
///                 can be @c NULL.
/// @param count    the number of elements to pop.
///
/// @since 0.1.0
MY_COLLECTIONS_API void my_vec_pop_multiple(
    my_vec_t *vec, void *dst, size_t count);

/// Inserts an element at position @c index within the vector,
/// shifting all elements after it to the right.
///
/// @param vec   The vector, must be initialized.
/// @param elem  The element data to copy to the vector.
///              Must be a valid pointer.
/// @param index The position of the inserted element.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OUT_OF_BOUNDS if the index exceeds the length,
///          @ref MY_VEC_CAPACITY_OVERFLOW if the new capacity exceeds
///          the vec's maximum, @ref MY_VEC_OK otherwise.
/// @author Andréas Leroux
/// @since 0.3.11
MY_COLLECTIONS_API my_vec_err_t my_vec_insert(
    my_vec_t *vec, void *elem, size_t index);

/// Inserts @c count elements at position @c index within the vector,
/// shifting all elements after them to the right.
///
/// @param vec   The vector, must be initialized.
/// @param elem  The elements data to copy to the vector.
///              Must be a valid pointer.
/// @param index The starting position of the inserted elements.
/// @param count The number of elements to insert.
///
/// @returns @ref MY_VEC_ALLOC if an allocator error has occured,
///          @ref MY_VEC_OUT_OF_BOUNDS if the index exceeds the length,
///          @ref MY_VEC_CAPACITY_OVERFLOW if the new capacity exceeds
///          the vec's maximum, @ref MY_VEC_OK otherwise.
/// @author Andréas Leroux
/// @since 0.3.11
MY_COLLECTIONS_API my_vec_err_t my_vec_insert_multiple(
    my_vec_t *vec, void *elem, size_t index, size_t count);

/// Change the value of an element at position @c index within the vector.
///
/// @param vec   The vector, must be initialized.
/// @param new_value The new value of the element. Must be a valid pointer.
/// @param index The position of the changed element.
///
/// @returns @ref MY_VEC_OUT_OF_BOUNDS if index is out of bounds, or @ref
/// MY_VEC_OK otherwise.
/// @author Andréas Leroux
/// @since 0.3.4
MY_COLLECTIONS_API my_vec_err_t my_vec_change_value(
    my_vec_t *vec, void *elem, size_t index);

/// Swap the elements at position @c index_1 and @c index_2 within the vector.
///
/// @param vec The vector, must be initialized.
/// @param index_1 The position of the first swapped element.
/// @param index_2 The position of the second swapped element.
///
/// @since 0.3.5
MY_INLINE void my_vec_swap(my_vec_t *vec, size_t index_1, size_t index_2)
{
    my_memswap(
        my_vec_get(vec, index_1), my_vec_get(vec, index_2), vec->elem_size);
}

/// Reverses the elements within the vector.
///
/// @param vec The vector, must be initialized.
///
/// @since 0.3.5
MY_INLINE void my_vec_reverse(my_vec_t *vec)
{
    assert(vec != NULL);
    assert(vec->length == 0 || vec->data != NULL);
    my_memrev(vec->data, vec->length, vec->elem_size);
}

/// Removes the element at position @c index and writes it to @c dst,
/// shifting all elements after it to the left.
///
/// @param vec      The vector, must be initialized.
/// @param[out] dst Where the removed element will be written to.
/// @param index    The position of the removed element.
///
/// @since 0.2.1
MY_COLLECTIONS_API void my_vec_remove(my_vec_t *vec, void *dst, size_t index);

/// Removes @c count elements at position @c index and writes them to @c dst,
/// shifting all elements after them to the left.
///
/// @param vec      The vector, must be initialized.
/// @param[out] dst Where the removed elements will be written to.
/// @param index    The starting position of the removed elements.
/// @param count    The number of elements to remove.
///
/// @since 0.2.1
MY_COLLECTIONS_API void my_vec_remove_multiple(
    my_vec_t *vec, void *dst, size_t index, size_t count);

/// Ensures the vector has enough capacity to hold @c min_cap elemements.
///
/// @param vec     The vector, must be initialized.
/// @param min_cap The minuum capacity of the vector.
///
/// @returns @ref MY_VEC_OK is successful,
/// @ref MY_VEC_ALLOC or @ref MY_VEC_CAPACITY_OVERFLOW in case of error.
/// @since 0.2.1
MY_COLLECTIONS_API my_vec_err_t my_vec_ensure_capacity(
    my_vec_t *vec, size_t min_cap);

/// Extends the vector to be of length @c length with the provided element.
/// Does nothing of <tt>length <= vec->length</tt>.
///
/// @param vec    The vector, must be initialized.
/// @param elem   The element to write to new values.
///               Must @b not be @c NULL.
/// @param length The new length of the vector.
///
/// @returns @ref MY_VEC_OK is successful,
/// @ref MY_VEC_ALLOC or @ref MY_VEC_CAPACITY_OVERFLOW in case of error.
/// @since 0.2.1
MY_COLLECTIONS_API my_vec_err_t my_vec_extend_to_length(
    my_vec_t *vec, void *elem, size_t length);

/// Casts and dereferences an pointer to an element of a vector.
///
/// @param type The type of element.
/// @param ptr  The element pointer to dereference.
///
/// @returns The element.
/// @since 0.1.0
#define MY_VEC_CAST_ELEM(type, ptr) (*((type *)(ptr)))

/// Fetches an element from the given vector and casts it.
///
/// @param type  The type of element.
/// @param vec   The vector, must be initialized.
/// @param index The position of the element.
///              Must not exceed @ref my_vec_t::length.
///
/// @returns The element.
/// @since 0.1.0
#define MY_VEC_GET_ELEM(type, vec, index) \
    MY_VEC_CAST_ELEM(type, my_vec_get((vec), (index)))

/// Fetches an element from the given vector and casts it.
/// Same as @ref MY_VEC_GET_ELEM, but shorter.
///
/// @param type  The type of element.
/// @param vec   The vector, must be initialized.
/// @param index The position of the element.
///              Must not exceed @ref my_vec_t::length.
///
/// @returns The element.
/// @since 0.3.4
#define MY_VEC_GET(type, vec, index) MY_VEC_GET_ELEM(type, vec, index)

MY_API_END

#endif
