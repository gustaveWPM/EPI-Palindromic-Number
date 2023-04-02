/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** Reverse a string
*/

#include "my_string.h"
#include "my_swap.h"

#include <stdlib.h>

void my_revstr(char *str)
{
    size_t rev_index = my_strlen(str) - 1;
    size_t index = 0;

    while (index < rev_index) {
        my_swap_ptr(&str[index], &str[rev_index]);
        index += 1;
        rev_index -= 1;
    }
}

char *my_create_revstr(char *str)
{
    size_t len = my_strlen(str);
    char *reversed_str = malloc((len + 1) * sizeof(char));

    if (!reversed_str)
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        reversed_str[i] = str[i];
    reversed_str[len] = '\0';
    my_revstr(reversed_str);
    return reversed_str;
}
