#ifndef TREE_H
#define TREE_H

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
