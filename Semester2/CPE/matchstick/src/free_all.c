/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-johan.chrillesen
** File description:
** free_all
*/

#include "my.h"
#include "matchstick.h"

void free_all(match_t *match)
{
    free(match->base_board);
    free(match->board);
    free(match);
}