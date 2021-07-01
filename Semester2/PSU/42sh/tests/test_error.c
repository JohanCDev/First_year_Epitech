/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** tests the error functions
*/

#include <libmy/io.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"

static void setup(void)
{
    my_init_stderr(malloc(256), 256, &free);
    cr_redirect_stderr();
}

static void finish(void)
{
    my_free_stderr();
}

Test(sh_strerror, invalid_code)
{
    cr_assert_str_eq(sh_strerror(-42), "Unknown error");
    cr_assert_str_eq(sh_strerror(SH_ERROR_MAX), "Unknown error");
    cr_assert_str_eq(sh_strerror(SH_ERROR_MAX + 1), "Unknown error");
}

Test(sh_perror, no_error, .init = &setup, .fini = &finish)
{
    sh_perror("test", SH_OK);
    sh_perror("", SH_OK);
    sh_perror(NULL, SH_OK);
    my_eputc('X');
    my_flush_stderr();
    cr_assert_stderr_eq_str("X", "");
}

Test(sh_perror, normal_error, .init = &setup, .fini = &finish)
{
    sh_perror("test", SH_BAD_NUMBER);
    sh_perror("", SH_EXPRESSION_SYNTAX);
    sh_perror(NULL, SH_BAD_NUMBER);
    my_flush_stderr();
    cr_assert_stderr_eq_str("test: Badly formed number.\n: Expression "
                            "Syntax.\nBadly formed number.\n ",
        "");
}
