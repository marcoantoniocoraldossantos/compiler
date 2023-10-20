// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include "utilities.h"
#include "token.h"

#define NUM_CHAR_CLASSES 20
#define NUM_STATES 10

typedef enum 
{
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
    ST_CMP, // < > = <= >= ==
    ST_NE, // !=
    ST_ENC, // /*
    ST_INC, // /* ... */
    ST_EXC, // */
    ST_ERR, // error state
    ST_END // end state
} state_t;

// main function to tokenize the source code file
token_list_t* lexical_analyzer(FILE *source_code_file);

#endif