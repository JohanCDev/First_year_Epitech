/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** play
*/

#include "my.h"
#include "navy.h"

extern s_glob_var glob_var;

char *get_input(void)
{
    char *buffer = malloc(sizeof(char *));
    int len = 0;

    if (buffer == NULL)
        return (NULL);
    len = read(0, buffer, 4096);
    buffer[len - 1] = '\0';
    if (!((buffer[0] >= 'A' && buffer[0] <= 'H') && \
    (buffer[1] >= '1' && buffer[1] <= '8')) || my_strlen(buffer) != 2)
        return (NULL);
    return (buffer);
}

void send_both_signals(char *input)
{
    send_signals(input[0] - 64);
    send_signals(input[1] - '0');
}

int play_player1(s_player_maps maps, int player, int other_player_pid, \
int round)
{
    char *input = malloc(sizeof(char *));

    if ((input = get_input())) {
        kill(glob_var.pid_enemy, SIGUSR2);
        send_both_signals(input);
        glob_var.nb_sig1 = 0;
        pause();
        if (round % 2 == 1)
            maps.map_p2 = fill_target(maps.map_p2, input, glob_var.nb_sig1);
        else
            maps.map_p1 = fill_target(maps.map_p1, input, glob_var.nb_sig1);
        if (check_end_game(maps.map_p2)) {
            display_maps(maps, player, round);
            my_printf("I won\n");
            return (0);
        }
        player = 2;
        display_maps(maps, 1, round);
        play(maps, player, other_player_pid);
    } else {
        my_printf("wrong position\n");
        play(maps, player, other_player_pid);
    }
    return (player);
}

void play_player2(s_player_maps maps, int player, int other_player_pid, \
int round)
{
    int signal_x = 64;
    int signal_y = 48;

    glob_var.nb_sig1 = 0;
    my_printf("waiting for enemy's attack...\n");
    wait_signals();
    signal_x = glob_var.nb_sig1;
    glob_var.nb_sig1 = 0;
    usleep(400000);
    kill(glob_var.pid_enemy, SIGUSR2);
    wait_signals();
    signal_y = glob_var.nb_sig1;
    if (round % 2 == 1)
        maps.map_p2 = fill_shoot(maps.map_p2, signal_x, signal_y);
    else
        maps.map_p1 = fill_shoot(maps.map_p1, signal_x, signal_y);
    player = 1;
    display_maps(maps, 2, round);
    play(maps, player, other_player_pid);
}

void play(s_player_maps maps, int player, int other_player_pid)
{
    static int round = 0;

    if (player == 1) {
        round++;
        my_printf("attack: ");
        player = play_player1(maps, player, other_player_pid, round);
        if (player = 0)
            return ;
    } else {
        round++;
        play_player2(maps, player, other_player_pid, round);
        if (check_end_game(maps.map_p1)) {
            display_maps(maps, player, round);
            my_printf("Enemy won\n");
            return ;
        }
    }
}