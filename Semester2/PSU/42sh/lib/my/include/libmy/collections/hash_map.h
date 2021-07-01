/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** The hash map definitions
*/

/// @file
///
/// Defines the hash map type.
/// A collection that stores keys and value pairs, where keys are unique.
///
/// @since 0.3.2

#ifndef __LIBMY_COLLECTIONS_HASH_MAP_H__
#define __LIBMY_COLLECTIONS_HASH_MAP_H__

#include "libmy/collections/config.h"

MY_API_BEGIN

#include <assert.h>

#include "libmy/hash.h"

////////////////////////////////////////////////////////////////////////////////
// Hash Map Main Definitions
////////////////////////////////////////////////////////////////////////////////

/// Used to free memory used by a map key.
///
/// Takes a pointer to the key, the pointer will never be @c NULL.
///
/// @since 0.3.2
typedef void (*my_map_drop_t)(void *);

/// Used to compare two map keys.
///
/// Takes two pointer to keys, the passed pointer will never be @c NULL.
///
/// Returns 0 if both keys are equal, a negative value if the first key is
/// 'lower' than the second key, or a positive value if the first key is
/// greater than the second one.
/// @since 0.3.2
typedef int (*my_map_compare_keys_t)(void const *, void const *);

/// Computes the hash of the given key pointer.
/// Implementations of this functions need to call the @c my_hasher_write
/// family of functions to hash the given key.
///
/// Takes a hasher as well as the key to hash as parameters, both may not be
/// @c NULL.
///
/// @since 0.3.2
typedef void (*my_map_hash_key_t)(my_hasher_t *, void const *);

/// This structure the properties of the key and value types of a map.
///
/// @since 0.3.2
struct my_map_kvtypes {
    /// The size (in bytes) of the key type, as returned by
    /// <tt>sizeof(type)</tt>
    ///
    /// Must not be greater than zero.
    ///
    /// @since 0.3.2
    size_t key_size;
    /// The alignment (in bytes) of the key type, as returned by
    /// <tt>alignof(type)</tt>, typically equal to the key size if the key type
    /// is numeric.
    ///
    /// Must not be greater than zero.
    ///
    /// @since 0.3.2
    size_t key_align;
    /// The size (in bytes) of the value type, as returned by
    /// <tt>sizeof(type)</tt>
    ///
    /// Must not be greater than zero.
    ///
    /// @since 0.3.2
    size_t value_size;
    /// The alignment (in bytes) of the value type, as returned by
    /// <tt>alignof(type)</tt>, typically equal to the value size if the value
    /// type is numeric.
    ///
    /// Must not be greater than zero.
    ///
    /// @since 0.3.2
    size_t value_align;
    /// Compares two keys, cannot be @c NULL.
    ///
    /// @since 0.3.2
    my_map_compare_keys_t compare;
    /// Used to hash keys, leave to @c NULL on non-hashing maps.
    ///
    /// @since 0.3.2
    my_map_hash_key_t hash;
    /// Used to free memory used by the key, can be @c NULL.
    ///
    /// @since 0.3.2
    my_map_drop_t key_drop;
    /// Used to free memory used by the value, can be @c NULL.
    ///
    /// @since 0.3.2
    my_map_drop_t value_drop;
};

/// Same as @ref my_map_kvtypes.
///
/// @since 0.3.2
typedef struct my_map_kvtypes my_map_kvtypes_t;

/// The storage location of a key-value pair.
///
/// @since 0.3.6
typedef struct p_my_hash_map_entry my_hash_map_entry_t;

/// The hash map structure.
/// You must initialize this structure using the @ref my_hash_map_init or
/// @ref my_hash_map_init_capacity functions.
///
/// @since 0.3.2
struct my_hash_map {
    /// @publicsection
    /// The number of entries stored in this map.
    ///
    /// @since 0.3.2
    size_t length;
    /// The current number of buckets.
    ///
    /// @since 0.3.2
    size_t capacity;
    /// The capacity doubling threshold.
    /// The map will grow if the number of entries divided by the current
    /// capacity execeeds this number.
    /// Needs to be between 0 and 1 (exclusive).
    ///
    /// @since 0.3.2
    double load_factor;
    /// @privatesection
    my_hash_map_entry_t **buckets;
    size_t key_size;
    size_t key_offset;
    size_t value_size;
    size_t value_offset;
    my_u64_t hasher_key_1;
    my_u64_t hasher_key_2;
    my_map_hash_key_t hash;
    my_map_compare_keys_t compare;
    my_map_drop_t key_drop;
    my_map_drop_t value_drop;
};

/// Same as @ref my_hash_map.
///
/// @since 0.3.2
typedef struct my_hash_map my_hash_map_t;

#include "libmy/internal/hash_map.h"

/// The error type for map operations.
///
/// @since 0.3.2
enum my_map_err {
    /// The operation has succeded.
    ///
    /// @since 0.3.2
    MY_MAP_OK = 0,
    /// Allocation error.
    ///
    /// @since 0.3.2
    MY_MAP_ALLOC,
    /// Invalid key-value types.
    ///
    /// @since 0.3.2
    MY_MAP_INVALID_KVTYPES,
};

/// Same as @ref my_map_err.
///
/// @since 0.3.2
typedef enum my_map_err my_map_err_t;

/// Initializes the given hash map with the @c kvtypes type parameters.
///
/// @param map A pointer to the map to initialize, must not be @c NULL.
/// @param kvtypes The type parameters, refer to @ref my_map_kvtypes for more
/// info.
///
/// @return @c MY_MAP_INVALID_KVTYPES if @c kvtypes is not valid, or
/// @c MY_MAP_OK otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API my_map_err_t my_hash_map_init(
    my_hash_map_t *map, my_map_kvtypes_t const *kvtypes);

/// Initializes the given hash map with the @c kvtypes type parameters and a
/// capacity of @c capacity buckets.
///
/// @param map A pointer to the map to initialize, must not be @c NULL.
/// @param kvtypes The type parameters, refer to @ref my_map_kvtypes for more
/// info.
/// @param capacity The number of buckets the be allocated. Adjusted to the
/// next power of two if not already a power of two.
///
/// @return @c MY_MAP_INVALID_KVTYPES if @c kvtypes is not valid,
/// @c MY_MAP_ALLOC if bucket allocation failed, or @c MY_MAP_OK otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API my_map_err_t my_hash_map_init_capacity(
    my_hash_map_t *map, my_map_kvtypes_t const *kvtypes, size_t capacity);

/// Puts the given key-value pair into the hash map.
/// Updates the value if @c key is already present in the map and drops the old
/// value if @ref my_map_kvtypes::value_drop was not @c NULL.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key, must not be @c NULL.
/// @param value A pointer to the value, must not be @c NULL.
///
/// @returns @c MY_MAP_ALLOC if entry allocation failed, or @c MY_MAP_OK
/// otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API my_map_err_t my_hash_map_insert(
    my_hash_map_t *map, void *key, void *value);

/// Checks whether the given @c key is contained in this hash map.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key to check, must not be @c NULL.
///
/// @returns 1 if the key is present, 0 otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API int my_hash_map_contains(
    my_hash_map_t *map, void const *key);

/// Fetches the value associated with the given @c key.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key, must not be @c NULL.
///
/// @returns A pointer to the value, or @c NULL if not present.
/// @since 0.3.2
MY_COLLECTIONS_API void *my_hash_map_get(my_hash_map_t *map, void const *key);

/// Removes a key-value pair from the hash map, if present.
/// Calls both @ref my_map_kvtypes::key_drop and
/// @ref my_map_kvtypes::value_drop if their values given in the creation of
/// this map was not @c NULL.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key to remove, must not be @c NULL.
///
/// @returns 1 if the key was present in the map before being removed, 0
/// otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API int my_hash_map_remove(my_hash_map_t *map, void const *key);

/// Frees the memory allocated by the hash map.
/// Does not free the given pointer.
///
/// @param map The hash map to drop, must not be @c NULL.
///
/// @since 0.3.2
MY_COLLECTIONS_API void my_hash_map_drop(my_hash_map_t *map);

/// Computes the hash of the given key, using the map's hash state.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key to hash, does not need to be present in the
/// map, but must not be @c NULL.
///
/// @returns The 64-bit hash value of @c key.
/// @since 0.3.2
MY_COLLECTIONS_API my_u64_t my_hash_map_hash_key(
    my_hash_map_t const *map, void const *key);

////////////////////////////////////////////////////////////////////////////////
// Entry API
////////////////////////////////////////////////////////////////////////////////

/// Fetches the entry associated with the given @c key.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key, must not be @c NULL.
///
/// @returns A pointer to entry where @c key is stored, or @c NULL if not
/// present.
/// @since 0.3.6
MY_COLLECTIONS_API my_hash_map_entry_t *my_hash_map_get_entry(
    my_hash_map_t *map, void const *key);

/// Puts the given key-value pair into the hash map.
/// Updates the value if @c key is already present in the map and drops the old
/// value if @ref my_map_kvtypes::value_drop was not @c NULL.
///
/// @param map The hash map, must not be @c NULL.
/// @param key A pointer to the key, must not be @c NULL.
/// @param value A pointer to the value, if @c NULL the element will be removed
/// from the map if it exists.
///
/// @returns A pointer to the updated/created entry, or @c NULL if either
/// @c value was @c NULL or entry allocation failed.
/// @since 0.3.6
MY_COLLECTIONS_API my_hash_map_entry_t *my_hash_map_insert_entry(
    my_hash_map_t *map, void *key, void *value);

/// Fetches the key associated with the given entry.
///
/// @param map The hash map, must not be @c NULL.
/// @param entry The map entry, must not be @c NULL.
///
/// @returns The key, must @b not be modified.
/// @since 0.3.6
MY_INLINE const void *my_hash_map_entry_key(
    my_hash_map_t *map, my_hash_map_entry_t const *entry)
{
    assert(map != NULL);
    assert(entry != NULL);
    return P_MY_HM_KEY(map, entry);
}

/// Fetches the value associated with the given entry.
///
/// @param map The hash map, must not be @c NULL.
/// @param entry The map entry, must not be @c NULL.
///
/// @returns The value, can be modified.
/// @since 0.3.6
MY_INLINE void *my_hash_map_entry_value(
    my_hash_map_t *map, my_hash_map_entry_t const *entry)
{
    assert(map != NULL);
    assert(entry != NULL);
    return P_MY_HM_VAL(map, entry);
}

////////////////////////////////////////////////////////////////////////////////
// Hash Map Iteration
////////////////////////////////////////////////////////////////////////////////

/// The iterator type for hash maps.
struct my_hash_map_iter {
    /// @publicsection
    /// A pointer to the hash map.
    ///
    /// @since 0.3.2
    my_hash_map_t const *map;
    /// A pointer to the current key, or @c NULL if none.
    ///
    /// @since 0.3.2
    void *key;
    /// A pointer to the current value, or @c NULL if none.
    ///
    /// @since 0.3.2
    void *value;
    /// @privatesection
    /// The index of the current entry's bucket.
    size_t bucket_index;
    my_hash_map_entry_t const *next_entry;
};

/// Same as @ref my_hash_map_iter.
///
/// @since 0.3.2
typedef struct my_hash_map_iter my_hash_map_iter_t;

/// Initalizes the hash map iterator.
///
/// @param iter A pointer to the iterator, must not be @c NULL.
/// @param map A pointer to the hash map, must not be @c NULL.
///
/// @since 0.3.2
MY_COLLECTIONS_API void my_hash_map_iter_init(
    my_hash_map_iter_t *iter, my_hash_map_t const *map);

/// Checks if the iterator has a next element to fetch.
///
/// The behavior is undefined if the target hash map was modified after the
/// call to @c ref my_hash_map_iter_init.
///
/// @param iter The iterator, must not be @c NULL.
///
/// @returns 1 if a next entry is available, 0 otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API int my_hash_map_iter_has_next(
    my_hash_map_iter_t const *iter);

/// Fetches the next entry from the map.
/// If sucessful, the entry's key and value can be accessed with
/// <tt>iter->key</tt> and <tt>iter->value</tt>, respectively.
///
/// The behavior is undefined if the target hash map was modified after the
/// call to @c ref my_hash_map_iter_init.
///
/// @param iter The iterator, must not be @c NULL.
///
/// @returns 1 if an entry was fetched, 0 otherwise.
/// @since 0.3.2
MY_COLLECTIONS_API int my_hash_map_iter_next(my_hash_map_iter_t *iter);

////////////////////////////////////////////////////////////////////////////////
// Hash Map Miscellaneous Functions
////////////////////////////////////////////////////////////////////////////////

/// Frees the passed nul-terminated string when used as a drop function for
/// keys or value of a hash map.
/// Do not call this function directly.
///
/// NOTE: This function can only be used if keys/values are INDIVIDUALLY
/// allocated.
/// @since 0.3.2
#define MY_HASH_MAP_CSTR_DROP ((my_map_drop_t)&p_my_hash_map_cstr_drop)
/// Checks if the two passed nul-terminated string pointers are equal when used
/// as key-comparision function of a hash map. Do not call this function
/// directly.
///
/// @since 0.3.2
#define MY_HASH_MAP_CSTR_CMP ((my_map_compare_keys_t)&p_my_hash_map_cstr_cmp)
/// Hashes nul-terminated string pointer keys of the hash map when used as the
/// key-hashing function.
///
/// @since 0.3.2
#define MY_HASH_MAP_CSTR_HASH ((my_map_hash_key_t)&p_my_hash_map_cstr_hash)

MY_API_END

#endif // !defined(__LIBMY_COLLECTIONS_HASH_MAP_H__)
