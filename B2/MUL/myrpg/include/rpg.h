/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/OpenGL.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include <math.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

#include "struct.h"
#include "inv.h"
#include "my.h"

#define PLAY_BUTTON (1)
#define QUIT_BUTTON (2)
#define HOME_BUTTON (3)
#define RESUME_BUTTON (4)
#define INFOS_BUTTON (5)
#define MUSIC_BUTTON (6)
#define PARAMS_BUTTON (7)
#define ATTACK_BUTTON (8)
#define DEFENSE_BUTTON (9)
#define RUNAWAY_BUTTON (10)

/*          ANIMATIONS              */
//events_switch.c
void analyse_key_events(game_t *rpg);
void analyse_events(game_t *rpg);
void mouse_button_is_pressed(game_t *rpg);
void mouse_moved_in_menu(game_t *rpg, scene_t *scene);

//events.c
void escape_is_pressed(game_t *rpg);
void mouse_is_moved(game_t *rpg);

//events_utils.c
void mouse_moved_in_menu(game_t *rpg, scene_t *scene);
void mouse_button_is_pressed(game_t *rpg);
void detect_fighting(game_t *rpg);
bool check_if_can_move(sfView *view, sfImage *hitboxes, \
sfVector2f move, game_t *rpg);

//get.c
void move_horizontally(game_t *rpg, enemie_info_t *enemie_info, \
unsigned int x, unsigned int y);
void move_vertically(game_t *rpg, enemie_info_t *enemie_info, \
unsigned int x, unsigned int y);
sfVector2f check_next_direction(game_t *rpg, enemie_info_t *enemie_info);
float get_start_y(game_t *rpg, int pos_x);

//rect.c
void move_rect(sfIntRect *rect, int offset, int max_value);
sfIntRect create_rect(int top, int left, int width, int height);

//window.c
sfRenderWindow *initialize_window(void);
void display_buttons_and_objects(scene_t *scene, sfRenderWindow *win);
void display_sprites_and_texts(game_t *rpg, sfRenderWindow *win);
void update_playing_game(game_t *rpg, sfRenderWindow *win);
void update_window(game_t *rpg, int display);

/*              END ANIMATIONS              */
/*                  BUTTONS                 */

//button_is_clicked.c
void do_effect_clicked(button_t *button, game_t *rpg);
void switch_button_clicked_second(button_t *button, game_t *rpg);
void switch_button_clicked(button_t *button, game_t *rpg);
bool button_is_clicked(game_t *rpg, button_t *button, \
sfMouseButtonEvent mousePosition);

//button.c
char *my_get_image_name(char *path);
void button_is_hover(button_t *button, sfMouseMoveEvent mousePosition);

/*              END BUTTONS             */
/*          CREATE AND DESTROY          */

//create_button.c
void set_params_of_button(button_t *button, char **array);
button_t *init_button_from_string(char const *informations, \
int type);

//create_object.c
game_object_t *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale);

//destroy.c
void destroy_menu(game_t *rpg);
void destroy_object(game_object_t *object);
void destroy_musics(musics_t *musics);
void destroy_player(player_t *player);
void destroy_all(game_t *rpg);

//destroy_scene
void destroy_scene(scene_t *scene, bool buttons, bool texts, bool objs);
void destroy_game(s_playing *playing_game);

//destroy_enemies_and_music
void destroy_enemies(enemies_t *enemy);
void destroy_musics(musics_t *musics);

//enemies_list.c
void insert_in_list_enemie(game_t *rpg, enemie_info_t *enemie_info);
void add_enemie_in_window(game_t *rpg);
void act_on_enemy(enemies_t *current, game_t *rpg);
void display_enemies(game_t *rpg);

//remove_enemy.c
void remove_enemy_from_list(game_t *rpg, enemies_t *to_destroy, \
bool destroy);
enemies_t *verify_if_outside(game_t *rpg, enemies_t *current);

/*          END CREATE AND DESTROY          */
/*               INITIALIZE                 */

//initialize_all.c
void initialize_struct(game_t *rpg);
void initialize_musics(musics_t *musics);
text_t *init_text(char *filepath, sfVector2f position, int value, int size);
text_t *init_text_str(char *filepath, sfVector2f position, char *str, int size);
void initialize_game(game_t *rpg);
game_t *initialize_all(void);

//initialize_menus.c
void initialize_menu(game_t *rpg);
void initialize_play_infos(game_t *rpg);
void initialize_pause_menu(game_t *rpg);

//reinitialize_all.c
void reinitialize_objects(game_t *rpg);
void reinitialize_towers(game_t *rpg);
void reinitialize_enemies(game_t *rpg);
void reinitialize_all(game_t *rpg);

//initialize_fight
void init_fight_scene(game_t *rpg);
particles_t *init_particles(void);


/*         END INITIALIZE           */
/*            OTHERS            */

//image.c
bool get_red_pixel(int *pix, sfImage *map_path, sfSprite *sprite, int pos_x);
bool check_placement(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path);
void draw_tower_on_image(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path);
bool can_tower_be_placed(sfImage *map_path, sfSprite *sprite, \
sfMouseButtonEvent pos);

//update_text.c
void update_text(text_t *text, int value, bool add, sfVector2f pos);

//waves.c
int switch_enemy(game_t *rpg, int index, int place);
int generate_random_enemy(void);
void create_wave(game_t *rpg);

//player
player_t *init_player(void);
void player_deplacment(game_t *rpg);

//fight
void fight_scene(game_t *rpg, enemie_info_t *enemie_info);
int player_turn(game_t *rpg, enemie_info_t *enemie_info);
void enemie_turn(game_t *rpg, enemie_info_t *enemie_info, int ret_player);
void player_won(game_t *rpg);
void player_died(game_t *rpg, t_tmp_fight tmp, enemie_info_t *enemie_info);
int switch_fight_key(game_t *rpg, enemie_info_t *enemie_info, int played);

void init_enemies_list(enemies_t *list);
void add_enemy_at_list(game_t *rpg, enemie_info_t *enemy_info);
void create_enemy(game_t *rpg, game_object_t *mob, sfVector2f stats);

void move_rectangles_for_fight(game_t *rpg, enemie_info_t *enemie_info);
t_tmp_fight initialize_fight(game_t *rpg, enemie_info_t *enemie_info, \
sfVector2f scale);
void end_fight(game_t *rpg, t_tmp_fight tmp, enemie_info_t *enemy_info);

void loot(inv_t **inv, int value);
//inv
scene_t *init_scene_inventory(void);
void detect_inv(game_t *rpg);
void display_inventory(game_t *rpg, inv_t **inv, sfRenderWindow *win);
text_t *init_life_text(text_t *text);
text_t *init_full_success_text(text_t *text);
text_t *init_multiple_success_text(text_t *text);
scene_t *init_inv_texts(scene_t *inv);

move_quest_t *check_travel_quest(game_t *rpg, move_quest_t *travel);
quest_log_t *init_quests(quest_log_t *quests);
bool check_region(sfVector2f view, move_quest_t *travel);
text_t **init_travels_texts(text_t **texts);
bool all_type_of_item(inv_t **inv);

void display_enemies(game_t *rpg);

sfRenderWindow *initialize_window(void);
void display_other(game_t *rpg, sfRenderWindow *win);

void make_zoom_before_fight(game_t *rpg);

//particles and rand
int random_int(int min, int max);
float random_float(float min, float max);
void snow_fall(game_t *rpg, snow_t **snow);
snow_t **init_snow(game_t *rpg);
void snow_display(snow_t *snow, game_t *rpg);
void snow_update(snow_t *snow);
snow_t *create_snow(void);
void free_snow(snow_t **snow);

void analyse_events(game_t *rpg);
void analyse_key_events(game_t *rpg);
void key_is_released(game_t *rpg);
sfVector2f execute_movement(game_t *rpg);

void update_fight_scene(game_t *rpg, enemie_info_t *enemie_info);

void mouse_button_is_pressed(game_t *rpg);

void reset_quests(quest_log_t *quests, game_t *rpg);
void reset_inventory(game_t *rpg);

inv_t *empty_inv_slot(inv_t *inv, char *filepath);
void destroy_particles(particles_t *particles);

void initialize_enemies(game_t *rpg);

void zoom_before_fight(game_t *rpg, enemie_info_t *enemie_info);

int check_boss_fight(game_t *rpg, enemie_info_t *enemie_info);
void switch_ennemies_turn_for_fight(game_t *rpg, enemie_info_t *enemie_info);
int continue_fight(game_t *rpg, enemie_info_t *enemie_info, int ret_player);
int proceed_enemy_turn(game_t *rpg, enemie_info_t *enemie_info, \
int ret_player);

void destroy_texts(text_t *text);

void check_boss_is_dead(game_t *rpg);

#endif /* !RPG_H_ */