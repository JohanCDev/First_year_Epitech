/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, unsigned_test, .init = redirect_all_std)
{
    my_printf("%u %u", -4, 4);
    cr_assert_stdout_eq_str("4294967292 4");
}

Test (my_printf, int_test, .init = redirect_all_std)
{
    my_printf("%d %d", 14, -14);
    cr_assert_stdout_eq_str("14 -14");
}

Test (my_printf, int_test_with_i, .init = redirect_all_std)
{
    my_printf("%i %i", 14, -14);
    cr_assert_stdout_eq_str("14 -14");
}

Test (my_printf, char_test, .init = redirect_all_std)
{
    my_printf("%c %c %c", 'a', 48, '0');
    cr_assert_stdout_eq_str("a 0 0");
}

Test (my_printf, string, .init = redirect_all_std)
{
    my_printf("%s", "Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test (my_printf, octal_test, .init = redirect_all_std)
{
    my_printf("%o %o %o", 8, 7, 64);
    cr_assert_stdout_eq_str("10 7 100");
}

Test (my_printf, octal_test_with_tag, .init = redirect_all_std)
{
    my_printf("%#o", 8);
    cr_assert_stdout_eq_str("010 07 0100");
}

Test (my_printf, hexa_test_with_x, .init = redirect_all_std)
{
    my_printf("%x %x", 79, 642435);
    cr_assert_stdout_eq_str("4f 9cd83");
}

Test (my_printf, hexa_test_with_X, .init = redirect_all_std)
{
    my_printf("%X %X", 79, 642435);
    cr_assert_stdout_eq_str("4F 9CD83");
}

Test (my_printf, hexa_test_with_x_and_tag, .init = redirect_all_std)
{
    my_printf("%#x", 642435);
    cr_assert_stdout_eq_str("0x9cd83");
}

Test (my_printf, hexa_test_with_X_and_tag, .init = redirect_all_std)
{
    my_printf("%#X", 642435);
    cr_assert_stdout_eq_str("0x9CD83");
}

Test (my_printf, binary_test, .init = redirect_all_std)
{
    my_printf("%b %b", 22, 642435);
    cr_assert_stdout_eq_str("10110 10011100110110000011");
}

Test (my_printf, percent_test, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf, plus_test, .init = redirect_all_std)
{
    my_printf("%+i %+i", 22, -4);
    cr_assert_stdout_eq_str("+22 -4");
}