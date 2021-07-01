/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** check_args
*/

#include "my.h"
#include "calendar.h"

int display_helper(void)
{
    my_printf("%s", HELPER);
    return (1);
}

int check_argc(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return (display_helper());
    else if (argc != NB_ARGS)
        return (0);
    return (2);
}

int check_args(int argc, char **argv)
{
    switch (check_argc(argc, argv)) {
    case 0:
        return (my_put_error("Bad arguments try with -h\n", -1));
    case 1:
        return 0;
    case 2:
        return 1;
    }
    return (my_put_error("Error with check_args\n", -1));
}