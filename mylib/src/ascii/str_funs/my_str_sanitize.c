/*
** EPITECH PROJECT, 2021
** my_str_sanitize.c
** File description:
** Str sanitizing (create a new strings without unwanted chars)
*/

#include "my_char.h"

#include <stdlib.h>
#include <stddef.h>

static size_t this_count_memsize(char *str, char *forbidden_chars)
{
    size_t memsize = 0;

    for (size_t i = 0; str[i]; i++)
        if (!my_char_in_str(str[i], forbidden_chars))
            memsize += 1;
    return memsize;
}

char *my_create_empty_string(void)
{
    char *empty_str = malloc(sizeof(char));

    if (!empty_str)
        return NULL;
    empty_str[0] = '\0';
    return empty_str;
}

char *my_str_sanitize(char *str, char *forbidden_chars)
{
    char *sanitized_str = NULL;
    size_t memsize = 0;
    size_t new_str_index = 0;

    if (!str)
        return NULL;
    memsize = this_count_memsize(str, forbidden_chars);
    if (memsize == 0)
        return (my_create_empty_string());
    sanitized_str = malloc((memsize + 1) * sizeof(char));
    if (!sanitized_str)
        return NULL;
    for (size_t old_str_index = 0; str[old_str_index]; old_str_index++) {
        if (!my_char_in_str(str[old_str_index], forbidden_chars)) {
            sanitized_str[new_str_index] = str[old_str_index];
            new_str_index += 1;
        }
    }
    sanitized_str[new_str_index] = '\0';
    return sanitized_str;
}
