/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_printf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/printf.h"

Test(my_printf, empty_string, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf(""), 0);
}

Test(my_printf, simple_strings, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("Hello, world!\n"), 14);
    cr_assert_eq(my_printf("100%%"), 4);
    cr_assert_eq(my_printf("%%APPDATA%%"), 9);
    cr_assert_stdout_eq_str("Hello, world!\n100%%APPDATA%", "");
}

Test(my_printf, invalid_conversions_are_skipped, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("test %Wd"), 8);
    cr_assert_eq(my_printf("unfinished %"), 12);
    cr_assert_stdout_eq_str("test %Wdunfinished %", "");
}

Test(my_printf, signed_int_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%d", 42), 2);
    cr_assert_eq(my_printf("%i", -2147483648), 11);
    cr_assert_eq(my_printf("%5d", 99), 5);
    cr_assert_eq(my_printf("%04lld", 0), 4);
    cr_assert_eq(my_printf("[%-3d]", 2), 5);
    cr_assert_eq(my_printf("% +zi", 7), 2);
    cr_assert_eq(my_printf("% i", 7), 2);
    cr_assert_eq(my_printf("%.i", 123), 3);
    cr_assert_eq(my_printf("%*.*i", 6, 4, 123), 6);
    cr_assert_stdout_eq_str("42-2147483648   990000[2  ]+7 7123  0123", "");
}

Test(my_printf, unsigned_int_conversions_decimal, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%u", 42), 2);
    cr_assert_eq(my_printf("%#u", 4294967295), 10);
    cr_assert_eq(my_printf("%5u", 99), 5);
    cr_assert_eq(my_printf("%04llu", 0), 4);
    cr_assert_eq(my_printf("[%-3u]", 2), 5);
    cr_assert_eq(my_printf("% +zu", 7), 1);
    cr_assert_eq(my_printf("% u", 7), 1);
    cr_assert_eq(my_printf("%.u", 123), 3);
    cr_assert_eq(my_printf("%*.*u", 6, 4, 123), 6);
    cr_assert_stdout_eq_str("424294967295   990000[2  ]77123  0123", "");
}

Test(my_printf, lower_hexadecimal_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%x", 10), 1);
    cr_assert_eq(my_printf("%#x", 0x2a), 4);
    cr_assert_eq(my_printf("%#6x", 0xdc), 6);
    cr_assert_eq(my_printf("%-#6x", 0xdc), 6);
    cr_assert_eq(my_printf("%llx", 0xfedcba9876543210), 16);
    cr_assert_stdout_eq_str("a0x2a  0xdc0xdc  fedcba9876543210", "");
}

Test(my_printf, upper_hexadecimal_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%X", 10), 1);
    cr_assert_eq(my_printf("%#X", 0x2a), 4);
    cr_assert_eq(my_printf("%#6X", 0xdc), 6);
    cr_assert_eq(my_printf("%-#6X", 0xdc), 6);
    cr_assert_eq(my_printf("%llX", 0xfedcba9876543210), 16);
    cr_assert_stdout_eq_str("A0X2A  0XDC0XDC  FEDCBA9876543210", "");
}

Test(my_printf, octal_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%o", 8), 2);
    cr_assert_eq(my_printf("%#o", 0744), 4);
    cr_assert_eq(my_printf("%#6o", 045), 6);
    cr_assert_eq(my_printf("%-#6o", 045), 6);
    cr_assert_eq(my_printf("%llo", 076543210), 8);
    cr_assert_stdout_eq_str("100744   045045   76543210", "");
}

Test(my_printf, binary_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%b", 0), 1);
    cr_assert_eq(my_printf("%B", 1), 1);
    cr_assert_eq(my_printf("%#B", 0xf), 6);
    cr_assert_eq(my_printf("%#b", 0x2c), 8);
    cr_assert_stdout_eq_str("010B11110b101100", "");
}

Test(my_printf, boolean_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%r", 0), 5);
    cr_assert_eq(my_printf("%hhR", 178), 4);
    cr_assert_eq(my_printf("%jR", 0), 5);
    cr_assert_eq(my_printf("%-10r", 1), 10);
    cr_assert_stdout_eq_str("falseTRUEFALSEtrue      ", "");
}

Test(my_printf, char_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%c", '?'), 1);
    cr_assert_eq(my_printf("%2$c%cs%2$c", 'e', 't'), 4);
    cr_assert_eq(my_printf("%5c", '!'), 5);
    cr_assert_eq(my_printf("%1$-*2$c", 'X', 4), 4);
    cr_assert_stdout_eq_str("?test    !X   ", "");
}

Test(my_printf, string_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%s", ""), 0);
    cr_assert_eq(my_printf("%#s", ""), 2);
    cr_assert_eq(my_printf("%s", "test"), 4);
    cr_assert_eq(my_printf("%s", NULL), 6);
    cr_assert_eq(my_printf("%#2hhs", "yeet"), 6);
    cr_assert_eq(my_printf("%4s", "?"), 4);
    cr_assert_eq(my_printf("%-4s", "!"), 4);
    cr_assert_eq(my_printf("value: \"%0 +-'Is\"\n", "X"), 11);
    cr_assert_stdout_eq_str("\"\"test(null)\"yeet\"   ?!   value: \"X\"\n", "");
}

Test(my_printf, octal_string_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%S", ""), 0);
    cr_assert_eq(my_printf("%#S", "test"), 6);
    cr_assert_eq(my_printf("%S", NULL), 6);
    cr_assert_eq(my_printf("%S", "\n"), 4);
    cr_assert_eq(my_printf("%.2S", "\001\013\200"), 8);
    cr_assert_eq(my_printf("%S", " ~te\220t\n"), 13);
    cr_assert_stdout_eq_str("\"test\"(null)\\012\\001\\013 ~te\\220t\\012", "");
}

Test(my_printf, pointer_conversions, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_printf("%p", NULL), 5);
    cr_assert_eq(my_printf("address: %p", (uintptr_t)0x402010), 17);
    cr_assert_stdout_eq_str("(nil)address: 0x402010", "");
}

Test(my_printf, count_conversions1, .init = cr_redirect_stdout)
{
    signed char count_1;
    short count_2;
    int count_3;
    long count_4;

    cr_assert_eq(my_printf("Test:%hhn [%-5d%hn]%n, OK\n%ln", &count_1, 42,
    &count_2, &count_3, &count_4), 18);
    cr_assert_eq(count_1, 5);
    cr_assert_eq(count_2, 12);
    cr_assert_eq(count_3, 13);
    cr_assert_eq(count_4, 18);
    cr_assert_stdout_eq_str("Test: [42   ], OK\n", "");
}

Test(my_printf, count_conversions2, .init = cr_redirect_stdout)
{
    long long count_1;
    intmax_t count_2;
    size_t count_3;
    ptrdiff_t count_4;

    cr_assert_eq(my_printf("YEET:%lln [%-+5d%jn]%zn, OK\n%tn", &count_1, 21,
    &count_2, &count_3, &count_4), 18);
    cr_assert_eq(count_1, 5);
    cr_assert_eq(count_2, 12);
    cr_assert_eq(count_3, 13);
    cr_assert_eq(count_4, 18);
    cr_assert_stdout_eq_str("YEET: [+21  ], OK\n", "");
}

Test(my_printf, mouli_tests1, .init = cr_redirect_stdout)
{
    char *res = "astekmoulinette astek moulinette astek%42moulinette\n";

    cr_assert_eq(my_printf("%s%s", "astek", "moulinette"), 15);
    cr_assert_eq(my_printf(" %s %s ", "astek", "moulinette"), 18);
    cr_assert_eq(my_printf(""), 0);
    cr_assert_eq(my_printf("%s%%%d%s\n", "astek", 42, "moulinette"), 19);
    cr_assert_stdout_eq_str(res, "");
}

Test(my_printf, mouli_tests2, .init = cr_redirect_stdout)
{
    char *res = "%s%dAstek42%Astekastek [astek] ";

    cr_assert_eq(my_printf("%%s%%d%s%d%%", "Astek", 42), 12);
    cr_assert_eq(my_printf("Astek"), 5);
    cr_assert_eq(my_printf("%s", "astek"), 5);
    cr_assert_eq(my_printf(" [%s] ", "astek"), 9);
    cr_assert_stdout_eq_str(res, "");
}
