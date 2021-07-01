/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** generator
*/

#ifndef __GENERATOR__
#define __GENERATOR__

//------NEEDED-INCLUDE----
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//---------MACROS---------

//-------STRUCTURES-------
typedef struct s_generator {
     int *maze;
     int height;
     int width;
     int ret;
} generator_t;

typedef struct s_create {
    int x1;
    int y1;
    int x2;
    int y2;
    int dx;
    int dy;
    int dir;
    int count;
} create_t;

//-------PROTOTYPES-------
//initialize_generator.c
void initialize_maze(generator_t *gen);
generator_t *initialize_generation(int argc, char **argv);

//helpers.c
bool my_str_isnum(char const *str);
void free_all(generator_t *gen);

void create_maze(generator_t *gen);
void print_maze(int *maze, int width, int height);

#endif