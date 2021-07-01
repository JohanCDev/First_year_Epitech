/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** initailize_game
*/

#include "rpg.h"

void initialize_playing_game(game_t *rpg)
{
    rpg->play_infos->playing_game->objs = malloc(sizeof(game_object_t) * 1);
    rpg->play_infos->playing_game->objs[0] = NULL;
    rpg->play_infos->playing_game->buttons = malloc(sizeof(button_t) * 1);
    rpg->play_infos->playing_game->buttons[0] = NULL;
    rpg->play_infos->playing_game->texts = malloc(sizeof(text_t) * 1);
    rpg->play_infos->playing_game->texts[0] = NULL;
}

void initialize_game(game_t *rpg)
{
    rpg->play_infos->playing_game->background = create_object\
    ("./resources/game/map.png", (sfVector2f) {0, 0}, \
    create_rect(0, 0, 3453, 1941), (sfVector2f) {1, 1});
    rpg->play_infos->map_view = \
    sfView_createFromRect((sfFloatRect) {0, 0, 3453, 1941});
    sfView_setCenter(rpg->play_infos->map_view, (sfVector2f){0, 120});
    sfView_zoom(rpg->play_infos->map_view, 1/6.0);
    rpg->play_infos->default_view = \
    sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    rpg->play_infos->hitboxes = \
    sfImage_createFromFile("./resources/game/hitbox.png");
    rpg->cursor = create_object("./resources/objects/cursor.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 500, 500}, (sfVector2f){0.08, 0.08});
    initialize_playing_game(rpg);
    rpg->play_infos->enemies = malloc(sizeof(enemies_t));
    rpg->play_infos->enemies = NULL;
    rpg->play_infos->main_clock = sfClock_create();
}
