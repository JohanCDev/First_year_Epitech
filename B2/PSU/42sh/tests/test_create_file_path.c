/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Tests the sh_create_file_path function
*/

#include <stdint.h>
#include <stdlib.h>
#include <criterion/criterion.h>

#include "util.h"

Test(sh_create_file_path, no_separator)
{
    char *path = sh_create_file_path(4, "yeet", "lel");

    cr_assert_str_eq(path, "yeet/lel");
    free(path);
    path = sh_create_file_path(16, "/usr/share/libmy", "libmy.a");
    cr_assert_str_eq(path, "/usr/share/libmy/libmy.a");
    free(path);
}

Test(sh_create_file_path, with_separator)
{
    char *path = sh_create_file_path(5, "yeet/", "lel");

    cr_assert_str_eq(path, "yeet/lel");
    free(path);
    path = sh_create_file_path(17, "/usr/share/libmy/", "libmy.a");
    cr_assert_str_eq(path, "/usr/share/libmy/libmy.a");
    free(path);
}
