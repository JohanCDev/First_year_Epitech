/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the character classification functions
*/

#include <criterion/criterion.h>
#include "libmy/ascii/character.h"

Test(my_isalpha, base)
{
    cr_assert(!my_isalpha(' '));
    cr_assert(!my_isalpha('~'));
    cr_assert(!my_isalpha('['));
    cr_assert(my_isalpha('A'));
    cr_assert(my_isalpha('T'));
    cr_assert(my_isalpha('Z'));
    cr_assert(my_isalpha('a'));
    cr_assert(my_isalpha('t'));
    cr_assert(my_isalpha('z'));
}

Test(my_isdigit, base)
{
    cr_assert(!my_isdigit(' '));
    cr_assert(!my_isdigit('~'));
    cr_assert(!my_isdigit('['));
    cr_assert(my_isdigit('0'));
    cr_assert(my_isdigit('1'));
    cr_assert(my_isdigit('2'));
    cr_assert(my_isdigit('3'));
    cr_assert(my_isdigit('4'));
    cr_assert(my_isdigit('5'));
    cr_assert(my_isdigit('6'));
    cr_assert(my_isdigit('7'));
    cr_assert(my_isdigit('8'));
    cr_assert(my_isdigit('9'));
}

Test(my_isalnum, base)
{
    cr_assert(!my_isalnum(' '));
    cr_assert(!my_isalnum('~'));
    cr_assert(!my_isalnum('['));
    cr_assert(my_isalnum('T'));
    cr_assert(my_isalnum('0'));
    cr_assert(my_isalnum('r'));
    cr_assert(my_isalnum('7'));
    cr_assert(my_isalnum('8'));
    cr_assert(my_isalnum('9'));
}

Test(my_isblank, base)
{
    cr_assert(my_isblank(' '));
    cr_assert(my_isblank('\t'));
    cr_assert(!my_isblank('~'));
}

Test(my_iscntrl, base)
{
    cr_assert(!my_iscntrl('A'));
    cr_assert(!my_iscntrl('?'));
    cr_assert(!my_iscntrl(0xff));
    cr_assert(my_iscntrl(0x7f));
    cr_assert(my_iscntrl(0x02));
}

Test(my_isgraph, base)
{
    cr_assert(my_isgraph('A'));
    cr_assert(my_isgraph('?'));
    cr_assert(!my_isgraph(0xff));
    cr_assert(!my_isgraph(0x7f));
    cr_assert(!my_isgraph(0x02));
}

Test(my_islower, base)
{
    cr_assert(my_islower('a'));
    cr_assert(my_islower('z'));
    cr_assert(!my_islower('A'));
    cr_assert(!my_islower('Z'));
    cr_assert(!my_islower('9'));
}

Test(my_isprint, base)
{
    cr_assert(!my_isprint(0x12));
    cr_assert(!my_isprint(0xca));
    cr_assert(my_isprint('#'));
    cr_assert(my_isprint('4'));
    cr_assert(my_isprint('c'));
    cr_assert(my_isprint('U'));
}

Test(my_ispunct, base)
{
    cr_assert(!my_ispunct(0x12));
    cr_assert(!my_ispunct(0xca));
    cr_assert(my_ispunct('#'));
    cr_assert(!my_ispunct('4'));
    cr_assert(!my_ispunct('c'));
    cr_assert(!my_ispunct('U'));
}

Test(my_isspace, base)
{
    cr_assert(!my_isspace(0x00));
    cr_assert(my_isspace(' '));
    cr_assert(my_isspace('\f'));
    cr_assert(my_isspace('\n'));
    cr_assert(my_isspace('\r'));
    cr_assert(my_isspace('\t'));
    cr_assert(my_isspace('\v'));
    cr_assert(!my_isspace('\a'));
    cr_assert(!my_isspace('\b'));
    cr_assert(!my_isspace('Y'));
}

Test(my_isupper, base)
{
    cr_assert(!my_isupper('a'));
    cr_assert(!my_isupper('z'));
    cr_assert(my_isupper('A'));
    cr_assert(my_isupper('Z'));
    cr_assert(!my_isupper('9'));
}

Test(my_isxdigit, base)
{
    cr_assert(my_isxdigit('0'));
    cr_assert(my_isxdigit('8'));
    cr_assert(my_isxdigit('a'));
    cr_assert(my_isxdigit('c'));
    cr_assert(my_isxdigit('D'));
    cr_assert(my_isxdigit('B'));
    cr_assert(!my_isxdigit('G'));
    cr_assert(!my_isxdigit('?'));
}
