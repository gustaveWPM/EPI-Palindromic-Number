/*
** EPITECH PROJECT, 2021
** my_two_dims_array_destroyer.c
** File description:
** 2d Array funs
*/

#include "my_safe_free.h"

#include <stddef.h>
#include <stdint.h>

void **my_create_empty_two_dims_array(void)
{
    void **two_dims_array = malloc(sizeof(NULL));

    if (!two_dims_array)
        return NULL;
    two_dims_array[0] = NULL;
    return two_dims_array;
}

size_t my_two_dims_array_len(void **array)
{
    size_t len = 0;

    if (!array)
        return 0;
    for (; array[len]; len++);
    return len;
}

void my_two_dims_array_destroyer(void **array)
{
    if (!array)
        return;
    for (size_t i = 0; array[i]; i++)
        MY_SAFE_FREE(array[i]);
    MY_SAFE_FREE(array);
}
