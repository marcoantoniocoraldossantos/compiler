#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include "hash.h"
#include "ast.h"

void construct_symtab(ast_node_t* node, hash_table_t* hash_table);
void semantic_analysis(ast_node_t* node, hash_table_t* hash_table);

void process_expression(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_statement(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_declaration(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_function(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_function_call(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_variable(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_array(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_assignment(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_if(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_while(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_for(ast_node_t* node, hash_table_t* symbol_table, char* scope);
void process_return(ast_node_t* node, hash_table_t* symbol_table, char* scope);


#endif /* SYMTAB_H */