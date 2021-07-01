/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Parses the next type in the given string
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const unsigned char SPEC_LOOKUP[P_MY_PRINTF_SPEC_MAX_VALUE] = {
    [P_MY_PRINTF_SPEC_SIGNED] = 1,
    [P_MY_PRINTF_SPEC_UNSIGNED] = 1,
    [P_MY_PRINTF_SPEC_OCTAL] = 1,
    [P_MY_PRINTF_SPEC_LOWER_HEXADECIMAL] = 1,
    [P_MY_PRINTF_SPEC_UPPER_HEXADECIMAL] = 1,
    [P_MY_PRINTF_SPEC_LOWER_BINARY] = 1,
    [P_MY_PRINTF_SPEC_UPPER_BINARY] = 1,
    [P_MY_PRINTF_SPEC_LOWER_BOOLEAN] = 1,
    [P_MY_PRINTF_SPEC_UPPER_BOOLEAN] = 1,
    [P_MY_PRINTF_SPEC_LOWER_FLOAT] = 2,
    [P_MY_PRINTF_SPEC_UPPER_FLOAT] = 2,
    [P_MY_PRINTF_SPEC_LOWER_FLOAT_EXPONENT] = 2,
    [P_MY_PRINTF_SPEC_UPPER_FLOAT_EXPONENT] = 2,
    [P_MY_PRINTF_SPEC_LOWER_FLOAT_SCIENTIFIC] = 2,
    [P_MY_PRINTF_SPEC_UPPER_FLOAT_SCIENTIFIC] = 2,
    [P_MY_PRINTF_SPEC_LOWER_FLOAT_HEXADECIMAL] = 2,
    [P_MY_PRINTF_SPEC_UPPER_FLOAT_HEXADECIMAL] = 2,
    [P_MY_PRINTF_SPEC_CHAR] = 3,
    [P_MY_PRINTF_SPEC_STRING] = 4,
    [P_MY_PRINTF_SPEC_STRING_OCTAL] = 4,
    [P_MY_PRINTF_SPEC_POINTER] = 5,
    [P_MY_PRINTF_SPEC_COUNT] = 6,
    [P_MY_PRINTF_SPEC_PERCENT] = 7,
};

static p_my_printf_arg_type_t my_printf_integer_type(
    p_my_printf_length_t len, int is_unsigned)
{
    switch (len) {
        case P_MY_PRINTF_LEN_CHAR: return P_MY_PRINTF_ARG_SBYTE + is_unsigned;
        case P_MY_PRINTF_LEN_SHORT: return P_MY_PRINTF_ARG_SHORT + is_unsigned;
        case P_MY_PRINTF_LEN_LONG: return P_MY_PRINTF_ARG_LONG + is_unsigned;
        case P_MY_PRINTF_LEN_LONG_LONG:
            return P_MY_PRINTF_ARG_LONG_LONG + is_unsigned;
        case P_MY_PRINTF_LEN_INTMAX_T:
            return P_MY_PRINTF_ARG_INTMAX_T + is_unsigned;
        case P_MY_PRINTF_LEN_SIZE_T:
            return P_MY_PRINTF_ARG_SSIZE_T + is_unsigned;
        case P_MY_PRINTF_LEN_PTRDIFF_T:
            return P_MY_PRINTF_ARG_PTRDIFF_T + is_unsigned;
        default: return P_MY_PRINTF_ARG_INT + is_unsigned;
    }
}

static p_my_printf_arg_type_t my_printf_float_type(p_my_printf_length_t len)
{
    if (len == P_MY_PRINTF_LEN_LONG_DOUBLE)
        return P_MY_PRINTF_ARG_LONG_DOUBLE;
    return P_MY_PRINTF_ARG_DOUBLE;
}

static p_my_printf_arg_type_t my_printf_count_type(p_my_printf_length_t len)
{
    switch (len) {
        case P_MY_PRINTF_LEN_CHAR: return P_MY_PRINTF_ARG_PTR_SCHAR;
        case P_MY_PRINTF_LEN_SHORT: return P_MY_PRINTF_ARG_PTR_SHORT;
        case P_MY_PRINTF_LEN_LONG: return P_MY_PRINTF_ARG_PTR_LONG;
        case P_MY_PRINTF_LEN_LONG_LONG: return P_MY_PRINTF_ARG_PTR_LONG_LONG;
        case P_MY_PRINTF_LEN_INTMAX_T: return P_MY_PRINTF_ARG_PTR_INTMAX_T;
        case P_MY_PRINTF_LEN_SIZE_T: return P_MY_PRINTF_ARG_PTR_SIZE_T;
        case P_MY_PRINTF_LEN_PTRDIFF_T: return P_MY_PRINTF_ARG_PTR_PTRDIFF_T;
        default: return P_MY_PRINTF_ARG_PTR_INT;
    }
}

MY_LOCAL p_my_printf_arg_type_t p_my_printf_get_type(
    p_my_printf_length_t len, p_my_printf_specifier_t specifier)
{
    switch (SPEC_LOOKUP[specifier]) {
        case 1:
            return my_printf_integer_type(
                len, specifier != P_MY_PRINTF_SPEC_SIGNED);
        case 2: return my_printf_float_type(len);
        case 3: return P_MY_PRINTF_ARG_CHAR;
        case 4: return P_MY_PRINTF_ARG_STRING;
        case 5: return P_MY_PRINTF_ARG_POINTER;
        case 6: return my_printf_count_type(len);
        case 7: return P_MY_PRINTF_ARG_PERCENT;
        default: return P_MY_PRINTF_ARG_INT;
    }
}
