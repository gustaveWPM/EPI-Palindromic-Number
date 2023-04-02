/*
** EPITECH PROJECT, 2021
** my_is_digitchar.c
** File description:
** Returns true if the char is a digit, otherwise false
*/

#include <stdbool.h>

bool my_is_digitchar(char c)
{
    return (c >= '0' && c <= '9');
}
