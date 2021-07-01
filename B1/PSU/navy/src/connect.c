/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** connect
*/

#include "my.h"
#include "navy.h"

extern s_glob_var glob_var;

void connect_player1(void)
{
    int pid1;

    pid1 = getpid();
    my_printf("my_pid: %d\n", pid1);
    my_printf("waiting for enemy connection...\n");
    initialize_signal();
    pause();
    my_printf("\nenemy connected\n\n");
    kill(glob_var.pid_enemy, SIGUSR1);
}

void connect_player2(int argc, char **argv)
{
    int pid1;
    int pid2;
    (void) argc;

    pid2 = getpid();
    my_printf("my_pid: %d\n", pid2);
    pid1 = my_getnbr(argv[1]);
    kill(pid1, SIGUSR2);
    initialize_signal();
    my_printf("successfully connected\n\n");
}

void display_maps(s_player_maps maps, int player, int round)
{
    if (round % 2 == 0 && player == 1 && player != -1)
        player = 2;
    else if (round % 2 == 1 && player == 2 && player != -1)
        player = 2;
    else if (round % 2 == 0 && player == 2 && player != -1)
        player = 1;
    switch (player) {
        case 1 :
            my_printf("my positions:\n");
            my_put_tab(maps.map_p1, "");
            my_printf("enemy's positions:\n");
            my_put_tab(maps.map_p2, "");
            break;
        case 2 :
            my_printf("my positions:\n");
            my_put_tab(maps.map_p2, "");
            my_printf("enemy's positions:\n");
            my_put_tab(maps.map_p1, "");
            break;
    }
}

int connect_player(int argc, char **argv)
{
    s_player_maps maps;

    maps.map_p1 = malloc(sizeof(char *) * 10);
    maps.map_p2 = malloc(sizeof(char *) * 10);
    if (argc == 2 && get_file(argv[1]) == 0) {
        connect_player1();
        maps.map_p1 = create_map();
        maps.map_p2 = create_map();
        for (int i = 0; i < 4; i++) {
            maps.map_p1 = create_boat(get_line_of_file(argv[1], i), \
            maps.map_p1);
        }
        display_maps(maps, 1, -1);
        play(maps, 1, glob_var.pid_enemy);
    } else if (argc == 3 && get_file(argv[2]) == 0) {
        connect_player2(argc, argv);
        maps.map_p1 = create_map();
        maps.map_p2 = create_map();
        for (int i = 0; i < 4; i++) {
            maps.map_p2 = create_boat(get_line_of_file(argv[2], i), \
            maps.map_p2);
        }
        display_maps(maps, 2, -1);
        play(maps, 2, my_getnbr(argv[1]));
    } else
        return (84);
    return (0);
}