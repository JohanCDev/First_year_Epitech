/*
** EPITECH PROJECT, 2020
** B-CPE-100-NAN-1-1-rush2-johan.chrillesen
** File description:
** languages proccesing functions
*/
#include "include/my.h"
#include <unistd.h>

float calculate_nbr_letters(char *str, char *search, int print);

float get_english_proba(char *str)
{
        float englishproba = calculate_nbr_letters(str, "e", 0) * 12;
        englishproba += calculate_nbr_letters(str, "t", 0) * 9;
        englishproba += calculate_nbr_letters(str, "a", 0) * 8;
        englishproba += calculate_nbr_letters(str, "o", 0) * 7.5;
        englishproba += calculate_nbr_letters(str, "i", 0) * 7;
        englishproba += calculate_nbr_letters(str, "n", 0) * 7;
        englishproba += calculate_nbr_letters(str, "h", 0) * 5;
        englishproba += calculate_nbr_letters(str, "s", 0) * 6.5;
        englishproba += calculate_nbr_letters(str, "r", 0) * 6.5;
        englishproba -= calculate_nbr_letters(str, "z", 0) * 4;
        englishproba -= calculate_nbr_letters(str, "q", 0) * 4;
        englishproba -= calculate_nbr_letters(str, "j", 0) * 4;
        englishproba -= calculate_nbr_letters(str, "x", 0) * 4;
        return (englishproba);
}

float get_french_proba(char *str)
{
        float frenchproba = calculate_nbr_letters(str, "e", 0) * 17;
        frenchproba += calculate_nbr_letters(str, "s", 0) * 8;
        frenchproba += calculate_nbr_letters(str, "a", 0) * 8;
        frenchproba += calculate_nbr_letters(str, "i", 0) * 7;
        frenchproba += calculate_nbr_letters(str, "t", 0) * 7.2;
        frenchproba += calculate_nbr_letters(str, "n", 0) * 7;
        frenchproba += calculate_nbr_letters(str, "u", 0) * 6.3;
        frenchproba += calculate_nbr_letters(str, "r", 0) * 6.6;
        frenchproba += calculate_nbr_letters(str, "o", 0) * 5.2;
        frenchproba -= calculate_nbr_letters(str, "k", 0) * 4;
        frenchproba -= calculate_nbr_letters(str, "w", 0) * 4;
        frenchproba -= calculate_nbr_letters(str, "y", 0) * 4;
        frenchproba -= calculate_nbr_letters(str, "g", 0) * 4;
        frenchproba -= calculate_nbr_letters(str, "x", 0) * 4;
        return (frenchproba);
}

float get_german_proba(char *str)
{
        float germanproba = calculate_nbr_letters(str, "e", 0) * 17;
        germanproba += calculate_nbr_letters(str, "n", 0) * 10;
        germanproba += calculate_nbr_letters(str, "g", 0) * 3.1;
        germanproba += calculate_nbr_letters(str, "r", 0) * 7.5;
        germanproba += calculate_nbr_letters(str, "i", 0) * 7.5;
        germanproba += calculate_nbr_letters(str, "a", 0) * 6;
        germanproba += calculate_nbr_letters(str, "t", 0) * 6;
        germanproba += calculate_nbr_letters(str, "d", 0) * 5;
        germanproba += calculate_nbr_letters(str, "s", 0) * 6.6;
        germanproba -= calculate_nbr_letters(str, "j", 0) * 4;
        germanproba -= calculate_nbr_letters(str, "x", 0) * 4;
        germanproba -= calculate_nbr_letters(str, "q", 0) * 4;
        germanproba -= calculate_nbr_letters(str, "y", 0) * 4;
        return (germanproba);
}

float get_spanish_proba(char *str)
{
        float spanishproba = calculate_nbr_letters(str, "a", 0) * 12;
        spanishproba += calculate_nbr_letters(str, "n", 0) * 7.5;
        spanishproba += calculate_nbr_letters(str, "o", 0) * 8.5;
        spanishproba += calculate_nbr_letters(str, "e", 0) * 13.5;
        spanishproba += calculate_nbr_letters(str, "i", 0) * 7.5;
        spanishproba += calculate_nbr_letters(str, "r", 0) * 6.4;
        spanishproba += calculate_nbr_letters(str, "s", 0) * 7;
        spanishproba += calculate_nbr_letters(str, "l", 0) * 6;
        spanishproba += calculate_nbr_letters(str, "d", 0) * 5;
        spanishproba -= calculate_nbr_letters(str, "w", 0) * 4;
        spanishproba -= calculate_nbr_letters(str, "k", 0) * 4;
        spanishproba -= calculate_nbr_letters(str, "x", 0) * 4;
        spanishproba -= calculate_nbr_letters(str, "z", 0) * 4;
        spanishproba -= calculate_nbr_letters(str, "y", 0) * 4;
        spanishproba -= calculate_nbr_letters(str, "j", 0) * 4;
        return (spanishproba);
}

char *get_language_estimate(char *str)
{
    float englishproba = get_english_proba(str);
    float frenchproba = get_french_proba(str);
    float germanproba = get_german_proba(str);
    float spanishproba = get_spanish_proba(str);

    switch(get_biggest_score(englishproba, frenchproba, germanproba, \
    spanishproba))
    {
        case 1 : my_putstr("=> English\n");
                break;
        case 2 : my_putstr("=> French\n");
                break;
        case 3 : my_putstr("=> German\n");
                break;
        case 4 : my_putstr("=> Spanish\n");
                break;
    }
}
