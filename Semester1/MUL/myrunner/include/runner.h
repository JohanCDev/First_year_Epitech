/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** runner
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef RUNNER_H
#define RUNNER_H
#define MOVE_RECT 2
#define MOVE_SPRITE 1
#define DRAW_SPRITE 0

typedef struct object_t {
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f position;
} object_s;

typedef struct linked_list linked_list_s;
struct linked_list {
    object_s *enemy;
    linked_list_s *next;
};

typedef struct win_t {
    sfVector2f size;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} win_s;

typedef struct score_t {
    sfText *text;
    sfFont *font;
    int score;
} score_s;

typedef struct enemies_t {
    object_s *enemy1;
    object_s *enemy2;
    object_s *enemy3;
    object_s *enemy4;
} enemies_s;

typedef struct game_t {
    object_s *player;
    object_s *player_win;
    object_s *big_bg;
    object_s *mid_bg;
    object_s *front_bg;
    object_s *ground;
    object_s *background_over;
    linked_list_s *enemy;
    enemies_s *enemies;
    win_s window;
    sfMusic *music;
    sfMusic *win_music;
    sfMusic *game_over;
    sfMusic *jump_sound;
    score_s score;
    sfText *your_score;
    int read_map;
    char *map;
    int win;
    int ret;
} game_s;

typedef struct {
    int nb_lines;
    int nb_columns;
    int size;
    int ret;
    int fd;
}info_map;

//animations.c
sfVector2f change_position(float pos_x, float pos_y);
void move_rect(sfIntRect *rect, int offset, int max_value);

//create_file.c
char *populate_array(info_map map_info, char *buff);
info_map get_file_size(info_map map_info, char const *filepath);
info_map count(info_map map_info, char *buff);
void free_and_close(info_map map_info, char *buff);
game_s *create_map(game_s *game, char *filepath);

//create.c
object_s *create_object(const char *path, sfVector2f pos, sfIntRect rect, \
sfVector2f size);
game_s *create_parallax(game_s *game);
win_s create_window(char const *name);
void create_score_label(char const *filepath, game_s *game);

//destroy.c
void destroy_musics(game_s *game);
void destroy_object(object_s *object);
void destroy_all(game_s *game, sfClock *clock);

//display.c
void detect_obstacles(game_s *game, linked_list_s *list);
void display_obstacles(game_s *game);
void do_parallax(game_s *game);
sfText *set_score(game_s *game);
void display_all(game_s *game);

//finish_game.c
void setup_final_text(game_s *game);
void initialize_dino(object_s *dino, sfVector2f pos_dino);
void display_everything(game_s *game);
void display_end_screen(game_s *game);
void finish_game(game_s *game);

//game.c
void switch_key_pressed(game_s *game);
void switch_event(game_s *game);
void animate_game(game_s *game, sfClock *clock, sfClock *obstacles_clock, \
int read_map);
int start_game(game_s *game);

//helper.c
sfVector2f create_vector(int x, int y);
sfIntRect create_rect(int top, int left, int width, int height);

//init_linked_list.c
void add_in_linked_list(game_s *game, object_s *object);
void print_obstacle(game_s *game);

//initialize_project.c
int detect_args(char **argv, game_s *game, int display);
int check_params(int argc, char **argv, game_s *game, int display);
int check_problems(int argc, char **argv, game_s *game, int display);

//jump.c
void display_jump(game_s *game, int i, int up);
void jump(game_s *game);

//main.c
int switch_problems(int argc, char **argv, game_s *game, int display);
void initialize_music(game_s *game);

//obstacles.c
void switch_map_part2(game_s *game);
void switch_map(game_s *game);
void do_obstacles(game_s *game, int read_map);

#endif