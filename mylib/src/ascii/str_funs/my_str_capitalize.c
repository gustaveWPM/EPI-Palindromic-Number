/*
** EPITECH PROJECT, 2021
** my_str_capitalize.c
** File description:
** Capitalize an str, for example: "pony" -> "Pony"
*/

#include "my_char.h"
#include "my_string.h"
#include "my_strtypes.h"

#include <stddef.h>

static size_t next_token_index(char *str, size_t i)
{
    if (i >= my_strlen(str) || !str[i])
        return i;
    if (my_is_alphanum_char(str[i])) {
        for (; my_is_alphanum_char(str[i]); i++);
        for (; !my_is_alphanum_char(str[i]); i++);
    } else
        for (; !my_is_alphanum_char(str[i]); i++);
    return i;
}

void my_str_capitalize_each_word(char *str)
{
    bool capitalize = false;
    size_t i = 0;
    size_t str_len = my_strlen(str);

    while (i < str_len) {
        if (i == 0 && str[i] && my_is_alphanum_char(str[i]))
            capitalize = true;
        if (str[i] && capitalize) {
            my_char_upcase(&str[i]);
            capitalize = false;
        }
        i = next_token_index(str, i);
        if (i < str_len && my_is_alphanum_char(str[i]))
            capitalize = true;
    }
}

void my_str_capitalize(char *str)
{
    size_t i = 0;

    if (!str || str_none(str, my_is_alphanum_char))
        return;
    for (i = 0; !my_is_alphanum_char(str[i]); i++);
    my_char_upcase(&str[i]);
}
