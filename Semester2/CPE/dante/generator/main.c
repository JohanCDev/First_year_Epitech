/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** main
*/

#include "generator.h"

void display_help(void)
{
    printf("Usage: ./generator [WIDTH] [HEIGHT] (perfect/imperfect)\n");
}

int check_args(char *str)
{
    if (!str || strcmp(str, "imperfect") == 0)
        return (0);
    else if (strcmp(str, "perfect") == 0)
        return (1);
    return (2);
}

void create_imperfect(t_generator *gen)
{
    while (++gen->i < gen->n)
        make_imperfect(gen);
}

int compute(t_generator *gen, char **av)
{
    if (check_args(av[3]) != 2) {
        gen->x = atoi(av[1]);
        gen->y = atoi(av[2]);
        gen->i = -1;
        gen->n = (gen->y * gen->x) / 4;
        srand(time(NULL));
        if (fill_int_array(gen) == 84)
            return (84);
        while (check_end(gen) == 0)
            merge_cells(gen);
        if (check_args(av[3]) == 0)
            create_imperfect(gen);
        put_start_end(gen);
        display_maze(gen);
    } else
        return (2);
    return (0);
}

int	main(int ac, char **av)
{
    t_generator gen = {0, 0, 0, 0, NULL};
    int ret = 0;

    if (ac == 3 || ac == 4) {
        ret = compute(&gen, av);
        if (ret == 84)
            return (84);
        else if (ret == 2)
            display_help();
    } else
        display_help();
    return (0);
}
