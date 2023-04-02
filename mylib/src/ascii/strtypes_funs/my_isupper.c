/*
** EPITECH PROJECT, 2021
** my_isupper.c
** File description:
** Returns true if the str is in UPPERCASE, otherwise false
*/

#include "my_strtypes.h"
#include "my_char.h"

#include <stdbool.h>
#include <stddef.h>

bool my_isupper(char *str)
{
    return (str_none(str, my_is_lowerchar));
}
