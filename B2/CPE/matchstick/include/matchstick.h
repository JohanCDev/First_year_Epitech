/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** sokoban
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

typedef struct s_match {
    int *board;
    int *base_board;
    int nb_sticks_max;
    int nb_lines;
    int ret;
} match_t;

//computer_turn.c
int calculate_nb_sticks(match_t *match);
void play_computer(match_t *match);

//initialize.c
int check_parameters(int argc, char **argv);
int init_int_board(match_t *match);
match_t *initialize_game(int argc, char **argv);

//play_game.c
int check_end_game(int *board, int nb_lines);
int play_game(match_t *match);

//player_turn.c
int make_player_turn(match_t *match);
int ask_and_verify(match_t *match);

//print_game_board.c
void print_game_board(match_t *match);
void print_stars(int nb_stars);
void print_line(int nb_line, int current_line, match_t *match);
void print_sticks(int nb_sticks);
void display_spaces(int nb_spaces);

//free_all.c
void free_all(match_t *match);

//verify_inputs.c
int get_line_remove(match_t *match);
int verify_line_remove(int nb_lines, char *line);
int get_matches(match_t *match, int line_removed);
int verification_remove(match_t *match, char *line, int line_removing);
int verification_if_valid_number(char *line, match_t *match, int line_removing);

#endif