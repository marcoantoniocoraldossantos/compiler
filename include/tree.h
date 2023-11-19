#ifndef TREE_H
#define TREE_H

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
typedef struct parse_tree_node_t 
{
    // Data in the node
    int data; // Replace 'int' with your desired data type
    struct parse_tree_node_t *child; // Pointer to the first child node
    struct parse_tree_node_t *sibling; // Pointer to the next sibling node
} parse_tree_node_t;

// Function prototypes
TreeNode* create_node(int data);
void add_child(TreeNode *parent, TreeNode *child);
void add_sibling(TreeNode *node, TreeNode *sibling);
void delete_tree(TreeNode *root);

#endif /* TREE_H */
