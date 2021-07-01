/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** waves
*/

#include "my.h"
#include "defender.h"

int switch_enemy(s_game *defender, int index, int place)
{
    int start_x = -40;

    switch (index) {
    case 1 :
        create_ch(defender, start_x * place);
        return (1);
    case 2 :
        create_br(defender, start_x * place);
        return (2);
    case 3 :
        create_sa(defender, start_x * place);
        return (2);
    case 4 :
        create_bg(defender, start_x * place);
        return (3);
    }
    return (0);
}

int generate_random_enemy(void)
{
    int random = 0;

    random = rand() % 10 + 1;
    if (random > 6 && random != 10) {
        if ((rand() % 2) == 1)
            return (2);
        return (3);
    } else if (random == 10)
        return (4);
    return (1);
}

void create_wave(s_game *defender)
{
    int difficulty = defender->play_infos->current_difficulty;
    int i = 0;

    while (difficulty > 0) {
        difficulty -= \
        switch_enemy(defender, generate_random_enemy(), i);
        i++;
    }
}