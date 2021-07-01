/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** stumper
*/

#ifndef __CALENDAR__
#define __CALENDAR__

//-----NEEDED-INCLUDE------
#include <stdbool.h>
//-----MACROS--------------
#define NB_ARGS 1
#define HELPER "USAGE\n\twrite instructions to the standard output \
until the END instruction\n"
#define SORTBYDATE 1025
#define SORTBYZIP 950
#define SORTBYID 816
#define SORTBYNAME 1028
#define SORTBYFORENAME 1456
#define SORTBYJOB 926
//-----STRUCTURES-----
typedef struct employee {
    int id;
    char *last_name;
    char *first_name;
    char *position;
    char *zip;
    bool fired;
    struct employee *next;
} employee_t;

typedef struct meeting {
    int id;
    char *day;
    char *place;
    int *emp_id;
    bool cancel;
    struct meeting *next;
} meeting_t;
//-----PROTOTYPES----------

//check_args.c

/// Check arguments of the binary
/// @returns -1 if failed, 0 if helper is asked, 1 if success
int check_args(int argc, char **argv);

//initialize_structure.c

/// Initialize the structure of employees
/// @returns the structure initialized with all parameters to 0 or NULL
employee_t *initialize_employee(void);

/// Initialize the structure of meetings
/// @returns the structure initialized with all parameters to 0 or NULL
meeting_t *initialize_meeting(void);

//free_all.c
void free_meet(meeting_t *head);
void free_emp(employee_t *head);

///Free all the parameters
///@param stumper Pointer to the structure 
void free_all(meeting_t *meet, employee_t *emp);

//print_infos.c
int print_info_emp(employee_t *emp);

/// Print all that is needed
/// @param stumper pointer to the structure
// int print_all_infos(s_stumper *stumper);

//create meeting.c
int create_new_meeting(char **array, employee_t *emp, meeting_t *meet);
int exclude_of_meeting(char **array, employee_t *emp, meeting_t *meet);
int cancel_meeting(char **array, employee_t *emp, meeting_t *meet);
int invite_in_meeting(char **array, employee_t *emp, meeting_t *meet);
meeting_t *cancel_meeting_if_needed(meeting_t *current, int id, int size);
int check_all_meetings(meeting_t *meet, int id);

//create_employees.c
int create_new_employee(char **array, employee_t *emp, meeting_t *meet);
int fire_employee(char **array, employee_t *emp, meeting_t *meet);
int nb_emps_in_meeting(meeting_t *meeting);
employee_t *set_employee_fired(employee_t *emp, meeting_t *meet, \

char *str);

//display_infos.c
void print_other_emp_in_meet(employee_t *actual_emp, meeting_t *actual_meet, \
employee_t *emp);
int display_info_employees(char **array, employee_t *emp, meeting_t *meet);
int display_info_meetings(char **array, employee_t *emp, meeting_t *meet);

//proceed.c
int proceed_all(employee_t *emp, meeting_t *meet);

//utils.c
int count_int_tab(int *i_tab);
int *remove_id_from_array_emp_id(int *array_id, int id_to_remove);
int *add_id_from_array_emp_id(int *array_id, int id_to_add);
int find_int_in_int_array(int *array, int to_find);
int is_in_other_meet(meeting_t *meet, int emp_id);
int *clean_int_array(int *array);
bool is_in_ascending_order(char *str1, char *str2);

//cmp_in_linked_list
meeting_t *my_find_meeting_with_meet_id(meeting_t *begin, void *data_ref, \
int (*cmp)(const char *, const char *));
employee_t *my_find_emp_with_emp_id(employee_t *begin, void *data_ref, \
int (*cmp)(const char *, const char *));
employee_t *my_find_emp_in_meeting_with_id(employee_t *begin, void *meet_id, \
int (*cmp)(const char *, const char *), int i);

//find sort fct
int find_command_sort_emp(char **command, employee_t *emp, meeting_t *meet);
int find_command_sort_meet(char **command, employee_t *emp, meeting_t *meet);

employee_t *sort_node_emps_by_zip(employee_t *before, employee_t *emp1, \
employee_t *emp2);
employee_t *sort_node_emps_by_id(employee_t *before, employee_t *emp1, \
employee_t *emp2);
employee_t *sort_node_emps_by_job(employee_t *before, employee_t *emp1, \
employee_t *emp2);
employee_t *sort_node_emps_by_name(employee_t *before, employee_t *emp1, \
employee_t *emp2);
employee_t *sort_node_emps_by_forename(employee_t *before, employee_t *emp1, \
employee_t *emp2);

meeting_t *cancel_meeting_if_needed(meeting_t *current, int id, int size);
void print_other_emp_in_meet(employee_t *actual_emp, meeting_t *actual_meet, \
employee_t *emp);
int is_in_other_meet(meeting_t *meet, int emp_id);
int *clean_int_array(int *array);
int nb_emps_in_meeting(meeting_t *meeting);
employee_t *set_employee_fired(employee_t *emp, meeting_t *meet, \
char *str);
void adjust_meeting_for_nb_emps(meeting_t *meet);

void my_sort_emp(employee_t *emp, employee_t *(*sort)(employee_t *, \
employee_t *, employee_t *));
employee_t *swap_emp_with_condition(employee_t *emp, char *data_ref);
int get_size_list_emp(employee_t *emp);
int get_sum_string(char *str);
void swap_emp_nodes(employee_t *before, employee_t *emp1, employee_t *emp2);

meeting_t *swap_meet_with_condition(meeting_t *meet, char *data_ref);
void swap_meet_nodes(meeting_t *before, meeting_t *meet1, meeting_t *meet2);
void my_sort_meet(meeting_t *meet, \
meeting_t *(*sort)(meeting_t *, meeting_t *, meeting_t *));
meeting_t *sort_node_meet_by_date(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2);
meeting_t *sort_node_meet_by_id(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2);
meeting_t *sort_node_meet_by_zip(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2);
char *check_date(char *date);
void swap_emp_id_ids_if_needed(employee_t *emp, int first, int second);
int get_size_list_meet(meeting_t *meet);
void swap_for_meetings_info(meeting_t *meet);

#endif