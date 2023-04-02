/*
** EPITECH PROJECT, 2021
** my_tokenizer.h
** File description:
** Tokenizer funs prototypes
*/

#ifndef MY_TOKENIZER_H
    #define MY_TOKENIZER_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdbool.h>

    size_t next_token_index(
        char *str, char *sep, size_t i
    );

    unsigned int count_tokens(char *str, char *sep);

    size_t token_len(char *str, char *sep);
#endif
