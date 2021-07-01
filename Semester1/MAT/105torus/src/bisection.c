/*
** EPITECH PROJECT, 2021
** B-MAT-100-NAN-1-1-105torus-johan.chrillesen
** File description:
** bisection
*/

static int check_end(char **argv, double xn)
{
    double result = my_func(argv, xn);

    if (((result < 0) ? -result : result) < powf(10, -1 * my_getnbr(argv[7])))
        return (1);
    else
        return (0);
}

static int do_bisection(char **argv, double x0, double x1, int nb_dec)
{
    double xn = (x0 + x1) / 2;

    if (nb_dec > 50)
        exit(84);
    if (check_end(argv, xn) == 1) {
        printf("x = %.*f\n", (nb_dec < my_getnbr(argv[7])) ? nb_dec : my_getnbr(argv[7]), xn);
        return (0);
    }
    if (my_func(argv, xn) * my_func(argv, x0) < 0) {
        printf("x = %.*f\n", (nb_dec < my_getnbr(argv[7])) ? nb_dec : my_getnbr(argv[7]), xn);
        return (do_bisection(argv, x0, xn, ++nb_dec));
    } else {
        printf("x = %.*f\n", (nb_dec < my_getnbr(argv[7])) ? nb_dec : my_getnbr(argv[7]), xn);
        return (do_bisection(argv, xn, x1, ++nb_dec));
    }
    return (0);
}

int bisection(char **argv)
{
    if (check_end(argv, 0.0) == 1)
        return (0);
    if (check_end(argv, 1.0) == 1)
        return (0);
    return (do_bisection(argv, 0.0, 1.0, 1));
}