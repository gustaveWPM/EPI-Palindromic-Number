/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Puts a string
*/

#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

size_t my_strlen(char *str);

bool my_dputstr(uint8_t fileno, char *str)
{
    ssize_t i = 0;

    if (!str)
        return false;
    i = write(fileno, str, my_strlen(str));
    if ((int) i)
        return true;
    return false;
}

void my_putstr(char *str)
{
    my_dputstr(STDOUT_FILENO, str);
}

void my_puterr(char *str)
{
    my_dputstr(STDERR_FILENO, str);
}
