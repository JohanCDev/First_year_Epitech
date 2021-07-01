/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef ARCHITECT
#define ARCHITECT

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct t_coord_point {
    double x;
    double y;
} s_coord_point;
char get_transformation(char *str);
void do_translation(s_coord_point *point, double *matrix, double x, double y);
void do_zoom(s_coord_point *point, double *matrix, double x, double y);
void do_rotation(s_coord_point *point, double *matrix, double degrees);
void do_symmetry(s_coord_point *point, double *matrix, double degrees);
int check_transformations(char **transfo, int i);
int check_arguments(int nb_args, char **argv);
s_coord_point *update_coordinates(double x, double y);
int transfo_values(char **argv, double *matrix, s_coord_point *current_point, int i);
int transfo_deg(char **argv, double *matrix, s_coord_point *current_point, int i);
void detect_the_transfo(char **argv, double *matrix, s_coord_point *current_point);
double *do_matrix_symmetry(s_coord_point *point, double *matrix);
double *do_matrix_rotation(s_coord_point *point, double *matrix);
double *matrix1_factor_matrix2(double *matrix, double *matrix_rotation);

#endif