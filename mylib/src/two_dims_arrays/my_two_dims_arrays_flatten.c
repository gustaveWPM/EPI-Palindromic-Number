/*
** EPITECH PROJECT, 2021
** my_two_dims_array_destroyer.c
** File description:
** 2d Array flattening funs
*/

#include "my_two_dims_arrays.h"
#include "my_string.h"

#include <stdlib.h>

char *get_flatten_strings_two_dims_arr_rpz(char **two_dims_arr)
{
    size_t two_dims_arr_len = my_two_dims_array_len((void **) two_dims_arr);
    size_t memsize = 0;
    char *flattened_arr = NULL;

    for (size_t i = 0; i < two_dims_arr_len; i++)
        memsize += my_strlen(two_dims_arr[i]);
    flattened_arr = malloc((memsize + 1) * sizeof(char));
    if (!flattened_arr)
        return NULL;
    for (size_t i = 0; i <= memsize; i++)
        flattened_arr[i] = '\0';
    for (size_t i = 0; i < two_dims_arr_len; i++)
        my_unsafe_strcat(flattened_arr, two_dims_arr[i]);
    return flattened_arr;
}
