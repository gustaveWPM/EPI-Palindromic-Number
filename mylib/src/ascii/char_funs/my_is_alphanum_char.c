/*
** EPITECH PROJECT, 2021
** my_is_alphanum_char.c
** File description:
** Returns true if the char is an alphanum, otherwise false
*/

#include <stdbool.h>

bool my_is_alphachar(char c);

bool my_is_digitchar(char c);

bool my_is_alphanum_char(char c)
{
    return (my_is_alphachar(c) || my_is_digitchar(c));
}
