// token.h
#ifndef TOKEN_H
#define TOKEN_H

#define HASH_TABLE_SIZE 27

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
} token_type_t;

typedef struct 
{
    token_type_t type;
    char *lexeme;
    int line;  
} token_t;

typedef struct token_node_t 
{
    token_t token;
    struct token_node_t *next;
} token_node_t;

typedef struct 
{
    token_node_t *head;
    token_node_t *tail;
    int count;
} token_list_t;

typedef struct bst_node 
{
    char lexeme[64];
    token_type_t token_type;
    struct bst_node* left;
    struct bst_node* right;
} bst_node_t;

// token functions
token_t* initialize_token();
token_list_t* initialize_token_list();
void add_token_to_list(token_list_t *list, token_t *token);
void print_token_list(token_list_t *list);
void free_token_list(token_list_t *list);
void print_token(token_t *token);
void free_token(token_t *token);
token_type_t get_token_type(bst_node_t* root, char *lexeme);
token_type_t identify_lexeme(bst_node_t* root, char *lexeme);
bst_node_t* initialize_bst();
bst_node_t* insert_bst_node(bst_node_t* root, char *lexeme, token_type_t token_type);
void free_bst(bst_node_t* root);
void print_bst(bst_node_t* root, int level);

char* token_type_to_string(token_type_t token_type);

#endif
