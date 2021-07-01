/*
** EPITECH PROJECT, 2021
** CoreDumpedWar
** File description:
** assembler
*/

#ifndef ASSEMBLER_H_
#define ASSEMBLER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../lib/my/my.h"
#include "../../op.h"

#define HEX_BASE "0123456789ABCDEF"

typedef struct asm_s {
    int ret;
    char *buffer;
    int fd;
    char **array_infos;
} t_asm;

void print_hexafile(t_asm *s_asm);
void check_put(char **array, t_asm *s_asm);
void convert_str_to_hex(char *str, int fd);
void check_add_sub(char **array, t_asm *s_asm);
void print_info_put(int i, t_asm *s_asm, char *hex_result, char **array);
void print_put_char_in_hex(char *hex_result, t_asm *s_asm, int k);
void print_infos(char **array, char *hex_result, t_asm *s_asm);
void print_zeros_before_info(char *hex_result, t_asm *s_asm);
void print_id_process(char **array, t_asm *s_asm);
void check_helper(char **argv, t_asm *s_asm);
void check_args(int argc, char **argv, t_asm *s_asm);
char *open_and_read_file(char const *filepath, t_asm *s_asm);
void get_all_lines(t_asm *s_asm, char *file_content, size_t len, FILE *file);
int get_size_file(char const *filepath);
char *my_putnbr_base_int(int number, char const *base);
char *add_zero_when_solo(char *hex_result);
void init_struct(t_asm *s_asm);
char *create_path(char const *filepath);
void check_and_or_xor(char **array, t_asm *s_asm);
void check_live(char **array, t_asm *s_asm);
void check_ld(char **array, t_asm *s_asm);
void check_st(char **array, t_asm *s_asm);
void check_zjmp(char **array, t_asm *s_asm);

#endif /* !ASSEMBLER_H_ */
