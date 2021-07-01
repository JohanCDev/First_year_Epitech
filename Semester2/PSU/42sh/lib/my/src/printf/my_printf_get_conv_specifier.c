/*
** EPITECH PROJECT, 2020
** Libmy - printf module
** File description:
** Parses the next conversion specifier
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const p_my_printf_specifier_t CONVERSION_SPECIFIERS[256] = {
    ['d'] = P_MY_PRINTF_SPEC_SIGNED,
    ['i'] = P_MY_PRINTF_SPEC_SIGNED,
    ['u'] = P_MY_PRINTF_SPEC_UNSIGNED,
    ['o'] = P_MY_PRINTF_SPEC_OCTAL,
    ['x'] = P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL,
    ['X'] = P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL,
    ['b'] = P_MY_PRINTF_SPEC_LOWER_BINARY,
    ['B'] = P_MY_PRINTF_SPEC_UPPER_BINARY,
    ['r'] = P_MY_PRINTF_SPEC_LOWER_BOOLEAN,
    ['R'] = P_MY_PRINTF_SPEC_UPPER_BOOLEAN,
    ['f'] = P_MY_PRINTF_SPEC_LOWER_FLOAT,
    ['F'] = P_MY_PRINTF_SPEC_UPPER_FLOAT,
    ['e'] = P_MY_PRINTF_SPEC_LOWER_FLOAT_EXPONENT,
    ['E'] = P_MY_PRINTF_SPEC_UPPER_FLOAT_EXPONENT,
    ['g'] = P_MY_PRINTF_SPEC_LOWER_FLOAT_SCIENTIFIC,
    ['G'] = P_MY_PRINTF_SPEC_UPPER_FLOAT_SCIENTIFIC,
    ['a'] = P_MY_PRINTF_SPEC_LOWER_FLOAT_HEXADECIMAL,
    ['A'] = P_MY_PRINTF_SPEC_UPPER_FLOAT_HEXADECIMAL,
    ['c'] = P_MY_PRINTF_SPEC_CHAR,
    ['s'] = P_MY_PRINTF_SPEC_STRING,
    ['S'] = P_MY_PRINTF_SPEC_STRING_OCTAL,
    ['p'] = P_MY_PRINTF_SPEC_POINTER,
    ['n'] = P_MY_PRINTF_SPEC_COUNT,
    ['%'] = P_MY_PRINTF_SPEC_PERCENT,
};

MY_LOCAL p_my_printf_specifier_t p_my_printf_get_conv_specifier(
    char const **sr)
{
    p_my_printf_specifier_t spec = CONVERSION_SPECIFIERS[(unsigned char)**sr];

    if (**sr)
        ++(*sr);
    return spec;
}
