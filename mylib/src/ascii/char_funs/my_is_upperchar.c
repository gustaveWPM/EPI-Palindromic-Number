/*
** EPITECH PROJECT, 2021
** my_is_upperchar.c
** File description:
** Returns true if the char is in UPPERCASE, otherwise false
*/

#include <stdbool.h>

bool my_is_upperchar(char c)
{
    return (c >= 'A' && c <= 'Z');
}
