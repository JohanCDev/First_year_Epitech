/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Error handling utilities
*/

#ifndef __SHELL_ERROR_H__
#define __SHELL_ERROR_H__

#include <assert.h>

#include "definition.h"

typedef enum sh_error {
    SH_OK = 0,
    SH_EXPRESSION_SYNTAX,
    SH_BAD_NUMBER,
    SH_BAD_VAR_START,
    SH_BAD_VAR_CHARS,
    SH_TOO_MANY_ARGS,
    SH_TOO_FEW_ARGS,
    SH_CD_NO_HOME_DIR,
    SH_CD_HOME_DIR,
    SH_OUT_OF_MEMORY,
    SH_INVALID_NULL_COMMAND,
    SH_MISSING_REDIRECT_NAME,
    SH_AMBIGUOUS_INPUT_REDIRECT,
    SH_AMBIGUOUS_OUTPUT_REDIRECT,
    SH_NO_MATCH,
    SH_READ_ONLY_VAR,
    SH_UNDEFINED_VAR,
    SH_ILLEGAL_VAR,
    SH_UNKNOWN_KEY,
    SH_UNKNOWN_KEYBIND_FUNCTION,
    SH_ALIAS_LOOP,
    SH_ERROR_MAX,
} sh_error_t;

/// Returns a string corresponding to the given error code.
///
/// @param code The error code.
///
/// @returns The error string, or "Unknown error" if <tt>code < SH_OK</tt> or
/// <tt>code >= SH_ERROR_MAX</tt>.
char const *sh_strerror(sh_error_t code);

/// Prints the given error code to the standard error output.
///
/// Does nothing if @c code is @c SH_OK.
///
/// @param prefix If not null or empty, prefix is printed followed by a colon
/// and a blank.
/// @param code The error code.
///
/// @returns The @c code argument.
sh_error_t sh_perror(char const *prefix, sh_error_t code);

/// Calls @ref sh_perror then returns the value of @c ret.
///
/// @param prefix If not null, prefix is printed followed by a colon
/// and a blank.
/// @param code The error code.
///
/// @returns The @c ret argument.
SH_INLINE int sh_rerror(char const *prefix, sh_error_t code, int ret)
{
    sh_perror(prefix, code);
    return ret;
}

/// Prints a message corresponding to the current value of @c errno.
///
/// @param prefix If not null, prefix is printed followed by a colon
/// and a blank.
///
/// @returns The value of @c errno
int sh_perror_errno(char const *prefix);

/// Prints a message corresponding the the current value of @c errno then
/// returns @c ret.
///
/// @param prefix If not null, prefix is printed followed by a colon
/// and a blank.
/// @param ret The return value.
///
/// @returns The @c ret parameter.
SH_INLINE int sh_rerror_errno(char const *prefix, int ret)
{
    sh_perror_errno(prefix);
    return ret;
}

/// Stores the error @c code in @c dst and returns @c ret.
///
/// @param[out] dst The location where @c code will be written. Must be a valid
/// pointer.
/// @param code The error code to write.
/// @param ret The return value.
///
/// @returns The @c ret parameter.
SH_INLINE int sh_serror(sh_error_t *dst, sh_error_t code, int ret)
{
    assert(dst != NULL);
    *dst = code;
    return ret;
}

#endif // !defined(__SHELL_ERROR_H__)
