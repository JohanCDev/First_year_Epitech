/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../my/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(test_lib, my_putchar, .init = redirect_all_std)
{
    my_putchar('a');
    my_putchar('b');
    my_putchar('0');
    my_putchar(72);
    my_putchar('e');
    my_putchar('T');
    cr_assert_stdout_eq_str("ab0HeT");
}

Test(lib_test, my_putstr, .init = redirect_all_std)
{
    my_putstr("I'm");
    my_putstr(" a ");
    my_putstr("test and");
    my_putstr(" I'm");
    my_putstr(" proud of it!");
    my_putstr("that's ");
    my_putstr("all");
    cr_assert_stdout_eq_str("I'm a test and I'm proud of it!that's all");
}

Test(test_lib_err, my_put_error, .init = redirect_all_std)
{
    my_put_error("Same thing as above", -1);
    my_put_error(" but ", -1);
    my_put_error("on the error output!", -1);
    cr_assert_stderr_eq_str("Same thing as above but on the error output!");
}

Test(test_lib_nb, my_putnbr, .init = redirect_all_std)
{
    my_put_nbr(40);
    my_put_nbr(0);
    my_put_nbr(13);
    my_put_nbr(2442525);
    my_put_nbr(-906);
    my_put_nbr(-0);
    my_put_nbr(-2147483648);
    cr_assert_stdout_eq_str("400132442525-9060-2147483648");
}

Test(test_lib_u_nb, my_put_unsigned_nbr, .init = redirect_all_std)
{
    my_put_unsigned_nbr(27);
    my_put_unsigned_nbr(1);
    cr_assert_stdout_eq_str("271");
}

Test(test_lib_printf, my_printf, .init = redirect_all_std)
{
    my_printf("This %d %i %s %X %x %b %S %o %u %p %P %% %#x %#X %#o %+i %+d %c \
%+i", 5, 5, "Hey", 12, 12, 12, "H\tn", 115, 2, 10, 10, 12, \
    12, 115, 12, 12, 'a', -12);
    cr_assert_stdout_eq_str(\
    "This 5 5 Hey C c 1100 H\\011n 163 2 0xa 0xa % 0xc 0xC 0163 +12 +12 a -12");
}

Test(test_lib_my_put_address, my_put_adress, .init = redirect_all_std)
{
    my_put_address(-12);
    cr_assert_stdout_eq_str("0x-c");
}

Test(test_lib_my_putstr_nonprintable, my_putstr_nonprintable, \
.init = redirect_all_std)
{
    my_putstr_nonprintable(">?\a\t");
    cr_assert_stdout_eq_str(">?\\007\\011");
}

Test(test_lib_my_put_tab, my_put_tab, .init = redirect_all_std)
{
    char **dest = my_str_to_word_array("    test         \
random string  salt", " ");
    my_put_tab(dest, "l");
    cr_assert_stdout_eq_str("testlrandomlstringlsalt\n");
}