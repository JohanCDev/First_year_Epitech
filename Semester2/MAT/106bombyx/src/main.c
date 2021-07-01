/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-106bombyx-johan.chrillesen
** File description:
** main
*/

#include "my.h"

int check_errors(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        return (85);
    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h")) {
            my_printf("USAGE\n\t./106bombyx n [k | i0 i1]\n\nDESCRIPTION\n\tn\tnumber of first generation individuals\n\tk\tgrowth rate from 1 to 4\n\ti0\tinitial generation(included)\n\ti1\tfinal generation(included)\n");
            return (1);
        }
        return (85);
    }
    if (!my_str_isnum(argv[1], 0))
        return (85);
    if (argc == 3)
        if (!((atoi(argv[2]) >= 1) && (atoi(argv[2]) <= 4)))
            return (85);
    if (argc == 4) {
        if (!my_str_isnum(argv[2], 0) || !my_str_isnum(argv[3], 0))
            return (85);
        if (atoi(argv[2]) > atoi(argv[3]))
            return (85);
    }
    return (0);
}

void first_option(char **argv)
{
    int i = 1;
    double x = atof(argv[1]);
    double growth_rate = atof(argv[2]);

    printf("%d %.2f\n", i, x);
    while (i < 100) {
        x = growth_rate * x * ((1000.0 - x) / 1000.0);
        if (x < 0)
            x = 0;
        printf("%d %.2f\n", ++i, x);
    }
}

void second_option(char **argv)
{
    double x = atof(argv[1]);
    int i0 = atoi(argv[2]);
    int i1 = atoi(argv[3]);

    for (float k = 1.0; k < 4; k += 0.01) {
        int i = 1;
        x = atof(argv[1]);
        for (; i < i0; i++) {
            x = k * x * ((1000.0 - x) / 1000.0);
            if (x < 0)
                x = 0;
        }
        for (; i <= i1; i++) {
            if (i >= i0)
                printf("%.2f %.2f\n", k, x);
            x = k * x * ((1000.0 - x) / 1000.0);
            if (x < 0)
                x = 0;
        }
    }
}

int main(int argc, char **argv)
{
    int ret = check_errors(argc, argv);

    if (ret)
        return (ret - 1);
    if (argc == 3)
        first_option(argv);
    if (argc == 4)
        second_option(argv);
    return (0);
}