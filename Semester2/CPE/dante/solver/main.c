/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** main
*/

#include "solver.h"

int main(int ac, char **av)
{
    solver_t solver;

    if (ac != 2)
        return (84);
    if ((read_map(&solver, av[1])) == 1)
        return (0);
    solver.y = get_array_length(solver.tab);
    solver.x = get_nb_column(solver.tab);
    my_show_wordtab(solver.tab);
    if ((set_begin_end(&solver)) == 0) {
        write(1, "No solution found\n", strlen("No solution found\n"));
        return (0);
    }
    if ((resolve(&solver, 0, 0)) == 0) {
        write(1, "No solution found\n", strlen("No solution found\n"));
        return (0);
    }
    modif_for_push(&solver);
    printf("\n");
    return (0);
}
