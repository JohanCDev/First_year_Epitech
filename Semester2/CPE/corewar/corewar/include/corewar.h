/*
** EPITECH PROJECT, 2021
** CoreDumpedWar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#define DEC_BASE "0123456789"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/my/my.h"

typedef struct core_s {
    char *buff;
    FILE *file;
    int ret;
} t_core;

char *open_and_read_file(char const *filepath, t_core *core);

#endif /* !COREWAR_H_ */

