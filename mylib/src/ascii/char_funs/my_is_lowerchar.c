/*
** EPITECH PROJECT, 2021
** my_is_lowerchar.c
** File description:
** RETURNS TRUE IF THE CHAR IS IN downcase, OTHERWISE FALSE
*/

#include <stdbool.h>

bool my_is_lowerchar(char c)
{
    return (c >= 'a' && c <= 'z');
}
