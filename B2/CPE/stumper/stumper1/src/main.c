/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** main
*/

#include "my.h"
#include "head.h"

s_head *initialize_struct(void)
{
    s_head *head = malloc(sizeof(s_head));

    head->c = 0;
    head->n = 0;
    head->q = 0;
    head->v = 0;
    head->nb_files = 0;
    return (head);
}

int get_params_next(s_head *head, char **argv, int i)
{
    int fd = 0;

    if (check_bytes(argv[i]) == 1)
        head->c = i;
    else if (check_lines(argv[i]) == 1)
        head->n = i;
    else if ((fd = open(argv[i], O_RDONLY)) != -1) {
        head->nb_files++;
        close(fd);
    }
    return (i);
}

void get_params(s_head *head, char **argv)
{
    for (int i = 1; argv[i]; i++) {
        if (check_quiet(argv[i]) == 1)
            head->q = i;
        else if (check_verbose(argv[i]) == 1)
            head->v = i;
        else
            i = get_params_next(head, argv, i);
    }
}

int main(int argc, char **argv)
{
    s_head *head = initialize_struct();

    get_params(head, argv);
    if (head->c > head->n)
        display_bytes(argv, my_getnbr(argv[head->c + 1]), head);
    else if (head->c < head->n)
        display_lines(argv, my_getnbr(argv[head->n + 1]), head);
    else
        display_lines(argv, 10, head);
}