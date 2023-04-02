/*
** EPITECH PROJECT, 2021
** my_isalpha.c
** File description:
** Returns true if the str is alpha, otherwise false
*/

#include "my_strtypes.h"
#include "my_char.h"

#include <stdbool.h>
#include <stddef.h>

bool my_isalpha(char *str)
{
    return (str_all(str, my_is_alphachar));
}
