/*
** EPITECH PROJECT, 2021
** vocab.h
** File description:
** Vocabulary
*/

#ifndef ERRORS_MSG_VOCAB_H
    #define ERRORS_MSG_VOCAB_H
    static const struct {
        char *ERR_UNEXPECTED_TOKEN;
        char *ERR_UNKNOWN_FLAG;
        char *ERR_INCOMPATIBLE_FLAGS;
        char *ERR_FLAGS_PRECEDENCE;
        char *ERR_UNIQ_FLAG;
        char *ERR_REQ_VALUE_FLAG;
        char *WARN_UNEXPECTED_TOKEN;
        char *WARN_UNKNOWN_FLAG;
    } OPTFLAGS_MSG = {
        "[ERROR] UNEXPECTED TOKEN: ",
        "[ERROR] UNKNOWN FLAG: ",
        "[ERROR] INCOMPATIBLE FLAGS: ",
        "[ERROR] WRONG FLAGS PRECEDENCES: ",
        "[ERROR] THIS FLAG SHOULD BE UNIQ: ",
        "[ERROR] THIS FLAG REQUIRES A VALUE: ",
        "[WARNING] UNEXPECTED TOKEN: ",
        "[WARNING] UNKNOWN FLAG: "
    };
#endif
