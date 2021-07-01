/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** initialize_playing_game
*/

#include "defender.h"
#include "my.h"

void initialize_playing_game_objects(s_game *defender)
{
    defender->play_infos->playing_game->objs[0] = create_object\
    ("./resources/objects/lives_coins.png", (sfVector2f) \
    {100, 60}, create_rect(0, 0, 411, 210), (sfVector2f) {0.4, 0.4});
    defender->play_infos->playing_game->objs[1] = create_object\
    ("./resources/objects/timer_box.png", (sfVector2f) \
    {800, 50}, create_rect(0, 0, 314, 82), (sfVector2f) {1, 1});
    defender->play_infos->playing_game->objs[2] = create_object\
    ("./resources/objects/menu.png", (sfVector2f) \
    {sfRenderWindow_getSize(defender->window).x + 291, 450}, \
    create_rect(0, 0, 582, 900), (sfVector2f) {1, 1});
    initialize_market_tower(defender);
    initialize_market_tower_second(defender);
}

void initialize_market_tower(s_game *defender)
{
    defender->play_infos->playing_game->objs[3] = create_object\
    ("./resources/objects/border_filled.png", (sfVector2f) \
    {1780, 270}, create_rect(50, 180, 540, 470), (sfVector2f) {0.36, 0.36});
    defender->play_infos->playing_game->objs[4] = create_object\
    ("./resources/objects/coins.png", (sfVector2f) \
    {1712, 166}, create_rect(0, 0, 411, 108), (sfVector2f) {0.33, 0.33});
    defender->play_infos->playing_game->objs[5] = create_object\
    ("./resources/objects/border_filled.png", (sfVector2f) \
    {1980, 270}, create_rect(50, 180, 540, 470), (sfVector2f) {0.36, 0.36});
    defender->play_infos->playing_game->objs[6] = create_object\
    ("./resources/objects/coins.png", (sfVector2f) \
    {1912, 166}, create_rect(0, 0, 411, 108), (sfVector2f) {0.33, 0.33});
}

void initialize_market_tower_second(s_game *defender)
{
    defender->play_infos->playing_game->objs[7] = create_object\
    ("./resources/objects/border_filled.png", (sfVector2f) \
    {1780, 480}, create_rect(50, 180, 540, 470), (sfVector2f) {0.36, 0.36});
    defender->play_infos->playing_game->objs[8] = create_object\
    ("./resources/objects/coins.png", (sfVector2f) \
    {1712, 376}, create_rect(0, 0, 411, 108), (sfVector2f) {0.33, 0.33});
    defender->play_infos->playing_game->objs[9] = create_object\
    ("./resources/objects/border_filled.png", (sfVector2f) \
    {1980, 480}, create_rect(50, 180, 540, 470), (sfVector2f) {0.36, 0.36});
    defender->play_infos->playing_game->objs[10] = create_object\
    ("./resources/objects/coins.png", (sfVector2f) \
    {1912, 376}, create_rect(0, 0, 411, 108), (sfVector2f) {0.33, 0.33});
    defender->play_infos->playing_game->objs[11] = NULL;
}

void initialize_playing_game_buttons(s_game *defender)
{
    defender->play_infos->playing_game->buttons[0] = init_button_from_string\
    (defender, "98.87 20 2.26 4 resources/objects/box.jpeg box", BOX_BUTTON);
    defender->play_infos->playing_game->buttons[1] = NULL;
}

void initialize_buttons_objects_and_text(s_game *defender)
{
    s_scene *scene = defender->play_infos->playing_game;
    scene->buttons = malloc(sizeof(s_button) * 3);
    scene->objs = malloc(sizeof(s_game_object) * 12);
    scene->texts = malloc(sizeof(s_text) * 8);
    initialize_play_infos(defender);
    initialize_playing_game_buttons(defender);
    initialize_playing_game_texts(scene->texts);
    initialize_playing_game_objects(defender);
}