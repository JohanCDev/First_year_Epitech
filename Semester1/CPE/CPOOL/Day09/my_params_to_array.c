/*
** EPITECH PROJECT, 2020
** my_params_to_array
** File description:
** 
*/

void populate(struct info_param *info, char const *str) {
    // Use my_ functions to fill the elements of the struct
    info->length = my_strlen(str);
    info->str = my_strdup(str);
    info->copy = my_strdup(str); //I assume that copy is just a copy of str(?)
    info->word_array = my_str_to_word_array(str);
}
 
struct info_param *my_params_to_array(int ac, char **av) {
    // allocate the array of structs (ac + 1 elements. The 1 for 0)
    struct info_param *arr = (struct info_param *)malloc(sizeof(struct info_param) * ac + 1);

    // populate data into the structs
    int i;
    for(i=0; i<ac; i++) {
        populate(&arr[i], av[i]);
    }

    // The last structs str=0
    arr[i].str = 0;

    // return pointer to the arr
    return(arr);
}

