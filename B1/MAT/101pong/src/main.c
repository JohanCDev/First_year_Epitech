/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-101pong-tanguy.bellicha
** File description:
** vectors
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int get_abs(int nb)
{
    if (nb >= 0)
        return (nb);
    else
        return (-nb);
}

int my_put_float(float nbr)
{
    int superior = (int)nbr;
    double temp = (nbr * 100) - (superior * 100);
    double floater = (int)temp;
    int is_neg = 1;

    if (superior < 0)
        is_neg = -1;
    floater *= is_neg;
    my_put_nbr(superior);
    my_putchar('.');
    if (floater < 10 && floater != 0)
        my_put_nbr(floater * 10);
    else if (floater >= 10 && floater != 0) {
        if (((floater - (floater * 10)) >= 5))
            floater = floater + 1;
        my_put_nbr(floater);
    }
    else
        my_putstr("00");
    return (0);
}

void print_result(float vector_x, float vector_y, float vector_z, int time, float x1, float y1, float z1)
{
    my_putstr("The velocity vector of the ball is:\n(");
    my_put_float(vector_x); my_putstr(", ");
    my_put_float(vector_y); my_putstr(", ");
    my_put_float(vector_z); my_putstr(")\n");
   
    my_putstr("At time t + "); my_put_nbr(time); my_putstr(", ball coordinates will be:\n(");
    my_put_float(x1 + vector_x * ((float) time)); my_putstr(", ");
    my_put_float(y1 + vector_y * ((float) time)); my_putstr(", ");
    my_put_float(z1 + vector_z * ((float) time)); my_putstr(")\n");
}

int main(int argc, char **argv)
{
    float x0;
    float y0;
    float z0;
    float x1;
    float y1;
    float z1;
    int time;
    float vector_x;
    float vector_y;
    float vector_z;
    float angle_rad;
    float angle_degrees;

    if (argc > 8) {
        my_put_error("Too much arguments\n");
        return (84);
    }
    if (argc < 8) {
        my_put_error("Not enough arguments\n");
        return (84);
    }
    for (int i = 1; i <= 6; i++) {
        if (!my_str_isnum(argv[i]) && !my_str_isfloat(argv[i])) {
            my_put_error("Incorrect argument\n");
            return (84);  
        }
    }
    if (my_isneg(my_getnbr(argv[7]))) {
        my_put_error("Time shift is negative\n");
        return (84);
    }
    if (my_str_isnum(argv[7]) == 0) {
        my_put_error("Time shift is not a number\n");
        return (84);
    }
    x0 = my_getfloat(argv[1]);
    y0 = my_getfloat(argv[2]);
    z0 = my_getfloat(argv[3]);
    x1 = my_getfloat(argv[4]);
    y1 = my_getfloat(argv[5]);
    z1 = my_getfloat(argv[6]);
    time = my_getnbr(argv[7]);
    vector_x = x1 - x0;
    vector_y = y1 - y0;
    vector_z = z1 - z0;
    print_result(vector_x, vector_y, vector_z, time, x1, y1, z1);
    angle_rad = acosf(vector_z/(sqrt((vector_x * vector_x) + (vector_y * vector_y) + (vector_z * vector_z))));
    angle_degrees = 180 * (angle_rad - (M_PI/2))/M_PI;
    if (x0 < 0) {
        if (x1 < x0)
            my_putstr("The ball won't reach the paddle.\n");
        else {
            my_putstr("The incidence angle is:\n");
            my_put_float(angle_degrees);
            my_putstr(" degrees\n");
        }
    }
    if (x0 >= 0) {
        if (x1 > x0)
            my_putstr("The ball won't reach the paddle.\n");
        else {
            my_putstr("The incidence angle is:\n");
            my_put_float(angle_degrees);
            my_putstr(" degrees\n");
        }
    }
}