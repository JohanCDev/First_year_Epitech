/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv)
{
    int crypt_key = 0;
    char *message = NULL;

    if (argc != 3)
        return (84);
    message = get_file(argv[1]);
}