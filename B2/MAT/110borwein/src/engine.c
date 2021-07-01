/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**
*/

#include "borwein.h"

void process(double start)
{
	process_midpoint(start);
	process_trapezoids(start);
	process_simpson(start);
}

void process_midpoint(double start)
{
	const char *header = "Midpoint:\n";
	double result = 0.0;

	for (int i = 0; i < 10000; i++)
		result += 0.5 * borwein(start, (i + 0.5) / 2.0);
	display(start, result, header);
}

void process_trapezoids(double start)
{
	const char *header = "Trapezoidal:\n";
	double result = 0.0;
	double h = 5000.0 / 10000.0;

	for (int i = 0; i < 10000; i++)
		result += h * ((borwein(start, i * h) + borwein(start, (i + 1) * h)) / 2.0);
	display(start, result, header);
}

void process_simpson(double start)
{
	const char *header = "Simpson:\n";
	double sum2 = borwein(start, 0.5 / 2.0);
	double sum1 = 0.0;
	double result = 0.0;

	for (int i = 1; i < 10000; i++) {
		sum1 += borwein(start, i * 0.5);
		sum2 += borwein(start, i * 0.5 + 0.5 / 2);
	}
	result = (0.5 / 6.0) * (borwein(start, 0) + borwein(start, 5000) + 2 * sum1 + 4 * sum2);
	display(start, result, header);
}

void display(double start, double val, const char *header)
{
	const char *last_header = "Simpson:\n";

	printf("%s", header);
	printf("I%d = %.*f\n", (int)start, 10, val);
	if ((val - M_PI / 2) < 0)
		printf("diff = %.10f\n", (val - M_PI / 2) * -1);
	else	
		printf("diff = %.10f\n", (val - M_PI / 2));
	if (strcmp(header, last_header) != 0)
		printf("\n");
}
