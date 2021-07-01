/*
** EPITECH PROJECT, 2021
** B-MAT-100-NAN-1-1-105torus-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include <math.h>

void do_help(void)
{
    my_printf("USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\n");
    my_printf("DESCRIPTION\n\topt\tmethod option:\n\t\t\t");
    my_printf("1 for the bisection method\n\t\t\t2 for the Newton's method\n\t\t\t3 for the secant method\n\t");
    my_printf("a[0-4]\tcoefficients of the equation\n\tn\tprecision (the application of the polynomial to the solution should\n");
    my_printf("\t\tbe smaller than 10ˆ-n)\n");
    exit (0);
}

void look_errors(int argc, char **argv)
{
    if (argc == 1)
        exit (84);
    if (!my_strcmp(argv[1], "-h"))
        do_help();
    if (argc != 8)
        exit (84);
    if (my_strcmp(argv[1], "1") && my_strcmp(argv[1], "2") && my_strcmp(argv[1], "3"))
        exit (84);
    if (!(my_str_isnum(argv[2], 1) && my_str_isnum(argv[3], 1) && my_str_isnum(argv[4], 1) && my_str_isnum(argv[5], 1)))
        exit (84);
    for (int i = 2; i < 7; i++) {
        if (my_getnbr(argv[i]) > 2147483647 || my_getnbr(argv[i]) < -2147483647)
            exit (84);
    }
    if (!my_str_isnum(argv[7], 0))
        exit (84);
}

double my_func(char **argv, double x)
{
    double res = (my_getnbr(argv[6]) * pow(x, 4) + my_getnbr(argv[5]) * pow(x, 3) + my_getnbr(argv[4]) * pow(x, 2) + my_getnbr(argv[3]) * x + my_getnbr(argv[2]));

    return (res);
}

double secant(char **argv)
{
    double x0 = 0;
    double x1 = 1;
    double x2;
    double limit;
    int print_zeros;
    double int_part;

    for (int i = 0; i < 80; i++) {
        if ((my_func(argv, x1)) - (my_func(argv, x0)) == 0)
            exit(84);
        x2 = x1 - ((my_func(argv, x1) * (x1 - x0)) / (my_func(argv, x1) - my_func(argv, x0)));
        print_zeros = (modf(x2 * pow(10, (-1 * my_getnbr(argv[7]))), &int_part) * 100000);
        if ((-1 * my_getnbr(argv[7])) > 8) {
            if (print_zeros == 0)
                printf("x = %.*g\n", my_getnbr(argv[7]), x2);
            else
                printf("x = %.*f\n", my_getnbr(argv[7]), x2);
        }
        else {
            if (i == 0)
                printf("x = %.*g\n", my_getnbr(argv[7]), x2);
            else
                printf("x = %.*f\n", my_getnbr(argv[7]), x2);
        }
        limit = ((x2 - x1) < 0) ? ((-1 * (x2 - x1)) / x2) : ((x2 - x1) / x2);
        if (limit < pow(10, - 1 * my_getnbr(argv[7])))
            return (0);
        x0 = x1;
        x1 = x2;
    }
}

void newton(char **argv)
{
    double x = 0.5;
    double x1;
    double derivate;
    double limit;

    printf("x = %.1f\n", x);
    for (int i = 0; i < 16; i++) {
        derivate = (4 * (my_getnbr(argv[6]) * pow(x, 3))) + (3 * (my_getnbr(argv[5]) * pow(x, 2))) + (2 * my_getnbr(argv[4]) * x) + my_getnbr(argv[3]);
        if (derivate == 0)
            exit(84);
        x1 = x - (my_func(argv, x) / derivate);
        limit = ((x1 - x) < 0) ? ((-1 * (x1 - x)) / x1) : ((x1 - x) / x1);
        if (limit < pow(10, -1 * my_getnbr(argv[7])))
            return (0);
        printf("x = %.*f\n", my_getnbr(argv[7]), x1);
        x = x1;
    }
    exit (84);
}

int main(int argc, char **argv)
{
    look_errors(argc, argv);
    if (!my_strcmp(argv[1], "1"))
        bisection(argv);
    if (!my_strcmp(argv[1], "2"))
        newton(argv);
    if (!my_strcmp(argv[1], "3"))
        secant(argv);
    return (0);
}