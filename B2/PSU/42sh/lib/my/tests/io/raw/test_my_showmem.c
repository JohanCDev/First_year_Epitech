/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_showmem function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

Test(my_showmem, null_string)
{
    cr_assert_eq(my_showmem(NULL, 42), -1);
}

Test(my_showmem, zero_size)
{
    cr_assert_eq(my_showmem("bob", 0), -1);
}

Test(my_showmem, aligned_size, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_showmem("This is a test?!", 16), 0);
    cr_assert_stdout_eq_str("\
00000000: 5468 6973 2069 7320 6120 7465 7374 3f21 This is a test?!\n");
}

Test(my_showmem, neat_stuff, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_showmem("hey guys show mem is cool you can do some pretty \
neat stuff\0\x0f\x1b\x7f\x05\x2e\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0e\
\x0f\x1b\x7f", 79), 0);
    cr_assert_stdout_eq_str("\
00000000: 6865 7920 6775 7973 2073 686f 7720 6d65 hey guys show me\n\
00000010: 6d20 6973 2063 6f6f 6c20 796f 7520 6361 m is cool you ca\n\
00000020: 6e20 646f 2073 6f6d 6520 7072 6574 7479 n do some pretty\n\
00000030: 206e 6561 7420 7374 7566 6600 0f1b 7f05  neat stuff.....\n\
00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f   ...............\n", "");
}
