/*
** EPITECH PROJECT, 2021
** my_isdigit.c
** File description:
** Returns true if the str contains only digits, otherwise false
*/

#include "my_strtypes.h"
#include "my_char.h"

#include <stdbool.h>
#include <stddef.h>

bool my_isdigit(char *str)
{
    return (str_all(str, my_is_digitchar));
}
