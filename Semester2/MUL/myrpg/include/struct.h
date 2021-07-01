/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#define MOB 10 /*un type nombre à donner*/
#define RESSOURCE 20 /*same*/
#define PNJ 20 /*""*/

#include "inv.h"

typedef struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} game_object_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    int button_type;
} button_t;

typedef struct musics_s {
    sfMusic *main_music;
    sfMusic *button_sound;
} musics_t;

typedef struct enemie_info_s {
    game_object_t *mob;
    sfClock *clock;
    int life;
    int attack_value;
} enemie_info_t;

typedef struct enemies_s enemies_t;
struct enemies_s
{
    enemie_info_t *enemie_info;
    enemies_t *next;
};

typedef struct text_s {
    sfText *text;
    int value;
    sfFont *font;
    sfVector2f potext_t;
} text_t;

typedef struct scene_s {
    game_object_t **objs;
    button_t **buttons;
    text_t **texts;
    game_object_t *background;
} scene_t;

typedef struct list_textures_s {
    sfTexture *run;
    sfTexture *idle;
    sfTexture *run_reversed;
} list_textures_t;

typedef struct player_s {
    sfClock *clock;
    sfTime timer;
    sfSprite *sprite;
    list_textures_t *textures;
    sfIntRect rect;
    sfVector2f map_pos;
    int offset;
    int max_value;
    int attack_value;
    int life;
    sfVector2f pos;
    char *name;
    inv_t **inv;
    game_object_t *heart;
} player_t;

typedef struct keys {
    bool go_up;
    bool go_right;
    bool go_down;
    bool go_left;
    bool interact;
    bool open_inventory;
    bool open_quest_log;
} keys_t;

typedef struct playing_game {
    scene_t *playing_game;
    sfView *map_view;
    sfView *default_view;
    sfImage *hitboxes;
    enemies_t *enemies;
    sfClock *main_clock;
    player_t *player;
    keys_t key_pressed;
    int current_nb_enemies;
    int max_nb_enemies;
} s_playing;

typedef struct move_quest {
    bool snow;
    bool hell;
    bool farm;
    bool forest;
    bool lake;
    bool graveyard;
    bool cave;
    bool castle;
    bool city;
    bool done;
} move_quest_t;

typedef struct increase_quest {
    int needed_type;
    int nbr_needed;
    int actual_nbr;
    bool done;
    bool started;
} increase_quest_t;

typedef struct found_quest {
    bool found;
    int needed_type;
} found_quest_t;

typedef struct tmp_fight_s {
    sfVector2f tmp_sc_player;
    sfVector2f tmp_sc_enn;
    sfVector2f tmp_pos_player;
    sfVector2f tmp_pos_enn;
} t_tmp_fight;

typedef struct quest_log {
    move_quest_t *travel;
    increase_quest_t *kill_mobs;
    increase_quest_t *ressources;
    increase_quest_t *talking;
    found_quest_t *errant;
    found_quest_t *unknown_stone;
} quest_log_t;

typedef struct snow {
    sfCircleShape *circle;
    sfVector2f pos;
    sfVector2f speed;
    float radius;
    sfColor color;
} snow_t;

typedef struct particles {
    game_object_t *particle;
    sfClock *clock;
    bool display;
    int current_sprite;
} particles_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    scene_t *menu;
    scene_t *pause_menu;
    scene_t *current_scene;
    scene_t *infos;
    scene_t *fight;
    scene_t *inventory;
    s_playing *play_infos;
    sfImage *map_path;
    game_object_t *cursor;
    musics_t *musics;
    enemie_info_t *enemy;
    quest_log_t *quests;
    particles_t *particles;
    snow_t **snow;
    int ret;
} game_t;

#endif /* !STRUCT_H_ */