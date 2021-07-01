/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** test_my_asm
*/

#include "criterion/criterion.h"
#include "assembler.h"

Test(create_path, create_path_easy)
{
    char *path = create_path("filepath");
    cr_assert_str_eq(path, "filepath.cor");
}

Test(create_path, create_path_harder)
{
    char *path = create_path("filepath.s");
    cr_assert_str_eq(path, "filepath.cor");
}

Test(my_putnbr_base_int, nbr_base_easy)
{
    int nb = 10;
    char const *base = "0123456789abcdef";
    char *str_nb = my_putnbr_base_int(nb, base);
    cr_assert_str_eq(str_nb, "a");
}

Test(my_putnbr_base_int, nbr_base_harder)
{
    int nb = 4096;
    char const *base = "0123456789abcdef";
    char *str_nb = my_putnbr_base_int(nb, base);
    cr_assert_str_eq(str_nb, "1000");
}

Test(my_putnbr_base_int, nbr_base_hex)
{
    int nb = 1000;
    char const *base = "0123456789abcdef";
    char *str_nb = my_putnbr_base_int(nb, base);
    cr_assert_str_eq(str_nb, "3e8");
}