/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** signals
*/

#include "my.h"
#include "navy.h"

extern s_glob_var glob_var = {0, 0};

void handler1(int signal_number, siginfo_t *info, void *context)
{
    (void) signal_number;
    (void) context;
    glob_var.pid_enemy = info->si_pid;
    glob_var.nb_sig1++;
}

void handler2(int signal_number, siginfo_t *info, void *context)
{
    (void) signal_number;
    (void) context;
    (void) info;
    glob_var.pid_enemy = info->si_pid;
}

int initialize_signal(void)
{
    struct sigaction action1;
    struct sigaction action2;

    sigemptyset(&action1.sa_mask);
    sigemptyset(&action2.sa_mask);
    action1.sa_flags = SA_SIGINFO;
    action1.sa_sigaction = &handler1;
    action2.sa_flags = SA_SIGINFO;
    action2.sa_sigaction = &handler2;
    sigaction(SIGUSR1, &action1, NULL);
    sigaction(SIGUSR2, &action2, NULL);
    return (1);
}

void send_signals(int nb)
{
    int i = 0;

    for (; i < nb; i++) {
        usleep(15000);
        kill(glob_var.pid_enemy, SIGUSR1);
    }
    for (; i < 9; i++) {
        usleep(15000);
        kill(glob_var.pid_enemy, SIGUSR2);
    }
}

void wait_signals(void)
{
    for (int i = 0; i < 9; i++) {
        pause();
        usleep(10000);
    }
}