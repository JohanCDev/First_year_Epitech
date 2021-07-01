/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pal.h"
#include "my.h"

void redirect_all_std(void);
int check_all_flags(char *str, flags_t *flags, char *value_to_insert);
int check_value_flags(flags_t *flags);

Test(initialize_structure, test_initialize_structure)
{
    pal_t pal;
    initialize_structure(&pal);

    cr_assert_eq(pal.flags.base, -1);
    cr_assert_eq(pal.flags.imax, -1);
    cr_assert_eq(pal.flags.imin, -1);
    cr_assert_eq(pal.flags.n, -1);
    cr_assert_eq(pal.flags.p, -1);
}

Test(check_args, test_args_helper, .init = redirect_all_std)
{
    int argc = 2;
    char **argv = my_str_to_word_array("./a.out -h", " ");
    pal_t pal;
    initialize_structure(&pal);

    check_args(argc, argv, &pal);

    cr_assert_stdout_eq_str(HELPER);
}

Test(check_args, test_args_flags, .init = redirect_all_std)
{
    int argc = 7;
    int argc2 = 3;
    char **argv = my_str_to_word_array\
    ("./a.out -b 10 -p 232 -imin 12 -imax 74", " ");
    char **argv2 = my_str_to_word_array("./a.out -p 232", " ");
    pal_t stumper2;

    initialize_structure(&stumper2);
    check_args(argc2, argv2, &stumper2);
    cr_assert_eq(stumper2.flags.base, 10);
    cr_assert_eq(stumper2.flags.imax, 100);
    cr_assert_eq(stumper2.flags.imin, 0);
    cr_assert_eq(stumper2.flags.n, -1);
    cr_assert_eq(stumper2.flags.p, 232);
}

Test(check_args, test_args_flags_next, .init = redirect_all_std)
{
    int argc = 7;
    char **argv = my_str_to_word_array\
    ("./a.out -b 10 -p 232 -imin 12 -imax 74", " ");
    pal_t pal;

    initialize_structure(&pal);
    check_args(argc, argv, &pal);
    cr_assert_eq(pal.flags.base, 10);
    cr_assert_eq(pal.flags.imax, 74);
    cr_assert_eq(pal.flags.imin, 12);
    cr_assert_eq(pal.flags.n, -1);
    cr_assert_eq(pal.flags.p, 232);
}

Test(check_args, test_args_invalid_number, .init = redirect_all_std)
{
    int argc = 9;
    char **argv = my_str_to_word_array\
    ("./a.out -b erzgiu -p 232 -imin 12 -imax 74", " ");
    pal_t pal;
    initialize_structure(&pal);

    int ret = check_args(argc, argv, &pal);
    cr_assert_eq(ret, -1);
}

Test(check_args, test_no_mandatory_args)
{
    int argc = 5;
    char **argv = my_str_to_word_array("./a.out -b 5 -imin 3", " ");
    pal_t pal;
    initialize_structure(&pal);
    int ret = check_args(argc, argv, &pal);

    cr_assert_eq(ret, -1);
}

Test(check_args, test_args_bad_flag, .init = redirect_all_std)
{
    int argc = 9;
    char **argv1 = my_str_to_word_array\
    ("./a.out -o 23 -n 121 -imin 12 -imax 74", " ");
    char **argv2 = my_str_to_word_array\
    ("./a.out - 121 -p 232 -imin 12 -imax 74", " ");
    pal_t pal;
    initialize_structure(&pal);
    int ret1 = check_args(argc, argv1, &pal);
    int ret2 = check_args(argc, argv2, &pal);

    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, -1);
}

Test(check_args, test_args_bad_flag_next, .init = redirect_all_std)
{
    int argc = 9;
    pal_t pal;
    initialize_structure(&pal);
    char **argv3 = my_str_to_word_array\
    ("./a.out -n 12 -p 232 -imin 12 -imax 74", " ");
    char **argv4 = my_str_to_word_array\
    ("./a.out -n 12 -b 1 -imin 12 -imax 74", " ");
    char **argv5 = my_str_to_word_array\
    ("./a.out -n 12 -b 12 -imin 12 -imax 74", " ");
    int ret3 = check_args(argc, argv3, &pal);
    int ret4 = check_args(argc, argv4, &pal);
    int ret5 = check_args(argc, argv5, &pal);

    cr_assert_eq(ret3, -1);
    cr_assert_eq(ret4, -1);
    cr_assert_eq(ret5, -1);
}

Test(check_args, test_args_same_flag, .init = redirect_all_std)
{
    int argc = 5;
    int argc2 = 7;
    char **argv1 = my_str_to_word_array("./a.out -p 10 -p 12", " ");
    char **argv2 = my_str_to_word_array("./a.out -b 8 -b 7", " ");
    char **argv3 = my_str_to_word_array("./a.out -n 34 -imin 4 -imin 9", " ");
    char **argv4 = my_str_to_word_array("./a.out -n 34 -imax 89 -imax 45", " ");
    char **argv5 = my_str_to_word_array("./a.out -n 343 -n 989", " ");
    pal_t pal;
    initialize_structure(&pal);
    int ret1 = check_args(argc, argv1, &pal);
    int ret2 = check_args(argc, argv2, &pal);
    int ret3 = check_args(argc2, argv3, &pal);
    int ret4 = check_args(argc2, argv4, &pal);
    int ret5 = check_args(argc, argv5, &pal);

    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, -1);
    cr_assert_eq(ret3, -1);
    cr_assert_eq(ret4, -1);
    cr_assert_eq(ret5, -1);
}

Test(check_args, test_invalid_nb_of_arg, .init = redirect_all_std)
{
    int argc = 1;
    int argc2 = 11;
    int argc3 = 2;
    char **argv1 = my_str_to_word_array("./a.out", " ");
    char **argv2 = my_str_to_word_array\
    ("./a.out -b 8 -p 9 -k 34 -u 45 -t 65", " ");
    char **argv3 = my_str_to_word_array("./a.out -b", " ");
    pal_t pal;
    initialize_structure(&pal);
    int ret1 = check_args(argc, argv1, &pal);
    int ret2 = check_args(argc2, argv2, &pal);
    int ret3 = check_args(argc3, argv3, &pal);

    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, -1);
    cr_assert_eq(ret3, -1);
}

Test(check_args, test_other_tricky_cases)
{
    int argc = 3;
    int argc2 = 11;
    int argc3 = 2;
    char **argv1 = my_str_to_word_array("./a.out -p 12321 -b", " ");
    char **argv2 = my_str_to_word_array("./a.out p 25", " ");
    char **argv3 = my_str_to_word_array("./a.out -b", " ");
    pal_t pal;
    initialize_structure(&pal);
    int ret1 = check_args(argc, argv1, &pal);
    int ret2 = check_args(argc3, argv2, &pal);
    int ret3 = check_args(argc3, argv3, &pal);

    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, -1);
    cr_assert_eq(ret3, -1);
}

Test(check_all_flags, test_check_all_flags)
{
    int ret = check_all_flags("-p", NULL, NULL);
    int ret1 = check_all_flags("-p", NULL, "64juioerzfg");
    int ret2 = check_all_flags("-", NULL, "64juioerzfg");
    int ret3 = check_all_flags("zhrg", NULL, "64juioerzfg");

    cr_assert_eq(ret, -1);
    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, -1);
    cr_assert_eq(ret3, -1);
}

Test(check_all_flags, test_check_all_flags_next)
{
    pal_t pal;
    initialize_structure(&pal);
    int ret = check_all_flags("-p", &pal.flags, "64");
    int ret1 = check_all_flags("-pqzlkjen", &pal.flags, "64");
    int ret2 = check_all_flags("pqzlkjen", &pal.flags, "64");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, 0);
}

Test(check_value_flags, test_check_all_flags_next)
{
    pal_t pal;
    initialize_structure(&pal);

    int ret = check_all_flags("-p", &pal.flags, "64");
    int ret1 = check_all_flags("-pqzlkjen", &pal.flags, "64");
    int ret2 = check_all_flags("pqzlkjen", &pal.flags, "64");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret1, -1);
    cr_assert_eq(ret2, 0);
}

Test(check_value_flags, test_value_flags)
{
    pal_t pal;
    initialize_structure(&pal);
    int ret = 0;

    pal.flags.base = 1;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
    pal.flags.base = 11;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
    pal.flags.p = 363;
    pal.flags.n = 363;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
    pal.flags.p = -1;
    pal.flags.imin = 5;
    pal.flags.imax = 3;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
}

Test(check_value_flags, test_value_flags_next)
{
    pal_t pal;
    initialize_structure(&pal);
    int ret = 0;

    pal.flags.base = 10;
    pal.flags.p = -1;
    pal.flags.n = 363;
    pal.flags.imin = 0;
    pal.flags.imax = 100;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, 1);
    pal.flags.n = -1;
    pal.flags.p = 153;
    pal.flags.base = 2;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, 1);
    pal.flags.n = -1;
    pal.flags.p = 154;
    pal.flags.base = 2;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
}

Test(check_value_flags, check_value_flags_test_value_flags_next__extra)
{
    pal_t pal;
    initialize_structure(&pal);
    int ret = 0;

    pal.flags.base = 1;
    pal.flags.p = 34;
    pal.flags.n = 3;
    pal.flags.imin = 102;
    pal.flags.imax = 100;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
    pal.flags.base = 5;
    pal.flags.p = 34;
    pal.flags.n = -1;
    pal.flags.imin = 102;
    pal.flags.imax = 100;
    ret = check_value_flags(&pal.flags);
    cr_assert_eq(ret, -1);
}