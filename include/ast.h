#ifndef AST_H
#define AST_H

#include "libraries.h"

#define MAXCHILDREN 3
#define MAXTOKENLEN 64

typedef enum 
{
    PROGRAM_NODE,
    DECLARATION_NODE,
    STATEMENT_NODE,
    EXPRESSION_NODE
} node_kind_t;

typedef enum 
{
    IF_STMT,
    WHILE_STMT,
} statement_kind_t;

typedef enum 
{
    ADD_EXPR,
    SUB_EXPR,
} expression_kind_t;

typedef enum 
{
    INT_TYPE,
    VOID_TYPE,
} expression_type_t;

typedef struct ast_node_t 
{
    struct ast_node_t *child[MAXCHILDREN];
    struct ast_node_t *sibling;
    int lineno;
    char lexeme[MAXTOKENLEN];
    node_kind_t node_kind;
    
} ast_node_t;

ast_node_t *initialize_ast();
void print_ast(ast_node_t *root);
void print_ast_util(ast_node_t *node, int level);
void free_ast(ast_node_t *root);
void add_child(ast_node_t *parent, ast_node_t *child);
void add_sibling(ast_node_t *node, ast_node_t *sibling);
ast_node_t* new_ast_node(node_kind_t kind, const char* lexeme);
ast_node_t* create_default_node(node_kind_t kind);


#endif /* AST_H */