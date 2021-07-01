/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Utility functions
*/

#include <stdlib.h>

void sh_free_entry(void *ptr)
{
    free(*(char **)ptr);
}
