// error.h
#ifndef ERROR_H
#define ERROR_H

#include "token.h"
#include "buffer.h"

void memory_alocation_error(char *caller);
void file_open_error(char *file_name);
void argument_error(char *program_name);
void lex_error(token_t* token, buffer_t buffer, int line, int column);

#endif