#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include "hash.h"
#include "ast.h"

void construct_symtab(ast_node_t* node, hash_table_t* hash_table);
void semantic_analysis(ast_node_t* node, hash_table_t* hash_table);

void process_variable_declaration(hash_table_t* hash_table, ast_node_t* node);
void process_vector_declaration(hash_table_t* hash_table, ast_node_t* node);
void process_variable(hash_table_t* hash_table, ast_node_t* node);
void process_vector(hash_table_t* hash_table, ast_node_t* node);
void process_function_declaration(hash_table_t* hash_table, ast_node_t* node);
void process_function_call(hash_table_t* hash_table, ast_node_t* node);
void process_return_int(hash_table_t* hash_table, ast_node_t* node);
void process_return_void(hash_table_t* hash_table, ast_node_t* node);
void process_variable_parameter(hash_table_t* hash_table, ast_node_t* node);
void process_vector_parameter(hash_table_t* hash_table, ast_node_t* node);
void process_void_parameter(hash_table_t* hash_table, ast_node_t* node);
void process_if(hash_table_t* hash_table, ast_node_t* node);
void process_if_else(hash_table_t* hash_table, ast_node_t* node);
void process_while(hash_table_t* hash_table, ast_node_t* node);
void process_assign(hash_table_t* hash_table, ast_node_t* node);
void process_operator(hash_table_t* hash_table, ast_node_t* node);
void process_relational(hash_table_t* hash_table, ast_node_t* node);
void process_constant(hash_table_t* hash_table, ast_node_t* node);
void process_identifier(hash_table_t* hash_table, ast_node_t* node);
void process_null(hash_table_t* hash_table, ast_node_t* node);


#endif /* SYMTAB_H */