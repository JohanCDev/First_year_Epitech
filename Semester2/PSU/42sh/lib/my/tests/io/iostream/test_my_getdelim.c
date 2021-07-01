/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_getdelim function
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_getdelim, error_null_line)
{
    char const *buf = "nope";
    my_iostream_t stream;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 0, &stream);
    cr_assert_eq(my_getdelim(NULL, &alloc_size, '\n', &stream), -1);
}

Test(my_getdelim, error_null_alloc_size)
{
    char const *buf = "nope";
    my_iostream_t stream;
    char *line = NULL;

    my_finit_input_memory(buf, 0, &stream);
    cr_assert_eq(my_getdelim(&line, NULL, '\n', &stream), -1);
}

Test(my_getdelim, error_empty_stream)
{
    char const *buf = "nope";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 0, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '\n', &stream), -1);
    cr_assert_eq(line, NULL);
    cr_assert_eq(alloc_size, 0);
    free(line);
}

Test(my_getdelim, no_delimiter)
{
    char const *buf = "This is a test";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 14, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 14);
    cr_assert_str_eq(line, "This is a test");
    cr_assert_geq(alloc_size, 14);
    free(line);
}

Test(my_getdelim, only_one_delimiter)
{
    char const *buf = "$";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 1, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 1);
    cr_assert_str_eq(line, "$");
    cr_assert_geq(alloc_size, 1);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), -1);
    free(line);
}

Test(my_getdelim, only_delimiters)
{
    char const *buf = "$$$$";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 4, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 1);
    cr_assert_str_eq(line, "$");
    cr_assert_geq(alloc_size, 1);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 1);
    cr_assert_str_eq(line, "$");
    cr_assert_geq(alloc_size, 1);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 1);
    cr_assert_str_eq(line, "$");
    cr_assert_geq(alloc_size, 1);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 1);
    cr_assert_str_eq(line, "$");
    cr_assert_geq(alloc_size, 1);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), -1);
    free(line);
}

Test(my_getdelim, one_line)
{
    char const *buf = "This is a test$";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 15, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 15);
    cr_assert_str_eq(line, "This is a test$");
    cr_assert_geq(alloc_size, 15);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), -1);
    free(line);
}

Test(my_getdelim, one_line_embedded_null)
{
    char const *buf = "This\0 is a test$";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 16, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), 16);
    cr_assert(memcmp(line, "This\0 is a test$", 16) == 0);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '$', &stream), -1);
    cr_assert_geq(alloc_size, 16);
    free(line);
}

static void test_my_getdelim_multiline_part_2(
    char **line, size_t alloc_size, my_iostream_t *stream)
{
    cr_assert_eq(my_getdelim(line, &alloc_size, '\n', stream), 15);
    cr_assert_str_eq(*line, "This is a test\n");
    cr_assert_geq(alloc_size, 15);
    cr_assert_eq(my_getdelim(line, &alloc_size, '\n', stream), 5);
    cr_assert_str_eq(*line, "end?\n");
    cr_assert_geq(alloc_size, 5);
    cr_assert_eq(my_getdelim(line, &alloc_size, '\n', stream), 16);
    cr_assert_str_eq(*line, "VVVVVVVVVVVVVVVV");
    cr_assert_geq(alloc_size, 16);
    cr_assert_eq(my_getdelim(line, &alloc_size, '\n', stream), -1);
}

Test(my_getdelim, multiline)
{
    char const *buf =
        "test\npoggers\n\nThis is a test\nend?\nVVVVVVVVVVVVVVVV";
    my_iostream_t stream;
    char *line = NULL;
    size_t alloc_size = 0;

    my_finit_input_memory(buf, 50, &stream);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '\n', &stream), 5);
    cr_assert_str_eq(line, "test\n");
    cr_assert_geq(alloc_size, 5);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '\n', &stream), 8);
    cr_assert_str_eq(line, "poggers\n");
    cr_assert_geq(alloc_size, 8);
    cr_assert_eq(my_getdelim(&line, &alloc_size, '\n', &stream), 1);
    cr_assert_str_eq(line, "\n");
    cr_assert_geq(alloc_size, 8);
    test_my_getdelim_multiline_part_2(&line, alloc_size, &stream);
    free(line);
}
