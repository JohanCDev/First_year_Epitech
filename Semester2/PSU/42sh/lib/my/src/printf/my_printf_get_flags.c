/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Parses the next flags in a string
*/

#include "libmy/printf.h"
#include "my_printf.h"

static const p_my_printf_flag_t MY_PRINTF_FLAGS[256] = {
    ['#'] = P_MY_PRINTF_FLAG_ALT,
    ['0'] = P_MY_PRINTF_FLAG_ZERO_PAD,
    ['-'] = P_MY_PRINTF_FLAG_LEFT_ADJUST,
    [' '] = P_MY_PRINTF_FLAG_SIGN_BLANK,
    ['+'] = P_MY_PRINTF_FLAG_PLACE_SIGN,
    ['\''] = P_MY_PRINTF_FLAG_GROUP_DIGITS,
    ['I'] = P_MY_PRINTF_FLAG_ALT_DIGITS,
};

MY_LOCAL int p_my_printf_get_flags(char const **flags)
{
    int ret = 0;
    p_my_printf_flag_t flag = MY_PRINTF_FLAGS[(unsigned char)**flags];

    while (flag) {
        ret |= flag;
        ++(*flags);
        flag = MY_PRINTF_FLAGS[(unsigned char)**flags];
    }
    return ret;
}
