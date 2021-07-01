/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Builtin commands execution
*/

#ifndef __SHELL_BUILTIN_H__
#define __SHELL_BUILTIN_H__

#include "context.h"

typedef struct {
    char const *name;
    bool need_glob;
    int (*run)(sh_ctx_t *, int *, size_t, char const *[]);
} sh_builtin_t;

extern const sh_builtin_t BUILTINS[];
extern const size_t BUILTIN_COUNT;

/// Fetches a builtin command by name.
///
/// @param name The name of the command.
///
/// @return The builtin, or @c NULL if not found.
sh_builtin_t const *sh_get_builtin(char const *name);

typedef enum {
    /// '-p' option.
    SH_DIRS_PRINT = 1,
    /// '-l' option.
    SH_DIRS_LONG = 2,
    /// '-n' option.
    SH_DIRS_WRAP = 4,
    /// '-v' option.
    SH_DIRS_FULL = 8,
} sh_dirs_options_t;

void sh_dirs_run(sh_ctx_t *ctx, sh_dirs_options_t options);

int sh_builtin_alias(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_bindkey(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_builtins(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_cd(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_dirs(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_env(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_exit(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_repeat(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_set(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_setenv(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_source(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_unalias(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_unset(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);
int sh_builtin_unsetenv(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[]);

#endif // !defined(__SHELL_BUILTIN_H__)
