/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef NAVY_H
#define NAVY_H
#include <signal.h>
#include <stdio.h>
#define is_other(c) (c == ':') ? 1 : 0
#define is_valid_num(c) (c >= '1' && c <= '8') ? 1 : 0

typedef struct t_glob_var {
    int pid_enemy;
    int nb_sig1;
} s_glob_var;

typedef struct t_coords_boat {
    int x0;
    int x1;
    int y0;
    int y1;
} s_coords_boat;

typedef struct t_player_maps {
    char **map_p1;
    char **map_p2;
} s_player_maps;

char **create_map(void);
char **create_boat(char *coordinates, char **map);
int check_availabality(s_coords_boat boat, char **map);

char **place_five_boat(char **map, char *position);
char **place_four_boat(char **map, char *position);
char **place_three_boat(char **map, char *position);
char **place_two_boat(char **map, char *position);

s_coords_boat init_coords_boat(int x0, int x1, int y0, int y1);

int connect_player(int argc, char **argv);
int get_enemy_pid(int enemy_pid);
void handler1(int signal_number, siginfo_t *info, void *context);
void handler2(int signal_number, siginfo_t *info, void *context);
int initialize_signal(void);
void send_signals(int nb);
void wait_signals(void);
void display_maps(s_player_maps maps, int player, int round);

int get_file(char *filename);
char *read_file(int fd, char *filepath);
int check_file(char **placements);
char *get_filepath(char *filename);
int check_placements(char *str);
char *get_line_of_file(char *filepath, int i_line);

int check_end_game(char **map);

void play(s_player_maps maps, int player, int other_player_pid);
char **fill_shoot(char **map, int char_x, int char_y);
char **fill_target(char **map, char *input, int hit);

#endif