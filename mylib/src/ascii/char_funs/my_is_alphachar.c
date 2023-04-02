/*
** EPITECH PROJECT, 2021
** my_is_alphachar.c
** File description:
** Returns true if the char is an alpha, otherwise false
*/

#include "my_char.h"

#include <stdbool.h>

bool my_is_alphachar(char c)
{
    return (my_is_lowerchar(c) || my_is_upperchar(c));
}
