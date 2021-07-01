/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-solostumper02-johan.chrillesen
** File description:
** unit_tests
*/

#include <criterion/criterion.h>

char *compare_strings(char *string1, char *string2);


Test(compare_strings, anagrams_true)
{
    cr_assert_str_eq(compare_strings("Hello", "olleh"), "no anagrams.\n");
    cr_assert_str_eq(compare_strings("Rail Safety", "Fairy tales"), \
    "no anagrams.\n");
    cr_assert_str_eq(compare_strings("Maison", "Aimons"), "no anagrams.\n");
}

Test(compare_strings, anagrams_false)
{
    cr_assert_str_eq(compare_strings("Jolor", "jui"), "no anagrams.\n");
    cr_assert_str_eq(compare_strings("chat", "oreiller"), "no anagrams.\n");
    cr_assert_str_eq(compare_strings("moo", "moon"), "no anagrams.\n");
}