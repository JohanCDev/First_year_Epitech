/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** check_args
*/

#include "my.h"
#include "pal.h"

int display_helper(void)
{
    my_printf("%s", HELPER);
    return (1);
}

int check_argc(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return (display_helper());
    else if (argc < NB_ARGS_MIN || argc > NB_ARGS_MAX)
        return 0;
    return (2);
}

int check_args(int argc, char **argv, pal_t *test)
{
    switch (check_argc(argc, argv)) {
    case 0:
        return (my_put_error("Bad arguments try with -h\n", -1));
    case 1:
        return 0;
    case 2:
        break;
    }
    return (get_flags(&test->flags, argv));
}