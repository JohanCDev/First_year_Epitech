/*
** EPITECH PROJECT, 2020
** LibMy - printf module internals
** File description:
** The internals for the printf module
*/

#ifndef __LIBMY_SRC_PRINTF_MY_PRINTF_H__
#define __LIBMY_SRC_PRINTF_MY_PRINTF_H__

#include "libmy/internal/attributes.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include "libmy/io.h"

typedef enum {
    /// When no length is present.
    P_MY_PRINTF_LEN_DEFAULT,
    /// length: h
    P_MY_PRINTF_LEN_CHAR,
    /// length: hh
    P_MY_PRINTF_LEN_SHORT,
    /// length: l
    P_MY_PRINTF_LEN_LONG,
    /// length: ll
    P_MY_PRINTF_LEN_LONG_LONG,
    /// length: L
    P_MY_PRINTF_LEN_LONG_DOUBLE,
    /// length: j
    P_MY_PRINTF_LEN_INTMAX_T,
    /// length: z
    P_MY_PRINTF_LEN_SIZE_T,
    /// length: t
    P_MY_PRINTF_LEN_PTRDIFF_T,
} p_my_printf_length_t;

typedef enum {
    /// When is conversion specifier is invalid.
    P_MY_PRINTF_SPEC_NONE,
    /// specifiers: d, i
    P_MY_PRINTF_SPEC_SIGNED,
    /// specifier: u
    P_MY_PRINTF_SPEC_UNSIGNED,
    /// specifier: o
    P_MY_PRINTF_SPEC_OCTAL,
    /// specifier: x
    P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL,
    /// specifier: X
    P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL,
    /// specifier: b
    P_MY_PRINTF_SPEC_LOWER_BINARY,
    /// specifier: B
    P_MY_PRINTF_SPEC_UPPER_BINARY,
    /// specifier: r
    P_MY_PRINTF_SPEC_LOWER_BOOLEAN,
    /// specifier: R
    P_MY_PRINTF_SPEC_UPPER_BOOLEAN,
    /// specifier: f
    P_MY_PRINTF_SPEC_LOWER_FLOAT,
    /// specifier: F
    P_MY_PRINTF_SPEC_UPPER_FLOAT,
    /// specifier: e
    P_MY_PRINTF_SPEC_LOWER_FLOAT_EXPONENT,
    /// specifier: E
    P_MY_PRINTF_SPEC_UPPER_FLOAT_EXPONENT,
    /// specifier: g
    P_MY_PRINTF_SPEC_LOWER_FLOAT_SCIENTIFIC,
    /// specifier: G
    P_MY_PRINTF_SPEC_UPPER_FLOAT_SCIENTIFIC,
    /// specifier: a
    P_MY_PRINTF_SPEC_LOWER_FLOAT_HEXADECIMAL,
    /// specifier: A
    P_MY_PRINTF_SPEC_UPPER_FLOAT_HEXADECIMAL,
    /// specifier: c
    P_MY_PRINTF_SPEC_CHAR,
    /// specifier: s
    P_MY_PRINTF_SPEC_STRING,
    /// specifier: S
    P_MY_PRINTF_SPEC_STRING_OCTAL,
    /// specifier: p
    P_MY_PRINTF_SPEC_POINTER,
    /// specifier: n
    P_MY_PRINTF_SPEC_COUNT,
    /// specifier: %
    P_MY_PRINTF_SPEC_PERCENT,
    P_MY_PRINTF_SPEC_MAX_VALUE
} p_my_printf_specifier_t;

typedef enum {
    /// length: hh, specifiers: d i
    P_MY_PRINTF_ARG_SBYTE = 0,
    /// length: hh, specifiers: d i
    P_MY_PRINTF_ARG_BYTE = 1,
    /// length: h, specifiers: d i
    P_MY_PRINTF_ARG_SHORT = 2,
    /// length: h, specifiers: o u x X
    P_MY_PRINTF_ARG_USHORT = 3,
    /// specifiers: d i
    P_MY_PRINTF_ARG_INT = 4,
    /// specifiers: o u x X
    P_MY_PRINTF_ARG_UINT = 5,
    /// length: l, specifiers: d i
    P_MY_PRINTF_ARG_LONG = 6,
    /// length: l, specifiers: o u x X
    P_MY_PRINTF_ARG_ULONG = 7,
    /// length: ll, specifiers: d i
    P_MY_PRINTF_ARG_LONG_LONG = 8,
    /// length: ll, specifiers: o u x X
    P_MY_PRINTF_ARG_ULONG_LONG = 9,
    /// length: j, specifiers: d i o u x X
    P_MY_PRINTF_ARG_INTMAX_T = 10,
    /// length: j, specifiers: o u x X
    P_MY_PRINTF_ARG_UINTMAX_T = 11,
    /// length: z, specifiers: d i
    P_MY_PRINTF_ARG_SSIZE_T = 12,
    /// length: z, specifiers: o u x X
    P_MY_PRINTF_ARG_SIZE_T = 13,
    /// length: t: specifiers: d i
    P_MY_PRINTF_ARG_PTRDIFF_T = 14,
    /// length: t: specifiers: o u x X
    P_MY_PRINTF_ARG_UPTRDIFF_T = 15,
    /// specifiers: f F e E g G a A
    P_MY_PRINTF_ARG_DOUBLE = 16,
    /// length: L, specifiers: f F e E g G a A
    P_MY_PRINTF_ARG_LONG_DOUBLE = 18,
    /// specifiers: s
    P_MY_PRINTF_ARG_STRING = 20,
    /// length: hh?, specifiers: c d i o u x X
    P_MY_PRINTF_ARG_CHAR = 22,
    /// specifier: p
    P_MY_PRINTF_ARG_POINTER = 24,
    /// length: hh, specifier: n
    P_MY_PRINTF_ARG_PTR_SCHAR,
    /// length: h, specifier: n
    P_MY_PRINTF_ARG_PTR_SHORT = 26,
    /// specifier: n
    P_MY_PRINTF_ARG_PTR_INT = 28,
    /// length: l, specifier: n
    P_MY_PRINTF_ARG_PTR_LONG = 30,
    /// length: ll, specifier: n
    P_MY_PRINTF_ARG_PTR_LONG_LONG = 32,
    /// length: j, specifier: n
    P_MY_PRINTF_ARG_PTR_INTMAX_T = 34,
    /// length: z, specifier: n
    P_MY_PRINTF_ARG_PTR_SIZE_T = 36,
    /// length: t, specifier: n
    P_MY_PRINTF_ARG_PTR_PTRDIFF_T = 38,
    P_MY_PRINTF_ARG_PERCENT = 40,
    P_MY_PRINTF_ARG_MAX_VALUE
} p_my_printf_arg_type_t;

typedef enum {
    P_MY_PRINTF_FLAG_NONE,
    P_MY_PRINTF_FLAG_ALT = 1,
    P_MY_PRINTF_FLAG_ZERO_PAD = 2,
    P_MY_PRINTF_FLAG_LEFT_ADJUST = 4,
    P_MY_PRINTF_FLAG_SIGN_BLANK = 8,
    P_MY_PRINTF_FLAG_PLACE_SIGN = 16,
    P_MY_PRINTF_FLAG_GROUP_DIGITS = 32,
    P_MY_PRINTF_FLAG_ALT_DIGITS = 64,
    P_MY_PRINTF_FLAG_HAS_FIELD_WIDTH = 128,
    P_MY_PRINTF_FLAG_HAS_PRECISION = 256
} p_my_printf_flag_t;

typedef union {
    intmax_t sint_arg;
    uintmax_t uint_arg;
    double double_arg;
    long double long_double_arg;
    char char_arg;
    char const *string_arg;
    void const *pointer_arg;
    signed char *schar_ptr_arg;
    short *short_ptr_arg;
    int *int_ptr_arg;
    long *long_ptr_arg;
    long long *long_long_ptr_arg;
    intmax_t *intmax_t_ptr_arg;
    size_t *size_t_ptr_arg;
    ptrdiff_t *ptrdiff_t_ptr_arg;
} p_my_printf_arg_t;

typedef struct {
    p_my_printf_arg_t value;
    p_my_printf_arg_type_t type;
    p_my_printf_specifier_t specifier;
    int flags;
    unsigned int field_width;
    unsigned int precision;
} p_my_printf_conv_t;

/// Gets the index of a positional argument and advances the string
/// if the index is a number followed by a dollar sign.
///
/// @param conv    The source string.
/// @param arg_pos The position of the current argument.
///                Is incremented by one if index is a number.
///
/// @returns 0 if successful, 1 otherwise.
MY_LOCAL int p_my_printf_get_position(char const **conv, size_t *arg_pos);

/// Jumps to the next conversion specifier.
///
/// @param str The string to consume.
///
/// @returns The offset to the next convertion specifier,
///          or 0 if no specifier is found.
MY_LOCAL size_t p_my_printf_next_conversion(char const **str);

/// Parses the conversion in the given string.
/// The conversion is not consumed if not valid.
///
/// @param src   The source to parse.
/// @param args  The array of arguments.
/// @param types The array of argument types.
/// @param pos   The position of the next argument,
///              updated after parsing depending on the number of
///              non-positional field width, precision or argument.
///
/// @returns The parsed conversion, if not valid, its specifier field is set to
///          @ref P_MY_PRINTF_SPEC_NONE.
MY_LOCAL p_my_printf_conv_t p_my_printf_parse_conversion(char const **src,
    p_my_printf_arg_t const args[], p_my_printf_arg_type_t const types[],
    size_t *pos);

/// Parses the next flags in the given string.
/// The characters of @c flags are consumed until a non-flag character is
/// found.
///
/// Current accepted flags:
/// - '#'  -> @ref P_MY_PRINTF_FLAG_ALT
/// - '0'  -> @ref P_MY_PRINTF_FLAG_ZERO_PAD
/// - '-'  -> @ref P_MY_PRINTF_FLAG_LEFT_ADJUST
/// - ' '  -> @ref P_MY_PRINTF_FLAG_SIGN_BLANK
/// - '+'  -> @ref P_MY_PRINTF_FLAG_PLACE_SIGN
/// - '\'' -> @ref P_MY_PRINTF_FLAG_GROUP_DIGITS
/// - 'I'  -> @ref P_MY_PRINTF_FLAG_ALT_DIGITS
///
/// @param flags The string containing the flags.
///
/// @returns The parsed flags, or zero if no flags was found.
MY_LOCAL int p_my_printf_get_flags(char const **flags);

/// Counts the number of paramerters required by the given format string.
///
/// @param fmt The format string.
///
/// @returns The number of required parameters.
MY_LOCAL size_t p_my_printf_count_parameters(char const *fmt);

/// Parses the next length modifier in the given string.
///
/// Current accepted length modifiers:
/// - hh -> @ref P_MY_PRINTF_LEN_CHAR
/// - h  -> @ref P_MY_PRINTF_LEN_SHORT
/// - l  -> @ref P_MY_PRINTF_LEN_LONG
/// - ll -> @ref P_MY_PRINTF_LEN_LONG_LONG
/// - L  -> @ref P_MY_PRINTF_LEN_LONG_DOUBLE
/// - j  -> @ref P_MY_PRINTF_LEN_INTMAX_T
/// - z  -> @ref P_MY_PRINTF_LEN_SIZE_T
/// - t  -> @ref P_MY_PRINTF_LEN_PTRDIFF_T
///
/// @returns The parsed length modifier, or @ref P_MY_PRINTF_LEN_DEFAULT
///          if no length modifier is present.
MY_LOCAL p_my_printf_length_t p_my_printf_get_len_modifier(char const **src);

/// Parses the next conversion specifier from the given string.
///
/// Current accepted conversion specifiers:
/// - d, i -> @ref P_MY_PRINTF_SPEC_SIGNED
/// - u    -> @ref P_MY_PRINTF_SPEC_UNSIGNED
/// - o    -> @ref P_MY_PRINTF_SPEC_OCTAL
/// - x    -> @ref P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL
/// - X    -> @ref P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL
/// - b    -> @ref P_MY_PRINTF_SPEC_LOWER_BINARY
/// - B    -> @ref P_MY_PRINTF_SPEC_UPPER_BINARY
/// - r    -> @ref P_MY_PRINTF_SPEC_LOWER_BOOLEAN
/// - R    -> @ref P_MY_PRINTF_SPEC_UPPER_BOOLEAN
/// - f    -> @ref P_MY_PRINTF_SPEC_LOWER_FLOAT
/// - F    -> @ref P_MY_PRINTF_SPEC_UPPER_FLOAT
/// - e    -> @ref P_MY_PRINTF_SPEC_LOWER_FLOAT_EXPONENT
/// - E    -> @ref P_MY_PRINTF_SPEC_UPPER_FLOAT_EXPONENT
/// - g    -> @ref P_MY_PRINTF_SPEC_LOWER_FLOAT_SCIENTIFIC
/// - G    -> @ref P_MY_PRINTF_SPEC_UPPER_FLOAT_SCIENTIFIC
/// - a    -> @ref P_MY_PRINTF_SPEC_LOWER_FLOAT_HEXADECIMAL
/// - A    -> @ref P_MY_PRINTF_SPEC_UPPER_FLOAT_HEXADECIMAL
/// - c    -> @ref P_MY_PRINTF_SPEC_CHAR
/// - s    -> @ref P_MY_PRINTF_SPEC_STRING
/// - S    -> @ref P_MY_PRINTF_SPEC_STRING_OCTAL
/// - p    -> @ref P_MY_PRINTF_SPEC_POINTER
/// - n    -> @ref P_MY_PRINTF_SPEC_COUNT
///
/// @returns The parsed conversion specifier, or @ref P_MY_PRINTF_SPEC_NONE
///          if the specifier is invalid.
MY_LOCAL p_my_printf_specifier_t p_my_printf_get_conv_specifier(
    char const **src);

/// Creates an argument type from a length and a specifier.
///
/// @param len       The length of the type.
/// @param specifier The conversion specifier.
///
/// @returns The created type.
MY_LOCAL p_my_printf_arg_type_t p_my_printf_get_type(
    p_my_printf_length_t len, p_my_printf_specifier_t specifier);

/// Fills the passed type array with the parsed type information from @c fmt.
/// The caller must ensure that @c type has enough space fit all types
/// specified in @c fmt.
///
/// @param fmt   The format string.
/// @param types The type array to fill.
MY_LOCAL void p_my_printf_fill_types(
    char const *fmt, p_my_printf_arg_type_t types[]);

/// Fills the passed arg array with the supplied va_list and the type array.
/// All integer types are converted to intmax_t/uintmax_t depending on
/// their signedness.
///
/// @param count     The number of args to fill.
/// @param[out] args The array to fill.
/// @param types     The types of arguments to fetch from @c va_args.
/// @param va_args   The source va_list.
MY_LOCAL void p_my_printf_fill_args(size_t count, p_my_printf_arg_t args[],
    p_my_printf_arg_type_t types[], va_list va_args);

/// Returns the corresponding base for a given numerical base.
///
/// @param conv      The conversion.
/// @param[out] base Where the store the base, can be @c NULL.
///
/// @returns The size of @c base.
MY_LOCAL unsigned p_my_printf_get_conv_base(
    p_my_printf_conv_t const *conv, char const **base);

MY_LOCAL int p_my_printf_lpad(
    my_iostream_t *output, p_my_printf_conv_t const *conv, size_t len, char c);
MY_LOCAL int p_my_printf_rpad(
    my_iostream_t *output, p_my_printf_conv_t const *conv, size_t len, char c);
MY_LOCAL int p_my_printf_zpad(my_iostream_t *output, size_t zeros);

typedef size_t (*p_my_printf_conv_len_t)(p_my_printf_conv_t const *, size_t *);

MY_LOCAL size_t p_my_printf_sint_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_uint_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_boolean_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_char_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_string_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_pointer_len(
    p_my_printf_conv_t const *conv, size_t *zeros);
MY_LOCAL size_t p_my_printf_conversion_len(
    p_my_printf_conv_t const *conv, size_t *zeros);

typedef int (*p_my_printf_conv_impl_t)(
    my_iostream_t *, p_my_printf_conv_t const *, size_t, size_t);

MY_LOCAL int p_my_printf_sint(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_uint(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_boolean(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_char(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_string(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_pointer(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_percent(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros);
MY_LOCAL int p_my_printf_conversion(
    my_iostream_t *output, p_my_printf_conv_t const *convi, size_t char_count);

#define PGET_FLAG(f) (conv->flags & P_MY_PRINTF_FLAG_##f)
#define PGET_SPEC(f) (conv->specifier == P_MY_PRINTF_SPEC_##f)

#endif // !defined(__LIBMY_SRC_PRINTF_MY_PRINTF_H__)
