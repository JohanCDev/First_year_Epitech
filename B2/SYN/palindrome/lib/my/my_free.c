/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** my_free
*/

#include <stdlib.h>
#include <unistd.h>

void my_free(void *ptr)
{
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
}