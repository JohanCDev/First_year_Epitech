/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "my.h"
#include <stdlib.h>
#include "calendar.h"
#include <string.h>

int main(int argc, char **argv)
{
    employee_t *emp = initialize_employee();
    meeting_t *meet = initialize_meeting();

    if (!emp || !meet)
        return (my_put_error("Error malloc\n", -1));
    switch (check_args(argc, argv)) {
    case 0:
        return 0;
    case -1:
        return 84;
    case 1:
        break;
    }
    if (proceed_all(emp, meet) == -1)
        return -1;
    free_all(meet, emp);
    return 0;
}