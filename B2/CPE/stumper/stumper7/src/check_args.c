/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_args
*/

#include "mydb.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

int get_size_array(char **array)
{
    int i = 0;

    for (; array[i]; i++);

    return (i);
}

movie_t put_infos_in_database(char **infos)
{
    movie_t movie = {0, NULL, NULL, 0, NULL, 0, NULL};

    movie.id_movie = atoi(infos[0]);
    movie.title = strdup(infos[1]);
    movie.synposis = strdup(infos[2]);
    movie.id_director = atoi(infos[3]);
    movie.director = strdup(infos[4]);
    movie.id_type = atoi(infos[5]);
    movie.type = strdup(infos[6]);
    if (movie.director == NULL || movie.synposis == NULL || \
    movie.title == NULL || movie.type == NULL || strlen(movie.director) > \
    DIRECTOR_MAX_LENGTH || strlen(movie.synposis) > SYNPOSIS_MAX_LENGTH || \
    strlen(movie.title) > TITLE_MAX_LENGTH || \
    strlen(movie.type) > TYPE_MAX_LENGTH) {
        movie.id_type = -84;
        return (movie);
    }
    return (movie);
}

int get_all_infos(char **array, db_t *database)
{
    char **infos = NULL;
    database->size = get_size_array(array);
    database->movies = malloc(sizeof(movie_t) * database->size);

    for (int i = 0; i < database->size; i++) {
        infos = my_strtok(array[i], ",\"");
        if (infos == NULL) {
            free_movies(database->movies, database->size);
            my_free_char_array(infos);
            return (-1);
        }
        database->movies[i] = put_infos_in_database(infos);
        if (database->movies[i].id_type == -84) {
            free_movies(database->movies, database->size);
            my_free_char_array(infos);
            return (-1);
        }
        my_free_char_array(infos);
    }
    return (0);
}

int get_data(char *filepath, db_t *database)
{
    my_file_t file = {0, NULL, 0};
    char **array = NULL;

    if (my_open_and_read(&file, filepath) == -1)
        return (-1);
    array = my_strtok(file.buffer, "\n");
    if (array == NULL)
        return (-1);
    if (get_all_infos(array, database) == -1)
        return (-1);
    if (database == NULL)
        return (-1);
    my_close_file(&file);
    return (0);
}

db_t *check_args(int ac, char **av)
{
    db_t *database = NULL;

    if (ac != 3)
        return (NULL);
    if ((database = malloc(sizeof(db_t))) == NULL)
        return (NULL);
    if (get_data(av[1], database) == -1) {
        free(database);
        return (NULL);
    }
    return (database);
}