/*
** EPITECH PROJECT, 2021
** my_is_empty_str.c
** File description:
** Returns true if a string is empty
*/

#include <stdbool.h>

bool my_is_empty_str(char *str)
{
    if (!str)
        return true;
    if (str[0] == '\0')
        return true;
    return false;
}
