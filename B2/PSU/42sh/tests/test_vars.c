/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Tests the local variables functions
*/

#include <criterion/criterion.h>

#include "shell.h"
#include "variables.h"

Test(sh_var_set, read_write_var)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};
    sh_lstr_t value;

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(
        sh_var_set(&ctx, SH_LSTR("shell", 5), SH_LSTR("42sh", 4), false),
        SH_OK);
    value = sh_var_get(&ctx, SH_LSTR("shell", 5));
    cr_assert_eq(value.length, 4);
    cr_assert(my_memcmp(value.value, "42sh", 4) == 0);
    sh_ctx_drop(&ctx);
}

Test(sh_var_set, read_only_var)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};
    sh_lstr_t value;

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(
        sh_var_set(&ctx, SH_LSTR("shell", 5), SH_LSTR("42sh", 4), true),
        SH_OK);
    cr_assert_eq(
        sh_var_set(&ctx, SH_LSTR("shell", 5), SH_LSTR("42sh", 4), true),
        SH_READ_ONLY_VAR);
    value = sh_var_get(&ctx, SH_LSTR("shell", 5));
    cr_assert_eq(value.length, 4);
    cr_assert(my_memcmp(value.value, "42sh", 4) == 0);
    sh_ctx_drop(&ctx);
}

Test(sh_var_remove, not_found)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};
    sh_lstr_t value;

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(sh_var_remove(&ctx, SH_LSTR("shell", 5)), SH_OK);
    value = sh_var_get(&ctx, SH_LSTR("shell", 5));
    cr_assert_eq(value.length, 0);
    cr_assert_eq(value.value, NULL);
    sh_ctx_drop(&ctx);
}

Test(sh_var_remove, read_write_var)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};
    sh_lstr_t value;

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(
        sh_var_set(&ctx, SH_LSTR("shell", 5), SH_LSTR("42sh", 4), false),
        SH_OK);
    cr_assert_eq(sh_var_remove(&ctx, SH_LSTR("shell", 5)), SH_OK);
    value = sh_var_get(&ctx, SH_LSTR("shell", 5));
    cr_assert_eq(value.length, 0);
    cr_assert_eq(value.value, NULL);
    sh_ctx_drop(&ctx);
}

Test(sh_var_remove, read_only_var)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", NULL};
    sh_lstr_t value;

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(
        sh_var_set(&ctx, SH_LSTR("shell", 5), SH_LSTR("42sh", 4), true),
        SH_OK);
    cr_assert_eq(sh_var_remove(&ctx, SH_LSTR("shell", 5)), SH_READ_ONLY_VAR);
    value = sh_var_get(&ctx, SH_LSTR("shell", 5));
    cr_assert_eq(value.length, 4);
    cr_assert(my_memcmp(value.value, "42sh", 4) == 0);
    sh_ctx_drop(&ctx);
}

Test(sh_check_var_name, invalid_start)
{
    cr_assert_eq(sh_check_var_name(NULL, 42), SH_BAD_VAR_START);
    cr_assert_eq(sh_check_var_name("yeet", 0), SH_BAD_VAR_START);
    cr_assert_eq(sh_check_var_name("!lel", 4), SH_BAD_VAR_START);
    cr_assert_eq(sh_check_var_name(" lel", 4), SH_BAD_VAR_START);
    cr_assert_eq(sh_check_var_name("~lel", 4), SH_BAD_VAR_START);
}

Test(sh_check_var_name, invalid_chars)
{
    cr_assert_eq(sh_check_var_name("f*rge", 5), SH_BAD_VAR_CHARS);
    cr_assert_eq(sh_check_var_name("f rge", 5), SH_BAD_VAR_CHARS);
    cr_assert_eq(sh_check_var_name("f~rge", 5), SH_BAD_VAR_CHARS);
}

Test(sh_check_var_name, valid_names)
{
    cr_assert_eq(sh_check_var_name("_", 1), SH_OK);
    cr_assert_eq(sh_check_var_name("_=/bin/sh", 1), SH_OK);
    cr_assert_eq(sh_check_var_name("asdf", 4), SH_OK);
    cr_assert_eq(sh_check_var_name("ASDF", 4), SH_OK);
    cr_assert_eq(sh_check_var_name("ThiSISAteST", 11), SH_OK);
    cr_assert_eq(sh_check_var_name("SSH_AGENT", 9), SH_OK);
}
