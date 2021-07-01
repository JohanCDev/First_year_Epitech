/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "borwein.h"

int my_str_isnum(char const *str)
{
    int is_okay = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] >= 48 && str[i] <= 57)
            is_okay = 1;
        else
            return (0);
    }
    return (is_okay);
}

int main(int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1], "-h") == 0) {
		display_help();
		return (0L);
	}
	if (check(argc, argv) == false)
		return (84);
	process(atof(argv[1]));
	return (0);
}

int check(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	if (!my_str_isnum(argv[1]))
		return (false);
	if (atoi(argv[1]) < 0)
		return (false);
	return (true);
}

void display_help(void)
{
	const char *header = "USAGE\n           ./110borwein n\n\n";
	const char *usage = "DESCRIPTION\n           n   constant defining"
		" the integral to be computed\n";

	printf("%s%s", header, usage);
}
