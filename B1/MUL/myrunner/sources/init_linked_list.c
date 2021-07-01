/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** init_linked_list
*/

#include "runner.h"
#include "my.h"

void add_in_linked_list(game_s *game, object_s *object)
{
    linked_list_s *new = malloc(sizeof(linked_list_s));

    if (new == NULL)
        return;
    new->enemy = object;
    new->next = game->enemy;
    game->enemy = new;
}

void print_obstacle(game_s *game)
{
    linked_list_s *new = game->enemy;

    while (new != NULL) {
        sfRenderWindow_drawSprite(game->window.window, \
        new->enemy->sprite, NULL);
        new = new->next;
    }
}