/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mydb.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
//IS_AN_ID
Test(is_an_id, none_id)
{
    cr_assert_eq(is_an_id(TITLE_FIELD), 0);
}

Test(is_an_id, id_director)
{
    cr_assert_eq(is_an_id(ID_DIRECTOR_FIELD), 1);
}

Test(is_an_id, id)
{
    cr_assert_eq(is_an_id(ID_FIELD), 1);
}

Test(is_an_id, id_type)
{
    cr_assert_eq(is_an_id(ID_TYPE_FIELD), 1);
}

//CHECK_ID_FIELDS
Test(check_id_fields, good_director_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_id_fields(movie, ID_DIRECTOR_FIELD, 42), 1);
}

Test(check_id_fields, good_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_id_fields(movie, ID_FIELD, 1), 1);
}

Test(check_id_fields, good_type_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_id_fields(movie, ID_TYPE_FIELD, 2), 1);
}

Test(check_id_fields, bad_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_id_fields(movie, ID_TYPE_FIELD, 42), 0);
}

Test(check_id_fields, bad_input)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_id_fields(movie, 53, 42), 0);
}

//CHECK_CHAR_FIELDS
Test(check_char_fields, good_title_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, TITLE_FIELD, "My Title"), 1);
}

Test(check_char_fields, good_synposis)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, SYNPOSIS_FIELD, "Just a bad movie"), 1);
}

Test(check_char_fields, good_director)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, DIRECTOR_FIELD, "Unknow"), 1);
}

Test(check_char_fields, good_type)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, TYPE_FIELD, "comedy"), 1);
}

Test(check_char_fields, bad_input)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, 53, "Unkow"), 0);
}

Test(check_char_fields, bad_title)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(check_char_fields(movie, TITLE_FIELD, "Mauvais"), 0);
}

//IS_A_GOOD_CARACTERISTIQUE
Test(is_a_good_caracteristique, good_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(is_a_good_caracteristique(movie, ID_FIELD, "1"), 1);
}

Test(is_a_good_caracteristique, bad_id)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(is_a_good_caracteristique(movie, ID_FIELD, "5"), 0);
}

Test(is_a_good_caracteristique, good_char)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(is_a_good_caracteristique(movie, TITLE_FIELD, "My Title"), 1);
}

Test(is_a_good_caracteristique, bad_char)
{
    movie_t movie = {1, "My Title", "Just a bad movie", 42, "Unknow", 2, "comedy"};

    cr_assert_eq(is_a_good_caracteristique(movie, TITLE_FIELD, "5"), 0);
}
/* 
LES FONCTIONS UTILES
cr_assert_eq
cr_assert_eq_str
cr_assert_stdout_eq_str
cr_asser_file_content
*/