/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-103cipher-johan.chrillesen
** File description:
** clear && make re && make clean && ./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S" 0
*/

#include "my.h"

void print_matrix(int **matrix, int line, int nb_column)
{
    int i = 0;
    int k = 0;

    my_printf("Key matrix:\n");
    while (i < line) {
        while (k < nb_column) {
            if (k + 1 < nb_column)
                my_printf("%d\t", matrix[i][k]);
            else
                my_printf("%d", matrix[i][k]);
            k++;
        }
        my_printf("\n");
        k = 0;
        i++;
    }
    my_printf("\n");
}

int **encrypt_message(int **message_matrix, int **key_matrix, int nb_columns, int nb_line)
{
    int **result = malloc(sizeof(int *) * (nb_line + 1));
    int index_line_mes = 0;
    int index_column_mes = 0;
    int index_line_key = 0;
    int index_column_key = 0;
    int index_line_res = 0;
    int index_column_res = 0;
    int plus = 0;

    while (index_line_res < nb_line) {
        while (index_column_key < nb_columns) {
            result[index_line_res] = malloc(sizeof(int) * nb_columns);
            while (plus < nb_columns) {
                //my_printf("%d += %d * %d\n", result[index_line_res][index_column_res], message_matrix[index_line_mes][index_column_mes + plus], key_matrix[index_line_key + plus][index_column_key]);
                result[index_line_res][index_column_res] += message_matrix[index_line_mes][index_column_mes + plus] * key_matrix[index_line_key + plus][index_column_key];
                plus++;
            }
            index_column_key++;
            plus = 0;
            if (index_line_res == 0 && index_column_res == 0)
                my_printf("%d", result[index_line_res][index_column_res]);
            else
                my_printf(" %d", result[index_line_res][index_column_res]);
            index_column_res++;
        }
        index_line_res++;
        index_line_mes++;
        index_column_key = 0;
        index_column_res = 0;
        index_column_mes = 0;
    }
    my_putchar('\n');
    return (result);
}

int **create_key_matrix(char *str, int nb_columns)
{
    int i = 0;
    int k = 0;
    int **key_matrix;

    key_matrix = malloc(sizeof(int *) * nb_columns);
    key_matrix[0] = malloc(sizeof(int) * nb_columns);
    for (i = 0; i < nb_columns; i++) {
        for (k = 0; k < nb_columns; k++) {
            if (*str)
                key_matrix[i][k] = *str++;
            else
                key_matrix[i][k] = 0;
        }
        key_matrix[i + 1] = malloc(sizeof(int) * nb_columns);
    }
    print_matrix(key_matrix, i, k);
    return (key_matrix);
}

int **create_message_matrix(char *str, int nb_columns)
{
    int index_line = 0;
    int index_column = 0;
    int nb_line = my_strlen(str) / nb_columns;
    int **matrix;
    matrix = malloc(sizeof(int *) * (nb_line + 1));
    matrix[0] = malloc(sizeof(int) * nb_columns);
    ((nb_line * nb_columns % my_strlen(str) != 0) || nb_line == 0) ? nb_line++ : 0;
    for (index_line = 0; index_line < nb_line; index_line++) {
        for (index_column = 0; index_column < nb_columns; index_column++) {
            if (*str)
                matrix[index_line][index_column] = *str++;
            else
                matrix[index_line][index_column] = 0;
        }
        matrix[index_line + 1] = malloc(sizeof(int) * nb_columns);
    }
    //print_matrix(matrix, nb_line, nb_columns);
    return (matrix);
}

int check_errors(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            my_printf("USAGE\n");
            my_printf("\t./103cipher message key flag\n");
            my_printf("\nDESCRIPTION\n");
            my_printf("\tmessage\ta message, made of ASCII characters\n");
            my_printf("\tkey\tthe encryption key, made of ASCII characters\n");
            my_printf("\tflag\t0 for the message to be encrypted, 1 to be decrypted\n");
        }
    }
    if (!argv[1] || !argv[2] || !argv[3] || argv[4])
        return (84);
    if (!my_str_isprintable(argv[1]))
        return (84);
    if (!my_str_isprintable(argv[2]))
        return (84);
    if (my_strcmp(argv[3], "0") != 0 && my_strcmp(argv[3], "1") != 0)
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    int **key_matrix;
    int **message_matrix;
    int **encrypted_message;
    int nb_columns = 0;
    int nb_letter = 0;
    int nb_line = 0;

    if (check_errors(argc, argv) == 84)
        return (84); 
    while (argv[2][nb_letter])
        nb_letter++;
    nb_columns = (int) sqrt(nb_letter);
    if (nb_columns * nb_columns % nb_letter != 0)
        nb_columns++;
    nb_line = my_strlen(argv[1]) / nb_columns;
    if ((nb_line * nb_columns % my_strlen(argv[1]) != 0) || nb_line == 0)
        nb_line++;
    message_matrix = create_message_matrix(argv[1], nb_columns);
    key_matrix = create_key_matrix(argv[2], nb_columns);
    if (my_getnbr(argv[3]) == 0) {
        my_printf("Encrypted message:\n");
        encrypted_message = encrypt_message(message_matrix, key_matrix, nb_columns, nb_line);
        //display_encrypted_matrix(encrypted_message);
    } else
        my_printf("Decrypted message:\n");
    return (0);
}