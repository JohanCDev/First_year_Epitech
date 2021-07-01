/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** check_calculations
*/

#include "assembler.h"

void check_add_sub(char **array, t_asm *s_asm)
{
    int i = 0;
    char *hex_result = malloc(sizeof(char) * 9);

    for (i = 0; array[i]; i++);
    if (!my_strcmp(array[0], "add") || !my_strcmp(array[0], "sub")) {
        if (i != 4) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        print_id_process(array, s_asm);
        print_infos(array, hex_result, s_asm);
    } else
        return;
}

void convert_str_to_hex(char *str, int fd)
{
    char *current_char = malloc(sizeof(char) * 2);

    current_char[1] = 0;
    for (int i = 0; str[i]; i++) {
        current_char[0] = str[i];
        write(fd, my_putnbr_base_int(current_char[0], HEX_BASE), \
        my_strlen(my_putnbr_base_int(current_char[0], HEX_BASE)));
        if (str[i + 1])
            write(fd, " ", 1);
    }
}

void check_put(char **array, t_asm *s_asm)
{
    int i = 0;
    char *hex_result = malloc(sizeof(char) * 9);

    hex_result[8] = 0;
    for (i = 0; array[i]; i++);
    if (!my_strcmp(array[0], "put")) {
        print_info_put(i, s_asm, hex_result, array);
    } else
        return;
}

void print_hexafile(t_asm *s_asm)
{
    s_asm->array_infos = my_str_to_word_array(s_asm->buffer, "\n");
    char **instructions = NULL;

    for (int i = 0; s_asm->array_infos[i]; i++) {
        instructions = my_str_to_word_array(s_asm->array_infos[i], ", ");
        check_live(instructions, s_asm);
        check_ld(instructions, s_asm);
        check_st(instructions, s_asm);
        check_add_sub(instructions, s_asm);
        check_put(instructions, s_asm);
        check_and_or_xor(instructions, s_asm);
        check_zjmp(instructions, s_asm);
        free_array(instructions);
    }
}