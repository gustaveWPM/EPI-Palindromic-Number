/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Dups a string into another one
*/

#include "my_string.h"
#include <stdlib.h>

char *my_strndup(char *str, size_t n)
{
    size_t str_len = my_strlen(str);
    char *dup_str = NULL;

    if (!str || n > str_len || n == 0)
        return NULL;
    dup_str = malloc((n + 1) * sizeof(char));
    if (!dup_str)
        return NULL;
    for (size_t i = 0; i < n; i++)
        dup_str[i] = str[i];
    dup_str[n] = '\0';
    return dup_str;
}

char *my_strdup(char *str)
{
    size_t str_len = my_strlen(str);
    char *dup_str = NULL;

    if (!str)
        return NULL;
    dup_str = malloc((str_len + 1) * sizeof(char));
    if (!dup_str)
        return NULL;
    for (size_t i = 0; i < str_len; i++)
        dup_str[i] = str[i];
    dup_str[str_len] = '\0';
    return dup_str;
}
