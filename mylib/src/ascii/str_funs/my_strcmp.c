/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** Compares in lexicographic order two strings
*/

#include "my_string.h"

int my_strcmp(const char *str_a, const char *str_b)
{
    while ((*str_a != '\0' && *str_b != '\0') && *str_a == *str_b) {
        str_a += 1;
        str_b += 1;
    }
    if (*str_a == *str_b)
        return 0;
    if ((int) *str_a - *str_b < 0)
        return -1;
    return 1;
}
