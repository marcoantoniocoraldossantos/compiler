#ifndef BST_H
#define BST_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>

#include "token.h"

// struct bst_node;

// typedef struct bst_node 
// {
//     char lexeme[64];
//     token_type_t token_type;
//     struct bst_node* left;
//     struct bst_node* right;
// } bst_node_t;

bst_node_t* initialize_bst();
bst_node_t* insert_bst_node(bst_node_t* root, char *lexeme, token_type_t token_type);
void free_bst(bst_node_t* root);
void print_bst(bst_node_t* root, int level);

#endif