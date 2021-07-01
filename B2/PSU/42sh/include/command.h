/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Command type definition
*/

#ifndef __SHELL_COMMAND_H__
#define __SHELL_COMMAND_H__

#include "builtin.h"
#include "token.h"

typedef enum sh_pipe_pos {
    SH_PIPE_BEGIN,
    SH_PIPE_MIDDLE,
    SH_PIPE_END,
    SH_PIPE_INVALID,
} sh_pipe_pos_t;

typedef enum sh_command_type {
    SH_COMMAND_UNRESOLVED,
    SH_COMMAND_EXTERNAL,
    SH_COMMAND_BUILTIN,
    SH_COMMAND_NOT_FOUND,
    SH_COMMAND_TYPE_COUNT,
} sh_command_type_t;

typedef struct sh_command_base {
    sh_command_type_t command_type;
    my_vec_t args;
    /// A vector of element type sh_token_type_t.
    /// Elements have either @c SH_TOKEN_SINGLE_STR, @c SH_TOKEN_DOUBLE_STR,
    /// @c SH_TOKEN_UNQUOTED_STR, or @c SH_TOKEN_ESCAPED_NAME as values.
    /// Each entry in this vector corresponds corresponds to one in @c args.
    my_vec_t arg_types;
    sh_pipe_pos_t pipe_pos;
    /// The path of the input redirection, set to @c NULL if no redirection.
    char *input;
    /// Either @c SH_TOKEN_SINGLE_STR, @c SH_TOKEN_DOUBLE_STR
    /// @c SH_TOKEN_UNQUOTED_STR, or @c SH_TOKEN_ESCAPED_NAME.
    sh_token_type_t input_type;
    /// The path of the output redirection, set to @c NULL if no redirection.
    char *output;
    /// Either @c SH_TOKEN_SINGLE_STR, @c SH_TOKEN_DOUBLE_STR
    /// @c SH_TOKEN_UNQUOTED_STR, or @c SH_TOKEN_ESCAPED_NAME.
    sh_token_type_t output_type;
    bool truncate;
    int pipe_in[2];
    int pipe_out[2];
} sh_command_base_t;

typedef struct sh_builtin_command {
    sh_command_base_t base;
    sh_builtin_t const *builtin;
} sh_builtin_command_t;

typedef struct sh_external_command {
    sh_command_base_t base;
    char const *path;
} sh_external_command_t;

typedef union sh_command {
    sh_command_type_t command_type;
    sh_command_base_t base;
    sh_builtin_command_t builtin;
    sh_external_command_t external;
} sh_command_t;

void sh_command_init(sh_command_t *command);

void sh_command_reset(sh_command_t *command);

void sh_command_drop(sh_command_t *command);

int sh_command_parse(sh_command_t *command, size_t token_count,
    sh_token_t tokens[], sh_pipe_pos_t pipe_pos);

bool sh_command_resolve(sh_ctx_t *ctx, sh_command_t *command);

/// Expands variable expressions (such as $VAR) into their values.
///
/// Errors are printed to the standard output.
///
/// @returns @c true on success, or @c false on error.
bool sh_command_expand_vars(sh_ctx_t *ctx, sh_command_t *command);

/// Expands the variables in a redirect name.
///
/// Errors are printed to the standard output.
///
/// @returns @c true if expansion successed (or no expansion was needed), or @c
/// false on error.
bool sh_command_expand_redirect(
    sh_ctx_t *ctx, char **name, sh_token_type_t *type);

bool sh_command_expand_aliases(sh_ctx_t *ctx, sh_command_t *command);

bool sh_command_need_globbing(sh_command_t *command, glob_t *globbuf);
bool sh_command_globbing(sh_ctx_t *ctx, sh_command_t *command);

/// Opens both input and output redirect files of the first command @c c1
///
/// The names are both expanded by @ref sh_command_expand_redirect before
/// opening.
///
/// @param ctx The shell context.
/// @param c1 The current command in which to open the redirects.
/// @param c2 The next command, used for pipe setup, can be @c NULL.
///
/// @returns @c true on success, or @c false on expansion or open failure.
bool sh_command_open_redirects(
    sh_ctx_t *ctx, sh_command_t *c1, sh_command_t *c2);

/// Executes a single command.
///
/// @param ctx The shell context.
/// @param command The command to execute.
/// @param next_command The next command, used for pipe setup, can be @c NULL.
int sh_command_execute(
    sh_ctx_t *ctx, sh_command_t *command, sh_command_t *next_command);

int sh_execute_external(sh_ctx_t *ctx, sh_external_command_t *command);
int sh_execute_builtin(sh_ctx_t *ctx, sh_builtin_command_t *command);

int sh_external_pipe_setup(
    sh_ctx_t *ctx, sh_pipe_pos_t pipe_pos, int old_pipe_fd[2]);
int sh_external_pipe_dup(
    sh_ctx_t *ctx, sh_pipe_pos_t pipe_pos, int old_pipe_fd[2]);
int sh_external_pipe_close(
    sh_ctx_t *ctx, sh_pipe_pos_t pipe_pos, int old_pipe_fd[2]);

#define SH_INPUT_FLAGS (O_RDONLY | O_CLOEXEC)

#define SH_OUTPUT_FLAGS_BASE (O_WRONLY | O_CREAT | O_CLOEXEC)
#define SH_OUTPUT_FLAGS(cmd) \
    (SH_OUTPUT_FLAGS_BASE | ((cmd)->truncate ? O_TRUNC : O_APPEND))

/// Files created by an output redirect have the mode:
/// u+rw, g+r, o+r
#define SH_OUTPUT_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/// The value of an alias
typedef struct sh_alias {
    char *value;
    size_t length;
    int multi_word;
} sh_alias_t;

/// A full alias entry
typedef struct sh_alias_entry {
    sh_lstr_t key;
    sh_alias_t value;
} sh_alias_entry_t;

#endif // !defined(__SHELL_COMMAND_H__)
