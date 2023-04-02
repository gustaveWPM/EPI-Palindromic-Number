/*
** EPITECH PROJECT, 2021
** my_tr.c
** File description:
** Translate or delete characters
*/

#include "my_string.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static char process_tr(size_t index, char *memo_str, char *set_a, char *set_b)
{
    for (size_t i = 0; set_a[i] && set_b[i]; i++)
        if (memo_str[index] == set_a[i])
            return set_b[i];
    return '\0';
}

char *my_create_tr(char *str, char *set_a, char *set_b)
{
    char *memo_str = my_strdup(str);
    char *new_str = my_strdup(str);
    char new_char = '\0';

    if (!memo_str || !new_str) {
        if (memo_str)
            free(memo_str);
        if (new_str)
            free(new_str);
        return NULL;
    }
    if (!str)
        return NULL;
    for (size_t i = 0; new_str[i]; i++) {
        new_char = process_tr(i, memo_str, set_a, set_b);
        if (new_char != '\0')
            new_str[i] = new_char;
    }
    free(memo_str);
    return new_str;
}

bool my_tr(char *str, char *set_a, char *set_b)
{
    char *memo_str = NULL;
    char new_char = '\0';

    if (!str)
        return false;
    memo_str = my_strdup(str);
    if (!memo_str)
        return false;
    for (size_t i = 0; str[i]; i++) {
        new_char = process_tr(i, memo_str, set_a, set_b);
        if (new_char != '\0')
            str[i] = new_char;
    }
    free(memo_str);
    return true;
}
