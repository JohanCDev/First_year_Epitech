/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-johan.chrillesen
** File description:
** initialize
*/

#include "my.h"
#include "matchstick.h"

int check_parameters(int argc, char **argv)
{
    if (!(argc == 3 && \
    (my_getnbr(argv[1]) > 1 && my_getnbr(argv[1]) < 100) && \
    (my_getnbr(argv[2]) > 0))) {
        my_put_error("Bad arguments, try with ./matchstick nb_lines ");
        my_put_error("(between 2 and 99 included) nb_max_stick (>0)\n");
        return (84);
    }
    return (0);
}

int init_int_board(match_t *match)
{
    if ((match->board = malloc(sizeof(int) * match->nb_lines)) == NULL || \
        (match->base_board = malloc(sizeof(int) * match->nb_lines)) == NULL)
        return (-1);
    for (int i = 0; i < match->nb_lines; i++) {
        match->board[i] = i * 2 + 1;
        match->base_board[i] = i * 2 + 1;
    }
    return (0);
}

match_t *initialize_game(int argc, char **argv)
{
    match_t *match = NULL;

    if ((match = malloc(sizeof(match_t))) == NULL)
        return (NULL);
    match->ret = 0;
    match->nb_lines = 0;
    match->nb_sticks_max = 0;
    if ((match->ret = check_parameters(argc, argv)) == 84) {
        free(match);
        return (NULL);
    }
    match->nb_lines = my_getnbr(argv[1]);
    match->nb_sticks_max = my_getnbr(argv[2]);
    if (init_int_board(match) == -1)
        return (NULL);
    return (match);
}