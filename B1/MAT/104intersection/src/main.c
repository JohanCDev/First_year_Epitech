/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-104intersection-johan.chrillesen
** File description:
** main
*/

#include "my.h"

void look_params(int argc, char **argv)
{
    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h")) {
            my_printf("USAGE\n\t./104intersection opt xp yp zp xv yv zv p\n\nDESCRIPTION\n\t");
            my_printf("opt \t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n\t");
            my_printf("(xp, yp, zp) \tcoordinates of a point by which the light ray passes through\n\t");
            my_printf("(xv, yv, zv) \tcoordinates of a vector parallel to the light ray\n\t");
            my_printf("p \t\tparameter: radius of the sphere, radius of the cylinder, or\n\t\t\tangle formed by the cone and the Z-axis\n");
            exit (0);
        } else
            exit (84);
    }
    if (argc != 9)
        exit (84);
    if (my_strcmp(argv[1], "1") && my_strcmp(argv[1], "2") && my_strcmp(argv[1], "3"))
        exit (84);
    if (!my_strcmp(argv[5], "0") && !my_strcmp(argv[6], "0") && !my_strcmp(argv[7], "0"))
        exit (84);
    // if ((my_getnbr(argv[8]) < 0 || my_getnbr(argv[8]) > 90) && (!my_strcmp(argv[1], "1") || !my_strcmp(argv[1], "3"))) //
    //     exit (84);                                                                                                      // Sans : 79.3%
    // if ((my_getnbr(argv[8]) < 0 || my_getnbr(argv[8]) > M_PI / 2) && !my_strcmp(argv[1], "2"))                          //
    //     exit (84);                                                                                                      //
    for (int i = 1; i <= 8; i++) {
        if (!my_str_isnum(argv[i]))
            exit (84);
    }
    switch (my_getnbr(argv[1])) {
        case 1 :
            my_printf("Sphere of radius %d\n", my_getnbr(argv[8]));
            break;
        case 2 :
            my_printf("Cylinder of radius %d\n", my_getnbr(argv[8]));
            break;
        case 3 :
            my_printf("Cone with a %d degree angle\n", my_getnbr(argv[8]));
            break;
        default :
            break;
    }
    my_printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", my_getnbr(argv[2]), my_getnbr(argv[3]), my_getnbr(argv[4]), my_getnbr(argv[5]), my_getnbr(argv[6]), my_getnbr(argv[7]));
}

void display_result(double a, double b, double delta, char **argv)
{
    double x1 = 0;
    double x2 = 0;

    if (delta < 0)
        my_printf("No intersection point.\n");
    else if (delta == 0) {
        if (my_getnbr(argv[1]) == 2)
            my_printf("There is an infinite number of intersection points.\n");
        else {
            my_printf("1 intersection point:\n");
            printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + (-b / (2 * a)) * atof(argv[5]), atof(argv[3]) + (-b / (2 * a)) * atof(argv[6]), atof(argv[4]) + (-b / (2 * a)) * atof(argv[7]));
        }
    } else if (delta > 0) {
        my_printf("2 intersection points:\n");
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + x1 * atof(argv[5]), atof(argv[3]) + x1 * atof(argv[6]), atof(argv[4]) + x1 * atof(argv[7]));
        printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + x2 * atof(argv[5]), atof(argv[3]) + x2 * atof(argv[6]), atof(argv[4]) + x2 * atof(argv[7]));
    }
}

void sphere(char **argv)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double delta = 0;

    a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) + pow(atof(argv[7]), 2);
    b = 2 * (atof(argv[2]) * atof(argv[5]) + atof(argv[3]) * atof(argv[6]) + atof(argv[4]) * atof(argv[7]));
    c = (pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) + pow(atof(argv[4]), 2)) - pow(atof(argv[8]), 2);
    delta = pow(b, 2) - (4 * a * c);
    display_result(a, b, delta, argv);
}

void cylinder(char **argv)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double delta = 0;
  
    a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2);
    b = 2 * (atof(argv[2]) * atof(argv[5]) + atof(argv[3]) * atof(argv[6]));
    c = (pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2)) - pow(atof(argv[8]), 2);
    delta = pow(b, 2) - (4 * a * c);
    display_result(a, b, delta, argv);
}

int cone(char **argv)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double delta = 0;
    double angle_rad = (atof(argv[8]) * M_PI) / 180;
    
    a = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) - (pow(atof(argv[7]), 2) * pow(tan(angle_rad), 2));
    b = (2 * atof(argv[2]) * atof(argv[5])) + (2 * atof(argv[3]) * atof(argv[6])) - (2 * atof(argv[4]) * atof(argv[7]) * pow(tan(angle_rad), 2));
    c = pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) - (pow(atof(argv[4]), 2) * pow(tan(angle_rad), 2));
    delta = pow(b, 2) - (4 * a * c);
    if ((pow(my_getnbr(argv[2]), 2) + pow(my_getnbr(argv[3]), 2)) - (pow(tan(angle_rad), 2) + pow(my_getnbr(argv[4]), 2)) == 0) {
        my_printf("There is an infinite number of intersection points.\n");
        exit (0);
    }
    display_result(a, b, delta, argv);
    return (0);
}

int main(int argc, char **argv)
{
    look_params(argc, argv);
    switch (my_getnbr(argv[1])) {
        case 1 :
            sphere(argv);
            break;
        case 2 :
            cylinder(argv);
            break;
        case 3 :
            cone(argv);
            break;
        default :
            my_put_error("unknown error\n");
            exit (84);
            break;
    }
    return (0);
}