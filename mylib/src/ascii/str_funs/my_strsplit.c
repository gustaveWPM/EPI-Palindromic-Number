/*
** EPITECH PROJECT, 2021
** my_strsplit.c
** File description:
** Split/tokenize a string from char * to char **
*/

#include "my_safe_free.h"
#include "my_char.h"
#include "my_string.h"
#include "my_two_dims_arrays.h"
#include "my_tokenizer.h"

#include <stdbool.h>
#include <stddef.h>

static char **process_strsplit(char *str, char *sep, unsigned int nb_tokens)
{
    char **tokenized_string = NULL;
    size_t str_len = my_strlen(str);
    unsigned int cur_token = 0;
    unsigned int cur_token_len = 0;

    tokenized_string = malloc((nb_tokens + 1) * sizeof(char *));
    if (!tokenized_string)
        return NULL;
    for (size_t i = 0; i < str_len; i = next_token_index(str, sep, i)) {
        cur_token_len = token_len(&str[i], sep);
        tokenized_string[cur_token] = my_strndup(&str[i], cur_token_len);
        if (tokenized_string[cur_token] == NULL) {
            my_two_dims_array_destroyer((void **) tokenized_string);
            return NULL;
        }
        cur_token += 1;
    }
    tokenized_string[cur_token] = NULL;
    return tokenized_string;
}

static char **my_sanitized_split(char *str, char *sep, char *forbidden_chars)
{
    unsigned int nb_tokens = 0;
    char *sanitized_str = NULL;
    char **tokenized_str = NULL;

    sanitized_str = my_str_sanitize(str, forbidden_chars);
    if (!sanitized_str)
        return NULL;
    nb_tokens = count_tokens(sanitized_str, sep);
    if (nb_tokens == 0)
        return ((char **) my_create_empty_two_dims_array());
    tokenized_str = process_strsplit(sanitized_str, sep, nb_tokens);
    free(sanitized_str);
    return tokenized_str;
}

char **my_strsplit(char *str, char *sep, char *forbidden_chars)
{
    unsigned int nb_tokens = 0;
    char **tokenized_str = NULL;

    if (!str)
        return NULL;
    if (forbidden_chars)
        return (my_sanitized_split(str, sep, forbidden_chars));
    nb_tokens = count_tokens(str, sep);
    if (nb_tokens == 0)
        return ((char **) my_create_empty_two_dims_array());
    tokenized_str = process_strsplit(str, sep, nb_tokens);
    return tokenized_str;
}
