/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** random
*/

#include "rpg.h"

int random_int(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}

float random_float(float min, float max)
{
    return ((float)rand() / (float)(RAND_MAX) * (max - min) + min);
}