/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** db_management
*/

#include "mydb.h"
#include "my.h"

int sort_management(db_t *db, char **av)
{
    int where;
    char **temp;

    if ((where = where_is_str_in_str(av[2], "sort")) > -1) {
        temp = my_strtok(av[2] + where, " ");
        if (!temp || !temp[1]) {
            my_free_char_array(temp);
            return (-1);
        }
        sort_films(db, get_field_from_title(temp[1]));
    }
    return (0);
}