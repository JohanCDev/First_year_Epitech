/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** my_str_to_wordtab
*/

#include "solver.h"

int	nb_mot(char *str, char sep)
{
    int	i = 0;
    int	nb = 1;

    while (str[i]) {
        if (str[i] == sep)
            nb++;
        i++;
    }
    return (nb);
}

char **my_str_to_wordtab(char *str, char sep)
{
    char **tab = NULL;
    int	i = 0;
    int	j = 1;

    if ((tab = \
        malloc((nb_mot(str, sep) + 1) * sizeof(char*))) == NULL)
        return (NULL);
    tab[nb_mot(str, sep)] = NULL;
    tab[0] = str;
    while (str[i]) {
        if (str[i] == sep) {
            str[i++] = 0;
            tab[j] = &str[i];
            j++;
        }
        i++;
    }
    return (tab);
}

void my_show_wordtab(char **tab)
{
    int	line = 0;
    int column = 0;

    while (tab[line] != NULL) {
        column = 0;
        while (tab[line][column]) {
            if (tab[line][column] == 'X')
                printf("N");
            column++;
        }
        line++;
    }
}
