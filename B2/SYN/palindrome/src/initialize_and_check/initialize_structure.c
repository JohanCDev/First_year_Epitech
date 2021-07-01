/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** initialize_structure
*/

#include "pal.h"
#include <stdlib.h>

void initialize_structure(pal_t *pal)
{
    pal->flags.base = -1;
    pal->flags.imax = -1;
    pal->flags.imin = -1;
    pal->flags.n = -1;
    pal->flags.p = -1;
}