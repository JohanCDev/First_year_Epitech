/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Utility functions
*/

#ifndef __SHELL_UTIL_H__
#define __SHELL_UTIL_H__

#include <libmy/hash.h>
#include <libmy/io/iostream.h>
#include <stdbool.h>
#include <stddef.h>

#include "error.h"

#define DEFAULT_PATH "/usr/bin:/bin"

/// Contatenates the given components, adding a '/' if necessary.
///
/// @param dir_len The length in bytes of @c dir_name
/// @param dir_name The directory part of the path
/// @param file_name The file part to add.
///
/// @returns The path, or NULL if allocation failed.
char *sh_create_file_path(
    size_t dir_len, char const *dir_name, char const *file_name);

/// Frees an entry of a string pointer array.
///
/// For use with @c my_vec_free.
///
/// @param ptr The pointer to free.
void sh_free_entry(void *ptr);

/// Closes the file descriptor at @c fd and sets the value to -1.
///
/// Does nothing if @c *fd is already -1.
///
/// @param fd A pointer to the file descriptor.
///
/// @returns The return value of close(2), or 0 if @c *fd was -1 before the
/// call.
int sh_sclose(int *fd);

/// Closes a pair of file descriptors by calling @ref sh_shclose twice
///
/// @param pipefd The file descriptors, can be @c NULL.
int sh_sclose_pipe(int pipefd[2]);

/// Attempts to parse an int.
///
/// @param str The string to parse.
/// @param[out] result Where the parsed int is stored.
///
/// @returns @c SH_OK if the parsing succeded, or an error code otherwise.
sh_error_t sh_parse_int(char const *str, int *result);

/// String with length information.
typedef struct sh_lstr {
    /// The string, may contain embedded null-bytes.
    char *value;
    /// The length of the string, optional terminator excluded.
    size_t length;
} sh_lstr_t;

#define SH_LSTR(value, length) ((sh_lstr_t){(char *)(value), (length)})
#define SH_TO_LSTR(value)      SH_LSTR((value), my_strlen((char *)(value)))

bool sh_lstr_dup(sh_lstr_t src, sh_lstr_t *dst);
int sh_lstr_cmp(sh_lstr_t const *a, sh_lstr_t const *b);
void sh_lstr_hash(my_hasher_t *hasher, sh_lstr_t *str);

/// Prints the given array of strings in a column format.
void sh_column_print(
    bool is_tty, size_t entry_count, char const **entries, my_iostream_t *out);

/// Returns the number of words in @c str.
///
/// A 'word' is defined as a sequence of non-whitespace characters
/// (see isspace(3)).
///
/// @returns The number of words in str, or zero is @c str is @c NULL or empty
/// (containing only whitespace).
size_t sh_count_words(char const *str);

/// Returns the next word in @c str
///
/// A 'word' is defined as a sequence of non-whitespace characters
/// (see isspace(3)).
///
/// @returns A pointer to the word start plus the size of the word, or @c NULL
/// and @c 0 when there are no more words in @c str
sh_lstr_t sh_next_word(char const *str);

/// Splits a string, without performing allocation.
///
/// @param src The source string, the string is not modified.
/// @param first The first part of @c src, doesn't include trailing whitespace.
/// @param second The fsecond part of @c src, doesn't include leading
/// whitespace.
/// @param pos Where to split @c src.
void sh_split_at(
    sh_lstr_t src, sh_lstr_t *first, sh_lstr_t *second, size_t pos);

#endif // !defined(__SHELL_UTIL_H__)
