/*
** EPITECH PROJECT, 2021
** str_funs.c
** File description:
** Str funs unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_string.h"
#include "my_strtypes.h"
#include "my_char.h"
#include "my_tokenizer.h"
#include "my_two_dims_arrays.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void my_criterion_listener(void);

Test(str_funs_tests, revstr_test, .init = NULL)
{
    char *test_str = "AHAH";
    char *reversed_str = NULL;

    reversed_str = my_create_revstr(test_str);
    cr_expect(!strcmp(reversed_str, "HAHA"));

    if (reversed_str)
        free(reversed_str);
}

Test(str_funs_tests, str_len_test, .init = NULL)
{
    char *test_str = "AHAH";

    cr_assert(my_strlen(NULL) == 0);

    cr_assert(my_strlen(test_str) == 4);
}

Test(str_funs_tests, strcmp_test, .init = NULL)
{
    cr_assert(my_strcmp("abc", "ab") == strcmp("abc", "ab"));
    cr_assert(my_strcmp("abc", "abc") == strcmp("abc", "abc"));
    cr_assert(my_strcmp("abc", "abc_") == strcmp("abc", "abc_"));
    cr_assert(my_strcmp("aabc", "abc") == strcmp("aabc", "abc"));
}

Test(str_funs_tests, strcapitalize_test, .init = NULL)
{
    char buff[8] = "abcdefg";

    my_str_capitalize(buff);
    cr_assert(!strcmp(buff, "Abcdefg"));
}

Test(str_funs_tests, strcapitalize_each_word_test, .init = NULL)
{
    char buff[79] = "hello world, glad to meet you! "
        "666eviltest try-something-harder, then+try+this";

    my_str_capitalize_each_word(buff);
    cr_assert(!strcmp(buff,
        "Hello World, Glad To Meet You! "
        "666eviltest Try-Something-Harder, Then+Try+This")
    );
}

Test(str_funs_tests, strdowncase_test, .init = NULL)
{
    char buff[8] = "Abcdefg";
    char *null_str = NULL;

    my_str_downcase(buff);
    cr_assert(!strcmp(buff, "abcdefg"));
    my_str_downcase(null_str);
    cr_assert(!null_str);
}

Test(str_funs_tests, strupcase_test, .init = NULL)
{
    char buff[8] = "Abcdefg";
    char *null_str = NULL;

    my_str_uppercase(buff);
    cr_assert(!strcmp(buff, "ABCDEFG"));

    my_str_uppercase(null_str);
    cr_assert(!null_str);
}

Test(str_funs_tests, togglecase_test, .init = NULL)
{
    char azertyuiop[12] = " azertyuiop";
    char *null_str = NULL;

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " Azertyuiop"));

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " AZERTYUIOP"));

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " azertyuiop"));

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " Azertyuiop"));

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " AZERTYUIOP"));

    my_str_togglecase(azertyuiop);
    cr_assert(!strcmp(azertyuiop, " azertyuiop"));

    my_str_togglecase(null_str);
    cr_assert(!null_str);
}

Test(my_atol_tests, basic_tests, .init = NULL)
{
    int64_t nbr = 21345;
    int64_t fetched_nbr = 0;

    fetched_nbr = my_atol("21345");
    cr_assert(fetched_nbr == nbr);
    fetched_nbr = my_atol("-21345");
    cr_assert(fetched_nbr == -21345);
    fetched_nbr = my_atol("abcdefg_je_connais_mon_alphabet");
    cr_assert(!fetched_nbr);
    fetched_nbr = my_atol("--21345");
    cr_assert(fetched_nbr == 21345);
    fetched_nbr = my_atol("--  21345");
    cr_assert(fetched_nbr == 21345);
    fetched_nbr = my_atol("-- - 21345");
    cr_assert(fetched_nbr == -21345);
    fetched_nbr = my_atol("-- - 21 345");
    cr_assert(fetched_nbr == -21);
    fetched_nbr = my_atol("-----------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "-------42");
    cr_assert(fetched_nbr == 42);
    fetched_nbr = my_atol("-----------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "----------------------------------------------"
    "------42");
    cr_assert(fetched_nbr == -42);
}

Test(my_strndup_test, basic_tests, .init = NULL)
{
    char *to_dup = "21345QdlkqJDLQJLdjkqDLKJQ_dQÇD_";
    char *ndup = my_strndup(&to_dup[2], 4);

    cr_assert(!strcmp("345Q", ndup));
    if (ndup)
        free(ndup);
    ndup = my_strndup(to_dup, 4);
    if (ndup) {
        cr_assert(!strcmp("2134", ndup));
        cr_assert(!my_strndup("2134", 9));
        free(ndup);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(my_strdup_test, basic_tests, .init = NULL)
{
    char *to_dup = "21345QdlkqJDLQJLdjkqDLKJQ_dQÇD_";
    char *dup = my_strdup(to_dup);

    if (dup) {
        cr_assert(!strcmp(to_dup, dup));
        free(dup);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(my_strcpy_test, basic_tests, .init = NULL)
{
    char dest[4] = {'\0'};
    char from[4] = "abc";
    char safe_dest[4] = "bca";

    cr_assert(!my_strcpy(from, dest));

    my_strcpy(from, safe_dest);
    cr_assert(!strcmp(from, safe_dest));
}

Test(my_unsafe_strcpy_test, basic_tests, .init = NULL)
{
    char dest[4] = {0};
    char from[4] = "abc";

    my_unsafe_strcpy(from, dest);
    cr_assert(!strcmp(from, dest));
}

Test(my_str_any_test, basic_tests, .init = NULL)
{
    cr_assert(!str_any(NULL, my_is_upperchar));
    cr_assert(!str_any("Abcdefg", my_is_digitchar));

    cr_assert(str_any("Hello World", my_is_upperchar));
}

Test(str_cat_test, basic_tests, .init = NULL)
{
    char hello[6] = "hello";
    char world[6] = " world";
    char *hello_world = NULL;

    hello_world = my_strcat(hello, world);
    if (hello_world) {
        cr_assert(!strcmp(hello_world, "hello world"));
        free(hello_world);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(str_alphabetical_order_cmp, basic_tests, .init = NULL)
{
    char *str_a = "hello";
    char *str_b = "world";

    cr_assert(!str_alphabetical_order_cmp(str_a, str_b));

    cr_assert(str_alphabetical_order_cmp(str_b, str_a));

    char *str_c = "Dupont";
    char *str_d = "Dupontt";
    cr_assert(!str_alphabetical_order_cmp(str_c, str_d));
    cr_assert(str_alphabetical_order_cmp(str_d, str_c));
}

Test(count_tokens_test, basic_tests, .init = NULL)
{
    unsigned int nb_tokens = count_tokens("a b c d e f g", " ");
    cr_assert(nb_tokens == 7);

    nb_tokens = count_tokens("a b     c  d  e    f         g", " ");
    cr_assert(nb_tokens == 7);

    nb_tokens = count_tokens("asqdsqdq bghfsfsdd     cqsdqdq  dqdqgh  eqsdqdqqs    fsdqdq         gqsdqsdq", " ");
    cr_assert(nb_tokens == 7);

    nb_tokens = count_tokens("           asqdsqdq bghfsfsdd     cqsdqdq  dqdqgh  eqsdqdqqs    fsdqdq         gqsdqsdq", " ");
    cr_assert(nb_tokens == 7);

    nb_tokens = count_tokens(NULL, " ");
    cr_assert(nb_tokens == 0);

    nb_tokens = count_tokens("       ", " ");
    cr_assert(nb_tokens == 0);

    nb_tokens = count_tokens(" :;///;::::;;:::///:     ", ":;/ ");
    cr_assert(nb_tokens == 0);
}

Test(next_token_index_test, basic_tests, .init = NULL)
{
    char *str = "a b c d e f g";
    size_t i = 0;

    i = next_token_index(str, " ", i);
    cr_assert(i == 2);

    i = next_token_index(str, " ", i);
    cr_assert(i == 4);

    i = next_token_index(str, " ", i);
    cr_assert(i == 6);

    i = next_token_index(str, " ", i);
    cr_assert(i == 8);

    i = next_token_index(str, " ", i);
    cr_assert(i == 10);

    i = next_token_index(str, " ", i);
    cr_assert(i == 12);

    i = next_token_index(str, " ", i);
    cr_assert(i == my_strlen(str));
}

Test(next_token_index_test, medium_tests, .init = NULL)
{
    char *str = "amsqdqsljkdqs    bqsmdjqsldjqs   csqdqsdqs  dqsdqs      esqdqsd    fqsdsqd  gqsdq";
    char *sep = " ";
    size_t i = 0;

    i = next_token_index(str, sep, i);
    cr_assert(i == 17);

    i = next_token_index(str, sep, i);
    cr_assert(i == 33);

    i = next_token_index(str, sep, i);
    cr_assert(i == 44);

    i = next_token_index(str, sep, i);
    cr_assert(i == 56);

    i = next_token_index(str, sep, i);
    cr_assert(i == 67);

    i = next_token_index(str, sep, i);
    cr_assert(i == 76);

    i = next_token_index(str, sep, i);
    cr_assert(i == 81);
}

Test(next_token_index_test, advanced_tests, .init = NULL)
{
    char *str = "amsqdqsljkdqs    bqsmdjqsldjqs,,,csqdqsdqs::dqsdqs,,, ::esqdqsd::, fqsdsqd:,gqsdq";
    char *sep = " ,:";
    size_t i = 0;

    i = next_token_index(str, sep, i);
    cr_assert(i == 17);

    i = next_token_index(str, sep, i);
    cr_assert(i == 33);

    i = next_token_index(str, sep, i);
    cr_assert(i == 44);

    i = next_token_index(str, sep, i);
    cr_assert(i == 56);

    i = next_token_index(str, sep, i);
    cr_assert(i == 67);

    i = next_token_index(str, sep, i);
    cr_assert(i == 76);

    i = next_token_index(str, sep, i);
    cr_assert(i == 81);

    char *no_token_str = "  :;:;:;:;:;:   :;:;:;:;:";
    i = 0;
    i = next_token_index(no_token_str, " :;", i);
    cr_assert(i == my_strlen(no_token_str));
}

Test(token_len_test, basic_tests, .init = NULL)
{
    char *str = "::::amsqdqsljkdqs    bqsmdjqsl,,,::dqsdqs,,, ::esqdqsd::, fqsdsqd:,gqsdq";
    char *sep = " ,:";
    size_t i = 0;
    size_t len = token_len(&str[i], sep);

    cr_assert(len == 13);
    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 13);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 9);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 6);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 7);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 7);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 5);

    i = next_token_index(str, sep, i);
    len = token_len(&str[i], sep);
    cr_assert(len == 0);
}

Test(strsplit_test, basic_tests, .init = my_criterion_listener)
{
    char *str = "Lorem Ipsum Dolor Sit Amet";
    char *sep = " ";
    char **tokenized_str = NULL;
    size_t two_dims_array_len = 0;
    unsigned int nb_tokens = count_tokens(str, sep);
    char **bidon = NULL;

    tokenized_str = my_strsplit(str, sep, NULL);
    if (tokenized_str) {
        two_dims_array_len = my_two_dims_array_len((void **) tokenized_str);
        cr_assert(nb_tokens == two_dims_array_len);
        cr_assert(my_two_dims_array_len(NULL) == 0);
        my_two_dims_array_destroyer((void **) bidon);
        cr_assert(bidon == NULL);
        for (int i = 0; tokenized_str[i]; i++)
            dprintf(STDOUT_FILENO, "%s ", tokenized_str[i]);
        my_two_dims_array_destroyer((void **) tokenized_str);
        cr_assert_stdout_eq_str("Lorem Ipsum Dolor Sit Amet ");
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(strsplit_test, medium_tests, .init = my_criterion_listener)
{
    char *str = "      ";
    char *sep = " ";
    char **tokenized_str = NULL;

    tokenized_str = my_strsplit(str, sep, NULL);
    if (tokenized_str) {
        cr_assert(tokenized_str[0] == NULL);
        my_two_dims_array_destroyer((void **) tokenized_str);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(strsplit_test, advanced_tests, .init = NULL)
{
    char *str = "aeiou aeiou";
    char *sep = " ";
    char **tokenized_str = NULL;

    cr_assert(!my_strsplit(NULL, " ", " "));

    tokenized_str = my_strsplit(str, sep, "aeoiu");
    if (tokenized_str) {
        cr_assert(tokenized_str[0] == NULL);
        my_two_dims_array_destroyer((void **) tokenized_str);
    } else
        cr_assert_fail("Failed to malloc\n");

    str = "aeiou aeiou";
    sep = " ";
    tokenized_str = NULL;

    tokenized_str = my_strsplit(str, sep, "aeoi");
    if (tokenized_str) {
        cr_assert(!strcmp(tokenized_str[0], "u"));
        cr_assert(!strcmp(tokenized_str[1], "u"));
        my_two_dims_array_destroyer((void **) tokenized_str);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(str_sanitize_test, basic_tests, .init = NULL)
{
    char *str = "AEIOU";
    char *forbidden_chars = "EIOU";
    char *sanitized_str = my_str_sanitize(str, forbidden_chars);

    if (sanitized_str) {
        cr_assert(!strcmp("A", sanitized_str));
        if (sanitized_str)
            free(sanitized_str);
        sanitized_str = my_str_sanitize(str, "AEIOU");
        cr_assert(!strcmp("\0", sanitized_str));
        if (sanitized_str)
            free(sanitized_str);
        cr_assert(!my_str_sanitize(NULL, "AEIOU"));
        sanitized_str = my_str_sanitize(str, "ZQSD");
        cr_assert(!strcmp(str, sanitized_str));
        if (sanitized_str)
            free(sanitized_str);
    } else
        cr_assert_fail("Failed to malloc\n");
}

Test(my_tr_test, basic_tests, .init = NULL)
{
    char str[7] = "AEIOU\n";
    char *const_str = "OUAEIAAAEEEIIIIIIOOOUUU\n";
    char *set_a = "AEI";
    char *set_b = "IJK";
    char *new_str = NULL;

    if (my_tr(str, set_a, set_b))
        cr_assert(!my_strcmp(str, "IJKOU\n"));
    new_str = my_create_tr(const_str, set_a, set_b);
    if (new_str)
        cr_assert(!my_strcmp(new_str, "OUIJKIIIJJJKKKKKKOOOUUU\n"));
    else
        cr_assert_fail("Failed to malloc\n");
    free(new_str);
}
