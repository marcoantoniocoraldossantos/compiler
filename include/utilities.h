#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "arguments.h"
#include "lexer.h"
#include "token.h"
#include "symtab.h"

// arguments functions
void verify_arguments(int argc, char *argv[]);
void save_arguments(int argc, char **argv);
void save_global_variables(FILE *input_file, buffer_t *buffer, bst_node_t *bst_root);

// functions to open and close files
FILE *open_file(char *filename, char *mode);
void close_file(FILE *file);

int handle_buffer_end(FILE *input_file, buffer_t *buffer);

// char / string functions
void replace_newline(char *string);
char *get_substring(char *string, int start, int end);

// auxiliar functions
void print_spaces(int line, int column);

// functions to help with the state machine
char_t get_char_type(char c);
char *state_to_string(state_t state);
token_type_t state_to_token_type(state_t state);
char *token_type_to_string(token_type_t token_type);
token_type_t reserved_word_token_type(const char *word);
int convert_token(token_type_t token_type);
bool ast_node_is_identifier(ast_node_t *node);
bool verify_if_line_number_already_exists(hash_entry_t* entry, int line_number);
char* variable_type_to_string(variable_type_t id_type);
bool id_is_variable(hash_table_t* symbol_table, char* lexeme);

#endif