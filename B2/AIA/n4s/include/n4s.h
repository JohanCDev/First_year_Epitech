/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

//-----NEEDED-INCLUDE-----
#include "my.h"

//---------MACROS---------

//-------STRUCTURE--------

//-------PROTOTYPES-------
char **my_strtok(char *line, char *separators);

//get info
double *get_info_lidar(void);
float get_current_speed(void);

//direction
int go_forward(float speed);
int go_backward(float speed);

//wheels
int manage_direction(void);

//speed
int manage_speed(void);

#endif /* !N4S_H_ */