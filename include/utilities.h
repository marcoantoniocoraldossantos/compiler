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

// arguments functions
void verify_arguments(int argc, char *argv[]);
void save_arguments(int argc, char **argv);

// functions to open and close files
FILE *open_file(char *filename, char *mode);
void close_file(FILE *file);

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

#endif