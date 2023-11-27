
#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "ast.h"
#include "buffer.h"
#include "token.h"

extern FILE *global_input_file;
extern bst_node_t *global_bst_tree;
extern ast_node_t *global_ast_tree;
extern buffer_t *global_buffer;
extern int global_line_number;
extern char global_lexeme[64];
extern token_type_t global_token_type;

#endif // GLOBALS_H
