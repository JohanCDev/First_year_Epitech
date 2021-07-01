/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** display
*/

#include "mydb.h"
#include "my.h"
#include <string.h>

void normal_print(db_t *db)
{
    movie_t mov;

    for (int i = 0; i < db->size; i++) {
        mov = db->movies[i];
        my_printf("%i;\"%s\";", mov.id_movie, mov.title);
        my_printf("\"%s\";%i;", mov.synposis, mov.id_director);
        my_printf("\"%s\";%i;\"%s\"\n", mov.director, mov.id_type, mov.type);
    }
}

void show_print(db_t *db, int start, int how)
{
    movie_t mov;
    int count = 0;

    for (int i = start - 1; i < db->size && count < how; i++) {
        mov = db->movies[i];
        my_printf("%i;\"%s\";", mov.id_movie, mov.title);
        my_printf("\"%s\";%i;", mov.synposis, mov.id_director);
        my_printf("\"%s\";%i;\"%s\"\n", mov.director, mov.id_type, mov.type);
        count++;
    }
    char *str = strdup(str)
}