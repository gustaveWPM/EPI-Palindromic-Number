/*
** EPITECH PROJECT, 2021
** my_criterion_listener.c
** File description:
** Stdout and Stderr Listener
*/

#include <criterion/redirect.h>

void my_criterion_listener(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
