/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** print_infos_calculations
*/

#include "assembler.h"

void print_id_process(char **array, t_asm *s_asm)
{
    if (!my_strcmp(array[0], "live"))
        write(s_asm->fd, "01 ", 3);
    if (!my_strcmp(array[0], "ld"))
        write(s_asm->fd, "02 ", 3);
    if (!my_strcmp(array[0], "st"))
        write(s_asm->fd, "03 ", 3);
    if (!my_strcmp(array[0], "add"))
        write(s_asm->fd, "04 ", 3);
    if (!my_strcmp(array[0], "sub"))
        write(s_asm->fd, "05 ", 3);
    if (!my_strcmp(array[0], "and"))
        write(s_asm->fd, "06 ", 3);
    if (!my_strcmp(array[0], "or"))
        write(s_asm->fd, "07 ", 3);
    if (!my_strcmp(array[0], "xor"))
        write(s_asm->fd, "08 ", 3);
    if (!my_strcmp(array[0], "zjmp"))
        write(s_asm->fd, "09 ", 3);
}

void print_zeros_before_info(char *hex_result, t_asm *s_asm)
{
    for (int i = 0; i < 8 - my_strlen(hex_result); i++) {
        write(s_asm->fd, "0", 1);
        if (i % 2)
            write(s_asm->fd, " ", 1);
    }
}

void print_infos(char **array, char *hex_result, t_asm *s_asm)
{
    for (int k = 1; array[k]; k++) {
        if (array[k][0] != 'r') {
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

void print_put_char_in_hex(char *hex_result, t_asm *s_asm, int k)
{
    while (k < (7 - my_strlen(hex_result))) {
        write(s_asm->fd, " 00", 3);
        k += 2;
    }
    for (; k < my_strlen(hex_result); k += 2) {
        write(s_asm->fd, " ", 1);
        write(s_asm->fd, &hex_result[k], 2);
    }
}

void print_info_put(int i, t_asm *s_asm, char *hex_result, char **array)
{
    int k = 0;

    if (i != 2) {
        write(2, "ahhhh no, don't agree\n", 23);
        s_asm->ret = 84;
        return;
    }
    write(s_asm->fd, "04 ", 3);
    hex_result = my_putnbr_base_int(my_strlen(array[1]), HEX_BASE);
    if (my_strlen(hex_result) % 2) {
        write(s_asm->fd, "0", 1);
        write(s_asm->fd, &hex_result[0], 1);
        k++;
    }
    print_put_char_in_hex(hex_result, s_asm, k);
    write(s_asm->fd, " ", 1);
    convert_str_to_hex(array[1], s_asm->fd);
}