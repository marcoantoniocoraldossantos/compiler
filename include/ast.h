#ifndef AST_H
#define AST_H

#include "libraries.h"

#define MAXCHILDREN 3
#define MAXTOKENLEN 64

typedef enum 
{
    PROGRAM_NODE,
    STATEMENT_NODE,
    EXPRESSION_NODE
} node_kind_t;

typedef enum 
{
    IF_STMT,
    WHILE_STMT,
    RETURN_STMT,
    ASSIGN_STMT,
    NOT_STMT,
} statement_kind_t;

typedef enum 
{
    OP_EXP,
    CONST_EXP,
    ID_EXP,
    NOT_EXP,
} expression_kind_t;

typedef enum 
{
    INT_TYPE,
    VOID_TYPE,
    NO_TYPE,
} expression_type_t;

typedef struct ast_node_t 
{
    struct ast_node_t *child[MAXCHILDREN];
    struct ast_node_t *sibling;
    int lineno;
    char lexeme[MAXTOKENLEN];
    node_kind_t node_kind;
    union 
    {
        statement_kind_t statement;
        expression_kind_t expression;
        expression_type_t type;
    } kind;
    
} ast_node_t;

ast_node_t *initialize_ast();
void print_ast(ast_node_t *root);
void print_ast_util(ast_node_t *node, int level);
void free_ast(ast_node_t *root);
void add_child(ast_node_t *parent, ast_node_t *child);
void add_sibling(ast_node_t *node, ast_node_t *sibling);
ast_node_t* new_ast_node(node_kind_t kind, int line, const char* lexeme, statement_kind_t statement, expression_kind_t expression, expression_type_t type);


#endif /* AST_H */