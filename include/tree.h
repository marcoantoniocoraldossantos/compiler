#ifndef TREE_H
#define TREE_H

typedef enum {
    STATEMENT_NODE,
    EXPRESSION_NODE
} node_type_t;

typedef enum 
{
    ASSIGN_STMT,        // id = expression;
    IF_STMT,            // if (condition) { ... }
    WHILE_STMT,         // while (condition) { ... }
    RETURN_STMT,        // return 0;
} statement_kind_t;

typedef enum 
{
    OPERATION_EXP,    // id + id, id - id, id * id, id / id
    CONSTANT_EXP,     // 0-9, 'a'-'Z', "string"
    VARIABLE_EXP,     // id
    RELATIONAL_EXP,   // id < id, id > id, id <= id, id >= id, id == id, id != id
    EQUALITY_EXP,     // id == id, id != id
} expression_kind_t;

// Define your tree node structure
typedef struct parse_tree_node_t {
    int line; // Linha do código-fonte
    char lexeme[64]; // Lexema (com tamanho máximo de 64 caracteres)
    node_type_t node_type; // Indica se é um nó de declaração ou expressão
    statement_type_t statement_type; // Tipo de declaração
    expression_type_t expression_type; // Tipo de expressão
    struct parse_tree_node_t *child; // Ponteiro para o primeiro nó filho
    struct parse_tree_node_t *sibling; // Ponteiro para o próximo nó irmão
} parse_tree_node_t;

// Function prototypes
parse_tree_node_t* create_node(int line, char *lexeme, node_type_t node_type, statement_type_t statement_type, expression_type_t expression_type));
void add_child(parse_tree_node_t *parent, parse_tree_node_t *child);
void add_sibling(parse_tree_node_t *node, parse_tree_node_t *sibling);
void delete_tree(parse_tree_node_t *root);

#endif /* TREE_H */
