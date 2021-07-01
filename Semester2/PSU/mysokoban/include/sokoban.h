/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <ncurses.h>

typedef struct s_check_map {
    int nb_o;
    int nb_p;
    int nb_x;
} check_map_t;

typedef struct s_lose {
    int nb_blocked_x;
    int nb_x;
} lose_t;

typedef struct s_sokoban {
    char **map;
    char **base_map;
    int width;
    int height;
    int nb_x;
    int pos_x;
    int pos_y;
    int ret;
} sokoban_t;

//helper_map.c
void count_lines(char *buffer, sokoban_t *sokoban);
int get_width_of_map(char *buffer, int i, sokoban_t *sokoban);
void change_map_add_o(sokoban_t *sokoban);
check_map_t count_specials_chars(check_map_t numbers_ch, char *buffer, int i);
int count_o_base(char **map);

//helper_position.c
void update_position_p(sokoban_t *sokoban, int i, int j);
void get_position_p(sokoban_t *sokoban);

//intitialize.c
int check_map(char *buffer);
int add_map_in_struct(sokoban_t *sokoban, int size, int fd);
char **get_map(char *filepath, sokoban_t *sokoban);
sokoban_t *initialize(int argc, char **argv, int print);

//movements.c
void move_up(sokoban_t *sokoban);
void move_down(sokoban_t *sokoban);
void move_left(sokoban_t *sokoban);
void move_right(sokoban_t *sokoban);

//end_game.c
int verify_nb_o(sokoban_t *sokoban, int i, int j, int nb_o);
void check_if_game_end(sokoban_t *sokoban);

//do_game.c
void act_on_game(sokoban_t *sokoban);
void display_game(sokoban_t *sokoban);
void print_map(sokoban_t *sokoban);
int switch_key(int key, sokoban_t *sokoban);

//initialize_ncurses
void initialize_ncurses(void);

//helper.c
char **copy_array(char **array);
int get_nb_x(char **map);
void print_help(int print);

//check_loss_game.c
int check_if_lose(sokoban_t *sokoban);


#endif