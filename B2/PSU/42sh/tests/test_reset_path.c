/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Tests the sh_ctx_reset_path function
*/

#include <criterion/criterion.h>
#include "context.h"

Test(sh_ctx_reset_path, no_path)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"LS_COLORS=?", "USER=yeet", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.path.length, 2);
    cr_assert_gt(ctx.path.capacity, 2);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 0), "/usr/bin");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 1), "/bin");
}

Test(sh_ctx_reset_path, empty_path)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"LS_COLORS=?", "PATH=", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.path.length, 0);
    cr_assert_eq(ctx.path.capacity, 0);
}

Test(sh_ctx_reset_path, empty_entries)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"PATH=::::/bin:", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.path.length, 1);
    cr_assert_gt(ctx.path.capacity, 1);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 0), "/bin");
}

Test(sh_ctx_reset_path, normal_path)
{
    sh_ctx_t ctx;
    char const *argv[] = {"42sh", NULL};
    char *envp[] = {"USER=?", "PATH=/usr/bin:/bin/:/usr/local/bin", NULL};

    cr_assert_eq(sh_ctx_init(&ctx, 1, argv, envp), 0);
    cr_assert_eq(ctx.path.length, 3);
    cr_assert_gt(ctx.path.capacity, 3);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 0), "/usr/bin");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 1), "/bin/");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &ctx.path, 2), "/usr/local/bin");
}
