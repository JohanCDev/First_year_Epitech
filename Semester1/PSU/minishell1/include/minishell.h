/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** minishell
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include "my.h"

typedef struct path_t {
    char *begin_path;
    char *previous_path;
    char *actual_path;
    int moved;
} s_path;

typedef struct env_t {
    int i;
    int found;
} s_env;

typedef struct minishell_t {
    s_path *path;
    s_env *env;
    char **env_tab;
    char *PATH_VAR;
} s_minishell;

void change_dir(char *line, s_minishell *minishell);
void check_bad_access(char *path, mode_t mode);
void get_actual_path(s_minishell *minishell);
void get_previous_path(s_minishell *minishell);
void initialize_project(s_minishell *minishell, char **env);
void free_all(s_minishell *minishell, char *line);
void switch_command(char *line, s_minishell *minishell);
void set_env(char *line, s_minishell *minishell);
char **copy_array(char **array, char *string_add);
void search_for_string(s_minishell *minishell, char *string);
void check_every_env(char **array, s_minishell *minishell, int h);
void unset_env(char *line, s_minishell *minishell);
void array_free(char **array);
void my_free(void *object);
int check_name_var(char const *str);
void reset_str(s_minishell *minishell, int i);
int check_if_errors(char **array, s_minishell *minishell);
int search_for_existing_var(s_minishell *minishell, char **array);
void do_others(s_minishell *minishell, char *line);
char **my_strtok(char *line, char *separators);
char *search_for_existing_path(char **path, char *filepath, char *command);
char **create_array_path(s_minishell *minishell);
char *assemble_filepath(char *filepath, char *path, char *command);
char *reset_string(char *str);
char *check_filepath(char *filepath);
char *check_permission(char *filepath);
void copy_path(s_minishell *minishell, char **env);
char *initialize_loop(s_minishell *minishell, char **env);
void my_print_core(int status);
void my_print_status(int status);

#endif