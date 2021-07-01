/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** db_management
*/

#include "mydb.h"
#include "my.h"

bool show_management(db_t *db, char **av)
{
    char **temp;
    int where;

    if ((where = where_is_str_in_str(av[2], "show")) > -1) {
        temp = my_strtok(av[2] + where, " ");
        if (!temp || !temp[1] || !temp[2]) {
            my_free_char_array(temp);
            return (false);
        }
        show_print(db, atoi(temp[1]), atoi(temp[2]));
        my_free_char_array(temp);
        return (true);
    } else {
        return (false);
    }
}

db_t *get_management(db_t *db, char **av)
{
    int where;
    char **temp;
    int field = -1;
    char *value = NULL;
    db_t *new;

    if ((where = where_is_str_in_str(av[2], "get ")) > -1) {
        temp = my_strtok(av[2] + where, " ");
        if (!temp || !temp[1] || !temp[2])
            return NULL;
        field = get_field_from_title(temp[1]);
        my_free_char_array(temp);
        if (field < 0) 
            return NULL;
        value = get_get_value(av[2] + where);
        if (!value)
            return (NULL);
        new = db_get_cmd(db, field, value);
        free (value);
        if (!new)
            return NULL;
        free(db);
        return (new);
    }
    return NULL;
}

int db_management(db_t *db, char **av)
{

    db = get_management(db, av);
    if (sort_management(db, av) < 0)
        return (-1);
    if (!show_management(db, av))
        normal_print(db);
    free_db(db);
    return (0);
}