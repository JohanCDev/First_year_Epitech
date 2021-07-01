/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The shell context
*/

#ifndef __SHELL_CONTEXT_H__
#define __SHELL_CONTEXT_H__

#include <libmy/collections.h>
#include <libmy/io/iostream.h>
#include <stdbool.h>

#include "definition.h"
#include "util.h"
#include "line_edit.h"

typedef struct sh_ctx {
    /// A vector of the environment entries.
    my_vec_t env;
    /// A map of local variables, includes shell variables as well.
    /// Key type: sh_lstr_t (allocated strings)
    /// Value type: sh_var_value_t (allocated strings)
    my_hash_map_t vars;
    /// Key type: sh_lstr_t (allocated strings)
    /// Value type: sh_alias_t (allocated strings)
    my_hash_map_t aliases;
    /// A vector of the entries from the PATH environment variable.
    my_vec_t path;
    /// A vector of sh_command_t
    my_vec_t pipeline;
    /// The line edition structure
    sh_line_edit_t line_edit;
    /// Is stdin a tty?
    int is_tty;
    /// The exit code of the previous program.
    int exit_code;
    /// The previous working directory, initialized to @c NULL.
    char *old_pwd;
    /// Exit value of exit builtins
    int had_exit_cmd;
    /// The current shell input
    my_iostream_t *input;
    /// The number of argument of the current shell.
    size_t argc;
    /// The arguments of the current shell.
    char const **argv;
} sh_ctx_t;

/// Initializes the shell's context
///
/// @param envp A NULL-terminared array of strings.
///
/// @returns 0 if successful.
int sh_ctx_init(sh_ctx_t *ctx, int argc, char const *argv[], char **envp);

/// Frees the contents of the shell context.
///
/// @param ctx The shell context.
void sh_ctx_drop(sh_ctx_t *ctx);

/// Reads the path environment variable
///
/// @param ctx The shell context.>
void sh_ctx_reset_path(sh_ctx_t *ctx);

#endif // !defined(__SHELL_CONTEXT_H__)
