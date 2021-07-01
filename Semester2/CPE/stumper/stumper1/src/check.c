/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** check
*/

#include "my.h"

int check_quiet(char *option)
{
    if (!my_strcmp(option, "-q") || !my_strcmp(option, "--quiet") || \
        !my_strcmp(option, "--silent"))
        return 1;
    return 0;
}

int check_verbose(char *option)
{
    if (!my_strcmp(option, "-v") || !my_strcmp(option, "--verbose"))
        return 1;
    return 0;
}

int check_bytes(char *option)
{
    if (!my_strcmp(option, "-c") || !my_strcmp(option, "--bytes"))
        return 1;
    return 0;
}

int check_lines(char *option)
{
    if (!my_strcmp(option, "-n") || !my_strcmp(option, "--lines"))
        return 1;
    return 0;
}
