/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-108trigo-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include <stdbool.h>
#include <math.h>

double *mat1_factor_mat2(double *mat1, double *mat2, int size, int line_length)
{
	double *mat_res = malloc(sizeof(double) * size);
	double tmp;

	for (int i = 0; i < line_length; i++) {
		for (int j = 0; j < line_length; j++) {
			tmp = 0;
			for (int k = 0; k < line_length; k++)
				tmp += mat1[(i * line_length) + k] * mat2[(line_length * k) + j];
			mat_res[j + (i * line_length)] = tmp;
		}
	}
	return (mat_res);
}

double *mat1_add_mat2(double *matrix1, double *matrix2, int size)
{
    double *matrix_tempo = malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++)
        matrix_tempo[i] = matrix1[i] + matrix2[i];
    return (matrix_tempo);
}

double *mat1_div_divider(double *mat1, double divider, int size, int len)
{
	double *mat_res = malloc(sizeof(double) * size);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			mat_res[j + (i * len)] = mat1[j + (i * len)] / divider;
	return (mat_res);
}

void print_matrix(double *array, int length)
{
    for (int i = 0; i < length; i++) {
        if ((i + 1) % (int)sqrt(length) != 0)
            printf("%.2f\t", array[i]);
        else
            printf("%.2f\n", array[i]);
    }
}

bool is_integer(double value)
{
    int casted = (int)value;

    return (casted == value);
}

bool check_if_nb_are_num(char **numbers)
{
    for (int i = 2; numbers[i]; i++) {
        if (!my_str_isnum(numbers[i], 1))
            return (0);
    }
    return (1);
}

int check_errors(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h")) {
        my_printf("USAGE\n\t./108trigo fun a0 a1 a2 ...\n\nDESCRIPTION\n\tfun\tfunction to be applied, among at least 'EXP', 'COS', 'SIN', 'COSH'\n\t\tand 'SINH'\n\tai\tcoeficients of the matrix\n");
        return (1);
    } else if (strcmp("EXP", argv[1]) && strcmp("COS", argv[1]) && strcmp("SIN", argv[1]) && strcmp("COSH", argv[1]) && strcmp("SINH", argv[1]))
        return (-1);
    else if (!is_integer(sqrt(argc - 2)))
        return (-1);
    if (!check_if_nb_are_num(argv)) {
        return (-1);
    }
    return (0);
}

double *init_matrix(char **inputs, int argc, int length)
{
    double *matrix = malloc(sizeof(double) * length);

    for (int i = 0; i < length; i++) {
        matrix[i] = atof(inputs[i]);
    }
    return (matrix);
}

int factorial(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return (fact);
}

double *create_mat_base(int size, int line_length)
{
    double *matrix = malloc(sizeof(double) * size);

    for (int i = 0; i < line_length; i++) {
		for (int j = 0; j < line_length; j++) {
			if (j == i)
				matrix[j + (i * line_length)] = 1;
			else
				matrix[j + (i * line_length)] = 0;
        }
    }
    return(matrix);
}

int equal_mat(double *mat1, double *mat2, int size)
{
    for (int i = 0; i < size; i++)
        if (mat1[i] != mat2[i])
            return (0);
    return (1);
}

int check_can_leave(double *mat_res, double *tempo_mat, int size)
{
    if (equal_mat(mat_res, tempo_mat, size))
        return (1);
    return (0);
}

void exponential(double *matrix, int length)
{
    int factor = 1;
    double *tempo_matrix = create_mat_base(length, (int)sqrt(length));
    double *result = malloc(sizeof(double) * length);

    for (int i = 1; i < 51; i++) {
        factor *= i;
        tempo_matrix = mat1_factor_mat2(tempo_matrix, matrix, length, (int)sqrt(length));
        my_printf("Result : \n");
        result = mat1_div_divider(mat1_add_mat2(tempo_matrix, result, length), factor, length, (int)sqrt(length));
        print_matrix(result, length);
        printf("-------------------------------\n\n");
        if (check_can_leave(result, tempo_matrix, length) && i > 2)
            break;
    }
    print_matrix(result, length);
}

void cosinus(double *matrix)
{

}

void sinus(double *matrix)
{
    
}

void cosinus_h(double *matrix)
{
    
}

void sinus_h(double *matrix)
{
    
}

void switch_funct(double *inputs, char *type, int length)
{
    if (!my_strcmp("EXP", type))
        exponential(inputs, length);
    else if (!my_strcmp("COS", type))
        cosinus(inputs);
    else if (!my_strcmp("SIN", type))
        sinus(inputs);
    else if (!my_strcmp("COSH", type))
        cosinus_h(inputs);
    else if (!my_strcmp("SINH", type))
        sinus_h(inputs);
}

int main(int argc, char **argv)
{
    int ret = check_errors(argc, argv);
    double *inputs = NULL;
    int length = 0;

    if (ret == -1)
        return (84);
    else if (ret == 1)
        return (0);
    length = (argc - 2);
    inputs = init_matrix(&argv[2], argc, length);
    switch_funct(inputs, argv[1], length);
    
    return (0);
}