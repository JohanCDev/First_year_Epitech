/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strcapitalize function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strcapitalize, null_string)
{
    cr_assert_eq(my_strcapitalize(NULL), NULL);
}

Test(my_strcapitalize, lowercase_phrase)
{
    char str[] = "this is a test";

    cr_assert_str_eq(my_strcapitalize(str), "This Is A Test");
}

Test(my_strcapitalize, uppercase_phrase)
{
    char str[] = "THIS IS A TEST";

    cr_assert_str_eq(my_strcapitalize(str), "This Is A Test");
}

Test(my_strcapitalize, wierd_speratators)
{
    char str[] = "THIS+IS-A,test";

    cr_assert_str_eq(my_strcapitalize(str), "This+Is-A,Test");
}

Test(my_strcapitalize, wierd_chars)
{
    char str[] = "+_ç0610:/;?,!%$ [{#~#}]";

    cr_assert_str_eq(my_strcapitalize(str), "+_ç0610:/;?,!%$ [{#~#}]");
}

Test(my_strcapitalize, alphanumerical)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";

    cr_assert_str_eq(my_strcapitalize(str), "Hey, How Are You? 42words \
Forty-Two; Fifty+One");
}
