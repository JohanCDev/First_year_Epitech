/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** A collection of functions related to strings
*/

/// @file
///
/// A collection of functions related to strings
///
/// @since 0.3.0

#ifndef __LIBMY_ASCII_ASCII_H__
#define __LIBMY_ASCII_ASCII_H__

#include "libmy/ascii/config.h"

MY_API_BEGIN

#include <stddef.h>
#include <sys/types.h>

MY_ASCII_API char *my_revstr(char *str);
MY_ASCII_API char *my_strcapitalize(char *str);
MY_ASCII_API char *my_strcat(char *dest, char const *src);
MY_ASCII_API char *my_strchr(char const *str, char c);
MY_ASCII_API int my_strcmp(char const *s1, char const *s2);
MY_ASCII_API char *my_strcpy(char *dst, char const *src);
MY_ASCII_API char *my_strechr(char const *str, char c);
MY_ASCII_API int my_stricmp(char const *s1, char const *s2);
MY_ASCII_API int my_strincmp(char const *s1, char const *s2, int n);
MY_ASCII_API int my_str_isalpha(char const *str);
MY_ASCII_API int my_str_islower(char const *str);
MY_ASCII_API int my_str_isnum(char const *str);
MY_ASCII_API int my_str_isprintable(char const *str);
MY_ASCII_API int my_str_isupper(char const *str);
MY_ASCII_API size_t my_strlen(char const *str);
MY_ASCII_API char *my_strlowcase(char *str);
MY_ASCII_API char *my_strncat(char *dest, char const *src, int nb);
MY_ASCII_API int my_strncmp(char const *s1, char const *s2, int n);
MY_ASCII_API char *my_strncpy(char *dst, char const *src, int n);
MY_ASCII_API char *my_strstr(char const *str, char const *to_find);
MY_ASCII_API char *my_strstr_n(
    char const *str, int str_len, char const *to_find, int to_find_len);
MY_ASCII_API char *my_strupcase(char *str);

#if LIBMY_ALLOW_MALLOC_FREE
MY_ASCII_API void my_free_str_array(char *array[], int len);

MY_ASCII_API char *my_strdup(char const *src);

/// Duplicates the given string @c src up to @c n bytes.
///
/// @param src The original string, may be @c NULL.
/// @param n The maximum number of bytes to be copied, if @c src is longer than
/// @c n, only @c n bytes are copied and a null terminator is added.
///
/// @returns The duplicated string, or @c NULL if src was @c NULL or allocation
/// failed.
/// @since 0.3.10
MY_ASCII_API char *my_strndup(char const *src, size_t n);

MY_ASCII_API char **my_str_to_word_array(char const *str);
#endif

/// Jumps to the next split of string using @c sep as a separator character.
///
/// On the first call @c begin should point to the start of the string and @c
/// end to @c NULL.
/// The values @c begin and @c end are then reused after each subsequent call
/// to this function.
///
/// @param begin A pointer to the start of the current split, it is updated to
/// be the pointer the next split.
/// @param end A pointer to the end of the current split, or a pointer to @c
/// NULL if either the function was never called or all the splits have been
/// consumed.
/// @param sep The seprarator character.
///
/// @returns The number of characters in this split, or -1 if the end was
/// reached.
/// @since 0.2.0
MY_ASCII_API ssize_t my_str_csplit_iter(
    char const **begin, char const **end, char sep);

#include "character.h"

MY_API_END

#endif // !defined(__LIBMY_ASCII_ASCII_H__)
