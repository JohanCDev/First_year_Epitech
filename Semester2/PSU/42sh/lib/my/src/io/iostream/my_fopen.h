/*
** EPITECH PROJECT, 2021
** Libmy - io module
** File description:
** Definitions for my_fopen
*/

#ifndef __LIBMY_SRC_IO_FOPEN_H__
#define __LIBMY_SRC_IO_FOPEN_H__

#include <fcntl.h>

typedef enum {
    P_MY_FOPEN_R = O_RDONLY,
    P_MY_FOPEN_W = O_WRONLY | O_CREAT | O_TRUNC,
    P_MY_FOPEN_A = O_WRONLY | O_CREAT | O_APPEND,
    P_MY_FOPEN_R_PLUS = O_RDWR,
    P_MY_FOPEN_W_PLUS = O_RDWR | O_CREAT | O_TRUNC,
    P_MY_FOPEN_A_PLUS = O_RDWR | O_CREAT | O_APPEND,
} my_fopen_modes;

#endif // !defined(__LIBMY_SRC_IO_FOPEN_H__)
