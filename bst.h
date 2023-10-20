#ifndef BST_H
#define BST_H

#include "libraries.h"

#include "lexer.h"
#include "token.h"
#include "buffer.h"
#include "error.h"
#include "arguments.h"

bst_node_t* initialize_bst();
bst_node_t* insert_bst_node(bst_node_t* root, char *lexeme, token_type_t token_type);
void free_bst(bst_node_t* root);
void print_bst(bst_node_t* root, int level);

#endif