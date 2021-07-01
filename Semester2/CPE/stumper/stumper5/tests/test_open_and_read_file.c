/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** test_initialize
*/

#include <criterion/criterion.h>
#include "hangman.h"

char *open_and_read_file(char const *filepath);

Test(open_and_read_file, file_exists)
{
    char *str = "tests/file";
    char *result = "butterfly\ntest\nmy_swap\nchicken";

    cr_assert_str_eq(open_and_read_file(str), result);
}