/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** speed
*/

#include "n4s.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int speed_convertor(double speed)
{
    double speed_value;
    int result;

    if (speed >= 1800)
        speed_value = 1.0;
    else if (speed >= 1500)
        speed_value = 0.8;
    else if (speed >= 1000)
        speed_value = 0.6;
    else if (speed >= 600)
        speed_value = 0.5;
    else if (speed >= 400)
        speed_value = 0.4;
    else
        speed_value = 0.2;
    result = go_forward(speed_value);
    return result;
}

int manage_speed(void)
{
    double speed;
    double *lidar = get_info_lidar();
    if (lidar == NULL)
        return 42;
    speed = (lidar[15] + lidar[16]) / 2;
    if (speed_convertor(speed) != 1)
        return 0;
    // free(lidar);
    return 1;
}