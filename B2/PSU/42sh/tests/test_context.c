/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Tests the shell context functions
*/

#include <stdint.h>
#include <criterion/criterion.h>
#include "context.h"

Test(sh_ctx_init, empty_env)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.env.capacity, 1);
    cr_assert_eq(ctx.env.length, 1);
    cr_assert_eq(ctx.exit_code, 0);
    cr_assert_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 0), NULL);
}

Test(sh_ctx_init, no_path)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"LS_COLORS=?", "USER=yeet", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.env.capacity, 3);
    cr_assert_eq(ctx.env.length, 3);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 0), "LS_COLORS=?");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 1), "USER=yeet");
    cr_assert_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 2), NULL);
    cr_assert_eq(ctx.is_tty, 0);
    cr_assert_eq(ctx.exit_code, 0);
}

Test(sh_ctx_init, normal_env)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"LS_COLORS=?", "PATH=/bin", "USER=yeet", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.env.capacity, 4);
    cr_assert_eq(ctx.env.length, 4);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 0), "LS_COLORS=?");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 1), "PATH=/bin");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 2), "USER=yeet");
    cr_assert_eq(MY_VEC_GET_ELEM(char *, &ctx.env, 3), NULL);
    cr_assert_eq(ctx.is_tty, 0);
    cr_assert_eq(ctx.exit_code, 0);
}

Test(sh_ctx_drop, normal)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=/usr/bin", "USER=root", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.is_tty, 0);
    cr_assert_eq(ctx.exit_code, 0);
    sh_ctx_drop(&ctx);
}
