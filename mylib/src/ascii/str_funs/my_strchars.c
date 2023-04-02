/*
** EPITECH PROJECT, 2021
** my_strchars.c
** File description:
** Returns true if str only includes authorized chars
*/

#include <stdbool.h>
#include <stddef.h>

static bool is_authorized_char(char c, char *authorized_chars)
{
    for (size_t i = 0; authorized_chars[i]; i++)
        if (authorized_chars[i] == c)
            return true;
    return false;
}

bool my_strchars(char *str, char *authorized_chars)
{
    for (size_t i = 0; str[i]; i++)
        if (!is_authorized_char(str[i], authorized_chars))
            return false;
    return true;
}
