/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** do_lines_param
*/

#include "my.h"
#include "head.h"

void print_for_lines(char *buffer, int nb_lines_to_jump)
{
    for (int k = 0; buffer[k]; k++) {
        if (buffer[k] == '\n')
            nb_lines_to_jump--;
        write(1, &buffer[k], 1);
        if (nb_lines_to_jump == 0) {
            break;
        }
    }
}

int display_lines(char **args, int x, s_head *head)
{
    int fd = 0;
    int rd = 0;
    int nb_lines_to_jump = x;
    char *buffer = malloc(sizeof(char) * 4096);

    for (int i = 1; args[i]; i++) {
        nb_lines_to_jump = x;
        if ((fd = open(args[i], O_RDONLY)) == -1)
            continue;
        if ((rd = read(fd, buffer, 4096)) == -1)
            return (-1);
        buffer[rd] = 0;
        if ((head->v != 0 || head->nb_files > 1) && head->q == 0)
            my_printf("==> %s <==\n", args[i]);
        print_for_lines(buffer, nb_lines_to_jump);
    }
    return (0);
}

void print_bytes(int rd, int x, char *buffer)
{
    if (rd < x)
        write(1, buffer, rd);
    else
        write(1, buffer, x);
    free(buffer);
}

int display_bytes(char **args, int x, s_head *head)
{
    int fd = 0;
    int rd = 0;
    char *buffer;

    for (int i = 1; args[i]; i++) {
        fd = open(args[i], O_RDONLY);
        if (fd == -1)
            continue;
        if (!(buffer = malloc(x)))
            return 1;
        rd = read(fd, buffer, x);
        if (rd == -1)
            return 1;
        buffer[rd] = 0;
        if ((head->v != 0 || head->nb_files > 1) && head->q == 0)
            my_printf("==> %s <==\n", args[i]);
        close(fd);
        print_bytes(rd, x, buffer);
    }
    return (0);
}