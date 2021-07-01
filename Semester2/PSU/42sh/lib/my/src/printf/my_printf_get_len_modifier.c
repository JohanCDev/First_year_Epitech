/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Parses the next length modifier
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const p_my_printf_length_t LENGTH_MODIFIERS[256] = {
    ['h'] = P_MY_PRINTF_LEN_SHORT,
    ['l'] = P_MY_PRINTF_LEN_LONG,
    ['L'] = P_MY_PRINTF_LEN_LONG_DOUBLE,
    ['j'] = P_MY_PRINTF_LEN_INTMAX_T,
    ['z'] = P_MY_PRINTF_LEN_SIZE_T,
    ['t'] = P_MY_PRINTF_LEN_PTRDIFF_T,
};

MY_LOCAL p_my_printf_length_t p_my_printf_get_len_modifier(char const **src)
{
    p_my_printf_length_t len = LENGTH_MODIFIERS[(unsigned char)**src];

    if (len == P_MY_PRINTF_LEN_DEFAULT)
        return len;
    ++(*src);
    if (len == P_MY_PRINTF_LEN_SHORT && **src == 'h') {
        len = P_MY_PRINTF_LEN_CHAR;
        ++(*src);
    } else if (len == P_MY_PRINTF_LEN_LONG && **src == 'l') {
        len = P_MY_PRINTF_LEN_LONG_LONG;
        ++(*src);
    }
    return len;
}
