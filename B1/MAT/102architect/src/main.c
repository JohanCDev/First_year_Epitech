/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-102architect-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include "architect.h"

s_coord_point *update_coordinates(double x, double y)
{
    s_coord_point *point = malloc(sizeof(s_coord_point));

    point->x = x;
    point->y = y;
    return (point);
}

int transfo_values(char **argv, double *matrix, s_coord_point *current_point, int i)
{
    char transfo = get_transformation(argv[i]);
    double x = atof(argv[i + 1]);
    double y = atof(argv[i + 2]);

    if (transfo == 't') {
        do_translation(current_point, matrix, x, y);
        printf("Translation along vector (%.0f, %.0f)\n", x, y);
    }
    if (transfo == 'z') {
        do_zoom(current_point, matrix, x, y);
        printf("Scaling by factors %.0f and %.0f\n", x, y);
    }
    return (3);
}

int transfo_deg(char **argv, double *matrix, s_coord_point *current_point, int i)
{
    char transfo = get_transformation(argv[i]);
    double degrees = atof(argv[i + 1]);

    if (transfo == 'r') {
        do_rotation(current_point, matrix, degrees);
        printf("Rotation by a %.0f degree angle\n", degrees);
    }
    if (transfo == 's') {
        do_symmetry(current_point, matrix, degrees);
        printf("Reflection over an axis with an inclination angle of %.0f degrees\n", degrees);
    }
    return (2);
}

void detect_the_transfo(char **argv, double *matrix, s_coord_point *current_point)
{
    int i = 3;
    char c = 0;

    while (argv[i]) {
        c = get_transformation(argv[i]);
        if (c == 't' || c == 'z')
            i += transfo_values(argv, matrix, current_point, i);
        else if (c == 'r' || c == 's')
            i += transfo_deg(argv, matrix, current_point, i);
    }
}

int main(int argc, char **argv)
{
    double matrix[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    s_coord_point *current_point; 

    if (check_arguments(argc, argv) == 84) {
        my_put_error("Incorrect arguments\n");
        return (84);
    }
    current_point = update_coordinates(atof(argv[1]), atof(argv[2]));
    detect_the_transfo(argv, matrix, current_point);
    display_matrix(matrix);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(argv[1]), atof(argv[2]), current_point->x, current_point->y);
    return (0);
}