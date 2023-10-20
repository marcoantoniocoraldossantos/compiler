#ifndef UTILITIES_H
#define UTILITIES_H

#include "libraries.h"

#include "lexer.h"
#include "token.h"
#include "buffer.h"
#include "error.h"
#include "arguments.h"

// verify if the number of arguments is correct
void verify_arguments(int argc, char *argv[]);

// functions to open and close files
FILE *open_file(char *filename, char *mode);
void close_file(FILE *file);

// 
void replace_newline(char *string);

bool is_number(char *string);

void print_spaces(int line, int column);

bool has_exclamation(char *lexeme);

char *get_substring(char *string, int start, int end);

void save_arguments(int argc, char **argv);

char_t get_char_type(char c);

char *token_type_to_string(token_t token_type);

#endif