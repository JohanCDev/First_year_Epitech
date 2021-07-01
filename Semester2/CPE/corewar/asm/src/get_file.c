/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** get_file
*/

#include "assembler.h"

int get_size_file(char const *filepath)
{
    FILE *file = fopen(filepath, "r");
    size_t len = 0;
    ssize_t rd = 0;
    int file_len = 0;
    char *file_content = NULL;

    if (file == NULL)
        return (0);
    while (rd >= 0) {
        rd = getline(&file_content, &len, file);
        len = 0;
        if (!(rd >= 0))
            break;
        file_len += my_strlen(file_content);
    }
    fclose(file);
    return (file_len);
}

void get_all_lines(t_asm *s_asm, char *file_content, size_t len, FILE *file)
{
    ssize_t rd = 0;

    while (rd >= 0) {
        rd = getline(&file_content, &len, file);
        if (!(rd >= 0))
            break;
        len = 0;
        my_strcat(s_asm->buffer, file_content);
    }
}

char *create_path(char const *filepath)
{
    char *ret_str = malloc(sizeof(char) * (my_strlen(filepath) + 6));
    int i = 0;

    ret_str[0] = 0;
    for (; filepath[i]; i++) {
        if (!my_strncmp(&filepath[i], ".s", 2)) {
            my_strcat(ret_str, ".cor");
            return (ret_str);
        }
        ret_str[i] = filepath[i];
        ret_str[i + 1] = 0;
    }
    my_strcat(ret_str, ".cor");
    return (ret_str);
}

char *open_and_read_file(char const *filepath, t_asm *s_asm)
{
    int size_file = get_size_file(filepath);
    s_asm->buffer = malloc(sizeof(char) * (size_file + 1));
    FILE *file = fopen(filepath, "r");
    my_printf("Reading in this file :%s\n", filepath);
    size_t len = 0;
    char *file_content = NULL;

    s_asm->buffer[size_file] = 0;
    if (file == NULL)
        return (NULL);
    if (!(getline(&file_content, &len, file) >= 0)) {
        fclose(file);
        return (NULL);
    }
    len = 0;
    my_strcpy(s_asm->buffer, file_content);
    get_all_lines(s_asm, file_content, len, file);
    fclose(file);
    return ("SUCCESS");
}