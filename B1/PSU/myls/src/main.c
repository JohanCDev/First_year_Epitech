/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** main
*/

#include "my.h"

void get_files(char *filepath)
{
    DIR *directory;
    struct dirent *file;
    char **tab = malloc(sizeof(char **) * 4096);
    int i = 0;
    directory = opendir(filepath);
    int *list_maj = malloc(sizeof(int) * 256);

    if (directory == NULL)
        return;
    while ((file = readdir(directory))) {
        if (file->d_name[0] != '.') {
            tab[i++] = file->d_name;
        }
    }
    list_maj = make_list_maj(tab);
    tab = sort_tab_alpha(tab, list_maj);
    my_put_tab(put_maj(tab, list_maj), "  ");
    free(tab);
    free(list_maj);
    closedir(directory);
}

ls_s set_params(ls_s param)
{
    param.r = 0;
    param.R = 0;
    param.d = 0;
    param.l = 0;
    param.t = 0;
    param.correct = 1;
    return (param);
}

void do_flag_d(ls_s param, char **argv, int i)
{
    while (param.d == 1 && param.correct == 1 && \
    (check_dir(argv[i]) || !argv[i + 1])) {
        if (check_dir(argv[i])) {
            my_printf("%s\n", argv[i]);
            return;
        }
        if (!argv[i + 1]) {
            my_printf(".\n");
            return;
        }
        i++;
    }
}

int do_my_ls(int argc, char **argv)
{
    int i = 1;
    ls_s param = {0, 0, 0, 0, 0, 1};

    if (argc == 1)
        get_files("./");
    while (argv[i]) {
        if (check_dir(argv[i]) == 0)
            param = detect_flags(param, argv[i]);
        else if (check_args(check_dir(argv[i])) != 1)
            return (84);
        do_flag_d(param, argv, i);
        if (check_dir(argv[i])) {
            make_flags(argv[i], param);
            (argv[i + 1]) ? my_printf("\n") : 0;
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int ret = 0;

    ret = do_my_ls(argc, argv);
    return (ret);
}