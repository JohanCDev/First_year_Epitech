/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_my_lib
*/

#include "../my/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_strlen, test_strlen)
{
    char *s1 = "i'm a test";
    char *s2 = "testing";
    char *s3 = "is not";
    char *s4 = "very fun lmao";
    char *s5 = "";
    unsigned int r1 = my_strlen(s1);
    unsigned int r2 = my_strlen(s2);
    unsigned int r3 = my_strlen(s3);
    unsigned int r4 = my_strlen(s4);
    unsigned int r5 = my_strlen(s5);

    cr_assert_eq(r1, 10);
    cr_assert_eq(r2, 7);
    cr_assert_eq(r3, 6);
    cr_assert_eq(r4, 13);
    cr_assert_eq(r5, 0);
}

Test(my_strcat, test_normal_strcat)
{
    char concat[] = "I am a";
    my_strcat(concat, " test!");

    cr_assert_str_eq(concat, "I am a test!");
}

Test(my_strcat, test_no_first_arg)
{
    char concat[] = "";
    my_strcat(concat, "a");

    cr_assert_str_eq(concat, "a");
}

Test(my_strcat, test_null_dest)
{
    char concat[] = "hey\0";
    my_strcat(concat, "a");

    cr_assert_str_eq(concat, "heya");
}

Test(my_strcat_char, test_dest)
{
    char concat[] = "hey\0";
    my_strcat_char(concat, 'a');

    cr_assert_str_eq(concat, "heya");
}

Test(my_strncat, test_normal_strncat)
{
    char concat[] = "a";
    my_strncat(concat, "b", 1);

    cr_assert_str_eq(concat, "ab");
}

Test(my_strncat, test_no_first_arg)
{
    char concat[] = "";
    my_strncat(concat, "b", 1);

    cr_assert_str_eq(concat, "b");
}

Test(my_strncat, test_null_dest)
{
    char concat[] = "\0";
    my_strncat(concat, "b", 1);

    cr_assert_str_eq(concat, "b");
}

Test(my_strncat, test_n_inf_to_i)
{
    char concat[] = "Hey\0";
    my_strncat(concat, "bdjf", 1);

    cr_assert_str_eq(concat, "Heyb");
}

Test(my_str_isnum, test_isnum)
{
    int a = my_str_isnum("Not num");
    int b = my_str_isnum("23234  Not23 num");
    int c = my_str_isnum("3234235");
    int d = my_str_isnum("1");

    cr_assert_eq(a, 0);
    cr_assert_eq(b, 0);
    cr_assert_eq(c, 1);
    cr_assert_eq(d, 1);
}

Test(my_str_isalpha, test_isalpha)
{
    int a = my_str_isalpha("not1 alpha");
    int b = my_str_isalpha("23234  Not23 alpha");
    int c = my_str_isalpha("alpha");
    int d = my_str_isalpha("sefsefsef");
    int e = my_str_isalpha("\0");
    int f = my_str_isalpha("aLpHa");
    int g = my_str_isalpha("}");

    cr_assert_eq(a, 0);
    cr_assert_eq(b, 0);
    cr_assert_eq(c, 1);
    cr_assert_eq(d, 1);
    cr_assert_eq(e, 1);
    cr_assert_eq(f, 1);
    cr_assert_eq(g, 0);
}

Test(my_atoi, test_my_getbr)
{
    int test1 = my_atoi("\0");
    int test2 = my_atoi("0");
    int test3 = my_atoi("12344532");
    int test4 = my_atoi("-132");
    int test5 = my_atoi("23");

    cr_assert_eq(test1, 0);
    cr_assert_eq(test2, 0);
    cr_assert_eq(test3, 12344532);
    cr_assert_eq(test4, -132);
    cr_assert_eq(test5, 23);
}

Test(my_atoi, test_my_atoi_next)
{
    int test6 = my_atoi("----++--23");
    int test7 = my_atoi("10U");
    int test8 = my_atoi("AAZJBFZJAKBG");
    int test9 = my_atoi("\t");
    int test10 = my_atoi("1035.");
    int test11 = my_atoi("1035\0");

    cr_assert_eq(test6, 23);
    cr_assert_eq(test7, 10);
    cr_assert_eq(test8, 0);
    cr_assert_eq(test9, 0);
    cr_assert_eq(test10, 1035);
    cr_assert_eq(test11, 1035);
}

Test(my_itoa, test_my_itoa)
{
    char *test_1 = my_itoa(42);
    char *test_2 = my_itoa(2314);
    char *test_3 = my_itoa(454);
    char *test_4 = my_itoa(321424);
    char *test_5 = my_itoa(303);
    char *test_6 = my_itoa(24421);

    cr_assert_str_eq(test_1, "42");
    cr_assert_str_eq(test_2, "2314");
    cr_assert_str_eq(test_3, "454");
    cr_assert_str_eq(test_4, "321424");
    cr_assert_str_eq(test_5, "303");
    cr_assert_str_eq(test_6, "24421");
}

Test(my_str_islower, test_my_str_is_lower)
{
    int test_1 = my_str_islower("azerty");
    int test_2 = my_str_islower("AZERTY");
    int test_3 = my_str_islower("AzErTy");
    int test_4 = my_str_islower("aZeRtY");
    int test_5 = my_str_islower("\0");
    int test_6 = my_str_islower("}");

    cr_assert_eq(test_1, 1);
    cr_assert_eq(test_2, 0);
    cr_assert_eq(test_3, 0);
    cr_assert_eq(test_4, 0);
    cr_assert_eq(test_5, 0);
    cr_assert_eq(test_6, 0);
}

Test(my_str_isprintable, test_my_str_isprintable)
{
    char str_test[2] = {'a', 128};
    int test_1 = my_str_isprintable("azerty");
    int test_2 = my_str_isprintable("AZERTY");
    int test_3 = my_str_isprintable("AzErTy");
    int test_4 = my_str_isprintable("aZeRtY");
    int test_9 = my_str_isprintable(str_test);
    int test_10 = my_str_isprintable("aZeRtY~");
    int test_11 = my_str_isprintable("aZeRtY ");

    cr_assert_eq(test_1, 1);
    cr_assert_eq(test_2, 1);
    cr_assert_eq(test_3, 1);
    cr_assert_eq(test_4, 1);
    cr_assert_eq(test_9, 0);
    cr_assert_eq(test_10, 1);
    cr_assert_eq(test_11, 1);
}

Test(my_str_isprintable, test_my_str_isprintable_next)
{
    int test_5 = my_str_isprintable("\0");
    int test_6 = my_str_isprintable("zaetz\tzerg");
    int test_7 = my_str_isprintable("\bijozg");
    int test_8 = my_str_isprintable("zaetz\t");

    cr_assert_eq(test_5, 0);
    cr_assert_eq(test_6, 0);
    cr_assert_eq(test_7, 0);
    cr_assert_eq(test_8, 0);
}

Test(my_str_isupper, test_my_str_isupper)
{
    int test_1 = my_str_isupper("azerty");
    int test_2 = my_str_isupper("AZERTY");
    int test_3 = my_str_isupper("AzErTy");
    int test_4 = my_str_isupper("aZeRtY");
    int test_5 = my_str_isupper("\0");
    int test_6 = my_str_isupper("@}");

    cr_assert_eq(test_1, 0);
    cr_assert_eq(test_2, 1);
    cr_assert_eq(test_3, 0);
    cr_assert_eq(test_4, 0);
    cr_assert_eq(test_5, 0);
    cr_assert_eq(test_6, 0);
}

Test(my_strcpy, test_my_strcpy)
{
    char test1[] = "init";
    char test2[] = "init";
    my_strcpy(test1, "Hey");
    my_strcpy(test2, "");

    cr_assert_str_eq(test1, "Hey");
    cr_assert_str_eq(test2, "");
}

Test(my_strcpy, test_my_strcpy_null)
{
    char *res1 = my_strcpy(NULL, NULL);
    char *res2 = my_strcpy("Hey", NULL);
    char *res3 = my_strcpy(NULL, "lo");

    cr_assert_null(res1);
    cr_assert_null(res2);
    cr_assert_null(res3);
}

Test(my_strcmp, test_my_strcmp)
{
    char test1[] = "hey";
    char test_2_1[] = "no";
    char test_2_2[] = "yes";
    int res1 = my_strcmp(test1, test1);
    int res2 = my_strcmp(test_2_1, test_2_2);
    int res3 = my_strcmp(test_2_2, test_2_1);
    int res4 = my_strcmp(test1, test_2_2);

    cr_assert_eq(res1, 0);
    cr_assert_eq(res2, -11);
    cr_assert_eq(res3, 11);
    cr_assert_eq(res4, -17);
}

Test(my_strncmp, test_my_strcmp)
{
    char test_1_1[] = "hey";
    char test_1_2[] = "heylo";
    char test_2_1[] = "no";
    char test_2_2[] = "nope";
    char test_2_3[] = "yes";
    int res1 = my_strncmp(test_1_1, test_1_2, 3);
    int res2 = my_strncmp(test_2_1, test_2_2, 2);
    int res3 = my_strncmp(test_2_2, test_2_3, 4);
    int res4 = my_strncmp(test_2_3, test_2_2, 4);

    cr_assert_eq(res1, 0);
    cr_assert_eq(res2, 0);
    cr_assert_eq(res3, -11);
    cr_assert_eq(res4, 11);
}

Test(my_strncmp, test_my_strcmp_next)
{
    char test_1_1[] = "hey";
    char test_1_2[] = "heplo";
    char test_1_3[] = "he";
    int res1 = my_strncmp(test_1_1, test_1_2, 3);
    int res2 = my_strncmp(test_1_2, test_1_1, 3);
    int res3 = my_strncmp(test_1_3, test_1_2, 3);
    int res4 = my_strncmp(test_1_1, test_1_1, 8);

    cr_assert_eq(res1, 9);
    cr_assert_eq(res2, -9);
    cr_assert_eq(res3, -112);
    cr_assert_eq(res4, 0);
}

Test(my_swap_int, test_my_swap_int)
{
    int a = 1;
    int b = 2;

    my_swap_int(&a, &b);
    cr_assert_eq(a, 2);
    cr_assert_eq(b, 1);
}

Test(my_swap_str, test_my_swap_str)
{
    char *a = "Hey";
    char *b = "Yeh";

    my_swap_str(&a, &b);
    cr_assert_str_eq(a, "Yeh");
    cr_assert_str_eq(b, "Hey");
}

Test(my_strdup, test_my_strdup)
{
    char *a = my_strdup("Hey Man");
    char *b = my_strdup("\0");

    cr_assert_str_eq(a, "Hey Man");
    cr_assert_str_eq(b, "\0");
}

Test(my_compute_power_rec, test_my_compute_power_rec)
{
    int a = my_compute_power_rec(2, 2);
    int b = my_compute_power_rec(2, 0);
    int c = my_compute_power_rec(2, -2);

    cr_assert_eq(a, 4);
    cr_assert_eq(b, 1);
    cr_assert_eq(c, 0);
}

Test(my_compute_square_root, test_my_compute_square_root)
{
    int a = my_compute_square_root(9);
    int b = my_compute_square_root(6);
    int c = my_compute_square_root(0);
    int d = my_compute_square_root(-2);

    cr_assert_eq(a, 3);
    cr_assert_eq(b, 0);
    cr_assert_eq(c, 0);
    cr_assert_eq(d, 0);
}

Test(my_isneg, test_my_isneg)
{
    int neg = my_isneg(-10);
    int pos = my_isneg(10);

    cr_assert_eq(neg, 1);
    cr_assert_eq(pos, 0);
}

Test(my_find_prime_sup, test_my_find_prime_sup)
{
    int a = my_find_prime_sup(4);
    int b = my_find_prime_sup(7);
    int c = my_find_prime_sup(0);
    int d = my_find_prime_sup(-2);

    cr_assert_eq(a, 5);
    cr_assert_eq(b, 7);
    cr_assert_eq(c, 2);
    cr_assert_eq(d, 2);
}

Test(my_revstr, test_my_revstr)
{
    char str2[] = "I'm a string";
    char str3[] = "Lucas";
    char str4[] = "";
    char str5[] = "2";

    my_revstr(&str2[0]);
    my_revstr(&str3[0]);
    my_revstr(&str4[0]);
    my_revstr(&str5[0]);
    cr_assert_str_eq(str2, "gnirts a m'I");
    cr_assert_str_eq(str3, "sacuL");
    cr_assert_str_eq(str4, "");
    cr_assert_str_eq(str5, "2");
}

Test(my_str_to_word_array, test_my_str_to_word_array_simple)
{
    char **dest = NULL;
    char src[] = "    test         random string  salt";
    dest = my_str_to_word_array(src, " ");

    cr_assert_str_eq(dest[0], "test");
    cr_assert_str_eq(dest[1], "random");
    cr_assert_str_eq(dest[2], "string");
    cr_assert_str_eq(dest[3], "salt");
}

Test(my_str_to_word_array, test_my_str_to_word_array_null)
{
    char **dest = NULL;
    dest = my_str_to_word_array(NULL, "hey");
    cr_assert_null(dest);
    dest = my_str_to_word_array("hey", NULL);
    cr_assert_null(dest);
    dest = my_str_to_word_array(NULL, NULL);
    cr_assert_null(dest);
}

Test(my_free, test_free_null)
{
    char *str = NULL;

    my_free((void *)str);
    cr_assert_null(str);
}

Test(my_free_array, test_my_free_array)
{
    char **dest = NULL;
    char src[] = "    test         random string  salt";
    dest = my_str_to_word_array(src, " ");

    my_free_array(dest);
    cr_assert_arr_eq(dest, dest, 0);
}

Test(sort_string_array, test_sort_string_array)
{
    char *array[6] = {"sa", "pa", "ua", "fa", "aa", "ra"};
    char *res[6] = {"aa", "fa", "pa", "ra", "sa", "ua"};

    sort_string_array(array);
    cr_assert_arr_eq(array, res, 6);
}

Test(my_sort_int_array, test_my_sort_int_array)
{
    int array[6] = {27, -4, 30000, -2632, 1, 0};
    int res[6] = {-2632, -4, 0, 1, 27, 30000};

    my_sort_int_array(array);
    cr_assert_arr_eq(array, res, 6);
}

Test(my_strcapitalize, test_my_strcapitalize)
{
    char str2[] = "azerty";
    char str3[] = "Lucas";
    char str4[] = "";
    char str5[] = "2";
    char str6[] = "5zegRTZ~";

    char *res1 = my_strcapitalize(str2);
    char *res2 = my_strcapitalize(str3);
    char *res3 = my_strcapitalize(str4);
    char *res4 = my_strcapitalize(str5);
    char *res5 = my_strcapitalize("6@");
    char *res6 = my_strcapitalize(str6);
    cr_assert_str_eq(res1, "AZERTY");
    cr_assert_str_eq(res2, "LUCAS");
    cr_assert_str_eq(res3, "");
    cr_assert_str_eq(res4, "2");
    cr_assert_str_eq(res5, "6@");
    cr_assert_str_eq(res6, "5ZEGRTZ~");
}

Test(my_strupcase, test_my_strupcase)
{
    char str2[] = "azerty";
    char str3[] = "Lucas";
    char str4[] = "";
    char str5[] = "2";
    char str6[] = "2a{";

    char *res1 = my_strupcase(str2);
    char *res2 = my_strupcase(str3);
    char *res3 = my_strupcase(str4);
    char *res4 = my_strupcase(str5);
    char *res5 = my_strupcase("6@");
    char *res6 = my_strupcase(str6);
    cr_assert_str_eq(res1, "AZERTY");
    cr_assert_str_eq(res2, "LUCAS");
    cr_assert_str_eq(res3, "");
    cr_assert_str_eq(res4, "2");
    cr_assert_str_eq(res5, "6@");
    cr_assert_str_eq(res6, "2A{");
}

Test(open_and_read_file, test_open_and_read_file)
{
    char str1[] = "Toto";
    char str2[] = "Makefile";
    char *str2_res = open_and_read_file(str2);
    char *res1 = open_and_read_file(str1);
    char *res2 = open_and_read_file(str2);

    cr_assert_str_eq(res2, str2_res);
    cr_assert_null(res1);
}

Test(my_factorial, test_my_factorial)
{
    int res9 = my_factorial(8);
    int res10 = my_factorial(9);
    int res11 = my_factorial(10);
    int res12 = my_factorial(11);
    int res13 = my_factorial(12);
    int res14 = my_factorial(13);
    int res15 = my_factorial(-1);

    cr_assert_eq(res9, 40320);
    cr_assert_eq(res10, 362880);
    cr_assert_eq(res11, 3628800);
    cr_assert_eq(res12, 39916800);
    cr_assert_eq(res13, 479001600);
    cr_assert_eq(res14, 0);
    cr_assert_eq(res15, 0);
}

Test(my_factorial, test_my_factorial_next)
{
    int res = my_factorial(0);
    int res2 = my_factorial(1);
    int res3 = my_factorial(2);
    int res4 = my_factorial(3);
    int res5 = my_factorial(4);
    int res6 = my_factorial(5);
    int res7 = my_factorial(6);
    int res8 = my_factorial(7);

    cr_assert_eq(res, 1);
    cr_assert_eq(res2, 1);
    cr_assert_eq(res3, 2);
    cr_assert_eq(res4, 6);
    cr_assert_eq(res5, 24);
    cr_assert_eq(res6, 120);
    cr_assert_eq(res7, 720);
    cr_assert_eq(res8, 5040);
}

Test(my_strlowcase, test_my_lowcase)
{
    char *res1 = my_strlowcase(my_strdup("AzeRtGb"));
    char *res2 = my_strlowcase(my_strdup("eriugZERZERG6432"));

    cr_assert_str_eq(res1, "azertgb");
    cr_assert_str_eq(res2, "eriugzerzerg6432");
}

Test(my_putnbr_base_int, test_my_putnbr_base_int_neg)
{
    int res = my_putnbr_base_int(-1, "01234");

    cr_assert_eq(res, 0);
}