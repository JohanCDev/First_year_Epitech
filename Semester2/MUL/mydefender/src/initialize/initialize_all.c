/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** initialize_all
*/

#include "my.h"
#include "defender.h"

void initialize_struct(s_game *defender)
{
    defender->menu = malloc(sizeof(s_scene));
    defender->play_infos = malloc(sizeof(s_playing));
    defender->play_infos->playing_game = malloc(sizeof(s_scene));
    defender->pause_menu = malloc(sizeof(s_scene));
    defender->menu->buttons = malloc(sizeof(s_button) * 4);
    defender->menu->objs = malloc(sizeof(s_game_object) * 1);
    defender->infos = malloc(sizeof(s_scene));
    defender->infos->background = malloc(sizeof(s_game_object));
    defender->infos->objs = malloc(sizeof(s_game_object) * 1);
    defender->infos->buttons = malloc(sizeof(s_button) * 2);
    defender->infos->texts = malloc(sizeof(s_text) * 1);
    defender->scoreboard = malloc(sizeof(s_scene));
    initialize_scoreboard_struct(defender->scoreboard);
    defender->window = initialize_window();
    defender->musics = malloc(sizeof(s_musics));
    defender->play_infos->nb_enemies = 0;
    defender->ret = 0;
}

void initialize_musics(s_musics *musics)
{
    musics->main_music = sfMusic_createFromFile\
    ("./resources/sounds/main_music.ogg");
    sfMusic_play(musics->main_music);
    sfMusic_setLoop(musics->main_music, sfTrue);
    sfMusic_setVolume(musics->main_music, 50);
    musics->button_sound = sfMusic_createFromFile\
    ("./resources/sounds/button_sound.ogg");
    musics->buying_sound = sfMusic_createFromFile\
    ("./resources/sounds/buying_sound.ogg");
    sfMusic_setVolume(musics->buying_sound, 80);
}

s_text *init_text(char *filepath, sfVector2f position, int value, int size)
{
    s_text *label = malloc(sizeof(s_text));

    label->font = sfFont_createFromFile(filepath);
    label->text = sfText_create();
    label->value = value;
    sfText_setFont(label->text, label->font);
    sfText_setCharacterSize(label->text, size);
    sfText_setString(label->text, "0");
    sfText_setPosition(label->text, position);
    return (label);
}

void initialize_playing_game(s_game *defender)
{
    defender->play_infos->playing_game->background = create_object\
    ("./resources/maps/test.jpg", (sfVector2f) \
    {sfRenderWindow_getSize(defender->window).x/2, \
        sfRenderWindow_getSize(defender->window).y/2}, \
    create_rect(0, 0, 1471, 832), (sfVector2f) {1.088, 1.088});
    defender->cursor = create_object("./resources/curseur.png", \
    (sfVector2f) {0, 0}, create_rect(0, 0, 136, 128), (sfVector2f) {0.3, 0.3});
    sfSprite_setOrigin(defender->cursor->sprite, (sfVector2f){0, 0});
    initialize_buttons_objects_and_text(defender);
    defender->play_infos->enemies = malloc(sizeof(s_enemies));
    defender->play_infos->enemies = NULL;
}

s_game *initialize_all(void)
{
    s_game *defender = malloc(sizeof(s_game));

    initialize_struct(defender);
    initialize_musics(defender->musics);
    initialize_menu(defender);
    initialize_playing_game(defender);
    initialize_pause_menu(defender);
    initialize_infos(defender);
    initialize_scoreboard(defender);
    defender->map_path = \
    sfImage_createFromFile("./resources/maps/path.png");
    return (defender);
}