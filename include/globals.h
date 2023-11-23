
#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "ast.h"
#include "buffer.h"

extern FILE *global_input_file;
extern bst_node_t *global_bst_tree;
extern ast_node_t *global_ast_tree;
extern buffer_t *global_buffer;

#endif // GLOBALS_H
