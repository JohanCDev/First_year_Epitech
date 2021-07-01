/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-106bombyx-johan.chrillesen
** File description:
** main
*/

#include "my.h"

int check_errors(int argc, char **argv)
{
    if (argc == 1)
        return (85);
    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h")) {
            my_printf("USAGE\n\t./107transfer [num den]*\n");
            my_printf("DESCRIPTION\n\tnum\tpolynomial numerator defined by its coefficients\n");
            my_printf("\tden\tpolynomial numerator defined by its coefficients\n");
            return (1);
        }
        return (85);
    }
    if (argc % 2 == 0)
        return (85);
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            if ((argv[i][j] != '.') && (argv[i][j] != '*') && (argv[i][j] < '0' || argv[i][j] > '9'))
                return (85);
    return (0);
}

int *fill_list(int *num_list, char *str)
{
    int index = 0;
    int i = 0;
    my_revstr(str);

    if (my_strlen(str) <= 1) {
        num_list[0] = my_getnbr(str);
        num_list[1] = -1;
        return (num_list);
    }
    while (str[i]) {
        num_list[index] = my_getnbr(&str[i]);
        i += my_strlen(my_itoa(num_list[index])) + 1;
        index++;
    }
    num_list[index - 1] = -1;
    return (num_list);
}

double compute_result(int *list, int x)
{
    double result = 0;
    int i = 0;

    while (list[i] != -1) {
        printf("list[%d] = %d\n", i, list[i]);
        result = (result * x) + (float) list[i];
        i++;
    }
    return (result);
}

int main(int argc, char **argv)
{
    int ret = check_errors(argc, argv);
    double result = 1.0;
    int k = 1;
    int *num_list = malloc(sizeof(int) * 1024);
    int *den_list = malloc(sizeof(int) * 1024);
    double num_result = 0.0;
    double den_result = 0.0;

    if (ret)
        return (ret - 1);
    for (double x = 0.0; x <= 1.001; x += 0.001) {
        for (int i = 1; i < argc; i += 2) {
            num_list = fill_list(num_list, argv[i]);
            den_list = fill_list(den_list, argv[i + 1]);
            num_result = compute_result(num_list, x);
            den_result = compute_result(den_list, x);
            if (num_result != den_result && den_result == 0)
                return (84);
            //printf("num %.5f, den %.5f\n", num_result, den_result);
            result *= num_result / den_result;
        }
        printf("%.3f -> %.5f\n", x, result);
        result = 1.0;
    }
    return (0);
}