/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-102architect-johan.chrillesen
** File description:
** matrix
*/

#include "my.h"
#include "architect.h"

double *matrix1_factor_matrix2(double *matrix1, double *matrix2)
{
	int size = 9;
	int i = 0;
	double matrix_tempo[size];

	for (i = 0; i < 9; i++)
		matrix_tempo[i] = matrix1[i];
	for (i = 0; i < 9; i++)
		matrix1[i] = matrix_tempo[i - (i % 3)] * matrix2[i % 3] + matrix_tempo[i - (i % 3) + 1] * matrix2[i % 3 + 3] + matrix_tempo[i - (i % 3) + 2] * matrix2[i % 3 + 6];
	return (matrix1);
}

double *do_matrix_rotation(s_coord_point *point, double *matrix)
{
	int i = 0;
	double *result = malloc(sizeof(double) * 9);

	result[0] = point->x;
	result[1] = -point->y;
	result[3] = point->y;
	result[4] = point->x;
	while (i < 9) {
		if (i != 0 && i != 4 && i != 1 && i != 3)
			result[i] = matrix[i];
		i++;
	}
	return (result);
}

double *do_matrix_symmetry(s_coord_point *point, double *matrix)
{
	int i = 0;
	double *result = malloc(sizeof(double) * 9);

	result[0] = point->x;
	result[1] = point->y;
	result[3] = point->y;
	result[4] = -point->x;
	while (i < 9) {
		if (i != 0 && i != 4 && i != 1 && i != 3)
			result[i] = matrix[i];
		i++;
	}
	return (result);
}

void display_matrix(double *matrix)
{
    int i = 0;

	while (i < 9) {
		if (matrix[i] < 0.01 && matrix[i] > -0.01)
			printf("0.00");
		else
			printf("%.2f", matrix[i]);
		i++;
		if (i % 3 == 0)
			printf("\n");
		else
			printf("	");
	}
}