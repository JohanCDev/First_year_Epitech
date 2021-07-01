/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** print_infos
*/

#include "my.h"
#include "pal.h"

int print_all_infos(pal_t *pal)
{
    my_printf("n %d p %d base %d imax %d imin %d\n", pal->flags.n, \
    pal->flags.p, pal->flags.base, pal->flags.imax, \
    pal->flags.imin);

    return 0;
}