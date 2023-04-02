/*
** EPITECH PROJECT, 2021
** my_tokenizer.c
** File description:
** Strings Tokenizer
*/

#include "my_char.h"
#include "my_string.h"
#include "my_two_dims_arrays.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

size_t next_token_index(
    char *str, char *sep, size_t i
)
{
    size_t str_len = my_strlen(str);

    if (!my_char_in_str(str[i], sep) && i < str_len) {
        while (!my_char_in_str(str[i], sep) && i < str_len)
            i += 1;
        while (my_char_in_str(str[i], sep) && i < str_len)
            i += 1;
        return i;
    }
    while (my_char_in_str(str[i], sep) && i < str_len)
        i += 1;
    return i;
}

unsigned int count_tokens(char *str, char *sep)
{
    unsigned int count = 0;
    size_t i = 0;
    size_t str_len = my_strlen(str);

    if (!str)
        return 0;
    while (str[i] && i < str_len) {
        if (!my_char_in_str(str[i], sep)) {
            count += 1;
            i = next_token_index(str, sep, i);
            continue;
        }
        i += 1;
    }
    return count;
}

size_t token_len(char *str, char *sep)
{
    size_t len = 0;
    size_t delta = 0;

    if (my_char_in_str(str[0], sep))
        delta = next_token_index(str, sep, len);
    for (; !my_char_in_str(str[len + delta], sep) && str[len + delta]; len++);
    return len;
}
