/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** get_cmd
*/

#include "mydb.h"
#include <stdlib.h>
#include <string.h>
#include "my.h"

bool check_id_fields(movie_t movie, int field, int id)
{
    switch (field) {
    case ID_DIRECTOR_FIELD:
        return (movie.id_director == id);
        break;
    case ID_FIELD:
        return (movie.id_movie == id);
        break;
    case ID_TYPE_FIELD:
        return (movie.id_type == id);
        break;
    }
    return (false);
}

bool check_char_fields(movie_t movie, int field, char *value)
{
    switch (field) {
    case TITLE_FIELD:
        return (strcmp(movie.title, value) == 0 ? true : false);
        break;
    case SYNPOSIS_FIELD:
        return (strcmp(movie.synposis, value) == 0 ? true : false);
        break;
    case DIRECTOR_FIELD:
        return (strcmp(movie.director, value) == 0 ? true : false);
        break;
    case TYPE_FIELD:
        return (strcmp(movie.type, value) == 0 ? true : false);
        break;
    }
    return (false);
}

bool is_a_good_caracteristique(movie_t movie, int field, char *value)
{
    bool is_id = is_an_id(field);
    int id = -1;

    if (is_id) {
        id = atoi(value);
        if (id <= 0)
            return (false);
        return (check_id_fields(movie, field, id));
    } else
        return (check_char_fields(movie, field, value));
}

db_t *db_get_cmd(db_t *db, int field, char *value)
{
    db_t *new_db = malloc(sizeof(*new_db));
    int new_length = 0;
    int j = 0;

    if (!new_db)
        return (NULL);
    for (int i = 0; i < db->size; i++)
        if (is_a_good_caracteristique(db->movies[i], field, value))
            new_length ++;
    new_db->size = new_length;
    new_db->movies = malloc(sizeof(*new_db->movies) * new_length);
    if (!new_db->movies)
        return (NULL);
    for (int i = 0; i < db->size; i++) {
        if (is_a_good_caracteristique(db->movies[i], field, value)) {
            new_db->movies[j] = db->movies[i];
            j++;
        }
    }
    return (new_db);
}

char *get_get_value(char *line)
{
    int begin = -1;
    int end = -1;
    int count = 0;
    char *value;

    for (int i = 0; line[i] && count < 2; i++) {
        if (line[i] == '\'') {
            count++;
            begin = (count == 1 ? i + 1 : begin);
            end = (count == 2 ? i : end);
        }
    }
    if (begin == -1 || end == -1)
        return (NULL);
    value = my_strndup(line + begin, end - begin);
    return (value);
}