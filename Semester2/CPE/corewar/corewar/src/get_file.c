/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-johan.chrillesen
** File description:
** get_file
*/

#include "corewar.h"

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

void get_all_lines(t_core *core, char *file_content, size_t len, FILE *file)
{
    ssize_t rd = 0;

    while (rd >= 0) {
        rd = getline(&file_content, &len, file);
        if (!(rd >= 0))
            break;
        len = 0;
        my_strcat(core->buff, file_content);
    }
}

char *open_and_read_file(char const *filepath, t_core *core)
{
    int size_file = get_size_file(filepath);
    core->buff = malloc(sizeof(char) * (size_file + 1));
    FILE *file = fopen(filepath, "r");
    size_t len = 0;
    char *file_content = NULL;

    core->buff[size_file] = 0;
    if (file == NULL)
        return (NULL);
    if (!(getline(&file_content, &len, file) >= 0)) {
        fclose(file);
        return (NULL);
    }
    len = 0;
    my_strcpy(core->buff, file_content);
    get_all_lines(core, file_content, len, file);
    fclose(file);
    return ("SUCCESS");
}