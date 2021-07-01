/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** solver
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define UTIME_TO_WAIT	500

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_solver
{
    char **tab;
    int a;
    int b;
    int i;
    int n;
    int x;
    int y;
} solver_t;

/* !LIBMY.A */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*get_next_line(const int fd);

/* !READ.C */
int	resolve(solver_t *solver, int line, int c);
int	set_begin_end(solver_t *solver);
void	modif_for_push(solver_t *solver);
int	read_map(solver_t *solver, char *filename);

/* !MY_STR_TO_WORDTAB */
int	nb_mot(char *str, char sep);
int	nb_mot_bis(char *str, char sep1, char sep2);
char	**my_str_to_wordtab(char *str, char sep);
void	my_show_wordtab(char **tab);

/* !COUNT.C */
int	get_nb_column(char **tab);
int	get_array_length(char **tab);

#endif /* !SOLVER_H_ */
