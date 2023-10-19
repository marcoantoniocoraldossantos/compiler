// error.h
#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void memory_alocation_error(char *caller);
void file_open_error(char *file_name);
void argument_error(char *program_name);
void lex_error(buffer_t buffer, int line, int column);

#endif