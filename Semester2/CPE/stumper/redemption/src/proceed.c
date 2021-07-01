/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** proceed
*/

#include "calendar.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"

int get_length_command(char **command)
{
    int i = 0;

    while (command[i])
        i++;
    return (i);
}

char **create_cmd_array(void)
{
    char **cmd = malloc(sizeof(char *) * 8);

    if (cmd == NULL)
        return NULL;
    cmd[0] = "new_employee";
    cmd[1] = "new_meeting";
    cmd[2] = "invite";
    cmd[3] = "exclude";
    cmd[4] = "info_employees";
    cmd[5] = "info_meetings";
    cmd[6] = "cancel";
    cmd[7] = "fire";
    return cmd;
}

int find_command(char **command, employee_t *emp, meeting_t *meet)
{
    int (*pf_redir[8])(char **, employee_t *, meeting_t *);
    char **cmd = create_cmd_array();
    int j = 0;

    if (command == NULL || cmd == NULL)
        return my_put_error("Error malloc.\n", -1);
    pf_redir[0] = create_new_employee;
    pf_redir[1] = create_new_meeting;
    pf_redir[2] = invite_in_meeting;
    pf_redir[3] = exclude_of_meeting;
    pf_redir[4] = display_info_employees;
    pf_redir[5] = display_info_meetings;
    pf_redir[6] = cancel_meeting;
    pf_redir[7] = fire_employee;
    for (; j < 8; j++)
        if (!my_strcmp(command[0], cmd[j]))
            break;
    if (j == 8)
        return (0);
    my_free(cmd);
    return (pf_redir[j](command, emp, meet));
}

int proceed_all(employee_t *emp, meeting_t *meet)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    char **array = NULL;

    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1)
            return -1;
        line[read] = 0;
        if (!my_strcmp(line, "END\n")) {
            free(line);
            return 0;
        }
        array = my_str_to_word_array(line, " \n");
        if (find_command(array, emp, meet) == -1)
            return -1;
        my_free_array(array);
        free(line);
        line = NULL;
    }
}