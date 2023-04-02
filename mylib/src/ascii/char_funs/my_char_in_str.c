/*
** EPITECH PROJECT, 2021
** my_char_in_str.c
** File description:
** Returns true if a string includes the passed character
*/

#include <stdbool.h>
#include <stddef.h>

bool my_char_in_str(char c, char *str)
{
    for (size_t i = 0; str[i]; i++)
        if (c == str[i])
            return true;
    return false;
}
