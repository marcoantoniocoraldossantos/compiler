// token.h
#ifndef TOKEN_H
#define TOKEN_H

#define HASH_TABLE_SIZE 27

#include "buffer.h"
#include "ast.h"

typedef enum 
{
    // reserved words
    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,
    
    // special symbols
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LESS_THAN,
    LESS_THAN_EQUAL,
    GREATER_THAN,
    GREATER_THAN_EQUAL,
    EQUAL,
    NOT_EQUAL,
    ASSIGN,
    SEMICOLON,
    COMMA,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMENT_START,
    COMMENT_END,
    
    // markers
    ID,
    NUM,

    //other
    UNKNOWN,
    ERROR,
} token_type_t;

typedef struct 
{
    token_type_t type;
    char *lexeme;
    int line;  
} token_t;

typedef struct bst_node 
{
    char lexeme[64];
    token_type_t token_type;
    struct bst_node* left;
    struct bst_node* right;
} bst_node_t;

// token functions
token_t* initialize_token();
void print_token(token_t *token);
void free_token(token_t *token);

// analyze functions
token_t* get_next_token();
int process_token(token_t *token);

token_type_t get_token_type(bst_node_t* root, char *lexeme);
token_type_t identify_lexeme(bst_node_t* root, char *lexeme);

#endif
