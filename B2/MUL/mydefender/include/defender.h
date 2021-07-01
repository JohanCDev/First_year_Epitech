/*
** EPITECH PROJECT, 2021
** My_defender
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define PLAY_BUTTON (1)
#define QUIT_BUTTON (2)
#define HOME_BUTTON (3)
#define RESUME_BUTTON (4)
#define INFOS_BUTTON (5)
#define BOX_BUTTON (6)
#define MUSIC_BUTTON (7)

typedef struct game_object_t
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} s_game_object;

typedef struct button_t s_button;
typedef void(*event)(char *str);

struct button_t {
    sfRectangleShape *rect;
    sfTexture *texture;
    event clicked_event;
    int button_type;
};

typedef struct musics_t {
    sfMusic *main_music;
    sfMusic *button_sound;
    sfMusic *buying_sound;
} s_musics;

typedef struct enemie_info_t {
    s_game_object *mob;
    float life;
    sfVector2f direction;
    int current_speed;
    int base_speed;
    sfClock *speed_clock;
    sfClock *clock;
} s_enemie_info;

typedef struct enemies_t s_enemies;
struct enemies_t
{
    s_enemie_info *enemie_info;
    s_enemies *next;
};

typedef struct tower_info_t {
    s_game_object *object;
    int offset_rect;
    int max_value_rect;
    int price;
    int type;
    int killed_enemies;
    float damage_hit;
    int can_move;
    int animation_milliseconds;
    int draw_circle;
    sfClock *clock;
    sfCircleShape *circle;
    sfVector2f direction;
} s_tower_info;

typedef struct towers_t s_towers;
struct towers_t
{
    s_tower_info *tower_info;
    s_towers *next;
};

typedef struct text_t {
    sfText *text;
    int value;
    sfFont *font;
    sfVector2f pos_text;
} s_text;

typedef struct scenes_t {
    s_game_object **objs;
    s_button **buttons;
    s_game_object *background;
    s_text **texts;
} s_scene;

typedef struct playing_game {
    s_scene *playing_game;
    s_enemies *enemies;
    int nb_enemies;
    s_towers *towers;
    s_game_object **market_list;
    sfClock *main_clock;
    bool show_menu;
    bool active_wave;
    int current_difficulty;
} s_playing;

typedef struct game_t {
    sfRenderWindow *window;
    sfEvent event;
    s_scene *menu;
    s_scene *pause_menu;
    s_scene *current_scene;
    s_scene *scoreboard;
    s_scene *infos;
    s_playing *play_infos;
    sfImage *map_path;
    s_game_object *cursor;
    s_musics *musics;
    int ret;
} s_game;

/*          ANIMATIONS              */
//events_switch.c
void analyse_key_events(s_game *defender);
void analyse_events(s_game *defender);
void mouse_button_is_pressed(s_game *defender);
void mouse_moved_in_menu(s_game *defender, s_scene *scene);

//events.c
void escape_is_pressed(s_game *defender);
void mouse_is_moved(s_game *defender);

//get.c
void move_horizontally(s_game *defender, s_enemie_info *enemie_info, \
unsigned int x, unsigned int y);
void move_vertically(s_game *defender, s_enemie_info *enemie_info, \
unsigned int x, unsigned int y);
sfVector2f check_next_direction(s_game *defender, s_enemie_info *enemie_info);
float get_start_y(s_game *defender, int pos_x);

//rect.c
void move_rect(sfIntRect *rect, int offset, int max_value);
sfIntRect create_rect(int top, int left, int width, int height);

//wave_chrono.c
void display_text_if_sup_or_eq_to_zero(s_game *defender);
void display_wave_chrono(s_game *defender);

//window.c
sfRenderWindow *initialize_window(void);
void display_buttons_and_objects(s_scene *scene, sfRenderWindow *win);
void display_sprites_and_texts(s_game *defender, sfRenderWindow *win);
void update_playing_game(s_game *defender, sfRenderWindow *win, s_scene *scene);
void update_window(s_game *defender, int display);

/*              END ANIMATIONS              */
/*                  BUTTONS                 */

//button_is_clicked.c
void do_effect_clicked(s_button *button, s_game *defender);
void switch_button_clicked_second(s_button *button, s_game *defender);
void switch_button_clicked(s_button *button, s_game *defender);
void button_is_clicked(s_game *defender, s_button *button, \
sfMouseButtonEvent mousePosition);

//button.c
char *my_get_image_name(char *path);
void button_is_hover(s_button *button, sfMouseMoveEvent mousePosition);

/*              END BUTTONS             */
/*          CREATE AND DESTROY          */

//create_button.c
void set_params_of_button(s_button *button, char **array, \
sfRenderWindow *window);
s_button *init_button_from_string(s_game *defender, char const *informations, \
int type);

//create_object.c
s_game_object *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale);

//create_towers.c
void create_sprite_circle_towers(s_tower_info *tower_info, char **array);
void set_base_settings_tower(s_tower_info *tower_info, char **array);
s_tower_info *create_tower_from_string(char const *informations);

//destroy.c
void destroy_menu(s_game *defender);
void destroy_object(s_game_object *object);
void destroy_musics(s_musics *musics);
void destroy_all(s_game *defender);

//enemies_list.c
void insert_in_list_enemie(s_game *defender, s_enemie_info *enemie_info);
void add_enemie_in_window(s_game *defender);
void act_on_enemy(s_enemies *current, s_game *defender);
void display_enemies(s_game *defender);

//remove_enemy.c
void remove_enemy_from_list(s_game *defender, s_enemies *to_destroy, \
bool destroy);
s_enemies *verify_if_outside(s_game *defender, s_enemies *current);

/*          END CREATE AND DESTROY          */
/*               INITIALIZE                 */

//initialize_all.c
void initialize_struct(s_game *defender);
void initialize_musics(s_musics *musics);
s_text *init_text(char *filepath, sfVector2f position, int value, int size);
void initialize_playing_game(s_game *defender);
s_game *initialize_all(void);

//initialize_menus.c
void initialize_menu(s_game *defender);
void initialize_play_infos(s_game *defender);
void initialize_pause_menu(s_game *defender);

//initialize_playing_game.c
void initialize_market_tower(s_game *defender);
void initialize_market_tower_second(s_game *defender);
void initialize_playing_game_objects(s_game *defender);
void initialize_playing_game_buttons(s_game *defender);
void initialize_buttons_objects_and_text(s_game *defender);

//initialize_scoreboard.c
void initialize_scoreboard_struct(s_scene *scoreboard);
void initialize_scoreboard(s_game *defender);
void initialize_infos(s_game *defender);

//initialize_texts.c
void initialize_playing_game_texts_next(s_text **texts);
void initialize_playing_game_texts(s_text **texts);

//reinitialize_all.c
void reinitialize_objects(s_game *defender);
void reinitialize_towers(s_game *defender);
void reinitialize_enemies(s_game *defender);
void reinitialize_all(s_game *defender);

/*         END INITIALIZE           */
/*              TOWERS              */

//detect_purchase.c
void detect_first_line_market(s_game *defender, s_game_object *object);
void detect_second_line_market(s_game *defender, s_game_object *object);

//buy_towers.c
void buy_scientist(s_game *defender);
void buy_gel(s_game *defender);
void buy_hospitals(s_game *defender);
void buy_medic(s_game *defender);

//market_towers.c
void market_object_is_clicked(s_game *defender, s_game_object *object, \
sfMouseButtonEvent mousePosition);
void show_market(s_game *defender);
void hide_market(s_game *defender);
void use_box(s_game *defender);

//show_towers.c
int place_tower_at_release(s_game *defender, s_tower_info *tower_info, \
int red_circle_tempo);
void tower_follow_mouse(s_game *defender, s_tower_info *tower_info);
int display_red_circle_if_incorrect(sfClock *clock, int red_circle_tempo, \
s_tower_info *tower_info, s_game *defender);
void place_tower_and_buy_it(s_game *defender, s_tower_info *tower_info);
void show_tower_until_release(s_game *defender, s_tower_info *tower_info);

//tower_interact_enemies.c
bool can_attack_this_enemie(s_tower_info *tower_info, \
s_enemie_info *enemie_info);
void attack_enemy(bool attack, s_game *defender, s_enemie_info *enemie_info, \
s_tower_info *tower);
void kill_enemy(s_game *defender, s_enemie_info *enemie_info);
bool detect_enemies_in_circle(s_game *defender, \
s_tower_info *tower_info, bool attack, int area_damage);

//towers.c
void insert_in_list_towers(s_game *defender, s_tower_info *tower_info);
void add_tower_in_window(s_game *defender);
void animate_towers(s_towers *current, s_game *defender);
void detect_click_on_tower(s_towers *current, s_game *defender, \
sfFloatRect tower_rect);
void display_towers(s_game *defender);

/*          END TOWERS          */
/*            OTHERS            */

//check_endgame.c
int check_if_end(int life);

//different_enemies.c
void create_ch(s_game *defender, int pos_x);
void create_br(s_game *defender, int pos_x);
void create_sa(s_game *defender, int pos_x);
void create_bg(s_game *defender, int pos_x);

//image.c
bool get_red_pixel(int *pix, sfImage *map_path, sfSprite *sprite, int pos_x);
bool check_placement(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path);
void draw_tower_on_image(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path);
bool can_tower_be_placed(sfImage *map_path, sfSprite *sprite, \
sfMouseButtonEvent pos);

//update_text.c
void update_text(s_text *text, int value, bool add, sfVector2f pos);

//waves.c
int switch_enemy(s_game *defender, int index, int place);
int generate_random_enemy(void);
void create_wave(s_game *defender);

#endif /* !DEFENDER_H_ */