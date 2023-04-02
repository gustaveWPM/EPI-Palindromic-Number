/*
** EPITECH PROJECT, 2021
** my_two_dims_arrays.h
** File description:
** Destroy functions prototypes
*/

#ifndef MY_TWO_DIMS_ARRAYS_H
    #define MY_TWO_DIMS_ARRAYS_H
    #include <stddef.h>
    void **my_create_empty_two_dims_array(void);
    size_t my_two_dims_array_len(void **array);
    void my_two_dims_array_destroyer(void **array);

    char *get_flatten_strings_two_dims_arr_rpz(char **two_dims_arr);
#endif
