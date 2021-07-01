/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** errors
*/

#include "my.h"

ls_s detect_flags(ls_s param, char *str)
{
    int i = 1;

    if (str[0] == '-')
        while (str[i]) {
            param = get_param(str[i], param);
            i++;
        }
    if (i == 1)
        param.correct = 0;
    return (param);
}

int check_dir(char *str)
{
    int directory_ret = 1;
    int flag_ret = 0;
    int cannot_read = -1;
    DIR *directory;

    if (str[0] == '-' && str[1])
        return (flag_ret);
    if (!(directory = opendir(str)))
        return (cannot_read);
    else
        return (directory_ret);
    closedir(directory);
    return (-2);
}

int check_args(int ret)
{
    if (ret == -1)
        my_put_error("No such file or directory\n");
    return (ret);
}