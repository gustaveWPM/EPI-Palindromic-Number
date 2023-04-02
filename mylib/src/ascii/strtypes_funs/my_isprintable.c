/*
** EPITECH PROJECT, 2021
** my_islower.c
** File description:
** RETURNS TRUE IF THE STR IS IN downcase, OTHERWISE FALSE
*/

#include "my_strtypes.h"
#include "my_char.h"

#include <stdbool.h>
#include <stddef.h>

bool my_is_printable(char *str)
{
    return (str_all(str, my_is_printablechar));
}
