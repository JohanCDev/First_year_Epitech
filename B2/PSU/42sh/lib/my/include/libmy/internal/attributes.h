/*
** EPITECH PROJECT, 2020
** LibMy - core module internals
** File description:
** Core attribute definitions
*/

#ifndef __LIBMY_INTERNAL_ATTRIBUTES_H__
#define __LIBMY_INTERNAL_ATTRIBUTES_H__

#ifdef __cplusplus
#ifdef __GNUC__
#define MY_ATTRIBUTE(attr_params) __attribute__((attr_params))
#else // !defined(_GNUC_)
#define MY_ATTRIBUTE(attr_params) [[gnu::attr_params]]
#endif // defined(_GNUC_)
#define MY_API_BEGIN extern "C" {
#define MY_API_END }
#else // !defined(__cplusplus)
#define MY_ATTRIBUTE(attr_params) __attribute__((attr_params))
#define MY_API_BEGIN
#define MY_API_END
#endif // defined(__cplusplus)

#if __GNUC__ >= 4
#define MY_API_IMPORT MY_ATTRIBUTE(visibility("default"))
#define MY_API_EXPORT MY_ATTRIBUTE(visibility("default"))
#define MY_LOCAL MY_ATTRIBUTE(visibility("hidden"))
#else // __GNUC__ < 4
#define MY_API_IMPORT
#define MY_API_EXPORT
#define MY_LOCAL
#endif // __GNUC__ >= 4

#if __GNUC__
#define MY_INLINE MY_ATTRIBUTE(always_inline) inline
#else // !defined(__GNUC__)
#define MY_INLINE inline
#endif // defined(__GNUC__)

#endif // !defined(__LIBMY_INTERNAL_ATTRIBUTES_H__)
