/*
** EPITECH PROJECT, 2021
** my_str_togglecase.c
** File description:
** Toggle a str case
*/

#include "my_char.h"
#include "my_string.h"
#include "my_strtypes.h"

#include <stddef.h>

void my_str_uppercase(char *str)
{
    if (!str)
        return;
    for (size_t i = 0; str[i] != '\0'; i++)
        my_char_upcase(&str[i]);
}

void my_str_downcase(char *str)
{
    if (!str)
        return;
    for (size_t i = 0; str[i] != '\0'; i++)
        my_char_downcase(&str[i]);
}

void my_str_togglecase(char *str)
{
    size_t i = 0;

    if (!str || str_none(str, my_is_alphachar))
        return;
    if (str_none(str, my_is_upperchar)) {
        my_str_capitalize(str);
        return;
    }
    for (i = 0; !my_is_alphachar(str[i]); i++);
    if (my_is_upperchar(str[i]) && str_any(str, my_is_lowerchar)) {
        my_str_uppercase(str);
        return;
    }
    my_str_downcase(str);
}
