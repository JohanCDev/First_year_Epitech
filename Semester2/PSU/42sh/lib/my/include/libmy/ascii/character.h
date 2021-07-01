/*
** EPITECH PROJECT, 2020
** LibMy - ascii module
** File description:
** Functions that classifies characters
*/

/// @file
///
/// Functions to handle ascii characters.
///
/// Provided in this header are functions of the format my_is* that classify
/// ascii characters and fonctions of the format my_to* that converts
/// characters.
///
/// @since 0.3.10

#ifndef __LIBMY_ASCII_CHARACTER_H__
#define __LIBMY_ASCII_CHARACTER_H__

#include "libmy/ascii/config.h"

MY_API_BEGIN

/// @param c The character
/// @returns Whether @c c an alphabetic character.
/// @since 0.2.0
MY_INLINE int my_isalpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/// @param c The character
/// @returns Whether @c c an digit character.
/// @since 0.2.0
MY_INLINE int my_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

/// @param c The character
/// @returns Whether @c c an alphabetic or digit character.
/// @since 0.2.0
MY_INLINE int my_isalnum(char c)
{
    return my_isalpha(c) || my_isdigit(c);
}

/// @param c The character
/// @returns Whether @c c an alphabetic or digit character.
/// @since 0.2.0
MY_INLINE int my_isblank(char c)
{
    return c == ' ' || c == '\t';
}

/// @param c The character
/// @returns Whether @c c a control character.
/// @since 0.2.0
MY_INLINE int my_iscntrl(char c)
{
    return (c >= 0x00 && c <= 0x1F) || c == 0x7F;
}

/// @param c The character
/// @returns Whether @c c a printable character.
/// @since 0.2.0
MY_INLINE int my_isgraph(char c)
{
    return c > ' ' && c <= '~';
}

/// @param c The character
/// @returns Whether @c c a lower alphabetical character.
/// @since 0.2.0
MY_INLINE int my_islower(char c)
{
    return c >= 'a' && c <= 'z';
}

/// @param c The character
/// @returns Whether @c c a printable character.
/// @since 0.2.0
MY_INLINE int my_isprint(char c)
{
    return c >= ' ' && c <= '~';
}

/// @param c The character
/// @returns Whether @c c a non-alphabetical printable character.
/// @since 0.2.0
MY_INLINE int my_ispunct(char c)
{
    return my_isgraph(c) && !my_isalnum(c);
}

/// @param c The character
/// @returns Whether @c c a whitespace character.
/// @since 0.2.0
MY_INLINE int my_isspace(char c)
{
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
        || c == '\v';
}

/// @param c The character
/// @returns Whether @c c a upper alphabetical character.
/// @since 0.2.0
MY_INLINE int my_isupper(char c)
{
    return c >= 'A' && c <= 'Z';
}

/// @param c The character
/// @returns Whether @c c a hexadecimal digit character.
/// @since 0.2.0
MY_INLINE int my_isxdigit(char c)
{
    return my_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

/// @param c The character
/// @returns The upper-case version of @c c, or @c c if not a lower-case
/// alphabetical character.
/// @since 0.2.0
MY_INLINE char my_toupper(char c)
{
    if (my_islower(c))
        return c & 0xdf;
    return c;
}

/// @param c The character
/// @returns The lower-case version of @c c, or @c c if not a upper-case
/// alphabetical character.
/// @since 0.2.0
MY_INLINE char my_tolower(char c)
{
    if (my_isupper(c))
        return c | 0x20;
    return c;
}

MY_API_END

#endif // !defined(__LIBMY_ASCII_CHARACTER_H__)
