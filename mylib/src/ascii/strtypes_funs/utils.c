/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** Utilities for strtypes
*/

#include <stdbool.h>
#include <stddef.h>

bool str_any(char *str, bool fun_ptr (char c))
{
    if (!str)
        return false;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (fun_ptr(str[i]))
            return true;
    return false;
}

bool str_none(char *str, bool fun_ptr (char c))
{
    if (!str)
        return false;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (fun_ptr(str[i]))
            return false;
    return true;
}

bool str_all(char *str, bool fun_ptr (char c))
{
    if (!str)
        return false;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!fun_ptr(str[i]))
            return false;
    return true;
}
