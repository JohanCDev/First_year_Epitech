/*
** EPITECH PROJECT, 2021
** sandpile.h
** File description:
** sandpile.h
*/


#ifndef __TICTACTOE__
#define __TICTACTOE__

//-----NEEDED-INCLUDE------
#include <stdbool.h>
//-----MACROS--------------

#define ERROR_ARGUMENT "Invalid argument.\n"
#define P_ONE_VICTORY "Player 1 won!\n"
#define P_TWO_VICTORY "Player 2 won!\n"
#define DRAW "Draw\n"

//-----STRUCTURE-----------
typedef struct s_tic
{
    int *map;
    int size;
    char p_one;
    char p_two;
} tic_t;

//-----PROTOTYPES----------
//error_handling.c
int argument_handling(tic_t *tictac, int ac, char **av);

//print_map.c
void print_map(tic_t *tic, int jump);

//tool_functions.c
bool is_a_valid_character(char c);
bool str_is_num(char *str);
bool my_str_isfloat(char const *str);

//victory.c
bool check_victory(tic_t *tic, int turn);

//play_game.c
int play_game(tic_t *tic);

#endif