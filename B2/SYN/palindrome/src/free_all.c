/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** free_all
*/

#include "pal.h"
#include "my.h"
#include <stdlib.h>

void free_if_base_is_not_10(void *ptr, int base)
{
    if (base != 10)
        my_free(ptr);
}