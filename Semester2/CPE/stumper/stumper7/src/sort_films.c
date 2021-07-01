/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** sort_films
*/

#include "mydb.h"
#include <stdlib.h>
#include <string.h>

void switch_id(db_t *database, int field, int j)
{
    switch (field) {
    case ID_FIELD:
        swap_numbers(&database->movies[j].id_movie, \
        &database->movies[j + 1].id_movie);
        break;
    case ID_DIRECTOR_FIELD:
        swap_numbers(&database->movies[j].id_director, \
        &database->movies[j + 1].id_director);
        break;
    case ID_TYPE_FIELD:
        swap_numbers(&database->movies[j].id_type, \
        &database->movies[j + 1].id_type);
        break;
    }
}

void switch_str(db_t *database, int field, int j)
{
    switch (field) {
    case TITLE_FIELD:
        swap_str(&database->movies[j].title, \
        &database->movies[j + 1].title);
        break;
    case DIRECTOR_FIELD:
        swap_str(&database->movies[j].director, \
        &database->movies[j + 1].director);
        break;
    case SYNPOSIS_FIELD:
        swap_str(&database->movies[j].synposis, \
        &database->movies[j + 1].synposis);
        break;
    case TYPE_FIELD:
        swap_str(&database->movies[j].type, \
        &database->movies[j + 1].type);
        break;
    }
}

void adapt_types(db_t *database, int col, int type, int j)
{
    if (type == 1)
        switch_id(database, col, j);
    else
        switch_str(database, col, j);
}

void my_sort_array(db_t *database, int col, int type)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < database->size; i++) {
        for (j = 0; j < database->size - i - 1; j++) {
            adapt_types(database, col, type, j);
        }
    }
}

void sort_films(db_t *database, int col_to_sort)
{
    if (is_an_id(col_to_sort) == 1)
        my_sort_array(database, col_to_sort, 1);
    else
        my_sort_array(database, col_to_sort, 2);
}