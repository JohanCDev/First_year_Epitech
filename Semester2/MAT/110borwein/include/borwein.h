/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef BORWEIN_
	#define BORWEIN_

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <math.h>
	#include <string.h>

	#define EXIT_FAIL (84)
	#define EXIT_NORMAL (0)
	#define M_PI (3.14159265358979323846)

struct request {
	double start;
	double end;
	double interval;
	int precision;
};

// engine.c
void process(double start);
void process_midpoint(double start);
void process_trapezoids(double start);
void process_simpson(double start);
void display(double start, double val, const char *header);


// main.c
int check(int argc, char **argv);
void display_help(void);

// math.c
double borwein(double start, double i);

#endif /* BORWEIN */