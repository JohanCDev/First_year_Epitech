/*
** EPITECH PROJECT, 2020
** LibMy - core module
** File description:
** The main header for the core module
*/

/// @file
///
/// Core utilities for LibMy.
///
/// @since 0.1.0

#ifndef __LIBMY_CORE_H__
#define __LIBMY_CORE_H__

#include "libmy/internal/attributes.h"

MY_API_BEGIN

#include "libmy/internal/types.h"

/// Computes the absolute value of @c x.
///
/// @note
/// Due to MY_ABS, being a macro the @c x expression will be evaluated twice.
///
/// @param x The source number.
///
/// @returns The absolute value of @c x.
/// @since 0.1.0
#define MY_ABS(x) ((x) < 0 ? -(x) : (x))

/// Compares and returns the maximum of two values.
///
/// @param a
/// @param b
///
/// @returns The biggest value, or the second argument if equal.
/// @since 0.1.0
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

/// Compares and returns the minimum of two values.
///
/// @param a
/// @param b
///
/// @returns The smallest value, or the first argument if equal.
/// @since 0.1.0
#define MY_MIN(a, b) ((b) < (a) ? (b) : (a))

/// Force casts to given pointer to the type @c t.
///
/// @note This can cause undefined behaviour if the output
///       type is not compatible with the given type!
///
/// @param t   The type of pointer to cast to.
/// @param ptr The pointer to cast.
///
/// @returns The casted pointer.
/// @since 0.2.0
#define MY_CAST(t, ptr) ((t)(void *)ptr)

MY_API_END

#endif // !defined(__LIBMY_CORE_H__)
