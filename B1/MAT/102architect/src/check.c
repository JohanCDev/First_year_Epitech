/*
** EPITECH PROJECT, 2020
** B-MAT-100-NAN-1-1-102architect-johan.chrillesen
** File description:
** check
*/

#include "my.h"
#include "architect.h"

int check_transformations(char **transfo, int i)
{
    char type = 0;

    if (!transfo[i][1])
        return (84);
    if (transfo[i][0] == '-' && my_str_isnum(transfo[i + 1]) && (transfo[i][1] == 't' || transfo[i][1] == 'z' || transfo[i][1] == 'r' || transfo[i][1] == 's') && !transfo[i][2]) {
        type = transfo[i][1];
        switch (type) {
            case 't':
                if (my_str_isnum(transfo[i + 2]))
                    return (2);
                break;
            case 'z':
                if (my_str_isnum(transfo[i + 2]))
                    return (2);
                break;
            case 'r':
                return (1);
                break;
            case 's':
                return (1);
                break;
            default:
                return (84);
        }
    }
    return (84);
}

int check_arguments(int nb_args, char **argv)
{
    int i = 1;

    if (nb_args < 5)
        return (84);
    //Check si le point de départ est bien un int en X et Y  
    while (argv[i] && i <= 2) {
        if (!my_str_isnum(argv[i]))
            return (84);
        i++;
    }
    //Check les transfos et les valeurs
    while (argv[i]) {
        if (check_transformations(argv, i) != 84)
            i += check_transformations(argv, i) + 1;
        else
            return (84);
    }
    return (1);
}