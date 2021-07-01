/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-johan.chrillesen
** File description:
** verify_inputs
*/

#include "matchstick.h"
#include "my.h"

int verification_if_valid_number(char *line, match_t *match, int line_removing)
{
    if (my_getnbr(line) > match->nb_sticks_max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n", \
        match->nb_sticks_max);
        free(line);
        return (-1);
    }
    if (!(my_getnbr(line) > 0)) {
        my_printf("Error: you have to remove at least one match\n");
        free(line);
        return (-1);
    } else if (my_getnbr(line) > match->board[line_removing - 1]) {
        my_printf("Error: not enough matches on this line\n");
        free(line);
        return (-1);
    }
    return (0);
}

int verification_remove(match_t *match, char *line, int line_removing)
{
    if (!my_str_isnum(line)) {
        my_printf("Error: invalid input (positive number expected)\n");
        free(line);
        return (-1);
    }
    if (verification_if_valid_number(line, match, line_removing) == -1)
        return (-1);
    return (0);
}

int get_matches(match_t *match, int line_removed)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int nbr = 0;

    while (1) {
        my_printf("Matches: ");
        if ((read = getline(&line , &len, stdin)) == -1) {
            free(line);
            return (-2);
        }
        line[my_strlen(line) - 1] = 0;
        if ((match->ret = verification_remove(match, line, line_removed)) == 0)
            break;
        else
            return (-1);
    }
    nbr = my_getnbr(line);
    free(line);
    return (nbr);
}

int verify_line_remove(int nb_lines, char *line)
{
    if (!my_str_isnum(line)) {
        my_printf("Error: invalid input (positive number expected)\n");
        free(line);
        return (-1);
    } else if (!(my_getnbr(line) >= 1 && my_getnbr(line) <= nb_lines)) {
        my_printf("Error: this line is out of range\n");
        free(line);
        return (-1);
    }
    return (0);
}

int get_line_remove(match_t *match)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int nbr = 0;

    while (1) {
        my_printf("Line: ");
        if ((read = getline(&line , &len, stdin)) == -1) {
            free(line);
            return (-2);
        }
        line[my_strlen(line) - 1] = 0;
        if (verify_line_remove(match->nb_lines, line) == -1) {
            return (-1);
        } else
            break;
    }
    nbr = my_getnbr(line);
    free(line);
    return (nbr);
}