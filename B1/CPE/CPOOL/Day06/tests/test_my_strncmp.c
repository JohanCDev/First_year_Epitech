/*
** EPITECH PROJECT, 2020
** test_my_strncmp
** File description:
** 
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, compare_from_a_byte)
{
    const char s1[] = "Hello";
    const char s2[] = "Hello";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), 0);
}

Test(my_strncmp, compare_from_a_byte1)
{
    const char s1[] = "Hello";
    const char s2[] = "Hell";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), 111);
}

Test(my_strncmp, compare_from_a_byte2)
{
    const char s1[] = "Hell";
    const char s2[] = "Hello";
    int n = 4;

    cr_assert_eq(my_strncmp(s1, s2, n), 0);
}

Test(my_strncmp, compare_from_a_byte21)
{
    const char s1[] = "Hello";
    const char s2[] = "Hell";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), 111);
}

Test(my_strncmp, compare_from_a_byte3)
{
    const char s1[] = "Hell";
    const char s2[] = "Hello";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), -111);
}

Test(my_strncmp, compare_from_a_byte4)
{
    const char s1[] = "Hello";
    const char s2[] = "";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), 72);
}

Test(my_strncmp, compare_from_a_byte5)
{
    const char s1[] = "";
    const char s2[] = "Hello";
    int n = 5;

    cr_assert_eq(my_strncmp(s1, s2, n), -72);
}

Test(my_strncmp, compare_from_a_byte6)
{
    const char s1[] = "Hello";
    const char s2[] = "Hello";
    int n = 0;

    cr_assert_eq(my_strncmp(s1, s2, n), 0);
}

Test(my_strncmp, compare_from_a_byte7)
{
    const char s1[] = "b";
    const char s2[] = "a";
    int n = 1;

    cr_assert_eq(my_strncmp(s1, s2, n), 1);
}

Test(my_strncmp, compare_from_a_byte8)
{
    const char s1[] = "a";
    const char s2[] = "b";
    int n = 1;

    cr_assert_eq(my_strncmp(s1, s2, n), -1);
}

Test(my_strncmp, compare_from_a_byte9)
{
    const char s1[] = "Hello";
    const char s2[] = "Hello";
    int n = -1;

    cr_assert_eq(my_strncmp(s1, s2, n), 0);
}
