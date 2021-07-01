/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-106bombyx-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include <stdbool.h>

typedef struct s_titration {
    double **base;
    double **first_d;
    double **second_d;
    int nb_lines;
    int ret;
} titration_t;

char *put_file_in_string(int fd, off_t file_size)
{
    char *buffer = malloc(sizeof(char) * file_size);
    int rd = read(fd, buffer, file_size);

    if (rd == -1)
        return (NULL);
    buffer[rd - 1] = 0;
    return (buffer);
}

int get_nb_lines(char const *file_content)
{
    int nb_lines = 0;
    int i = 0;

    while (file_content[i]) {
        if (file_content[i] == '\n')
            nb_lines++;
        i++;
    }
    return (nb_lines + 1);
}

char *get_str_until_char(const char *str, char c)
{
    int i = 0;
    char *ret = NULL;

    while (str[i] && str[i] != c)
        i++;
    ret = malloc(sizeof(char) * (i + 2));
    ret = my_strncpy(ret, str, i);
    ret[i] = 0;
    return (ret);
}

double **transfer_file(char const *file_content, double **array, titration_t *titration)
{
    int k = 0;

    titration->nb_lines = get_nb_lines(file_content);
    array = malloc(sizeof(double) * 2 * titration->nb_lines);
    for (int i = 0; i < titration->nb_lines; i++) {
        array[i] = malloc(sizeof(double) * 2);
        if (!my_str_isnum(get_str_until_char(&file_content[k], ';')))
            exit (84);
        array[i][0] = atof(&file_content[k]);
        while (file_content[k] != ';')
            k++;
        k++;
        if (!my_str_isnum(get_str_until_char(&file_content[k], '\n')))
            exit (84);
        array[i][1] = atof(&file_content[k]);
        while (file_content[k] && file_content[k] != '\n')
            k++;
        k++;
    }
    return (array);
}

double **get_file(char const *filepath, titration_t *titration)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;
    char *file = NULL;
    double **array = NULL;

    if (stat(filepath, &file_stat))
        exit (84);
    file = put_file_in_string(fd, file_stat.st_size);
    if (file == NULL)
        return (NULL);
    array = transfer_file(file, array, titration);
    return (array);
}

int check_errors(int argc, char **argv, titration_t *titration)
{
    if (argc != 2)
        return (85);
    if (!my_strcmp(argv[1], "-h")) {
        my_printf("USAGE\n\t./109titration file\n\nDESCRIPTION\n\tfile\ta csv file containing \"vol;ph\" lines\n");
        return (1);
    }
    titration->base = get_file(argv[1], titration);
    if (titration->base == NULL)
        return (85);
    return (0);
}

double search_equivalence(double **array, bool type, int nb_lines)
{
    double highest_value = array[0][1];
    double highest_index = array[0][0];
    
    if (!type) {
        for (int i = 0; i < nb_lines; i++) {
            if (array[i][1] > highest_value) {
                highest_index = array[i][0];
                highest_value = array[i][1];
            }
        }
        return (highest_index);
    }
    return (highest_index);
}

double **calculate_derivate(double **array, int nb_lines)
{
    double before = 0;
    double after = 0;
    double result = 0;
    double coef_before = 0;
    double coef_after = 0;
    double **result_array = malloc(sizeof(double) * 2 * (nb_lines - 2));

    for (int i = 0; i < nb_lines - 2; i++)
        result_array[i] = malloc(sizeof(double) * 2);
    for (int i = 1; i < nb_lines - 1; i++) {
        coef_before = array[i][0] - array[i - 1][0];
        coef_after = array[i + 1][0] - array[i][0];
        before = (array[i][1] - array[i - 1][1]) / (array[i][0] - array[i - 1][0]);
        after = (array[i + 1][1] - array[i][1]) / (array[i + 1][0] - array[i][0]);
        result = (coef_after * before + coef_before * after) / (coef_before + coef_after);
        result_array[i - 1][0] = array[i][0];
        result_array[i - 1][1] = result;
    }
    return (result_array);
}

void create_estimated_derivative(double **array, double *after)
{
    int nb_line = ((after[0] - array[0][0]) * 10 + 1);
    double **new_array = malloc(sizeof(double) * 2 * nb_line);

    for (int k = 0; k < nb_line; k++)
        new_array[k] = malloc(sizeof(double) * 2);
    for (int k = 0; k < nb_line; k++)
        new_array[k][0] = array[0][0] + (k * 0.1);
    new_array[0] = array[0];
    for (int k = 0; k < nb_line; k++)
        printf("%.1f ml -> %.2f\n", new_array[k][0], new_array[k][1]);
}

int main(int argc, char **argv)
{
    titration_t *titration = malloc(sizeof(titration_t));
    int ret = check_errors(argc, argv, titration);
    int k = 0;
    double f_equivalence = 0.0;

    if (ret)
        return (ret - 1);
    titration->first_d = malloc(sizeof(double) * 2 * (titration->nb_lines - 2));
    for (int i = 0; i < titration->nb_lines - 2; i++)
        titration->first_d[i] = malloc(sizeof(double) * 2);
    printf("Derivative:\n");
    titration->first_d = calculate_derivate(titration->base, titration->nb_lines);
    for (int i = 0; i < titration->nb_lines - 2; i++)
        printf("%.1f ml -> %.2f\n", titration->first_d[i][0], titration->first_d[i][1]);
    f_equivalence = search_equivalence(titration->first_d, 0, titration->nb_lines -2);

    printf("\nEquivalence point at %.1f ml\n\nSecond derivative:\n", f_equivalence);

    titration->second_d = calculate_derivate(titration->first_d, titration->nb_lines - 2);
    for (int i = 0; i < titration->nb_lines - 4; i++)
        printf("%.1f ml -> %.2f\n", titration->second_d[i][0], titration->second_d[i][1]);

    printf("\nSecond derivative estimated:\n");
    
    while (titration->base[k][0] != f_equivalence)
        k++;
    create_estimated_derivative(&titration->base[k - 1], titration->base[k + 1]);
    return (0);
}