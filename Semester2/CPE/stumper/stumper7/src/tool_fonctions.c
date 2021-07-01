/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** tool_fonctions
*/

#include "mydb.h"
#include "string.h"

bool is_an_id(int field)
{
    if (field == ID_DIRECTOR_FIELD)
        return (true);
    if (field == ID_FIELD)
        return (true);
    if (field == ID_TYPE_FIELD)
        return (true);
    return (false);
}

int where_is_str_in_str(char *str, char *to_find)
{
    int to_find_length;

    if (!str || !to_find)
        return (-1);
    to_find_length = strlen(to_find);
    for (int i = 0; str[i]; i++) {
        if (strncmp(str + i, to_find, to_find_length) == 0)
            return (i);
    }
    return (-1);
}

int get_field_from_title(char *field_title)
{
    if (strcmp(field_title, "id_movie") == 0)
        return (ID_FIELD);
    if (strcmp(field_title, "title") == 0)
        return (TITLE_FIELD);
    if (strcmp(field_title, "synopsis") == 0)
        return (SYNPOSIS_FIELD);
    if (strcmp(field_title, "id_director") == 0)
        return (ID_DIRECTOR_FIELD);
    if (strcmp(field_title, "director") == 0)
        return (DIRECTOR_FIELD);
    if (strcmp(field_title, "id_type") == 0)
        return (ID_TYPE_FIELD);
    if (strcmp(field_title, "type") == 0)
        return (TYPE_FIELD);
    return (-1);
}