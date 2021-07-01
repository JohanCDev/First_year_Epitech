/*
** EPITECH PROJECT, 2020
** bsnavy
** File description:
** create_map
*/

#include "my.h"
#include "navy.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 10);

    if (map == NULL)
        return ((char **) "ERROR");
    map[0] = my_strdup(" |A B C D E F G H\n");
    map[1] = my_strdup("-+---------------\n");
    map[2] = my_strdup("1|. . . . . . . .\n");
    map[3] = my_strdup("2|. . . . . . . .\n");
    map[4] = my_strdup("3|. . . . . . . .\n");
    map[5] = my_strdup("4|. . . . . . . .\n");
    map[6] = my_strdup("5|. . . . . . . .\n");
    map[7] = my_strdup("6|. . . . . . . .\n");
    map[8] = my_strdup("7|. . . . . . . .\n");
    map[9] = my_strdup("8|. . . . . . . .\n");
    return (map);
}