/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** switch_param
*/

#include "my.h"

ls_s get_param(char arg, ls_s param)
{
    switch (arg) {
        case 'l':
            param.l = 1;
            break;
        case 'R' :
            param.R = 16;
            break;
        case 'd' :
            param.d = 8;
            break;
        case 'r' :
            param.r = 2;
            break;
        case 't' :
            param.t = 4;
            break;
        default:
            param.correct = 0;
    }
    return (param);
}