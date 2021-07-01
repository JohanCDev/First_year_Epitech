/*
** EPITECH PROJECT, 2021
** LibMy - ascii module
** File description:
** Splits string by iterating over them.
*/

#include "libmy/ascii.h"

MY_ASCII_API ssize_t my_str_csplit_iter(
    char const **begin, char const **end, char sep)
{
    if (*end == NULL) {
        if (*begin == NULL)
            return -1;
        *end = my_strchr(*begin, sep);
        if (*end == NULL)
            *end = *begin + my_strlen(*begin);
        return *end - *begin;
    }
    if (**end == '\0') {
        *begin = NULL;
        *end = NULL;
        return -1;
    }
    *begin = *end + 1;
    *end = my_strchr(*begin, sep);
    if (*end == NULL)
        *end = *begin + my_strlen(*begin);
    return *end - *begin;
}

// sep: x
// ("test" NULL -> "test" "" 4), ("test" "" -> "" "" -1)

// sep: x
// ("xbox is a console" NULL) -> ("" "xbox is a console" 0)
// ("" "xbox is a console") -> ("box is a console" "x is a console" 2)
// ("box is a console" "x is a console") -> (" is a console" "" 13)
// (" is a console" "") -> ("" "" -1)
