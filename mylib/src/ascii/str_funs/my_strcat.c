/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** Str concat
*/

#include "my_string.h"

#include <stddef.h>
#include <stdlib.h>

void my_unsafe_strcat(char *dest, char *src)
{
    size_t len = my_strlen(dest);
    size_t i = 0;

    for (i = 0; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
}

char *my_strcat(char *dest, char *src)
{
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);
    size_t len = 0;
    size_t i = 0;
    char *concat_str = malloc((dest_len + src_len + 1) * sizeof(char));

    if (!concat_str)
        return NULL;
    my_unsafe_strcat(concat_str, dest);
    len = my_strlen(concat_str);
    for (i = 0; src[i]; i++)
        concat_str[len + i] = src[i];
    concat_str[len + i] = '\0';
    return concat_str;
}
