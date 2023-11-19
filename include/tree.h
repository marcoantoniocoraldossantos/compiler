#ifndef TREE_H
#define TREE_H

typedef enum {
    ASSIGNMENT_STMT,  // Atribuição (ex: x = 5;)
    IF_STMT,          // Declaração IF (ex: if (condição) { ... } [else { ... }])
    WHILE_STMT,       // Declaração WHILE (ex: while (condição) { ... })
    RETURN_STMT,      // Declaração RETURN (ex: return x;)
    // Outros tipos de declarações, se aplicáveis...
} StatementKind;

typedef enum {
    OPERATION_EXP,    // Expressão de operação (ex: x + y)
    CONSTANT_EXP,     // Expressão de constante (ex: 10, 'a', "string")
    VARIABLE_EXP,     // Expressão de variável (ex: x, y)
    RELATIONAL_EXP,   // Expressão relacional (ex: x > y, x <= y)
    EQUALITY_EXP,     // Expressão de igualdade (ex: x == y, x != y)
    // Outros tipos de expressões, se aplicáveis...
} ExpressionKind;


// Define your tree node structure
typedef struct TreeNode {
    // Data in the node
    int data; // Replace 'int' with your desired data type
    struct TreeNode *child; // Pointer to the first child node
    struct TreeNode *sibling; // Pointer to the next sibling node
} TreeNode;

// Function prototypes
TreeNode* create_node(int data);
void add_child(TreeNode *parent, TreeNode *child);
void add_sibling(TreeNode *node, TreeNode *sibling);
void delete_tree(TreeNode *root);

#endif /* TREE_H */
