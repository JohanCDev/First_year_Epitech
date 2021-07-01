/*
** EPITECH PROJECT, 2021
** LibMy - parsing module
** File description:
** The main header for the parsing module
*/

/// @file
///
/// Parsing utlilites.
///
/// @since 0.1.0

#ifndef __LIBMY_PARSING_PARSING_H__
#define __LIBMY_PARSING_PARSING_H__

#include "libmy/parsing/config.h"

MY_API_BEGIN

#include <stddef.h>
#include "libmy/internal/types.h"

/// Parses a number, leniently.
/// @c str can contain as much plus or minus signs before the number.
/// For a stricter version, see @ref my_getnbr_strict.
///
/// @param str The number string.
///
/// @returns The parsed number, or zero if @c is invalid.
/// @since 0.1.0
MY_PARSING_API int my_getnbr(char const *str);

/// Parses a number, strictly.
/// @c str can contain only one plus or minus sign before the number.
/// For a more lenient version, see @ref my_getnbr.
///
/// @param str The number string.
///
/// @returns The parsed number, or zero if @c is invalid.
/// @since 0.1.0
MY_PARSING_API int my_getnbr_strict(char const *str);

/// Parses a number leniently using a base.
/// @c str can contain as much plus or minus signs before the number.
///
/// @param str  The number string.
/// @param base The base, must not contain duplicate characters,
///             be null or empty.
///
/// @returns The parsed number, or zero if @c is invalid.
/// @since 0.1.0
MY_PARSING_API int my_getnbr_base(char const *str, char const *base);

/// Parses an <tt>unsigned int</tt> starting from the first character of the
/// given string pointer, stores the parsed number in @c dst and advances
/// @c str by the number of digits parsed.
///
/// @note In case of overflow, the extra digits are not added to @c dst,
///       but are still consumed from the input string.
///
/// @param str      A pointer to a nul-termnated string.
/// @param[out] dst Where the parsed number is stored, it is set to 0
///                 in case of invalid number, can be @c NULL.
///
/// @returns 0 the number was parsed successfully, or 1 if the starting
///          character of @c str is not a non-zero digit.
/// @since 0.3.1
MY_PARSING_API int my_next_uint(char const **str, unsigned *dst);

/// Parses a @c size_t starting from the first character of the
/// given string pointer, stores the parsed number in @c dst and advances
/// @c str by the number of digits parsed.
///
/// @note In case of overflow, the extra digits are not added to @c dst,
///       but are still consumed from the input string.
///
/// @param str      A pointer to a nul-termnated string.
/// @param[out] dst Where the parsed number is stored, it is set to 0
///                 in case of invalid number, can be @c NULL.
///
/// @returns 0 the number was parsed successfully, or 1 if the starting
///          character of @c str is not a non-zero digit.
/// @since 0.2.0
MY_PARSING_API int my_next_size_t(char const **str, size_t *dst);

MY_API_END

#endif // !defined(__LIBMY_PARSING_PARSING__)
