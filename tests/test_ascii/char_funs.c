/*
** EPITECH PROJECT, 2021
** char_funs.c
** File description:
** Char funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_char.h"

Test(char_funs_tests, test_alphachar, .init = NULL)
{
    cr_assert(!my_is_alphachar('a' - 1));
    cr_assert(!my_is_alphachar('A' - 1));
    cr_assert(!my_is_alphachar('z' + 1));
    cr_assert(!my_is_alphachar('Z' + 1));

    cr_assert(my_is_alphachar('c'));
    cr_assert(my_is_alphachar('C'));
}

Test(char_funs_tests, test_alphanum, .init = NULL)
{
    cr_assert(!my_is_alphanum_char('a' - 1));
    cr_assert(!my_is_alphanum_char('A' - 1));
    cr_assert(!my_is_alphanum_char('z' + 1));
    cr_assert(!my_is_alphanum_char('Z' + 1));
    cr_assert(!my_is_alphanum_char('$'));

    cr_assert(my_is_alphanum_char('c'));
    cr_assert(my_is_alphanum_char('C'));
    cr_assert(my_is_alphanum_char('0'));
    cr_assert(my_is_alphanum_char('9'));
}

Test(char_funs_tests, test_is_digitchar, .init = NULL)
{
    cr_assert(!my_is_digitchar('0' - 1));
    cr_assert(!my_is_digitchar('9' + 1));

    cr_assert(my_is_digitchar('3'));
}

Test(char_funs_tests, test_is_lowerchar, .init = NULL)
{
    cr_assert(!my_is_lowerchar('A'));

    cr_assert(my_is_lowerchar('a'));
    cr_assert(!my_is_lowerchar('9'));
}

Test(char_funs_tests, test_is_upperchar, .init = NULL)
{
    cr_assert(!my_is_upperchar('a'));

    cr_assert(my_is_upperchar('A'));
    cr_assert(!my_is_upperchar('9'));
}

Test(char_funs_tests, test_toggle_char, .init = NULL)
{
    char downcase = 'h';
    char uppercase = 'H';
    char invalid = '9';

    my_char_togglecase(&downcase);
    my_char_togglecase(&uppercase);
    my_char_togglecase(&invalid);
    cr_assert(downcase == 'H');
    cr_assert(uppercase == 'h');
    cr_assert(invalid == '9');
}

Test(char_funs_tests, test_downcase_char, .init = NULL)
{
    char uppercase = 'Z';
    char downcase = 'z';
    char invalid = '9';

    my_char_downcase(&uppercase);
    my_char_downcase(&downcase);
    my_char_downcase(&invalid);
    cr_assert(uppercase == 'z');
    cr_assert(downcase == 'z');
    cr_assert(invalid == '9');
}

Test(char_funs_tests, test_upcase_char, .init = NULL)
{
    char uppercase = 'Z';
    char downcase = 'z';
    char invalid = '9';

    my_char_upcase(&uppercase);
    my_char_upcase(&downcase);
    cr_assert(uppercase == 'Z');
    cr_assert(downcase == 'Z');
    cr_assert(invalid == '9');
}
