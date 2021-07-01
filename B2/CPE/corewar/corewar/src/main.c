/*
** EPITECH PROJECT, 2021
** CoreDumpedWar
** File description:
** main
*/

#include "corewar.h"

int detect_instruction(char *instruction)
{
    char *tmp_instruction = malloc(sizeof(char) * 3);

    tmp_instruction[2] = 0;
    if (my_strlen(instruction) > 1)
        my_strncpy(tmp_instruction, instruction, 2);
    if (!my_strcmp(tmp_instruction, "04")) {
        my_printf("Add\n");
        return (27);
    }
    if (!my_strcmp(tmp_instruction, "05")) {
        my_printf("Sub\n");
        return (27);
    }
    return (0);
}

void make_commands(char *file_content)
{
    int i = 0;
    int check_if_change = 0;

    while (i < my_strlen(file_content)) {
        check_if_change = i;
        i += detect_instruction(&file_content[i]);
        if (check_if_change == i)
            break;
    }
}

int check_helper(char **argv)
{
    if (!my_strcmp(argv[1], "-h")) {
        write(1, "USAGE\n\
\t./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\
DESCRIPTION\n\
\t-dump nbr_cycle dumps the memory after the nbr_cycle execution \
(if the round isn’t already over) with the following format: 32 bytes/line \
in hexadecimal (A0BCDEFE1DD3...)\n\
\t-n prog_number sets the next program’s number. \
By default, the first free number in the parameter order\n\
\t-a load_address sets the next program’s loading address. When no address is\
specified, optimize the addresses so that the processes are as far\
away from each other as possible. The addresses are MEM_SIZE modulo.\n", 592);
        return (1);
    }
    return (0);
}

void check_args(int argc, char **argv, t_core *core)
{
    if (argc == 2) {
        if (check_helper(argv) == 1) {
            core->ret = 1;
            return;
        }
    } else {
        write(2, "ahhhh no, don't agree\n", 23);
        core->ret = 85;
        return;
    }
}

int main(int argc, char **argv)
{
    t_core core = {.buff = NULL, .file = NULL, .ret = 0};

    check_args(argc, argv, &core);
    if (core.ret != 0)
        return (core.ret - 1);
    if (open_and_read_file(argv[1], &core) == NULL)
        return (84);
    my_printf("%s\n", core.buff);
    make_commands(core.buff);
    free(core.buff);
    return (0);
}