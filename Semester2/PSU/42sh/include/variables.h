/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Variable handling
*/

#ifndef __SHELL_VARIABLES_H__
#define __SHELL_VARIABLES_H__

#include <libmy/ascii/character.h>

#include "context.h"
#include "util.h"

typedef struct sh_var_value {
    sh_lstr_t inner;
    bool read_only;
} sh_var_value_t;

/// Checks if the given character can be found right after a dollar sign.
SH_INLINE bool sh_is_var_expr_start(char c)
{
    return my_isalnum(c);
}

/// Validates a variable name.
///
/// A valid variable name matches the regex [a-zA-Z_][a-zA-Z_0-9]*
///
/// @param name The variable name.
/// @param name_len The number of characters in @c name.
///
/// @returns @c SH_OK if @c name is a valid variable name, or an error code
/// otherwise.
sh_error_t sh_check_var_name(char const *name, size_t name_len);

typedef struct sh_expansion {
    char *str;
    size_t value_begin;
    size_t value_end;
} sh_expansion_t;

/// Expands the first variable encountered in <tt>*str</tt> from
/// <tt>*offset</tt>.
///
/// @param ctx The shell context.
/// @param exp The variable expansion context.
/// @param[out] name The name of the variable,
/// set when the return value is @c SH_UNDEFINED_VAR.
/// @param copy_name Whether @c name should be allocated in its own buffer, if
/// @c true, @c name's value is valid or @c NULL regardless of the function's
/// return value and will need to be free'd.
///
/// @returns @c SH_OK if expansion succeded, @c SH_OUT_OF_MEMORY,
/// @c SH_UNDEFINED_VAR.
sh_error_t sh_expand_var(
    sh_ctx_t *ctx, sh_expansion_t *exp, sh_lstr_t *name, bool copy_name);

/// Expands all variables in <tt>*str</tt>, losing all variable value
/// position information in the process.
///
/// Do use this function if you require knowledge of where the variable are
/// expanded for argument inserting purposes.
sh_error_t sh_expand_vars(
    sh_ctx_t *ctx, char **str, sh_lstr_t *name, bool copy_name);

/// Prints the error code to stderr, unless it is @c SH_OK.
///
/// If the code is @c SH_UNDEFINED_VAR, the name of the variable is printed
/// alongside the error message.
///
/// @returns @c true if @c code is @c SH_OK, @c false otherwise.
bool sh_print_var_error(sh_error_t code, sh_lstr_t name);

#endif // !defined(__SHELL_VARIABLES_H__)
