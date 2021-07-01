/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** pal
*/

#ifndef __STUMPER__
#define __STUMPER__

//-----NEEDED-INCLUDE------
#include <stdbool.h>
//-----MACROS--------------
#define NB_ARGS_MIN 3
#define NB_ARGS_MAX 9
#define HELPER "USAGE\n\t\
./palindrome -n number -p palindrome [-b base] [-imin i] [-imax i]\n\
DESCRIPTION\n\
\t-n n integer to be transformed (>=0)\n\
\t-p pal palindromic number to be obtained (incompatible with the -n\
option) (>=0)\n\
\tif defined, all fitting values of n will be output\n\
\t-b base base in which the procedure will be executed (1<b<=10) [def: 10]\n\
\t-imin i minimum number of iterations, included (>=0) [def: 0]\n\
\t-imax i maximum number of iterations, included (>=0) [def: 100]\n"
#define NFLAG "n"
#define PFLAG "p"
#define BASEFLAG "b"
#define IMINFLAG "imin"
#define IMAXFLAG "imax"
//-----STRUCTURE-----------
typedef struct s_flags {
    int n;
    int p;
    int base;
    int imin;
    int imax;
} flags_t;

typedef struct s_pal {
    flags_t flags;
} pal_t;
//-----PROTOTYPES----------

//check_args.c

/// Check arguments of the binary
/// @param test pointer to the main structure
/// @returns -1 if failed, 0 if helper is asked, 1 if success
int check_args(int argc, char **argv, pal_t *test);

//initialize_structure.c

/// Initialize the structure
/// @returns the structure initialized with all parameters to 0 or NULL
void initialize_structure(pal_t *pal);

//manage_flags.c

///Check if a parameter is a flag
///@returns 1 if success, -1 if a flag is not recognized
int get_flags(flags_t *flags, char **argv);

//free_all.c

///Free a ptr if the base is not 10
///@param ptr Pointer to free
///@param base Base of the program
void free_if_base_is_not_10(void *ptr, int base);

//Get_type_flag.c

/// Check the type of a str flag
/// @param flags pointer to flag structure
/// @param flag str where is a flag
/// @return -1 if no corresponding flag is found, 0 if a flag is found
int get_type_flag_str(flags_t *flags, char *flag, char *value_to_insert);

//proceed.c
char *reverse_number(char *number);
char *get_new_number(char *number);
bool is_palindrom(char *number);
char *change_base(int nb, int base);
void print_result(int nb_that_lead, char *nb_pal, int nb_it, int base);
char *change_base_to_dec(char *nb, int base);
char *change_base_from_dec(int nb, int base);


int proceed_code(pal_t *pal);

#endif