/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper4-quentin.leroueil
** File description:
** fight
*/

#include "pokemon.h"

void assign_values_fight(pokemon_t *pokemon_ptr, pokemon_t pokemon)
{
    pokemon_ptr->attack = pokemon.attack;
    pokemon_ptr->defense = pokemon.defense;
    pokemon_ptr->speed = pokemon.speed;
    pokemon_ptr->health = pokemon.health;
}

void act_on_game(pokemon_t *attack, pokemon_t *defend)
{
    int damage = 0;
    unsigned int health_lost = 0;

    damage = (rand() % attack->attack); 
    printf("%s attacks for %d damage\n", attack->name, attack->attack);
    printf("%s blocks %d damage\n", defend->name, defend->defense);
    health_lost = damage - defend->defense;
    defend->health -= health_lost;
    printf("%s loses %d health (%d left)\n", defend->name, \
    health_lost, defend->health);
}

void start_fight(pokemon_t *first, pokemon_t *second, bool turn)
{
    if (turn == 0)
        act_on_game(first, second);
    else
        act_on_game(second, first);
}

void proceed_fight(pokemon_t *first, pokemon_t *second)
{
    bool turn = 0;

    srand(time(NULL));
    while (1) {
        start_fight(first, second, turn);
        if (first->health <= 0) {
            printf("%s is KO\n", first->name);
            printf("%s wins the fight !\n", second->name);
            break;
        } else if (second->health == 0) {
            printf("%s is KO\n", second->name);
            printf("%s wins the fight !\n", first->name);
            break;
        }
        if (turn == 0)
            turn = 1;
        else
            turn = 0;
    }
    free_pokemons(first, second);
}

int fight(pokemon_t *fight_pokemons)
{
    pokemon_t *first = malloc(sizeof(pokemon_t));
    pokemon_t *second = malloc(sizeof(pokemon_t));

    if (first == NULL || second == NULL)
        return (84);
    if (fight_pokemons[0].speed > fight_pokemons[1].speed) {
        assign_values_fight(first, fight_pokemons[0]);
        assign_values_fight(second, fight_pokemons[1]);
    } else {
        assign_values_fight(first, fight_pokemons[1]);
        assign_values_fight(second, fight_pokemons[0]);
    }
    proceed_fight(first, second);
    return (0);
}