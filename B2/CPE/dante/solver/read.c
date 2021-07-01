/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** read
*/

#include "solver.h"

int	resolve(solver_t *solver, int line, int column)
{
    if (column < 0 || (column > solver->x - 1) || line < 0 || (line > solver->y - 1))
        return (0);
    else if (solver->tab[line][column] == 'F')
        return (1);
    else if (solver->tab[line][column] != '*' && solver->tab[line][column] != 'D')
        return (0);
    printf("o");
    solver->tab[line][column] = 'o';
    if (resolve(solver, line, (column + 1)) == 1)
        return (1);
    else if (resolve(solver, (line + 1), column) == 1)
        return (1);
    else if (resolve(solver, line, (column - 1)) == 1)
        return (1);
    else if (resolve(solver, (line - 1), column) == 1)
        return (1);
    printf( "C");
    solver->tab[line][column] = 'C';
    return (0);
}

int	set_begin_end(solver_t *solver)
{
    if (solver->tab[0][0] == 'X' || \
    solver->tab[solver->y - 1][solver->x - 1] == 'X')
        return (0);
    solver->tab[0][0] = 'D';
    solver->tab[solver->y - 1][solver->x - 1] = 'F';
    solver->tab[solver->y - 1][solver->x] = 0;
    return (1);
}

void modif_for_push(solver_t *solver)
{
    int	line = 0;
    int	column = 0;

    while (solver->tab[line]) {
        column = 0;
        while (solver->tab[line][column]) {
            if (solver->tab[line][column] == 'C')
                solver->tab[line][column] = '*';
            else if (solver->tab[line][column] == 'F')
                solver->tab[line][column] = 'o';
            column++;
        }
        line++;
    }
}

int read_map(solver_t *solver, char *filename)
{
    struct stat sb;
    int fd = 0;
    int line = 0;
    char *buffer = NULL;

    if (stat(filename, &sb) == -1)
        return (1);
    if ((fd = open(filename, O_RDWR)) == -1)
        return (1);
    if ((buffer = malloc(sizeof(char) * (sb.st_size + 1))) == NULL)
        return (1);
    if (read(fd, buffer, sb.st_size) <= 0)
        return (1);
    buffer[sb.st_size - 1] = '\0';
    line = sb.st_size - 1;
    while (buffer[--line] == '\n');
    buffer[line + 1] = 0;
    close(fd);
    solver->tab = my_str_to_wordtab(buffer, '\n');
    my_show_wordtab(solver->tab);
    return (0);
}
