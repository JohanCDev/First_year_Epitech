/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_frees
*/

#include "mydb.h"
#include <stdlib.h>
#include "my.h"

void my_free_str(char *str)
{
    if (str) {
        free(str);
        str = NULL;
    }
}

void free_movies(movie_t *movies, int size)
{
    for (int i = 0; i < size; i++) {
        my_free_str(movies[i].title);
        my_free_str(movies[i].synposis);
        my_free_str(movies[i].director);
        my_free_str(movies[i].type);
    }
    if (movies) {
        free(movies);
        movies = NULL;
    }
}

void free_db(db_t *db)
{
    if (db->movies)
        free_movies(db->movies, db->size);
    free(db);
}