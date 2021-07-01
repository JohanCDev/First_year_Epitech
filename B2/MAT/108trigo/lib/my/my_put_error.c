/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_put_error
*/

#include <unistd.h>
#include "my.h"

int my_put_error(char *message)
{
    int len = my_strlen(message);

    write(2, message, len);
    return (84);
}