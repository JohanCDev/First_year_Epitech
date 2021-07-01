/*
** EPITECH PROJECT, 2021
** CoreDumpedWar
** File description:
** main
*/

#include "assembler.h"

char *add_zero_when_solo(char *hex_result)
{
    int length = my_strlen(hex_result);

    if (length % 2) {
        hex_result = my_revstr(hex_result);
        hex_result[length] = '0';
        hex_result[length + 1] = 0;
        hex_result = my_revstr(hex_result);
    }
    return (hex_result);
}

void init_struct(t_asm *s_asm)
{
    s_asm->array_infos = NULL;
    s_asm->buffer = NULL;
    s_asm->fd = 0;
    s_asm->ret = 0;
}

void end_program(t_asm *s_asm)
{
    close(s_asm->fd);
    for (int i = 0; s_asm->array_infos[i]; i++)
        free(s_asm->array_infos[i]);
    free(s_asm->array_infos);
    free(s_asm->buffer);
    free(s_asm);
}

int main(int argc, char **argv)
{
    t_asm *s_asm = malloc(sizeof(t_asm));

    if (s_asm == NULL) {
        write(2, "ahhhh no, don't agree\n", 23);
        return (84);
    }
    check_args(argc, argv, s_asm);
    if (s_asm->ret != 0)
        return (s_asm->ret - 1);
    s_asm->fd = open(create_path(argv[1]), O_CREAT | O_RDWR, 0777);
    if (s_asm->fd == 0) {
        write(2, "Unable to open file\n", 23);
        return (84);
    }
    print_hexafile(s_asm);
    end_program(s_asm);
    return (0);
}