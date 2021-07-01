/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "mydb.h"
#include <stdlib.h>
#include "my.h"

int main(int ac, char **av)
{
    db_t *database = check_args(ac, av);
    if (database == NULL)
        return (84);
    if (db_management(database, av) < 0)
        return (84);
    return (0);
}
