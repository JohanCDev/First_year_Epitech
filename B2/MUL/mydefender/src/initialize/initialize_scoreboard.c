/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** initialize_scoreboard
*/

#include "my.h"
#include "defender.h"

void initialize_scoreboard_struct(s_scene *scoreboard)
{
    scoreboard->background = malloc(sizeof(s_game_object));
    scoreboard->texts = malloc(sizeof(s_text) * 2);
    scoreboard->buttons = malloc(sizeof(s_button) * 3);
    scoreboard->objs = malloc(sizeof(s_game_object));
    scoreboard->texts = malloc(sizeof(s_text));
}

void initialize_scoreboard(s_game *defender)
{
    defender->scoreboard->background = create_object\
    ("./resources/menu/scoreboard.png", (sfVector2f){800, 450}, \
    create_rect(0, 0, 750, 500), (sfVector2f){2.13, 1.8});
    defender->scoreboard->texts[0] = init_text("./resources/font.ttf", \
    (sfVector2f){780, 480}, -1, 120);
    sfText_setColor(defender->scoreboard->texts[0]->text, \
    (sfColor){255, 0, 0, 255});
    defender->scoreboard->texts[1] = NULL;
    defender->scoreboard->buttons[0] = init_button_from_string\
    (defender, "95.3 92 6.75 12 resources/pause/home.png home", \
    HOME_BUTTON);
    defender->scoreboard->buttons[1] = init_button_from_string\
    (defender, "95.3 8 6.75 12 resources/menu/quit.png quit", QUIT_BUTTON);
    defender->scoreboard->buttons[2] = NULL;
    defender->scoreboard->objs[0] = NULL;
}

void initialize_infos(s_game *defender)
{
    defender->infos->background = create_object\
    ("./resources/menu/how_to_play.png", (sfVector2f){800, 450}, \
    create_rect(0, 0, 1600, 898), (sfVector2f){1, 1});
    defender->infos->buttons[0] = init_button_from_string\
    (defender, "95.3 92 6.75 12 resources/pause/home.png home", \
    HOME_BUTTON);
    defender->infos->buttons[1] = NULL;
    defender->infos->objs[0] = NULL;
    defender->infos->texts[0] = NULL;
}