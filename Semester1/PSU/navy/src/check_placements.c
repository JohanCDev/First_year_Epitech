/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** check_map
*/

#include "my.h"
#include "navy.h"

char **populate_placements(char *str, char **placements)
{
    int x = 0;
    int y = 0;
    int k = 0;

    while (y < 4) {
        while (str[k] != '\n' && k < 31) {
            placements[y][x++] = str[k];
            k++;
        }
        placements[y][x + 1] = '\0';
        k++;
        y++;
        x = 0;
    }
    return (placements);
}

int get_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int check_file(char **placements)
{
    for (int i = 0; i < 4; i++) {
        if ((get_abs(placements[i][2] - placements[i][5]) != i + 1 && \
        (placements[i][3] - placements[i][6]) == 0) || \
        (get_abs(placements[i][3] - placements[i][6]) != i + 1 && \
        (placements[i][2] - placements[i][5]) == 0) || ((placements[i][2] \
        - placements[i][5]) && (placements[i][3] - placements[i][6])))
            return (84);
        if (!((placements[i][2] >= 'A' && placements[i][2] <= 'H') && \
        (placements[i][3] >= '1' && placements[i][3] <= '8') && \
        (placements[i][5] >= 'A' && placements[i][5] <= 'H') && \
        (placements[i][6] >= '1' && placements[i][6] <= '8')))
            return (84);
    }
    return (0);
}

int check_placements(char *str)
{
    char **placements = malloc(sizeof(char *) * 4);

    for (int i = 0; i < 4; i++)
        placements[i] = malloc(sizeof(char) * 8);
    placements = populate_placements(str, placements);
    return (check_file(placements));
}