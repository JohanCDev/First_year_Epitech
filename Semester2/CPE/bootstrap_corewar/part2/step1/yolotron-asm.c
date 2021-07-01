/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-bscorewar-johan.chrillesen
** File description:
** yolotron-asm
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct asm_s {
    int ret;
    char *buffer;
    int fd;
    char **array_infos;
} t_asm;

char **my_str_to_word_array(char *str, char *delims);
void free_array(char **array);

char *open_and_read_file(char const *filepath)
{
    int i = 0;
    int fd = open(filepath, O_RDONLY);
    struct stat file;
    char *buffer = NULL;

    if (!filepath)
        return (NULL);
    i = stat(filepath, &file);
    if (i == -1 || fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * file.st_size);
    if (!buffer)
        return NULL;
    i = read(fd, buffer, file.st_size);
    if (i == -1)
        return NULL;
    buffer[i - 1] = '\0';
    close(fd);
    return (buffer);
}

void check_helper(char **argv, t_asm *s_asm)
{
    if (!strcmp(argv[1], "-h")) {
        write(1, "Usage: ./yolotron-asm [source file] [output file]\n", 51);
        s_asm->ret = 1;
        return;
    } else {
        write(1, "ahhhh no, don't agree\n", 23);
        s_asm->ret = 85;
        return;
    }
    s_asm->ret = 0;
    return;
}

void init_struct(t_asm *s_asm)
{
    s_asm->array_infos = NULL;
    s_asm->buffer = NULL;
    s_asm->fd = 0;
    s_asm->ret = 0;
}

void check_args(int argc, char **argv, t_asm *s_asm)
{
    init_struct(s_asm);
    if (argc == 2) {
        check_helper(argv, s_asm);
        if (s_asm->ret != 0)
            return;
    } else if (argc != 3) {
        write(2, "ahhhh no, don't agree\n", 23);
        s_asm->ret = 85;
        return;
    }
    s_asm->buffer = open_and_read_file(argv[1]);
    if (s_asm->buffer == NULL) {
        s_asm->ret = 85;
        return;
    }
    s_asm->ret = 0;
    return;
}

int nb_words(char *str)
{
    int nb_words = 0;

    for (int i = 0; str[i] && str[i] != '\n'; i++) {
        if (str[i] == ' ')
            nb_words++;
    }
    return (nb_words);
}

char *my_putnbr_base_int(int number, char const *base)
{
    int res = 0;
    int i = 0;
    int pow = 1;
    int base_size = strlen(base);
    char *str_nb = malloc(sizeof(char) * 8);

    while ((number / pow) >= base_size)
        pow *= base_size;
    while (pow > 0) {
        res = (number / pow) % base_size;
        str_nb[i] = base[res];
        pow = pow / base_size;
        i++;
    }
    return (str_nb);
}


void my_swap(char *a, char *b)
{
    char *tempo = a;

    *a = *b;
    *b = *tempo;
}


char *reverse_pairs(char *hex_result)
{
    int nb_pairs = strlen(hex_result) / 2 + (strlen(hex_result) % 2);
    char tmp_char = 0;
    char *tmp_pair1 = malloc(sizeof(char) * 3);
    char *tmp_pair2 = malloc(sizeof(char) * 3);
    char *tmp_pair3 = malloc(sizeof(char) * 3);

    tmp_pair1[2] = 0;
    tmp_pair2[2] = 0;
    tmp_pair3[2] = 0;
    if (strlen(hex_result) % 2) {
        tmp_char = hex_result[strlen(hex_result) - 1];
        hex_result[strlen(hex_result) - 1] = '0';
        hex_result[strlen(hex_result)] = tmp_char;
        hex_result[strlen(hex_result)] = 0;
    }
    if (nb_pairs == 1)
        return (hex_result);
    for (int i = 1; i < nb_pairs; i += 2) {
        strncpy(tmp_pair3, &hex_result[i - 1], 2);
        hex_result[strlen(hex_result) - 2 - i] = tmp_pair3[0];
        hex_result[strlen(hex_result) - 1 - i] = tmp_pair3[1];
        // strncpy(tmp_pair1, &hex_result[i - 1], 2);
        // strncpy(tmp_pair2, &hex_result[strlen(hex_result) - 1 - i], 2);
        my_swap(tmp_pair1, tmp_pair2);
        printf("Got : %s\n", hex_result);
    }
    return (hex_result);
}

void check_add(char **array, t_asm *s_asm)
{
    int i = 0;
    char **line_to_convert = NULL;
    char *hex_result = malloc(sizeof(char) * 9);

    hex_result[8] = 0;
    for (i = 0; array[i]; i++);
    if (!strcmp(array[0], "add")) {
        if (i != 3) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        write(s_asm->fd, "01 ", 3);
        for (int k = 1; array[k]; k++) {
            hex_result = my_putnbr_base_int(atoi(array[k]), "0123456789ABCDEF");
            hex_result = reverse_pairs(hex_result);
            int m = 0;
            for (; m < strlen(hex_result); m += 2) {
                write(s_asm->fd, &hex_result[m], 2);
                write(s_asm->fd, " ", 1);
            }
            for (; m < 8; m++) {
                write(s_asm->fd, "0", 1);
                if (m % 2)
                    write(s_asm->fd, " ", 1);
            }
        }
    } else
        return;
}

void check_sub(char **array, t_asm *s_asm)
{
    int i = 0;
    char **line_to_convert = NULL;

    for (i = 0; array[i]; i++);
    if (!strcmp(array[0], "sub")) {
        if (i != 3) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        write(s_asm->fd, "02 ", 3);
        for (int k = 1; array[k]; k++) {
            write(s_asm->fd, my_putnbr_base_int(atoi(array[k]), "0123456789ABCDEF"), strlen(my_putnbr_base_int(atoi(array[k]), "0123456789ABCDEF")));
            write(s_asm->fd, " ", 1);
        }
    } else
        return;
}

void check_mul(char **array, t_asm *s_asm)
{
    int i = 0;
    char **line_to_convert = NULL;

    for (i = 0; array[i]; i++);
    if (!strcmp(array[0], "mul")) {
        if (i != 3) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        write(s_asm->fd, "03 ", 3);
        for (int k = 1; array[k]; k++) {
            write(s_asm->fd, my_putnbr_base_int(atoi(array[k]), "0123456789ABCDEF"), strlen(my_putnbr_base_int(atoi(array[k]), "0123456789ABCDEF")));
            write(s_asm->fd, " ", 1);
        }
    } else
        return;
}

void convert_str_to_hex(char *str, int fd)
{
    char *current_char = malloc(sizeof(char) * 2);

    current_char[1] = 0;
    for (int i = 0; str[i]; i++) {
        current_char[0] = str[i];
        write(fd, my_putnbr_base_int(current_char[0], "0123456789ABCDEF"), strlen(my_putnbr_base_int(current_char[0], "0123456789ABCDEF")));
        if (str[i + 1])
            write(fd, " ", 1);
    }
}

void check_put(char **array, t_asm *s_asm)
{
    int i = 0;

    for (i = 0; array[i]; i++);
    if (!strcmp(array[0], "put")) {
        if (i != 2) {
            write(2, "ahhhh no, don't agree\n", 23);
            s_asm->ret = 84;
            return;
        }
        write(s_asm->fd, "04 ", 3);
        convert_str_to_hex(array[1], s_asm->fd);
    } else
        return;
}

void print_hexafile(t_asm *s_asm)
{
    s_asm->array_infos = my_str_to_word_array(s_asm->buffer, "\n");
    char **instructions = NULL;

    for (int i = 0; s_asm->array_infos[i]; i++) {
        instructions = my_str_to_word_array(s_asm->array_infos[i], " ");
        check_add(instructions, s_asm);
        check_sub(instructions, s_asm);
        check_mul(instructions, s_asm);
        check_put(instructions, s_asm);
        free_array(instructions);
        //fprintf(s_asm->fd, " | ");
    }
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
    s_asm->fd = open(argv[2], O_CREAT | O_RDWR, 0777);
    if (s_asm->fd == 0) {
        write(2, "Unable to open file\n", 23);
        return (84);
    }
    print_hexafile(s_asm);
    end_program(s_asm);
    return (0);
}