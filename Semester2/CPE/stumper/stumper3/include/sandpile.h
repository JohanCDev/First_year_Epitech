/*
** EPITECH PROJECT, 2021
** sandpile.h
** File description:
** sandpile.h
*/


#ifndef __SANDPILE__
#define __SANDPILE__

//-----NEEDED-INCLUDE------
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//-----MACROS--------------

//-----STRUCTURE-----------
typedef struct s_map
{
    int height;
    int width;
    int *map;
    int ret;
    char *str;
} map_t;

//-----PROTOTYPES----------


#endif