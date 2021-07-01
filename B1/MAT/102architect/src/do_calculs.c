/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-102architect-johan.chrillesen
** File description:
** calculs
*/

#include "my.h"
#include "architect.h"
#include <math.h>

void do_translation(s_coord_point *point, double *matrix, double x, double y)
{
    matrix[2] += x;
    matrix[5] += y;
    point->x += x;
    point->y += y;
}

void do_zoom(s_coord_point *point, double *matrix, double x, double y)
{
    matrix[0] *= x;
    matrix[4] *= y;
    point->x *= x;
    point->y *= y;
}

void do_rotation(s_coord_point *point, double *matrix, double degrees)
{
    double *rotation = 0;
    double tempo = 0;
    double x = 0;
    double y = 0;

    x = cos(((degrees * M_PI) / 180));
    y = sin(((degrees * M_PI) / 180));
    rotation = do_matrix_rotation(update_coordinates(x, y), matrix);
    matrix1_factor_matrix2(matrix, rotation);
    tempo = point->x;
    point->x = tempo * rotation[0] + point->y * rotation[1];
    point->y = tempo * rotation[3] + point->y * rotation[4];

}

void do_symmetry(s_coord_point *point, double *matrix, double degrees)
{
    double *rotation = 0;
    double tempo = 0;
    double x = 0;
    double y = 0;

    x = cos(2 * ((degrees * M_PI) / 180));
    y = sin(2 * ((degrees * M_PI) / 180));
    rotation = do_matrix_symmetry(update_coordinates(x, y), matrix);
    matrix1_factor_matrix2(matrix, rotation);
    tempo = point->x;
    point->x = tempo * rotation[0] + point->y * rotation[1];
    point->y = tempo * rotation[3] + point->y * rotation[4];
}