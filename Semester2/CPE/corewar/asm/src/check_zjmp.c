/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** check_zjmp
*/

#include "assembler.h"

void print_zjmp_info(char **array, t_asm *s_asm, char *hex_result)
{
    for (int k = 1; array[k]; k++) {
        if (array[1][0] != '%') {
            write(2, "ahhhh no, don't agree\n", 23);
            break;
        }
        if (my_getnbr(&array[k][1]) > REG_NUMBER || \
        my_getnbr(&array[k][1]) < 1) {
            write(2, "ahhhh no, don't agree\n", 23);
            break;
        }
        hex_result = my_putnbr_base_int(my_getnbr(&array[k][1]), HEX_BASE);
        hex_result = add_zero_when_solo(hex_result);
        for (int n = 0; n < my_strlen(hex_result); n += 2) {
            write(s_asm->fd, &hex_result[n], 2);
            write(s_asm->fd, " ", 1);
        }
    }
}

void check_zjmp(char **array, t_asm *s_asm)
{
    int i = 0;
    char *hex_result = malloc(sizeof(char) * (9));

    for (i = 0; array[i]; i++);
    if (!my_strcmp(array[0], "zjmp")) {
        if (i != 2) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        print_id_process(array, s_asm);
        print_zjmp_info(array, s_asm, hex_result);
    } else
        return;
}