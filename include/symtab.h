#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include "hash.h"
#include "ast.h"

void construct_symtab(ast_node_t* node, hash_table_t* hash_table);
void semantic_analysis(ast_node_t* node, hash_table_t* hash_table);

void process_expression(ast_node_t* node, hash_table_t* symbol_table, char* scope);

#endif /* SYMTAB_H */