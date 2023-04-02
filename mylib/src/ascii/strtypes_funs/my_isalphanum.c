/*
** EPITECH PROJECT, 2021
** my_isalphanum.c
** File description:
** Returns true if the str is alphanum, otherwise false
*/

#include "my_strtypes.h"
#include "my_char.h"

#include <stdbool.h>
#include <stddef.h>

bool my_isalphanum(char *str)
{
    return (str_all(str, my_is_alphanum_char));
}
