/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Prints a string conversion
*/

#include "libmy/core.h"
#include "libmy/printf.h"
#include "my_printf.h"

static const char *OCTAL = "01234567";

static int write_char_octal(my_iostream_t *out, char c)
{
    unsigned char nb = (unsigned char)c;

    if (c >= ' ' && c <= '~')
        return my_fputc(c, out);
    if (my_fputc('\\', out) || my_fputc(OCTAL[nb / 0100], out))
        return 1;
    nb %= 0100;
    if (my_fputc(OCTAL[nb / 010], out) || my_fputc(OCTAL[nb % 010], out))
        return 1;
    return 0;
}

static int write_string(my_iostream_t *output, p_my_printf_conv_t const *conv,
    const char *str, size_t len)
{
    size_t max;
    int need_quotes = PGET_FLAG(ALT);

    if (need_quotes)
        len -= 2;
    if ((need_quotes && my_fputc('"', output)) || (!need_quotes && len == 0))
        return need_quotes;
    if (!PGET_SPEC(STRING_OCTAL))
        return my_fwrite(str, len, 1, output) != 1
            || (need_quotes && my_fputc('"', output));
    max = SIZE_MAX;
    if (PGET_FLAG(HAS_PRECISION))
        max = conv->precision;
    for (size_t i = 0; str[i] && i < max; ++i)
        if (write_char_octal(output, str[i]))
            return 1;
    return need_quotes && my_fputc('"', output);
}

MY_LOCAL int p_my_printf_string(my_iostream_t *output,
    p_my_printf_conv_t const *conv, size_t len, size_t zeros)
{
    char const *str = conv->value.string_arg;

    (void)zeros;
    if (!str)
        str = "(null)";
    if (p_my_printf_lpad(output, conv, len, ' ')
        || write_string(output, conv, str, len)
        || p_my_printf_rpad(output, conv, len, ' '))
        return -1;
    return MY_MAX(len, conv->field_width);
}
