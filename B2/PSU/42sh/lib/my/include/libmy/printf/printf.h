/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Defines the printf function and its variants
*/

/// @file
///
/// Defines the printf family of functions.
///
/// The functions in this module support all the standard convertions
/// specifiers expect for the floating point conversions (%f, %F, %f, %G, %a
/// and %A) as well the following conversions:
///
/// - %b, %B the unsigned integer is converted to unsigned binary notation, if
/// '#' is supplied then the prefix '0b' or '0B' is prepended if the specifier
/// if b, or B, respectively.
///
/// - %r, %R the unsigned integer is converted to a boolean and printed as
/// true/TRUE or false/FALSE whether the integer is different to zero
/// respectively.
///
/// - %S the const char * argument is printed as an octal string, accepts
/// @c NULL pointers.
///
/// - %s same as libC printf, prints the nul-terminated string argument, but
/// can accept @c NULL pointers.
///
/// The '#' flag may be used in string coversions (%s and %S) to surrond the
/// string with double quotes ("").
///
/// Positional precision, field width and arguments are supported.
/// @since 0.3.0

#ifndef __LIBMY_PRINTF_PRINTF_H__
#define __LIBMY_PRINTF_PRINTF_H__

#include "libmy/printf/config.h"

MY_API_BEGIN

#include "libmy/io.h"

#ifndef MY_PRINTF_BUF_SIZE
    /// The buffer size for non-streams versions of printf.
    #define MY_PRINTF_BUF_SIZE ((size_t)256)
#endif // !defiend(MY_PRINTF_BUF_SIZE)

/// An analogue of the @c printf function from LibC.
/// See module documentation for more information.
///
/// @param fmt The format.
/// @param ... The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_printf(char const *fmt, ...);

/// An analogue of the @c dprintf function from POSIX.1-2008.
/// See module documentation for more information.
///
/// @param fd  The output file descriptor.
/// @param fmt The format.
/// @param ... The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_dprintf(int fd, char const *fmt, ...);

/// An analogue of the @c fprintf function from LibC.
/// See module documentation for more information.
///
/// @param out The output stream.
/// @param fmt The format.
/// @param ... The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_fprintf(my_iostream_t *out, char const *fmt, ...);

/// An analogue of the @c sprintf function from LibC.
/// See module documentation for more information.
///
/// @param[out] str The output string, can be @c NULL.
///                 If not null, the string must have enough capacity to hold
///                 the output of this call and not overlap with @c fmt.
/// @param fmt      The format.
/// @param ...      The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_sprintf(char *str, char const *fmt, ...);

/// An analogue of the @c snprintf function from LibC.
/// See module documentation for more information.
///
/// @param[out] str The output string, can be @c NULL.
///                 If not null, the string must have enough capacity to hold
///                 @c size bytes and not overlap with @c fmt.
/// @param size     The maximum size of the buffer.
/// @param fmt      The format.
/// @param ...      The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_snprintf(char *str, size_t size, const char *fmt, ...);

/// An analogue of the @c asprintf function from the GNU LibC.
/// See module documentation for more information.
///
/// @param[out] strp Where the allocated string is stored,
///                  can be NULL.
/// @param fmt       The format.
/// @param ...       The arguments.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_asprintf(char **strp, const char *fmt, ...);

#include <stdarg.h>

/// An analogue of the @c vprintf function from LibC.
/// See module documentation for more information.
///
/// @param fmt  The format.
/// @param args The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_vprintf(char const *fmt, va_list args);

/// An analogue of the @c vdprintf function from POSIX.1-2008.
/// See module documentation for more information.
///
/// @param fd   The output file descriptor.
/// @param fmt  The format.
/// @param args The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_vdprintf(int fd, char const *fmt, va_list args);

/// An analogue of the @c vfprintf function from LibC.
/// See module documentation for more information.
///
/// @param out  The output stream.
/// @param fmt  The format.
/// @param args The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
///          If an I/O error occured, a negative value is returned.
/// @since 0.2.0
MY_PRINTF_API int my_vfprintf(
    my_iostream_t *out, char const *fmt, va_list args);

/// An analogue of the @c vsprintf function from LibC.
/// See module documentation for more information.
///
/// @param[out] str The output string, can be @c NULL.
///                 If not null, the string must have enough capacity to hold
///                 the output of this call and not overlap with @c fmt.
/// @param fmt      The format.
/// @param args     The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_vsprintf(char *str, char const *fmt, va_list args);

/// An analogue of the @c vsnprintf function from LibC.
/// See module documentation for more information.
///
/// @param[out] str The output string, can be @c NULL.
///                 If not null, the string must have enough capacity to hold
///                 @c size bytes and not overlap with @c fmt.
/// @param size     The maximum size of the buffer.
/// @param fmt      The format.
/// @param args     The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_vsnprintf(
    char *str, size_t size, const char *fmt, va_list args);

/// An analogue of the @c vasprintf function from the GNU LibC.
/// See module documentation for more information.
///
/// @param[out] strp Where the allocated string is stored,
///                  can be NULL.
/// @param fmt       The format.
/// @param args      The arguments as a @c va_list.
///
/// @returns The number of characters printed, excluding the null byte
///          used to end output to strings.
/// @since 0.2.0
MY_PRINTF_API int my_vasprintf(char **strp, const char *fmt, va_list args);

MY_API_END

#endif // !defined(__LIBMY_PRINTF_PRINTF_H__)
