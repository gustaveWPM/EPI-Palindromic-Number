/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** Copy the content of a string into an another one
*/

#include "my_string.h"

#include <stdbool.h>

void my_unsafe_strcpy(char *str_from, char *str_to)
{
    size_t str_from_len = my_strlen(str_from);

    for (size_t i = 0; i < str_from_len; i++)
        str_to[i] = str_from[i];
    str_to[str_from_len] = '\0';
}

bool my_strcpy(char *str_from, char *str_to)
{
    size_t str_from_len = my_strlen(str_from);
    size_t str_to_len = my_strlen(str_to);

    if (str_from_len > str_to_len)
        return false;
    for (size_t i = 0; i < str_from_len; i++)
        str_to[i] = str_from[i];
    str_to[str_from_len] = '\0';
    return true;
}
