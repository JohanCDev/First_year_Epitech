/*
** EPITECH PROJECT, 2021
** main
** File description:
** for palindrome
*/

#include "pal.h"
#include "my.h"

int main(int argc, char **argv)
{
    pal_t pal;

    initialize_structure(&pal);
    switch (check_args(argc, argv, &pal)) {
    case 0:
        return 0;
    case -1:
        return 84;
    case 1:
        break;
    }
    proceed_code(&pal);
    return (0);
}