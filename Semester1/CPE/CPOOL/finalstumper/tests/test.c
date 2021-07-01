/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-johan.chrillesen
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "rush3.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(rush3, rush, .init = redirect_all_stdout)
{
    char *buff = "o--o\n";
    rush3(buff);
    cr_assert_stdout_eq_str("[rush1-1] 1 4");
}