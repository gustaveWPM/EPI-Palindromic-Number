/*
** EPITECH PROJECT, 2021
** my_is_printablechar.c
** File description:
** Returns true if the char is printable
*/

#include <stdbool.h>

bool my_is_printablechar(char c)
{
    return (c >= ' ' && c <= '~');
}
