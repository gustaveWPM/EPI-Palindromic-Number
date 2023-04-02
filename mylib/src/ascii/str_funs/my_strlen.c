/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** Returns a str length. For example: my_strlen("abc") -> 3
*/

#include <stddef.h>

size_t my_strlen(char *str)
{
    size_t len = 0;

    if (!str)
        return 0;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}
