/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** mydb
*/

#ifndef __MY_DB__
#define __MY_DB__

//-----NEEDED-INCLUDE------
#include <stdbool.h>
#include <stdio.h>
//-----MACROS--------------

#define TITLE_MAX_LENGTH 32
#define SYNPOSIS_MAX_LENGTH 128
#define DIRECTOR_MAX_LENGTH 16
#define TYPE_MAX_LENGTH 16

#define ID_FIELD 0
#define TITLE_FIELD 1
#define SYNPOSIS_FIELD 2
#define ID_DIRECTOR_FIELD 3
#define DIRECTOR_FIELD 4
#define ID_TYPE_FIELD 5
#define TYPE_FIELD 6



//-----STRUCTURE-----------

typedef struct argument_s
{
    int show_cmd;
} argument_t;

typedef struct movie_s {
    int id_movie;
    char *title;
    char *synposis;
    int id_director;
    char *director;
    int id_type;
    char *type;
} movie_t;

typedef struct db_s {
    movie_t *movies;
    int size;
} db_t;

//-----PROTOTYPES----------
//db_management.c
int db_management(db_t *db, char **av);

//get_input.c
char *get_input(FILE *stream);

//my_frees.c
void my_free_str(char *str);
void free_movies(movie_t *movies, int size);
void free_db(db_t *db);

//check_args.c
db_t *check_args(int ac, char **av);

//get_cmd.c
bool check_id_fields(movie_t movie, int field, int id);
bool check_char_fields(movie_t movie, int field, char *value);
bool is_a_good_caracteristique(movie_t movie, int field, char *value);
db_t *db_get_cmd(db_t *db, int field, char *value);
char *get_get_value(char *line);

//display.c
void normal_print(db_t *db);
void show_print(db_t *db, int start, int how);

//tool_functions.C
int get_field_from_title(char *field_title);
int where_is_str_in_str(char *str, char *to_find);
bool is_an_id(int field);

//sort_fils.c
void sort_films(db_t *database, int col_to_sort);

//sort_management.c
int sort_management(db_t *db, char **av);

//swap_func.c
void swap_numbers(int *int_1, int *int_2);
void swap_str(char **str1, char **str2);

#endif