// token.h
#ifndef TOKEN_H
#define TOKEN_H

typedef enum 
{
    RESERVED_WORD,
    SPECIAL_SYMBOL,
    MARKER_ID,
    MARKER_NUM,
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

// token functions
token_list_t* initialize_token_list();
void add_token_to_list(token_list_t *list, token_t *token);
void print_token_list(token_list_t *list);
void free_token_list(token_list_t *list);

#endif

// typedef enum 
//{
//     // Reserved words
//     ELSE,
//     IF,
//     INT,
//     RETURN,
//     VOID,
//     WHILE,
    
//     // Special symbols
//     PLUS,
//     MINUS,
//     MULTIPLY,
//     DIVIDE,
//     LESS_THAN,
//     LESS_THAN_EQUAL,
//     GREATER_THAN,
//     GREATER_THAN_EQUAL,
//     EQUAL,
//     NOT_EQUAL,
//     ASSIGN,
//     SEMICOLON,
//     COMMA,
//     LEFT_PAREN,
//     RIGHT_PAREN,
//     LEFT_BRACKET,
//     RIGHT_BRACKET,
//     LEFT_BRACE,
//     RIGHT_BRACE,
//     COMMENT_START,
//     COMMENT_END,
    
//     // Markers
//     ID,
//     NUM,

//     // Add more tokens as needed for your language
//} TokenType;