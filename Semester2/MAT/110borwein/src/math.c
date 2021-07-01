/*
** EPITECH PROJECT, 2018
** math.c
** File description:
**
*/

#include "borwein.h"

double borwein(double start, double i)
{
	double fact = 1.0;
	double div = 0.0;

	if (fabs(i) < 0.001)
		return (1.0);
	for (int k = 0; k < start + 1; k++) {
		div = (2 * k + 1);
		fact *= (sin(i / div)) / (i / div);
	}
	return (fact);
}