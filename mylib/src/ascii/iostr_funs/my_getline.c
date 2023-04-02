/*
** EPITECH PROJECT, 2021
** my_getline.c
** File description:
** Not implemented yet
*/

#include <stdio.h>
#include <stddef.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    return getline(lineptr, n, stream);
}
