// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define NUM_CHAR_CLASSES 20
#define NUM_STATES 26

typedef enum {
    CHAR_SPACE, CHAR_LETTER, CHAR_DIGIT, // isspace isalpha isdigit
    CHAR_PLUS, CHAR_MINUS, CHAR_ASTERISK, CHAR_SLASH, // + - * /
    CHAR_LESS_THAN, CHAR_GREATER_THAN, CHAR_EQUALS, CHAR_EXCLAMATION, // = < > !
    CHAR_SEMICOLON, CHAR_COMMA, // ; ,
    CHAR_LPAREN, CHAR_RPAREN, CHAR_LBRACKET, CHAR_RBRACKET, CHAR_LBRACE, CHAR_RBRACE, // ( ) [ ] { }
    CHAR_OTHER // anything else
} char_t;

typedef enum 
{
    ST_SRT, // start state
    ST_ID, // identifier
    ST_NUM, // number
    ST_ADD, // +
    ST_SUB, // -
    ST_MUL, // *
    ST_LT, // <
    ST_GT, // > 
    ST_LE, // <=
    ST_GE, // >=
    ST_EQ, // ==
    ST_ASG, // =
    ST_NE, // !=
    ST_SEM, // ;
    ST_COM, // ,
    ST_LPA, // (
    ST_RPA, // )
    ST_LBK, // [
    ST_RBK, // ]
    ST_LBC, // {
    ST_RBC, // }
    ST_ENC, // /*
    ST_INC, // /* ... */
    ST_EXC, // */
    ST_ERR, // error state
    ST_END // end state
} state_t;

token_list_t* lexical_analyzer(FILE *source_code_file);
char_t get_char_type(char c);
char *state_to_string(state_t state);



#endif