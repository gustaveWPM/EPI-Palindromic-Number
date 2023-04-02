/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** Puts a character
*/

#include <unistd.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

bool my_dputchar(uint8_t fileno, char c)
{
    ssize_t i = 0;

    i = write(fileno, &c, 1);
    if ((int) i)
        return true;
    return false;
}

void my_putchar(char c)
{
    my_dputchar(STDOUT_FILENO, c);
}

void my_putchar_err(char c)
{
    my_dputchar(STDERR_FILENO, c);
}
