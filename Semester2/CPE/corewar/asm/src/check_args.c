/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** check_args
*/

#include "assembler.h"

void check_helper(char **argv, t_asm *s_asm)
{
    if (!my_strcmp(argv[1], "-h")) {
        write(1, "USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\t\
file_name file in assembly language to be converted into \
file_name.cor, an executable in the Virtual Machine.\n", 151);
        s_asm->ret = 1;
        return;
    }
    s_asm->ret = 0;
    return;
}

void check_args(int argc, char **argv, t_asm *s_asm)
{
    init_struct(s_asm);
    if (argc == 2) {
        check_helper(argv, s_asm);
        if (s_asm->ret == 1)
            return;
    } else {
        write(2, "ahhhh no, don't agree\n", 23);
        s_asm->ret = 85;
        return;
    }
    open_and_read_file(argv[1], s_asm);
    if (s_asm->buffer == NULL) {
        s_asm->ret = 85;
        return;
    }
    s_asm->ret = 0;
    return;
}