#ifndef AST_H
#define AST_H

#include "libraries.h"

#define MAXCHILDREN 3
#define MAXTOKENLEN 64

typedef enum
{
    EXT_VARIABLE_DECL,
    EXT_VECTOR_DECL,
    EXT_VARIABLE,
    EXT_VECTOR,
    EXT_FUNCTION_DECL,
    EXT_FUNCTION_CALL,
    EXT_RETURN_INT,
    EXT_RETURN_VOID,
    EXT_VARIABLE_PARAMETER,
    EXT_VECTOR_PARAMETER,
    EXT_VOID_PARAMETER,
    EXT_IF,
    EXT_IF_ELSE,
    EXT_WHILE,
    EXT_ASSIGN,
    EXT_OPERATOR,
    EXT_RELATIONAL,
    EXT_CONSTANT,
    EXT_IDENTIFIER,
    EXT_NULL,
} extended_type_t;

typedef enum 
{
    PROGRAM_NODE,
    STATEMENT_NODE,
    EXPRESSION_NODE,
    DECLARATION_NODE,
    PARAMETER_NODE,
    NULL_NODE,
} node_kind_t;

typedef enum 
{
    IF_STMT,
    WHILE_STMT,
    RETURN_STMT,
    DECL_STMT,
    PARAM_STMT,
    COMPOUND_STMT,
    EXP_STMT,
    NULL_STMT,
} statement_kind_t;

typedef enum 
{
    OP_EXP,
    CONST_EXP,
    REL_EXP,
    ID_EXP,
    NOT_EXP,
    FUNCTION_EXP,
    VECTOR_EXP,
    ATTR_EXP,
    CALL_EXP,
    NULL_EXP,
} expression_kind_t;

typedef enum 
{
    INT_TYPE,
    VOID_TYPE,
    NULL_TYPE,
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
    // struct ast_node_t* next;
    // struct ast_node_t* previous;
    extended_type_t extended_type;
} ast_node_t;

ast_node_t *initialize_ast();
void print_ast(ast_node_t *root);
void print_ast_util(ast_node_t *node, int level);
void free_ast(ast_node_t *root);
void add_child(ast_node_t *parent, ast_node_t *child);
void add_sibling(ast_node_t *node, ast_node_t *sibling);
ast_node_t* new_ast_node(node_kind_t kind, int line, const char* lexeme, statement_kind_t statement, expression_kind_t expression, expression_type_t type);
void print_ast_node(ast_node_t *node);

#endif /* AST_H */