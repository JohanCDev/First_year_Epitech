/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** generator
*/

#ifndef __SOLVER__
#define __SOLVER__

//------NEEDED-INCLUDE----
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//---------MACROS---------

//-------STRUCTURES-------
typedef struct s_solver {
     char *maze;
     int height;
     int width;
     int ret;
} solver_t;

typedef struct s_dir {
     int dir;
     int count;
     int x;
     int y;
     int dx;
     int dy;
     int forward;
     int count;
} dir_t;

//-------PROTOTYPES-------
char *solve_maze(char *maze, int width, int height);
int check_maze(solver_t *solver, int size, int fd);
int check_shape(solver_t *solver, char *maze);

#endif