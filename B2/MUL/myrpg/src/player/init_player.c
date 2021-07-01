/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** init_player
*/

#include "rpg.h"

void create_player_textures(player_t *player, sfIntRect rect)
{
    player->textures = malloc(sizeof(list_textures_t));
    player->textures->run = sfTexture_createFromFile\
    ("./resources/game/player/Run.png", NULL);
    player->textures->idle = sfTexture_createFromFile\
    ("./resources/game/player/Idle.png", NULL);
    player->textures->run_reversed = sfTexture_createFromFile\
    ("./resources/game/player/Run_Reversed.png", NULL);
    player->rect = rect;
    player->offset = 31;
    player->max_value = 248;
}

game_object_t *init_heart_player(game_object_t *heart)
{
    sfVector2u size;

    heart = malloc(sizeof(game_object_t));
    heart->sprite = sfSprite_create();
    heart->texture = sfTexture_createFromFile("./resources/heart.png", NULL);
    heart->position.x = 750;
    heart->position.y = 640;
    size = sfTexture_getSize(heart->texture);
    heart->rect.top = 0;
    heart->rect.left = 0;
    heart->rect.width = size.x / 9;
    heart->rect.height = size.y;
    sfSprite_setTexture(heart->sprite, heart->texture, sfTrue);
    sfSprite_setPosition(heart->sprite, heart->position);
    sfSprite_setTextureRect(heart->sprite, heart->rect);
    return heart;
}

player_t *init_player(void)
{
    sfIntRect rect = {0, 0, 32, 54};
    sfVector2f scale = {0.75, 0.75};
    player_t *player = malloc(sizeof(player_t));
    if (player != NULL) {
        player->name = "Godefroy de Montmirail";
        player->clock = sfClock_create();
        player->sprite = sfSprite_create();
        create_player_textures(player, rect);
        player->life = 100;
        player->map_pos = (sfVector2f) {1726, 970};
        player->attack_value = 15;
        sfSprite_setScale(player->sprite, scale);
        sfSprite_setPosition(player->sprite, (sfVector2f){0, 120});
        sfSprite_setTexture(player->sprite, player->textures->idle, sfTrue);
        sfSprite_setTextureRect(player->sprite, rect);
        player->inv = init_inventory(player->inv);
        player->heart = init_heart_player(player->heart);
    } else
        return (NULL);
    return (player);
}